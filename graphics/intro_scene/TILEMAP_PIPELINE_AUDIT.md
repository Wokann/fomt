# Childhood story background tilemap audit

## Correction of the earlier OBJ classification

The earlier `OBJECT_PIPELINE_AUDIT.md` correctly established the twenty
`0x500`-byte RAM slots, but incorrectly connected their consumer to the OAM
emitter. That OBJ/4bpp interpretation is superseded by the complete consumer
trace below. The old note and PNGs remain recoverable at Git revision
`8b4dd1db`; they are not the current authoring format.

A `70 00 05 00` stream header establishes a decoded length, not a pixel
format. Treating its 1,280 bytes as forty 4bpp tiles happened to round-trip
losslessly, but did not prove that those bytes were pixels.

## Loading and actual consumers

`InitializeIntroStoryGraphics` starts at `scene + 0x20`, calls `Unpack`
twenty times and advances the destination by `0x500` each time. Its source
table is now `gIntroStoryTilemapSources[10][2]`, with BG3 then BG2 in each
row. These are the existing twenty pointers in unchanged physical order.

`RunIntroStorySceneCore` supplies the missing consumer evidence. Its transfer
phase queues two `DmaTransferDescriptor` copies:

| Source slot | Destination | Byte count | Consumer |
| --- | --- | ---: | --- |
| selected even slot | `0x0600F000` | `0x500` | BG3 screen block 30 |
| following odd slot | `0x0600E800` | `0x500` | BG2 screen block 29 |

Initialization writes BG3CNT `0x1E43` and BG2CNT `0x1D42` into the verified
display-state halfwords at `+0x0E` and `+0x0C`. Both select character block
zero and the screen blocks above. The transfer addresses are not OBJ VRAM
at `0x06010000`. UI updates may emit sprites, but that does not make these
two background-map transfers part of an OAM pipeline.

Each payload holds `20 * 32` little-endian halfwords: twenty rows at the
32-column BG screen-block stride. A halfword retains its tile index, flip
bits and palette-bank bits. Blank map entries select tile 1023; the same
initialization path explicitly clears its 32-byte character slot at
`0x06007FE0`. The separate background tiles and palette sources remain
separate resources.

## Source and RAM layout

The maintained sources are now:

```text
shared/tilemaps/frame_00_bg3.tilemap
shared/tilemaps/frame_00_bg2.tilemap
...
shared/tilemaps/frame_09_bg3.tilemap
shared/tilemaps/frame_09_bg2.tilemap
```

These are native row-major tilemap data, not grayscale pixel atlases. The
frame number records the paired source-bank order, not a guessed character
identity or animation timing. Labels use the corresponding
`gIntroStoryFrame00Bg3Tilemap` / `gIntroStoryFrame00Bg2Tilemap` convention.

The same-named scene header represents the actual runtime storage as
`u16 background_tilemaps[20][20][32]` at `+0x20`. Each map occupies `0x500`
bytes, all maps occupy `0x6400`, and the complete native context remains
`0x6430` bytes. Initialization still leaves this storage untouched before
unpacking. Size and offset checks guard these contracts.

## Build and verification

The existing generic `.lz` suffix rule invokes the C `fomt-lz` tool directly
from each `.tilemap`. Original Raw-LZ1/2/3 variants, search ladders and packed
capacities are unchanged target metadata. The generated `.tilemap.lz` lives
beside its authoring source and is included directly by ROM assembly. No new
converter, image compositor, JSON sidecar, ROM extractor or post-link patch
is involved in the formal build.

Migration uses the existing C decoder on the already source-built streams.
Each result is independently checked against a fresh gbagfx conversion of
the previous PNG, and against the previous decoded bytes. It does not read a
base ROM to create authoring data. Rebuilt compressed streams must retain
their original bytes, and the four complete ROM builds must still match.

After four-region verification, the obsolete twenty PNG atlases and their
forty generated `.4bpp`/`.lz` cache files were removed. They did not carry
additional palette, tilemap or OAM information absent from the native maps.

## Remaining scope

The opening/title scene's regional `IndexedResourceArchive` is a different
resource family, documented in `README.md`. Its verified OAM pieces must not
be assigned to these twenty BG maps.

The main childhood loop remains native while its complete ordinary-C++
candidate is unmatched. This correction does not count any new C++ bytes or
claim that the remaining scene hierarchy, scheduling or final-screen
composition has been recovered. It corrects the source format and the
runtime data type from direct consumer evidence.
