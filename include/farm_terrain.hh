#ifndef FARM_TERRAIN_HH
#define FARM_TERRAIN_HH

#include "field_render_rect_descriptors.hh"

struct Farm;

EXTERN_C
// Still native: horizontal fit is checked, but destination height is not.
void ApplyMapTerrainPatch(FieldRenderTileAttributes * destination, u32 width,
    FieldRenderRectDescriptor const & patch, u32 x, u32 y);
// Winter uses the low input byte; nonzero selects the alternate map and patches.
void InitializeFarmTerrain(FieldRenderTileAttributes * destination,
    Farm const & farm, u8 winter);
EXTERN_C_END

#endif // FARM_TERRAIN_HH
