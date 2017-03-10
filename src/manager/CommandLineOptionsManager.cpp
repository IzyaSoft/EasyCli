#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <ICommandLineOptionValidator.h>
#include "CommandLineOptionsManager.h"

namespace EasySoftCmdLine
{
    CommandLineOptionsManager :: CommandLineOptionsManager(EasySoftCmdLine::ICommandLineOptionValidator* validator,
                                                           int argc, char** argv, bool linuxStyle, bool useSpaces, bool interactiveMode)
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

    bool CommandLineOptionsManager :: TryGetValue(std::string key, std::string& outValue)
    {
        std::vector<KeyValueOption>::iterator it = std::find_if(_programOptions.begin(), _programOptions.end(),
                                                               [key](EasySoftCmdLine::KeyValueOption item)
                                                               {
                                                                   return strcmp(item.GetKey().c_str(), key.c_str()) == 0;
                                                               });
        if(it==_programOptions.end())
            return false;
        outValue = (*it).GetValue();
        return true;
    }

    bool CommandLineOptionsManager :: TryGetIntValue(std::string key, int& outValue)
    {
        std::string value;
        if(TryGetValue(key, value))
            return false;
        outValue = atoi(value.c_str());
        return true;
    }

    bool CommandLineOptionsManager :: TryGetDoubleValue(std::string key, double& outValue)
    {
        std::string value;
        if(TryGetValue(key, value))
            return false;
        outValue = atof(value.c_str());
        return true;
    }
}
