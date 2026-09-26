# Small companion OAM archive

This directory is the editable source for the shared `0x840`-byte
`IndexedResourceArchive` at JP `0x3ED1BC`, US `0x667060`, EU `0x6670BC`, and
DE `0x3EE0FC`. The four retail payloads are byte-identical:

```text
SHA-256 45596a1fced2bdeb33c101de5f124c26939d03ee0f2d71e361ba5ffab53a7cc7
```

`full/native.png` is the editable native-order indexed atlas of 52 4bpp tiles;
`full/native.pal` contains both original 16-color palette banks. The generic
graphics rules produce `native.4bpp` and `native.gbapal`, and `archive.inc`
links them with the original selector, descriptor, OAM, and selection tables.
The build no longer reads a ROM template or applies a post-link patch for this
archive.

`full/group_000.png` through `full/group_015.png` are OAM-composited reference
views, not compilation input. `preview/` contains RGBA review images only.

The archive contains three selector descriptors, sixteen group descriptors,
three OAM records, fifty-two 4bpp tiles, two BGR555 palettes, and sixteen
selection entries. The native source atlas includes pixels hidden by the OAM
composition; the original tables preserve sharing between group views.

```console
make -j4 gfx-small-companion-archive
make -j4 fomt_jp
make -j4 fomt_us
make -j4 fomt_eu
make -j4 fomt_de
```
