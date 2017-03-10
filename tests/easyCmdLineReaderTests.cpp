#include <iostream>
#include "TestCommandLineOptionsParser.h"
#include "gtest/gtest.h"

using namespace std;
using namespace EasySoftCmdLineTests;

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
