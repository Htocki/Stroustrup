cmake_minimum_required (VERSION 3.15)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (SOURCES src/main.cpp)

project (Straustrup)

include_directories (lib/date/include)

add_executable (${CMAKE_PROJECT_NAME} ${SOURCES})

target_link_libraries (${CMAKE_PROJECT_NAME} PUBLIC date)

add_subdirectory (lib/googletest)
add_subdirectory (lib/date)