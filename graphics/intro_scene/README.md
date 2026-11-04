# Intro Scene graphics

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

`shared/background_tiles.png` and `shared/background_palettes.pal` are the
authoritative editable sources for the decoded linear 4bpp Intro Scene VRAM
payload and its three BGR555 palette banks.

The checked source represents the native tile order. It is not a guessed final
screen layout: other Intro Scene resources, palette choices, display registers
and possible composition remain distinct runtime data. The C tools rebuild
the 4bpp tiles and their `0x70` Raw-LZ2 stream directly from the PNG. The
`--literal-tail` encoder strategy reproduces the three final retail literal
commands, so the resulting 0x49BC-byte stream matches the original byte for
byte without reading it during the build. The old original-stream copy has been removed.
`gbagfx` and `fomt-lz` generate adjacent `.4bpp` and `.4bpp.lz` files;
assembly includes the latter directly, without a baserom build dependency or
a `.0x70` pseudo-extension.
The packed stream occupies 0x49BC bytes at JP 0x4C91C0, US 0x743058,
EU 0x7430B4, and DE 0x4CA4CC.

`shared/tilemaps/frame_00_bg3.tilemap` through `frame_09_bg2.tilemap` are
twenty native 32-column, 20-row BG tilemaps for the childhood story. The
loader stages each `0x500`-byte map in RAM; the main loop then queues paired
maps to BG3 screen block 30 and BG2 screen block 29. The former PNG/4bpp/OBJ
classification was incorrect: an unpacked byte count alone did not establish
a pixel format. `TILEMAP_PIPELINE_AUDIT.md` records the actual consumers and
the correction.

The ordinary `.lz` suffix rule packs these map sources with the existing C
compressor, preserving each original Raw-LZ1/2/3 profile, ladder and capacity.
Assembly directly includes the generated `.tilemap.lz` files. All twenty
decoded and compressed payloads are identical in JP, US, EU and DE; no new
tool, source sidecar, ROM input or post-link patch is required.

## Regional indexed OAM archive

`ConstructIntroSceneCore` expands an `IndexedResourceArchive` following the
background tiles and palettes. Unlike the twenty BG tilemap streams, this
archive contains a complete native frame layout: animation selectors, 16-byte
frame descriptors, eight-byte GBA OAM records, mixed-depth tiles, BGR555 palettes,
and frame entries. The data proves complete OAM-composited PNG frames without
inventing a layout sidecar.

Each of `indexed_archive/jp/`, `us_eu/`, and `de/` contains the actual
regional sources. `title_tiles.png` stores 8bpp title tiles; `frame_tiles.png`
stores 4bpp frame tiles. The OAM color-depth bit verifies the split. This
replaces the old mixed-depth atlas incorrectly presented as a single 4bpp
image. Every physical tile, including hidden and shared pixels, is retained.
The PNG palette used to preview the title is not a palette compilation input.

Independent `palettes_00_15.pal` and `palettes_16_17.pal` (JP) or
`palettes_16_18.pal` (overseas) preserve the counted palette table, including
its indexed zero banks. Ordinary gbagfx suffix rules generate adjacent
`.8bpp`, `.4bpp`, and `.gbapal` files. The final image-grid cells and palette
file sizes are controlled by the verified native counts, not extra ROM padding.

The native seven-table layout remains in each group's `archive.inc`. It
includes title tiles, frame tiles, then palettes in their physical order;
descriptors without drawable OAM remain ordinary records. An assembly object
under `build/` produces the source-adjacent decoded `archive.bin`; the
compressed resource is `archive.bin.lz`, directly included by ROM assembly.
The seven counts are computed from table boundary labels. The assembler checks
record widths and the shared `INTRO_SCENE_RESOURCE_CAPACITY` from
`include/intro_scene.hh`; decoded data must fit the actual C++ buffer.
There is no Python frame overlay, duplicate decoded-edit stage, baserom
extraction, or post-link patch in this archive's normal build.

JP's `120` Huffman-4/LZ2 stream is now encoded directly from `archive.bin` by
the generic C `encode-huff4-lz2` command. Its greedy matches, literal grouping,
and frequency-derived Huffman tree reproduce all `0x2D90` retail bytes.
The command verifies its decoded output and rejects packed-slot overflow.
The old original-stream copy has been removed.

US/EU and DE use `220` Huffman-8/LZ2. Their authoring and assembly paths are
the same; `encode-huff8-lz2` now reproduces their complete packed bytes with
ladder `3,6,8,10,11,13,15` and the generic `--tie=exchange` policy. Both old
`archive.original.lz` inputs are removed. All regional archive outputs use the
same shared `.lz` recipe; only the real seven-table composition needs an
explicit assembly-to-binary rule. The overseas encoders use slot zero rather
than fixed-size padding. Three changed-source fixtures per group also pass
native decode checks; the normal four-region ROM builds match every byte.

三种开场归档均由实际七表源码、图块 PNG 和独立 PAL 编译为 `archive.bin`，
再通过共享压缩规则生成 `archive.bin.lz`。US/EU 和 DE 的 Huffman-8/LZ2
已使用通用交换排序策略独立匹配，旧模板移除；不新增归档重建脚本或补丁。

| Source group | ROM start | Packed size | 8bpp title tiles | 4bpp frame tiles |
| --- | --- | ---: | ---: | ---: |
| JP | `0x084CDBDC` | `0x2D90` | 361 | 88 |
| US/EU | US `0x08747A74`, EU `0x08747AD0` | `0x2764` | 237 | 95 |
| DE | `0x084CEEE8` | `0x275C` | 237 | 97 |

The archive's tile count measures 32-byte OBJ units: an 8bpp tile occupies
two units. Its unchanged total counts therefore remain 810, 569, and 571.
`full/` holds nine JP or eight overseas OAM-composited reference images, not
a second set of authoring inputs. `runtime_obj_palette.gbapal` is likewise
a captured display reference; its low banks are loaded outside this archive.

The ROM starts above are written with the GBA `0x08000000` base; the equivalent
file offsets are `0x4CDBDC`, `0x747A74`, `0x747AD0`, and `0x4CEEE8`.

The same initializer also consumes `small_indexed_archive/shared/full/`: a
separate, raw `0x118`-byte archive with three complete 16-by-16 OAM frames.
Its native bytes are identical in JP, US, EU, and DE. All three views share
the same four native tiles and palette; their original PNG exports were
byte-for-byte duplicates. The ordinary C `gbagfx` rules compile tiles from
`frame_0000.png` and the palette from the independent `frame_0000.pal`. The selection, descriptor,
OAM, and animation records are written directly in the assembly source;
there is no ROM-template rebuild or post-link patch for this archive.

## Startup background layers

`InitializeIntroSceneSequenceResources` additionally expands a shared `0x8000`-byte 4bpp tile payload,
loads sixteen BGR555 palette banks, and then uses the four native startup-map
sources.  The tiles and palette banks are verified byte-identically against
the JP, US, EU and DE ROMs and are available under
`shared/startup_visual/`.

`shared/startup_tilemaps/bg0.tilemap` through `bg3.tilemap`
remain the authoritative editable layout sources.  Each `0x1000`-byte source
contains two 32-by-32 BG maps in alternating 0x40-byte rows.  The eight PNGs
under `reference/startup/` were rendered from that proven row split, tile IDs,
flip bits and palette-bank fields; they are visual references only, because a
flat PNG cannot preserve those native map fields.

The C `fomt-lz` tool builds each `bgN.tilemap.lz` beside its editable
`.tilemap`; assembly includes that generated stream directly. All four maps
encode directly from source with exact retail packed bytes. `bg0` uses
the codec's generic `--parent-first` Huffman tie policy, while `bg3` uses
`--tie=quick`; neither reads a saved tree or original packing metadata.
Neither the resource build nor the link reads a retail ROM or patches the
finished image.

`InitializeIntroSceneSequenceResources` writes the two maps from each source to fixed VRAM screen
blocks. This is a proven storage relationship, not an assertion about which
map is visible at a particular point in the scene:

| Editable source | First 32x32 map | Second 32x32 map |
| --- | --- | --- |
| `bg0.tilemap` | screen block 24 (`0x0600C000`) | screen block 25 (`0x0600C800`) |
| `bg1.tilemap` | screen block 26 (`0x0600D000`) | screen block 27 (`0x0600D800`) |
| `bg2.tilemap` | screen block 28 (`0x0600E000`) | screen block 29 (`0x0600E800`) |
| `bg3.tilemap` | screen block 30 (`0x0600F000`) | screen block 31 (`0x0600F800`) |

For each of the 32 rows, the first `0x40` bytes of the source's `0x80`-byte
row go to the first screen block and the next `0x40` bytes go to the second.
The checked-in `.tilemap` files deliberately preserve this decoded native
interleaving; the rendered layer PNGs must not replace them as source data.

The startup tile payload uses the `230` Huffman-8/LZ3 family. `gbagfx` converts
the tile PNG and independent palette PAL into adjacent `.4bpp` and `.gbapal` resources;
the C `fomt-lz` tool directly packs the tiles into `.4bpp.lz`, using ladder
`5,10,14` and `--greedy --tie=exchange`. The complete 14704-byte retail stream
matches without output-size padding; `startup_tiles.original.lz` is removed.
Three edited tile sources decode exactly. The compressor uses natural output
length; the existing ROM bounds and unresolved references still constrain
growth. Assembly links these generated resources directly,
without reading a ROM or patching the linked image. The native startup maps
remain independently editable through their Huffman-4/LZ3 path.

启动图块、四张启动地图和各地区开场索引归档均从现有源码与独立资源生成，
不再依赖原始压缩流模板；区域归档的内部索引及运行时容量仍受实际格式约束。
