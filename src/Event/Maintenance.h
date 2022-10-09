//
// Created by 17eth on 2022-10-08.
//

#ifndef CMAKE_LOCK_FREE_PROGRAMMING_MAINTENANCE_H
#define CMAKE_LOCK_FREE_PROGRAMMING_MAINTENANCE_H

#include "Event.h"

namespace LockFreeDispatch {

    class Maintenance : public Event {
        private:
            uint32_t vehicleID;
            uint32_t fireStationID;

        public:
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_MAINTENANCE_H
