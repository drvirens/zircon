#ifndef __zcStatus_h__
#define __zcStatus_h__

enum zcStatusType
{
    zcStatus_Pending,
    zcStatus_Success,
    zcStatus_Failed,
    zcStatus_Max
};

class zcStatus
{
  public:
    zcStatus();
    explicit zcStatus(const zcStatusType aStatusType);
    zcStatusType Status() const;

  private:
    const zcStatusType status_;
};
#endif