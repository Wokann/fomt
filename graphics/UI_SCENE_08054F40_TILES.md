# Frisbee background resources

`Run__11FrisbeeCore` calls the background loader (`func_08054F40` in US,
`loc_08054CD0` in JP). The six adjacent objects have the same bytes in all
four regions. The native loader and the later DMA queue establish the formats
below; these are not inferred from the appearance of a ROM byte dump.

The source directory is `ui/scene_08054f40_tiles/shared/`. The standard
`graphics_file_rules.mk` rules convert PAL to GBAPAL and PNG to 4bpp, then
compress the maps and tiles beside their sources. No baseline ROM is read
during a build. The existing static `tiles.4bpp` source is unchanged.

| Source | Symbol | ROM bytes | Decoded layout and use |
| --- | --- | ---: | --- |
| `background.tilemap` | `gFrisbeeBackgroundTilemap` | 496 | 32 × 20 u16 BG entries; 1280 bytes to BG3 at `0600E000`, first 192 bytes also to BG2 at `0600E800` |
| `overlay.tilemap` | `gFrisbeeOverlayTilemap` | 40 | 32 × 20 u16 entries, unpacked to the mutable map at core + `1D5A` |
| `overlay_top.tilemap` | `gFrisbeeOverlayTopTilemap` | 44 | 32 × 5 u16 entries, overwrites the first five rows of that same map |
| `tiles.4bpp` | `gBeachBackgroundTiles` | 3240 | 328 static 4bpp tiles, directly unpacked to `06000000` |
| `palettes.pal` | `gFrisbeeBackgroundPalettes` | 160 | Five 16-color BGR555 palette banks |
| `animation.png` | `gFrisbeeBackgroundAnimationTiles` | 3204 | Four consecutive frames of 48 4bpp tiles (6144 decoded bytes) |

The animation is unpacked at core + `0558`. The update code advances its
frame index with `(frame + 1) & 3` and queues `0x600` bytes from
`core + 0558 + frame * 0x600` to `06000000`. The PNG displays four frames
vertically, eight tiles per row; it preserves native tile order.

The overlay updater writes palette-bank-3 tile entries and queues the complete
1280-byte mutable map to `0600F000` (BG1). The three recovered source maps use
banks 0 through 4. The base map's tile `03FF` points to the 32-byte blank tile
explicitly cleared at `06007FE0` by the loader.

## Original cross-resource palette read

The loader passes **512 bytes**, not 512 colors, to `CopyHardwareDma3`.
The real palette occupies only 160 bytes. Therefore the native transfer also
copies the first 352 bytes of the immediately following packed animation to
BG palette banks 5 through 15. Both JP and overseas instructions retain this
behavior. The source labels are real relocations, and the two resources remain
adjacent; no aliases, duplicated padding palette, or post-link fix is used.

The PAL source deliberately contains only the 80 actual colors. Do not expand
it to 256 colors or independently separate these objects on the assumption
that the original transfer has that source extent. The recovered maps and
gauge writes do not use banks 5–15, but that observation does not by itself
authorize changing the native copy length. Native frame counts, map geometry,
palette-bank indices and current compression slots remain format limits.

## Physical order

The following are half-open ranges, including all six resources above:

| Region | Resource group | Palette | Packed animation |
| --- | --- | --- | --- |
| JP | `084BEC40–084C0850` | `084BFB2C–084BFBCC` | `084BFBCC–084C0850` |
| US | `08738AD8–0873A6E8` | `087399C4–08739A64` | `08739A64–0873A6E8` |
| EU | `08738B34–0873A744` | `08739A20–08739AC0` | `08739AC0–0873A744` |
| DE | `084BFE44–084C1A54` | `084C0D30–084C0DD0` | `084C0DD0–084C1A54` |

The preexisting `reference/base_layer_3.png` and `reference/screen.png` show
only the static beach layer, not the complete live Frisbee scene.

Validation status is recorded with the consolidated four-region audit in
[`../RELOCATION_AUDIT.md`](../RELOCATION_AUDIT.md).
