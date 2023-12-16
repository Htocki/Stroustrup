cmake_minimum_required (VERSION 3.28)

set (SOURCES
  "ConvertFromUSCToDKK.cpp"
  "ConvertFromUSCToUSD.cpp"
  "ConvertToUSC.cpp"
  "EqualToOperator.cpp"
  "InputOperator.cpp"
  "Main.cpp"
  "OutputOperator.cpp"
)

project ("money-test")

add_executable (${PROJECT_NAME} ${SOURCES})

set_property (TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

add_test (NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries (${PROJECT_NAME} 
  PUBLIC 
    money 
    gtest
)