#------------------------------------------------------------------------------
# Makefile for Coursera Embedded Systems Course 1 Module 2
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Platforms: 
#      HOST
#      MSP432 - TI Lauchpad MSP432p401r
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
#      hex - create intel hex from target binary
#      clean - Removes all generated files
#
# Overrides:
#      PLATFORM - HOST or MSP432
#      CPU - ARM Cortex Architecture (cortex-m0plus, cortex-m4)
#      ARCH - ARM Architecture (arm, thumb)
#      SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = c1m2

# Default platform, override from command line
PLATFORM = HOST
#PLATFORM = MSP432 

# Operating system, CPU, architecture, and specifications
OS = $(shell uname -s)
CPU = $(shell machine) 
ARCH = $(shell uname -p)
SPECS = nosys.specs

# CPU, ARCH, and SPECS override
ifeq ($(PLATFORM), MSP432)
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
endif

# Default tools, override with PLATFORM
CC = gcc
LD = ld
SIZE = size
OBJDUMP = objdump
OBJCOPY = objcopy

# Tool overrides
ifeq ($(PLATFORM),MSP432)
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
SIZE = arm-none-eabi-size
OBJDUMP = arm-none-eabi-objdump
OBJCOPY = arm-none-eabi-objcopy
endif

# Preprocessor flags, default
CPPFLAGS += $(foreach INC, $(INCLUDES), -I$(INC))

# Preprocessor flags, architecture specific
ifeq ($(PLATFORM), HOST)
CPPFLAGS  += -DHOST
endif

ifeq ($(PLATFORM), MSP432)
#CPPFLAGS += -nostdinc
CPPFLAGS  += -DMSP432
endif

# Compiler flags, common
CFLAGS = -Wall               \
         -Werror             \
         -g                  \
         -O0                 \
         -std=c99            \
         -v

# Compiler flags, architecture specific
ifeq ($(PLATFORM), MSP432)
CFLAGS += -mcpu=$(CPU)       \
          -mthumb            \
          -march=$(ARCH)     \
          -mfloat-abi=hard   \
          -mfpu=fpv4-sp-d16  \
          --specs=$(SPECS)
endif

# Linker file and flags
LINKER_FILE =
LDFLAGS = -Wl,-Map=$(TARGET).map 

# Linker file and flags, architecture specific
ifeq ($(PLATFORM), MSP432)
LINKER_FILE = ./msp432p401r.lds
LDFLAGS += -T $(LINKER_FILE)
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
	@echo PLATFORM = $(PLATFORM)
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
	@echo LINKER_FILE = $(LINKER_FILE)
	@echo 


%.i : %.c
	$(CC) -E $< $(CPPFLAGS) $(CFLAGS) -o $@

%.d : %.c
	$(CC) -E -MM $< $(CPPFLAGS) -o $@

%.asm : %.i
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@
	$(OBJDUMP) --disassemble $@ > $*.dump


.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out $(TARGET).d
	echo
	$(SIZE) -Axt $(TARGET).out
	$(SIZE) -Bx $(TARGET).out
	@echo

.PHONY: compile-all
compile-all : $(OBJS)


$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

$(TARGET).d: $(SRCS)
	$(CC) -E -MM $(CPPFLAGS) $(SRCS) 

.PHONY: hex
hex: $(TARGET).out
	$(OBJCOPY) -O ihex $< $(TARGET).hex
	$(SIZE) -Bd $(TARGET).hex
	@echo


.PHONY:clean
clean:
	@rm -f $(OBJS) $(ASMS) $(DEPS) $(CPPS) $(MAPS) $(DMPS) $(TARGET).out $(TARGET).hex  

