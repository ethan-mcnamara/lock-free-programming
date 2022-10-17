#include "FireStation.h"

namespace LockFreeDispatch {

    // Get fireStationID
    uint32_t FireStation::getFireStationID() const
    {
        return fireStationID;
    }

    // Set fireStationID
    void FireStation::setFireStationID(uint32_t id)
    {
        fireStationID = id;
    }

    // Get fireStationLocation
    Location FireStation::getFireStationLocation()
    {
        return fireStationLocation;
    }

    // Set fireStationLocation
    void FireStation::setFireStationLocation(Location location)
    {
        fireStationLocation = location;
    }

    // Get maxNumCrew
    uint16_t FireStation::getMaxNumCrew() const
    {
        return maxNumCrew;
    }

    // Set maxNumCrew
    void FireStation::setMaxNumCrew(uint16_t crewNum)
    {
        maxNumCrew = crewNum;
    }

    // Get maxNumVehicles
    uint8_t FireStation::getMaxNumVehicles() const
    {
        return maxNumVehicles;
    }

    // Set maxNumVehicles
    void FireStation::setMaxNumVehicles(uint8_t vehicleNum)
    {
        maxNumVehicles = vehicleNum;
    }
} // LockFreeDispatch