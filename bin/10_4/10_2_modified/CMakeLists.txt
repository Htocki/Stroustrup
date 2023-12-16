cmake_minimum_required (VERSION 3.28)

project ("10_2_modified")

add_executable (${PROJECT_NAME} "src/Store_temps.cpp")

set_property (TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)