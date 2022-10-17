#ifndef CMAKE_LOCK_FREE_PROGRAMMING_MAINTENANCE_H
#define CMAKE_LOCK_FREE_PROGRAMMING_MAINTENANCE_H

#include "Event.h"

namespace LockFreeDispatch {

    class Maintenance : public Event {
        private:
            uint32_t vehicleID;
            uint32_t fireStationID;

        public:
        uint32_t getVehicleID() const;

        void setVehicleID(uint32_t id);

        uint32_t getFireStationID() const;

        void setFireStationID(uint32_t id);
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_MAINTENANCE_H
