set(TARGET api)

add_library(${TARGET})

target_sources(${TARGET}
    PRIVATE
        dart_api.cpp
    
    PUBLIC
        FILE_SET HEADERS
)

target_link_libraries(${TARGET}
    PRIVATE
        utils
)