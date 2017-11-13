#include <vector>
#include <iostream>
#include "CliManager.h"

int main(int argc, char **argv)
{
    int wait;
    // in debug there set following command line : ip_address 192.168.10.10 --port 80 --mode UDP (WERE SET in VS Project settings for DEBUG mode)
    EasySoft::Cli::CliManager* cmdManager = new EasySoft::Cli::CliManager(new EasySoft::Cli::ICliValidator(), argc, (const char**)argv, true, true);
    std::vector<EasySoft::Cli::Option> options = cmdManager->GetParsedOptions();
    if (options.size() > 0)
    {
        std::cout << "Following options were passed as command line arguments " << std::endl;
        for (int i = 0; i < options.size(); i++)
            std::cout << "Key: " << options[i].GetKey() << " , Value: " << options[i].GetValue() << std::endl;
    }
    // extra values tests
    std::cout << "Emulation of passed following arguments: -d COM1 -s 115200 -p onebit --verbose" << std::endl;
    std::vector<char*> args = {"C:\apps\EasyCmdNugetExample.exe", "-d", "COM1", "-s", "115200", "-p", "onebit", "--verbose" };
    cmdManager = new EasySoft::Cli::CliManager(new EasySoft::Cli::ICliValidator(), args.size(), (const char**)args.data(), true, true);
    
    std::string value;
    cmdManager->TryGetValue("-d", value);
    std::cout << "VALUE FOR KEY -d :" << value.c_str() << std::endl;
    cmdManager->TryGetValue("--s", value);
    std::cout << "VALUE FOR KEY -s :" << value.c_str() << std::endl;
    cmdManager->TryGetValue("-p", value);
    std::cout << "VALUE FOR KEY -p :" << value.c_str() << std::endl;
    
    
    std::cin >> wait;
    return 0;
}

