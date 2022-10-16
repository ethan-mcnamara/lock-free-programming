//
// Created by 17eth on 2022-10-08.
//

#ifndef LOCK_FREE_PROGRAMMING_FIRESTATION_H
#define LOCK_FREE_PROGRAMMING_FIRESTATION_H
#include <cstdint>
#include "../Location/Location.h"

namespace LockFreeDispatch {

    class FireStation {
        private:
            uint32_t fireStationID;
            Location fireStationLocation;
            uint16_t maxNumCrew;
            uint8_t maxNumVehicles;
        public:
            uint16_t curNumCrew;
            uint8_t curNumVehicles;

            uint32_t getFireStationID() const;

            void setFireStationID(uint32_t id);

            Location getFireStationLocation();

            void setFireStationLocation(Location location);

            uint16_t getMaxNumCrew() const;

            void setMaxNumCrew(uint16_t crewNum);

            uint8_t getMaxNumVehicles() const;

            void setMaxNumVehicles(uint8_t vehicleNum);
    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_FIRESTATION_H
