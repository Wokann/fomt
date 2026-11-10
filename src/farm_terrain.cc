#include "farm_terrain.hh"
#include "farm.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "    .cpu arm7tdmi\n"
    "\n"
    "    @ Indexed terrain copying remains native until its C++ matches.\n"
    "    @ Farm initialization is compiled from src/farm_terrain.cc.\n"
    "    thumb_func_start ApplyMapTerrainPatch\n"
    "ApplyMapTerrainPatch:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, sb\n"
    "    mov r6, r8\n"
    "    push {r6, r7}\n"
    "    adds r5, r0, #0\n"
    "    adds r6, r1, #0\n"
    "    adds r4, r2, #0\n"
    "    cmp r5, #0\n"
    "    beq .L080171EC\n"
    "    cmp r6, #0\n"
    "    beq .L080171EC\n"
    "    ldr r2, [r4, #0x14]\n"
    "    cmp r2, #0\n"
    "    beq .L080171EC\n"
    "    ldr r0, [r4, #0x10]\n"
    "    mov r8, r0\n"
    "    cmp r0, #0\n"
    "    beq .L080171EC\n"
    "    ldrb r7, [r4]\n"
    "    adds r0, r3, r7\n"
    "    cmp r0, r6\n"
    "    bhi .L080171EC\n"
    "    lsls r1, r3, #2\n"
    "    adds r1, r5, r1\n"
    "    ldr r0, [sp, #0x1c]\n"
    "    muls r0, r6, r0\n"
    "    lsls r0, r0, #2\n"
    "    adds r5, r1, r0\n"
    "    ldrb r4, [r4, #1]\n"
    "    mov ip, r4\n"
    "    movs r0, #0\n"
    "    cmp r0, ip\n"
    "    bhs .L080171EC\n"
    "    lsls r6, r6, #2\n"
    "    mov sb, r6\n"
    ".L080171C6:\n"
    "    movs r1, #0\n"
    "    adds r6, r0, #1\n"
    "    cmp r1, r7\n"
    "    bhs .L080171E4\n"
    "    mov r3, r8\n"
    "    adds r4, r5, #0\n"
    ".L080171D2:\n"
    "    ldrb r0, [r2]\n"
    "    lsls r0, r0, #2\n"
    "    adds r0, r0, r3\n"
    "    ldr r0, [r0]\n"
    "    stm r4!, {r0}\n"
    "    adds r2, #1\n"
    "    adds r1, #1\n"
    "    cmp r1, r7\n"
    "    blo .L080171D2\n"
    ".L080171E4:\n"
    "    add r5, sb\n"
    "    adds r0, r6, #0\n"
    "    cmp r0, ip\n"
    "    blo .L080171C6\n"
    ".L080171EC:\n"
    "    pop {r3, r4}\n"
    "    mov r8, r3\n"
    "    mov sb, r4\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r0}\n"
    "    bx r0\n"
);


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
