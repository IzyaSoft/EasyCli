#ifndef CONFIGURATION_ICOMMANDOPTIONVALIDATOR_H_
#define CONFIGURATION_ICOMMANDOPTIONVALIDATOR_H_

#include <vector>
#include "KeyValueOption.h"
#include "platform.h"

namespace EasySoftCmdLine
{
    class EXPORT ICommandLineOptionValidator
    {
    public:
        virtual bool Validate(std::vector<EasySoftCmdLine::KeyValueOption> options, bool useWithoutOptions = true, bool printHelp = true);
        virtual ~ICommandLineOptionValidator(){}
    };
}
#endif /* CONFIGURATION_ICOMMANDOPTIONVALIDATOR_H_ */
