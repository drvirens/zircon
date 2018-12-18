#ifndef __zcRepo_h__
#define __zcRepo_h__

#include <functional>
#include "zcStatus.h"

class zcIdentifier;

template <typename DERIVED, typename AGGREGATE>
class zcRepo
{
public:
  zcStatus Put(const AGGREGATE &aAggregate, std::function<void(zcStatus)> aCompletion)
  {
    DERIVED *d = static_cast<DERIVED *>(this);
    if (d)
    {
      d->Put(aAggregate, aCompletion);
    }
  }
  void Get(const zcIdentifier &aId)
  {
    DERIVED *d = static_cast<DERIVED *>(this);
    if (d)
    {
      d->Get(aId);
    }
  }
  void Remove(const zcIdentifier &aId, std::function<void(zcStatus)> aCompletion)
  {
    DERIVED *d = static_cast<DERIVED *>(this);
    if (d)
    {
      d->Remove(aId, aCompletion);
    }
  }
};

#endif //__zcRepo_h__
