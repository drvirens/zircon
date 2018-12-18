CMAKE_MINIMUM_REQUIRED(VERSION 3.9)

set(ZC_MODULE_NAME "zcDomain")
set(ZC_MODULE_VERSION "1.0.0")

project(${ZC_MODULE_NAME}
        VERSION ${ZC_MODULE_VERSION}
        DESCRIPTION "zircon domain project"
        LANGUAGES CXX
    )

# global. target names
set(ZC_TGT_ZCDOMAIN_LIB "zcDomain" CACHE STRING "name of the lib")
set(ZC_TGT_ZCDOMAIN_EXEC_SAMPLE "zcDomain_Sample" CACHE STRING "name of sample app")
set(ZC_TGT_ZCDOMAIN_EXEC_TEST_LIB "zcDomain_TestLib" CACHE STRING "name of lib test executable")


add_subdirectory(lib)
add_subdirectory(exec)
