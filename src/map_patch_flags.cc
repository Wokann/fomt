#include "map_patch_flags.hh"
#include "field_render_rect_descriptors.hh"

#include FOMT_TEXT_INCLUDE(map_patch_flags_1.cc)

ActorDataSelectionEntry const gActorDataSelectionEntries[] = {
    { &gFieldRenderRectDescriptors[39], &gFieldRenderRectDescriptors[40], 0x15, 0x0C },
    { &gFieldRenderRectDescriptors[41], &gFieldRenderRectDescriptors[42], 0x0A, 0x02 },
    { &gFieldRenderRectDescriptors[43], &gFieldRenderRectDescriptors[44], 0x24, 0x1B },
    { &gFieldRenderRectDescriptors[45], &gFieldRenderRectDescriptors[46], 0x15, 0x1B },
    { &gFieldRenderRectDescriptors[47], &gFieldRenderRectDescriptors[48], 0x21, 0x19 },
    { &gFieldRenderRectDescriptors[49], &gFieldRenderRectDescriptors[50], 0x0B, 0x19 },
    { &gFieldRenderRectDescriptors[51], &gFieldRenderRectDescriptors[52], 0x1F, 0x10 },
    { &gFieldRenderRectDescriptors[53], &gFieldRenderRectDescriptors[54], 0x05, 0x10 },
    { &gFieldRenderRectDescriptors[59], &gFieldRenderRectDescriptors[60], 0x15, 0x0E },
    { &gFieldRenderRectDescriptors[61], &gFieldRenderRectDescriptors[62], 0x0B, 0x02 },
    { &gFieldRenderRectDescriptors[55], &gFieldRenderRectDescriptors[56], 0x25, 0x02 },
    { &gFieldRenderRectDescriptors[57], &gFieldRenderRectDescriptors[58], 0x06, 0x02 },
    { &gFieldRenderRectDescriptors[17], &gFieldRenderRectDescriptors[16], 0x01, 0x02 },
    { &gFieldRenderRectDescriptors[63], &gFieldRenderRectDescriptors[64], 0x69, 0x3E },
};

#include FOMT_TEXT_INCLUDE(map_patch_flags_2.cc)

MapPatchFlags::MapPatchFlags() : value(0)
{
}

bool MapPatchFlags::IsClear(u32 index) const
{
    return !IsSet(index);
}

EC FieldRenderPatchPlacement SelectMapFlagPatch(MapPatchFlags const & flags, u32 index, bool winter)
{
    bool present = flags.IsSet(index);

    if (present) {
        if (index == 13 && winter) {
            return FieldRenderPatchPlacement(&gFieldRenderRectDescriptors[66],
                gActorDataSelectionEntries[index].tile_x, gActorDataSelectionEntries[index].tile_y);
        }
        return FieldRenderPatchPlacement(gActorDataSelectionEntries[index].present_patch,
            gActorDataSelectionEntries[index].tile_x, gActorDataSelectionEntries[index].tile_y);
    }
    if (index == 13 && winter) {
        return FieldRenderPatchPlacement(&gFieldRenderRectDescriptors[65],
            gActorDataSelectionEntries[index].tile_x, gActorDataSelectionEntries[index].tile_y);
    }
    return FieldRenderPatchPlacement(gActorDataSelectionEntries[index].absent_patch,
        gActorDataSelectionEntries[index].tile_x, gActorDataSelectionEntries[index].tile_y);
}

void MapPatchFlags::Set(u32 index)
{
    if (index <= 13)
        value |= 1 << (index & 31);
}

void MapPatchFlags::Clear(u32 index)
{
    if (index <= 13)
        value &= ~(1 << (index & 31));
}

void MapPatchFlags::ClearAll()
{
    value = 0;
}
