#ifndef __zc_present_h__
#define __zc_present_h__

#include <string>
class zcCommon;
class zcDomain;

class zcPresent
{
private:
  std::string name_;
  zcCommon *common_;
  zcDomain *domain_;

private:
  zcPresent();
  void ConstructL();

public:
  static zcPresent *NewL();
  virtual ~zcPresent();
  std::string Name() const;
};

#endif //__zc_domain_h__
