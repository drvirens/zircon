//
//  DoB.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/3/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef DoB_hpp
#define DoB_hpp

namespace domain
{
class DoB
{
private:
  const int mm_;
  const int dd_;
  const int yyyy_;

public:
  explicit DoB(int mm, int dd, int yyyy);
};
} // namespace domain

#endif /* DoB_hpp */
