# Intro Scene object pipeline audit

This note records what is proven about the twenty editable native object-tile
streams.  It deliberately does **not** assign character names, frame sizes, or
palette banks to those streams: those properties have not yet been recovered
from the runtime resource path.

## Proven loading contract

`func_0805FBB8` receives the scene updater's runtime context base, advances
its object-source storage address by `0x20`, then walks
`gIntroSceneUnpackSources` exactly twenty times. Every iteration calls
`Unpack` and advances that destination by `0x500`. This is not a literal VRAM
address passed by a static resource table: the sole caller, `func_0805EE44`,
passes its live scene context as the argument after initializing its own
state. Consequently:

- every `object_00.4bpp` through `object_19.4bpp` source is exactly `0x500`
  decoded bytes (40 native 4bpp tiles);
- the numbered source order is a real runtime staging order, not an inferred
  animation or character order;
- the shared source set can be rebuilt as twenty independent fixed-capacity
  Raw-LZ streams without changing the game's loader contract.

## Proven RAM staging layout

The call chain fixes the storage contract more precisely than a generic OBJ
upload description. `func_0805FCD0` allocates `0x6430` bytes for the scene
work object through `func_0805ED4C`; `func_0805FD44` then enters
`func_0805EE44`, which calls `func_0805FBB8` with that same object. The latter
starts its source cursor at `scene + 0x20` and writes twenty consecutive
`0x500`-byte decoded streams:

```text
scene + 0x0020  object_00  0x500 bytes
scene + 0x0520  object_01  0x500 bytes
...
scene + 0x5F20  object_19  0x500 bytes
scene + 0x6420  end of object storage
```

Thus the object payload occupies exactly `0x6400` bytes of the `0x6430`-byte
scene allocation, leaving its final `0x10` bytes outside the stream storage.
`func_0805FBB8` also initializes several literal VRAM ranges for the scene,
but the twenty `Unpack` destinations themselves are this runtime RAM buffer,
not those VRAM ranges. Any future image compositor must therefore prove the
later RAM-to-renderer/object-record path for a particular source; it cannot
legitimately infer an OAM layout merely from the loading stride.

The four retail FoMT regions have identical packed payloads and identical
decoded payloads for all twenty source streams.  Only their ROM offsets vary.
`make gfx-intro-objects-all` verifies every region against its own original
range.

## Verified separation from nearby archives

The object-tile loader is `func_0805FBB8`. Its draw path ultimately calls the
engine-wide OAM emitter `func_0805E99C`, which consumes caller-supplied
eight-byte piece records and creates transient hardware OAM entries. The
loader itself supplies no static one-record-per-object descriptor table.

`func_08000914` separately unpacks `gUnk_08747A74` (or the JP/DE physical
counterpart) and constructs an `IndexedResourceArchive` from the result.  Its
own layout has now been verified: every selected 16-byte descriptor closes
over its eight-byte OAM range, native tile range, and BGR555 palette index.
`indexed_archive/{jp,us_eu,de}/full/` contains its complete OAM-composited
frames and rebuilds each regional packed slot losslessly.

That does not make it the OAM table for the twenty object streams.  Its
decoded contracts are JP `0x69E4` / `120`, US and EU `0x4C0C` / `220`, and DE
`0x4C64` / `220`; their layouts, tiles, and palettes are regional data and do
not reference the twenty shared `0x500` object payloads.  It is a separate
managed archive, not evidence that the object stream order has a frame or
character identity.

This removes a tempting but false shortcut: sharing the twenty object tile
streams does not make their OAM descriptors, palettes, frame order, or
character identity shared or statically recoverable.

## Runtime-target recheck

The object loader also does not establish a fixed object-to-VRAM mapping.
`func_0805EE44` receives a scene-context value through its caller and passes
that runtime value directly to `func_0805FBB8`. The latter reserves the
leading `0x20` bytes and then supplies successive `+0x500` destinations to
`Unpack`. The loader therefore proves a bounded native allocation stride, but
not a literal VRAM base or a permanent identity for any numbered source.

Likewise, `func_0805E99C` is a generic emitter: it receives caller-provided
eight-byte OAM piece records and a runtime handle, then writes transient
hardware OAM entries. The Intro Scene call sites resolve those records through
scene-state objects rather than through a static twenty-entry descriptor table
adjacent to `gIntroSceneUnpackSources`. This independently confirms that the
numbered object source order is a loading order only.

## Address-space constraint for ROM analysis

The assembly symbol `func_0805E99C` is a cross-localization logical name; it
is not automatically the same physical JP address.  The JP code carrier maps
that function to physical entry `0x0805E6E0` (`jp_code_0803ee_func` source
range `0x5E6E0..0x5E968`), whereas FoMT-US has the equivalent code at its
logical `0x0805E99C` location.  Ghidra analysis must therefore use a physical
address for the ROM being inspected.

Decompiling the physical JP entry establishes the generic hardware-OAM
contract: it walks caller-supplied eight-byte piece records, derives each
piece's shape, size, coordinates, tile index, palette bank and flip bits, and
writes a transient entry into the caller's OAM buffer.  It confirms the
emitter format, but it does **not** attach any static Intro object stream to a
particular piece-record sequence.  This distinction is why the source-order
list still cannot be converted into independent full PNG assets.

## Why a complete PNG cannot yet be emitted

The same initialization path subsequently drives the Intro Scene through
runtime `IndexedResourceHandle` objects.  In the JP-disassembled scene code,
`func_08000914` creates handles from the scene's indexed-resource provider;
its draw/update paths resolve resource entries and submit transient draw
records.  The object loader's twenty compressed streams are not accompanied by
a static, one-record-per-stream OAM table in the data block.

Thus a renderer that simply lays each 40-tile payload into a rectangle would
invent all of the following:

1. which resource entry selects which tile range;
2. OAM shape, size, tile offset, flipping, and draw order;
3. frame position and animation timing; and
4. the palette bank selected for that draw.

That would be a reference illustration at best, not an editable source or a
verified reconstruction.  No such PNG is checked in.

## Required next evidence

A full-frame pipeline can be added only after one concrete scene resource is
traced end-to-end:

1. identify its indexed-resource descriptor and its OAM-piece range;
2. prove the selected object-tile slot and palette bank at the draw call;
3. render the OAM pieces from the 4bpp source using that exact metadata;
4. map every editable pixel back to the native tile byte(s), as the actor and
   portrait archive tools already do; and
5. verify the unchanged rebuild against JP, US, EU, and DE, followed by a
   one-pixel fixed-slot edit fixture.

The source representation will remain the native `.4bpp` payloads.  Any
future full PNG is an editing view derived from the runtime descriptors, not a
JSON-controlled replacement layout.
