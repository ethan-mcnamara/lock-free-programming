#include <string>
#include "Time.h"

namespace LockFreeDispatch {

    // Get millisecond
    uint8_t Time::getMillisecond() const
    {
        return millisecond;
    }

    // Set millisecond
    void Time::setMillisecond(uint8_t digit)
    {
        millisecond = digit;
    }

    // Get second
    uint8_t Time::getSecond() const
    {
        return second;
    }

    // Set second
    void Time::setSecond(uint8_t digit)
    {
        second = digit;
    }

    // Get minute
    uint8_t Time::getMinute() const
    {
        return minute;
    }

    // Set minute
    void Time::setMinute(uint8_t digit)
    {
        minute = digit;
    }

    // Get hour
    uint8_t Time::getHour() const
    {
        return hour;
    }

    // Set millisecond
    void Time::setHour(uint8_t digit)
    {
        hour = digit;
    }

    // Get day
    uint8_t Time::getDay() const
    {
        return day;
    }

    // Set millisecond
    void Time::setDay(uint8_t digit)
    {
        day = digit;
    }

    // Set time
    void Time::setTime(uint8_t newDay, uint8_t newHour, uint8_t newMinute, uint8_t newSecond, uint8_t newMillisecond)
    {
        day = newDay;
        hour = newHour;
        minute = newMinute;
        second = newSecond;
        millisecond = newMillisecond;
    }

    // isEqual
    bool Time::isEqual(Time otherTime)
    {
        return  (day == otherTime.day) &&
                (hour == otherTime.hour) &&
                (minute == otherTime.minute) &&
                (second == otherTime.second) &&
                (millisecond == otherTime.millisecond);
    }

    // isBefore
    bool Time::isBefore(Time otherTime) const
    {
        if (day < otherTime.day) return true;
        else if (day == otherTime.day)
        {
            if (hour < otherTime.hour) return true;
            else if (hour == otherTime.hour)
            {
                if (minute < otherTime.minute) return true;
                else if (minute == otherTime.minute)
                {
                    if (second < otherTime.second) return second;
                    else if (second == otherTime.second)
                    {
                        if (millisecond < otherTime.millisecond) return true;
                    }
                }
            }
        }
        return false;
    }

    // isAfter
    bool Time::isAfter(Time otherTime) const
    {
        if (day > otherTime.day) return true;
        else if (day == otherTime.day)
        {
            if (hour > otherTime.hour) return true;
            else if (hour == otherTime.hour)
            {
                if (minute > otherTime.minute) return true;
                else if (minute == otherTime.minute)
                {
                    if (second > otherTime.second) return second;
                    else if (second == otherTime.second)
                    {
                        if (millisecond > otherTime.millisecond) return true;
                    }
                }
            }
        }
        return false;
    }

    // printTime
    void Time::printTime() const
    {
        printf("%d:%02d:%02d:%02d:%02d", day, hour, minute, second, millisecond);
    }

    Time Time::stringToTime(std::string time) {
        // TODO - implement function
    }
} // LockFreeDispatch