cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(Airport VERSION 1.0)

# Add subdirectory of libraries
add_subdirectory(modules)

# Include SFML directory
include_directories(${CMAKE_MODULE_PATH}/SFML)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

# Add the executable
add_executable(airport.app bin/app.cpp)

# Link package SFML and local modules
target_link_libraries(airport.app PUBLIC sfml-graphics 
                                         modules)

# Specify the C++ standart
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
