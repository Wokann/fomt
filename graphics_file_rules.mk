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

# Intro Scene object tiles are twenty independently packed, byte-identical
# Raw-LZ streams.  Their 0x500-byte decoded sources preserve native tile
# order; OAM composition is deliberately kept separate until it is proven.
INTRO_OBJECTS_SOURCE_DIR := graphics/intro_scene/shared/object_tiles
INTRO_OBJECTS_REGION := $(shell echo "$(GAME_REGION)" | tr '[:upper:]' '[:lower:]')

# The earlier Intro Scene setup function creates two interleaved 32-by-32 BG
# tilemaps from each 0x1000-byte Huffman-4/LZ3 source.  Keep the native
# interleaving as editable source until the compositor's palette/layout rules
# are proven.
INTRO_STARTUP_TILEMAPS_SOURCE_DIR := graphics/intro_scene/shared/startup_tilemaps

# func_08000914 expands this regional IndexedResourceArchive immediately
# after the Intro Scene background data. Complete frames are composed from
# the archive's own OAM records, so no JSON layout sidecar is necessary.
INTRO_INDEXED_ARCHIVE_SOURCE_ROOT := graphics/intro_scene/indexed_archive
INTRO_INDEXED_ARCHIVE_GROUP := $(if $(filter US EU,$(GAME_REGION)),us_eu,$(INTRO_OBJECTS_REGION))
INTRO_INDEXED_ARCHIVE_SOURCE_DIR := $(INTRO_INDEXED_ARCHIVE_SOURCE_ROOT)/$(INTRO_INDEXED_ARCHIVE_GROUP)
INTRO_INDEXED_ARCHIVE_LAYOUT := $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/archive.inc
INTRO_INDEXED_ARCHIVE_TITLE_TILES := $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/title_tiles.8bpp
INTRO_INDEXED_ARCHIVE_FRAME_TILES := $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/frame_tiles.4bpp
INTRO_INDEXED_ARCHIVE_PALETTES := $(patsubst %.pal,%.gbapal,$(wildcard $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/palettes_*.pal))
INTRO_INDEXED_ARCHIVE_OUTPUT := $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/archive.lz
INTRO_INDEXED_ARCHIVE_SOURCE_OBJ := $(BUILD_DIR)/graphics/intro_scene/indexed_archive/archive.o
INTRO_INDEXED_ARCHIVE_SOURCE_BIN := $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/archive.bin

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

UI_SCENE_0805AB08_TILES_SOURCE_DIR := graphics/ui/scene_0805ab08_tiles/shared
UI_SCENE_0805AB08_TILES_SOURCE := $(UI_SCENE_0805AB08_TILES_SOURCE_DIR)/tiles.4bpp
UI_SCENE_0805AB08_TILES_OUTPUT := $(UI_SCENE_0805AB08_TILES_SOURCE).lz

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
$(MAP_STATE_PALETTE_SOURCE_DIR)/fallback_00.gbapal.lz: FOMT_LZ3_ARGS := 145 0xA0
$(MAP_STATE_PALETTE_SOURCE_DIR)/fallback_01.gbapal.lz: FOMT_LZ3_ARGS := 147 0x8C
$(MAP_STATE_PALETTE_SOURCE_DIR)/fallback_02.gbapal.lz: FOMT_LZ3_ARGS := 456 0x98
$(MAP_STATE_PALETTE_SOURCE_DIR)/fallback_03.gbapal.lz: FOMT_LZ3_ARGS := 456 0x94
$(MAP_STATE_PALETTE_SOURCE_DIR)/fallback_04.gbapal.lz: FOMT_LZ3_ARGS := 147 0x94

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

# These known native streams share one source-to-packed rule.  Only the codec
# variant, tested encoder search ladder, and original slot size vary by asset.
# Keeping those values as target metadata avoids one shell recipe per stream.
FOMT_LZ_ENCODE_OUTPUTS := $(addsuffix .lz, \
  $(UI_SCENE_080A2BA4_SOURCE_DIR)/layer_0.tilemap \
  $(UI_SCENE_080A2BA4_SOURCE_DIR)/layer_1.tilemap \
  $(UI_SCENE_080A2BA4_SOURCE_DIR)/layer_2.tilemap \
  $(UI_SCENE_080A2BA4_SOURCE_DIR)/tiles.4bpp \
  $(UI_SCENE_080AE7D0_MAP0_SOURCE) $(UI_SCENE_080AE7D0_MAP1_SOURCE) $(UI_SCENE_080AE7D0_TILES_SOURCE) \
  $(UI_SCENE_080B7164_MAP0_SOURCE) $(UI_SCENE_080B7164_MAP1_SOURCE) $(UI_SCENE_080B7164_TILES_SOURCE) \
  $(UI_SCENE_080C160C_MAP0_SOURCE) $(UI_SCENE_080C160C_MAP1_SOURCE) $(UI_SCENE_080C160C_TILES_SOURCE) \
  $(UI_SCENE_080BCFAC_MAP0_SOURCE) $(UI_SCENE_080BCFAC_MAP1_SOURCE) $(UI_SCENE_080BCFAC_TILES_SOURCE) \
  $(UI_SCENE_080B55D0_AUX_MAP0_SOURCE) $(UI_SCENE_080B55D0_AUX_MAP1_SOURCE) $(UI_SCENE_080B55D0_AUX_TILES_SOURCE) \
  $(UI_SCENE_08054F40_TILES_SOURCE) $(UI_SCENE_0805AB08_TILES_SOURCE) \
  $(INTRO_BACKGROUND_TILES_BIN) \
  graphics/intro_scene/shared/startup_visual/startup_tiles.4bpp \
  graphics/ui/farm_status/shared/base_tiles.4bpp \
  graphics/ui/seasonal_background/winter/winter_tiles.4bpp \
  $(UI_SCENE_080B55D0_MAIN_SOURCE) \
  $(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/startup_00.tilemap \
  $(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/startup_01.tilemap \
  $(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/startup_02.tilemap \
  $(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/startup_03.tilemap \
  $(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_00.tilemap \
  $(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_01.tilemap \
  $(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_02.tilemap \
  $(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_03.tilemap \
  $(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_04.tilemap \
  $(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_05.tilemap \
  $(UI_SCENE_08077810_LAYER0_SOURCE) $(UI_SCENE_08077810_LAYER1_SOURCE) \
  $(UI_SCENE_08077810_JP_TILES) $(UI_SCENE_08077810_JP_LAYER1_SOURCE) \
  $(addprefix $(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_,$(addsuffix .4bpp,00 01 02 03 05 06)) \
  $(addprefix $(MAP_DATA_SOURCE_DIR)/map_,$(addsuffix /layer_0.4bpp,08 09 14 36 44 53)) \
  $(addprefix $(INTRO_OBJECTS_SOURCE_DIR)/object_,$(addsuffix .4bpp,00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19)) \
  $(MAP_DATA_SOURCE_DIR)/map_08/layer_1.gbapal $(MAP_DATA_SOURCE_DIR)/map_08/layer_2.gbapal \
  $(MAP_DATA_SOURCE_DIR)/map_09/layer_1.gbapal $(MAP_DATA_SOURCE_DIR)/map_09/layer_2.gbapal \
  $(MAP_DATA_SOURCE_DIR)/map_09/layer_5.tilemap $(MAP_DATA_SOURCE_DIR)/map_31/layer_5.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_08/layer_4.tilemap $(MAP_DATA_SOURCE_DIR)/map_08/layer_5.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_09/layer_4.tilemap $(MAP_DATA_SOURCE_DIR)/map_31/layer_4.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_44/layer_4.tilemap $(MAP_DATA_SOURCE_DIR)/map_45/layer_4.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_15/layer_1.gbapal $(MAP_DATA_SOURCE_DIR)/map_36/layer_1.gbapal \
  $(MAP_DATA_SOURCE_DIR)/map_44/layer_5.tilemap $(MAP_DATA_SOURCE_DIR)/map_45/layer_5.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_14/layer_1.gbapal $(MAP_DATA_SOURCE_DIR)/map_14/layer_2.gbapal \
  $(MAP_DATA_SOURCE_DIR)/map_14/layer_4.tilemap $(MAP_DATA_SOURCE_DIR)/map_14/layer_5.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_15/layer_4.tilemap $(MAP_DATA_SOURCE_DIR)/map_08/layer_3.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_44/layer_1.gbapal $(MAP_DATA_SOURCE_DIR)/map_44/layer_3.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_45/layer_3.tilemap $(MAP_DATA_SOURCE_DIR)/map_31/layer_3.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_09/layer_3.tilemap $(MAP_DATA_SOURCE_DIR)/map_40/layer_4.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_15/layer_2.gbapal $(MAP_DATA_SOURCE_DIR)/map_40/layer_3.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_53/layer_1.gbapal $(MAP_DATA_SOURCE_DIR)/map_15/layer_5.tilemap \
  $(MAP_DATA_SOURCE_DIR)/map_40/layer_5.tilemap)

$(UI_SCENE_080A2BA4_SOURCE_DIR)/layer_0.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 125 0x28
$(UI_SCENE_080A2BA4_SOURCE_DIR)/layer_1.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1234679 0xB0
$(UI_SCENE_080A2BA4_SOURCE_DIR)/layer_2.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1234679 0x64
$(UI_SCENE_080A2BA4_SOURCE_DIR)/tiles.4bpp.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,5,6,8,10,12 0x29C
$(UI_SCENE_080AE7D0_MAP0_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 3,5,6,7,8,9,10 0x238
$(UI_SCENE_080AE7D0_MAP1_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 2,5,10 0x8C
$(UI_SCENE_080AE7D0_TILES_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,5,7,10,11,13,15 0x1A48
$(UI_SCENE_080B7164_MAP0_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 3,5,7 0x64
$(UI_SCENE_080B7164_MAP1_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9 0xA8
$(UI_SCENE_080B7164_TILES_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,5,7,8,10,11,12 0x70C
$(UI_SCENE_080C160C_MAP0_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,3,6,7,9,10,11 0x20C
$(UI_SCENE_080C160C_MAP1_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 3,7,9 0xD8
$(UI_SCENE_080C160C_TILES_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,4,6,7,8,10,12 0xA38 --literal-tail
$(UI_SCENE_080BCFAC_MAP0_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 2,6,10 0x124
$(UI_SCENE_080BCFAC_MAP1_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 1,6,9 0xA8
$(UI_SCENE_080BCFAC_TILES_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,5,6,7,9,11,13 0xC04
$(UI_SCENE_080B55D0_AUX_MAP0_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 1,2,5 0x16C
$(UI_SCENE_080B55D0_AUX_MAP1_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9 0x110
$(UI_SCENE_080B55D0_AUX_TILES_SOURCE).lz: FOMT_LZ_ENCODE := encode-lz2 2,5,8,9,10,11,12 0xD60
$(UI_SCENE_08054F40_TILES_OUTPUT): FOMT_LZ_ENCODE := encode-lz2 2,5,7,8,10,13,14 0xCA8
$(UI_SCENE_0805AB08_TILES_OUTPUT): FOMT_LZ_ENCODE := encode-lz2 3,5,7,10,11,12,14 0x880
$(INTRO_BACKGROUND_PACKED_BIN): FOMT_LZ_ENCODE := encode-lz2 3,5,8,10,12,13,15 0x49BC --literal-tail
graphics/intro_scene/shared/startup_visual/startup_tiles.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,10,14 0 --greedy --tie=exchange
graphics/ui/farm_status/shared/base_tiles.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,8,13 0 --greedy --tie=exchange
graphics/ui/seasonal_background/winter/winter_tiles.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,10,13 0 --greedy --tie=exchange
$(UI_SCENE_080B55D0_MAIN_SOURCE).lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,10,12 0 --greedy --tie=exchange
$(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/startup_00.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,7,9 0x3DC --parent-first
$(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/startup_01.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,7,9 0x21C --tie=first
$(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/startup_02.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,8,11 0xF4
$(INTRO_STARTUP_TILEMAPS_SOURCE_DIR)/startup_03.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,7,10 0 --tie=quick
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_00.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,8,12 0 --tie=heap
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_01.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,6,11 0x1D8
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_02.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,6,10 0 --tie=exchange
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_03.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,8,12 0 --tie=heap-sort
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_04.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,8,11 0x1D0
$(FARM_STATUS_SECONDARY_TILEMAP_SOURCE_DIR)/secondary_05.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,6,10 0 --tie=exchange
$(UI_SCENE_08077810_LAYER0_PACKED): FOMT_LZ_ENCODE := encode-huff4-lz3 1,5,9 0x16C
$(UI_SCENE_08077810_LAYER1_PACKED): FOMT_LZ_ENCODE := encode-huff4-lz0 1,10 0
$(UI_SCENE_08077810_JP_TILES_PACKED): FOMT_LZ_ENCODE := encode-huff4-lz3 1,4,10 0x4C0
$(UI_SCENE_08077810_JP_LAYER1_PACKED): FOMT_LZ_ENCODE := encode-huff4-lz2 1,2,3,4,5,6,10 0 --tie=last
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_00.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 1,4,8 0 --greedy --tie=exchange
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_01.4bpp.lz: FOMT_LZ_ENCODE := encode-huff4-lz2 2,4,5,6,7,8,11 0x424 --filter=1
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_02.4bpp.lz: FOMT_LZ_ENCODE := encode-huff4-lz2 2,4,5,6,7,8,10 0x418 --filter=1
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_03.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 1,8,11 0 --greedy --tie=exchange
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_05.4bpp.lz: FOMT_LZ_ENCODE := encode-huff4-lz2 2,4,5,6,7,8,8 0x364
$(FARM_HOUSE_VISUAL_SOURCE_DIR)/visual_06.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 1,8,12 0 --greedy --tie=exchange

# All 17 of these retail Raw-LZ3 streams were rebuilt directly and matched
# their original packed bytes; their .original.lz copies are audit-only now.
$(INTRO_OBJECTS_SOURCE_DIR)/object_01.4bpp.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9 0x54
$(INTRO_OBJECTS_SOURCE_DIR)/object_03.4bpp.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9 0x6C
$(INTRO_OBJECTS_SOURCE_DIR)/object_05.4bpp.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9 0x98
$(INTRO_OBJECTS_SOURCE_DIR)/object_07.4bpp.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9 0x78
$(INTRO_OBJECTS_SOURCE_DIR)/object_08.4bpp.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,7 0x94
$(INTRO_OBJECTS_SOURCE_DIR)/object_09.4bpp.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9 0x60
$(INTRO_OBJECTS_SOURCE_DIR)/object_11.4bpp.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9 0x74
$(INTRO_OBJECTS_SOURCE_DIR)/object_12.4bpp.lz: FOMT_LZ_ENCODE := encode-lz3 5,8,10 0x26C
$(INTRO_OBJECTS_SOURCE_DIR)/object_14.4bpp.lz: FOMT_LZ_ENCODE := encode-lz3 5,8,10 0x274
$(INTRO_OBJECTS_SOURCE_DIR)/object_17.4bpp.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9 0x50
$(INTRO_OBJECTS_SOURCE_DIR)/object_19.4bpp.lz: FOMT_LZ_ENCODE := encode-lz3 5,8,10 0x68
# These six Raw-LZ2 objects also match their original packed slots exactly.
$(INTRO_OBJECTS_SOURCE_DIR)/object_02.4bpp.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,4,6,7,8,9 0xF4
$(INTRO_OBJECTS_SOURCE_DIR)/object_04.4bpp.lz: FOMT_LZ_ENCODE := encode-lz2 1,4,5,6,7,8,9 0x140
$(INTRO_OBJECTS_SOURCE_DIR)/object_06.4bpp.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,4,6,7,8,10 0x120
$(INTRO_OBJECTS_SOURCE_DIR)/object_10.4bpp.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,4,6,7,8,9 0xD8
$(INTRO_OBJECTS_SOURCE_DIR)/object_13.4bpp.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,5,6,10 0x24
$(INTRO_OBJECTS_SOURCE_DIR)/object_15.4bpp.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,3,4,6,8,10 0x38
# The remaining three object slots use the same direct source-to-stream rule.
$(INTRO_OBJECTS_SOURCE_DIR)/object_00.4bpp.lz: FOMT_LZ_ENCODE := encode-lz1 2,6,8,10 0x2FC
$(INTRO_OBJECTS_SOURCE_DIR)/object_16.4bpp.lz: FOMT_LZ_ENCODE := encode-lz1 4,6,8,10 0x304
$(INTRO_OBJECTS_SOURCE_DIR)/object_18.4bpp.lz: FOMT_LZ_ENCODE := encode-lz1 4,6,9,11 0x30C
$(MAP_DATA_SOURCE_DIR)/map_08/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,5 0xE0
$(MAP_DATA_SOURCE_DIR)/map_08/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,9,14 0 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_09/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,9,13 0 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_14/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 6,11,14 0 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_36/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,9,13 0 --greedy --tie=exchange
$(MAP_DATA_SOURCE_DIR)/map_44/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 5,10,13 0 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_53/layer_0.4bpp.lz: FOMT_LZ_ENCODE := encode-huff8-lz3 4,9,12 0 --greedy --tie=exchange --filter=1
$(MAP_DATA_SOURCE_DIR)/map_08/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 4,5,4 0xE4
$(MAP_DATA_SOURCE_DIR)/map_09/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 4,5,7 0xD8
$(MAP_DATA_SOURCE_DIR)/map_09/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-lz3 4,5,7 0xCC
$(MAP_DATA_SOURCE_DIR)/map_09/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,6,12 0x6C
$(MAP_DATA_SOURCE_DIR)/map_31/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 3,6,11 0xEC
$(MAP_DATA_SOURCE_DIR)/map_44/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 3,5,9 0xD4 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_45/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz3 1,5,9 0x90 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_08/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,4,7,8,9,12 0x260 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_08/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,3,4,7,10,12,7 0x7C --filter=3
$(MAP_DATA_SOURCE_DIR)/map_09/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,2,4,7,8,9,12 0x224 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_31/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 1,4,5,6,7,9,7 0x104 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_44/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,6,7,9 0x134 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_45/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-lz2 2,3,4,5,7,8,10 0x174 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_15/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz0 6,6 0xF8
$(MAP_DATA_SOURCE_DIR)/map_36/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-lz0 6,8 0x124
$(MAP_DATA_SOURCE_DIR)/map_14/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,5,5 0xF8 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_14/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,4,6 0xD8
$(MAP_DATA_SOURCE_DIR)/map_14/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,10,14 0xC6C
$(MAP_DATA_SOURCE_DIR)/map_14/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 9,11,13 0x7D8 --tie=reverse
$(MAP_DATA_SOURCE_DIR)/map_15/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,10,14 0xC68 --tie=first
$(MAP_DATA_SOURCE_DIR)/map_08/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 7,9,12 0x71C
$(MAP_DATA_SOURCE_DIR)/map_44/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,5,7 0x108 --filter=3
$(MAP_DATA_SOURCE_DIR)/map_44/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 5,7,9 0x254 --filter=4 --tie=first
$(MAP_DATA_SOURCE_DIR)/map_45/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,5,8 0x220
$(MAP_DATA_SOURCE_DIR)/map_31/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,7,11 0x320 --filter=3 --tie=first
$(MAP_DATA_SOURCE_DIR)/map_09/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 6,9,12 0x704 --parent-first
$(MAP_DATA_SOURCE_DIR)/map_40/layer_4.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,5,9 0x158 --tie=reverse --parent-first
$(MAP_DATA_SOURCE_DIR)/map_15/layer_2.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 1,4,6 0 --tie=last
$(MAP_DATA_SOURCE_DIR)/map_40/layer_3.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 3,7,9 0 --tie=last
$(MAP_DATA_SOURCE_DIR)/map_53/layer_1.gbapal.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 4,7,5 0 --filter=3 --tie=last
$(MAP_DATA_SOURCE_DIR)/map_15/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 8,10,14 0 --tie=reverse-select
$(MAP_DATA_SOURCE_DIR)/map_40/layer_5.tilemap.lz: FOMT_LZ_ENCODE := encode-huff4-lz3 2,5,7 0 --tie=shell

$(FOMT_LZ_ENCODE_OUTPUTS): %.lz: % $(FOMT_LZ_TOOL)
	@$(FOMT_LZ_TOOL) $(firstword $(FOMT_LZ_ENCODE)) $< $@ $(wordlist 2,99,$(FOMT_LZ_ENCODE))

$(UI_SCENE_08077810_CHARACTER_PACKED): $(UI_SCENE_08077810_CHARACTER_TILES) $(UI_SCENE_08077810_CHARACTER_TRAILER) $(FOMT_LZ_TOOL)
	@$(FOMT_LZ_TOOL) encode-huff8-lz3 $< $@ 6,10,12 0 --greedy --tie=exchange --tail=$(UI_SCENE_08077810_CHARACTER_TRAILER)

$(MAP_STATE_PALETTE_SOURCE_DIR)/%.gbapal.lz: $(MAP_STATE_PALETTE_SOURCE_DIR)/%.gbapal $(FOMT_LZ_TOOL)
	@$(FOMT_LZ_TOOL) encode-lz3 $< $@ $(FOMT_LZ3_ARGS)

$(INTRO_INDEXED_ARCHIVE_TITLE_TILES): GFX_TILE_COUNT := $(if $(filter jp,$(INTRO_INDEXED_ARCHIVE_GROUP)),361,237)
$(INTRO_INDEXED_ARCHIVE_FRAME_TILES): GFX_TILE_COUNT := $(if $(filter jp,$(INTRO_INDEXED_ARCHIVE_GROUP)),88,$(if $(filter de,$(INTRO_INDEXED_ARCHIVE_GROUP)),97,95))
$(filter-out $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/palettes_00_15.gbapal,$(INTRO_INDEXED_ARCHIVE_PALETTES)): GFX_PALETTE_COLORS := $(if $(filter jp,$(INTRO_INDEXED_ARCHIVE_GROUP)),32,48)
$(INTRO_INDEXED_ARCHIVE_SOURCE_OBJ): $(INTRO_INDEXED_ARCHIVE_LAYOUT) $(INTRO_INDEXED_ARCHIVE_TITLE_TILES) $(INTRO_INDEXED_ARCHIVE_FRAME_TILES) $(INTRO_INDEXED_ARCHIVE_PALETTES)
	@mkdir -p $(dir $@)
	@$(AS) $(ASFLAGS) $< -o $@
$(INTRO_INDEXED_ARCHIVE_SOURCE_BIN): $(INTRO_INDEXED_ARCHIVE_SOURCE_OBJ)
	@$(OBJCOPY) -O binary $< $@
ifeq ($(GAME_REGION),JP)
$(INTRO_INDEXED_ARCHIVE_OUTPUT): $(INTRO_INDEXED_ARCHIVE_SOURCE_BIN) $(FOMT_LZ_TOOL)
	@$(FOMT_LZ_TOOL) encode-huff4-lz2 $< $@ 3,6,8,10,12,13,15 0x2D90
else
# The overseas Huffman-8 tie order is not yet byte-identical. Do not replace
# its original packing input with a merely valid but different encoding.
INTRO_INDEXED_ARCHIVE_ORIGINAL := $(INTRO_INDEXED_ARCHIVE_SOURCE_DIR)/archive.original.lz
$(INTRO_INDEXED_ARCHIVE_OUTPUT): $(INTRO_INDEXED_ARCHIVE_SOURCE_BIN) $(INTRO_INDEXED_ARCHIVE_ORIGINAL) $(FOMT_LZ_TOOL)
	@$(FOMT_LZ_TOOL) rebuild-native $< $(INTRO_INDEXED_ARCHIVE_ORIGINAL) $@
endif

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

# FoMT's native packed streams retain their original slot metadata beside the
# editable tiles or tilemap. The same codec and rule serve every region.
%.4bpp.lz: %.4bpp %.original.lz $(FOMT_LZ_TOOL)
	@$(FOMT_LZ_TOOL) rebuild-native $< $(word 2,$^) $@

%.tilemap.lz: %.tilemap %.original.lz $(FOMT_LZ_TOOL)
	@$(FOMT_LZ_TOOL) rebuild-native $< $(word 2,$^) $@

%.gbapal.lz: %.gbapal %.original.lz $(FOMT_LZ_TOOL)
	@$(FOMT_LZ_TOOL) rebuild-native $< $(word 2,$^) $@
