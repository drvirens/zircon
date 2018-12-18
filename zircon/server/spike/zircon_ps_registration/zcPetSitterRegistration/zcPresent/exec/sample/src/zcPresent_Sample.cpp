#include <iostream>
#include "zcPresent.h"


int main(int argC, char *argV[])
{
    std::cout << "zcPresent main function called boss" << std::endl;

    zcPresent *common = zcPresent::NewL();
    if (common)
    {
        std::cout << "zcPresent object allocated" << std::endl;
        std::string name = common->Name();
        std::cout << "zcPresent object Name returned => [" << name << "]" << std::endl;
    }

    return 0;
}
