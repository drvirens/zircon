//
//  Test_Unit_Aggregate_Account_Apply_EventCreated.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/7/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//


#include <catch2/catch.hpp>


#include "command/Command_CloseAccount.hpp"
#include "command/Command_CreateAccount.hpp"
#include "event/Event_AccountClosed.hpp"
#include "event/Event_AccountCreated.hpp"
#include "event/Event_AccountVerificationStarted.hpp"
#include "aggregate/Aggregate_Account.hpp"
#include "aggregate/FullName.hpp"
#include "aggregate/NameOfPerson.hpp"
#include "aggregate/PhoneNumber.hpp"
#include "aggregate/Email.hpp"
#include "aggregate/PhoneNumber.hpp"
#include "aggregate/DoB.hpp"
#include "aggregate/ReferralCode.hpp"
#include "aggregate/SSN.hpp"
#include "aggregate/AccountInformation.hpp"

SCENARIO("Apply AccountCreated Event", "[Aggregate_Account]")
{
  GIVEN("Readymade Account Information")
  {
    const domain::NameOfPerson firstName("Virendra");
    const domain::NameOfPerson middleName("Nathulal");
    const domain::NameOfPerson lastName("Shakya");
    const domain::FullName accountFullName(firstName, middleName, lastName);

    const domain::PhoneNumber phoneNumber("+1", "415", "6054482");
    const domain::Email email("virendra.shakya", "chartboost", "com");
    const domain::DoB dateOfBith(1, 6, 1972);
    const domain::SSN ssn("123-45-6789");
    const domain::ReferralCode referralCode("mrwatts");

    domain::AccountInformation accountInfo;
    accountInfo.SetFullName(accountFullName);
    accountInfo.SetPhoneNumber(phoneNumber);
    accountInfo.SetEmail(email);
    accountInfo.SetDob(dateOfBith);
    accountInfo.SetSSN(ssn);
    accountInfo.SetReferralCode(referralCode);

    WHEN("Account is created")
    {
      domain::Aggregate_Account account;

      const cmd::Command_CreateAccount commandCreateAccount(accountInfo);
      std::vector<std::shared_ptr<const domain::Event>> events = account.Create(commandCreateAccount);

      THEN("Event_AccountCreated is generated")
      {
        const domain::Event_AccountCreated *event_AccountCreated = 0;
        const domain::Event_AccountVerificationStarted *event_AccountVerificationStarted = 0;

        std::vector<std::shared_ptr<const domain::Event>>::const_iterator it;
        for (it = events.begin(); it != events.end(); it++)
        {
          const domain::Event *e = (*it).get();
          const domain::Event_AccountCreated *ptr = dynamic_cast<const domain::Event_AccountCreated *>(e);
          if (ptr)
          {
            event_AccountCreated = ptr;
          }
        }

        REQUIRE(event_AccountCreated != 0);

        std::vector<std::shared_ptr<const domain::Event>> eventsByAccountCreated = account.Apply(*event_AccountCreated);

        std::vector<std::shared_ptr<const domain::Event>>::const_iterator it1;
        for (it1 = eventsByAccountCreated.begin(); it1 != eventsByAccountCreated.end(); it1++)
        {
          const domain::Event *e = (*it1).get();
          const domain::Event_AccountVerificationStarted *ptr1 = dynamic_cast<const domain::Event_AccountVerificationStarted *>(e);
          if (ptr1)
          {
            event_AccountVerificationStarted = ptr1;
          }
        }

        REQUIRE(event_AccountVerificationStarted != 0);

        const domain::AccountInformation obtainedAccountInfo = event_AccountVerificationStarted->GetAccountInfo();

        const domain::FullName fn = obtainedAccountInfo.GetFullName();
        const domain::NameOfPerson expectedFirstName("Virendra");
        const domain::NameOfPerson actualFirstName = fn.GetFirstName();
        REQUIRE(actualFirstName == expectedFirstName);
        const domain::NameOfPerson expectedMiddleName("Nathulal");
        REQUIRE(fn.GetMiddleName() == middleName );
        REQUIRE(fn.GetMiddleName() == expectedMiddleName );
      const domain::NameOfPerson expectedLastName("Shakya");
      REQUIRE(fn.GetLastName() == lastName );
      REQUIRE(fn.GetLastName() == expectedLastName );

        const domain::Email obtainedEmail = obtainedAccountInfo.GetEmail();
        const std::string obtainedEmailUserName = obtainedEmail.GetUserName();
        const std::string obtainedEmailSecondaryDomain = obtainedEmail.GetSecondaryDomain();
        const std::string obtainedEmailTopDomain = obtainedEmail.GetTopDomain();

        REQUIRE(obtainedEmailUserName == "virendra.shakya");
        REQUIRE(obtainedEmailSecondaryDomain == "chartboost");
        REQUIRE(obtainedEmailTopDomain == "com");
      }
    }
  }
}
