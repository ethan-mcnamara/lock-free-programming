#include "Location.h"
#include <cmath>
#include <chrono>
#include <thread>
#include <atomic>
#include <iostream>

namespace LockFreeDispatch
{

    // Get xCoord
    float Location::getXCoord() const
    {
        return xCoord;
    }

    // Set xCoord
    void Location::setXCoord(float coord)
    {
        xCoord = coord;
    }

    // Get yCoord
    float Location::getYCoord() const
    {
        return yCoord;
    }

    // Set yCoord
    void Location::setYCoord(float coord)
    {
        yCoord = coord;
    }

    void Location::moveLocationWrapper(Location destination)
    {
        // Create a thread to start the process of moving the vehicle.
        // Thread will run in background as no call to thread.join is ever made.
        // Thread will return when travel has stopped
        // If, during Vehicle's travel, it is rerouted elsewhere,
        // the inTransit variable will be set to false for some time which will cause the thread to return.
        // `moveLocation` is a private function and is never called outside this wrapper function.
        inTransit = true;
        std::thread moveLocation_thread([destination, this]()
        {
            moveLocation(destination);
        });
        moveLocation_thread.detach();
    }

    void Location::moveLocation(Location destination)
    {
        // Direction of travel for each axis represented by variable storing either
        // 1 or -1, depending on the direction required to travel in that axis
        // to travel towards the destination/
        // (-1)^0 (false boolean) == 1
        // (-1)^1 (true boolean) == -1
        bool xDirectionOfTravelBool = (destination.getXCoord() - xCoord) < 0;
        float xDirectionOfTravel = std::pow(-1, xDirectionOfTravelBool);
        bool yDirectionOfTravelBool = (destination.getYCoord() - yCoord) < 0;
        float yDirectionOfTravel = std::pow(-1, yDirectionOfTravelBool);

        while (xCoord != destination.getXCoord() && yCoord != destination.getYCoord() && inTransit)
        {
            xCoord += 0.01 * xDirectionOfTravel;
            yCoord += 0.01 * yDirectionOfTravel;

            // Sleep for 1 millisecond to simulate travel time
            std::this_thread::sleep_for(std::chrono::milliseconds(1) );
        }
        inTransit = false;
    }

    bool Location::getInTransit() const
    {
        return inTransit;
    }

    void Location::setInTransitFalse()
    {
        inTransit = false;
    }

    Location::Location(float x, float y)
    {
        xCoord = x;
        yCoord = y;
        inTransit = false;
    }

    Location::Location()
    {
        xCoord = 0;
        yCoord = 0;
        inTransit = false;
    }

    double Location::calculateDistance(const Location &locationA, const Location &locationB)
    {
        float xDist = locationA.getXCoord() - locationB.getXCoord();
        float yDist = locationA.getYCoord() - locationB.getYCoord();
        double xDistSquared = std::pow(xDist, 2.0);
        double yDistSquared = std::pow(yDist, 2.0);
        return std::sqrt(xDistSquared + yDistSquared);
    }

} // LockFreeDispatch