//
//  AccountId.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/2/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef AccountId_hpp
#define AccountId_hpp

#include "zcIdentifier.h"

namespace domain
{
class AccountId
{
  private:
  zcIdentifier id_;
  
  public:
    AccountId();
    ~AccountId();
};
} // namespace domain

#endif /* AccountId_hpp */
