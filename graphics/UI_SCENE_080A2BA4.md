# `func_080A2BA4` BG resource set

`func_080A2BA4` is an as-yet unnamed UI-scene setup routine. Its resource
labels and VRAM loads are nevertheless concrete: the routine clears VRAM
screen blocks, passes four labelled ROM streams to `Unpack`, then configures
BG control values `0x1C43`, `0x1D41`, and `0x1E42`. Those controls select the
three screen blocks at `0x0600E000`, `0x0600E800`, and `0x0600F000`; the fourth
stream supplies the 4bpp character tiles at `0x06000000`.

The source therefore uses the native representation rather than an invented
screen capture:

| Source | Packed bytes | Decoded bytes | Native format | Runtime destination |
| --- | ---: | ---: | --- | --- |
| `layer_0.tilemap` | `0x28` | `0x500` (32x20 u16 entries) | `030`, ladder `125` | `0x0600E000` |
| `layer_1.tilemap` | `0xB0` | `0x500` (32x20 u16 entries) | `020`, ladder `1234679` | `0x0600E800` |
| `layer_2.tilemap` | `0x64` | `0x500` (32x20 u16 entries) | `020`, ladder `1234679` | `0x0600F000` |
| `tiles.4bpp` | `0x29C` | `0x1400` (160 4bpp tiles) | `020`, ladder `125681012` | `0x06000000` |

## Four-region evidence

All four packed streams, as well as every decoded payload, are byte-identical
in JP, US, EU, and DE. The physical starts differ only by localization ROM
layout:

| Region | First stream | Last stream |
| --- | ---: | ---: |
| JP | `0x4D5430` | `0x4D556C` |
| US | `0x74EF14` | `0x74F050` |
| EU | `0x74EF70` | `0x74F0AC` |
| DE | `0x4D6380` | `0x4D64BC` |

The four packed SHA-256 values in source order are:

```text
f89eac66fe9bfe4d66b2540a85e31a01b689315178f0e6381a7a3e53357fa2a5
4713bef027f8a799ac01398ed175f9dc6d9c6ec3601cd1a199e553bc21da4d31
2be4fe990176fbdce9ceda3a34de17f25c5864b6b433e681733fcf0d850ecee6
affe9000551cfe131462a85c89847ac8d7909a7883a8201e3109a5e577fdb54d
```

## Shared palette boundary and read-only preview

The routine copies exactly `0x200` bytes from `gUnk_0874F2EC` to BG palette
RAM. The existing assembly label boundary after its first `0x60` bytes is
`gUnk_0874F34C`, and that latter label is also constructed as an
`IndexedResourceArchive` by nearby code. Therefore the range is **not** an
independently editable palette source: changing it as artwork could damage the
archive's other consumer.

It is nevertheless the exact palette supplied to this UI routine, so the
repository contains read-only, code-backed regional previews in
`reference/jp/`, `reference/us/`, `reference/eu/`, and `reference/de/`. Each
contains the three 256-by-160 BG layers and a `screen.png` cropped to the GBA's
actual 240-by-160 viewport. These files are reference output only and have no
build or patch rule. Their source hashes and each region's copied 0x200-byte
palette range are checked before rendering.

The four checked-in native sources are editable. Rebuilds preserve each retail
compressed stream when unchanged; an edited stream is re-encoded with the
proven corresponding Raw-LZ encoder and rejected when it no longer fits its
original fixed ROM slot.

## Build and linkage

```console
make gfx-ui-scene-080a2ba4-all
make gfx-ui-scene-080a2ba4-reference
make gfx-ui-scene-080a2ba4-patch-test
```

`%.gba` depends on this source set. After `objcopy`, the regular ROM build
patches exactly these four original ranges with the selected region's generated
streams. Existing code labels and pointers remain at their retail locations,
so no guessed relocation table is introduced.
