#ifndef CMAKE_LOCK_FREE_PROGRAMMING_EVENT_H
#define CMAKE_LOCK_FREE_PROGRAMMING_EVENT_H

#include "../Time/Time.h"
#include <cstdint>
#include "Event.h"
#include "../Location/Location.h"
class Vehicle;
#include <vector>
#include <memory>

namespace LockFreeDispatch {

    class Event {
    private:
        uint32_t eventID;
        Time startTime;
        uint64_t durationSeconds;
        bool dispatched;
        Location eventLocation;
        uint16_t vehicleRequirementId;
    public:
        Event();

        Event(uint32_t id, Time start, uint64_t duration, Location location, uint16_t requirementsId);

        uint32_t getEventID() const;

        void setEventID(uint32_t id);

        Time getStartTime();

        void setStartTime(Time time);

        uint64_t getDurationSeconds() const;

        void setDurationSeconds(uint64_t duration);

        bool getDispatched() const;

        void setDispatched(bool dispatchStatus);

        Location getLocation();

        void setLocation(Location newLocation);

        void addVehicleRequirementId(uint16_t newVehicleRequirementId);
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_EVENT_H
