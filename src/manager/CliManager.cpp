#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <ICliValidator.h>
#include "CliManager.h"

namespace EasySoft
{
    namespace Cli
    {
        CliManager :: CliManager(EasySoft::Cli::ICliValidator* validator,
                                 const int argc, const char** argv, const bool linuxStyle,
                                 const bool useSpaces, const bool interactiveMode)
        {
            _validator = std::shared_ptr<EasySoft::Cli::ICliValidator>(validator);
            std::vector<std::string> prefix;
            if(linuxStyle)
                prefix = {"-", "--"};
            else prefix = {"/"};
            std::vector<std::string> separators;
            if(!useSpaces)
                separators.push_back("=");
            _parser = std::shared_ptr<EasySoft::Cli::CliParser>(new EasySoft::Cli::CliParser(prefix, separators, interactiveMode));
            _options = _parser->Parse(argc, argv);
            bool validationResult = _validator->Validate(_options, false, false);
            if(!validationResult)
                exit(1);
        }

        bool CliManager :: TryGetValue(const std::string& key, std::string& outValue) const
        {
            std::vector<EasySoft::Cli::Option>::const_iterator it = std::find_if(_options.begin(), _options.end(),
                                                                   [key](EasySoft::Cli::Option item)
                                                                   {
                                                                       return strcmp(item.GetKey().c_str(), key.c_str()) == 0;
                                                                   });
            if(it==_options.end())
                return false;
            outValue = (*it).GetValue();
            return true;
        }

        bool CliManager :: TryGetIntValue(const std::string& key, int& outValue) const
        {
            std::string value;
            if(!TryGetValue(key, value))
                return false;
            outValue = atoi(value.c_str());
            return true;
        }

        bool CliManager :: TryGetDoubleValue(const std::string& key, double& outValue) const
        {
            std::string value;
            if(!TryGetValue(key, value))
                return false;
            outValue = atof(value.c_str());
            return true;
        }
    }
}
