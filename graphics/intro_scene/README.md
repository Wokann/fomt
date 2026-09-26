# Intro Scene graphics

`shared/background_tiles.png` and `shared/background_palettes.png` are the
authoritative editable sources for the decoded linear 4bpp Intro Scene VRAM
payload and its three BGR555 palette banks.

The checked source represents the native tile order. It is not a guessed final
screen layout: other Intro Scene resources, palette choices, display registers
and possible composition remain distinct runtime data. The original stream is
used byte-for-byte when source pixels are unchanged. Edited tiles are rebuilt
to 4bpp, encoded into a valid `0x70` stream, strictly decoded, and rejected if
they do not fit the original 0x49BC-byte allocation.
The checked-in `shared/background_tiles.original.lz` supplies that native
slot reference. C `gbagfx` and `fomt-lz` generate adjacent `.4bpp` and
`.4bpp.lz` files from the PNG; assembly includes the latter directly,
without a baserom build dependency or a `.0x70` pseudo-extension.
The packed stream occupies 0x49BC bytes at JP 0x4C91C0, US 0x743058,
EU 0x7430B4, and DE 0x4CA4CC.

`shared/object_tiles/object_00.4bpp` through `object_19.4bpp` are the twenty
additional streams loaded by the same routine. Each decodes to exactly `0x500`
bytes and is copied into the intro object's tile staging area before the
runtime object code uploads it to OBJ VRAM. All twenty packed streams and
decoded payloads are byte-identical in JP, US, EU and DE.

They are intentionally checked in as native 4bpp tile sources, not fabricated
full-image PNGs: their OAM composition and per-object palette selection are
still runtime data and have not yet been independently reconstructed. This is
an editable and lossless source representation without a JSON layout sidecar;
it is also the appropriate input for a later verified OAM/full-PNG tool.

`OBJECT_PIPELINE_AUDIT.md` records the code-backed boundary: the twenty
streams are a fixed VRAM loading sequence, while the scene's actual frame,
OAM-piece and palette selection come from runtime indexed-resource handles.

```console
make gfx-intro-objects-all
```

The eleven Raw-LZ3 objects `01`, `03`, `05`, `07`, `08`, `09`, `11`, `12`,
`14`, `17`, and `19` are encoded directly by the C compressor from their
`.4bpp` sources. Each rebuilt packed slot matches the retail bytes exactly;
the corresponding `.original.lz` files are retained only for independent
comparison, not read by these build rules. The other nine objects still use
their source-adjacent original streams to preserve byte-exact output until
their packing modes are independently reproduced. Edited streams are decoded
for verification and rejected if they exceed their original packed slots.
Assembly includes the generated `.4bpp.lz` files directly.

## Regional indexed OAM archive

`func_08000914` separately expands an `IndexedResourceArchive` immediately
after the background stream. Unlike the twenty object-tile streams, this
archive contains a complete native frame layout: animation selectors, 16-byte
frame descriptors, eight-byte GBA OAM records, 4bpp tiles, BGR555 palettes,
and frame entries. The data proves complete OAM-composited PNG frames without
inventing a layout sidecar.

The authoritative PNG sources follow the actual localization layouts:

- `indexed_archive/jp/full/` has nine drawable JP frames;
- `indexed_archive/us_eu/full/` has eight shared US/EU frames; and
- `indexed_archive/de/full/` has eight DE frames.

Each archive also selects two descriptors without drawable OAM. They have no
fabricated blank PNG; their unchanged table data remains in the source archive.
The native seven-table layout is authored in `jp/archive.inc`,
`us_eu/archive.inc`, and `de/archive.inc`. Each layout includes its group's
`native_tiles.4bpp`, generated from `native_tiles.png`; this atlas preserves
hidden pixels and shared-tile details that a composited frame cannot represent.
The complete PNG frames remain additional editable inputs. Their visible-pixel
edits are applied to the source-assembled archive using the native OAM records.

The intermediate decoded archive stays under `build/`. The C `fomt-lz` tool
packs it to source-adjacent `archive.lz` using the checked-in
`archive.original.lz` for the original codec and slot size. Unchanged content
retains the exact publisher stream; an edit is strictly decoded and rejected
if it exceeds that slot. JP uses `120` Huffman-4/LZ2; the overseas archives use
`220` Huffman-8/LZ2. Assembly includes `archive.lz` directly. A normal resource
build does not read a retail ROM or patch the linked image.

| Source group | ROM start | Packed size | Native tiles |
| --- | --- | ---: | ---: |
| JP | `0x084CDBDC` | `0x2D90` | 810 |
| US/EU | US `0x08747A74`, EU `0x08747AD0` | `0x2764` | 569 |
| DE | `0x084CEEE8` | `0x275C` | 571 |

The ROM starts above are written with the GBA `0x08000000` base; the equivalent
file offsets are `0x4CDBDC`, `0x747A74`, `0x747AD0`, and `0x4CEEE8`.

```console
make gfx-intro-indexed-archive-all
make gfx-intro-indexed-archive-edit-test
```

The same initializer also consumes `small_indexed_archive/shared/full/`: a
separate, raw `0x118`-byte archive with three complete 16-by-16 OAM frames.
Its native bytes are identical in JP, US, EU, and DE. All three views share
the same four native tiles and palette; their original PNG exports were
byte-for-byte duplicates. One `frame_0000.png` therefore supplies both
assets through the ordinary C `gbagfx` rules. The selection, descriptor,
OAM, and animation records are written directly in the assembly source;
there is no ROM-template rebuild or post-link patch for this archive.

```console
make gfx-intro-small-archive-all
```

## Startup background layers

`func_080019D8` additionally expands a shared `0x8000`-byte 4bpp tile payload,
loads sixteen BGR555 palette banks, and then uses the four native startup-map
sources.  The tiles and palette banks are verified byte-identically against
the JP, US, EU and DE ROMs and are available under
`shared/startup_visual/`.

`shared/startup_tilemaps/startup_00.tilemap` through `startup_03.tilemap`
remain the authoritative editable layout sources.  Each `0x1000`-byte source
contains two 32-by-32 BG maps in alternating 0x40-byte rows.  The eight PNGs
under `reference/startup/` were rendered from that proven row split, tile IDs,
flip bits and palette-bank fields; they are visual references only, because a
flat PNG cannot preserve those native map fields.

The four `startup_NN.original.lz` files retain the byte-identical publisher
streams for an unchanged source. The C `fomt-lz` tool builds each
`startup_NN.tilemap.lz` beside its editable `.tilemap`; assembly includes that
generated stream directly. Neither the resource build nor the link reads a
retail ROM or patches the finished image.

`func_080019D8` writes the two maps from each source to fixed VRAM screen
blocks. This is a proven storage relationship, not an assertion about which
map is visible at a particular point in the scene:

| Editable source | First 32x32 map | Second 32x32 map |
| --- | --- | --- |
| `startup_00.tilemap` | screen block 24 (`0x0600C000`) | screen block 25 (`0x0600C800`) |
| `startup_01.tilemap` | screen block 26 (`0x0600D000`) | screen block 27 (`0x0600D800`) |
| `startup_02.tilemap` | screen block 28 (`0x0600E000`) | screen block 29 (`0x0600E800`) |
| `startup_03.tilemap` | screen block 30 (`0x0600F000`) | screen block 31 (`0x0600F800`) |

For each of the 32 rows, the first `0x40` bytes of the source's `0x80`-byte
row go to the first screen block and the next `0x40` bytes go to the second.
The checked-in `.tilemap` files deliberately preserve this decoded native
interleaving; the rendered layer PNGs must not replace them as source data.

The startup tile payload uses the `230` Huffman-8/LZ3 family. `gbagfx` converts
the tile and palette PNGs into source-adjacent `.4bpp` and `.gbapal` resources;
the C `fomt-lz` tool then packs the tiles into `.4bpp.lz`. The checked-in
`startup_tiles.original.lz` preserves the publisher stream for unchanged art.
Edited tiles are decoded after H8/LZ3 encoding and rejected if they exceed the
original `0x3970` slot. Assembly links these generated resources directly,
without reading a ROM or patching the linked image. The native startup maps
remain independently editable through their Huffman-4/LZ3 path.

```console
make gfx-intro-startup-visual-test
make gfx-intro-startup-tilemaps-all
```
