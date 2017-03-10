#ifndef CONFIGURATION_COMMANDLINEOPTIONSMANAGER_H_
#define CONFIGURATION_COMMANDLINEOPTIONSMANAGER_H_

#include <memory>
#include "CommandLineOptionsParser.h"
#include "ICommandLineOptionValidator.h"

namespace EasySoftCmdLine
{
    class CommandLineOptionsManager
    {
    public:
        CommandLineOptionsManager(EasySoftCmdLine::ICommandLineOptionValidator* validator, int argc, char** argv,
                                  bool linuxStyle = true, bool useSpaces = true, bool interactiveMode = false);
        bool TryGetValue(std::string key, std::string& outValue);
        bool TryGetIntValue(std::string key, int& outValue);
        bool TryGetDoubleValue(std::string key, double& outValue);
        std::vector<EasySoftCmdLine::KeyValueOption>& GetParsedOptions() {return _programOptions;}
    private:
        std::shared_ptr<EasySoftCmdLine::CommandLineOptionsParser> _parser;
        std::shared_ptr<EasySoftCmdLine::ICommandLineOptionValidator> _validator;
        std::vector<EasySoftCmdLine::KeyValueOption> _programOptions;
    };
}

#endif /* CONFIGURATION_COMMANDLINEOPTIONSMANAGER_H_ */
