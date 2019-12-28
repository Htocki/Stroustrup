cmake_minimum_required (VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (PROJECT Straustrup)

project (${PROJECT})

add_subdirectory (sources)
add_subdirectory (libraries/googletest)
add_subdirectory (libraries/date)