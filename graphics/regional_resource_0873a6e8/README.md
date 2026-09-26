# Regional resource `0873A6E8`

`gUnk_0873A6E8` has one drawable OAM group in each native archive. JP, US, and
EU are byte-identical. DE has the same selector, descriptor, OAM, palette,
empty header, and final index; only its 56 native 4bpp tiles differ.

| Source domain | Regions | ROM offset(s) | Length | Header counts | SHA-256 |
| --- | --- | --- | ---: | --- | --- |
| `shared/` | JP / US / EU | `0x4C0850` / `0x73A6E8` / `0x73A744` | `0x76C` | `1, 1, 3, 56, 1, 0` | `a05269ed950c7e531e8886808f4e932f7bb2e00b6c846df6d0835608920a4764` |
| `de/` | DE | `0x4C1A54` | `0x76C` | `1, 1, 3, 56, 1, 0` | `f01742625d55eea85e34694a92ea36e6d210782f21eedc667a08ad0bc4c91028` |

`shared/full/native.png` supplies the JP/US/EU tiles and `de/full/native.png`
supplies the DE tiles, both in physical ROM order. Root `native.pal` is the
shared editable 16-color palette. Generic graphics rules compile them to
adjacent `.4bpp` and `.gbapal` products. `archive.inc` directly links those
products with the common tables in their original order; no ROM-template
rebuild, JSON sidecar, or post-link patch is used for this archive.

The old `full/group_000.png` and `preview/` are OAM-composited reference views,
not build inputs. The PNG/PAL products round-trip to the original native bytes,
and complete JP, US, EU, and DE ROM builds match their original SHA-1 values.
