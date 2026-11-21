#include "calendar.hh"
#include "map_terrain.hh"
#include "world_map.hh"
#include "map_patch_flags.hh"
#include "compression.hh"
#include "actor.hh"
#include "map_data.hh"
#include "map_selection.h"
#include "field_render_rect_descriptors.hh"
#include "field_render_resource_data.hh"
#include "hardware_dma.hh"
#include "hardware_context.hh"
#include "hardware_dma_queue.hh"
#include "time_of_day_types.hh"
#include "gbasvc.h"
#include "gbaio.h"
#include <string.h>
#include <algorithm>

GameSceneWorldMap::GameSceneWorldMap()
    : map(MAP_NONE), map_data_id(MAP_DATA_COUNT), x(), y(),
      tiles_changed(0), view_changed(false), time_palette_changed(false),
      tile_attributes(nullptr), tile_patch_countdown(0), movement_frames(0)
{
    for (u32 layer = 0; layer < ARRAY_COUNT(time_palette_buffers); ++layer)
        time_palette_buffers[layer] = new u16[240];
    for (u32 layer = 0; layer < ARRAY_COUNT(tile_layers); ++layer)
        tile_layers[layer] = new u16[0x3C80];
    tile_attributes = new FieldRenderTileAttributes[0x3C80];
}

GameSceneWorldMap::~GameSceneWorldMap()
{
    delete[] tile_attributes;
    for (u32 layer = 0; layer < ARRAY_COUNT(tile_layers); ++layer)
        delete[] tile_layers[layer];
    for (u32 layer = 0; layer < ARRAY_COUNT(time_palette_buffers); ++layer)
        delete[] time_palette_buffers[layer];
}

void GameSceneWorldMap::Update()
{
    GameSceneWorldMap * map = this;
    if (map->movement_frames != 0) {
        map->x.q16 += map->step_x_q16;
        map->y.q16 += map->step_y_q16;
        --map->movement_frames;
        map->view_changed = true;
    }
    // These are layout indices, not the logical MAP_* identifiers.
    switch (map->map_data_id) {
    case 14:
        map->layout_animation_4.Tick(gMapLayoutTileAnimation8);
        map->layout_animation_5.Tick(gMapLayoutTileAnimation9);
        map->layout_animation_6.Tick(gMapLayoutTileAnimation10);
        break;
    case 15:
        map->layout_animation_4.Tick(gMapLayoutTileAnimation11);
        map->layout_animation_5.Tick(gMapLayoutTileAnimation12);
        map->layout_animation_6.Tick(gMapLayoutTileAnimation13);
        break;
    case 60:
        map->layout_animation_8.Tick(gMapLayoutTileAnimation17);
        break;
    case 31:
        map->layout_animation_9.Tick(gMapLayoutTileAnimation15);
        break;
    case 8:
        map->layout_animation_7.Tick(gMapLayoutTileAnimation14);
        break;
    case 9:
        map->layout_animation_7.Tick(gMapLayoutTileAnimation16);
        break;
    case 6:
        map->layout_animation_2.Tick(gMapLayoutTileAnimation4);
        map->layout_animation_3.Tick(gMapLayoutTileAnimation5);
        break;
    case 7:
        map->layout_animation_2.Tick(gMapLayoutTileAnimation6);
        map->layout_animation_3.Tick(gMapLayoutTileAnimation7);
        break;
    case 0:
    case 62:
    case 63:
        map->layout_animation_0.Tick(gMapLayoutTileAnimation0);
        map->layout_animation_1.Tick(gMapLayoutTileAnimation2);
        break;
    case 1:
        map->layout_animation_0.Tick(gMapLayoutTileAnimation1);
        map->layout_animation_1.Tick(gMapLayoutTileAnimation3);
        break;
    }
}

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".include \"asm/gba.inc\"\n"
    ".align 2, 0\n"
    "thumb_func_start Draw__17GameSceneWorldMapR16HardwareDmaQueueR20HardwareDisplayStateR18HardwareLinkedList\n"
    "Draw__17GameSceneWorldMapR16HardwareDmaQueueR20HardwareDisplayStateR18HardwareLinkedList:\n"
    "push {r4, r5, r6, r7, lr}\n"
    "mov r7, sl\n"
    "mov r6, sb\n"
    "mov r5, r8\n"
    "push {r5, r6, r7}\n"
    "sub sp, #0x5c\n"
    "adds r6, r0, #0\n"
    "mov sl, r1\n"
    "str r2, [sp, #0x1c]\n"
    "str r3, [sp, #0x20]\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x29\n"
    "ldrb r0, [r4]\n"
    "cmp r0, #0\n"
    "bne .Lgame_map_after_update_0020\n"
    "b .Lgame_map_after_update_0172\n"
    ".Lgame_map_after_update_0020:\n"
    "ldr r0, [r6, #4]\n"
    "bl GetMapData\n"
    "movs r2, #0xa\n"
    "ldrsh r1, [r6, r2]\n"
    "mov ip, r1\n"
    "movs r3, #0xe\n"
    "ldrsh r7, [r6, r3]\n"
    "ldrh r0, [r0, #0x20]\n"
    "str r0, [sp, #0x24]\n"
    "mov r0, ip\n"
    "cmp r1, #0\n"
    "bge .Lgame_map_after_update_003c\n"
    "adds r0, #7\n"
    ".Lgame_map_after_update_003c:\n"
    "asrs r1, r0, #3\n"
    "adds r0, r7, #0\n"
    "cmp r7, #0\n"
    "bge .Lgame_map_after_update_0046\n"
    "adds r0, r7, #7\n"
    ".Lgame_map_after_update_0046:\n"
    "asrs r0, r0, #3\n"
    "ldr r5, [sp, #0x24]\n"
    "muls r0, r5, r0\n"
    "adds r1, r1, r0\n"
    "str r1, [sp, #0x28]\n"
    "movs r0, #0\n"
    "str r0, [sp, #0x2c]\n"
    "str r4, [sp, #0x38]\n"
    "adds r1, r6, #0\n"
    "adds r1, #0x10\n"
    "str r1, [sp, #0x34]\n"
    "adds r2, r6, #0\n"
    "adds r2, #0x80\n"
    "str r2, [sp, #0x48]\n"
    "ldr r3, [sp, #0x20]\n"
    "ldr r3, [r3, #8]\n"
    "str r3, [sp, #0x40]\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x5c\n"
    "str r4, [sp, #0x44]\n"
    "mov r5, sp\n"
    "str r5, [sp, #0x30]\n"
    "movs r0, #0x68\n"
    "adds r0, r0, r6\n"
    "mov r8, r0\n"
    "movs r1, #0\n"
    "str r1, [sp, #0x4c]\n"
    ".Lgame_map_after_update_007c:\n"
    "ldr r2, [sp, #0x2c]\n"
    "lsls r4, r2, #2\n"
    "ldr r3, [sp, #0x34]\n"
    "adds r0, r3, r4\n"
    "ldr r5, [r0]\n"
    "cmp r5, #0\n"
    "beq .Lgame_map_after_update_0140\n"
    "ldr r0, .Lgame_map_after_update_012c\n"
    "adds r0, r4, r0\n"
    "ldr r0, [r0]\n"
    "str r0, [sp, #0x50]\n"
    "ldr r0, .Lgame_map_after_update_0130\n"
    "adds r0, r4, r0\n"
    "ldr r2, [r0]\n"
    "ldr r0, .Lgame_map_after_update_0134\n"
    "adds r0, r4, r0\n"
    "ldr r0, [r0]\n"
    "mov sb, r0\n"
    "lsls r1, r0, #8\n"
    "movs r3, #0xf8\n"
    "lsls r3, r3, #5\n"
    "adds r0, r3, #0\n"
    "ands r1, r0\n"
    "movs r0, #0x40\n"
    "orrs r1, r0\n"
    "orrs r2, r1\n"
    "ldr r0, [sp, #0x30]\n"
    "strh r2, [r0]\n"
    "ldr r1, [sp, #0x50]\n"
    "movs r0, #0xfc\n"
    "lsls r0, r0, #0x18\n"
    "adds r3, r1, r0\n"
    "ldr r1, [sp, #0x1c]\n"
    "adds r3, r1, r3\n"
    "strh r2, [r3]\n"
    "ldr r0, .Lgame_map_after_update_0138\n"
    "adds r0, r4, r0\n"
    "ldr r1, [r0]\n"
    "mov r2, sp\n"
    "mov r0, ip\n"
    "cmp r0, #0\n"
    "bge .Lgame_map_after_update_00d2\n"
    "adds r0, #7\n"
    ".Lgame_map_after_update_00d2:\n"
    "asrs r0, r0, #3\n"
    "lsls r0, r0, #3\n"
    "mov r3, ip\n"
    "subs r0, r3, r0\n"
    "strh r0, [r2]\n"
    "movs r2, #0xfc\n"
    "lsls r2, r2, #0x18\n"
    "adds r1, r1, r2\n"
    "ldr r3, [sp, #0x1c]\n"
    "adds r1, r3, r1\n"
    "strh r0, [r1]\n"
    "ldr r0, .Lgame_map_after_update_013c\n"
    "adds r0, r4, r0\n"
    "ldr r0, [r0]\n"
    "mov r2, sp\n"
    "adds r1, r7, #0\n"
    "cmp r7, #0\n"
    "bge .Lgame_map_after_update_00f8\n"
    "adds r1, r7, #7\n"
    ".Lgame_map_after_update_00f8:\n"
    "asrs r1, r1, #3\n"
    "lsls r1, r1, #3\n"
    "subs r1, r7, r1\n"
    "strh r1, [r2]\n"
    "movs r4, #0xfc\n"
    "lsls r4, r4, #0x18\n"
    "adds r0, r0, r4\n"
    "ldr r2, [sp, #0x1c]\n"
    "adds r0, r2, r0\n"
    "strh r1, [r0]\n"
    "ldr r3, [sp, #0x28]\n"
    "lsls r0, r3, #1\n"
    "adds r0, r5, r0\n"
    "mov r4, r8\n"
    "str r0, [r4]\n"
    "adds r1, r6, #0\n"
    "adds r1, #0x6c\n"
    "ldr r5, [sp, #0x4c]\n"
    "adds r1, r1, r5\n"
    "mov r2, sb\n"
    "lsls r0, r2, #0xb\n"
    "movs r3, #0xc0\n"
    "lsls r3, r3, #0x13\n"
    "adds r0, r0, r3\n"
    "str r0, [r1]\n"
    "b .Lgame_map_after_update_0144\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_012c: .word gWorldMapViewportControlRegisters\n"
    ".Lgame_map_after_update_0130: .word gWorldMapViewportPriorities\n"
    ".Lgame_map_after_update_0134: .word gWorldMapViewportScreenBlocks\n"
    ".Lgame_map_after_update_0138: .word gWorldMapViewportHorizontalScrollRegisters\n"
    ".Lgame_map_after_update_013c: .word gWorldMapViewportVerticalScrollRegisters\n"
    ".Lgame_map_after_update_0140:\n"
    "mov r4, r8\n"
    "str r5, [r4]\n"
    ".Lgame_map_after_update_0144:\n"
    "movs r5, #8\n"
    "add r8, r5\n"
    "ldr r0, [sp, #0x4c]\n"
    "adds r0, #8\n"
    "str r0, [sp, #0x4c]\n"
    "ldr r1, [sp, #0x2c]\n"
    "adds r1, #1\n"
    "str r1, [sp, #0x2c]\n"
    "cmp r1, #2\n"
    "bls .Lgame_map_after_update_007c\n"
    "movs r4, #0\n"
    "mov r2, sp\n"
    "ldrh r3, [r2, #0x24]\n"
    "ldr r2, [sp, #0x48]\n"
    "strh r3, [r2]\n"
    "ldr r5, [sp, #0x40]\n"
    "ldr r2, [r5, #0x10]\n"
    "ldr r0, [sp, #0x20]\n"
    "ldr r1, [sp, #0x44]\n"
    "bl _call_via_r2\n"
    "ldr r7, [sp, #0x38]\n"
    "strb r4, [r7]\n"
    ".Lgame_map_after_update_0172:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x28\n"
    "ldrb r0, [r4]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_0190\n"
    "adds r0, r6, #0\n"
    "adds r0, #0x90\n"
    "ldr r0, [r0]\n"
    "ldr r2, [r0, #0x1c]\n"
    "adds r0, r6, #0\n"
    "mov r1, sl\n"
    "bl _call_via_r2\n"
    "movs r0, #0\n"
    "strb r0, [r4]\n"
    ".Lgame_map_after_update_0190:\n"
    "adds r0, r6, #0\n"
    "adds r0, #0x2a\n"
    "ldrb r1, [r0]\n"
    "str r0, [sp, #0x3c]\n"
    "cmp r1, #0\n"
    "bne .Lgame_map_after_update_019e\n"
    "b .Lgame_map_after_update_02b0\n"
    ".Lgame_map_after_update_019e:\n"
    "ldr r1, [r6, #0x24]\n"
    "add r0, sp, #4\n"
    "ldr r2, .Lgame_map_after_update_01d4\n"
    "movs r3, #0xf0\n"
    "lsls r3, r3, #1\n"
    "bl __21DmaTransferDescriptorPCvPvUi\n"
    "add r0, sp, #4\n"
    "mov r8, r0\n"
    "mov r2, sl\n"
    "ldr r1, [r2, #4]\n"
    "ldr r0, [r2, #0xc]\n"
    "cmp r1, r0\n"
    "beq .Lgame_map_after_update_01d8\n"
    "cmp r1, #0\n"
    "beq .Lgame_map_after_update_01ca\n"
    "adds r0, r1, #0\n"
    "mov r1, r8\n"
    "ldm r1!, {r3, r4, r5}\n"
    "stm r0!, {r3, r4, r5}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lgame_map_after_update_01ca:\n"
    "mov r7, sl\n"
    "ldr r0, [r7, #4]\n"
    "adds r0, #0x10\n"
    "str r0, [r7, #4]\n"
    "b .Lgame_map_after_update_02aa\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_01d4: .word BG_PLTT + PLTT_SIZE_4BPP\n"
    ".Lgame_map_after_update_01d8:\n"
    "str r1, [sp, #0x54]\n"
    "movs r0, #1\n"
    "str r0, [sp, #0x18]\n"
    "mov r0, sl\n"
    "ldr r1, [r0]\n"
    "ldr r2, [sp, #0x54]\n"
    "subs r0, r2, r1\n"
    "asrs r4, r0, #4\n"
    "str r4, [sp, #0x14]\n"
    "add r2, sp, #0x18\n"
    "add r0, sp, #0x14\n"
    "cmp r4, #1\n"
    "bhs .Lgame_map_after_update_01f4\n"
    "adds r0, r2, #0\n"
    ".Lgame_map_after_update_01f4:\n"
    "ldr r0, [r0]\n"
    "adds r0, r4, r0\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_0216\n"
    "lsls r4, r0, #4\n"
    "adds r0, r4, #0\n"
    "bl malloc\n"
    "mov sb, r4\n"
    "cmp r0, #0\n"
    "bne .Lgame_map_after_update_0210\n"
    "mov r0, sb\n"
    "bl RetryMemoryAllocation\n"
    ".Lgame_map_after_update_0210:\n"
    "mov r3, sl\n"
    "ldr r1, [r3]\n"
    "b .Lgame_map_after_update_021a\n"
    ".Lgame_map_after_update_0216:\n"
    "movs r0, #0\n"
    "mov sb, r0\n"
    ".Lgame_map_after_update_021a:\n"
    "adds r4, r0, #0\n"
    "str r4, [sp, #0x58]\n"
    "adds r2, r1, #0\n"
    "adds r3, r4, #0\n"
    "ldr r4, [sp, #0x54]\n"
    "cmp r2, r4\n"
    "beq .Lgame_map_after_update_0242\n"
    ".Lgame_map_after_update_0228:\n"
    "cmp r3, #0\n"
    "beq .Lgame_map_after_update_0238\n"
    "adds r0, r3, #0\n"
    "adds r1, r2, #0\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lgame_map_after_update_0238:\n"
    "adds r2, #0x10\n"
    "adds r3, #0x10\n"
    "ldr r5, [sp, #0x54]\n"
    "cmp r2, r5\n"
    "bne .Lgame_map_after_update_0228\n"
    ".Lgame_map_after_update_0242:\n"
    "adds r4, r3, #0\n"
    "ldr r0, [sp, #0x18]\n"
    "cmp r0, #1\n"
    "bne .Lgame_map_after_update_025e\n"
    "cmp r4, #0\n"
    "beq .Lgame_map_after_update_025a\n"
    "adds r0, r4, #0\n"
    "mov r1, r8\n"
    "ldm r1!, {r2, r3, r7}\n"
    "stm r0!, {r2, r3, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lgame_map_after_update_025a:\n"
    "adds r4, #0x10\n"
    "b .Lgame_map_after_update_0280\n"
    ".Lgame_map_after_update_025e:\n"
    "adds r3, r0, #0\n"
    "adds r2, r4, #0\n"
    "cmp r3, #0\n"
    "beq .Lgame_map_after_update_027e\n"
    ".Lgame_map_after_update_0266:\n"
    "cmp r2, #0\n"
    "beq .Lgame_map_after_update_0276\n"
    "adds r0, r2, #0\n"
    "mov r1, r8\n"
    "ldm r1!, {r4, r5, r7}\n"
    "stm r0!, {r4, r5, r7}\n"
    "ldr r1, [r1]\n"
    "str r1, [r0]\n"
    ".Lgame_map_after_update_0276:\n"
    "subs r3, #1\n"
    "adds r2, #0x10\n"
    "cmp r3, #0\n"
    "bne .Lgame_map_after_update_0266\n"
    ".Lgame_map_after_update_027e:\n"
    "adds r4, r2, #0\n"
    ".Lgame_map_after_update_0280:\n"
    "mov r0, sl\n"
    "ldr r2, [r0, #4]\n"
    "ldr r1, [r0]\n"
    "adds r0, r1, #0\n"
    "cmp r1, r2\n"
    "beq .Lgame_map_after_update_0292\n"
    ".Lgame_map_after_update_028c:\n"
    "adds r0, #0x10\n"
    "cmp r0, r2\n"
    "bne .Lgame_map_after_update_028c\n"
    ".Lgame_map_after_update_0292:\n"
    "cmp r1, #0\n"
    "beq .Lgame_map_after_update_029c\n"
    "adds r0, r1, #0\n"
    "bl free\n"
    ".Lgame_map_after_update_029c:\n"
    "ldr r0, [sp, #0x58]\n"
    "add r0, sb\n"
    "ldr r1, [sp, #0x58]\n"
    "mov r2, sl\n"
    "str r1, [r2]\n"
    "str r4, [r2, #4]\n"
    "str r0, [r2, #0xc]\n"
    ".Lgame_map_after_update_02aa:\n"
    "movs r0, #0\n"
    "ldr r3, [sp, #0x3c]\n"
    "strb r0, [r3]\n"
    ".Lgame_map_after_update_02b0:\n"
    "ldr r0, [r6, #4]\n"
    "cmp r0, #0x41\n"
    "bls .Lgame_map_after_update_02b8\n"
    "b .Lgame_map_after_update_070c\n"
    ".Lgame_map_after_update_02b8:\n"
    "lsls r0, r0, #2\n"
    "ldr r1, .Lgame_map_after_update_02c4\n"
    "adds r0, r0, r1\n"
    "ldr r0, [r0]\n"
    "mov pc, r0\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_02c4: .word .Lgame_map_after_update_02c8\n"
    ".Lgame_map_after_update_02c8:\n"
    ".word .Lgame_map_after_update_0598\n"
    ".word .Lgame_map_after_update_061c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_0508\n"
    ".word .Lgame_map_after_update_0550\n"
    ".word .Lgame_map_after_update_04f0\n"
    ".word .Lgame_map_after_update_04fc\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_03d0\n"
    ".word .Lgame_map_after_update_0454\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_04e4\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_06d4\n"
    ".word .Lgame_map_after_update_06d4\n"
    ".word .Lgame_map_after_update_06d4\n"
    ".word .Lgame_map_after_update_06d4\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_04d8\n"
    ".word .Lgame_map_after_update_070c\n"
    ".word .Lgame_map_after_update_0598\n"
    ".word .Lgame_map_after_update_0598\n"
    ".word .Lgame_map_after_update_06d4\n"
    ".word .Lgame_map_after_update_06d4\n"
    ".Lgame_map_after_update_03d0:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x40\n"
    "ldr r5, .Lgame_map_after_update_0448\n"
    "ldrb r0, [r4, #1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_0408\n"
    "movs r7, #0\n"
    "strb r7, [r4, #1]\n"
    "ldrb r2, [r4]\n"
    "adds r0, r6, #0\n"
    "adds r1, r5, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "ldr r0, [r5, #4]\n"
    "ldrh r1, [r0, #2]\n"
    "movs r2, #0\n"
    "ldrb r0, [r4]\n"
    "adds r0, #1\n"
    "strb r0, [r4]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, r1\n"
    "bne .Lgame_map_after_update_0402\n"
    "movs r2, #1\n"
    ".Lgame_map_after_update_0402:\n"
    "cmp r2, #0\n"
    "beq .Lgame_map_after_update_0408\n"
    "strb r7, [r4]\n"
    ".Lgame_map_after_update_0408:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x44\n"
    "ldr r5, .Lgame_map_after_update_044c\n"
    "ldrb r0, [r4, #1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_0440\n"
    "movs r7, #0\n"
    "strb r7, [r4, #1]\n"
    "ldrb r2, [r4]\n"
    "adds r0, r6, #0\n"
    "adds r1, r5, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "ldr r0, [r5, #4]\n"
    "ldrh r1, [r0, #2]\n"
    "movs r2, #0\n"
    "ldrb r0, [r4]\n"
    "adds r0, #1\n"
    "strb r0, [r4]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, r1\n"
    "bne .Lgame_map_after_update_043a\n"
    "movs r2, #1\n"
    ".Lgame_map_after_update_043a:\n"
    "cmp r2, #0\n"
    "beq .Lgame_map_after_update_0440\n"
    "strb r7, [r4]\n"
    ".Lgame_map_after_update_0440:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x48\n"
    "ldr r5, .Lgame_map_after_update_0450\n"
    "b .Lgame_map_after_update_0692\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_0448: .word gMapLayoutTileAnimation8\n"
    ".Lgame_map_after_update_044c: .word gMapLayoutTileAnimation9\n"
    ".Lgame_map_after_update_0450: .word gMapLayoutTileAnimation10\n"
    ".Lgame_map_after_update_0454:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x40\n"
    "ldr r5, .Lgame_map_after_update_04cc\n"
    "ldrb r0, [r4, #1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_048c\n"
    "movs r7, #0\n"
    "strb r7, [r4, #1]\n"
    "ldrb r2, [r4]\n"
    "adds r0, r6, #0\n"
    "adds r1, r5, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "ldr r0, [r5, #4]\n"
    "ldrh r1, [r0, #2]\n"
    "movs r2, #0\n"
    "ldrb r0, [r4]\n"
    "adds r0, #1\n"
    "strb r0, [r4]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, r1\n"
    "bne .Lgame_map_after_update_0486\n"
    "movs r2, #1\n"
    ".Lgame_map_after_update_0486:\n"
    "cmp r2, #0\n"
    "beq .Lgame_map_after_update_048c\n"
    "strb r7, [r4]\n"
    ".Lgame_map_after_update_048c:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x44\n"
    "ldr r5, .Lgame_map_after_update_04d0\n"
    "ldrb r0, [r4, #1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_04c4\n"
    "movs r7, #0\n"
    "strb r7, [r4, #1]\n"
    "ldrb r2, [r4]\n"
    "adds r0, r6, #0\n"
    "adds r1, r5, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "ldr r0, [r5, #4]\n"
    "ldrh r1, [r0, #2]\n"
    "movs r2, #0\n"
    "ldrb r0, [r4]\n"
    "adds r0, #1\n"
    "strb r0, [r4]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, r1\n"
    "bne .Lgame_map_after_update_04be\n"
    "movs r2, #1\n"
    ".Lgame_map_after_update_04be:\n"
    "cmp r2, #0\n"
    "beq .Lgame_map_after_update_04c4\n"
    "strb r7, [r4]\n"
    ".Lgame_map_after_update_04c4:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x48\n"
    "ldr r5, .Lgame_map_after_update_04d4\n"
    "b .Lgame_map_after_update_0692\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_04cc: .word gMapLayoutTileAnimation11\n"
    ".Lgame_map_after_update_04d0: .word gMapLayoutTileAnimation12\n"
    ".Lgame_map_after_update_04d4: .word gMapLayoutTileAnimation13\n"
    ".Lgame_map_after_update_04d8:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x50\n"
    "ldr r5, .Lgame_map_after_update_04e0\n"
    "b .Lgame_map_after_update_0692\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_04e0: .word gMapLayoutTileAnimation17\n"
    ".Lgame_map_after_update_04e4:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x54\n"
    "ldr r5, .Lgame_map_after_update_04ec\n"
    "b .Lgame_map_after_update_0692\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_04ec: .word gMapLayoutTileAnimation15\n"
    ".Lgame_map_after_update_04f0:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x4c\n"
    "ldr r5, .Lgame_map_after_update_04f8\n"
    "b .Lgame_map_after_update_0692\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_04f8: .word gMapLayoutTileAnimation14\n"
    ".Lgame_map_after_update_04fc:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x4c\n"
    "ldr r5, .Lgame_map_after_update_0504\n"
    "b .Lgame_map_after_update_0692\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_0504: .word gMapLayoutTileAnimation16\n"
    ".Lgame_map_after_update_0508:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x38\n"
    "ldr r5, .Lgame_map_after_update_0548\n"
    "ldrb r0, [r4, #1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_0540\n"
    "movs r7, #0\n"
    "strb r7, [r4, #1]\n"
    "ldrb r2, [r4]\n"
    "adds r0, r6, #0\n"
    "adds r1, r5, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "ldr r0, [r5, #4]\n"
    "ldrh r1, [r0, #2]\n"
    "movs r2, #0\n"
    "ldrb r0, [r4]\n"
    "adds r0, #1\n"
    "strb r0, [r4]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, r1\n"
    "bne .Lgame_map_after_update_053a\n"
    "movs r2, #1\n"
    ".Lgame_map_after_update_053a:\n"
    "cmp r2, #0\n"
    "beq .Lgame_map_after_update_0540\n"
    "strb r7, [r4]\n"
    ".Lgame_map_after_update_0540:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x3c\n"
    "ldr r5, .Lgame_map_after_update_054c\n"
    "b .Lgame_map_after_update_0692\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_0548: .word gMapLayoutTileAnimation4\n"
    ".Lgame_map_after_update_054c: .word gMapLayoutTileAnimation5\n"
    ".Lgame_map_after_update_0550:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x38\n"
    "ldr r5, .Lgame_map_after_update_0590\n"
    "ldrb r0, [r4, #1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_0588\n"
    "movs r7, #0\n"
    "strb r7, [r4, #1]\n"
    "ldrb r2, [r4]\n"
    "adds r0, r6, #0\n"
    "adds r1, r5, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "ldr r0, [r5, #4]\n"
    "ldrh r1, [r0, #2]\n"
    "movs r2, #0\n"
    "ldrb r0, [r4]\n"
    "adds r0, #1\n"
    "strb r0, [r4]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, r1\n"
    "bne .Lgame_map_after_update_0582\n"
    "movs r2, #1\n"
    ".Lgame_map_after_update_0582:\n"
    "cmp r2, #0\n"
    "beq .Lgame_map_after_update_0588\n"
    "strb r7, [r4]\n"
    ".Lgame_map_after_update_0588:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x3c\n"
    "ldr r5, .Lgame_map_after_update_0594\n"
    "b .Lgame_map_after_update_0692\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_0590: .word gMapLayoutTileAnimation6\n"
    ".Lgame_map_after_update_0594: .word gMapLayoutTileAnimation7\n"
    ".Lgame_map_after_update_0598:\n"
    "adds r1, r6, #0\n"
    "adds r1, #0x58\n"
    "ldrb r0, [r1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_05d0\n"
    "subs r0, #1\n"
    "strb r0, [r1]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, #0\n"
    "bne .Lgame_map_after_update_05c0\n"
    "ldr r1, .Lgame_map_after_update_05bc\n"
    "adds r0, r6, #0\n"
    "movs r2, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "b .Lgame_map_after_update_05d0\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_05bc: .word gMapTilePatch7\n"
    ".Lgame_map_after_update_05c0:\n"
    "cmp r0, #0xa\n"
    "bne .Lgame_map_after_update_05d0\n"
    "ldr r1, .Lgame_map_after_update_0610\n"
    "adds r0, r6, #0\n"
    "movs r2, #1\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    ".Lgame_map_after_update_05d0:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x30\n"
    "ldr r5, .Lgame_map_after_update_0614\n"
    "ldrb r0, [r4, #1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_0608\n"
    "movs r7, #0\n"
    "strb r7, [r4, #1]\n"
    "ldrb r2, [r4]\n"
    "adds r0, r6, #0\n"
    "adds r1, r5, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "ldr r0, [r5, #4]\n"
    "ldrh r1, [r0, #2]\n"
    "movs r2, #0\n"
    "ldrb r0, [r4]\n"
    "adds r0, #1\n"
    "strb r0, [r4]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, r1\n"
    "bne .Lgame_map_after_update_0602\n"
    "movs r2, #1\n"
    ".Lgame_map_after_update_0602:\n"
    "cmp r2, #0\n"
    "beq .Lgame_map_after_update_0608\n"
    "strb r7, [r4]\n"
    ".Lgame_map_after_update_0608:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x34\n"
    "ldr r5, .Lgame_map_after_update_0618\n"
    "b .Lgame_map_after_update_0692\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_0610: .word gMapTilePatch7\n"
    ".Lgame_map_after_update_0614: .word gMapLayoutTileAnimation0\n"
    ".Lgame_map_after_update_0618: .word gMapLayoutTileAnimation2\n"
    ".Lgame_map_after_update_061c:\n"
    "adds r1, r6, #0\n"
    "adds r1, #0x58\n"
    "ldrb r0, [r1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_0654\n"
    "subs r0, #1\n"
    "strb r0, [r1]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, #0\n"
    "bne .Lgame_map_after_update_0644\n"
    "ldr r1, .Lgame_map_after_update_0640\n"
    "adds r0, r6, #0\n"
    "movs r2, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "b .Lgame_map_after_update_0654\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_0640: .word gMapTilePatch8\n"
    ".Lgame_map_after_update_0644:\n"
    "cmp r0, #0xa\n"
    "bne .Lgame_map_after_update_0654\n"
    "ldr r1, .Lgame_map_after_update_06c8\n"
    "adds r0, r6, #0\n"
    "movs r2, #1\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    ".Lgame_map_after_update_0654:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x30\n"
    "ldr r5, .Lgame_map_after_update_06cc\n"
    "ldrb r0, [r4, #1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_068c\n"
    "movs r7, #0\n"
    "strb r7, [r4, #1]\n"
    "ldrb r2, [r4]\n"
    "adds r0, r6, #0\n"
    "adds r1, r5, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "ldr r0, [r5, #4]\n"
    "ldrh r1, [r0, #2]\n"
    "movs r2, #0\n"
    "ldrb r0, [r4]\n"
    "adds r0, #1\n"
    "strb r0, [r4]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, r1\n"
    "bne .Lgame_map_after_update_0686\n"
    "movs r2, #1\n"
    ".Lgame_map_after_update_0686:\n"
    "cmp r2, #0\n"
    "beq .Lgame_map_after_update_068c\n"
    "strb r7, [r4]\n"
    ".Lgame_map_after_update_068c:\n"
    "adds r4, r6, #0\n"
    "adds r4, #0x34\n"
    "ldr r5, .Lgame_map_after_update_06d0\n"
    ".Lgame_map_after_update_0692:\n"
    "ldrb r0, [r4, #1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_070c\n"
    "movs r7, #0\n"
    "strb r7, [r4, #1]\n"
    "ldrb r2, [r4]\n"
    "adds r0, r6, #0\n"
    "adds r1, r5, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "ldr r0, [r5, #4]\n"
    "ldrh r1, [r0, #2]\n"
    "movs r2, #0\n"
    "ldrb r0, [r4]\n"
    "adds r0, #1\n"
    "strb r0, [r4]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, r1\n"
    "bne .Lgame_map_after_update_06be\n"
    "movs r2, #1\n"
    ".Lgame_map_after_update_06be:\n"
    "cmp r2, #0\n"
    "beq .Lgame_map_after_update_070c\n"
    "strb r7, [r4]\n"
    "b .Lgame_map_after_update_070c\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_06c8: .word gMapTilePatch8\n"
    ".Lgame_map_after_update_06cc: .word gMapLayoutTileAnimation1\n"
    ".Lgame_map_after_update_06d0: .word gMapLayoutTileAnimation3\n"
    ".Lgame_map_after_update_06d4:\n"
    "adds r1, r6, #0\n"
    "adds r1, #0x58\n"
    "ldrb r0, [r1]\n"
    "cmp r0, #0\n"
    "beq .Lgame_map_after_update_070c\n"
    "subs r0, #1\n"
    "strb r0, [r1]\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "cmp r0, #0\n"
    "bne .Lgame_map_after_update_06fc\n"
    "ldr r1, .Lgame_map_after_update_06f8\n"
    "adds r0, r6, #0\n"
    "movs r2, #0\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    "b .Lgame_map_after_update_070c\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_06f8: .word gMapTilePatch9\n"
    ".Lgame_map_after_update_06fc:\n"
    "cmp r0, #0xa\n"
    "bne .Lgame_map_after_update_070c\n"
    "ldr r1, .Lgame_map_after_update_071c\n"
    "adds r0, r6, #0\n"
    "movs r2, #1\n"
    "mov r3, sl\n"
    "bl QueueMapTilePatch\n"
    ".Lgame_map_after_update_070c:\n"
    "add sp, #0x5c\n"
    "pop {r3, r4, r5}\n"
    "mov r8, r3\n"
    "mov sb, r4\n"
    "mov sl, r5\n"
    "pop {r4, r5, r6, r7}\n"
    "pop {r0}\n"
    "bx r0\n"
    ".align 2, 0\n"
    ".Lgame_map_after_update_071c: .word gMapTilePatch9\n"
);

bool MapViewportTilemapCommand::Run()
{
    u32 source_stride = source_width * sizeof(u16);
    volatile HardwareDmaRegisters * registers =
        reinterpret_cast<volatile HardwareDmaRegisters *>(&REG_DMA3SAD);
    for (u32 layer = 0; layer < ARRAY_COUNT(layers); ++layer) {
        u16 const * input = layers[layer].source;
        if (input != nullptr) {
            u8 const * source = reinterpret_cast<u8 const *>(input);
            u16 * destination = layers[layer].destination;
            u16 * end = destination + 32 * 21;
            do {
                WriteHardwareDmaRegisters(source, destination,
                    (static_cast<u32>(DMA_ENABLE) << 16) | 31, registers);
                source += source_stride;
                destination += 32;
            } while (destination != end);
        }
    }
    return false;
}

void GameSceneWorldMap::SetLocation(Location const & location, i32 period,
    u32 first_weight, u32 second_weight)
{
    map = location.GetMap();
    x.q16 = location.GetX() << 16;
    y.q16 = location.GetY() << 16;
    RefreshAppearance(period, first_weight, second_weight);
    SetWorldMapCameraPosition(this, location.GetX(), location.GetY());
}

void GameSceneWorldMap::RefreshAppearance(i32 period, u32 first_weight, u32 second_weight)
{
    map_data_id = SelectMapData();
    MapData const * data = GetMapData(map_data_id);
    if (data->terrain_map != nullptr && data->terrain_data != nullptr) {
        for (u32 row = 0; row < data->height; ++row) {
            for (u32 column = 0; column < data->width; ++column) {
                u32 index = column + row * data->width;
                u8 attribute = static_cast<u8 const *>(data->terrain_map)[index];
                tile_attributes[index] = static_cast<FieldRenderTileAttributes const *>(data->terrain_data)[attribute];
            }
        }
    } else {
        FieldRenderTileAttributes empty = { false, false, 0, 0, 0 };
        std::fill(tile_attributes, tile_attributes + 0x3C80, empty);
    }
    LoadTilemaps();
    SetWorldMapTimeOfDayPalette(*this, period);
    BlendTimeOfDayPalettes(first_weight, second_weight);
    tiles_changed = 1;
    layout_animation_0.ResetFrame();
    layout_animation_1.ResetFrame();
    layout_animation_2.ResetFrame();
    layout_animation_3.ResetFrame();
    layout_animation_4.ResetFrame();
    layout_animation_5.ResetFrame();
    layout_animation_6.ResetFrame();
    layout_animation_7.ResetFrame();
    layout_animation_8.ResetFrame();
    layout_animation_9.ResetFrame();
    tile_patch_countdown = 0;
}

EC Vec2 ClampWorldMapCameraPosition(GameSceneWorldMap const * map, i32 x, i32 y)
{
    i32 old_x = map->x.parts.integer;
    i32 old_y = map->y.parts.integer;
    i32 center_x = old_x + 120;
    i32 center_y = old_y + 80;
    MapData const * data = GetMapData(map->map_data_id);
    i32 width = data->width * 8;
    i32 height = data->height * 8;
    i32 dx = x - center_x;
    i32 dy = y - center_y;
    i32 next_x = old_x + dx;
    if (next_x < 0)
        next_x = 0;
    else if (next_x > width - 240)
        next_x = width - 240;
    i32 next_y = old_y + dy;
    if (next_y < 0)
        next_y = 0;
    else if (next_y > height - 160)
        next_y = height - 160;
    return Vec2(next_x, next_y);
}

EC void SetWorldMapCameraPosition(GameSceneWorldMap * map, i32 x, i32 y)
{
    Vec2 target;
    target = ClampWorldMapCameraPosition(map, x, y);
    Vec2 const & position = target;
    if (map->x.parts.integer != position.x) {
        map->view_changed = true;
        map->x.q16 = position.x << 16;
    }
    i32 current_y = map->y.parts.integer;
    if (current_y != position.y) {
        map->view_changed = true;
        map->y.q16 = position.y << 16;
    }
}

EC void PanWorldMapCameraTo(GameSceneWorldMap * map, i32 x, i32 y, u32 speed)
{
    Vec2 target;
    target = ClampWorldMapCameraPosition(map, x, y);
    Vec2 const & position = target;
    if (speed == 0)
        speed = 1;
    i32 old_x = map->x.parts.integer;
    i32 dx = position.x - old_x;
    i32 old_y = map->y.parts.integer;
    i32 dy = position.y - old_y;
    if (dx != 0 || dy != 0) {
        u32 squared = dx * dx + dy * dy;
        i32 shift = 0;
        while ((squared << (shift * 2)) <= 0x3FFFFFFF)
            ++shift;
        squared <<= shift * 2;
        i32 distance = Sqrt(squared) >> shift;
        i32 frames = static_cast<u32>(distance) / speed;
        if (frames == 0)
            frames = 1;
        map->step_x_q16 = ((position.x << 16) - map->x.q16) / frames;
        map->step_y_q16 = ((position.y << 16) - map->y.q16) / frames;
        map->movement_frames = frames;
    } else {
        map->movement_frames = 0;
    }
}

EC bool IsWorldMapCameraMovementComplete(GameSceneWorldMap const * map)
{
    return map->movement_frames == 0;
}

EC void QueueMapTilePatch(GameSceneWorldMap *,
    FarmHouseTilePatchDescriptor const & patch, u32 frame, HardwareDmaQueue & queue)
{
    // The unused receiver and unchecked frame number preserve the native ABI.
    u8 const * data = patch.frame_data;
    MapTilePatchFrameHeader const * header = reinterpret_cast<MapTilePatchFrameHeader const *>(data);
    u32 tile_count = header->tiles_per_frame;
    data += sizeof(MapTilePatchFrameHeader);
    data += tile_count * frame * TILE_SIZE_4BPP;
    u32 destination_tile = patch.destination_tile;
    u32 byte_count = tile_count * TILE_SIZE_4BPP;
    DmaTransferDescriptor transfer(data,
        reinterpret_cast<void *>(BG_VRAM + destination_tile * TILE_SIZE_4BPP), byte_count);
    queue.PushBack(transfer);
}

EC void ApplyMapTilePatch(GameSceneWorldMap * map,
    FieldRenderRectDescriptor const & patch, u32 x, u32 y)
{
    u32 map_width = GetMapData(map->map_data_id)->width;
    u32 width = patch.width;
    u32 height = patch.height;
    void const * const * buffers = patch.source_buffers;
    for (u32 layer = 0; layer < 3; ++layer) {
        if (buffers[layer] != nullptr) {
            for (u32 row = 0; row < height; ++row) {
                memcpy(map->tile_layers[layer] + x + (y + row) * map_width,
                    static_cast<u16 const *>(buffers[layer]) + row * width,
                    width * sizeof(u16));
            }
        }
    }
    if (patch.lookup_indices != nullptr && patch.lookup_values != nullptr) {
        for (u32 row = 0; row < height; ++row) {
            u8 const * source = static_cast<u8 const *>(patch.lookup_indices) + row * width;
            FieldRenderTileAttributes * destination = map->tile_attributes + x + (y + row) * map_width;
            for (u32 column = 0; column < width; ++column) {
                *destination++ = static_cast<FieldRenderTileAttributes const *>(patch.lookup_values)[*source++];
            }
        }
    }
}

void GameSceneWorldMap::LoadTilemaps()
{
    GameSceneWorldMap & map = *this;
    MapData const * data = GetMapData(map.map_data_id);
    u32 layer = 0;
    u16 ** destination = map.tile_layers;
    for (; layer < 3; ++destination, ++layer) {
        u8 const * source = data->tilemaps[layer];
        if (source != nullptr)
            Unpack(source, *destination);
        else
            FillHardwareDma3(0x03FF03FF, *destination, static_cast<u32>(data->width) * (data->height << 1));
    }
    map.view_changed = true;
}

EC void SetWorldMapTimeOfDayPalette(GameSceneWorldMap & map, i32 period)
{
    switch (period) {
    case TIME_OF_DAY_PERIOD_NIGHT:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_NIGHT, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_MORNING, 1);
        break;
    case TIME_OF_DAY_PERIOD_MORNING:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_MORNING, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_AFTERNOON, 1);
        break;
    case TIME_OF_DAY_PERIOD_AFTERNOON:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_AFTERNOON, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_EVENING, 1);
        break;
    case TIME_OF_DAY_PERIOD_EVENING:
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_EVENING, 0);
        map.LoadTimeOfDayPalette(TIME_OF_DAY_PERIOD_NIGHT, 1);
        break;
    }
    map.time_palette_changed = true;
}

void GameSceneWorldMap::LoadTimeOfDayPalette(i32 period, u32 buffer_index)
{
    GameSceneWorldMap & map = *this;
    MapData const * data = GetMapData(map.map_data_id);
    // The native loader first decodes the default palette even when the
    // selected period will decode that same resource again below.
    Unpack(data->palettes[0], map.time_palette_buffers[buffer_index]);
    switch (period) {
    case TIME_OF_DAY_PERIOD_MORNING:
    case TIME_OF_DAY_PERIOD_AFTERNOON:
    case TIME_OF_DAY_PERIOD_EVENING:
        Unpack(data->palettes[0], map.time_palette_buffers[buffer_index]);
        break;
    case TIME_OF_DAY_PERIOD_NIGHT:
        Unpack(data->palettes[1], map.time_palette_buffers[buffer_index]);
        break;
    }
}

asm_unified(
    ".text\n"
    ".align 2, 0\n"
    "thumb_func_start BlendTimeOfDayPalettes__17GameSceneWorldMapUiUi\n"
    "BlendTimeOfDayPalettes__17GameSceneWorldMapUiUi:\n"
    "push {r4, r5, r6, r7, lr}\n"
    "mov r7, sl\n"
    "mov r6, sb\n"
    "mov r5, r8\n"
    "push {r5, r6, r7}\n"
    "sub sp, #8\n"
    "mov sl, r0\n"
    "mov sb, r1\n"
    "movs r0, #0\n"
    "str r0, [sp]\n"
    "movs r0, #0x1f\n"
    "ands r1, r0\n"
    "mov sb, r1\n"
    "mov r0, sl\n"
    "ldr r0, [r0, #0x20]\n"
    "mov r8, r0\n"
    "mov r1, sl\n"
    "ldr r7, [r1, #0x1c]\n"
    "ldr r6, [r1, #0x24]\n"
    "movs r0, #0x1f\n"
    "ands r2, r0\n"
    "lsls r2, r2, #5\n"
    "str r2, [sp, #4]\n"
    ".Lgame_map_time_palette_after_002e:\n"
    "movs r0, #0x20\n"
    "rsbs r0, r0, #0\n"
    "adds r1, r0, #0\n"
    "adds r0, r5, #0\n"
    "ands r0, r1\n"
    "mov r1, sb\n"
    "orrs r0, r1\n"
    "lsls r0, r0, #0x18\n"
    "lsrs r0, r0, #0x18\n"
    "ldr r1, .Lgame_map_time_palette_after_0094\n"
    "ands r5, r1\n"
    "orrs r5, r0\n"
    "ldr r0, .Lgame_map_time_palette_after_0098\n"
    "adds r1, r0, #0\n"
    "adds r0, r5, #0\n"
    "ands r0, r1\n"
    "ldr r1, [sp, #4]\n"
    "orrs r0, r1\n"
    "lsls r0, r0, #0x10\n"
    "lsrs r0, r0, #0x10\n"
    "ldr r1, .Lgame_map_time_palette_after_009c\n"
    "ands r5, r1\n"
    "orrs r5, r0\n"
    "adds r0, r6, #0\n"
    "adds r1, r7, #0\n"
    "mov r2, r8\n"
    "adds r3, r5, #0\n"
    "ldr r4, .Lgame_map_time_palette_after_00a0\n"
    "bl _call_via_r4\n"
    "movs r0, #0x20\n"
    "add r8, r0\n"
    "adds r7, #0x20\n"
    "adds r6, #0x20\n"
    "ldr r1, [sp]\n"
    "adds r1, #1\n"
    "str r1, [sp]\n"
    "cmp r1, #0xe\n"
    "bls .Lgame_map_time_palette_after_002e\n"
    "mov r1, sl\n"
    "adds r1, #0x2a\n"
    "movs r0, #1\n"
    "strb r0, [r1]\n"
    "add sp, #8\n"
    "pop {r3, r4, r5}\n"
    "mov r8, r3\n"
    "mov sb, r4\n"
    "mov sl, r5\n"
    "pop {r4, r5, r6, r7}\n"
    "pop {r0}\n"
    "bx r0\n"
    ".align 2, 0\n"
    ".Lgame_map_time_palette_after_0094: .word 0xFFFFFF00\n"
    ".Lgame_map_time_palette_after_0098: .word 0xFFFFFC1F\n"
    ".Lgame_map_time_palette_after_009c: .word 0xFFFF0000\n"
    ".Lgame_map_time_palette_after_00a0: .word BlendRgb5PaletteBank\n"
);

void GameSceneWorldMap::LoadTiles(HardwareDmaQueue &)
{
    GameSceneWorldMap & map = *this;
    MapData const * data = GetMapData(map.map_data_id);
    Unpack(data->tiles, reinterpret_cast<void *>(BG_VRAM));
}

EC bool func_080A5EB8(GameSceneWorldMap * map, Location const & location)
{
    if (location.GetMap() != MAP_MINERAL_BEACH || map->map != MAP_MINERAL_BEACH
        || map->map_data_id != 8)
        return false;

    Vec2 position(location.GetX() / 8, location.GetY() / 8);
    u32 width = GetMapData(8)->width;
    for (u32 layer = 0; layer < 3; ++layer) {
        u16 const * column = map->tile_layers[2 - layer] + position.x;
        column += position.y * width;
        u32 tile = *column & 0x3FF;
        if (tile != 0x3FF) {
            if (tile - 0x58 <= 0x3C || tile <= 0x33)
                return true;
            return false;
        }
    }
    return false;
}

EC void ClearWorldMapTileRectangle(GameSceneWorldMap * map, u32 layer,
    Vec2 const & position, u32 width, u32 height)
{
    u32 map_width = GetMapData(map->map_data_id)->width;
    for (u32 row = 0; row < height; ++row) {
        for (u32 column = 0; column < width; ++column) {
            u32 index = position.x + column + (position.y + row) * map_width;
            u16 & tile = map->tile_layers[layer][index];
            tile = 0x3FF;
            map->tile_attributes[index].unk_00_00 = false;
            map->tile_attributes[index].unk_02_01 = 0;
        }
    }
    map->view_changed = true;
}

EC void StartWorldMapTilePatchCountdown(GameSceneWorldMap * map)
{
    map->tile_patch_countdown = 0x14;
}

EC void RefreshCoopFeedTrough(GameSceneWorldMap * map, u32 index)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x24:
    case 0x25:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[22],
            gFieldRenderPatchArgumentData.values_00[index], 8);
        break;
    case 0x40:
    {
        FieldRenderRectDescriptor const & patch = gFieldRenderRectDescriptors[22];
        u8 const * coordinates = gFieldRenderPatchArgumentData.values_08;
        ApplyMapTilePatch(map, patch,
            coordinates[index], 4);
        break;
    }
    }
    map->view_changed = true;
}

asm_unified(
    ".text\n"
    ".align 2, 0\n"
    "thumb_func_start RefreshBarnFeedTrough\n"
    "RefreshBarnFeedTrough:\n"
    "push {r4, lr}\n"
    "adds r4, r0, #0\n"
    "adds r2, r1, #0\n"
    "ldr r0, [r4, #4]\n"
    "cmp r0, #0x27\n"
    "beq .Lgame_map_barn_feed_0050\n"
    "cmp r0, #0x27\n"
    "bgt .Lgame_map_barn_feed_0016\n"
    "cmp r0, #0x26\n"
    "beq .Lgame_map_barn_feed_001c\n"
    "b .Lgame_map_barn_feed_00a4\n"
    ".Lgame_map_barn_feed_0016:\n"
    "cmp r0, #0x41\n"
    "beq .Lgame_map_barn_feed_0094\n"
    "b .Lgame_map_barn_feed_00a4\n"
    ".Lgame_map_barn_feed_001c:\n"
    "cmp r2, #0xf\n"
    "bls .Lgame_map_barn_feed_0040\n"
    "ldr r1, .Lgame_map_barn_feed_0038\n"
    "ldr r3, .Lgame_map_barn_feed_003c\n"
    "adds r0, r2, #0\n"
    "subs r0, #0x10\n"
    "lsls r0, r0, #1\n"
    "adds r2, r0, r3\n"
    "ldrb r2, [r2]\n"
    "adds r3, #1\n"
    "adds r0, r0, r3\n"
    "ldrb r3, [r0]\n"
    "b .Lgame_map_barn_feed_0084\n"
    ".align 2, 0\n"
    ".Lgame_map_barn_feed_0038: .word gFieldRenderRectDescriptors + 0x1F8\n"
    ".Lgame_map_barn_feed_003c: .word gFieldRenderPatchArgumentData + 0x0C\n"
    ".Lgame_map_barn_feed_0040:\n"
    "ldr r1, .Lgame_map_barn_feed_0048\n"
    "ldr r0, .Lgame_map_barn_feed_004c\n"
    "b .Lgame_map_barn_feed_0078\n"
    ".align 2, 0\n"
    ".Lgame_map_barn_feed_0048: .word gFieldRenderRectDescriptors + 0x1F8\n"
    ".Lgame_map_barn_feed_004c: .word gFieldRenderPatchArgumentData + 0x2C\n"
    ".Lgame_map_barn_feed_0050:\n"
    "cmp r2, #0xf\n"
    "bls .Lgame_map_barn_feed_0074\n"
    "ldr r1, .Lgame_map_barn_feed_006c\n"
    "ldr r3, .Lgame_map_barn_feed_0070\n"
    "adds r0, r2, #0\n"
    "subs r0, #0x10\n"
    "lsls r0, r0, #1\n"
    "adds r2, r0, r3\n"
    "ldrb r2, [r2]\n"
    "adds r3, #1\n"
    "adds r0, r0, r3\n"
    "ldrb r3, [r0]\n"
    "b .Lgame_map_barn_feed_0084\n"
    ".align 2, 0\n"
    ".Lgame_map_barn_feed_006c: .word gFieldRenderRectDescriptors + 0x1F8\n"
    ".Lgame_map_barn_feed_0070: .word gFieldRenderPatchArgumentData + 0x0C\n"
    ".Lgame_map_barn_feed_0074:\n"
    "ldr r1, .Lgame_map_barn_feed_008c\n"
    "ldr r0, .Lgame_map_barn_feed_0090\n"
    ".Lgame_map_barn_feed_0078:\n"
    "lsls r3, r2, #1\n"
    "adds r2, r3, r0\n"
    "ldrb r2, [r2]\n"
    "adds r0, #1\n"
    "adds r3, r3, r0\n"
    "ldrb r3, [r3]\n"
    ".Lgame_map_barn_feed_0084:\n"
    "adds r0, r4, #0\n"
    "bl ApplyMapTilePatch\n"
    "b .Lgame_map_barn_feed_00a4\n"
    ".align 2, 0\n"
    ".Lgame_map_barn_feed_008c: .word gFieldRenderRectDescriptors + 0x1F8\n"
    ".Lgame_map_barn_feed_0090: .word gFieldRenderPatchArgumentData + 0x3C\n"
    ".Lgame_map_barn_feed_0094:\n"
    "ldr r1, .Lgame_map_barn_feed_00b4\n"
    "ldr r0, .Lgame_map_barn_feed_00b8\n"
    "adds r0, r2, r0\n"
    "ldrb r2, [r0]\n"
    "adds r0, r4, #0\n"
    "movs r3, #5\n"
    "bl ApplyMapTilePatch\n"
    ".Lgame_map_barn_feed_00a4:\n"
    "adds r1, r4, #0\n"
    "adds r1, #0x29\n"
    "movs r0, #1\n"
    "strb r0, [r1]\n"
    "pop {r4}\n"
    "pop {r0}\n"
    "bx r0\n"
    ".align 2, 0\n"
    ".Lgame_map_barn_feed_00b4: .word gFieldRenderRectDescriptors + 0x1F8\n"
    ".Lgame_map_barn_feed_00b8: .word gFieldRenderPatchArgumentData + 0x5C\n"
);

EC void func_080A6138(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[0], 0x19, 0xF);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[0], 0x28, 0xF);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[0], 0x36, 0xF);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6194(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[1], 0x19, 0xF);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[1], 0x28, 0xF);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[1], 0x36, 0xF);
        break;
    }
    map->view_changed = true;
}

EC void func_080A61F0(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[2], 0xB, 3);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[2], 0x13, 3);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6234(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[3], 0xB, 3);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[3], 0x13, 3);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6278(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[4], 0xF, 2);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[4], 0x17, 2);
        break;
    }
    map->view_changed = true;
}

EC void func_080A62BC(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[5], 0xF, 2);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[5], 0x17, 2);
        break;
    }
    map->view_changed = true;
}

EC void func_080A6300(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[8], 1, 0x11);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[8], 0x10, 0x11);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[8], 0x18, 0x11);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

EC void func_080A635C(GameSceneWorldMap * map)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x29:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[7], 1, 0x11);
        break;
    case 0x2A:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[7], 0x10, 0x11);
        break;
    case 0x2B:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[7], 0x18, 0x11);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

EC void func_080A63B8(GameSceneWorldMap * map, u32 unk)
{
    switch (static_cast<i32>(map->map_data_id)) {
    case 0x40:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[67], 1, 0xD);
        break;
    case 0x24:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[67], 1, 0x11);
        break;
    case 0x25:
        ApplyMapTilePatch(map, gFieldRenderRectDescriptors[67], 1, unk == 0 ? 0x11 : 0xD);
        break;
    default:
        return;
    }
    map->view_changed = true;
}

u32 GameSceneWorldMap::SelectMapData()
{
    GameSceneWorldMap const * map = this;
    return SelectMapDataId(map->map, SEASON_SUMMER, 0, 0, 0);
}

EC FieldRenderTileAttributes * GetWorldMapTileAttributes(GameSceneWorldMap * map,
    u32 x, u32 y)
{
    u32 width = GetMapData(map->map_data_id)->width;
    return &map->tile_attributes[x + y * width];
}

EC u32 GetWorldMapDataId(GameSceneWorldMap const * map)
{
    return map->map_data_id;
}

EC u32 GetWorldMapId(GameSceneWorldMap const * map)
{
    return map->map;
}

EC i32 GetWorldMapViewY(GameSceneWorldMap const * map)
{
    return map->y.parts.integer;
}

EC i32 GetWorldMapViewX(GameSceneWorldMap const * map)
{
    return map->x.parts.integer;
}


// The three logical map layers use BG3, BG2 and BG1 respectively.
u32 const gWorldMapViewportScreenBlocks[3] = { 28, 29, 30 };
u32 const gWorldMapViewportPriorities[3] = { 3, 2, 1 };

volatile u16 * const gWorldMapViewportControlRegisters[3] = {
    &REG_BG3CNT, &REG_BG2CNT, &REG_BG1CNT,
};

volatile u16 * const gWorldMapViewportHorizontalScrollRegisters[3] = {
    &REG_BG3HOFS, &REG_BG2HOFS, &REG_BG1HOFS,
};

volatile u16 * const gWorldMapViewportVerticalScrollRegisters[3] = {
    &REG_BG3VOFS, &REG_BG2VOFS, &REG_BG1VOFS,
};

FieldRenderPatchArgumentData const gFieldRenderPatchArgumentData = {
        { 0x10, 0x13, 0x16, 0x19, 0x1C, 0x1F, 0x22, 0x25 },
        { 0x10, 0x13, 0x16, 0x19 },
        {
            { 0x03, 0x08 },
            { 0x03, 0x14 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
            { 0x00, 0x00 },
        },
        {
            0x1A, 0x08, 0x1F, 0x08, 0x24, 0x08, 0x29, 0x08,
            0x1A, 0x14, 0x1F, 0x14, 0x24, 0x14, 0x29, 0x14,
            0x1A, 0x08, 0x1F, 0x08, 0x24, 0x08, 0x29, 0x08,
            0x1A, 0x14, 0x1F, 0x14, 0x24, 0x14, 0x29, 0x14,
            0x38, 0x08, 0x3D, 0x08, 0x42, 0x08, 0x47, 0x08,
            0x38, 0x14, 0x3D, 0x14, 0x42, 0x14, 0x47, 0x14,
        },
        { 0x14, 0x19, 0x03, 0x00 },
    };
