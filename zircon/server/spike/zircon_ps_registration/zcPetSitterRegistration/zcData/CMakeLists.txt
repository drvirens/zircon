CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

set(ZC_MODULE_NAME "zcData")
set(ZC_MODULE_VERSION "1.0.0")

project(${ZC_MODULE_NAME}
        VERSION ${ZC_MODULE_VERSION}
        DESCRIPTION "zircon data project"
        LANGUAGES CXX
        )

# global. target names
set(ZC_TGT_ZCDATA_LIB "zcData" CACHE STRING "name of the lib")
set(ZC_TGT_ZCDATA_EXEC_SAMPLE "zcData_Sample" CACHE STRING "name of sample app")
set(ZC_TGT_ZCDATA_EXEC_TEST_LIB "zcData_TestLib" CACHE STRING "name of lib test executable")


add_subdirectory(lib)
add_subdirectory(exec)
