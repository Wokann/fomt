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

# The actor archive is a separate IndexedResourceArchive whose first table
# selects timed animation frames.  Its source frames are complete
# OAM-composited PNGs, not guessed linear tile sheets.  Rebuild preserves the
# original archive tables and patches only table four's native 4bpp tile data.
ACTOR_ARCHIVE_TOOL := tools/actor_archive.py
ACTOR_ARCHIVE_EDIT_TEST := tools/actor_archive_edit_test.py
ACTOR_SOURCE_DIRS := graphics/sprites/actor_archive
ACTOR_FULL_IMAGES := $(foreach directory,$(ACTOR_SOURCE_DIRS),$(wildcard $(directory)/full/*.png))
# Cover every native actor selector.  The archive exporter resolves selectors
# through the native animation table, producing 2,963 referenced frame
# descriptors; the 46 unreferenced descriptor slots have no game caller and
# therefore are deliberately not treated as authored animation frames.
ACTOR_ANIMATIONS := 0x000-0x9F6
ACTOR_TILE_BIN := $(BUILD_DIR)/graphics/sprites/shared/actor_tiles.4bpp
ACTOR_ARCHIVE_LENGTH := 0xDB638
ACTOR_ARCHIVE_SHA256 := 19a8733e132573478713e9b6e48e9650a702e62516209159787d26f270933736
ACTOR_TILE_SHA256 := 5feee08fb08ead63211d9cc17dfc46c5b7f1722599aad36883c10ef3d18334f6
ACTOR_TILE_OFFSET_JP := 0x329558
ACTOR_TILE_OFFSET_US := 0x5A33FC
ACTOR_TILE_OFFSET_EU := 0x5A3458
ACTOR_TILE_OFFSET_DE := 0x32A498
ACTOR_ARCHIVE_OFFSET_JP := 0x311B84
ACTOR_ARCHIVE_OFFSET_US := 0x58BA28
ACTOR_ARCHIVE_OFFSET_EU := 0x58BA84
ACTOR_ARCHIVE_OFFSET_DE := 0x312AC4
ACTOR_TILE_OFFSET := $(ACTOR_TILE_OFFSET_$(GAME_REGION))
ACTOR_ARCHIVE_OFFSET := $(ACTOR_ARCHIVE_OFFSET_$(GAME_REGION))

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

# Farm-status background tiles are a 16-palette-bank, linear 4bpp grid.  The
# native stream is a shared 0x70/Huffman/LZ payload.  The compressor keeps the
# original packed bytes when the editable PNG has not changed; edited tiles
# are strictly decompressed and must still fit the original 0x21C4-byte slot.
FARM_STATUS_TILES_SOURCE := graphics/ui/farm_status/shared/base_tiles.png
FARM_STATUS_PALETTE_SOURCE := graphics/ui/farm_status/shared/base_palettes.png
FARM_STATUS_TILES_BIN := $(BUILD_DIR)/graphics/ui/farm_status/base_tiles.4bpp
FARM_STATUS_PALETTE_BIN := $(BUILD_DIR)/graphics/ui/farm_status/base_tiles.gbapal
FARM_STATUS_PACKED_BIN := $(BUILD_DIR)/graphics/ui/farm_status/base_tiles.0x70
FARM_STATUS_CODEC := tools/marvelous_codec.py
FARM_STATUS_PALETTE_TOOL := tools/palette_banks.py
FARM_STATUS_PREVIEW_TOOL := tools/farm_status_previews.py
FARM_STATUS_TILEMAP_TOOL := tools/farm_status_tilemaps.py
FARM_STATUS_REFERENCE_DIR := graphics/ui/farm_status/reference
FARM_STATUS_TILEMAP_SOURCE_DIR := graphics/ui/farm_status/shared/tilemaps
FARM_STATUS_TILEMAP_SOURCES := $(wildcard $(FARM_STATUS_TILEMAP_SOURCE_DIR)/*.tilemap)
FARM_STATUS_TILEMAP_BIN := $(BUILD_DIR)/graphics/ui/farm_status/preview_tilemaps.bin
FARM_STATUS_SECONDARY_TILEMAP_TOOL := tools/farm_status_secondary_tilemaps.py
FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR := graphics/ui/farm_status/shared/secondary_tilemaps
FARM_STATUS_SECONDARY_TILEMAP_SOURCES := $(wildcard $(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/*.tilemap)
FARM_STATUS_SECONDARY_TILEMAP_OUTPUT_DIR := $(BUILD_DIR)/graphics/ui/farm_status/secondary_tilemaps
FARM_STATUS_SECONDARY_TILEMAP_STAMP := $(FARM_STATUS_SECONDARY_TILEMAP_OUTPUT_DIR)/.secondary-tilemaps.stamp
FARM_STATUS_SECONDARY_TILEMAP_REGION := $(shell echo "$(GAME_REGION)" | tr '[:upper:]' '[:lower:]')
FARM_STATUS_STREAM_LENGTH := 0x21C4
FARM_STATUS_STREAM_SHA256 := 669dec9d78bbe0d2ceb08383495eea9da863086b00c7dbd4687d90e5c01cddc5
FARM_STATUS_TILES_SHA256 := 0039e4aa2bb252d5ae17cb2028406e47a79c4461990ad6c1e7e384a962b719e8
FARM_STATUS_PALETTE_SHA256 := 8d2885512b1f0a453e45d632c61a41be90d978f8614aa07109202a955da61303
FARM_STATUS_STREAM_OFFSET_JP := 0x2AD72C
FARM_STATUS_STREAM_OFFSET_US := 0x5275D0
FARM_STATUS_STREAM_OFFSET_EU := 0x52762C
FARM_STATUS_STREAM_OFFSET_DE := 0x2AE66C
FARM_STATUS_PALETTE_OFFSET_JP := 0x2AF8F0
FARM_STATUS_PALETTE_OFFSET_US := 0x529794
FARM_STATUS_PALETTE_OFFSET_EU := 0x5297F0
FARM_STATUS_PALETTE_OFFSET_DE := 0x2B0830
FARM_STATUS_STREAM_OFFSET := $(FARM_STATUS_STREAM_OFFSET_$(GAME_REGION))
FARM_STATUS_PALETTE_OFFSET := $(FARM_STATUS_PALETTE_OFFSET_$(GAME_REGION))

# Intro Scene loading sends this 0x70 output straight to VRAM. The decoded
# 0x6E00-byte resource is a 40-by-22 linear 4bpp tile image (320 by 176
# pixels) and the immediately following 0x60 bytes are three palette banks.
# The stream and palette are byte-identical in JP, US, EU and DE.
INTRO_BACKGROUND_TILES_SOURCE := graphics/intro_scene/shared/background_tiles.png
INTRO_BACKGROUND_PALETTE_SOURCE := graphics/intro_scene/shared/background_palettes.png
INTRO_BACKGROUND_TILES_BIN := $(BUILD_DIR)/graphics/intro_scene/background_tiles.4bpp
INTRO_BACKGROUND_PALETTE_BIN := $(BUILD_DIR)/graphics/intro_scene/background_palettes.gbapal
INTRO_BACKGROUND_PACKED_BIN := $(BUILD_DIR)/graphics/intro_scene/background_tiles.0x70
INTRO_BACKGROUND_STREAM_LENGTH := 0x49BC
INTRO_BACKGROUND_STREAM_SHA256 := f0c828f16cafc75c3b277841bca74d1b7f62bbdf3551c9b591103c0f46213d4f
INTRO_BACKGROUND_TILES_SHA256 := ee0ea9e581dab0baad7a55f2eed3c44dbc63518a2a5b8da5f79d4ef03d0b91c7
INTRO_BACKGROUND_PALETTE_SHA256 := 9d372a163a837204d61a996f95b8f894912cd6d7e4f49342fd07b810c2751d8e
INTRO_BACKGROUND_STREAM_OFFSET_JP := 0x4C91C0
INTRO_BACKGROUND_STREAM_OFFSET_US := 0x743058
INTRO_BACKGROUND_STREAM_OFFSET_EU := 0x7430B4
INTRO_BACKGROUND_STREAM_OFFSET_DE := 0x4CA4CC
INTRO_BACKGROUND_PALETTE_OFFSET_JP := 0x4CDB7C
INTRO_BACKGROUND_PALETTE_OFFSET_US := 0x747A14
INTRO_BACKGROUND_PALETTE_OFFSET_EU := 0x747A70
INTRO_BACKGROUND_PALETTE_OFFSET_DE := 0x4CEE88
INTRO_BACKGROUND_STREAM_OFFSET := $(INTRO_BACKGROUND_STREAM_OFFSET_$(GAME_REGION))
INTRO_BACKGROUND_PALETTE_OFFSET := $(INTRO_BACKGROUND_PALETTE_OFFSET_$(GAME_REGION))

# Intro Scene object tiles are twenty independently packed, byte-identical
# Raw-LZ streams.  Their 0x500-byte decoded sources preserve native tile
# order; OAM composition is deliberately kept separate until it is proven.
INTRO_OBJECTS_TOOL := tools/intro_scene_objects.py
INTRO_OBJECTS_SOURCE_DIR := graphics/intro_scene/shared/object_tiles
INTRO_OBJECTS := 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19
INTRO_OBJECTS_SOURCES := $(foreach object,$(INTRO_OBJECTS),$(INTRO_OBJECTS_SOURCE_DIR)/object_$(object).4bpp)
INTRO_OBJECTS_OUTPUT_DIR := $(BUILD_DIR)/graphics/intro_scene/objects
INTRO_OBJECTS_OUTPUTS := $(foreach object,$(INTRO_OBJECTS),$(INTRO_OBJECTS_OUTPUT_DIR)/object_$(object).0x70)
INTRO_OBJECTS_STAMP := $(INTRO_OBJECTS_OUTPUT_DIR)/.objects.stamp
INTRO_OBJECTS_REGION := $(shell echo "$(GAME_REGION)" | tr '[:upper:]' '[:lower:]')

# The earlier Intro Scene setup function creates two interleaved 32-by-32 BG
# tilemaps from each 0x1000-byte Huffman-4/LZ3 source.  Keep the native
# interleaving as editable source until the compositor's palette/layout rules
# are proven.
INTRO_STARTUP_TILEMAPS_TOOL := tools/intro_scene_startup_tilemaps.py
INTRO_STARTUP_TILEMAPS_SOURCE_DIR := graphics/intro_scene/shared/startup_tilemaps
INTRO_STARTUP_TILEMAPS := 00 01 02 03
INTRO_STARTUP_TILEMAPS_SOURCES := $(foreach map,$(INTRO_STARTUP_TILEMAPS),$(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/startup_$(map).tilemap)
INTRO_STARTUP_TILEMAPS_OUTPUT_DIR := $(BUILD_DIR)/graphics/intro_scene/startup_tilemaps
INTRO_STARTUP_TILEMAPS_OUTPUTS := $(foreach map,$(INTRO_STARTUP_TILEMAPS),$(INTRO_STARTUP_TILEMAPS_OUTPUT_DIR)/startup_$(map).0x70)
INTRO_STARTUP_TILEMAPS_STAMP := $(INTRO_STARTUP_TILEMAPS_OUTPUT_DIR)/.startup-tilemaps.stamp
INTRO_STARTUP_TILEMAPS_REGION := $(INTRO_OBJECTS_REGION)

# func_080A2BA4 loads three 32-by-20 BG tilemaps and one 160-tile 4bpp
# character stream into fixed VRAM locations. Its adjacent palette bytes are
# also part of an indexed archive, so native tile/tilemap sources are kept
# without inventing an unproven coloured composite.
UI_SCENE_080A2BA4_TOOL := tools/ui_scene_080a2ba4.py
UI_SCENE_080A2BA4_SOURCE_DIR := graphics/ui/scene_080a2ba4/shared
UI_SCENE_080A2BA4_SOURCES := $(wildcard $(UI_SCENE_080A2BA4_SOURCE_DIR)/*)
UI_SCENE_080A2BA4_OUTPUT_DIR := $(BUILD_DIR)/graphics/ui/scene_080a2ba4
UI_SCENE_080A2BA4_STAMP := $(UI_SCENE_080A2BA4_OUTPUT_DIR)/.scene-080a2ba4.stamp
UI_SCENE_080A2BA4_REGION := $(INTRO_OBJECTS_REGION)

# MapData owns 66 six-layer map records.  This initial pipeline exports every
# unique retail visual stream as native decoded source and rebuilds it without
# changing packed bytes.  A changed source is intentionally rejected until the
# exact Marvelous encoder for that stream's format has been proven.
MAP_RESOURCES_TOOL := tools/map_resources.py
MAP_RESOURCES_SOURCE_DIR := graphics/maps/shared
MAP_RESOURCES_SOURCES := $(wildcard $(MAP_RESOURCES_SOURCE_DIR)/*/*)
MAP_RESOURCES_OUTPUT_DIR := $(BUILD_DIR)/graphics/maps
MAP_RESOURCES_STAMP := $(MAP_RESOURCES_OUTPUT_DIR)/.map-resources.stamp
MAP_RESOURCES_REGION := $(INTRO_OBJECTS_REGION)
MAP_RESOURCES_ALL_ROM_ARGS := --all-rom jp baserom_jp.gba --all-rom us baserom_us.gba --all-rom eu baserom_eu.gba --all-rom de baserom_de.gba
MAP_RESOURCES_ROM_ARGS := --rom jp baserom_jp.gba --rom us baserom_us.gba --rom eu baserom_eu.gba --rom de baserom_de.gba
INDEXED_RESOURCE_ARCHIVE_TOOL := tools/indexed_resource_archive.py
UNPACK_VRAM_INVENTORY_TOOL := tools/unpack_vram_inventory.py

# The Records Screen uses seven independently selected, raw 16x16 4bpp task
# icons.  Each source PNG retains the physical icon's own 16-colour BGR555
# palette; the C++ pointer table determines presentation order at runtime.
RECORDS_MINIGAME_SOURCE_DIR := graphics/ui/records_minigame/shared
RECORDS_MINIGAME_TOOL := tools/records_minigame_resources.py
RECORDS_MINIGAME_TASKS := 00 01 02 03 04 05 06
RECORDS_MINIGAME_SOURCES := $(foreach task,$(RECORDS_MINIGAME_TASKS),$(RECORDS_MINIGAME_SOURCE_DIR)/task_$(task).png)
RECORDS_MINIGAME_OUTPUT_DIR := $(BUILD_DIR)/graphics/ui/records_minigame
RECORDS_MINIGAME_TILES_BIN := $(foreach task,$(RECORDS_MINIGAME_TASKS),$(RECORDS_MINIGAME_OUTPUT_DIR)/task_$(task).4bpp)
RECORDS_MINIGAME_PALETTE_BIN := $(foreach task,$(RECORDS_MINIGAME_TASKS),$(RECORDS_MINIGAME_OUTPUT_DIR)/task_$(task).gbapal)
RECORDS_MINIGAME_OUTPUTS := $(RECORDS_MINIGAME_TILES_BIN) $(RECORDS_MINIGAME_PALETTE_BIN)

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

$(GFX_TOOL): $(GFX_TOOL_SOURCES)
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

$(ACTOR_TILE_BIN): $(ACTOR_ARCHIVE_TOOL) $(PORTRAIT_ARCHIVE_TOOL) $(ACTOR_FULL_IMAGES) $(BASE_ROM)
	@mkdir -p $(dir $@)
	@$(PYTHON) $(ACTOR_ARCHIVE_TOOL) $(BASE_ROM) --offset $(ACTOR_ARCHIVE_OFFSET) --length $(ACTOR_ARCHIVE_LENGTH) --sha256 $(ACTOR_ARCHIVE_SHA256) rebuild --animations $(ACTOR_ANIMATIONS) --source $(ACTOR_SOURCE_DIRS) --output $@

$(UI_SHARED_RESOURCE_TILE_BIN) $(UI_SHARED_RESOURCE_PALETTE_BIN): $(UI_SHARED_RESOURCE_SOURCE) $(TILE_GRID_TOOL)
	@mkdir -p $(dir $(UI_SHARED_RESOURCE_TILE_BIN))
	@$(PYTHON) $(TILE_GRID_TOOL) build --source $(UI_SHARED_RESOURCE_SOURCE) --tiles $(UI_SHARED_RESOURCE_TILE_BIN) --palette $(UI_SHARED_RESOURCE_PALETTE_BIN)

$(FARM_STATUS_TILES_BIN): $(FARM_STATUS_TILES_SOURCE) $(TILE_GRID_TOOL)
	@mkdir -p $(dir $(FARM_STATUS_TILES_BIN))
	@$(PYTHON) $(TILE_GRID_TOOL) build --source $(FARM_STATUS_TILES_SOURCE) --tiles $(FARM_STATUS_TILES_BIN) --palette $(BUILD_DIR)/graphics/ui/farm_status/base_tiles_palette0.gbapal

$(FARM_STATUS_PALETTE_BIN): $(FARM_STATUS_PALETTE_SOURCE) $(FARM_STATUS_PALETTE_TOOL)
	@mkdir -p $(dir $@)
	@$(PYTHON) $(FARM_STATUS_PALETTE_TOOL) build --source $(FARM_STATUS_PALETTE_SOURCE) --output $@

$(FARM_STATUS_PACKED_BIN): $(FARM_STATUS_TILES_BIN) $(FARM_STATUS_CODEC) $(BASE_ROM)
	@mkdir -p $(dir $@)
	@$(PYTHON) $(FARM_STATUS_CODEC) $(FARM_STATUS_TILES_BIN) $@ \
	  --baseline-rom $(BASE_ROM) --baseline-offset $(FARM_STATUS_STREAM_OFFSET) \
	  --baseline-length $(FARM_STATUS_STREAM_LENGTH) --baseline-sha256 $(FARM_STATUS_STREAM_SHA256)

$(FARM_STATUS_TILEMAP_BIN): $(FARM_STATUS_TILEMAP_SOURCES) $(FARM_STATUS_TILEMAP_TOOL) $(FARM_STATUS_PREVIEW_TOOL)
	@$(PYTHON) $(FARM_STATUS_TILEMAP_TOOL) build --source-dir $(FARM_STATUS_TILEMAP_SOURCE_DIR) --output $@

$(FARM_STATUS_SECONDARY_TILEMAP_STAMP): $(FARM_STATUS_SECONDARY_TILEMAP_SOURCES) $(FARM_STATUS_SECONDARY_TILEMAP_TOOL) $(FARM_STATUS_CODEC) $(BASE_ROM)
	@$(PYTHON) $(FARM_STATUS_SECONDARY_TILEMAP_TOOL) build --region $(FARM_STATUS_SECONDARY_TILEMAP_REGION) --rom $(BASE_ROM) \
	  --source-dir $(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR) --output-dir $(FARM_STATUS_SECONDARY_TILEMAP_OUTPUT_DIR)
	@touch $@

$(INTRO_BACKGROUND_TILES_BIN): $(INTRO_BACKGROUND_TILES_SOURCE) $(TILE_GRID_TOOL)
	@mkdir -p $(dir $@)
	@$(PYTHON) $(TILE_GRID_TOOL) build --source $(INTRO_BACKGROUND_TILES_SOURCE) --tiles $@ --palette $(BUILD_DIR)/graphics/intro_scene/background_palette0.gbapal

$(INTRO_BACKGROUND_PALETTE_BIN): $(INTRO_BACKGROUND_PALETTE_SOURCE) $(FARM_STATUS_PALETTE_TOOL)
	@mkdir -p $(dir $@)
	@$(PYTHON) $(FARM_STATUS_PALETTE_TOOL) build --source $< --banks 3 --output $@

$(INTRO_BACKGROUND_PACKED_BIN): $(INTRO_BACKGROUND_TILES_BIN) $(FARM_STATUS_CODEC) $(BASE_ROM)
	@mkdir -p $(dir $@)
	@$(PYTHON) $(FARM_STATUS_CODEC) $(INTRO_BACKGROUND_TILES_BIN) $@ \
	  --baseline-rom $(BASE_ROM) --baseline-offset $(INTRO_BACKGROUND_STREAM_OFFSET) \
	  --baseline-length $(INTRO_BACKGROUND_STREAM_LENGTH) --baseline-sha256 $(INTRO_BACKGROUND_STREAM_SHA256)

$(INTRO_OBJECTS_STAMP): $(INTRO_OBJECTS_SOURCES) $(INTRO_OBJECTS_TOOL) $(FARM_STATUS_CODEC) $(BASE_ROM)
	@$(PYTHON) $(INTRO_OBJECTS_TOOL) build --region $(INTRO_OBJECTS_REGION) --rom $(BASE_ROM) \
	  --source-dir $(INTRO_OBJECTS_SOURCE_DIR) --output-dir $(INTRO_OBJECTS_OUTPUT_DIR)
	@touch $@

$(INTRO_OBJECTS_OUTPUTS): $(INTRO_OBJECTS_STAMP)

$(INTRO_STARTUP_TILEMAPS_STAMP): $(INTRO_STARTUP_TILEMAPS_SOURCES) $(INTRO_STARTUP_TILEMAPS_TOOL) $(FARM_STATUS_CODEC) $(BASE_ROM)
	@$(PYTHON) $(INTRO_STARTUP_TILEMAPS_TOOL) build --region $(INTRO_STARTUP_TILEMAPS_REGION) --rom $(BASE_ROM) \
	  --source-dir $(INTRO_STARTUP_TILEMAPS_SOURCE_DIR) --output-dir $(INTRO_STARTUP_TILEMAPS_OUTPUT_DIR)
	@touch $@

$(INTRO_STARTUP_TILEMAPS_OUTPUTS): $(INTRO_STARTUP_TILEMAPS_STAMP)

$(UI_SCENE_080A2BA4_STAMP): $(UI_SCENE_080A2BA4_SOURCES) $(UI_SCENE_080A2BA4_TOOL) $(FARM_STATUS_CODEC) $(BASE_ROM)
	@$(PYTHON) $(UI_SCENE_080A2BA4_TOOL) build --region $(UI_SCENE_080A2BA4_REGION) --rom $(BASE_ROM) \
	  --source-dir $(UI_SCENE_080A2BA4_SOURCE_DIR) --output-dir $(UI_SCENE_080A2BA4_OUTPUT_DIR)
	@touch $@

$(MAP_RESOURCES_STAMP): $(MAP_RESOURCES_SOURCES) $(MAP_RESOURCES_TOOL) baserom_jp.gba baserom_us.gba baserom_eu.gba baserom_de.gba
	@$(PYTHON) $(MAP_RESOURCES_TOOL) build --region $(MAP_RESOURCES_REGION) --rom $(BASE_ROM) \
	  --source-dir $(MAP_RESOURCES_SOURCE_DIR) --output-dir $(MAP_RESOURCES_OUTPUT_DIR) $(MAP_RESOURCES_ALL_ROM_ARGS)
	@touch $@

$(RECORDS_MINIGAME_OUTPUTS): $(RECORDS_MINIGAME_SOURCES) $(RECORDS_MINIGAME_TOOL)
	@$(PYTHON) $(RECORDS_MINIGAME_TOOL) build --source-dir $(RECORDS_MINIGAME_SOURCE_DIR) --output-dir $(RECORDS_MINIGAME_OUTPUT_DIR)

FONT_REGION_DOUBLE_BIN := $(FONT_SHARED_DOUBLE_BIN)

# Rebuild the active localization's verified font payloads without causing GNU
# make to update every optional assembler dependency file in a fresh worktree.
.PHONY: gfx-font gfx-jp-font gfx-fonts gfx-font-test gfx-fonts-test gfx-portraits gfx-portraits-all gfx-actors gfx-actors-test gfx-actors-all gfx-actors-edit-test gfx-ui gfx-ui-test gfx-ui-all gfx-farm-status gfx-farm-status-test gfx-farm-status-all gfx-farm-status-edit-test gfx-farm-status-previews gfx-farm-status-tilemaps gfx-farm-status-tilemaps-test gfx-farm-status-tilemaps-all gfx-farm-status-secondary-tilemaps gfx-farm-status-secondary-tilemaps-all gfx-farm-status-secondary-tilemaps-test gfx-farm-status-secondary-tilemaps-edit-test gfx-intro-background gfx-intro-background-test gfx-intro-background-all gfx-intro-background-edit-test gfx-intro-objects gfx-intro-objects-all gfx-intro-objects-test gfx-intro-objects-edit-test gfx-intro-startup-tilemaps gfx-intro-startup-tilemaps-test gfx-intro-startup-tilemaps-all gfx-intro-startup-tilemaps-edit-test gfx-map-resources gfx-map-resources-test gfx-map-resources-all gfx-map-resources-patch-test gfx-records-minigame gfx-records-minigame-test gfx-records-minigame-all resource-archive-audit unpack-vram-inventory gfx-assets gfx-verify tile-grid-region-test tile-grid-test oam-pack oam-pack-test oam-pack-audit
.PHONY: gfx-ui-scene-080a2ba4 gfx-ui-scene-080a2ba4-test gfx-ui-scene-080a2ba4-all gfx-ui-scene-080a2ba4-patch-test gfx-ui-scene-080a2ba4-edit-test
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
gfx-actors: $(ACTOR_TILE_BIN)
gfx-actors-test: gfx-actors $(BASE_ROM) $(GFX_RANGE_VERIFY)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(ACTOR_TILE_OFFSET) --input $(ACTOR_TILE_BIN) --sha256 $(ACTOR_TILE_SHA256)
gfx-actors-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-actors-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-actors-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-actors-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-actors-test
gfx-actors-edit-test: $(ACTOR_ARCHIVE_EDIT_TEST) $(ACTOR_ARCHIVE_TOOL) $(PORTRAIT_ARCHIVE_TOOL) baserom_us.gba $(ACTOR_SOURCE_DIRS)
	@$(PYTHON) $(ACTOR_ARCHIVE_EDIT_TEST) baserom_us.gba --offset $(ACTOR_ARCHIVE_OFFSET_US) --length $(ACTOR_ARCHIVE_LENGTH) --source graphics/sprites/actor_archive
gfx-ui: $(UI_SHARED_RESOURCE_TILE_BIN) $(UI_SHARED_RESOURCE_PALETTE_BIN)
gfx-ui-test: gfx-ui $(BASE_ROM) $(GFX_RANGE_VERIFY)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(UI_SHARED_RESOURCE_TILE_OFFSET) --input $(UI_SHARED_RESOURCE_TILE_BIN) --sha256 $(UI_SHARED_RESOURCE_TILE_SHA256)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(UI_SHARED_RESOURCE_PALETTE_OFFSET) --input $(UI_SHARED_RESOURCE_PALETTE_BIN) --sha256 $(UI_SHARED_RESOURCE_PALETTE_SHA256)
gfx-ui-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-ui-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-ui-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-ui-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-ui-test
gfx-ui-scene-080a2ba4: $(UI_SCENE_080A2BA4_STAMP)
gfx-ui-scene-080a2ba4-test: gfx-ui-scene-080a2ba4 $(UI_SCENE_080A2BA4_TOOL)
	@$(PYTHON) $(UI_SCENE_080A2BA4_TOOL) verify --region $(UI_SCENE_080A2BA4_REGION) --rom $(BASE_ROM) \
	  --source-dir $(UI_SCENE_080A2BA4_SOURCE_DIR) --output-dir $(UI_SCENE_080A2BA4_OUTPUT_DIR)
gfx-ui-scene-080a2ba4-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-ui-scene-080a2ba4-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-ui-scene-080a2ba4-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-ui-scene-080a2ba4-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-ui-scene-080a2ba4-test
gfx-ui-scene-080a2ba4-patch-test: gfx-ui-scene-080a2ba4-all $(UI_SCENE_080A2BA4_TOOL)
	@$(PYTHON) $(UI_SCENE_080A2BA4_TOOL) patch-test --output-root build \
	  --rom jp baserom_jp.gba --rom us baserom_us.gba --rom eu baserom_eu.gba --rom de baserom_de.gba
gfx-ui-scene-080a2ba4-edit-test: $(UI_SCENE_080A2BA4_TOOL) baserom_jp.gba
	@$(PYTHON) $(UI_SCENE_080A2BA4_TOOL) edit-test --region jp --rom baserom_jp.gba
gfx-farm-status: $(FARM_STATUS_TILES_BIN) $(FARM_STATUS_PALETTE_BIN) $(FARM_STATUS_PACKED_BIN)
gfx-farm-status-test: gfx-farm-status $(BASE_ROM) $(GFX_RANGE_VERIFY)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(FARM_STATUS_STREAM_OFFSET) --input $(FARM_STATUS_PACKED_BIN) --sha256 $(FARM_STATUS_STREAM_SHA256)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(FARM_STATUS_PALETTE_OFFSET) --input $(FARM_STATUS_PALETTE_BIN) --sha256 $(FARM_STATUS_PALETTE_SHA256)
gfx-farm-status-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-farm-status-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-farm-status-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-farm-status-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-farm-status-test
gfx-farm-status-edit-test: $(FARM_STATUS_TILES_SOURCE) $(FARM_STATUS_PALETTE_SOURCE) $(FARM_STATUS_CODEC) $(TILE_GRID_TOOL) $(FARM_STATUS_PALETTE_TOOL) baserom_us.gba
	@$(PYTHON) tools/farm_status_edit_test.py baserom_us.gba $(FARM_STATUS_TILES_SOURCE) $(FARM_STATUS_PALETTE_SOURCE)
gfx-farm-status-previews: $(FARM_STATUS_TILES_SOURCE) $(FARM_STATUS_PALETTE_SOURCE) $(FARM_STATUS_TILEMAP_SOURCES) $(FARM_STATUS_PREVIEW_TOOL) baserom_jp.gba baserom_us.gba baserom_eu.gba baserom_de.gba
	@$(PYTHON) $(FARM_STATUS_PREVIEW_TOOL) --tiles-source $(FARM_STATUS_TILES_SOURCE) --palettes-source $(FARM_STATUS_PALETTE_SOURCE) --tilemaps-source $(FARM_STATUS_TILEMAP_SOURCE_DIR) --rom baserom_us.gba --region us --output $(FARM_STATUS_REFERENCE_DIR) --replace --verify-jp baserom_jp.gba --verify-us baserom_us.gba --verify-eu baserom_eu.gba --verify-de baserom_de.gba
gfx-farm-status-tilemaps: $(FARM_STATUS_TILEMAP_BIN)
gfx-farm-status-tilemaps-test: gfx-farm-status-tilemaps $(FARM_STATUS_TILEMAP_TOOL) baserom_jp.gba baserom_us.gba baserom_eu.gba baserom_de.gba
	@$(PYTHON) $(FARM_STATUS_TILEMAP_TOOL) verify --source-dir $(FARM_STATUS_TILEMAP_SOURCE_DIR) \
	  --rom jp baserom_jp.gba --rom us baserom_us.gba --rom eu baserom_eu.gba --rom de baserom_de.gba
gfx-farm-status-tilemaps-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-farm-status-tilemaps
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-farm-status-tilemaps
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-farm-status-tilemaps
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-farm-status-tilemaps
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-farm-status-tilemaps-test
gfx-farm-status-secondary-tilemaps: $(FARM_STATUS_SECONDARY_TILEMAP_STAMP)
gfx-farm-status-secondary-tilemaps-test: gfx-farm-status-secondary-tilemaps $(BASE_ROM) $(FARM_STATUS_SECONDARY_TILEMAP_TOOL)
	@$(PYTHON) $(FARM_STATUS_SECONDARY_TILEMAP_TOOL) verify --region $(FARM_STATUS_SECONDARY_TILEMAP_REGION) --rom $(BASE_ROM) \
	  --source-dir $(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR) --output-dir $(FARM_STATUS_SECONDARY_TILEMAP_OUTPUT_DIR)
gfx-farm-status-secondary-tilemaps-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-farm-status-secondary-tilemaps-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-farm-status-secondary-tilemaps-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-farm-status-secondary-tilemaps-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-farm-status-secondary-tilemaps-test
gfx-farm-status-secondary-tilemaps-edit-test: $(FARM_STATUS_SECONDARY_TILEMAP_TOOL) baserom_jp.gba
	@$(PYTHON) $(FARM_STATUS_SECONDARY_TILEMAP_TOOL) edit-test --region jp --rom baserom_jp.gba
gfx-intro-background: $(INTRO_BACKGROUND_TILES_BIN) $(INTRO_BACKGROUND_PALETTE_BIN) $(INTRO_BACKGROUND_PACKED_BIN)
gfx-intro-background-test: gfx-intro-background $(BASE_ROM) $(GFX_RANGE_VERIFY)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(INTRO_BACKGROUND_STREAM_OFFSET) --input $(INTRO_BACKGROUND_PACKED_BIN) --sha256 $(INTRO_BACKGROUND_STREAM_SHA256)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(INTRO_BACKGROUND_PALETTE_OFFSET) --input $(INTRO_BACKGROUND_PALETTE_BIN) --sha256 $(INTRO_BACKGROUND_PALETTE_SHA256)
gfx-intro-background-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-intro-background-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-intro-background-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-intro-background-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-intro-background-test
gfx-intro-background-edit-test: $(INTRO_BACKGROUND_TILES_SOURCE) $(INTRO_BACKGROUND_PALETTE_SOURCE) $(FARM_STATUS_CODEC) $(TILE_GRID_TOOL) $(FARM_STATUS_PALETTE_TOOL) baserom_us.gba
	@$(PYTHON) tools/intro_background_edit_test.py baserom_us.gba $(INTRO_BACKGROUND_TILES_SOURCE) $(INTRO_BACKGROUND_PALETTE_SOURCE)
gfx-intro-objects: $(INTRO_OBJECTS_STAMP)
gfx-intro-objects-test: gfx-intro-objects $(BASE_ROM) $(INTRO_OBJECTS_TOOL)
	@$(PYTHON) $(INTRO_OBJECTS_TOOL) verify --region $(INTRO_OBJECTS_REGION) --rom $(BASE_ROM) \
	  --source-dir $(INTRO_OBJECTS_SOURCE_DIR) --output-dir $(INTRO_OBJECTS_OUTPUT_DIR)
gfx-intro-objects-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-intro-objects-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-intro-objects-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-intro-objects-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-intro-objects-test
gfx-intro-objects-edit-test: $(INTRO_OBJECTS_TOOL) baserom_jp.gba
	@$(PYTHON) $(INTRO_OBJECTS_TOOL) edit-test --region jp --rom baserom_jp.gba
gfx-intro-startup-tilemaps: $(INTRO_STARTUP_TILEMAPS_STAMP)
gfx-intro-startup-tilemaps-test: gfx-intro-startup-tilemaps $(BASE_ROM) $(INTRO_STARTUP_TILEMAPS_TOOL)
	@$(PYTHON) $(INTRO_STARTUP_TILEMAPS_TOOL) verify --region $(INTRO_STARTUP_TILEMAPS_REGION) --rom $(BASE_ROM) \
	  --source-dir $(INTRO_STARTUP_TILEMAPS_SOURCE_DIR) --output-dir $(INTRO_STARTUP_TILEMAPS_OUTPUT_DIR)
gfx-intro-startup-tilemaps-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-intro-startup-tilemaps-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-intro-startup-tilemaps-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-intro-startup-tilemaps-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-intro-startup-tilemaps-test
gfx-intro-startup-tilemaps-edit-test: $(INTRO_STARTUP_TILEMAPS_TOOL) baserom_jp.gba
	@$(PYTHON) $(INTRO_STARTUP_TILEMAPS_TOOL) edit-test --region jp --rom baserom_jp.gba
gfx-map-resources: $(MAP_RESOURCES_STAMP)
gfx-map-resources-test: gfx-map-resources $(MAP_RESOURCES_TOOL) baserom_jp.gba baserom_us.gba baserom_eu.gba baserom_de.gba
	@$(PYTHON) $(MAP_RESOURCES_TOOL) verify --region $(MAP_RESOURCES_REGION) --source-dir $(MAP_RESOURCES_SOURCE_DIR) --output-dir $(MAP_RESOURCES_OUTPUT_DIR) \
	  --rom jp baserom_jp.gba --rom us baserom_us.gba --rom eu baserom_eu.gba --rom de baserom_de.gba
gfx-map-resources-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-map-resources-test
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-map-resources-test
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-map-resources-test
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-map-resources-test
gfx-map-resources-patch-test: gfx-map-resources-all $(MAP_RESOURCES_TOOL)
	@$(PYTHON) $(MAP_RESOURCES_TOOL) patch-test --output-root build $(MAP_RESOURCES_ROM_ARGS)
resource-archive-audit: $(INDEXED_RESOURCE_ARCHIVE_TOOL) baserom_jp.gba baserom_us.gba baserom_eu.gba baserom_de.gba
	@$(PYTHON) $(INDEXED_RESOURCE_ARCHIVE_TOOL) compare --rom jp baserom_jp.gba 0x3ED9FC --rom us baserom_us.gba 0x6678A0 --rom eu baserom_eu.gba 0x6678FC --rom de baserom_de.gba 0x3EE93C
	@$(PYTHON) $(INDEXED_RESOURCE_ARCHIVE_TOOL) compare --rom jp baserom_jp.gba 0x3ED1BC --rom us baserom_us.gba 0x667060 --rom eu baserom_eu.gba 0x6670BC --rom de baserom_de.gba 0x3EE0FC
unpack-vram-inventory: $(UNPACK_VRAM_INVENTORY_TOOL)
	@$(PYTHON) $(UNPACK_VRAM_INVENTORY_TOOL) . --csv $(BUILD_DIR)/unpack_vram_inventory.csv
gfx-records-minigame: $(RECORDS_MINIGAME_OUTPUTS)
gfx-records-minigame-test: gfx-records-minigame $(RECORDS_MINIGAME_TOOL) baserom_jp.gba baserom_us.gba baserom_eu.gba baserom_de.gba
	@$(PYTHON) $(RECORDS_MINIGAME_TOOL) verify --source-dir $(RECORDS_MINIGAME_SOURCE_DIR) \
	  --rom jp baserom_jp.gba --rom us baserom_us.gba --rom eu baserom_eu.gba --rom de baserom_de.gba
gfx-records-minigame-all:
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-records-minigame
	@$(MAKE) --no-print-directory GAME_REGION=US gfx-records-minigame
	@$(MAKE) --no-print-directory GAME_REGION=EU gfx-records-minigame
	@$(MAKE) --no-print-directory GAME_REGION=DE gfx-records-minigame
	@$(MAKE) --no-print-directory GAME_REGION=JP gfx-records-minigame-test
# Generic linear 4bpp grid regression using a verified UI resource. Unlike
# character sprites, this payload has no OAM or tile-map indirection.
TILE_GRID_TEST_DIR := $(BUILD_DIR)/graphics/tile_grid_test
tile-grid-region-test: $(TILE_GRID_TOOL) $(GFX_RANGE_VERIFY) $(BASE_ROM)
	@$(PYTHON) $(TILE_GRID_TOOL) export $(BASE_ROM) --tiles-offset $(UI_SHARED_RESOURCE_TILE_OFFSET) --tiles-length 0x120 --palette-offset $(UI_SHARED_RESOURCE_PALETTE_OFFSET) --width 24 --sha256 $(UI_SHARED_RESOURCE_TILE_SHA256) --output $(TILE_GRID_TEST_DIR)/ui_shared_resource.png --replace
	@$(PYTHON) $(TILE_GRID_TOOL) build --source $(TILE_GRID_TEST_DIR)/ui_shared_resource.png --tiles $(TILE_GRID_TEST_DIR)/ui_shared_resource.4bpp --palette $(TILE_GRID_TEST_DIR)/ui_shared_resource.gbapal
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(UI_SHARED_RESOURCE_TILE_OFFSET) --input $(TILE_GRID_TEST_DIR)/ui_shared_resource.4bpp --sha256 $(UI_SHARED_RESOURCE_TILE_SHA256)
	@$(PYTHON) $(GFX_RANGE_VERIFY) $(BASE_ROM) --offset $(UI_SHARED_RESOURCE_PALETTE_OFFSET) --input $(TILE_GRID_TEST_DIR)/ui_shared_resource.gbapal --sha256 $(UI_SHARED_RESOURCE_PALETTE_SHA256)
tile-grid-test:
	@$(MAKE) --no-print-directory GAME_REGION=JP tile-grid-region-test
	@$(MAKE) --no-print-directory GAME_REGION=US tile-grid-region-test
	@$(MAKE) --no-print-directory GAME_REGION=EU tile-grid-region-test
	@$(MAKE) --no-print-directory GAME_REGION=DE tile-grid-region-test

gfx-assets: gfx-font gfx-portraits gfx-actors gfx-ui gfx-ui-scene-080a2ba4 gfx-farm-status gfx-farm-status-tilemaps gfx-farm-status-secondary-tilemaps gfx-intro-background gfx-intro-objects gfx-intro-startup-tilemaps gfx-map-resources gfx-records-minigame

# Full graphics gate for assets that have an authoritative source/rebuild
# path.  It intentionally does not link a ROM: the project-wide link is
# currently blocked independently by non-graphics C sources.
gfx-verify:
	@$(MAKE) --no-print-directory gfx-fonts-test
	@$(MAKE) --no-print-directory gfx-portraits-all
	@$(MAKE) --no-print-directory gfx-actors-all
	@$(MAKE) --no-print-directory gfx-actors-edit-test
	@$(MAKE) --no-print-directory gfx-ui-all
	@$(MAKE) --no-print-directory gfx-ui-scene-080a2ba4-all
	@$(MAKE) --no-print-directory gfx-ui-scene-080a2ba4-patch-test
	@$(MAKE) --no-print-directory gfx-ui-scene-080a2ba4-edit-test
	@$(MAKE) --no-print-directory gfx-farm-status-all
	@$(MAKE) --no-print-directory gfx-farm-status-edit-test
	@$(MAKE) --no-print-directory gfx-farm-status-tilemaps-all
	@$(MAKE) --no-print-directory gfx-farm-status-secondary-tilemaps-all
	@$(MAKE) --no-print-directory gfx-farm-status-secondary-tilemaps-edit-test
	@$(MAKE) --no-print-directory gfx-intro-background-all
	@$(MAKE) --no-print-directory gfx-intro-background-edit-test
	@$(MAKE) --no-print-directory gfx-intro-objects-all
	@$(MAKE) --no-print-directory gfx-intro-objects-edit-test
	@$(MAKE) --no-print-directory gfx-intro-startup-tilemaps-all
	@$(MAKE) --no-print-directory gfx-intro-startup-tilemaps-edit-test
	@$(MAKE) --no-print-directory gfx-map-resources-all
	@$(MAKE) --no-print-directory gfx-map-resources-patch-test
	@$(MAKE) --no-print-directory resource-archive-audit
	@$(MAKE) --no-print-directory gfx-records-minigame-all
	@$(MAKE) --no-print-directory tile-grid-test
	@$(MAKE) --no-print-directory oam-pack-test
	@$(MAKE) --no-print-directory oam-pack-audit

$(BUILD_DIR)/asm/data/data_0813B288.o: $(FONT_SHARED_SINGLE_BIN) $(FONT_REGION_DOUBLE_BIN) $(PORTRAIT_TILE_BIN) $(ACTOR_TILE_BIN) $(UI_SHARED_RESOURCE_TILE_BIN) $(UI_SHARED_RESOURCE_PALETTE_BIN) $(FARM_STATUS_PACKED_BIN) $(FARM_STATUS_PALETTE_BIN) $(FARM_STATUS_TILEMAP_BIN) $(FARM_STATUS_SECONDARY_TILEMAP_STAMP) $(INTRO_BACKGROUND_PACKED_BIN) $(INTRO_BACKGROUND_PALETTE_BIN) $(INTRO_OBJECTS_STAMP) $(INTRO_STARTUP_TILEMAPS_STAMP) $(MAP_RESOURCES_STAMP) $(RECORDS_MINIGAME_OUTPUTS)

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
%.gba: %.elf $(MAP_RESOURCES_STAMP) $(UI_SCENE_080A2BA4_STAMP)
	$(OBJCOPY) -O binary $< $@
	@$(PYTHON) $(MAP_RESOURCES_TOOL) patch --region $(MAP_RESOURCES_REGION) --rom $@ \
	  --archive $(MAP_RESOURCES_OUTPUT_DIR)/map_visual_archive.0x70 $(MAP_RESOURCES_ALL_ROM_ARGS)
	@$(PYTHON) $(UI_SCENE_080A2BA4_TOOL) patch --region $(UI_SCENE_080A2BA4_REGION) --baseline $(BASE_ROM) \
	  --rom $@ --output-dir $(UI_SCENE_080A2BA4_OUTPUT_DIR)

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

# Audit/build-only graphics targets do not need C/C++ dependency discovery.
ifneq (,$(filter gfx-ui-scene-080a2ba4 gfx-ui-scene-080a2ba4-test gfx-ui-scene-080a2ba4-all gfx-ui-scene-080a2ba4-patch-test gfx-ui-scene-080a2ba4-edit-test,$(MAKECMDGOALS)))
ALL_DEPS :=
endif

ifneq (clean,$(MAKECMDGOALS))
ifeq (,$(filter fomt_us fomt_jp fomt_eu fomt_de compare compare_eu compare_de gfx-font gfx-jp-font gfx-fonts gfx-font-test gfx-fonts-test gfx-portraits gfx-portraits-all gfx-actors gfx-actors-test gfx-actors-all gfx-actors-edit-test gfx-ui gfx-ui-test gfx-ui-all gfx-farm-status gfx-farm-status-test gfx-farm-status-all gfx-farm-status-edit-test gfx-farm-status-previews gfx-farm-status-tilemaps gfx-farm-status-tilemaps-test gfx-farm-status-tilemaps-all gfx-farm-status-secondary-tilemaps gfx-farm-status-secondary-tilemaps-test gfx-farm-status-secondary-tilemaps-all gfx-farm-status-secondary-tilemaps-edit-test gfx-intro-background gfx-intro-background-test gfx-intro-background-all gfx-intro-background-edit-test gfx-intro-objects gfx-intro-objects-all gfx-intro-objects-test gfx-intro-objects-edit-test gfx-map-resources gfx-map-resources-test gfx-map-resources-all gfx-map-resources-patch-test gfx-records-minigame gfx-records-minigame-test gfx-records-minigame-all resource-archive-audit unpack-vram-inventory gfx-assets gfx-verify tile-grid-region-test tile-grid-test oam-pack oam-pack-test oam-pack-audit,$(MAKECMDGOALS)))
-include $(ALL_DEPS)
endif
.PRECIOUS: $(BUILD_DIR)/%.d
endif
