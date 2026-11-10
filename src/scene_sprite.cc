#include "prelude.h"
#include "gbaio.h"
#include "entity_actor.hh"
#include "world_runtime.hh"
#include "hardware_dma_queue.hh"

#include "scene_sprite.hh"
#include "scene_sprite_indexed.hh"

GameSceneSpriteBase::GameSceneSpriteBase(GameObject * source, u32 size_shift,
    i32 const * palette_kinds, u32 palette_count)
    : world(source), tiles(size_shift), tile_index(tiles.GetTileIndex()),
      palettes(palette_count)
{
    i32 const * current = palette_kinds;
    for (u32 index = 0; index < palette_count; ++index)
        palettes[index] = source->vfunc_48(*current++);
}

GameSceneSpriteBase::GameSceneSpriteBase(GameObject * source, u32 size_shift, i32 palette_kind)
    : world(source), tiles(size_shift), tile_index(tiles.GetTileIndex()), palettes(1)
{
    palettes[0] = source->vfunc_48(palette_kind);
}


GameSceneSpriteBase::~GameSceneSpriteBase()
{
    for (u32 index = 0; index < palettes.count; ++index)
        world->ClearSpritePaletteResourceFlag(palettes[index]);
}

void GameSceneSpriteBase::QueueTileUpload(HardwareDmaQueue & queue,
    IndexedResourceTileRange const & range)
{
    IndexedResourceTileUnit const * source = range.data;
    u32 byte_count = 0;
    if (source != nullptr)
        byte_count = range.byte_count;
    if (byte_count != 0) {
        DmaTransferDescriptor transfer(source,
            reinterpret_cast<void *>(OBJ_VRAM0 + tiles.GetTileIndex() * TILE_SIZE_4BPP), byte_count);
        queue.PushBack(transfer);
    }
}

void GameSceneSpriteBase::UploadPalettes(IndexedResourcePaletteRange const & range, u8 unk)
{
    u32 byte_count = range.data ? range.byte_count : 0;
    if (byte_count != 0) {
        GameObject * object = world;
        u32 count = byte_count / PLTT_SIZE_4BPP;
        u8 const * current = reinterpret_cast<u8 const *>(range.data);
        for (u32 index = 0; index < count; ++index, current += PLTT_SIZE_4BPP) {
            object->SetSpritePaletteColors(current, palettes[index], unk);
        }
    }
}

GameSceneIndexedSprite::GameSceneIndexedSprite(IndexedResourceProvider * resource,
    u32 index, GameObject * world, u32 size_shift, i32 const * palette_kinds,
    u32 palette_count, bool unk_3D)
    : GameSceneSpriteBase(world, size_shift, palette_kinds, palette_count),
      handle(resource, index, 0x100), unk_3C(1), unk_3D(unk_3D), unk_3E(0)
{
}

GameSceneIndexedSprite::GameSceneIndexedSprite(IndexedResourceProvider * resource,
    u32 index, GameObject * world, u32 size_shift, i32 palette_kind, bool unk_3D)
    : GameSceneSpriteBase(world, size_shift, palette_kind),
      handle(resource, index, 0x100), unk_3C(1), unk_3D(unk_3D), unk_3E(0)
{
}

u32 GameSceneSpriteBase::Submit(WorldSpriteDrawBuffer * buffer, i32 x, i32 y,
    u32 priorities, u32 sort_key, IndexedResourceSpriteRange const & range,
    GameObject * palette_source) const
{
    bool has_handle = tiles.handle != 0;
    if (has_handle) {
        u32 first_tile = tile_index;
        GameScenePaletteIndices const & palette_indices = palettes;
        return SubmitWorldSpriteRecords(buffer, x, y, priorities, sort_key,
            range, palette_source, first_tile, palette_indices);
    }
    return 0;
}

asm_unified(
    ".pushsection .iwram, \"ax\", %progbits\n"
    ".include \"asm/macro.inc\"\n"
    "arm_func_start SubmitWorldSpriteRecords\n"
    "SubmitWorldSpriteRecords:\n"
    "    push {r4, r5, r6, r7, r8, sb, sl, lr}\n"
    "    mov ip, #0\n"
    "    sub sp, sp, #0x34\n"
    "    str ip, [sp, #0x24]\n"
    "    str ip, [sp, #0x28]\n"
    "    str ip, [sp, #0x2c]\n"
    "    ldr r4, [sp, #0x58]\n"
    "    str ip, [sp, #8]\n"
    "    ldr r6, [r4]\n"
    "    str ip, [sp, #0x30]\n"
    "    str r1, [sp, #0x18]\n"
    "    mov r7, r0\n"
    "    str r2, [sp, #0x14]\n"
    "    add r0, sp, #0x24\n"
    "    str r3, [sp, #0x10]\n"
    "    mov lr, ip\n"
    "    str r0, [sp, #0xc]\n"
    "    cmp r6, ip\n"
    "    ldrhne lr, [r4, #4]\n"
    "    add lr, r6, lr, lsl #3\n"
    "    str lr, [sp, #4]\n"
    "    cmp r6, lr\n"
    "    beq .Lauto_030006FC\n"
    "    .Lauto_03000538:\n"
    "    add r1, sp, #0x1c\n"
    "    str r1, [sp]\n"
    "    ldm r6, {r2, r3}\n"
    "    mov r0, r1\n"
    "    stm r0, {r2, r3}\n"
    "    add r1, sp, #0x18\n"
    "    ldm r1, {r1, r2}\n"
    "    mov r8, r2\n"
    "    lsl r3, r2, #7\n"
    "    add ip, r1, r3, asr #23\n"
    "    cmp ip, #0xef\n"
    "    mov sb, ip\n"
    "    bgt .Lauto_030006EC\n"
    "    ldr r1, [sp, #0x14]\n"
    "    lsl r3, r2, #0x18\n"
    "    add r0, r1, r3, asr #24\n"
    "    cmp r0, #0x9f\n"
    "    mov sl, r0\n"
    "    bgt .Lauto_030006EC\n"
    "    lsr r3, r2, #0x1e\n"
    "    and r2, r2, #0xc000\n"
    "    lsr r2, r2, #0xb\n"
    "    ldr r1, .LIwramSpriteDimensions\n"
    "    orr r2, r2, r3, lsl #1\n"
    "    ldrh r2, [r1, r2]\n"
    "    and r3, r2, #0xff\n"
    "    add r3, ip, r3\n"
    "    cmp r3, #0\n"
    "    ble .Lauto_030006EC\n"
    "    add r3, r0, r2, lsr #8\n"
    "    cmp r3, #0\n"
    "    ble .Lauto_030006EC\n"
    "    ldr r3, [sp, #0x20]\n"
    "    mov r5, r3\n"
    "    and r2, r5, #0xf000\n"
    "    lsr r4, r2, #0xc\n"
    "    ldr r2, [sp, #0xc]\n"
    "    ldrb r3, [r2, r4]\n"
    "    subs ip, r3, #0x10\n"
    "    bpl .Lauto_0300060C\n"
    "    ldr r0, [sp, #0x5c]\n"
    "    ldr r3, [r0]\n"
    "    ldr r0, [sp, #0x64]\n"
    "    add r2, r4, #4\n"
    "    ldrb r1, [r0, r2]\n"
    "    ldr r0, [sp, #0x5c]\n"
    "    ldr ip, [r3, #0x50]\n"
    "    mov lr, pc\n"
    "    bx ip\n"
    "    mov ip, r0\n"
    "    ldr r1, [sp, #0xc]\n"
    "    add r3, ip, #0x10\n"
    "    strb r3, [r1, r4]\n"
    ".Lauto_0300060C:\n"
    "    bic r2, r8, #0xff00000\n"
    "    bic r2, r2, #0xf3000\n"
    "    bic r2, r2, #0xff0\n"
    "    bic r2, r2, #0xf\n"
    "    lsl r1, r5, #0x16\n"
    "    orr r2, r2, #0x1000\n"
    "    lsl r0, sl, #0x18\n"
    "    lsl r3, sb, #0x17\n"
    "    lsr r3, r3, #7\n"
    "    orr r3, r3, r0, lsr #24\n"
    "    orr r2, r2, r3\n"
    "    str r2, [sp, #0x1c]\n"
    "    lsr r1, r1, #0x16\n"
    "    ldr r2, [sp, #0x60]\n"
    "    and r3, r5, #0xc00\n"
    "    ldr r0, [sp, #0x10]\n"
    "    lsr r3, r3, #9\n"
    "    ldr lr, [sp]\n"
    "    add r1, r1, r2\n"
    "    orr r1, r1, ip, lsl #12\n"
    "    lsr r3, r0, r3\n"
    "    lsl r3, r3, #0xa\n"
    "    and r3, r3, #0xc00\n"
    "    ldrb r0, [r7]\n"
    "    orr r1, r1, r3\n"
    "    str r1, [sp, #0x20]\n"
    "    cmp r0, #0x7f\n"
    "    bhi .Lauto_030006E0\n"
    "    ldrb r3, [lr, #5]\n"
    "    ldr r2, [sp, #0x54]\n"
    "    lsr r3, r3, #2\n"
    "    and r3, r3, #3\n"
    "    orr r3, r3, r3, lsl #7\n"
    "    add r1, r7, r3, lsl #2\n"
    "    ldr r3, [r1, #4]!\n"
    "    orr ip, r0, r2, lsl #7\n"
    "    cmp r3, #0x7f\n"
    "    bhi .Lauto_030006C4\n"
    "    lsl r3, r3, #2\n"
    "    add r3, r3, #4\n"
    "    add r2, r1, r3\n"
    "    cmp r2, #0\n"
    "    strne ip, [r1, r3]\n"
    "    ldr r3, [r1]\n"
    "    add r3, r3, #1\n"
    "    str r3, [r1]\n"
    "    .Lauto_030006C4:\n"
    "    add r3, r7, r0, lsl #3\n"
    "    add r3, r3, #0x810\n"
    "    ldm lr, {r1, r2}\n"
    "    add r3, r3, #4\n"
    "    stm r3, {r1, r2}\n"
    "    add r2, r0, #1\n"
    "    strb r2, [r7]\n"
    "    .Lauto_030006E0:\n"
    "    ldr r2, [sp, #8]\n"
    "    add r2, r2, #1\n"
    "    str r2, [sp, #8]\n"
    "    .Lauto_030006EC:\n"
    "    ldr r3, [sp, #4]\n"
    "    add r6, r6, #8\n"
    "    cmp r6, r3\n"
    "    bne .Lauto_03000538\n"
    "    .Lauto_030006FC:\n"
    "    ldr r0, [sp, #8]\n"
    "    b .Lauto_03000708\n"
    ".LIwramSpriteDimensions: .word gHardwareSpriteDimensions\n"
    "    .Lauto_03000708:\n"
    "    add sp, sp, #0x34\n"
    "    pop {r4, r5, r6, r7, r8, sb, sl, lr}\n"
    "    bx lr\n"
    ".popsection\n"
    ".thumb\n"
);
