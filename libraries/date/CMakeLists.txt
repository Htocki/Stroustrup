set (BINARY Date)

set (INTERFACE
    interface/Date.h
    )

set (SOURCES
    sources/Year.h
    sources/Month.h
    sources/Day.h

    sources/Date.cpp
    sources/Year.cpp
    sources/Month.cpp
    sources/Day.cpp
    )

project (${PROJECT})

source_group ("Interface Files" FILES ${INTERFACE})
source_group ("Source Files" FILES ${SOURCES})

add_executable (${BINARY} ${INTERFACE} ${SOURCES})

add_library (${BINARY}_lib STATIC ${INTERFACE} ${SOURCES})