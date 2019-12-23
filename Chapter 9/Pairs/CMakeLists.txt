cmake_minimum_required (VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (PROJECT Pairs)

set (HEADERS
    includes/Name_pairs.h
    )

set (SOURCES
    sources/Name_pairs.cpp
    sources/main.cpp
    )

project (${PROJECT})

source_group ("Header Files" FILES ${HEADERS})
source_group ("Source Files" FILES ${SOURCES})

add_executable (${PROJECT} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT} PRIVATE includes)