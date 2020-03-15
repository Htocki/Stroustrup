cmake_minimum_required (VERSION 3.15)

set (SOURCES
	"EqualToOperator.cpp"
	"InputOperator.cpp"
	"Main.cpp"
	"OutputOperator.cpp"
	)

project ("roman_int-test")

add_executable (${PROJECT_NAME} ${SOURCES})

add_test (NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries (${PROJECT_NAME} 
	PUBLIC 
		roman_int
		gtest
	)