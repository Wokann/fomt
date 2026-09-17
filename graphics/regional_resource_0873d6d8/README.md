# Regional resource `0873D6D8`

`gUnk_0873D6D8` has one drawable OAM group per archive. JP, US, and EU are
byte-identical. DE adds one native layout record and eight 4bpp tiles, so it
uses a separate fixed-size source domain.

| Source domain | Regions | ROM offset(s) | Length | Header counts | SHA-256 |
| --- | --- | --- | ---: | --- | --- |
| `shared/` | JP / US / EU | `0x4C3840` / `0x73D6D8` / `0x73D734` | `0x76C` | `1, 1, 3, 56, 1, 0` | `8fff63c07bd1644165948f08f0c63b3ec1ba10e8c547b171e67368f2fb74b0e1` |
| `de/` | DE | `0x4C4A44` | `0x874` | `1, 1, 4, 64, 1, 0` | `7f9861a38aa4da765cfcc53c3cbe9c5da7eee9713bc5aa0a23a6181c009e00b1` |

Both domains contain one BGR555 palette and one selection entry.
`full/group_000.png` is the editable indexed-PNG source; `preview/` is a
regenerated OAM-composited reference. All native tables remain in the archive,
with no JSON layout sidecar. Four-region rebuild, patch and editable-pixel
tests prove that each output remains byte-exact and bounds-confined.
