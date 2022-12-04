#ifndef LOCK_FREE_PROGRAMMING_DISTRICTRESOURCES_H
#define LOCK_FREE_PROGRAMMING_DISTRICTRESOURCES_H

#include <vector>
#include "../Vehicle/Vehicle.h"

namespace LockFreeDispatch {

    class DistrictResources {
        private:
            std::vector<Vehicle> districtVehicles;
            std::vector<FireStation> districtFireStations;

        public:
            void populateDistrictVehicles(const std::vector<Vehicle>& vehicles);
            void populateDistrictFireStations(const std::vector<FireStation>& stations);
            FireStation findFireStation(uint32_t fireStationID);
            void processVehicleSampleData(const std::string& fileName);
            void processFireStationSampleData(const std::string& fileName);

    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_DISTRICTRESOURCES_H
