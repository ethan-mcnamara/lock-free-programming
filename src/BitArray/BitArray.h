#ifndef LOCK_FREE_PROGRAMMING_BITARRAY_H
#define LOCK_FREE_PROGRAMMING_BITARRAY_H

#include <cstdint>

namespace LockFreeDispatch {

    class BitArray {
        public:
            static void modifyBitArray(int vehicleID, bool writeTrue);

        private:
            static uint64_t globalBitArray [2];


    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_BITARRAY_H
