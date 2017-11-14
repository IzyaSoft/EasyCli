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
# 2. PROJECT STRUCTURE, TOOLS AND DEPENDENCIES

# 3. USAGE EXAMPLE

# 4. NUGET PACKAGE

https://www.nuget.org/packages/EasyCli/
Example of how to use could be found in MSVS (project for Visual Studio 2013) -> EasyCliNugetExample

# 5. CONTRIBUTORS
    EvilLord666 (Ushakov Michael)
    VeryNiceGuy (Alex Petrov)
