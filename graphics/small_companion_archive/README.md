# Small companion OAM archive

This directory is the editable source for the shared `0x840`-byte
`IndexedResourceArchive` at JP `0x3ED1BC`, US `0x667060`, EU `0x6670BC`, and
DE `0x3EE0FC`. The four retail payloads are byte-identical:

```text
SHA-256 45596a1fced2bdeb33c101de5f124c26939d03ee0f2d71e361ba5ffab53a7cc7
```

`full/group_000.png` through `full/group_015.png` are the sixteen complete
indexed-PNG OAM resources. Their geometry, tile mapping, draw order and
palette selections come from the native archive descriptor/OAM tables; no JSON
or hand-authored layout sidecar is used. `preview/` contains RGBA review
images and is not an input to the rebuild.

The archive contains three selector descriptors, sixteen group descriptors,
three OAM records, fifty-two 4bpp tiles, two BGR555 palettes, and sixteen
selection entries. The rebuild starts with the verified baseline archive and
changes only native 4bpp pixels reached by an edited PNG. It retains selector,
descriptor, OAM, palette and non-visible tile bytes exactly as stored by the
retail ROM.

```console
make gfx-small-companion-archive-all
make gfx-small-companion-archive-patch-test
make gfx-small-companion-archive-edit-test
```

The last command edits a visible pixel shared by multiple group views and
verifies that only the native tile table changes, within the fixed archive
allocation.
