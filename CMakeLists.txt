cmake_minimum_required (VERSION 3.15)

set (SOURCES 
	"src/Main.cpp"
	)

project ("Straustrup")

add_executable (${PROJECT_NAME} ${SOURCES})

set_target_properties (${PROJECT_NAME}
	PROPERTIES
		set (CMAKE_CXX_STANDARD 17)
		set (CMAKE_CXX_STANDARD_REQUIRED ON)
	)

target_link_libraries (${PROJECT_NAME} 
	PUBLIC
		book
		date
		library
		namepairs
		patron
		rational
	)

add_subdirectory ("lib/googletest")
add_subdirectory ("lib/book")
add_subdirectory ("lib/date")
add_subdirectory ("lib/library")
add_subdirectory ("lib/money")
add_subdirectory ("lib/namepairs")
add_subdirectory ("lib/patron")
add_subdirectory ("lib/rational")