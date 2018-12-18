#include <iostream>
#include "zcData.h"
#include "zcCommon.h"
#include "zcDomain.h"
#include "zcSinglyLinkedList.h"

static void _pFn_Foo()
{
    std::cout << "this is random private function" << std::endl;
}
zcData::zcData() : common_(0), domain_(0)
{
    std::cout << "zcData Defaul Constructor" << std::endl;
}
void zcData::ConstructL()
{
    std::cout << "zcData ConstructL" << std::endl;
    common_ = zcCommon::NewL();
    domain_ = zcDomain::NewL();
}
zcData *zcData::NewL()
{
    _pFn_Foo();
    std::cout << "zcData NewL" << std::endl;
    zcData *obj = new zcData;
    if (obj)
    {
        obj->ConstructL();
    }
    return obj;
}
zcData::~zcData()
{
    std::cout << "zcData desstructor" << std::endl;
}
std::string zcData::Name() const
{
    std::cout << "zcData Name" << std::endl;
    std::string commonname = common_->Name();
    std::string domainname = domain_->Name();
    std::cout << "zcCommon returned Name as:" << commonname << std::endl;
    std::cout << "zcDomain returned Name as:" << domainname << std::endl;
    return "zcData_Aha";
}
