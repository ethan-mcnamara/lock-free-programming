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
        VehicleStatus curVehicleStatus;
        float workFactor;
    public:
        Vehicle(uint32_t id, Location location, FireStation station, uint16_t maxCrew, uint16_t curCrew,
                         float maxWater, float curWater, VehicleStatus status, float wFactor);

        Vehicle(uint16_t numCrew, float volWater);

        uint32_t getVehicleID() const;

        void setVehicleID(uint32_t id);

        Location getVehicleLocation();

        void setVehicleLocation(Location newLocation);

        FireStation getHomeFireStation();

        void setHomeFireStation(FireStation station);

        uint16_t getMaxNumCrew() const;

        void setMaxNumCrew(uint16_t newMaxNumCrew);

        uint16_t getCurNumCrew() const;

        void setCurNumCrew(uint16_t newCurNumCrew);

        float getCurWaterVolumeLitres() const;

        void setCurWaterVolumeLitres(float volume);

        float getMaxWaterVolumeLitres() const;

        void setMaxWaterVolumeLitres(float volume);

        VehicleStatus getCurVehicleStatus();

        void setCurVehicleStatus(VehicleStatus newStatus);

        float getWorkFactor() const;

        void setWorkFactor(float newWorkFactor);
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_VEHICLE_H
