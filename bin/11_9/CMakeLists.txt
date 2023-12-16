cmake_minimum_required (VERSION 3.28)

project ("11_9")

add_executable (${PROJECT_NAME} "src/Main.cpp")

set_property (TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)