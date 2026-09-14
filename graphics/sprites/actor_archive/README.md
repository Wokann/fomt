# Actor archive frames

`full/` is the sole editable source set for the native actor archive.  It has
one palette-indexed, OAM-composited PNG for each frame descriptor referenced by
the retail animation table: `frame_0000.png` through the highest referenced
descriptor ID.  A file name is deliberately the native frame ID, not an
inferred character name, because one frame may be shared by multiple animation
selectors.

`tools/actor_archive.py` obtains geometry, OAM composition, tile ownership and
palette selection directly from the archive in the selected base ROM.  No JSON
layout file participates in export, rebuild or link.  The Makefile passes the
full native selector range (`0x000-0x9F6`) to the tool and rebuilds its shared
tile table into `build/<region>/graphics/sprites/shared/actor_tiles.4bpp`.

The archive contains 3,009 descriptor slots, but only 2,963 are referenced by
the game animation table.  The remaining 46 have no retail caller and are
preserved from the original native table rather than exported as invented
assets.  The existing character-specific README files document selector groups
that have been independently identified; they are descriptive references, not
additional build inputs.
