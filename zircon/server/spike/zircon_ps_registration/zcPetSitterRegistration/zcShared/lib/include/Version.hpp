//
//  Version.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 9/30/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef Version_hpp
#define Version_hpp

#include <string>

namespace dok
{ //domain kernel
class MajorVersion
{
private:
  int major_;
};
class MinorVersion
{
private:
  int minor_;
};
class PatchVersion
{
private:
  int patch_;
};
class Version
{
private:
  MajorVersion major_;
  MinorVersion minor_;
  PatchVersion patch_;
};
} // namespace dok

#endif /* Version_hpp */
