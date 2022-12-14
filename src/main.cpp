#include <iostream>
#include <thread>
#include "DistrictResources/DistrictResources.h"
#include "Event/EventFactory.h"

using namespace LockFreeDispatch;

DistrictResources *districtResources = new DistrictResources();
EventFactory *eventFactory = new EventFactory();
Time *programClock = new Time();
BitArray *globalBitArray = new BitArray();

int main(int argc, char *argv[])
{

    #pragma region commandLineArguments
    // Process command-line arguments
    if (argc != 5)
    {
        exit(-1);
    }
    std::string vehicleListFileName = argv[1];
    std::string fireStationListFileName = argv[2];
    std::string eventListFileName = argv[3];
    std::string vehicleRequirementsListFileName = argv[4];
    #pragma endregion commandLineArguments

    #pragma region readData
    // Read Fire Station data (no dependencies on other files)
    std::thread processFireStationData_thread([a = districtResources, fireStationListFileName]()
    {
        a->processFireStationSampleData(fireStationListFileName);
    });

    // Read Vehicle Requirements data (no dependencies on other files)
    std::thread processVehicleRequirementData_thread([a = districtResources,
                                                      vehicleRequirementsListFileName]()
    {
        a->processVehicleRequirementsSampleData(vehicleRequirementsListFileName);
    });

    // Read Event data (no requirements on other files)
    std::thread processEventData_thread([a = districtResources, eventListFileName, b = eventFactory->pendingQueue]()
    {
        a->processEventSampleData(eventListFileName, eventFactory->pendingQueue);
    });

    processFireStationData_thread.join();

    // Read Vehicle data (dependent on successful processing of Fire Station data)
    std::thread processVehicleData_thread([a = districtResources, vehicleListFileName]()
    {
        a->processVehicleSampleData(vehicleListFileName);
    });

    processVehicleData_thread.join();
    processVehicleRequirementData_thread.join();
    processEventData_thread.join();

    #pragma endregion readData

    #pragma region programClockSetup

    *programClock = LockFreeDispatch::Time::stringToTime("00:00:00:00:00");
    std::thread programClock_thread([a = programClock, b = eventFactory]()
    {
        // Run clock until all events have been dispatched
        while (!b->pendingQueue.empty() && !b->activeQueue.empty())
        {
            a->incrementTimeOneMillisecond();
            std::this_thread::sleep_for( std::chrono::milliseconds(1) );
        }
    });
    programClock_thread.detach();

    #pragma endregion programClockSetup

    #pragma region populateActiveQueue

    std::cout << "pendingQueue size: " << eventFactory->pendingQueue.size() << std::endl;
    std::thread populateActiveQueue_thread([a = eventFactory, b = districtResources, c = globalBitArray]()
    {
        a->populateActiveQueue(programClock, b, c);
    });
    populateActiveQueue_thread.join();

    #pragma endregion populateActiveQueue

    return 0;
}