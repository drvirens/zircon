//
//  NameOfPerson.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/2/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#include "aggregate/NameOfPerson.hpp"
#include "CommonHeaders.hpp"

namespace domain
{
NameOfPerson::NameOfPerson(const std::string &name)
    : name_(name)
{
}
const std::string &NameOfPerson::GetName() const
{
  return name_;
}

bool NameOfPerson::operator==(const NameOfPerson &aRhs) const
{
  if (this == &aRhs)
  {
    return true;
  }
  if (name_ == aRhs.name_)
  {
    return true;
  }
  return false;
}

const std::string &NameOfPerson::ToStdString() const
{
  return GetName();
}

std::ostream &operator<<(std::ostream &aOutputStream, NameOfPerson const &aRhs)
{
  return (aOutputStream << aRhs.ToStdString());
}
} // namespace domain
