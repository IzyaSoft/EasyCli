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
        virtual bool Validate(const std::vector<EasySoftCmdLine::KeyValueOption>& options, const bool useWithoutOptions = true, const bool printHelp = true) const;
        virtual ~ICommandLineOptionValidator(){}
    };
}
#endif /* CONFIGURATION_ICOMMANDOPTIONVALIDATOR_H_ */
