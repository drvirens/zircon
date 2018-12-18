//
//  ReferralCode.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/3/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef ReferralCode_hpp
#define ReferralCode_hpp

#include <string>

namespace domain
{
class ReferralCode
{
private:
  const std::string referralCode_;

public:
  explicit ReferralCode(const std::string &aReferralCode);
};
} // namespace domain

#endif /* ReferralCode_hpp */
