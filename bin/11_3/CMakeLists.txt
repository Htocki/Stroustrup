cmake_minimum_required (VERSION 3.15)

project ("11_3")

add_executable (${PROJECT_NAME} "src/Main.cpp")

set_target_properties (${PROJECT_NAME}
    PROPERTIES
        set (CMAKE_CXX_STANDARD 17)
        set (CMAKE_CXX_STANDARD_REQUIRED ON)
    )

file (COPY 
        "${PROJECT_SOURCE_DIR}/files" 
    DESTINATION
        "${PROJECT_BINARY_DIR}"
    )