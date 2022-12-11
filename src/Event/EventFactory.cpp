#include "EventFactory.h"
#include "../VehicleStatus/VehicleStatus.h"
#include <type_traits>
#include <atomic>
#include <iostream>

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

    void EventFactory::selectVehicles(std::vector<Vehicle> *vehicleReqts, std::vector<Vehicle> *orderedVehicles) {
        // TODO - implement function
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


} // LockFreeDispatch