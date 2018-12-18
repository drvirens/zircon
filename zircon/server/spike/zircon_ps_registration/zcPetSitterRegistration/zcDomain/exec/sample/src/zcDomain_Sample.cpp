#include <iostream>
#include "zcDomain.h"


#include "aggregate/Aggregate_Account.hpp"
#include "command/Command_CloseAccount.hpp"
#include "command/Command_CreateAccount.hpp"
#include "event/Event_AccountClosed.hpp"
#include "event/Event_AccountCreated.hpp"
#include "aggregate/FullName.hpp"
#include "aggregate/NameOfPerson.hpp"
#include "aggregate/PhoneNumber.hpp"
#include "aggregate/Email.hpp"
#include "aggregate/PhoneNumber.hpp"
#include "aggregate/DoB.hpp"
#include "aggregate/ReferralCode.hpp"
#include "aggregate/SSN.hpp"

static void tryUseCaseCreateAccount()
{
  
  std::cout << "tryUseCaseCreateAccount entered" << std::endl;
  
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
  
  domain::Aggregate_Account account;
  const cmd::Command_CreateAccount commandCreateAccount(accountInfo);
  std::vector<std::shared_ptr<const domain::Event> > events = account.Create(commandCreateAccount);
  
  std::vector<std::shared_ptr<const domain::Event> >::const_iterator it;
  for (it = events.begin(); it != events.end(); it++)
    {
    const domain::Event *e = (*it).get();
    account.Apply(*e);
    }
  
  std::cout << "tryUseCaseCreateAccount exitted" << std::endl;
}


int main(int argC, char *argV[])
{
    std::cout << "zcDomain main function called boss" << std::endl;

    zcDomain *common = zcDomain::NewL();
    if (common)
    {
        std::cout << "zcDomain object allocated" << std::endl;
        std::string name = common->Name();
        std::cout << "zcDomain object Name returned => [" << name << "]" << std::endl;
    }
  
  tryUseCaseCreateAccount();
    return 0;
}
