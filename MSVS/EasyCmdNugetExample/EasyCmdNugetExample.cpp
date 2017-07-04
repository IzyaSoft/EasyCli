#include <vector>
#include <iostream>
#include "CommandLineOptionsManager.h"

int main(int argc, char **argv)
{
    int wait;
    // extra values tests
    std::vector<char*> args = {"C:\apps\EasyCmdNugetExample.exe", "-d", "COM1", "-s", "115200", "-p", "onebit", "--verbose" };
    EasySoftCmdLine::CommandLineOptionsManager cmdManager(new EasySoftCmdLine::ICommandLineOptionValidator(),
                                                          args.size(), (const char**)args.data(), true, true);
    
    std::string value;
    cmdManager.TryGetValue("-d", value);
    std::cout << "VALUE FOR KEY -d :" << value.c_str() << std::endl;
    cmdManager.TryGetValue("--s", value);
    std::cout << "VALUE FOR KEY -s :" << value.c_str() << std::endl;
    cmdManager.TryGetValue("-p", value);
    std::cout << "VALUE FOR KEY -p :" << value.c_str() << std::endl;
    
    //std::vector<EasySoftCmdLine::KeyValueOption> options = cmdManager.GetParsedOptions();
    std::cin >> wait;
    return 0;
}

