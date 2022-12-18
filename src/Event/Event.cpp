#include "Event.h"

namespace LockFreeDispatch
{

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

    Event::Event()
            : eventID( -1 ), startTime( Time() ), durationSeconds( 0 ),
            dispatched( false ), vehicleRequirementId( -1 ) {}

    // Get eventLocation
    Location Event::getLocation()
    {
        return eventLocation;
    }

    // Set eventLocation
    void Event::setLocation(Location newLocation)
    {
        eventLocation = newLocation;
    }

    // Add new vehicleRequirement
    void Event::addVehicleRequirementId(uint16_t newVehicleRequirementId)
    {
        vehicleRequirementId = newVehicleRequirementId;
    }

    Event::Event(uint32_t id, Time start, uint64_t duration, Location location, uint16_t requirementsId)
                 {
        eventID = id;
        startTime = start;
        durationSeconds = duration;
        eventLocation = location;
        vehicleRequirementId = requirementsId;
        dispatched = false;
    }
} // LockFreeDispatch