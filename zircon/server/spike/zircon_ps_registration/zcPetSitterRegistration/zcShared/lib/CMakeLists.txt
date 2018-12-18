add_library(${ZC_TGT_ZCSHARED_LIB} "")

target_sources(${ZC_TGT_ZCSHARED_LIB}
        PRIVATE
            "${CMAKE_CURRENT_LIST_DIR}/src/zcCommon.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/zcCommon_p.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/zcCommon_p.h"
            "${CMAKE_CURRENT_LIST_DIR}/src/zcSinglyLinkedList.cpp"

            "${CMAKE_CURRENT_LIST_DIR}/src/Version.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/CommonHeaders.cpp"

            "${CMAKE_CURRENT_LIST_DIR}/src/zc_hash/ZcHash.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/zc_hash/xxhash.c"
            "${CMAKE_CURRENT_LIST_DIR}/src/zc_hash/xxhash.h"
            "${CMAKE_CURRENT_LIST_DIR}/src/zc_assert/Zircon_Assertions.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/zc_assert/ppk_assert.cpp"


            "${CMAKE_CURRENT_LIST_DIR}/src/zcStatus.cpp"

        PUBLIC
            "${CMAKE_CURRENT_LIST_DIR}/include/zcCommon.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/zcSinglyLinkedList.h"

            "${CMAKE_CURRENT_LIST_DIR}/include/Version.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/CommonHeaders.hpp"

            "${CMAKE_CURRENT_LIST_DIR}/include/zc_assert/Zircon_Assertions.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/zc_assert/ppk_assert.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/zc_hash/ZcHash.hpp"

            "${CMAKE_CURRENT_LIST_DIR}/include/zcStatus.h"
    )

target_compile_definitions(${ZC_TGT_ZCSHARED_LIB}
        PUBLIC
            disabled_USE_OWN_MAIN=1
    )

target_include_directories(${ZC_TGT_ZCSHARED_LIB}
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/include
    )


# install headers and libs
# use the cmake command like below for install directory path:
# cmake .. -DCMAKE_INSTALL_PREFIX=./DEBUG.BUILD
install(TARGETS ${ZC_TGT_ZCSHARED_LIB} DESTINATION zc/${ZC_INSTALL_BIN_DIR})
install(FILES include/zcCommon.h include/zcSinglyLinkedList.h DESTINATION zc/${ZC_INSTALL_INC_DIR})
