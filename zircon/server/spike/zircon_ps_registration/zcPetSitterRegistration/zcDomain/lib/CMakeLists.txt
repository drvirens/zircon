
add_library(${ZC_TGT_ZCDOMAIN_LIB} "")

target_sources(${ZC_TGT_ZCDOMAIN_LIB}
        PRIVATE

            "${CMAKE_CURRENT_LIST_DIR}/src/zcDomain.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/zcDomain_p.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/zcDomain_p.h"
            "${CMAKE_CURRENT_LIST_DIR}/src/zcTemplateClass.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/zcTemplateClass.h"

            "${CMAKE_CURRENT_LIST_DIR}/src/aggregate/AccountId.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/aggregate/AccountInformation.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/aggregate/Aggregate.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/aggregate/DoB.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/aggregate/FullName.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/aggregate/PhoneNumber.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/aggregate/SSN.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/aggregate/Aggregate_Account.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/aggregate/Email.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/aggregate/NameOfPerson.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/aggregate/ReferralCode.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/event/Event.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/event/Event_AccountClosed.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/event/Event_AccountCreated.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/event/Event_AccountVerificationStarted.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/command/Command.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/command/Command_CloseAccount.cpp"
            "${CMAKE_CURRENT_LIST_DIR}/src/command/Command_CreateAccount.cpp"

            "${CMAKE_CURRENT_LIST_DIR}/src/zcIdentifier.cpp"



        PUBLIC
            "${CMAKE_CURRENT_LIST_DIR}/include/zcDomain.h"
            "${CMAKE_CURRENT_LIST_DIR}/include/aggregate/AccountId.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/aggregate/AccountInformation.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/aggregate/Aggregate.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/aggregate/Aggregate_Account.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/aggregate/DoB.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/aggregate/Email.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/aggregate/FullName.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/aggregate/NameOfPerson.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/aggregate/PhoneNumber.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/aggregate/ReferralCode.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/aggregate/SSN.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/event/Event.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/event/Event_AccountClosed.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/event/Event_AccountCreated.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/event/Event_AccountVerificationStarted.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/command/Command.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/command/Command_CloseAccount.hpp"
            "${CMAKE_CURRENT_LIST_DIR}/include/command/Command_CreateAccount.hpp"

            "${CMAKE_CURRENT_LIST_DIR}/include/zcIdentifier.h"
    )

target_compile_definitions(${ZC_TGT_ZCDOMAIN_LIB}
        PUBLIC
            disabled_USE_OWN_MAIN=1
    )

target_include_directories(${ZC_TGT_ZCDOMAIN_LIB}
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}/include
    )

target_link_libraries(${ZC_TGT_ZCDOMAIN_LIB}
    ${ZC_TGT_ZCSHARED_LIB}
)

# install headers and libs
# use the cmake command like below for install directory path:
# cmake .. -DCMAKE_INSTALL_PREFIX=~/Zircon/byproducts
install(TARGETS ${ZC_TGT_ZCDOMAIN_LIB} DESTINATION zc/${ZC_INSTALL_BIN_DIR})
install(FILES include/zcDomain.h DESTINATION zc/${ZC_INSTALL_INC_DIR})
