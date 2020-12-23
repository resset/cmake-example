cmake_minimum_required(VERSION 3.15)

project(cmini VERSION 0.1 LANGUAGES C)

add_executable(${PROJECT_NAME})

option(USE_PAGAN "Use kernel code" ON)

if(USE_PAGAN)
    add_subdirectory(lib/pagan)
    list(APPEND EXTRA_LIBS pagan)
    target_compile_definitions(${PROJECT_NAME} PRIVATE USE_PAGAN)
endif()

configure_file(version.h.in version.h)
set(SOURCES src/cmini.c)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    "${PROJECT_BINARY_DIR}"
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    ${EXTRA_LIBS}
)

add_custom_target(${PROJECT_NAME}.bin
    COMMAND             ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME} ${PROJECT_NAME}.bin
    DEPENDS             ${PROJECT_NAME}
    WORKING_DIRECTORY   "${CMAKE_BINARY_DIR}"
)
