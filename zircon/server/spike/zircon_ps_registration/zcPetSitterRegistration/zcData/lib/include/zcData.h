#ifndef __zc_data_h__
#define __zc_data_h__

#include <string>
class zcCommon;
class zcDomain;

class zcData
{
private:
  std::string name_;
  zcCommon *common_;
  zcDomain *domain_;

private:
  zcData();
  void ConstructL();

public:
  static zcData *NewL();
  virtual ~zcData();
  std::string Name() const;
};

#endif //__zc_data_h__
