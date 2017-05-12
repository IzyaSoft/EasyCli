#ifndef CONFIGURATION_TESTCOMMANDLINEOPTIONSPARSER_H_
#define CONFIGURATION_TESTCOMMANDLINEOPTIONSPARSER_H_

#include <vector>
#include "CommandLineOptionsParser.h"
#include "gtest/gtest.h"

namespace EasySoftCmdLineTests
{
    std::vector<std::string> linuxCommandLinePrefixes = {"-", "--"};
    std::vector<std::string> windowsCommandLinePrefixes = {"/"};
    std::vector<std::string> keyValueSeparatorViaEquals = {"="};
    std::vector<std::string> keyValueSeparatorViaSpace = {};

    //std::string simpleValidString = "./someapp --help";
    //std::string simpleValidString2 = "./someapp -l \"abcdefgh\" --verbose";
    const char* onlyHelpOption[] = {"./someapp", "--help"};
    std::vector<EasySoftCmdLine::KeyValueOption> expectedOnlyHelpOptions = {EasySoftCmdLine::KeyValueOption(EXECUTION_PATH_KEY, "./someapp"),
                                                                            EasySoftCmdLine::KeyValueOption("--help", "")};
    const char* optionsWithRealValues[] = {"./someapp", "-l", "abcdefgh", "--verbose"};
    std::vector<EasySoftCmdLine::KeyValueOption> expectedOptionsWithRealValues = {EasySoftCmdLine::KeyValueOption(EXECUTION_PATH_KEY, "./someapp"),
                                                                                  EasySoftCmdLine::KeyValueOption("-l", "abcdefgh"),
                                                                                  EasySoftCmdLine::KeyValueOption("--verbose", "")};
    const char* optionsWithRealValuesSeparatedWithEquals[] = {"./someapp", "-l=abcdefgh", "--device=/dev/usb1", "--subcarrier=2"};
    std::vector<EasySoftCmdLine::KeyValueOption> expectedOptionsWithRealValuesSeparatedWithEquals = {EasySoftCmdLine::KeyValueOption(EXECUTION_PATH_KEY, "./someapp"),
                                                                                                     EasySoftCmdLine::KeyValueOption("-l", "abcdefgh"),
                                                                                                     EasySoftCmdLine::KeyValueOption("--device", "/dev/usb1"),
                                                                                                     EasySoftCmdLine::KeyValueOption("--subcarrier", "2")};
    const char* optionsWithoutPrefixes[] = {"./someapp", "abc", "def=def", "aaa", "lll"};
    std::vector<EasySoftCmdLine::KeyValueOption> expectedOptionsWithoutPrefixes = {EasySoftCmdLine::KeyValueOption(EXECUTION_PATH_KEY, "./someapp")};
    const char* optionsWithRealValuesSeparatedWithEqualsWinStyle[] = {".\\someapp.exe", "/l=abcdefgh", "/device=usb1", "/subcarrier=2"};
    std::vector<EasySoftCmdLine::KeyValueOption> expectedOptionsWithRealValuesSeparatedWithEqualsWinStyle = {EasySoftCmdLine::KeyValueOption(EXECUTION_PATH_KEY, ".\\someapp.exe"),
                                                                                                             EasySoftCmdLine::KeyValueOption("/l", "abcdefgh"),
                                                                                                             EasySoftCmdLine::KeyValueOption("/device", "usb1"),
                                                                                                             EasySoftCmdLine::KeyValueOption("/subcarrier", "2")};

    void CheckOptions(std::vector<EasySoftCmdLine::KeyValueOption> expected, std::vector<EasySoftCmdLine::KeyValueOption> actual)
    {
        ASSERT_EQ(expected.size(), actual.size());
        for(unsigned int optionCounter = 0; optionCounter < expected.size(); optionCounter++)
        {
            ASSERT_STREQ(expected[optionCounter].GetKey().c_str(), actual[optionCounter].GetKey().c_str());
            ASSERT_STREQ(expected[optionCounter].GetKey().c_str(), actual[optionCounter].GetKey().c_str());
        }
    }

    TEST(CommandLineOptionsParser, SimpleOnlyKeysLinuxStyle)
    {
        EasySoftCmdLine::CommandLineOptionsParser parser(linuxCommandLinePrefixes, keyValueSeparatorViaSpace);
        std::vector<EasySoftCmdLine::KeyValueOption> actual = parser.Parse(2, onlyHelpOption);
        CheckOptions(expectedOnlyHelpOptions, actual);
    }

    TEST(CommandLineOptionsParser, KeysSeparatedWithValuesViaSpaceLinuxStyle)
    {
        EasySoftCmdLine::CommandLineOptionsParser parser(linuxCommandLinePrefixes, keyValueSeparatorViaSpace);
        std::vector<EasySoftCmdLine::KeyValueOption> actual = parser.Parse(4, optionsWithRealValues);
        CheckOptions(expectedOptionsWithRealValues, actual);
    }

    TEST(CommandLineOptionsParser, KeysSeparatedWithValuesViaEqualsLinuxStyle)
    {
        EasySoftCmdLine::CommandLineOptionsParser parser(linuxCommandLinePrefixes, keyValueSeparatorViaEquals);
        std::vector<EasySoftCmdLine::KeyValueOption> actual = parser.Parse(4, optionsWithRealValuesSeparatedWithEquals);
        CheckOptions(expectedOptionsWithRealValuesSeparatedWithEquals, actual);
    }

    TEST(CommandLineOptionsParser, KeysWithoutPrefixes)
    {
        EasySoftCmdLine::CommandLineOptionsParser parser(linuxCommandLinePrefixes, keyValueSeparatorViaEquals);
        std::vector<EasySoftCmdLine::KeyValueOption> actual = parser.Parse(4, optionsWithoutPrefixes);
        CheckOptions(expectedOptionsWithoutPrefixes, actual);
    }

    TEST(CommandLineOptionsParser, KeysSeparatedWithValuesViaEqualsWindowsStyle)
    {
        EasySoftCmdLine::CommandLineOptionsParser parser(windowsCommandLinePrefixes, keyValueSeparatorViaEquals);
        std::vector<EasySoftCmdLine::KeyValueOption> actual = parser.Parse(4, optionsWithRealValuesSeparatedWithEqualsWinStyle);
        CheckOptions(expectedOptionsWithRealValuesSeparatedWithEqualsWinStyle, actual);
    }
}


#endif /* CONFIGURATION_TESTCOMMANDLINEOPTIONSPARSER_H_ */
