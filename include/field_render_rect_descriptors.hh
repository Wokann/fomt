#ifndef FIELD_RENDER_RECT_DESCRIPTORS_HH
#define FIELD_RENDER_RECT_DESCRIPTORS_HH

#include "map_data.hh"

struct FieldRenderRectDescriptor
{
    u8 width;
    u8 height;
    void const * source_buffers[3];
    void const * lookup_values;
    void const * lookup_indices;
};

// Native terrain patching consumes these two pointer fields directly.
typedef char FieldRenderRectDescriptorSizeCheck[sizeof(FieldRenderRectDescriptor) == 0x18 ? 1 : -1];
typedef char FieldRenderRectDescriptorHeightCheck[offsetof(FieldRenderRectDescriptor, height) == 1 ? 1 : -1];
typedef char FieldRenderRectDescriptorValuesCheck[offsetof(FieldRenderRectDescriptor, lookup_values) == 0x10 ? 1 : -1];
typedef char FieldRenderRectDescriptorIndicesCheck[offsetof(FieldRenderRectDescriptor, lookup_indices) == 0x14 ? 1 : -1];

struct FieldRenderPatchPlacement
{
    FieldRenderPatchPlacement(FieldRenderRectDescriptor const * patch, u32 x, u32 y)
        : patch(patch), x(x), y(y) {}

    FieldRenderRectDescriptor const * patch;
    u32 x;
    u32 y;
};

typedef char FieldRenderPatchPlacementSizeCheck[sizeof(FieldRenderPatchPlacement) == 12 ? 1 : -1];
typedef char FieldRenderPatchPlacementXCheck[offsetof(FieldRenderPatchPlacement, x) == 4 ? 1 : -1];
typedef char FieldRenderPatchPlacementYCheck[offsetof(FieldRenderPatchPlacement, y) == 8 ? 1 : -1];

enum
{
    // Fourteen named building variants precede this remaining array.
    FIELD_RENDER_RECT_DESCRIPTOR_COUNT = 68,
};

extern FieldRenderRectDescriptor const gFarmHouseLevel0Patch;
extern FieldRenderRectDescriptor const gFarmHouseLevel0WinterPatch;
extern FieldRenderRectDescriptor const gFarmHouseLevel1Patch;
extern FieldRenderRectDescriptor const gFarmHouseLevel1WinterPatch;
extern FieldRenderRectDescriptor const gFarmHouseLevel2Patch;
extern FieldRenderRectDescriptor const gFarmHouseLevel2WinterPatch;
extern FieldRenderRectDescriptor const gBarnLevel0Patch;
extern FieldRenderRectDescriptor const gBarnLevel0WinterPatch;
extern FieldRenderRectDescriptor const gBarnLevel1Patch;
extern FieldRenderRectDescriptor const gBarnLevel1WinterPatch;
extern FieldRenderRectDescriptor const gCoopLevel0Patch;
extern FieldRenderRectDescriptor const gCoopLevel0WinterPatch;
extern FieldRenderRectDescriptor const gCoopLevel1Patch;
extern FieldRenderRectDescriptor const gCoopLevel1WinterPatch;

extern FieldRenderRectDescriptor const gFieldRenderRectDescriptors[FIELD_RENDER_RECT_DESCRIPTOR_COUNT];

#endif // FIELD_RENDER_RECT_DESCRIPTORS_HH
