set(TARGET bin)

add_library(${TARGET})

target_sources(${TARGET}
    PRIVATE
        console.cpp
        dart_utils.cpp
        dart_front_end.cpp
        dart_utils.cpp
        options.cpp
        platform.cpp
        run.cpp
    
    PUBLIC
        FILE_SET HEADERS
)

target_link_libraries(${TARGET}
    PRIVATE
        api
        platform
        utils
)