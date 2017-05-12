#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <ICommandLineOptionValidator.h>
#include "CommandLineOptionsManager.h"

namespace EasySoftCmdLine
{
    CommandLineOptionsManager :: CommandLineOptionsManager(EasySoftCmdLine::ICommandLineOptionValidator* validator,
                                                           const int argc, const char** argv, const bool linuxStyle,
                                                           const bool useSpaces, const bool interactiveMode)
    {
        _validator = std::shared_ptr<EasySoftCmdLine::ICommandLineOptionValidator>(validator);
        std::vector<std::string> prefix;
        if(linuxStyle)
            prefix = {"-", "--"};
        else prefix = {"/"};
        std::vector<std::string> separators;
        if(!useSpaces)
            separators.push_back("=");
        _parser = std::shared_ptr<EasySoftCmdLine::CommandLineOptionsParser>(new EasySoftCmdLine::CommandLineOptionsParser(prefix, separators, interactiveMode));
        _programOptions = _parser->Parse(argc, argv);
        bool validationResult = _validator->Validate(_programOptions, false, false);
        if(!validationResult)
            exit(1);
    }

    bool CommandLineOptionsManager :: TryGetValue(const std::string& key, std::string& outValue) const
    {
        std::vector<KeyValueOption>::const_iterator it = std::find_if(_programOptions.begin(), _programOptions.end(),
                                                               [key](EasySoftCmdLine::KeyValueOption item)
                                                               {
                                                                   return strcmp(item.GetKey().c_str(), key.c_str()) == 0;
                                                               });
        if(it==_programOptions.end())
            return false;
        outValue = (*it).GetValue();
        return true;
    }

    bool CommandLineOptionsManager :: TryGetIntValue(const std::string& key, int& outValue) const
    {
        std::string value;
        if(!TryGetValue(key, value))
            return false;
        outValue = atoi(value.c_str());
        return true;
    }

    bool CommandLineOptionsManager :: TryGetDoubleValue(const std::string& key, double& outValue) const
    {
        std::string value;
        if(!TryGetValue(key, value))
            return false;
        outValue = atof(value.c_str());
        return true;
    }
}
