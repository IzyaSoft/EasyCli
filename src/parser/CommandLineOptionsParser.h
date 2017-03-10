#ifndef CONFIGURATION_COMMANDLINEOPTIONSPARSER_H_
#define CONFIGURATION_COMMANDLINEOPTIONSPARSER_H_

#include <vector>
#include "KeyValueOption.h"

namespace EasySoftCmdLine
{
    #define EXECUTION_PATH_KEY "path"
    #define COMMAND_KEY        "command"

    class CommandLineOptionsParser
    {
    public:
        CommandLineOptionsParser(std::vector<std::string>& optionPrefixes, std::vector<std::string>& keyValueSeparators, bool interactiveMode = false);
        std::vector<EasySoftCmdLine::KeyValueOption>& Parse(int argc, char** argv);
    private:
        bool CheckIsKey(std::string& argumentString);
        bool CheckValueIsPresent(std::string& argumentString);
        std::string& GetKeyValueSeparator(std::string& argumentString);
    private:
        bool _interactiveMode;
        std::vector<KeyValueOption> _programOptions;
        std::vector<std::string> _optionPrefixes;
        std::vector<std::string> _keyValueSeparators;
    };
}

#endif /* CONFIGURATION_COMMANDLINEOPTIONSPARSER_H_ */
