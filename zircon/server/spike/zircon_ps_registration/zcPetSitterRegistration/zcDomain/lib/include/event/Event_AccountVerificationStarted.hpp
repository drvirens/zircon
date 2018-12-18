//
//  Event_AccountVerificationStarted.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/7/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef Event_AccountVerificationStarted_hpp
#define Event_AccountVerificationStarted_hpp

#include <memory>
#include "event/Event.hpp"
#include "aggregate/AccountInformation.hpp"

namespace domain
{

class Event_AccountVerificationStarted : public Event
{
private:
  const AccountInformation accountInfo_;

public:
  explicit Event_AccountVerificationStarted(const AccountInformation &aAccountInfo);
  const AccountInformation &GetAccountInfo() const;
  virtual ~Event_AccountVerificationStarted();
};

} // namespace domain

#endif /* Event_AccountVerificationStarted_hpp */
