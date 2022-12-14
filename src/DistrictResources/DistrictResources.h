#ifndef LOCK_FREE_PROGRAMMING_DISTRICTRESOURCES_H
#define LOCK_FREE_PROGRAMMING_DISTRICTRESOURCES_H

#include <vector>
#include <unordered_map>
#include <memory>
#include "../Vehicle/Vehicle.h"
#include "../Event/Event.h"

namespace LockFreeDispatch {

    class DistrictResources {
        private:
            std::vector< std::unique_ptr< Vehicle > > districtVehicles;
            std::vector< std::unique_ptr < FireStation > > districtFireStations;
            std::unordered_map<uint32_t, std::vector<Vehicle>> vehicleRequirements;

        public:
            void populateDistrictVehicles(const std::vector<Vehicle>& vehicles);
            void populateDistrictFireStations(const std::vector<FireStation>& stations);
            FireStation findFireStation(uint32_t fireStationID);
            void processVehicleSampleData(const std::string& fileName);
            void processFireStationSampleData(const std::string& fileName);
            void processEventSampleData(const std::string &fileName, std::vector<Event> *pendingQueue);
            void processVehicleRequirementsSampleData(const std::string &fileName);
            std::vector<Vehicle> *getVehicleRequirements(uint32_t eventID);
            std::vector<Vehicle> *getOrderedVehicleList(Location *eventLocation);
    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_DISTRICTRESOURCES_H
