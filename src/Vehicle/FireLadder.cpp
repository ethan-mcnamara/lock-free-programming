#include "FireLadder.h"
#include "../Vehicle/Vehicle.h"
class Vehicle;

namespace LockFreeDispatch {
    FireLadder::FireLadder(uint32_t id1, Location location1, FireStation station1, uint16_t maxCrew1, uint16_t curCrew1,
                           float maxWater1, float curWater1, VehicleStatus status1, float wFactor1) :
                           Vehicle(id1, location1, station1, maxCrew1, curCrew1,
                                   maxWater1, curWater1, status1, wFactor1)
                                   {

                                   }

    FireLadder::FireLadder(uint16_t numCrew1, float volWater1) : Vehicle(numCrew1, volWater1)
    {

    }
}// LockFreeDispatch