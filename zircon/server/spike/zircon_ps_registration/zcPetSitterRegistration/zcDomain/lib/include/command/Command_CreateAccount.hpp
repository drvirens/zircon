//
//  Command_CreateAccount.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 9/30/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef Command_CreateAccount_hpp
#define Command_CreateAccount_hpp

#include <memory>
#include "command/Command.hpp"
#include "aggregate/AccountInformation.hpp"

namespace cmd
{

class Command_CreateAccount : public Command
{
private:
  std::shared_ptr<const domain::AccountInformation> accountInfo_;

public:
  explicit Command_CreateAccount(const domain::AccountInformation &aAccountInfor);
  const domain::AccountInformation &GetAccountInfo() const;
};
} // namespace cmd

#endif /* Command_CreateAccount_hpp */
