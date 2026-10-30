# Shared UI number glyph tiles

`tiles.png` is the editable indexed source for `gUiNumberGlyphTiles`.
The 112 x 8 atlas contains fourteen consecutive native 8 x 8, 4bpp tiles:
digits 0-9 followed by the four remaining native UI tiles. The one-row atlas
retains character-RAM tile-index order; it does not invent a BG screen map.

The ordinary `%.4bpp: %.png` rule in `graphics_file_rules.mk` generates
`tiles.4bpp` beside the PNG. Existing assembly includes that generated file
at its original physical point. No resource-specific Make recipe, Python
builder, ROM input or post-link patch is involved. A PNG -> 4bpp conversion
reproduces all 448 original bytes, including the final native tile that one
native caller does not request.

The embedded PNG palette previews the existing shared scene palette at
`graphics/ui/scene_08077810/shared/tiles.pal`. Runtime palette ownership stays
with that scene/caller, including its transparent/background color changes.
The 4bpp converter reads the indexed pixels, not the preview RGB colors;
edit the actual PAL source when changing runtime colors. No palette copy
is introduced for this shared atlas.

The quantity selector copies the full atlas to BG slot `0x024`, the Earnings
Report to slot `0x150`; cooking routines also use this same record, including
one leading `0x1A0`-byte copy. Those native callers retain their original
tile counts and offsets. Pixel edits preserve this fourteen-tile layout;
changing the count or reordering glyphs also requires updating the users.

| Region | ROM address | Bytes |
| --- | --- | --- |
| JP | `0x084D6C38` | 448 |
| US | `0x08750C8C` | 448 |
| EU | `0x08750CE8` | 448 |
| DE | `0x084D81A8` | 448 |

All four regions share the same source. Native SHA-256:
`2b7c39eab1900bb410cced0daa2ffd21055045e47ddcf99f318255775e77ec4f`.
The old address label `gUnk_08750C8C` is replaced directly, without an alias.
