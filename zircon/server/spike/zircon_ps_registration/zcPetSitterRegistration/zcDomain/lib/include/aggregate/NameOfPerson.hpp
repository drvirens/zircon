//
//  NameOfPerson.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/2/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef NameOfPerson_hpp
#define NameOfPerson_hpp

#include <string>
#include <iostream>

namespace domain
{

class NameOfPerson
{

private:
  const std::string name_;

public:
  explicit NameOfPerson(const std::string &name);
  void SetName(const std::string &aName);
  const std::string &GetName() const;
  const std::string &ToStdString() const;

  bool operator==(const NameOfPerson &aRhs) const;
};

std::ostream &operator<<(std::ostream &aOutputStream, NameOfPerson const &aRhs);

} // namespace domain

#endif /* NameOfPerson_hpp */
