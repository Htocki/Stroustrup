cmake_minimum_required (VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (BINARY Date)

set (HEADERS
    headers/Date.h
    headers/Year.h
    headers/Month.h
    headers/Day.h
    )

set (SOURCES
    sources/Date.cpp
    sources/Year.cpp
    sources/Month.cpp
    sources/Day.cpp
    )

set (LIBRARY_OUTPUT_DIRECTORY "Omrza")

project (${BINARY})

add_executable (${BINARY} ${HEADERS} ${SOURCES})

include_directories (headers)

add_library (${BINARY}_lib STATIC ${HEADERS} ${SOURCES})