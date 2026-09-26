# Regional resource `0873D6D8`

`gUnk_0873D6D8` has one drawable OAM group per archive. JP, US, and EU are
byte-identical. DE adds one native layout record and eight 4bpp tiles, so it
uses a larger archive with a separate native tile atlas.

| Source domain | Regions | ROM offset(s) | Length | Header counts | SHA-256 |
| --- | --- | --- | ---: | --- | --- |
| `shared/` | JP / US / EU | `0x4C3840` / `0x73D6D8` / `0x73D734` | `0x76C` | `1, 1, 3, 56, 1, 0` | `8fff63c07bd1644165948f08f0c63b3ec1ba10e8c547b171e67368f2fb74b0e1` |
| `de/` | DE | `0x4C4A44` | `0x874` | `1, 1, 4, 64, 1, 0` | `7f9861a38aa4da765cfcc53c3cbe9c5da7eee9713bc5aa0a23a6181c009e00b1` |

`shared/full/native.png` stores JP/US/EU's 56 tiles and `de/full/native.png`
stores DE's 64 tiles, each in physical ROM order. Root `native.pal` is the
shared editable 16-color palette. The generic graphics rules generate
adjacent `.4bpp` and `.gbapal` products; `archive.inc` places those products
among the original-order selector, descriptor, OAM, and index tables. Only
the descriptor, OAM, and tile sections need a DE conditional. No JSON layout
sidecar, ROM-template rebuild, or post-link patch is used for this archive.

The old `full/group_000.png` and `preview/` are OAM-composited reference
views, not build inputs. The generated tiles and palette match their native
ROM bytes exactly, and complete JP, US, EU, and DE ROM builds match their
original SHA-1 values.
