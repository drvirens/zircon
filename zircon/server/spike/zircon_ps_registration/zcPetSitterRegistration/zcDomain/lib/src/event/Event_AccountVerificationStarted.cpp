//
//  Event_AccountVerificationStarted.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/7/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#include "event/Event_AccountVerificationStarted.hpp"
#include "CommonHeaders.hpp"

namespace domain
{
Event_AccountVerificationStarted::Event_AccountVerificationStarted(const AccountInformation &aAccountInfo)
    : accountInfo_(aAccountInfo)
{
}
const AccountInformation &Event_AccountVerificationStarted::GetAccountInfo() const
{
  return accountInfo_;
}

Event_AccountVerificationStarted::~Event_AccountVerificationStarted()
{
}
} // namespace domain
