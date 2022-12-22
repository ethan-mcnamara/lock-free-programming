#ifndef CMAKE_LOCK_FREE_PROGRAMMING_FIREENGINE_H
#define CMAKE_LOCK_FREE_PROGRAMMING_FIREENGINE_H

#include "Vehicle.h"
class Vehicle;

namespace LockFreeDispatch {

    class FireEngine : public Vehicle {
        private:

        public:
            FireEngine(uint32_t id1, Location location1, FireStation station1, uint16_t maxCrew1, uint16_t curCrew1,
                       float maxWater1, float curWater1, VehicleStatus status1, float wFactor1);
            FireEngine(uint16_t numCrew, float volWater);

    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_FIREENGINE_H
