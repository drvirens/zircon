#ifndef __zcAccountRepo_h__
#define __zcAccountRepo_h__

#include <aggregate/Aggregate.hpp>
#include "zcRepo.h"

class zcAccountRepo : public zcRepo<zcAccountRepo, domain::Aggregate>
{
public:
  zcAccountRepo();
  ~zcAccountRepo();

  zcStatus Put(const domain::Aggregate &aAggregate, std::function<void(zcStatus)> aCompletion)
  {
    zcStatus status;

    aCompletion(status);

    return status;
  }
  void Get(const zcIdentifier &aId)
  {
  }
  void Remove(const zcIdentifier &aId, std::function<void(zcStatus)> aCompletion)
  {
  }
};

#endif //__zcAccountRepo_h__
