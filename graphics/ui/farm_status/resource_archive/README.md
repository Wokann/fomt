# Farm Status / Town Map OAM resource archive

`full/resource_000.png` through `full/resource_039.png` are the forty
editable indexed-image sources in the shared Farm Status / Town Map
`IndexedResourceArchive`. They are complete OAM-composited resources, not
linear tile dumps: thirty-eight are 16 by 16 pixels and two are 8 by 8 pixels.
`preview/` contains equivalent RGBA review images and is not an input.

The native archive is byte-identical in all four retail FoMT localizations:

| Region | ROM range |
| --- | --- |
| JP | `0x4D977C`–`0x4DA620` |
| US | `0x7537D0`–`0x754674` |
| EU | `0x75382C`–`0x7546D0` |
| DE | `0x4DACEC`–`0x4DBB90` |

Its fixed `0xEA4` bytes have SHA-256
`480a114e52b941e289d67055ddd632b6c0bbee3cfa66263523ad91c7e1d4dfc1`.
The six counted runtime tables contain 20 selection records, 40 group
descriptors, 11 OAM entries, 73 4bpp tiles, 13 BGR555 palettes, no sixth-table
records, and 40 selection entries. Each group descriptor has a verified OAM
range, tile range, and exactly one palette range. The first table maps each
high-level selection to two group IDs; it remains native data rather than a
second authored manifest.

`func_0805E790` resolves a group descriptor into the OAM/tile/palette ranges,
and `func_080757E8` copies those referenced tile and palette bytes to OBJ VRAM
and OBJ palette memory. This is the code-backed relationship that makes each
full PNG a safe editing surface.

The source PNG preserves its exact 16-color index palette. A rebuild starts
from the original full archive and changes only visible pixels that differ
from `full/`; descriptor tables, OAM records, BGR555 palettes, selection
records, unused table fields, and OAM-hidden tile pixels remain intact. Some
resources share native tile pixels. If their full PNG edits disagree, the
build fails instead of silently picking one value.

```console
make gfx-farm-status-resource-archive-all
make gfx-farm-status-resource-archive-patch-test
make gfx-farm-status-resource-archive-edit-test
```

The first command verifies unchanged source reconstruction in JP, US, EU and
DE. The second proves applying each generated fixed-size archive to its retail
range leaves the complete ROM unchanged. The last performs one coordinated
visible-pixel edit across a shared native tile and proves that only the tile
table changes.
