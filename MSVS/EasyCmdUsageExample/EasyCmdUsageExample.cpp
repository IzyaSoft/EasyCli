
#include <CommandLineOptionsParser.h>
#include <iostream>

int main(int argc, char **argv)
{
    std::vector<std::string> windowsCommandLinePrefixes = { "/" };
    std::vector<std::string> keyValueSeparatorViaEquals = { "=" };

    EasySoftCmdLine::CommandLineOptionsParser parser(windowsCommandLinePrefixes, keyValueSeparatorViaEquals);
    std::vector<EasySoftCmdLine::KeyValueOption> pairs = parser.Parse(argc, (const char**)argv);

    std::cout << "Key-Value Pairs:" << std::endl << std::endl;

    for (auto i = pairs.begin(); i != pairs.end(); ++i)
        std::cout << "Key: " << i->GetKey() << "; Value: " << i->GetValue() << ";" << std::endl;

    std::cin.get();

    return 0;
}