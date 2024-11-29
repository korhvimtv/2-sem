cmake_minimum_required(VERSION 3.27)
project(money_tracker)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(money_tracker
        functions.cpp
        header.h
        main.cpp)
