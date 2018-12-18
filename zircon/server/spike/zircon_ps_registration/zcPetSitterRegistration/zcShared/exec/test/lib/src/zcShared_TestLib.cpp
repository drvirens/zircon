// #include <iostream>
// #include "zcCommon.h"

// int main(int argC, char *argV[])
// {
//     std::cout << "zcCommon test suite main function called hugo boss man" << std::endl;

//     zcCommon *common = zcCommon::NewL();
//     if (common)
//     {
//         std::cout << "zcCommon object allocated" << std::endl;
//         std::string name = common->Name();
//         std::cout << "zcCommon object Name returned => [" << name << "]" << std::endl;
//     }
//     return 0;
// }

#define CATCH_CONFIG_CONSOLE_WIDTH 120
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
