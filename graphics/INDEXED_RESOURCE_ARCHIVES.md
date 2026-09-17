# Indexed resource archive audit

This document records ROM ranges consumed by `IndexedResourceArchive` in
`src/resource_handle.cc`. They are **not** automatically image resources:
their descriptor payloads may select graphics, animation data, layout records,
or other runtime data. They remain direct baseline-ROM data until a consumer
and a lossless source format are established.

The constructor establishes six counted descriptor blocks with element sizes
4, 16, 8, 32, 32, and 8 bytes, followed by a counted table of four-byte
entries. `tools/indexed_resource_archive.py` parses only these proven bounds;
it intentionally does not assign guessed meanings to descriptor fields.

The generated [label-bound inventory](INDEXED_RESOURCE_ARCHIVE_INVENTORY.md)
separately lists every currently bounded DE `gUnk_*` payload whose native
header parses successfully, including records that are still unmanaged or
regionally different. It is the coverage ledger for this staged pipeline.

## Confirmed shared archives

| Archive | JP | US | EU | DE | Native length | Header counts | Entries | SHA-256 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Common resource archive | `0x3ED9FC` | `0x6678A0` | `0x6678FC` | `0x3EE93C` | `0x12848` | `493, 500, 101, 1624, 342, 0` | 532 | `c28eff40e6965f89015da48b9527ea995eeec0d7ec30c4f1f2aeda5b8f3f9f33` |
| Small companion archive | `0x3ED1BC` | `0x667060` | `0x6670BC` | `0x3EE0FC` | `0x840` | `3, 16, 3, 52, 2, 0` | 16 | `45596a1fced2bdeb33c101de5f124c26939d03ee0f2d71e361ba5ffab53a7cc7` |
| Small shared UI archive | `0x4DABB8` | `0x754C0C` | `0x754C68` | `0x4DC128` | `0x548` | `2, 4, 2, 36, 2, 0` | 5 | `2908231dba2fb5105723476b17f7fd4ab3d4fe597144df7a0dc06ef065ffca6b` |
| Cooking UI archive | `0x4DA620` | `0x754674` | `0x7546D0` | `0x4DBB90` | `0x598` | `1, 3, 3, 40, 1, 0` | 4 | `3ad7d5722ca026e54678295cb52f199e435ae313e99a8c0cadf4b62e89566fda` |
| Menu UI archive | `0x4A4910` | `0x71E7A8` | `0x71E804` | `0x4A5974` | `0x504` | `8, 8, 1, 32, 1, 0` | 8 | `294385013bada21051d9c04acea32fc4880318eef8dc59d2b9158cea7a978c8c` |
| Large shared archive | `0x4A5068` | `0x71EF00` | `0x71EF5C` | `0x4A60CC` | `0x6EA0` | `27, 102, 1, 768, 46, 0` | 124 | `f3dbd496b2e790073ecf8175ef5be7f2d2aad8d8777751ccad7d3cb7d8203878` |
| Shared archive `08725DA0` | `0x4ABF08` | `0x725DA0` | `0x725DFC` | `0x4ACF6C` | `0xF2C` | `6, 6, 20, 109, 2, 0` | 6 | `cd97e9321879d994de4330bb45763b1b368a782167db9c8f3f6d506357c8e11c` |
| Shared archive `086F2FAC` | `0x479108` | `0x6F2FAC` | `0x6F3008` | `0x47A048` | `0x31FC` | `4, 16, 2, 384, 4, 0` | 16 | `de384dcd7c3fe848025b77ae9efb94d63e9d15cc2247cb858727a20167b1b2a4` |
| Shared archive `086FAA80` | `0x480BDC` | `0x6FAA80` | `0x6FAADC` | `0x481B1C` | `0x584` | `3, 9, 1, 36, 1, 0` | 9 | `95c9e3db66e9d29b25c7e228d60accf8abba3ce6c5c7a489ece487a97d84ac31` |
| Shared archive `0871ECAC` | `0x4A4E14` | `0x71ECAC` | `0x71ED08` | `0x4A5E78` | `0x128` | `1, 5, 1, 4, 1, 0` | 4 | `9f278e9f3fc533ace766b248d2e55c8c5bbc9ee1ad026abe1c36804eeb18ed81` |
| Shared archive `0871EDD4` | `0x4A4F3C` | `0x71EDD4` | `0x71EE30` | `0x4A5FA0` | `0x12C` | `1, 5, 1, 4, 1, 0` | 5 | `102175f059443e70fd1483b0e568d5b1e125812a9170a70433b280a927039017` |
| Shared archive `08527094` | `0x2AD1F0` | `0x527094` | `0x5270F0` | `0x2AE130` | `0x1A4` | `4, 8, 7, 4, 1, 0` | 8 | `b54f1e2abe5bc34fdde8cb5a4c7b18d82d5d669d315db22a237cd9b03856306d` |
| Shared archive `08727368` | `0x4AD4D0` | `0x727368` | `0x7273C4` | `0x4AE534` | `0x70C` | `3, 21, 68, 22, 1, 0` | 37 | `d045b5182e480e59df0de81d681be5187deb65427b80757af52a618d83955f0a` |
| Shared archive `08727A74` | `0x4ADBDC` | `0x727A74` | `0x727AD0` | `0x4AEC40` | `0x794` | `1, 1, 36, 49, 1, 0` | 1 | `3734dad3d75471435276b57d3fa13693950e13a49b24d9caede41a2562041ffc` |
| Shared archive `08728320` | `0x4AE488` | `0x728320` | `0x72837C` | `0x4AF4EC` | `0x105C` | `7, 21, 32, 107, 1, 0` | 21 | `db6e14760f25e35a7211916f8a30cdafd90bcba78faed0e738bfc69dcf0edbfc` |
| Shared archive `0872937C` | `0x4AF4E4` | `0x72937C` | `0x7293D8` | `0x4B0548` | `0xE4` | `1, 3, 1, 3, 1, 0` | 3 | `0e4724ae1b5689f71ce4ccab6643f935d670cc64a153a16cbc7748943c2ad6ba` |
| Shared archive `08729460` | `0x4AF5C8` | `0x729460` | `0x7294BC` | `0x4B062C` | `0x2A04` | `1, 3, 9, 330, 1, 0` | 3 | `7a8b853ced44cc16da447b0f51ff98865b591f54b006fac3a3b52adfc9b1a24a` |
| Shared archive `0872EE78` | `0x4B4FE0` | `0x72EE78` | `0x72EED4` | `0x4B61E4` | `0x2A4` | `4, 4, 1, 16, 1, 0` | 4 | `037e8098cf0ae92448f15134435110b9973350086eb0c4ff894fe628fcf5956e` |
| Shared archive `08731B40` | `0x4B7CA8` | `0x731B40` | `0x731B9C` | `0x4B8EAC` | `0x6604` | `20, 20, 13, 794, 3, 0` | 20 | `f7ba7a09d7fd9da4ce57d4c898240aee2a733beb30e58e95230efa83ab0d1104` |
| Shared archive `0873AE54` | `0x4C0FBC` | `0x73AE54` | `0x73AEB0` | `0x4C21C0` | `0x174` | `2, 2, 1, 8, 1, 0` | 2 | `4df3efe78a69739b78cd62fb773e30710ddac261913c72027f46d2ba4f22fac7` |
| Shared archive `0873AFC8` | `0x4C1130` | `0x73AFC8` | `0x73B024` | `0x4C2334` | `0xE5C` | `1, 1, 9, 110, 1, 0` | 1 | `0d6914b0adbac7c333dfdc60c3050ab487ac5ba38fa84e30f58b42de72318aa4` |
| Shared archive `0873CCB4` | `0x4C2E1C` | `0x73CCB4` | `0x73CD10` | `0x4C4020` | `0x1F8` | `1, 2, 2, 12, 1, 0` | 2 | `509924386721ac51164b216e8af9f05e7dbd33dd6be09847e528545ccd7c1d7f` |
| Shared archive `0873CEAC` | `0x4C3014` | `0x73CEAC` | `0x73CF08` | `0x4C4218` | `0xE4` | `1, 1, 2, 4, 1, 0` | 1 | `91a82b1e3c4e6221eea6d2b2ce4a5b0bee79493ed3bf30796d9772c6c1a606d0` |
| Shared archive `0873CF90` | `0x4C30F8` | `0x73CF90` | `0x73CFEC` | `0x4C42FC` | `0x2A4` | `4, 4, 1, 16, 1, 0` | 4 | `71781d5bc4ce062555f65b42316d21fceecc540f2ca81db24b40eb24b489c3d2` |
| Shared archive `0873D234` | `0x4C339C` | `0x73D234` | `0x73D290` | `0x4C45A0` | `0x3C8` | `3, 6, 1, 24, 1, 0` | 6 | `3abfeee1b4c92cf474ec9bcba97809fbe42f87006023cb6e07e2c9d3736bda77` |
| Shared archive `0873D5FC` | `0x4C3764` | `0x73D5FC` | `0x73D658` | `0x4C4968` | `0xDC` | `1, 1, 1, 4, 1, 0` | 1 | `ee9d4a1f4f377bae3b1ea463e567a3c744e09b319b1de58f5ad32b87d14ae7b6` |
| Shared archive `0873DE44` | `0x4C3FAC` | `0x73DE44` | `0x73DEA0` | `0x4C52B8` | `0x76C` | `1, 1, 3, 56, 1, 0` | 1 | `8cd938635878c39beb869b454414787b8231eada2c056409ad196027fe8c3931` |
| Shared archive `0873E5B0` | `0x4C4718` | `0x73E5B0` | `0x73E60C` | `0x4C5A24` | `0x76C` | `1, 1, 3, 56, 1, 0` | 1 | `88099d904d2e94041c3400a97c921a2edcf0e9fe148a760323b01abcc958050a` |
| Shared archive `0873ED1C` | `0x4C4E84` | `0x73ED1C` | `0x73ED78` | `0x4C6190` | `0x6AC` | `3, 10, 11, 41, 2, 0` | 11 | `e9264bb9348375ee86ed48a0c373615fddcc4d5812c9c4656abff76e0c4081b3` |
| Shared archive `087401A4` | `0x4C630C` | `0x7401A4` | `0x740200` | `0x4C7618` | `0x2B0` | `1, 4, 4, 16, 1, 0` | 4 | `3d8be5f248282e9dbcbf14f8c30f97fc5aae48fb5a5306c2993adbae217cfdf1` |
| Shared archive `08740454` | `0x4C65BC` | `0x740454` | `0x7404B0` | `0x4C78C8` | `0x14C` | `1, 3, 2, 6, 1, 0` | 3 | `eea4d3527019773fd5cbbbdd7dbe0d85eb16eea402a5d7d7603fa9d103e190bc` |
| Shared archive `087405A0` | `0x4C6708` | `0x7405A0` | `0x7405FC` | `0x4C7A14` | `0x368` | `2, 1, 2, 24, 1, 0` | 1 | `d7556b7934c14a071803760e7c138016f0b7f7b8ebbe949268f9662e1cb58dc6` |
| Shared archive `08740908` | `0x4C6A70` | `0x740908` | `0x740964` | `0x4C7D7C` | `0xDC` | `1, 1, 1, 4, 1, 0` | 1 | `7803dd34b7e3aafc39ea41395c34be785bd28a8fc8add9dbeb2f1c9fd80f2f1a` |
| Shared archive `087409E4` | `0x4C6B4C` | `0x7409E4` | `0x740A40` | `0x4C7E58` | `0x1010` | `1, 3, 18, 120, 1, 0` | 4 | `5f7a693b74b3a1a91e25515dc6b56bfdca5c6d73dd76ea2051e2573178810320` |
| Shared archive `0874EE38` | `0x4D5354` | `0x74EE38` | `0x74EE94` | `0x4D62A4` | `0xDC` | `1, 1, 1, 4, 1, 0` | 1 | `b01a430fb80a11101e121ff8f0aac65d9263770992eedc2f4b6efdbdbaf378ef` |
| Shared archive `087506E0` | `0x4D668C` | `0x7506E0` | `0x75073C` | `0x4D7BFC` | `0x56C` | `4, 4, 10, 36, 1, 0` | 4 | `47327d507aaa6887ea219a7a8facf07c41f18c0560d87d2ee74a448d5c989661` |
| Shared archive `0875352C` | `0x4D94D8` | `0x75352C` | `0x753588` | `0x4DAA48` | `0xDC` | `1, 1, 1, 4, 1, 0` | 1 | `38e1fc4d3ae2dca18201483a01c7d8c4f2f349d647714657819d26781d0baa42` |
| Shared archive `08753608` | `0x4D95B4` | `0x753608` | `0x753664` | `0x4DAB24` | `0xDC` | `1, 1, 1, 4, 1, 0` | 1 | `7be849ea577613d60c0442e0d6621854079e92ca590fd7341cd3c1b8dc37f073` |
| Shared archive `087536E4` | `0x4D9690` | `0x7536E4` | `0x753740` | `0x4DAC00` | `0xEC` | `2, 4, 3, 2, 1, 0` | 4 | `566a82212c7eedadffa176211cc46c539368d6e34b512de40d9c0289d83685e1` |
| Farm Status / Town Map archive | `0x4D977C` | `0x7537D0` | `0x75382C` | `0x4DACEC` | `0xEA4` | `20, 40, 11, 73, 13, 0` | 40 | `480a114e52b941e289d67055ddd632b6c0bbee3cfa66263523ad91c7e1d4dfc1` |

All forty complete native archive payloads are byte-identical across JP, US,
EU, and DE. The common archive is the data currently exposed under
`gUnk_086678A0` in non-JP regional assembly; the JP physical match was found
by the exact complete payload, not by inventing a JP label.

The common archive's group-descriptor consumer is fully bounded. Every
drawable descriptor selects valid GBA OAM, 4bpp tile, and BGR555 palette
ranges; `func_0805E790` resolves the fields and `func_080757E8` uploads tiles
and palettes to OBJ memory. Its 498 indexed PNG sources and fixed-size rebuild
live under `graphics/common_resource_archive/`. The two all-zero groups (`316`,
`429`) are native non-drawable records and are deliberately not artwork.

The small companion archive follows the same fully bounded group-descriptor
contract. Its sixteen descriptors select three native GBA OAM records, fifty-
two 4bpp tiles, and two BGR555 palettes. Every group is drawable; shared OAM
records intentionally map multiple editable group views onto their native tile
ranges. Its complete indexed PNG sources and fixed-size rebuild live under
`graphics/small_companion_archive/`.

The small shared UI archive is independently bounded at the four locations in
the table. Its four descriptors contain three drawable resources and one
all-zero native slot; together they select two OAM records, 36 4bpp tiles, two
BGR555 palettes, and five selection entries. Generic UI and cooking-screen
constructors both instantiate it, so its `graphics/ui/small_resource_archive/`
PNG sources deliberately retain neutral physical group names rather than
inventing a single-screen interpretation.

The cooking UI archive is independently bounded at the four locations in the
table. Its three descriptors contain two drawable resources and one all-zero
native slot; together they select three OAM records, 40 4bpp tiles, one BGR555
palette, and four selection entries. Cooking constructors instantiate it, so
its PNG sources live under `graphics/ui/cooking_resource_archive/`; their
neutral physical group names avoid guessing a separate gameplay role for each
selection-frame variant.

The menu UI archive is independently bounded at the four locations in the
table. Its eight descriptors all select drawable records, together covering one
OAM record, 32 4bpp tiles, one BGR555 palette, and eight selection entries. It
is constructed next to the menu entry-ID table; its PNG sources therefore live
under `graphics/ui/menu_resource_archive/`, but retain neutral group names
until each icon's semantics have independent runtime evidence.

The large shared archive is independently bounded at the four locations in the
table. Its 102 descriptors all select drawable records, together covering one
OAM record, 768 4bpp tiles, 46 BGR555 palettes, and 124 selection entries. Its
complete editable PNG sources are under `graphics/large_resource_archive/`.
The current consumer evidence establishes an active shared runtime archive, not
the gameplay meaning of every group, so its source file names remain neutral.

Shared archive `08725DA0` is independently bounded at the four locations in
the table. Its six descriptors all select drawable records, together covering
20 OAM records, 109 4bpp tiles, two BGR555 palettes, and six selection entries.
Its editable PNG sources are under `graphics/shared_resource_08725da0/`; its
original address is retained because individual gameplay semantics remain
unverified.

Shared archive `086F2FAC` is independently bounded at the four locations in
the table. Its sixteen descriptors all select drawable records, together
covering two OAM records, 384 native 4bpp tiles, four BGR555 palettes, and
sixteen selection entries. Its editable PNG sources are under
`graphics/shared_resource_086f2fac/`; the address remains its source name
until the runtime purpose is independently established.

Shared archive `086FAA80` is independently bounded at the four locations in
the table. Its nine descriptors all select drawable records, together covering
one OAM record, 36 native 4bpp tiles, one BGR555 palette, and nine selection
entries. Its editable PNG sources are under
`graphics/shared_resource_086faa80/`; the address remains its source name
until the runtime purpose is independently established.

Shared archive `0871ECAC` is independently bounded at the four locations in
the table. Its five descriptors contain four drawable resources and one
all-zero native slot; together they select one OAM record, four native 4bpp
tiles, one BGR555 palette, and four selection entries. Its editable PNG
sources are under `graphics/shared_resource_0871ecac/`; the address remains
its source name until the runtime purpose is independently established.

Shared archive `0871EDD4` is independently bounded at the four locations in
the table. Its five descriptors contain four drawable resources and one
all-zero native slot; together they select one OAM record, four native 4bpp
tiles, one BGR555 palette, and five selection entries. Its editable PNG
sources are under `graphics/shared_resource_0871edd4/`; the address remains
its source name until the runtime purpose is independently established.

Shared archive `08727368` is independently bounded at the four locations in
the table. Its 21 descriptors contain nineteen drawable resources and two
all-zero native slots; together they select 68 OAM records, 22 native 4bpp
tiles, three BGR555 palettes, and 37 selection entries. Its editable PNG
sources are under `graphics/shared_resource_08727368/`; the address remains
its source name until the runtime purpose is independently established.

Shared archive `08727A74` is independently bounded at the four locations in
the table. Its one descriptor selects 36 native flipped OAM entries, 49 native
4bpp tiles, one BGR555 palette, and one selection entry. Its editable PNG
source is under `graphics/shared_resource_08727a74/`; the address remains its
source name until the runtime purpose is independently established.

Shared archive `08728320` is independently bounded at the four locations in
the table. Its 21 descriptors select 32 native OAM records, 107 native 4bpp
tiles, one BGR555 palette, and 21 selection entries. Its editable PNG sources
are under `graphics/shared_resource_08728320/`; the address remains its source
name until the runtime purpose is independently established.

Shared archive `0872937C` is independently bounded at the four locations in
the table. Its three descriptors select one native OAM record, three native
4bpp tiles, one BGR555 palette, and three selection entries. Its editable PNG
sources are under `graphics/shared_resource_0872937c/`; the address remains its
source name until the runtime purpose is independently established.

Shared archive `08729460` is independently bounded at the four locations in
the table. Its three descriptors select nine native OAM records, 330 native
4bpp tiles, one BGR555 palette, and three selection entries. Its editable PNG
sources are under `graphics/shared_resource_08729460/`; the address remains its
source name until the runtime purpose is independently established.

Shared archive `0872EE78` is independently bounded at the four locations in
the table. Its four descriptors select one native OAM record, 16 native 4bpp
tiles, one BGR555 palette, and four selection entries. Its editable PNG sources
are under `graphics/shared_resource_0872ee78/`; the address remains its source
name until the runtime purpose is independently established.

Shared archive `08731B40` is independently bounded at the four locations in
the table. Its 20 descriptors select 13 native OAM records, 794 native 4bpp
tiles, three BGR555 palettes, and 20 selection entries. Its editable PNG
sources are under `graphics/shared_resource_08731b40/`; the address remains its
source name until the runtime purpose is independently established.

Shared archive `0873AE54` is independently bounded at the four locations in
the table. Its two descriptors select one native OAM record, eight native 4bpp
tiles, one BGR555 palette, and two selection entries. Its editable PNG sources
are under `graphics/shared_resource_0873ae54/`; the address remains its source
name until the runtime purpose is independently established.

Shared archive `0873AFC8` is independently bounded at the four locations in
the table. Its descriptor selects one native OAM record, 110 native 4bpp tiles,
one BGR555 palette, and one selection entry. Its editable PNG source is under
`graphics/shared_resource_0873afc8/`; the address remains its source name until
the runtime purpose is independently established.

Shared archive `0873CCB4` is independently bounded at the four locations in
the table. Its two descriptors select two native OAM records, 12 native 4bpp
tiles, one BGR555 palette, and two selection entries. Its editable PNG sources
are under `graphics/shared_resource_0873ccb4/`; the address remains its source
name until the runtime purpose is independently established.

Shared archive `0873CEAC` is independently bounded at the four locations in
the table. Its descriptor selects one native OAM record, four native 4bpp
tiles, one BGR555 palette, and one selection entry. Its editable PNG source is
under `graphics/shared_resource_0873ceac/`; the address remains its source name
until the runtime purpose is independently established.

Shared archive `0873CF90` is independently bounded at the four locations in
the table. Its four descriptors select one native OAM record, 16 native 4bpp
tiles, one BGR555 palette, and four selection entries. Its editable PNG sources
are under `graphics/shared_resource_0873cf90/`; the address remains its source
name until the runtime purpose is independently established.

Shared archive `0873D234` is independently bounded at the four locations in
the table. Its six descriptors select one native OAM record, 24 native 4bpp
tiles, one BGR555 palette, and six selection entries. Its editable PNG sources
are under `graphics/shared_resource_0873d234/`; the address remains its source
name until the runtime purpose is independently established.

Shared archive `0873D5FC` is independently bounded at the four locations in
the table. Its one descriptor selects one native OAM record, four native 4bpp
tiles, one BGR555 palette, and one selection entry. Its editable PNG source is
under `graphics/shared_resource_0873d5fc/`; the address remains its source name
until the runtime purpose is independently established.

Shared archive `0873DE44` is independently bounded at the four locations in
the table. Its one descriptor selects one native OAM record, 56 native 4bpp
tiles, one BGR555 palette, and one selection entry. Its editable PNG source is
under `graphics/shared_resource_0873de44/`; the address remains its source name
until the runtime purpose is independently established.

Shared archive `0873E5B0` is independently bounded at the four locations in
the table. Its one descriptor selects one native OAM record, 56 native 4bpp
tiles, one BGR555 palette, and one selection entry. Its editable PNG source is
under `graphics/shared_resource_0873e5b0/`; the address remains its source name
until the runtime purpose is independently established.

Shared archive `0873ED1C` is independently bounded at the four locations in
the table. Its ten descriptors select eleven native OAM records, 41 native
4bpp tiles, two BGR555 palettes, and eleven selection entries. Its editable
PNG sources are under `graphics/shared_resource_0873ed1c/`; the address remains
its source name until the runtime purpose is independently established.

Shared archive `087401A4` is independently bounded at the four locations in
the table. Its four descriptors select four native OAM records, 16 native 4bpp
tiles, one BGR555 palette, and four selection entries. Its editable PNG sources
are under `graphics/shared_resource_087401a4/`; the address remains its source
name until the runtime purpose is independently established.

Shared archive `08740454` is independently bounded at the four locations in
the table. Its three descriptors select two native OAM records, six native 4bpp
tiles, one BGR555 palette, and three selection entries. Three native OAM flips
remain layout data. Its editable PNG sources are under
`graphics/shared_resource_08740454/`; the address remains its source name until
the runtime purpose is independently established.

Shared archive `087405A0` is independently bounded at the four locations in
the table. Its one descriptor selects two native OAM records, 24 native 4bpp
tiles, one BGR555 palette, and one selection entry. Its editable PNG source is
under `graphics/shared_resource_087405a0/`; the address remains its source name
until the runtime purpose is independently established.

Shared archive `08740908` is independently bounded at the four locations in
the table. Its one descriptor selects one native OAM record, four native 4bpp
tiles, one BGR555 palette, and one selection entry. Its editable PNG source is
under `graphics/shared_resource_08740908/`; the address remains its source name
until the runtime purpose is independently established.

Shared archive `087409E4` is independently bounded at the four locations in
the table. Its one descriptor selects three native OAM records, 120 native 4bpp
tiles, one BGR555 palette, and four selection entries. Its editable PNG sources
are under `graphics/shared_resource_087409e4/`; the address remains its source
name until the runtime purpose is independently established.

Shared archive `0874EE38` is independently bounded at the four locations in
the table. Its one descriptor selects one native OAM record, four native 4bpp
tiles, one BGR555 palette, and one selection entry. Its editable PNG source is
under `graphics/shared_resource_0874ee38/`; the address remains its source name
until the runtime purpose is independently established.

Shared archive `087506E0` is independently bounded at the four locations in
the table. Its four descriptors select four native OAM records, 36 native 4bpp
tiles, one BGR555 palette, and four selection entries. Its editable PNG sources
are under `graphics/shared_resource_087506e0/`; the address remains its source
name until the runtime purpose is independently established.

Shared archive `0875352C` is independently bounded at the four locations in
the table. Its one descriptor selects one native OAM record, four native 4bpp
tiles, one BGR555 palette, and one selection entry. Its editable PNG source is
under `graphics/shared_resource_0875352c/`; the address remains its source name
until the runtime purpose is independently established.

Shared archive `08753608` is independently bounded at the four locations in
the table. Its one descriptor selects one native OAM record, four native 4bpp
tiles, one BGR555 palette, and one selection entry. Its editable PNG source is
under `graphics/shared_resource_08753608/`; the address remains its source name
until the runtime purpose is independently established.

Shared archive `087536E4` is independently bounded at the four locations in
the table. Its two descriptors select four native OAM records, two native 4bpp
tiles, one BGR555 palette, and four selection entries. Its editable PNG sources
are under `graphics/shared_resource_087536e4/`; the address remains its source
name until the runtime purpose is independently established.

The Farm Status screen constructs a third archive at `0x4D977C` in JP and
`0x7537D0` in US (with the regional locations recorded by its rebuild tool).
Town Map uses the same complete `0xEA4` payload. Its consumer path is fully
bounded: forty group descriptors select valid OAM, 4bpp tile, and BGR555
palette ranges, and runtime code uploads the latter two ranges to OBJ memory.
Complete indexed-PNG sources and the fixed-size lossless rebuild are under
`graphics/ui/farm_status/resource_archive/`.

Recheck the evidence with:

```console
python tools/indexed_resource_archive.py compare ^
  --rom jp baserom_jp.gba 0x3ED9FC ^
  --rom us baserom_us.gba 0x6678A0 ^
  --rom eu baserom_eu.gba 0x6678FC ^
  --rom de baserom_de.gba 0x3EE93C

python tools/indexed_resource_archive.py compare ^
  --rom jp baserom_jp.gba 0x3ED1BC ^
  --rom us baserom_us.gba 0x667060 ^
  --rom eu baserom_eu.gba 0x6670BC ^
  --rom de baserom_de.gba 0x3EE0FC

python tools/indexed_resource_archive.py compare ^
  --rom jp baserom_jp.gba 0x4DABB8 ^
  --rom us baserom_us.gba 0x754C0C ^
  --rom eu baserom_eu.gba 0x754C68 ^
  --rom de baserom_de.gba 0x4DC128

python tools/indexed_resource_archive.py compare ^
  --rom jp baserom_jp.gba 0x4DA620 ^
  --rom us baserom_us.gba 0x754674 ^
  --rom eu baserom_eu.gba 0x7546D0 ^
  --rom de baserom_de.gba 0x4DBB90

python tools/indexed_resource_archive.py compare ^
  --rom jp baserom_jp.gba 0x4A4910 ^
  --rom us baserom_us.gba 0x71E7A8 ^
  --rom eu baserom_eu.gba 0x71E804 ^
  --rom de baserom_de.gba 0x4A5974

python tools/indexed_resource_archive.py compare ^
  --rom jp baserom_jp.gba 0x4A5068 ^
  --rom us baserom_us.gba 0x71EF00 ^
  --rom eu baserom_eu.gba 0x71EF5C ^
  --rom de baserom_de.gba 0x4A60CC

python tools/indexed_resource_archive.py compare ^
  --rom jp baserom_jp.gba 0x4ABF08 ^
  --rom us baserom_us.gba 0x725DA0 ^
  --rom eu baserom_eu.gba 0x725DFC ^
  --rom de baserom_de.gba 0x4ACF6C
```

The `^` continuation marker is for `cmd.exe`; remove it or use the shell's
own continuation syntax elsewhere.

## Consequence for the graphics pipeline

The managed actor tile stream, Records Screen task icon/palette pairs, and
other confirmed resource payloads retain their existing direct runtime labels.
Any future archive conversion must preserve its parsed boundary, descriptor
counts, entry ordering, and every pointer or caller that resolves an archive
index.
