#ifndef CMAKE_LOCK_FREE_PROGRAMMING_EVENT_H
#define CMAKE_LOCK_FREE_PROGRAMMING_EVENT_H

#include "../Time/Time.h"
#include <cstdint>
#include "Event.h"
#include "../Location/Location.h"
class Vehicle;
#include <vector>

namespace LockFreeDispatch {

    class Event {
    private:
        uint32_t eventID;
        Time startTime;
        uint64_t durationSeconds;
        bool dispatched;
        Location *eventLocation;
        std::vector<Vehicle*> vehicleRequirements;
        uint16_t vehicleRequirementId;
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

        Location *getLocation();

        void setLocation(Location *newLocation);

        std::vector<Vehicle*> getVehicleRequirements();

        void addVehicleRequirementId(uint16_t newVehicleRequirementId);

        Vehicle *popVehicleRequirement();

        void deleteVehicleRequirements();

        bool findVehicleRequirement(Vehicle *vehicle);
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_EVENT_H
