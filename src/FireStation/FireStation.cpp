#include "FireStation.h"

namespace LockFreeDispatch
{

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

    // Get curNumCrew
    uint16_t FireStation::getCurNumCrew() const
    {
        return curNumCrew;
    }

    // Set curNumCrew
    void FireStation::setCurNumCrew(uint16_t newNumCrew)
    {
        curNumCrew = newNumCrew;
    }

    FireStation::FireStation(uint32_t id, Location location, uint16_t maxCrew, uint16_t curCrew)
    {
        fireStationID = id;
        fireStationLocation = location;
        maxNumCrew = maxCrew;
        curNumCrew = curCrew;
    }

    FireStation::FireStation()
    {
        fireStationID = -1;
        fireStationLocation = Location();
        maxNumCrew = 0;
        curNumCrew = 0;
    }

} // LockFreeDispatch