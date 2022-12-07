#include "Maintenance.h"

namespace LockFreeDispatch {

    // Get vehicleID
    uint32_t Maintenance::getVehicleID() const
    {
        return vehicleID;
    }

    // Set vehicleID
    void Maintenance::setVehicleID(uint32_t id)
    {
        vehicleID = id;
    }

    // Get fireStationID
    uint32_t Maintenance::getFireStationID() const
    {
        return fireStationID;
    }

    // Set fireStationID
    void Maintenance::setFireStationID(uint32_t id)
    {
        fireStationID = id;
    }

    Maintenance::Maintenance() = default;
} // LockFreeDispatch