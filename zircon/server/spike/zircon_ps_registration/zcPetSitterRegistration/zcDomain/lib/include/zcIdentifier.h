#ifndef __zcIdentifier_h__
#define __zcIdentifier_h__

#include <string>

class zcIdentifier
{
  private:
    std::string id_;

  public:
    explicit zcIdentifier(const std::string &aId);
    explicit zcIdentifier();
    ~zcIdentifier();

    std::string Id() const;
};

#endif //__zcIdentifier_h__