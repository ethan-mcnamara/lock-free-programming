cmake_minimum_required(VERSION 3.24)
project(lock-free-programming)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(lock-free-programming
        BitArray/BitArray.cpp
        DistrictResources/DistrictResources.cpp
        Event/EventFactory.cpp
        Event/Event.cpp
        FireStation/FireStation.cpp
        Location/Location.cpp
        Time/Time.cpp
        Vehicle/FireEngine.cpp
        Vehicle/FireLadder.cpp
        Vehicle/Vehicle.cpp
        main.cpp
        )