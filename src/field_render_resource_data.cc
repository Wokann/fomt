#include "field_render_resource_data.hh"
#include "gbaio.h"

// These are terrain lookup objects, not anonymous zero padding. The 2x3
// blocked patch and twelve 3x5 clear patches address them through their
// descriptors. The following object's alignment supplies each index tail.
FieldRenderTileAttributes const gFieldRenderBlockedTileAttributes[] = {
    { true, false, 0, 0, 0 },
};

u8 const gFieldRenderBlockedPatchIndices[][2] = {
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
};

FieldRenderTileAttributes const gFieldRenderClearTileAttributes[] = {
    { false, false, 0, 0, 0 },
};

u8 const gFieldRenderClearPatchIndices[][3] = {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
};
