#ifndef LOCK_FREE_PROGRAMMING_TIME_H
#define LOCK_FREE_PROGRAMMING_TIME_H

#include <cstdint>
#include <string>

namespace LockFreeDispatch {

    class Time {
    private:
        uint8_t millisecond;
        uint8_t second;
        uint8_t minute;
        uint8_t hour;
        uint16_t day;

    public:
        Time();

        uint8_t getMillisecond() const;

        void setMillisecond(uint8_t digit);

        uint8_t getSecond() const;

        void setSecond(uint8_t digit);

        uint8_t getMinute() const;

        void setMinute(uint8_t digit);

        uint8_t getHour() const;

        void setHour(uint8_t digit);

        uint8_t getDay() const;

        void setDay(uint8_t digit);

        void setTime(uint8_t newDay, uint8_t newHour, uint8_t newMinute, uint8_t newSecond, uint8_t newMillisecond);

        bool isEqual(Time otherTime);

        bool isBefore(Time otherTime) const;

        bool isAfter(Time otherTime) const;

        void printTime() const;

        static Time stringToTime(std::string time);

        void incrementTimeOneMillisecond();
    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_TIME_H
