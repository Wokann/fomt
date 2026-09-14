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

OLD_CC1  := tools/agbcc/bin/old_agbcc$(EXE)

# Host-side graphics tools.  gbagfx is vendored from pokeemerald under its
# original licence; fontpad only bridges FoMT's 8x12 1bpp glyph records to
# gbagfx's 8x8-tile input without changing the authored PNG workflow.
GFX_TOOL_DIR := tools/gbagfx
GFX_TOOL := $(GFX_TOOL_DIR)/gbagfx$(EXE)
FONT_PAD_DIR := tools/fontpad
FONT_PAD := $(FONT_PAD_DIR)/fontpad$(EXE)
OAM_PACK_DIR := tools/oam_pack
OAM_PACK := $(OAM_PACK_DIR)/oam_pack$(EXE)
.PHONY: $(GFX_TOOL) $(FONT_PAD) $(OAM_PACK)

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

# Both font streams are physically identical in all four retail FoMT
# localizations. Native records have twelve active rows and are padded only
# for gbagfx's 8x8 tile conversion.
FONT_SHARED_SINGLE_PNG := graphics/font/shared/single_width_font.png
FONT_SHARED_SINGLE_PADDED := $(BUILD_DIR)/graphics/font/shared/single_width_font.padded.1bpp
FONT_SHARED_SINGLE_BIN := $(BUILD_DIR)/graphics/font/shared/single_width_font.1bpp
FONT_SHARED_DOUBLE_PNG := graphics/font/shared/double_width_font.png
FONT_SHARED_DOUBLE_PADDED := $(BUILD_DIR)/graphics/font/shared/double_width_font.padded.1bpp
FONT_SHARED_DOUBLE_BIN := $(BUILD_DIR)/graphics/font/shared/double_width_font.1bpp

# The dialogue-portrait archive has a shared tile/OAM/palette layout in every
# retail localization. Full portraits are the normal palette-indexed authoring
# source; portrait_archive.py patches only their visible changes into table
# four and detects shared-tile conflicts. Per-descriptor tile groups remain as
# an advanced exact-edit fallback.
PORTRAIT_SOURCE_DIR := graphics/portraits/shared
PORTRAIT_FULL_IMAGES := $(wildcard $(PORTRAIT_SOURCE_DIR)/full/*.png)
PORTRAIT_ARCHIVE_TOOL := tools/portrait_archive.py
PORTRAIT_TILE_BIN := $(BUILD_DIR)/graphics/portraits/shared/portrait_tiles.4bpp
PORTRAIT_ARCHIVE_LENGTH := 0x5E0A4
PORTRAIT_ARCHIVE_SHA256 := 34c23aced1a4f23ba80d1429a87f4c8a7ca11b0458c61a37a6eb48731440bbd2
PORTRAIT_ARCHIVE_OFFSET_JP := 0x2B3AE0
PORTRAIT_ARCHIVE_OFFSET_US := 0x52D984
PORTRAIT_ARCHIVE_OFFSET_EU := 0x52D9E0
PORTRAIT_ARCHIVE_OFFSET_DE := 0x2B4A20
PORTRAIT_ARCHIVE_OFFSET := $(PORTRAIT_ARCHIVE_OFFSET_$(GAME_REGION))

# Rick's daily overworld animation is a fixed six-tile frame class: a 16x16
# upper body followed by a centred 8x16 lower strip. The 26 full PNG frames
# and their native 4bpp/BGR555 rebuild are shared byte-for-byte by all four
# retail localizations, although each ROM stores the data elsewhere.
OVERWORLD_SPRITE_TOOL := tools/overworld_sprite.py
OVERWORLD_RICK_SOURCE_DIR := graphics/sprites/rick_daily/shared/frames
OVERWORLD_RICK_FRAMES := $(wildcard $(OVERWORLD_RICK_SOURCE_DIR)/*.png)
OVERWORLD_RICK_TILE_BIN := $(BUILD_DIR)/graphics/sprites/rick_daily/rick_daily.4bpp
OVERWORLD_RICK_PALETTE_BIN := $(BUILD_DIR)/graphics/sprites/rick_daily/rick_daily.gbapal
OVERWORLD_RICK_BUILD_STAMP := $(BUILD_DIR)/graphics/sprites/rick_daily/.build.stamp
OVERWORLD_RICK_TILE_SHA256 := a3b557ebe746ce6b2a7d1f5d0ea522837a99283c2dd05879f787dba2c733bf71
OVERWORLD_RICK_TILE_OFFSET_JP := 0x380898
OVERWORLD_RICK_TILE_OFFSET_US := 0x5FA73C
OVERWORLD_RICK_TILE_OFFSET_EU := 0x5FA798
OVERWORLD_RICK_TILE_OFFSET_DE := 0x3817D8
OVERWORLD_RICK_PALETTE_OFFSET_JP := 0x3E859C
OVERWORLD_RICK_PALETTE_OFFSET_US := 0x662440
OVERWORLD_RICK_PALETTE_OFFSET_EU := 0x66249C
OVERWORLD_RICK_PALETTE_OFFSET_DE := 0x3E94DC
OVERWORLD_RICK_TILE_OFFSET := $(OVERWORLD_RICK_TILE_OFFSET_$(GAME_REGION))
OVERWORLD_RICK_PALETTE_OFFSET := $(OVERWORLD_RICK_PALETTE_OFFSET_$(GAME_REGION))

OVERWORLD_RICK_WEDDING_SOURCE_DIR := graphics/sprites/rick_wedding/shared/frames
OVERWORLD_RICK_WEDDING_FRAMES := $(wildcard $(OVERWORLD_RICK_WEDDING_SOURCE_DIR)/*.png)
OVERWORLD_RICK_WEDDING_TILE_BIN := $(BUILD_DIR)/graphics/sprites/rick_wedding/rick_wedding.4bpp
OVERWORLD_RICK_WEDDING_PALETTE_BIN := $(BUILD_DIR)/graphics/sprites/rick_wedding/rick_wedding.gbapal
OVERWORLD_RICK_WEDDING_BUILD_STAMP := $(BUILD_DIR)/graphics/sprites/rick_wedding/.build.stamp
OVERWORLD_RICK_WEDDING_TILE_SHA256 := 2288b1caca41144453cc9c73fe9ee209cb356345f4f462fb961f0858300b0d8c
OVERWORLD_RICK_WEDDING_TILE_OFFSET_JP := 0x381C18
OVERWORLD_RICK_WEDDING_TILE_OFFSET_US := 0x5FBABC
OVERWORLD_RICK_WEDDING_TILE_OFFSET_EU := 0x5FBB18
OVERWORLD_RICK_WEDDING_TILE_OFFSET_DE := 0x382B58
OVERWORLD_RICK_WEDDING_PALETTE_OFFSET_JP := 0x3E85BC
OVERWORLD_RICK_WEDDING_PALETTE_OFFSET_US := 0x662460
OVERWORLD_RICK_WEDDING_PALETTE_OFFSET_EU := 0x6624BC
OVERWORLD_RICK_WEDDING_PALETTE_OFFSET_DE := 0x3E94FC
OVERWORLD_RICK_WEDDING_TILE_OFFSET := $(OVERWORLD_RICK_WEDDING_TILE_OFFSET_$(GAME_REGION))
OVERWORLD_RICK_WEDDING_PALETTE_OFFSET := $(OVERWORLD_RICK_WEDDING_PALETTE_OFFSET_$(GAME_REGION))

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

$(GFX_TOOL):
	@$(MAKE) -C $(GFX_TOOL_DIR)

$(FONT_PAD): $(FONT_PAD_DIR)/fontpad.c $(FONT_PAD_DIR)/Makefile
	@$(MAKE) -C $(FONT_PAD_DIR)

$(OAM_PACK): $(OAM_PACK_DIR)/oam_pack.c $(OAM_PACK_DIR)/Makefile
	@$(MAKE) -C $(OAM_PACK_DIR)

$(FONT_SHARED_SINGLE_PADDED): $(FONT_SHARED_SINGLE_PNG) $(GFX_TOOL)
	@mkdir -p $(dir $@)
	@$(GFX_TOOL) $< $@

$(FONT_SHARED_SINGLE_BIN): $(FONT_SHARED_SINGLE_PADDED) $(FONT_PAD)
	@mkdir -p $(dir $@)
	@$(FONT_PAD) trim-grid-12-from-16 $< $@ 16 487

$(FONT_SHARED_DOUBLE_PADDED): $(FONT_SHARED_DOUBLE_PNG) $(GFX_TOOL)
	@mkdir -p $(dir $@)
	@$(GFX_TOOL) $< $@

$(FONT_SHARED_DOUBLE_BIN): $(FONT_SHARED_DOUBLE_PADDED) $(FONT_PAD)
	@mkdir -p $(dir $@)
	@$(FONT_PAD) trim-grid-16x12-from-16x16 $< $@ 32 6922

$(PORTRAIT_TILE_BIN): $(PORTRAIT_ARCHIVE_TOOL) $(PORTRAIT_FULL_IMAGES) $(BASE_ROM)
	@mkdir -p $(dir $@)
	@$(PYTHON) $(PORTRAIT_ARCHIVE_TOOL) $(BASE_ROM) --offset $(PORTRAIT_ARCHIVE_OFFSET) --length $(PORTRAIT_ARCHIVE_LENGTH) --sha256 $(PORTRAIT_ARCHIVE_SHA256) rebuild-full --source $(PORTRAIT_SOURCE_DIR) --output $@

$(OVERWORLD_RICK_BUILD_STAMP): $(OVERWORLD_SPRITE_TOOL) $(OVERWORLD_RICK_FRAMES)
	@mkdir -p $(dir $@)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) build --source $(OVERWORLD_RICK_SOURCE_DIR) --tiles $(OVERWORLD_RICK_TILE_BIN) --palette $(OVERWORLD_RICK_PALETTE_BIN)
	@touch $@

$(OVERWORLD_RICK_TILE_BIN) $(OVERWORLD_RICK_PALETTE_BIN): $(OVERWORLD_RICK_BUILD_STAMP)

$(OVERWORLD_RICK_WEDDING_BUILD_STAMP): $(OVERWORLD_SPRITE_TOOL) $(OVERWORLD_RICK_WEDDING_FRAMES)
	@mkdir -p $(dir $@)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) build --source $(OVERWORLD_RICK_WEDDING_SOURCE_DIR) --tiles $(OVERWORLD_RICK_WEDDING_TILE_BIN) --palette $(OVERWORLD_RICK_WEDDING_PALETTE_BIN)
	@touch $@

$(OVERWORLD_RICK_WEDDING_TILE_BIN) $(OVERWORLD_RICK_WEDDING_PALETTE_BIN): $(OVERWORLD_RICK_WEDDING_BUILD_STAMP)

FONT_REGION_DOUBLE_BIN := $(FONT_SHARED_DOUBLE_BIN)

# Rebuild the active localization's verified font payloads without causing GNU
# make to update every optional assembler dependency file in a fresh worktree.
.PHONY: gfx-font gfx-jp-font gfx-fonts gfx-portraits gfx-portraits-all gfx-overworld-rick gfx-overworld-rick-test gfx-overworld-rick-all gfx-assets oam-pack oam-pack-test
oam-pack: $(OAM_PACK)
oam-pack-test: $(OAM_PACK) baserom_jp.gba baserom_us.gba baserom_eu.gba baserom_de.gba $(PORTRAIT_SOURCE_DIR)/full/000_TALK_PORTRAIT_RICK_NORMAL.png
	@mkdir -p $(BUILD_DIR)/graphics/oam_pack
	@for reference in \
	  "baserom_jp.gba $(PORTRAIT_ARCHIVE_OFFSET_JP)" \
	  "baserom_us.gba $(PORTRAIT_ARCHIVE_OFFSET_US)" \
	  "baserom_eu.gba $(PORTRAIT_ARCHIVE_OFFSET_EU)" \
	  "baserom_de.gba $(PORTRAIT_ARCHIVE_OFFSET_DE)"; do \
	  set -- $$reference; \
	  $(OAM_PACK) $(PORTRAIT_SOURCE_DIR)/full/000_TALK_PORTRAIT_RICK_NORMAL.png \
	    --tiles $(BUILD_DIR)/graphics/oam_pack/rick_normal.4bpp \
	    --palette $(BUILD_DIR)/graphics/oam_pack/rick_normal.gbapal \
	    --oam $(BUILD_DIR)/graphics/oam_pack/rick_normal.oam \
	    --origin-x -24 --origin-y -72 --strategy canvas \
	    --reference-rom $$1 --reference-offset $$2 --portrait-id 0; \
	done
gfx-font: $(FONT_SHARED_SINGLE_BIN) $(FONT_REGION_DOUBLE_BIN)
gfx-jp-font: gfx-font
gfx-fonts:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-font
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-font
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-font
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-font
gfx-portraits: $(PORTRAIT_TILE_BIN)
gfx-portraits-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-portraits
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-portraits
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-portraits
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-portraits
gfx-overworld-rick: $(OVERWORLD_RICK_TILE_BIN) $(OVERWORLD_RICK_PALETTE_BIN) $(OVERWORLD_RICK_WEDDING_TILE_BIN) $(OVERWORLD_RICK_WEDDING_PALETTE_BIN)
gfx-overworld-rick-test: gfx-overworld-rick $(BASE_ROM)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) verify $(BASE_ROM) --tiles-offset $(OVERWORLD_RICK_TILE_OFFSET) --palette-offset $(OVERWORLD_RICK_PALETTE_OFFSET) --tiles $(OVERWORLD_RICK_TILE_BIN) --palette $(OVERWORLD_RICK_PALETTE_BIN) --sha256 $(OVERWORLD_RICK_TILE_SHA256)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) verify $(BASE_ROM) --tiles-offset $(OVERWORLD_RICK_WEDDING_TILE_OFFSET) --palette-offset $(OVERWORLD_RICK_WEDDING_PALETTE_OFFSET) --tiles $(OVERWORLD_RICK_WEDDING_TILE_BIN) --palette $(OVERWORLD_RICK_WEDDING_PALETTE_BIN) --sha256 $(OVERWORLD_RICK_WEDDING_TILE_SHA256)
gfx-overworld-rick-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-overworld-rick-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-overworld-rick-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-overworld-rick-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-overworld-rick-test
gfx-assets: gfx-font gfx-portraits gfx-overworld-rick

$(BUILD_DIR)/asm/data/data_0813B288.o: $(FONT_SHARED_SINGLE_BIN) $(FONT_REGION_DOUBLE_BIN) $(PORTRAIT_TILE_BIN) $(OVERWORLD_RICK_TILE_BIN) $(OVERWORLD_RICK_PALETTE_BIN) $(OVERWORLD_RICK_WEDDING_TILE_BIN) $(OVERWORLD_RICK_WEDDING_PALETTE_BIN)

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

# overrides for matching
$(BUILD_DIR)/src/m4a.o: CC1 := $(OLD_CC1)

clean:
	@echo "RM $(ROM) $(ELF) $(MAP) $(BUILD_DIR)"
	@rm -f $(ROM) $(ELF) $(MAP) 
	@rm -rf $(BUILD_DIR)/

.PHONY: clean

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(filter fomt_us fomt_jp fomt_eu fomt_de compare compare_eu compare_de gfx-font gfx-jp-font gfx-fonts gfx-portraits gfx-portraits-all gfx-overworld-rick gfx-overworld-rick-test gfx-overworld-rick-all gfx-assets oam-pack oam-pack-test,$(MAKECMDGOALS)))
-include $(ALL_DEPS)
endif
.PRECIOUS: $(BUILD_DIR)/%.d
endif
