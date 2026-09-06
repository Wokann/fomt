#include "map_data.hh"

extern "C" MapData const * GetMapData(u32 map_id) SECTION(".text.get_map_data");

extern "C" MapData const * GetMapData(u32 map_id)
{
    return gMapData + map_id;
}
