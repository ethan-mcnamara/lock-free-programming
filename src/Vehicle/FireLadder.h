#ifndef CMAKE_LOCK_FREE_PROGRAMMING_FIRELADDER_H
#define CMAKE_LOCK_FREE_PROGRAMMING_FIRELADDER_H

#include "Vehicle.h"

namespace LockFreeDispatch {

    class FireLadder : public Vehicle {
        private:

        public:
        FireLadder(uint32_t id1, Location location1, FireStation station1, uint16_t maxCrew1, uint16_t curCrew1,
                   float maxWater1, float curWater1, VehicleStatus status1, float wFactor1);

        FireLadder(uint16_t numCrew1, float volWater1);

    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_FIRELADDER_H
