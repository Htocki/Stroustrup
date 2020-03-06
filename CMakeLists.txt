cmake_minimum_required (VERSION 3.15)

project ("Straustrup")

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
add_subdirectory ("lib/money")
add_subdirectory ("lib/namepairs")
add_subdirectory ("lib/patron")
add_subdirectory ("lib/rational")
add_subdirectory ("lib/sum")

add_subdirectory ("bin/10_1")