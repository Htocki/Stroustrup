cmake_minimum_required (VERSION 3.15)

set (SOURCES
	"AdditionOperator.cpp"
	"DivisionOperator.cpp"
	"EqualOperator.cpp"
	"Main.cpp"
	"MultiplicationOperator.cpp"
	"SubtractionOperator.cpp"
	"ToDouble.cpp"
	)

project ("rational-test")

add_executable (${PROJECT_NAME} ${SOURCES})

add_test (NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries (${PROJECT_NAME} 
	PUBLIC 
		rational 
		gtest
	)