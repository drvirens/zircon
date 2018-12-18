//
//  AccountInformation.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/1/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#include "aggregate/AccountInformation.hpp"
#include "CommonHeaders.hpp"

namespace domain
{
void AccountInformation::SetFullName(const FullName &aAccountFullName)
{
  fullName_ = std::make_shared<const domain::FullName>(
      aAccountFullName.GetFirstName(),
      aAccountFullName.GetMiddleName(),
      aAccountFullName.GetLastName());
}
void AccountInformation::SetPhoneNumber(const PhoneNumber &aPhoneNumber)
{
  phoneNumber_ = std::make_shared<const domain::PhoneNumber>(
      aPhoneNumber.GetCountryCode(),
      aPhoneNumber.GetAreaCode(),
      aPhoneNumber.GetNumber());
}
void AccountInformation::SetEmail(const Email &aEmail)
{
  email_ = std::make_shared<const domain::Email>(aEmail.GetUserName(), aEmail.GetSecondaryDomain(), aEmail.GetTopDomain());
}
void AccountInformation::SetDob(const DoB &aDoB)
{
}
void AccountInformation::SetSSN(const SSN &aSSN)
{
}
void AccountInformation::SetReferralCode(const ReferralCode &aReferralCode)
{
}
void AccountInformation::SetAccountId(const AccountId &accountId)
{
}

const FullName &AccountInformation::GetFullName() const
{
  ZIRCON_ASSERT(0 != fullName_.get());
  return *(fullName_.get());
}
const PhoneNumber &AccountInformation::GetPhoneNumber() const
{
  ZIRCON_ASSERT(0 != phoneNumber_.get());
  return *(phoneNumber_.get());
}
const Email &AccountInformation::GetEmail() const
{
  ZIRCON_ASSERT(0 != email_.get());
  return *(email_.get());
}
const DoB &AccountInformation::GetDob() const
{
  ZIRCON_ASSERT(0 != dob_.get());
  return *(dob_.get());
}
const SSN &AccountInformation::GetSSN() const
{
  ZIRCON_ASSERT(0 != ssn_.get());
  return *(ssn_.get());
}
const ReferralCode &AccountInformation::GetReferralCode() const
{
  ZIRCON_ASSERT(0 != referralCode_.get());
  return *(referralCode_.get());
}
const AccountId &AccountInformation::GetAccountId() const
{
  ZIRCON_ASSERT(0 != accountId_.get());
  return *(accountId_.get());
}
} // namespace domain
