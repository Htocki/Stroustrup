set (SOURCES
    "leapyear.cpp"
    "day_of_week.cpp"
    "next_sunday.cpp"
    "next_weekday.cpp"
    "main.cpp"
    )

project ("date-test")

add_executable (${PROJECT_NAME} ${SOURCES})

add_test (NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries (${PROJECT_NAME} 
    PUBLIC 
        date 
        gtest
    )