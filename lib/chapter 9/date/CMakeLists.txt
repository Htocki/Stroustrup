cmake_minimum_required (VERSION 3.15)

set (INTERFACE
    "interface/Date.h"
    "interface/Year.h"
    "interface/Month.h"
    "interface/Day.h"
    )

set (REALIZATION
    "realization/Date.cpp"
    "realization/Year.cpp"
    "realization/Month.cpp"
    "realization/Day.cpp"
    )

project (date)

include_directories ("interface")

add_library (${PROJECT_NAME} STATIC ${INTERFACE} ${REALIZATION})

set_target_properties (${PROJECT_NAME}
	PROPERTIES
		set (CMAKE_CXX_STANDARD 17)
		set (CMAKE_CXX_STANDARD_REQUIRED ON)
	)