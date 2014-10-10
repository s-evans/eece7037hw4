
# Prologue

sp              := $(sp).x
dirstack_$(sp)  := $(d)
d               := $(abspath $(dir))

# Local variables

SRC_$(d) := client_command_factory.cpp command.cpp command_factory.cpp main.cpp version_command.cpp
SRC_$(d) := $(addprefix $(d)/, $(SRC_$(d)))
PFX_$(d) := $(OBJDIR)/$(d)
OBJ_$(d) := $(addsuffix .o, $(addprefix $(OBJDIR)/, $(SRC_$(d))))
DEP_$(d) := $(addsuffix .d, $(addprefix $(OBJDIR)/, $(SRC_$(d))))
TGT_$(d) := $(OUTDIR)/client

# Compile referenced variables

INC_$(d)/ := -I$(BOOST)

# Link referenced variables

LIB_$(TGT_$(d)) := 

# Local rules

$(PFX_$(d))/%.o: $(d)/% | $(PFX_$(d))
	$(COMP) $(INC_$(dir $<))

$(TGT_$(d)): $(OBJ_$(d)) | $(OUTDIR)
	$(LINK) $(LIB_$@)

# Global variables

TARGETS += $(TGT_$(d)) 
MKDIRS  += $(OUTDIR) $(PFX_$(d))

# Epilogue

-include	$(DEP_$(d))

d 			:= $(dirstack_$(sp))
sp			:= $(basename $(sp))

