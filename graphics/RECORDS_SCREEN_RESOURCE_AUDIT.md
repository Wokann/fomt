# Records Screen resource audit

This audit closes the former "other Records-screen resources" lead without
promoting adjacent ROM bytes to artwork.  The conclusion is based on the
compiled data object, its assembly callers, and the fixed resource bounds;
it does not rely on visual similarity.

## Owned visual resources

`src/records_screen_data.cc` defines
`gRecordsScreenMinigameTaskResources` as seven two-word entries.  Every entry
is a pointer to one `0x80`-byte 16-by-16 4bpp tile grid and its immediately
following `0x20`-byte BGR555 palette.  The physical records are in ascending
ROM order, but the table selects the presentation order below:

| Presentation table index | Physical `task_NN` source |
| ---: | --- |
| 0 | `task_00` |
| 1 | `task_02` |
| 2 | `task_03` |
| 3 | `task_04` |
| 4 | `task_05` |
| 5 | `task_06` |
| 6 | `task_01` |

The same ordering exists in JP and overseas branches.  The only regional
differences are physical ROM offsets.  `tools/records_minigame_resources.py`
hash-checks each of the seven tile and palette records for JP, US, EU, and DE,
and the one shared set of indexed PNG sources rebuilds all four byte-for-byte.

The Records Screen assembly path at
`asm/code_0803EE94.s:125216` indexes this two-word table and passes its
tile/palette pair to the UI resource constructor.  This is direct code
evidence for the table's role; it is not inferred from the file names.

## Adjacent data is not additional Records artwork

The records object itself additionally contains:

- localized strings and a regional digit-glyph cache;
- `gCodeLinkoncePackedCellSizeLookup`, a six-byte two-bit cell-size lookup
  read by `func_080E2BB4`; and
- ordinary C++ runtime/allocator strings.

None of these is a tile, palette, tilemap, or OAM source.  The nearest raw
tile/palette pair before the overseas Records range is
`gUnk_08751E6C`/`gUnk_08751EEC`; assembly callers use it as Animal Festival
icon record 09, and it is already owned by the Animal Festival icon pipeline.
The next physical ranges belong to the separately managed Farm Status icon and
seasonal-background families.  Therefore a scan of surrounding bytes is not
evidence for another Records Screen image family.

## Verification

```console
make gfx-records-minigame-all
```

The target rebuilds the seven sources for every region and compares each
generated tile/palette pair with its original JP, US, EU, and DE slot.  This
audit adds no guessed PNG and no JSON layout sidecar.
