//
// Created by 17eth on 2022-10-08.
//

#ifndef LOCK_FREE_PROGRAMMING_VEHICLESTATUS_H
#define LOCK_FREE_PROGRAMMING_VEHICLESTATUS_H


#include <cstdint>
#include <string>

class VehicleStatus {
    private:

    public:
        uint8_t status;

    std::string toString() const
    {
        switch(status)
        {
            case 0:
                return "Available";
            case 1:
                return "Responding";
            case 2:
                return "Returning";
            case 3:
                return "Maintenance";
            default:
                return "Unknown";
        }
    }
};


#endif //LOCK_FREE_PROGRAMMING_VEHICLESTATUS_H
