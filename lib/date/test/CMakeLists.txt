cmake_minimum_required (VERSION 3.28)

set (SOURCES
  "Day_of_week.cpp"
  "Leapyear.cpp"
  "Main.cpp"
  "Next_sunday.cpp"
  "Next_weekday.cpp"
)

project ("date-test")

add_executable (${PROJECT_NAME} ${SOURCES})

set_property (TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

add_test (NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries (${PROJECT_NAME} 
  PUBLIC 
    date 
    gtest
)