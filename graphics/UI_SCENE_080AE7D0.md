# `func_080AE7D0` BG resource set

`func_080AE7D0` is a currently unnamed UI-scene setup routine. It clears the
screen blocks at `0x0600F000` and `0x0600F800`, unpacks two labelled 32-by-32
tilemaps into them, and unpacks its tile source to `0x06000000`. It configures
the corresponding BG control values `0x1E41` and `0x1F42`. A separate,
contiguous 0x200-byte BGR555 palette range is copied by the same routine.

| Source | Packed bytes | Decoded bytes | Native format | Runtime destination |
| --- | ---: | ---: | --- | --- |
| `layer_0.tilemap` | `0x238` | `0x800` (32x32 u16 entries) | `020`, ladder `35678910` | `0x0600F800` |
| `layer_1.tilemap` | `0x8C` | `0x800` (32x32 u16 entries) | `030`, ladder `2510` | `0x0600F000` |
| `tiles.4bpp` | `0x1A48` | `0x7400` (928 4bpp tiles) | `020`, ladder `25710111315` | `0x06000000` |
| `palette_banks.png` | raw | `0x200` (16 BGR555 banks) | uncompressed | palette-memory copy |

The tile data and tilemaps intentionally remain native sources. Their shared
palette is represented by an indexed 256-colour swatch PNG, but no combined
scene PNG is claimed: the exact screen compositor and its runtime layer order
have not yet been established.

## Four-region evidence

Each compressed stream, decoded payload, and palette range is byte-identical
in JP, US, EU, and DE.

| Region | First stream | Palette |
| --- | ---: | ---: |
| JP | `0x4B5D9C` | `0x4B7AA8` |
| US | `0x72FC34` | `0x731940` |
| EU | `0x72FC90` | `0x73199C` |
| DE | `0x4B6FA0` | `0x4B8CAC` |

The checked packed/data SHA-256 values, in source order, are:

```text
dac12010416069a87ce5c9a1cce09ffea27752538ad96b3d852067f4dfac2ff5
7337a182c0e3095afb5c988987362f741f3f00349c5695770114ecd67c07490f
2888335b90c9eb97f6070deac4405a291ada4de4bd88808231aaf5177caf2b0b
f00f6c6244f3c5497846998979764889717faf5eb805d1630b36001e60ece437
```

## Build and linkage

```console
make gfx-ui-scene-080ae7d0-all
make gfx-ui-scene-080ae7d0-patch-test
```

The normal `%.gba` recipe regenerates these sources first, then patches only
the listed original ranges after `objcopy`. It refuses to patch a target range
that is neither the retail baseline nor the matching generated output. A
modified compressed stream must fit its original ROM slot; otherwise the build
reports the required size instead of silently overwriting following data.
