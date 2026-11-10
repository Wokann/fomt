# Graphics conversion and packing rules.
#
# Like pret/pokeemerald's graphics_file_rules.mk, this file owns generated
# graphics artifacts.  Outputs live beside their authoring sources under
# graphics/; build/ is reserved for compiler and linker intermediates.
# Both font streams are physically identical in all four retail FoMT
# localizations. Native records have twelve active rows and are padded only
# for gbagfx's 8x8 tile conversion.
FONT_SHARED_SINGLE_PNG := graphics/font/shared/single_width_font.png
FONT_SHARED_SINGLE_PADDED := graphics/font/shared/single_width_font.padded.1bpp
FONT_SHARED_SINGLE_BIN := graphics/font/shared/single_width_font.1bpp
FONT_SHARED_DOUBLE_PNG := graphics/font/shared/double_width_font.png
FONT_SHARED_DOUBLE_PADDED := graphics/font/shared/double_width_font.padded.1bpp
FONT_SHARED_DOUBLE_BIN := graphics/font/shared/double_width_font.1bpp

# The dialogue-portrait archive has the same native layout in every region.
# Author the physical tile atlas and independent PAL banks directly. Full OAM
# portraits are reference views, not a second set of overlapping build inputs.
PORTRAIT_SOURCE_DIR := graphics/portraits/shared
PORTRAIT_NATIVE_TILES := $(PORTRAIT_SOURCE_DIR)/native_tiles.4bpp

# The actor archive uses one shared physical atlas, including covered pixels
# and unreferenced descriptor tiles. Compile it directly with gbagfx, rather
# than rebuilding a baseline archive and applying visible-frame patches.
ACTOR_NATIVE_TILES := graphics/sprites/actor_archive/native_tiles.4bpp

# Farm-status background tiles are a 16-palette-bank, linear 4bpp grid.  The
# native Huffman/LZ3 stream is encoded directly from the current PNG-generated
# tile bytes, using the same generic C encoder as the other packed resources.
FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR := graphics/ui/farm_status/shared/secondary_tilemaps

FARM_STATUS_WINTER_TILES_SOURCE := graphics/ui/farm_status/winter/shared/tiles.png
FARM_STATUS_WINTER_OUTPUT_DIR := graphics/ui/farm_status/winter/shared
FARM_STATUS_WINTER_TILES_BIN := $(FARM_STATUS_WINTER_OUTPUT_DIR)/winter_tiles.4bpp

# Intro Scene loading sends this 0x70 output straight to VRAM. The decoded
# 0x6E00-byte resource is a 40-by-22 linear 4bpp tile image (320 by 176
# pixels) and the immediately following 0x60 bytes are three palette banks.
# The stream and palette are byte-identical in JP, US, EU and DE.
INTRO_BACKGROUND_TILES_SOURCE := graphics/intro_scene/shared/background_tiles.png
INTRO_BACKGROUND_TILES_BIN := $(INTRO_BACKGROUND_TILES_SOURCE:.png=.4bpp)
INTRO_BACKGROUND_PACKED_BIN := $(INTRO_BACKGROUND_TILES_BIN).lz

# Childhood-story maps are twenty independent 32x20 halfword tilemaps.
# They are authored map data, not PNG pixels. The ordinary compression suffix
# rule packs their unchanged native Raw-LZ formats beside the sources.
INTRO_TILEMAPS_SOURCE_DIR := graphics/intro_scene/shared/tilemaps
INTRO_REGION := $(shell echo "$(GAME_REGION)" | tr '[:upper:]' '[:lower:]')

# The earlier Intro Scene setup function creates two interleaved 32-by-32 BG
# tilemaps from each 0x1000-byte Huffman-4/LZ3 source.  Keep the native
# interleaving as editable source until the compositor's palette/layout rules
# are proven.
INTRO_STARTUP_TILEMAPS_SOURCE_DIR := graphics/intro_scene/shared/startup_tilemaps

# ConstructIntroSceneCore expands this regional IndexedResourceArchive immediately
# after the Intro Scene background data. Complete frames are composed from
# the archive's own OAM records, so no JSON layout sidecar is necessary.
INTRO_INDEXED_ARCHIVE_SOURCE_ROOT := graphics/intro_scene/indexed_archive
INTRO_INDEXED_ARCHIVE_GROUP := $(if $(filter US EU,$(GAME_REGION)),us_eu,$(INTRO_REGION))
INTRO_INDEXED_ARCHIVE_SOURCE_DIR := $(INTRO_INDEXED_ARCHIVE_SOURCE_ROOT)/$(INTRO_INDEXED_ARCHIVE_GROUP)
INTRO_INDEXED_ARCHIVE_LAYOUT := $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/archive.inc
INTRO_INDEXED_ARCHIVE_TITLE_TILES := $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/title_tiles.8bpp
INTRO_INDEXED_ARCHIVE_FRAME_TILES := $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/frame_tiles.4bpp
INTRO_INDEXED_ARCHIVE_PALETTES := $(patsubst %.pal,%.gbapal,$(wildcard $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/palettes_*.pal))
INTRO_INDEXED_ARCHIVE_SOURCE_OBJ := $(BUILD_DIR)/graphics/intro_scene/indexed_archive/archive.o
INTRO_INDEXED_ARCHIVE_SOURCE_BIN := $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/archive.bin
INTRO_INDEXED_ARCHIVE_OUTPUT := $(INTRO_INDEXED_ARCHIVE_SOURCE_BIN).lz
INTRO_SCENE_SIZE_HEADER := $(BUILD_DIR)/intro_scene_resource_size.hh

# The menu's three poses share the complete tile stream from group zero.
UI_HAND_CURSOR_DOMAIN := $(if $(filter JP,$(GAME_REGION)),jp,overseas)
UI_HAND_CURSOR_TILES := graphics/regional_resource_08728208/$(UI_HAND_CURSOR_DOMAIN)/full/group_000.4bpp
UI_GRAPHICS_SIZE_HEADER := $(BUILD_DIR)/ui_graphics_sizes.hh

# func_080A2BA4 loads three 32-by-20 BG tilemaps and one 160-tile 4bpp
# character stream into fixed VRAM locations. Its adjacent palette bytes are
# also part of an indexed archive, so native tile/tilemap sources are kept
# without inventing an unproven coloured composite.
UI_SCENE_080A2BA4_SOURCE_DIR := graphics/ui/scene_080a2ba4/shared

# Overseas func_08077810 consumes two shared BG tilemaps and character tiles;
# JP uses a different code/data layout and its own resource group.
UI_SCENE_08077810_SOURCE_DIR := graphics/ui/scene_08077810/shared
UI_SCENE_08077810_CHARACTER_TILES := $(UI_SCENE_08077810_SOURCE_DIR)/tiles.4bpp
UI_SCENE_08077810_CHARACTER_PACKED := $(UI_SCENE_08077810_CHARACTER_TILES).lz
UI_SCENE_08077810_CHARACTER_TRAILER := $(UI_SCENE_08077810_SOURCE_DIR)/tiles_trailer.bin
UI_SCENE_08077810_LAYER0_SOURCE := $(UI_SCENE_08077810_SOURCE_DIR)/layer_0.tilemap
UI_SCENE_08077810_LAYER0_PACKED := $(UI_SCENE_08077810_LAYER0_SOURCE).lz
UI_SCENE_08077810_LAYER1_SOURCE := $(UI_SCENE_08077810_SOURCE_DIR)/layer_1.tilemap
UI_SCENE_08077810_LAYER1_PACKED := $(UI_SCENE_08077810_LAYER1_SOURCE).lz
# JP reaches a different resource group from its separate intro-scene code.
# Keep it physically separate from the shared US/EU/DE sources.
UI_SCENE_08077810_JP_SOURCE_DIR := graphics/ui/scene_08077810/jp
UI_SCENE_08077810_JP_TILES := $(UI_SCENE_08077810_JP_SOURCE_DIR)/tiles.4bpp
UI_SCENE_08077810_JP_TILES_PACKED := $(UI_SCENE_08077810_JP_TILES).lz
UI_SCENE_08077810_JP_LAYER1_SOURCE := $(UI_SCENE_08077810_JP_SOURCE_DIR)/layer_1.tilemap
UI_SCENE_08077810_JP_LAYER1_PACKED := $(UI_SCENE_08077810_JP_LAYER1_SOURCE).lz

# func_080AE7D0 has two 32-by-32 BG tilemaps, a 928-tile 4bpp character
# stream and an independently bounded 16-bank palette.  Native sources avoid
# assigning a visual compositor before the screen's layer logic is proven.
UI_SCENE_080AE7D0_SOURCE_DIR := graphics/ui/scene_080ae7d0/shared
UI_SCENE_080AE7D0_MAP0_SOURCE := $(UI_SCENE_080AE7D0_SOURCE_DIR)/layer_0.tilemap
UI_SCENE_080AE7D0_MAP1_SOURCE := $(UI_SCENE_080AE7D0_SOURCE_DIR)/layer_1.tilemap
UI_SCENE_080AE7D0_TILES_SOURCE := $(UI_SCENE_080AE7D0_SOURCE_DIR)/tiles.4bpp

# func_080B7164 loads two native 32-by-32 BG tilemaps and a 4bpp tile stream.
# Its 0x200-byte palette-RAM copy starts at the shared three-bank JASC-PAL
# source and continues into the following archive.  The rendered PNGs are
# references; the native tilemaps retain map/flip/bank metadata.
UI_SCENE_080B7164_SOURCE_DIR := graphics/ui/scene_080b7164/shared
UI_SCENE_080B7164_MAP0_SOURCE := $(UI_SCENE_080B7164_SOURCE_DIR)/layer_0.tilemap
UI_SCENE_080B7164_MAP1_SOURCE := $(UI_SCENE_080B7164_SOURCE_DIR)/layer_1.tilemap
UI_SCENE_080B7164_TILES_SOURCE := $(UI_SCENE_080B7164_SOURCE_DIR)/tiles.4bpp

# This profile shares the C Raw-LZ codec with 080B7164. It has its own
# physical ranges and ladders, but the same two tilemap plus 4bpp topology.
UI_SCENE_080C160C_SOURCE_DIR := graphics/ui/scene_080c160c/shared
UI_SCENE_080C160C_MAP0_SOURCE := $(UI_SCENE_080C160C_SOURCE_DIR)/layer_0.tilemap
UI_SCENE_080C160C_MAP1_SOURCE := $(UI_SCENE_080C160C_SOURCE_DIR)/layer_1.tilemap
UI_SCENE_080C160C_TILES_SOURCE := $(UI_SCENE_080C160C_SOURCE_DIR)/tiles.4bpp

UI_SCENE_080BCFAC_SOURCE_DIR := graphics/ui/scene_080bcfac/shared
UI_SCENE_080BCFAC_MAP0_SOURCE := $(UI_SCENE_080BCFAC_SOURCE_DIR)/layer_0.tilemap
UI_SCENE_080BCFAC_MAP1_SOURCE := $(UI_SCENE_080BCFAC_SOURCE_DIR)/layer_1.tilemap
UI_SCENE_080BCFAC_TILES_SOURCE := $(UI_SCENE_080BCFAC_SOURCE_DIR)/tiles.4bpp

UI_SCENE_080B55D0_AUX_SOURCE_DIR := graphics/ui/scene_080b55d0_aux/shared
UI_SCENE_080B55D0_AUX_MAP0_SOURCE := $(UI_SCENE_080B55D0_AUX_SOURCE_DIR)/layer_0.tilemap
UI_SCENE_080B55D0_AUX_MAP1_SOURCE := $(UI_SCENE_080B55D0_AUX_SOURCE_DIR)/layer_1.tilemap
UI_SCENE_080B55D0_AUX_TILES_SOURCE := $(UI_SCENE_080B55D0_AUX_SOURCE_DIR)/tiles.4bpp

# The scene's 32 KiB main 4bpp tile stream is physically separate from its
# two auxiliary maps.  It has a verified editable native source but no
# asserted full-scene layout yet.
UI_SCENE_080B55D0_MAIN_SOURCE_DIR := graphics/ui/scene_080b55d0_main/shared
UI_SCENE_080B55D0_MAIN_SOURCE := $(UI_SCENE_080B55D0_MAIN_SOURCE_DIR)/main_tiles.4bpp

UI_SCENE_08054F40_TILES_SOURCE_DIR := graphics/ui/scene_08054f40_tiles/shared
UI_SCENE_08054F40_TILES_SOURCE := $(UI_SCENE_08054F40_TILES_SOURCE_DIR)/tiles.4bpp
UI_SCENE_08054F40_TILES_OUTPUT := $(UI_SCENE_08054F40_TILES_SOURCE).lz

UI_THREE_LAYER_BACKGROUND_DIR := graphics/ui/three_layer_background/shared
$(UI_THREE_LAYER_BACKGROUND_DIR)/tiles.4bpp: GFX_TILE_COUNT := 358
$(UI_THREE_LAYER_BACKGROUND_DIR)/palettes.gbapal: GFX_PALETTE_COLORS := 176

# Seven FarmHouse visual descriptors each pass a separately bounded native
# 0x70 stream directly to Unpack. Shared native-index PNGs and independent
# PALs use the ordinary source-adjacent conversions below.
FARM_HOUSE_VISUAL_SOURCE_DIR := graphics/farm_house_visual/shared
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_00.4bpp: GFX_TILE_COUNT := 64
$(addprefix $(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_,$(addsuffix .4bpp,01 02 05)): GFX_TILE_COUNT := 63
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_03.4bpp: GFX_TILE_COUNT := 159
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_04.4bpp: GFX_TILE_COUNT := 351
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_06.4bpp: GFX_TILE_COUNT := 223

# The first physical MapData run is assembled from source-adjacent packed
# streams. Read its incbin list instead of duplicating 42 paths in make.
MAP_DATA_SOURCE_DIR := graphics/maps/shared
MAP_DATA_PALETTE_OUTPUTS := $(patsubst %.pal,%.gbapal,$(wildcard $(MAP_DATA_SOURCE_DIR)/map_*/*.pal))
$(MAP_DATA_PALETTE_OUTPUTS): GFX_PALETTE_COLORS := 240

MAP_STATE_PALETTE_SOURCE_DIR := graphics/map_state_palettes/shared
$(MAP_STATE_PALETTE_SOURCE_DIR)/fallback_00.gbapal.lz: FOMT_LZ3_ARGS := 145
$(MAP_STATE_PALETTE_SOURCE_DIR)/fallback_01.gbapal.lz: FOMT_LZ3_ARGS := 147
$(MAP_STATE_PALETTE_SOURCE_DIR)/fallback_02.gbapal.lz: FOMT_LZ3_ARGS := 456
$(MAP_STATE_PALETTE_SOURCE_DIR)/fallback_03.gbapal.lz: FOMT_LZ3_ARGS := 456
$(MAP_STATE_PALETTE_SOURCE_DIR)/fallback_04.gbapal.lz: FOMT_LZ3_ARGS := 147

$(GFX_TOOL): $(GFX_TOOL_SOURCES)
	@$(MAKE) -C $(GFX_TOOL_DIR)

$(FONT_PAD): $(FONT_PAD_DIR)/fontpad.c $(FONT_PAD_DIR)/Makefile
	@$(MAKE) -C $(FONT_PAD_DIR)

$(OAM_PACK): $(OAM_PACK_DIR)/oam_pack.c $(OAM_PACK_DIR)/Makefile
	@$(MAKE) -C $(OAM_PACK_DIR)

$(FONT_SHARED_SINGLE_PADDED): $(FONT_SHARED_SINGLE_PNG) $(GFX_TOOL)
	@$(GFX_TOOL) $< $@

$(FONT_SHARED_SINGLE_BIN): $(FONT_SHARED_SINGLE_PADDED) $(FONT_PAD)
	@$(FONT_PAD) trim-grid-12-from-16 $< $@ 16 487

$(FONT_SHARED_DOUBLE_PADDED): $(FONT_SHARED_DOUBLE_PNG) $(GFX_TOOL)
	@$(GFX_TOOL) $< $@

$(FONT_SHARED_DOUBLE_BIN): $(FONT_SHARED_DOUBLE_PADDED) $(FONT_PAD)
	@$(FONT_PAD) trim-grid-16x12-from-16x16 $< $@ 32 6922

# The 16-tile-wide atlases end with 14 and 2 unused image-grid cells.
# Emit only the actual native table records through the generic PNG rule.
$(PORTRAIT_NATIVE_TILES): GFX_TILE_COUNT := 11586
$(ACTOR_NATIVE_TILES): GFX_TILE_COUNT := 24398

$(FARM_STATUS_WINTER_TILES_BIN): $(FARM_STATUS_WINTER_TILES_SOURCE) $(GFX_TOOL)
	@$(GFX_TOOL) $(FARM_STATUS_WINTER_TILES_SOURCE) $(FARM_STATUS_WINTER_TILES_BIN)

# Native streams share one suffix rule. Codec variants, search ladders and
# encoding options are target metadata; scaninc discovers the actual
# requested outputs from source references, without a second resource list.

$(UI_SCENE_080A2BA4_SOURCE_DIR)/layer_0.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 125
$(UI_SCENE_080A2BA4_SOURCE_DIR)/layer_1.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1234679
$(UI_SCENE_080A2BA4_SOURCE_DIR)/layer_2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1234679
$(UI_SCENE_080A2BA4_SOURCE_DIR)/tiles.4bpp.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,5,6,8,10,12
$(UI_SCENE_080AE7D0_MAP0_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 3,5,6,7,8,9,10
$(UI_SCENE_080AE7D0_MAP1_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 2,5,10
$(UI_SCENE_080AE7D0_TILES_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,5,7,10,11,13,15
$(UI_SCENE_080B7164_MAP0_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 3,5,7
$(UI_SCENE_080B7164_MAP1_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9
$(UI_SCENE_080B7164_TILES_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,5,7,8,10,11,12
$(UI_SCENE_080C160C_MAP0_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,3,6,7,9,10,11
$(UI_SCENE_080C160C_MAP1_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 3,7,9
$(UI_SCENE_080C160C_TILES_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,4,6,7,8,10,12 --literal-tail
$(UI_SCENE_080BCFAC_MAP0_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 2,6,10
$(UI_SCENE_080BCFAC_MAP1_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 1,6,9
$(UI_SCENE_080BCFAC_TILES_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,5,6,7,9,11,13
$(UI_SCENE_080B55D0_AUX_MAP0_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 1,2,5
$(UI_SCENE_080B55D0_AUX_MAP1_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9
$(UI_SCENE_080B55D0_AUX_TILES_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,5,8,9,10,11,12
$(UI_SCENE_08054F40_TILES_OUTPUT): FOMT_LZ_ENCODE := encode-lz2 2,5,7,8,10,13,14

# Frisbee BG maps and four-frame tile animation use the same native suffix rules.
$(UI_SCENE_08054F40_TILES_SOURCE_DIR)/background.tilemap.lz: FOMT_LZ_ENCODE := encode-lz0 4,6
$(UI_SCENE_08054F40_TILES_SOURCE_DIR)/overlay.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9
$(UI_SCENE_08054F40_TILES_SOURCE_DIR)/overlay_top.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,2,5
$(UI_SCENE_08054F40_TILES_SOURCE_DIR)/animation.4bpp.lz: FOMT_LZ_ENCODE := encode-lz2 3,6,7,8,11,12,13
$(UI_SCENE_08054F40_TILES_SOURCE_DIR)/palettes.gbapal: GFX_PALETTE_COLORS := 80
$(UI_THREE_LAYER_BACKGROUND_DIR)/tiles.4bpp.lz: FOMT_LZ_ENCODE := encode-lz2 3,5,7,10,11,12,14
$(UI_THREE_LAYER_BACKGROUND_DIR)/layout_0.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,2,5
$(UI_THREE_LAYER_BACKGROUND_DIR)/layout_1.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,7
$(UI_THREE_LAYER_BACKGROUND_DIR)/layout_2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 2,4,7
$(UI_THREE_LAYER_BACKGROUND_DIR)/layout_3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,3,5
$(INTRO_BACKGROUND_PACKED_BIN): FOMT_LZ_ENCODE := encode-lz2 3,5,8,10,12,13,15 --literal-tail
graphics/intro_scene/shared/startup_visual/startup_tiles.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,10,14 --greedy --tie=exchange
graphics/ui/farm_status/shared/base_tiles.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,8,13 --greedy --tie=exchange
graphics/ui/seasonal_background/winter/winter_tiles.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,10,13 --greedy --tie=exchange
graphics/ui/seasonal_background/shared/nonwinter_tiles.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz2 2,5,8,10,11,12,14 --tie=exchange
$(FARM_STATUS_WINTER_TILES_BIN).lz: FOMT_LZ_ENCODE := encode-huff8-lz2 3,5,7,8,10,12,14 --tie=exchange
$(UI_SCENE_080B55D0_MAIN_SOURCE).lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,10,12 --greedy --tie=exchange
$(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/bg0.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,7,9 --parent-first
$(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/bg1.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,7,9 --tie=first
$(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/bg2.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,8,11
$(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/bg3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,7,10 --tie=quick
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_00.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,8,12 --tie=heap
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_01.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,6,11
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_02.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,6,10 --tie=exchange
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_03.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,8,12 --tie=heap-sort
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_04.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,8,11
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_05.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,6,10 --tie=exchange
$(UI_SCENE_08077810_LAYER0_PACKED): FOMT_LZ_ENCODE := encode-huff4-lz3 1,5,9
$(UI_SCENE_08077810_LAYER1_PACKED): FOMT_LZ_ENCODE := encode-huff4-lz0 1,10
$(UI_SCENE_08077810_JP_TILES_PACKED): FOMT_LZ_ENCODE := encode-huff4-lz3 1,4,10
$(UI_SCENE_08077810_JP_LAYER1_PACKED): FOMT_LZ_ENCODE := encode-huff4-lz2 1,2,3,4,5,6,10 --tie=last
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_00.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 1,4,8 --greedy --tie=exchange
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_01.4bpp.lz: FOMT_LZ_ENCODE := encode-huff4-lz2 2,4,5,6,7,8,11 --filter=1
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_02.4bpp.lz: FOMT_LZ_ENCODE := encode-huff4-lz2 2,4,5,6,7,8,10 --filter=1
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_03.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 1,8,11 --greedy --tie=exchange
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_04.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz2 2,6,7,8,9,11,13 --tie=exchange
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_05.4bpp.lz: FOMT_LZ_ENCODE := encode-huff4-lz2 2,4,5,6,7,8,8
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_06.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 1,8,12 --greedy --tie=exchange

# These eleven Raw-LZ3 maps are rebuilt directly from authored tilemaps.
# Original comparison samples are kept outside the formal source tree.
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_00_bg2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_01_bg2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_02_bg2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_03_bg2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_04_bg3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,7
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_04_bg2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_05_bg2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_06_bg3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 5,8,10
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_07_bg3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 5,8,10
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_08_bg2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_09_bg2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 5,8,10
# These six Raw-LZ2 maps reproduce their original compressed streams exactly.
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_01_bg3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,4,6,7,8,9
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_02_bg3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,4,5,6,7,8,9
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_03_bg3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,4,6,7,8,10
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_05_bg3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,4,6,7,8,9
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_06_bg2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,10
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_07_bg2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,6,8,10
# The remaining three tilemaps use the same direct source-to-stream rule.
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_00_bg3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz1 2,6,8,10
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_08_bg3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz1 4,6,8,10
$(INTRO_TILEMAPS_SOURCE_DIR)/frame_09_bg3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz1 4,6,9,11
# This complete MapData run is bounded by still-raw neighboring resources.
# All six natural encodings already match; retain their verified storage
# budgets until those neighboring references are also relocatable.
$(MAP_DATA_SOURCE_DIR)/map_00/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,9,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_00/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,5,4 --tie=first --filter=3
$(MAP_DATA_SOURCE_DIR)/map_00/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,6
$(MAP_DATA_SOURCE_DIR)/map_00/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,10,14 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_00/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 8,10,13 --tie=quick --filter=4
$(MAP_DATA_SOURCE_DIR)/map_00/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,8,10,11,12,11 --filter=4
# The next physical run has shared tiles/palettes and interleaved map layers.
# Keep its real payload order in assembly and use the same generic suffix rule.
$(MAP_DATA_SOURCE_DIR)/map_01/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,9,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_01/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 4,5,5
$(MAP_DATA_SOURCE_DIR)/map_01/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,10,13 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_01/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 8,10,13 --tie=first --filter=4
$(MAP_DATA_SOURCE_DIR)/map_01/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,8,10,11,12,11 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_01/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 4,5,3
$(MAP_DATA_SOURCE_DIR)/map_10/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,11,13 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_10/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz0 6,6
$(MAP_DATA_SOURCE_DIR)/map_12/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,9,13 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_12/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,8,13 --tie=last --filter=4
$(MAP_DATA_SOURCE_DIR)/map_12/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,8,13 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_10/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,4,6 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_11/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,10,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_11/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,4,6
$(MAP_DATA_SOURCE_DIR)/map_13/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,9,13 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_13/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,8,13 --tie=last --filter=4
$(MAP_DATA_SOURCE_DIR)/map_13/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,8,13 --tie=last --filter=4
$(MAP_DATA_SOURCE_DIR)/map_11/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,4,6
$(MAP_DATA_SOURCE_DIR)/map_51/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,7,8
$(MAP_DATA_SOURCE_DIR)/map_51/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,8,10 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_51/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,5,8 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_26/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,7,10
$(MAP_DATA_SOURCE_DIR)/map_26/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,5,6,7,8,9,10 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_26/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,9 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_25/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 6,9,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_25/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz0 6,8
$(MAP_DATA_SOURCE_DIR)/map_25/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,7,10 --tie=reverse --filter=3
$(MAP_DATA_SOURCE_DIR)/map_25/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,5,6,7,8,9,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_25/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 2,5,11 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_37/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,7,8 --tie=last
$(MAP_DATA_SOURCE_DIR)/map_37/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 4,5,8
$(MAP_DATA_SOURCE_DIR)/map_37/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,6,7 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_36/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,8 --tie=last
$(MAP_DATA_SOURCE_DIR)/map_36/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,7,6 --tie=quick
$(MAP_DATA_SOURCE_DIR)/map_36/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,7 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_53/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,7,8 --tie=heap-sort
$(MAP_DATA_SOURCE_DIR)/map_53/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_53/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,9,7 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_29/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,8,10 --tie=first --filter=3
$(MAP_DATA_SOURCE_DIR)/map_29/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,6,9,10,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_29/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,5,11 --tie=heap --filter=4
$(MAP_DATA_SOURCE_DIR)/map_30/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,8,10 --tie=last
$(MAP_DATA_SOURCE_DIR)/map_30/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,3,4,5,6,8,10 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_30/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,5,6,7,9,10,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_29/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,10,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_29/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,7,7 --tie=exchange --filter=3
$(MAP_DATA_SOURCE_DIR)/map_22/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,8,9 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_22/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,5,10 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_22/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,5,11 --tie=exchange --filter=3
$(MAP_DATA_SOURCE_DIR)/map_23/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,8,10 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_23/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,4,5,6,8,9,11 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_23/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,5,9 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_24/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,8,10 --tie=heap
$(MAP_DATA_SOURCE_DIR)/map_24/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,3,4,5,6,9,11 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_24/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,6,9 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_22/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,10,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_22/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,4,6 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_50/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,9,13 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_50/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,6 --tie=quick --filter=3
$(MAP_DATA_SOURCE_DIR)/map_34/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,7,8 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_34/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,8,8 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_34/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,8
$(MAP_DATA_SOURCE_DIR)/map_35/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,6,10 --tie=heap-sort --filter=4
$(MAP_DATA_SOURCE_DIR)/map_35/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,7,10 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_35/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,5,9 --tie=exchange --filter=4
$(MAP_DATA_SOURCE_DIR)/map_32/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,7,9 --tie=first --filter=3
$(MAP_DATA_SOURCE_DIR)/map_32/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,6,7,8 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_32/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,7,9,7 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_33/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,7,9 --tie=reverse-select --filter=4
$(MAP_DATA_SOURCE_DIR)/map_33/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,7,8,7 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_33/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 2,5,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_32/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,11,13 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_32/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,6,7 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_52/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz2 2,5,7,8,9,10,13 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_52/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz2 1,2,3,4,5,6,7 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_52/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz2 2,3,4,5,6,7,10 --tie=exchange --filter=4
$(MAP_DATA_SOURCE_DIR)/map_52/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,8,8 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_52/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_50/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,6,7,10
$(MAP_DATA_SOURCE_DIR)/map_50/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,7,10 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_50/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,9 --tie=exchange --filter=3
$(MAP_DATA_SOURCE_DIR)/map_41/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 6,11,13 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_41/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,4,6 --tie=first --filter=3
$(MAP_DATA_SOURCE_DIR)/map_43/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,7,9 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_43/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,3,4,5,6,7,11 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_43/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,6,9 --tie=exchange --filter=3
$(MAP_DATA_SOURCE_DIR)/map_42/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,6,9
$(MAP_DATA_SOURCE_DIR)/map_42/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,3,4,6,7,9,9 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_42/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,5,9 --tie=exchange --filter=4
$(MAP_DATA_SOURCE_DIR)/map_41/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,9 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_41/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,8,10 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_41/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,5,9 --tie=quick --filter=4
$(MAP_DATA_SOURCE_DIR)/map_10/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 7,9,12 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_10/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 8,9,10 --tie=reverse-select --filter=3
$(MAP_DATA_SOURCE_DIR)/map_10/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 8,9,11 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_11/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 7,9,11 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_11/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 8,9,10 --tie=exchange --filter=3
$(MAP_DATA_SOURCE_DIR)/map_11/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 8,9,10 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_08/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,5
$(MAP_DATA_SOURCE_DIR)/map_08/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,9,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_09/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,9,13 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_14/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 6,11,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_15/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 6,11,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_14/layer_3.tilemap.lz $(MAP_DATA_SOURCE_DIR)/map_15/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 8,10,14 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_36/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,9,13 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_44/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,10,13 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_53/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,9,12 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_08/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 4,5,4
$(MAP_DATA_SOURCE_DIR)/map_09/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 4,5,7
$(MAP_DATA_SOURCE_DIR)/map_09/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 4,5,7
$(MAP_DATA_SOURCE_DIR)/map_09/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,6,12
$(MAP_DATA_SOURCE_DIR)/map_31/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 3,6,11
$(MAP_DATA_SOURCE_DIR)/map_44/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 3,5,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_45/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_08/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,4,7,8,9,12 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_08/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,3,4,7,10,12,7 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_09/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,4,7,8,9,12 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_31/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,4,5,6,7,9,7 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_44/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,6,7,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_45/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,7,8,10 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_15/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz0 6,6
$(MAP_DATA_SOURCE_DIR)/map_36/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz0 6,8
$(MAP_DATA_SOURCE_DIR)/map_14/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,5,5 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_14/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,4,6
$(MAP_DATA_SOURCE_DIR)/map_14/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,10,14
$(MAP_DATA_SOURCE_DIR)/map_14/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 9,11,13 --tie=reverse
$(MAP_DATA_SOURCE_DIR)/map_15/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,10,14 --tie=first
$(MAP_DATA_SOURCE_DIR)/map_08/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 7,9,12
$(MAP_DATA_SOURCE_DIR)/map_44/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,5,7 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_44/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,7,9 --filter=4 --tie=first
$(MAP_DATA_SOURCE_DIR)/map_45/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,5,8
$(MAP_DATA_SOURCE_DIR)/map_31/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,7,11 --filter=3 --tie=first
$(MAP_DATA_SOURCE_DIR)/map_09/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,9,12 --parent-first
$(MAP_DATA_SOURCE_DIR)/map_40/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,5,9 --tie=reverse --parent-first
$(MAP_DATA_SOURCE_DIR)/map_15/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,4,6 --tie=last
$(MAP_DATA_SOURCE_DIR)/map_40/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,7,9 --tie=last
$(MAP_DATA_SOURCE_DIR)/map_53/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,7,5 --filter=3 --tie=last
$(MAP_DATA_SOURCE_DIR)/map_15/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 8,10,14 --tie=reverse-select
$(MAP_DATA_SOURCE_DIR)/map_40/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,7 --tie=shell

# Remaining MapData payloads keep their original physical gaps and identities.
# The shared UI/map tile stream reuses its existing profile above.
$(MAP_DATA_SOURCE_DIR)/map_28/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,7,9 --tie=exchange --filter=4
$(MAP_DATA_SOURCE_DIR)/map_28/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,10 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_28/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,8 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_04/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz2 2,5,7,10,11,13,15 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_04/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 5,6,6
$(MAP_DATA_SOURCE_DIR)/map_04/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,9,14
$(MAP_DATA_SOURCE_DIR)/map_04/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,11,14
$(MAP_DATA_SOURCE_DIR)/map_04/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,11,14
$(MAP_DATA_SOURCE_DIR)/map_04/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,6,3 --tie=reverse
$(MAP_DATA_SOURCE_DIR)/map_05/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz2 2,5,7,10,11,13,15 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_05/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,6
$(MAP_DATA_SOURCE_DIR)/map_05/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 6,10,14 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_05/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,9,13
$(MAP_DATA_SOURCE_DIR)/map_05/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 7,11,14 --tie=exchange --filter=4
$(MAP_DATA_SOURCE_DIR)/map_05/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,5,6 --tie=shell
$(MAP_DATA_SOURCE_DIR)/map_18/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz2 2,3,4,5,7,8,10 --tie=exchange --filter=4
$(MAP_DATA_SOURCE_DIR)/map_18/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,7,10 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_18/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,6,7,9 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_19/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,6,8,10 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_19/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,9 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_19/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 5,7,8 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_18/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,10,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_18/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,5,6 --tie=last --filter=3
$(MAP_DATA_SOURCE_DIR)/map_56/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 7,9,12 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_56/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,4,5 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_56/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,7 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_56/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,2,3
$(MAP_DATA_SOURCE_DIR)/map_56/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,7 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_57/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,3,4,5,6,9,13 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_57/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,2,3
$(MAP_DATA_SOURCE_DIR)/map_57/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,3,4,5,6,7,8 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_58/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,9,10,8 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_58/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,2,3
$(MAP_DATA_SOURCE_DIR)/map_58/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,7 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_59/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,6,7,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_59/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,2,3
$(MAP_DATA_SOURCE_DIR)/map_59/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,7 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_60/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,6,6
$(MAP_DATA_SOURCE_DIR)/map_60/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,7
$(MAP_DATA_SOURCE_DIR)/map_60/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,7 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_61/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,9 --tie=exchange --filter=4
$(MAP_DATA_SOURCE_DIR)/map_61/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,2,3
$(MAP_DATA_SOURCE_DIR)/map_61/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,8,10 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_02/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,4,4
$(MAP_DATA_SOURCE_DIR)/map_02/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,10,12 --tie=reverse --filter=4
$(MAP_DATA_SOURCE_DIR)/map_02/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,6,12 --tie=quick
$(MAP_DATA_SOURCE_DIR)/map_02/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,6,11
$(MAP_DATA_SOURCE_DIR)/map_02/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,4,4
$(MAP_DATA_SOURCE_DIR)/map_03/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,9,12 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_03/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,4,6
$(MAP_DATA_SOURCE_DIR)/map_03/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,10,12 --tie=shell --filter=3
$(MAP_DATA_SOURCE_DIR)/map_03/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,6,12 --tie=reverse
$(MAP_DATA_SOURCE_DIR)/map_03/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,6,11 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_03/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,5
$(MAP_DATA_SOURCE_DIR)/map_20/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz2 2,3,4,5,6,7,10 --tie=exchange --filter=4
$(MAP_DATA_SOURCE_DIR)/map_20/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,7,10 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_20/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,9 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_21/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,6,7,10 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_21/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_21/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,8,8 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_54/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,7,8 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_54/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,8 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_54/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,9,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_26/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,10,13 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_26/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,6,7 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_27/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,7,9 --tie=exchange --filter=4
$(MAP_DATA_SOURCE_DIR)/map_27/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,8,8 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_27/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,7,8,8 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_39/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,9,10 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_39/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,5,10
$(MAP_DATA_SOURCE_DIR)/map_39/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,7,10 --tie=first
$(MAP_DATA_SOURCE_DIR)/map_38/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 3,8,10 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_38/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 3,6,9
$(MAP_DATA_SOURCE_DIR)/map_38/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,7,9
$(MAP_DATA_SOURCE_DIR)/map_48/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz2 2,3,4,5,7,8,10 --tie=exchange --filter=3
$(MAP_DATA_SOURCE_DIR)/map_48/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,8,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_48/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,7,8,8 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_06/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,10,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_06/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 4,6,6
$(MAP_DATA_SOURCE_DIR)/map_06/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,11,14 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_06/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,11,13 --tie=first --filter=4
$(MAP_DATA_SOURCE_DIR)/map_06/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 5,8,13 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_06/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,5,7 --tie=first
$(MAP_DATA_SOURCE_DIR)/map_07/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,10,14 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_07/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 4,6,7
$(MAP_DATA_SOURCE_DIR)/map_07/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,11,13
$(MAP_DATA_SOURCE_DIR)/map_07/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,11,13 --tie=reverse --filter=3
$(MAP_DATA_SOURCE_DIR)/map_07/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,8,13 --tie=reverse --filter=4
$(MAP_DATA_SOURCE_DIR)/map_07/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,6,7 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_16/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 6,10,13 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_16/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz0 5,6
$(MAP_DATA_SOURCE_DIR)/map_16/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 6,8,10 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_16/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,6,10 --tie=exchange --filter=3
$(MAP_DATA_SOURCE_DIR)/map_16/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,5,5 --tie=exchange --filter=3
$(MAP_DATA_SOURCE_DIR)/map_16/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,4,7
$(MAP_DATA_SOURCE_DIR)/map_17/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 9,11,13 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_17/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz0 5,6
$(MAP_DATA_SOURCE_DIR)/map_17/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,8,11 --tie=exchange --filter=3
$(MAP_DATA_SOURCE_DIR)/map_17/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,6,10 --tie=exchange --filter=3
$(MAP_DATA_SOURCE_DIR)/map_17/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,7 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_17/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,4,6
$(MAP_DATA_SOURCE_DIR)/map_55/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,7,9 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_55/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,8,10 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_55/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,9,7 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_62/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,6,8
$(MAP_DATA_SOURCE_DIR)/map_62/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,8
$(MAP_DATA_SOURCE_DIR)/map_63/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 2,5,7 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_63/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,7 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_64/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,8 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_64/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,7,8 --tie=quick
$(MAP_DATA_SOURCE_DIR)/map_65/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,7,8
$(MAP_DATA_SOURCE_DIR)/map_65/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,5,9 --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_49/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,7,9 --tie=reverse
$(MAP_DATA_SOURCE_DIR)/map_49/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,6,7,10 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_49/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,6,9,9 --filter=4
$(MAP_DATA_SOURCE_DIR)/map_48/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,10,13 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_48/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,6 --tie=reverse-select --filter=3
$(MAP_DATA_SOURCE_DIR)/map_46/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,9
$(MAP_DATA_SOURCE_DIR)/map_46/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,8,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_46/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,5,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_47/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,6,8
$(MAP_DATA_SOURCE_DIR)/map_47/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,9 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_47/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 4,5,8 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_46/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,10,13 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_46/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,5,6 --filter=3

%.lz: % $(FOMT_LZ_TOOL)
	@$(if $(FOMT_LZ_ENCODE),$(FOMT_LZ_TOOL) $(firstword $(FOMT_LZ_ENCODE)) $< $@ $(wordlist 2,99,$(FOMT_LZ_ENCODE)),$(error Missing FoMT codec parameters for $@))

$(UI_SCENE_08077810_CHARACTER_PACKED): $(UI_SCENE_08077810_CHARACTER_TILES) $(UI_SCENE_08077810_CHARACTER_TRAILER) $(FOMT_LZ_TOOL)
	@$(FOMT_LZ_TOOL) encode-huff8-lz3 $< $@ 6,10,12 --greedy --tie=exchange --tail=$(UI_SCENE_08077810_CHARACTER_TRAILER)

$(MAP_STATE_PALETTE_SOURCE_DIR)/%.gbapal.lz: $(MAP_STATE_PALETTE_SOURCE_DIR)/%.gbapal $(FOMT_LZ_TOOL)
	@$(FOMT_LZ_TOOL) encode-lz3 $< $@ $(FOMT_LZ3_ARGS)

$(INTRO_INDEXED_ARCHIVE_TITLE_TILES): GFX_TILE_COUNT := $(if $(filter jp,$(INTRO_INDEXED_ARCHIVE_GROUP)),361,237)
$(INTRO_INDEXED_ARCHIVE_FRAME_TILES): GFX_TILE_COUNT := $(if $(filter jp,$(INTRO_INDEXED_ARCHIVE_GROUP)),88,$(if $(filter de,$(INTRO_INDEXED_ARCHIVE_GROUP)),97,95))
$(filter-out $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/palettes_00_15.gbapal,$(INTRO_INDEXED_ARCHIVE_PALETTES)): GFX_PALETTE_COLORS := $(if $(filter jp,$(INTRO_INDEXED_ARCHIVE_GROUP)),32,48)
$(INTRO_INDEXED_ARCHIVE_SOURCE_OBJ): $(INTRO_INDEXED_ARCHIVE_LAYOUT) $(INTRO_INDEXED_ARCHIVE_TITLE_TILES) $(INTRO_INDEXED_ARCHIVE_FRAME_TILES) $(INTRO_INDEXED_ARCHIVE_PALETTES)
	@mkdir -p $(dir $@)
	@$(CPP) $(CPPFLAGS) -D__ASSEMBLER__ -x assembler-with-cpp $< -o $(@:.o=.s)
	@$(AS) $(ASFLAGS) $(@:.o=.s) -o $@
$(INTRO_INDEXED_ARCHIVE_SOURCE_BIN): $(INTRO_INDEXED_ARCHIVE_SOURCE_OBJ)
	@$(OBJCOPY) -O binary $< $@

$(INTRO_SCENE_SIZE_HEADER): $(INTRO_INDEXED_ARCHIVE_SOURCE_BIN) graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@printf '#define INTRO_SCENE_RESOURCE_BYTES %s\n' "$$(wc -c < $<)" > $@
ifeq ($(GAME_REGION),JP)
$(INTRO_INDEXED_ARCHIVE_OUTPUT): FOMT_LZ_ENCODE := encode-huff4-lz2 3,6,8,10,12,13,15
else
$(INTRO_INDEXED_ARCHIVE_OUTPUT): FOMT_LZ_ENCODE := encode-huff8-lz2 3,6,8,10,11,13,15 --tie=exchange
endif

# Reuse the existing generated-size-header mechanism. The allocator reserves
# a power-of-two count of 32-byte OBJ tile units, rounded up for the payload.
$(UI_GRAPHICS_SIZE_HEADER): graphics/ui/shared_resource/shared_resource.4bpp graphics/ui/shared_resource/shared_resource.gbapal $(UI_HAND_CURSOR_TILES) graphics_file_rules.mk
	@mkdir -p $(dir $@)
	@shared_tiles=$$(wc -c < graphics/ui/shared_resource/shared_resource.4bpp); shared_palettes=$$(wc -c < graphics/ui/shared_resource/shared_resource.gbapal); \
	bytes=$$(wc -c < $(UI_HAND_CURSOR_TILES)); units=$$((($$bytes + 31) / 32)); shift=0; capacity=1; \
	while [ $$capacity -lt $$units ]; do capacity=$$(($$capacity * 2)); shift=$$(($$shift + 1)); done; \
	printf '#define UI_SHARED_TILE_BYTES %s\n#define UI_SHARED_PALETTE_BYTES %s\n#define UI_HAND_CURSOR_TILE_BYTES %s\n#define UI_HAND_CURSOR_TILE_SIZE_SHIFT %s\n' "$$shared_tiles" "$$shared_palettes" "$$bytes" "$$shift" > $@

# Standard source-adjacent conversions mirror pret's graphics_file_rules.mk.
# Assets that need exact record packing or a retail-compatible compressor keep
# dedicated rules above; ordinary PNG-derived files use these shared rules.
%.1bpp: %.png $(GFX_TOOL)
	@$(GFX_TOOL) $< $@

%.4bpp: %.png $(GFX_TOOL)
	@$(GFX_TOOL) $< $@ $(if $(GFX_TILE_COUNT),-num_tiles $(GFX_TILE_COUNT))

%.8bpp: %.png $(GFX_TOOL)
	@$(GFX_TOOL) $< $@ $(if $(GFX_TILE_COUNT),-num_tiles $(GFX_TILE_COUNT))

%.gbapal: %.pal $(GFX_TOOL)
	@$(GFX_TOOL) $< $@ $(if $(GFX_PALETTE_COLORS),-num_colors $(GFX_PALETTE_COLORS))
