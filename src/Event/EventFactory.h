#ifndef LOCK_FREE_PROGRAMMING_EVENTFACTORY_H
#define LOCK_FREE_PROGRAMMING_EVENTFACTORY_H

#include <vector>
#include "../Vehicle/Vehicle.h"

namespace LockFreeDispatch {

    class EventFactory {
        private:
            std::vector<Vehicle> vehiclesMeetingRequirements(std::vector<Vehicle> *vehicleReqts, std::vector<Vehicle> *orderedVehicles);

        public:
            void selectVehicles(std::vector<Vehicle> *vehicleReqts, std::vector<Vehicle> *orderedVehicles);
            bool modifyVehicleStatus(std::vector<Vehicle> *vehicleList);

    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_EVENTFACTORY_H
