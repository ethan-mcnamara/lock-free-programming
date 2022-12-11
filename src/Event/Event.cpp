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

    Event::Event() = default;

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

    // Get all vehicleRequirements
    std::vector<Vehicle*> Event::getVehicleRequirements()
    {
        return vehicleRequirements;
    }

    // Add new vehicleRequirement
    void Event::addVehicleRequirementId(uint16_t newVehicleRequirementId)
    {
        vehicleRequirementId = newVehicleRequirementId;
    }

    // Pop single vehicleRequirement from list
    Vehicle *Event::popVehicleRequirement()
    {
        if (vehicleRequirements.empty()) return nullptr;
        Vehicle* toReturn = vehicleRequirements.back();
        vehicleRequirements.pop_back();
        return toReturn;
    }

    // Delete all vehicleRequirements
    void Event::deleteVehicleRequirements()
    {
        vehicleRequirements.clear();
    }

    // Find vehicleRequirement
    bool Event::findVehicleRequirement(Vehicle *vehicle)
    {
        for (auto requirement : vehicleRequirements)
        {
            if (requirement == vehicle) return true;
        }
        return false;
    }
} // LockFreeDispatch