# Regional resource `0874F34C`

`gUnk_0874F34C` has 22 drawable OAM groups in every retail region but three
independent native layouts. US and EU are byte-identical; JP and DE have their
own table sizes and payloads.

| Source domain | Regions | ROM offset(s) | Fixed length | Header counts | Groups / tiles / palettes |
| --- | --- | --- | ---: | --- | --- |
| `jp/` | JP | `0x4D5868` | `0xE24` | `22, 22, 3, 92, 3, 0` | 22 / 92 / 3 |
| `us_eu/` | US / EU | `0x74F34C` / `0x74F3A8` | `0x1394` | `22, 22, 9, 134, 3, 0` | 22 / 134 / 3 |
| `de/` | DE | `0x4D67B8` | `0x1444` | `22, 22, 7, 140, 3, 0` | 22 / 140 / 3 |

`full/group_*.png` holds editable indexed-PNG source. `preview/` is rebuilt
from the original OAM data as a readable reference only. Selection, descriptor,
OAM, tile-allocation and palette tables remain inside the native fixed archive;
there is no JSON layout sidecar.

Make selects the corresponding JP, US/EU, or DE source domain, rebuilds the
exact archive length and post-link patches only the matching original address.
The four-region verification target proves unchanged byte recovery, safe patch
placement and a visible-pixel edit confined to every native allocation.
