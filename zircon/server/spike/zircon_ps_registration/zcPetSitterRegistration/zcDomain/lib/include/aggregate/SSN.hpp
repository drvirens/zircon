//
//  SSN.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/7/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef SSN_hpp
#define SSN_hpp

#include <string>

namespace domain
{
class SSN
{
private:
  const std::string ssn_;

public:
  explicit SSN(const std::string &aSsn);
};
} // namespace domain

#endif /* SSN_hpp */
