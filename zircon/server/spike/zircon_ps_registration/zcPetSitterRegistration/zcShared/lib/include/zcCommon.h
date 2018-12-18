#ifndef __zc_common_h__
#define __zc_common_h__

#include <string>

class zcCommon
{
private:
  std::string name_;

private:
  zcCommon();
  void ConstructL();

public:
  static zcCommon *NewL();
  virtual ~zcCommon();
  std::string Name() const;
};

#endif //__zc_common_h__