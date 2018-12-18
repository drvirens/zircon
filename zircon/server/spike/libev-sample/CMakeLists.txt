cmake_minimum_required(VERSION 3.9)

project(evTestViren VERSION "1.0.0" DESCRIPTION "lib ev test" LANGUAGES CXX)


if (LIBEV_INCLUDE_DIRS AND LIBEV_LIBRARIES) 
else ()
endif ()

find_path(LIBEV_INCLUDE_DIR
    NAMES ev.h
    HINTS ${LIBEV_RROT_DIR}
    PATH_SUFFIXES include)

find_library(LIBEV_LIBRARY
    NAME ev
    HINTS ${LIBEV_ROOT_DIR}
    PATH_SUFFIXES ${CMAKE_INSTALL_LIBDIR})


message(STATUS "value for LIBEV_INCLUDE_DIR => ${LIBEV_INCLUDE_DIR} ")
message(STATUS "value for LIBEV_LIBRARY => ${LIBEV_LIBRARY} ")


add_executable(testev "")

target_sources(testev
        PUBLIC "sample.cpp"
    )

target_include_directories(testev
        PRIVATE ${LIBEV_INCLUDE_DIR}
    )

target_link_libraries(testev
        PRIVATE ${LIBEV_LIBRARY}
    )




