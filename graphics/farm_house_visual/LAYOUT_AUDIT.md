# FarmHouse visual layout audit

This note records what the retail code proves about the seven managed tile
streams, and why they must not be presented as a single static full-image
PNG yet.

## Proven composition operation

`func_080A5BD8` receives a map instance, a `FarmHouseVisualDescriptor`, and
tile-space `x`/`y` coordinates.  It obtains the active map width through
`GetMapData`, then uses the embedded `FieldRenderRectDescriptor` as follows:

1. `width` and `height` select a rectangular area.
2. Each non-null `source_buffers[0..2]` supplies one 16-bit tilemap row
   stream.  The function copies every row to the selected position in the
   active map layer.  The seven FarmHouse descriptors use fourteen non-null
   buffers in total; their exact bounds are `width * height * 2`, and each is
   now managed as a native `.tilemap` source.
3. When both `lookup_values` and `lookup_indices` are non-null, the function
   additionally writes lookup-selected 32-bit entries into a fourth active
   map buffer.  `LOOKUP_AUDIT.md` records the exact code-backed lower bounds:
   all seven rectangles use only lookup entries 0 and 1 across every retail
   region.  This is field metadata, not a palette or independently editable
   image resource.

The game calls this operation many times with different FarmHouse feature
states and coordinates.  For example, code around `0x080A66E4` conditionally
places descriptor 2 at `(0x13, 0x11)`, descriptor 6 at `(0x16, 0x10)`,
descriptor 1 at `(0x13, 0x11)`, descriptor 0 at `(8, 0x0C)`, and descriptor
4 at `(0x17, 0x17)`.  Other branches place the same descriptors at different
coordinates.  Thus the descriptor is a state-dependent **tilemap patch**,
not a self-contained screen layout.

## Proven tile upload

The house setup branch around `0x080A924C` conditionally calls `Unpack` on a
descriptor's `+0x18` source.  Its `+0x1C` field is shifted by five and added
to VRAM base `0x06000000`; these are the seven managed native 4bpp streams.
The descriptor's `+0x20` fields are separately copied by nearby setup code.
The code loads `+0x28` as a palette-bank selector and `+0x29` as a number of
0x20-byte BGR555 banks, then invokes the DMA helper on that exact range.  The
ten non-null sources are now managed as native `.gbapal` files.  This proves
their buffers and destination-bank units, but not a complete static scene or
the broader palette layout surrounding each state.

## Required evidence before a full PNG becomes source

A trustworthy editable screen needs all of the following for a named
FarmHouse state:

- the base map layer selected by that state;
- the exact ordered set of `func_080A5BD8` patch calls and their coordinates;
- every loaded tile stream and destination tile index;
- the selected BGR555 palette banks; and
- the BG priority/visibility configuration used to display the result.

The current evidence proves the tile streams and patch buffers universally.
A renderer may eventually create state-labelled **reference** PNGs once all
five inputs are recovered, but it must keep the native tile streams and patch
data as the authoritative editable source.  No JSON layout sidecar is
introduced.
