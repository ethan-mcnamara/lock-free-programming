#include <iostream>
#include <cmath>
#include "BitArray.h"

namespace LockFreeDispatch {

    void BitArray::modifyBitArray(int vehicleID, bool writeTrue)
    {
        if (vehicleID < 63)
        {
            uint64_t position = (double_t) std::pow(2.0, (double_t) vehicleID);
            if(writeTrue)
            {
                // Write 1 to vehicle position in array
                globalBitArray[0] |= position;
            }
            else
            {
                // Write 0 to vehicle position in array
                globalBitArray[0] &= ~position;
            }
        }
        else if (vehicleID < 128)
        {
            uint64_t position = (double_t) std::pow(2.0, (double_t) vehicleID);
            if(writeTrue)
            {
                // Write 1 to vehicle position in array
                globalBitArray[1] |= position;
            }
            else
            {
                // Write 0 to vehicle position in array
                globalBitArray[1] &= ~position;
            }
        }
        else
        {
            exit(-1);
        }
    }
} // LockFreeDispatch