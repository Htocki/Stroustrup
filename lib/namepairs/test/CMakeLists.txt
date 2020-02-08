cmake_minimum_required (VERSION 3.15)

set (SOURCES
	"main.cpp"
	"operatorEq.cpp"
	"operatorNotEq.cpp"
	)

project ("namepairs-test")

add_executable (${PROJECT_NAME} ${SOURCES})

add_test (NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries (${PROJECT_NAME} 
	PUBLIC 
		namepairs 
		gtest
	)