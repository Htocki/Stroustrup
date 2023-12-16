cmake_minimum_required (VERSION 3.28)

project ("10_3")

add_executable (${PROJECT_NAME} "src/Temp_stats.cpp")

set_property (TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

file (REMOVE "${PROJECT_BINARY_DIR}/files")

file (
  COPY "${PROJECT_SOURCE_DIR}/files" 
  DESTINATION "${PROJECT_BINARY_DIR}"
)