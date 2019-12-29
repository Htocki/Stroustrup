cmake_minimum_required (VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

project (Straustrup)

add_subdirectory (sources)
add_subdirectory (external/googletest)
add_subdirectory (libraries/date)