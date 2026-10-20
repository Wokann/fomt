#include "farm_terrain.hh"
#include "farm.hh"

EC void InitializeFarmTerrain(FieldRenderTileAttributes * destination,
    Farm const & farm, u8 winter)
{
    MapData const * data = GetMapData(winter != 0);
    u32 width = data->width;
    u32 height = data->height;
    for (u32 index = 0; index < width * height; ++index)
        destination[index] = static_cast<FieldRenderTileAttributes const *>(data->terrain_data)[
            static_cast<u8 const *>(data->terrain_map)[index]];

    for (u32 row = 0; row < Farm::FIELD_HEIGHT; ++row) {
        u32 y = row * 2 + 22;
        for (u32 column = 0; column < Farm::FIELD_WIDTH; ++column) {
            u32 x = column * 2 + 34;
            u32 offset = x + y * width;
            destination[offset].unk_00_00 =
                destination[offset + 1].unk_00_00 =
                destination[offset + width].unk_00_00 =
                destination[offset + width + 1].unk_00_00 =
                    farm.field.PlotAt(column, row).IsTerrainBlocking();
        }
    }

    switch (farm.farm_house.GetUpgradeLevel()) {
    case 0:
        ApplyMapTerrainPatch(destination, width,
            winter ? gFarmHouseLevel0WinterPatch : gFarmHouseLevel0Patch, 26, 3);
        break;
    case 1:
        ApplyMapTerrainPatch(destination, width,
            winter ? gFarmHouseLevel1WinterPatch : gFarmHouseLevel1Patch, 18, 3);
        break;
    case 2:
        ApplyMapTerrainPatch(destination, width,
            winter ? gFarmHouseLevel2WinterPatch : gFarmHouseLevel2Patch, 10, 2);
        break;
    }
    switch (farm.barn.GetUpgradeLevel()) {
    case 0:
        ApplyMapTerrainPatch(destination, width,
            winter ? gBarnLevel0WinterPatch : gBarnLevel0Patch, 58, 2);
        break;
    case 1:
        ApplyMapTerrainPatch(destination, width,
            winter ? gBarnLevel1WinterPatch : gBarnLevel1Patch, 58, 2);
        break;
    }
    switch (farm.coop.GetUpgradeLevel()) {
    case 0:
        ApplyMapTerrainPatch(destination, width,
            winter ? gCoopLevel0WinterPatch : gCoopLevel0Patch, 14, 52);
        break;
    case 1:
        ApplyMapTerrainPatch(destination, width,
            winter ? gCoopLevel1WinterPatch : gCoopLevel1Patch, 14, 52);
        break;
    }
}
