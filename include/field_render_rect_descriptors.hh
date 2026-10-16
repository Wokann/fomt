#ifndef FIELD_RENDER_RECT_DESCRIPTORS_HH
#define FIELD_RENDER_RECT_DESCRIPTORS_HH

#include "field.hh"

// A patch lookup entry is copied as one opaque four-byte tile attribute.
// Its individual bits are not assigned meanings by the recovered writer.
struct FieldRenderTileAttributes
{
    u32 unk_00;
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

enum
{
    FIELD_RENDER_RECT_DESCRIPTOR_COUNT = 82,
};

extern FieldRenderRectDescriptor const gFieldRenderRectDescriptors[FIELD_RENDER_RECT_DESCRIPTOR_COUNT];

#endif // FIELD_RENDER_RECT_DESCRIPTORS_HH
