#ifndef CONFIGURATION_KEYVALUEOPTION_H_
#define CONFIGURATION_KEYVALUEOPTION_H_

#include <string>

namespace EasySoftCmdLine
{
    class KeyValueOption
    {
    public:
        KeyValueOption(std::string key, std::string value) :_key(key), _value(value) { }
        std::string GetKey() {return _key;}
        std::string GetValue() {return _value;}
    private:
        std::string _key;
        std::string _value;
    };
}
#endif /* CONFIGURATION_KEYVALUEOPTION_H_ */
