# CMake minimum version
cmake_minimum_required(VERSION 3.20)

# Project name
project(PrivateInheritance)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(PrivateInheritance main.cpp)

# Set Visual Studio version-specific settings (if needed)
if(MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MyExecutable)
endif()
