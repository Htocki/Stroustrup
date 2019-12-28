set (BINARY Date)

set (INTERFACE
    interface/Date.h
    interface/Year.h
    interface/Month.h
    interface/Day.h
    )

set (SOURCES
    sources/Date.cpp
    sources/Year.cpp
    sources/Month.cpp
    sources/Day.cpp
    )

project (${BINARY})

source_group ("Interface Files" FILES ${INTERFACE})
source_group ("Source Files" FILES ${SOURCES})

add_executable (${BINARY} ${INTERFACE} ${SOURCES})

include_directories (interface)

add_library (${BINARY}_lib STATIC ${INTERFACE} ${SOURCES})