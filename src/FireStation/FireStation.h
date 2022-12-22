#ifndef LOCK_FREE_PROGRAMMING_FIRESTATION_H
#define LOCK_FREE_PROGRAMMING_FIRESTATION_H
#include <cstdint>
#include "../Location/Location.h"

namespace LockFreeDispatch {

    class FireStation {
        private:
            uint32_t fireStationID;
            uint16_t curNumCrew;
            uint16_t maxNumCrew;
            Location fireStationLocation;

        public:
            FireStation(uint32_t id, Location location, uint16_t maxCrew, uint16_t curCrew);

            FireStation();

            uint32_t getFireStationID() const;

            void setFireStationID(uint32_t id);

            Location getFireStationLocation();

            void setFireStationLocation(Location location);

            uint16_t getMaxNumCrew() const;

            void setMaxNumCrew(uint16_t crewNum);

            uint16_t getCurNumCrew() const;

            void setCurNumCrew(uint16_t newNumCrew);
    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_FIRESTATION_H
