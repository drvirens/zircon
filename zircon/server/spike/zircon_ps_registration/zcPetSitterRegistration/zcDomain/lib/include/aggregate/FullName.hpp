//
//  FullName.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/2/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef FullName_hpp
#define FullName_hpp

#include "aggregate/NameOfPerson.hpp"

namespace domain
{
class FullName
{
private:
  const NameOfPerson firstName_;
  const NameOfPerson middleName_;
  const NameOfPerson lastName_;

public:
  explicit FullName(const NameOfPerson &firstName,
                    const NameOfPerson &middleName,
                    const NameOfPerson &lastName);
  const NameOfPerson &GetFirstName() const;
  const NameOfPerson &GetMiddleName() const;
  const NameOfPerson &GetLastName() const;
};
} // namespace domain

#endif /* FullName_hpp */
