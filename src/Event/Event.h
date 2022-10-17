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


        uint32_t getEventID() const;

        void setEventID(uint32_t id);

        Time getStartTime();

        void setStartTime(Time time);

        uint64_t getDurationSeconds() const;

        void setDurationSeconds(uint64_t duration);
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_EVENT_H
