#include "EventFactory.h"
#include "../VehicleStatus/VehicleStatus.h"
#include <type_traits>
#include <atomic>
#include <iostream>
#include <cmath>

namespace LockFreeDispatch {


    std::vector<Vehicle> EventFactory::vehiclesMeetingRequirements(std::vector<Vehicle> *vehicleReqts,
                                                                   std::vector<Vehicle> *orderedVehicles) {
        std::vector<Vehicle> meetingRequirements;

        for (auto vehicle : *orderedVehicles)
        {
            for (auto reqt : *vehicleReqts)
            {
                // TODO - should confirm the Engine/Ladder type
                if (vehicle.getCurNumCrew() >= reqt.getCurNumCrew()
                    && vehicle.getCurWaterVolumeLitres() >= reqt.getCurWaterVolumeLitres())
                {
                    meetingRequirements.push_back(vehicle);
                }
            }
        }
        return meetingRequirements;
    }

    void EventFactory::selectVehicles(std::vector<Vehicle> *vehicleReqts, std::vector<Vehicle> *orderedVehicles,
                                      BitArray *bitArray) {
        while (true)
        {
            std::vector<Vehicle> selectedVehicles;
            uint8_t numVehiclesRequired = vehicleReqts->size();
            std::vector<Vehicle> listSubset = vehiclesMeetingRequirements(vehicleReqts, orderedVehicles);
            float avgWorkFactor = calculateAverageWorkFactor(listSubset);

            for (auto vehicle : listSubset)
            {
                if (vehicle.getWorkFactor() >= avgWorkFactor)
                {
                    if (vehicle.getCurVehicleStatus() == VehicleStatus::Available
                    || vehicle.getCurVehicleStatus() == VehicleStatus::Returning)
                    {
                        selectedVehicles.push_back(vehicle);
                        --numVehiclesRequired;
                    }
                }
                if (numVehiclesRequired == 0)
                {
                    if (modifyVehicleStatus(&selectedVehicles, bitArray))
                    {
                        return;
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
            for (auto vehicle : *orderedVehicles) {
                if (vehicle.getCurVehicleStatus() == VehicleStatus::Available
                    || vehicle.getCurVehicleStatus() == VehicleStatus::Returning) {
                    selectedVehicles.push_back(vehicle);
                    --numVehiclesRequired;
                }
                if (numVehiclesRequired == 0)
                {
                    if (modifyVehicleStatus(&selectedVehicles, bitArray))
                    {
                        return;
                    }
                }
            }
            // See, it's friendly :)
            tryAgain:;
        }
    }

    bool EventFactory::modifyVehicleStatus(std::vector<Vehicle> *vehicleList, BitArray *bitArray) {
        BitArray unmodifiedBitArray;
        unmodifiedBitArray.setGlobalBitArray(bitArray->getGlobalBitArray());
        BitArray modifiedBitArray;
        modifiedBitArray.setGlobalBitArray(bitArray->getGlobalBitArray());

        for (auto vehicle : *vehicleList)
        {
            if (vehicle.getCurVehicleStatus() == VehicleStatus::Available
            || vehicle.getCurVehicleStatus() == VehicleStatus::Returning)
            {
                modifiedBitArray.setGlobalBitArray(modifiedBitArray.modifyBitArray(vehicle.getVehicleID(), true));
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
            for (auto vehicle : *vehicleList)
            {
                vehicle.setCurVehicleStatus(VehicleStatus::Responding);
            }
            return true;
        }
        return false;
    }

    float EventFactory::calculateAverageWorkFactor(std::vector<Vehicle> vehicleList) {
        float listSize = vehicleList.size();
        float workFactorSum = 0;
        for (auto vehicle : vehicleList)
        {
            workFactorSum += vehicle.getWorkFactor();
        }
        return workFactorSum / listSize;
    }


} // LockFreeDispatch