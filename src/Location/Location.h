#ifndef CMAKE_LOCK_FREE_PROGRAMMING_LOCATION_H
#define CMAKE_LOCK_FREE_PROGRAMMING_LOCATION_H

#include <cstdint>
#include <atomic>

namespace LockFreeDispatch {

    class Location {
        private:
            float xCoord;
            float yCoord;
            bool inTransit;
            void moveLocation(Location destination);

        public:
            Location(float x, float y);

            Location();

            float getXCoord() const;

            void setXCoord(float coord);

            float getYCoord() const;

            void setYCoord(float coord);

            static double calculateDistance(Location *locationA, Location *locationB);

            void moveLocationWrapper(Location destination);

            bool getInTransit();

            void setInTransitFalse();
    };

} // LockFreeDispatch

#endif //CMAKE_LOCK_FREE_PROGRAMMING_LOCATION_H
