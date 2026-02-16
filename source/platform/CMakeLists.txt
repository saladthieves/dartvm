set(TARGET platform)

add_library(${TARGET})

target_sources(${TARGET}
    PRIVATE
        singleton.cpp
    
    PUBLIC
        FILE_SET HEADERS
)