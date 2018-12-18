//
//  Email.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/3/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#include "aggregate/Email.hpp"
#include "CommonHeaders.hpp"

namespace domain
{

Email::Email(const std::string &userName,
             const std::string &secondaryDomain,
             const std::string &topDomain)
    : userName_(userName), secondaryDomain_(secondaryDomain), topDomain_(topDomain)
{
}

const std::string &Email::GetUserName() const
{
  return userName_;
}
const std::string &Email::GetSecondaryDomain() const
{
  return secondaryDomain_;
}
const std::string &Email::GetTopDomain() const
{
  return topDomain_;
}

} // namespace domain
