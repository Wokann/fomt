HOSTCC ?= $(CC)
HOSTCFLAGS ?= -std=c11 -Wall -Wextra -Werror -O2

ifeq ($(OS),Windows_NT)
EXE := .exe
endif

TOOL_DIRS := fomt-lz fontpad gbafix gbagfx mary oam_pack progress scaninc textproc
CLEAN_DIRS := $(addprefix clean-,$(TOOL_DIRS))

.PHONY: all clean $(TOOL_DIRS) $(CLEAN_DIRS)

all: $(TOOL_DIRS) verify-gfx-range$(EXE)

$(TOOL_DIRS):
	@$(MAKE) -C $@

verify-gfx-range$(EXE): verify_gfx_range.c Makefile
	$(HOSTCC) $(CPPFLAGS) $(HOSTCFLAGS) $< $(LDFLAGS) -o $@

clean: $(CLEAN_DIRS)
	$(RM) verify-gfx-range verify-gfx-range.exe

$(CLEAN_DIRS): clean-%:
	@$(MAKE) -C $* clean
