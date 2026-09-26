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
  PYTHON ?= py -3
else
  EXE :=
  PYTHON ?= python3
endif

CC1      := tools/agbcc/bin/agbcc$(EXE)
CC1PLUS  := tools/agbcc/bin/agbcp$(EXE)
HOSTCC ?= cc

OLD_CC1  := tools/agbcc/bin/old_agbcc$(EXE)

# ROM header values live in config.mk, as in pret/pokeruby.  The small host
# tool writes them only after objcopy has produced the flat GBA image.
GBAFIX_DIR := tools/gbafix
GBAFIX := $(GBAFIX_DIR)/gbafix$(EXE)

# Host-side graphics tools.  gbagfx is vendored from pokeemerald under its
# original licence; fontpad only bridges FoMT's 8x12 1bpp glyph records to
# gbagfx's 8x8-tile input without changing the authored PNG workflow.
GFX_TOOL_DIR := tools/gbagfx
GFX_TOOL := $(GFX_TOOL_DIR)/gbagfx$(EXE)
FOMT_LZ_TOOL := tools/fomt-lz$(EXE)
GFX_TOOL_SOURCES := $(wildcard $(GFX_TOOL_DIR)/*.c $(GFX_TOOL_DIR)/*.h) $(GFX_TOOL_DIR)/Makefile
FONT_PAD_DIR := tools/fontpad
FONT_PAD := $(FONT_PAD_DIR)/fontpad$(EXE)
OAM_PACK_DIR := tools/oam_pack
OAM_PACK := $(OAM_PACK_DIR)/oam_pack$(EXE)
GFX_RANGE_VERIFY := tools/verify-gfx-range$(EXE)
TILE_GRID_LEGACY_LIB := tools/tile_grid.py
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

# Some JP-only implementations are ordinary compiler-owned C++ objects whose
# historical inline assembly is kept in reviewable assembly include files.
# Derive the object dependencies from the include names so editing one always
# rebuilds its owning C++ object without naming a ROM as a build input.
INLINE_JP_ASM_INCLUDES := $(wildcard $(ASM_DIR)/*_jp.inc)
INLINE_JP_ASM_MODULES := $(patsubst $(ASM_DIR)/%_jp.inc,%,$(INLINE_JP_ASM_INCLUDES))
$(foreach module,$(INLINE_JP_ASM_MODULES),$(eval $(BUILD_DIR)/$(SRC_DIR)/$(module).o: $(ASM_DIR)/$(module)_jp.inc))


ASM_SRCS := $(wildcard $(SRC_DIR)/*.s $(ASM_DIR)/*.s)
ASM_OBJS := $(ASM_SRCS:%.s=$(BUILD_DIR)/%.o)

DATA_ASM_SRCS := $(wildcard $(DATA_ASM_DIR)/*.s)
DATA_ASM_OBJS := $(DATA_ASM_SRCS:%.s=$(BUILD_DIR)/%.o)

ALL_OBJS := $(C_OBJS) $(CXX_OBJS) $(ASM_OBJS) $(DATA_ASM_OBJS)
ALL_DEPS := $(ALL_OBJS:%.o=%.d)

include graphics_file_rules.mk

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
	tr -d '\r' < $(BUILD_NAME).sha1 | sha1sum -c -

.PHONY: fomt_us fomt_jp fomt_eu fomt_de compare_eu compare_de compare

TEXT_TOOL_DIR := tools/textproc
TEXT_TOOL := $(TEXT_TOOL_DIR)/fomt-text$(EXE)
TEXT_PREPROC := $(TEXT_TOOL_DIR)/fomt-preproc$(EXE)
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
TEXT_FRAGMENT_CANDIDATES := $(wildcard data/text/$(TEXT_REGION)/*.cc)
FOMT_TEXT_INCLUDE_LPAREN := (
FOMT_TEXT_INCLUDE_RPAREN := )
FOMT_TEXT_INCLUDE_REGEX_LPAREN := \(
FOMT_TEXT_INCLUDE_REGEX_RPAREN := \)
TEXT_FRAGMENT_REGION_INCLUDES := $(shell grep -RhoE '^#include FOMT_TEXT_INCLUDE$(FOMT_TEXT_INCLUDE_REGEX_LPAREN)[[:alnum:]_]+\.cc$(FOMT_TEXT_INCLUDE_REGEX_RPAREN)' $(SRC_DIR) | cut -d '$(FOMT_TEXT_INCLUDE_LPAREN)' -f2 | tr -d '$(FOMT_TEXT_INCLUDE_RPAREN)' | sed 's|^|data/text/$(TEXT_REGION)/|' | sort | uniq)
TEXT_FRAGMENT_INCLUDES := $(TEXT_FRAGMENT_REGION_INCLUDES)
TEXT_FRAGMENT_SOURCES := $(sort $(filter $(TEXT_FRAGMENT_CANDIDATES),$(TEXT_FRAGMENT_INCLUDES)))

# The staff-credit source and the Reference Guide pages use their own visible
# authoring formats.  The staff source is lowered in-place by its owning
# src/staff_credits.cc unit; guide pages remain a generated aggregate source.
STAFF_CREDITS_SOURCE := data/text/$(TEXT_REGION)/staff_credits_1.cc

REGION_TEXT_SOURCES := $(filter-out $(TEXT_FRAGMENT_SOURCES) $(STAFF_CREDITS_SOURCE),$(wildcard data/text/$(TEXT_REGION)/*.cc))
REGION_TEXT_ORDINARY_OBJS := $(patsubst data/text/$(TEXT_REGION)/%.cc,$(BUILD_DIR)/data/text/%.o,$(REGION_TEXT_SOURCES))
REGION_TEXT_ORDINARY_DEPS := $(REGION_TEXT_ORDINARY_OBJS:.o=.d)
REGION_TEXT_OBJS := $(REGION_TEXT_ORDINARY_OBJS)
REGION_TEXT_DEPS := $(REGION_TEXT_ORDINARY_DEPS)

# The manifest records directory order, physical ROM-group order, and whether
# an auxiliary page participates in the master directory.
GUIDE_COLLECTION_MANIFEST := src/reference_guide.cc
GUIDE_PAGE_SOURCES := $(wildcard data/text/$(TEXT_REGION)/reference_guide/*.cc)
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

ALL_OBJS += $(REGION_TEXT_OBJS) $(GUIDE_GENERATED_OBJ) $(MARY_SCRIPTS_OBJ) $(MARY_SCRIPT_TABLE_OBJ)
ALL_DEPS += $(REGION_TEXT_DEPS) $(GUIDE_GENERATED_DEP) $(MARY_BUNDLE_DEP)

.SECONDARY: $(GUIDE_GENERATED_SOURCE) $(MARY_BUNDLE_OUTPUTS)

$(TEXT_TOOLS): $(TEXT_TOOL_DIR)/fomt_text.cpp $(TEXT_TOOL_DIR)/fomt_preproc.cpp $(TEXT_TOOL_DIR)/Makefile
	@$(MAKE) -C $(TEXT_TOOL_DIR) $(notdir $@)

$(GBAFIX): $(GBAFIX_DIR)/gbafix.c $(GBAFIX_DIR)/Makefile
	@$(MAKE) -C $(GBAFIX_DIR) $(notdir $@)

$(FOMT_LZ_TOOL): tools/fomt_lz.c
	@$(HOSTCC) -std=c11 -Wall -Wextra -Werror -O2 $< -o $@

$(GFX_RANGE_VERIFY): tools/verify_gfx_range.c
	@$(HOSTCC) -std=c11 -Wall -Wextra -Werror -O2 $< -o $@

# graphics_file_rules.mk owns every image conversion dependency.  Assemble
# only after it has produced the source-adjacent assets; GAS then records each
# real .incbin input in its ordinary generated dependency file.
$(ASM_OBJS) $(DATA_ASM_OBJS): | graphics

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
@$(TEXT_TOOL) source charmap.txt $(GAME_REGION) $(basename $@).fomt-preprocessed.cc $(basename $@).fomt-text.cc $(FOMT_TEXT_SOURCE_ARGS)
@($(CC1PLUS) $(CXXFLAGS) -o $(basename $@).s < $(basename $@).fomt-text.cc || false)
@$(TEXT_PREPROC) asm $(basename $@).fomt-text.cc $(basename $@).s
@$(AS) $(ASFLAGS) $(basename $@).s -o $@
endef

define FOMT_COMPILE_C
@mkdir -p $(dir $(basename $@).fomt-preprocessed.c)
@$(CPP) -iquote $(BUILD_DIR) $(1) -P $(CPPFLAGS) $< -o $(basename $@).fomt-preprocessed.c
@$(TEXT_TOOL) source charmap.txt $(GAME_REGION) $(basename $@).fomt-preprocessed.c $(basename $@).fomt-text.c $(FOMT_TEXT_SOURCE_ARGS)
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

# The selected regional .cc sources map to the region-neutral object paths
# used by the linker scripts.  Their recipe is the same universal pipeline as
# every other C++ translation unit; no text-specific staging source is made.
$(REGION_TEXT_ORDINARY_DEPS): $(BUILD_DIR)/data/text/%.d: data/text/$(TEXT_REGION)/%.cc
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MT $@ -MT $(BUILD_DIR)/data/text/$*.o

$(REGION_TEXT_ORDINARY_OBJS): $(BUILD_DIR)/data/text/%.o: data/text/$(TEXT_REGION)/%.cc $(BUILD_DIR)/data/text/%.d $(TEXT_TOOLS) charmap.txt
	@echo "CP $<"
	$(call FOMT_COMPILE_CPP,)

# ROM from ELF
# Keep the post-link archive replacement available before the generic ROM rule
# runs, regardless of which regional BUILD_NAME selected the target.
$(ROM): $(GBAFIX) config.mk
$(ROM): $(SHARED_RESOURCE_08731B40_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0871D51C_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0872BE64_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0872DE44_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_08738144_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0873A6E8_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0873D6D8_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0874F34C_OUTPUT)

%.gba: %.elf $(MAP_RESOURCES_STAMP) $(COMMON_RESOURCE_ARCHIVE_OUTPUT) $(COOKING_UI_RESOURCE_ARCHIVE_OUTPUT) $(LARGE_SHARED_RESOURCE_ARCHIVE_OUTPUT) $(SHARED_RESOURCE_08725DA0_OUTPUT)
	$(OBJCOPY) -O binary $< $@
	@$(PYTHON) $(MAP_RESOURCES_TOOL) patch --region $(MAP_RESOURCES_REGION) --rom $@ \
	  --archive $(MAP_RESOURCES_OUTPUT_DIR)/map_visual_archive.0x70 $(MAP_RESOURCES_ALL_ROM_ARGS)
	@$(PYTHON) $(COOKING_UI_RESOURCE_ARCHIVE_TOOL) $(BASE_ROM) --profile cooking-ui \
	  --offset $(COOKING_UI_RESOURCE_ARCHIVE_OFFSET) \
	  --length $(COOKING_UI_RESOURCE_ARCHIVE_LENGTH) \
	  --sha256 $(COOKING_UI_RESOURCE_ARCHIVE_SHA256) \
	  patch --target $@ --archive $(COOKING_UI_RESOURCE_ARCHIVE_OUTPUT)
	@$(PYTHON) $(LARGE_SHARED_RESOURCE_ARCHIVE_TOOL) $(BASE_ROM) --profile large-shared \
	  --offset $(LARGE_SHARED_RESOURCE_ARCHIVE_OFFSET) \
	  --length $(LARGE_SHARED_RESOURCE_ARCHIVE_LENGTH) \
	  --sha256 $(LARGE_SHARED_RESOURCE_ARCHIVE_SHA256) \
	  patch --target $@ --archive $(LARGE_SHARED_RESOURCE_ARCHIVE_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08725DA0_TOOL) $(BASE_ROM) --profile shared-08725da0 \
	  --offset $(SHARED_RESOURCE_08725DA0_OFFSET) \
	  --length $(SHARED_RESOURCE_08725DA0_LENGTH) \
	  --sha256 $(SHARED_RESOURCE_08725DA0_SHA256) \
	  patch --target $@ --archive $(SHARED_RESOURCE_08725DA0_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08731B40_TOOL) $(BASE_ROM) --profile shared-08731b40 --offset $(SHARED_RESOURCE_08731B40_OFFSET) --length $(SHARED_RESOURCE_08731B40_LENGTH) --sha256 $(SHARED_RESOURCE_08731B40_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08731B40_OUTPUT)
	@$(PYTHON) $(REGIONAL_RESOURCE_0871D51C_TOOL) $(BASE_ROM) --profile $(REGIONAL_RESOURCE_0871D51C_PROFILE) --offset $(REGIONAL_RESOURCE_0871D51C_OFFSET) --length $(REGIONAL_RESOURCE_0871D51C_LENGTH) --sha256 $(REGIONAL_RESOURCE_0871D51C_SHA256) patch --target $@ --archive $(REGIONAL_RESOURCE_0871D51C_OUTPUT)
	@$(PYTHON) $(REGIONAL_RESOURCE_0872BE64_TOOL) $(BASE_ROM) --profile $(REGIONAL_RESOURCE_0872BE64_PROFILE) --offset $(REGIONAL_RESOURCE_0872BE64_OFFSET) --length $(REGIONAL_RESOURCE_0872BE64_LENGTH) --sha256 $(REGIONAL_RESOURCE_0872BE64_SHA256) patch --target $@ --archive $(REGIONAL_RESOURCE_0872BE64_OUTPUT)
	@$(PYTHON) $(REGIONAL_RESOURCE_0872DE44_TOOL) $(BASE_ROM) --profile $(REGIONAL_RESOURCE_0872DE44_PROFILE) --offset $(REGIONAL_RESOURCE_0872DE44_OFFSET) --length $(REGIONAL_RESOURCE_0872DE44_LENGTH) --sha256 $(REGIONAL_RESOURCE_0872DE44_SHA256) patch --target $@ --archive $(REGIONAL_RESOURCE_0872DE44_OUTPUT)
	@$(PYTHON) $(REGIONAL_RESOURCE_08738144_TOOL) $(BASE_ROM) --profile $(REGIONAL_RESOURCE_08738144_PROFILE) --offset $(REGIONAL_RESOURCE_08738144_OFFSET) --length $(REGIONAL_RESOURCE_08738144_LENGTH) --sha256 $(REGIONAL_RESOURCE_08738144_SHA256) patch --target $@ --archive $(REGIONAL_RESOURCE_08738144_OUTPUT)
	@$(PYTHON) $(REGIONAL_RESOURCE_0873A6E8_TOOL) $(BASE_ROM) --profile $(REGIONAL_RESOURCE_0873A6E8_PROFILE) --offset $(REGIONAL_RESOURCE_0873A6E8_OFFSET) --length $(REGIONAL_RESOURCE_0873A6E8_LENGTH) --sha256 $(REGIONAL_RESOURCE_0873A6E8_SHA256) patch --target $@ --archive $(REGIONAL_RESOURCE_0873A6E8_OUTPUT)
	@$(PYTHON) $(REGIONAL_RESOURCE_0873D6D8_TOOL) $(BASE_ROM) --profile $(REGIONAL_RESOURCE_0873D6D8_PROFILE) --offset $(REGIONAL_RESOURCE_0873D6D8_OFFSET) --length $(REGIONAL_RESOURCE_0873D6D8_LENGTH) --sha256 $(REGIONAL_RESOURCE_0873D6D8_SHA256) patch --target $@ --archive $(REGIONAL_RESOURCE_0873D6D8_OUTPUT)
	@$(PYTHON) $(REGIONAL_RESOURCE_0874F34C_TOOL) $(BASE_ROM) --profile $(REGIONAL_RESOURCE_0874F34C_PROFILE) --offset $(REGIONAL_RESOURCE_0874F34C_OFFSET) --length $(REGIONAL_RESOURCE_0874F34C_LENGTH) --sha256 $(REGIONAL_RESOURCE_0874F34C_SHA256) patch --target $@ --archive $(REGIONAL_RESOURCE_0874F34C_OUTPUT)
	@$(PYTHON) $(COMMON_RESOURCE_ARCHIVE_TOOL) $(BASE_ROM) \
	  --offset $(COMMON_RESOURCE_ARCHIVE_OFFSET) \
	  --length $(COMMON_RESOURCE_ARCHIVE_LENGTH) \
	  --sha256 $(COMMON_RESOURCE_ARCHIVE_SHA256) \
	  patch --target $@ --archive $(COMMON_RESOURCE_ARCHIVE_OUTPUT)
	@$(GBAFIX) $@ -p -t"$(TITLE)" -c$(GAME_CODE) -m$(MAKER_CODE) -r$(GAME_REVISION) --silent

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

# This remains the ordinary C++ rule above.  Its explicit authoring marker
# needs only the selected visible-credit input; field layout is source-derived.
$(BUILD_DIR)/src/staff_credits.o: FOMT_TEXT_SOURCE_ARGS := $(STAFF_CREDITS_SOURCE)
$(BUILD_DIR)/src/staff_credits.o: $(STAFF_CREDITS_SOURCE)

# ASM dependency file (dummy, generated with the object)
$(BUILD_DIR)/%.d: $(BUILD_DIR)/%.o
	@touch $@

# ASM object
$(BUILD_DIR)/%.o: %.s
	@echo "AS $<"
	@$(AS) $(ASFLAGS) $< -o $@ --MD $(BUILD_DIR)/$*.d

# This source directly includes the generated palette streams. Keep the asset
# conversion in the same ordinary prerequisite path as the assembler input.
$(BUILD_DIR)/asm/data/data_0813B288.o: $(MAP_STATE_PALETTE_OUTPUTS) $(MAP_STATE_TEMPLATE_SOURCES) $(FARM_HOUSE_VISUAL_OUTPUTS) $(FARM_HOUSE_PALETTE_SOURCES) $(FARM_HOUSE_TILEMAP_SOURCES) $(UI_SCENE_080A2BA4_OUTPUTS) $(UI_SCENE_08077810_ACTIVE_ASSETS) $(UI_SCENE_08054F40_TILES_OUTPUT) $(UI_SCENE_0805AB08_TILES_OUTPUT) $(UI_SCENE_080B7164_OUTPUTS) $(UI_SCENE_080C160C_OUTPUTS) $(UI_SCENE_080BCFAC_OUTPUTS) $(UI_SCENE_080B55D0_AUX_OUTPUTS) $(UI_SCENE_080B55D0_MAIN_OUTPUT) $(UI_SCENE_080AE7D0_OUTPUTS) $(SHARED_RESOURCE_0873AE54_ASSETS) $(SHARED_RESOURCE_0873D5FC_ASSETS) $(SHARED_RESOURCE_08740908_ASSETS) $(SHARED_RESOURCE_0874EE38_ASSETS) $(SHARED_RESOURCE_0875352C_ASSETS) $(SHARED_RESOURCE_08753608_ASSETS) $(SHARED_RESOURCE_08755154_ASSETS) $(INTRO_SMALL_ARCHIVE_ASSETS) $(SHARED_RESOURCE_0871ECAC_ASSETS) $(SHARED_RESOURCE_0871ECAC_SOURCE_DIR)/archive.inc $(SHARED_RESOURCE_0871EDD4_ASSETS) $(SHARED_RESOURCE_0871EDD4_SOURCE_DIR)/archive.inc $(SMALL_UI_RESOURCE_ARCHIVE_ASSETS) $(SMALL_UI_RESOURCE_ARCHIVE_SOURCE_DIR)/archive.inc $(MENU_UI_RESOURCE_ARCHIVE_ASSETS) $(MENU_UI_RESOURCE_ARCHIVE_SOURCE_DIR)/archive.inc

$(BUILD_DIR)/asm/data/data_0813B288.o: asm/data/data_0813B288_de_initial.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_0873CEAC_ASSETS) $(SHARED_RESOURCE_0873CEAC_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_0873CF90_ASSETS) $(SHARED_RESOURCE_0873CF90_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_0873CCB4_ASSETS) $(SHARED_RESOURCE_0873CCB4_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_0873D234_ASSETS) $(SHARED_RESOURCE_0873D234_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_0873DE44_ASSETS) $(SHARED_RESOURCE_0873DE44_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_0873E5B0_ASSETS) $(SHARED_RESOURCE_0873E5B0_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_0873ED1C_ASSETS) $(SHARED_RESOURCE_0873ED1C_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_087401A4_ASSETS) $(SHARED_RESOURCE_087401A4_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_08740454_ASSETS) $(SHARED_RESOURCE_08740454_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_087405A0_ASSETS) $(SHARED_RESOURCE_087405A0_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_087409E4_ASSETS) $(SHARED_RESOURCE_087409E4_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_087506E0_ASSETS) $(SHARED_RESOURCE_087506E0_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_087536E4_ASSETS) $(SHARED_RESOURCE_087536E4_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_08527094_ASSETS) $(SHARED_RESOURCE_08527094_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_086FAA80_ASSETS) $(SHARED_RESOURCE_086FAA80_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_08726CCC_ASSETS) $(SHARED_RESOURCE_08726CCC_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_08727368_ASSETS) $(SHARED_RESOURCE_08727368_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_08727A74_ASSETS) $(SHARED_RESOURCE_08727A74_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_08728320_ASSETS) $(SHARED_RESOURCE_08728320_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_0872937C_ASSETS) $(SHARED_RESOURCE_0872937C_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_0872EE78_ASSETS) $(SHARED_RESOURCE_0872EE78_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_08729460_ASSETS) $(SHARED_RESOURCE_08729460_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_0873AFC8_ASSETS) $(SHARED_RESOURCE_0873AFC8_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(REGIONAL_RESOURCE_0875B444_ASSETS) $(REGIONAL_RESOURCE_0875B444_SOURCE_ROOT)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(REGIONAL_RESOURCE_08728208_ASSETS) $(REGIONAL_RESOURCE_08728208_SOURCE_ROOT)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SHARED_RESOURCE_086F2FAC_ASSETS) $(SHARED_RESOURCE_086F2FAC_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(FARM_STATUS_RESOURCE_ARCHIVE_ASSETS) $(FARM_STATUS_RESOURCE_ARCHIVE_SOURCE_DIR)/archive.inc
$(BUILD_DIR)/asm/data/data_0813B288.o: $(SMALL_COMPANION_ARCHIVE_ASSETS) $(SMALL_COMPANION_ARCHIVE_SOURCE_DIR)/archive.inc

# overrides for matching
$(BUILD_DIR)/src/m4a.o: CC1 := $(OLD_CC1)

clean:
	@echo "RM $(ROM) $(ELF) $(MAP) $(BUILD_DIR)"
	@rm -f $(ROM) $(ELF) $(MAP) 
	@rm -rf $(BUILD_DIR)/

.PHONY: clean

# Audit/build-only graphics targets do not need C/C++ dependency discovery.
ifneq (,$(filter gfx-ui-scene-080a2ba4 gfx-ui-scene-080a2ba4-reference gfx-ui-scene-080a2ba4-test gfx-ui-scene-080a2ba4-all gfx-ui-scene-080ae7d0 gfx-ui-scene-080ae7d0-preview gfx-ui-scene-080ae7d0-test gfx-ui-scene-080ae7d0-all gfx-ui-scene-080b7164 gfx-ui-scene-080b7164-preview gfx-ui-scene-080b7164-test gfx-ui-scene-080b7164-all gfx-ui-scene-080c160c gfx-ui-scene-080c160c-preview gfx-ui-scene-080c160c-test gfx-ui-scene-080c160c-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-ui-scene-080bcfac gfx-ui-scene-080bcfac-preview gfx-ui-scene-080bcfac-test gfx-ui-scene-080bcfac-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-ui-scene-080b55d0-aux gfx-ui-scene-080b55d0-aux-reference gfx-ui-scene-080b55d0-aux-test gfx-ui-scene-080b55d0-aux-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-farm-status-task-ui-tile gfx-farm-status-task-ui-tile-test gfx-farm-status-task-ui-tile-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-ui-shared-tiles-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-ui-scene-08054f40-tiles gfx-ui-scene-08054f40-reference gfx-ui-scene-08054f40-tiles-test gfx-ui-scene-08054f40-tiles-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-ui-scene-0805ab08-tiles gfx-ui-scene-0805ab08-reference gfx-ui-scene-0805ab08-tiles-test gfx-ui-scene-0805ab08-tiles-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-seasonal-nonwinter gfx-seasonal-nonwinter-test gfx-seasonal-nonwinter-all gfx-seasonal-winter gfx-seasonal-winter-test gfx-seasonal-winter-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-intro-indexed-archive gfx-intro-indexed-archive-test gfx-intro-indexed-archive-all gfx-intro-indexed-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-intro-small-archive gfx-intro-small-archive-test gfx-intro-small-archive-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-map-resources-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-farm-status-resource-archive,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-small-companion-archive,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-small-ui-resource-archive,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-cooking-ui-resource-archive gfx-cooking-ui-resource-archive-test gfx-cooking-ui-resource-archive-all gfx-cooking-ui-resource-archive-patch-test gfx-cooking-ui-resource-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-menu-ui-resource-archive,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-large-shared-resource-archive gfx-large-shared-resource-archive-test gfx-large-shared-resource-archive-all gfx-large-shared-resource-archive-patch-test gfx-large-shared-resource-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08725da0 gfx-shared-resource-08725da0-test gfx-shared-resource-08725da0-all gfx-shared-resource-08725da0-patch-test gfx-shared-resource-08725da0-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-086f2fac,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-086faa80,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0871ecac,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0871edd4,$(MAKECMDGOALS)))
ALL_DEPS :=
endif
ifneq (,$(filter gfx-shared-resource-08527094,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08726ccc,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08727368,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08727a74,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08728320,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0872937c,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08729460,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0872ee78,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08731b40 gfx-shared-resource-08731b40-test gfx-shared-resource-08731b40-all gfx-shared-resource-08731b40-patch-test gfx-shared-resource-08731b40-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873ae54 gfx-shared-resource-0873ae54-test gfx-shared-resource-0873ae54-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873afc8,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873ccb4,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873ceac,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873cf90,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873d234,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873d5fc gfx-shared-resource-0873d5fc-test gfx-shared-resource-0873d5fc-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873de44,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873e5b0,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873ed1c,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-087401a4,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08740454,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-087405a0,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08740908 gfx-shared-resource-08740908-test gfx-shared-resource-08740908-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-087409e4,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0874ee38 gfx-shared-resource-0874ee38-test gfx-shared-resource-0874ee38-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-087506e0,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0875352c gfx-shared-resource-0875352c-test gfx-shared-resource-0875352c-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08753608 gfx-shared-resource-08753608-test gfx-shared-resource-08753608-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-087536e4,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08755154 gfx-shared-resource-08755154-test gfx-shared-resource-08755154-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-regional-resource-0875b444,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-regional-resource-0871d51c gfx-regional-resource-0871d51c-test gfx-regional-resource-0871d51c-all gfx-regional-resource-0871d51c-patch-test gfx-regional-resource-0871d51c-edit-test gfx-regional-resource-0871d51c-edit-test-one,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-regional-resource-08728208,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-regional-resource-0872be64 gfx-regional-resource-0872be64-test gfx-regional-resource-0872be64-all gfx-regional-resource-0872be64-patch-test gfx-regional-resource-0872be64-edit-test gfx-regional-resource-0872be64-edit-test-one,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-regional-resource-0872de44 gfx-regional-resource-0872de44-test gfx-regional-resource-0872de44-all gfx-regional-resource-0872de44-patch-test gfx-regional-resource-0872de44-edit-test gfx-regional-resource-0872de44-edit-test-one,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-regional-resource-08738144 gfx-regional-resource-08738144-test gfx-regional-resource-08738144-all gfx-regional-resource-08738144-patch-test gfx-regional-resource-08738144-edit-test gfx-regional-resource-08738144-edit-test-one,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-regional-resource-0873a6e8 gfx-regional-resource-0873a6e8-test gfx-regional-resource-0873a6e8-all gfx-regional-resource-0873a6e8-patch-test gfx-regional-resource-0873a6e8-edit-test gfx-regional-resource-0873a6e8-edit-test-one gfx-regional-resource-0873d6d8 gfx-regional-resource-0873d6d8-test gfx-regional-resource-0873d6d8-all gfx-regional-resource-0873d6d8-patch-test gfx-regional-resource-0873d6d8-edit-test gfx-regional-resource-0873d6d8-edit-test-one,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-regional-resource-0874f34c gfx-regional-resource-0874f34c-test gfx-regional-resource-0874f34c-all gfx-regional-resource-0874f34c-patch-test gfx-regional-resource-0874f34c-edit-test gfx-regional-resource-0874f34c-edit-test-one,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter indexed-resource-archive-inventory,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-common-resource-archive gfx-common-resource-archive-test gfx-common-resource-archive-all gfx-common-resource-archive-patch-test gfx-common-resource-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-farm-house-tilemaps gfx-farm-house-tilemaps-test gfx-farm-house-tilemaps-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-portraits gfx-portraits-test gfx-portraits-all gfx-portraits-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (clean,$(MAKECMDGOALS))
ifeq (unpack-coverage-inventory,$(strip $(MAKECMDGOALS)))
# This target needs only the Python audit tool, never the default ROM build.
else
# The regional fomt_* wrappers recurse into compare.  Load only dependency
# files that already exist: a clean build creates each .d with its object,
# while an incremental compare must notice edited .incbin graphics inputs.
ifneq (,$(filter compare,$(MAKECMDGOALS)))
-include $(wildcard $(ALL_DEPS))
endif
ifeq (,$(filter fomt_us fomt_jp fomt_eu fomt_de compare compare_eu compare_de gfx-font gfx-jp-font gfx-fonts gfx-font-test gfx-fonts-test gfx-portraits gfx-portraits-all gfx-actors gfx-actors-test gfx-actors-all gfx-actors-edit-test gfx-ui gfx-ui-test gfx-ui-all gfx-ui-scene-080a2ba4 gfx-ui-scene-080a2ba4-test gfx-ui-scene-080a2ba4-all gfx-ui-scene-08077810 gfx-ui-scene-08077810-reference gfx-ui-scene-08077810-test gfx-ui-scene-08077810-all gfx-ui-scene-080ae7d0 gfx-ui-scene-080ae7d0-preview gfx-ui-scene-080ae7d0-test gfx-ui-scene-080ae7d0-all gfx-ui-scene-080b7164 gfx-ui-scene-080b7164-preview gfx-ui-scene-080b7164-test gfx-ui-scene-080b7164-all gfx-ui-scene-080c160c gfx-ui-scene-080c160c-test gfx-ui-scene-080c160c-all gfx-ui-scene-080b55d0-aux gfx-ui-scene-080b55d0-aux-reference gfx-ui-scene-080b55d0-aux-test gfx-ui-scene-080b55d0-aux-all gfx-ui-scene-080b55d0-main gfx-ui-scene-080b55d0-main-test gfx-ui-scene-080b55d0-main-all gfx-ui-scene-08054f40-reference gfx-farm-house-tilemaps gfx-farm-house-tilemaps-test gfx-farm-house-tilemaps-all gfx-farm-status gfx-farm-status-test gfx-farm-status-all gfx-farm-status-winter gfx-farm-status-winter-test gfx-farm-status-winter-all gfx-farm-status-previews gfx-farm-status-tilemaps gfx-farm-status-tilemaps-test gfx-farm-status-tilemaps-all gfx-farm-status-secondary-tilemaps gfx-farm-status-secondary-tilemaps-test gfx-farm-status-secondary-tilemaps-all gfx-farm-status-exterior-styles gfx-farm-status-exterior-styles-test gfx-farm-status-selector-icon gfx-farm-status-selector-icon-test gfx-farm-status-selector-icon-all gfx-clock-font gfx-clock-font-test gfx-clock-font-all gfx-farm-status-creature-icons gfx-farm-status-creature-icons-test gfx-farm-status-creature-icons-all gfx-intro-background gfx-intro-background-test gfx-intro-background-all gfx-intro-objects gfx-intro-objects-all gfx-intro-objects-test gfx-intro-startup-visual gfx-intro-startup-visual-test gfx-intro-startup-visual-all gfx-map-resources gfx-map-resources-test gfx-map-resources-all gfx-map-resources-patch-test gfx-records-minigame gfx-records-minigame-test gfx-records-minigame-all resource-archive-audit unpack-vram-inventory gfx-assets gfx-verify tile-grid-region-test tile-grid-test oam-pack oam-pack-test oam-pack-audit,$(MAKECMDGOALS)))
-include $(ALL_DEPS)
endif
.PRECIOUS: $(BUILD_DIR)/%.d
endif
endif
