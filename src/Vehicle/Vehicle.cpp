#include "Vehicle.h"

namespace LockFreeDispatch {

    // Get vehicleID
    uint32_t Vehicle::getVehicleID() const
    {
        return vehicleID;
    }

    // Set vehicleID
    void Vehicle::setVehicleID(uint32_t id)
    {
        vehicleID = id;
    }

    // Get vehicleLocation
    Location Vehicle::getVehicleLocation()
    {
        return vehicleLocation;
    }

    // Set vehicleLocation
    void Vehicle::setVehicleLocation(Location newLocation)
    {
        vehicleLocation = newLocation;
    }

    // Get homeFireStation
    FireStation Vehicle::getHomeFireStation()
    {
        return homeFireStation;
    }

    // Set homeFireStation
    void Vehicle::setHomeFireStation(FireStation station)
    {
        homeFireStation = station;
    }

    // Get maxNumCrew
    uint16_t Vehicle::getMaxNumCrew() const
    {
        return maxNumCrew;
    }

    // Set maxNumCrew
    void Vehicle::setMaxNumCrew(uint16_t newMaxNumCrew)
    {
        maxNumCrew = newMaxNumCrew;
    }

    // Get curNumCrew
    uint16_t Vehicle::getCurNumCrew() const
    {
        return curNumCrew;
    }

    // Set curNumCrew
    void Vehicle::setCurNumCrew(uint16_t newCurNumCrew)
    {
        curNumCrew = newCurNumCrew;
    }

    // Get curWaterVolumeLitres
    float Vehicle::getCurWaterVolumeLitres() const
    {
        return curWaterVolumeLitres;
    }

    // Set curWaterVolumeLitres
    void Vehicle::setCurWaterVolumeLitres(float volume)
    {
        curWaterVolumeLitres = volume;
    }

    // Get maxWaterVolumeLitres
    float Vehicle::getMaxWaterVolumeLitres() const
    {
        return maxWaterVolumeLitres;
    }

    // Set maxWaterVolumeLitres
    void Vehicle::setMaxWaterVolumeLitres(float volume)
    {
        maxWaterVolumeLitres = volume;
    }

    // Get curVehicleStatus
    VehicleStatus Vehicle::getCurVehicleStatus()
    {
        return curVehicleStatus;
    }

    // Set curVehicleStatus
    void Vehicle::setCurVehicleStatus(VehicleStatus newStatus)
    {
        curVehicleStatus = newStatus;
    }

    float Vehicle::getWorkFactor() const
    {
        return workFactor;
    }

    void Vehicle::setWorkFactor(float newWorkFactor)
    {
        workFactor = newWorkFactor;
    }

    Vehicle::Vehicle(uint32_t id, Location location, FireStation station, uint16_t maxCrew, uint16_t curCrew,
                     float maxWater, float curWater, VehicleStatus status, float wFactor) {
        vehicleID = id;
        vehicleLocation = location;
        homeFireStation = station;
        maxNumCrew = maxCrew;
        curNumCrew = curCrew;
        maxWaterVolumeLitres = maxWater;
        curWaterVolumeLitres = curWater;
        curVehicleStatus = status;
        workFactor = wFactor;
    }

    Vehicle::Vehicle(uint16_t numCrew, float volWater) {
        vehicleID = -1;
        vehicleLocation = Location();
        homeFireStation = FireStation();
        maxNumCrew = numCrew;
        curNumCrew = numCrew;
        maxWaterVolumeLitres = volWater;
        curWaterVolumeLitres = volWater;
        curVehicleStatus = VehicleStatus::Available;
        workFactor = 0;
    }


} // LockFreeDispatch