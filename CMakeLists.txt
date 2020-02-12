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

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

include (FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        master
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

add_subdirectory ("lib/book")
add_subdirectory ("lib/date")
add_subdirectory ("lib/library")
add_subdirectory ("lib/namepairs")
add_subdirectory ("lib/patron")
add_subdirectory ("lib/rational")