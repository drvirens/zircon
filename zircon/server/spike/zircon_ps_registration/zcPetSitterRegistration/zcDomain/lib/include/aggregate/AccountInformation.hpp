//
//  AccountInformation.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/1/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef AccountInformation_hpp
#define AccountInformation_hpp

#include <memory>
#include "aggregate/AccountId.hpp"
#include "aggregate/FullName.hpp"
#include "aggregate/PhoneNumber.hpp"
#include "aggregate/Email.hpp"
#include "aggregate/DoB.hpp"
#include "aggregate/ReferralCode.hpp"
#include "aggregate/SSN.hpp"

namespace domain
{

class AccountInformation
{
private:
  std::shared_ptr<const domain::AccountId> accountId_;
  std::shared_ptr<const domain::FullName> fullName_;
  std::shared_ptr<const domain::PhoneNumber> phoneNumber_;
  std::shared_ptr<const domain::Email> email_;
  std::shared_ptr<const domain::DoB> dob_;
  std::shared_ptr<const domain::ReferralCode> referralCode_;
  std::shared_ptr<const domain::SSN> ssn_;

public:
  void SetFullName(const FullName &aAccountFullName);
  void SetPhoneNumber(const PhoneNumber &aPhoneNumber);
  void SetEmail(const Email &aEmail);
  void SetDob(const DoB &aDoB);
  void SetSSN(const SSN &aSSN);
  void SetReferralCode(const ReferralCode &aReferralCode);
  void SetAccountId(const AccountId &accountId);

  const FullName &GetFullName() const;
  const PhoneNumber &GetPhoneNumber() const;
  const Email &GetEmail() const;
  const DoB &GetDob() const;
  const SSN &GetSSN() const;
  const ReferralCode &GetReferralCode() const;
  const AccountId &GetAccountId() const;
};
} // namespace domain

#endif /* AccountInformation_hpp */
