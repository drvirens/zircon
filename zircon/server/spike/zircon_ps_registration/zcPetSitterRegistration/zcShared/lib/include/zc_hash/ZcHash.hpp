//
//  ZcHash.hpp
//  vsZircon_PetSitter
//
//  Created by Virendra Shakya on 10/8/18.
//  Copyright © 2018 Virendra Shakya. All rights reserved.
//

#ifndef ZcHash_hpp
#define ZcHash_hpp

#include <string>

namespace Zircon
{
namespace Common
{
  
  typedef std::string ZcDigest;
  static const ZcDigest kEmptyDigest = "";
  
template <typename HashImplT>
class ZcHash
{
public:
  void Reset() const
  {
    const HashImplT * const thiz = static_cast<const HashImplT * const>(this);
    if (thiz)
    {
      thiz->CallReset();
    }
  }

  ZcDigest Digest() const
  {
    const HashImplT * const thiz = static_cast<const HashImplT * const>(this);
    if (thiz)
    {
      return thiz->CallDigest();
    }
  return kEmptyDigest;
  }

  ZcDigest Compute(const void *aPtr, long aSize) const
  {
    const HashImplT * const thiz = static_cast<const HashImplT * const>(this);
    if (thiz)
    {
      return thiz->CallCompute(aPtr, aSize);
    }
  return kEmptyDigest;
  }

protected:
  void DoUpdate(const void *aPtr, long aSize)
  {
    const HashImplT * const thiz = static_cast<const HashImplT * const>(this);
    if (thiz)
    {
      thiz->CallDoUpdate(aPtr, aSize);
    }
  }
};
} // namespace Common
} // namespace Zircon

#endif /* ZcHash_hpp */
