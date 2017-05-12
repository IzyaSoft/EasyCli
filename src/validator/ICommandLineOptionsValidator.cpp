#include <ICommandLineOptionValidator.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include "ConfigurationKeys.h"

namespace EasySoftCmdLine
{
    bool ICommandLineOptionValidator :: Validate(const std::vector<EasySoftCmdLine::KeyValueOption>& options, const bool useWithoutOptions, const bool printHelp) const
    {
        if(!useWithoutOptions && options.size() < 2)
        {
            std::cout << "Missing arguments, how to use see " << options[0].GetValue() << " " << HELP_LONG << " or " << HELP_SHORT << "." << std::endl;
            return false;
        }
        bool helpPresent = false;
        std::find_if(options.begin(), options.end(),[&helpPresent](EasySoftCmdLine::KeyValueOption option)
                                                    {
                                                        helpPresent = (strcmp(option.GetKey().c_str(), HELP_LONG) == 0) ||
                                                                      (strcmp(option.GetKey().c_str(), HELP_SHORT) == 0);
                                                        return helpPresent;
                                                    });
        if(helpPresent && options.size() > 2)
        {
            std::cout << HELP_LONG << " or " << HELP_SHORT << " can't be use simultaneously with other keys." << std::endl;
            return false;
        }

        bool versionPresent = false;
        std::find_if(options.begin(), options.end(),[&versionPresent](EasySoftCmdLine::KeyValueOption option)
                                                    {
                                                        versionPresent = (strcmp(option.GetKey().c_str(), VERSION_LONG) == 0) ||
                                                                         (strcmp(option.GetKey().c_str(), VERSION_SHORT) == 0);
                                                        return versionPresent;
                                                    });
        if(versionPresent && options.size() > 2)
        {
            std::cout << VERSION_LONG << " or " << VERSION_SHORT << " can't be use simultaneously with other keys." << std::endl;
            return false;
        }
        return true;
    }
}
