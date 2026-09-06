#include "actor_state.hh"

EC u32 func_0809D8D4(ActorStateGrid const * grid, u32 column, u32 row)
{
    u32 offset = column * 2;
    offset += row * 56;
    u8 const * bytes = reinterpret_cast<u8 const *>(grid);
    bytes += offset;
    return (static_cast<u32>(bytes[4]) << 28) >> 28;
}
