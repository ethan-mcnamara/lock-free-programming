//
// Created by 17eth on 2022-10-08.
//

#ifndef CMAKE_LOCK_FREE_PROGRAMMING_LOCATION_H
#define CMAKE_LOCK_FREE_PROGRAMMING_LOCATION_H

#include <cstdint>

namespace LockFreeDispatch {

    class Location {
        private:
            int64_t xCoord;
            int64_t yCoord;

        public:

        int64_t getXCoord() const;

        void setXCoord(int64_t coord);

        int64_t getYCoord() const;

        void setYCoord(int64_t coord);
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_LOCATION_H
