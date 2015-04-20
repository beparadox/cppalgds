#===============================================================================
#
#     Filename: Makefile
#  Description:
#
#        Usage: make              (generate executable                      )
#               make clean        (remove objects, executable, prerequisits )
#
#      Version: 1.0
#      Created:
#     Revision: ---
#
#       Author: Bambridge E. Peterson
#      Company:
#        Email: bambridge.peterson@gmail.com
#
#        Notes: This is a GNU make (gmake) makefile.
#               C   extension   :  c
#               C++ extensions  :  cc cpp C
#               C and C++ sources can be mixed.
#               Prerequisites are generated automatically; makedepend is not
#               needed (see documentation for GNU make Version 3.81, April 2006,
#               section 4.13). The utility sed is used.
#========================================== makefile template version 1.10 =====

#-----------------name of executable-------------------------------------------
EXECUTABLE:= main

#-----------------list of all source files-------------------------------------
SOURCES= main.cpp 

#-----------------compiler-----------------------------------------------------
CC=gcc
CPP=g++

#-----------------compiler flags-----------------------------------------------
DEBUG_CFLAGS = -Wall -ansi -pedantic -O0 -g

#-----------------linker flags ------------------------------------------------
DEBUG_LFLAGS := -g

#-----------------system libraries --------------------------------------------
SYS_LIBS=-lm

#-----------------directories--------------------------------------------------
LOCAL_INC_DIR = ./include 
SDIR = ./src
TDIR = ./tests
ODIR = ./src/obj

#-----------------header files-------------------------------------------------
HFILES = List.h ArrayList.h LinkedList.h listPractice.h ArrayStack.h Stack.h

#==============================================================================
# Compile this bitch
#==============================================================================
CPPFLAGS := ${DEBUG_CFLAGS}
CPP_SOURCES = $(addprefix $(SDIR)/,$(SOURCES))
INC_DIR = $(addprefix -I, $(LOCAL_INC_DIR))
#OBJ_DIR = $(addprefix $(ODIR), 
BASENAMES = $(basename $(SOURCES))
ALL_CFLAGS = $(DEBUG_CFLAGS)
ALL_LFLAGS = $(DEBUG_LFLAGS) $(INC_DIR)
OBJ_FILES = $(addprefix $(ODIR)/, $(BASENAMES))
#OBJ = $(addprefix $(ODIR),$(BASENAMES))


#------------- generate the names of the object files -------------------------
OBJECTS = $(addsuffix .o, $(OBJ_FILES))

#------------- make the executable --------------------------------------------
$(EXECUTABLE): $(OBJECTS)
	$(CPP) $(ALL_LFLAGS) -o $(EXECUTABLE) $(OBJECTS)

#------------- make the objects -----------------------------------------------
#$(OBJECTS): $(CPP_SOURCES) 
#	$(CPP) $(INC_DIR) -c $(ALL_CFLAGS) $< -o $(OBJECTS)

$(OBJECTS): $(CPP_SOURCES) 
	$(CPP) $(INC_DIR) -c $< -o $(OBJECTS)


#main: main.o
#	$(CXX) $(LIBS) -o $@ $^ $(DEBUG_FLAGS)

#listPractice: listPractice.o
#	$(CXX) -o 

.PHONY: print 

print-%: ;  @echo $* = $($*)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

