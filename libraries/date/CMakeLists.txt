cmake_minimum_required (VERSION 3.15)

set (PROJECT Date)

set (INTERFACE
    interface/Date.h
    )

set (SOURCES
    sources/Year.h
    sources/Month.h
    sources/Day.h

    sources/Date.cpp
    sources/Year.cpp
    sources/Month.cpp
    sources/Day.cpp
    sources/main.cpp
    )

project (${PROJECT})

source_group ("Interface Files" FILES ${INTERFACE})
source_group ("Source Files" FILES ${SOURCES})

add_executable (${PROJECT} ${INTERFACE} ${SOURCES})

target_include_directories(${PROJECT} PRIVATE interface)