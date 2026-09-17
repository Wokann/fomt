# Regional `0875B444` indexed OAM archive

`gUnk_0875B444` has one fixed `IndexedResourceArchive` layout in every retail
FoMT region: six selection records, six group descriptors, one BGR555 palette,
twenty-four 4bpp tiles, and six drawable OAM groups.  The complete JP payload
is distinct; US, EU, and DE share the other complete payload.  The source
trees therefore follow the two verified byte domains:

| Source tree | Regions | ROM offsets | SHA-256 |
| --- | --- | --- | --- |
| `jp/` | JP | `0x4E07CC` | `a3aff94806fef413110271384ca4eed8aef15a02c968528e68935b1f73e18ccb` |
| `overseas/` | US / EU / DE | `0x75B444` / `0x75B4A0` / `0x4E2960` | `8da8ca4fbff49ad00f1ba1f81243cb56718b42741524531b1cf3e307a5693218` |

`full/group_*.png` are editable indexed-PNG sources. `preview/group_*.png`
are rendered from the native OAM records for inspection only. Selection,
descriptor, OAM, tile-allocation, and palette tables remain inside the native
fixed archive; this pipeline deliberately has no JSON layout sidecar.

```console
make gfx-regional-resource-0875b444-all
make gfx-regional-resource-0875b444-patch-test
make gfx-regional-resource-0875b444-edit-test
```

The first command verifies unchanged reconstruction for JP, US, EU, and DE.
The second confirms that patching unchanged outputs preserves every retail ROM
byte-for-byte. The third changes one visible source pixel in each domain and
confirms the rebuilt archive remains inside its original fixed allocation.
