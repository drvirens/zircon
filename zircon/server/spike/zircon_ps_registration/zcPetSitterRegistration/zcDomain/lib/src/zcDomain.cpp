#include <iostream>
#include "zcDomain.h"
#include "zcCommon.h"
#include "zcSinglyLinkedList.h"

static void _pFn_Foo() {
  std::cout << "this is random private function" << std::endl;
}

zcDomain::zcDomain() : common_(0)
{
    std::cout << "zcDomain Defaul Constructor" << std::endl;
}
void zcDomain::ConstructL()
{
    std::cout << "zcDomain ConstructL" << std::endl;
    common_ = zcCommon::NewL();
}
zcDomain *zcDomain::NewL()
{
  _pFn_Foo();
    std::cout << "zcDomain NewL" << std::endl;
    zcDomain *obj = new zcDomain;
    if (obj)
    {
        obj->ConstructL();
    }
    return obj;
}
zcDomain::~zcDomain()
{
    std::cout << "zcDomain desstructor" << std::endl;
}
std::string zcDomain::Name() const
{
    std::string commonname = common_->Name();
    std::cout << "zcCommon returned Name as:" << commonname << std::endl;
    std::cout << "zcDomain Name" << std::endl;
    return "zcDomain_Aha";
}
