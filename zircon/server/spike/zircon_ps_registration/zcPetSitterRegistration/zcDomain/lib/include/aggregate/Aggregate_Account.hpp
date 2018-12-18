//
//  Aggregate_Account.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 9/30/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef Aggregate_Account_hpp
#define Aggregate_Account_hpp

#include "aggregate/Aggregate.hpp"
#include "aggregate/AccountInformation.hpp"
#include "aggregate/AccountId.hpp"

#include "event/Event.hpp"
#include "event/Event_AccountClosed.hpp"
#include "event/Event_AccountCreated.hpp"
#include "event/Event_AccountVerificationStarted.hpp"

namespace cmd
{
class Command_CreateAccount;
}

namespace domain
{
class Aggregate_Account : public Aggregate
{
private:
  std::shared_ptr<const AccountInformation> accountInfo_;

private:
  std::vector<std::shared_ptr<const domain::Event> > ApplyAccountCreated(const domain::Event_AccountCreated &event);
  std::vector<std::shared_ptr<const domain::Event> > ApplyAccountClosed(const domain::Event_AccountClosed &event);
  std::vector<std::shared_ptr<const domain::Event> > ApplyAccountVerificationStarted(const domain::Event_AccountVerificationStarted &event);

public:
  std::vector<std::shared_ptr<const domain::Event> > Close(const AccountId &accountId) const;
  std::vector<std::shared_ptr<const domain::Event> > Create(const cmd::Command_CreateAccount &aCommand) const;
  std::vector<std::shared_ptr<const domain::Event> > Apply(const domain::Event &event);
  virtual const dok::Version GetVersion() const;
};
} // namespace domain

#endif /* Aggregate_Account_hpp */
