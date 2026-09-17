# FarmHouse lookup-field audit

Each of the seven `FarmHouseVisualDescriptor` records begins with a
`FieldRenderRectDescriptor`.  In addition to the already-managed tilemap
patch buffers, it contains a `lookup_values` pointer at `+0x10` and a
`lookup_indices` pointer at `+0x14`.

`func_080A5BD8` establishes their operational meaning and safe lower bounds:

1. It visits exactly `width * height` bytes at `lookup_indices`.
2. For every index byte, it multiplies the value by four.
3. It reads that four-byte entry from `lookup_values` and writes it to the
   field renderer object's fourth working buffer (`object + 0x2C`).

This is not a BGR555 palette operation: it neither uses 16-bit words nor
writes palette RAM.  The consumer of the fourth buffer remains unidentified,
so these fields are classified as **field lookup metadata**, not graphics.
They deliberately stay in the regional ROM data rather than being exported
as editable tiles, palettes, or a JSON layout.

## Four-region result

Run the reproducible audit with:

```console
make farm-house-lookup-audit
```

All seven rectangles are byte-identical in FoMT-JP, FoMT-US, FoMT-EU, and
FoMT-DE.  Together they contain 1,202 index cells.  Every rectangle contains
only indices `0` and `1`, therefore each proven value domain is exactly two
four-byte entries (eight bytes).  Descriptors 1 and 2 share the same index
and value source; other descriptors use their own index grids and may share
the same two-entry values range.

The eight-byte ranges are deliberately only the **observed minimum**.  A
neighbouring ROM label does not prove the complete logical table size, and
the data is not promoted to a managed source until the fourth-buffer consumer
and its gameplay/rendering role are recovered.
