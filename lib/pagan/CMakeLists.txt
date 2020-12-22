project(pagan VERSION 0.1 LANGUAGES C)

set(SOURCES src/pagan_startup.c)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
