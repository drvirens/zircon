//
//  SSN.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/7/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#include "aggregate/SSN.hpp"
#include "CommonHeaders.hpp"

namespace domain
{
SSN::SSN(const std::string &aSsn)
    : ssn_(aSsn)
{
}

} // namespace domain
