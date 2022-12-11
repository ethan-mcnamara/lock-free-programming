#ifndef CMAKE_LOCK_FREE_PROGRAMMING_LOCATION_H
#define CMAKE_LOCK_FREE_PROGRAMMING_LOCATION_H

#include <cstdint>
#include <atomic>

namespace LockFreeDispatch {

    class Location {
        private:
            std::atomic<float> *xCoord;
            std::atomic<float> *yCoord;
            bool inTransit;
            void moveLocation(Location destination);

        public:

            std::atomic<float> *const getXCoord() const;

            void setXCoord(float coord);

            std::atomic<float> *const getYCoord() const;

            void setYCoord(float coord);

            double calculateDistance(Location locationA, Location locationB);

            void moveLocationWrapper(Location destination);
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_LOCATION_H
