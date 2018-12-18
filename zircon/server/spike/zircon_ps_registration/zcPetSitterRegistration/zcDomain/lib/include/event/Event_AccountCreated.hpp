//
//  Event_AccountCreated.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 9/30/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef Event_AccountCreated_hpp
#define Event_AccountCreated_hpp

#include <memory>
#include "event/Event.hpp"
#include "aggregate/AccountInformation.hpp"

namespace domain
{

class Event_AccountCreated : public Event
{
private:
  const AccountInformation accountInfo_;

public:
  explicit Event_AccountCreated(const AccountInformation &aAccountInfo);
  const AccountInformation &GetAccountInfo() const;
  virtual ~Event_AccountCreated();
};

} // namespace domain

#endif /* Event_AccountCreated_hpp */
