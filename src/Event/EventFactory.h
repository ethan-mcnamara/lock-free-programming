#ifndef LOCK_FREE_PROGRAMMING_EVENTFACTORY_H
#define LOCK_FREE_PROGRAMMING_EVENTFACTORY_H

#include <vector>
#include "../Vehicle/Vehicle.h"
#include "../BitArray/BitArray.h"
#include "../DistrictResources/DistrictResources.h"

namespace LockFreeDispatch {

    class EventFactory {
        private:

            std::vector<Vehicle *> vehiclesMeetingRequirements(
                    std::vector<Vehicle *> vehicleReqts, std::vector<Vehicle *> orderedVehicles);
            float calculateAverageWorkFactor(std::vector<Vehicle *> vehicleList);

        public:
            std::vector<Event> pendingQueue;

            std::vector<Event> activeQueue;

            std::vector<Vehicle *>
            selectVehicles(std::vector<Vehicle *> vehicleReqts, std::vector<Vehicle *> orderedVehicles,
                           BitArray *bitArray);

            bool modifyVehicleStatus(std::vector<Vehicle *> vehicleList, BitArray *bitArray);

            void populateActiveQueue(Time *programClock, DistrictResources *districtResources, BitArray *bitArray);

            void processEvent(Event *curEvent, DistrictResources *districtResources, BitArray *bitArray);

            void processVehicle(Vehicle *curVehicle, Event *curEvent, BitArray *bitArray);

            void removeEventActiveQueue(uint32_t eventID);

    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_EVENTFACTORY_H
