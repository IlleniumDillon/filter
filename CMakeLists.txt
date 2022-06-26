project(CMakeTemplate)
include_directories(include/)
file(GLOB_RECURSE FILTER_LIB_SRC
        src/*.c
        )
file(GLOB_RECURSE SHARE_LIB_SRC
        share/*.c
        )
add_library(share STATIC ${SHARE_LIB_SRC})
add_library(filter STATIC ${FILTER_LIB_SRC})
add_executable(demo example/main.c)
target_link_libraries(demo filter share)