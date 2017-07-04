#------------------------------------------------------------------------------
# Makefile for Coursera Embedded Systems Course 1 Module 4
#
# Use: make [TARGET] 
#
# Build Targets:
#
#      <FILE>.i - Builds <FILE>.i preprocessed source file
#      <FILE>.d - Builds <FILE>.d dependency file from source
#      <FILE>.asm - Builds <FILE>.asm assembly file from souce
#      <FILE>.o - Builds <FILE>.o object file and disassemble to .dump
#      info - Echo out make variables
#      build - Builds and links all source files
#      all - Same as build
#      compile-all - only complile without linking
#      clean - Removes all generated files
#
# Overrides:
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = main

# Operating system, CPU, architecture, and specifications
OS = $(shell uname -s)
CPU = $(shell machine) 
ARCH = $(shell uname -p)
SPECS = nosys.specs

# source and includes paths
SRC_PATH = ./src/
INC_PATH = ./include/common/

# Default tools
CC = gcc
LD = ld
SIZE = size
OBJDUMP = objdump
OBJCOPY = objcopy

# Preprocessor flags, default
#CPPFLAGS += $(foreach INC, $(INCLUDES), -I$(INC))
CPPFLAGS += -I$(INC_PATH)
CPPFLAGS += -D VERBOSE


# Compiler flags, common
CFLAGS = -Wall               \
         -Werror             \
         -g                  \
         -O0                 \
         -std=c99            \
         -v

# Linker file and flags
LDFLAGS = -Wl
  #,-Map=$(TARGET).map 

# Flags for size tool
ifeq ($(OS), Darwin)
    SIZEFLAGS = -m -x
else
    SIZEFLAGS = -Axt
endif

SRCS := $(SOURCES)
INCS := $(INCLUDES)
CPPS := $(SOURCES:.c=.i)
DEPS := $(SOURCES:.c=.d)
ASMS := $(SOURCES:.c=.asm)
OBJS := $(SOURCES:.c=.o)
MAPS := $(SOURCES:.c=.map) $(TARGET).map
DMPS := $(SOURCES:.c=.dump)

###############################################
#
#  Begin target definitions
#

.PHONY:info
info:
	@echo 
	@echo TARGET = $(TARGET)
	@echo 
	@echo SRCS = $(SRCS)
	@echo INCS = $(INCS)
	@echo CPPS = $(CPPS)
	@echo DEPS = $(DEPS)
	@echo ASMS = $(ASMS)
	@echo OBJS = $(OBJS)
	@echo MAPS = $(MAPS)
	@echo DMPS = $(DMPS)
	@echo 
	@echo OS = $(OS)
	@echo CPU = $(CPU)
	@echo ARCH = $(ARCH)
	@echo SPECS = $(SPECS)
	@echo 
	@echo CC = $(CC)
	@echo LD = $(LD)
	@echo SIZE = $(SIZE)
	@echo OBJDUMP = $(OBJDUMP)
	@echo  
	@echo CPPFLAGS = $(CPPFLAGS)
	@echo CFLAGS = $(CFLAGS)
	@echo LDFLAGS = $(LDFLAGS)
	@echo SIZEFLAGS = $(SIZEFLAGS)
	@echo LINKER_FILE = $(LINKER_FILE)
	@echo 


%.i:%.c
	$(CC) -E $< $(CPPFLAGS) $(CFLAGS) -o $@

%.d:%.c
	$(CC) -E -MM $< $(CPPFLAGS) -o $@

%.asm:%.i
	$(CC) -S $< $(CFLAGS) -o $@

%.o:%.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@
	$(OBJDUMP) --disassemble $@ > $*.dump


.PHONY: build
build: all

.PHONY: all
all: $(TARGET) $(TARGET).d
	@echo
	$(SIZE) $(SIZEFLAGS) $(TARGET)
	@echo

.PHONY: compile-all
compile-all : $(OBJS)


$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

$(TARGET).d: $(SRCS)
	$(CC) -E -MM $(CPPFLAGS) $(SRCS) 


.PHONY:clean
clean:
	@rm -f $(OBJS) $(ASMS) $(DEPS) $(CPPS) $(MAPS) $(DMPS) $(TARGET) $(TARGET).hex  

