#ifndef CONFIGURATION_NESTEDOPTIONS_H_
#define CONFIGURATION_NESTEDOPTIONS_H_

#include <string>

namespace EasySoftCmdLine
{
    std::string helpMessage =
        "  There are following command line options: \r\n"
        "  1. Entering interactive mode : --interactive or -ia \r\n"
        "  2. Receive help info --help or -h \r\n"
        "  3. See version number --version or -v \r\n"
        "  4. Use verbose mode --verbose or -vv \r\n";

    std::string interactiveOptions =
        "  Options in interactive mode starts from command, possible commands are help, send or convert, keys are the same as for traditional mode:\r\n"
        "";
}

#endif /* CONFIGURATION_NESTEDOPTIONS_H_ */
