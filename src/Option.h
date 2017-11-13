#ifndef EASYSOFTCLI_OPTION_H_
#define EASYSOFTCLI_OPTION_H_

#include <string>
#include "platform.h"

namespace EasySoft
{
    namespace Cli
    {
        class EXPORT Option
        {
        public:
            Option(const std::string& key, const std::string& value) :_key(key), _value(value) { }
            const std::string& GetKey() const {return _key;}
            const std::string& GetValue() const {return _value;}
        private:
            std::string _key;
            std::string _value;
        };
    }
}
#endif /* CONFIGURATION_KEYVALUEOPTION_H_ */
