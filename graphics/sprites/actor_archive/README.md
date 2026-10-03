# Actor archive

Edit `native_tiles.png` for pixels and the independent `palettes_*.pal` files
for colors. Each 4-bit grayscale atlas pixel stores a native palette index,
not an RGB color. The atlas stores all 24,398 tiles in physical table order,
including OAM-covered pixels and tiles belonging to unreferenced descriptors.
Preserve palette indexes even when two entries have the same RGB color.

Generic gbagfx rules produce `native_tiles.4bpp` and the `.gbapal` files beside
their sources. The atlas rule excludes its final two image-grid padding cells.
Each PAL has at most 256 colors (sixteen banks); the last PAL contains exactly
32 colors. `archive.inc` directly includes these outputs between the explicit
native archive tables. JP, US, EU, and DE use the same archive bytes at their
respective physical addresses. No Python overlay, baseline ROM, intermediate
source-archive template, or post-link patch is part of this compilation path.

`full/frame_NNNN.png` is an OAM-composited reference view, not a build input.
The archive contains 3,009 descriptor slots, of which 2,963 are referenced by
the game animation table. The remaining 46 are preserved in the source tables
and native atlas. Frame names retain the descriptor IDs because several
animation selectors can share a frame. Existing character-specific READMEs
document identified selector groups and are not additional build inputs.

Use `make gfx-actors` to compile this archive's images and palettes, or
`make gfx-actors-all` for optional byte comparisons against all four ROMs.
