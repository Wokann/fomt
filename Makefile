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
OAM_PACK_AUDIT := $(OAM_PACK_DIR)/audit_portraits.py
GFX_RANGE_VERIFY := tools/verify_gfx_range.py
TILE_GRID_TOOL := tools/tile_grid.py
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
FONT_SHARED_SINGLE_SHA256 := 92bc2a39dd9caf5e0f02a8ce7518f223eabe6c491bc4e05b8d1d2104f731754c
FONT_SHARED_DOUBLE_SHA256 := bb7ffb1ed47acb9a05d2789eae9f3236945a4892df746c5a4f9f1dde706c4d3e
FONT_SHARED_SINGLE_OFFSET_JP := 0x7515A8
FONT_SHARED_SINGLE_OFFSET_US := 0x4F90CC
FONT_SHARED_SINGLE_OFFSET_EU := 0x4F9128
FONT_SHARED_SINGLE_OFFSET_DE := 0x71DDD4
FONT_SHARED_DOUBLE_OFFSET_JP := 0x752E7C
FONT_SHARED_DOUBLE_OFFSET_US := 0x4FA9A0
FONT_SHARED_DOUBLE_OFFSET_EU := 0x4FA9FC
FONT_SHARED_DOUBLE_OFFSET_DE := 0x71F6A8
FONT_SHARED_SINGLE_OFFSET := $(FONT_SHARED_SINGLE_OFFSET_$(GAME_REGION))
FONT_SHARED_DOUBLE_OFFSET := $(FONT_SHARED_DOUBLE_OFFSET_$(GAME_REGION))

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

# UiSharedResourceData explicitly identifies this 0x120-byte VRAM payload and
# its immediately following 32-byte palette.  It is a simple 24x24 linear
# 4bpp grid, common to every retail localization.
UI_SHARED_RESOURCE_SOURCE := graphics/ui/shared_resource/shared_resource.png
UI_SHARED_RESOURCE_TILE_BIN := $(BUILD_DIR)/graphics/ui/shared_resource/shared_resource.4bpp
UI_SHARED_RESOURCE_PALETTE_BIN := $(BUILD_DIR)/graphics/ui/shared_resource/shared_resource.gbapal
UI_SHARED_RESOURCE_TILE_SHA256 := 0ccf3327b9f4b30e2b1e47d763f56c9a15d8dff94ff3e44c79b8e87c89a8992c
UI_SHARED_RESOURCE_PALETTE_SHA256 := 4c62773b262255ca7aa361ffb127e7d1a36397b9057ab59ff44ba4d5ac357a2c
UI_SHARED_RESOURCE_TILE_OFFSET_JP := 0x4E0BA0
UI_SHARED_RESOURCE_TILE_OFFSET_US := 0x75B818
UI_SHARED_RESOURCE_TILE_OFFSET_EU := 0x75B874
UI_SHARED_RESOURCE_TILE_OFFSET_DE := 0x4E2D34
UI_SHARED_RESOURCE_PALETTE_OFFSET_JP := 0x4E0CC0
UI_SHARED_RESOURCE_PALETTE_OFFSET_US := 0x75B938
UI_SHARED_RESOURCE_PALETTE_OFFSET_EU := 0x75B994
UI_SHARED_RESOURCE_PALETTE_OFFSET_DE := 0x4E2E54
UI_SHARED_RESOURCE_TILE_OFFSET := $(UI_SHARED_RESOURCE_TILE_OFFSET_$(GAME_REGION))
UI_SHARED_RESOURCE_PALETTE_OFFSET := $(UI_SHARED_RESOURCE_PALETTE_OFFSET_$(GAME_REGION))

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
OVERWORLD_RICK_PALETTE_SHA256 := 7023974d0e32aaee06e1da906644414117f4c5745c83e0a6ae73895136282b10
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

# The next adjacent character resources use the exact same fixed six-tile
# frame format as Rick.  Their source frames are shared by every retail
# localization; only the physical ROM ranges differ.  Popuri's baby frames
# intentionally reuse the Popuri daily palette in the native data stream.
OVERWORLD_FIXED_SIX_TILE_ASSETS := popuri_daily popuri_sleeping popuri_baby popuri_wedding lillia_daily
OVERWORLD_FIXED_SIX_TILE_BINS := $(foreach asset,$(OVERWORLD_FIXED_SIX_TILE_ASSETS),$(BUILD_DIR)/graphics/sprites/$(asset)/$(asset).4bpp $(BUILD_DIR)/graphics/sprites/$(asset)/$(asset).gbapal)

define DEFINE_FIXED_SIX_TILE_ASSET
$(BUILD_DIR)/graphics/sprites/$(1)/.build.stamp: $(OVERWORLD_SPRITE_TOOL) $$(wildcard graphics/sprites/$(1)/shared/frames/*.png)
	@mkdir -p $$(dir $$@)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) build --source graphics/sprites/$(1)/shared/frames --tiles $(BUILD_DIR)/graphics/sprites/$(1)/$(1).4bpp --palette $(BUILD_DIR)/graphics/sprites/$(1)/$(1).gbapal
	@touch $$@

$(BUILD_DIR)/graphics/sprites/$(1)/$(1).4bpp $(BUILD_DIR)/graphics/sprites/$(1)/$(1).gbapal: $(BUILD_DIR)/graphics/sprites/$(1)/.build.stamp
endef
$(foreach asset,$(OVERWORLD_FIXED_SIX_TILE_ASSETS),$(eval $(call DEFINE_FIXED_SIX_TILE_ASSET,$(asset))))

OVERWORLD_POPURI_DAILY_TILE_SHA256 := 4e72631235ce49c3c2fa19e88cc683d8ffba919411c59db6354396b1107f7d6e
OVERWORLD_POPURI_SLEEPING_TILE_SHA256 := 7465adbf16179ba88480972cd0f6f955c8f5361c08f967285df79df89dbeee06
OVERWORLD_POPURI_BABY_TILE_SHA256 := 3bbf1d5a752264f56445dfcef307b3b61aec9a5525254fe488831f8d1bd68678
OVERWORLD_POPURI_WEDDING_TILE_SHA256 := 29c1c944edeb26507edd82603792e2c2c5a979a10e9fe3e507be5ae6a3b675f0
OVERWORLD_LILLIA_DAILY_TILE_SHA256 := 70e62a16e4f4df4e77cd13a91d7a6d63e9d0247dd304855f39cc325f3454c703

OVERWORLD_POPURI_DAILY_TILE_OFFSET_JP := 0x382998
OVERWORLD_POPURI_DAILY_TILE_OFFSET_US := 0x5FC83C
OVERWORLD_POPURI_DAILY_TILE_OFFSET_EU := 0x5FC898
OVERWORLD_POPURI_DAILY_TILE_OFFSET_DE := 0x3838D8
OVERWORLD_POPURI_DAILY_PALETTE_OFFSET_JP := 0x3E85DC
OVERWORLD_POPURI_DAILY_PALETTE_OFFSET_US := 0x662480
OVERWORLD_POPURI_DAILY_PALETTE_OFFSET_EU := 0x6624DC
OVERWORLD_POPURI_DAILY_PALETTE_OFFSET_DE := 0x3E951C

OVERWORLD_POPURI_SLEEPING_TILE_OFFSET_JP := 0x383D18
OVERWORLD_POPURI_SLEEPING_TILE_OFFSET_US := 0x5FDBBC
OVERWORLD_POPURI_SLEEPING_TILE_OFFSET_EU := 0x5FDC18
OVERWORLD_POPURI_SLEEPING_TILE_OFFSET_DE := 0x384C58
OVERWORLD_POPURI_SLEEPING_PALETTE_OFFSET_JP := 0x3E85FC
OVERWORLD_POPURI_SLEEPING_PALETTE_OFFSET_US := 0x6624A0
OVERWORLD_POPURI_SLEEPING_PALETTE_OFFSET_EU := 0x6624FC
OVERWORLD_POPURI_SLEEPING_PALETTE_OFFSET_DE := 0x3E953C

OVERWORLD_POPURI_BABY_TILE_OFFSET_JP := 0x384318
OVERWORLD_POPURI_BABY_TILE_OFFSET_US := 0x5FE1BC
OVERWORLD_POPURI_BABY_TILE_OFFSET_EU := 0x5FE218
OVERWORLD_POPURI_BABY_TILE_OFFSET_DE := 0x385258

OVERWORLD_POPURI_WEDDING_TILE_OFFSET_JP := 0x385518
OVERWORLD_POPURI_WEDDING_TILE_OFFSET_US := 0x5FF3BC
OVERWORLD_POPURI_WEDDING_TILE_OFFSET_EU := 0x5FF418
OVERWORLD_POPURI_WEDDING_TILE_OFFSET_DE := 0x386458
OVERWORLD_POPURI_WEDDING_PALETTE_OFFSET_JP := 0x3E861C
OVERWORLD_POPURI_WEDDING_PALETTE_OFFSET_US := 0x6624C0
OVERWORLD_POPURI_WEDDING_PALETTE_OFFSET_EU := 0x66251C
OVERWORLD_POPURI_WEDDING_PALETTE_OFFSET_DE := 0x3E955C

OVERWORLD_LILLIA_DAILY_TILE_OFFSET_JP := 0x386118
OVERWORLD_LILLIA_DAILY_TILE_OFFSET_US := 0x5FFFBC
OVERWORLD_LILLIA_DAILY_TILE_OFFSET_EU := 0x600018
OVERWORLD_LILLIA_DAILY_TILE_OFFSET_DE := 0x387058
OVERWORLD_LILLIA_DAILY_PALETTE_OFFSET_JP := 0x3E863C
OVERWORLD_LILLIA_DAILY_PALETTE_OFFSET_US := 0x6624E0
OVERWORLD_LILLIA_DAILY_PALETTE_OFFSET_EU := 0x66253C
OVERWORLD_LILLIA_DAILY_PALETTE_OFFSET_DE := 0x3E957C

define SELECT_OVERWORLD_OFFSETS
OVERWORLD_$(1)_TILE_OFFSET := $$(OVERWORLD_$(1)_TILE_OFFSET_$$(GAME_REGION))
OVERWORLD_$(1)_PALETTE_OFFSET := $$(OVERWORLD_$(1)_PALETTE_OFFSET_$$(GAME_REGION))
endef
$(foreach asset,POPURI_DAILY POPURI_SLEEPING POPURI_BABY POPURI_WEDDING LILLIA_DAILY,$(eval $(call SELECT_OVERWORLD_OFFSETS,$(asset))))

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

$(UI_SHARED_RESOURCE_TILE_BIN) $(UI_SHARED_RESOURCE_PALETTE_BIN): $(UI_SHARED_RESOURCE_SOURCE) $(TILE_GRID_TOOL)
	@mkdir -p $(dir $(UI_SHARED_RESOURCE_TILE_BIN))
	@$(PYTHON) $(TILE_GRID_TOOL) build --source $(UI_SHARED_RESOURCE_SOURCE) --tiles $(UI_SHARED_RESOURCE_TILE_BIN) --palette $(UI_SHARED_RESOURCE_PALETTE_BIN)

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
.PHONY: gfx-font gfx-jp-font gfx-fonts gfx-font-test gfx-fonts-test gfx-portraits gfx-portraits-all gfx-ui gfx-ui-test gfx-ui-all gfx-overworld-rick gfx-overworld-rick-test gfx-overworld-rick-all gfx-overworld-actors gfx-overworld-actors-test gfx-overworld-actors-all gfx-assets gfx-verify tile-grid-region-test tile-grid-test oam-pack oam-pack-test oam-pack-audit
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
oam-pack-audit: $(OAM_PACK) $(OAM_PACK_AUDIT) baserom_jp.gba $(PORTRAIT_FULL_IMAGES)
	@$(PYTHON) $(OAM_PACK_AUDIT) $(OAM_PACK) baserom_jp.gba \
	  --archive-offset $(PORTRAIT_ARCHIVE_OFFSET_JP) \
	  --source $(PORTRAIT_SOURCE_DIR)/full --output $(BUILD_DIR)/graphics/oam_pack/audit
gfx-font: $(FONT_SHARED_SINGLE_BIN) $(FONT_REGION_DOUBLE_BIN)
gfx-jp-font: gfx-font
gfx-fonts:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-font
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-font
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-font
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-font
gfx-font-test: gfx-font $(BASE_ROM) $(GFX_RANGE_VERIFY)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(FONT_SHARED_SINGLE_OFFSET) --input $(FONT_SHARED_SINGLE_BIN) --sha256 $(FONT_SHARED_SINGLE_SHA256)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(FONT_SHARED_DOUBLE_OFFSET) --input $(FONT_SHARED_DOUBLE_BIN) --sha256 $(FONT_SHARED_DOUBLE_SHA256)
gfx-fonts-test:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-font-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-font-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-font-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-font-test
gfx-portraits: $(PORTRAIT_TILE_BIN)
gfx-portraits-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-portraits
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-portraits
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-portraits
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-portraits
gfx-ui: $(UI_SHARED_RESOURCE_TILE_BIN) $(UI_SHARED_RESOURCE_PALETTE_BIN)
gfx-ui-test: gfx-ui $(BASE_ROM) $(GFX_RANGE_VERIFY)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(UI_SHARED_RESOURCE_TILE_OFFSET) --input $(UI_SHARED_RESOURCE_TILE_BIN) --sha256 $(UI_SHARED_RESOURCE_TILE_SHA256)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(UI_SHARED_RESOURCE_PALETTE_OFFSET) --input $(UI_SHARED_RESOURCE_PALETTE_BIN) --sha256 $(UI_SHARED_RESOURCE_PALETTE_SHA256)
gfx-ui-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-ui-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-ui-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-ui-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-ui-test
gfx-overworld-rick: $(OVERWORLD_RICK_TILE_BIN) $(OVERWORLD_RICK_PALETTE_BIN) $(OVERWORLD_RICK_WEDDING_TILE_BIN) $(OVERWORLD_RICK_WEDDING_PALETTE_BIN)
gfx-overworld-rick-test: gfx-overworld-rick $(BASE_ROM)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) verify $(BASE_ROM) --tiles-offset $(OVERWORLD_RICK_TILE_OFFSET) --palette-offset $(OVERWORLD_RICK_PALETTE_OFFSET) --tiles $(OVERWORLD_RICK_TILE_BIN) --palette $(OVERWORLD_RICK_PALETTE_BIN) --sha256 $(OVERWORLD_RICK_TILE_SHA256)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) verify $(BASE_ROM) --tiles-offset $(OVERWORLD_RICK_WEDDING_TILE_OFFSET) --palette-offset $(OVERWORLD_RICK_WEDDING_PALETTE_OFFSET) --tiles $(OVERWORLD_RICK_WEDDING_TILE_BIN) --palette $(OVERWORLD_RICK_WEDDING_PALETTE_BIN) --sha256 $(OVERWORLD_RICK_WEDDING_TILE_SHA256)
gfx-overworld-rick-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-overworld-rick-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-overworld-rick-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-overworld-rick-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-overworld-rick-test

# Generic linear 4bpp grid regression.  Rick's native stream is intentionally
# viewed here as a 48-pixel-wide tile grid, not as the six-tile authored-frame
# class, so this tests the generic conversion path independently.
TILE_GRID_TEST_DIR := $(BUILD_DIR)/graphics/tile_grid_test
tile-grid-region-test: $(TILE_GRID_TOOL) $(GFX_RANGE_VERIFY) $(BASE_ROM)
	@$(PYTHON) $(TILE_GRID_TOOL) export $(BASE_ROM) --tiles-offset $(OVERWORLD_RICK_TILE_OFFSET) --tiles-length 0x1380 --palette-offset $(OVERWORLD_RICK_PALETTE_OFFSET) --width 48 --sha256 $(OVERWORLD_RICK_TILE_SHA256) --output $(TILE_GRID_TEST_DIR)/rick.png --replace
	@$(PYTHON) $(TILE_GRID_TOOL) build --source $(TILE_GRID_TEST_DIR)/rick.png --tiles $(TILE_GRID_TEST_DIR)/rick.4bpp --palette $(TILE_GRID_TEST_DIR)/rick.gbapal
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(OVERWORLD_RICK_TILE_OFFSET) --input $(TILE_GRID_TEST_DIR)/rick.4bpp --sha256 $(OVERWORLD_RICK_TILE_SHA256)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(OVERWORLD_RICK_PALETTE_OFFSET) --input $(TILE_GRID_TEST_DIR)/rick.gbapal --sha256 $(OVERWORLD_RICK_PALETTE_SHA256)
tile-grid-test:
	@$(MAKE) --no-print-directory GAME_REGION=JP tile-grid-region-test
	@$(MAKE) --no-print-directory GAME_REGION=US tile-grid-region-test
	@$(MAKE) --no-print-directory GAME_REGION=EU tile-grid-region-test
	@$(MAKE) --no-print-directory GAME_REGION=DE tile-grid-region-test

# This target deliberately keeps each source family independently addressable:
# an artist can rebuild Popuri without needing to touch Rick or Lillia.
gfx-overworld-actors: gfx-overworld-rick $(OVERWORLD_FIXED_SIX_TILE_BINS)
gfx-overworld-actors-test: gfx-overworld-actors $(BASE_ROM)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) verify $(BASE_ROM) --tiles-offset $(OVERWORLD_POPURI_DAILY_TILE_OFFSET) --palette-offset $(OVERWORLD_POPURI_DAILY_PALETTE_OFFSET) --tiles $(BUILD_DIR)/graphics/sprites/popuri_daily/popuri_daily.4bpp --palette $(BUILD_DIR)/graphics/sprites/popuri_daily/popuri_daily.gbapal --sha256 $(OVERWORLD_POPURI_DAILY_TILE_SHA256)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) verify $(BASE_ROM) --tiles-offset $(OVERWORLD_POPURI_SLEEPING_TILE_OFFSET) --palette-offset $(OVERWORLD_POPURI_SLEEPING_PALETTE_OFFSET) --tiles $(BUILD_DIR)/graphics/sprites/popuri_sleeping/popuri_sleeping.4bpp --palette $(BUILD_DIR)/graphics/sprites/popuri_sleeping/popuri_sleeping.gbapal --sha256 $(OVERWORLD_POPURI_SLEEPING_TILE_SHA256)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) verify $(BASE_ROM) --tiles-offset $(OVERWORLD_POPURI_BABY_TILE_OFFSET) --palette-offset $(OVERWORLD_POPURI_DAILY_PALETTE_OFFSET) --tiles $(BUILD_DIR)/graphics/sprites/popuri_baby/popuri_baby.4bpp --palette $(BUILD_DIR)/graphics/sprites/popuri_baby/popuri_baby.gbapal --sha256 $(OVERWORLD_POPURI_BABY_TILE_SHA256)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) verify $(BASE_ROM) --tiles-offset $(OVERWORLD_POPURI_WEDDING_TILE_OFFSET) --palette-offset $(OVERWORLD_POPURI_WEDDING_PALETTE_OFFSET) --tiles $(BUILD_DIR)/graphics/sprites/popuri_wedding/popuri_wedding.4bpp --palette $(BUILD_DIR)/graphics/sprites/popuri_wedding/popuri_wedding.gbapal --sha256 $(OVERWORLD_POPURI_WEDDING_TILE_SHA256)
	@$(PYTHON) $(OVERWORLD_SPRITE_TOOL) verify $(BASE_ROM) --tiles-offset $(OVERWORLD_LILLIA_DAILY_TILE_OFFSET) --palette-offset $(OVERWORLD_LILLIA_DAILY_PALETTE_OFFSET) --tiles $(BUILD_DIR)/graphics/sprites/lillia_daily/lillia_daily.4bpp --palette $(BUILD_DIR)/graphics/sprites/lillia_daily/lillia_daily.gbapal --sha256 $(OVERWORLD_LILLIA_DAILY_TILE_SHA256)
gfx-overworld-actors-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-overworld-actors-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-overworld-actors-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-overworld-actors-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-overworld-actors-test
gfx-assets: gfx-font gfx-portraits gfx-ui gfx-overworld-actors

# Full graphics gate for assets that have an authoritative source/rebuild
# path.  It intentionally does not link a ROM: the project-wide link is
# currently blocked independently by non-graphics C sources.
gfx-verify:
	@$(MAKE) --no-print-directory gfx-fonts-test
	@$(MAKE) --no-print-directory gfx-portraits-all
	@$(MAKE) --no-print-directory gfx-ui-all
	@$(MAKE) --no-print-directory gfx-overworld-actors-all
	@$(MAKE) --no-print-directory tile-grid-test
	@$(MAKE) --no-print-directory oam-pack-test
	@$(MAKE) --no-print-directory oam-pack-audit

$(BUILD_DIR)/asm/data/data_0813B288.o: $(FONT_SHARED_SINGLE_BIN) $(FONT_REGION_DOUBLE_BIN) $(PORTRAIT_TILE_BIN) $(UI_SHARED_RESOURCE_TILE_BIN) $(UI_SHARED_RESOURCE_PALETTE_BIN) $(OVERWORLD_RICK_TILE_BIN) $(OVERWORLD_RICK_PALETTE_BIN) $(OVERWORLD_RICK_WEDDING_TILE_BIN) $(OVERWORLD_RICK_WEDDING_PALETTE_BIN) $(OVERWORLD_FIXED_SIX_TILE_BINS)

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
ifeq (,$(filter fomt_us fomt_jp fomt_eu fomt_de compare compare_eu compare_de gfx-font gfx-jp-font gfx-fonts gfx-font-test gfx-fonts-test gfx-portraits gfx-portraits-all gfx-ui gfx-ui-test gfx-ui-all gfx-overworld-rick gfx-overworld-rick-test gfx-overworld-rick-all gfx-overworld-actors gfx-overworld-actors-test gfx-overworld-actors-all gfx-assets gfx-verify tile-grid-region-test tile-grid-test oam-pack oam-pack-test oam-pack-audit,$(MAKECMDGOALS)))
-include $(ALL_DEPS)
endif
.PRECIOUS: $(BUILD_DIR)/%.d
endif
