CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

set(ZC_MODULE_NAME "zcPresent")
set(ZC_MODULE_VERSION "1.0.0")

project(${ZC_MODULE_NAME}
        VERSION ${ZC_MODULE_VERSION}
        DESCRIPTION "zircon present project"
        LANGUAGES CXX
        )

# global. target names
set(ZC_TGT_ZCPRESENT_LIB "zcPresent" CACHE STRING "name of the lib")
set(ZC_TGT_ZCPRESENT_EXEC_SAMPLE "zcPresent_Sample" CACHE STRING "name of sample app")
set(ZC_TGT_ZCPRESENT_EXEC_TEST_LIB "zcPresent_TestLib" CACHE STRING "name of lib test executable")


add_subdirectory(lib)
add_subdirectory(exec)
