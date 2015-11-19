cmake_minimum_required(VERSION 3.3)
project(Assignment_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Assignment_1.vcxproj
    data.txt
    main.cpp
    Nummers.txt)

add_executable(Assignment_1 ${SOURCE_FILES})