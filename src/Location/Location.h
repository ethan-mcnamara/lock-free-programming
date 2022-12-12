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

            std::atomic<float> *getXCoord();

            void setXCoord(float coord);

            std::atomic<float> *getYCoord();

            void setYCoord(float coord);

            static double calculateDistance(Location locationA, Location locationB);

            void moveLocationWrapper(Location destination);

            bool getInTransit();

            void setInTransitFalse();
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_LOCATION_H
