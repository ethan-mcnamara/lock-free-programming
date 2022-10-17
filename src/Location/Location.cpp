#include "Location.h"

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
} // LockFreeDispatch