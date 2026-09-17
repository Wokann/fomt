# Regional resource `0873A6E8`

`gUnk_0873A6E8` has one drawable OAM group in each native archive. JP, US, and
EU are byte-identical; DE has the same fixed layout but different payload data.

| Source domain | Regions | ROM offset(s) | Length | Header counts | SHA-256 |
| --- | --- | --- | ---: | --- | --- |
| `shared/` | JP / US / EU | `0x4C0850` / `0x73A6E8` / `0x73A744` | `0x76C` | `1, 1, 3, 56, 1, 0` | `a05269ed950c7e531e8886808f4e932f7bb2e00b6c846df6d0835608920a4764` |
| `de/` | DE | `0x4C1A54` | `0x76C` | `1, 1, 3, 56, 1, 0` | `f01742625d55eea85e34694a92ea36e6d210782f21eedc667a08ad0bc4c91028` |

Both domains have 56 4bpp tiles, one BGR555 palette and one selection entry.
`full/group_000.png` is the editable indexed-PNG source; `preview/` is a
reference rendering from native OAM. The archive keeps every layout table in
place and uses no JSON sidecar. Four-region build, patch and editable-pixel
tests verify exact fixed-range reconstruction.
