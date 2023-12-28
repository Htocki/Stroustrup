cmake_minimum_required (VERSION 3.28)

project ("fltk-test")

add_executable (${PROJECT_NAME} "Main.cpp")

set_property (TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

target_include_directories (${PROJECT_NAME}
  PRIVATE
    ${fltk_BINARY_DIR}
    ${fltk_SOURCE_DIR}
)

target_link_libraries (${PROJECT_NAME} PRIVATE fltk)