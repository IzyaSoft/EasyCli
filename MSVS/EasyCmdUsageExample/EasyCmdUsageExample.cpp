
#include <CommandLineOptionsParser.h>

int main(int argc, char **argv)
{
    std::vector<std::string> windowsCommandLinePrefixes = { "/" };
    std::vector<std::string> keyValueSeparatorViaEquals = { "=" };

    EasySoftCmdLine::CommandLineOptionsParser parser(windowsCommandLinePrefixes, keyValueSeparatorViaEquals);
    std::vector<EasySoftCmdLine::KeyValueOption> actual = parser.Parse(argc, argv);

    return 0;
}