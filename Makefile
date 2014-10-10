
# Immutable global variables

BOOST ?= /usr/include
CPPFLAGS := -MP -MD $(CPPFLAGS)
LDFLAGS := $(LDFLAGS)

# Late resolved global variables

COMP = $(CXX) -c $< -o $@ $(CPPFLAGS)
LINK = $(CXX) -o $@ $^ $(LDFLAGS)

OBJDIR = obj
OUTDIR = out

# Mutable global variables

TARGETS := 
MKDIRS := 
CLEAN := out obj

# Assert a default target

.PHONY: all
all: targets

# Define program build rules

dir := .
include $(dir)/Rules.mk

# Targets

.PHONY: targets
targets: $(TARGETS) 

.PHONY: clean
clean:
		rm -rf $(sort $(CLEAN))

$(sort $(MKDIRS)):
		mkdir -p $@
