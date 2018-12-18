//
//  Aggregate_Account.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 9/30/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#include "aggregate/Aggregate_Account.hpp"
#include "event/Event_AccountCreated.hpp"
#include "event/Event_AccountVerificationStarted.hpp"
#include "command/Command_CreateAccount.hpp"
#include "CommonHeaders.hpp"

namespace domain
{
std::vector<std::shared_ptr<const domain::Event> > Aggregate_Account::Close(const AccountId &accountId) const
{
  std::vector<std::shared_ptr<const domain::Event> > events;
  return events;
}

std::vector<std::shared_ptr<const domain::Event> > Aggregate_Account::Create(const cmd::Command_CreateAccount &aCommand) const
{
  std::vector<std::shared_ptr<const domain::Event> > events;

  const AccountInformation &accountInfo = aCommand.GetAccountInfo();

  std::shared_ptr<domain::Event_AccountCreated> created = std::make_shared<domain::Event_AccountCreated>(accountInfo);

  events.push_back(created);

  return events;
}

const dok::Version Aggregate_Account::GetVersion() const
{
  dok::Version ver;
  return ver;
}

std::vector<std::shared_ptr<const domain::Event> > Aggregate_Account::Apply(const domain::Event &event)
{
  const domain::Event *evt = &event;
  const Event_AccountVerificationStarted *verificationStarted = dynamic_cast<const domain::Event_AccountVerificationStarted *>(evt);
  if (verificationStarted)
  {
    return ApplyAccountVerificationStarted(*verificationStarted);
  }
  const Event_AccountCreated *created = dynamic_cast<const domain::Event_AccountCreated *>(evt);
  if (created)
  {
    return ApplyAccountCreated(*created);
  }
  const Event_AccountClosed *closed = dynamic_cast<const Event_AccountClosed *>(evt);
  if (closed)
  {
    return ApplyAccountClosed(*closed);
  }

  std::vector<std::shared_ptr<const domain::Event> > empty;
  return empty;
}

std::vector<std::shared_ptr<const domain::Event> > Aggregate_Account::ApplyAccountVerificationStarted(const domain::Event_AccountVerificationStarted &event)
{
  std::vector<std::shared_ptr<const domain::Event> > events;
  return events;
}

std::vector<std::shared_ptr<const domain::Event> > Aggregate_Account::ApplyAccountCreated(const domain::Event_AccountCreated &event)
{
  const AccountInformation &accountInfo = event.GetAccountInfo();
  std::vector<std::shared_ptr<const domain::Event> > events;
  std::shared_ptr<const domain::Event_AccountVerificationStarted> verificationStarted = std::make_shared<const domain::Event_AccountVerificationStarted>(accountInfo);
  events.push_back(verificationStarted);
  return events;
}

std::vector<std::shared_ptr<const domain::Event> > Aggregate_Account::ApplyAccountClosed(const domain::Event_AccountClosed &event)
{
  std::vector<std::shared_ptr<const domain::Event> > events;
  return events;
}
} // namespace domain
