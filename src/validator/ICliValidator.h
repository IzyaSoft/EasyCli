#ifndef EASYSOFTCLI_ICLIVALIDATOR_H_
#define EASYSOFTCLI_ICLIVALIDATOR_H_

#include <vector>
#include "Option.h"
#include "platform.h"

namespace EasySoft
{
    namespace Cli
    {
        class EXPORT ICliValidator
        {
        public:
            virtual bool Validate(const std::vector<EasySoft::Cli::Option>& options,
                                  const bool useWithoutOptions = true,
                                  const bool printHelp = true) const;
            virtual ~ICliValidator(){}
        };
    }
}
#endif
