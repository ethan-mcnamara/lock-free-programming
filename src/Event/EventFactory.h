#ifndef LOCK_FREE_PROGRAMMING_EVENTFACTORY_H
#define LOCK_FREE_PROGRAMMING_EVENTFACTORY_H

#include <vector>
#include "../Vehicle/Vehicle.h"
#include "../BitArray/BitArray.h"

namespace LockFreeDispatch {

    class EventFactory {
        private:

            std::vector<Vehicle> vehiclesMeetingRequirements(std::vector<Vehicle> *vehicleReqts, std::vector<Vehicle> *orderedVehicles);
            float calculateAverageWorkFactor(std::vector<Vehicle> vehicleList);

        public:
            std::vector<Event> pendingQueue;

            std::vector<Event> activeQueue;

            void selectVehicles(std::vector<Vehicle> *vehicleReqts, std::vector<Vehicle> *orderedVehicles,
                                BitArray *bitArray);
            bool modifyVehicleStatus(std::vector<Vehicle> *vehicleList, BitArray *bitArray);

    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_EVENTFACTORY_H
