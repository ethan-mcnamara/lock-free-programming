#ifndef LOCK_FREE_PROGRAMMING_BITARRAY_H
#define LOCK_FREE_PROGRAMMING_BITARRAY_H

#include <cstdint>
#include <atomic>

namespace LockFreeDispatch {

    class BitArray {
        public:
            std::atomic_ullong globalBitArray = std::atomic_ullong { 0 };

            uint64_t modifyBitArray(int vehicleID, bool writeTrue);
            bool getVehicleAvailability(int vehicleID);
            void setGlobalBitArray(uint64_t newBitArray);
            uint64_t getGlobalBitArray();

        private:

    };

} // LockFreeDispatch

#endif //LOCK_FREE_PROGRAMMING_BITARRAY_H
