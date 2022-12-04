#include "Location.h"
#include <cmath>

namespace LockFreeDispatch {

    // Get xCoord
    int64_t Location::getXCoord() const
    {
        return xCoord;
    }

    // Set xCoord
    void Location::setXCoord(int64_t coord)
    {
        xCoord = coord;
    }

    // Get yCoord
    int64_t Location::getYCoord() const
    {
        return yCoord;
    }

    // Set yCoord
    void Location::setYCoord(int64_t coord)
    {
        yCoord = coord;
    }

    double Location::calculateDistance(Location locationA, Location locationB) {
        int64_t xDist = locationA.getXCoord() - locationB.getXCoord();
        int64_t yDist = locationA.getYCoord() - locationB.getYCoord();
        double xDistSquared = std::pow((double) xDist, 2.0);
        double yDistSquared = std::pow((double) yDist, 2.0);
        return std::sqrt(xDistSquared + yDistSquared);
    }
} // LockFreeDispatch