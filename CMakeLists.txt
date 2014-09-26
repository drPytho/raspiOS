################
# CMAKE RULES! #
################
# Huge thanks to mxaddict for setting up the CMake build system!
# we need features that are 2.6 >= dependent
cmake_minimum_required(VERSION 2.6)
# lets name the project
project(RaspiOS)
# add the -c and -Wall flags
add_definitions(
    -c
    -Wall
    -std=c++11
)
if ( CMAKE_BUILD_TYPE STREQUAL "" )
    # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
    # differentiation between debug and release builds.
    set(
        CMAKE_BUILD_TYPE
        "Debug"
        CACHE STRING
        "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) \"Debug\" \"Release\" \"RelWithDebInfo\" \"MinSizeRel\"."
        FORCE
    )
endif ( CMAKE_BUILD_TYPE STREQUAL "" )
if ( CMAKE_BUILD_TYPE STREQUAL "Release" )
    add_definitions( -O2 )
endif ( CMAKE_BUILD_TYPE STREQUAL "Release" )
# Lets LOAD app our headers!
file(GLOB_RECURSE HDRS ${RaspiOS_SOURCE_DIR}/src/*.h)
# Lets LOAD app our sources!
file(GLOB_RECURSE SRCS
    ${RaspiOS_SOURCE_DIR}/src/*.cpp
    ${RaspiOS_SOURCE_DIR}/src/*.cc
    ${RaspiOS_SOURCE_DIR}/src/*.c
)

# Define the executable
add_executable(RaspiOS ${SRCS})
# We need a CMAKE_DIR with some code to find external dependencies
SET(RaspiOS_CMAKE_DIR "${RaspiOS_SOURCE_DIR}/cmake")
#######################################
# LOOK for the packages that we need! #
#######################################
# SDL2
INCLUDE(${RaspiOS_CMAKE_DIR}/FindSDL2.cmake)
# Awesomium
INCLUDE(${RaspiOS_CMAKE_DIR}/FindAwesomium.cmake)
# Define the include DIRs
include_directories(
    ${RaspiOS_SOURCE_DIR}/
    ${RaspiOS_SOURCE_DIR}/src
    ${SDL2_INCLUDE_DIRS}
    ${AWESOMIUM_INCLUDE_DIR}
)
# Define the link libraries
target_link_libraries( RaspiOS
    ${SDL2_LIBRARIES}
    ${AWESOMIUM_LIBRARY}
)
