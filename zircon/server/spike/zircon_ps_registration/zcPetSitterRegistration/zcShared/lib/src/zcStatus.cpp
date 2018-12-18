#include "zcStatus.h"

zcStatus::zcStatus() : status_(zcStatus_Pending)
{
}
zcStatus::zcStatus(const zcStatusType aStatusType)
    : status_(aStatusType)
{
}
zcStatusType zcStatus::Status() const
{
    return status_;
}