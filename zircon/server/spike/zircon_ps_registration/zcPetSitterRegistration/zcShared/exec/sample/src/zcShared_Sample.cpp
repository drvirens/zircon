#include <iostream>
#include "zcCommon.h"

int main(int argC, char *argV[])
{
    std::cout << "zcCommon main function called boss" << std::endl;

    zcCommon *common = zcCommon::NewL();
    if (common)
    {
        std::cout << "zcCommon object allocated" << std::endl;
        std::string name = common->Name();
        std::cout << "zcCommon object Name returned => [" << name << "]" << std::endl;
    }
    return 0;
}