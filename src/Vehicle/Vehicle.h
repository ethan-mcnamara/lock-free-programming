//
// Created by 17eth on 2022-10-08.
//

#ifndef CMAKE_LOCK_FREE_PROGRAMMING_VEHICLE_H
#define CMAKE_LOCK_FREE_PROGRAMMING_VEHICLE_H
#include <cstdint>
#include "../Location/Location.h"
#include "../FireStation/FireStation.h"
#include "../VehicleStatus/VehicleStatus.h"

namespace LockFreeDispatch {

    class Vehicle {
    private:
        uint32_t vehicleID;
        Location vehicleLocation;
        FireStation homeFireStation;
        uint16_t maxNumCrew;
        uint16_t curNumCrew;
        float curWaterVolumeLitres;
        float maxWaterVolumeLitres;
    public:
        VehicleStatus curVehicleStatus;

    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_VEHICLE_H
