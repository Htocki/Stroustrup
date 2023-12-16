cmake_minimum_required (VERSION 3.28)

set (SOURCES
  "AdditionOperator.cpp"
  "DivisionOperator.cpp"
  "EqualToOperator.cpp"
  "Main.cpp"
  "MultiplicationOperator.cpp"
  "SubtractionOperator.cpp"
  "ToDouble.cpp"
)

project ("rational-test")

add_executable (${PROJECT_NAME} ${SOURCES})

set_property (TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

add_test (NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries (${PROJECT_NAME} 
  PUBLIC 
    rational 
    gtest
)