//
//  Aggregate.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 9/30/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef Aggregate_hpp
#define Aggregate_hpp

#include <memory>
#include <vector>
#include "Version.hpp"

namespace domain
{
class Aggregate
{
public:
  virtual const dok::Version GetVersion() const = 0;
};
} // namespace domain

#endif /* Aggregate_hpp */
