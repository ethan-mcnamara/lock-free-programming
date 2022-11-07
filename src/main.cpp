//
// Created by 17eth on 2022-10-08.
//

#include <iostream>
#include <vector>

static std::vector<LockFreeDispatch::Event> pendingEvents;
static std::vector<LockFreeDispatch::Event> activeEvents;
static std::vector<LockFreeDispatch::Vehicle> resourceVehicles;
static std::vector<LockFreeDispatch::FireStation> resourceFireStations;

int main()
{
    std::cout << "Hello World!";
    return 0;
}