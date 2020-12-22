project(kernel VERSION 0.1 LANGUAGES C)

set(SOURCES src/pagan_startup.c)

add_library(kernel STATIC ${SOURCES})

target_include_directories(kernel PUBLIC include)
