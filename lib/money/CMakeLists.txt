cmake_minimum_required (VERSION 3.15)

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

add_library (${PROJECT_NAME}
	STATIC
		${INCLUDE}
		${SOURCES}
    )

set_target_properties (${PROJECT_NAME}
	PROPERTIES
		set (CMAKE_CXX_STANDARD 17)
		set (CMAKE_CXX_STANDARD_REQUIRED ON)
	)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
	)

add_subdirectory ("test")