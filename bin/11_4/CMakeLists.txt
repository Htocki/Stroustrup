cmake_minimum_required (VERSION 3.15)

project ("11_4")

add_executable (${PROJECT_NAME} "src/MultiInput.cpp")

set_target_properties (${PROJECT_NAME}
    PROPERTIES
        set (CMAKE_CXX_STANDARD 17)
        set (CMAKE_CXX_STANDARD_REQUIRED ON)
    )
