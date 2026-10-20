#include "actor_state.hh"
#include "field_render_rect_descriptors.hh"

u8 const gActorStateMaxValues[] = {
    10, 10, 255, 10, 10, 255,
};

#include FOMT_TEXT_INCLUDE(actor_state_1.cc)

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

#include FOMT_TEXT_INCLUDE(actor_state_2.cc)

EC FieldRenderPatchPlacement SelectMapFlagPatch(u32 const & flags, u32 index, bool winter)
{
    bool present = false;
    if (index <= 13)
        present = (flags & (1 << (index & 31))) != 0;

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

extern "C" u32 func_0809C3E0(ActorStateSlots & self, u32 index)
{
    u32 result = 0;

    if (self.unk_00[index] != 0)
    {
        u8 * const values = self.unk_0C;
        u8 & value = values[index];

        if (value < gActorStateMaxValues[index])
            ++value;
        else
        {
            self.unk_00[index] = 0;
            self.unk_06[index] = 1;
            result = 1;
        }
    }

    return result;
}

// Initializing the 22 known flags preserves the two unknown upper bits at
// +0x626 and the padding at +0x627. Every cell's three fields are cleared.
ActorStateGrid::ActorStateGrid()
    : unk_00(0),
      flag_624_0(false), flag_624_1(false), flag_624_2(false), flag_624_3(false),
      flag_624_4(false), flag_624_5(false), flag_624_6(false), flag_624_7(false),
      flag_625_0(false), flag_625_1(false), flag_625_2(false), flag_625_3(false),
      flag_625_4(false), flag_625_5(false), flag_625_6(false), flag_625_7(false),
      flag_626_0(false), flag_626_1(false), flag_626_2(false),
      flag_626_3(false), flag_626_4(false), flag_626_5(false)
{
    for (u32 row = 0; row < 28; ++row) {
        for (u32 column = 0; column < 28; ++column) {
            cells[row][column].unk_00 = 0;
            cells[row][column].unk_04 = 0;
            cells[row][column].unk_0A = 0;
        }
    }
}

EC u32 func_0809D8D4(ActorStateGrid const * grid, u32 column, u32 row)
{
    return grid->cells[row][column].unk_00;
}

EC u8 func_0809DFAC(ActorStateGrid const & state)
{
    u8 result = state.flag_625_5;
    if (state.flag_625_6)
        ++result;
    if (state.flag_625_7)
        ++result;
    if (state.flag_626_0)
        ++result;
    if (state.flag_626_1)
        ++result;
    if (state.flag_626_2)
        ++result;
    if (state.flag_626_3)
        ++result;
    if (state.flag_626_4)
        ++result;
    if (state.flag_626_5)
        ++result;
    return result;
}

EC u8 func_0809E02C(ActorStateGrid const & state)
{
    u8 result = state.flag_624_1;
    if (state.flag_624_2)
        ++result;
    if (state.flag_624_3)
        ++result;
    if (state.flag_624_4)
        ++result;
    if (state.flag_624_5)
        ++result;
    if (state.flag_624_6)
        ++result;
    if (state.flag_624_7)
        ++result;
    if (state.flag_625_0)
        ++result;
    if (state.flag_625_1)
        ++result;
    return result;
}

EC u8 const * func_0809E0AC(ActorStateGrid const * grid, u32 column, u32 row)
{
    u32 offset = row * 56 + 4;
    u8 const * bytes = reinterpret_cast<u8 const *>(grid);
    bytes += offset;
    bytes += column * 2;
    u16 const value = *reinterpret_cast<u16 const *>(bytes);

    switch ((static_cast<u32>(value) << 28) >> 28)
    {
    case 0:
        return gActorStateGridCellType0Data;
    case 1:
        return gActorStateGridCellType1Data;
    case 2:
        return gActorStateGridCellType2Data;
    case 3:
        return gActorStateGridCellType3Data;
    case 4:
        return gActorStateGridCellType4Data;
    default:
        return 0;
    }
}

EC bool func_0809E174(ActorStateGrid const & state)
{
    return state.flag_624_0;
}

EC bool func_0809E184(ActorStateGrid const & state)
{
    return state.flag_625_2;
}

EC bool func_0809E194(ActorStateGrid const & state)
{
    return state.flag_625_3;
}

EC bool func_0809E1A4(ActorStateGrid const & state)
{
    return state.flag_625_4;
}
