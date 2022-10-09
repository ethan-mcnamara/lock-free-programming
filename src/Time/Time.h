//
// Created by 17eth on 2022-10-08.
//

#ifndef LOCK_FREE_PROGRAMMING_TIME_H
#define LOCK_FREE_PROGRAMMING_TIME_H

#include <cstdint>

namespace LockFreeDispatch {

    class Time {
    private:
        uint8_t millisecond;
        uint8_t second;
        uint8_t minute;
        uint8_t hour;
        uint16_t day;

    public:

    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_TIME_H
