#include <iostream>
#include <vector>
#include <CliParser.h>

// /port=COM6 /speed=115200 /parity=event /fc=cts (in VS debug settings) ONLY while run as DEBUG (F5)
int main(int argc, char **argv)
{
    std::vector<std::string> windowsCommandLinePrefixes = { "/" };
    std::vector<std::string> keyValueSeparatorViaEquals = { "=" };

    EasySoft::Cli::CliParser parser(windowsCommandLinePrefixes, keyValueSeparatorViaEquals);
    std::vector<EasySoft::Cli::Option> pairs = parser.Parse(argc, (const char**)argv);

    std::cout << "Key-Value Pairs:" << std::endl << std::endl;

    for (auto i = pairs.begin(); i != pairs.end(); ++i)
        std::cout << "Key: " << i->GetKey() << "; Value: " << i->GetValue() << ";" << std::endl;

    std::cin.get();

    return 0;
}
