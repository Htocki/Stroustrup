cmake_minimum_required (VERSION 3.28)

set (INCLUDE
  "include/Conversions.h"
  "include/Currency.h"
  "include/Money.h"
)

set (SOURCES
  "src/Conversions.cpp"
  "src/Money.cpp"
)

project ("money")

add_library (${PROJECT_NAME} STATIC ${INCLUDE} ${SOURCES})

set_property (TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

target_include_directories(${PROJECT_NAME}
  PUBLIC 
    $<INSTALL_INTERFACE:include>    
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_subdirectory ("test")