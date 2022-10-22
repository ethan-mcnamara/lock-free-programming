#include "Event.h"

namespace LockFreeDispatch {

    // Get eventID
    uint32_t Event::getEventID() const
    {
        return eventID;
    }

    // Set eventID
    void Event::setEventID(uint32_t id)
    {
        eventID = id;
    }

    // Get startTime
    Time Event::getStartTime()
    {
        return startTime;
    }

    // Set startTime
    void Event::setStartTime(Time time)
    {
        startTime = time;
    }

    // Get durationSeconds
    uint64_t Event::getDurationSeconds() const
    {
        return durationSeconds;
    }

    // Set durationSeconds
    void Event::setDurationSeconds(uint64_t duration)
    {
        durationSeconds = duration;
    }

    // Get dispatched
    bool Event::getDispatched() const
    {
        return dispatched;
    }

    // Set dispatched
    void Event::setDispatched(bool dispatchStatus)
    {
        dispatched = dispatchStatus;
    }
} // LockFreeDispatch