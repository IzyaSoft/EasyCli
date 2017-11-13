#ifndef TESTEASYSOFTCLI_TESTPARSER_H_
#define TESTEASYSOFTCLI_TESTPARSER_H_

#include <vector>
#include "CliParser.h"
#include "gtest/gtest.h"

namespace EasySoft
{
    namespace Cli
    {
        namespace Tests
        {
            std::vector<std::string> linuxCommandLinePrefixes = {"-", "--"};
            std::vector<std::string> windowsCommandLinePrefixes = {"/"};
            std::vector<std::string> keyValueSeparatorViaEquals = {"="};
            std::vector<std::string> keyValueSeparatorViaSpace = {};

            //std::string simpleValidString = "./someapp --help";
            //std::string simpleValidString2 = "./someapp -l \"abcdefgh\" --verbose";
            const char* onlyHelpOption[] = {"./someapp", "--help"};
            std::vector<EasySoft::Cli::Option> expectedOnlyHelpOptions =
            {
                EasySoft::Cli::Option(EXECUTION_PATH_KEY, "./someapp"),
                EasySoft::Cli::Option("--help", "")
            };
            const char* optionsWithRealValues[] = {"./someapp", "-l", "abcdefgh", "--verbose"};
            std::vector<EasySoft::Cli::Option> expectedOptionsWithRealValues = {EasySoft::Cli::Option(EXECUTION_PATH_KEY, "./someapp"),
                                                                                          EasySoft::Cli::Option("-l", "abcdefgh"),
                                                                                          EasySoft::Cli::Option("--verbose", "")};
            const char* optionsWithRealValuesSeparatedWithEquals[] = {"./someapp", "-l=abcdefgh", "--device=/dev/usb1", "--subcarrier=2"};
            std::vector<EasySoft::Cli::Option> expectedOptionsWithRealValuesSeparatedWithEquals = {EasySoft::Cli::Option(EXECUTION_PATH_KEY, "./someapp"),
                                                                                                             EasySoft::Cli::Option("-l", "abcdefgh"),
                                                                                                             EasySoft::Cli::Option("--device", "/dev/usb1"),
                                                                                                             EasySoft::Cli::Option("--subcarrier", "2")};
            const char* optionsWithoutPrefixes[] = {"./someapp", "abc", "def=def", "aaa", "lll"};
            std::vector<EasySoft::Cli::Option> expectedOptionsWithoutPrefixes = {EasySoft::Cli::Option(EXECUTION_PATH_KEY, "./someapp")};
            const char* optionsWithRealValuesSeparatedWithEqualsWinStyle[] = {".\\someapp.exe", "/l=abcdefgh", "/device=usb1", "/subcarrier=2"};
            std::vector<EasySoft::Cli::Option> expectedOptionsWithRealValuesSeparatedWithEqualsWinStyle = {EasySoft::Cli::Option(EXECUTION_PATH_KEY, ".\\someapp.exe"),
                                                                                                                     EasySoft::Cli::Option("/l", "abcdefgh"),
                                                                                                                     EasySoft::Cli::Option("/device", "usb1"),
                                                                                                                     EasySoft::Cli::Option("/subcarrier", "2")};

            void CheckOptions(std::vector<EasySoft::Cli::Option> expected, std::vector<EasySoft::Cli::Option> actual)
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
                EasySoft::Cli::CliParser parser(linuxCommandLinePrefixes, keyValueSeparatorViaSpace);
                std::vector<EasySoft::Cli::Option> actual = parser.Parse(2, onlyHelpOption);
                CheckOptions(expectedOnlyHelpOptions, actual);
            }

            TEST(CommandLineOptionsParser, KeysSeparatedWithValuesViaSpaceLinuxStyle)
            {
                EasySoft::Cli::CliParser parser(linuxCommandLinePrefixes, keyValueSeparatorViaSpace);
                std::vector<EasySoft::Cli::Option> actual = parser.Parse(4, optionsWithRealValues);
                CheckOptions(expectedOptionsWithRealValues, actual);
            }

            TEST(CommandLineOptionsParser, KeysSeparatedWithValuesViaEqualsLinuxStyle)
            {
                EasySoft::Cli::CliParser parser(linuxCommandLinePrefixes, keyValueSeparatorViaEquals);
                std::vector<EasySoft::Cli::Option> actual = parser.Parse(4, optionsWithRealValuesSeparatedWithEquals);
                CheckOptions(expectedOptionsWithRealValuesSeparatedWithEquals, actual);
            }

            TEST(CommandLineOptionsParser, KeysWithoutPrefixes)
            {
                EasySoft::Cli::CliParser parser(linuxCommandLinePrefixes, keyValueSeparatorViaEquals);
                std::vector<EasySoft::Cli::Option> actual = parser.Parse(4, optionsWithoutPrefixes);
                CheckOptions(expectedOptionsWithoutPrefixes, actual);
            }

            TEST(CommandLineOptionsParser, KeysSeparatedWithValuesViaEqualsWindowsStyle)
            {
                EasySoft::Cli::CliParser parser(windowsCommandLinePrefixes, keyValueSeparatorViaEquals);
                std::vector<EasySoft::Cli::Option> actual = parser.Parse(4, optionsWithRealValuesSeparatedWithEqualsWinStyle);
                CheckOptions(expectedOptionsWithRealValuesSeparatedWithEqualsWinStyle, actual);
            }
        }
    }
}

#endif
