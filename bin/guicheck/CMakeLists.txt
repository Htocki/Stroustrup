cmake_minimum_required (VERSION 3.15)

project ("guicheck")

add_executable (${PROJECT_NAME} "src/Main.cpp")

set_target_properties (${PROJECT_NAME}
  PROPERTIES
    set (CMAKE_CXX_STANDARD 20)
    set (CMAKE_CXX_STANDARD_REQUIRED ON)
)

target_link_libraries (${PROJECT_NAME} 
  PUBLIC
    window
)