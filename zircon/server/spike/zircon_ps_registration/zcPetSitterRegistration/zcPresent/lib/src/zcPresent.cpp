#include <iostream>
#include "zcPresent.h"
#include "zcCommon.h"
#include "zcDomain.h"
#include "zcSinglyLinkedList.h"

static void _pFn_Foo()
{
    std::cout << "this is random private function" << std::endl;
}
zcPresent::zcPresent() : common_(0), domain_(0)
{
    std::cout << "zcPresent Defaul Constructor" << std::endl;
}
void zcPresent::ConstructL()
{
    std::cout << "zcPresent ConstructL" << std::endl;
    common_ = zcCommon::NewL();
    domain_ = zcDomain::NewL();
}
zcPresent *zcPresent::NewL()
{
    _pFn_Foo();
    std::cout << "zcPresent NewL" << std::endl;
    zcPresent *obj = new zcPresent;
    if (obj)
    {
        obj->ConstructL();
    }
    return obj;
}
zcPresent::~zcPresent()
{
    std::cout << "zcPresent desstructor" << std::endl;
}
std::string zcPresent::Name() const
{
    std::cout << "zcPresent Name" << std::endl;
    std::string commonname = common_->Name();
    std::string domainname = domain_->Name();
    std::cout << "zcCommon returned Name as:" << commonname << std::endl;
    std::cout << "zcDomain returned Name as:" << domainname << std::endl;
    return "zcPresent_Aha";
}
