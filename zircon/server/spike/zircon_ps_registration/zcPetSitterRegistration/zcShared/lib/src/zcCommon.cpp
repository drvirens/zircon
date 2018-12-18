#include <iostream>
#include "zcCommon.h"

zcCommon::zcCommon()
{
    std::cout << "zcCommon Defaul Constructor" << std::endl;
}
void zcCommon::ConstructL()
{
    std::cout << "zcCommon ConstructL" << std::endl;
}
zcCommon *zcCommon::NewL()
{
    std::cout << "zcCommon NewL" << std::endl;
    zcCommon *obj = new zcCommon;
    if (obj)
    {
        obj->ConstructL();
    }
    return obj;
}
zcCommon::~zcCommon()
{
    std::cout << "zcCommon desstructor" << std::endl;
}
std::string zcCommon::Name() const
{
    std::cout << "zcCommon Name" << std::endl;
    return "zcCommon_Aha";
}
