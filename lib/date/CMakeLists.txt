cmake_minimum_required (VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (BINARY date)

set (INCLUDE
    include/Date.h
    )

set (SOURCES
    sources/Date.cpp
    )

project (${BINARY})

include_directories (include)

add_library (${BINARY}_lib STATIC ${INCLUDE} ${SOURCES})