project(pagan VERSION 0.1 LANGUAGES C)

add_library(${PROJECT_NAME} STATIC)

set(SOURCES src/pagan_startup.c)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC include)
