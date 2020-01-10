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

include_directories ("include")
include_directories ("../../googletest/googletest/include")

add_executable (${PROJECT_NAME}_test ${TEST_SOURCES})
add_test (NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)
target_link_libraries (${PROJECT_NAME}_test PUBLIC ${PROJECT_NAME} gtest)

add_library (${PROJECT_NAME} STATIC ${INCLUDE} ${SOURCES} ${TEST_SOURCES})


set_target_properties (${PROJECT_NAME}
	PROPERTIES
		set (CMAKE_CXX_STANDARD 17)
		set (CMAKE_CXX_STANDARD_REQUIRED ON)
	)
