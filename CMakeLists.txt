cmake_minimum_required (VERSION 3.15)

project ("Straustrup")

if (CMAKE_COMPILER_IS_GNUCXX)
  add_definitions (-Wall -pedantic -std=gnu++2a)
endif ()

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include (CTest)
endif ()

enable_testing ()

include (FetchContent)

# google test
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        master
)

FetchContent_GetProperties(googletest)
if (NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory (
    ${googletest_SOURCE_DIR}
    ${googletest_BINARY_DIR}
  )
endif ()

# sfml
set (BUILD_SHARED_LIBS false)

FetchContent_Declare (
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        master
)

FetchContent_GetProperties (sfml)
if (NOT sfml_POPULATED)
  if (LINK_DEPS_STATIC)
    set (SFML_STATIC_LIBRARIES CACHE BOOL TRUE)
  endif ()

  FetchContent_Populate (sfml)
  add_subdirectory (
    ${sfml_SOURCE_DIR} 
    ${sfml_BINARY_DIR}
  )
endif ()

add_subdirectory ("lib/book")
add_subdirectory ("lib/date")
add_subdirectory ("lib/gui")
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