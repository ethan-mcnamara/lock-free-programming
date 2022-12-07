#include <algorithm>
#include <vector>
#include <iterator>
#include "CriticalSituation.h"

namespace LockFreeDispatch {
    // Get eventLocation
    Location CriticalSituation::getLocation()
    {
        return eventLocation;
    }

    // Set eventLocation
    void CriticalSituation::setLocation(Location newLocation)
    {
        eventLocation = newLocation;
    }

    // Get all vehicleRequirements
    std::vector<Vehicle*> CriticalSituation::getVehicleRequirements()
    {
        return vehicleRequirements;
    }

    // Add new vehicleRequirement
    void CriticalSituation::addVehicleRequirementId(uint16_t newVehicleRequirementId)
    {
        vehicleRequirementId = newVehicleRequirementId;
    }

    // Pop single vehicleRequirement from list
    Vehicle *CriticalSituation::popVehicleRequirement()
    {
        if (vehicleRequirements.empty()) return nullptr;
        Vehicle* toReturn = vehicleRequirements.back();
        vehicleRequirements.pop_back();
        return toReturn;
    }

    // Delete all vehicleRequirements
    void CriticalSituation::deleteVehicleRequirements()
    {
        vehicleRequirements.clear();
    }

    // Find vehicleRequirement
    bool CriticalSituation::findVehicleRequirement(Vehicle *vehicle)
    {
        for (auto requirement : vehicleRequirements)
        {
            if (requirement == vehicle) return true;
        }
        return false;
    }

    CriticalSituation::CriticalSituation() = default;

} // LockFreeDispatch