cmake_minimum_required (VERSION 3.17)

project ("11_12")

add_executable (${PROJECT_NAME} "src/Main.cpp")

set_target_properties (${PROJECT_NAME}
  PROPERTIES
    set (CMAKE_CXX_STANDARD 20)
    set (CMAKE_CXX_STANDARD_REQUIRED ON)
)

file (
  COPY 
    "${PROJECT_SOURCE_DIR}/files" 
  DESTINATION
    "${PROJECT_BINARY_DIR}"
)