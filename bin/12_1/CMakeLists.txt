cmake_minimum_required (VERSION 3.15)

project ("12_1")

add_executable (${PROJECT_NAME} "src/Main.cpp")

set_target_properties (
  ${PROJECT_NAME}
    PROPERTIES
      set (CMAKE_CXX_STANDARD 20)
      set (CMAKE_CXX_STANDARD_REQUIRED ON)
)

find_package (FLTK REQUIRED)

if (FLTK_FOUND)
  target_link_libraries (
    ${PROJECT_NAME}
      PUBLIC
        ${FLTK_LIBRARIES}
  )

else () 
  message ("!!! FLTK is not found.")
endif ()