#ifndef CMAKE_LOCK_FREE_PROGRAMMING_FIREENGINE_H
#define CMAKE_LOCK_FREE_PROGRAMMING_FIREENGINE_H

#include "Vehicle.h"

namespace LockFreeDispatch {

    class FireEngine : public Vehicle {
        private:

        public:
            FireEngine(uint32_t id, Location location, FireStation station, uint16_t maxCrew, uint16_t curCrew,
                       float maxWater, float curWater, VehicleStatus status, float wFactor);

    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_FIREENGINE_H
