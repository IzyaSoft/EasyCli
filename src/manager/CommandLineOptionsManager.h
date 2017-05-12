#ifndef CONFIGURATION_COMMANDLINEOPTIONSMANAGER_H_
#define CONFIGURATION_COMMANDLINEOPTIONSMANAGER_H_

#include <memory>
#include "CommandLineOptionsParser.h"
#include "ICommandLineOptionValidator.h"

namespace EasySoftCmdLine
{
    class EXPORT CommandLineOptionsManager
    {
    public:
        CommandLineOptionsManager(EasySoftCmdLine::ICommandLineOptionValidator* validator, const int argc, const char** argv,
                                  const bool linuxStyle = true, const bool useSpaces = true, const bool interactiveMode = false);
        bool TryGetValue(const std::string& key, std::string& outValue) const;
        bool TryGetIntValue(const std::string& key, int& outValue) const;
        bool TryGetDoubleValue(const std::string& key, double& outValue) const;
        std::vector<EasySoftCmdLine::KeyValueOption>& GetParsedOptions() {return _programOptions;}
    private:
        std::shared_ptr<EasySoftCmdLine::CommandLineOptionsParser> _parser;
        std::shared_ptr<EasySoftCmdLine::ICommandLineOptionValidator> _validator;
        std::vector<EasySoftCmdLine::KeyValueOption> _programOptions;
    };
}

#endif /* CONFIGURATION_COMMANDLINEOPTIONSMANAGER_H_ */
