set (SOURCES main.cpp)

add_executable (${CMAKE_PROJECT_NAME} ${SOURCES})

target_link_libraries (${CMAKE_PROJECT_NAME} PUBLIC date_lib)