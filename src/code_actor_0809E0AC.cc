#include "actor_state.hh"

extern u8 const gActorStateGridCellType0Data[];
extern u8 const gActorStateGridCellType1Data[];
extern u8 const gActorStateGridCellType2Data[];
extern u8 const gActorStateGridCellType3Data[];
extern u8 const gActorStateGridCellType4Data[];

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
