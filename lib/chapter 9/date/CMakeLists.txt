cmake_minimum_required (VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (BINARY date)

set (INTERFACE
    "interface/Date.h"
    "interface/Year.h"
    "interface/Month.h"
    "interface/Day.h"
    )

set (REALIZATION
    "realization/Date.cpp"
    "realization/Year.cpp"
    "realization/Month.cpp"
    "realization/Day.cpp"
    )

project (${BINARY})

include_directories ("interface")

add_library (${BINARY} STATIC ${INTERFACE} ${REALIZATION})