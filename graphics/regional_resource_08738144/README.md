# Regional resource `08738144`

`gUnk_08738144` has three independently verified native source domains. Its
regional structure is not a small localization-only variation:

| Source domain | Regions | ROM offset(s) | Fixed length | Header counts | Drawable groups / tiles / palettes |
| --- | --- | --- | ---: | --- | --- |
| `jp/` | JP | `0x4BE2AC` | `0x994` | `3, 3, 2, 72, 1, 0` | 3 / 72 / 1 |
| `us_eu/` | US / EU | `0x731B40` / `0x731B9C` | `0x6604` | `20, 20, 13, 794, 3, 0` | 20 / 794 / 3 |
| `de/` | DE | `0x4BF4B0` | `0x994` | `3, 3, 2, 72, 1, 0` | 3 / 72 / 1 |

US and EU are byte-identical and share one source directory. JP and DE have
the same physical table dimensions but different complete payloads, so each
retains its own editable PNG source. The three domains are never substituted
for one another.

`full/group_*.png` files are editable indexed-PNG sources. `preview/` is an
OAM-composited visual reference regenerated from the native archive. Selection,
descriptor, OAM, tile-allocation and palette tables remain inside each fixed
archive; no JSON layout sidecar is used.

The Make build chooses the matching source and native profile for each region,
then post-link patches only its original range. The target's four-region test
checks byte-exact unchanged rebuilds, post-link safety, and a visible-pixel
round trip confined to every proven archive allocation.
