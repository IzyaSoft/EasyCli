#ifndef CONFIGURATION_NESTEDOPTIONS_H_
#define CONFIGURATION_NESTEDOPTIONS_H_

#include <string>

namespace EasySoftCmdLine
{
    std::string helpMessage =
        "  Emulator is software for testing algorithms of 802.11ah standard with following possibilities: \r\n"
        "  1) selecting using converters (padding, scrambler, fec, spatial mapping, e.t.c) \r\n"
        "  2) printing and logging result of encoding/decoding with selected converters \r\n"
        "  3) sending and receiving data via usb as byte streams \r\n\r\n"
        "  There are following command line options: \r\n"
        "  1. Entering interactive mode : --interactive or -ia \r\n"
        "  2. Receive help info --help or -h \r\n"
        "  3. See version number --version \r\n"
        "  4. Convert line (string) and print it to stdout --line or -l (i.e. ./emulator --line test-line \r\n"
        "  5. Convert file (will be opened in text mode) and print it to stdout --file or -f (i.e. ./emulator --file sample.txt \r\n"
        "  6. Convert file (--file or -f) or line (--line or -l) and transmit it via usb device (--device or -d) using subcarrier (--subcarrier or -sc),"
        "     the last one is optional, i.e. ./emulator -l abcdef -d /dev/usb1s -sc 2 \r\n"
        "  7. Repeat sending --repeat or -r i.e. ./emulator -l abcdef -d /dev/usb1 -r 5 \r\n\r\n"
        "  8. It is possible to separate symbols by --symbols or sb, i.e. -sb [STF] --repeat 3, or --symbol [STF][LTF], or or --symbols [LTF]"
        "  9. It is possible to set up convertion direction with key --direct or -dr will be used direct convertion, or --reverse / -rv for reverse \r\n"
        "     or --round for both first direct and after that reverse.";

    std::string interactiveOptions =
        "  Options in interactive mode starts from command, possible commands are help, send or convert, keys are the same as for traditional mode:\r\n"
        "  1. Convert line (string) and print it to stdout --line or -l (i.e. ./emulator --line test-line \r\n"
        "  2. Convert file (will be opened in text mode) and print it to stdout --file or -f (i.e. ./emulator --file sample.txt \r\n"
        "  3. Convert file (--file or -f) or line (--line or -l) and transmit it via usb device (--device or -d) using subcarrier (--subcarrier or -sc),"
        "     the last one is optional, i.e. ./emulator -l abcdef -d /dev/usb1s -sc 2 \r\n"
        "  4. Repeat sending --repeat or -r i.e. ./emulator -l abcdef -d /dev/usb1 -r 5 \r\n\r\n"
        "  5. It is possible to separate symbols by --symbols or sb, i.e. -sb [STF] --repeat 3, or --symbol [STF][LTF], or or --symbols [LTF]"
        "  6. It is possible to set up convertion direction with key --direct or -dr will be used direct convertion, or --reverse / -rv for reverse \r\n"
        "     or --round for both first direct and after that reverse.";
}

#endif /* CONFIGURATION_NESTEDOPTIONS_H_ */
