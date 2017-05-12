# Easy Sockets Makefile Implementation v 1.0
# ********************************0. INCLUDE SECTION***********************************
# include Makefile.extra
# *****************************END OF INCLUDE SECTION**********************************
# ********************************1. VARIABLES SECTION*********************************
# 1 C/C++ Compiler
CXX = g++
CXXFLAGS = -g -O2 -Wall
# 2. Compiler And Linker Keys (man gcc)
LIB_NAME = libEasyCmdLineReader.so
LIB_VERSION_OPTION = 1.1
LIB_BUILD_DIRECTORY = .

LIB_COMPILE_OPTION = -fPIC
LIB_LINK_OPTION = -shared

LANG_OPTION = -std=c++11
# 3. Linking libraries
LIBPATH = -L. -L..
# -L/lib64/
# -L/lib/
LIBS = 
# -lc -lrt
# -lrt -lpthread
# 4. DEFINITIONS (PREPROCESSOR DEFINE)
ROOT_DIR := ./src
DEFS := -D__GXX_EXPERIMENTAL_CXX0X__
# 5. INCLUDES PATH
INCLUDES := -I$(ROOT_DIR)/ -I$(ROOT_DIR)/defs -I$(ROOT_DIR)/manager -I$(ROOT_DIR)/parser -I$(ROOT_DIR)/validator
# 6. SOURCES FILES
# Directories with sources
DIRS = $(ROOT_DIR)/defs $(ROOT_DIR)/manager $(ROOT_DIR)/parser $(ROOT_DIR)/validator
SRC_DIRS := $(addprefix / , $(DIRS))
# Obtaining source files list
C_SRC_FILES := $(foreach sdir, $(SRC_DIRS), $(wildcard $(sdir)/*.c))
CPP_SRC_FILES := $(foreach sdir, $(SRC_DIRS), $(wildcard $(sdir)/*.cpp))
# 7. OBJECTS FILE NAME
C_OBJFILES = $(C_SRC_FILES:.c=.o)
CPP_OBJFILES = $(CPP_SRC_FILES:.cpp=.o) $(C_OBJFILES)
# $(SRCFILES:.cpp=.o)
# 8. TARGETS OR RESULTING OBJ-FILE
# LIB_VERSION := 1.0
CPP_SHARED_LIB = $(LIB_BUILD_DIRECTORY)/$(LIB_NAME).$(LIB_VERSION_OPTION)
DEFAULT_TARGET = shared-lib
# *****************************END OF VARIABLES SECTION********************************
# ****************************2. BUILDING TARGETS SECTION******************************
# BY DEFAULT BUILDS first target (make without parameters)
# TO BUILD SPECIFIC TARGETS TYPE make "target name" (without quotation marks)
# each target MUST BE WRITTEN AS: Dependencies Tab(press tab key) Command
# MAKEFILE SPECIAL MACROSES (STARTS WITH $):
# $@ name of target 
# $? list of dependancies before that macro
# $^ list of dependancies which independent of wheather they met before or after
# $+ similar to $^ but doesn't exclude dublicates
# $< first dependancy

# PHONY TARGET ARE TARGETS WITHOUT OUTPUT FILES
.PHONY: depend clean finish create-build-dir copy-include

all: clean create-build-dir $(DEFAULT_TARGET) finish

shared-lib: clean create-build-dir $(CPP_SHARED_LIB) copy-include finish

create-build-dir:
	@ -mkdir -p $(LIB_BUILD_DIRECTORY)
	
$(CPP_SHARED_LIB):$(C_OBJFILES) $(CPP_OBJFILES)
	$(CXX) $(CXXFLAGS) $(LANG_OPTION) $(LIB_LINK_OPTION) $(DEFS) $(INCLUDES) $(LIBPATH) $(LIBS) -o $(CPP_SHARED_LIB) $(CPP_OBJFILES)

# These are the suffix replacement rules
%.o : %.c
	$(CXX) -c $(CXXFLAGS) $(LANG_OPTION) $(LIB_COMPILE_OPTION) $(DEFS) $(INCLUDES) $< -o $@

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $(LANG_OPTION)  $(LIB_COMPILE_OPTION) $(DEFS) $(INCLUDES) $< -o $@

clean:
	@ -rm -f $(CPP_OBJFILES)
	@ -rm -f $(CPP_SHARED_LIB)
	@ -rm -rf $(LIB_BUILD_DIRECTORY)/include

copy-include:
	@ mkdir -p $(LIB_BUILD_DIRECTORY)/include
	@ find $(ROOT_DIR) -name *.h -exec cp {} $(LIB_BUILD_DIRECTORY)/include \;
#@ cp -R $(ROOT_DIR)/*.h $(LIB_BUILD_DIRECTORY)/include

#remove intermediate obj files
finish:
	@ -rm $(CPP_OBJFILES)

depend: $(C_SRC_FILES) $(CPP_SRC_FILES)
	makedepend $(INCLUDES) $^

# make depend needs this line
# ****************************END OF BUILDING TARGETS SECTION**************************

