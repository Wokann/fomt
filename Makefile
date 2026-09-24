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
OAM_PACK_AUDIT := $(OAM_PACK_DIR)/audit_portraits.py
GFX_RANGE_VERIFY := tools/verify_gfx_range.py
TILE_GRID_TOOL := tools/tile_grid.py
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
$(ROM): $(SHARED_RESOURCE_086F2FAC_OUTPUT)
$(ROM): $(SHARED_RESOURCE_086FAA80_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0871ECAC_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0871EDD4_OUTPUT)
$(ROM): $(SHARED_RESOURCE_08527094_OUTPUT)
$(ROM): $(SHARED_RESOURCE_08726CCC_OUTPUT)
$(ROM): $(SHARED_RESOURCE_08727368_OUTPUT)
$(ROM): $(SHARED_RESOURCE_08727A74_OUTPUT)
$(ROM): $(SHARED_RESOURCE_08728320_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0872937C_OUTPUT)
$(ROM): $(SHARED_RESOURCE_08729460_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0872EE78_OUTPUT)
$(ROM): $(SHARED_RESOURCE_08731B40_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0873AE54_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0873AFC8_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0873CCB4_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0873CEAC_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0873CF90_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0873D234_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0873D5FC_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0873DE44_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0873E5B0_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0873ED1C_OUTPUT)
$(ROM): $(SHARED_RESOURCE_087401A4_OUTPUT)
$(ROM): $(SHARED_RESOURCE_08740454_OUTPUT)
$(ROM): $(SHARED_RESOURCE_087405A0_OUTPUT)
$(ROM): $(SHARED_RESOURCE_08740908_OUTPUT)
$(ROM): $(SHARED_RESOURCE_087409E4_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0874EE38_OUTPUT)
$(ROM): $(SHARED_RESOURCE_087506E0_OUTPUT)
$(ROM): $(SHARED_RESOURCE_0875352C_OUTPUT)
$(ROM): $(SHARED_RESOURCE_08753608_OUTPUT)
$(ROM): $(SHARED_RESOURCE_087536E4_OUTPUT)
$(ROM): $(SHARED_RESOURCE_08755154_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0875B444_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0871D51C_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_08728208_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0872BE64_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0872DE44_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_08738144_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0873A6E8_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0873D6D8_OUTPUT)
$(ROM): $(REGIONAL_RESOURCE_0874F34C_OUTPUT)

%.gba: %.elf $(MAP_RESOURCES_STAMP) $(MAP_STATE_TEMPLATE_STAMP) $(UI_SCENE_080A2BA4_STAMP) $(UI_SCENE_080AE7D0_STAMP) $(UI_SCENE_080B7164_STAMP) $(UI_SCENE_080B7164_PALETTE_BIN) $(UI_SCENE_080C160C_STAMP) $(UI_SCENE_080C160C_PALETTE_BIN) $(UI_SCENE_080BCFAC_STAMP) $(UI_SCENE_080BCFAC_PALETTE_BIN) $(UI_SCENE_080B55D0_AUX_STAMP) $(UI_SCENE_080B55D0_MAIN_STAMP) $(foreach profile,$(RAW_VRAM_UI_PROFILES),$(RAW_VRAM_TILES_$(profile)_STAMP)) $(UI_SCENE_08054F40_TILES_STAMP) $(UI_SCENE_0805AB08_TILES_STAMP) $(FARM_HOUSE_VISUAL_STAMP) $(FARM_HOUSE_TILEMAP_STAMP) $(FARM_HOUSE_PALETTE_STAMP) $(FARM_STATUS_RESOURCE_ARCHIVE_OUTPUT) $(COMMON_RESOURCE_ARCHIVE_OUTPUT) $(SMALL_COMPANION_ARCHIVE_OUTPUT) $(SMALL_UI_RESOURCE_ARCHIVE_OUTPUT) $(COOKING_UI_RESOURCE_ARCHIVE_OUTPUT) $(MENU_UI_RESOURCE_ARCHIVE_OUTPUT) $(LARGE_SHARED_RESOURCE_ARCHIVE_OUTPUT) $(SHARED_RESOURCE_08725DA0_OUTPUT)
	$(OBJCOPY) -O binary $< $@
	@$(PYTHON) $(MAP_RESOURCES_TOOL) patch --region $(MAP_RESOURCES_REGION) --rom $@ \
	  --archive $(MAP_RESOURCES_OUTPUT_DIR)/map_visual_archive.0x70 $(MAP_RESOURCES_ALL_ROM_ARGS)
	@$(PYTHON) $(MAP_STATE_TEMPLATE_TOOL) patch --region $(MAP_STATE_TEMPLATE_REGION) --rom $@ \
	  --output-dir $(MAP_STATE_TEMPLATE_OUTPUT_DIR) $(MAP_RESOURCES_ALL_ROM_ARGS)
	@$(PYTHON) $(UI_SCENE_080A2BA4_TOOL) patch --region $(UI_SCENE_080A2BA4_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_080A2BA4_OUTPUT_DIR)
	@$(PYTHON) $(UI_SCENE_080AE7D0_TOOL) patch --region $(UI_SCENE_080AE7D0_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_080AE7D0_OUTPUT_DIR)
	@$(PYTHON) $(UI_SCENE_080B7164_TOOL) patch --region $(UI_SCENE_080B7164_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_080B7164_OUTPUT_DIR)
	@$(PYTHON) $(UI_SCENE_080B7164_VISUAL_TOOL) patch --region $(UI_SCENE_080B7164_REGION) --baseline $(BASE_ROM) \
	  --profile 080b7164 --rom $@ --output-dir $(UI_SCENE_080B7164_OUTPUT_DIR)
	@$(PYTHON) $(UI_SCENE_080C160C_TOOL) --profile 080c160c patch --region $(UI_SCENE_080C160C_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_080C160C_OUTPUT_DIR)
	@$(PYTHON) $(UI_SCENE_080C160C_VISUAL_TOOL) patch --profile 080c160c --region $(UI_SCENE_080C160C_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_080C160C_OUTPUT_DIR)
	@$(PYTHON) $(UI_SCENE_080BCFAC_TOOL) --profile 080bcfac patch --region $(UI_SCENE_080BCFAC_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_080BCFAC_OUTPUT_DIR)
	@$(PYTHON) $(UI_SCENE_080BCFAC_VISUAL_TOOL) patch --profile 080bcfac --region $(UI_SCENE_080BCFAC_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_080BCFAC_OUTPUT_DIR)
	@$(PYTHON) $(UI_SCENE_080B55D0_AUX_TOOL) --profile 080b55d0_aux patch --region $(UI_SCENE_080B55D0_AUX_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_080B55D0_AUX_OUTPUT_DIR)
	@$(PYTHON) $(UI_SCENE_080B55D0_MAIN_TOOL) --profile 080b55d0_main patch --region $(UI_SCENE_080B55D0_MAIN_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_080B55D0_MAIN_OUTPUT_DIR)
	@set -e; $(foreach profile,$(RAW_VRAM_UI_PROFILES),$(PYTHON) $(RAW_VRAM_TILES_$(profile)_TOOL) --profile $(profile) patch --region $(RAW_VRAM_TILES_$(profile)_REGION) --baseline $(BASE_ROM) --rom $@ --output-dir $(RAW_VRAM_TILES_$(profile)_OUTPUT_DIR);)
	@$(PYTHON) $(UI_SCENE_08054F40_TILES_TOOL) --profile 08054f40_tiles patch --region $(UI_SCENE_08054F40_TILES_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_08054F40_TILES_OUTPUT_DIR)
	@$(PYTHON) $(UI_SCENE_0805AB08_TILES_TOOL) --profile 0805ab08_tiles patch --region $(UI_SCENE_0805AB08_TILES_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_0805AB08_TILES_OUTPUT_DIR)
	@$(PYTHON) $(FARM_HOUSE_VISUAL_TOOL) patch --region $(FARM_HOUSE_VISUAL_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(FARM_HOUSE_VISUAL_OUTPUT_DIR)
	@$(PYTHON) $(FARM_HOUSE_TILEMAP_TOOL) patch --region $(FARM_HOUSE_TILEMAP_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(FARM_HOUSE_TILEMAP_OUTPUT_DIR) $(MAP_RESOURCES_ALL_ROM_ARGS)
	@$(PYTHON) $(FARM_HOUSE_PALETTE_TOOL) patch --region $(FARM_HOUSE_PALETTE_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(FARM_HOUSE_PALETTE_OUTPUT_DIR) $(MAP_RESOURCES_ALL_ROM_ARGS)
	@$(PYTHON) $(SMALL_COMPANION_ARCHIVE_TOOL) $(BASE_ROM) --profile small-companion \
	  --offset $(SMALL_COMPANION_ARCHIVE_OFFSET) \
	  --length $(SMALL_COMPANION_ARCHIVE_LENGTH) \
	  --sha256 $(SMALL_COMPANION_ARCHIVE_SHA256) \
	  patch --target $@ --archive $(SMALL_COMPANION_ARCHIVE_OUTPUT)
	@$(PYTHON) $(SMALL_UI_RESOURCE_ARCHIVE_TOOL) $(BASE_ROM) --profile small-ui \
	  --offset $(SMALL_UI_RESOURCE_ARCHIVE_OFFSET) \
	  --length $(SMALL_UI_RESOURCE_ARCHIVE_LENGTH) \
	  --sha256 $(SMALL_UI_RESOURCE_ARCHIVE_SHA256) \
	  patch --target $@ --archive $(SMALL_UI_RESOURCE_ARCHIVE_OUTPUT)
	@$(PYTHON) $(COOKING_UI_RESOURCE_ARCHIVE_TOOL) $(BASE_ROM) --profile cooking-ui \
	  --offset $(COOKING_UI_RESOURCE_ARCHIVE_OFFSET) \
	  --length $(COOKING_UI_RESOURCE_ARCHIVE_LENGTH) \
	  --sha256 $(COOKING_UI_RESOURCE_ARCHIVE_SHA256) \
	  patch --target $@ --archive $(COOKING_UI_RESOURCE_ARCHIVE_OUTPUT)
	@$(PYTHON) $(MENU_UI_RESOURCE_ARCHIVE_TOOL) $(BASE_ROM) --profile menu-ui \
	  --offset $(MENU_UI_RESOURCE_ARCHIVE_OFFSET) \
	  --length $(MENU_UI_RESOURCE_ARCHIVE_LENGTH) \
	  --sha256 $(MENU_UI_RESOURCE_ARCHIVE_SHA256) \
	  patch --target $@ --archive $(MENU_UI_RESOURCE_ARCHIVE_OUTPUT)
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
	@$(PYTHON) $(SHARED_RESOURCE_086F2FAC_TOOL) $(BASE_ROM) --profile shared-086f2fac \
	  --offset $(SHARED_RESOURCE_086F2FAC_OFFSET) \
	  --length $(SHARED_RESOURCE_086F2FAC_LENGTH) \
	  --sha256 $(SHARED_RESOURCE_086F2FAC_SHA256) \
	  patch --target $@ --archive $(SHARED_RESOURCE_086F2FAC_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_086FAA80_TOOL) $(BASE_ROM) --profile shared-086faa80 \
	  --offset $(SHARED_RESOURCE_086FAA80_OFFSET) \
	  --length $(SHARED_RESOURCE_086FAA80_LENGTH) \
	  --sha256 $(SHARED_RESOURCE_086FAA80_SHA256) \
	  patch --target $@ --archive $(SHARED_RESOURCE_086FAA80_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0871ECAC_TOOL) $(BASE_ROM) --profile shared-0871ecac \
	  --offset $(SHARED_RESOURCE_0871ECAC_OFFSET) \
	  --length $(SHARED_RESOURCE_0871ECAC_LENGTH) \
	  --sha256 $(SHARED_RESOURCE_0871ECAC_SHA256) \
	  patch --target $@ --archive $(SHARED_RESOURCE_0871ECAC_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0871EDD4_TOOL) $(BASE_ROM) --profile shared-0871edd4 \
	  --offset $(SHARED_RESOURCE_0871EDD4_OFFSET) \
	  --length $(SHARED_RESOURCE_0871EDD4_LENGTH) \
	  --sha256 $(SHARED_RESOURCE_0871EDD4_SHA256) \
	  patch --target $@ --archive $(SHARED_RESOURCE_0871EDD4_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08527094_TOOL) $(BASE_ROM) --profile shared-08527094 --offset $(SHARED_RESOURCE_08527094_OFFSET) --length $(SHARED_RESOURCE_08527094_LENGTH) --sha256 $(SHARED_RESOURCE_08527094_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08527094_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08726CCC_TOOL) $(BASE_ROM) --profile shared-08726ccc --offset $(SHARED_RESOURCE_08726CCC_OFFSET) --length $(SHARED_RESOURCE_08726CCC_LENGTH) --sha256 $(SHARED_RESOURCE_08726CCC_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08726CCC_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08727368_TOOL) $(BASE_ROM) --profile shared-08727368 --offset $(SHARED_RESOURCE_08727368_OFFSET) --length $(SHARED_RESOURCE_08727368_LENGTH) --sha256 $(SHARED_RESOURCE_08727368_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08727368_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08727A74_TOOL) $(BASE_ROM) --profile shared-08727a74 --offset $(SHARED_RESOURCE_08727A74_OFFSET) --length $(SHARED_RESOURCE_08727A74_LENGTH) --sha256 $(SHARED_RESOURCE_08727A74_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08727A74_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08728320_TOOL) $(BASE_ROM) --profile shared-08728320 --offset $(SHARED_RESOURCE_08728320_OFFSET) --length $(SHARED_RESOURCE_08728320_LENGTH) --sha256 $(SHARED_RESOURCE_08728320_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08728320_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0872937C_TOOL) $(BASE_ROM) --profile shared-0872937c --offset $(SHARED_RESOURCE_0872937C_OFFSET) --length $(SHARED_RESOURCE_0872937C_LENGTH) --sha256 $(SHARED_RESOURCE_0872937C_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0872937C_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08729460_TOOL) $(BASE_ROM) --profile shared-08729460 --offset $(SHARED_RESOURCE_08729460_OFFSET) --length $(SHARED_RESOURCE_08729460_LENGTH) --sha256 $(SHARED_RESOURCE_08729460_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08729460_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0872EE78_TOOL) $(BASE_ROM) --profile shared-0872ee78 --offset $(SHARED_RESOURCE_0872EE78_OFFSET) --length $(SHARED_RESOURCE_0872EE78_LENGTH) --sha256 $(SHARED_RESOURCE_0872EE78_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0872EE78_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08731B40_TOOL) $(BASE_ROM) --profile shared-08731b40 --offset $(SHARED_RESOURCE_08731B40_OFFSET) --length $(SHARED_RESOURCE_08731B40_LENGTH) --sha256 $(SHARED_RESOURCE_08731B40_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08731B40_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0873AE54_TOOL) $(BASE_ROM) --profile shared-0873ae54 --offset $(SHARED_RESOURCE_0873AE54_OFFSET) --length $(SHARED_RESOURCE_0873AE54_LENGTH) --sha256 $(SHARED_RESOURCE_0873AE54_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0873AE54_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0873AFC8_TOOL) $(BASE_ROM) --profile shared-0873afc8 --offset $(SHARED_RESOURCE_0873AFC8_OFFSET) --length $(SHARED_RESOURCE_0873AFC8_LENGTH) --sha256 $(SHARED_RESOURCE_0873AFC8_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0873AFC8_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0873CCB4_TOOL) $(BASE_ROM) --profile shared-0873ccb4 --offset $(SHARED_RESOURCE_0873CCB4_OFFSET) --length $(SHARED_RESOURCE_0873CCB4_LENGTH) --sha256 $(SHARED_RESOURCE_0873CCB4_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0873CCB4_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0873CEAC_TOOL) $(BASE_ROM) --profile shared-0873ceac --offset $(SHARED_RESOURCE_0873CEAC_OFFSET) --length $(SHARED_RESOURCE_0873CEAC_LENGTH) --sha256 $(SHARED_RESOURCE_0873CEAC_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0873CEAC_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0873CF90_TOOL) $(BASE_ROM) --profile shared-0873cf90 --offset $(SHARED_RESOURCE_0873CF90_OFFSET) --length $(SHARED_RESOURCE_0873CF90_LENGTH) --sha256 $(SHARED_RESOURCE_0873CF90_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0873CF90_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0873D234_TOOL) $(BASE_ROM) --profile shared-0873d234 --offset $(SHARED_RESOURCE_0873D234_OFFSET) --length $(SHARED_RESOURCE_0873D234_LENGTH) --sha256 $(SHARED_RESOURCE_0873D234_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0873D234_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0873D5FC_TOOL) $(BASE_ROM) --profile shared-0873d5fc --offset $(SHARED_RESOURCE_0873D5FC_OFFSET) --length $(SHARED_RESOURCE_0873D5FC_LENGTH) --sha256 $(SHARED_RESOURCE_0873D5FC_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0873D5FC_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0873DE44_TOOL) $(BASE_ROM) --profile shared-0873de44 --offset $(SHARED_RESOURCE_0873DE44_OFFSET) --length $(SHARED_RESOURCE_0873DE44_LENGTH) --sha256 $(SHARED_RESOURCE_0873DE44_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0873DE44_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0873E5B0_TOOL) $(BASE_ROM) --profile shared-0873e5b0 --offset $(SHARED_RESOURCE_0873E5B0_OFFSET) --length $(SHARED_RESOURCE_0873E5B0_LENGTH) --sha256 $(SHARED_RESOURCE_0873E5B0_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0873E5B0_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0873ED1C_TOOL) $(BASE_ROM) --profile shared-0873ed1c --offset $(SHARED_RESOURCE_0873ED1C_OFFSET) --length $(SHARED_RESOURCE_0873ED1C_LENGTH) --sha256 $(SHARED_RESOURCE_0873ED1C_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0873ED1C_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_087401A4_TOOL) $(BASE_ROM) --profile shared-087401a4 --offset $(SHARED_RESOURCE_087401A4_OFFSET) --length $(SHARED_RESOURCE_087401A4_LENGTH) --sha256 $(SHARED_RESOURCE_087401A4_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_087401A4_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08740454_TOOL) $(BASE_ROM) --profile shared-08740454 --offset $(SHARED_RESOURCE_08740454_OFFSET) --length $(SHARED_RESOURCE_08740454_LENGTH) --sha256 $(SHARED_RESOURCE_08740454_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08740454_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_087405A0_TOOL) $(BASE_ROM) --profile shared-087405a0 --offset $(SHARED_RESOURCE_087405A0_OFFSET) --length $(SHARED_RESOURCE_087405A0_LENGTH) --sha256 $(SHARED_RESOURCE_087405A0_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_087405A0_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08740908_TOOL) $(BASE_ROM) --profile shared-08740908 --offset $(SHARED_RESOURCE_08740908_OFFSET) --length $(SHARED_RESOURCE_08740908_LENGTH) --sha256 $(SHARED_RESOURCE_08740908_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08740908_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_087409E4_TOOL) $(BASE_ROM) --profile shared-087409e4 --offset $(SHARED_RESOURCE_087409E4_OFFSET) --length $(SHARED_RESOURCE_087409E4_LENGTH) --sha256 $(SHARED_RESOURCE_087409E4_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_087409E4_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0874EE38_TOOL) $(BASE_ROM) --profile shared-0874ee38 --offset $(SHARED_RESOURCE_0874EE38_OFFSET) --length $(SHARED_RESOURCE_0874EE38_LENGTH) --sha256 $(SHARED_RESOURCE_0874EE38_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0874EE38_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_087506E0_TOOL) $(BASE_ROM) --profile shared-087506e0 --offset $(SHARED_RESOURCE_087506E0_OFFSET) --length $(SHARED_RESOURCE_087506E0_LENGTH) --sha256 $(SHARED_RESOURCE_087506E0_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_087506E0_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_0875352C_TOOL) $(BASE_ROM) --profile shared-0875352c --offset $(SHARED_RESOURCE_0875352C_OFFSET) --length $(SHARED_RESOURCE_0875352C_LENGTH) --sha256 $(SHARED_RESOURCE_0875352C_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_0875352C_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08753608_TOOL) $(BASE_ROM) --profile shared-08753608 --offset $(SHARED_RESOURCE_08753608_OFFSET) --length $(SHARED_RESOURCE_08753608_LENGTH) --sha256 $(SHARED_RESOURCE_08753608_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08753608_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_087536E4_TOOL) $(BASE_ROM) --profile shared-087536e4 --offset $(SHARED_RESOURCE_087536E4_OFFSET) --length $(SHARED_RESOURCE_087536E4_LENGTH) --sha256 $(SHARED_RESOURCE_087536E4_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_087536E4_OUTPUT)
	@$(PYTHON) $(SHARED_RESOURCE_08755154_TOOL) $(BASE_ROM) --profile shared-08755154 --offset $(SHARED_RESOURCE_08755154_OFFSET) --length $(SHARED_RESOURCE_08755154_LENGTH) --sha256 $(SHARED_RESOURCE_08755154_SHA256) patch --target $@ --archive $(SHARED_RESOURCE_08755154_OUTPUT)
	@$(PYTHON) $(REGIONAL_RESOURCE_0875B444_TOOL) $(BASE_ROM) --profile regional-0875b444 --offset $(REGIONAL_RESOURCE_0875B444_OFFSET) --length $(REGIONAL_RESOURCE_0875B444_LENGTH) --sha256 $(REGIONAL_RESOURCE_0875B444_SHA256) patch --target $@ --archive $(REGIONAL_RESOURCE_0875B444_OUTPUT)
	@$(PYTHON) $(REGIONAL_RESOURCE_0871D51C_TOOL) $(BASE_ROM) --profile $(REGIONAL_RESOURCE_0871D51C_PROFILE) --offset $(REGIONAL_RESOURCE_0871D51C_OFFSET) --length $(REGIONAL_RESOURCE_0871D51C_LENGTH) --sha256 $(REGIONAL_RESOURCE_0871D51C_SHA256) patch --target $@ --archive $(REGIONAL_RESOURCE_0871D51C_OUTPUT)
	@$(PYTHON) $(REGIONAL_RESOURCE_08728208_TOOL) $(BASE_ROM) --profile regional-08728208 --offset $(REGIONAL_RESOURCE_08728208_OFFSET) --length $(REGIONAL_RESOURCE_08728208_LENGTH) --sha256 $(REGIONAL_RESOURCE_08728208_SHA256) patch --target $@ --archive $(REGIONAL_RESOURCE_08728208_OUTPUT)
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
	@$(PYTHON) $(FARM_STATUS_RESOURCE_ARCHIVE_TOOL) $(BASE_ROM) \
	  --offset $(FARM_STATUS_RESOURCE_ARCHIVE_OFFSET) \
	  --length $(FARM_STATUS_RESOURCE_ARCHIVE_LENGTH) \
	  --sha256 $(FARM_STATUS_RESOURCE_ARCHIVE_SHA256) \
	  patch --target $@ --archive $(FARM_STATUS_RESOURCE_ARCHIVE_OUTPUT)
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

# This remains the ordinary C++ rule above.  Only its explicit authoring
# marker needs the selected visible-credit input and baseline field layout.
$(BUILD_DIR)/src/staff_credits.o: FOMT_TEXT_SOURCE_ARGS := $(STAFF_CREDITS_SOURCE) baserom_$(TEXT_REGION).gba
$(BUILD_DIR)/src/staff_credits.o: $(STAFF_CREDITS_SOURCE) baserom_$(TEXT_REGION).gba

# ASM dependency file (dummy, generated with the object)
$(BUILD_DIR)/%.d: $(BUILD_DIR)/%.o
	@touch $@

# ASM object
$(BUILD_DIR)/%.o: %.s
	@echo "AS $<"
	@$(AS) $(ASFLAGS) $< -o $@ --MD $(BUILD_DIR)/$*.d

# This source directly includes the generated palette streams. Keep the asset
# conversion in the same ordinary prerequisite path as the assembler input.
$(BUILD_DIR)/asm/data/data_0813B288.o: $(MAP_STATE_PALETTE_OUTPUTS)

# overrides for matching
$(BUILD_DIR)/src/m4a.o: CC1 := $(OLD_CC1)

clean:
	@echo "RM $(ROM) $(ELF) $(MAP) $(BUILD_DIR)"
	@rm -f $(ROM) $(ELF) $(MAP) 
	@rm -rf $(BUILD_DIR)/

.PHONY: clean

# Audit/build-only graphics targets do not need C/C++ dependency discovery.
ifneq (,$(filter gfx-ui-scene-080a2ba4 gfx-ui-scene-080a2ba4-reference gfx-ui-scene-080a2ba4-test gfx-ui-scene-080a2ba4-all gfx-ui-scene-080a2ba4-patch-test gfx-ui-scene-080a2ba4-edit-test gfx-ui-scene-080ae7d0 gfx-ui-scene-080ae7d0-preview gfx-ui-scene-080ae7d0-test gfx-ui-scene-080ae7d0-all gfx-ui-scene-080ae7d0-patch-test gfx-ui-scene-080ae7d0-edit-test gfx-ui-scene-080b7164 gfx-ui-scene-080b7164-preview gfx-ui-scene-080b7164-test gfx-ui-scene-080b7164-all gfx-ui-scene-080b7164-patch-test gfx-ui-scene-080b7164-edit-test gfx-ui-scene-080c160c gfx-ui-scene-080c160c-preview gfx-ui-scene-080c160c-test gfx-ui-scene-080c160c-all gfx-ui-scene-080c160c-patch-test gfx-ui-scene-080c160c-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-ui-scene-080bcfac gfx-ui-scene-080bcfac-preview gfx-ui-scene-080bcfac-test gfx-ui-scene-080bcfac-all gfx-ui-scene-080bcfac-patch-test gfx-ui-scene-080bcfac-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-ui-scene-080b55d0-aux gfx-ui-scene-080b55d0-aux-reference gfx-ui-scene-080b55d0-aux-test gfx-ui-scene-080b55d0-aux-all gfx-ui-scene-080b55d0-aux-patch-test gfx-ui-scene-080b55d0-aux-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-raw-vram-tiles-08697920 gfx-raw-vram-tiles-08697920-test gfx-raw-vram-tiles-08697920-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-farm-status-task-ui-tile gfx-farm-status-task-ui-tile-test gfx-farm-status-task-ui-tile-all,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-raw-vram-tiles-08698e14 gfx-raw-vram-tiles-08698e14-test gfx-raw-vram-tiles-08698e14-all gfx-raw-vram-tiles-0869a0a4 gfx-raw-vram-tiles-0869a0a4-test gfx-raw-vram-tiles-0869a0a4-all gfx-raw-vram-tiles-field,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-raw-vram-tiles-086d5508 gfx-raw-vram-tiles-086d5508-test gfx-raw-vram-tiles-086d5508-all gfx-raw-vram-tiles-086d6698 gfx-raw-vram-tiles-086d6698-test gfx-raw-vram-tiles-086d6698-all gfx-raw-vram-tiles-field-leading,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter $(RAW_VRAM_UI_TARGETS) gfx-raw-vram-tiles-ui,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-ui-scene-08054f40-tiles gfx-ui-scene-08054f40-reference gfx-ui-scene-08054f40-tiles-test gfx-ui-scene-08054f40-tiles-all gfx-ui-scene-08054f40-tiles-patch-test gfx-ui-scene-08054f40-tiles-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-ui-scene-0805ab08-tiles gfx-ui-scene-0805ab08-reference gfx-ui-scene-0805ab08-tiles-test gfx-ui-scene-0805ab08-tiles-all gfx-ui-scene-0805ab08-tiles-patch-test gfx-ui-scene-0805ab08-tiles-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-seasonal-nonwinter gfx-seasonal-nonwinter-test gfx-seasonal-nonwinter-all gfx-seasonal-nonwinter-reference gfx-seasonal-nonwinter-edit-test gfx-seasonal-winter gfx-seasonal-winter-test gfx-seasonal-winter-all gfx-seasonal-winter-reference gfx-seasonal-winter-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-intro-indexed-archive gfx-intro-indexed-archive-test gfx-intro-indexed-archive-all gfx-intro-indexed-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-intro-small-archive gfx-intro-small-archive-all gfx-intro-small-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-map-resources-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-farm-status-resource-archive gfx-farm-status-resource-archive-test gfx-farm-status-resource-archive-all gfx-farm-status-resource-archive-patch-test gfx-farm-status-resource-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-small-companion-archive gfx-small-companion-archive-test gfx-small-companion-archive-all gfx-small-companion-archive-patch-test gfx-small-companion-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-small-ui-resource-archive gfx-small-ui-resource-archive-test gfx-small-ui-resource-archive-all gfx-small-ui-resource-archive-patch-test gfx-small-ui-resource-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-cooking-ui-resource-archive gfx-cooking-ui-resource-archive-test gfx-cooking-ui-resource-archive-all gfx-cooking-ui-resource-archive-patch-test gfx-cooking-ui-resource-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-menu-ui-resource-archive gfx-menu-ui-resource-archive-test gfx-menu-ui-resource-archive-all gfx-menu-ui-resource-archive-patch-test gfx-menu-ui-resource-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-large-shared-resource-archive gfx-large-shared-resource-archive-test gfx-large-shared-resource-archive-all gfx-large-shared-resource-archive-patch-test gfx-large-shared-resource-archive-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08725da0 gfx-shared-resource-08725da0-test gfx-shared-resource-08725da0-all gfx-shared-resource-08725da0-patch-test gfx-shared-resource-08725da0-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-086f2fac gfx-shared-resource-086f2fac-test gfx-shared-resource-086f2fac-all gfx-shared-resource-086f2fac-patch-test gfx-shared-resource-086f2fac-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-086faa80 gfx-shared-resource-086faa80-test gfx-shared-resource-086faa80-all gfx-shared-resource-086faa80-patch-test gfx-shared-resource-086faa80-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0871ecac gfx-shared-resource-0871ecac-test gfx-shared-resource-0871ecac-all gfx-shared-resource-0871ecac-patch-test gfx-shared-resource-0871ecac-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0871edd4 gfx-shared-resource-0871edd4-test gfx-shared-resource-0871edd4-all gfx-shared-resource-0871edd4-patch-test gfx-shared-resource-0871edd4-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif
ifneq (,$(filter gfx-shared-resource-08527094 gfx-shared-resource-08527094-test gfx-shared-resource-08527094-all gfx-shared-resource-08527094-patch-test gfx-shared-resource-08527094-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08726ccc gfx-shared-resource-08726ccc-test gfx-shared-resource-08726ccc-all gfx-shared-resource-08726ccc-patch-test gfx-shared-resource-08726ccc-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08727368 gfx-shared-resource-08727368-test gfx-shared-resource-08727368-all gfx-shared-resource-08727368-patch-test gfx-shared-resource-08727368-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08727a74 gfx-shared-resource-08727a74-test gfx-shared-resource-08727a74-all gfx-shared-resource-08727a74-patch-test gfx-shared-resource-08727a74-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08728320 gfx-shared-resource-08728320-test gfx-shared-resource-08728320-all gfx-shared-resource-08728320-patch-test gfx-shared-resource-08728320-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0872937c gfx-shared-resource-0872937c-test gfx-shared-resource-0872937c-all gfx-shared-resource-0872937c-patch-test gfx-shared-resource-0872937c-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08729460 gfx-shared-resource-08729460-test gfx-shared-resource-08729460-all gfx-shared-resource-08729460-patch-test gfx-shared-resource-08729460-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0872ee78 gfx-shared-resource-0872ee78-test gfx-shared-resource-0872ee78-all gfx-shared-resource-0872ee78-patch-test gfx-shared-resource-0872ee78-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08731b40 gfx-shared-resource-08731b40-test gfx-shared-resource-08731b40-all gfx-shared-resource-08731b40-patch-test gfx-shared-resource-08731b40-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873ae54 gfx-shared-resource-0873ae54-test gfx-shared-resource-0873ae54-all gfx-shared-resource-0873ae54-patch-test gfx-shared-resource-0873ae54-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873afc8 gfx-shared-resource-0873afc8-test gfx-shared-resource-0873afc8-all gfx-shared-resource-0873afc8-patch-test gfx-shared-resource-0873afc8-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873ccb4 gfx-shared-resource-0873ccb4-test gfx-shared-resource-0873ccb4-all gfx-shared-resource-0873ccb4-patch-test gfx-shared-resource-0873ccb4-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873ceac gfx-shared-resource-0873ceac-test gfx-shared-resource-0873ceac-all gfx-shared-resource-0873ceac-patch-test gfx-shared-resource-0873ceac-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873cf90 gfx-shared-resource-0873cf90-test gfx-shared-resource-0873cf90-all gfx-shared-resource-0873cf90-patch-test gfx-shared-resource-0873cf90-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873d234 gfx-shared-resource-0873d234-test gfx-shared-resource-0873d234-all gfx-shared-resource-0873d234-patch-test gfx-shared-resource-0873d234-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873d5fc gfx-shared-resource-0873d5fc-test gfx-shared-resource-0873d5fc-all gfx-shared-resource-0873d5fc-patch-test gfx-shared-resource-0873d5fc-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873de44 gfx-shared-resource-0873de44-test gfx-shared-resource-0873de44-all gfx-shared-resource-0873de44-patch-test gfx-shared-resource-0873de44-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873e5b0 gfx-shared-resource-0873e5b0-test gfx-shared-resource-0873e5b0-all gfx-shared-resource-0873e5b0-patch-test gfx-shared-resource-0873e5b0-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0873ed1c gfx-shared-resource-0873ed1c-test gfx-shared-resource-0873ed1c-all gfx-shared-resource-0873ed1c-patch-test gfx-shared-resource-0873ed1c-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-087401a4 gfx-shared-resource-087401a4-test gfx-shared-resource-087401a4-all gfx-shared-resource-087401a4-patch-test gfx-shared-resource-087401a4-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08740454 gfx-shared-resource-08740454-test gfx-shared-resource-08740454-all gfx-shared-resource-08740454-patch-test gfx-shared-resource-08740454-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-087405a0 gfx-shared-resource-087405a0-test gfx-shared-resource-087405a0-all gfx-shared-resource-087405a0-patch-test gfx-shared-resource-087405a0-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08740908 gfx-shared-resource-08740908-test gfx-shared-resource-08740908-all gfx-shared-resource-08740908-patch-test gfx-shared-resource-08740908-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-087409e4 gfx-shared-resource-087409e4-test gfx-shared-resource-087409e4-all gfx-shared-resource-087409e4-patch-test gfx-shared-resource-087409e4-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0874ee38 gfx-shared-resource-0874ee38-test gfx-shared-resource-0874ee38-all gfx-shared-resource-0874ee38-patch-test gfx-shared-resource-0874ee38-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-087506e0 gfx-shared-resource-087506e0-test gfx-shared-resource-087506e0-all gfx-shared-resource-087506e0-patch-test gfx-shared-resource-087506e0-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-0875352c gfx-shared-resource-0875352c-test gfx-shared-resource-0875352c-all gfx-shared-resource-0875352c-patch-test gfx-shared-resource-0875352c-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08753608 gfx-shared-resource-08753608-test gfx-shared-resource-08753608-all gfx-shared-resource-08753608-patch-test gfx-shared-resource-08753608-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-087536e4 gfx-shared-resource-087536e4-test gfx-shared-resource-087536e4-all gfx-shared-resource-087536e4-patch-test gfx-shared-resource-087536e4-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-shared-resource-08755154 gfx-shared-resource-08755154-test gfx-shared-resource-08755154-all gfx-shared-resource-08755154-patch-test gfx-shared-resource-08755154-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-regional-resource-0875b444 gfx-regional-resource-0875b444-test gfx-regional-resource-0875b444-all gfx-regional-resource-0875b444-patch-test gfx-regional-resource-0875b444-edit-test gfx-regional-resource-0875b444-edit-test-one,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-regional-resource-0871d51c gfx-regional-resource-0871d51c-test gfx-regional-resource-0871d51c-all gfx-regional-resource-0871d51c-patch-test gfx-regional-resource-0871d51c-edit-test gfx-regional-resource-0871d51c-edit-test-one,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-regional-resource-08728208 gfx-regional-resource-08728208-test gfx-regional-resource-08728208-all gfx-regional-resource-08728208-patch-test gfx-regional-resource-08728208-edit-test gfx-regional-resource-08728208-edit-test-one,$(MAKECMDGOALS)))
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

ifneq (,$(filter gfx-farm-house-tilemaps gfx-farm-house-tilemaps-test gfx-farm-house-tilemaps-all gfx-farm-house-tilemaps-patch-test gfx-farm-house-tilemaps-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (,$(filter gfx-portraits gfx-portraits-test gfx-portraits-all gfx-portraits-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (clean,$(MAKECMDGOALS))
ifeq (unpack-coverage-inventory,$(strip $(MAKECMDGOALS)))
# This target needs only the Python audit tool, never the default ROM build.
else
ifeq (,$(filter fomt_us fomt_jp fomt_eu fomt_de compare compare_eu compare_de gfx-font gfx-jp-font gfx-fonts gfx-font-test gfx-fonts-test gfx-portraits gfx-portraits-all gfx-actors gfx-actors-test gfx-actors-all gfx-actors-edit-test gfx-ui gfx-ui-test gfx-ui-all gfx-ui-scene-080a2ba4 gfx-ui-scene-080a2ba4-test gfx-ui-scene-080a2ba4-all gfx-ui-scene-080a2ba4-patch-test gfx-ui-scene-080a2ba4-edit-test gfx-ui-scene-08077810 gfx-ui-scene-08077810-reference gfx-ui-scene-08077810-test gfx-ui-scene-08077810-all gfx-ui-scene-08077810-patch-test gfx-ui-scene-08077810-edit-test gfx-ui-scene-080ae7d0 gfx-ui-scene-080ae7d0-preview gfx-ui-scene-080ae7d0-test gfx-ui-scene-080ae7d0-all gfx-ui-scene-080ae7d0-patch-test gfx-ui-scene-080ae7d0-edit-test gfx-ui-scene-080b7164 gfx-ui-scene-080b7164-preview gfx-ui-scene-080b7164-test gfx-ui-scene-080b7164-all gfx-ui-scene-080b7164-patch-test gfx-ui-scene-080b7164-edit-test gfx-ui-scene-080c160c gfx-ui-scene-080c160c-test gfx-ui-scene-080c160c-all gfx-ui-scene-080c160c-patch-test gfx-ui-scene-080c160c-edit-test gfx-ui-scene-080b55d0-aux gfx-ui-scene-080b55d0-aux-reference gfx-ui-scene-080b55d0-aux-test gfx-ui-scene-080b55d0-aux-all gfx-ui-scene-080b55d0-aux-patch-test gfx-ui-scene-080b55d0-aux-edit-test gfx-ui-scene-080b55d0-main gfx-ui-scene-080b55d0-main-test gfx-ui-scene-080b55d0-main-all gfx-ui-scene-080b55d0-main-patch-test gfx-ui-scene-080b55d0-main-edit-test gfx-ui-scene-08054f40-reference gfx-farm-house-tilemaps gfx-farm-house-tilemaps-test gfx-farm-house-tilemaps-all gfx-farm-house-tilemaps-patch-test gfx-farm-house-tilemaps-edit-test gfx-farm-status gfx-farm-status-test gfx-farm-status-all gfx-farm-status-edit-test gfx-farm-status-winter gfx-farm-status-winter-test gfx-farm-status-winter-all gfx-farm-status-winter-edit-test gfx-farm-status-previews gfx-farm-status-tilemaps gfx-farm-status-tilemaps-test gfx-farm-status-tilemaps-all gfx-farm-status-secondary-tilemaps gfx-farm-status-secondary-tilemaps-test gfx-farm-status-secondary-tilemaps-all gfx-farm-status-secondary-tilemaps-edit-test gfx-farm-status-exterior-styles gfx-farm-status-exterior-styles-test gfx-farm-status-exterior-styles-all gfx-farm-status-exterior-styles-edit-test gfx-farm-status-selector-icon gfx-farm-status-selector-icon-test gfx-farm-status-selector-icon-all gfx-farm-status-selector-icon-edit-test gfx-clock-font gfx-clock-font-test gfx-clock-font-all gfx-clock-font-edit-test gfx-farm-status-creature-icons gfx-farm-status-creature-icons-test gfx-farm-status-creature-icons-all gfx-intro-background gfx-intro-background-test gfx-intro-background-all gfx-intro-background-edit-test gfx-intro-objects gfx-intro-objects-all gfx-intro-objects-test gfx-intro-objects-edit-test gfx-intro-startup-visual gfx-intro-startup-visual-export gfx-intro-startup-visual-reference gfx-intro-startup-visual-test gfx-intro-startup-visual-all gfx-intro-startup-visual-edit-test gfx-map-resources gfx-map-resources-test gfx-map-resources-all gfx-map-resources-patch-test gfx-records-minigame gfx-records-minigame-test gfx-records-minigame-all resource-archive-audit map-terrain-audit farm-house-lookup-audit unpack-vram-inventory gfx-assets gfx-verify tile-grid-region-test tile-grid-test oam-pack oam-pack-test oam-pack-audit,$(MAKECMDGOALS)))
-include $(ALL_DEPS)
endif
.PRECIOUS: $(BUILD_DIR)/%.d
endif
endif
