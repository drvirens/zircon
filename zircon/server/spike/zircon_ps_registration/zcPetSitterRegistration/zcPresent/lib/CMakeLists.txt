
add_library(${ZC_TGT_ZCPRESENT_LIB} "")

target_sources(${ZC_TGT_ZCPRESENT_LIB}
        PRIVATE

        "${CMAKE_CURRENT_LIST_DIR}/src/zcPresent.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/zcPresent_p.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/zcPresent_p.h"

        "${CMAKE_CURRENT_LIST_DIR}/src/zcAccountController.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/zcAccountService.cpp"

        PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/include/zcPresent.h"

        "${CMAKE_CURRENT_LIST_DIR}/include/zcAccountController.h"
        "${CMAKE_CURRENT_LIST_DIR}/include/zcAccountService.h"

        )

target_compile_definitions(${ZC_TGT_ZCPRESENT_LIB}
        PUBLIC
        disabled_USE_OWN_MAIN=1
        )

target_include_directories(${ZC_TGT_ZCPRESENT_LIB}
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
        )

# zcshared-lib
target_link_libraries(${ZC_TGT_ZCPRESENT_LIB}
        ${ZC_TGT_ZCSHARED_LIB}
        )
target_link_libraries(${ZC_TGT_ZCPRESENT_LIB}
        ${ZC_TGT_ZCDOMAIN_LIB}
)

# install headers and libs
# use the cmake command like below for install directory path:
# cmake .. -DCMAKE_INSTALL_PREFIX=~/Zircon/byproducts
install(TARGETS ${ZC_TGT_ZCPRESENT_LIB} DESTINATION zc/${ZC_INSTALL_BIN_DIR})
install(FILES include/zcPresent.h DESTINATION zc/${ZC_INSTALL_INC_DIR})
