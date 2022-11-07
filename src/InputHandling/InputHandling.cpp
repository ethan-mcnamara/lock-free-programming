//
// Created by 17eth on 2022-11-06.
//

#include "InputHandling.h"

namespace LockFreeDispatch {

    // Set vehicleListFileName
    void InputHandling::setVehicleListFileName(string fileName)
    {
        vehicleListFileName = fileName;
    }

    // Get vehicleListFileName
    string InputHandling::getVehicleListFileName()
    {
        return vehicleListFileName;
    }

    // Set fireStationListFileName
    void InputHandling::setFireStationListFileName(string fileName)
    {
        fireStationListFileName = fileName;
    }

    // Get fireStationListFileName
    string InputHandling::getFireStationListFileName()
    {
        return fireStationListFileName;
    }

    // Set eventListFileName
    void InputHandling::setEventListFileName(string fileName)
    {
        eventListFileName = fileName;
    }

    // Get eventListFileName
    string InputHandling::getEventListFileName()
    {
        return eventListFileName;
    }

    // Set vehicleRequirementsFileName
    void InputHandling::setVehicleRequirementsFileName(string fileName)
    {
        vehicleRequirementsFileName = fileName;
    }

    // Get vehicleRequirementsFileName
    string InputHandling::getVehicleRequirementsFileName()
    {
        return vehicleRequirementsFileName;
    }

    // Set vehicleListFilePointer
    void InputHandling::setVehicleListFilePointer()
    {
        vehicleListFilePointer.open(vehicleListFileName, ios::in);
    }

    // Set fireStationListFilePointer
    void InputHandling::setFireStationListFilePointer()
    {
        fireStationListPointer.open(fireStationListFileName, ios::in);
    }

    // Set eventListFilePointer
    void InputHandling::setEventListFilePointer()
    {
        eventListFilePointer.open(eventListFileName, ios::in);
    }

    // Set vehicleRequirementsListFilePointer
    void InputHandling::setVehicleRequirementsListFilePointer()
    {
        vehicleRequirementsFilePointer.open(vehicleRequirementsFileName, ios::in);
    }
} // LockFreeDispatch