#ifndef CONFIGURATION_COMMANDLINEOPTIONSPARSER_H_
#define CONFIGURATION_COMMANDLINEOPTIONSPARSER_H_

#include <vector>
#include "KeyValueOption.h"
#include "platform.h"

namespace EasySoftCmdLine
{
    #define EXECUTION_PATH_KEY "path"
    #define COMMAND_KEY        "command"

    class EXPORT CommandLineOptionsParser
    {
    public:
        CommandLineOptionsParser(std::vector<std::string>& optionPrefixes, std::vector<std::string>& keyValueSeparators, bool interactiveMode = false);
        std::vector<EasySoftCmdLine::KeyValueOption>& Parse(const int argc, const char** argv);
    private:
        bool CheckIsKey(std::string& argumentString) const;
        bool CheckValueIsPresent(std::string& argumentString) const;
        std::string& GetKeyValueSeparator(std::string& argumentString);
    private:
        bool _interactiveMode;
        std::vector<KeyValueOption> _programOptions;
        std::vector<std::string> _optionPrefixes;
        std::vector<std::string> _keyValueSeparators;
    };
}

#endif /* CONFIGURATION_COMMANDLINEOPTIONSPARSER_H_ */
