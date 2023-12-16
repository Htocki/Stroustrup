cmake_minimum_required (VERSION 3.28)

project ("Straustrup" LANGUAGES CXX)

if (CMAKE_COMPILER_IS_GNUCXX)
  add_definitions (-Wall -pedantic)
endif ()

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include (CTest)
endif ()

enable_testing ()

include (FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

FetchContent_MakeAvailable(googletest)

add_subdirectory ("lib/book")
add_subdirectory ("lib/date")
add_subdirectory ("lib/library")
add_subdirectory ("lib/money")
add_subdirectory ("lib/namepairs")
add_subdirectory ("lib/patron")
add_subdirectory ("lib/rational")
add_subdirectory ("lib/roman_int")

add_subdirectory ("bin/10_1")
add_subdirectory ("bin/10_2")
add_subdirectory ("bin/10_3")
add_subdirectory ("bin/10_4")
add_subdirectory ("bin/10_8")
add_subdirectory ("bin/10_9")
add_subdirectory ("bin/10_11")
add_subdirectory ("bin/11_1")
add_subdirectory ("bin/11_3")
add_subdirectory ("bin/11_4")
add_subdirectory ("bin/11_5")
add_subdirectory ("bin/11_6")
add_subdirectory ("bin/11_7")
add_subdirectory ("bin/11_9")
add_subdirectory ("bin/11_10")
add_subdirectory ("bin/11_12")
add_subdirectory ("bin/11_13")
add_subdirectory ("bin/11_14")
add_subdirectory ("bin/11_15")