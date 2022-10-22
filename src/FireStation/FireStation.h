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
            uint16_t curNumCrew;
            uint8_t curNumVehicles;

        public:
            uint32_t getFireStationID() const;

            void setFireStationID(uint32_t id);

            Location getFireStationLocation();

            void setFireStationLocation(Location location);

            uint16_t getMaxNumCrew() const;

            void setMaxNumCrew(uint16_t crewNum);

            uint8_t getMaxNumVehicles() const;

            void setMaxNumVehicles(uint8_t vehicleNum);

        uint16_t getCurNumCrew() const;

        void setCurNumCrew(uint16_t newNumCrew);

        uint8_t getCurNumVehicles() const;

        void setCurNumVehicles(uint8_t newNumVehicles);
    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_FIRESTATION_H
