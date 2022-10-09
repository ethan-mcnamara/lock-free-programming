//
// Created by 17eth on 2022-10-08.
//

#ifndef CMAKE_LOCK_FREE_PROGRAMMING_EVENT_H
#define CMAKE_LOCK_FREE_PROGRAMMING_EVENT_H

#include "../Time/Time.h"
#include <cstdint>

namespace LockFreeDispatch {

    class Event {
    private:
        uint32_t eventID;
        Time startTime;
        uint64_t durationSeconds;
    public:
        bool dispatched;


    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_EVENT_H
