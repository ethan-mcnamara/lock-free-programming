cmake_minimum_required(VERSION 3.24)
project(lock-free-programming)

set(CMAKE_CXX_STANDARD 14)

add_executable(lock-free-programming
        BitArray/BitArray.h
        BitArray/BitArray.cpp
        DistrictResources/DistrictResources.cpp
        DistrictResources/DistrictResources.h
        Event/CriticalSituation.cpp
        Event/CriticalSituation.h
        Event/EventFactory.cpp
        Event/EventFactory.h
        Event/Event.cpp
        Event/Event.h
        Event/Maintenance.cpp
        Event/Maintenance.h
        FireStation/FireStation.cpp
        FireStation/FireStation.h
        Location/Location.cpp
        Location/Location.h
        Time/Time.cpp
        Time/Time.h
        Vehicle/FireEngine.cpp
        Vehicle/FireEngine.h
        Vehicle/FireLadder.cpp
        Vehicle/FireLadder.h
        Vehicle/Vehicle.cpp
        Vehicle/Vehicle.h
        VehicleStatus/VehicleStatus.h
        main.cpp
        )