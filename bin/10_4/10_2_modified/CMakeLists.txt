cmake_minimum_required (VERSION 3.15)

project ("10_2_modified")

add_executable (${PROJECT_NAME} "src/Store_temps.cpp")

set_target_properties (${PROJECT_NAME}
	PROPERTIES
		set (CMAKE_CXX_STANDARD 17)
		set (CMAKE_CXX_STANDARD_REQUIRED ON)
	)