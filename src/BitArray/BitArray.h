#ifndef LOCK_FREE_PROGRAMMING_BITARRAY_H
#define LOCK_FREE_PROGRAMMING_BITARRAY_H

#include <cstdint>

namespace LockFreeDispatch {

    class BitArray {
        public:
            void modifyBitArray(int vehicleID, bool writeTrue);
            bool getVehicleAvailability(int vehicleID);

        private:
            uint64_t globalBitArray [2];


    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_BITARRAY_H
