#include "Location.h"
#include <cmath>
#include <chrono>
#include <thread>
#include <atomic>

namespace LockFreeDispatch {

    // Get xCoord
    std::atomic<float> *Location::getXCoord()
    {
        return xCoord;
    }

    // Set xCoord
    void Location::setXCoord(float coord)
    {
        xCoord = reinterpret_cast<std::atomic<float> *>(&coord);
    }

    // Get yCoord
    std::atomic<float> *Location::getYCoord()
    {
        return yCoord;
    }

    // Set yCoord
    void Location::setYCoord(float coord)
    {
        yCoord = reinterpret_cast<std::atomic<float> *>(&coord);
    }

    double Location::calculateDistance(Location locationA, Location locationB)
    {
        float xDist = locationA.getXCoord() - locationB.getXCoord();
        float yDist = locationA.getYCoord() - locationB.getYCoord();
        double xDistSquared = std::pow((double) xDist, 2.0);
        double yDistSquared = std::pow((double) yDist, 2.0);
        return std::sqrt(xDistSquared + yDistSquared);
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
    }

    void Location::moveLocation(Location destination)
    {
        // Direction of travel for each axis represented by variable storing either
        // 1 or -1, depending on the direction required to travel in that axis
        // to travel towards the destination/
        // (-1)^0 (false boolean) == 1
        // (-1)^1 (true boolean) == -1
        bool xDirectionOfTravelBool = (destination.getXCoord() - xCoord) < 0;
        float xDirectionOfTravel = (float) std::pow(-1, xDirectionOfTravelBool);
        bool yDirectionOfTravelBool = (destination.getYCoord() - yCoord) < 0;
        float yDirectionOfTravel = (float) std::pow(-1, yDirectionOfTravelBool);

        while (xCoord != destination.getXCoord() && yCoord != destination.getYCoord() && inTransit)
        {
            // Increment the coordinate value by 0.01 in proper direction using CAS
            if (xCoord != destination.getXCoord())
            {
                float oldXCoord;
                float newXCoord;
                do
                {
                    oldXCoord = *xCoord;
                    newXCoord = 0.01 * xDirectionOfTravel;
                }
                while (!xCoord->compare_exchange_weak(oldXCoord, newXCoord));
            }

            if (yCoord != destination.getYCoord())
            {
                float oldYCoord;
                float newYCoord;
                do
                {
                    oldYCoord = *yCoord;
                    newYCoord = 0.01 * yDirectionOfTravel;
                }
                while (!yCoord->compare_exchange_weak(oldYCoord, newYCoord));
            }

            // Sleep for 1 millisecond to simulate travel time
            std::this_thread::sleep_for(std::chrono::milliseconds(1) );
        }
        inTransit = false;
    }

    bool Location::getInTransit()
    {
        return inTransit;
    }

    void Location::setInTransitFalse()
    {
        inTransit = false;
    }
} // LockFreeDispatch