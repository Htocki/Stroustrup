cmake_minimum_required (VERSION 3.15)

set (SOURCES
	"Sum.cpp"
	"Main.cpp"
	)

project ("sum-test")

add_executable (${PROJECT_NAME} ${SOURCES})

add_test (NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries (${PROJECT_NAME} 
	PUBLIC  
		gtest
		sum
	)

file (COPY 
		"${PROJECT_SOURCE_DIR}/files" 
	DESTINATION
		"${PROJECT_BINARY_DIR}"
	)