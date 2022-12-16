#include "EventFactory.h"
#include "../VehicleStatus/VehicleStatus.h"
#include "../Time/Time.h"
#include "../Location/Location.h"
#include "Event.h"
#include <type_traits>
#include <atomic>
#include <iostream>
#include <cmath>
#include <thread>

namespace LockFreeDispatch {


    std::vector<Vehicle *> EventFactory::vehiclesMeetingRequirements(
            std::vector<Vehicle *> vehicleReqts,
            std::vector<Vehicle *> orderedVehicles) {

        std::vector<Vehicle*> meetingRequirements;

        for (const auto & vehicle : orderedVehicles)
        {
            for (const auto & reqt : vehicleReqts)
            {
                // TODO - should confirm the Engine/Ladder type
                if (vehicle->getCurNumCrew() >= reqt->getCurNumCrew()
                    && vehicle->getCurWaterVolumeLitres() >= reqt->getCurWaterVolumeLitres())
                {
                    meetingRequirements.push_back(vehicle);
                }
            }
        }
        return meetingRequirements;
    }

    std::vector<Vehicle *> EventFactory::selectVehicles(
            std::vector<Vehicle *> vehicleReqts, std::vector<Vehicle *> orderedVehicles,
            BitArray *bitArray) {
        while (true)
        {
            std::vector<Vehicle*> selectedVehicles;
            uint8_t numVehiclesRequired = vehicleReqts.size();
            std::vector<Vehicle*> listSubset = vehiclesMeetingRequirements(vehicleReqts, orderedVehicles);
            float avgWorkFactor = calculateAverageWorkFactor(listSubset);

            for (const auto & vehicle : listSubset)
            {
                if (vehicle->getWorkFactor() >= avgWorkFactor)
                {
                    if (vehicle->getCurVehicleStatus() == VehicleStatus::Available
                    || vehicle->getCurVehicleStatus() == VehicleStatus::Returning)
                    {
                        selectedVehicles.push_back(vehicle);
                        --numVehiclesRequired;
                    }
                }
                if (numVehiclesRequired == 0)
                {
                    if (modifyVehicleStatus(selectedVehicles, bitArray))
                    {
                        return selectedVehicles;
                    }
                    else
                    {
                        // Break inner for loop and continue outer while loop
                        // I know, I know, it's a goto - don't be scared
                        // This is the easiest way to perform the loop iteration needed and won't harm anyone
                        // despite what everyone says, these can be useful.
                        goto tryAgain;
                    }
                }
            }
            for (const auto & vehicle : orderedVehicles) {
                if (vehicle->getCurVehicleStatus() == VehicleStatus::Available
                    || vehicle->getCurVehicleStatus() == VehicleStatus::Returning) {
                    selectedVehicles.push_back(vehicle);
                    --numVehiclesRequired;
                }
                if (numVehiclesRequired == 0)
                {
                    if (modifyVehicleStatus(selectedVehicles, bitArray))
                    {
                        return selectedVehicles;
                    }
                }
            }
            // See, it's friendly :)
            tryAgain:;
        }
    }

    bool EventFactory::modifyVehicleStatus(std::vector<Vehicle *> vehicleList, BitArray *bitArray) {
        BitArray unmodifiedBitArray;
        unmodifiedBitArray.setGlobalBitArray(bitArray->getGlobalBitArray());
        BitArray modifiedBitArray;
        modifiedBitArray.setGlobalBitArray(bitArray->getGlobalBitArray());

        for (const auto & vehicle : vehicleList)
        {
            if (vehicle->getCurVehicleStatus() == VehicleStatus::Available
            || vehicle->getCurVehicleStatus() == VehicleStatus::Returning)
            {
                modifiedBitArray.setGlobalBitArray(modifiedBitArray.modifyBitArray(vehicle->getVehicleID(), true));
            }
            else
            {
                return false;
            }
        }

        uint64_t expected = unmodifiedBitArray.getGlobalBitArray();
        uint64_t desired = modifiedBitArray.getGlobalBitArray();
        if(bitArray->globalBitArray.compare_exchange_weak(expected, desired))
        {
            for (const auto & vehicle : vehicleList)
            {
                vehicle->setCurVehicleStatus(VehicleStatus::Responding);
            }
            return true;
        }
        return false;
    }

    float EventFactory::calculateAverageWorkFactor(std::vector<Vehicle *> vehicleList) {
        size_t listSize = vehicleList.size();
        float workFactorSum = 0;
        for (auto vehicle : vehicleList)
        {
            workFactorSum += vehicle->getWorkFactor();
        }
        return workFactorSum / listSize;
    }

    void EventFactory::populateActiveQueue(Time *programClock, DistrictResources *districtResources, BitArray *bitArray)
    {
        while (!pendingQueue.empty())
        {
            // Wait until the start time of the next event is after the program clock
            while(pendingQueue.front().getStartTime().isBefore(*programClock));

            // Get a reference to the current event
            auto curEvent = &pendingQueue.front();

            // Add the next event to the back of the active queue
            activeQueue.push_back(*curEvent);

            // Remove the event from the pending queue
            pendingQueue.erase(pendingQueue.begin());

            std::cout << "Starting dispatch process for Event #" << curEvent->getEventID() << std::endl;

            // Create a thread to handle this event
            std::thread curEvent_thread([this, districtResources, curEvent, bitArray]()
            {
                processEvent(curEvent, districtResources, bitArray);
            });
            curEvent_thread.detach();
        }
    }

    void EventFactory::processEvent(Event *curEvent, DistrictResources *districtResources, BitArray *bitArray)
    {
        std::vector<Vehicle*> eventRequirements = districtResources->getVehicleRequirements(curEvent->getEventID());
        std::cout << "Before ordered list" << std::endl;
        std::vector<Vehicle*> orderedList = districtResources->getOrderedVehicleList(curEvent->getLocation());
        std::cout << "After ordered list" << std::endl;
        std::vector<Vehicle*> dispatchedVehicles = selectVehicles(eventRequirements, orderedList, bitArray);

        for (const auto & vehicle : dispatchedVehicles)
        {
            // Create a thread to handle this vehicle for this event
            std::thread curVehicle_thread([this, &vehicle, curEvent, bitArray]()
            {
                processVehicle(vehicle, curEvent, bitArray);
            });
            curVehicle_thread.detach();
        }

        removeEventActiveQueue(curEvent->getEventID());
        std::cout << "Dispatched event #" << curEvent->getEventID() << std::endl;
    }

    void EventFactory::processVehicle(Vehicle *curVehicle, Event *curEvent, BitArray *bitArray)
    {
        // Start travel towards event location
        curVehicle->getVehicleLocation().setInTransitFalse();
        curVehicle->getVehicleLocation().moveLocationWrapper(curEvent->getLocation());

        // Wait until vehicle arrives at event location
        while(Location::calculateDistance(curVehicle->getVehicleLocation(), curEvent->getLocation()) != 0);

        // Sleep for duration of event
        std::this_thread::sleep_for(std::chrono::milliseconds(curEvent->getDurationSeconds()) );

        // Set vehicle to available on bitArray
        bitArray->modifyBitArray(curVehicle->getVehicleID(), false);

        // Start moving vehicle back to home station
        curVehicle->getVehicleLocation().moveLocationWrapper(curVehicle->getHomeFireStation().getFireStationLocation());

        // Allow for slight delay to ensure inTransit is set to True
        std::this_thread::sleep_for(std::chrono::milliseconds(1) );

        // Wait until vehicle arrives back at home station or is dispatched elsewhere
        while(Location::calculateDistance(curVehicle->getVehicleLocation(), curVehicle->getHomeFireStation().getFireStationLocation()) != 0
        || curVehicle->getVehicleLocation().getInTransit());

    }

    void EventFactory::removeEventActiveQueue(uint32_t eventID)
    {
        for (size_t i = 0; i < activeQueue.size(); ++i)
        {
            if (activeQueue[i].getEventID() == eventID)
                activeQueue.erase(activeQueue.begin() + i);
        }
    }


} // LockFreeDispatch