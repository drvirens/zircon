
add_executable(${ZC_TGT_ZCDOMAIN_EXEC_SAMPLE} "")
target_sources(${ZC_TGT_ZCDOMAIN_EXEC_SAMPLE}
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/src/zcDomain_Sample.cpp"
)
target_include_directories(${ZC_TGT_ZCDOMAIN_EXEC_SAMPLE}
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/include
    )

target_link_libraries(${ZC_TGT_ZCDOMAIN_EXEC_SAMPLE}
        ${ZC_TGT_ZCDOMAIN_LIB}
    )

install(TARGETS ${ZC_TGT_ZCDOMAIN_EXEC_SAMPLE} DESTINATION zc/${ZC_INSTALL_BIN_DIR})
