# MapData visual resources

> Build-workflow update (2026-10-04): The old per-family `gfx-*` targets
> and Python extraction, preview, and inventory helpers have been retired.
> Their audit observations below are retained as historical evidence, not as
> current build instructions. Assets are generated beside authored sources
> and included at link time; see the [current workflow](../README.md).
> Removed helpers can be recovered from Git revision `31411d1d` if an old
> audit must be reproduced. Normal builds do not read baserom or patch ROMs.

The first physically continuous MapData stream run is now linked from this
source tree, not copied from a ROM after linking. Its 42 streams are identical
in JP, US, EU, and DE and occupy these verified half-open ranges:

| Region | Start | End |
| --- | ---: | ---: |
| JP | `0x400244` | `0x41DA7C` |
| US | `0x67A0E8` | `0x697920` |
| EU | `0x67A144` | `0x69797C` |
| DE | `0x401184` | `0x41E9BC` |

`shared/map_data.inc` lists the real ROM order and labels. The ordinary
Make rules convert seven editable PNG tile sets to `.4bpp`, eleven editable
JASC palettes to `.gbapal`, and then use the shared `tools/fomt-lz` codec to
make the source-adjacent `.lz` files. The other 24 sources are native u16
`.tilemap` files, preserving tile indices, flip flags, and palette banks.
All forty-two streams now encode directly from their tile, palette or tilemap
sources. These include map `08` layers `1`/`2`, map `09` layers `1`/`2`/`5`, and map `31`
layer `5`, plus map `44` and `45` layer `5` with the codec's 16-bit differential
filter. The same filter also directly encodes Raw-LZ2 tilemaps: map `08`
layers `4`/`5`, map `09` layer `4`, map `31` layer `4`, and maps `44`/`45`
layer `4`. The Raw-LZ0 map `15` and `36` layer `1` palettes use the same C
codec's retail greedy command strategy. Another ten map palettes and tilemaps
use the codec's Huffman-4/LZ3 greedy path with explicit same-frequency leaf
ordering. Map `09` layer `3` and map `40` layer `4` additionally use the generic
`--parent-first` Huffman tie policy: an internal subtree is merged before an
equally weighted leaf. This derives the tree from current literal frequencies;
it does not copy a tree or command stream from a reference file.
Map `08`, `09`, `14`, `36`, `44`, and `53` layer `0` tiles now also use
source-only Huffman-8/LZ3 with `--greedy --tie=exchange`; all but `36` apply
the verified four-bit differential filter. The six obsolete packing templates
are removed. Map `14` layer `3`, and map `15` layers `0` and `3`, now use the
same source-only Huffman-8/LZ3 policy. Its canonical leaves must be exchange-
sorted by depth after frequency sorting, not simply grouped stably by depth.
The computed depths remain unchanged. These three final templates are removed,
and all 42 direct encoders match the complete retail bytes. Retained `.original.lz` samples
for those streams are audit copies, not build inputs.

None of these 42 streams requires original packing metadata as a build input.
No normal build reads `baserom`.
Nonzero compressor slots reject oversize output; slot zero uses the natural
compressed length. The existing ROM link boundaries and unresolved references
still constrain growth. Native decoder checks and complete four-region ROM
comparisons verify output; they do not prove arbitrary layout changes safe.

这段连续地图资源共 42 份，现已全部独立从源码编码。最后三份
map_14/layer_3、map_15/layer_0 和 map_15/layer_3 复用通用编码器，
由当前频率建树，规范码再按深度交换排序，未添加资源专用排列或
补丁。三份旧模板移除；该批只覆盖 42 份，后续资源的当前进度见下方。

## Next source-backed block: map 00

The six visual streams for map `00` now use the same source-adjacent build
workflow. Their physical order is `0, 1, 3, 4, 5, 2`, not the pointer-field
order. The complete block contains 19,036 packed bytes and 101,312 decoded
bytes, identical in all four regions:

| Region | Start | End |
| --- | ---: | ---: |
| JP | `0x42188C` | `0x4262E8` |
| US | `0x69B730` | `0x6A018C` |
| EU | `0x69B78C` | `0x6A01E8` |
| DE | `0x4227CC` | `0x427228` |

`map_00/layer_0.png` is an indexed 128-by-512 native tile atlas. Its first
palette bank previews the tile indices only; the final map's palette-bank
selection and composition remain in its independent tilemaps. Both 240-colour
palettes are authored separately as `layer_1.pal` and `layer_2.pal`, never
derived from the tile PNG. The existing three `.tilemap` files remain native
u16 map records. The old tracked `.4bpp` and `.gbapal` files are now generated
artifacts, using the normal gbagfx suffix rules.

Raw/Huffman LZ2/LZ3, differential filters and frequency-derived Huffman tie
policies all use the existing C encoder. Every natural packed output already
matches the original; no original stream is a build input or a packing
template. Each stream retains its verified storage budget so an oversize edit
fails before shifting unresolved neighbors. All six real payload labels are
defined directly at their first byte, removing the JP/US base-offset bindings
and EU `+4` `.set` adjustments for this block. No new input section, helper
manifest or link-time patch was added.

The `.lz` suffix rule now builds the outputs discovered from source references,
without a second list of output filenames. Only the necessary codec parameters
are target metadata; missing parameters are an explicit build error. PNG/PAL
byte round trips and three edits per decoded source verify the source path.
All twelve occurrences of these six payload-start pointers in each complete
ROM correspond exactly to `map_data.o`'s `R_ARM_ABS32` relocations. Complete
JP/US/EU/DE WSL `-j4` builds, byte comparisons and SHA-1 checks pass. This
pointer audit covers this block only, not the remaining raw streams.

## Following continuous run: shared and interleaved map resources

The next physical run contains 98 distinct streams, 157,588 packed bytes and
687,704 decoded bytes. All four regions contain the same complete stream
bytes, bounded by the existing DE physical payload labels and verified against
the other regions, rather than guessed from successive map numbers:

| Region | Start | End |
| --- | ---: | ---: |
| JP | `0x4262E8` | `0x44CA7C` |
| US | `0x6A018C` | `0x6C6920` |
| EU | `0x6A01E8` | `0x6C697C` |
| DE | `0x427228` | `0x44D9BC` |

Map `01` immediately follows map `00`. Maps `10`/`12` and `11`/`13` share
tiles and palettes, but their individual tilemaps occupy different positions
inside this larger run. Other maps share tiles or use the same palette in both
palette fields. Each unique payload keeps one physical label and one source;
the common `gMapData` table continues to reference it directly. No duplicate
asset, artificial alias, new archive manifest or additional section is needed.

Ten new 128-by-512 indexed PNG atlases preserve native tile indices. Thirteen
independent 240-colour JASC `.pal` files preserve the complete BGR555 palettes;
the PNGs preview only the first palette bank. The other 75 existing `.tilemap`
files remain native u16 records. The 23 old tracked `.4bpp`/`.gbapal` inputs
are now ignored generated files, all with byte-identical PNG/PAL round trips.
The existing suffix rules and dependency scanner discover every new `.lz`
reference; only ordinary codec parameters are added as target metadata.

All 98 natural encodings already match the retail bytes without slot padding,
original Huffman tables or packing templates. Raw/Huffman LZ0/LZ2/LZ3 and
four-bit/16-bit differential filters reuse the existing C tool and its generic
frequency-derived tie policies. Three source mutations per stream, 294 checks
in total, encode and decode losslessly. Verified original storage budgets still
reject oversize edits before shifting unresolved neighboring resources.

The JP/US base-offset definitions and EU `+4` adjustments are removed: 294
`.set` aliases become real labels at the first payload byte in the original
assembly positions. Each region has 141 actual payload-start pointer references,
all matching `map_data.o`'s real `R_ARM_ABS32` relocations. The whole-ROM word
scan also finds three non-pointer coincidences: US `0x231612` lies among
`gM4aWaveData_073`'s signed PCM samples; DE `0xCFCD3` and `0xCFDD3` straddle
the reachable Thumb sequence `ldr r0,[sp,#32]; add r0,r8; ldr r1,[sp,#32]`
inside `func_080CFC7C`. These sample/instruction bytes are not patched.

Full JP/US/EU/DE WSL `-j4` builds, complete-ROM byte/SHA-1 comparisons and
actual generated-asset dependency checks pass. This audit covers the selected
98 streams; it does not prove interior pointer references or the remaining raw
resources safe for arbitrary relocation.

At that stage, these three blocks covered 146 of `gMapData`'s 272 distinct
visual streams. The other 126 had not yet joined the complete editable
pipeline: some were explicit assembly bytes, some were slices of a legacy
binary container, and one already reused a source-generated UI tile stream.
The first 42-stream run ends before a separate VRAM resource; treating all
272 pointers as one uninterrupted archive would overwrite unrelated data.
The final source-backed coverage and actual intervening gaps are below.

MapData fields 6 and 7 are terrain/interaction data, not image inputs.

## Complete visual-source coverage: 272 distinct streams

The last 126 streams now use the same generic source-adjacent workflow. They
contain 221,508 packed bytes and 985,136 decoded bytes, identical in all four
regions. Their nine separate physical runs retain every intervening resource
and byte; the complete regional address ranges are recorded in
`CODE_ROM_LAYOUT.md`. Their physical order does not follow map IDs.

Thirteen indexed 128-by-512 PNG atlases and 21 independent 240-colour PAL
sources replace tracked converter outputs; 92 existing u16 tilemaps keep their
native tile/flip/palette records. PNG palette previews show only the first
bank, not a reconstructed complete scene. Map `02` shares its tiles with
`gUiScene080B55D0MainTilesLz`, so both callers use the existing UI source path
`graphics/ui/scene_080b55d0_main/shared/main_tiles.png`. No duplicate tile
asset or new resource-specific tool is introduced.

All natural encodings already match the original bytes. Necessary ladder,
filter, tie and storage-budget parameters are target metadata for the existing
C compressor, not lists of per-resource build recipes. Every `.lz` dependency
is discovered from its direct assembly reference. The complete 272-stream
graph was force-built from its authored PNG/PAL/native-map inputs; no original
ROM, `.original.lz`, packing template or post-link patch is a build input.

The selected JP/US base-offset definitions and EU `+4` adjustments are gone:
378 `.set` definitions become real physical labels. Equal bytes at the three
distinct starts `gUnk_MapDataResource_341`, `_356` and `_366` keep three distinct
resources; content equality does not imply pointer identity. Whole-ROM
relocation inspection confirms 170 actual start references per region,
including the existing UI caller. JP `0xD683` crosses `ldrh; ldr; ands`, and DE
`0xD2719` crosses `beq; ldr; ldrb`; those two unaligned byte coincidences are
instructions, not pointers. Interior references and unresolved neighboring
data remain outside that start-pointer claim.

The former `map_state_palette_templates.bin` was not one giant uncompressed
palette table: its first `0x60` bytes remain explicit native data, followed by
25 of these compressed streams. The aggregate binary is no longer needed.
The separate legacy tilemap container remains unresolved native data and is
not included in this visual-source completion count. The assembly also drops
233 region conditionals contradicted by their enclosing region, including
unused old DE copies, without changing any regional ROM bytes.

Region-filtered dependency checks also exposed the earlier 42-stream DE run
at `0x08401184..0x0841E9BC`: its 120,888 bytes were still raw copies despite
the common source manifest. Those DE bodies now reference the same existing
42 generated streams directly, retaining all physical labels. Completion is
checked against each region's actual dependency graph and real symbols, not
against inactive branches' paths. The existing C++ scaninc accepts generic
`-D`/`-U` known symbols and conservatively retains unknown conditions; 47
regression checks, including 32 comparisons with real GAS dependencies, pass.

All 34 PNG/PAL byte round trips and 378 modified-source encode/decode checks
pass. JP/US/EU/DE WSL `-j4` builds, complete byte/SHA-1 comparisons and actual
dependency checks pass. **272/272 covers only MapData's visual inputs**, not
all FoMT graphics, terrain data or C/C++ function decompilation. Verified
storage budgets still reject oversize edits before shifting unknown neighbors.
