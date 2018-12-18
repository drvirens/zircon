//
//  FullName.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/2/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#include "aggregate/FullName.hpp"
#include "CommonHeaders.hpp"
#include "aggregate/NameOfPerson.hpp"

namespace domain
{
FullName::FullName(const NameOfPerson &firstName,
                   const NameOfPerson &middleName,
                   const NameOfPerson &lastName)
    : firstName_(firstName), middleName_(middleName), lastName_(lastName)
{
}

const NameOfPerson &FullName::GetFirstName() const
{
    return firstName_;
}
const NameOfPerson &FullName::GetMiddleName() const
{
    return middleName_;
}
const NameOfPerson &FullName::GetLastName() const
{
    return lastName_;
}
} // namespace domain
