#include <cmath>
#include <atomic>
#include "BitArray.h"

namespace LockFreeDispatch
{

    uint64_t BitArray::modifyBitArray(int vehicleID, bool writeTrue)
    {
        uint64_t position = (double_t) std::pow(2.0, (double_t) vehicleID);
        uint64_t copyGlobalBitArray  = globalBitArray;
        if(writeTrue)
        {
            // Write 1 to vehicle position in array
            copyGlobalBitArray |= position;
        }
        else
        {
            // Write 0 to vehicle position in array
            copyGlobalBitArray &= ~position;
        }
        return copyGlobalBitArray;
    }

    bool BitArray::getVehicleAvailability(int vehicleID)
    {
        uint64_t position = (double_t) std::pow(2.0, (double_t) vehicleID);
        return globalBitArray & position;
    }

    void BitArray::setGlobalBitArray(uint64_t newBitArray)
    {
        globalBitArray = newBitArray;
    }

    uint64_t BitArray::getGlobalBitArray()
    {
        return globalBitArray;
    }

} // LockFreeDispatch