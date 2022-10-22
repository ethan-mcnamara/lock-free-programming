#ifndef LOCK_FREE_PROGRAMMING_VEHICLESTATUS_H
#define LOCK_FREE_PROGRAMMING_VEHICLESTATUS_H


#include <cstdint>
#include <string>

enum class VehicleStatus {
    Available,
    Responding,
    Returning,
    Maintenance,
    Unavailable
};


#endif //LOCK_FREE_PROGRAMMING_VEHICLESTATUS_H
