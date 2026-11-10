#include "prelude.h"
#include "gbaio.h"
#pragma implementation "entity_auxiliary_sprites.hh"
#include "game_world.hh"
#include "scene_sprite.hh"
#include "hardware_dma_queue.hh"
#include "entity_auxiliary_sprites.hh"

asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    ".align 2, 0\n"
    "    .global __22EntityAuxiliarySpritesP10GameObject\n"
    "    .thumb_func\n"
    "__22EntityAuxiliarySpritesP10GameObject:\n"
    "    push\t{r4, r5, r6, r7, lr}\n"
    "    mov\tr7, sl\n"
    "    mov\tr6, r9\n"
    "    mov\tr5, r8\n"
    "    push\t{r5, r6, r7}\n"
    "    sub\tsp, #48\t@ 0x30\n"
    "    mov\tr9, r0\n"
    "    mov\tsl, r1\n"
    "    mov\tr6, r9\n"
    "    stmia\tr6!, {r1}\n"
    "    movs\tr7, #2\n"
    "    add\tr0, sp, #32\n"
    "    mov\tr8, r0\n"
    "    mov\tr1, sp\n"
    "    adds\tr1, #36\t@ 0x24\n"
    "    str\tr1, [sp, #44]\t@ 0x2c\n"
    "    movs\tr5, #0\n"
    "    adds\tr4, r6, #0\n"
    ".Lworld_sprite_constructor_0:\n"
    "    str\tr5, [r4, #0]\n"
    "    strh\tr5, [r4, #4]\n"
    "    str\tr5, [r4, #8]\n"
    "    strh\tr5, [r4, #12]\n"
    "    str\tr5, [r4, #16]\n"
    "    strh\tr5, [r4, #20]\n"
    "    str\tr5, [r4, #24]\n"
    "    strh\tr5, [r4, #28]\n"
    "    adds\tr0, r6, #0\n"
    "    adds\tr0, #32\n"
    "    bl InitializeObjTilePoolOwner\n"
    "    str\tr5, [r4, #36]\t@ 0x24\n"
    "    adds\tr4, #44\t@ 0x2c\n"
    "    adds\tr6, #44\t@ 0x2c\n"
    "    subs\tr7, #1\n"
    "    movs\tr0, #1\n"
    "    negs\tr0, r0\n"
    "    cmp\tr7, r0\n"
    "    bne .Lworld_sprite_constructor_0\n"
    "    mov\tr6, r9\n"
    "    adds\tr6, #136\t@ 0x88\n"
    "    movs\tr0, #0\n"
    "    str\tr0, [r6, #0]\n"
    "    mov\tr0, r9\n"
    "    adds\tr0, #156\t@ 0x9c\n"
    "    movs\tr4, #1\n"
    "    strb\tr4, [r0, #0]\n"
    "    mov\tr2, sl\n"
    "    ldr\tr0, [r2, #0]\n"
    "    ldr\tr2, [r0, #72]\t@ 0x48\n"
    "    mov\tr0, sl\n"
    "    movs\tr1, #15\n"
    "    bl _call_via_r2\n"
    "    mov\tr3, r8\n"
    "    strb\tr0, [r3, #0]\n"
    "    adds\tr5, r6, #0\n"
    "    ldr\tr2, [r5, #0]\n"
    "    cmp\tr4, r2\n"
    "    bls .Lworld_sprite_constructor_1\n"
    "    mov\tr0, r9\n"
    "    adds\tr0, #140\t@ 0x8c\n"
    "    adds\tr2, #4\n"
    "    adds\tr2, r5, r2\n"
    "    ldrb\tr1, [r3, #0]\n"
    "    subs\tr2, r2, r0\n"
    "    bl memset\n"
    "    ldr\tr2, [r5, #0]\n"
    "    adds\tr0, r2, #4\n"
    "    adds\tr0, r5, r0\n"
    "    add\tr1, sp, #32\n"
    "    ldrb\tr1, [r1, #0]\n"
    "    subs\tr2, r4, r2\n"
    "    bl memset\n"
    "    str\tr4, [r5, #0]\n"
    "    b .Lworld_sprite_constructor_2\n"
    ".Lworld_sprite_constructor_1:\n"
    "    mov\tr0, r9\n"
    "    adds\tr0, #140\t@ 0x8c\n"
    "    mov\tr4, r9\n"
    "    adds\tr4, #141\t@ 0x8d\n"
    "    mov\tr2, r8\n"
    "    ldrb\tr1, [r2, #0]\n"
    "    subs\tr2, r4, r0\n"
    "    bl memset\n"
    "    ldr\tr0, [r5, #0]\n"
    "    adds\tr0, #4\n"
    "    adds\tr0, r5, r0\n"
    "    subs\tr0, r0, r4\n"
    "    ldr\tr1, [r6, #0]\n"
    "    subs\tr1, r1, r0\n"
    "    str\tr1, [r6, #0]\n"
    ".Lworld_sprite_constructor_2:\n"
    "    mov\tr3, sl\n"
    "    ldr\tr0, [r3, #0]\n"
    "    ldr\tr1, [r0, #104]\t@ 0x68\n"
    "    mov\tr0, sl\n"
    "    bl _call_via_r1\n"
    "    mov\tr8, r0\n"
    "    movs\tr7, #0\n"
    ".Lworld_sprite_constructor_3:\n"
    "    movs\tr0, #44\t@ 0x2c\n"
    "    adds\tr6, r7, #0\n"
    "    muls\tr6, r0\n"
    "    add\tr6, r9\n"
    "    adds\tr4, r6, #4\n"
    "    ldr r0, .Lworld_sprite_constructor_4\n"
    "    adds\tr2, r7, r0\n"
    "    mov\tr1, r8\n"
    "    ldr\tr5, [r1, #0]\n"
    "    ldr\tr0, [sp, #44]\t@ 0x2c\n"
    "    ldr\tr3, [r5, #12]\n"
    "    bl _call_via_r3\n"
    "    ldr\tr0, [sp, #36]\t@ 0x24\n"
    "    ldrh\tr2, [r0, #0]\n"
    "    mov\tr0, sp\n"
    "    ldr\tr3, [r5, #16]\n"
    "    mov\tr1, r8\n"
    "    bl _call_via_r3\n"
    "    mov\tr0, sp\n"
    "    mov\tr1, sp\n"
    "    movs\tr2, #32\n"
    "    bl memcpy\n"
    "    mov\tr0, sp\n"
    "    ldmia\tr0!, {r1, r2, r3}\n"
    "    stmia\tr4!, {r1, r2, r3}\n"
    "    ldmia\tr0!, {r1, r2, r3}\n"
    "    stmia\tr4!, {r1, r2, r3}\n"
    "    ldmia\tr0!, {r2, r3}\n"
    "    stmia\tr4!, {r2, r3}\n"
    "    adds\tr4, r6, #0\n"
    "    adds\tr4, #36\t@ 0x24\n"
    "    ldr\tr1, [r4, #4]\n"
    "    adds\tr0, r4, #0\n"
    "    bl ReleaseObjTileHandle\n"
    "    adds\tr0, r4, #0\n"
    "    movs\tr1, #2\n"
    "    bl AllocateObjTileHandle\n"
    "    adds\tr1, r0, #0\n"
    "    str\tr1, [r4, #4]\n"
    "    adds\tr0, r4, #0\n"
    "    bl GetObjTileIndex\n"
    "    strh\tr0, [r6, #44]\t@ 0x2c\n"
    "    adds\tr7, #1\n"
    "    cmp\tr7, #2\n"
    "    bls .Lworld_sprite_constructor_3\n"
    "    mov\tr0, r9\n"
    "    add\tsp, #48\t@ 0x30\n"
    "    pop\t{r3, r4, r5}\n"
    "    mov\tr8, r3\n"
    "    mov\tr9, r4\n"
    "    mov\tsl, r5\n"
    "    pop\t{r4, r5, r6, r7}\n"
    "    pop\t{r1}\n"
    "    bx\tr1\n"
    "    .align 2, 0\n"
    ".Lworld_sprite_constructor_4: .word 0x0000091A\n"
);


EntityAuxiliarySprites::~EntityAuxiliarySprites()
{
    // Match native cleanup: release the first index, then destroy all three
    // retained tile entries in reverse member-array order.
    world->ClearSpritePaletteResourceFlag(indices[0]);
}

void EntityAuxiliarySprites::PrepareResources(HardwareDmaQueue & queue)
{
    // Each retained group gets a queued OBJ tile copy, including an empty range.
    for (u32 index = 0; index < ARRAY_COUNT(entries); ++index) {
        IndexedResourceTileRange & range = entries[index].group.tiles;
        IndexedResourceTileUnit const * source = range.data;
        u32 tile_index = entries[index].tiles.GetTileIndex();
        u32 byte_count = range.data ? range.byte_count : 0;
        DmaTransferDescriptor transfer(source,
            reinterpret_cast<void *>(OBJ_VRAM0 + tile_index * TILE_SIZE_4BPP), byte_count);
        queue.PushBack(transfer);
    }
    // All three groups use the first group's palette and retained index.
    world->SetSpritePaletteColors(
        reinterpret_cast<u8 const *>(entries[0].group.palettes.data), indices[0], 1);
}

void EntityAuxiliarySprites::Draw(WorldSpriteDrawBuffer * buffer, i32 x, i32 y, u32 kind) const
{
    EntityAuxiliarySpriteEntry const & entry = entries[kind];
    u16 tile_offset = entry.tile_index;
    // Auxiliary groups retain a fixed depth key, independent of actor Y.
    u32 sort_key = 0x8000;
    GameObject * source = world;
    GameScenePaletteIndices const & palette_indices = indices;
    // All four source priorities map to hardware OBJ priority 2.
    SubmitWorldSpriteRecords(buffer, x, y, 0xAA, sort_key, entry.group.sprites,
        source, tile_offset, palette_indices);
}
