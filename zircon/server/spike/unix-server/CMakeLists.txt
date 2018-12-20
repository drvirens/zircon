cmake_minimum_required(VERSION 3.9)
project(zcunixservprj DESCRIPTION "zcunixserv" VERSION "0.0.1" LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ZC_LIB_NAME zc)
set(ZC_SERVER_NAME server)
set(ZC_SAMPLE_CLIENT_NAME client)
set(ZC_TEST_NAME test)


set(ZC_USE_MOCK_BIND OFF)



# ---------------------------------------------------------------
#
# LIB
#
# ---------------------------------------------------------------

# link with libev
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



add_library(${ZC_LIB_NAME} "")
target_sources(${ZC_LIB_NAME}
    PRIVATE
        "zc_utils.c"
        "zc_log.c"
        "zc_server.c"
        "zc_alloc.c"
        "zc_client.c"
        "zc_socket.c"
        "zc_socket_native.c"

    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_utils.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_log.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_server.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_alloc.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_client.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_assert.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_socket.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_global_constants.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_socket_native.h"

    )
target_include_directories(${ZC_LIB_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
    PRIVATE
        ${LIBEV_INCLUDE_DIR}
)
target_link_libraries(${ZC_LIB_NAME}
    PRIVATE
        ${LIBEV_LIBRARY}
)






# ---------------------------------------------------------------
#
# SERVER APP
#
# ---------------------------------------------------------------

add_executable(${ZC_SERVER_NAME} "")

if (${ZC_USE_MOCK_BIND})
  add_definitions(-DUSE_MOCK_BIND=0)
else ()
  add_definitions(-DUSE_MOCK_BIND=0)
endif()

target_sources(${ZC_SERVER_NAME}
    PUBLIC
        "main.c"
)
target_include_directories(${ZC_SERVER_NAME}
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_utils.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_log.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_server.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_alloc.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_client.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_socket.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_global_constants.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_socket_native.h"

    PRIVATE ${LIBEV_INCLUDE_DIR}
)
target_link_libraries(${ZC_SERVER_NAME}
    PRIVATE
        ${ZC_LIB_NAME}
        ${LIBEV_LIBRARY}
)







# ---------------------------------------------------------------
#
# CLIENT APP
#
# ---------------------------------------------------------------


add_executable(${ZC_SAMPLE_CLIENT_NAME} "")
target_sources(${ZC_SAMPLE_CLIENT_NAME}
    PUBLIC
        "zc_sample_client_app.c"
)
target_include_directories(${ZC_SAMPLE_CLIENT_NAME}
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_utils.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_log.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_server.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_alloc.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_client.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_socket.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_global_constants.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_socket_native.h"
)
target_link_libraries(${ZC_SAMPLE_CLIENT_NAME} ${ZC_LIB_NAME})




# ---------------------------------------------------------------
#
# TEST
#
# ---------------------------------------------------------------
add_executable(${ZC_TEST_NAME} "")


if (ZC_USE_MOCK_BIND)
  add_definitions(-DUSE_MOCK_BIND=1)
else ()
  add_definitions(-DUSE_MOCK_BIND=0)
endif()

target_sources(${ZC_TEST_NAME}
    PRIVATE
        "test_zc_server.cpp"
        "test_zc_log.cpp"
        "test_zc_utils.cpp"
        "test_zc_socket.cpp"
        "test_main.cpp"
)
target_include_directories(${ZC_TEST_NAME}
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_utils.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_log.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_server.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_alloc.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_client.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_socket.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_global_constants.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zc_socket_native.h"
)

target_link_libraries(${ZC_TEST_NAME} ${ZC_LIB_NAME})

find_package(Catch2 REQUIRED)
target_link_libraries(${ZC_TEST_NAME} Catch2::Catch2)


#DEPENDENCIES
add_dependencies(${ZC_TEST_NAME} ${ZC_LIB_NAME})
