    @ The Records Screen task resources are seven raw 16x16 4bpp grids and
    @ matching 16-colour palettes.  All four retail localizations contain
    @ identical payloads; keep the region-specific build paths explicit.
    .macro FOMT_RECORDS_TASK_TILES_00
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_00.4bpp"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_00.4bpp"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_00.4bpp"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_00.4bpp"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_TILES_01
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_01.4bpp"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_01.4bpp"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_01.4bpp"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_01.4bpp"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_TILES_02
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_02.4bpp"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_02.4bpp"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_02.4bpp"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_02.4bpp"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_TILES_03
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_03.4bpp"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_03.4bpp"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_03.4bpp"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_03.4bpp"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_TILES_04
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_04.4bpp"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_04.4bpp"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_04.4bpp"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_04.4bpp"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_TILES_05
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_05.4bpp"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_05.4bpp"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_05.4bpp"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_05.4bpp"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_TILES_06
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_06.4bpp"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_06.4bpp"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_06.4bpp"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_06.4bpp"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_TILES index
    .if \index == 0
    FOMT_RECORDS_TASK_TILES_00
    .elseif \index == 1
    FOMT_RECORDS_TASK_TILES_01
    .elseif \index == 2
    FOMT_RECORDS_TASK_TILES_02
    .elseif \index == 3
    FOMT_RECORDS_TASK_TILES_03
    .elseif \index == 4
    FOMT_RECORDS_TASK_TILES_04
    .elseif \index == 5
    FOMT_RECORDS_TASK_TILES_05
    .elseif \index == 6
    FOMT_RECORDS_TASK_TILES_06
    .else
    .error "invalid Records Screen task icon index"
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_PALETTE_00
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_00.gbapal"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_00.gbapal"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_00.gbapal"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_00.gbapal"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_PALETTE_01
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_01.gbapal"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_01.gbapal"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_01.gbapal"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_01.gbapal"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_PALETTE_02
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_02.gbapal"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_02.gbapal"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_02.gbapal"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_02.gbapal"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_PALETTE_03
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_03.gbapal"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_03.gbapal"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_03.gbapal"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_03.gbapal"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_PALETTE_04
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_04.gbapal"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_04.gbapal"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_04.gbapal"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_04.gbapal"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_PALETTE_05
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_05.gbapal"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_05.gbapal"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_05.gbapal"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_05.gbapal"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_PALETTE_06
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/records_minigame/task_06.gbapal"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/records_minigame/task_06.gbapal"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/records_minigame/task_06.gbapal"
    .else
    .incbin "build/us/graphics/ui/records_minigame/task_06.gbapal"
    .endif
    .endif
    .endif
    .endm
    .macro FOMT_RECORDS_TASK_PALETTE index
    .if \index == 0
    FOMT_RECORDS_TASK_PALETTE_00
    .elseif \index == 1
    FOMT_RECORDS_TASK_PALETTE_01
    .elseif \index == 2
    FOMT_RECORDS_TASK_PALETTE_02
    .elseif \index == 3
    FOMT_RECORDS_TASK_PALETTE_03
    .elseif \index == 4
    FOMT_RECORDS_TASK_PALETTE_04
    .elseif \index == 5
    FOMT_RECORDS_TASK_PALETTE_05
    .elseif \index == 6
    FOMT_RECORDS_TASK_PALETTE_06
    .else
    .error "invalid Records Screen task palette index"
    .endif
    .endm

    @ The Farm Status previews are native BG tilemaps.  They remain separate
    @ from the shared 4bpp tile grid because every entry carries a tile ID,
    @ flip bits and a palette-bank selector.  The generated bundle follows
    @ PREVIEWS/VARIANTS order in tools/farm_status_tilemaps.py.
    .macro FOMT_FARM_STATUS_TILEMAP offset, length
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/farm_status/preview_tilemaps.bin", \offset, \length
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/farm_status/preview_tilemaps.bin", \offset, \length
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/farm_status/preview_tilemaps.bin", \offset, \length
    .else
    .incbin "build/us/graphics/ui/farm_status/preview_tilemaps.bin", \offset, \length
    .endif
    .endif
    .endif
    .endm

    @ func_0806EC94 copies one raw exterior-style record into the Farm Status
    @ BG tile grid.  Each rebuilt file retains its native two-u16 header and
    @ all three style payloads, so the original style selector stays intact.
    .macro FOMT_FARM_STATUS_EXTERIOR_STYLE name
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/farm_status/exterior_styles/\name\().4bpp"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/farm_status/exterior_styles/\name\().4bpp"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/farm_status/exterior_styles/\name\().4bpp"
    .else
    .incbin "build/us/graphics/ui/farm_status/exterior_styles/\name\().4bpp"
    .endif
    .endif
    .endif
    .endm

    @ Code-backed static BG tile streams.  The routines that load these
    @ symbols consume the assembled payloads, rather than preview-only copies.
    .macro FOMT_UI_SCENE_08054F40_TILES
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/scene_08054f40_tiles/tiles.4bpp.0x70"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/scene_08054f40_tiles/tiles.4bpp.0x70"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/scene_08054f40_tiles/tiles.4bpp.0x70"
    .else
    .incbin "build/us/graphics/ui/scene_08054f40_tiles/tiles.4bpp.0x70"
    .endif
    .endif
    .endif
    .endm

    .macro FOMT_UI_SCENE_0805AB08_TILES
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/scene_0805ab08_tiles/tiles.4bpp.0x70"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/scene_0805ab08_tiles/tiles.4bpp.0x70"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/scene_0805ab08_tiles/tiles.4bpp.0x70"
    .else
    .incbin "build/us/graphics/ui/scene_0805ab08_tiles/tiles.4bpp.0x70"
    .endif
    .endif
    .endif
    .endm

    @ Four independently bounded inputs of func_080AE7D0.  Keep the source
    @ name as a macro argument so all regional branches select the same
    @ verified asset without duplicating the original data symbols.
    .macro FOMT_UI_SCENE_080AE7D0_ASSET file
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/scene_080ae7d0/\file"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/scene_080ae7d0/\file"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/scene_080ae7d0/\file"
    .else
    .incbin "build/us/graphics/ui/scene_080ae7d0/\file"
    .endif
    .endif
    .endif
    .endm

    .macro FOMT_UI_SCENE_080B7164_ASSET file
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/scene_080b7164/\file"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/scene_080b7164/\file"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/scene_080b7164/\file"
    .else
    .incbin "build/us/graphics/ui/scene_080b7164/\file"
    .endif
    .endif
    .endif
    .endm

    .macro FOMT_UI_SCENE_080C160C_ASSET file
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/scene_080c160c/\file"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/scene_080c160c/\file"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/scene_080c160c/\file"
    .else
    .incbin "build/us/graphics/ui/scene_080c160c/\file"
    .endif
    .endif
    .endif
    .endm

    .macro FOMT_UI_SCENE_080BCFAC_ASSET file
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/scene_080bcfac/\file"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/scene_080bcfac/\file"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/scene_080bcfac/\file"
    .else
    .incbin "build/us/graphics/ui/scene_080bcfac/\file"
    .endif
    .endif
    .endif
    .endm

    .macro FOMT_UI_SCENE_080B55D0_AUX_ASSET file
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/scene_080b55d0_aux/\file"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/scene_080b55d0_aux/\file"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/scene_080b55d0_aux/\file"
    .else
    .incbin "build/us/graphics/ui/scene_080b55d0_aux/\file"
    .endif
    .endif
    .endif
    .endm

    .macro FOMT_UI_SCENE_080A2BA4_ASSET file
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/scene_080a2ba4/\file"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/scene_080a2ba4/\file"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/scene_080a2ba4/\file"
    .else
    .incbin "build/us/graphics/ui/scene_080a2ba4/\file"
    .endif
    .endif
    .endif
    .endm

    @ This symbol exists only in the overseas code/data layout.  JP has a
    @ distinct startup implementation and must not consume this asset.
    .macro FOMT_UI_SCENE_08077810_TILEMAP
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/scene_08077810/layer_0.tilemap.0x70"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/scene_08077810/layer_0.tilemap.0x70"
    .else
    .incbin "build/us/graphics/ui/scene_08077810/layer_0.tilemap.0x70"
    .endif
    .endif
    .endm

    @ func_0806EC94 selects one of two three-layer 64x44 BG layouts.  Keep
    @ the native compressed streams separate because EU exposes header labels
    @ eight bytes before several payload labels.
    .macro FOMT_FARM_STATUS_SECONDARY_TILEMAP index, offset, length
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/farm_status/secondary_tilemaps/secondary_\index\().0x70", \offset, \length
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/farm_status/secondary_tilemaps/secondary_\index\().0x70", \offset, \length
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/farm_status/secondary_tilemaps/secondary_\index\().0x70", \offset, \length
    .else
    .incbin "build/us/graphics/ui/farm_status/secondary_tilemaps/secondary_\index\().0x70", \offset, \length
    .endif
    .endif
    .endif
    .endm

    @ The resource selector's case 9 has an independently paired 16x16 4bpp
    @ tile record and BGR555 palette.  Its name stays tied to the proven
    @ selector case until the owning UI state has a source-level name.
    .macro FOMT_FARM_STATUS_SELECTOR_CASE_09 extension
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/farm_status/auxiliary_icons/selector_case_09.\extension"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/farm_status/auxiliary_icons/selector_case_09.\extension"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/farm_status/auxiliary_icons/selector_case_09.\extension"
    .else
    .incbin "build/us/graphics/ui/farm_status/auxiliary_icons/selector_case_09.\extension"
    .endif
    .endif
    .endif
    .endm

    .macro FOMT_FARM_STATUS_WINTER_TILES offset, length
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/farm_status/winter_tiles.0x70", \offset, \length
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/farm_status/winter_tiles.0x70", \offset, \length
    .else
    .incbin "build/us/graphics/ui/farm_status/winter_tiles.0x70", \offset, \length
    .endif
    .endif
    .endm

    @ Animal Festival selects ten independent 16x16 4bpp icon records and
    @ their following BGR555 palettes.  The physical order is retained:
    @ callers address individual labels rather than a synthetic atlas.
    .macro FOMT_ANIMAL_FESTIVAL_ICON index, extension
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/animal_festival/icon_\index\().\extension"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/animal_festival/icon_\index\().\extension"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/animal_festival/icon_\index\().\extension"
    .else
    .incbin "build/us/graphics/ui/animal_festival/icon_\index\().\extension"
    .endif
    .endif
    .endif
    .endm

    @ Overseas UI code copies the first 0x1000 bytes as 128 individual
    @ 8x8/4bpp glyphs.  The final four native bytes are retained by the
    @ rebuilt record.  JP has no counterpart in this region-specific path.
    .macro FOMT_CLOCK_FONT
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/clock_font/clock_font.bin"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/clock_font/clock_font.bin"
    .else
    .incbin "build/us/graphics/ui/clock_font/clock_font.bin"
    .endif
    .endif
    .endm

    @ Two ten-record Farm Status creature/UI icon sequences are complete
    @ 16x16 4bpp grids with immediately following BGR555 palettes. Keep each
    @ physical sequence order: callers retain and select original labels.
    .macro FOMT_FARM_STATUS_CREATURE_ICON index, extension
    .ifdef REGION_JP
    .incbin "build/jp/graphics/ui/farm_status/creature_icons/icon_\index\().\extension"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/farm_status/creature_icons/icon_\index\().\extension"
    .else
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/farm_status/creature_icons/icon_\index\().\extension"
    .else
    .incbin "build/us/graphics/ui/farm_status/creature_icons/icon_\index\().\extension"
    .endif
    .endif
    .endif
    .endm

    .ifdef REGION_JP
    @ JP revision 0 counterpart of data_0813B288.s.
    @
    @ The original object is an asset-only incbin container.  JP retains that
    @ object boundary while using its independently matched JP asset range.

    .section .rodata
jp_data_0813b288_start:
    .incbin "baserom_jp.gba", 0x13C3CC, (0x2AD1F0 - 0x13C3CC)

    @ Resource archive referenced by the JP UI resource constructor.
    @ This is a physical label inside the otherwise still-raw asset stream,
    @ so code can retain a genuine relocation instead of an absolute word.
    .global gUnk_082AD1F0
gUnk_082AD1F0:
    .incbin "baserom_jp.gba", 0x2AD1F0, (0x2AD394 - 0x2AD1F0)
    FOMT_FARM_STATUS_SECONDARY_TILEMAP 00, 0, 0x110
    FOMT_FARM_STATUS_SECONDARY_TILEMAP 01, 0, 0x1D8
    FOMT_FARM_STATUS_SECONDARY_TILEMAP 02, 0, 0xB0

    @ Farm-status screen: the native stream expands to an 8bpp tile grid and
    @ is paired with its 256-colour background palette.  Keep these labels
    @ stable for the common screen code while sourcing their payloads from the
    @ verified editable graphics path.
    .global gUnk_085275D0
gUnk_085275D0:
    .incbin "build/jp/graphics/ui/farm_status/base_tiles.0x70"
    .global gUnk_08529794
gUnk_08529794:
    .incbin "build/jp/graphics/ui/farm_status/base_tiles.gbapal"
    FOMT_FARM_STATUS_EXTERIOR_STYLE doghouse

    @ Farm Status preview tilemap labels.  Every table entry selects one raw
    @ BG map; the non-map spans between them stay native ROM data.
    .global gUnk_082AFC74
gUnk_082AFC74:
    FOMT_FARM_STATUS_TILEMAP 0x2D0, 0x60
    .global gUnk_082AFCD4
gUnk_082AFCD4:
    FOMT_FARM_STATUS_TILEMAP 0x270, 0x30
    FOMT_FARM_STATUS_EXTERIOR_STYLE mailbox
    .global gUnk_082AFDC8
gUnk_082AFDC8:
    FOMT_FARM_STATUS_TILEMAP 0x120, 0xA8
    .global gUnk_082AFE70
gUnk_082AFE70:
    FOMT_FARM_STATUS_TILEMAP 0x060, 0x60
    .global gUnk_082AFED0
gUnk_082AFED0:
    FOMT_FARM_STATUS_TILEMAP 0x000, 0x30
    FOMT_FARM_STATUS_EXTERIOR_STYLE window
    .global gUnk_082B0744
gUnk_082B0744:
    FOMT_FARM_STATUS_TILEMAP 0x438, 0x9A
    .incbin "baserom_jp.gba", 0x2B07DE, 0x2
    .global gUnk_082B07E0
gUnk_082B07E0:
    FOMT_FARM_STATUS_TILEMAP 0x390, 0x54
    FOMT_FARM_STATUS_SECONDARY_TILEMAP 03, 0, 0x114
    FOMT_FARM_STATUS_SECONDARY_TILEMAP 04, 0, 0x1D0
    FOMT_FARM_STATUS_SECONDARY_TILEMAP 05, 0, 0xB0
    .incbin "baserom_jp.gba", 0x2B0BC8, (0x2B2F20 - 0x2B0BC8)
    .global gUnk_082B2F20
gUnk_082B2F20:
    FOMT_FARM_STATUS_TILEMAP 0x330, 0x60
    .global gUnk_082B2F80
gUnk_082B2F80:
    FOMT_FARM_STATUS_TILEMAP 0x2A0, 0x30
    .incbin "baserom_jp.gba", 0x2B2FB0, (0x2B3074 - 0x2B2FB0)
    .global gUnk_082B3074
gUnk_082B3074:
    FOMT_FARM_STATUS_TILEMAP 0x1C8, 0xA8
    .global gUnk_082B311C
gUnk_082B311C:
    FOMT_FARM_STATUS_TILEMAP 0x0C0, 0x60
    .global gUnk_082B317C
gUnk_082B317C:
    FOMT_FARM_STATUS_TILEMAP 0x030, 0x30
    .incbin "baserom_jp.gba", 0x2B31AC, (0x2B39F0 - 0x2B31AC)
    .global gUnk_082B39F0
gUnk_082B39F0:
    FOMT_FARM_STATUS_TILEMAP 0x4D2, 0x9A
    .incbin "baserom_jp.gba", 0x2B3A8A, 0x2
    .global gUnk_082B3A8C
gUnk_082B3A8C:
    FOMT_FARM_STATUS_TILEMAP 0x3E4, 0x54
    .incbin "baserom_jp.gba", 0x2B3AE0, (0x2B69B8 - 0x2B3AE0)
    .incbin "build/jp/graphics/portraits/shared/portrait_tiles.4bpp"
    .incbin "baserom_jp.gba", 0x3111F8, (0x311B84 - 0x3111F8)
    .global gUnk_08311B84
gUnk_08311B84:
    .incbin "baserom_jp.gba", 0x311B84, (0x329558 - 0x311B84)
    .incbin "build/jp/graphics/sprites/shared/actor_tiles.4bpp"
    .incbin "baserom_jp.gba", 0x3E7F18, (0x3ED9FC - 0x3E7F18)
    .global gUnk_083ED9FC
gUnk_083ED9FC:
    .incbin "baserom_jp.gba", 0x3ED9FC, (0x41ECDC - 0x3ED9FC)
    .global gUnk_FieldPlotRenderRecord_004
gUnk_FieldPlotRenderRecord_004:
    .incbin "baserom_jp.gba", 0x41ECDC, 0x30
    .global gUnk_FieldPlotRenderRecord_011
gUnk_FieldPlotRenderRecord_011:
    .incbin "baserom_jp.gba", 0x41ED0C, 0x18
    .global gUnk_FieldPlotRenderRecord_006
gUnk_FieldPlotRenderRecord_006:
    .incbin "baserom_jp.gba", 0x41ED24, 0x3C
    .global gUnk_FieldPlotRenderRecord_002
gUnk_FieldPlotRenderRecord_002:
    .incbin "baserom_jp.gba", 0x41ED60, 0x30
    .global gUnk_FieldPlotRenderRecord_010
gUnk_FieldPlotRenderRecord_010:
    .incbin "baserom_jp.gba", 0x41ED90, 0x24
    .global gUnk_FieldPlotRenderRecord_014
gUnk_FieldPlotRenderRecord_014:
    .incbin "baserom_jp.gba", 0x41EDB4, 0x30
    .global gUnk_FieldPlotRenderRecord_017
gUnk_FieldPlotRenderRecord_017:
    .incbin "baserom_jp.gba", 0x41EDE4, 0x30
    .global gUnk_FieldPlotRenderRecord_018
gUnk_FieldPlotRenderRecord_018:
    .incbin "baserom_jp.gba", 0x41EE14, 0x30
    .global gUnk_FieldPlotRenderRecord_015
gUnk_FieldPlotRenderRecord_015:
    .incbin "baserom_jp.gba", 0x41EE44, 0x30
    .global gUnk_FieldPlotRenderRecord_007
gUnk_FieldPlotRenderRecord_007:
    .incbin "baserom_jp.gba", 0x41EE74, 0x24
    .global gUnk_FieldPlotRenderRecord_009
gUnk_FieldPlotRenderRecord_009:
    .incbin "baserom_jp.gba", 0x41EE98, 0x3C
    .global gUnk_FieldPlotRenderRecord_016
gUnk_FieldPlotRenderRecord_016:
    .incbin "baserom_jp.gba", 0x41EED4, 0x30
    .global gUnk_FieldPlotRenderRecord_001
gUnk_FieldPlotRenderRecord_001:
    .incbin "baserom_jp.gba", 0x41EF04, 0x24
    .global gUnk_FieldPlotRenderRecord_008
gUnk_FieldPlotRenderRecord_008:
    .incbin "baserom_jp.gba", 0x41EF28, 0x30
    .global gUnk_FieldPlotRenderRecord_013
gUnk_FieldPlotRenderRecord_013:
    .incbin "baserom_jp.gba", 0x41EF58, 0x1278
    .global gUnk_FieldPlotRenderRecord_003
gUnk_FieldPlotRenderRecord_003:
    .incbin "baserom_jp.gba", 0x4201D0, 0x1290
    .global gUnk_FieldPlotRenderRecord_012
gUnk_FieldPlotRenderRecord_012:
    .incbin "baserom_jp.gba", 0x421460, 0x18
    .global gUnk_FieldPlotRenderRecord_005
gUnk_FieldPlotRenderRecord_005:
    .incbin "baserom_jp.gba", 0x421478, 0x3C
    .global gUnk_FieldPlotRenderRecord_019
gUnk_FieldPlotRenderRecord_019:
    .incbin "baserom_jp.gba", 0x4214B4, 0x3C
    .global gUnk_FieldPlotRenderRecord_000
gUnk_FieldPlotRenderRecord_000:
    .incbin "baserom_jp.gba", 0x4214F0, 0x3B034
    .global gUnk_FieldPlotRenderRecord_033
gUnk_FieldPlotRenderRecord_033:
    .incbin "baserom_jp.gba", 0x45C524, 0x18
    .global gUnk_FieldPlotRenderRecord_031
gUnk_FieldPlotRenderRecord_031:
    .incbin "baserom_jp.gba", 0x45C53C, 0x18
    .global gUnk_FieldPlotRenderRecord_034
gUnk_FieldPlotRenderRecord_034:
    .incbin "baserom_jp.gba", 0x45C554, 0x18
    .global gUnk_FieldPlotRenderRecord_032
gUnk_FieldPlotRenderRecord_032:
    .incbin "baserom_jp.gba", 0x45C56C, 0x18
    .global gUnk_FieldPlotRenderRecord_023
gUnk_FieldPlotRenderRecord_023:
    .incbin "baserom_jp.gba", 0x45C584, 0x18
    .global gUnk_FieldPlotRenderRecord_025
gUnk_FieldPlotRenderRecord_025:
    .incbin "baserom_jp.gba", 0x45C59C, 0x18

    @ Song header labels recovered from gSongTable.  The raw M4A payloads
    @ remain in this regional asset container; the C table uses these labels.
    .global gSong_Unused
    .set gSong_Unused, jp_data_0813b288_start + 0x0
    .global gSong_Audio001
    .set gSong_Audio001, jp_data_0813b288_start + 0x1622AC
    .global gSong_Audio002
    .set gSong_Audio002, jp_data_0813b288_start + 0x162900
    .global gSong_Audio003
    .set gSong_Audio003, jp_data_0813b288_start + 0x1630B8
    .global gSong_Audio004
    .set gSong_Audio004, jp_data_0813b288_start + 0x1632E4
    .global gSong_Audio005
    .set gSong_Audio005, jp_data_0813b288_start + 0x163E54
    .global gSong_Audio006
    .set gSong_Audio006, jp_data_0813b288_start + 0x164840
    .global gSong_Audio007
    .set gSong_Audio007, jp_data_0813b288_start + 0x164F44
    .global gSong_Audio008
    .set gSong_Audio008, jp_data_0813b288_start + 0x165C84
    .global gSong_Audio009
    .set gSong_Audio009, jp_data_0813b288_start + 0x16651C
    .global gSong_Audio010
    .set gSong_Audio010, jp_data_0813b288_start + 0x1667A8
    .global gSong_Audio011
    .set gSong_Audio011, jp_data_0813b288_start + 0x167A8C
    .global gSong_Audio012
    .set gSong_Audio012, jp_data_0813b288_start + 0x1683A4
    .global gSong_Audio013
    .set gSong_Audio013, jp_data_0813b288_start + 0x168BA8
    .global gSong_Audio014
    .set gSong_Audio014, jp_data_0813b288_start + 0x169360
    .global gSong_Audio015
    .set gSong_Audio015, jp_data_0813b288_start + 0x169904
    .global gSong_Audio016
    .set gSong_Audio016, jp_data_0813b288_start + 0x169E90
    .global gSong_Audio017
    .set gSong_Audio017, jp_data_0813b288_start + 0x16A5CC
    .global gSong_Audio018
    .set gSong_Audio018, jp_data_0813b288_start + 0x16A86C
    .global gSong_Audio019
    .set gSong_Audio019, jp_data_0813b288_start + 0x16B0BC
    .global gSong_Audio020
    .set gSong_Audio020, jp_data_0813b288_start + 0x16B54C
    .global gSong_Audio021
    .set gSong_Audio021, jp_data_0813b288_start + 0x16B974
    .global gSong_Audio022
    .set gSong_Audio022, jp_data_0813b288_start + 0x16BD94
    .global gSong_Audio023
    .set gSong_Audio023, jp_data_0813b288_start + 0x16C310
    .global gSong_Audio024
    .set gSong_Audio024, jp_data_0813b288_start + 0x16C7E4
    .global gSong_Audio025
    .set gSong_Audio025, jp_data_0813b288_start + 0x16D16C
    .global gSong_Audio026
    .set gSong_Audio026, jp_data_0813b288_start + 0x16D4F8
    .global gSong_Audio027
    .set gSong_Audio027, jp_data_0813b288_start + 0x16D87C
    .global gSong_Audio028
    .set gSong_Audio028, jp_data_0813b288_start + 0x16D8A0
    .global gSong_Audio029
    .set gSong_Audio029, jp_data_0813b288_start + 0x16D8BC
    .global gSong_Audio030
    .set gSong_Audio030, jp_data_0813b288_start + 0x16D8D8
    .global gSong_Audio031
    .set gSong_Audio031, jp_data_0813b288_start + 0x16D8F4
    .global gSong_Audio032
    .set gSong_Audio032, jp_data_0813b288_start + 0x16D910
    .global gSong_Audio033
    .set gSong_Audio033, jp_data_0813b288_start + 0x16DEE0
    .global gSong_Audio034
    .set gSong_Audio034, jp_data_0813b288_start + 0x16E6A0
    .global gSong_Audio035
    .set gSong_Audio035, jp_data_0813b288_start + 0x16F0BC
    .global gSong_Audio036
    .set gSong_Audio036, jp_data_0813b288_start + 0x16F8D8
    .global gSong_Audio037
    .set gSong_Audio037, jp_data_0813b288_start + 0x16FDB0
    .global gSong_Audio101
    .set gSong_Audio101, jp_data_0813b288_start + 0x16FDD4
    .global gSong_Audio102
    .set gSong_Audio102, jp_data_0813b288_start + 0x16FDF0
    .global gSong_Audio103
    .set gSong_Audio103, jp_data_0813b288_start + 0x16FE0C
    .global gSong_Audio104
    .set gSong_Audio104, jp_data_0813b288_start + 0x16FE30
    .global gSong_Audio105
    .set gSong_Audio105, jp_data_0813b288_start + 0x16FE4C
    .global gSong_Audio106
    .set gSong_Audio106, jp_data_0813b288_start + 0x16FE68
    .global gSong_Audio107
    .set gSong_Audio107, jp_data_0813b288_start + 0x16FE84
    .global gSong_Audio108
    .set gSong_Audio108, jp_data_0813b288_start + 0x16FEA0
    .global gSong_Audio109
    .set gSong_Audio109, jp_data_0813b288_start + 0x16FEBC
    .global gSong_Audio110
    .set gSong_Audio110, jp_data_0813b288_start + 0x16FED8
    .global gSong_Audio111
    .set gSong_Audio111, jp_data_0813b288_start + 0x16FEF4
    .global gSong_Audio112
    .set gSong_Audio112, jp_data_0813b288_start + 0x16FF10
    .global gSong_Audio113
    .set gSong_Audio113, jp_data_0813b288_start + 0x16FF2C
    .global gSong_Audio114
    .set gSong_Audio114, jp_data_0813b288_start + 0x16FF48
    .global gSong_Audio115
    .set gSong_Audio115, jp_data_0813b288_start + 0x16FF64
    .global gSong_Audio116
    .set gSong_Audio116, jp_data_0813b288_start + 0x16FF80
    .global gSong_Audio117
    .set gSong_Audio117, jp_data_0813b288_start + 0x16FF9C
    .global gSong_Audio118
    .set gSong_Audio118, jp_data_0813b288_start + 0x16FFB8
    .global gSong_Audio119
    .set gSong_Audio119, jp_data_0813b288_start + 0x16FFD4
    .global gSong_Audio120
    .set gSong_Audio120, jp_data_0813b288_start + 0x16FFF0
    .global gSong_Audio121
    .set gSong_Audio121, jp_data_0813b288_start + 0x17000C
    .global gSong_Audio122
    .set gSong_Audio122, jp_data_0813b288_start + 0x170028
    .global gSong_Audio123
    .set gSong_Audio123, jp_data_0813b288_start + 0x170044
    .global gSong_Audio124
    .set gSong_Audio124, jp_data_0813b288_start + 0x170060
    .global gSong_Audio125
    .set gSong_Audio125, jp_data_0813b288_start + 0x17007C
    .global gSong_Audio126
    .set gSong_Audio126, jp_data_0813b288_start + 0x170098
    .global gSong_Audio127
    .set gSong_Audio127, jp_data_0813b288_start + 0x1700B4
    .global gSong_Audio128
    .set gSong_Audio128, jp_data_0813b288_start + 0x1700D0
    .global gSong_Audio129
    .set gSong_Audio129, jp_data_0813b288_start + 0x1700EC
    .global gSong_Audio130
    .set gSong_Audio130, jp_data_0813b288_start + 0x170108
    .global gSong_Audio131
    .set gSong_Audio131, jp_data_0813b288_start + 0x170124
    .global gSong_Audio132
    .set gSong_Audio132, jp_data_0813b288_start + 0x170140
    .global gSong_Audio133
    .set gSong_Audio133, jp_data_0813b288_start + 0x17015C
    .global gSong_Audio134
    .set gSong_Audio134, jp_data_0813b288_start + 0x170178
    .global gSong_Audio135
    .set gSong_Audio135, jp_data_0813b288_start + 0x170194
    .global gSong_Audio136
    .set gSong_Audio136, jp_data_0813b288_start + 0x1701B0
    .global gSong_Audio137
    .set gSong_Audio137, jp_data_0813b288_start + 0x1701D0
    .global gSong_Audio138
    .set gSong_Audio138, jp_data_0813b288_start + 0x1701EC
    .global gSong_Audio139
    .set gSong_Audio139, jp_data_0813b288_start + 0x170208
    .global gSong_Audio140
    .set gSong_Audio140, jp_data_0813b288_start + 0x170224
    .global gSong_Audio141
    .set gSong_Audio141, jp_data_0813b288_start + 0x170240
    .global gSong_Audio142
    .set gSong_Audio142, jp_data_0813b288_start + 0x17026C
    .global gSong_Audio143
    .set gSong_Audio143, jp_data_0813b288_start + 0x170288
    .global gSong_Audio144
    .set gSong_Audio144, jp_data_0813b288_start + 0x1702A4
    .global gSong_Audio145
    .set gSong_Audio145, jp_data_0813b288_start + 0x1702D0
    .global gSong_Audio146
    .set gSong_Audio146, jp_data_0813b288_start + 0x1702F4
    .global gSong_Audio147
    .set gSong_Audio147, jp_data_0813b288_start + 0x170318
    .global gSong_Audio148
    .set gSong_Audio148, jp_data_0813b288_start + 0x170334
    .global gSong_Audio149
    .set gSong_Audio149, jp_data_0813b288_start + 0x170354
    .global gSong_Audio150
    .set gSong_Audio150, jp_data_0813b288_start + 0x170370
    .global gSong_Audio151
    .set gSong_Audio151, jp_data_0813b288_start + 0x17038C
    .global gSong_Audio152
    .set gSong_Audio152, jp_data_0813b288_start + 0x1703A8
    .global gSong_Audio153
    .set gSong_Audio153, jp_data_0813b288_start + 0x1703CC
    .global gSong_Audio154
    .set gSong_Audio154, jp_data_0813b288_start + 0x1703E8
    .global gSong_Audio155
    .set gSong_Audio155, jp_data_0813b288_start + 0x170408
    .global gSong_Audio156
    .set gSong_Audio156, jp_data_0813b288_start + 0x170424
    .global gSong_Audio157
    .set gSong_Audio157, jp_data_0813b288_start + 0x170484
    .global gSong_Audio158
    .set gSong_Audio158, jp_data_0813b288_start + 0x1704B0
    .global gSong_Audio159
    .set gSong_Audio159, jp_data_0813b288_start + 0x1704D8
    .global gSong_Audio160
    .set gSong_Audio160, jp_data_0813b288_start + 0x170508
    .global gSong_Audio161
    .set gSong_Audio161, jp_data_0813b288_start + 0x170524
    .global gSong_Audio162
    .set gSong_Audio162, jp_data_0813b288_start + 0x170550
    .global gSong_Audio163
    .set gSong_Audio163, jp_data_0813b288_start + 0x17056C
    .global gSong_Audio164
    .set gSong_Audio164, jp_data_0813b288_start + 0x17058C
    .global gSong_Audio165
    .set gSong_Audio165, jp_data_0813b288_start + 0x1705B0
    .global gSong_Audio166
    .set gSong_Audio166, jp_data_0813b288_start + 0x1705CC
    .global gSong_Audio167
    .set gSong_Audio167, jp_data_0813b288_start + 0x170600
    .global gSong_Audio168
    .set gSong_Audio168, jp_data_0813b288_start + 0x170628
    .global gSong_Audio169
    .set gSong_Audio169, jp_data_0813b288_start + 0x170644
    .global gSong_Audio170
    .set gSong_Audio170, jp_data_0813b288_start + 0x170660
    .global gSong_Audio171
    .set gSong_Audio171, jp_data_0813b288_start + 0x170680
    .global gSong_Audio172
    .set gSong_Audio172, jp_data_0813b288_start + 0x17069C
    .global gSong_Audio173
    .set gSong_Audio173, jp_data_0813b288_start + 0x1706D4
    .global gSong_Audio174
    .set gSong_Audio174, jp_data_0813b288_start + 0x1706F8
    .global gSong_Audio175
    .set gSong_Audio175, jp_data_0813b288_start + 0x17076C
    .global gSong_Audio176
    .set gSong_Audio176, jp_data_0813b288_start + 0x1707F8
    .global gSong_Audio177
    .set gSong_Audio177, jp_data_0813b288_start + 0x170818
    .global gSong_Audio178
    .set gSong_Audio178, jp_data_0813b288_start + 0x170874
    .global gSong_Audio179
    .set gSong_Audio179, jp_data_0813b288_start + 0x1708E0
    .global gSong_Audio180
    .set gSong_Audio180, jp_data_0813b288_start + 0x17090C
    .global gSong_Audio181
    .set gSong_Audio181, jp_data_0813b288_start + 0x17093C
    .global gSong_Audio182
    .set gSong_Audio182, jp_data_0813b288_start + 0x170980
    .global gSong_Audio183
    .set gSong_Audio183, jp_data_0813b288_start + 0x170AE8
    .global gSong_Audio184
    .set gSong_Audio184, jp_data_0813b288_start + 0x170B0C
    .global gSong_Audio185
    .set gSong_Audio185, jp_data_0813b288_start + 0x170B28
    .global gSong_Audio186
    .set gSong_Audio186, jp_data_0813b288_start + 0x170B44
    .global gSong_Audio187
    .set gSong_Audio187, jp_data_0813b288_start + 0x170B64
    .global gSong_Audio188
    .set gSong_Audio188, jp_data_0813b288_start + 0x170B98
    .global gSong_Audio189
    .set gSong_Audio189, jp_data_0813b288_start + 0x170BC0
    .global gSong_Audio190
    .set gSong_Audio190, jp_data_0813b288_start + 0x170C14
    .global gSong_Audio191
    .set gSong_Audio191, jp_data_0813b288_start + 0x170C34
    .global gSong_Audio192
    .set gSong_Audio192, jp_data_0813b288_start + 0x170C50
    .global gSong_Audio193
    .set gSong_Audio193, jp_data_0813b288_start + 0x170C68
    .global gSong_Audio197
    .set gSong_Audio197, jp_data_0813b288_start + 0x170C84
    .global gSong_Audio198
    .set gSong_Audio198, jp_data_0813b288_start + 0x170CA0
    .global gSong_Audio199
    .set gSong_Audio199, jp_data_0813b288_start + 0x170CBC
    .global gSong_Audio200
    .set gSong_Audio200, jp_data_0813b288_start + 0x170CE0
    .global gSong_Audio201
    .set gSong_Audio201, jp_data_0813b288_start + 0x170D00
    .global gSong_Audio202
    .set gSong_Audio202, jp_data_0813b288_start + 0x170D20
    .global gSong_Audio203
    .set gSong_Audio203, jp_data_0813b288_start + 0x170D3C
    .global gSong_Audio204
    .set gSong_Audio204, jp_data_0813b288_start + 0x170D60
    .global gSong_Audio205
    .set gSong_Audio205, jp_data_0813b288_start + 0x170D80
    .global gSong_Audio206
    .set gSong_Audio206, jp_data_0813b288_start + 0x170DA0
    .global gSong_Audio207
    .set gSong_Audio207, jp_data_0813b288_start + 0x170DC0
    .global gSong_Audio208
    .set gSong_Audio208, jp_data_0813b288_start + 0x170DDC
    .global gSong_Audio209
    .set gSong_Audio209, jp_data_0813b288_start + 0x170DF8
    .global gSong_Audio210
    .set gSong_Audio210, jp_data_0813b288_start + 0x170E18

    @ WaveData headers referenced by the recovered M4A ToneData tables.
    .global gM4aWaveData_000
    .set gM4aWaveData_000, jp_data_0813b288_start + 0x4
    .global gM4aWaveData_001
    .set gM4aWaveData_001, jp_data_0813b288_start + 0x8C44
    .global gM4aWaveData_002
    .set gM4aWaveData_002, jp_data_0813b288_start + 0xA980
    .global gM4aWaveData_003
    .set gM4aWaveData_003, jp_data_0813b288_start + 0xDB7C
    .global gM4aWaveData_004
    .set gM4aWaveData_004, jp_data_0813b288_start + 0xF414
    .global gM4aWaveData_005
    .set gM4aWaveData_005, jp_data_0813b288_start + 0x11B8C
    .global gM4aWaveData_006
    .set gM4aWaveData_006, jp_data_0813b288_start + 0x16398
    .global gM4aWaveData_007
    .set gM4aWaveData_007, jp_data_0813b288_start + 0x170AC
    .global gM4aWaveData_008
    .set gM4aWaveData_008, jp_data_0813b288_start + 0x17484
    .global gM4aWaveData_009
    .set gM4aWaveData_009, jp_data_0813b288_start + 0x1E37C
    .global gM4aWaveData_010
    .set gM4aWaveData_010, jp_data_0813b288_start + 0x228CC
    .global gM4aWaveData_011
    .set gM4aWaveData_011, jp_data_0813b288_start + 0x2869C
    .global gM4aWaveData_012
    .set gM4aWaveData_012, jp_data_0813b288_start + 0x29C60
    .global gM4aWaveData_013
    .set gM4aWaveData_013, jp_data_0813b288_start + 0x2E504
    .global gM4aWaveData_014
    .set gM4aWaveData_014, jp_data_0813b288_start + 0x343DC
    .global gM4aWaveData_015
    .set gM4aWaveData_015, jp_data_0813b288_start + 0x38DA0
    .global gM4aWaveData_016
    .set gM4aWaveData_016, jp_data_0813b288_start + 0x3A900
    .global gM4aWaveData_017
    .set gM4aWaveData_017, jp_data_0813b288_start + 0x3C168
    .global gM4aWaveData_018
    .set gM4aWaveData_018, jp_data_0813b288_start + 0x42F88
    .global gM4aWaveData_019
    .set gM4aWaveData_019, jp_data_0813b288_start + 0x4D8C4
    .global gM4aWaveData_020
    .set gM4aWaveData_020, jp_data_0813b288_start + 0x50E70
    .global gM4aWaveData_021
    .set gM4aWaveData_021, jp_data_0813b288_start + 0x53C04
    .global gM4aWaveData_022
    .set gM4aWaveData_022, jp_data_0813b288_start + 0x60428
    .global gM4aWaveData_023
    .set gM4aWaveData_023, jp_data_0813b288_start + 0x7387C
    .global gM4aWaveData_024
    .set gM4aWaveData_024, jp_data_0813b288_start + 0x74C98
    .global gM4aWaveData_025
    .set gM4aWaveData_025, jp_data_0813b288_start + 0x756E8
    .global gM4aWaveData_026
    .set gM4aWaveData_026, jp_data_0813b288_start + 0x76B20
    .global gM4aWaveData_027
    .set gM4aWaveData_027, jp_data_0813b288_start + 0x7E534
    .global gM4aWaveData_028
    .set gM4aWaveData_028, jp_data_0813b288_start + 0x87BD4
    .global gM4aWaveData_029
    .set gM4aWaveData_029, jp_data_0813b288_start + 0x91CF8
    .global gM4aWaveData_030
    .set gM4aWaveData_030, jp_data_0813b288_start + 0x9508C
    .global gM4aWaveData_031
    .set gM4aWaveData_031, jp_data_0813b288_start + 0x99024
    .global gM4aWaveData_032
    .set gM4aWaveData_032, jp_data_0813b288_start + 0xA2DE8
    .global gM4aWaveData_033
    .set gM4aWaveData_033, jp_data_0813b288_start + 0xABCFC
    .global gM4aWaveData_034
    .set gM4aWaveData_034, jp_data_0813b288_start + 0xAE990
    .global gM4aWaveData_035
    .set gM4aWaveData_035, jp_data_0813b288_start + 0xAF518
    .global gM4aWaveData_036
    .set gM4aWaveData_036, jp_data_0813b288_start + 0xB5F2C
    .global gM4aWaveData_037
    .set gM4aWaveData_037, jp_data_0813b288_start + 0xB8268
    .global gM4aWaveData_038
    .set gM4aWaveData_038, jp_data_0813b288_start + 0xB95FC
    .global gM4aWaveData_039
    .set gM4aWaveData_039, jp_data_0813b288_start + 0xBA8D4
    .global gM4aWaveData_040
    .set gM4aWaveData_040, jp_data_0813b288_start + 0xBC06C
    .global gM4aWaveData_041
    .set gM4aWaveData_041, jp_data_0813b288_start + 0xBC98C
    .global gM4aWaveData_042
    .set gM4aWaveData_042, jp_data_0813b288_start + 0xBDF80
    .global gM4aWaveData_043
    .set gM4aWaveData_043, jp_data_0813b288_start + 0xBE730
    .global gM4aWaveData_044
    .set gM4aWaveData_044, jp_data_0813b288_start + 0xC0434
    .global gM4aWaveData_045
    .set gM4aWaveData_045, jp_data_0813b288_start + 0xC2844
    .global gM4aWaveData_046
    .set gM4aWaveData_046, jp_data_0813b288_start + 0xC3E30
    .global gM4aWaveData_047
    .set gM4aWaveData_047, jp_data_0813b288_start + 0xC49D0
    .global gM4aWaveData_048
    .set gM4aWaveData_048, jp_data_0813b288_start + 0xC50B8
    .global gM4aWaveData_049
    .set gM4aWaveData_049, jp_data_0813b288_start + 0xC5770
    .global gM4aWaveData_050
    .set gM4aWaveData_050, jp_data_0813b288_start + 0xC6188
    .global gM4aWaveData_051
    .set gM4aWaveData_051, jp_data_0813b288_start + 0xC6820
    .global gM4aWaveData_052
    .set gM4aWaveData_052, jp_data_0813b288_start + 0xC85F4
    .global gM4aWaveData_053
    .set gM4aWaveData_053, jp_data_0813b288_start + 0xC9064
    .global gM4aWaveData_054
    .set gM4aWaveData_054, jp_data_0813b288_start + 0xC960C
    .global gM4aWaveData_055
    .set gM4aWaveData_055, jp_data_0813b288_start + 0xC9F58
    .global gM4aWaveData_056
    .set gM4aWaveData_056, jp_data_0813b288_start + 0xCC914
    .global gM4aWaveData_057
    .set gM4aWaveData_057, jp_data_0813b288_start + 0xCEC1C
    .global gM4aWaveData_058
    .set gM4aWaveData_058, jp_data_0813b288_start + 0xCF180
    .global gM4aWaveData_059
    .set gM4aWaveData_059, jp_data_0813b288_start + 0xD08A4
    .global gM4aWaveData_060
    .set gM4aWaveData_060, jp_data_0813b288_start + 0xD1508
    .global gM4aWaveData_061
    .set gM4aWaveData_061, jp_data_0813b288_start + 0xD2C24
    .global gM4aWaveData_062
    .set gM4aWaveData_062, jp_data_0813b288_start + 0xD8CB8
    .global gM4aWaveData_063
    .set gM4aWaveData_063, jp_data_0813b288_start + 0xDDD64
    .global gM4aWaveData_064
    .set gM4aWaveData_064, jp_data_0813b288_start + 0xDFCB0
    .global gM4aWaveData_065
    .set gM4aWaveData_065, jp_data_0813b288_start + 0xE0E28
    .global gM4aWaveData_066
    .set gM4aWaveData_066, jp_data_0813b288_start + 0xE45F8
    .global gM4aWaveData_067
    .set gM4aWaveData_067, jp_data_0813b288_start + 0xE9800
    .global gM4aWaveData_068
    .set gM4aWaveData_068, jp_data_0813b288_start + 0xEBD88
    .global gM4aWaveData_069
    .set gM4aWaveData_069, jp_data_0813b288_start + 0xEDDBC
    .global gM4aWaveData_070
    .set gM4aWaveData_070, jp_data_0813b288_start + 0xEE684
    .global gM4aWaveData_071
    .set gM4aWaveData_071, jp_data_0813b288_start + 0xF0174
    .global gM4aWaveData_072
    .set gM4aWaveData_072, jp_data_0813b288_start + 0xF170C
    .global gM4aWaveData_073
    .set gM4aWaveData_073, jp_data_0813b288_start + 0xF431C
    .global gM4aWaveData_074
    .set gM4aWaveData_074, jp_data_0813b288_start + 0xF6A30
    .global gM4aWaveData_075
    .set gM4aWaveData_075, jp_data_0813b288_start + 0xF7468
    .global gM4aWaveData_076
    .set gM4aWaveData_076, jp_data_0813b288_start + 0xFAE94
    .global gM4aWaveData_077
    .set gM4aWaveData_077, jp_data_0813b288_start + 0xFC830
    .global gM4aWaveData_078
    .set gM4aWaveData_078, jp_data_0813b288_start + 0x100014
    .global gM4aWaveData_079
    .set gM4aWaveData_079, jp_data_0813b288_start + 0x100470
    .global gM4aWaveData_080
    .set gM4aWaveData_080, jp_data_0813b288_start + 0x100EF0
    .global gM4aWaveData_081
    .set gM4aWaveData_081, jp_data_0813b288_start + 0x101D50
    .global gM4aWaveData_082
    .set gM4aWaveData_082, jp_data_0813b288_start + 0x10BDC0
    .global gM4aWaveData_083
    .set gM4aWaveData_083, jp_data_0813b288_start + 0x112720
    .global gM4aWaveData_084
    .set gM4aWaveData_084, jp_data_0813b288_start + 0x117B5C
    .global gM4aWaveData_085
    .set gM4aWaveData_085, jp_data_0813b288_start + 0x11C578
    .global gM4aWaveData_086
    .set gM4aWaveData_086, jp_data_0813b288_start + 0x11F8D0
    .global gM4aWaveData_087
    .set gM4aWaveData_087, jp_data_0813b288_start + 0x122D64
    .global gM4aWaveData_088
    .set gM4aWaveData_088, jp_data_0813b288_start + 0x124920
    .global gM4aWaveData_089
    .set gM4aWaveData_089, jp_data_0813b288_start + 0x126998
    .global gM4aWaveData_090
    .set gM4aWaveData_090, jp_data_0813b288_start + 0x127B44
    .global gM4aWaveData_091
    .set gM4aWaveData_091, jp_data_0813b288_start + 0x1293D8
    .global gM4aWaveData_092
    .set gM4aWaveData_092, jp_data_0813b288_start + 0x12A8E4
    .global gM4aWaveData_093
    .set gM4aWaveData_093, jp_data_0813b288_start + 0x12B5C4
    .global gM4aWaveData_094
    .set gM4aWaveData_094, jp_data_0813b288_start + 0x12BF34
    .global gM4aWaveData_095
    .set gM4aWaveData_095, jp_data_0813b288_start + 0x136BF0
    .global gM4aWaveData_096
    .set gM4aWaveData_096, jp_data_0813b288_start + 0x13CE38
    .global gM4aWaveData_097
    .set gM4aWaveData_097, jp_data_0813b288_start + 0x13E2DC
    .global gM4aWaveData_098
    .set gM4aWaveData_098, jp_data_0813b288_start + 0x14B4B8
    .global gM4aWaveData_099
    .set gM4aWaveData_099, jp_data_0813b288_start + 0x152C48
    .global gM4aWaveData_100
    .set gM4aWaveData_100, jp_data_0813b288_start + 0x153420
    .global gM4aWaveData_101
    .set gM4aWaveData_101, jp_data_0813b288_start + 0x154254
    .global gM4aWaveData_102
    .set gM4aWaveData_102, jp_data_0813b288_start + 0x1547B8
    .global gM4aWaveData_103
    .set gM4aWaveData_103, jp_data_0813b288_start + 0x1566EC
    .global gM4aWaveData_104
    .set gM4aWaveData_104, jp_data_0813b288_start + 0x158300
    .global gM4aWaveData_105
    .set gM4aWaveData_105, jp_data_0813b288_start + 0x15BAF4

    @ Region-neutral labels for FarmHouse tile-patch source payloads.
    @ The payload layouts remain raw; src/farm_house.cc owns their typed
    @ descriptor tables.
    .global gUnk_FarmHouseTilePatchResource_000
    .set gUnk_FarmHouseTilePatchResource_000, jp_data_0813b288_start + 0x32E4D0
    .global gUnk_FarmHouseTilePatchResource_001
    .set gUnk_FarmHouseTilePatchResource_001, jp_data_0813b288_start + 0x3322D0
    .global gUnk_FarmHouseTilePatchResource_002
    .set gUnk_FarmHouseTilePatchResource_002, jp_data_0813b288_start + 0x32CE04
    .global gUnk_FarmHouseTilePatchResource_003
    .set gUnk_FarmHouseTilePatchResource_003, jp_data_0813b288_start + 0x330CF4
    .global gUnk_FarmHouseTilePatchResource_004
    .set gUnk_FarmHouseTilePatchResource_004, jp_data_0813b288_start + 0x3305D0
    .global gUnk_FarmHouseTilePatchResource_005
    .set gUnk_FarmHouseTilePatchResource_005, jp_data_0813b288_start + 0x334348
    .global gUnk_FarmHouseTilePatchResource_006
    .set gUnk_FarmHouseTilePatchResource_006, jp_data_0813b288_start + 0x335548
    .global gUnk_FarmHouseTilePatchResource_007
    .set gUnk_FarmHouseTilePatchResource_007, jp_data_0813b288_start + 0x32E714
    .global gUnk_FarmHouseTilePatchResource_008
    .set gUnk_FarmHouseTilePatchResource_008, jp_data_0813b288_start + 0x332514
    .global gUnk_FarmHouseTilePatchResource_009
    .set gUnk_FarmHouseTilePatchResource_009, jp_data_0813b288_start + 0x32FECC
    .global gUnk_FarmHouseTilePatchResource_010
    .set gUnk_FarmHouseTilePatchResource_010, jp_data_0813b288_start + 0x333C44
    .global gUnk_FarmHouseTilePatchResource_011
    .set gUnk_FarmHouseTilePatchResource_011, jp_data_0813b288_start + 0x32FC88
    .global gUnk_FarmHouseTilePatchResource_012
    .set gUnk_FarmHouseTilePatchResource_012, jp_data_0813b288_start + 0x333A00
    .global gUnk_FarmHouseTilePatchResource_013
    .set gUnk_FarmHouseTilePatchResource_013, jp_data_0813b288_start + 0x32CA3C
    .global gUnk_FarmHouseTilePatchResource_014
    .set gUnk_FarmHouseTilePatchResource_014, jp_data_0813b288_start + 0x340000
    .global gUnk_FarmHouseTilePatchResource_015
    .set gUnk_FarmHouseTilePatchResource_015, jp_data_0813b288_start + 0x340B84
    .global gUnk_FarmHouseTilePatchResource_016
    .set gUnk_FarmHouseTilePatchResource_016, jp_data_0813b288_start + 0x342408
    .global gUnk_FarmHouseTilePatchResource_017
    .set gUnk_FarmHouseTilePatchResource_017, jp_data_0813b288_start + 0x342F8C
    .global gUnk_FarmHouseTilePatchResource_018
    .set gUnk_FarmHouseTilePatchResource_018, jp_data_0813b288_start + 0x326A38
    .global gUnk_FarmHouseTilePatchResource_019
    .set gUnk_FarmHouseTilePatchResource_019, jp_data_0813b288_start + 0x326C3C
    .global gUnk_FarmHouseTilePatchResource_020
    .set gUnk_FarmHouseTilePatchResource_020, jp_data_0813b288_start + 0x326914
    .global gUnk_FarmHouseTilePatchResource_021
    .set gUnk_FarmHouseTilePatchResource_021, jp_data_0813b288_start + 0x327B9C
    .global gUnk_FarmHouseTilePatchResource_022
    .set gUnk_FarmHouseTilePatchResource_022, jp_data_0813b288_start + 0x327DA0
    .global gUnk_FarmHouseTilePatchResource_023
    .set gUnk_FarmHouseTilePatchResource_023, jp_data_0813b288_start + 0x327A78
    .global gUnk_FarmHouseTilePatchResource_024
    .set gUnk_FarmHouseTilePatchResource_024, jp_data_0813b288_start + 0x329DE4
    .global gUnk_FarmHouseTilePatchResource_025
    .set gUnk_FarmHouseTilePatchResource_025, jp_data_0813b288_start + 0x32CC80
    .global gUnk_FarmHouseTilePatchResource_026
    .set gUnk_FarmHouseTilePatchResource_026, jp_data_0813b288_start + 0x32B6B8
    .global gUnk_FarmHouseTilePatchResource_027
    .set gUnk_FarmHouseTilePatchResource_027, jp_data_0813b288_start + 0x335838
    .global gUnk_FarmHouseTilePatchAnimationResource_000
    .set gUnk_FarmHouseTilePatchAnimationResource_000, jp_data_0813b288_start + 0x338E20
    .global gUnk_FarmHouseTilePatchAnimationResource_001
    .set gUnk_FarmHouseTilePatchAnimationResource_001, jp_data_0813b288_start + 0x338B1C

    @ Region-neutral labels for FarmHouse visual descriptor resources.
    @ Their payload formats remain in the raw regional asset container.
    .global gUnk_FarmHouseVisualResource_000
    .set gUnk_FarmHouseVisualResource_000, jp_data_0813b288_start + 0x336C20
    .global gUnk_FarmHouseVisualResource_001
    .set gUnk_FarmHouseVisualResource_001, jp_data_0813b288_start + 0x336C50
    .global gUnk_FarmHouseVisualResource_004
    .set gUnk_FarmHouseVisualResource_004, jp_data_0813b288_start + 0x33683C
    .global gUnk_FarmHouseVisualResource_005
    .set gUnk_FarmHouseVisualResource_005, jp_data_0813b288_start + 0x336C00
    .global gUnk_FarmHouseVisualResource_006
    .set gUnk_FarmHouseVisualResource_006, jp_data_0813b288_start + 0x337104
    .global gUnk_FarmHouseVisualResource_007
    .set gUnk_FarmHouseVisualResource_007, jp_data_0813b288_start + 0x3371D8
    .global gUnk_FarmHouseVisualResource_010
    .set gUnk_FarmHouseVisualResource_010, jp_data_0813b288_start + 0x336C80
    .global gUnk_FarmHouseVisualResource_011
    .set gUnk_FarmHouseVisualResource_011, jp_data_0813b288_start + 0x3370A4
    .global gUnk_FarmHouseVisualResource_012
    .set gUnk_FarmHouseVisualResource_012, jp_data_0813b288_start + 0x3372AC
    .global gUnk_FarmHouseVisualResource_013
    .set gUnk_FarmHouseVisualResource_013, jp_data_0813b288_start + 0x33CB34
    .global gUnk_FarmHouseVisualResource_014
    .set gUnk_FarmHouseVisualResource_014, jp_data_0813b288_start + 0x33CC08
    .global gUnk_FarmHouseVisualResource_015
    .set gUnk_FarmHouseVisualResource_015, jp_data_0813b288_start + 0x33C6BC
    .global gUnk_FarmHouseVisualResource_016
    .set gUnk_FarmHouseVisualResource_016, jp_data_0813b288_start + 0x33CAD4
    .global gUnk_FarmHouseVisualResource_017
    .set gUnk_FarmHouseVisualResource_017, jp_data_0813b288_start + 0x33CCDC
    .global gUnk_FarmHouseVisualResource_018
    .set gUnk_FarmHouseVisualResource_018, jp_data_0813b288_start + 0x33A2E0
    .global gUnk_FarmHouseVisualResource_019
    .set gUnk_FarmHouseVisualResource_019, jp_data_0813b288_start + 0x33A418
    .global gUnk_FarmHouseVisualResource_022
    .set gUnk_FarmHouseVisualResource_022, jp_data_0813b288_start + 0x339724
    .global gUnk_FarmHouseVisualResource_023
    .set gUnk_FarmHouseVisualResource_023, jp_data_0813b288_start + 0x33A2C0
    .global gUnk_FarmHouseVisualResource_024
    .set gUnk_FarmHouseVisualResource_024, jp_data_0813b288_start + 0x33BC9C
    .global gUnk_FarmHouseVisualResource_025
    .set gUnk_FarmHouseVisualResource_025, jp_data_0813b288_start + 0x33C1AC
    .global gUnk_FarmHouseVisualResource_028
    .set gUnk_FarmHouseVisualResource_028, jp_data_0813b288_start + 0x33A550
    .global gUnk_FarmHouseVisualResource_029
    .set gUnk_FarmHouseVisualResource_029, jp_data_0813b288_start + 0x33BC3C
    .global gUnk_FarmHouseVisualResource_030
    .set gUnk_FarmHouseVisualResource_030, jp_data_0813b288_start + 0x3376D0
    .global gUnk_FarmHouseVisualResource_031
    .set gUnk_FarmHouseVisualResource_031, jp_data_0813b288_start + 0x3376F8
    .global gUnk_FarmHouseVisualResource_034
    .set gUnk_FarmHouseVisualResource_034, jp_data_0813b288_start + 0x33730C
    .global gUnk_FarmHouseVisualResource_035
    .set gUnk_FarmHouseVisualResource_035, jp_data_0813b288_start + 0x337670
    .global gUnk_FarmHouseVisualResource_036
    .set gUnk_FarmHouseVisualResource_036, jp_data_0813b288_start + 0x337720
    .global gUnk_FarmHouseVisualResource_037
    .set gUnk_FarmHouseVisualResource_037, jp_data_0813b288_start + 0x3388DC
    .global gUnk_FarmHouseVisualResource_038
    .set gUnk_FarmHouseVisualResource_038, jp_data_0813b288_start + 0x3389FC
    .global gUnk_FarmHouseVisualResource_041
    .set gUnk_FarmHouseVisualResource_041, jp_data_0813b288_start + 0x337780
    .global gUnk_FarmHouseVisualResource_042
    .set gUnk_FarmHouseVisualResource_042, jp_data_0813b288_start + 0x33885C

    @ Region-neutral labels for gMapData raw resource targets.
    @ Their payload types are not decoded yet.
    .global gUnk_MapDataResource_092
    .set gUnk_MapDataResource_092, jp_data_0813b288_start + 0x2C3E78
    .global gUnk_MapDataResource_093
    .set gUnk_MapDataResource_093, jp_data_0813b288_start + 0x2C89B4
    .global gUnk_MapDataResource_095
    .set gUnk_MapDataResource_095, jp_data_0813b288_start + 0x2C8AAC
    .global gUnk_MapDataResource_096
    .set gUnk_MapDataResource_096, jp_data_0813b288_start + 0x2CA7A0
    .global gUnk_MapDataResource_097
    .set gUnk_MapDataResource_097, jp_data_0813b288_start + 0x2CB40C
    .global gUnk_MapDataResource_094
    .set gUnk_MapDataResource_094, jp_data_0813b288_start + 0x2CBBE4
    .global gUnk_MapDataResource_100
    .set gUnk_MapDataResource_100, jp_data_0813b288_start + 0x2CBCBC
    .global gUnk_MapDataResource_101
    .set gUnk_MapDataResource_101, jp_data_0813b288_start + 0x2D0CBC
    .global gUnk_MapDataResource_103
    .set gUnk_MapDataResource_103, jp_data_0813b288_start + 0x2D0DB4
    .global gUnk_MapDataResource_104
    .set gUnk_MapDataResource_104, jp_data_0813b288_start + 0x2D2B34
    .global gUnk_MapDataResource_105
    .set gUnk_MapDataResource_105, jp_data_0813b288_start + 0x2D379C
    .global gUnk_MapDataResource_102
    .set gUnk_MapDataResource_102, jp_data_0813b288_start + 0x2D3F0C
    .global gUnk_MapDataResource_244
    .set gUnk_MapDataResource_244, jp_data_0813b288_start + 0x2D3FE0
    .global gUnk_MapDataResource_245
    .set gUnk_MapDataResource_245, jp_data_0813b288_start + 0x2D41EC
    .global gUnk_MapDataResource_246
    .set gUnk_MapDataResource_246, jp_data_0813b288_start + 0x2D4344
    .global gUnk_MapDataResource_056
    .set gUnk_MapDataResource_056, jp_data_0813b288_start + 0x2D43CC
    .global gUnk_MapDataResource_057
    .set gUnk_MapDataResource_057, jp_data_0813b288_start + 0x2D749C
    .global gUnk_MapDataResource_059
    .set gUnk_MapDataResource_059, jp_data_0813b288_start + 0x2D757C
    .global gUnk_MapDataResource_060
    .set gUnk_MapDataResource_060, jp_data_0813b288_start + 0x2D7C98
    .global gUnk_MapDataResource_061
    .set gUnk_MapDataResource_061, jp_data_0813b288_start + 0x2D7EF8
    .global gUnk_MapDataResource_058
    .set gUnk_MapDataResource_058, jp_data_0813b288_start + 0x2D7F74
    .global gUnk_MapDataResource_064
    .set gUnk_MapDataResource_064, jp_data_0813b288_start + 0x2D8058
    .global gUnk_MapDataResource_065
    .set gUnk_MapDataResource_065, jp_data_0813b288_start + 0x2DA62C
    .global gUnk_MapDataResource_067
    .set gUnk_MapDataResource_067, jp_data_0813b288_start + 0x2DA704
    .global gUnk_MapDataResource_068
    .set gUnk_MapDataResource_068, jp_data_0813b288_start + 0x2DAE08
    .global gUnk_MapDataResource_069
    .set gUnk_MapDataResource_069, jp_data_0813b288_start + 0x2DB02C
    .global gUnk_MapDataResource_066
    .set gUnk_MapDataResource_066, jp_data_0813b288_start + 0x2DB098
    .global gUnk_MapDataResource_222
    .set gUnk_MapDataResource_222, jp_data_0813b288_start + 0x2DB164
    .global gUnk_MapDataResource_223
    .set gUnk_MapDataResource_223, jp_data_0813b288_start + 0x2DCA1C
    .global gUnk_MapDataResource_268
    .set gUnk_MapDataResource_268, jp_data_0813b288_start + 0x2DCB40
    .global gUnk_MapDataResource_269
    .set gUnk_MapDataResource_269, jp_data_0813b288_start + 0x2DCD94
    .global gUnk_MapDataResource_270
    .set gUnk_MapDataResource_270, jp_data_0813b288_start + 0x2DCEC8
    .global gUnk_MapDataResource_273
    .set gUnk_MapDataResource_273, jp_data_0813b288_start + 0x2DCF9C
    .global gUnk_MapDataResource_274
    .set gUnk_MapDataResource_274, jp_data_0813b288_start + 0x2DD1BC
    .global gUnk_MapDataResource_275
    .set gUnk_MapDataResource_275, jp_data_0813b288_start + 0x2DD330
    .global gUnk_MapDataResource_266
    .set gUnk_MapDataResource_266, jp_data_0813b288_start + 0x2DD3C0
    .global gUnk_MapDataResource_267
    .set gUnk_MapDataResource_267, jp_data_0813b288_start + 0x2DF938
    .global gUnk_MapDataResource_195
    .set gUnk_MapDataResource_195, jp_data_0813b288_start + 0x2DFA40
    .global gUnk_MapDataResource_196
    .set gUnk_MapDataResource_196, jp_data_0813b288_start + 0x2DFD60
    .global gUnk_MapDataResource_197
    .set gUnk_MapDataResource_197, jp_data_0813b288_start + 0x2DFE64
    .global gUnk_MapDataResource_321
    .set gUnk_MapDataResource_321, jp_data_0813b288_start + 0x2DFF50
    .global gUnk_MapDataResource_322
    .set gUnk_MapDataResource_322, jp_data_0813b288_start + 0x2E1558
    .global gUnk_MapDataResource_178
    .set gUnk_MapDataResource_178, jp_data_0813b288_start + 0x2E5148
    .global gUnk_MapDataResource_179
    .set gUnk_MapDataResource_179, jp_data_0813b288_start + 0x2E529C
    .global gUnk_MapDataResource_180
    .set gUnk_MapDataResource_180, jp_data_0813b288_start + 0x2E53EC
    .global gUnk_MapDataResource_000
    .set gUnk_MapDataResource_000, jp_data_0813b288_start + 0x2E54C0
    .global gUnk_MapDataResource_001
    .set gUnk_MapDataResource_001, jp_data_0813b288_start + 0x2E9070
    .global gUnk_MapDataResource_003
    .set gUnk_MapDataResource_003, jp_data_0813b288_start + 0x2E9164
    .global gUnk_MapDataResource_004
    .set gUnk_MapDataResource_004, jp_data_0813b288_start + 0x2E9910
    .global gUnk_MapDataResource_005
    .set gUnk_MapDataResource_005, jp_data_0813b288_start + 0x2E9D98
    .global gUnk_MapDataResource_002
    .set gUnk_MapDataResource_002, jp_data_0813b288_start + 0x2E9E28
    .global gUnk_MapDataResource_008
    .set gUnk_MapDataResource_008, jp_data_0813b288_start + 0x2E9F1C
    .global gUnk_MapDataResource_009
    .set gUnk_MapDataResource_009, jp_data_0813b288_start + 0x2EDCD8
    .global gUnk_MapDataResource_011
    .set gUnk_MapDataResource_011, jp_data_0813b288_start + 0x2EDDBC
    .global gUnk_MapDataResource_012
    .set gUnk_MapDataResource_012, jp_data_0813b288_start + 0x2EE6E0
    .global gUnk_MapDataResource_013
    .set gUnk_MapDataResource_013, jp_data_0813b288_start + 0x2EEB94
    .global gUnk_MapDataResource_010
    .set gUnk_MapDataResource_010, jp_data_0813b288_start + 0x2EEC28
    .global gUnk_MapDataResource_070
    .set gUnk_MapDataResource_070, jp_data_0813b288_start + 0x2EECFC
    .global gUnk_MapDataResource_071
    .set gUnk_MapDataResource_071, jp_data_0813b288_start + 0x2F2678
    .global gUnk_MapDataResource_084
    .set gUnk_MapDataResource_084, jp_data_0813b288_start + 0x2F2744
    .global gUnk_MapDataResource_085
    .set gUnk_MapDataResource_085, jp_data_0813b288_start + 0x2F31C4
    .global gUnk_MapDataResource_086
    .set gUnk_MapDataResource_086, jp_data_0813b288_start + 0x2F38BC
    .global gUnk_MapDataResource_072
    .set gUnk_MapDataResource_072, jp_data_0813b288_start + 0x2F3E04
    .global gUnk_MapDataResource_078
    .set gUnk_MapDataResource_078, jp_data_0813b288_start + 0x2F3EC0
    .global gUnk_MapDataResource_079
    .set gUnk_MapDataResource_079, jp_data_0813b288_start + 0x2F7818
    .global gUnk_MapDataResource_089
    .set gUnk_MapDataResource_089, jp_data_0813b288_start + 0x2F78E0
    .global gUnk_MapDataResource_090
    .set gUnk_MapDataResource_090, jp_data_0813b288_start + 0x2F846C
    .global gUnk_MapDataResource_091
    .set gUnk_MapDataResource_091, jp_data_0813b288_start + 0x2F8ACC
    .global gUnk_MapDataResource_080
    .set gUnk_MapDataResource_080, jp_data_0813b288_start + 0x2F9004
    .global gUnk_MapDataResource_309
    .set gUnk_MapDataResource_309, jp_data_0813b288_start + 0x2F90BC
    .global gUnk_MapDataResource_310
    .set gUnk_MapDataResource_310, jp_data_0813b288_start + 0x2F92B0
    .global gUnk_MapDataResource_311
    .set gUnk_MapDataResource_311, jp_data_0813b288_start + 0x2F946C
    .global gUnk_MapDataResource_168
    .set gUnk_MapDataResource_168, jp_data_0813b288_start + 0x2F9538
    .global gUnk_MapDataResource_169
    .set gUnk_MapDataResource_169, jp_data_0813b288_start + 0x2F9704
    .global gUnk_MapDataResource_170
    .set gUnk_MapDataResource_170, jp_data_0813b288_start + 0x2F98C4
    .global gUnk_MapDataResource_159
    .set gUnk_MapDataResource_159, jp_data_0813b288_start + 0x2F9998
    .global gUnk_MapDataResource_160
    .set gUnk_MapDataResource_160, jp_data_0813b288_start + 0x2FB0A4
    .global gUnk_MapDataResource_161
    .set gUnk_MapDataResource_161, jp_data_0813b288_start + 0x2FB25C
    .global gUnk_MapDataResource_162
    .set gUnk_MapDataResource_162, jp_data_0813b288_start + 0x2FB4C4
    .global gUnk_MapDataResource_163
    .set gUnk_MapDataResource_163, jp_data_0813b288_start + 0x2FB6A4
    .global gUnk_MapDataResource_229
    .set gUnk_MapDataResource_229, jp_data_0813b288_start + 0x2FB7B8
    .global gUnk_MapDataResource_230
    .set gUnk_MapDataResource_230, jp_data_0813b288_start + 0x2FBAA0
    .global gUnk_MapDataResource_231
    .set gUnk_MapDataResource_231, jp_data_0813b288_start + 0x2FBB54
    .global gUnk_MapDataResource_224
    .set gUnk_MapDataResource_224, jp_data_0813b288_start + 0x2FBBF4
    .global gUnk_MapDataResource_225
    .set gUnk_MapDataResource_225, jp_data_0813b288_start + 0x2FBE68
    .global gUnk_MapDataResource_226
    .set gUnk_MapDataResource_226, jp_data_0813b288_start + 0x2FBEF8
    .global gUnk_MapDataResource_323
    .set gUnk_MapDataResource_323, jp_data_0813b288_start + 0x2FBF8C
    .global gUnk_MapDataResource_324
    .set gUnk_MapDataResource_324, jp_data_0813b288_start + 0x2FC110
    .global gUnk_MapDataResource_325
    .set gUnk_MapDataResource_325, jp_data_0813b288_start + 0x2FC1FC
    .global gUnk_MapDataResource_185
    .set gUnk_MapDataResource_185, jp_data_0813b288_start + 0x2FC280
    .global gUnk_MapDataResource_186
    .set gUnk_MapDataResource_186, jp_data_0813b288_start + 0x2FC5D0
    .global gUnk_MapDataResource_187
    .set gUnk_MapDataResource_187, jp_data_0813b288_start + 0x2FC7B4
    .global gUnk_MapDataResource_190
    .set gUnk_MapDataResource_190, jp_data_0813b288_start + 0x2FC92C
    .global gUnk_MapDataResource_191
    .set gUnk_MapDataResource_191, jp_data_0813b288_start + 0x2FCB78
    .global gUnk_MapDataResource_192
    .set gUnk_MapDataResource_192, jp_data_0813b288_start + 0x2FCDC4
    .global gUnk_MapDataResource_183
    .set gUnk_MapDataResource_183, jp_data_0813b288_start + 0x2FCF10
    .global gUnk_MapDataResource_184
    .set gUnk_MapDataResource_184, jp_data_0813b288_start + 0x30070C
    .global gUnk_MapDataResource_144
    .set gUnk_MapDataResource_144, jp_data_0813b288_start + 0x300884
    .global gUnk_MapDataResource_145
    .set gUnk_MapDataResource_145, jp_data_0813b288_start + 0x300B84
    .global gUnk_MapDataResource_146
    .set gUnk_MapDataResource_146, jp_data_0813b288_start + 0x300D84
    .global gUnk_MapDataResource_149
    .set gUnk_MapDataResource_149, jp_data_0813b288_start + 0x300EB0
    .global gUnk_MapDataResource_150
    .set gUnk_MapDataResource_150, jp_data_0813b288_start + 0x3011B8
    .global gUnk_MapDataResource_151
    .set gUnk_MapDataResource_151, jp_data_0813b288_start + 0x3014BC
    .global gUnk_MapDataResource_154
    .set gUnk_MapDataResource_154, jp_data_0813b288_start + 0x3015E8
    .global gUnk_MapDataResource_155
    .set gUnk_MapDataResource_155, jp_data_0813b288_start + 0x3018E4
    .global gUnk_MapDataResource_156
    .set gUnk_MapDataResource_156, jp_data_0813b288_start + 0x301B18
    .global gUnk_MapDataResource_142
    .set gUnk_MapDataResource_142, jp_data_0813b288_start + 0x301C0C
    .global gUnk_MapDataResource_143
    .set gUnk_MapDataResource_143, jp_data_0813b288_start + 0x3051D0
    .global gUnk_MapDataResource_302
    .set gUnk_MapDataResource_302, jp_data_0813b288_start + 0x30532C
    .global gUnk_MapDataResource_303
    .set gUnk_MapDataResource_303, jp_data_0813b288_start + 0x306D8C
    .global gUnk_MapDataResource_212
    .set gUnk_MapDataResource_212, jp_data_0813b288_start + 0x306EA0
    .global gUnk_MapDataResource_213
    .set gUnk_MapDataResource_213, jp_data_0813b288_start + 0x307058
    .global gUnk_MapDataResource_214
    .set gUnk_MapDataResource_214, jp_data_0813b288_start + 0x307158
    .global gUnk_MapDataResource_217
    .set gUnk_MapDataResource_217, jp_data_0813b288_start + 0x307278
    .global gUnk_MapDataResource_218
    .set gUnk_MapDataResource_218, jp_data_0813b288_start + 0x307410
    .global gUnk_MapDataResource_219
    .set gUnk_MapDataResource_219, jp_data_0813b288_start + 0x307528
    .global gUnk_MapDataResource_202
    .set gUnk_MapDataResource_202, jp_data_0813b288_start + 0x3075D0
    .global gUnk_MapDataResource_203
    .set gUnk_MapDataResource_203, jp_data_0813b288_start + 0x30774C
    .global gUnk_MapDataResource_204
    .set gUnk_MapDataResource_204, jp_data_0813b288_start + 0x30783C
    .global gUnk_MapDataResource_207
    .set gUnk_MapDataResource_207, jp_data_0813b288_start + 0x30791C
    .global gUnk_MapDataResource_208
    .set gUnk_MapDataResource_208, jp_data_0813b288_start + 0x307A10
    .global gUnk_MapDataResource_209
    .set gUnk_MapDataResource_209, jp_data_0813b288_start + 0x307B10
    .global gUnk_MapDataResource_200
    .set gUnk_MapDataResource_200, jp_data_0813b288_start + 0x307B94
    .global gUnk_MapDataResource_201
    .set gUnk_MapDataResource_201, jp_data_0813b288_start + 0x30A86C
    .global gUnk_MapDataResource_314
    .set gUnk_MapDataResource_314, jp_data_0813b288_start + 0x30A9D8
    .global gUnk_MapDataResource_315
    .set gUnk_MapDataResource_315, jp_data_0813b288_start + 0x30BAD4
    .global gUnk_MapDataResource_316
    .set gUnk_MapDataResource_316, jp_data_0813b288_start + 0x30BBD8
    .global gUnk_MapDataResource_317
    .set gUnk_MapDataResource_317, jp_data_0813b288_start + 0x30BD80
    .global gUnk_MapDataResource_318
    .set gUnk_MapDataResource_318, jp_data_0813b288_start + 0x30BEE8
    .global gUnk_MapDataResource_304
    .set gUnk_MapDataResource_304, jp_data_0813b288_start + 0x30BFE0
    .global gUnk_MapDataResource_305
    .set gUnk_MapDataResource_305, jp_data_0813b288_start + 0x30C1A4
    .global gUnk_MapDataResource_306
    .set gUnk_MapDataResource_306, jp_data_0813b288_start + 0x30C308
    .global gUnk_MapDataResource_249
    .set gUnk_MapDataResource_249, jp_data_0813b288_start + 0x30C3C0
    .global gUnk_MapDataResource_250
    .set gUnk_MapDataResource_250, jp_data_0813b288_start + 0x30EAF8
    .global gUnk_MapDataResource_261
    .set gUnk_MapDataResource_261, jp_data_0813b288_start + 0x30EC00
    .global gUnk_MapDataResource_262
    .set gUnk_MapDataResource_262, jp_data_0813b288_start + 0x30ED84
    .global gUnk_MapDataResource_263
    .set gUnk_MapDataResource_263, jp_data_0813b288_start + 0x30EE88
    .global gUnk_MapDataResource_256
    .set gUnk_MapDataResource_256, jp_data_0813b288_start + 0x30EF54
    .global gUnk_MapDataResource_257
    .set gUnk_MapDataResource_257, jp_data_0813b288_start + 0x30F0B4
    .global gUnk_MapDataResource_258
    .set gUnk_MapDataResource_258, jp_data_0813b288_start + 0x30F1B4
    .global gUnk_MapDataResource_251
    .set gUnk_MapDataResource_251, jp_data_0813b288_start + 0x30F274
    .global gUnk_MapDataResource_252
    .set gUnk_MapDataResource_252, jp_data_0813b288_start + 0x30F3C0
    .global gUnk_MapDataResource_253
    .set gUnk_MapDataResource_253, jp_data_0813b288_start + 0x30F4A8
    .global gUnk_MapDataResource_073
    .set gUnk_MapDataResource_073, jp_data_0813b288_start + 0x30F550
    .global gUnk_MapDataResource_074
    .set gUnk_MapDataResource_074, jp_data_0813b288_start + 0x30FA10
    .global gUnk_MapDataResource_075
    .set gUnk_MapDataResource_075, jp_data_0813b288_start + 0x30FC44
    .global gUnk_MapDataResource_081
    .set gUnk_MapDataResource_081, jp_data_0813b288_start + 0x30FE1C
    .global gUnk_MapDataResource_082
    .set gUnk_MapDataResource_082, jp_data_0813b288_start + 0x3102D0
    .global gUnk_MapDataResource_083
    .set gUnk_MapDataResource_083, jp_data_0813b288_start + 0x3104F0
    .global gUnk_MapDataResource_028
    .set gUnk_MapDataResource_028, jp_data_0813b288_start + 0x3106B0
    .global gUnk_MapDataResource_029
    .set gUnk_MapDataResource_029, jp_data_0813b288_start + 0x3153BC
    .global gUnk_MapDataResource_031
    .set gUnk_MapDataResource_031, jp_data_0813b288_start + 0x3154F0
    .global gUnk_MapDataResource_032
    .set gUnk_MapDataResource_032, jp_data_0813b288_start + 0x316570
    .global gUnk_MapDataResource_033
    .set gUnk_MapDataResource_033, jp_data_0813b288_start + 0x317608
    .global gUnk_MapDataResource_030
    .set gUnk_MapDataResource_030, jp_data_0813b288_start + 0x317C48
    .global gUnk_MapDataResource_036
    .set gUnk_MapDataResource_036, jp_data_0813b288_start + 0x317D7C
    .global gUnk_MapDataResource_037
    .set gUnk_MapDataResource_037, jp_data_0813b288_start + 0x31CC28
    .global gUnk_MapDataResource_039
    .set gUnk_MapDataResource_039, jp_data_0813b288_start + 0x31CD24
    .global gUnk_MapDataResource_040
    .set gUnk_MapDataResource_040, jp_data_0813b288_start + 0x31DC4C
    .global gUnk_MapDataResource_041
    .set gUnk_MapDataResource_041, jp_data_0813b288_start + 0x31EC64
    .global gUnk_MapDataResource_038
    .set gUnk_MapDataResource_038, jp_data_0813b288_start + 0x31F1B8
    .global gUnk_MapDataResource_122
    .set gUnk_MapDataResource_122, jp_data_0813b288_start + 0x3212E8
    .global gUnk_MapDataResource_123
    .set gUnk_MapDataResource_123, jp_data_0813b288_start + 0x3214C4
    .global gUnk_MapDataResource_124
    .set gUnk_MapDataResource_124, jp_data_0813b288_start + 0x321630
    .global gUnk_MapDataResource_127
    .set gUnk_MapDataResource_127, jp_data_0813b288_start + 0x321718
    .global gUnk_MapDataResource_128
    .set gUnk_MapDataResource_128, jp_data_0813b288_start + 0x3218F0
    .global gUnk_MapDataResource_129
    .set gUnk_MapDataResource_129, jp_data_0813b288_start + 0x321A1C
    .global gUnk_MapDataResource_120
    .set gUnk_MapDataResource_120, jp_data_0813b288_start + 0x321B18
    .global gUnk_MapDataResource_121
    .set gUnk_MapDataResource_121, jp_data_0813b288_start + 0x324C38
    .global gUnk_MapDataResource_338
    .set gUnk_MapDataResource_338, jp_data_0813b288_start + 0x324D5C
    .global gUnk_MapDataResource_339
    .set gUnk_MapDataResource_339, jp_data_0813b288_start + 0x325B14
    .global gUnk_MapDataResource_340
    .set gUnk_MapDataResource_340, jp_data_0813b288_start + 0x325BB4
    .global gUnk_MapDataResource_341
    .set gUnk_MapDataResource_341, jp_data_0813b288_start + 0x325C4C
    .global gUnk_MapDataResource_342
    .set gUnk_MapDataResource_342, jp_data_0813b288_start + 0x325C58
    .global gUnk_MapDataResource_345
    .set gUnk_MapDataResource_345, jp_data_0813b288_start + 0x325D04
    .global gUnk_MapDataResource_346
    .set gUnk_MapDataResource_346, jp_data_0813b288_start + 0x325D80
    .global gUnk_MapDataResource_347
    .set gUnk_MapDataResource_347, jp_data_0813b288_start + 0x325D8C
    .global gUnk_MapDataResource_350
    .set gUnk_MapDataResource_350, jp_data_0813b288_start + 0x325DE8
    .global gUnk_MapDataResource_351
    .set gUnk_MapDataResource_351, jp_data_0813b288_start + 0x325E74
    .global gUnk_MapDataResource_352
    .set gUnk_MapDataResource_352, jp_data_0813b288_start + 0x325E80
    .global gUnk_MapDataResource_355
    .set gUnk_MapDataResource_355, jp_data_0813b288_start + 0x325EE0
    .global gUnk_MapDataResource_356
    .set gUnk_MapDataResource_356, jp_data_0813b288_start + 0x325F60
    .global gUnk_MapDataResource_357
    .set gUnk_MapDataResource_357, jp_data_0813b288_start + 0x325F6C
    .global gUnk_MapDataResource_360
    .set gUnk_MapDataResource_360, jp_data_0813b288_start + 0x325FC8
    .global gUnk_MapDataResource_361
    .set gUnk_MapDataResource_361, jp_data_0813b288_start + 0x32607C
    .global gUnk_MapDataResource_362
    .set gUnk_MapDataResource_362, jp_data_0813b288_start + 0x3260A8
    .global gUnk_MapDataResource_365
    .set gUnk_MapDataResource_365, jp_data_0813b288_start + 0x326190
    .global gUnk_MapDataResource_366
    .set gUnk_MapDataResource_366, jp_data_0813b288_start + 0x326254
    .global gUnk_MapDataResource_367
    .set gUnk_MapDataResource_367, jp_data_0813b288_start + 0x326260
    .global gUnk_MapDataResource_014
    .set gUnk_MapDataResource_014, jp_data_0813b288_start + 0x344D94
    .global gUnk_MapDataResource_015
    .set gUnk_MapDataResource_015, jp_data_0813b288_start + 0x346F2C
    .global gUnk_MapDataResource_017
    .set gUnk_MapDataResource_017, jp_data_0813b288_start + 0x346FD0
    .global gUnk_MapDataResource_018
    .set gUnk_MapDataResource_018, jp_data_0813b288_start + 0x347560
    .global gUnk_MapDataResource_019
    .set gUnk_MapDataResource_019, jp_data_0813b288_start + 0x347784
    .global gUnk_MapDataResource_016
    .set gUnk_MapDataResource_016, jp_data_0813b288_start + 0x34781C
    .global gUnk_MapDataResource_022
    .set gUnk_MapDataResource_022, jp_data_0813b288_start + 0x3478BC
    .global gUnk_MapDataResource_023
    .set gUnk_MapDataResource_023, jp_data_0813b288_start + 0x349814
    .global gUnk_MapDataResource_025
    .set gUnk_MapDataResource_025, jp_data_0813b288_start + 0x3498B4
    .global gUnk_MapDataResource_026
    .set gUnk_MapDataResource_026, jp_data_0813b288_start + 0x349E40
    .global gUnk_MapDataResource_027
    .set gUnk_MapDataResource_027, jp_data_0813b288_start + 0x34A05C
    .global gUnk_MapDataResource_024
    .set gUnk_MapDataResource_024, jp_data_0813b288_start + 0x34A104
    .global gUnk_MapDataResource_132
    .set gUnk_MapDataResource_132, jp_data_0813b288_start + 0x34A198
    .global gUnk_MapDataResource_133
    .set gUnk_MapDataResource_133, jp_data_0813b288_start + 0x34A370
    .global gUnk_MapDataResource_134
    .set gUnk_MapDataResource_134, jp_data_0813b288_start + 0x34A474
    .global gUnk_MapDataResource_137
    .set gUnk_MapDataResource_137, jp_data_0813b288_start + 0x34A544
    .global gUnk_MapDataResource_138
    .set gUnk_MapDataResource_138, jp_data_0813b288_start + 0x34A744
    .global gUnk_MapDataResource_139
    .set gUnk_MapDataResource_139, jp_data_0813b288_start + 0x34A7FC
    .global gUnk_MapDataResource_328
    .set gUnk_MapDataResource_328, jp_data_0813b288_start + 0x34A870
    .global gUnk_MapDataResource_329
    .set gUnk_MapDataResource_329, jp_data_0813b288_start + 0x34A9FC
    .global gUnk_MapDataResource_330
    .set gUnk_MapDataResource_330, jp_data_0813b288_start + 0x34AB14
    .global gUnk_MapDataResource_166
    .set gUnk_MapDataResource_166, jp_data_0813b288_start + 0x34ABA0
    .global gUnk_MapDataResource_167
    .set gUnk_MapDataResource_167, jp_data_0813b288_start + 0x34D664
    .global gUnk_MapDataResource_173
    .set gUnk_MapDataResource_173, jp_data_0813b288_start + 0x34D7A4
    .global gUnk_MapDataResource_174
    .set gUnk_MapDataResource_174, jp_data_0813b288_start + 0x34D8F0
    .global gUnk_MapDataResource_175
    .set gUnk_MapDataResource_175, jp_data_0813b288_start + 0x34DA00
    .global gUnk_MapDataResource_239
    .set gUnk_MapDataResource_239, jp_data_0813b288_start + 0x34DAD8
    .global gUnk_MapDataResource_240
    .set gUnk_MapDataResource_240, jp_data_0813b288_start + 0x34DF9C
    .global gUnk_MapDataResource_241
    .set gUnk_MapDataResource_241, jp_data_0813b288_start + 0x34E0B8
    .global gUnk_MapDataResource_234
    .set gUnk_MapDataResource_234, jp_data_0813b288_start + 0x34E1B4
    .global gUnk_MapDataResource_235
    .set gUnk_MapDataResource_235, jp_data_0813b288_start + 0x34E54C
    .global gUnk_MapDataResource_236
    .set gUnk_MapDataResource_236, jp_data_0813b288_start + 0x34E628
    .global gUnk_MapDataResource_292
    .set gUnk_MapDataResource_292, jp_data_0813b288_start + 0x34E708
    .global gUnk_MapDataResource_293
    .set gUnk_MapDataResource_293, jp_data_0813b288_start + 0x34E8FC
    .global gUnk_MapDataResource_294
    .set gUnk_MapDataResource_294, jp_data_0813b288_start + 0x34E9E4
    .global gUnk_MapDataResource_042
    .set gUnk_MapDataResource_042, jp_data_0813b288_start + 0x34EAC0
    .global gUnk_MapDataResource_043
    .set gUnk_MapDataResource_043, jp_data_0813b288_start + 0x353938
    .global gUnk_MapDataResource_045
    .set gUnk_MapDataResource_045, jp_data_0813b288_start + 0x353AC4
    .global gUnk_MapDataResource_046
    .set gUnk_MapDataResource_046, jp_data_0813b288_start + 0x354638
    .global gUnk_MapDataResource_047
    .set gUnk_MapDataResource_047, jp_data_0813b288_start + 0x354FB0
    .global gUnk_MapDataResource_044
    .set gUnk_MapDataResource_044, jp_data_0813b288_start + 0x355438
    .global gUnk_MapDataResource_050
    .set gUnk_MapDataResource_050, jp_data_0813b288_start + 0x3555AC
    .global gUnk_MapDataResource_051
    .set gUnk_MapDataResource_051, jp_data_0813b288_start + 0x35A244
    .global gUnk_MapDataResource_053
    .set gUnk_MapDataResource_053, jp_data_0813b288_start + 0x35A36C
    .global gUnk_MapDataResource_054
    .set gUnk_MapDataResource_054, jp_data_0813b288_start + 0x35AC40
    .global gUnk_MapDataResource_055
    .set gUnk_MapDataResource_055, jp_data_0813b288_start + 0x35B5A8
    .global gUnk_MapDataResource_052
    .set gUnk_MapDataResource_052, jp_data_0813b288_start + 0x35BA20
    .global gUnk_MapDataResource_106
    .set gUnk_MapDataResource_106, jp_data_0813b288_start + 0x35BB30
    .global gUnk_MapDataResource_107
    .set gUnk_MapDataResource_107, jp_data_0813b288_start + 0x35E310
    .global gUnk_MapDataResource_109
    .set gUnk_MapDataResource_109, jp_data_0813b288_start + 0x35E3A0
    .global gUnk_MapDataResource_110
    .set gUnk_MapDataResource_110, jp_data_0813b288_start + 0x35E560
    .global gUnk_MapDataResource_111
    .set gUnk_MapDataResource_111, jp_data_0813b288_start + 0x35E710
    .global gUnk_MapDataResource_108
    .set gUnk_MapDataResource_108, jp_data_0813b288_start + 0x35E860
    .global gUnk_MapDataResource_114
    .set gUnk_MapDataResource_114, jp_data_0813b288_start + 0x35EA14
    .global gUnk_MapDataResource_115
    .set gUnk_MapDataResource_115, jp_data_0813b288_start + 0x3608C8
    .global gUnk_MapDataResource_117
    .set gUnk_MapDataResource_117, jp_data_0813b288_start + 0x360950
    .global gUnk_MapDataResource_118
    .set gUnk_MapDataResource_118, jp_data_0813b288_start + 0x360AB4
    .global gUnk_MapDataResource_119
    .set gUnk_MapDataResource_119, jp_data_0813b288_start + 0x360C5C
    .global gUnk_MapDataResource_116
    .set gUnk_MapDataResource_116, jp_data_0813b288_start + 0x360DA8
    .global gUnk_MapDataResource_333
    .set gUnk_MapDataResource_333, jp_data_0813b288_start + 0x360EDC
    .global gUnk_MapDataResource_334
    .set gUnk_MapDataResource_334, jp_data_0813b288_start + 0x361094
    .global gUnk_MapDataResource_335
    .set gUnk_MapDataResource_335, jp_data_0813b288_start + 0x3611C4
    .global gUnk_MapDataResource_370
    .set gUnk_MapDataResource_370, jp_data_0813b288_start + 0x361264
    .global gUnk_MapDataResource_371
    .set gUnk_MapDataResource_371, jp_data_0813b288_start + 0x3612F8
    .global gUnk_MapDataResource_374
    .set gUnk_MapDataResource_374, jp_data_0813b288_start + 0x361340
    .global gUnk_MapDataResource_375
    .set gUnk_MapDataResource_375, jp_data_0813b288_start + 0x36144C
    .global gUnk_MapDataResource_376
    .set gUnk_MapDataResource_376, jp_data_0813b288_start + 0x3614C0
    .global gUnk_MapDataResource_377
    .set gUnk_MapDataResource_377, jp_data_0813b288_start + 0x3616E4
    .global gUnk_MapDataResource_378
    .set gUnk_MapDataResource_378, jp_data_0813b288_start + 0x3617D0
    .global gUnk_MapDataResource_379
    .set gUnk_MapDataResource_379, jp_data_0813b288_start + 0x3619B4
    .global gUnk_MapDataResource_297
    .set gUnk_MapDataResource_297, jp_data_0813b288_start + 0x361A80
    .global gUnk_MapDataResource_298
    .set gUnk_MapDataResource_298, jp_data_0813b288_start + 0x361BF4
    .global gUnk_MapDataResource_299
    .set gUnk_MapDataResource_299, jp_data_0813b288_start + 0x361D98
    .global gUnk_MapDataResource_290
    .set gUnk_MapDataResource_290, jp_data_0813b288_start + 0x361E70
    .global gUnk_MapDataResource_291
    .set gUnk_MapDataResource_291, jp_data_0813b288_start + 0x364868
    .global gUnk_MapDataResource_280
    .set gUnk_MapDataResource_280, jp_data_0813b288_start + 0x364958
    .global gUnk_MapDataResource_281
    .set gUnk_MapDataResource_281, jp_data_0813b288_start + 0x364BBC
    .global gUnk_MapDataResource_282
    .set gUnk_MapDataResource_282, jp_data_0813b288_start + 0x364D14
    .global gUnk_MapDataResource_285
    .set gUnk_MapDataResource_285, jp_data_0813b288_start + 0x364E18
    .global gUnk_MapDataResource_286
    .set gUnk_MapDataResource_286, jp_data_0813b288_start + 0x36503C
    .global gUnk_MapDataResource_287
    .set gUnk_MapDataResource_287, jp_data_0813b288_start + 0x365164
    .global gUnk_MapDataResource_278
    .set gUnk_MapDataResource_278, jp_data_0813b288_start + 0x365204
    .global gUnk_MapDataResource_279
    .set gUnk_MapDataResource_279, jp_data_0813b288_start + 0x367184

    @ Region-neutral labels for FieldRenderRectDescriptor raw resources.
    @ Their payload types are not decoded yet.
    .global gUnk_FieldRenderResource_143
    .set gUnk_FieldRenderResource_143, jp_data_0813b288_start + 0x326314
    .global gUnk_FieldRenderResource_144
    .set gUnk_FieldRenderResource_144, jp_data_0813b288_start + 0x326514
    .global gUnk_FieldRenderResource_145
    .set gUnk_FieldRenderResource_145, jp_data_0813b288_start + 0x326714
    .global gUnk_FieldRenderResource_148
    .set gUnk_FieldRenderResource_148, jp_data_0813b288_start + 0x327478
    .global gUnk_FieldRenderResource_149
    .set gUnk_FieldRenderResource_149, jp_data_0813b288_start + 0x327678
    .global gUnk_FieldRenderResource_150
    .set gUnk_FieldRenderResource_150, jp_data_0813b288_start + 0x327878
    .global gUnk_FieldRenderResource_134
    .set gUnk_FieldRenderResource_134, jp_data_0813b288_start + 0x3285A4
    .global gUnk_FieldRenderResource_135
    .set gUnk_FieldRenderResource_135, jp_data_0813b288_start + 0x328BD4
    .global gUnk_FieldRenderResource_136
    .set gUnk_FieldRenderResource_136, jp_data_0813b288_start + 0x329204
    .global gUnk_FieldRenderResource_128
    .set gUnk_FieldRenderResource_128, jp_data_0813b288_start + 0x329834
    .global gUnk_FieldRenderResource_129
    .set gUnk_FieldRenderResource_129, jp_data_0813b288_start + 0x329ADC
    .global gUnk_FieldRenderResource_139
    .set gUnk_FieldRenderResource_139, jp_data_0813b288_start + 0x329D84
    .global gUnk_FieldRenderResource_140
    .set gUnk_FieldRenderResource_140, jp_data_0813b288_start + 0x329DB4
    .global gUnk_FieldRenderResource_132
    .set gUnk_FieldRenderResource_132, jp_data_0813b288_start + 0x32B168
    .global gUnk_FieldRenderResource_133
    .set gUnk_FieldRenderResource_133, jp_data_0813b288_start + 0x32B410
    .global gUnk_FieldRenderResource_038
    .set gUnk_FieldRenderResource_038, jp_data_0813b288_start + 0x32D288
    .global gUnk_FieldRenderResource_039
    .set gUnk_FieldRenderResource_039, jp_data_0813b288_start + 0x32D464
    .global gUnk_FieldRenderResource_040
    .set gUnk_FieldRenderResource_040, jp_data_0813b288_start + 0x32D640
    .global gUnk_FieldRenderResource_030
    .set gUnk_FieldRenderResource_030, jp_data_0813b288_start + 0x32D81C
    .global gUnk_FieldRenderResource_031
    .set gUnk_FieldRenderResource_031, jp_data_0813b288_start + 0x32D918
    .global gUnk_FieldRenderResource_032
    .set gUnk_FieldRenderResource_032, jp_data_0813b288_start + 0x32DA14
    .global gUnk_FieldRenderResource_012
    .set gUnk_FieldRenderResource_012, jp_data_0813b288_start + 0x32DB10
    .global gUnk_FieldRenderResource_013
    .set gUnk_FieldRenderResource_013, jp_data_0813b288_start + 0x32DD80
    .global gUnk_FieldRenderResource_006
    .set gUnk_FieldRenderResource_006, jp_data_0813b288_start + 0x32DFF0
    .global gUnk_FieldRenderResource_007
    .set gUnk_FieldRenderResource_007, jp_data_0813b288_start + 0x32E190
    .global gUnk_FieldRenderResource_000
    .set gUnk_FieldRenderResource_000, jp_data_0813b288_start + 0x32E330
    .global gUnk_FieldRenderResource_001
    .set gUnk_FieldRenderResource_001, jp_data_0813b288_start + 0x32E400
    .global gUnk_FieldRenderResource_024
    .set gUnk_FieldRenderResource_024, jp_data_0813b288_start + 0x32F518
    .global gUnk_FieldRenderResource_025
    .set gUnk_FieldRenderResource_025, jp_data_0813b288_start + 0x32F780
    .global gUnk_FieldRenderResource_018
    .set gUnk_FieldRenderResource_018, jp_data_0813b288_start + 0x32F9E8
    .global gUnk_FieldRenderResource_019
    .set gUnk_FieldRenderResource_019, jp_data_0813b288_start + 0x32FB38
    .global gUnk_FieldRenderResource_043
    .set gUnk_FieldRenderResource_043, jp_data_0813b288_start + 0x331178
    .global gUnk_FieldRenderResource_044
    .set gUnk_FieldRenderResource_044, jp_data_0813b288_start + 0x331334
    .global gUnk_FieldRenderResource_045
    .set gUnk_FieldRenderResource_045, jp_data_0813b288_start + 0x3314F0
    .global gUnk_FieldRenderResource_035
    .set gUnk_FieldRenderResource_035, jp_data_0813b288_start + 0x3316AC
    .global gUnk_FieldRenderResource_036
    .set gUnk_FieldRenderResource_036, jp_data_0813b288_start + 0x331798
    .global gUnk_FieldRenderResource_037
    .set gUnk_FieldRenderResource_037, jp_data_0813b288_start + 0x331884
    .global gUnk_FieldRenderResource_016
    .set gUnk_FieldRenderResource_016, jp_data_0813b288_start + 0x331970
    .global gUnk_FieldRenderResource_017
    .set gUnk_FieldRenderResource_017, jp_data_0813b288_start + 0x331BE0
    .global gUnk_FieldRenderResource_010
    .set gUnk_FieldRenderResource_010, jp_data_0813b288_start + 0x331E50
    .global gUnk_FieldRenderResource_011
    .set gUnk_FieldRenderResource_011, jp_data_0813b288_start + 0x331FD0
    .global gUnk_FieldRenderResource_004
    .set gUnk_FieldRenderResource_004, jp_data_0813b288_start + 0x332150
    .global gUnk_FieldRenderResource_005
    .set gUnk_FieldRenderResource_005, jp_data_0813b288_start + 0x332210
    .global gUnk_FieldRenderResource_028
    .set gUnk_FieldRenderResource_028, jp_data_0813b288_start + 0x333318
    .global gUnk_FieldRenderResource_029
    .set gUnk_FieldRenderResource_029, jp_data_0813b288_start + 0x333554
    .global gUnk_FieldRenderResource_022
    .set gUnk_FieldRenderResource_022, jp_data_0813b288_start + 0x333790
    .global gUnk_FieldRenderResource_023
    .set gUnk_FieldRenderResource_023, jp_data_0813b288_start + 0x3338C8
    .global gUnk_FieldRenderResource_154
    .set gUnk_FieldRenderResource_154, jp_data_0813b288_start + 0x334B3C
    .global gUnk_FieldRenderResource_157
    .set gUnk_FieldRenderResource_157, jp_data_0813b288_start + 0x334B88
    .global gUnk_FieldRenderResource_151
    .set gUnk_FieldRenderResource_151, jp_data_0813b288_start + 0x334B94
    .global gUnk_FieldRenderResource_166
    .set gUnk_FieldRenderResource_166, jp_data_0813b288_start + 0x334BA0
    .global gUnk_FieldRenderResource_160
    .set gUnk_FieldRenderResource_160, jp_data_0813b288_start + 0x334BFC
    .global gUnk_FieldRenderResource_163
    .set gUnk_FieldRenderResource_163, jp_data_0813b288_start + 0x334C58
    .global gUnk_FieldRenderResource_119
    .set gUnk_FieldRenderResource_119, jp_data_0813b288_start + 0x334CBC
    .global gUnk_FieldRenderResource_106
    .set gUnk_FieldRenderResource_106, jp_data_0813b288_start + 0x334CC4
    .global gUnk_FieldRenderResource_107
    .set gUnk_FieldRenderResource_107, jp_data_0813b288_start + 0x334CE4
    .global gUnk_FieldRenderResource_103
    .set gUnk_FieldRenderResource_103, jp_data_0813b288_start + 0x334EF4
    .global gUnk_FieldRenderResource_102
    .set gUnk_FieldRenderResource_102, jp_data_0813b288_start + 0x334F14
    .global gUnk_FieldRenderResource_089
    .set gUnk_FieldRenderResource_089, jp_data_0813b288_start + 0x334F34
    .global gUnk_FieldRenderResource_099
    .set gUnk_FieldRenderResource_099, jp_data_0813b288_start + 0x334F94
    .global gUnk_FieldRenderResource_082
    .set gUnk_FieldRenderResource_082, jp_data_0813b288_start + 0x334FB8
    .global gUnk_FieldRenderResource_083
    .set gUnk_FieldRenderResource_083, jp_data_0813b288_start + 0x3350E4
    .global gUnk_FieldRenderResource_096
    .set gUnk_FieldRenderResource_096, jp_data_0813b288_start + 0x335210
    .global gUnk_FieldRenderResource_070
    .set gUnk_FieldRenderResource_070, jp_data_0813b288_start + 0x335228
    .global gUnk_FieldRenderResource_071
    .set gUnk_FieldRenderResource_071, jp_data_0813b288_start + 0x335240
    .global gUnk_FieldRenderResource_078
    .set gUnk_FieldRenderResource_078, jp_data_0813b288_start + 0x335258
    .global gUnk_FieldRenderResource_079
    .set gUnk_FieldRenderResource_079, jp_data_0813b288_start + 0x335270
    .global gUnk_FieldRenderResource_074
    .set gUnk_FieldRenderResource_074, jp_data_0813b288_start + 0x335288
    .global gUnk_FieldRenderResource_075
    .set gUnk_FieldRenderResource_075, jp_data_0813b288_start + 0x3352A0
    .global gUnk_FieldRenderResource_058
    .set gUnk_FieldRenderResource_058, jp_data_0813b288_start + 0x3352B8
    .global gUnk_FieldRenderResource_059
    .set gUnk_FieldRenderResource_059, jp_data_0813b288_start + 0x3352E8
    .global gUnk_FieldRenderResource_054
    .set gUnk_FieldRenderResource_054, jp_data_0813b288_start + 0x335318
    .global gUnk_FieldRenderResource_055
    .set gUnk_FieldRenderResource_055, jp_data_0813b288_start + 0x335348
    .global gUnk_FieldRenderResource_092
    .set gUnk_FieldRenderResource_092, jp_data_0813b288_start + 0x335378
    .global gUnk_FieldRenderResource_066
    .set gUnk_FieldRenderResource_066, jp_data_0813b288_start + 0x335468
    .global gUnk_FieldRenderResource_067
    .set gUnk_FieldRenderResource_067, jp_data_0813b288_start + 0x3354A0
    .global gUnk_FieldRenderResource_062
    .set gUnk_FieldRenderResource_062, jp_data_0813b288_start + 0x3354D8
    .global gUnk_FieldRenderResource_063
    .set gUnk_FieldRenderResource_063, jp_data_0813b288_start + 0x335510
    .global gUnk_FieldRenderResource_086
    .set gUnk_FieldRenderResource_086, jp_data_0813b288_start + 0x3356CC
    .global gUnk_FieldRenderResource_050
    .set gUnk_FieldRenderResource_050, jp_data_0813b288_start + 0x33572C
    .global gUnk_FieldRenderResource_051
    .set gUnk_FieldRenderResource_051, jp_data_0813b288_start + 0x33575C
    .global gUnk_FieldRenderResource_046
    .set gUnk_FieldRenderResource_046, jp_data_0813b288_start + 0x33578C
    .global gUnk_FieldRenderResource_047
    .set gUnk_FieldRenderResource_047, jp_data_0813b288_start + 0x3357BC
    .global gUnk_FieldRenderResource_093
    .set gUnk_FieldRenderResource_093, jp_data_0813b288_start + 0x3357EC
    .global gUnk_FieldRenderResource_114
    .set gUnk_FieldRenderResource_114, jp_data_0813b288_start + 0x33FF38
    .global gUnk_FieldRenderResource_115
    .set gUnk_FieldRenderResource_115, jp_data_0813b288_start + 0x33FF58
    .global gUnk_FieldRenderResource_118
    .set gUnk_FieldRenderResource_118, jp_data_0813b288_start + 0x33FF78
    .global gUnk_FieldRenderResource_110
    .set gUnk_FieldRenderResource_110, jp_data_0813b288_start + 0x33FF80
    .global gUnk_FieldRenderResource_111
    .set gUnk_FieldRenderResource_111, jp_data_0813b288_start + 0x33FFA0
    .global gUnk_FieldRenderResource_122
    .set gUnk_FieldRenderResource_122, jp_data_0813b288_start + 0x340804
    .global gUnk_FieldRenderResource_123
    .set gUnk_FieldRenderResource_123, jp_data_0813b288_start + 0x3409C4
    .global gUnk_FieldRenderResource_126
    .set gUnk_FieldRenderResource_126, jp_data_0813b288_start + 0x342C0C
    .global gUnk_FieldRenderResource_127
    .set gUnk_FieldRenderResource_127, jp_data_0813b288_start + 0x342DCC

    @ Additional region-neutral labels for later gFieldRenderRectDescriptors entries.
    @ Their payload types are not known yet.
    .global gUnk_FieldRenderResource_169
    .set gUnk_FieldRenderResource_169, jp_data_0813b288_start + 0x334E44
    .global gUnk_FieldRenderResource_170
    .set gUnk_FieldRenderResource_170, jp_data_0813b288_start + 0x334E5C
    .global gUnk_FieldRenderResource_173
    .set gUnk_FieldRenderResource_173, jp_data_0813b288_start + 0x3357F8
    .global gUnk_FieldRenderResource_176
    .set gUnk_FieldRenderResource_176, jp_data_0813b288_start + 0x335818
    .global gUnk_FieldRenderResource_179
    .set gUnk_FieldRenderResource_179, jp_data_0813b288_start + 0x334D84
    .global gUnk_FieldRenderResource_182
    .set gUnk_FieldRenderResource_182, jp_data_0813b288_start + 0x334DA4
    .global gUnk_FieldRenderResource_183
    .set gUnk_FieldRenderResource_183, jp_data_0813b288_start + 0x334E04
    .global gUnk_FieldRenderResource_186
    .set gUnk_FieldRenderResource_186, jp_data_0813b288_start + 0x334E24
    .global gUnk_FieldRenderResource_187
    .set gUnk_FieldRenderResource_187, jp_data_0813b288_start + 0x334DC4
    .global gUnk_FieldRenderResource_190
    .set gUnk_FieldRenderResource_190, jp_data_0813b288_start + 0x334DE4
    .global gUnk_FieldRenderResource_191
    .set gUnk_FieldRenderResource_191, jp_data_0813b288_start + 0x334EB4
    .global gUnk_FieldRenderResource_194
    .set gUnk_FieldRenderResource_194, jp_data_0813b288_start + 0x334ED4
    .global gUnk_FieldRenderResource_195
    .set gUnk_FieldRenderResource_195, jp_data_0813b288_start + 0x334E74
    .global gUnk_FieldRenderResource_198
    .set gUnk_FieldRenderResource_198, jp_data_0813b288_start + 0x334E94
    .global gUnk_FieldRenderResource_199
    .set gUnk_FieldRenderResource_199, jp_data_0813b288_start + 0x334D44
    .global gUnk_FieldRenderResource_202
    .set gUnk_FieldRenderResource_202, jp_data_0813b288_start + 0x334D64
    .global gUnk_FieldRenderResource_203
    .set gUnk_FieldRenderResource_203, jp_data_0813b288_start + 0x334D04
    .global gUnk_FieldRenderResource_206
    .set gUnk_FieldRenderResource_206, jp_data_0813b288_start + 0x334D24
    .global gUnk_FieldRenderResource_207
    .set gUnk_FieldRenderResource_207, jp_data_0813b288_start + 0x32CDC4
    .global gUnk_FieldRenderResource_210
    .set gUnk_FieldRenderResource_210, jp_data_0813b288_start + 0x32CDE4
    .global gUnk_FieldRenderResource_211
    .set gUnk_FieldRenderResource_211, jp_data_0813b288_start + 0x32CD84
    .global gUnk_FieldRenderResource_214
    .set gUnk_FieldRenderResource_214, jp_data_0813b288_start + 0x32CDA4
    .global gUnk_FieldRenderResource_215
    .set gUnk_FieldRenderResource_215, jp_data_0813b288_start + 0x33FFC0
    .global gUnk_FieldRenderResource_218
    .set gUnk_FieldRenderResource_218, jp_data_0813b288_start + 0x33FFE0
    .global gUnk_FieldRenderResource_219
    .set gUnk_FieldRenderResource_219, jp_data_0813b288_start + 0x334B48
    .global gUnk_FieldRenderResource_222
    .set gUnk_FieldRenderResource_222, jp_data_0813b288_start + 0x334B68
    .global gUnk_FieldRenderResource_223
    .set gUnk_FieldRenderResource_223, jp_data_0813b288_start + 0x3269D8
    .global gUnk_FieldRenderResource_224
    .set gUnk_FieldRenderResource_224, jp_data_0813b288_start + 0x3269F8
    .global gUnk_FieldRenderResource_225
    .set gUnk_FieldRenderResource_225, jp_data_0813b288_start + 0x327B3C
    .global gUnk_FieldRenderResource_226
    .set gUnk_FieldRenderResource_226, jp_data_0813b288_start + 0x327B5C
    .global gUnk_FieldRenderResource_227
    .set gUnk_FieldRenderResource_227, jp_data_0813b288_start + 0x334CB4

    .global gUnk_086D6458
gUnk_086D6458:
    .incbin "baserom_jp.gba", 0x45C5B4, 0xC
    .global gUnk_FieldPlotRenderRecord_026
gUnk_FieldPlotRenderRecord_026:
    .incbin "baserom_jp.gba", 0x45C5C0, 0x18
    .global gUnk_FieldPlotRenderRecord_020
gUnk_FieldPlotRenderRecord_020:
    .incbin "baserom_jp.gba", 0x45C5D8, 0x9C

    .global gUnk_086D6518
gUnk_086D6518:
    .incbin "baserom_jp.gba", 0x45C674, 0x8

    .global gUnk_086D6520
gUnk_086D6520:
    .incbin "baserom_jp.gba", 0x45C67C, 0x8

    .global gUnk_086D6528
gUnk_086D6528:
    .incbin "baserom_jp.gba", 0x45C684, 0x8
    .global gUnk_FieldPlotRenderRecord_024
gUnk_FieldPlotRenderRecord_024:
    .incbin "baserom_jp.gba", 0x45C68C, 0x18

    .global gUnk_086D6548
gUnk_086D6548:
    .incbin "baserom_jp.gba", 0x45C6A4, 0x60
    .global gUnk_FieldPlotRenderRecord_037
gUnk_FieldPlotRenderRecord_037:
    .incbin "baserom_jp.gba", 0x45C704, 0x18
    .global gUnk_FieldPlotRenderRecord_035
gUnk_FieldPlotRenderRecord_035:
    .incbin "baserom_jp.gba", 0x45C71C, 0x18
    .global gUnk_FieldPlotRenderRecord_038
gUnk_FieldPlotRenderRecord_038:
    .incbin "baserom_jp.gba", 0x45C734, 0x18
    .global gUnk_FieldPlotRenderRecord_036
gUnk_FieldPlotRenderRecord_036:
    .incbin "baserom_jp.gba", 0x45C74C, 0x18

    .global gUnk_086D6608
gUnk_086D6608:
    .incbin "baserom_jp.gba", 0x45C764, 0xC
    .global gUnk_FieldPlotRenderRecord_022
gUnk_FieldPlotRenderRecord_022:
    .incbin "baserom_jp.gba", 0x45C770, 0x18
    .global gUnk_FieldPlotRenderRecord_029
gUnk_FieldPlotRenderRecord_029:
    .incbin "baserom_jp.gba", 0x45C788, 0x18
    .global gUnk_FieldPlotRenderRecord_027
gUnk_FieldPlotRenderRecord_027:
    .incbin "baserom_jp.gba", 0x45C7A0, 0x18
    .global gUnk_FieldPlotRenderRecord_030
gUnk_FieldPlotRenderRecord_030:
    .incbin "baserom_jp.gba", 0x45C7B8, 0x18
    .global gUnk_FieldPlotRenderRecord_028
gUnk_FieldPlotRenderRecord_028:
    .incbin "baserom_jp.gba", 0x45C7D0, 0x18
    .global gUnk_FieldPlotRenderRecord_021
gUnk_FieldPlotRenderRecord_021:
    .incbin "baserom_jp.gba", 0x45C7E8, 0xC

    .incbin "baserom_jp.gba", 0x45C7F4, (0x462520 - 0x45C7F4)

    .global gActorStateGridCellType0Data
gActorStateGridCellType0Data:
    .incbin "baserom_jp.gba", 0x462520, 0xC

    .global gActorStateGridCellType1Data
gActorStateGridCellType1Data:
    .incbin "baserom_jp.gba", 0x46252C, 0xC

    .global gActorStateGridCellType2Data
gActorStateGridCellType2Data:
    .incbin "baserom_jp.gba", 0x462538, 0xC

    .global gActorStateGridCellType3Data
gActorStateGridCellType3Data:
    .incbin "baserom_jp.gba", 0x462544, 0xC

    @ The following raw range also contains the still-undecoded Intro Scene
    @ unpack inputs. Keep the raw payloads intact, but expose their native
    @ boundaries directly so the C++ pointer table has real relocations.
jp_data_08462550_start:
    .global gActorStateGridCellType4Data
gActorStateGridCellType4Data:
    .incbin "baserom_jp.gba", 0x462550, (0x4AE370 - 0x462550)

    @ UI resource archive payloads referenced directly by the JP UI constructor.
    @ The formats remain undecoded, but each label names byte zero of its
    @ physical JP record so callers use ordinary relocations.
    .global gUnk_084AE370
gUnk_084AE370:
    .incbin "baserom_jp.gba", 0x4AE370, (0x4AE488 - 0x4AE370)
    .global gUnk_084AE488
gUnk_084AE488:
    .incbin "baserom_jp.gba", 0x4AE488, (0x4AF4E4 - 0x4AE488)
    .global gUnk_084AF4E4
gUnk_084AF4E4:
    .incbin "baserom_jp.gba", 0x4AF4E4, (0x4C7B5C - 0x4AF4E4)

    @ Twenty 0x500-byte Raw-LZ object-tile payloads, unpacked in order by
    @ func_0805FBB8. Their OAM composition remains runtime data.
    .global gUnk_IntroSceneUnpackSource_000
gUnk_IntroSceneUnpackSource_000:
    .incbin "build/jp/graphics/intro_scene/objects/object_00.0x70"
    .global gUnk_IntroSceneUnpackSource_001
gUnk_IntroSceneUnpackSource_001:
    .incbin "build/jp/graphics/intro_scene/objects/object_01.0x70"
    .global gUnk_IntroSceneUnpackSource_002
gUnk_IntroSceneUnpackSource_002:
    .incbin "build/jp/graphics/intro_scene/objects/object_02.0x70"
    .global gUnk_IntroSceneUnpackSource_003
gUnk_IntroSceneUnpackSource_003:
    .incbin "build/jp/graphics/intro_scene/objects/object_03.0x70"
    .global gUnk_IntroSceneUnpackSource_004
gUnk_IntroSceneUnpackSource_004:
    .incbin "build/jp/graphics/intro_scene/objects/object_04.0x70"
    .global gUnk_IntroSceneUnpackSource_005
gUnk_IntroSceneUnpackSource_005:
    .incbin "build/jp/graphics/intro_scene/objects/object_05.0x70"
    .global gUnk_IntroSceneUnpackSource_006
gUnk_IntroSceneUnpackSource_006:
    .incbin "build/jp/graphics/intro_scene/objects/object_06.0x70"
    .global gUnk_IntroSceneUnpackSource_007
gUnk_IntroSceneUnpackSource_007:
    .incbin "build/jp/graphics/intro_scene/objects/object_07.0x70"
    .global gUnk_IntroSceneUnpackSource_008
gUnk_IntroSceneUnpackSource_008:
    .incbin "build/jp/graphics/intro_scene/objects/object_08.0x70"
    .global gUnk_IntroSceneUnpackSource_009
gUnk_IntroSceneUnpackSource_009:
    .incbin "build/jp/graphics/intro_scene/objects/object_09.0x70"
    .global gUnk_IntroSceneUnpackSource_010
gUnk_IntroSceneUnpackSource_010:
    .incbin "build/jp/graphics/intro_scene/objects/object_10.0x70"
    .global gUnk_IntroSceneUnpackSource_011
gUnk_IntroSceneUnpackSource_011:
    .incbin "build/jp/graphics/intro_scene/objects/object_11.0x70"
    .global gUnk_IntroSceneUnpackSource_012
gUnk_IntroSceneUnpackSource_012:
    .incbin "build/jp/graphics/intro_scene/objects/object_12.0x70"
    .global gUnk_IntroSceneUnpackSource_013
gUnk_IntroSceneUnpackSource_013:
    .incbin "build/jp/graphics/intro_scene/objects/object_13.0x70"
    .global gUnk_IntroSceneUnpackSource_014
gUnk_IntroSceneUnpackSource_014:
    .incbin "build/jp/graphics/intro_scene/objects/object_14.0x70"
    .global gUnk_IntroSceneUnpackSource_015
gUnk_IntroSceneUnpackSource_015:
    .incbin "build/jp/graphics/intro_scene/objects/object_15.0x70"
    .global gUnk_IntroSceneUnpackSource_016
gUnk_IntroSceneUnpackSource_016:
    .incbin "build/jp/graphics/intro_scene/objects/object_16.0x70"
    .global gUnk_IntroSceneUnpackSource_017
gUnk_IntroSceneUnpackSource_017:
    .incbin "build/jp/graphics/intro_scene/objects/object_17.0x70"
    .global gUnk_IntroSceneUnpackSource_018
gUnk_IntroSceneUnpackSource_018:
    .incbin "build/jp/graphics/intro_scene/objects/object_18.0x70"
    .global gUnk_IntroSceneUnpackSource_019
gUnk_IntroSceneUnpackSource_019:
    .incbin "build/jp/graphics/intro_scene/objects/object_19.0x70"
    .incbin "build/jp/graphics/intro_scene/background_tiles.0x70"
    .incbin "build/jp/graphics/intro_scene/background_palettes.gbapal"
    .global gUnk_084CDBDC
gUnk_084CDBDC:
    .incbin "build/jp/graphics/intro_scene/indexed_archive/archive.0x70"

    @ Four Huffman-4/LZ3 streams unpacked by the earlier Intro Scene startup
    @ path.  Each source is an interleaved pair of 32-by-32 BG tilemaps.
    .global gUnk_IntroSceneStartupUnpackSource_000
gUnk_IntroSceneStartupUnpackSource_000:
    .incbin "build/jp/graphics/intro_scene/startup_tilemaps/startup_00.0x70"
    .global gUnk_IntroSceneStartupUnpackSource_001
gUnk_IntroSceneStartupUnpackSource_001:
    .incbin "build/jp/graphics/intro_scene/startup_tilemaps/startup_01.0x70"
    .global gUnk_IntroSceneStartupUnpackSource_002
gUnk_IntroSceneStartupUnpackSource_002:
    .incbin "build/jp/graphics/intro_scene/startup_tilemaps/startup_02.0x70"
    .global gUnk_IntroSceneStartupUnpackSource_003
gUnk_IntroSceneStartupUnpackSource_003:
    .incbin "build/jp/graphics/intro_scene/startup_tilemaps/startup_03.0x70"
    .incbin "build/jp/graphics/intro_scene/startup_visual/startup_tiles.0x70"
    .global gUnk_084D4AC4
gUnk_084D4AC4:
    .incbin "build/jp/graphics/intro_scene/startup_visual/startup_palette_banks.gbapal"
    .global gUnk_084D4CC4
gUnk_084D4CC4:
    .incbin "build/jp/graphics/intro_scene/small_indexed_archive/archive.bin"
    .global gUnk_084D4DDC
gUnk_084D4DDC:
    .incbin "build/jp/graphics/ui/scene_08077810_jp/tiles.0x70"
    .global gUnk_084D529C
gUnk_084D529C:
    .incbin "build/jp/graphics/ui/scene_08077810_jp/palette.gbapal"
.global gUnk_084D52BC
gUnk_084D52BC:
    .incbin "build/jp/graphics/ui/scene_08077810_jp/layer_1.tilemap.0x70"
    .incbin "baserom_jp.gba", 0x4D5354, (0x4D5430 - 0x4D5354)
    .global gUnk_084D5430
gUnk_084D5430:
    .incbin "baserom_jp.gba", 0x4D5430, (0x4D5458 - 0x4D5430)
    .global gUnk_084D5458
gUnk_084D5458:
    .incbin "baserom_jp.gba", 0x4D5458, (0x4D5508 - 0x4D5458)
    .global gUnk_084D5508
gUnk_084D5508:
    .incbin "baserom_jp.gba", 0x4D5508, (0x4D556C - 0x4D5508)
    .global gUnk_084D556C
gUnk_084D556C:
    .incbin "baserom_jp.gba", 0x4D556C, (0x4D5808 - 0x4D556C)
    .global gUnk_084D5808
gUnk_084D5808:
    .incbin "baserom_jp.gba", 0x4D5808, (0x4D5868 - 0x4D5808)
    .global gUnk_084D5868
gUnk_084D5868:
    .incbin "baserom_jp.gba", 0x4D5868, (0x4D668C - 0x4D5868)
    .global gUnk_084D668C
gUnk_084D668C:
    .incbin "baserom_jp.gba", 0x4D668C, (0x4D7878 - 0x4D668C)
    FOMT_ANIMAL_FESTIVAL_ICON 00, 4bpp
    FOMT_ANIMAL_FESTIVAL_ICON 00, gbapal
.global gUnk_084D7918
gUnk_084D7918:
    FOMT_ANIMAL_FESTIVAL_ICON 01, 4bpp
    .global gUnk_084D7998
gUnk_084D7998:
    FOMT_ANIMAL_FESTIVAL_ICON 01, gbapal
    FOMT_ANIMAL_FESTIVAL_ICON 02, 4bpp
    FOMT_ANIMAL_FESTIVAL_ICON 02, gbapal
    FOMT_ANIMAL_FESTIVAL_ICON 03, 4bpp
    FOMT_ANIMAL_FESTIVAL_ICON 03, gbapal
    FOMT_ANIMAL_FESTIVAL_ICON 04, 4bpp
    FOMT_ANIMAL_FESTIVAL_ICON 04, gbapal
    FOMT_ANIMAL_FESTIVAL_ICON 05, 4bpp
    FOMT_ANIMAL_FESTIVAL_ICON 05, gbapal
    FOMT_ANIMAL_FESTIVAL_ICON 06, 4bpp
    FOMT_ANIMAL_FESTIVAL_ICON 06, gbapal
    FOMT_ANIMAL_FESTIVAL_ICON 07, 4bpp
    FOMT_ANIMAL_FESTIVAL_ICON 07, gbapal
    FOMT_ANIMAL_FESTIVAL_ICON 08, 4bpp
    FOMT_ANIMAL_FESTIVAL_ICON 08, gbapal
    FOMT_ANIMAL_FESTIVAL_ICON 09, 4bpp
    FOMT_ANIMAL_FESTIVAL_ICON 09, gbapal

    @ Records-screen minigame icon/palette boundaries.  The paired labels are
    @ preserved because records_screen_data.cc uses ordinary relocations.
    .global gUnk_084D7EB8
gUnk_084D7EB8:
    FOMT_RECORDS_TASK_TILES 00
    .global gUnk_084D7F38
gUnk_084D7F38:
    FOMT_RECORDS_TASK_PALETTE 00
    .global gUnk_084D7F58
gUnk_084D7F58:
    FOMT_RECORDS_TASK_TILES 01
    .global gUnk_084D7FD8
gUnk_084D7FD8:
    FOMT_RECORDS_TASK_PALETTE 01
    .global gUnk_084D7FF8
gUnk_084D7FF8:
    FOMT_RECORDS_TASK_TILES 02
    .global gUnk_084D8078
gUnk_084D8078:
    FOMT_RECORDS_TASK_PALETTE 02
    .global gUnk_084D8098
gUnk_084D8098:
    FOMT_RECORDS_TASK_TILES 03
    .global gUnk_084D8118
gUnk_084D8118:
    FOMT_RECORDS_TASK_PALETTE 03
    .global gUnk_084D8138
gUnk_084D8138:
    FOMT_RECORDS_TASK_TILES 04
    .global gUnk_084D81B8
gUnk_084D81B8:
    FOMT_RECORDS_TASK_PALETTE 04
    .global gUnk_084D81D8
gUnk_084D81D8:
    FOMT_RECORDS_TASK_TILES 05
    .global gUnk_084D8258
gUnk_084D8258:
    FOMT_RECORDS_TASK_PALETTE 05
    .global gUnk_084D8278
gUnk_084D8278:
    FOMT_RECORDS_TASK_TILES 06
    .global gUnk_084D82F8
gUnk_084D82F8:
    FOMT_RECORDS_TASK_PALETTE 06
    FOMT_FARM_STATUS_CREATURE_ICON 00, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 00, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 01, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 01, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 02, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 02, gbapal
    .global gUnk_084D84F8
gUnk_084D84F8:
    FOMT_FARM_STATUS_CREATURE_ICON 03, 4bpp
    .global gUnk_084D8578
gUnk_084D8578:
    FOMT_FARM_STATUS_CREATURE_ICON 03, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 04, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 04, gbapal
    .global gUnk_084D8638
gUnk_084D8638:
    FOMT_FARM_STATUS_CREATURE_ICON 05, 4bpp
    .global gUnk_084D86B8
gUnk_084D86B8:
    FOMT_FARM_STATUS_CREATURE_ICON 05, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 06, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 06, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 07, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 07, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 08, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 08, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 09, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 09, gbapal
    FOMT_FARM_STATUS_SELECTOR_CASE_09 4bpp
    FOMT_FARM_STATUS_SELECTOR_CASE_09 gbapal
    .incbin "baserom_jp.gba", 0x4D89F8, (0x4D8E98 - 0x4D89F8)
    FOMT_FARM_STATUS_CREATURE_ICON 10, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 10, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 11, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 11, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 12, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 12, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 13, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 13, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 14, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 14, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 15, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 15, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 16, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 16, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 17, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 17, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 18, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 18, gbapal
    FOMT_FARM_STATUS_CREATURE_ICON 19, 4bpp
    FOMT_FARM_STATUS_CREATURE_ICON 19, gbapal
    .incbin "baserom_jp.gba", 0x4D94D8, (0x4D977C - 0x4D94D8)
    .global gUnk_084D977C
gUnk_084D977C:
    .incbin "baserom_jp.gba", 0x4D977C, (0x4DB1DC - 0x4D977C)
    .global gUnk_084DB1DC
gUnk_084DB1DC:
    .incbin "build/jp/graphics/ui/seasonal_background/bg_30.tilemap"
    .global gUnk_084DB4E8
gUnk_084DB4E8:
    .incbin "build/jp/graphics/ui/seasonal_background/bg_29.tilemap"
    .global gUnk_084DB7F4
gUnk_084DB7F4:
    .incbin "build/jp/graphics/ui/seasonal_background/nonwinter_tiles.0x70"
    .global gUnk_084DDA8C
gUnk_084DDA8C:
    .incbin "build/jp/graphics/ui/seasonal_background/nonwinter_palette_banks.gbapal"
    .global gUnk_084DDB4C
gUnk_084DDB4C:
    .incbin "baserom_jp.gba", 0x4DDB4C, (0x4DDB58 - 0x4DDB4C)
    .global gUnk_084DDB58
gUnk_084DDB58:
    .incbin "baserom_jp.gba", 0x4DDB58, (0x4DDB78 - 0x4DDB58)
    .global gUnk_084DDB78
gUnk_084DDB78:
    .incbin "baserom_jp.gba", 0x4DDB78, (0x4DDB84 - 0x4DDB78)
    .global gUnk_084DDB84
gUnk_084DDB84:
    .incbin "baserom_jp.gba", 0x4DDB84, (0x4DDBA4 - 0x4DDB84)
    .global gUnk_084DDBA4
gUnk_084DDBA4:
    .incbin "baserom_jp.gba", 0x4DDBA4, (0x4DDBB8 - 0x4DDBA4)
    .global gUnk_084DDBB8
gUnk_084DDBB8:
    .incbin "baserom_jp.gba", 0x4DDBB8, (0x4DDBC0 - 0x4DDBB8)
    .global gUnk_084DDBC0
gUnk_084DDBC0:
    .incbin "baserom_jp.gba", 0x4DDBC0, (0x4DDECC - 0x4DDBC0)
    .global gUnk_084DDECC
gUnk_084DDECC:
    .incbin "build/jp/graphics/ui/seasonal_background/winter/winter_bg_29.tilemap"
    .global gUnk_084DE1D8
gUnk_084DE1D8:
    .incbin "build/jp/graphics/ui/seasonal_background/winter/winter_tiles.0x70"
    .global gUnk_084E0304
gUnk_084E0304:
    .incbin "build/jp/graphics/ui/seasonal_background/winter/winter_palette_banks.gbapal"
    .global gUnk_084E03C4
gUnk_084E03C4:
    .incbin "baserom_jp.gba", 0x4E03C4, (0x4E03D0 - 0x4E03C4)
    .global gUnk_084E03D0
gUnk_084E03D0:
    .incbin "baserom_jp.gba", 0x4E03D0, (0x4E03E4 - 0x4E03D0)
    .global gUnk_084E03E4
gUnk_084E03E4:
    .incbin "baserom_jp.gba", 0x4E03E4, (0x4E0BA0 - 0x4E03E4)

    @ Shared UI resource payloads.  These direct labels let the ui_state
    @ table retain ordinary relocations without a synthetic base-plus-offset
    @ alias.  The first payload is 0x120 bytes by its typed table entry.
    .global gUnk_UiSharedResourceData_000
gUnk_UiSharedResourceData_000:
    .incbin "build/jp/graphics/ui/shared_resource/shared_resource.4bpp"
    .global gUnk_UiSharedResourceData_001
gUnk_UiSharedResourceData_001:
    .incbin "build/jp/graphics/ui/shared_resource/shared_resource.gbapal"

    @ The packed Mary stream occupies the original JP interval
    @ 0x084E0CE0..0x087515A8.  Resume the raw asset container after it.
    .section .rodata.mary_scripts_tail
    @ FoMT's 487 single-width glyphs are 8x12/1bpp records shared byte-for-
    @ byte by all four retail localizations. The authored PNG is rebuilt
    @ through gbagfx plus tools/fontpad; the emitted 0x16D4 bytes are verified
    @ against each regional ROM before this split.
    .incbin "build/jp/graphics/font/shared/single_width_font.1bpp"
    .incbin "baserom_jp.gba", 0x752C7C, (0x752E7C - 0x752C7C)
    @ The 6,922 double-width glyphs use 16x12/1bpp records and are likewise
    @ shared byte-for-byte by JP, US, EU, and DE. Their source PNG has the
    @ same lossless gbagfx/fontpad round-trip guarantees as the single-width
    @ font above.
    .incbin "build/jp/graphics/font/shared/double_width_font.1bpp"
    .incbin "baserom_jp.gba", 0x77B76C, (0x77F610 - 0x77B76C)

    @ Font renderer payloads. The byte layouts remain raw assets, while
    @ src/font.cc owns the typed references used by the glyph resolver.
    .global gFontSingleWidthGlyphData
    .set gFontSingleWidthGlyphData, jp_data_08462550_start + 0x2EF058
    .global gFontSingleByteGlyphIndices
    .set gFontSingleByteGlyphIndices, jp_data_08462550_start + 0x2F072C
    .global gFontDoubleWidthGlyphData
    .set gFontDoubleWidthGlyphData, jp_data_08462550_start + 0x2F092C
    .global gFontShiftJisGlyphIndices
    .set gFontShiftJisGlyphIndices, jp_data_08462550_start + 0x31921C

    .else
    .section .rodata

    @ The verified leading DE resource stream is 0x2080 bytes after the US
    @ stream.  Later DE assets are physically reordered and use direct labels
    @ inside the regional data block below.
    .macro FOMT_REGION_ASSET_INCBIN offset, length
    .ifdef REGION_DE
    .incbin "baserom_de.gba", (\offset + 0x2080), \length
    .else
    .incbin "baserom_us.gba", \offset, \length
    .endif
    .endm

    @ The non-winter seasonal background has independently bounded native
    @ tile, palette and 30-by-13 BG-map sources. DE reorders this group, so it
    @ must not use FOMT_REGION_ASSET_INCBIN's leading-stream adjustment.
    .macro FOMT_SEASONAL_NONWINTER_ASSET name
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/seasonal_background/\name"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/seasonal_background/\name"
    .else
    .incbin "build/us/graphics/ui/seasonal_background/\name"
    .endif
    .endif
    .endm

    @ Winter shares BG30 with the non-winter group but has its own H8/LZ3
    @ stream, six-bank palette and BG29 map. The payloads are common across
    @ JP/US/EU/DE while retaining each region's physical placement.
    .macro FOMT_SEASONAL_WINTER_ASSET name
    .ifdef REGION_DE
    .incbin "build/de/graphics/ui/seasonal_background/winter/\name"
    .else
    .ifdef REGION_EU
    .incbin "build/eu/graphics/ui/seasonal_background/winter/\name"
    .else
    .incbin "build/us/graphics/ui/seasonal_background/winter/\name"
    .endif
    .endif
    .endm

    @ Emits a direct record label at the exact byte consumed by the C++ table.
    @ The selected region's resource stream supplies the record bytes directly.
    .macro FOMT_FIELD_PLOT_RENDER_RECORD label, offset, length
    .global \label
\label:
    FOMT_REGION_ASSET_INCBIN \offset, \length
    .endm

    .ifdef REGION_EU
    @ The Mary stream starts at 0x082AC108 in the EU asset container.
    .LDATA_BEG = 0x13B2E0

us_data_0813b288_start:
	.incbin "baserom_eu.gba", (.LDATA_BEG), (0x2AC108 - .LDATA_BEG)
    .else
    .ifdef REGION_DE
    .LDATA_BEG = 0x13D308

us_data_0813b288_start:
	.include "asm/data/data_0813B288_de_initial.inc"
    .else
    .LDATA_BEG = 0x13B288

us_data_0813b288_start:
	.incbin "baserom_us.gba", (.LDATA_BEG), (0x2AC0B0 - .LDATA_BEG)
    .endif
    .endif

    @ Song header labels recovered from gSongTable.  The raw M4A payloads
    @ remain in this regional asset container; the C table uses these labels.
    .global gSong_Unused
    .set gSong_Unused, us_data_0813b288_start + 0x0
    .global gSong_Audio001
    .set gSong_Audio001, us_data_0813b288_start + 0x1622AC
    .global gSong_Audio002
    .set gSong_Audio002, us_data_0813b288_start + 0x162900
    .global gSong_Audio003
    .set gSong_Audio003, us_data_0813b288_start + 0x1630B8
    .global gSong_Audio004
    .set gSong_Audio004, us_data_0813b288_start + 0x1632E4
    .global gSong_Audio005
    .set gSong_Audio005, us_data_0813b288_start + 0x163E54
    .global gSong_Audio006
    .set gSong_Audio006, us_data_0813b288_start + 0x164840
    .global gSong_Audio007
    .set gSong_Audio007, us_data_0813b288_start + 0x164F44
    .global gSong_Audio008
    .set gSong_Audio008, us_data_0813b288_start + 0x165C84
    .global gSong_Audio009
    .set gSong_Audio009, us_data_0813b288_start + 0x16651C
    .global gSong_Audio010
    .set gSong_Audio010, us_data_0813b288_start + 0x1667A8
    .global gSong_Audio011
    .set gSong_Audio011, us_data_0813b288_start + 0x167A8C
    .global gSong_Audio012
    .set gSong_Audio012, us_data_0813b288_start + 0x1683A4
    .global gSong_Audio013
    .set gSong_Audio013, us_data_0813b288_start + 0x168BA8
    .global gSong_Audio014
    .set gSong_Audio014, us_data_0813b288_start + 0x169360
    .global gSong_Audio015
    .set gSong_Audio015, us_data_0813b288_start + 0x169904
    .global gSong_Audio016
    .set gSong_Audio016, us_data_0813b288_start + 0x169E90
    .global gSong_Audio017
    .set gSong_Audio017, us_data_0813b288_start + 0x16A5CC
    .global gSong_Audio018
    .set gSong_Audio018, us_data_0813b288_start + 0x16A86C
    .global gSong_Audio019
    .set gSong_Audio019, us_data_0813b288_start + 0x16B0BC
    .global gSong_Audio020
    .set gSong_Audio020, us_data_0813b288_start + 0x16B54C
    .global gSong_Audio021
    .set gSong_Audio021, us_data_0813b288_start + 0x16B974
    .global gSong_Audio022
    .set gSong_Audio022, us_data_0813b288_start + 0x16BD94
    .global gSong_Audio023
    .set gSong_Audio023, us_data_0813b288_start + 0x16C310
    .global gSong_Audio024
    .set gSong_Audio024, us_data_0813b288_start + 0x16C7E4
    .global gSong_Audio025
    .set gSong_Audio025, us_data_0813b288_start + 0x16D16C
    .global gSong_Audio026
    .set gSong_Audio026, us_data_0813b288_start + 0x16D4F8
    .global gSong_Audio027
    .set gSong_Audio027, us_data_0813b288_start + 0x16D87C
    .global gSong_Audio028
    .set gSong_Audio028, us_data_0813b288_start + 0x16D8A0
    .global gSong_Audio029
    .set gSong_Audio029, us_data_0813b288_start + 0x16D8BC
    .global gSong_Audio030
    .set gSong_Audio030, us_data_0813b288_start + 0x16D8D8
    .global gSong_Audio031
    .set gSong_Audio031, us_data_0813b288_start + 0x16D8F4
    .global gSong_Audio032
    .set gSong_Audio032, us_data_0813b288_start + 0x16D910
    .global gSong_Audio033
    .set gSong_Audio033, us_data_0813b288_start + 0x16DEE0
    .global gSong_Audio034
    .set gSong_Audio034, us_data_0813b288_start + 0x16E6A0
    .global gSong_Audio035
    .set gSong_Audio035, us_data_0813b288_start + 0x16F0BC
    .global gSong_Audio036
    .set gSong_Audio036, us_data_0813b288_start + 0x16F8D8
    .global gSong_Audio037
    .set gSong_Audio037, us_data_0813b288_start + 0x16FDB0
    .global gSong_Audio101
    .set gSong_Audio101, us_data_0813b288_start + 0x16FDD4
    .global gSong_Audio102
    .set gSong_Audio102, us_data_0813b288_start + 0x16FDF0
    .global gSong_Audio103
    .set gSong_Audio103, us_data_0813b288_start + 0x16FE0C
    .global gSong_Audio104
    .set gSong_Audio104, us_data_0813b288_start + 0x16FE30
    .global gSong_Audio105
    .set gSong_Audio105, us_data_0813b288_start + 0x16FE4C
    .global gSong_Audio106
    .set gSong_Audio106, us_data_0813b288_start + 0x16FE68
    .global gSong_Audio107
    .set gSong_Audio107, us_data_0813b288_start + 0x16FE84
    .global gSong_Audio108
    .set gSong_Audio108, us_data_0813b288_start + 0x16FEA0
    .global gSong_Audio109
    .set gSong_Audio109, us_data_0813b288_start + 0x16FEBC
    .global gSong_Audio110
    .set gSong_Audio110, us_data_0813b288_start + 0x16FED8
    .global gSong_Audio111
    .set gSong_Audio111, us_data_0813b288_start + 0x16FEF4
    .global gSong_Audio112
    .set gSong_Audio112, us_data_0813b288_start + 0x16FF10
    .global gSong_Audio113
    .set gSong_Audio113, us_data_0813b288_start + 0x16FF2C
    .global gSong_Audio114
    .set gSong_Audio114, us_data_0813b288_start + 0x16FF48
    .global gSong_Audio115
    .set gSong_Audio115, us_data_0813b288_start + 0x16FF64
    .global gSong_Audio116
    .set gSong_Audio116, us_data_0813b288_start + 0x16FF80
    .global gSong_Audio117
    .set gSong_Audio117, us_data_0813b288_start + 0x16FF9C
    .global gSong_Audio118
    .set gSong_Audio118, us_data_0813b288_start + 0x16FFB8
    .global gSong_Audio119
    .set gSong_Audio119, us_data_0813b288_start + 0x16FFD4
    .global gSong_Audio120
    .set gSong_Audio120, us_data_0813b288_start + 0x16FFF0
    .global gSong_Audio121
    .set gSong_Audio121, us_data_0813b288_start + 0x17000C
    .global gSong_Audio122
    .set gSong_Audio122, us_data_0813b288_start + 0x170028
    .global gSong_Audio123
    .set gSong_Audio123, us_data_0813b288_start + 0x170044
    .global gSong_Audio124
    .set gSong_Audio124, us_data_0813b288_start + 0x170060
    .global gSong_Audio125
    .set gSong_Audio125, us_data_0813b288_start + 0x17007C
    .global gSong_Audio126
    .set gSong_Audio126, us_data_0813b288_start + 0x170098
    .global gSong_Audio127
    .set gSong_Audio127, us_data_0813b288_start + 0x1700B4
    .global gSong_Audio128
    .set gSong_Audio128, us_data_0813b288_start + 0x1700D0
    .global gSong_Audio129
    .set gSong_Audio129, us_data_0813b288_start + 0x1700EC
    .global gSong_Audio130
    .set gSong_Audio130, us_data_0813b288_start + 0x170108
    .global gSong_Audio131
    .set gSong_Audio131, us_data_0813b288_start + 0x170124
    .global gSong_Audio132
    .set gSong_Audio132, us_data_0813b288_start + 0x170140
    .global gSong_Audio133
    .set gSong_Audio133, us_data_0813b288_start + 0x17015C
    .global gSong_Audio134
    .set gSong_Audio134, us_data_0813b288_start + 0x170178
    .global gSong_Audio135
    .set gSong_Audio135, us_data_0813b288_start + 0x170194
    .global gSong_Audio136
    .set gSong_Audio136, us_data_0813b288_start + 0x1701B0
    .global gSong_Audio137
    .set gSong_Audio137, us_data_0813b288_start + 0x1701D0
    .global gSong_Audio138
    .set gSong_Audio138, us_data_0813b288_start + 0x1701EC
    .global gSong_Audio139
    .set gSong_Audio139, us_data_0813b288_start + 0x170208
    .global gSong_Audio140
    .set gSong_Audio140, us_data_0813b288_start + 0x170224
    .global gSong_Audio141
    .set gSong_Audio141, us_data_0813b288_start + 0x170240
    .global gSong_Audio142
    .set gSong_Audio142, us_data_0813b288_start + 0x17026C
    .global gSong_Audio143
    .set gSong_Audio143, us_data_0813b288_start + 0x170288
    .global gSong_Audio144
    .set gSong_Audio144, us_data_0813b288_start + 0x1702A4
    .global gSong_Audio145
    .set gSong_Audio145, us_data_0813b288_start + 0x1702D0
    .global gSong_Audio146
    .set gSong_Audio146, us_data_0813b288_start + 0x1702F4
    .global gSong_Audio147
    .set gSong_Audio147, us_data_0813b288_start + 0x170318
    .global gSong_Audio148
    .set gSong_Audio148, us_data_0813b288_start + 0x170334
    .global gSong_Audio149
    .set gSong_Audio149, us_data_0813b288_start + 0x170354
    .global gSong_Audio150
    .set gSong_Audio150, us_data_0813b288_start + 0x170370
    .global gSong_Audio151
    .set gSong_Audio151, us_data_0813b288_start + 0x17038C
    .global gSong_Audio152
    .set gSong_Audio152, us_data_0813b288_start + 0x1703A8
    .global gSong_Audio153
    .set gSong_Audio153, us_data_0813b288_start + 0x1703CC
    .global gSong_Audio154
    .set gSong_Audio154, us_data_0813b288_start + 0x1703E8
    .global gSong_Audio155
    .set gSong_Audio155, us_data_0813b288_start + 0x170408
    .global gSong_Audio156
    .set gSong_Audio156, us_data_0813b288_start + 0x170424
    .global gSong_Audio157
    .set gSong_Audio157, us_data_0813b288_start + 0x170484
    .global gSong_Audio158
    .set gSong_Audio158, us_data_0813b288_start + 0x1704B0
    .global gSong_Audio159
    .set gSong_Audio159, us_data_0813b288_start + 0x1704D8
    .global gSong_Audio160
    .set gSong_Audio160, us_data_0813b288_start + 0x170508
    .global gSong_Audio161
    .set gSong_Audio161, us_data_0813b288_start + 0x170524
    .global gSong_Audio162
    .set gSong_Audio162, us_data_0813b288_start + 0x170550
    .global gSong_Audio163
    .set gSong_Audio163, us_data_0813b288_start + 0x17056C
    .global gSong_Audio164
    .set gSong_Audio164, us_data_0813b288_start + 0x17058C
    .global gSong_Audio165
    .set gSong_Audio165, us_data_0813b288_start + 0x1705B0
    .global gSong_Audio166
    .set gSong_Audio166, us_data_0813b288_start + 0x1705CC
    .global gSong_Audio167
    .set gSong_Audio167, us_data_0813b288_start + 0x170600
    .global gSong_Audio168
    .set gSong_Audio168, us_data_0813b288_start + 0x170628
    .global gSong_Audio169
    .set gSong_Audio169, us_data_0813b288_start + 0x170644
    .global gSong_Audio170
    .set gSong_Audio170, us_data_0813b288_start + 0x170660
    .global gSong_Audio171
    .set gSong_Audio171, us_data_0813b288_start + 0x170680
    .global gSong_Audio172
    .set gSong_Audio172, us_data_0813b288_start + 0x17069C
    .global gSong_Audio173
    .set gSong_Audio173, us_data_0813b288_start + 0x1706D4
    .global gSong_Audio174
    .set gSong_Audio174, us_data_0813b288_start + 0x1706F8
    .global gSong_Audio175
    .set gSong_Audio175, us_data_0813b288_start + 0x17076C
    .global gSong_Audio176
    .set gSong_Audio176, us_data_0813b288_start + 0x1707F8
    .global gSong_Audio177
    .set gSong_Audio177, us_data_0813b288_start + 0x170818
    .global gSong_Audio178
    .set gSong_Audio178, us_data_0813b288_start + 0x170874
    .global gSong_Audio179
    .set gSong_Audio179, us_data_0813b288_start + 0x1708E0
    .global gSong_Audio180
    .set gSong_Audio180, us_data_0813b288_start + 0x17090C
    .global gSong_Audio181
    .set gSong_Audio181, us_data_0813b288_start + 0x17093C
    .global gSong_Audio182
    .set gSong_Audio182, us_data_0813b288_start + 0x170980
    .global gSong_Audio183
    .set gSong_Audio183, us_data_0813b288_start + 0x170AEC
    .global gSong_Audio184
    .set gSong_Audio184, us_data_0813b288_start + 0x170B10
    .global gSong_Audio185
    .set gSong_Audio185, us_data_0813b288_start + 0x170B2C
    .global gSong_Audio186
    .set gSong_Audio186, us_data_0813b288_start + 0x170B48
    .global gSong_Audio187
    .set gSong_Audio187, us_data_0813b288_start + 0x170B68
    .global gSong_Audio188
    .set gSong_Audio188, us_data_0813b288_start + 0x170B9C
    .global gSong_Audio189
    .set gSong_Audio189, us_data_0813b288_start + 0x170BC4
    .global gSong_Audio190
    .set gSong_Audio190, us_data_0813b288_start + 0x170C18
    .global gSong_Audio191
    .set gSong_Audio191, us_data_0813b288_start + 0x170C38
    .global gSong_Audio192
    .set gSong_Audio192, us_data_0813b288_start + 0x170C54
    .global gSong_Audio193
    .set gSong_Audio193, us_data_0813b288_start + 0x170C6C
    .global gSong_Audio197
    .set gSong_Audio197, us_data_0813b288_start + 0x170C88
    .global gSong_Audio198
    .set gSong_Audio198, us_data_0813b288_start + 0x170CA4
    .global gSong_Audio199
    .set gSong_Audio199, us_data_0813b288_start + 0x170CC0
    .global gSong_Audio200
    .set gSong_Audio200, us_data_0813b288_start + 0x170CE4
    .global gSong_Audio201
    .set gSong_Audio201, us_data_0813b288_start + 0x170D04
    .global gSong_Audio202
    .set gSong_Audio202, us_data_0813b288_start + 0x170D24
    .global gSong_Audio203
    .set gSong_Audio203, us_data_0813b288_start + 0x170D40
    .global gSong_Audio204
    .set gSong_Audio204, us_data_0813b288_start + 0x170D64
    .global gSong_Audio205
    .set gSong_Audio205, us_data_0813b288_start + 0x170D84
    .global gSong_Audio206
    .set gSong_Audio206, us_data_0813b288_start + 0x170DA4
    .global gSong_Audio207
    .set gSong_Audio207, us_data_0813b288_start + 0x170DC4
    .global gSong_Audio208
    .set gSong_Audio208, us_data_0813b288_start + 0x170DE0
    .global gSong_Audio209
    .set gSong_Audio209, us_data_0813b288_start + 0x170DFC
    .global gSong_Audio210
    .set gSong_Audio210, us_data_0813b288_start + 0x170E1C

    @ WaveData headers referenced by the recovered M4A ToneData tables.
    .global gM4aWaveData_000
    .set gM4aWaveData_000, us_data_0813b288_start + 0x4
    .global gM4aWaveData_001
    .set gM4aWaveData_001, us_data_0813b288_start + 0x8C44
    .global gM4aWaveData_002
    .set gM4aWaveData_002, us_data_0813b288_start + 0xA980
    .global gM4aWaveData_003
    .set gM4aWaveData_003, us_data_0813b288_start + 0xDB7C
    .global gM4aWaveData_004
    .set gM4aWaveData_004, us_data_0813b288_start + 0xF414
    .global gM4aWaveData_005
    .set gM4aWaveData_005, us_data_0813b288_start + 0x11B8C
    .global gM4aWaveData_006
    .set gM4aWaveData_006, us_data_0813b288_start + 0x16398
    .global gM4aWaveData_007
    .set gM4aWaveData_007, us_data_0813b288_start + 0x170AC
    .global gM4aWaveData_008
    .set gM4aWaveData_008, us_data_0813b288_start + 0x17484
    .global gM4aWaveData_009
    .set gM4aWaveData_009, us_data_0813b288_start + 0x1E37C
    .global gM4aWaveData_010
    .set gM4aWaveData_010, us_data_0813b288_start + 0x228CC
    .global gM4aWaveData_011
    .set gM4aWaveData_011, us_data_0813b288_start + 0x2869C
    .global gM4aWaveData_012
    .set gM4aWaveData_012, us_data_0813b288_start + 0x29C60
    .global gM4aWaveData_013
    .set gM4aWaveData_013, us_data_0813b288_start + 0x2E504
    .global gM4aWaveData_014
    .set gM4aWaveData_014, us_data_0813b288_start + 0x343DC
    .global gM4aWaveData_015
    .set gM4aWaveData_015, us_data_0813b288_start + 0x38DA0
    .global gM4aWaveData_016
    .set gM4aWaveData_016, us_data_0813b288_start + 0x3A900
    .global gM4aWaveData_017
    .set gM4aWaveData_017, us_data_0813b288_start + 0x3C168
    .global gM4aWaveData_018
    .set gM4aWaveData_018, us_data_0813b288_start + 0x42F88
    .global gM4aWaveData_019
    .set gM4aWaveData_019, us_data_0813b288_start + 0x4D8C4
    .global gM4aWaveData_020
    .set gM4aWaveData_020, us_data_0813b288_start + 0x50E70
    .global gM4aWaveData_021
    .set gM4aWaveData_021, us_data_0813b288_start + 0x53C04
    .global gM4aWaveData_022
    .set gM4aWaveData_022, us_data_0813b288_start + 0x60428
    .global gM4aWaveData_023
    .set gM4aWaveData_023, us_data_0813b288_start + 0x7387C
    .global gM4aWaveData_024
    .set gM4aWaveData_024, us_data_0813b288_start + 0x74C98
    .global gM4aWaveData_025
    .set gM4aWaveData_025, us_data_0813b288_start + 0x756E8
    .global gM4aWaveData_026
    .set gM4aWaveData_026, us_data_0813b288_start + 0x76B20
    .global gM4aWaveData_027
    .set gM4aWaveData_027, us_data_0813b288_start + 0x7E534
    .global gM4aWaveData_028
    .set gM4aWaveData_028, us_data_0813b288_start + 0x87BD4
    .global gM4aWaveData_029
    .set gM4aWaveData_029, us_data_0813b288_start + 0x91CF8
    .global gM4aWaveData_030
    .set gM4aWaveData_030, us_data_0813b288_start + 0x9508C
    .global gM4aWaveData_031
    .set gM4aWaveData_031, us_data_0813b288_start + 0x99024
    .global gM4aWaveData_032
    .set gM4aWaveData_032, us_data_0813b288_start + 0xA2DE8
    .global gM4aWaveData_033
    .set gM4aWaveData_033, us_data_0813b288_start + 0xABCFC
    .global gM4aWaveData_034
    .set gM4aWaveData_034, us_data_0813b288_start + 0xAE990
    .global gM4aWaveData_035
    .set gM4aWaveData_035, us_data_0813b288_start + 0xAF518
    .global gM4aWaveData_036
    .set gM4aWaveData_036, us_data_0813b288_start + 0xB5F2C
    .global gM4aWaveData_037
    .set gM4aWaveData_037, us_data_0813b288_start + 0xB8268
    .global gM4aWaveData_038
    .set gM4aWaveData_038, us_data_0813b288_start + 0xB95FC
    .global gM4aWaveData_039
    .set gM4aWaveData_039, us_data_0813b288_start + 0xBA8D4
    .global gM4aWaveData_040
    .set gM4aWaveData_040, us_data_0813b288_start + 0xBC06C
    .global gM4aWaveData_041
    .set gM4aWaveData_041, us_data_0813b288_start + 0xBC98C
    .global gM4aWaveData_042
    .set gM4aWaveData_042, us_data_0813b288_start + 0xBDF80
    .global gM4aWaveData_043
    .set gM4aWaveData_043, us_data_0813b288_start + 0xBE730
    .global gM4aWaveData_044
    .set gM4aWaveData_044, us_data_0813b288_start + 0xC0434
    .global gM4aWaveData_045
    .set gM4aWaveData_045, us_data_0813b288_start + 0xC2844
    .global gM4aWaveData_046
    .set gM4aWaveData_046, us_data_0813b288_start + 0xC3E30
    .global gM4aWaveData_047
    .set gM4aWaveData_047, us_data_0813b288_start + 0xC49D0
    .global gM4aWaveData_048
    .set gM4aWaveData_048, us_data_0813b288_start + 0xC50B8
    .global gM4aWaveData_049
    .set gM4aWaveData_049, us_data_0813b288_start + 0xC5770
    .global gM4aWaveData_050
    .set gM4aWaveData_050, us_data_0813b288_start + 0xC6188
    .global gM4aWaveData_051
    .set gM4aWaveData_051, us_data_0813b288_start + 0xC6820
    .global gM4aWaveData_052
    .set gM4aWaveData_052, us_data_0813b288_start + 0xC85F4
    .global gM4aWaveData_053
    .set gM4aWaveData_053, us_data_0813b288_start + 0xC9064
    .global gM4aWaveData_054
    .set gM4aWaveData_054, us_data_0813b288_start + 0xC960C
    .global gM4aWaveData_055
    .set gM4aWaveData_055, us_data_0813b288_start + 0xC9F58
    .global gM4aWaveData_056
    .set gM4aWaveData_056, us_data_0813b288_start + 0xCC914
    .global gM4aWaveData_057
    .set gM4aWaveData_057, us_data_0813b288_start + 0xCEC1C
    .global gM4aWaveData_058
    .set gM4aWaveData_058, us_data_0813b288_start + 0xCF180
    .global gM4aWaveData_059
    .set gM4aWaveData_059, us_data_0813b288_start + 0xD08A4
    .global gM4aWaveData_060
    .set gM4aWaveData_060, us_data_0813b288_start + 0xD1508
    .global gM4aWaveData_061
    .set gM4aWaveData_061, us_data_0813b288_start + 0xD2C24
    .global gM4aWaveData_062
    .set gM4aWaveData_062, us_data_0813b288_start + 0xD8CB8
    .global gM4aWaveData_063
    .set gM4aWaveData_063, us_data_0813b288_start + 0xDDD64
    .global gM4aWaveData_064
    .set gM4aWaveData_064, us_data_0813b288_start + 0xDFCB0
    .global gM4aWaveData_065
    .set gM4aWaveData_065, us_data_0813b288_start + 0xE0E28
    .global gM4aWaveData_066
    .set gM4aWaveData_066, us_data_0813b288_start + 0xE45F8
    .global gM4aWaveData_067
    .set gM4aWaveData_067, us_data_0813b288_start + 0xE9800
    .global gM4aWaveData_068
    .set gM4aWaveData_068, us_data_0813b288_start + 0xEBD88
    .global gM4aWaveData_069
    .set gM4aWaveData_069, us_data_0813b288_start + 0xEDDBC
    .global gM4aWaveData_070
    .set gM4aWaveData_070, us_data_0813b288_start + 0xEE684
    .global gM4aWaveData_071
    .set gM4aWaveData_071, us_data_0813b288_start + 0xF0174
    .global gM4aWaveData_072
    .set gM4aWaveData_072, us_data_0813b288_start + 0xF170C
    .global gM4aWaveData_073
    .set gM4aWaveData_073, us_data_0813b288_start + 0xF431C
    .global gM4aWaveData_074
    .set gM4aWaveData_074, us_data_0813b288_start + 0xF6A30
    .global gM4aWaveData_075
    .set gM4aWaveData_075, us_data_0813b288_start + 0xF7468
    .global gM4aWaveData_076
    .set gM4aWaveData_076, us_data_0813b288_start + 0xFAE94
    .global gM4aWaveData_077
    .set gM4aWaveData_077, us_data_0813b288_start + 0xFC830
    .global gM4aWaveData_078
    .set gM4aWaveData_078, us_data_0813b288_start + 0x100014
    .global gM4aWaveData_079
    .set gM4aWaveData_079, us_data_0813b288_start + 0x100470
    .global gM4aWaveData_080
    .set gM4aWaveData_080, us_data_0813b288_start + 0x100EF0
    .global gM4aWaveData_081
    .set gM4aWaveData_081, us_data_0813b288_start + 0x101D50
    .global gM4aWaveData_082
    .set gM4aWaveData_082, us_data_0813b288_start + 0x10BDC0
    .global gM4aWaveData_083
    .set gM4aWaveData_083, us_data_0813b288_start + 0x112720
    .global gM4aWaveData_084
    .set gM4aWaveData_084, us_data_0813b288_start + 0x117B5C
    .global gM4aWaveData_085
    .set gM4aWaveData_085, us_data_0813b288_start + 0x11C578
    .global gM4aWaveData_086
    .set gM4aWaveData_086, us_data_0813b288_start + 0x11F8D0
    .global gM4aWaveData_087
    .set gM4aWaveData_087, us_data_0813b288_start + 0x122D64
    .global gM4aWaveData_088
    .set gM4aWaveData_088, us_data_0813b288_start + 0x124920
    .global gM4aWaveData_089
    .set gM4aWaveData_089, us_data_0813b288_start + 0x126998
    .global gM4aWaveData_090
    .set gM4aWaveData_090, us_data_0813b288_start + 0x127B44
    .global gM4aWaveData_091
    .set gM4aWaveData_091, us_data_0813b288_start + 0x1293D8
    .global gM4aWaveData_092
    .set gM4aWaveData_092, us_data_0813b288_start + 0x12A8E4
    .global gM4aWaveData_093
    .set gM4aWaveData_093, us_data_0813b288_start + 0x12B5C4
    .global gM4aWaveData_094
    .set gM4aWaveData_094, us_data_0813b288_start + 0x12BF34
    .global gM4aWaveData_095
    .set gM4aWaveData_095, us_data_0813b288_start + 0x136BF0
    .global gM4aWaveData_096
    .set gM4aWaveData_096, us_data_0813b288_start + 0x13CE38
    .global gM4aWaveData_097
    .set gM4aWaveData_097, us_data_0813b288_start + 0x13E2DC
    .global gM4aWaveData_098
    .set gM4aWaveData_098, us_data_0813b288_start + 0x14B4B8
    .global gM4aWaveData_099
    .set gM4aWaveData_099, us_data_0813b288_start + 0x152C48
    .global gM4aWaveData_100
    .set gM4aWaveData_100, us_data_0813b288_start + 0x153420
    .global gM4aWaveData_101
    .set gM4aWaveData_101, us_data_0813b288_start + 0x154254
    .global gM4aWaveData_102
    .set gM4aWaveData_102, us_data_0813b288_start + 0x1547B8
    .global gM4aWaveData_103
    .set gM4aWaveData_103, us_data_0813b288_start + 0x1566EC
    .global gM4aWaveData_104
    .set gM4aWaveData_104, us_data_0813b288_start + 0x158300
    .global gM4aWaveData_105
    .set gM4aWaveData_105, us_data_0813b288_start + 0x15BAF4

	.ifndef REGION_DE
	.ifndef REGION_DE
	@ Region-neutral labels for FarmHouse tile-patch source payloads.
	@ The payload layouts remain raw; src/farm_house.cc owns their typed
	@ descriptor tables.
	.global gUnk_FarmHouseTilePatchResource_000
	.set gUnk_FarmHouseTilePatchResource_000, us_data_0813b288_start + 0x5A94B8
	.global gUnk_FarmHouseTilePatchResource_001
	.set gUnk_FarmHouseTilePatchResource_001, us_data_0813b288_start + 0x5AD2B8
	.global gUnk_FarmHouseTilePatchResource_002
	.set gUnk_FarmHouseTilePatchResource_002, us_data_0813b288_start + 0x5A7DEC
	.global gUnk_FarmHouseTilePatchResource_003
	.set gUnk_FarmHouseTilePatchResource_003, us_data_0813b288_start + 0x5ABCDC
	.global gUnk_FarmHouseTilePatchResource_004
	.set gUnk_FarmHouseTilePatchResource_004, us_data_0813b288_start + 0x5AB5B8
	.global gUnk_FarmHouseTilePatchResource_005
	.set gUnk_FarmHouseTilePatchResource_005, us_data_0813b288_start + 0x5AF330
	.global gUnk_FarmHouseTilePatchResource_006
	.set gUnk_FarmHouseTilePatchResource_006, us_data_0813b288_start + 0x5B0530
	.global gUnk_FarmHouseTilePatchResource_007
	.set gUnk_FarmHouseTilePatchResource_007, us_data_0813b288_start + 0x5A96FC
	.global gUnk_FarmHouseTilePatchResource_008
	.set gUnk_FarmHouseTilePatchResource_008, us_data_0813b288_start + 0x5AD4FC
	.global gUnk_FarmHouseTilePatchResource_009
	.set gUnk_FarmHouseTilePatchResource_009, us_data_0813b288_start + 0x5AAEB4
	.global gUnk_FarmHouseTilePatchResource_010
	.set gUnk_FarmHouseTilePatchResource_010, us_data_0813b288_start + 0x5AEC2C
	.global gUnk_FarmHouseTilePatchResource_011
	.set gUnk_FarmHouseTilePatchResource_011, us_data_0813b288_start + 0x5AAC70
	.global gUnk_FarmHouseTilePatchResource_012
	.set gUnk_FarmHouseTilePatchResource_012, us_data_0813b288_start + 0x5AE9E8
	.global gUnk_FarmHouseTilePatchResource_013
	.set gUnk_FarmHouseTilePatchResource_013, us_data_0813b288_start + 0x5A7A24
	.global gUnk_FarmHouseTilePatchResource_014
	.set gUnk_FarmHouseTilePatchResource_014, us_data_0813b288_start + 0x5BAFE8
	.global gUnk_FarmHouseTilePatchResource_015
	.set gUnk_FarmHouseTilePatchResource_015, us_data_0813b288_start + 0x5BBB6C
	.global gUnk_FarmHouseTilePatchResource_016
	.set gUnk_FarmHouseTilePatchResource_016, us_data_0813b288_start + 0x5BD3F0
	.global gUnk_FarmHouseTilePatchResource_017
	.set gUnk_FarmHouseTilePatchResource_017, us_data_0813b288_start + 0x5BDF74
	.global gUnk_FarmHouseTilePatchResource_018
	.set gUnk_FarmHouseTilePatchResource_018, us_data_0813b288_start + 0x5A1A20
	.global gUnk_FarmHouseTilePatchResource_019
	.set gUnk_FarmHouseTilePatchResource_019, us_data_0813b288_start + 0x5A1C24
	.global gUnk_FarmHouseTilePatchResource_020
	.set gUnk_FarmHouseTilePatchResource_020, us_data_0813b288_start + 0x5A18FC
	.global gUnk_FarmHouseTilePatchResource_021
	.set gUnk_FarmHouseTilePatchResource_021, us_data_0813b288_start + 0x5A2B84
	.global gUnk_FarmHouseTilePatchResource_022
	.set gUnk_FarmHouseTilePatchResource_022, us_data_0813b288_start + 0x5A2D88
	.global gUnk_FarmHouseTilePatchResource_023
	.set gUnk_FarmHouseTilePatchResource_023, us_data_0813b288_start + 0x5A2A60
	.global gUnk_FarmHouseTilePatchResource_024
	.set gUnk_FarmHouseTilePatchResource_024, us_data_0813b288_start + 0x5A4DCC
	.global gUnk_FarmHouseTilePatchResource_025
	.set gUnk_FarmHouseTilePatchResource_025, us_data_0813b288_start + 0x5A7C68
	.global gUnk_FarmHouseTilePatchResource_026
	.set gUnk_FarmHouseTilePatchResource_026, us_data_0813b288_start + 0x5A66A0
	.global gUnk_FarmHouseTilePatchResource_027
	.set gUnk_FarmHouseTilePatchResource_027, us_data_0813b288_start + 0x5B0820
	.global gUnk_FarmHouseTilePatchAnimationResource_000
	.set gUnk_FarmHouseTilePatchAnimationResource_000, us_data_0813b288_start + 0x5B3E08
	.global gUnk_FarmHouseTilePatchAnimationResource_001
	.set gUnk_FarmHouseTilePatchAnimationResource_001, us_data_0813b288_start + 0x5B3B04

	@ Region-neutral labels for FarmHouse visual descriptor resources.
	@ Their payload formats remain in the raw regional asset container.
	.global gUnk_FarmHouseVisualResource_000
	.set gUnk_FarmHouseVisualResource_000, us_data_0813b288_start + 0x5B1C08
	.global gUnk_FarmHouseVisualResource_001
	.set gUnk_FarmHouseVisualResource_001, us_data_0813b288_start + 0x5B1C38
	.global gUnk_FarmHouseVisualResource_004
	.set gUnk_FarmHouseVisualResource_004, us_data_0813b288_start + 0x5B1824
	.global gUnk_FarmHouseVisualResource_005
	.set gUnk_FarmHouseVisualResource_005, us_data_0813b288_start + 0x5B1BE8
	.global gUnk_FarmHouseVisualResource_006
	.set gUnk_FarmHouseVisualResource_006, us_data_0813b288_start + 0x5B20EC
	.global gUnk_FarmHouseVisualResource_007
	.set gUnk_FarmHouseVisualResource_007, us_data_0813b288_start + 0x5B21C0
	.global gUnk_FarmHouseVisualResource_010
	.set gUnk_FarmHouseVisualResource_010, us_data_0813b288_start + 0x5B1C68
	.global gUnk_FarmHouseVisualResource_011
	.set gUnk_FarmHouseVisualResource_011, us_data_0813b288_start + 0x5B208C
	.global gUnk_FarmHouseVisualResource_012
	.set gUnk_FarmHouseVisualResource_012, us_data_0813b288_start + 0x5B2294
	.global gUnk_FarmHouseVisualResource_013
	.set gUnk_FarmHouseVisualResource_013, us_data_0813b288_start + 0x5B7B1C
	.global gUnk_FarmHouseVisualResource_014
	.set gUnk_FarmHouseVisualResource_014, us_data_0813b288_start + 0x5B7BF0
	.global gUnk_FarmHouseVisualResource_015
	.set gUnk_FarmHouseVisualResource_015, us_data_0813b288_start + 0x5B76A4
	.global gUnk_FarmHouseVisualResource_016
	.set gUnk_FarmHouseVisualResource_016, us_data_0813b288_start + 0x5B7ABC
	.global gUnk_FarmHouseVisualResource_017
	.set gUnk_FarmHouseVisualResource_017, us_data_0813b288_start + 0x5B7CC4
	.global gUnk_FarmHouseVisualResource_018
	.set gUnk_FarmHouseVisualResource_018, us_data_0813b288_start + 0x5B52C8
	.global gUnk_FarmHouseVisualResource_019
	.set gUnk_FarmHouseVisualResource_019, us_data_0813b288_start + 0x5B5400
	.global gUnk_FarmHouseVisualResource_022
	.set gUnk_FarmHouseVisualResource_022, us_data_0813b288_start + 0x5B470C
	.global gUnk_FarmHouseVisualResource_023
	.set gUnk_FarmHouseVisualResource_023, us_data_0813b288_start + 0x5B52A8
	.global gUnk_FarmHouseVisualResource_024
	.set gUnk_FarmHouseVisualResource_024, us_data_0813b288_start + 0x5B6C84
	.global gUnk_FarmHouseVisualResource_025
	.set gUnk_FarmHouseVisualResource_025, us_data_0813b288_start + 0x5B7194
	.global gUnk_FarmHouseVisualResource_028
	.set gUnk_FarmHouseVisualResource_028, us_data_0813b288_start + 0x5B5538
	.global gUnk_FarmHouseVisualResource_029
	.set gUnk_FarmHouseVisualResource_029, us_data_0813b288_start + 0x5B6C24
	.global gUnk_FarmHouseVisualResource_030
	.set gUnk_FarmHouseVisualResource_030, us_data_0813b288_start + 0x5B26B8
	.global gUnk_FarmHouseVisualResource_031
	.set gUnk_FarmHouseVisualResource_031, us_data_0813b288_start + 0x5B26E0
	.global gUnk_FarmHouseVisualResource_034
	.set gUnk_FarmHouseVisualResource_034, us_data_0813b288_start + 0x5B22F4
	.global gUnk_FarmHouseVisualResource_035
	.set gUnk_FarmHouseVisualResource_035, us_data_0813b288_start + 0x5B2658
	.global gUnk_FarmHouseVisualResource_036
	.set gUnk_FarmHouseVisualResource_036, us_data_0813b288_start + 0x5B2708
	.global gUnk_FarmHouseVisualResource_037
	.set gUnk_FarmHouseVisualResource_037, us_data_0813b288_start + 0x5B38C4
	.global gUnk_FarmHouseVisualResource_038
	.set gUnk_FarmHouseVisualResource_038, us_data_0813b288_start + 0x5B39E4
	.global gUnk_FarmHouseVisualResource_041
	.set gUnk_FarmHouseVisualResource_041, us_data_0813b288_start + 0x5B2768
	.global gUnk_FarmHouseVisualResource_042
	.set gUnk_FarmHouseVisualResource_042, us_data_0813b288_start + 0x5B3844

	.endif

	.endif

	@ Region-neutral labels for gMapData raw resource targets.
	@ Their payload types are not decoded yet.
	.ifndef REGION_DE
	.global gUnk_MapDataResource_092
	.set gUnk_MapDataResource_092, us_data_0813b288_start + 0x53EE60
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_093
	.set gUnk_MapDataResource_093, us_data_0813b288_start + 0x54399C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_095
	.set gUnk_MapDataResource_095, us_data_0813b288_start + 0x543A94
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_096
	.set gUnk_MapDataResource_096, us_data_0813b288_start + 0x545788
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_097
	.set gUnk_MapDataResource_097, us_data_0813b288_start + 0x5463F4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_094
	.set gUnk_MapDataResource_094, us_data_0813b288_start + 0x546BCC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_100
	.set gUnk_MapDataResource_100, us_data_0813b288_start + 0x546CA4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_101
	.set gUnk_MapDataResource_101, us_data_0813b288_start + 0x54BCA4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_103
	.set gUnk_MapDataResource_103, us_data_0813b288_start + 0x54BD9C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_104
	.set gUnk_MapDataResource_104, us_data_0813b288_start + 0x54DB1C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_105
	.set gUnk_MapDataResource_105, us_data_0813b288_start + 0x54E784
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_102
	.set gUnk_MapDataResource_102, us_data_0813b288_start + 0x54EEF4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_244
	.set gUnk_MapDataResource_244, us_data_0813b288_start + 0x54EFC8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_245
	.set gUnk_MapDataResource_245, us_data_0813b288_start + 0x54F1D4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_246
	.set gUnk_MapDataResource_246, us_data_0813b288_start + 0x54F32C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_056
	.set gUnk_MapDataResource_056, us_data_0813b288_start + 0x54F3B4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_057
	.set gUnk_MapDataResource_057, us_data_0813b288_start + 0x552484
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_059
	.set gUnk_MapDataResource_059, us_data_0813b288_start + 0x552564
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_060
	.set gUnk_MapDataResource_060, us_data_0813b288_start + 0x552C80
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_061
	.set gUnk_MapDataResource_061, us_data_0813b288_start + 0x552EE0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_058
	.set gUnk_MapDataResource_058, us_data_0813b288_start + 0x552F5C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_064
	.set gUnk_MapDataResource_064, us_data_0813b288_start + 0x553040
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_065
	.set gUnk_MapDataResource_065, us_data_0813b288_start + 0x555614
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_067
	.set gUnk_MapDataResource_067, us_data_0813b288_start + 0x5556EC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_068
	.set gUnk_MapDataResource_068, us_data_0813b288_start + 0x555DF0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_069
	.set gUnk_MapDataResource_069, us_data_0813b288_start + 0x556014
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_066
	.set gUnk_MapDataResource_066, us_data_0813b288_start + 0x556080
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_222
	.set gUnk_MapDataResource_222, us_data_0813b288_start + 0x55614C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_223
	.set gUnk_MapDataResource_223, us_data_0813b288_start + 0x557A04
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_268
	.set gUnk_MapDataResource_268, us_data_0813b288_start + 0x557B28
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_269
	.set gUnk_MapDataResource_269, us_data_0813b288_start + 0x557D7C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_270
	.set gUnk_MapDataResource_270, us_data_0813b288_start + 0x557EB0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_273
	.set gUnk_MapDataResource_273, us_data_0813b288_start + 0x557F84
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_274
	.set gUnk_MapDataResource_274, us_data_0813b288_start + 0x5581A4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_275
	.set gUnk_MapDataResource_275, us_data_0813b288_start + 0x558318
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_266
	.set gUnk_MapDataResource_266, us_data_0813b288_start + 0x5583A8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_267
	.set gUnk_MapDataResource_267, us_data_0813b288_start + 0x55A920
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_195
	.set gUnk_MapDataResource_195, us_data_0813b288_start + 0x55AA28
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_196
	.set gUnk_MapDataResource_196, us_data_0813b288_start + 0x55AD48
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_197
	.set gUnk_MapDataResource_197, us_data_0813b288_start + 0x55AE4C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_321
	.set gUnk_MapDataResource_321, us_data_0813b288_start + 0x55AF38
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_322
	.set gUnk_MapDataResource_322, us_data_0813b288_start + 0x55C540
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_178
	.set gUnk_MapDataResource_178, us_data_0813b288_start + 0x560130
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_179
	.set gUnk_MapDataResource_179, us_data_0813b288_start + 0x560284
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_180
	.set gUnk_MapDataResource_180, us_data_0813b288_start + 0x5603D4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_000
	.set gUnk_MapDataResource_000, us_data_0813b288_start + 0x5604A8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_001
	.set gUnk_MapDataResource_001, us_data_0813b288_start + 0x564058
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_003
	.set gUnk_MapDataResource_003, us_data_0813b288_start + 0x56414C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_004
	.set gUnk_MapDataResource_004, us_data_0813b288_start + 0x5648F8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_005
	.set gUnk_MapDataResource_005, us_data_0813b288_start + 0x564D80
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_002
	.set gUnk_MapDataResource_002, us_data_0813b288_start + 0x564E10
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_008
	.set gUnk_MapDataResource_008, us_data_0813b288_start + 0x564F04
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_009
	.set gUnk_MapDataResource_009, us_data_0813b288_start + 0x568CC0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_011
	.set gUnk_MapDataResource_011, us_data_0813b288_start + 0x568DA4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_012
	.set gUnk_MapDataResource_012, us_data_0813b288_start + 0x5696C8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_013
	.set gUnk_MapDataResource_013, us_data_0813b288_start + 0x569B7C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_010
	.set gUnk_MapDataResource_010, us_data_0813b288_start + 0x569C10
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_070
	.set gUnk_MapDataResource_070, us_data_0813b288_start + 0x569CE4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_071
	.set gUnk_MapDataResource_071, us_data_0813b288_start + 0x56D660
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_084
	.set gUnk_MapDataResource_084, us_data_0813b288_start + 0x56D72C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_085
	.set gUnk_MapDataResource_085, us_data_0813b288_start + 0x56E1AC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_086
	.set gUnk_MapDataResource_086, us_data_0813b288_start + 0x56E8A4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_072
	.set gUnk_MapDataResource_072, us_data_0813b288_start + 0x56EDEC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_078
	.set gUnk_MapDataResource_078, us_data_0813b288_start + 0x56EEA8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_079
	.set gUnk_MapDataResource_079, us_data_0813b288_start + 0x572800
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_089
	.set gUnk_MapDataResource_089, us_data_0813b288_start + 0x5728C8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_090
	.set gUnk_MapDataResource_090, us_data_0813b288_start + 0x573454
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_091
	.set gUnk_MapDataResource_091, us_data_0813b288_start + 0x573AB4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_080
	.set gUnk_MapDataResource_080, us_data_0813b288_start + 0x573FEC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_309
	.set gUnk_MapDataResource_309, us_data_0813b288_start + 0x5740A4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_310
	.set gUnk_MapDataResource_310, us_data_0813b288_start + 0x574298
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_311
	.set gUnk_MapDataResource_311, us_data_0813b288_start + 0x574454
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_168
	.set gUnk_MapDataResource_168, us_data_0813b288_start + 0x574520
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_169
	.set gUnk_MapDataResource_169, us_data_0813b288_start + 0x5746EC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_170
	.set gUnk_MapDataResource_170, us_data_0813b288_start + 0x5748AC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_159
	.set gUnk_MapDataResource_159, us_data_0813b288_start + 0x574980
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_160
	.set gUnk_MapDataResource_160, us_data_0813b288_start + 0x57608C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_161
	.set gUnk_MapDataResource_161, us_data_0813b288_start + 0x576244
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_162
	.set gUnk_MapDataResource_162, us_data_0813b288_start + 0x5764AC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_163
	.set gUnk_MapDataResource_163, us_data_0813b288_start + 0x57668C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_229
	.set gUnk_MapDataResource_229, us_data_0813b288_start + 0x5767A0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_230
	.set gUnk_MapDataResource_230, us_data_0813b288_start + 0x576A88
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_231
	.set gUnk_MapDataResource_231, us_data_0813b288_start + 0x576B3C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_224
	.set gUnk_MapDataResource_224, us_data_0813b288_start + 0x576BDC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_225
	.set gUnk_MapDataResource_225, us_data_0813b288_start + 0x576E50
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_226
	.set gUnk_MapDataResource_226, us_data_0813b288_start + 0x576EE0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_323
	.set gUnk_MapDataResource_323, us_data_0813b288_start + 0x576F74
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_324
	.set gUnk_MapDataResource_324, us_data_0813b288_start + 0x5770F8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_325
	.set gUnk_MapDataResource_325, us_data_0813b288_start + 0x5771E4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_185
	.set gUnk_MapDataResource_185, us_data_0813b288_start + 0x577268
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_186
	.set gUnk_MapDataResource_186, us_data_0813b288_start + 0x5775B8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_187
	.set gUnk_MapDataResource_187, us_data_0813b288_start + 0x57779C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_190
	.set gUnk_MapDataResource_190, us_data_0813b288_start + 0x577914
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_191
	.set gUnk_MapDataResource_191, us_data_0813b288_start + 0x577B60
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_192
	.set gUnk_MapDataResource_192, us_data_0813b288_start + 0x577DAC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_183
	.set gUnk_MapDataResource_183, us_data_0813b288_start + 0x577EF8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_184
	.set gUnk_MapDataResource_184, us_data_0813b288_start + 0x57B6F4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_144
	.set gUnk_MapDataResource_144, us_data_0813b288_start + 0x57B86C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_145
	.set gUnk_MapDataResource_145, us_data_0813b288_start + 0x57BB6C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_146
	.set gUnk_MapDataResource_146, us_data_0813b288_start + 0x57BD6C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_149
	.set gUnk_MapDataResource_149, us_data_0813b288_start + 0x57BE98
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_150
	.set gUnk_MapDataResource_150, us_data_0813b288_start + 0x57C1A0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_151
	.set gUnk_MapDataResource_151, us_data_0813b288_start + 0x57C4A4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_154
	.set gUnk_MapDataResource_154, us_data_0813b288_start + 0x57C5D0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_155
	.set gUnk_MapDataResource_155, us_data_0813b288_start + 0x57C8CC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_156
	.set gUnk_MapDataResource_156, us_data_0813b288_start + 0x57CB00
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_142
	.set gUnk_MapDataResource_142, us_data_0813b288_start + 0x57CBF4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_143
	.set gUnk_MapDataResource_143, us_data_0813b288_start + 0x5801B8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_302
	.set gUnk_MapDataResource_302, us_data_0813b288_start + 0x580314
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_303
	.set gUnk_MapDataResource_303, us_data_0813b288_start + 0x581D74
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_212
	.set gUnk_MapDataResource_212, us_data_0813b288_start + 0x581E88
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_213
	.set gUnk_MapDataResource_213, us_data_0813b288_start + 0x582040
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_214
	.set gUnk_MapDataResource_214, us_data_0813b288_start + 0x582140
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_217
	.set gUnk_MapDataResource_217, us_data_0813b288_start + 0x582260
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_218
	.set gUnk_MapDataResource_218, us_data_0813b288_start + 0x5823F8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_219
	.set gUnk_MapDataResource_219, us_data_0813b288_start + 0x582510
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_202
	.set gUnk_MapDataResource_202, us_data_0813b288_start + 0x5825B8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_203
	.set gUnk_MapDataResource_203, us_data_0813b288_start + 0x582734
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_204
	.set gUnk_MapDataResource_204, us_data_0813b288_start + 0x582824
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_207
	.set gUnk_MapDataResource_207, us_data_0813b288_start + 0x582904
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_208
	.set gUnk_MapDataResource_208, us_data_0813b288_start + 0x5829F8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_209
	.set gUnk_MapDataResource_209, us_data_0813b288_start + 0x582AF8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_200
	.set gUnk_MapDataResource_200, us_data_0813b288_start + 0x582B7C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_201
	.set gUnk_MapDataResource_201, us_data_0813b288_start + 0x585854
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_314
	.set gUnk_MapDataResource_314, us_data_0813b288_start + 0x5859C0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_315
	.set gUnk_MapDataResource_315, us_data_0813b288_start + 0x586ABC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_316
	.set gUnk_MapDataResource_316, us_data_0813b288_start + 0x586BC0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_317
	.set gUnk_MapDataResource_317, us_data_0813b288_start + 0x586D68
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_318
	.set gUnk_MapDataResource_318, us_data_0813b288_start + 0x586ED0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_304
	.set gUnk_MapDataResource_304, us_data_0813b288_start + 0x586FC8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_305
	.set gUnk_MapDataResource_305, us_data_0813b288_start + 0x58718C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_306
	.set gUnk_MapDataResource_306, us_data_0813b288_start + 0x5872F0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_249
	.set gUnk_MapDataResource_249, us_data_0813b288_start + 0x5873A8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_250
	.set gUnk_MapDataResource_250, us_data_0813b288_start + 0x589AE0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_261
	.set gUnk_MapDataResource_261, us_data_0813b288_start + 0x589BE8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_262
	.set gUnk_MapDataResource_262, us_data_0813b288_start + 0x589D6C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_263
	.set gUnk_MapDataResource_263, us_data_0813b288_start + 0x589E70
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_256
	.set gUnk_MapDataResource_256, us_data_0813b288_start + 0x589F3C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_257
	.set gUnk_MapDataResource_257, us_data_0813b288_start + 0x58A09C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_258
	.set gUnk_MapDataResource_258, us_data_0813b288_start + 0x58A19C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_251
	.set gUnk_MapDataResource_251, us_data_0813b288_start + 0x58A25C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_252
	.set gUnk_MapDataResource_252, us_data_0813b288_start + 0x58A3A8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_253
	.set gUnk_MapDataResource_253, us_data_0813b288_start + 0x58A490
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_073
	.set gUnk_MapDataResource_073, us_data_0813b288_start + 0x58A538
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_074
	.set gUnk_MapDataResource_074, us_data_0813b288_start + 0x58A9F8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_075
	.set gUnk_MapDataResource_075, us_data_0813b288_start + 0x58AC2C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_081
	.set gUnk_MapDataResource_081, us_data_0813b288_start + 0x58AE04
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_082
	.set gUnk_MapDataResource_082, us_data_0813b288_start + 0x58B2B8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_083
	.set gUnk_MapDataResource_083, us_data_0813b288_start + 0x58B4D8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_028
	.set gUnk_MapDataResource_028, us_data_0813b288_start + 0x58B698
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_029
	.set gUnk_MapDataResource_029, us_data_0813b288_start + 0x5903A4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_031
	.set gUnk_MapDataResource_031, us_data_0813b288_start + 0x5904D8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_032
	.set gUnk_MapDataResource_032, us_data_0813b288_start + 0x591558
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_033
	.set gUnk_MapDataResource_033, us_data_0813b288_start + 0x5925F0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_030
	.set gUnk_MapDataResource_030, us_data_0813b288_start + 0x592C30
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_036
	.set gUnk_MapDataResource_036, us_data_0813b288_start + 0x592D64
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_037
	.set gUnk_MapDataResource_037, us_data_0813b288_start + 0x597C10
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_039
	.set gUnk_MapDataResource_039, us_data_0813b288_start + 0x597D0C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_040
	.set gUnk_MapDataResource_040, us_data_0813b288_start + 0x598C34
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_041
	.set gUnk_MapDataResource_041, us_data_0813b288_start + 0x599C4C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_038
	.set gUnk_MapDataResource_038, us_data_0813b288_start + 0x59A1A0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_122
	.set gUnk_MapDataResource_122, us_data_0813b288_start + 0x59C2D0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_123
	.set gUnk_MapDataResource_123, us_data_0813b288_start + 0x59C4AC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_124
	.set gUnk_MapDataResource_124, us_data_0813b288_start + 0x59C618
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_127
	.set gUnk_MapDataResource_127, us_data_0813b288_start + 0x59C700
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_128
	.set gUnk_MapDataResource_128, us_data_0813b288_start + 0x59C8D8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_129
	.set gUnk_MapDataResource_129, us_data_0813b288_start + 0x59CA04
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_120
	.set gUnk_MapDataResource_120, us_data_0813b288_start + 0x59CB00
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_121
	.set gUnk_MapDataResource_121, us_data_0813b288_start + 0x59FC20
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_338
	.set gUnk_MapDataResource_338, us_data_0813b288_start + 0x59FD44
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_339
	.set gUnk_MapDataResource_339, us_data_0813b288_start + 0x5A0AFC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_340
	.set gUnk_MapDataResource_340, us_data_0813b288_start + 0x5A0B9C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_341
	.set gUnk_MapDataResource_341, us_data_0813b288_start + 0x5A0C34
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_342
	.set gUnk_MapDataResource_342, us_data_0813b288_start + 0x5A0C40
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_345
	.set gUnk_MapDataResource_345, us_data_0813b288_start + 0x5A0CEC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_346
	.set gUnk_MapDataResource_346, us_data_0813b288_start + 0x5A0D68
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_347
	.set gUnk_MapDataResource_347, us_data_0813b288_start + 0x5A0D74
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_350
	.set gUnk_MapDataResource_350, us_data_0813b288_start + 0x5A0DD0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_351
	.set gUnk_MapDataResource_351, us_data_0813b288_start + 0x5A0E5C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_352
	.set gUnk_MapDataResource_352, us_data_0813b288_start + 0x5A0E68
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_355
	.set gUnk_MapDataResource_355, us_data_0813b288_start + 0x5A0EC8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_356
	.set gUnk_MapDataResource_356, us_data_0813b288_start + 0x5A0F48
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_357
	.set gUnk_MapDataResource_357, us_data_0813b288_start + 0x5A0F54
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_360
	.set gUnk_MapDataResource_360, us_data_0813b288_start + 0x5A0FB0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_361
	.set gUnk_MapDataResource_361, us_data_0813b288_start + 0x5A1064
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_362
	.set gUnk_MapDataResource_362, us_data_0813b288_start + 0x5A1090
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_365
	.set gUnk_MapDataResource_365, us_data_0813b288_start + 0x5A1178
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_366
	.set gUnk_MapDataResource_366, us_data_0813b288_start + 0x5A123C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_367
	.set gUnk_MapDataResource_367, us_data_0813b288_start + 0x5A1248
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_014
	.set gUnk_MapDataResource_014, us_data_0813b288_start + 0x5BFD7C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_015
	.set gUnk_MapDataResource_015, us_data_0813b288_start + 0x5C1F14
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_017
	.set gUnk_MapDataResource_017, us_data_0813b288_start + 0x5C1FB8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_018
	.set gUnk_MapDataResource_018, us_data_0813b288_start + 0x5C2548
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_019
	.set gUnk_MapDataResource_019, us_data_0813b288_start + 0x5C276C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_016
	.set gUnk_MapDataResource_016, us_data_0813b288_start + 0x5C2804
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_022
	.set gUnk_MapDataResource_022, us_data_0813b288_start + 0x5C28A4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_023
	.set gUnk_MapDataResource_023, us_data_0813b288_start + 0x5C47FC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_025
	.set gUnk_MapDataResource_025, us_data_0813b288_start + 0x5C489C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_026
	.set gUnk_MapDataResource_026, us_data_0813b288_start + 0x5C4E28
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_027
	.set gUnk_MapDataResource_027, us_data_0813b288_start + 0x5C5044
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_024
	.set gUnk_MapDataResource_024, us_data_0813b288_start + 0x5C50EC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_132
	.set gUnk_MapDataResource_132, us_data_0813b288_start + 0x5C5180
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_133
	.set gUnk_MapDataResource_133, us_data_0813b288_start + 0x5C5358
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_134
	.set gUnk_MapDataResource_134, us_data_0813b288_start + 0x5C545C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_137
	.set gUnk_MapDataResource_137, us_data_0813b288_start + 0x5C552C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_138
	.set gUnk_MapDataResource_138, us_data_0813b288_start + 0x5C572C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_139
	.set gUnk_MapDataResource_139, us_data_0813b288_start + 0x5C57E4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_328
	.set gUnk_MapDataResource_328, us_data_0813b288_start + 0x5C5858
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_329
	.set gUnk_MapDataResource_329, us_data_0813b288_start + 0x5C59E4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_330
	.set gUnk_MapDataResource_330, us_data_0813b288_start + 0x5C5AFC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_166
	.set gUnk_MapDataResource_166, us_data_0813b288_start + 0x5C5B88
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_167
	.set gUnk_MapDataResource_167, us_data_0813b288_start + 0x5C864C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_173
	.set gUnk_MapDataResource_173, us_data_0813b288_start + 0x5C878C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_174
	.set gUnk_MapDataResource_174, us_data_0813b288_start + 0x5C88D8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_175
	.set gUnk_MapDataResource_175, us_data_0813b288_start + 0x5C89E8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_239
	.set gUnk_MapDataResource_239, us_data_0813b288_start + 0x5C8AC0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_240
	.set gUnk_MapDataResource_240, us_data_0813b288_start + 0x5C8F84
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_241
	.set gUnk_MapDataResource_241, us_data_0813b288_start + 0x5C90A0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_234
	.set gUnk_MapDataResource_234, us_data_0813b288_start + 0x5C919C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_235
	.set gUnk_MapDataResource_235, us_data_0813b288_start + 0x5C9534
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_236
	.set gUnk_MapDataResource_236, us_data_0813b288_start + 0x5C9610
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_292
	.set gUnk_MapDataResource_292, us_data_0813b288_start + 0x5C96F0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_293
	.set gUnk_MapDataResource_293, us_data_0813b288_start + 0x5C98E4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_294
	.set gUnk_MapDataResource_294, us_data_0813b288_start + 0x5C99CC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_042
	.set gUnk_MapDataResource_042, us_data_0813b288_start + 0x5C9AA8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_043
	.set gUnk_MapDataResource_043, us_data_0813b288_start + 0x5CE920
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_045
	.set gUnk_MapDataResource_045, us_data_0813b288_start + 0x5CEAAC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_046
	.set gUnk_MapDataResource_046, us_data_0813b288_start + 0x5CF620
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_047
	.set gUnk_MapDataResource_047, us_data_0813b288_start + 0x5CFF98
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_044
	.set gUnk_MapDataResource_044, us_data_0813b288_start + 0x5D0420
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_050
	.set gUnk_MapDataResource_050, us_data_0813b288_start + 0x5D0594
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_051
	.set gUnk_MapDataResource_051, us_data_0813b288_start + 0x5D522C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_053
	.set gUnk_MapDataResource_053, us_data_0813b288_start + 0x5D5354
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_054
	.set gUnk_MapDataResource_054, us_data_0813b288_start + 0x5D5C28
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_055
	.set gUnk_MapDataResource_055, us_data_0813b288_start + 0x5D6590
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_052
	.set gUnk_MapDataResource_052, us_data_0813b288_start + 0x5D6A08
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_106
	.set gUnk_MapDataResource_106, us_data_0813b288_start + 0x5D6B18
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_107
	.set gUnk_MapDataResource_107, us_data_0813b288_start + 0x5D92F8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_109
	.set gUnk_MapDataResource_109, us_data_0813b288_start + 0x5D9388
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_110
	.set gUnk_MapDataResource_110, us_data_0813b288_start + 0x5D9548
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_111
	.set gUnk_MapDataResource_111, us_data_0813b288_start + 0x5D96F8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_108
	.set gUnk_MapDataResource_108, us_data_0813b288_start + 0x5D9848
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_114
	.set gUnk_MapDataResource_114, us_data_0813b288_start + 0x5D99FC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_115
	.set gUnk_MapDataResource_115, us_data_0813b288_start + 0x5DB8B0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_117
	.set gUnk_MapDataResource_117, us_data_0813b288_start + 0x5DB938
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_118
	.set gUnk_MapDataResource_118, us_data_0813b288_start + 0x5DBA9C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_119
	.set gUnk_MapDataResource_119, us_data_0813b288_start + 0x5DBC44
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_116
	.set gUnk_MapDataResource_116, us_data_0813b288_start + 0x5DBD90
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_333
	.set gUnk_MapDataResource_333, us_data_0813b288_start + 0x5DBEC4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_334
	.set gUnk_MapDataResource_334, us_data_0813b288_start + 0x5DC07C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_335
	.set gUnk_MapDataResource_335, us_data_0813b288_start + 0x5DC1AC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_370
	.set gUnk_MapDataResource_370, us_data_0813b288_start + 0x5DC24C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_371
	.set gUnk_MapDataResource_371, us_data_0813b288_start + 0x5DC2E0
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_374
	.set gUnk_MapDataResource_374, us_data_0813b288_start + 0x5DC328
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_375
	.set gUnk_MapDataResource_375, us_data_0813b288_start + 0x5DC434
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_376
	.set gUnk_MapDataResource_376, us_data_0813b288_start + 0x5DC4A8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_377
	.set gUnk_MapDataResource_377, us_data_0813b288_start + 0x5DC6CC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_378
	.set gUnk_MapDataResource_378, us_data_0813b288_start + 0x5DC7B8
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_379
	.set gUnk_MapDataResource_379, us_data_0813b288_start + 0x5DC99C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_297
	.set gUnk_MapDataResource_297, us_data_0813b288_start + 0x5DCA68
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_298
	.set gUnk_MapDataResource_298, us_data_0813b288_start + 0x5DCBDC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_299
	.set gUnk_MapDataResource_299, us_data_0813b288_start + 0x5DCD80
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_290
	.set gUnk_MapDataResource_290, us_data_0813b288_start + 0x5DCE58
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_291
	.set gUnk_MapDataResource_291, us_data_0813b288_start + 0x5DF850
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_280
	.set gUnk_MapDataResource_280, us_data_0813b288_start + 0x5DF940
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_281
	.set gUnk_MapDataResource_281, us_data_0813b288_start + 0x5DFBA4
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_282
	.set gUnk_MapDataResource_282, us_data_0813b288_start + 0x5DFCFC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_285
	.set gUnk_MapDataResource_285, us_data_0813b288_start + 0x5DFE00
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_286
	.set gUnk_MapDataResource_286, us_data_0813b288_start + 0x5E0024
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_287
	.set gUnk_MapDataResource_287, us_data_0813b288_start + 0x5E014C
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_278
	.set gUnk_MapDataResource_278, us_data_0813b288_start + 0x5E01EC
	.endif
	.ifndef REGION_DE
	.global gUnk_MapDataResource_279
	.set gUnk_MapDataResource_279, us_data_0813b288_start + 0x5E216C
	.endif

	@ Region-neutral labels for FieldRenderRectDescriptor raw resources.
	@ Their payload types are not decoded yet.
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_143
	.set gUnk_FieldRenderResource_143, us_data_0813b288_start + 0x5A12FC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_144
	.set gUnk_FieldRenderResource_144, us_data_0813b288_start + 0x5A14FC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_145
	.set gUnk_FieldRenderResource_145, us_data_0813b288_start + 0x5A16FC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_148
	.set gUnk_FieldRenderResource_148, us_data_0813b288_start + 0x5A2460
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_149
	.set gUnk_FieldRenderResource_149, us_data_0813b288_start + 0x5A2660
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_150
	.set gUnk_FieldRenderResource_150, us_data_0813b288_start + 0x5A2860
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_134
	.set gUnk_FieldRenderResource_134, us_data_0813b288_start + 0x5A358C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_135
	.set gUnk_FieldRenderResource_135, us_data_0813b288_start + 0x5A3BBC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_136
	.set gUnk_FieldRenderResource_136, us_data_0813b288_start + 0x5A41EC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_128
	.set gUnk_FieldRenderResource_128, us_data_0813b288_start + 0x5A481C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_129
	.set gUnk_FieldRenderResource_129, us_data_0813b288_start + 0x5A4AC4
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_139
	.set gUnk_FieldRenderResource_139, us_data_0813b288_start + 0x5A4D6C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_140
	.set gUnk_FieldRenderResource_140, us_data_0813b288_start + 0x5A4D9C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_132
	.set gUnk_FieldRenderResource_132, us_data_0813b288_start + 0x5A6150
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_133
	.set gUnk_FieldRenderResource_133, us_data_0813b288_start + 0x5A63F8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_038
	.set gUnk_FieldRenderResource_038, us_data_0813b288_start + 0x5A8270
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_039
	.set gUnk_FieldRenderResource_039, us_data_0813b288_start + 0x5A844C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_040
	.set gUnk_FieldRenderResource_040, us_data_0813b288_start + 0x5A8628
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_030
	.set gUnk_FieldRenderResource_030, us_data_0813b288_start + 0x5A8804
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_031
	.set gUnk_FieldRenderResource_031, us_data_0813b288_start + 0x5A8900
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_032
	.set gUnk_FieldRenderResource_032, us_data_0813b288_start + 0x5A89FC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_012
	.set gUnk_FieldRenderResource_012, us_data_0813b288_start + 0x5A8AF8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_013
	.set gUnk_FieldRenderResource_013, us_data_0813b288_start + 0x5A8D68
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_006
	.set gUnk_FieldRenderResource_006, us_data_0813b288_start + 0x5A8FD8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_007
	.set gUnk_FieldRenderResource_007, us_data_0813b288_start + 0x5A9178
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_000
	.set gUnk_FieldRenderResource_000, us_data_0813b288_start + 0x5A9318
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_001
	.set gUnk_FieldRenderResource_001, us_data_0813b288_start + 0x5A93E8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_024
	.set gUnk_FieldRenderResource_024, us_data_0813b288_start + 0x5AA500
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_025
	.set gUnk_FieldRenderResource_025, us_data_0813b288_start + 0x5AA768
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_018
	.set gUnk_FieldRenderResource_018, us_data_0813b288_start + 0x5AA9D0
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_019
	.set gUnk_FieldRenderResource_019, us_data_0813b288_start + 0x5AAB20
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_043
	.set gUnk_FieldRenderResource_043, us_data_0813b288_start + 0x5AC160
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_044
	.set gUnk_FieldRenderResource_044, us_data_0813b288_start + 0x5AC31C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_045
	.set gUnk_FieldRenderResource_045, us_data_0813b288_start + 0x5AC4D8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_035
	.set gUnk_FieldRenderResource_035, us_data_0813b288_start + 0x5AC694
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_036
	.set gUnk_FieldRenderResource_036, us_data_0813b288_start + 0x5AC780
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_037
	.set gUnk_FieldRenderResource_037, us_data_0813b288_start + 0x5AC86C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_016
	.set gUnk_FieldRenderResource_016, us_data_0813b288_start + 0x5AC958
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_017
	.set gUnk_FieldRenderResource_017, us_data_0813b288_start + 0x5ACBC8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_010
	.set gUnk_FieldRenderResource_010, us_data_0813b288_start + 0x5ACE38
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_011
	.set gUnk_FieldRenderResource_011, us_data_0813b288_start + 0x5ACFB8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_004
	.set gUnk_FieldRenderResource_004, us_data_0813b288_start + 0x5AD138
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_005
	.set gUnk_FieldRenderResource_005, us_data_0813b288_start + 0x5AD1F8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_028
	.set gUnk_FieldRenderResource_028, us_data_0813b288_start + 0x5AE300
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_029
	.set gUnk_FieldRenderResource_029, us_data_0813b288_start + 0x5AE53C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_022
	.set gUnk_FieldRenderResource_022, us_data_0813b288_start + 0x5AE778
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_023
	.set gUnk_FieldRenderResource_023, us_data_0813b288_start + 0x5AE8B0
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_154
	.set gUnk_FieldRenderResource_154, us_data_0813b288_start + 0x5AFB24
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_157
	.set gUnk_FieldRenderResource_157, us_data_0813b288_start + 0x5AFB70
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_151
	.set gUnk_FieldRenderResource_151, us_data_0813b288_start + 0x5AFB7C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_166
	.set gUnk_FieldRenderResource_166, us_data_0813b288_start + 0x5AFB88
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_160
	.set gUnk_FieldRenderResource_160, us_data_0813b288_start + 0x5AFBE4
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_163
	.set gUnk_FieldRenderResource_163, us_data_0813b288_start + 0x5AFC40
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_119
	.set gUnk_FieldRenderResource_119, us_data_0813b288_start + 0x5AFCA4
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_106
	.set gUnk_FieldRenderResource_106, us_data_0813b288_start + 0x5AFCAC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_107
	.set gUnk_FieldRenderResource_107, us_data_0813b288_start + 0x5AFCCC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_103
	.set gUnk_FieldRenderResource_103, us_data_0813b288_start + 0x5AFEDC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_102
	.set gUnk_FieldRenderResource_102, us_data_0813b288_start + 0x5AFEFC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_089
	.set gUnk_FieldRenderResource_089, us_data_0813b288_start + 0x5AFF1C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_099
	.set gUnk_FieldRenderResource_099, us_data_0813b288_start + 0x5AFF7C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_082
	.set gUnk_FieldRenderResource_082, us_data_0813b288_start + 0x5AFFA0
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_083
	.set gUnk_FieldRenderResource_083, us_data_0813b288_start + 0x5B00CC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_096
	.set gUnk_FieldRenderResource_096, us_data_0813b288_start + 0x5B01F8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_070
	.set gUnk_FieldRenderResource_070, us_data_0813b288_start + 0x5B0210
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_071
	.set gUnk_FieldRenderResource_071, us_data_0813b288_start + 0x5B0228
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_078
	.set gUnk_FieldRenderResource_078, us_data_0813b288_start + 0x5B0240
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_079
	.set gUnk_FieldRenderResource_079, us_data_0813b288_start + 0x5B0258
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_074
	.set gUnk_FieldRenderResource_074, us_data_0813b288_start + 0x5B0270
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_075
	.set gUnk_FieldRenderResource_075, us_data_0813b288_start + 0x5B0288
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_058
	.set gUnk_FieldRenderResource_058, us_data_0813b288_start + 0x5B02A0
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_059
	.set gUnk_FieldRenderResource_059, us_data_0813b288_start + 0x5B02D0
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_054
	.set gUnk_FieldRenderResource_054, us_data_0813b288_start + 0x5B0300
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_055
	.set gUnk_FieldRenderResource_055, us_data_0813b288_start + 0x5B0330
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_092
	.set gUnk_FieldRenderResource_092, us_data_0813b288_start + 0x5B0360
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_066
	.set gUnk_FieldRenderResource_066, us_data_0813b288_start + 0x5B0450
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_067
	.set gUnk_FieldRenderResource_067, us_data_0813b288_start + 0x5B0488
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_062
	.set gUnk_FieldRenderResource_062, us_data_0813b288_start + 0x5B04C0
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_063
	.set gUnk_FieldRenderResource_063, us_data_0813b288_start + 0x5B04F8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_086
	.set gUnk_FieldRenderResource_086, us_data_0813b288_start + 0x5B06B4
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_050
	.set gUnk_FieldRenderResource_050, us_data_0813b288_start + 0x5B0714
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_051
	.set gUnk_FieldRenderResource_051, us_data_0813b288_start + 0x5B0744
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_046
	.set gUnk_FieldRenderResource_046, us_data_0813b288_start + 0x5B0774
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_047
	.set gUnk_FieldRenderResource_047, us_data_0813b288_start + 0x5B07A4
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_093
	.set gUnk_FieldRenderResource_093, us_data_0813b288_start + 0x5B07D4
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_114
	.set gUnk_FieldRenderResource_114, us_data_0813b288_start + 0x5BAF20
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_115
	.set gUnk_FieldRenderResource_115, us_data_0813b288_start + 0x5BAF40
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_118
	.set gUnk_FieldRenderResource_118, us_data_0813b288_start + 0x5BAF60
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_110
	.set gUnk_FieldRenderResource_110, us_data_0813b288_start + 0x5BAF68
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_111
	.set gUnk_FieldRenderResource_111, us_data_0813b288_start + 0x5BAF88
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_122
	.set gUnk_FieldRenderResource_122, us_data_0813b288_start + 0x5BB7EC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_123
	.set gUnk_FieldRenderResource_123, us_data_0813b288_start + 0x5BB9AC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_126
	.set gUnk_FieldRenderResource_126, us_data_0813b288_start + 0x5BDBF4
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_127
	.set gUnk_FieldRenderResource_127, us_data_0813b288_start + 0x5BDDB4
	.endif

	@ Additional region-neutral labels for later gFieldRenderRectDescriptors entries.
	@ Their payload types are not known yet.
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_169
	.set gUnk_FieldRenderResource_169, us_data_0813b288_start + 0x5AFE2C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_170
	.set gUnk_FieldRenderResource_170, us_data_0813b288_start + 0x5AFE44
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_173
	.set gUnk_FieldRenderResource_173, us_data_0813b288_start + 0x5B07E0
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_176
	.set gUnk_FieldRenderResource_176, us_data_0813b288_start + 0x5B0800
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_179
	.set gUnk_FieldRenderResource_179, us_data_0813b288_start + 0x5AFD6C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_182
	.set gUnk_FieldRenderResource_182, us_data_0813b288_start + 0x5AFD8C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_183
	.set gUnk_FieldRenderResource_183, us_data_0813b288_start + 0x5AFDEC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_186
	.set gUnk_FieldRenderResource_186, us_data_0813b288_start + 0x5AFE0C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_187
	.set gUnk_FieldRenderResource_187, us_data_0813b288_start + 0x5AFDAC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_190
	.set gUnk_FieldRenderResource_190, us_data_0813b288_start + 0x5AFDCC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_191
	.set gUnk_FieldRenderResource_191, us_data_0813b288_start + 0x5AFE9C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_194
	.set gUnk_FieldRenderResource_194, us_data_0813b288_start + 0x5AFEBC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_195
	.set gUnk_FieldRenderResource_195, us_data_0813b288_start + 0x5AFE5C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_198
	.set gUnk_FieldRenderResource_198, us_data_0813b288_start + 0x5AFE7C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_199
	.set gUnk_FieldRenderResource_199, us_data_0813b288_start + 0x5AFD2C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_202
	.set gUnk_FieldRenderResource_202, us_data_0813b288_start + 0x5AFD4C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_203
	.set gUnk_FieldRenderResource_203, us_data_0813b288_start + 0x5AFCEC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_206
	.set gUnk_FieldRenderResource_206, us_data_0813b288_start + 0x5AFD0C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_207
	.set gUnk_FieldRenderResource_207, us_data_0813b288_start + 0x5A7DAC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_210
	.set gUnk_FieldRenderResource_210, us_data_0813b288_start + 0x5A7DCC
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_211
	.set gUnk_FieldRenderResource_211, us_data_0813b288_start + 0x5A7D6C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_214
	.set gUnk_FieldRenderResource_214, us_data_0813b288_start + 0x5A7D8C
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_215
	.set gUnk_FieldRenderResource_215, us_data_0813b288_start + 0x5BAFA8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_218
	.set gUnk_FieldRenderResource_218, us_data_0813b288_start + 0x5BAFC8
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_219
	.set gUnk_FieldRenderResource_219, us_data_0813b288_start + 0x5AFB30
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_222
	.set gUnk_FieldRenderResource_222, us_data_0813b288_start + 0x5AFB50
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_223
	.set gUnk_FieldRenderResource_223, us_data_0813b288_start + 0x5A19C0
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_224
	.set gUnk_FieldRenderResource_224, us_data_0813b288_start + 0x5A19E0
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_225
	.set gUnk_FieldRenderResource_225, us_data_0813b288_start + 0x5A2B24
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_226
	.set gUnk_FieldRenderResource_226, us_data_0813b288_start + 0x5A2B44
	.endif
	.ifndef REGION_DE
	.global gUnk_FieldRenderResource_227
	.set gUnk_FieldRenderResource_227, us_data_0813b288_start + 0x5AFC9C
	.endif

	@ The EU stream resumes at US source offsets + 0x64 immediately after
	@ the regional script block.  Their lengths are identical through the
	@ following resource; the next physical boundary is handled explicitly.
	.macro eu_post_script_incbin source_offset, size
	.ifdef REGION_EU
	.incbin "baserom_eu.gba", (\source_offset + 0x64), \size
	.else
	FOMT_REGION_ASSET_INCBIN \source_offset, \size
	.endif
	.endm

	@ FOMT_REGION_ASSET_STREAM_BEGIN
	@ The US and EU streams resume immediately after their packed Mary blocks.
	.section .rodata.mary_scripts_tail
	.macro non_de_asset_label name
	.ifndef REGION_DE
	.global \name
\name:
	.endif
	.endm
	.ifndef REGION_DE
	.ifdef REGION_EU
	.global gFontSingleWidthGlyphData
gFontSingleWidthGlyphData:
	.incbin "build/eu/graphics/font/shared/single_width_font.1bpp", 0, 8
	.endif

	.global gUnk_084F90CC
gUnk_084F90CC:
	.ifdef REGION_EU
	.incbin "build/eu/graphics/font/shared/single_width_font.1bpp", 8, (0x16D4 - 8)
	.global gFontSingleByteGlyphIndices
gFontSingleByteGlyphIndices:
	.incbin "baserom_eu.gba", 0x4FA7FC, (0x4FA804 - 0x4FA7FC)
	.else
	.ifndef REGION_DE
	.global gFontSingleWidthGlyphData
	gFontSingleWidthGlyphData:
	.endif
	.incbin "build/us/graphics/font/shared/single_width_font.1bpp"
	.endif

	.global gUnk_084FA7A0
gUnk_084FA7A0:
	.ifdef REGION_EU
	.incbin "baserom_eu.gba", 0x4FA804, (0x4FA9FC - 0x4FA804)
	.global gFontDoubleWidthGlyphData
gFontDoubleWidthGlyphData:
	.incbin "build/eu/graphics/font/shared/double_width_font.1bpp", 0, 8
	.else
	.ifndef REGION_DE
	.global gFontSingleByteGlyphIndices
	gFontSingleByteGlyphIndices:
	.endif
	eu_post_script_incbin 0x4FA7A0, 0x200
	.endif

	.global gUnk_084FA9A0
gUnk_084FA9A0:
	.ifdef REGION_EU
	.incbin "build/eu/graphics/font/shared/double_width_font.1bpp", 8, (0x288F0 - 8)
	.global gFontShiftJisGlyphIndices
gFontShiftJisGlyphIndices:
	.incbin "baserom_eu.gba", 0x5232EC, (0x5232F4 - 0x5232EC)
	.else
	.ifndef REGION_DE
	.global gFontDoubleWidthGlyphData
	gFontDoubleWidthGlyphData:
	.endif
	.incbin "build/us/graphics/font/shared/double_width_font.1bpp"
	.endif

	.global gUnk_08523290
gUnk_08523290:
	.ifndef REGION_EU
	.ifndef REGION_DE
	.global gFontShiftJisGlyphIndices
gFontShiftJisGlyphIndices:
	.endif
	.endif
	.ifdef REGION_EU
	.incbin "baserom_eu.gba", 0x5232F4, 0x3DFC
	@ The EU archive header directly precedes the payload label used by US.
	.global gUnk_08527094
gUnk_08527094:
	.incbin "baserom_eu.gba", 0x5270F0, 0x8
	.else
	FOMT_REGION_ASSET_INCBIN 0x523290, 0x3E04
	.endif
	.ifndef REGION_DE
	.ifndef REGION_EU
	.global gUnk_08527094
gUnk_08527094:
	.endif
	.endif
	.ifdef REGION_EU
	.incbin "baserom_eu.gba", 0x5270F8, 0x19C
	.global gUnk_08527294
gUnk_08527294:
	.incbin "baserom_eu.gba", 0x527294, 0x8
	.else
	eu_post_script_incbin 0x527094, 0x1A4
	.endif

	non_de_asset_label gUnk_08527238
	.ifdef REGION_EU
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 00, 0x8, 0x108
	.global gUnk_085273A4
gUnk_085273A4:
	.incbin "baserom_eu.gba", 0x5273A4, 0x8
	.else
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 00, 0, 0x110
	.endif

	non_de_asset_label gUnk_08527348
	.ifdef REGION_EU
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 01, 0x8, 0x1D0
	.global gUnk_0852757C
gUnk_0852757C:
	.incbin "baserom_eu.gba", 0x52757C, 0x8
	.else
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 01, 0, 0x1D8
	.endif

	non_de_asset_label gUnk_08527520
	.ifdef REGION_EU
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 02, 0x8, 0xA8
	.global gUnk_0852762C
gUnk_0852762C:
	.incbin "build/eu/graphics/ui/farm_status/base_tiles.0x70", 0, 0x8
	.else
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 02, 0, 0xB0
	.endif

	.ifdef REGION_EU
	.incbin "build/eu/graphics/ui/farm_status/base_tiles.0x70", 0x8, 0x21BC
	.global gUnk_085297F0
gUnk_085297F0:
	.incbin "build/eu/graphics/ui/farm_status/base_tiles.gbapal", 0, 0x8
	.else
	.global gUnk_085275D0
gUnk_085275D0:
	.incbin "build/us/graphics/ui/farm_status/base_tiles.0x70"
	.endif

	.ifdef REGION_EU
	@ EU stores archive headers at the targets used by its regional code.
	@ Bind every resource name directly to those physical bytes.
	.global gUnk_08529794
gUnk_08529794:
	.incbin "build/eu/graphics/ui/farm_status/base_tiles.gbapal", 0x8, 0x1F8
	.global gUnk_08529994
gUnk_08529994:
	FOMT_FARM_STATUS_EXTERIOR_STYLE doghouse
	.global gUnk_08529B18
gUnk_08529B18:
	FOMT_FARM_STATUS_TILEMAP 0x2D0, 0x60
	.global gUnk_08529B78
gUnk_08529B78:
	FOMT_FARM_STATUS_TILEMAP 0x270, 0x30
	.global gUnk_08529BA8
gUnk_08529BA8:
	FOMT_FARM_STATUS_EXTERIOR_STYLE mailbox
	.global gUnk_08529C6C
gUnk_08529C6C:
	FOMT_FARM_STATUS_TILEMAP 0x120, 0xA8
	.global gUnk_08529D14
gUnk_08529D14:
	FOMT_FARM_STATUS_TILEMAP 0x060, 0x60
	.global gUnk_08529D74
gUnk_08529D74:
	FOMT_FARM_STATUS_TILEMAP 0x000, 0x30
	.global gUnk_08529DA4
gUnk_08529DA4:
	FOMT_FARM_STATUS_EXTERIOR_STYLE window
	.global gUnk_0852A5E8
gUnk_0852A5E8:
	FOMT_FARM_STATUS_TILEMAP 0x438, 0x9A
	.incbin "baserom_eu.gba", 0x52A6DE, 0x2
	.global gUnk_0852A684
gUnk_0852A684:
	FOMT_FARM_STATUS_TILEMAP 0x390, 0x54
	.global gUnk_0852A734
gUnk_0852A734:
	.incbin "baserom_eu.gba", 0x52A734, 0x8
	.global gUnk_0852A6D8
	gUnk_0852A6D8:
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 03, 0x8, 0x10C
	.global gUnk_0852A848
gUnk_0852A848:
	.incbin "baserom_eu.gba", 0x52A848, 0x8
	.global gUnk_0852A7EC
	gUnk_0852A7EC:
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 04, 0x8, 0x1C8
	.global gUnk_0852AA18
gUnk_0852AA18:
	.incbin "baserom_eu.gba", 0x52AA18, 0x8
	.global gUnk_0852A9BC
	gUnk_0852A9BC:
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 05, 0x8, 0xA8
	.global gUnk_0852AAC8
gUnk_0852AAC8:
	FOMT_FARM_STATUS_WINTER_TILES 0, 0x8
	.global gUnk_0852AA6C
gUnk_0852AA6C:
	FOMT_FARM_STATUS_WINTER_TILES 0x8, 0x1FCC
	.global gUnk_0852CA9C
gUnk_0852CA9C:
	.incbin "baserom_eu.gba", 0x52CA9C, 0x8
	.global gUnk_0852CA40
gUnk_0852CA40:
	.incbin "baserom_eu.gba", 0x52CAA4, 0x1F8
	.global gUnk_0852CC40
gUnk_0852CC40:
	.incbin "baserom_eu.gba", 0x52CC9C, 0x8
	.incbin "baserom_eu.gba", 0x52CCA4, 0x17C
	.global gUnk_0852CDC4
gUnk_0852CDC4:
	FOMT_FARM_STATUS_TILEMAP 0x330, 0x60
	.global gUnk_0852CE24
gUnk_0852CE24:
	FOMT_FARM_STATUS_TILEMAP 0x2A0, 0x30
	.global gUnk_0852CE54
gUnk_0852CE54:
	.incbin "baserom_eu.gba", 0x52CEB0, 0x8
	.incbin "baserom_eu.gba", 0x52CEB8, 0xBC
	.global gUnk_0852CF18
gUnk_0852CF18:
	FOMT_FARM_STATUS_TILEMAP 0x1C8, 0xA8
	.global gUnk_0852CFC0
gUnk_0852CFC0:
	FOMT_FARM_STATUS_TILEMAP 0x0C0, 0x60
	.global gUnk_0852D020
gUnk_0852D020:
	FOMT_FARM_STATUS_TILEMAP 0x030, 0x30
	.global gUnk_0852D050
gUnk_0852D050:
	.incbin "baserom_eu.gba", 0x52D0AC, 0x8
	.incbin "baserom_eu.gba", 0x52D0B4, 0x83C
	.global gUnk_0852D894
gUnk_0852D894:
	FOMT_FARM_STATUS_TILEMAP 0x4D2, 0x9A
	.incbin "baserom_eu.gba", 0x52D98A, 0x2
	.global gUnk_0852D930
gUnk_0852D930:
	FOMT_FARM_STATUS_TILEMAP 0x3E4, 0x54
	.global gUnk_0852D984
gUnk_0852D984:
	.incbin "baserom_eu.gba", 0x52D9E0, 0x8
	.incbin "baserom_eu.gba", 0x52D9E8, (0x5308B8 - 0x52D9E8)
	.incbin "build/eu/graphics/portraits/shared/portrait_tiles.4bpp"
	.incbin "baserom_eu.gba", 0x58B0F8, (0x58BA84 - 0x58B0F8)
	.else
	.global gUnk_08529794
gUnk_08529794:
	.incbin "build/us/graphics/ui/farm_status/base_tiles.gbapal"

	non_de_asset_label gUnk_08529994
	FOMT_FARM_STATUS_EXTERIOR_STYLE doghouse
	.global gUnk_08529B18
gUnk_08529B18:
	FOMT_FARM_STATUS_TILEMAP 0x2D0, 0x60
	.global gUnk_08529B78
gUnk_08529B78:
	FOMT_FARM_STATUS_TILEMAP 0x270, 0x30

	non_de_asset_label gUnk_08529BA8
	FOMT_FARM_STATUS_EXTERIOR_STYLE mailbox
	.global gUnk_08529C6C
gUnk_08529C6C:
	FOMT_FARM_STATUS_TILEMAP 0x120, 0xA8
	.global gUnk_08529D14
gUnk_08529D14:
	FOMT_FARM_STATUS_TILEMAP 0x060, 0x60
	.global gUnk_08529D74
gUnk_08529D74:
	FOMT_FARM_STATUS_TILEMAP 0x000, 0x30

	non_de_asset_label gUnk_08529DA4
	FOMT_FARM_STATUS_EXTERIOR_STYLE window
	.global gUnk_0852A5E8
gUnk_0852A5E8:
	FOMT_FARM_STATUS_TILEMAP 0x438, 0x9A
	eu_post_script_incbin 0x52A682, 0x2
	.global gUnk_0852A684
gUnk_0852A684:
	FOMT_FARM_STATUS_TILEMAP 0x390, 0x54

	non_de_asset_label gUnk_0852A6D8
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 03, 0, 0x114

	non_de_asset_label gUnk_0852A7EC
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 04, 0, 0x1D0

	non_de_asset_label gUnk_0852A9BC
	FOMT_FARM_STATUS_SECONDARY_TILEMAP 05, 0, 0xB0

	non_de_asset_label gUnk_0852AA6C
	FOMT_FARM_STATUS_WINTER_TILES 0, 0x1FD4

	non_de_asset_label gUnk_0852CA40
	eu_post_script_incbin 0x52CA40, 0x200

	non_de_asset_label gUnk_0852CC40
	eu_post_script_incbin 0x52CC40, (0x52CDC4 - 0x52CC40)
	.global gUnk_0852CDC4
gUnk_0852CDC4:
	FOMT_FARM_STATUS_TILEMAP 0x330, 0x60
	.global gUnk_0852CE24
gUnk_0852CE24:
	FOMT_FARM_STATUS_TILEMAP 0x2A0, 0x30

	non_de_asset_label gUnk_0852CE54
	eu_post_script_incbin 0x52CE54, (0x52CF18 - 0x52CE54)
	.global gUnk_0852CF18
gUnk_0852CF18:
	FOMT_FARM_STATUS_TILEMAP 0x1C8, 0xA8
	.global gUnk_0852CFC0
gUnk_0852CFC0:
	FOMT_FARM_STATUS_TILEMAP 0x0C0, 0x60
	.global gUnk_0852D020
gUnk_0852D020:
	FOMT_FARM_STATUS_TILEMAP 0x030, 0x30

	non_de_asset_label gUnk_0852D050
	eu_post_script_incbin 0x52D050, (0x52D894 - 0x52D050)
	.global gUnk_0852D894
gUnk_0852D894:
	FOMT_FARM_STATUS_TILEMAP 0x4D2, 0x9A
	eu_post_script_incbin 0x52D92E, 0x2
	.global gUnk_0852D930
gUnk_0852D930:
	FOMT_FARM_STATUS_TILEMAP 0x3E4, 0x54

	.ifndef REGION_DE
	.global gUnk_0852D984
gUnk_0852D984:
	.endif
	.ifdef REGION_DE
	FOMT_REGION_ASSET_INCBIN 0x52D984, 0x5E0A4
	.else
	.incbin "baserom_us.gba", 0x52D984, (0x53085C - 0x52D984)
	.incbin "build/us/graphics/portraits/shared/portrait_tiles.4bpp"
	.incbin "baserom_us.gba", 0x58B09C, (0x58BA28 - 0x58B09C)
	.endif
	.endif

	.ifndef REGION_DE
	.global gUnk_0858BA28
gUnk_0858BA28:
	.endif
	.ifdef REGION_EU
	.incbin "baserom_eu.gba", 0x58BA84, (0x5A3458 - 0x58BA84)
	.incbin "build/eu/graphics/sprites/shared/actor_tiles.4bpp"
	.incbin "baserom_eu.gba", 0x661E18, (0x6670BC - 0x661E18)
	.else
	.ifdef REGION_DE
	FOMT_REGION_ASSET_INCBIN 0x58BA28, 0xDB638
	.else
	.incbin "baserom_us.gba", 0x58BA28, (0x5A33FC - 0x58BA28)
	.incbin "build/us/graphics/sprites/shared/actor_tiles.4bpp"
	.incbin "baserom_us.gba", 0x661DBC, (0x667060 - 0x661DBC)
	.endif
	.endif

	non_de_asset_label gUnk_08667060
	FOMT_REGION_ASSET_INCBIN 0x667060, 0x840

	.ifndef REGION_DE
	.global gUnk_086678A0
gUnk_086678A0:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x6678A0, 0x30080

	non_de_asset_label gUnk_08697920
	FOMT_REGION_ASSET_INCBIN 0x697920, 0x11E0

	non_de_asset_label gUnk_08698B00
    .ifdef REGION_DE
    FOMT_REGION_ASSET_INCBIN 0x698B00, 0x314
    .else
    FOMT_REGION_ASSET_INCBIN 0x698B00, 0x80
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_004, 0x698B80, 0x30
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_011, 0x698BB0, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_006, 0x698BC8, 0x3C
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_002, 0x698C04, 0x30
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_010, 0x698C34, 0x24
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_014, 0x698C58, 0x30
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_017, 0x698C88, 0x30
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_018, 0x698CB8, 0x30
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_015, 0x698CE8, 0x30
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_007, 0x698D18, 0x24
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_009, 0x698D3C, 0x3C
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_016, 0x698D78, 0x30
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_001, 0x698DA8, 0x24
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_008, 0x698DCC, 0x30
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_013, 0x698DFC, 0x18
    .endif

	.ifndef REGION_DE
	.global gUnk_08698E14
gUnk_08698E14:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x698E14, 0x11E0

	.ifndef REGION_DE
	.global gUnk_08699FF4
gUnk_08699FF4:
	.endif
    .ifdef REGION_DE
    FOMT_REGION_ASSET_INCBIN 0x699FF4, 0xB0
    .else
    FOMT_REGION_ASSET_INCBIN 0x699FF4, 0x80
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_003, 0x69A074, 0x30
    .endif

	non_de_asset_label gUnk_0869A0A4
	FOMT_REGION_ASSET_INCBIN 0x69A0A4, 0x11E0

	non_de_asset_label gUnk_0869B284
    .ifdef REGION_DE
    FOMT_REGION_ASSET_INCBIN 0x69B284, 0x3A284
    .else
    FOMT_REGION_ASSET_INCBIN 0x69B284, 0x80
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_012, 0x69B304, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_005, 0x69B31C, 0x3C
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_019, 0x69B358, 0x3C
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_000, 0x69B394, 0x3A174
    .endif

	.ifndef REGION_DE
	.global gUnk_086D5508
gUnk_086D5508:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x6D5508, 0xE60

	.ifndef REGION_DE
	.global gUnk_086D6368
gUnk_086D6368:
	.endif
    .ifdef REGION_DE
    FOMT_REGION_ASSET_INCBIN 0x6D6368, 0xF0
    .else
    FOMT_REGION_ASSET_INCBIN 0x6D6368, 0x60
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_033, 0x6D63C8, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_031, 0x6D63E0, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_034, 0x6D63F8, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_032, 0x6D6410, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_023, 0x6D6428, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_025, 0x6D6440, 0x18
    .endif

	non_de_asset_label gUnk_086D6458
    .ifdef REGION_DE
    FOMT_REGION_ASSET_INCBIN 0x6D6458, 0xC0
    .else
    FOMT_REGION_ASSET_INCBIN 0x6D6458, 0xC
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_026, 0x6D6464, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_020, 0x6D647C, 0x9C
    .endif

	non_de_asset_label gUnk_086D6518
	FOMT_REGION_ASSET_INCBIN 0x6D6518, 0x8

	non_de_asset_label gUnk_086D6520
	FOMT_REGION_ASSET_INCBIN 0x6D6520, 0x8

	non_de_asset_label gUnk_086D6528
    .ifdef REGION_DE
    FOMT_REGION_ASSET_INCBIN 0x6D6528, 0x20
    .else
    FOMT_REGION_ASSET_INCBIN 0x6D6528, 0x8
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_024, 0x6D6530, 0x18
    .endif

	non_de_asset_label gUnk_086D6548
    .ifdef REGION_DE
    FOMT_REGION_ASSET_INCBIN 0x6D6548, 0xC0
    .else
    FOMT_REGION_ASSET_INCBIN 0x6D6548, 0x60
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_037, 0x6D65A8, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_035, 0x6D65C0, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_038, 0x6D65D8, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_036, 0x6D65F0, 0x18
    .endif

	non_de_asset_label gUnk_086D6608
    .ifdef REGION_DE
    FOMT_REGION_ASSET_INCBIN 0x6D6608, 0x90
    .else
    FOMT_REGION_ASSET_INCBIN 0x6D6608, 0xC
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_022, 0x6D6614, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_029, 0x6D662C, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_027, 0x6D6644, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_030, 0x6D665C, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_028, 0x6D6674, 0x18
    FOMT_FIELD_PLOT_RENDER_RECORD gUnk_FieldPlotRenderRecord_021, 0x6D668C, 0xC
    .endif

	non_de_asset_label gUnk_086D6698
	FOMT_REGION_ASSET_INCBIN 0x6D6698, 0xE60

	non_de_asset_label gUnk_086D74F8
	FOMT_REGION_ASSET_INCBIN 0x6D74F8, 0x4ECC

	non_de_asset_label gActorStateGridCellType0Data
	FOMT_REGION_ASSET_INCBIN 0x6DC3C4, 0xC

	non_de_asset_label gActorStateGridCellType1Data
	FOMT_REGION_ASSET_INCBIN 0x6DC3D0, 0xC

	non_de_asset_label gActorStateGridCellType2Data
	FOMT_REGION_ASSET_INCBIN 0x6DC3DC, 0xC

	non_de_asset_label gActorStateGridCellType3Data
	FOMT_REGION_ASSET_INCBIN 0x6DC3E8, 0xC

	non_de_asset_label gActorStateGridCellType4Data
	FOMT_REGION_ASSET_INCBIN 0x6DC3F4, 0x158

	non_de_asset_label gUnk_086DC54C
	FOMT_REGION_ASSET_INCBIN 0x6DC54C, 0x30

	non_de_asset_label gUnk_086DC57C
	FOMT_REGION_ASSET_INCBIN 0x6DC57C, 0x70C

	non_de_asset_label gUnk_086DCC88
	FOMT_REGION_ASSET_INCBIN 0x6DCC88, 0xA08

	non_de_asset_label gUnk_086DD690
	FOMT_REGION_ASSET_INCBIN 0x6DD690, 0x20

	non_de_asset_label gUnk_086DD6B0
	FOMT_REGION_ASSET_INCBIN 0x6DD6B0, 0x30

	non_de_asset_label gUnk_086DD6E0
	FOMT_REGION_ASSET_INCBIN 0x6DD6E0, 0x70C

	non_de_asset_label gUnk_086DDDEC
	FOMT_REGION_ASSET_INCBIN 0x6DDDEC, 0xA08

	non_de_asset_label gUnk_086DE7F4
	FOMT_REGION_ASSET_INCBIN 0x6DE7F4, 0xC4E8

	non_de_asset_label gUnk_086EACDC
	FOMT_REGION_ASSET_INCBIN 0x6EACDC, 0x8

	non_de_asset_label gUnk_086EACE4
	FOMT_REGION_ASSET_INCBIN 0x6EACE4, 0x20

	non_de_asset_label gUnk_086EAD04
	FOMT_REGION_ASSET_INCBIN 0x6EAD04, 0x20

	non_de_asset_label gUnk_086EAD24
	FOMT_REGION_ASSET_INCBIN 0x6EAD24, 0x20

	non_de_asset_label gUnk_086EAD44
	FOMT_REGION_ASSET_INCBIN 0x6EAD44, 0x20

	non_de_asset_label gUnk_086EAD64
	FOMT_REGION_ASSET_INCBIN 0x6EAD64, 0x20

	non_de_asset_label gUnk_086EAD84
	FOMT_REGION_ASSET_INCBIN 0x6EAD84, 0x8

	non_de_asset_label gUnk_086EAD8C
	FOMT_REGION_ASSET_INCBIN 0x6EAD8C, 0x8220

	non_de_asset_label gUnk_086F2FAC
	FOMT_REGION_ASSET_INCBIN 0x6F2FAC, 0x7AD4

	non_de_asset_label gUnk_086FAA80
	FOMT_REGION_ASSET_INCBIN 0x6FAA80, 0x584

	non_de_asset_label gUnk_086FB004
	FOMT_REGION_ASSET_INCBIN 0x6FB004, 0x2198

	non_de_asset_label gUnk_086FD19C
	FOMT_REGION_ASSET_INCBIN 0x6FD19C, 0xA4

	non_de_asset_label gUnk_086FD240
	FOMT_REGION_ASSET_INCBIN 0x6FD240, 0x177F0

	non_de_asset_label gUnk_08714A30
	FOMT_REGION_ASSET_INCBIN 0x714A30, 0x130

	non_de_asset_label gUnk_08714B60
	FOMT_REGION_ASSET_INCBIN 0x714B60, 0x8C

	non_de_asset_label gUnk_08714BEC
	FOMT_REGION_ASSET_INCBIN 0x714BEC, 0x2398

	non_de_asset_label gUnk_08716F84
	FOMT_REGION_ASSET_INCBIN 0x716F84, 0x134

	non_de_asset_label gUnk_087170B8
	.endif
	.ifdef REGION_DE
	.global gFontSingleWidthGlyphData
gFontSingleWidthGlyphData:
	.incbin "build/de/graphics/font/shared/single_width_font.1bpp"
	.global gFontSingleByteGlyphIndices
gFontSingleByteGlyphIndices:
	.incbin "baserom_de.gba", 0x71F4A8, 0xF4
	.else
	FOMT_REGION_ASSET_INCBIN 0x7170B8, 0x6464
	.endif

	.ifndef REGION_DE
	.global gUnk_0871D51C
gUnk_0871D51C:
	.endif
	.ifdef REGION_DE
	.incbin "baserom_de.gba", 0x71F59C, 0x10C
	.global gFontDoubleWidthGlyphData
gFontDoubleWidthGlyphData:
	.incbin "build/de/graphics/font/shared/double_width_font.1bpp"
	.global gFontShiftJisGlyphIndices
gFontShiftJisGlyphIndices:
	.incbin "baserom_de.gba", 0x747F98, 0x1AFC
	.else
	FOMT_REGION_ASSET_INCBIN 0x71D51C, 0x128C
	.endif

	.ifndef REGION_DE
	non_de_asset_label gUnk_0871E7A8
	FOMT_REGION_ASSET_INCBIN 0x71E7A8, 0x504

	non_de_asset_label gUnk_0871ECAC
	FOMT_REGION_ASSET_INCBIN 0x71ECAC, 0x128

	non_de_asset_label gUnk_0871EDD4
	FOMT_REGION_ASSET_INCBIN 0x71EDD4, 0x12C

	non_de_asset_label gUnk_0871EF00
	FOMT_REGION_ASSET_INCBIN 0x71EF00, 0x6EA0

	non_de_asset_label gUnk_08725DA0
	FOMT_REGION_ASSET_INCBIN 0x725DA0, 0xF2C

	non_de_asset_label gUnk_08726CCC
	FOMT_REGION_ASSET_INCBIN 0x726CCC, 0x69C

	non_de_asset_label gUnk_08727368
	FOMT_REGION_ASSET_INCBIN 0x727368, 0x70C

	non_de_asset_label gUnk_08727A74
	FOMT_REGION_ASSET_INCBIN 0x727A74, 0x794

	.ifndef REGION_DE
	.global gUnk_08728208
gUnk_08728208:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x728208, 0x118

	non_de_asset_label gUnk_08728320
	FOMT_REGION_ASSET_INCBIN 0x728320, 0x105C

	non_de_asset_label gUnk_0872937C
	FOMT_REGION_ASSET_INCBIN 0x72937C, 0xE4

	non_de_asset_label gUnk_08729460
	FOMT_REGION_ASSET_INCBIN 0x729460, 0x2A04

	.ifndef REGION_DE
	.global gUnk_0872BE64
gUnk_0872BE64:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x72BE64, 0x76C

	non_de_asset_label gUnk_0872C5D0
	FOMT_UI_SCENE_080B55D0_AUX_ASSET "layer_0.tilemap.0x70"

	non_de_asset_label gUnk_0872C73C
	FOMT_UI_SCENE_080B55D0_AUX_ASSET "layer_1.tilemap.0x70"

	non_de_asset_label gUnk_0872C84C
	FOMT_UI_SCENE_080B55D0_AUX_ASSET "tiles.4bpp.0x70"

	non_de_asset_label gUnk_0872D5AC
	FOMT_REGION_ASSET_INCBIN 0x72D5AC, 0x20

	non_de_asset_label gUnk_0872D5CC
	FOMT_UI_SCENE_080B7164_ASSET "layer_0.tilemap.0x70"

	non_de_asset_label gUnk_0872D630
	FOMT_UI_SCENE_080B7164_ASSET "layer_1.tilemap.0x70"

	non_de_asset_label gUnk_0872D6D8
	FOMT_UI_SCENE_080B7164_ASSET "tiles.4bpp.0x70"

	non_de_asset_label gUnk_0872DDE4
	FOMT_REGION_ASSET_INCBIN 0x72DDE4, 0x60

	.ifndef REGION_DE
	.global gUnk_0872DE44
gUnk_0872DE44:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x72DE44, 0x1034

	.ifndef REGION_DE
	.global gUnk_0872EE78
gUnk_0872EE78:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x72EE78, 0x2A4

	non_de_asset_label gUnk_0872F11C
	FOMT_REGION_ASSET_INCBIN 0x72F11C, 0xA0

	non_de_asset_label gUnk_0872F1BC
	FOMT_REGION_ASSET_INCBIN 0x72F1BC, 0x30

	non_de_asset_label gUnk_0872F1EC
	FOMT_REGION_ASSET_INCBIN 0x72F1EC, 0x30

	non_de_asset_label gUnk_0872F21C
	FOMT_UI_SCENE_0805AB08_TILES

	non_de_asset_label gUnk_0872FA9C
	FOMT_REGION_ASSET_INCBIN 0x72FA9C, 0x160

	non_de_asset_label gUnk_0872FBFC
	FOMT_REGION_ASSET_INCBIN 0x72FBFC, 0x38

	non_de_asset_label gUnk_0872FC34
	FOMT_UI_SCENE_080AE7D0_ASSET "layer_0.tilemap.0x70"

	non_de_asset_label gUnk_0872FE6C
	FOMT_UI_SCENE_080AE7D0_ASSET "layer_1.tilemap.0x70"

	non_de_asset_label gUnk_0872FEF8
	FOMT_UI_SCENE_080AE7D0_ASSET "tiles.4bpp.0x70"

	non_de_asset_label gUnk_08731940
	FOMT_UI_SCENE_080AE7D0_ASSET "palette_banks.gbapal"

	non_de_asset_label gUnk_08731B40 @ChickenPortraits
	FOMT_REGION_ASSET_INCBIN 0x731B40, 0x6604

	non_de_asset_label gUnk_08738144 @gCalendarFont?
	FOMT_REGION_ASSET_INCBIN 0x738144, 0x994

	non_de_asset_label gUnk_08738AD8
	FOMT_REGION_ASSET_INCBIN 0x738AD8, 0x1F0

	non_de_asset_label gUnk_08738CC8
	FOMT_REGION_ASSET_INCBIN 0x738CC8, 0x28

	non_de_asset_label gUnk_08738CF0
	FOMT_REGION_ASSET_INCBIN 0x738CF0, 0x2C

	non_de_asset_label gUnk_08738D1C
	FOMT_UI_SCENE_08054F40_TILES

	non_de_asset_label gUnk_087399C4
	FOMT_REGION_ASSET_INCBIN 0x7399C4, 0xA0

	non_de_asset_label gUnk_08739A64
	FOMT_REGION_ASSET_INCBIN 0x739A64, 0xC84

	.ifndef REGION_DE
	.global gUnk_0873A6E8
gUnk_0873A6E8:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x73A6E8, 0x76C

	non_de_asset_label gUnk_0873AE54
	FOMT_REGION_ASSET_INCBIN 0x73AE54, 0x174

	non_de_asset_label gUnk_0873AFC8
	FOMT_REGION_ASSET_INCBIN 0x73AFC8, 0xE5C

	non_de_asset_label gUnk_0873BE24
	FOMT_UI_SCENE_080BCFAC_ASSET "layer_0.tilemap.0x70"

	non_de_asset_label gUnk_0873BF48
	FOMT_UI_SCENE_080BCFAC_ASSET "layer_1.tilemap.0x70"

	non_de_asset_label gUnk_0873BFF0
	FOMT_UI_SCENE_080BCFAC_ASSET "tiles.4bpp.0x70"

	non_de_asset_label gUnk_0873CBF4
	FOMT_REGION_ASSET_INCBIN 0x73CBF4, 0xC0

	.ifndef REGION_DE
	.global gUnk_0873CCB4
gUnk_0873CCB4:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x73CCB4, 0x1F8

	non_de_asset_label gUnk_0873CEAC
	FOMT_REGION_ASSET_INCBIN 0x73CEAC, 0xE4

	.ifndef REGION_DE
	.global gUnk_0873CF90
gUnk_0873CF90:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x73CF90, 0x2A4

	.ifndef REGION_DE
	.global gUnk_0873D234
gUnk_0873D234:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x73D234, 0x3C8

	non_de_asset_label gUnk_0873D5FC
	FOMT_REGION_ASSET_INCBIN 0x73D5FC, 0xDC

	.ifndef REGION_DE
	.global gUnk_0873D6D8
gUnk_0873D6D8:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x73D6D8, 0x76C

	.ifndef REGION_DE
	.global gUnk_0873DE44
gUnk_0873DE44:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x73DE44, 0x76C

	.ifndef REGION_DE
	.global gUnk_0873E5B0
gUnk_0873E5B0:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x73E5B0, 0x76C

	.ifndef REGION_DE
	.global gUnk_0873ED1C
gUnk_0873ED1C:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x73ED1C, 0x6AC

	non_de_asset_label gUnk_0873F3C8
	FOMT_UI_SCENE_080C160C_ASSET "layer_0.tilemap.0x70"

	non_de_asset_label gUnk_0873F5D4
	FOMT_UI_SCENE_080C160C_ASSET "layer_1.tilemap.0x70"

	non_de_asset_label gUnk_0873F6AC
	FOMT_UI_SCENE_080C160C_ASSET "tiles.4bpp.0x70"

	non_de_asset_label gUnk_087400E4
	FOMT_REGION_ASSET_INCBIN 0x7400E4, 0xC0

	.ifndef REGION_DE
	.global gUnk_087401A4
gUnk_087401A4:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x7401A4, 0x2B0

	.ifndef REGION_DE
	.global gUnk_08740454
gUnk_08740454:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x740454, 0x14C

	.ifndef REGION_DE
	.global gUnk_087405A0
gUnk_087405A0:
	.endif
	FOMT_REGION_ASSET_INCBIN 0x7405A0, 0x368

	non_de_asset_label gUnk_08740908
	FOMT_REGION_ASSET_INCBIN 0x740908, 0xDC

	.ifdef REGION_DE
	FOMT_REGION_ASSET_INCBIN 0x7409E4, 0x2674
	.else
	@ Twenty 0x500-byte Raw-LZ object-tile payloads, unpacked in order by
	@ func_0805FBB8.  Their OAM composition remains runtime data.
	.macro FOMT_INTRO_SCENE_OBJECT source
	.ifdef REGION_EU
	.incbin "build/eu/graphics/intro_scene/objects/object_\source\().0x70"
	.else
	.incbin "build/us/graphics/intro_scene/objects/object_\source\().0x70"
	.endif
	.endm
	non_de_asset_label gUnk_087409E4
	FOMT_REGION_ASSET_INCBIN 0x7409E4, (0x7419F4 - 0x7409E4)
	.global gUnk_IntroSceneUnpackSource_000
gUnk_IntroSceneUnpackSource_000:
	FOMT_INTRO_SCENE_OBJECT 00
	.global gUnk_IntroSceneUnpackSource_001
gUnk_IntroSceneUnpackSource_001:
	FOMT_INTRO_SCENE_OBJECT 01
	.global gUnk_IntroSceneUnpackSource_002
gUnk_IntroSceneUnpackSource_002:
	FOMT_INTRO_SCENE_OBJECT 02
	.global gUnk_IntroSceneUnpackSource_003
gUnk_IntroSceneUnpackSource_003:
	FOMT_INTRO_SCENE_OBJECT 03
	.global gUnk_IntroSceneUnpackSource_004
gUnk_IntroSceneUnpackSource_004:
	FOMT_INTRO_SCENE_OBJECT 04
	.global gUnk_IntroSceneUnpackSource_005
gUnk_IntroSceneUnpackSource_005:
	FOMT_INTRO_SCENE_OBJECT 05
	.global gUnk_IntroSceneUnpackSource_006
gUnk_IntroSceneUnpackSource_006:
	FOMT_INTRO_SCENE_OBJECT 06
	.global gUnk_IntroSceneUnpackSource_007
gUnk_IntroSceneUnpackSource_007:
	FOMT_INTRO_SCENE_OBJECT 07
	.global gUnk_IntroSceneUnpackSource_008
gUnk_IntroSceneUnpackSource_008:
	FOMT_INTRO_SCENE_OBJECT 08
	.global gUnk_IntroSceneUnpackSource_009
gUnk_IntroSceneUnpackSource_009:
	FOMT_INTRO_SCENE_OBJECT 09
	.global gUnk_IntroSceneUnpackSource_010
gUnk_IntroSceneUnpackSource_010:
	FOMT_INTRO_SCENE_OBJECT 10
	.global gUnk_IntroSceneUnpackSource_011
gUnk_IntroSceneUnpackSource_011:
	FOMT_INTRO_SCENE_OBJECT 11
	.global gUnk_IntroSceneUnpackSource_012
gUnk_IntroSceneUnpackSource_012:
	FOMT_INTRO_SCENE_OBJECT 12
	.global gUnk_IntroSceneUnpackSource_013
gUnk_IntroSceneUnpackSource_013:
	FOMT_INTRO_SCENE_OBJECT 13
	.global gUnk_IntroSceneUnpackSource_014
gUnk_IntroSceneUnpackSource_014:
	FOMT_INTRO_SCENE_OBJECT 14
	.global gUnk_IntroSceneUnpackSource_015
gUnk_IntroSceneUnpackSource_015:
	FOMT_INTRO_SCENE_OBJECT 15
	.global gUnk_IntroSceneUnpackSource_016
gUnk_IntroSceneUnpackSource_016:
	FOMT_INTRO_SCENE_OBJECT 16
	.global gUnk_IntroSceneUnpackSource_017
gUnk_IntroSceneUnpackSource_017:
	FOMT_INTRO_SCENE_OBJECT 17
	.global gUnk_IntroSceneUnpackSource_018
gUnk_IntroSceneUnpackSource_018:
	FOMT_INTRO_SCENE_OBJECT 18
	.global gUnk_IntroSceneUnpackSource_019
gUnk_IntroSceneUnpackSource_019:
	FOMT_INTRO_SCENE_OBJECT 19
	.endif

	non_de_asset_label gUnk_08743058
	.ifdef REGION_DE
	.incbin "baserom_de.gba", 0x7450D8, 0x2EC0
	.global gFontShiftJisGlyphIndices
gFontShiftJisGlyphIndices:
	.incbin "baserom_de.gba", 0x747F98, 0x1AFC
	.else
	.ifdef REGION_EU
	.incbin "build/eu/graphics/intro_scene/background_tiles.0x70"
	.else
	.incbin "build/us/graphics/intro_scene/background_tiles.0x70"
	.endif
	.endif
	.endif

	non_de_asset_label gUnk_08747A14
	.ifdef REGION_DE
	FOMT_REGION_ASSET_INCBIN 0x747A14, 0x60
	.else
	.ifdef REGION_EU
	.incbin "build/eu/graphics/intro_scene/background_palettes.gbapal"
	.else
	.incbin "build/us/graphics/intro_scene/background_palettes.gbapal"
	.endif
	.endif

	.ifdef REGION_DE
	@ Preserve the verified final DE bytes immediately before the IWRAM LMA.
	@ The corresponding US tail resources are physically relocated into the
	@ earlier DE stream, where they have direct labels.
	FOMT_REGION_ASSET_INCBIN 0x747A74, 0x2348
	.else
	.global gUnk_08747A74
gUnk_08747A74:
	.ifdef REGION_EU
	.incbin "build/eu/graphics/intro_scene/indexed_archive/archive.0x70"
	.else
	.incbin "build/us/graphics/intro_scene/indexed_archive/archive.0x70"
	.endif

	@ Four Huffman-4/LZ3 streams unpacked by the earlier Intro Scene startup
	@ path. Each source is an interleaved pair of 32-by-32 BG tilemaps.
	.macro FOMT_INTRO_SCENE_STARTUP_TILEMAP source
	.ifdef REGION_EU
	.incbin "build/eu/graphics/intro_scene/startup_tilemaps/startup_\source\().0x70"
	.else
	.incbin "build/us/graphics/intro_scene/startup_tilemaps/startup_\source\().0x70"
	.endif
	.endm
	.macro FOMT_INTRO_SCENE_STARTUP_VISUAL_TILES
	.ifdef REGION_EU
	.incbin "build/eu/graphics/intro_scene/startup_visual/startup_tiles.0x70"
	.else
	.incbin "build/us/graphics/intro_scene/startup_visual/startup_tiles.0x70"
	.endif
	.endm
	.macro FOMT_INTRO_SCENE_STARTUP_VISUAL_PALETTE
	.ifdef REGION_EU
	.incbin "build/eu/graphics/intro_scene/startup_visual/startup_palette_banks.gbapal"
	.else
	.incbin "build/us/graphics/intro_scene/startup_visual/startup_palette_banks.gbapal"
	.endif
	.endm
	.global gUnk_IntroSceneStartupUnpackSource_000
gUnk_IntroSceneStartupUnpackSource_000:
	FOMT_INTRO_SCENE_STARTUP_TILEMAP 00
	.global gUnk_IntroSceneStartupUnpackSource_001
gUnk_IntroSceneStartupUnpackSource_001:
	FOMT_INTRO_SCENE_STARTUP_TILEMAP 01
	.global gUnk_IntroSceneStartupUnpackSource_002
gUnk_IntroSceneStartupUnpackSource_002:
	FOMT_INTRO_SCENE_STARTUP_TILEMAP 02
	.global gUnk_IntroSceneStartupUnpackSource_003
gUnk_IntroSceneStartupUnpackSource_003:
	FOMT_INTRO_SCENE_STARTUP_TILEMAP 03

	.global gUnk_0874A9C0
gUnk_0874A9C0:
	FOMT_INTRO_SCENE_STARTUP_VISUAL_TILES

	.global gUnk_0874E330
gUnk_0874E330:
	FOMT_INTRO_SCENE_STARTUP_VISUAL_PALETTE

	.global gUnk_0874E530
gUnk_0874E530:
	.ifdef REGION_DE
	.incbin "build/de/graphics/intro_scene/small_indexed_archive/archive.bin"
	.else
	.ifdef REGION_EU
	.incbin "build/eu/graphics/intro_scene/small_indexed_archive/archive.bin"
	.else
	.incbin "build/us/graphics/intro_scene/small_indexed_archive/archive.bin"
	.endif
	.endif

	.global gUnk_0874E648
gUnk_0874E648:
	FOMT_REGION_ASSET_INCBIN 0x74E648, 0x4F8

	.global gUnk_0874EB40
gUnk_0874EB40:
	FOMT_REGION_ASSET_INCBIN 0x74EB40, 0x20

	.global gUnk_0874EB60
gUnk_0874EB60:
	FOMT_REGION_ASSET_INCBIN 0x74EB60, 0x16C

	.global gUnk_0874ECCC
gUnk_0874ECCC:
	FOMT_UI_SCENE_08077810_TILEMAP

	.global gUnk_0874EE38
gUnk_0874EE38:
	FOMT_REGION_ASSET_INCBIN 0x74EE38, 0xDC

	.global gUnk_0874EF14
gUnk_0874EF14:
	FOMT_UI_SCENE_080A2BA4_ASSET "layer_0.tilemap.0x70"

	.global gUnk_0874EF3C
gUnk_0874EF3C:
	FOMT_UI_SCENE_080A2BA4_ASSET "layer_1.tilemap.0x70"

	.global gUnk_0874EFEC
gUnk_0874EFEC:
	FOMT_UI_SCENE_080A2BA4_ASSET "layer_2.tilemap.0x70"

	.global gUnk_0874F050
gUnk_0874F050:
	FOMT_UI_SCENE_080A2BA4_ASSET "tiles.4bpp.0x70"

	.global gUnk_0874F2EC
gUnk_0874F2EC:
	FOMT_REGION_ASSET_INCBIN 0x74F2EC, 0x60

	.global gUnk_0874F34C
gUnk_0874F34C:
	FOMT_REGION_ASSET_INCBIN 0x74F34C, 0x1394

	.global gUnk_087506E0
gUnk_087506E0:
	FOMT_REGION_ASSET_INCBIN 0x7506E0, 0x56C

	.global gUnk_08750C4C
gUnk_08750C4C:
	FOMT_REGION_ASSET_INCBIN 0x750C4C, 0x20

	.global gUnk_08750C6C
gUnk_08750C6C:
	FOMT_REGION_ASSET_INCBIN 0x750C6C, 0x20

	.global gUnk_08750C8C
gUnk_08750C8C:
	FOMT_REGION_ASSET_INCBIN 0x750C8C, 0x1C0

	.global gUnk_08750E4C
gUnk_08750E4C:
	FOMT_REGION_ASSET_INCBIN 0x750E4C, 0x120

	.global gUnk_08750F6C
gUnk_08750F6C:
	FOMT_REGION_ASSET_INCBIN 0x750F6C, 0x20

	.global gUnk_08750F8C
gUnk_08750F8C:
	FOMT_REGION_ASSET_INCBIN 0x750F8C, 0x120

	.global gUnk_087510AC
gUnk_087510AC:
	FOMT_REGION_ASSET_INCBIN 0x7510AC, 0x120

	.global gUnk_087511CC
gUnk_087511CC:
	FOMT_REGION_ASSET_INCBIN 0x7511CC, 0x120

	.global gUnk_087512EC
gUnk_087512EC:
	FOMT_REGION_ASSET_INCBIN 0x7512EC, 0x20

	.global gUnk_0875130C
gUnk_0875130C:
	FOMT_REGION_ASSET_INCBIN 0x75130C, 0x120

	.global gUnk_0875142C
gUnk_0875142C:
	FOMT_REGION_ASSET_INCBIN 0x75142C, 0x120

	.global gUnk_0875154C
gUnk_0875154C:
	FOMT_REGION_ASSET_INCBIN 0x75154C, 0x120

	.global gUnk_0875166C
gUnk_0875166C:
	FOMT_REGION_ASSET_INCBIN 0x75166C, 0x120

	.global gUnk_0875178C
gUnk_0875178C:
	FOMT_REGION_ASSET_INCBIN 0x75178C, 0x20

	.global gUnk_087517AC
gUnk_087517AC:
	FOMT_REGION_ASSET_INCBIN 0x7517AC, 0x120

	.global gUnk_087518CC
gUnk_087518CC:
	FOMT_ANIMAL_FESTIVAL_ICON 00, 4bpp

	.global gUnk_0875194C
gUnk_0875194C:
	FOMT_ANIMAL_FESTIVAL_ICON 00, gbapal

	.global gUnk_0875196C
gUnk_0875196C:
	FOMT_ANIMAL_FESTIVAL_ICON 01, 4bpp

	.global gUnk_087519EC
gUnk_087519EC:
	FOMT_ANIMAL_FESTIVAL_ICON 01, gbapal

	.global gUnk_08751A0C
gUnk_08751A0C:
	FOMT_ANIMAL_FESTIVAL_ICON 02, 4bpp

	.global gUnk_08751A8C
gUnk_08751A8C:
	FOMT_ANIMAL_FESTIVAL_ICON 02, gbapal

	.global gUnk_08751AAC
gUnk_08751AAC:
	FOMT_ANIMAL_FESTIVAL_ICON 03, 4bpp

	.global gUnk_08751B2C
gUnk_08751B2C:
	FOMT_ANIMAL_FESTIVAL_ICON 03, gbapal

	.global gUnk_08751B4C
gUnk_08751B4C:
	FOMT_ANIMAL_FESTIVAL_ICON 04, 4bpp

	.global gUnk_08751BCC
gUnk_08751BCC:
	FOMT_ANIMAL_FESTIVAL_ICON 04, gbapal

	.global gUnk_08751BEC
gUnk_08751BEC:
	FOMT_ANIMAL_FESTIVAL_ICON 05, 4bpp

	.global gUnk_08751C6C
gUnk_08751C6C:
	FOMT_ANIMAL_FESTIVAL_ICON 05, gbapal

	.global gUnk_08751C8C
gUnk_08751C8C:
	FOMT_ANIMAL_FESTIVAL_ICON 06, 4bpp

	.global gUnk_08751D0C
gUnk_08751D0C:
	FOMT_ANIMAL_FESTIVAL_ICON 06, gbapal

	.global gUnk_08751D2C
gUnk_08751D2C:
	FOMT_ANIMAL_FESTIVAL_ICON 07, 4bpp

	.global gUnk_08751DAC
gUnk_08751DAC:
	FOMT_ANIMAL_FESTIVAL_ICON 07, gbapal

	.global gUnk_08751DCC
gUnk_08751DCC:
	FOMT_ANIMAL_FESTIVAL_ICON 08, 4bpp

	.global gUnk_08751E4C
gUnk_08751E4C:
	FOMT_ANIMAL_FESTIVAL_ICON 08, gbapal

	.global gUnk_08751E6C
gUnk_08751E6C:
	FOMT_ANIMAL_FESTIVAL_ICON 09, 4bpp

	.global gUnk_08751EEC
gUnk_08751EEC:
	FOMT_ANIMAL_FESTIVAL_ICON 09, gbapal

	.global gUnk_08751F0C
gUnk_08751F0C:
	FOMT_RECORDS_TASK_TILES 00

	.global gUnk_08751F8C
gUnk_08751F8C:
	FOMT_RECORDS_TASK_PALETTE 00

	.global gUnk_08751FAC
gUnk_08751FAC:
	FOMT_RECORDS_TASK_TILES 01

	.global gUnk_0875202C
gUnk_0875202C:
	FOMT_RECORDS_TASK_PALETTE 01

	.global gUnk_0875204C
gUnk_0875204C:
	FOMT_RECORDS_TASK_TILES 02

	.global gUnk_087520CC
gUnk_087520CC:
	FOMT_RECORDS_TASK_PALETTE 02

	.global gUnk_087520EC
gUnk_087520EC:
	FOMT_RECORDS_TASK_TILES 03

	.global gUnk_0875216C
gUnk_0875216C:
	FOMT_RECORDS_TASK_PALETTE 03

	.global gUnk_0875218C
gUnk_0875218C:
	FOMT_RECORDS_TASK_TILES 04

	.global gUnk_0875220C
gUnk_0875220C:
	FOMT_RECORDS_TASK_PALETTE 04

	.global gUnk_0875222C
gUnk_0875222C:
	FOMT_RECORDS_TASK_TILES 05

	.global gUnk_087522AC
gUnk_087522AC:
	FOMT_RECORDS_TASK_PALETTE 05

	.global gUnk_087522CC
gUnk_087522CC:
	FOMT_RECORDS_TASK_TILES 06

	.global gUnk_0875234C
gUnk_0875234C:
	FOMT_RECORDS_TASK_PALETTE 06

	.global gUnk_0875236C
gUnk_0875236C:
	FOMT_FARM_STATUS_CREATURE_ICON 00, 4bpp

	.global gUnk_087523EC
gUnk_087523EC:
	FOMT_FARM_STATUS_CREATURE_ICON 00, gbapal

	.global gUnk_0875240C
gUnk_0875240C:
	FOMT_FARM_STATUS_CREATURE_ICON 01, 4bpp

	.global gUnk_0875248C
gUnk_0875248C:
	FOMT_FARM_STATUS_CREATURE_ICON 01, gbapal

	.global gUnk_087524AC
gUnk_087524AC:
	FOMT_FARM_STATUS_CREATURE_ICON 02, 4bpp

	.global gUnk_0875252C
gUnk_0875252C:
	FOMT_FARM_STATUS_CREATURE_ICON 02, gbapal

	.global gUnk_0875254C
gUnk_0875254C:
	FOMT_FARM_STATUS_CREATURE_ICON 03, 4bpp

	.global gUnk_087525CC
gUnk_087525CC:
	FOMT_FARM_STATUS_CREATURE_ICON 03, gbapal

	.global gUnk_087525EC
gUnk_087525EC:
	FOMT_FARM_STATUS_CREATURE_ICON 04, 4bpp

	.global gUnk_0875266C
gUnk_0875266C:
	FOMT_FARM_STATUS_CREATURE_ICON 04, gbapal

	.global gUnk_0875268C
gUnk_0875268C:
	FOMT_FARM_STATUS_CREATURE_ICON 05, 4bpp

	.global gUnk_0875270C
gUnk_0875270C:
	FOMT_FARM_STATUS_CREATURE_ICON 05, gbapal

	.global gUnk_0875272C
gUnk_0875272C:
	FOMT_FARM_STATUS_CREATURE_ICON 06, 4bpp

	.global gUnk_087527AC
gUnk_087527AC:
	FOMT_FARM_STATUS_CREATURE_ICON 06, gbapal

	.global gUnk_087527CC
gUnk_087527CC:
	FOMT_FARM_STATUS_CREATURE_ICON 07, 4bpp

	.global gUnk_0875284C
gUnk_0875284C:
	FOMT_FARM_STATUS_CREATURE_ICON 07, gbapal

	.global gUnk_0875286C
gUnk_0875286C:
	FOMT_FARM_STATUS_CREATURE_ICON 08, 4bpp

	.global gUnk_087528EC
gUnk_087528EC:
	FOMT_FARM_STATUS_CREATURE_ICON 08, gbapal

	.global gUnk_0875290C
gUnk_0875290C:
	FOMT_FARM_STATUS_CREATURE_ICON 09, 4bpp

	.global gUnk_0875298C
gUnk_0875298C:
	FOMT_FARM_STATUS_CREATURE_ICON 09, gbapal

	.global gUnk_087529AC
gUnk_087529AC:
	FOMT_REGION_ASSET_INCBIN 0x7529AC, 0x80

	.global gUnk_08752A2C
gUnk_08752A2C:
	FOMT_REGION_ASSET_INCBIN 0x752A2C, 0x80

	.global gUnk_08752AAC
gUnk_08752AAC:
	FOMT_REGION_ASSET_INCBIN 0x752AAC, 0x20

	.global gUnk_08752ACC
gUnk_08752ACC:
	FOMT_REGION_ASSET_INCBIN 0x752ACC, 0x80

	.global gUnk_08752B4C
gUnk_08752B4C:
	FOMT_REGION_ASSET_INCBIN 0x752B4C, 0x80

	.global gUnk_08752BCC
gUnk_08752BCC:
	FOMT_REGION_ASSET_INCBIN 0x752BCC, 0x80

	.global gUnk_08752C4C
gUnk_08752C4C:
	FOMT_REGION_ASSET_INCBIN 0x752C4C, 0x80

	.global gUnk_08752CCC
gUnk_08752CCC:
	FOMT_REGION_ASSET_INCBIN 0x752CCC, 0x80

	.global gUnk_08752D4C
gUnk_08752D4C:
	FOMT_REGION_ASSET_INCBIN 0x752D4C, 0x80

	.global gUnk_08752DCC
gUnk_08752DCC:
	FOMT_REGION_ASSET_INCBIN 0x752DCC, 0x80

	.global gUnk_08752E4C
gUnk_08752E4C:
	FOMT_FARM_STATUS_SELECTOR_CASE_09 4bpp

	.global gUnk_08752ECC
gUnk_08752ECC:
	FOMT_FARM_STATUS_SELECTOR_CASE_09 gbapal

	.global gUnk_08752EEC
gUnk_08752EEC:
	FOMT_FARM_STATUS_CREATURE_ICON 10, 4bpp

	.global gUnk_08752F6C
gUnk_08752F6C:
	FOMT_FARM_STATUS_CREATURE_ICON 10, gbapal

	.global gUnk_08752F8C
gUnk_08752F8C:
	FOMT_FARM_STATUS_CREATURE_ICON 11, 4bpp

	.global gUnk_0875300C
gUnk_0875300C:
	FOMT_FARM_STATUS_CREATURE_ICON 11, gbapal

	.global gUnk_0875302C
gUnk_0875302C:
	FOMT_FARM_STATUS_CREATURE_ICON 12, 4bpp

	.global gUnk_087530AC
gUnk_087530AC:
	FOMT_FARM_STATUS_CREATURE_ICON 12, gbapal

	.global gUnk_087530CC
gUnk_087530CC:
	FOMT_FARM_STATUS_CREATURE_ICON 13, 4bpp

	.global gUnk_0875314C
gUnk_0875314C:
	FOMT_FARM_STATUS_CREATURE_ICON 13, gbapal

	.global gUnk_0875316C
gUnk_0875316C:
	FOMT_FARM_STATUS_CREATURE_ICON 14, 4bpp

	.global gUnk_087531EC
gUnk_087531EC:
	FOMT_FARM_STATUS_CREATURE_ICON 14, gbapal

	.global gUnk_0875320C
gUnk_0875320C:
	FOMT_FARM_STATUS_CREATURE_ICON 15, 4bpp

	.global gUnk_0875328C
gUnk_0875328C:
	FOMT_FARM_STATUS_CREATURE_ICON 15, gbapal

	.global gUnk_087532AC
gUnk_087532AC:
	FOMT_FARM_STATUS_CREATURE_ICON 16, 4bpp

	.global gUnk_0875332C
gUnk_0875332C:
	FOMT_FARM_STATUS_CREATURE_ICON 16, gbapal

	.global gUnk_0875334C
gUnk_0875334C:
	FOMT_FARM_STATUS_CREATURE_ICON 17, 4bpp

	.global gUnk_087533CC
gUnk_087533CC:
	FOMT_FARM_STATUS_CREATURE_ICON 17, gbapal

	.global gUnk_087533EC
gUnk_087533EC:
	FOMT_FARM_STATUS_CREATURE_ICON 18, 4bpp

	.global gUnk_0875346C
gUnk_0875346C:
	FOMT_FARM_STATUS_CREATURE_ICON 18, gbapal

	.global gUnk_0875348C
gUnk_0875348C:
	FOMT_FARM_STATUS_CREATURE_ICON 19, 4bpp

	.global gUnk_0875350C
gUnk_0875350C:
	FOMT_FARM_STATUS_CREATURE_ICON 19, gbapal

	.global gUnk_0875352C
gUnk_0875352C:
	FOMT_REGION_ASSET_INCBIN 0x75352C, 0xDC

	.global gUnk_08753608
gUnk_08753608:
	FOMT_REGION_ASSET_INCBIN 0x753608, 0xDC

	.global gUnk_087536E4
gUnk_087536E4:
	FOMT_REGION_ASSET_INCBIN 0x7536E4, 0xEC

	.global gUnk_087537D0
gUnk_087537D0:
	FOMT_REGION_ASSET_INCBIN 0x7537D0, 0xEA4

	.global gUnk_08754674
gUnk_08754674:
	FOMT_REGION_ASSET_INCBIN 0x754674, 0x598

	.global gUnk_08754C0C
gUnk_08754C0C:
	FOMT_REGION_ASSET_INCBIN 0x754C0C, 0x548

	.global gUnk_08755154
gUnk_08755154:
	FOMT_REGION_ASSET_INCBIN 0x755154, 0xDC

	.global gUnk_08755230
gUnk_08755230:
	FOMT_SEASONAL_NONWINTER_ASSET "bg_30.tilemap"

	.global gUnk_0875553C
gUnk_0875553C:
	FOMT_SEASONAL_NONWINTER_ASSET "bg_29.tilemap"

	.global gUnk_08755848
gUnk_08755848:
	FOMT_SEASONAL_NONWINTER_ASSET "nonwinter_tiles.0x70"

	.global gUnk_08757AE0
gUnk_08757AE0:
	FOMT_SEASONAL_NONWINTER_ASSET "nonwinter_palette_banks.gbapal"

	.global gUnk_08757BA0
gUnk_08757BA0:
	FOMT_REGION_ASSET_INCBIN 0x757BA0, 0xC

	.global gUnk_08757BAC
gUnk_08757BAC:
	FOMT_REGION_ASSET_INCBIN 0x757BAC, 0x20

	.global gUnk_08757BCC
gUnk_08757BCC:
	FOMT_REGION_ASSET_INCBIN 0x757BCC, 0xC

	.global gUnk_08757BD8
gUnk_08757BD8:
	FOMT_REGION_ASSET_INCBIN 0x757BD8, 0x20

	.global gUnk_08757BF8
gUnk_08757BF8:
	FOMT_REGION_ASSET_INCBIN 0x757BF8, 0x14

	.global gUnk_08757C0C
gUnk_08757C0C:
	FOMT_REGION_ASSET_INCBIN 0x757C0C, 0x8

	.global gUnk_08757C14
gUnk_08757C14:
	FOMT_SEASONAL_NONWINTER_ASSET "bg_30.tilemap"

	.global gUnk_08757F20
gUnk_08757F20:
	FOMT_SEASONAL_WINTER_ASSET "winter_bg_29.tilemap"

	.global gUnk_0875822C
gUnk_0875822C:
	FOMT_SEASONAL_WINTER_ASSET "winter_tiles.0x70"

	.global gUnk_0875A358
gUnk_0875A358:
	FOMT_SEASONAL_WINTER_ASSET "winter_palette_banks.gbapal"

	.global gUnk_0875A418
gUnk_0875A418:
	FOMT_REGION_ASSET_INCBIN 0x75A418, 0xC

	.global gUnk_0875A424
gUnk_0875A424:
	FOMT_REGION_ASSET_INCBIN 0x75A424, 0x14

	.global gUnk_0875A438
gUnk_0875A438:
	FOMT_REGION_ASSET_INCBIN 0x75A438, 0x8

	.global gUnk_0875A440 @ gClockFont
gUnk_0875A440:
	FOMT_CLOCK_FONT

	.global gUnk_0875B444
gUnk_0875B444:
	FOMT_REGION_ASSET_INCBIN 0x75B444, 0x3D4

	@ These labels designate the exact payload bytes consumed by the typed
	@ ui_state table.  Do not replace them with base-plus-offset aliases.
	.global gUnk_UiSharedResourceData_000
gUnk_UiSharedResourceData_000:
	.ifdef REGION_EU
	.incbin "build/eu/graphics/ui/shared_resource/shared_resource.4bpp"
	.else
	.ifdef REGION_DE
	.incbin "build/de/graphics/ui/shared_resource/shared_resource.4bpp"
	.else
	.incbin "build/us/graphics/ui/shared_resource/shared_resource.4bpp"
	.endif
	.endif
	.global gUnk_UiSharedResourceData_001
gUnk_UiSharedResourceData_001:
	.ifdef REGION_EU
	.incbin "build/eu/graphics/ui/shared_resource/shared_resource.gbapal"
	.else
	.ifdef REGION_DE
	.incbin "build/de/graphics/ui/shared_resource/shared_resource.gbapal"
	.else
	.incbin "build/us/graphics/ui/shared_resource/shared_resource.gbapal"
	.endif
	.endif
	@ US and EU store twelve non-palette bytes between this typed 16-colour
	@ palette and the following function table.  Keep them raw: UiSharedResourceData
	@ points to exactly 0x20 palette bytes, not to this adjacent metadata.
	.ifdef REGION_EU
	.incbin "baserom_eu.gba", 0x75B9B4, 0xC
	.else
	.incbin "baserom_us.gba", 0x75B958, 0xC
	.endif

	@ Thumb function dispatch table.  Keep these as relocations so regional
	@ code-layout differences update the function pointers automatically.
	.4byte func_080D3778 + 1
	.4byte func_080D379C + 1
	.4byte func_080D3840 + 1
	.4byte func_080D3870 + 1

	FOMT_REGION_ASSET_INCBIN 0x75B974, 0x84

	.endif
    .endif

    @ EU payload labels used directly by map and FarmHouse C++ tables.
    @ The preceding four bytes remain the EU archive header; each label below
    @ denotes payload byte 0, so C++ never compensates with a regional offset.
    .ifdef REGION_EU
    .set gUnk_MapDataResource_000, gUnk_MapDataResource_000 + 4
    .set gUnk_MapDataResource_001, gUnk_MapDataResource_001 + 4
    .set gUnk_MapDataResource_002, gUnk_MapDataResource_002 + 4
    .set gUnk_MapDataResource_003, gUnk_MapDataResource_003 + 4
    .set gUnk_MapDataResource_004, gUnk_MapDataResource_004 + 4
    .set gUnk_MapDataResource_005, gUnk_MapDataResource_005 + 4
    .set gUnk_MapDataResource_008, gUnk_MapDataResource_008 + 4
    .set gUnk_MapDataResource_009, gUnk_MapDataResource_009 + 4
    .set gUnk_MapDataResource_010, gUnk_MapDataResource_010 + 4
    .set gUnk_MapDataResource_011, gUnk_MapDataResource_011 + 4
    .set gUnk_MapDataResource_012, gUnk_MapDataResource_012 + 4
    .set gUnk_MapDataResource_013, gUnk_MapDataResource_013 + 4
    .set gUnk_MapDataResource_014, gUnk_MapDataResource_014 + 4
    .set gUnk_MapDataResource_015, gUnk_MapDataResource_015 + 4
    .set gUnk_MapDataResource_016, gUnk_MapDataResource_016 + 4
    .set gUnk_MapDataResource_017, gUnk_MapDataResource_017 + 4
    .set gUnk_MapDataResource_018, gUnk_MapDataResource_018 + 4
    .set gUnk_MapDataResource_019, gUnk_MapDataResource_019 + 4
    .set gUnk_MapDataResource_022, gUnk_MapDataResource_022 + 4
    .set gUnk_MapDataResource_023, gUnk_MapDataResource_023 + 4
    .set gUnk_MapDataResource_024, gUnk_MapDataResource_024 + 4
    .set gUnk_MapDataResource_025, gUnk_MapDataResource_025 + 4
    .set gUnk_MapDataResource_026, gUnk_MapDataResource_026 + 4
    .set gUnk_MapDataResource_027, gUnk_MapDataResource_027 + 4
    .set gUnk_MapDataResource_028, gUnk_MapDataResource_028 + 4
    .set gUnk_MapDataResource_029, gUnk_MapDataResource_029 + 4
    .set gUnk_MapDataResource_030, gUnk_MapDataResource_030 + 4
    .set gUnk_MapDataResource_031, gUnk_MapDataResource_031 + 4
    .set gUnk_MapDataResource_032, gUnk_MapDataResource_032 + 4
    .set gUnk_MapDataResource_033, gUnk_MapDataResource_033 + 4
    .set gUnk_MapDataResource_036, gUnk_MapDataResource_036 + 4
    .set gUnk_MapDataResource_037, gUnk_MapDataResource_037 + 4
    .set gUnk_MapDataResource_038, gUnk_MapDataResource_038 + 4
    .set gUnk_MapDataResource_039, gUnk_MapDataResource_039 + 4
    .set gUnk_MapDataResource_040, gUnk_MapDataResource_040 + 4
    .set gUnk_MapDataResource_041, gUnk_MapDataResource_041 + 4
    .set gUnk_MapDataResource_042, gUnk_MapDataResource_042 + 4
    .set gUnk_MapDataResource_043, gUnk_MapDataResource_043 + 4
    .set gUnk_MapDataResource_044, gUnk_MapDataResource_044 + 4
    .set gUnk_MapDataResource_045, gUnk_MapDataResource_045 + 4
    .set gUnk_MapDataResource_046, gUnk_MapDataResource_046 + 4
    .set gUnk_MapDataResource_047, gUnk_MapDataResource_047 + 4
    .set gUnk_MapDataResource_050, gUnk_MapDataResource_050 + 4
    .set gUnk_MapDataResource_051, gUnk_MapDataResource_051 + 4
    .set gUnk_MapDataResource_052, gUnk_MapDataResource_052 + 4
    .set gUnk_MapDataResource_053, gUnk_MapDataResource_053 + 4
    .set gUnk_MapDataResource_054, gUnk_MapDataResource_054 + 4
    .set gUnk_MapDataResource_055, gUnk_MapDataResource_055 + 4
    .set gUnk_MapDataResource_056, gUnk_MapDataResource_056 + 4
    .set gUnk_MapDataResource_057, gUnk_MapDataResource_057 + 4
    .set gUnk_MapDataResource_058, gUnk_MapDataResource_058 + 4
    .set gUnk_MapDataResource_059, gUnk_MapDataResource_059 + 4
    .set gUnk_MapDataResource_060, gUnk_MapDataResource_060 + 4
    .set gUnk_MapDataResource_061, gUnk_MapDataResource_061 + 4
    .set gUnk_MapDataResource_064, gUnk_MapDataResource_064 + 4
    .set gUnk_MapDataResource_065, gUnk_MapDataResource_065 + 4
    .set gUnk_MapDataResource_066, gUnk_MapDataResource_066 + 4
    .set gUnk_MapDataResource_067, gUnk_MapDataResource_067 + 4
    .set gUnk_MapDataResource_068, gUnk_MapDataResource_068 + 4
    .set gUnk_MapDataResource_069, gUnk_MapDataResource_069 + 4
    .set gUnk_MapDataResource_070, gUnk_MapDataResource_070 + 4
    .set gUnk_MapDataResource_071, gUnk_MapDataResource_071 + 4
    .set gUnk_MapDataResource_072, gUnk_MapDataResource_072 + 4
    .set gUnk_MapDataResource_073, gUnk_MapDataResource_073 + 4
    .set gUnk_MapDataResource_074, gUnk_MapDataResource_074 + 4
    .set gUnk_MapDataResource_075, gUnk_MapDataResource_075 + 4
    .set gUnk_MapDataResource_078, gUnk_MapDataResource_078 + 4
    .set gUnk_MapDataResource_079, gUnk_MapDataResource_079 + 4
    .set gUnk_MapDataResource_080, gUnk_MapDataResource_080 + 4
    .set gUnk_MapDataResource_081, gUnk_MapDataResource_081 + 4
    .set gUnk_MapDataResource_082, gUnk_MapDataResource_082 + 4
    .set gUnk_MapDataResource_083, gUnk_MapDataResource_083 + 4
    .set gUnk_MapDataResource_084, gUnk_MapDataResource_084 + 4
    .set gUnk_MapDataResource_085, gUnk_MapDataResource_085 + 4
    .set gUnk_MapDataResource_086, gUnk_MapDataResource_086 + 4
    .set gUnk_MapDataResource_089, gUnk_MapDataResource_089 + 4
    .set gUnk_MapDataResource_090, gUnk_MapDataResource_090 + 4
    .set gUnk_MapDataResource_091, gUnk_MapDataResource_091 + 4
    .set gUnk_MapDataResource_092, gUnk_MapDataResource_092 + 4
    .set gUnk_MapDataResource_093, gUnk_MapDataResource_093 + 4
    .set gUnk_MapDataResource_094, gUnk_MapDataResource_094 + 4
    .set gUnk_MapDataResource_095, gUnk_MapDataResource_095 + 4
    .set gUnk_MapDataResource_096, gUnk_MapDataResource_096 + 4
    .set gUnk_MapDataResource_097, gUnk_MapDataResource_097 + 4
    .set gUnk_MapDataResource_100, gUnk_MapDataResource_100 + 4
    .set gUnk_MapDataResource_101, gUnk_MapDataResource_101 + 4
    .set gUnk_MapDataResource_102, gUnk_MapDataResource_102 + 4
    .set gUnk_MapDataResource_103, gUnk_MapDataResource_103 + 4
    .set gUnk_MapDataResource_104, gUnk_MapDataResource_104 + 4
    .set gUnk_MapDataResource_105, gUnk_MapDataResource_105 + 4
    .set gUnk_MapDataResource_106, gUnk_MapDataResource_106 + 4
    .set gUnk_MapDataResource_107, gUnk_MapDataResource_107 + 4
    .set gUnk_MapDataResource_108, gUnk_MapDataResource_108 + 4
    .set gUnk_MapDataResource_109, gUnk_MapDataResource_109 + 4
    .set gUnk_MapDataResource_110, gUnk_MapDataResource_110 + 4
    .set gUnk_MapDataResource_111, gUnk_MapDataResource_111 + 4
    .set gUnk_MapDataResource_114, gUnk_MapDataResource_114 + 4
    .set gUnk_MapDataResource_115, gUnk_MapDataResource_115 + 4
    .set gUnk_MapDataResource_116, gUnk_MapDataResource_116 + 4
    .set gUnk_MapDataResource_117, gUnk_MapDataResource_117 + 4
    .set gUnk_MapDataResource_118, gUnk_MapDataResource_118 + 4
    .set gUnk_MapDataResource_119, gUnk_MapDataResource_119 + 4
    .set gUnk_MapDataResource_120, gUnk_MapDataResource_120 + 4
    .set gUnk_MapDataResource_121, gUnk_MapDataResource_121 + 4
    .set gUnk_MapDataResource_122, gUnk_MapDataResource_122 + 4
    .set gUnk_MapDataResource_123, gUnk_MapDataResource_123 + 4
    .set gUnk_MapDataResource_124, gUnk_MapDataResource_124 + 4
    .set gUnk_MapDataResource_127, gUnk_MapDataResource_127 + 4
    .set gUnk_MapDataResource_128, gUnk_MapDataResource_128 + 4
    .set gUnk_MapDataResource_129, gUnk_MapDataResource_129 + 4
    .set gUnk_MapDataResource_132, gUnk_MapDataResource_132 + 4
    .set gUnk_MapDataResource_133, gUnk_MapDataResource_133 + 4
    .set gUnk_MapDataResource_134, gUnk_MapDataResource_134 + 4
    .set gUnk_MapDataResource_137, gUnk_MapDataResource_137 + 4
    .set gUnk_MapDataResource_138, gUnk_MapDataResource_138 + 4
    .set gUnk_MapDataResource_139, gUnk_MapDataResource_139 + 4
    .set gUnk_MapDataResource_142, gUnk_MapDataResource_142 + 4
    .set gUnk_MapDataResource_143, gUnk_MapDataResource_143 + 4
    .set gUnk_MapDataResource_144, gUnk_MapDataResource_144 + 4
    .set gUnk_MapDataResource_145, gUnk_MapDataResource_145 + 4
    .set gUnk_MapDataResource_146, gUnk_MapDataResource_146 + 4
    .set gUnk_MapDataResource_149, gUnk_MapDataResource_149 + 4
    .set gUnk_MapDataResource_150, gUnk_MapDataResource_150 + 4
    .set gUnk_MapDataResource_151, gUnk_MapDataResource_151 + 4
    .set gUnk_MapDataResource_154, gUnk_MapDataResource_154 + 4
    .set gUnk_MapDataResource_155, gUnk_MapDataResource_155 + 4
    .set gUnk_MapDataResource_156, gUnk_MapDataResource_156 + 4
    .set gUnk_MapDataResource_159, gUnk_MapDataResource_159 + 4
    .set gUnk_MapDataResource_160, gUnk_MapDataResource_160 + 4
    .set gUnk_MapDataResource_161, gUnk_MapDataResource_161 + 4
    .set gUnk_MapDataResource_162, gUnk_MapDataResource_162 + 4
    .set gUnk_MapDataResource_163, gUnk_MapDataResource_163 + 4
    .set gUnk_MapDataResource_166, gUnk_MapDataResource_166 + 4
    .set gUnk_MapDataResource_167, gUnk_MapDataResource_167 + 4
    .set gUnk_MapDataResource_168, gUnk_MapDataResource_168 + 4
    .set gUnk_MapDataResource_169, gUnk_MapDataResource_169 + 4
    .set gUnk_MapDataResource_170, gUnk_MapDataResource_170 + 4
    .set gUnk_MapDataResource_173, gUnk_MapDataResource_173 + 4
    .set gUnk_MapDataResource_174, gUnk_MapDataResource_174 + 4
    .set gUnk_MapDataResource_175, gUnk_MapDataResource_175 + 4
    .set gUnk_MapDataResource_178, gUnk_MapDataResource_178 + 4
    .set gUnk_MapDataResource_179, gUnk_MapDataResource_179 + 4
    .set gUnk_MapDataResource_180, gUnk_MapDataResource_180 + 4
    .set gUnk_MapDataResource_183, gUnk_MapDataResource_183 + 4
    .set gUnk_MapDataResource_184, gUnk_MapDataResource_184 + 4
    .set gUnk_MapDataResource_185, gUnk_MapDataResource_185 + 4
    .set gUnk_MapDataResource_186, gUnk_MapDataResource_186 + 4
    .set gUnk_MapDataResource_187, gUnk_MapDataResource_187 + 4
    .set gUnk_MapDataResource_190, gUnk_MapDataResource_190 + 4
    .set gUnk_MapDataResource_191, gUnk_MapDataResource_191 + 4
    .set gUnk_MapDataResource_192, gUnk_MapDataResource_192 + 4
    .set gUnk_MapDataResource_195, gUnk_MapDataResource_195 + 4
    .set gUnk_MapDataResource_196, gUnk_MapDataResource_196 + 4
    .set gUnk_MapDataResource_197, gUnk_MapDataResource_197 + 4
    .set gUnk_MapDataResource_200, gUnk_MapDataResource_200 + 4
    .set gUnk_MapDataResource_201, gUnk_MapDataResource_201 + 4
    .set gUnk_MapDataResource_202, gUnk_MapDataResource_202 + 4
    .set gUnk_MapDataResource_203, gUnk_MapDataResource_203 + 4
    .set gUnk_MapDataResource_204, gUnk_MapDataResource_204 + 4
    .set gUnk_MapDataResource_207, gUnk_MapDataResource_207 + 4
    .set gUnk_MapDataResource_208, gUnk_MapDataResource_208 + 4
    .set gUnk_MapDataResource_209, gUnk_MapDataResource_209 + 4
    .set gUnk_MapDataResource_212, gUnk_MapDataResource_212 + 4
    .set gUnk_MapDataResource_213, gUnk_MapDataResource_213 + 4
    .set gUnk_MapDataResource_214, gUnk_MapDataResource_214 + 4
    .set gUnk_MapDataResource_217, gUnk_MapDataResource_217 + 4
    .set gUnk_MapDataResource_218, gUnk_MapDataResource_218 + 4
    .set gUnk_MapDataResource_219, gUnk_MapDataResource_219 + 4
    .set gUnk_MapDataResource_222, gUnk_MapDataResource_222 + 4
    .set gUnk_MapDataResource_223, gUnk_MapDataResource_223 + 4
    .set gUnk_MapDataResource_224, gUnk_MapDataResource_224 + 4
    .set gUnk_MapDataResource_225, gUnk_MapDataResource_225 + 4
    .set gUnk_MapDataResource_226, gUnk_MapDataResource_226 + 4
    .set gUnk_MapDataResource_229, gUnk_MapDataResource_229 + 4
    .set gUnk_MapDataResource_230, gUnk_MapDataResource_230 + 4
    .set gUnk_MapDataResource_231, gUnk_MapDataResource_231 + 4
    .set gUnk_MapDataResource_234, gUnk_MapDataResource_234 + 4
    .set gUnk_MapDataResource_235, gUnk_MapDataResource_235 + 4
    .set gUnk_MapDataResource_236, gUnk_MapDataResource_236 + 4
    .set gUnk_MapDataResource_239, gUnk_MapDataResource_239 + 4
    .set gUnk_MapDataResource_240, gUnk_MapDataResource_240 + 4
    .set gUnk_MapDataResource_241, gUnk_MapDataResource_241 + 4
    .set gUnk_MapDataResource_244, gUnk_MapDataResource_244 + 4
    .set gUnk_MapDataResource_245, gUnk_MapDataResource_245 + 4
    .set gUnk_MapDataResource_246, gUnk_MapDataResource_246 + 4
    .set gUnk_MapDataResource_249, gUnk_MapDataResource_249 + 4
    .set gUnk_MapDataResource_250, gUnk_MapDataResource_250 + 4
    .set gUnk_MapDataResource_251, gUnk_MapDataResource_251 + 4
    .set gUnk_MapDataResource_252, gUnk_MapDataResource_252 + 4
    .set gUnk_MapDataResource_253, gUnk_MapDataResource_253 + 4
    .set gUnk_MapDataResource_256, gUnk_MapDataResource_256 + 4
    .set gUnk_MapDataResource_257, gUnk_MapDataResource_257 + 4
    .set gUnk_MapDataResource_258, gUnk_MapDataResource_258 + 4
    .set gUnk_MapDataResource_261, gUnk_MapDataResource_261 + 4
    .set gUnk_MapDataResource_262, gUnk_MapDataResource_262 + 4
    .set gUnk_MapDataResource_263, gUnk_MapDataResource_263 + 4
    .set gUnk_MapDataResource_266, gUnk_MapDataResource_266 + 4
    .set gUnk_MapDataResource_267, gUnk_MapDataResource_267 + 4
    .set gUnk_MapDataResource_268, gUnk_MapDataResource_268 + 4
    .set gUnk_MapDataResource_269, gUnk_MapDataResource_269 + 4
    .set gUnk_MapDataResource_270, gUnk_MapDataResource_270 + 4
    .set gUnk_MapDataResource_273, gUnk_MapDataResource_273 + 4
    .set gUnk_MapDataResource_274, gUnk_MapDataResource_274 + 4
    .set gUnk_MapDataResource_275, gUnk_MapDataResource_275 + 4
    .set gUnk_MapDataResource_278, gUnk_MapDataResource_278 + 4
    .set gUnk_MapDataResource_279, gUnk_MapDataResource_279 + 4
    .set gUnk_MapDataResource_280, gUnk_MapDataResource_280 + 4
    .set gUnk_MapDataResource_281, gUnk_MapDataResource_281 + 4
    .set gUnk_MapDataResource_282, gUnk_MapDataResource_282 + 4
    .set gUnk_MapDataResource_285, gUnk_MapDataResource_285 + 4
    .set gUnk_MapDataResource_286, gUnk_MapDataResource_286 + 4
    .set gUnk_MapDataResource_287, gUnk_MapDataResource_287 + 4
    .set gUnk_MapDataResource_290, gUnk_MapDataResource_290 + 4
    .set gUnk_MapDataResource_291, gUnk_MapDataResource_291 + 4
    .set gUnk_MapDataResource_292, gUnk_MapDataResource_292 + 4
    .set gUnk_MapDataResource_293, gUnk_MapDataResource_293 + 4
    .set gUnk_MapDataResource_294, gUnk_MapDataResource_294 + 4
    .set gUnk_MapDataResource_297, gUnk_MapDataResource_297 + 4
    .set gUnk_MapDataResource_298, gUnk_MapDataResource_298 + 4
    .set gUnk_MapDataResource_299, gUnk_MapDataResource_299 + 4
    .set gUnk_MapDataResource_302, gUnk_MapDataResource_302 + 4
    .set gUnk_MapDataResource_303, gUnk_MapDataResource_303 + 4
    .set gUnk_MapDataResource_304, gUnk_MapDataResource_304 + 4
    .set gUnk_MapDataResource_305, gUnk_MapDataResource_305 + 4
    .set gUnk_MapDataResource_306, gUnk_MapDataResource_306 + 4
    .set gUnk_MapDataResource_309, gUnk_MapDataResource_309 + 4
    .set gUnk_MapDataResource_310, gUnk_MapDataResource_310 + 4
    .set gUnk_MapDataResource_311, gUnk_MapDataResource_311 + 4
    .set gUnk_MapDataResource_314, gUnk_MapDataResource_314 + 4
    .set gUnk_MapDataResource_315, gUnk_MapDataResource_315 + 4
    .set gUnk_MapDataResource_316, gUnk_MapDataResource_316 + 4
    .set gUnk_MapDataResource_317, gUnk_MapDataResource_317 + 4
    .set gUnk_MapDataResource_318, gUnk_MapDataResource_318 + 4
    .set gUnk_MapDataResource_321, gUnk_MapDataResource_321 + 4
    .set gUnk_MapDataResource_322, gUnk_MapDataResource_322 + 4
    .set gUnk_MapDataResource_323, gUnk_MapDataResource_323 + 4
    .set gUnk_MapDataResource_324, gUnk_MapDataResource_324 + 4
    .set gUnk_MapDataResource_325, gUnk_MapDataResource_325 + 4
    .set gUnk_MapDataResource_328, gUnk_MapDataResource_328 + 4
    .set gUnk_MapDataResource_329, gUnk_MapDataResource_329 + 4
    .set gUnk_MapDataResource_330, gUnk_MapDataResource_330 + 4
    .set gUnk_MapDataResource_333, gUnk_MapDataResource_333 + 4
    .set gUnk_MapDataResource_334, gUnk_MapDataResource_334 + 4
    .set gUnk_MapDataResource_335, gUnk_MapDataResource_335 + 4
    .set gUnk_MapDataResource_338, gUnk_MapDataResource_338 + 4
    .set gUnk_MapDataResource_339, gUnk_MapDataResource_339 + 4
    .set gUnk_MapDataResource_340, gUnk_MapDataResource_340 + 4
    .set gUnk_MapDataResource_341, gUnk_MapDataResource_341 + 4
    .set gUnk_MapDataResource_342, gUnk_MapDataResource_342 + 4
    .set gUnk_MapDataResource_345, gUnk_MapDataResource_345 + 4
    .set gUnk_MapDataResource_346, gUnk_MapDataResource_346 + 4
    .set gUnk_MapDataResource_347, gUnk_MapDataResource_347 + 4
    .set gUnk_MapDataResource_350, gUnk_MapDataResource_350 + 4
    .set gUnk_MapDataResource_351, gUnk_MapDataResource_351 + 4
    .set gUnk_MapDataResource_352, gUnk_MapDataResource_352 + 4
    .set gUnk_MapDataResource_355, gUnk_MapDataResource_355 + 4
    .set gUnk_MapDataResource_356, gUnk_MapDataResource_356 + 4
    .set gUnk_MapDataResource_357, gUnk_MapDataResource_357 + 4
    .set gUnk_MapDataResource_360, gUnk_MapDataResource_360 + 4
    .set gUnk_MapDataResource_361, gUnk_MapDataResource_361 + 4
    .set gUnk_MapDataResource_362, gUnk_MapDataResource_362 + 4
    .set gUnk_MapDataResource_365, gUnk_MapDataResource_365 + 4
    .set gUnk_MapDataResource_366, gUnk_MapDataResource_366 + 4
    .set gUnk_MapDataResource_367, gUnk_MapDataResource_367 + 4
    .set gUnk_MapDataResource_370, gUnk_MapDataResource_370 + 4
    .set gUnk_MapDataResource_371, gUnk_MapDataResource_371 + 4
    .set gUnk_MapDataResource_374, gUnk_MapDataResource_374 + 4
    .set gUnk_MapDataResource_375, gUnk_MapDataResource_375 + 4
    .set gUnk_MapDataResource_376, gUnk_MapDataResource_376 + 4
    .set gUnk_MapDataResource_377, gUnk_MapDataResource_377 + 4
    .set gUnk_MapDataResource_378, gUnk_MapDataResource_378 + 4
    .set gUnk_MapDataResource_379, gUnk_MapDataResource_379 + 4
    .set gUnk_FarmHouseTilePatchResource_000, gUnk_FarmHouseTilePatchResource_000 + 4
    .set gUnk_FarmHouseTilePatchResource_001, gUnk_FarmHouseTilePatchResource_001 + 4
    .set gUnk_FarmHouseTilePatchResource_002, gUnk_FarmHouseTilePatchResource_002 + 4
    .set gUnk_FarmHouseTilePatchResource_003, gUnk_FarmHouseTilePatchResource_003 + 4
    .set gUnk_FarmHouseTilePatchResource_004, gUnk_FarmHouseTilePatchResource_004 + 4
    .set gUnk_FarmHouseTilePatchResource_005, gUnk_FarmHouseTilePatchResource_005 + 4
    .set gUnk_FarmHouseTilePatchResource_006, gUnk_FarmHouseTilePatchResource_006 + 4
    .set gUnk_FarmHouseTilePatchResource_007, gUnk_FarmHouseTilePatchResource_007 + 4
    .set gUnk_FarmHouseTilePatchResource_008, gUnk_FarmHouseTilePatchResource_008 + 4
    .set gUnk_FarmHouseTilePatchResource_009, gUnk_FarmHouseTilePatchResource_009 + 4
    .set gUnk_FarmHouseTilePatchResource_010, gUnk_FarmHouseTilePatchResource_010 + 4
    .set gUnk_FarmHouseTilePatchResource_011, gUnk_FarmHouseTilePatchResource_011 + 4
    .set gUnk_FarmHouseTilePatchResource_012, gUnk_FarmHouseTilePatchResource_012 + 4
    .set gUnk_FarmHouseTilePatchResource_013, gUnk_FarmHouseTilePatchResource_013 + 4
    .set gUnk_FarmHouseTilePatchResource_014, gUnk_FarmHouseTilePatchResource_014 + 4
    .set gUnk_FarmHouseTilePatchResource_015, gUnk_FarmHouseTilePatchResource_015 + 4
    .set gUnk_FarmHouseTilePatchResource_016, gUnk_FarmHouseTilePatchResource_016 + 4
    .set gUnk_FarmHouseTilePatchResource_017, gUnk_FarmHouseTilePatchResource_017 + 4
    .set gUnk_FarmHouseTilePatchResource_018, gUnk_FarmHouseTilePatchResource_018 + 4
    .set gUnk_FarmHouseTilePatchResource_019, gUnk_FarmHouseTilePatchResource_019 + 4
    .set gUnk_FarmHouseTilePatchResource_020, gUnk_FarmHouseTilePatchResource_020 + 4
    .set gUnk_FarmHouseTilePatchResource_021, gUnk_FarmHouseTilePatchResource_021 + 4
    .set gUnk_FarmHouseTilePatchResource_022, gUnk_FarmHouseTilePatchResource_022 + 4
    .set gUnk_FarmHouseTilePatchResource_023, gUnk_FarmHouseTilePatchResource_023 + 4
    .set gUnk_FarmHouseTilePatchResource_024, gUnk_FarmHouseTilePatchResource_024 + 4
    .set gUnk_FarmHouseTilePatchResource_025, gUnk_FarmHouseTilePatchResource_025 + 4
    .set gUnk_FarmHouseTilePatchResource_026, gUnk_FarmHouseTilePatchResource_026 + 4
    .set gUnk_FarmHouseTilePatchResource_027, gUnk_FarmHouseTilePatchResource_027 + 4
    .set gUnk_FarmHouseTilePatchAnimationResource_000, gUnk_FarmHouseTilePatchAnimationResource_000 + 4
    .set gUnk_FarmHouseTilePatchAnimationResource_001, gUnk_FarmHouseTilePatchAnimationResource_001 + 4
    .set gUnk_FarmHouseVisualResource_000, gUnk_FarmHouseVisualResource_000 + 4
    .set gUnk_FarmHouseVisualResource_001, gUnk_FarmHouseVisualResource_001 + 4
    .set gUnk_FarmHouseVisualResource_004, gUnk_FarmHouseVisualResource_004 + 4
    .set gUnk_FarmHouseVisualResource_005, gUnk_FarmHouseVisualResource_005 + 4
    .set gUnk_FarmHouseVisualResource_006, gUnk_FarmHouseVisualResource_006 + 4
    .set gUnk_FarmHouseVisualResource_007, gUnk_FarmHouseVisualResource_007 + 4
    .set gUnk_FarmHouseVisualResource_010, gUnk_FarmHouseVisualResource_010 + 4
    .set gUnk_FarmHouseVisualResource_011, gUnk_FarmHouseVisualResource_011 + 4
    .set gUnk_FarmHouseVisualResource_012, gUnk_FarmHouseVisualResource_012 + 4
    .set gUnk_FarmHouseVisualResource_013, gUnk_FarmHouseVisualResource_013 + 4
    .set gUnk_FarmHouseVisualResource_014, gUnk_FarmHouseVisualResource_014 + 4
    .set gUnk_FarmHouseVisualResource_015, gUnk_FarmHouseVisualResource_015 + 4
    .set gUnk_FarmHouseVisualResource_016, gUnk_FarmHouseVisualResource_016 + 4
    .set gUnk_FarmHouseVisualResource_017, gUnk_FarmHouseVisualResource_017 + 4
    .set gUnk_FarmHouseVisualResource_018, gUnk_FarmHouseVisualResource_018 + 4
    .set gUnk_FarmHouseVisualResource_019, gUnk_FarmHouseVisualResource_019 + 4
    .set gUnk_FarmHouseVisualResource_022, gUnk_FarmHouseVisualResource_022 + 4
    .set gUnk_FarmHouseVisualResource_023, gUnk_FarmHouseVisualResource_023 + 4
    .set gUnk_FarmHouseVisualResource_024, gUnk_FarmHouseVisualResource_024 + 4
    .set gUnk_FarmHouseVisualResource_025, gUnk_FarmHouseVisualResource_025 + 4
    .set gUnk_FarmHouseVisualResource_028, gUnk_FarmHouseVisualResource_028 + 4
    .set gUnk_FarmHouseVisualResource_029, gUnk_FarmHouseVisualResource_029 + 4
    .set gUnk_FarmHouseVisualResource_030, gUnk_FarmHouseVisualResource_030 + 4
    .set gUnk_FarmHouseVisualResource_031, gUnk_FarmHouseVisualResource_031 + 4
    .set gUnk_FarmHouseVisualResource_034, gUnk_FarmHouseVisualResource_034 + 4
    .set gUnk_FarmHouseVisualResource_035, gUnk_FarmHouseVisualResource_035 + 4
    .set gUnk_FarmHouseVisualResource_036, gUnk_FarmHouseVisualResource_036 + 4
    .set gUnk_FarmHouseVisualResource_037, gUnk_FarmHouseVisualResource_037 + 4
    .set gUnk_FarmHouseVisualResource_038, gUnk_FarmHouseVisualResource_038 + 4
    .set gUnk_FarmHouseVisualResource_041, gUnk_FarmHouseVisualResource_041 + 4
    .set gUnk_FarmHouseVisualResource_042, gUnk_FarmHouseVisualResource_042 + 4

    .set gUnk_FieldRenderResource_000, gUnk_FieldRenderResource_000 + 4
    .set gUnk_FieldRenderResource_001, gUnk_FieldRenderResource_001 + 4
    .set gUnk_FieldRenderResource_004, gUnk_FieldRenderResource_004 + 4
    .set gUnk_FieldRenderResource_005, gUnk_FieldRenderResource_005 + 4
    .set gUnk_FieldRenderResource_006, gUnk_FieldRenderResource_006 + 4
    .set gUnk_FieldRenderResource_007, gUnk_FieldRenderResource_007 + 4
    .set gUnk_FieldRenderResource_010, gUnk_FieldRenderResource_010 + 4
    .set gUnk_FieldRenderResource_011, gUnk_FieldRenderResource_011 + 4
    .set gUnk_FieldRenderResource_012, gUnk_FieldRenderResource_012 + 4
    .set gUnk_FieldRenderResource_013, gUnk_FieldRenderResource_013 + 4
    .set gUnk_FieldRenderResource_016, gUnk_FieldRenderResource_016 + 4
    .set gUnk_FieldRenderResource_017, gUnk_FieldRenderResource_017 + 4
    .set gUnk_FieldRenderResource_018, gUnk_FieldRenderResource_018 + 4
    .set gUnk_FieldRenderResource_019, gUnk_FieldRenderResource_019 + 4
    .set gUnk_FieldRenderResource_022, gUnk_FieldRenderResource_022 + 4
    .set gUnk_FieldRenderResource_023, gUnk_FieldRenderResource_023 + 4
    .set gUnk_FieldRenderResource_024, gUnk_FieldRenderResource_024 + 4
    .set gUnk_FieldRenderResource_025, gUnk_FieldRenderResource_025 + 4
    .set gUnk_FieldRenderResource_028, gUnk_FieldRenderResource_028 + 4
    .set gUnk_FieldRenderResource_029, gUnk_FieldRenderResource_029 + 4
    .set gUnk_FieldRenderResource_030, gUnk_FieldRenderResource_030 + 4
    .set gUnk_FieldRenderResource_031, gUnk_FieldRenderResource_031 + 4
    .set gUnk_FieldRenderResource_032, gUnk_FieldRenderResource_032 + 4
    .set gUnk_FieldRenderResource_035, gUnk_FieldRenderResource_035 + 4
    .set gUnk_FieldRenderResource_036, gUnk_FieldRenderResource_036 + 4
    .set gUnk_FieldRenderResource_037, gUnk_FieldRenderResource_037 + 4
    .set gUnk_FieldRenderResource_038, gUnk_FieldRenderResource_038 + 4
    .set gUnk_FieldRenderResource_039, gUnk_FieldRenderResource_039 + 4
    .set gUnk_FieldRenderResource_040, gUnk_FieldRenderResource_040 + 4
    .set gUnk_FieldRenderResource_043, gUnk_FieldRenderResource_043 + 4
    .set gUnk_FieldRenderResource_044, gUnk_FieldRenderResource_044 + 4
    .set gUnk_FieldRenderResource_045, gUnk_FieldRenderResource_045 + 4
    .set gUnk_FieldRenderResource_046, gUnk_FieldRenderResource_046 + 4
    .set gUnk_FieldRenderResource_047, gUnk_FieldRenderResource_047 + 4
    .set gUnk_FieldRenderResource_050, gUnk_FieldRenderResource_050 + 4
    .set gUnk_FieldRenderResource_051, gUnk_FieldRenderResource_051 + 4
    .set gUnk_FieldRenderResource_054, gUnk_FieldRenderResource_054 + 4
    .set gUnk_FieldRenderResource_055, gUnk_FieldRenderResource_055 + 4
    .set gUnk_FieldRenderResource_058, gUnk_FieldRenderResource_058 + 4
    .set gUnk_FieldRenderResource_059, gUnk_FieldRenderResource_059 + 4
    .set gUnk_FieldRenderResource_062, gUnk_FieldRenderResource_062 + 4
    .set gUnk_FieldRenderResource_063, gUnk_FieldRenderResource_063 + 4
    .set gUnk_FieldRenderResource_066, gUnk_FieldRenderResource_066 + 4
    .set gUnk_FieldRenderResource_067, gUnk_FieldRenderResource_067 + 4
    .set gUnk_FieldRenderResource_070, gUnk_FieldRenderResource_070 + 4
    .set gUnk_FieldRenderResource_071, gUnk_FieldRenderResource_071 + 4
    .set gUnk_FieldRenderResource_074, gUnk_FieldRenderResource_074 + 4
    .set gUnk_FieldRenderResource_075, gUnk_FieldRenderResource_075 + 4
    .set gUnk_FieldRenderResource_078, gUnk_FieldRenderResource_078 + 4
    .set gUnk_FieldRenderResource_079, gUnk_FieldRenderResource_079 + 4
    .set gUnk_FieldRenderResource_082, gUnk_FieldRenderResource_082 + 4
    .set gUnk_FieldRenderResource_083, gUnk_FieldRenderResource_083 + 4
    .set gUnk_FieldRenderResource_086, gUnk_FieldRenderResource_086 + 4
    .set gUnk_FieldRenderResource_089, gUnk_FieldRenderResource_089 + 4
    .set gUnk_FieldRenderResource_092, gUnk_FieldRenderResource_092 + 4
    .set gUnk_FieldRenderResource_093, gUnk_FieldRenderResource_093 + 4
    .set gUnk_FieldRenderResource_096, gUnk_FieldRenderResource_096 + 4
    .set gUnk_FieldRenderResource_099, gUnk_FieldRenderResource_099 + 4
    .set gUnk_FieldRenderResource_102, gUnk_FieldRenderResource_102 + 4
    .set gUnk_FieldRenderResource_103, gUnk_FieldRenderResource_103 + 4
    .set gUnk_FieldRenderResource_106, gUnk_FieldRenderResource_106 + 4
    .set gUnk_FieldRenderResource_107, gUnk_FieldRenderResource_107 + 4
    .set gUnk_FieldRenderResource_110, gUnk_FieldRenderResource_110 + 4
    .set gUnk_FieldRenderResource_111, gUnk_FieldRenderResource_111 + 4
    .set gUnk_FieldRenderResource_114, gUnk_FieldRenderResource_114 + 4
    .set gUnk_FieldRenderResource_115, gUnk_FieldRenderResource_115 + 4
    .set gUnk_FieldRenderResource_118, gUnk_FieldRenderResource_118 + 4
    .set gUnk_FieldRenderResource_119, gUnk_FieldRenderResource_119 + 4
    .set gUnk_FieldRenderResource_122, gUnk_FieldRenderResource_122 + 4
    .set gUnk_FieldRenderResource_123, gUnk_FieldRenderResource_123 + 4
    .set gUnk_FieldRenderResource_126, gUnk_FieldRenderResource_126 + 4
    .set gUnk_FieldRenderResource_127, gUnk_FieldRenderResource_127 + 4
    .set gUnk_FieldRenderResource_128, gUnk_FieldRenderResource_128 + 4
    .set gUnk_FieldRenderResource_129, gUnk_FieldRenderResource_129 + 4
    .set gUnk_FieldRenderResource_132, gUnk_FieldRenderResource_132 + 4
    .set gUnk_FieldRenderResource_133, gUnk_FieldRenderResource_133 + 4
    .set gUnk_FieldRenderResource_134, gUnk_FieldRenderResource_134 + 4
    .set gUnk_FieldRenderResource_135, gUnk_FieldRenderResource_135 + 4
    .set gUnk_FieldRenderResource_136, gUnk_FieldRenderResource_136 + 4
    .set gUnk_FieldRenderResource_139, gUnk_FieldRenderResource_139 + 4
    .set gUnk_FieldRenderResource_140, gUnk_FieldRenderResource_140 + 4
    .set gUnk_FieldRenderResource_143, gUnk_FieldRenderResource_143 + 4
    .set gUnk_FieldRenderResource_144, gUnk_FieldRenderResource_144 + 4
    .set gUnk_FieldRenderResource_145, gUnk_FieldRenderResource_145 + 4
    .set gUnk_FieldRenderResource_148, gUnk_FieldRenderResource_148 + 4
    .set gUnk_FieldRenderResource_149, gUnk_FieldRenderResource_149 + 4
    .set gUnk_FieldRenderResource_150, gUnk_FieldRenderResource_150 + 4
    .set gUnk_FieldRenderResource_151, gUnk_FieldRenderResource_151 + 4
    .set gUnk_FieldRenderResource_154, gUnk_FieldRenderResource_154 + 4
    .set gUnk_FieldRenderResource_157, gUnk_FieldRenderResource_157 + 4
    .set gUnk_FieldRenderResource_160, gUnk_FieldRenderResource_160 + 4
    .set gUnk_FieldRenderResource_163, gUnk_FieldRenderResource_163 + 4
    .set gUnk_FieldRenderResource_166, gUnk_FieldRenderResource_166 + 4
    .set gUnk_FieldRenderResource_169, gUnk_FieldRenderResource_169 + 4
    .set gUnk_FieldRenderResource_170, gUnk_FieldRenderResource_170 + 4
    .set gUnk_FieldRenderResource_173, gUnk_FieldRenderResource_173 + 4
    .set gUnk_FieldRenderResource_176, gUnk_FieldRenderResource_176 + 4
    .set gUnk_FieldRenderResource_179, gUnk_FieldRenderResource_179 + 4
    .set gUnk_FieldRenderResource_182, gUnk_FieldRenderResource_182 + 4
    .set gUnk_FieldRenderResource_183, gUnk_FieldRenderResource_183 + 4
    .set gUnk_FieldRenderResource_186, gUnk_FieldRenderResource_186 + 4
    .set gUnk_FieldRenderResource_187, gUnk_FieldRenderResource_187 + 4
    .set gUnk_FieldRenderResource_190, gUnk_FieldRenderResource_190 + 4
    .set gUnk_FieldRenderResource_191, gUnk_FieldRenderResource_191 + 4
    .set gUnk_FieldRenderResource_194, gUnk_FieldRenderResource_194 + 4
    .set gUnk_FieldRenderResource_195, gUnk_FieldRenderResource_195 + 4
    .set gUnk_FieldRenderResource_198, gUnk_FieldRenderResource_198 + 4
    .set gUnk_FieldRenderResource_199, gUnk_FieldRenderResource_199 + 4
    .set gUnk_FieldRenderResource_202, gUnk_FieldRenderResource_202 + 4
    .set gUnk_FieldRenderResource_203, gUnk_FieldRenderResource_203 + 4
    .set gUnk_FieldRenderResource_206, gUnk_FieldRenderResource_206 + 4
    .set gUnk_FieldRenderResource_207, gUnk_FieldRenderResource_207 + 4
    .set gUnk_FieldRenderResource_210, gUnk_FieldRenderResource_210 + 4
    .set gUnk_FieldRenderResource_211, gUnk_FieldRenderResource_211 + 4
    .set gUnk_FieldRenderResource_214, gUnk_FieldRenderResource_214 + 4
    .set gUnk_FieldRenderResource_215, gUnk_FieldRenderResource_215 + 4
    .set gUnk_FieldRenderResource_218, gUnk_FieldRenderResource_218 + 4
    .set gUnk_FieldRenderResource_219, gUnk_FieldRenderResource_219 + 4
    .set gUnk_FieldRenderResource_222, gUnk_FieldRenderResource_222 + 4
    .set gUnk_FieldRenderResource_223, gUnk_FieldRenderResource_223 + 4
    .set gUnk_FieldRenderResource_224, gUnk_FieldRenderResource_224 + 4
    .set gUnk_FieldRenderResource_225, gUnk_FieldRenderResource_225 + 4
    .set gUnk_FieldRenderResource_226, gUnk_FieldRenderResource_226 + 4
    .set gUnk_FieldRenderResource_227, gUnk_FieldRenderResource_227 + 4
    .endif
