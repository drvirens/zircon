//
//  Email.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/3/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef Email_hpp
#define Email_hpp

#include <string>

namespace domain
{
class Email
{
private:
  const std::string userName_;
  const std::string secondaryDomain_;
  const std::string topDomain_;

public:
  explicit Email(const std::string &userName,
                 const std::string &secondaryDomain,
                 const std::string &topDomain);
  const std::string &GetUserName() const;
  const std::string &GetSecondaryDomain() const;
  const std::string &GetTopDomain() const;
};
} // namespace domain

#endif /* Email_hpp */
