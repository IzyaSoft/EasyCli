#ifndef EASYSOFTCLI_CLIMANAGER_H_
#define EASYSOFTCLI_CLIMANAGER_H_

#include <memory>
#include "CliParser.h"
#include "ICliValidator.h"

namespace EasySoft
{
    namespace Cli
    {
        class EXPORT CliManager
        {
        public:
            CliManager(EasySoft::Cli::ICliValidator* validator, const int argc, const char** argv,
                       const bool linuxStyle = true, const bool useSpaces = true, const bool interactiveMode = false);
            bool TryGetValue(const std::string& key, std::string& outValue) const;
            bool TryGetIntValue(const std::string& key, int& outValue) const;
            bool TryGetDoubleValue(const std::string& key, double& outValue) const;
            std::vector<EasySoft::Cli::Option>& GetParsedOptions() {return _options;}
        private:
            std::shared_ptr<EasySoft::Cli::CliParser> _parser;
            std::shared_ptr<EasySoft::Cli::ICliValidator> _validator;
            std::vector<EasySoft::Cli::Option> _options;
        };
    }
}

#endif
