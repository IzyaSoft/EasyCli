#include <string.h>
#include <future>
#include "CliParser.h"

namespace EasySoft
{
    namespace Cli
    {
        CliParser :: CliParser(std::vector<std::string>& optionPrefixes, std::vector<std::string>& keyValueSeparators, bool interactiveMode)
        {
           _optionPrefixes.assign(optionPrefixes.begin(), optionPrefixes.end());
           _keyValueSeparators.assign(keyValueSeparators.begin(), keyValueSeparators.end());
           _interactiveMode = interactiveMode;
        }

        std::vector<EasySoft::Cli::Option>& CliParser :: Parse(const int argc, const char** argv)
        {
            try
            {
                _programOptions.reserve(argc);
                std::string firstKey = _interactiveMode ? COMMAND_KEY : EXECUTION_PATH_KEY;
                _programOptions.push_back(EasySoft::Cli::Option (firstKey, argv[0]));
                for(int argCounter = 1; argCounter < argc; argCounter++)
                {
                    std::string argumentString(argv[argCounter]);
                    if(CheckIsKey(argumentString))
                    {
                        // probably could be a value ...
                        // 1. key and value in the one string i.e. key=value
                        if(CheckValueIsPresent(argumentString))
                        {
                            std::string separator = GetKeyValueSeparator(argumentString);
                            int index = argumentString.find(separator);
                            _programOptions.push_back(EasySoft::Cli::Option (argumentString.substr(0, index), argumentString.substr(index + separator.size())));
                            continue;
                        }
                        if(argCounter + 1 < argc)
                        {
                            std::string nextArgumentString(argv[argCounter + 1]);
                            // 2. key and value were separated with space and placed in 2 different elements
                            if(!CheckIsKey(nextArgumentString))
                            {
                                _programOptions.push_back(EasySoft::Cli::Option (argumentString, nextArgumentString));
                                continue;
                            }
                        }
                        // 3. option contains only key and no value
                        _programOptions.push_back(EasySoft::Cli::Option (argumentString, std::string ()));
                    }
                }
                return _programOptions;
            }
            catch(...)
            {
                _programOptions.clear();
                return _programOptions;
            }
        }

        std::string& CliParser :: GetKeyValueSeparator(std::string& argumentString)
        {
            std::vector<std::string>::iterator it;
            for(it = _keyValueSeparators.begin(); it != _keyValueSeparators.end(); it++)
                if(argumentString.find(*it) != std::string::npos)
                    return (*it);
            throw std::runtime_error("Something goes wrong at getting key value separator!");
        }

        bool CliParser :: CheckValueIsPresent(std::string& argumentString) const
        {
            std::vector<std::string>::const_iterator it;
            for(it = _keyValueSeparators.begin(); it != _keyValueSeparators.end(); it++)
                if(argumentString.find(*it) != std::string::npos)
                    return true;
            return false;
        }

        bool CliParser :: CheckIsKey(std::string& argumentString) const
        {
           std::vector<std::string>::const_iterator it;
           for(it = _optionPrefixes.begin(); it!= _optionPrefixes.end(); it++)
               if(strncmp((*it).c_str(), argumentString.c_str(), (*it).size()) == 0)
                   return true;
           return false;
        }
    }
}
