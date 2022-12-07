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
        bool dispatched;
    public:
        Event();

        uint32_t getEventID() const;

        void setEventID(uint32_t id);

        Time getStartTime();

        void setStartTime(Time time);

        uint64_t getDurationSeconds() const;

        void setDurationSeconds(uint64_t duration);

        bool getDispatched() const;

        void setDispatched(bool dispatchStatus);
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_EVENT_H
