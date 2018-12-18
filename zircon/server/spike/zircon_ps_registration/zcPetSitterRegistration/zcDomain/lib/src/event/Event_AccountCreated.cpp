//
//  Event_AccountCreated.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 9/30/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#include "event/Event_AccountCreated.hpp"
#include "CommonHeaders.hpp"

namespace domain
{
Event_AccountCreated::Event_AccountCreated(const AccountInformation &aAccountInfo)
    : accountInfo_(aAccountInfo)
{
}
const AccountInformation &Event_AccountCreated::GetAccountInfo() const
{
  return accountInfo_;
}

Event_AccountCreated::~Event_AccountCreated()
{
}
} // namespace domain
