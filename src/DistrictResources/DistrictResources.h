#ifndef LOCK_FREE_PROGRAMMING_DISTRICTRESOURCES_H
#define LOCK_FREE_PROGRAMMING_DISTRICTRESOURCES_H

#include <vector>
#include "../Vehicle/Vehicle.h"

namespace LockFreeDispatch {

    class DistrictResources {
        private:

        public:
            std::vector<Vehicle> districtVehicles;
            std::vector<FireStation> districtFireStations;

    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_DISTRICTRESOURCES_H
