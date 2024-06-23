cmake_minimum_required(VERSION 3.28)
project(vehicle_v2)

set(CMAKE_CXX_STANDARD 17)

add_executable(vehicle_v2 main.cpp
        Header/Vehicle.h
        Header/VehicleOwner.h
        Source/Vehicle.cpp
        Source/VehicleOwner.cpp
        Header/Customer.h
        Source/Customer.cpp)
