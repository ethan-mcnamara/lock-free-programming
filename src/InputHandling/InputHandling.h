//
// Created by 17eth on 2022-11-06.
//

#ifndef LOCK_FREE_PROGRAMMING_INPUTHANDLING_H
#define LOCK_FREE_PROGRAMMING_INPUTHANDLING_H

namespace LockFreeDispatch {

    class InputHandling {
    private:
        static string vehicleListFileName;
        static fstream vehicleListFilePointer;
        static string fireStationListFileName;
        static fstream fireStationListPointer;
        static string eventListFileName;
        static fstream eventListFilePointer;
        static string vehicleRequirementsFileName;
        static fstream vehicleRequirementsFilePointer;

    public:
        void setVehicleListFileName(string fileName);
        string getVehicleListFileName();
        void setFireStationListFileName(string fileName);
        string getFireStationListFileName();
        void setEventListFileName(string fileName);
        string getEventListFileName();
        void setVehicleRequirementsFileName(string fileName);
        string getVehicleRequirementsFileName();
        void setVehicleListFilePointer();
        void setFireStationListFilePointer();
        void setEventListFilePointer();
        void setVehicleRequirementsListFilePointer();


    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_INPUTHANDLING_H
