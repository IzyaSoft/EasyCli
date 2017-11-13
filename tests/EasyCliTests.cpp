#include "gtest/gtest.h"
#include "parser/TestCliParser.h"

using namespace std;
using namespace EasySoft::Cli::Tests;

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
