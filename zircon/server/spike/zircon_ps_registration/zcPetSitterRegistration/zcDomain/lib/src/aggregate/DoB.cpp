//
//  DoB.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/3/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#include "aggregate/DoB.hpp"
#include "CommonHeaders.hpp"

namespace domain
{

DoB::DoB(int mm, int dd, int yyyy)
    : mm_(mm), dd_(dd), yyyy_(yyyy)
{
}

} // namespace domain
