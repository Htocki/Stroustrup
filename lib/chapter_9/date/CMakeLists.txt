cmake_minimum_required (VERSION 3.15)

set (TEST_SOURCES
    "test/leapyear-test.cpp"
    "test/main.cpp")

set (INCLUDE
    "include/Date.h"
    "include/Year.h"
    "include/Month.h"
    "include/Day.h"
    )

set (SOURCES
    "src/Date.cpp"
    "src/Year.cpp"
    "src/Month.cpp"
    "src/Day.cpp"
    )

project (date)

# Library.
add_library (${PROJECT_NAME} 
    STATIC 
        ${INCLUDE} 
        ${SOURCES} 
        ${TEST_SOURCES}
    )

set_target_properties (${PROJECT_NAME}
	PROPERTIES
		set (CMAKE_CXX_STANDARD 17)
		set (CMAKE_CXX_STANDARD_REQUIRED ON)
	)

target_include_directories (${PROJECT_NAME} 
    PRIVATE
        "include"
        "../../googletest/googletest/include"
    )

# Test for the library.
set (TEST_NAME ${PROJECT_NAME}-test)

add_executable (${TEST_NAME} ${TEST_SOURCES})

add_test (NAME ${TEST_NAME} COMMAND ${TEST_NAME})

target_link_libraries (${TEST_NAME} PUBLIC ${PROJECT_NAME} gtest)

target_include_directories (${TEST_NAME} 
    PRIVATE
       "include"
       "../../googletest/googletest/include"
    )