cmake_minimum_required (VERSION 3.15)

project ("11_11")

set (HEADERS 
  "include/HelpFunctions.h"
  "include/PunctStream.h"
)

set (SOURCES
  "src/HelpFunctions.cpp"
  "src/Main.cpp"
  "src/PunctStream.cpp"
)

add_executable (${PROJECT_NAME} ${HEADERS} ${SOURCES})

set_target_properties (${PROJECT_NAME}
  PROPERTIES
    set (CMAKE_CXX_STANDARD 20)
    set (CMAKE_CXX_STANDARD_REQUIRED ON)
)

target_include_directories (${PROJECT_NAME}
  PUBLIC 
    $<INSTALL_INTERFACE:include>    
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)