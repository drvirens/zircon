// #include <iostream>
// #include "zcDomain.h"

// int main(int argC, char *argV[])
// {
//     std::cout << "zcDomain test suite main function called hugo boss man" << std::endl;

//     zcDomain *common = zcDomain::NewL();
//     if (common)
//     {
//         std::cout << "zcDomain object allocated" << std::endl;
//         std::string name = common->Name();
//         std::cout << "zcDomain object Name returned => [" << name << "]" << std::endl;
//     }
//     return 0;
// }

#define CATCH_CONFIG_CONSOLE_WIDTH 120
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
