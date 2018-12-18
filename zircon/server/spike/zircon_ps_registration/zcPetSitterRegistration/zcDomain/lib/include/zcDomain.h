#ifndef __zc_domain_h__
#define __zc_domain_h__

#include <string>
class zcCommon;

class zcDomain
{
private:
  std::string name_;
  zcCommon *common_;

private:
  zcDomain();
  void ConstructL();

public:
  static zcDomain *NewL();
  virtual ~zcDomain();
  std::string Name() const;
};

#endif //__zc_domain_h__