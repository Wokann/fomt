.SUFFIXES:

# ==================
# = PROJECT CONFIG =
# ==================

include config.mk

INCLUDE_DIRS := \
  tools/agbcc/include \
  tools/libagbc++ \
  tools/libsix/include

SRC_DIR = src
ASM_DIR = asm
DATA_ASM_DIR = asm/data
BUILD_DIR = build/$(REGION_DIR)

# ====================
# = TOOL DEFINITIONS =
# ====================

TOOLCHAIN ?= $(DEVKITARM)

ifneq (,$(TOOLCHAIN))
  export PATH := $(TOOLCHAIN)/bin:$(PATH)
endif

PREFIX := arm-none-eabi-

export OBJCOPY := $(PREFIX)objcopy
export AS := $(PREFIX)as
export CPP := $(PREFIX)cpp
export LD := $(PREFIX)ld
export STRIP := $(PREFIX)strip

ifeq ($(OS),Windows_NT)
  EXE := .exe
else
  EXE :=
endif

CC1      := tools/agbcc/bin/agbcc$(EXE)
CC1PLUS  := tools/agbcc/bin/agbcp$(EXE)

OLD_CC1  := tools/agbcc/bin/old_agbcc$(EXE)

# ================
# = BUILD CONFIG =
# ================

INCFLAGS     := $(foreach dir, $(INCLUDE_DIRS), -I "$(dir)")

CPPFLAGS := $(INCFLAGS) -I . -iquote . -iquote include -Wno-trigraphs -fno-exceptions -D$(REGION_DEFINE)=1
CFLAGS   := -g -mthumb-interwork -Wimplicit -Wparentheses -Werror -O2 -fhex-asm -fdata-sections
CXXFLAGS := -quiet -fno-exceptions -fno-rtti -fvtable-thunks $(CFLAGS)
ASFLAGS  := $(INCFLAGS) -I . -I include -mcpu=arm7tdmi --defsym $(REGION_DEFINE)=1

ROM := $(BUILD_NAME).gba
ELF := $(ROM:.gba=.elf)
MAP := $(ROM:.gba=.map)

C_SRCS := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/rt/*.c)
C_OBJS := $(C_SRCS:%.c=$(BUILD_DIR)/%.o)

CXX_SRCS := $(filter-out $(SRC_DIR)/reference_guide.cc,$(wildcard $(SRC_DIR)/*.cc $(SRC_DIR)/rt/*.cc))
CXX_OBJS := $(CXX_SRCS:%.cc=$(BUILD_DIR)/%.o)


ASM_SRCS := $(wildcard $(SRC_DIR)/*.s $(ASM_DIR)/*.s)
ASM_OBJS := $(ASM_SRCS:%.s=$(BUILD_DIR)/%.o)

DATA_ASM_SRCS := $(wildcard $(DATA_ASM_DIR)/*.s)
DATA_ASM_OBJS := $(DATA_ASM_SRCS:%.s=$(BUILD_DIR)/%.o)

ALL_OBJS := $(C_OBJS) $(CXX_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS)
ALL_DEPS := $(ALL_OBJS:%.o=%.d)

SUBDIRS := $(sort $(dir $(ALL_OBJS)))
$(shell mkdir -p $(SUBDIRS))

# ===========
# = RECIPES =
# ===========

fomt_us:
	@$(MAKE) GAME_REGION=US GAME_REVISION=0 compare

fomt_jp:
	@$(MAKE) GAME_REGION=JP GAME_REVISION=0 compare

fomt_eu:
	@$(MAKE) GAME_REGION=EU GAME_REVISION=0 compare

fomt_de:
	@$(MAKE) GAME_REGION=DE GAME_REVISION=0 compare

# Every regional target builds and verifies its corresponding base ROM.
compare_eu:
	@$(MAKE) GAME_REGION=EU GAME_REVISION=0 compare

compare_de:
	@$(MAKE) GAME_REGION=DE GAME_REVISION=0 compare

# US and JP targets build and verify their corresponding base ROM.

compare: $(ROM)
	sha1sum -c $(BUILD_NAME).sha1

.PHONY: fomt_us fomt_jp fomt_eu fomt_de compare_eu compare_de compare

TEXT_TOOL_DIR := tools/textproc
TEXT_TOOL := $(TEXT_TOOL_DIR)/fomt-text
TEXT_PREPROC := $(TEXT_TOOL_DIR)/fomt-preproc
TEXT_TOOLS := $(TEXT_TOOL) $(TEXT_PREPROC)

ifeq ($(GAME_REGION),JP)
TEXT_REGION := jp
else ifeq ($(GAME_REGION),EU)
TEXT_REGION := eu
else ifeq ($(GAME_REGION),DE)
TEXT_REGION := de
else
TEXT_REGION := us
endif

# Every ordinary .cc file joins the same C++ compilation channel below.  Files
# included at a physical point inside an owning src module must not also become
# standalone objects.  Enumerate existing text files with wildcard, then use
# the actual src include relation to select those fragments.  Renaming or
# adding an included fragment therefore needs no Makefile update.
TEXT_FRAGMENT_CANDIDATES := $(wildcard data/text/common/*.cc data/text/$(TEXT_REGION)/*.cc)
TEXT_FRAGMENT_LITERAL_INCLUDES := $(shell grep -RhoE '^#include "data/text/(common|$(TEXT_REGION))/[^"]+\.cc"' $(SRC_DIR) | sed -E 's/^#include "([^"]+)"/\1/' | sort -u)
FOMT_TEXT_INCLUDE_LPAREN := (
FOMT_TEXT_INCLUDE_RPAREN := )
FOMT_TEXT_INCLUDE_REGEX_LPAREN := \(
FOMT_TEXT_INCLUDE_REGEX_RPAREN := \)
TEXT_FRAGMENT_REGION_INCLUDES := $(shell grep -RhoE '^#include FOMT_TEXT_INCLUDE$(FOMT_TEXT_INCLUDE_REGEX_LPAREN)[[:alnum:]_]+\.cc$(FOMT_TEXT_INCLUDE_REGEX_RPAREN)' $(SRC_DIR) | cut -d '$(FOMT_TEXT_INCLUDE_LPAREN)' -f2 | tr -d '$(FOMT_TEXT_INCLUDE_RPAREN)' | sed 's|^|data/text/$(TEXT_REGION)/|' | sort -u)
TEXT_FRAGMENT_INCLUDES := $(sort $(TEXT_FRAGMENT_LITERAL_INCLUDES) $(TEXT_FRAGMENT_REGION_INCLUDES))
TEXT_FRAGMENT_SOURCES := $(sort $(filter $(TEXT_FRAGMENT_CANDIDATES),$(TEXT_FRAGMENT_INCLUDES)))

# The staff-credit source and the Reference Guide pages use their own visible
# authoring formats.  They are the only inputs that must be lowered to a
# normal .cc source before entering the shared compilation channel.
STAFF_CREDITS_SOURCE := data/text/$(TEXT_REGION)/staff_credits.cc

# Shop-common strings are the first physical block of the unified status UI
# source. The original shop data remains between this block and the status
# text block, so compile that branch to its existing object name.
STATUS_UI_SHOP_COMMON_TEXT_SOURCE := data/text/$(TEXT_REGION)/status_ui.cc
STATUS_UI_SHOP_COMMON_TEXT_OBJ := $(BUILD_DIR)/data/text/shop_common.o
STATUS_UI_SHOP_COMMON_TEXT_DEP := $(STATUS_UI_SHOP_COMMON_TEXT_OBJ:.o=.d)

REGION_TEXT_SOURCES := $(filter-out $(TEXT_FRAGMENT_SOURCES) $(STAFF_CREDITS_SOURCE),$(wildcard data/text/$(TEXT_REGION)/*.cc))
REGION_TEXT_ORDINARY_OBJS := $(patsubst data/text/$(TEXT_REGION)/%.cc,$(BUILD_DIR)/data/text/%.o,$(REGION_TEXT_SOURCES))
REGION_TEXT_ORDINARY_DEPS := $(REGION_TEXT_ORDINARY_OBJS:.o=.d)
REGION_TEXT_OBJS := $(REGION_TEXT_ORDINARY_OBJS) $(STATUS_UI_SHOP_COMMON_TEXT_OBJ)
REGION_TEXT_DEPS := $(REGION_TEXT_ORDINARY_DEPS) $(STATUS_UI_SHOP_COMMON_TEXT_DEP)
COMMON_TEXT_SOURCES := $(filter-out $(TEXT_FRAGMENT_SOURCES),$(wildcard data/text/common/*.cc))
COMMON_TEXT_OBJS := $(COMMON_TEXT_SOURCES:%.cc=$(BUILD_DIR)/%.o)
COMMON_TEXT_DEPS := $(COMMON_TEXT_OBJS:.o=.d)

# The manifest records directory order, physical ROM-group order, and whether
# an auxiliary page participates in the master directory.
GUIDE_COLLECTION_MANIFEST := src/reference_guide.cc
GUIDE_PAGE_SOURCES := $(wildcard data/text/$(TEXT_REGION)/reference_guide/*.cc)
STAFF_CREDITS_GENERATED_SOURCE := $(BUILD_DIR)/data/text/$(TEXT_REGION)/staff_credits.cc
STAFF_CREDITS_GENERATED_OBJ := $(BUILD_DIR)/data/text/staff_credits.o
STAFF_CREDITS_GENERATED_DEP := $(BUILD_DIR)/data/text/staff_credits.d
GUIDE_GENERATED_SOURCE := $(BUILD_DIR)/src/reference_guide.cc
GUIDE_GENERATED_OBJ := $(BUILD_DIR)/src/reference_guide.o
GUIDE_GENERATED_DEP := $(BUILD_DIR)/src/reference_guide.d

MARY_TOOL := tools/mary/mary.exe
MARY_SOURCE_DIR := data/scripts/$(REGION_DIR)
MARY_OUTPUT_DIR := $(BUILD_DIR)/data/scripts
MARY_LIBRARY := $(MARY_SOURCE_DIR)/fomt_callables.mary.h
MARY_SCRIPT_TABLE := $(MARY_SOURCE_DIR)/fomt_scripts.mary.h
MARY_CONSTANTS := include/fomt_constants.mary.h
MARY_SOURCES := $(wildcard $(MARY_SOURCE_DIR)/*.mary.c)
MARY_BUNDLE_STAMP := $(MARY_OUTPUT_DIR)/.mary-bundle.stamp
MARY_SCRIPTS_ASM := $(MARY_OUTPUT_DIR)/scripts.s
MARY_SCRIPT_TABLE_ASM := $(MARY_OUTPUT_DIR)/script_table.s
MARY_SCRIPTS_BIN := $(MARY_OUTPUT_DIR)/scripts.bin
MARY_BUNDLE_DEP := $(MARY_OUTPUT_DIR)/scripts.d
MARY_BUNDLE_OUTPUTS := $(MARY_SCRIPTS_ASM) $(MARY_SCRIPT_TABLE_ASM) $(MARY_SCRIPTS_BIN) $(MARY_BUNDLE_DEP)
MARY_SCRIPTS_OBJ := $(MARY_OUTPUT_DIR)/scripts.o
MARY_SCRIPT_TABLE_OBJ := $(MARY_OUTPUT_DIR)/script_table.o

ALL_OBJS += $(REGION_TEXT_OBJS) $(COMMON_TEXT_OBJS) $(STAFF_CREDITS_GENERATED_OBJ) $(GUIDE_GENERATED_OBJ) $(MARY_SCRIPTS_OBJ) $(MARY_SCRIPT_TABLE_OBJ)
ALL_DEPS += $(REGION_TEXT_DEPS) $(COMMON_TEXT_DEPS) $(STAFF_CREDITS_GENERATED_DEP) $(GUIDE_GENERATED_DEP) $(MARY_BUNDLE_DEP)

.SECONDARY: $(GUIDE_GENERATED_SOURCE) $(STAFF_CREDITS_GENERATED_SOURCE) $(MARY_BUNDLE_OUTPUTS)

$(TEXT_TOOLS): $(TEXT_TOOL_DIR)/fomt_text.cpp $(TEXT_TOOL_DIR)/fomt_preproc.cpp $(TEXT_TOOL_DIR)/Makefile
	@$(MAKE) -C $(TEXT_TOOL_DIR) $(notdir $@)

# Mary owns the complete packed RIFF script stream.  Its three headers remain
# explicit inputs: callables and slot names live with the selected scripts,
# while the C/C++-shared constant table lives in include/.
$(MARY_BUNDLE_STAMP): $(MARY_TOOL) $(MARY_SOURCES) $(MARY_LIBRARY) $(MARY_SCRIPT_TABLE) $(MARY_CONSTANTS) charmap.txt
	@mkdir -p $(MARY_OUTPUT_DIR)
	@$(MARY_TOOL) bundle $(MARY_SOURCE_DIR) -o $(MARY_OUTPUT_DIR) --layout packed --library $(MARY_LIBRARY) --script-table $(MARY_SCRIPT_TABLE) --constants $(MARY_CONSTANTS) --charmap charmap.txt -D MARY_FOMT_$(GAME_REGION)
	@touch $@

$(MARY_BUNDLE_OUTPUTS): $(MARY_BUNDLE_STAMP)

$(MARY_SCRIPTS_OBJ): $(MARY_SCRIPTS_ASM)
	@echo "AS $<"
	@$(AS) $(ASFLAGS) $< -o $@

$(MARY_SCRIPT_TABLE_OBJ): $(MARY_SCRIPT_TABLE_ASM)
	@echo "AS $<"
	@$(AS) $(ASFLAGS) $< -o $@

# Every ordinary C/C++ unit first becomes a normal preprocessed source file.
# fomt-text then lowers only its quoted game text to FOMT byte literals; it
# leaves ALIGN(n), SECTION(...), structures, and pointer tables as C/C++.
# fomt-preproc consumes the resulting source plus agbcc/agbcp assembly to
# perform generic relocation repair and executable-section closing alignment.
define FOMT_COMPILE_CPP
@mkdir -p $(dir $(basename $@).fomt-preprocessed.cc)
@$(CPP) -iquote $(BUILD_DIR) $(1) -P $(CPPFLAGS) $< -o $(basename $@).fomt-preprocessed.cc
@$(TEXT_TOOL) source charmap.txt $(GAME_REGION) $(basename $@).fomt-preprocessed.cc $(basename $@).fomt-text.cc
@($(CC1PLUS) $(CXXFLAGS) -o $(basename $@).s < $(basename $@).fomt-text.cc || false)
@$(TEXT_PREPROC) asm $(basename $@).fomt-text.cc $(basename $@).s
@$(AS) $(ASFLAGS) $(basename $@).s -o $@
endef

define FOMT_COMPILE_C
@mkdir -p $(dir $(basename $@).fomt-preprocessed.c)
@$(CPP) -iquote $(BUILD_DIR) $(1) -P $(CPPFLAGS) $< -o $(basename $@).fomt-preprocessed.c
@$(TEXT_TOOL) source charmap.txt $(GAME_REGION) $(basename $@).fomt-preprocessed.c $(basename $@).fomt-text.c
@$(CC1) $(CFLAGS) -o $(basename $@).s < $(basename $@).fomt-text.c
@$(TEXT_PREPROC) asm $(basename $@).fomt-text.c $(basename $@).s
@$(AS) $(ASFLAGS) $(basename $@).s -o $@
endef

# Every article remains a deliberately non-C++ text source.  One collection
# invocation emits one physical C++ object: master directory, group text, and
# the matching line-pointer tables in exact ROM order.
$(GUIDE_GENERATED_SOURCE): $(GUIDE_COLLECTION_MANIFEST) $(GUIDE_PAGE_SOURCES) $(TEXT_TOOL) charmap.txt
	@mkdir -p $(dir $@)
	$(TEXT_TOOL) guide-collection charmap.txt $(GAME_REGION) $(GUIDE_COLLECTION_MANIFEST) $@

$(BUILD_DIR)/src/reference_guide.d: $(GUIDE_GENERATED_SOURCE)
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MT $(BUILD_DIR)/src/reference_guide.o

$(BUILD_DIR)/src/reference_guide.o: $(GUIDE_GENERATED_SOURCE) $(BUILD_DIR)/src/reference_guide.d $(TEXT_TOOLS) charmap.txt
	@echo "CP $<"
	$(call FOMT_COMPILE_CPP,)

# Staff credits are one visible scrolling sequence.  fomt-text recovers the
# original text-field layout and row-pointer sharing from the selected ROM,
# then emits standard C++ which immediately enters the shared channel below.
$(STAFF_CREDITS_GENERATED_SOURCE): $(STAFF_CREDITS_SOURCE) $(TEXT_TOOL) charmap.txt baserom_$(TEXT_REGION).gba
	@mkdir -p $(dir $@)
	$(TEXT_TOOL) staff-credits charmap.txt $(GAME_REGION) baserom_$(TEXT_REGION).gba $< $@


# The selected regional .cc sources map to the region-neutral object paths
# used by the linker scripts.  Their recipe is the same universal pipeline as
# every other C++ translation unit; no text-specific staging source is made.
$(REGION_TEXT_ORDINARY_DEPS): $(BUILD_DIR)/data/text/%.d: data/text/$(TEXT_REGION)/%.cc
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MT $@ -MT $(BUILD_DIR)/data/text/$*.o

$(REGION_TEXT_ORDINARY_OBJS): $(BUILD_DIR)/data/text/%.o: data/text/$(TEXT_REGION)/%.cc $(BUILD_DIR)/data/text/%.d $(TEXT_TOOLS) charmap.txt
	@echo "CP $<"
	$(call FOMT_COMPILE_CPP,)

$(STATUS_UI_SHOP_COMMON_TEXT_DEP): $(STATUS_UI_SHOP_COMMON_TEXT_SOURCE)
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -DFOMT_TEXT_STATUS_UI_SHOP_COMMON=1 $< -o $@ -MM -MG -MT $@ -MT $(STATUS_UI_SHOP_COMMON_TEXT_OBJ)

$(STATUS_UI_SHOP_COMMON_TEXT_OBJ): $(STATUS_UI_SHOP_COMMON_TEXT_SOURCE) $(STATUS_UI_SHOP_COMMON_TEXT_DEP) $(TEXT_TOOLS) charmap.txt
	@echo "CP $<"
	$(call FOMT_COMPILE_CPP,-DFOMT_TEXT_STATUS_UI_SHOP_COMMON=1)

# The generated staff-credit source follows the same C++ text pipeline as any
# other data/text translation unit.  Its ROM-neutral object name is the one
# referenced by both linker scripts.
$(STAFF_CREDITS_GENERATED_DEP): $(STAFF_CREDITS_GENERATED_SOURCE)
	@mkdir -p $(dir $@)
	@$(CPP) -iquote $(BUILD_DIR) $(CPPFLAGS) $< -o $@ -MM -MG -MT $(STAFF_CREDITS_GENERATED_OBJ)

$(STAFF_CREDITS_GENERATED_OBJ): $(STAFF_CREDITS_GENERATED_SOURCE) $(STAFF_CREDITS_GENERATED_DEP) $(TEXT_TOOLS) charmap.txt
	@echo "CP $<"
	$(call FOMT_COMPILE_CPP,)

# ROM from ELF
%.gba: %.elf
	$(OBJCOPY) -O binary $< $@

# ELF
$(ELF): $(ALL_OBJS) $(LDS)
	@echo "LD $(LDS) $(ALL_OBJS:$(BUILD_DIR)/%=%)"
	@cd $(BUILD_DIR) && $(LD) -T $(LDS_LINK_PATH) -Map ../../$(MAP) -L../../tools/agbcc/lib -lgcc -lc $(ALL_OBJS:$(BUILD_DIR)/%=%) -o ../../$@
	@$(STRIP) -N .gcc2_compiled. $(ELF)

# C dependency file
$(BUILD_DIR)/%.d: %.c
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MT $@ -MT $(BUILD_DIR)/$*.o

# C object
$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)/%.d $(TEXT_TOOLS) charmap.txt
	@echo "CC $<"
	$(call FOMT_COMPILE_C,)

# C++ dependency file
$(BUILD_DIR)/%.d: %.cc
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MT $@ -MT $(BUILD_DIR)/$*.o

# C++ object
$(BUILD_DIR)/%.o: %.cc $(BUILD_DIR)/%.d $(TEXT_TOOLS) charmap.txt
	@echo "CP $<"
	$(call FOMT_COMPILE_CPP,)

# ASM dependency file (dummy, generated with the object)
$(BUILD_DIR)/%.d: $(BUILD_DIR)/%.o
	@touch $@

# ASM object
$(BUILD_DIR)/%.o: %.s
	@echo "AS $<"
	@$(AS) $(ASFLAGS) $< -o $@ --MD $(BUILD_DIR)/$*.d

# overrides for matching
$(BUILD_DIR)/src/m4a.o: CC1 := $(OLD_CC1)

clean:
	@echo "RM $(ROM) $(ELF) $(MAP) $(BUILD_DIR)"
	@rm -f $(ROM) $(ELF) $(MAP) 
	@rm -rf $(BUILD_DIR)/

.PHONY: clean

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(filter fomt_us fomt_jp fomt_eu fomt_de compare_eu compare_de,$(MAKECMDGOALS)))
-include $(ALL_DEPS)
endif
.PRECIOUS: $(BUILD_DIR)/%.d
endif
