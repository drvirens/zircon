cmake_minimum_required(VERSION 3.9)

set(ZC_MODULE_NAME "zcShared")
set(ZC_MODULE_VERSION "1.0.0")

project(${ZC_MODULE_NAME}
        VERSION ${ZC_MODULE_VERSION}
        DESCRIPTION "zircon zcShared project"
        LANGUAGES CXX
    )

# global. target names
set(ZC_TGT_ZCSHARED_LIB "zcShared" CACHE STRING "name of the lib")
set(ZC_TGT_ZCSHARED_EXEC_SAMPLE "zcShared_Sample" CACHE STRING "name of sample app")
set(ZC_TGT_ZCSHARED_EXEC_TEST_LIB "zcShared_TestLib" CACHE STRING "name of lib test executable")

add_subdirectory(lib)
add_subdirectory(exec)
