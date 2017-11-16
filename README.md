# 1. EasyCli OVERVIEW
A cross-platform command line tool (reading arguments from command line and getting values as string, int or double by key).
Argumnets could be passed either in windows or linux style with possibility to choose separator (i.e. space or =)
`
Linux Style

    ./myapp --port=com6 --baudrate=115200 --parity=even --stopbits=2 --flowcontrol=cts
    ./myapp -if infile.txt -of outfile
    
Windows Style

    .\myapp.exe \ipAddress 192.168.10.43 \port 4543 \settings mysetting.xml
`
This library was fully tested with Unit tests.

# 2. PROJECT STRUCTURE, TOOLS AND DEPENDENCIES
     \
     \src
     \contrib
     \tests
     \MSVS

\src - contains all sources and headers

\contrib - contains libs that are using in project

\tests - unit tests of library with google tests

\MSVS - projects for Visual Studio 2013 (vc120 toolset) contains project for building library, tests and 2 usage 

Library could be build:

In linux:

1) From Eclipse (src is a directory with eclipse project file)

2) Via Makefile as make

In Windows - From Visual Studio
# 3. USAGE EXAMPLE
`

     EasySoft::Cli::CliManager* cmdManager = new EasySoft::Cli::CliManager(new EasySoft::Cli::ICliValidator(), 
                                                                          argc, (const char**)argv, true, true);
     std::vector<EasySoft::Cli::Option> options = cmdManager->GetParsedOptions();
`

We could recieve values as string, int or double via series of bool TryGet*** methods, if we have no value for key we receive true via TryGetValue with empty string.

`

     std::string value;
     cmdManager->TryGetValue("-d", value);
     std::cout << "VALUE FOR KEY -d :" << value.c_str() << std::endl;
     cmdManager->TryGetValue("--s", value);
     std::cout << "VALUE FOR KEY -s :" << value.c_str() << std::endl;
     cmdManager->TryGetValue("-p", value);
     std::cout << "VALUE FOR KEY -p :" << value.c_str() << std::endl;
`

For getting double we should use TryGetDouble, for int - TryGetInt.

# 4. NUGET PACKAGE

https://www.nuget.org/packages/EasyCli/
Example of how to use could be found in MSVS (project for Visual Studio 2013) -> EasyCliNugetExample

# 5. CONTRIBUTORS
    EvilLord666 (Ushakov Michael)
    VeryNiceGuy (Alex Petrov)
