cmake_minimum_required(VERSION 3.9)

set(ZC_PACKAGE_NAME "zc.petsitter.registration")
set(ZC_PACKAGE_VERSION "1.0.0")

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${ZC_PACKAGE_NAME}
        VERSION ${ZC_PACKAGE_VERSION}
        DESCRIPTION "zircon zcShared project"
        LANGUAGES CXX
    )


option(ZC_BUILD_TESTS "BUILD TESTS" OFF)

set(ZC_INSTALL_USE_DEFAULT ON)
if(NOT CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    message(STATUS "SRC NOT EQUAL TO CURR-SRC DIR")
    # DISABLE ZC_INSTALL BY DEFAULT IF BUILDING AS A SUBMODULE
    set(ZC_INSTALL_USE_DEFAULT OFF)
else()
    message(STATUS "SRC EQUAL TO CURR-SRC DIR")
    set(ZC_INSTALL_USE_DEFAULT ON)
endif()

# global. install dir names
set(ZC_INSTALL_BIN_DIR "zc_bin" CACHE STRING "install dir for zcShared bin")
set(ZC_INSTALL_LIB_DIR "zc_lib" CACHE STRING "install dir for zcShared lib")
set(ZC_INSTALL_INC_DIR "zc_inc" CACHE STRING "install dir for zcShared inc")

add_subdirectory(zcShared)
add_subdirectory(zcDomain)
add_subdirectory(zcPresent)
add_subdirectory(zcData)
