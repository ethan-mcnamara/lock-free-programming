#include "FireLadder.h"

namespace LockFreeDispatch {
    FireLadder::FireLadder(uint32_t id, Location *location, FireStation station, uint16_t maxCrew, uint16_t curCrew,
                           float maxWater, float curWater, VehicleStatus status, float wFactor)
    {
        setVehicleID(id);
        setVehicleLocation(location);
        setHomeFireStation(station);
        setMaxNumCrew(maxCrew);
        setCurNumCrew(curCrew);
        setMaxWaterVolumeLitres(maxWater);
        setCurWaterVolumeLitres(curWater);
        setCurVehicleStatus(status);
        setWorkFactor(wFactor);


    } // LockFreeDispatch