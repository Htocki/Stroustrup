cmake_minimum_required (VERSION 3.15)

set (SOURCES 
	"src/main.cpp"
	)

project (Straustrup)

add_executable (${PROJECT_NAME} ${SOURCES})

target_link_libraries (${PROJECT_NAME} PUBLIC date)

add_subdirectory ("lib/googletest")
add_subdirectory ("lib/chapter 9/date")

set_target_properties (${PROJECT_NAME}
	PROPERTIES
		set (CMAKE_CXX_STANDARD 17)
		set (CMAKE_CXX_STANDARD_REQUIRED ON)
	)

target_include_directories (${PROJECT_NAME} 
    PRIVATE
        "lib/chapter 9/date/include"
    )