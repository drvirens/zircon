//
//  PhoneNumber.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/2/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#include "aggregate/PhoneNumber.hpp"
#include "CommonHeaders.hpp"

namespace domain
{

PhoneNumber::PhoneNumber(const std::string &countryCode,
                         const std::string &areaCode,
                         const std::string &number)
    : countryCode_(countryCode), areaCode_(areaCode), number_(number)
{
}

const std::string &PhoneNumber::GetCountryCode() const
{
    return countryCode_;
}
const std::string &PhoneNumber::GetAreaCode() const
{
    return areaCode_;
}
const std::string &PhoneNumber::GetNumber() const
{
    return number_;
}

} // namespace domain
