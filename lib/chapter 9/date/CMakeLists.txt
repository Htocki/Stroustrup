cmake_minimum_required (VERSION 3.15)

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

add_library (${PROJECT_NAME} STATIC ${INCLUDE} ${SOURCES})

set_target_properties (${PROJECT_NAME}
	PROPERTIES
		set (CMAKE_CXX_STANDARD 17)
		set (CMAKE_CXX_STANDARD_REQUIRED ON)
	)