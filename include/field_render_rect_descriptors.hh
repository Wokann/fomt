#ifndef FIELD_RENDER_RECT_DESCRIPTORS_HH
#define FIELD_RENDER_RECT_DESCRIPTORS_HH

#include "field.hh"

// Rectangle patches copy all four bytes; field-plot updates write only
// bit 0 of the first halfword and bits 1..15 of the second halfword.
// Their meanings and the untouched bits remain unknown.
struct FieldRenderTileAttributes
{
    bool unk_00_00 : 1;
    u32 unk_00_01 : 15;
    u16 unk_02_00 : 1;
    u16 unk_02_01 : 15;
};

typedef char FieldRenderTileAttributesSizeCheck[sizeof(FieldRenderTileAttributes) == 4 ? 1 : -1];

struct FieldRenderRectDescriptor
{
    u8 width;
    u8 height;
    void const * source_buffers[3];
    void const * lookup_values;
    void const * lookup_indices;
};

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
    FIELD_RENDER_RECT_DESCRIPTOR_COUNT = 82,
};

extern FieldRenderRectDescriptor const gFieldRenderRectDescriptors[FIELD_RENDER_RECT_DESCRIPTOR_COUNT];

#endif // FIELD_RENDER_RECT_DESCRIPTORS_HH
