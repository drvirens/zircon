//
//  Test_Unit_Hash.cpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/8/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#include <iostream>
#include <catch2/catch.hpp>
#include "zc_hash/ZcHash.hpp"

class MyHash : public Zircon::Common::ZcHash<MyHash>
{
private:
  Zircon::Common::ZcDigest digest_;

public:
  void CallReset() const
  {
    std::cout << "MyHash::CallReset called" << std::endl;
  }
  Zircon::Common::ZcDigest CallDigest() const
  {
    std::cout << "MyHash::CallDigest called" << std::endl;
    return digest_;
  }

  Zircon::Common::ZcDigest CallCompute(const void *aPtr, long aSize) const
  {
    std::cout << "MyHash::CallCompute called" << std::endl;
    return digest_;
  }

protected:
  void CallDoUpdate(const void *aPtr, long aSize)
  {
    std::cout << "MyHash::CallDoUpdate called" << std::endl;
  }
};

void testHash()
{
  MyHash hash;
  hash.Reset();
  hash.Compute(0, 0);
  Zircon::Common::ZcDigest digest = hash.Digest();
}

TEST_CASE("Reset of derived is called", "[ZcHash]")
{
  testHash();
}
