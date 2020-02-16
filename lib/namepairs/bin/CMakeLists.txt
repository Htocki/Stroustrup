cmake_minimum_required (VERSION 3.15)

project ("namepairs-bin")

add_executable (${PROJECT_NAME} "Main.cpp")

set_target_properties (${PROJECT_NAME}
	PROPERTIES
		set (CMAKE_CXX_STANDARD 17)
		set (CMAKE_CXX_STANDARD_REQUIRED ON)
	)

target_link_libraries (${PROJECT_NAME} 
	PUBLIC
		namepairs
	)
