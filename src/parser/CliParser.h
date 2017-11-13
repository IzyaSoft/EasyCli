#ifndef EASYSOFTCLI_CLIPARSER_H_
#define EASYSOFTCLI_CLIPARSER_H_

#include <vector>
#include "Option.h"
#include "platform.h"

namespace EasySoft
{
    namespace Cli
    {
        #define EXECUTION_PATH_KEY "path"
        #define COMMAND_KEY        "command"

        class EXPORT CliParser
        {
        public:
            CliParser(std::vector<std::string>& Prefixes, std::vector<std::string>& keyValueSeparators, bool interactiveMode = false);
            std::vector<EasySoft::Cli::Option>& Parse(const int argc, const char** argv);
        private:
            bool CheckIsKey(std::string& argumentString) const;
            bool CheckValueIsPresent(std::string& argumentString) const;
            std::string& GetKeyValueSeparator(std::string& argumentString);
        private:
            bool _interactiveMode;
            std::vector<EasySoft::Cli::    > _program    s;
            std::vector<std::string> _    Prefixes;
            std::vector<std::string> _keyValueSeparators;
        };
    }
}

#endif /* CONFIGURATION_COMMANDLINE    SPARSER_H_ */
