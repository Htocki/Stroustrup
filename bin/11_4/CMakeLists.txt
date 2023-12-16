cmake_minimum_required (VERSION 3.28)

project ("11_4")

add_executable (${PROJECT_NAME} "src/MultiInput.cpp")

set_property (TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
