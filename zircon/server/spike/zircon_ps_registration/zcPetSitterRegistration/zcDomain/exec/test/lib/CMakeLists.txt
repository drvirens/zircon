
add_executable(${ZC_TGT_ZCDOMAIN_EXEC_TEST_LIB} "")
target_sources(${ZC_TGT_ZCDOMAIN_EXEC_TEST_LIB}
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/src/zcDomain_TestLib.cpp"
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/src/test_DomainSample.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/Test_Unit_Aggregate_Account.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/Test_Unit_Aggregate_Account_Apply_EventCreated.cpp"

)

target_include_directories(${ZC_TGT_ZCDOMAIN_EXEC_TEST_LIB}
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/include
    )

target_link_libraries(${ZC_TGT_ZCDOMAIN_EXEC_TEST_LIB}
        ${ZC_TGT_ZCDOMAIN_LIB}
    )

# Catch2 is required
find_package(Catch2 REQUIRED)
target_link_libraries(${ZC_TGT_ZCDOMAIN_EXEC_TEST_LIB} Catch2::Catch2)


# install headers and libs
# use the cmake command like below for install directory path:
# cmake .. -DCMAKE_INSTALL_PREFIX=~/Zircon/byproducts
install(TARGETS ${ZC_TGT_ZCDOMAIN_EXEC_TEST_LIB} DESTINATION zc/${ZC_INSTALL_BIN_DIR})

