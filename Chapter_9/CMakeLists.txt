cmake_minimum_required (VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (PROJECT Chapter_9)

set (HEADERS
    includes/Date.hpp
    includes/Year.hpp
    includes/Month.hpp
    includes/Day.hpp
    )

set (SOURCES
    sources/Date.cpp
    sources/Year.cpp
    sources/Month.cpp
    sources/Day.cpp
    sources/main.cpp
    )

project (${PROJECT})

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_executable (${PROJECT} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT} PRIVATE /)