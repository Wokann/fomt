#include "obj_palette_collection.hh"
#include "new_game_birthday_input.hh"
#include "gbaio.h"
#include "new_game_identity.hh"
#include "new_game_name_input.hh"
#include "intro_scene.hh"
#include "new_game_data.hh"
#include "game_state.hh"
#include "hardware_context.hh"
#include "obj_tile_collection.hh"
#include "hardware_blend.hh"
#include "hardware_display_state.hh"
#include "hardware_sprite_buffer.hh"
#include "hardware_dma.hh"
#include "hardware_interrupt_guard.hh"
#include "hardware_sound.hh"
#include "sram_image.hh"
#include "ui_state.hh"
#include <string.h>
#include "game_scene.hh"

#include <new>

static inline void QueueMenuBlend(HardwareContext * core, HardwareBlendObject & blend)
{
    HardwareLinkedList * list =
        GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    list->Append(&blend);
}

static inline bool MenuBlendIsQueued(HardwareBlendObject const & blend)
{
    return blend.previous_slot != nullptr;
}

static inline u32 SpriteTileIndex(ObjTileCollectionEntry & entry)
{
    return GetObjTileIndex(&entry, entry.handle);
}

static inline u32 SpritePaletteBank(ObjPaletteCollectionEntry & entry)
{
    return GetObjPaletteBank(&entry, entry.handle);
}

static inline void SetBirthdayInputDate(GameDate & destination, Season season,
    u32 const & requested_day)
{
    destination.season = season;
    u32 day = requested_day;
    if (day > 29)
        day %= 30;
    destination.day = day;
}

static inline void SubmitBirthdaySprite(NewGameBirthdayInputCore * core,
    HardwareSpriteOamRecord const & attributes)
{
    HardwareSpriteBufferState * buffer =
        GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
    u32 const & position_and_mode = reinterpret_cast<u32 const &>(attributes);
    u32 count = buffer->sprite_count;
    if (count < ARRAY_COUNT(buffer->sprites)) {
        HardwareSpriteOamRecord & destination = buffer->sprites[count];
        reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
        reinterpret_cast<u16 *>(&destination)[2] =
            reinterpret_cast<u16 const *>(&attributes)[2];
        buffer->sprite_count = count + 1;
    }
}

inline BirthdayInputUiOwner::BirthdayInputUiOwner(u32 const & flags)
{
    // Reserve the owner before acquiring the temporary shared resources.
    void * storage = ::operator new(sizeof(UiStateOwner));
    ObjTileCollection shared;
    ObjPaletteCollection resources;
    value = new (storage) UiStateOwner(0, 31, 15, flags, shared, resources);
}

#if defined(REGION_JP)
asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "thumb_func_start __24NewGameBirthdayInputCoreG8GameDate\n"
    "__24NewGameBirthdayInputCoreG8GameDate:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, r8\n"
    "    push {r7}\n"
    "    sub sp, #24\n"
    "    adds r7, r0, #0\n"
    "    adds r6, r1, #0\n"
    "    add r1, sp, #20\n"
    "    movs r0, #30\n"
    "    movs r2, #1\n"
    "    movs r3, #0\n"
    "    mov r8, r3\n"
    "    strh r0, [r1, #0]\n"
    "    strh r2, [r1, #2]\n"
    "    adds r0, r7, #0\n"
    "    bl __15HardwareContextRC29HardwareInputRepeatParameters\n"
    "    ldr r0, .Lscalar_1_1\n"
    "    str r0, [r7, #4]\n"
    "    mov r0, r8\n"
    "    str r0, [r7, #8]\n"
    "    movs r0, #4\n"
    "    bl __builtin_new\n"
    "    adds r5, r0, #0\n"
    "    add r0, sp, #12\n"
    "    bl __17ObjTileCollection\n"
    "    add r4, sp, #16\n"
    "    adds r0, r4, #0\n"
    "    bl __20ObjPaletteCollection\n"
    "    ldr r0, [r7, #8]\n"
    "    str r0, [sp, #0]\n"
    "    add r1, sp, #12\n"
    "    str r1, [sp, #4]\n"
    "    str r4, [sp, #8]\n"
    "    adds r0, r5, #0\n"
    "    movs r1, #0\n"
    "    movs r2, #31\n"
    "    movs r3, #15\n"
    "    bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection\n"
    "    str r0, [r7, #12]\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #2\n"
    "    bl _._20ObjPaletteCollection\n"
    "    add r0, sp, #12\n"
    "    movs r1, #2\n"
    "    bl _._17ObjTileCollection\n"
    "    adds r0, r7, #0\n"
    "    adds r0, #16\n"
    "    movs r1, #1\n"
    "    bl __23HardwareMusicPlayerSlotUc\n"
    "    adds r0, r7, #0\n"
    "    adds r0, #20\n"
    "    movs r1, #2\n"
    "    bl __23HardwareMusicPlayerSlotUc\n"
    "    adds r4, r7, #0\n"
    "    adds r4, #24\n"
    "    adds r0, r4, #0\n"
    "    bl InitializeObjTilePoolOwner\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #7\n"
    "    bl AllocateObjTileHandle\n"
    "    str r0, [r4, #4]\n"
    "    adds r4, #8\n"
    "    adds r0, r4, #0\n"
    "    bl ConstructObjPalettePoolOwner\n"
    "    adds r0, r4, #0\n"
    "    bl AllocateObjPaletteHandle\n"
    "    str r0, [r4, #4]\n"
    "    adds r4, #8\n"
    "    adds r0, r4, #0\n"
    "    bl InitializeObjTilePoolOwner\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #3\n"
    "    bl AllocateObjTileHandle\n"
    "    str r0, [r4, #4]\n"
    "    adds r4, #8\n"
    "    adds r0, r4, #0\n"
    "    bl ConstructObjPalettePoolOwner\n"
    "    adds r0, r4, #0\n"
    "    bl AllocateObjPaletteHandle\n"
    "    str r0, [r4, #4]\n"
    "    lsls r1, r6, #30\n"
    "    lsls r6, r6, #25\n"
    "    movs r2, #158\n"
    "    lsls r2, r2, #2\n"
    "    adds r4, r7, r2\n"
    "    lsrs r1, r1, #30\n"
    "    ldrb r2, [r4, #0]\n"
    "    movs r0, #4\n"
    "    negs r0, r0\n"
    "    ands r0, r2\n"
    "    orrs r0, r1\n"
    "    strb r0, [r4, #0]\n"
    "    lsrs r2, r6, #27\n"
    "    cmp r2, #29\n"
    "    bls .Lscalar_1_0\n"
    "    adds r0, r2, #0\n"
    "    movs r1, #30\n"
    "    bl __umodsi3\n"
    "    adds r2, r0, #0\n"
    ".Lscalar_1_0:\n"
    "    movs r0, #31\n"
    "    ands r2, r0\n"
    "    lsls r2, r2, #2\n"
    "    ldrb r1, [r4, #0]\n"
    "    movs r0, #125\n"
    "    negs r0, r0\n"
    "    ands r0, r1\n"
    "    orrs r0, r2\n"
    "    strb r0, [r4, #0]\n"
    "    movs r3, #159\n"
    "    lsls r3, r3, #2\n"
    "    adds r0, r7, r3\n"
    "    mov r1, r8\n"
    "    strh r1, [r0, #0]\n"
    "    ldr r2, .Lscalar_1_2\n"
    "    adds r1, r7, r2\n"
    "    movs r0, #2\n"
    "    strh r0, [r1, #0]\n"
    "    ldrb r0, [r4, #0]\n"
    "    lsls r0, r0, #30\n"
    "    lsrs r1, r0, #30\n"
    "    cmp r1, #1\n"
    "    beq .Lscalar_1_6\n"
    "    cmp r1, #1\n"
    "    bgt .Lscalar_1_3\n"
    "    cmp r1, #0\n"
    "    beq .Lscalar_1_4\n"
    "    b .Lscalar_1_11\n"
    ".Lscalar_1_1: .word __vt_24NewGameBirthdayInputCore\n"
    ".Lscalar_1_2: .word 0x0000027e\n"
    ".Lscalar_1_3:\n"
    "    cmp r1, #2\n"
    "    beq .Lscalar_1_8\n"
    "    cmp r1, #3\n"
    "    beq .Lscalar_1_10\n"
    "    b .Lscalar_1_11\n"
    ".Lscalar_1_4:\n"
    "    ldr r3, .Lscalar_1_5\n"
    "    adds r1, r7, r3\n"
    "    movs r0, #0\n"
    "    strb r0, [r1, #0]\n"
    "    b .Lscalar_1_11\n"
    ".Lscalar_1_5: .word 0x00000279\n"
    ".Lscalar_1_6:\n"
    "    ldr r0, .Lscalar_1_7\n"
    "    adds r1, r7, r0\n"
    "    movs r0, #1\n"
    "    strb r0, [r1, #0]\n"
    "    b .Lscalar_1_11\n"
    "    .align 2, 0\n"
    ".Lscalar_1_7: .word 0x00000279\n"
    ".Lscalar_1_8:\n"
    "    ldr r2, .Lscalar_1_9\n"
    "    adds r1, r7, r2\n"
    "    movs r0, #2\n"
    "    strb r0, [r1, #0]\n"
    "    b .Lscalar_1_11\n"
    "    .align 2, 0\n"
    ".Lscalar_1_9: .word 0x00000279\n"
    ".Lscalar_1_10:\n"
    "    ldr r3, .Lscalar_1_12\n"
    "    adds r0, r7, r3\n"
    "    strb r1, [r0, #0]\n"
    ".Lscalar_1_11:\n"
    "    movs r1, #158\n"
    "    lsls r1, r1, #2\n"
    "    adds r0, r7, r1\n"
    "    ldrb r0, [r0, #0]\n"
    "    lsls r0, r0, #25\n"
    "    lsrs r0, r0, #27\n"
    "    adds r0, #1\n"
    "    ldr r2, .Lscalar_1_13\n"
    "    adds r1, r7, r2\n"
    "    movs r2, #0\n"
    "    strb r0, [r1, #0]\n"
    "    ldr r3, .Lscalar_1_12\n"
    "    adds r0, r7, r3\n"
    "    ldrb r1, [r0, #0]\n"
    "    adds r0, r7, #0\n"
    "    adds r0, #56\n"
    "    strb r1, [r0, #0]\n"
    "    adds r0, #1\n"
    "    strb r2, [r0, #0]\n"
    "    adds r0, #1\n"
    "    strb r2, [r0, #0]\n"
    "    adds r0, #10\n"
    "    strb r2, [r0, #0]\n"
    "    adds r0, r7, #0\n"
    "    add sp, #24\n"
    "    pop {r3}\n"
    "    mov r8, r3\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r1}\n"
    "    bx r1\n"
    "    .align 2, 0\n"
    ".Lscalar_1_12: .word 0x00000279\n"
    ".Lscalar_1_13: .word 0x0000027a\n"
);
#else
asm_unified(
    ".text\n"
    ".include \"asm/macro.inc\"\n"
    "thumb_func_start __24NewGameBirthdayInputCoreG8GameDate\n"
    "__24NewGameBirthdayInputCoreG8GameDate:\n"
    "    push {r4, r5, r6, r7, lr}\n"
    "    mov r7, r8\n"
    "    push {r7}\n"
    "    sub sp, #24\n"
    "    adds r7, r0, #0\n"
    "    adds r6, r1, #0\n"
    "    add r1, sp, #20\n"
    "    movs r0, #30\n"
    "    movs r2, #1\n"
    "    movs r3, #0\n"
    "    mov r8, r3\n"
    "    strh r0, [r1, #0]\n"
    "    strh r2, [r1, #2]\n"
    "    adds r0, r7, #0\n"
    "    bl __15HardwareContextRC29HardwareInputRepeatParameters\n"
    "    ldr r0, .L__24NewGameBirthdayInputCoreG8GameDate_native_120\n"
    "    str r0, [r7, #4]\n"
    "    mov r0, r8\n"
    "    str r0, [r7, #8]\n"
    "    movs r0, #4\n"
    "    bl __builtin_new\n"
    "    adds r5, r0, #0\n"
    "    add r0, sp, #12\n"
    "    bl __17ObjTileCollection\n"
    "    add r4, sp, #16\n"
    "    adds r0, r4, #0\n"
    "    bl __20ObjPaletteCollection\n"
    "    ldr r0, [r7, #8]\n"
    "    str r0, [sp, #0]\n"
    "    add r1, sp, #12\n"
    "    str r1, [sp, #4]\n"
    "    str r4, [sp, #8]\n"
    "    adds r0, r5, #0\n"
    "    movs r1, #0\n"
    "    movs r2, #31\n"
    "    movs r3, #15\n"
    "    bl __12UiStateOwnerUiUiUiUiRC17ObjTileCollectionRC20ObjPaletteCollection\n"
    "    str r0, [r7, #12]\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #2\n"
    "    bl _._20ObjPaletteCollection\n"
    "    add r0, sp, #12\n"
    "    movs r1, #2\n"
    "    bl _._17ObjTileCollection\n"
    "    adds r0, r7, #0\n"
    "    adds r0, #16\n"
    "    movs r1, #1\n"
    "    bl __23HardwareMusicPlayerSlotUc\n"
    "    adds r0, r7, #0\n"
    "    adds r0, #20\n"
    "    movs r1, #2\n"
    "    bl __23HardwareMusicPlayerSlotUc\n"
    "    adds r4, r7, #0\n"
    "    adds r4, #24\n"
    "    adds r0, r4, #0\n"
    "    bl InitializeObjTilePoolOwner\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #7\n"
    "    bl AllocateObjTileHandle\n"
    "    str r0, [r4, #4]\n"
    "    adds r4, #8\n"
    "    adds r0, r4, #0\n"
    "    bl ConstructObjPalettePoolOwner\n"
    "    adds r0, r4, #0\n"
    "    bl AllocateObjPaletteHandle\n"
    "    str r0, [r4, #4]\n"
    "    adds r4, #8\n"
    "    adds r0, r4, #0\n"
    "    bl InitializeObjTilePoolOwner\n"
    "    adds r0, r4, #0\n"
    "    movs r1, #3\n"
    "    bl AllocateObjTileHandle\n"
    "    str r0, [r4, #4]\n"
    "    adds r4, #8\n"
    "    adds r0, r4, #0\n"
    "    bl ConstructObjPalettePoolOwner\n"
    "    adds r0, r4, #0\n"
    "    bl AllocateObjPaletteHandle\n"
    "    str r0, [r4, #4]\n"
    "    lsls r1, r6, #30\n"
    "    lsls r6, r6, #25\n"
#if defined(REGION_DE)
    "    movs r2, #140\n"
#else
    "    movs r2, #137\n"
#endif
    "    lsls r2, r2, #3\n"
    "    adds r4, r7, r2\n"
    "    lsrs r1, r1, #30\n"
    "    ldrb r2, [r4, #0]\n"
    "    movs r0, #4\n"
    "    negs r0, r0\n"
    "    ands r0, r2\n"
    "    orrs r0, r1\n"
    "    strb r0, [r4, #0]\n"
    "    lsrs r2, r6, #27\n"
    "    cmp r2, #29\n"
    "    bls .L__24NewGameBirthdayInputCoreG8GameDate_native_e8\n"
    "    adds r0, r2, #0\n"
    "    movs r1, #30\n"
    "    bl __umodsi3\n"
    "    adds r2, r0, #0\n"
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_e8:\n"
    "    movs r0, #31\n"
    "    ands r2, r0\n"
    "    lsls r2, r2, #2\n"
    "    ldrb r1, [r4, #0]\n"
    "    movs r0, #125\n"
    "    negs r0, r0\n"
    "    ands r0, r1\n"
    "    orrs r0, r2\n"
    "    strb r0, [r4, #0]\n"
    "    ldr r3, .L__24NewGameBirthdayInputCoreG8GameDate_native_124\n"
    "    adds r0, r7, r3\n"
    "    mov r1, r8\n"
    "    strh r1, [r0, #0]\n"
    "    ldr r2, .L__24NewGameBirthdayInputCoreG8GameDate_native_128\n"
    "    adds r1, r7, r2\n"
    "    movs r0, #2\n"
    "    strh r0, [r1, #0]\n"
    "    ldrb r0, [r4, #0]\n"
    "    lsls r0, r0, #30\n"
    "    lsrs r0, r0, #30\n"
    "    cmp r0, #1\n"
    "    beq .L__24NewGameBirthdayInputCoreG8GameDate_native_144\n"
    "    cmp r0, #1\n"
    "    bgt .L__24NewGameBirthdayInputCoreG8GameDate_native_12c\n"
    "    cmp r0, #0\n"
    "    beq .L__24NewGameBirthdayInputCoreG8GameDate_native_136\n"
    "    b .L__24NewGameBirthdayInputCoreG8GameDate_native_164\n"
    "    .align 2, 0\n"
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_120: .word __vt_24NewGameBirthdayInputCore\n"
#if defined(REGION_DE)
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_124: .word 0x00000464\n"
#else
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_124: .word 0x0000044c\n"
#endif
#if defined(REGION_DE)
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_128: .word 0x00000466\n"
#else
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_128: .word 0x0000044e\n"
#endif
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_12c:\n"
    "    cmp r0, #2\n"
    "    beq .L__24NewGameBirthdayInputCoreG8GameDate_native_150\n"
    "    cmp r0, #3\n"
    "    beq .L__24NewGameBirthdayInputCoreG8GameDate_native_15c\n"
    "    b .L__24NewGameBirthdayInputCoreG8GameDate_native_164\n"
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_136:\n"
    "    ldr r3, .L__24NewGameBirthdayInputCoreG8GameDate_native_140\n"
    "    adds r1, r7, r3\n"
    "    movs r0, #0\n"
    "    b .L__24NewGameBirthdayInputCoreG8GameDate_native_162\n"
    "    .align 2, 0\n"
#if defined(REGION_DE)
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_140: .word 0x00000461\n"
#else
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_140: .word 0x00000449\n"
#endif
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_144:\n"
    "    ldr r0, .L__24NewGameBirthdayInputCoreG8GameDate_native_14c\n"
    "    adds r1, r7, r0\n"
    "    movs r0, #4\n"
    "    b .L__24NewGameBirthdayInputCoreG8GameDate_native_162\n"
#if defined(REGION_DE)
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_14c: .word 0x00000461\n"
#else
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_14c: .word 0x00000449\n"
#endif
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_150:\n"
    "    ldr r2, .L__24NewGameBirthdayInputCoreG8GameDate_native_158\n"
    "    adds r1, r7, r2\n"
    "    movs r0, #8\n"
    "    b .L__24NewGameBirthdayInputCoreG8GameDate_native_162\n"
#if defined(REGION_DE)
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_158: .word 0x00000461\n"
#else
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_158: .word 0x00000449\n"
#endif
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_15c:\n"
    "    ldr r3, .L__24NewGameBirthdayInputCoreG8GameDate_native_1a0\n"
    "    adds r1, r7, r3\n"
    "    movs r0, #12\n"
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_162:\n"
    "    strb r0, [r1, #0]\n"
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_164:\n"
#if defined(REGION_DE)
    "    movs r1, #140\n"
#else
    "    movs r1, #137\n"
#endif
    "    lsls r1, r1, #3\n"
    "    adds r0, r7, r1\n"
    "    ldrb r0, [r0, #0]\n"
    "    lsls r0, r0, #25\n"
    "    lsrs r0, r0, #27\n"
    "    adds r0, #1\n"
    "    ldr r2, .L__24NewGameBirthdayInputCoreG8GameDate_native_1a4\n"
    "    adds r1, r7, r2\n"
    "    movs r2, #0\n"
    "    strb r0, [r1, #0]\n"
    "    ldr r3, .L__24NewGameBirthdayInputCoreG8GameDate_native_1a0\n"
    "    adds r0, r7, r3\n"
    "    ldrb r1, [r0, #0]\n"
    "    adds r0, r7, #0\n"
    "    adds r0, #56\n"
    "    strb r1, [r0, #0]\n"
    "    adds r0, #1\n"
    "    strb r2, [r0, #0]\n"
    "    adds r0, #1\n"
    "    strb r2, [r0, #0]\n"
    "    adds r0, #10\n"
    "    strb r2, [r0, #0]\n"
    "    adds r0, r7, #0\n"
    "    add sp, #24\n"
    "    pop {r3}\n"
    "    mov r8, r3\n"
    "    pop {r4, r5, r6, r7}\n"
    "    pop {r1}\n"
    "    bx r1\n"
#if defined(REGION_DE)
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_1a0: .word 0x00000461\n"
#else
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_1a0: .word 0x00000449\n"
#endif
#if defined(REGION_DE)
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_1a4: .word 0x00000462\n"
#else
    ".L__24NewGameBirthdayInputCoreG8GameDate_native_1a4: .word 0x0000044a\n"
#endif
);
#endif

asm_unified(
    ".text\n"
    ".include \"six/asm/hw/video.s\"\n"
    ".ifdef REGION_JP\n"
    "\t.global RunBirthdayInputCore\n"
    "\t.thumb_func\n"
    "RunBirthdayInputCore:\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sl\n"
    "\tmov r6, sb\n"
    "\tmov r5, r8\n"
    "\tpush {r5, r6, r7}\n"
    "\tsub sp, #0x18\n"
    "\tmov sl, r0\n"
    "\tadds r5, r1, #0\n"
    "\tadds r0, r5, #0\n"
    "\tbl EnableHardwareForcedBlank\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tmov r1, sp\n"
    "\tmovs r2, #0x3f\n"
    "\tstrh r2, [r1]\n"
    "\tadds r0, #0x50\n"
    "\tstrh r2, [r0]\n"
    "\tmovs r0, #0x10\n"
    "\tbl __builtin_new\n"
    "\tadds r4, r0, #0\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadds r1, r0, #0\n"
    "\tmovs r0, #0\n"
    "\tstr r0, [r4]\n"
    "\tstr r0, [r4, #4]\n"
    "\tldr r0, .Ljp_0806D9E4\n"
    "\tstr r0, [r4, #8]\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0xc\n"
    "\tbl __23HardwareBlendControllerP20HardwareDisplayState\n"
    "\tstr r4, [sp, #4]\n"
    "\tadds r0, r5, #0\n"
    "\tbl InitializeBirthdayInputGraphics\n"
    "\tadds r0, r5, #0\n"
    "\tbl InitializeBirthdayInputCursor\n"
    "\tadds r0, r5, #0\n"
    "\tbl BuildBirthdayInputGlyphs\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, .Ljp_0806D9E8\n"
    "\tadds r0, #0xc\n"
    "\tmovs r2, #1\n"
    "\tmovs r3, #1\n"
    "\tbl BeginHardwareBlend\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareCommandList\n"
    "\tldr r2, [r0, #8]\n"
    "\tldr r1, [sp, #4]\n"
    "\tldr r2, [r2, #0x10]\n"
    "\tbl _call_via_r2\n"
    "\tmovs r0, #0\n"
    "\tmov r8, r0\n"
    "\tadd r1, sp, #8\n"
    "\tmov sb, r1\n"
    "\tmov r0, sp\n"
    "\tadds r0, #0xc\n"
    "\tstr r0, [sp, #0x14]\n"
    ".Ljp_0806D9BC:\n"
    "\tadds r0, r5, #0\n"
    "\tbl UpdateHardwareFrame\n"
    "\tadds r0, r5, #0\n"
    "\tbl UpdateHardwareInput\n"
    "\tmovs r1, #0x9f\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r5, r1\n"
    "\tmovs r1, #0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tcmp r0, #4\n"
    "\tbls .Ljp_0806D9D8\n"
    "\tb .Ljp_0806DB34\n"
    ".Ljp_0806D9D8:\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .Ljp_0806D9EC\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".Ljp_0806D9E4: .word __vt_19HardwareBlendObject\n"
    ".Ljp_0806D9E8: .word 0x00000889\n"
    ".Ljp_0806D9EC: .word .Ljp_0806D9F0\n"
    ".Ljp_0806D9F0: .word .Ljp_0806DA04\n"
    "\t.word .Ljp_0806DA1C\n"
    "\t.word .Ljp_0806DA4C\n"
    "\t.word .Ljp_0806DAF2\n"
    "\t.word .Ljp_0806DB24\n"
    ".Ljp_0806DA04:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, [r0]\n"
    "\trsbs r0, r1, #0\n"
    "\torrs r0, r1\n"
    "\tcmp r0, #0\n"
    "\tbge .Ljp_0806DA12\n"
    "\tb .Ljp_0806DB34\n"
    ".Ljp_0806DA12:\n"
    "\tadds r1, r5, #0\n"
    "\tadds r1, #0x44\n"
    "\tmovs r0, #1\n"
    "\tstrb r0, [r1]\n"
    "\tb .Ljp_0806DB10\n"
    ".Ljp_0806DA1C:\n"
    "\tadds r0, r5, #0\n"
    "\tbl MoveBirthdayInputCursor\n"
    "\tadds r0, r5, #0\n"
    "\tbl UpdateBirthdayInputCursor\n"
    "\tadds r0, r5, #0\n"
    "\tbl ConfirmBirthdayInputSelection\n"
    "\tlsls r0, r0, #0x18\n"
    "\tcmp r0, #0\n"
    "\tbeq .Ljp_0806DA44\n"
    "\tldr r0, .Ljp_0806DA40\n"
    "\tadds r1, r5, r0\n"
    "\tmovs r0, #0\n"
    "\tstrh r0, [r1]\n"
    "\tb .Ljp_0806DB10\n"
    "\t.align 2, 0\n"
    ".Ljp_0806DA40: .word 0x0000027E\n"
    ".Ljp_0806DA44:\n"
    "\tadds r0, r5, #0\n"
    "\tbl CancelBirthdayInputSelection\n"
    "\tb .Ljp_0806DB34\n"
    ".Ljp_0806DA4C:\n"
    "\tldr r1, .Ljp_0806DA80\n"
    "\tadds r0, r5, r1\n"
    "\tmovs r1, #0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tcmp r0, #2\n"
    "\tbne .Ljp_0806DB34\n"
    "\tmovs r1, #0xa0\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r0, r5, r1\n"
    "\tmovs r1, #0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tcmp r0, #0\n"
    "\tbne .Ljp_0806DAE4\n"
    "\tldr r1, .Ljp_0806DA84\n"
    "\tadds r0, r5, r1\n"
    "\tldrb r0, [r0]\n"
    "\tlsls r0, r0, #0x18\n"
    "\tasrs r0, r0, #0x18\n"
    "\tcmp r0, #1\n"
    "\tbeq .Ljp_0806DA92\n"
    "\tcmp r0, #1\n"
    "\tbgt .Ljp_0806DA88\n"
    "\tcmp r0, #0\n"
    "\tbeq .Ljp_0806DA8E\n"
    "\tb .Ljp_0806DA9A\n"
    "\t.align 2, 0\n"
    ".Ljp_0806DA80: .word 0x0000027E\n"
    ".Ljp_0806DA84: .word 0x00000279\n"
    ".Ljp_0806DA88:\n"
    "\tcmp r0, #2\n"
    "\tbeq .Ljp_0806DA96\n"
    "\tb .Ljp_0806DA9A\n"
    ".Ljp_0806DA8E:\n"
    "\tmovs r2, #0\n"
    "\tb .Ljp_0806DA9C\n"
    ".Ljp_0806DA92:\n"
    "\tmovs r2, #1\n"
    "\tb .Ljp_0806DA9C\n"
    ".Ljp_0806DA96:\n"
    "\tmovs r2, #2\n"
    "\tb .Ljp_0806DA9C\n"
    ".Ljp_0806DA9A:\n"
    "\tmovs r2, #3\n"
    ".Ljp_0806DA9C:\n"
    "\tmovs r0, #0x9e\n"
    "\tlsls r0, r0, #2\n"
    "\tadds r6, r5, r0\n"
    "\tldr r1, .Ljp_0806DAE0\n"
    "\tadds r0, r5, r1\n"
    "\tldrb r0, [r0]\n"
    "\tlsls r0, r0, #0x18\n"
    "\tasrs r0, r0, #0x18\n"
    "\tmovs r4, #4\n"
    "\trsbs r4, r4, #0\n"
    "\tands r4, r7\n"
    "\torrs r4, r2\n"
    "\tsubs r1, r0, #1\n"
    "\tcmp r1, #0x1d\n"
    "\tbls .Ljp_0806DAC4\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #0x1e\n"
    "\tbl __umodsi3\n"
    "\tadds r1, r0, #0\n"
    ".Ljp_0806DAC4:\n"
    "\tmovs r0, #0x1f\n"
    "\tands r1, r0\n"
    "\tlsls r1, r1, #2\n"
    "\tmovs r0, #0x7d\n"
    "\trsbs r0, r0, #0\n"
    "\tands r0, r4\n"
    "\torrs r0, r1\n"
    "\tadds r7, r0, #0\n"
    "\tstrb r0, [r6]\n"
    "\tadds r1, r5, #0\n"
    "\tadds r1, #0x44\n"
    "\tmovs r0, #0\n"
    "\tstrb r0, [r1]\n"
    "\tb .Ljp_0806DB10\n"
    ".Ljp_0806DAE0: .word 0x0000027A\n"
    ".Ljp_0806DAE4:\n"
    "\tmovs r0, #0x9f\n"
    "\tlsls r0, r0, #2\n"
    "\tadds r1, r5, r0\n"
    "\tldrh r0, [r1]\n"
    "\tsubs r0, #1\n"
    "\tstrh r0, [r1]\n"
    "\tb .Ljp_0806DB34\n"
    ".Ljp_0806DAF2:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, .Ljp_0806DB20\n"
    "\tadds r0, #0xc\n"
    "\tmovs r2, #1\n"
    "\tmovs r3, #1\n"
    "\tbl EndHardwareBlend\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareCommandList\n"
    "\tldr r2, [r0, #8]\n"
    "\tldr r1, [sp, #4]\n"
    "\tldr r2, [r2, #0x10]\n"
    "\tbl _call_via_r2\n"
    ".Ljp_0806DB10:\n"
    "\tmovs r0, #0x9f\n"
    "\tlsls r0, r0, #2\n"
    "\tadds r1, r5, r0\n"
    "\tldrh r0, [r1]\n"
    "\tadds r0, #1\n"
    "\tstrh r0, [r1]\n"
    "\tb .Ljp_0806DB34\n"
    "\t.align 2, 0\n"
    ".Ljp_0806DB20: .word 0x00000889\n"
    ".Ljp_0806DB24:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, [r0]\n"
    "\trsbs r0, r1, #0\n"
    "\torrs r0, r1\n"
    "\tcmp r0, #0\n"
    "\tblt .Ljp_0806DB34\n"
    "\tmovs r1, #1\n"
    "\tmov r8, r1\n"
    ".Ljp_0806DB34:\n"
    "\tadds r0, r5, #0\n"
    "\tbl UpdateBirthdayInputUi\n"
    "\tadds r0, r5, #0\n"
    "\tbl RenderBirthdayInputSprites\n"
    "\tmov r0, r8\n"
    "\tcmp r0, #0\n"
    "\tbne .Ljp_0806DB48\n"
    "\tb .Ljp_0806D9BC\n"
    ".Ljp_0806DB48:\n"
    "\tmovs r0, #0\n"
    "\tstr r0, [sp, #8]\n"
    "\tmov r1, sb\n"
    "\tstr r1, [sp, #0xc]\n"
    "\tldr r1, [sp, #0x14]\n"
    "\tstr r0, [r1, #4]\n"
    "\tmov r1, sb\n"
    "\tstr r0, [r1]\n"
    "\tmov r1, sl\n"
    "\tstr r0, [r1]\n"
    "\tldr r1, [sp, #8]\n"
    "\tcmp r1, #0\n"
    "\tbeq .Ljp_0806DB6E\n"
    "\tldr r0, [r1]\n"
    "\tldr r2, [r0, #8]\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #3\n"
    "\tbl _call_via_r2\n"
    ".Ljp_0806DB6E:\n"
    "\tldr r1, [sp, #4]\n"
    "\tcmp r1, #0\n"
    "\tbeq .Ljp_0806DB80\n"
    "\tldr r0, [r1, #8]\n"
    "\tldr r2, [r0, #0xc]\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #3\n"
    "\tbl _call_via_r2\n"
    ".Ljp_0806DB80:\n"
    "\tmov r0, sl\n"
    "\tadd sp, #0x18\n"
    "\tpop {r3, r4, r5}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tmov sl, r5\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    "    .else\n"
    "\n"
    "\tthumb_func_start RunBirthdayInputCore\n"
    "RunBirthdayInputCore: @ 0x0806DB38\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sl\n"
    "\tmov r6, sb\n"
    "\tmov r5, r8\n"
    "\tpush {r5, r6, r7}\n"
    "\tsub sp, #0x18\n"
    "\tmov sl, r0\n"
    "\tadds r5, r1, #0\n"
    "\tadds r0, r5, #0\n"
    "\tbl EnableHardwareForcedBlank\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tmov r1, sp\n"
    "\tmovs r2, #0x3f\n"
    "\tstrh r2, [r1]\n"
    "\tadds r0, #0x50\n"
    "\tstrh r2, [r0]\n"
    "\tmovs r0, #0x10\n"
    "\tbl __builtin_new\n"
    "\tadds r4, r0, #0\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadds r1, r0, #0\n"
    "\tmovs r0, #0\n"
    "\tstr r0, [r4]\n"
    "\tstr r0, [r4, #4]\n"
    "\tldr r0, .L0806DBE4 @ =__vt_19HardwareBlendObject\n"
    "\tstr r0, [r4, #8]\n"
    "\tadds r0, r4, #0\n"
    "\tadds r0, #0xc\n"
    "\tbl __23HardwareBlendControllerP20HardwareDisplayState\n"
    "\tstr r4, [sp, #4]\n"
    "\tadds r0, r5, #0\n"
    "\tbl InitializeBirthdayInputGraphics\n"
    "\tadds r0, r5, #0\n"
    "\tbl InitializeBirthdayInputCursor\n"
    "\tadds r0, r5, #0\n"
    "\tbl BuildBirthdayInputGlyphs\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, .L0806DBE8 @ =0x00000889\n"
    "\tadds r0, #0xc\n"
    "\tmovs r2, #1\n"
    "\tmovs r3, #1\n"
    "\tbl BeginHardwareBlend\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareCommandList\n"
    "\tldr r2, [r0, #8]\n"
    "\tldr r1, [sp, #4]\n"
    "\tldr r2, [r2, #0x10]\n"
    "\tbl _call_via_r2\n"
    "\tmovs r0, #0\n"
    "\tmov r8, r0\n"
    "\tadd r1, sp, #8\n"
    "\tmov sb, r1\n"
    "\tmov r0, sp\n"
    "\tadds r0, #0xc\n"
    "\tstr r0, [sp, #0x14]\n"
    ".L0806DBC0:\n"
    "\tadds r0, r5, #0\n"
    "\tbl UpdateHardwareFrame\n"
    "\tadds r0, r5, #0\n"
    "\tbl UpdateHardwareInput\n"
    "\tldr r1, .L0806DBEC @ =0x0000044C\n"
    "\tadds r0, r5, r1\n"
    "\tmovs r1, #0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tcmp r0, #4\n"
    "\tbls .L0806DBDA\n"
    "\tb .L0806DD3C\n"
    ".L0806DBDA:\n"
    "\tlsls r0, r0, #2\n"
    "\tldr r1, .L0806DBF0 @ =.L0806DBF4\n"
    "\tadds r0, r0, r1\n"
    "\tldr r0, [r0]\n"
    "\tmov pc, r0\n"
    "\t.align 2, 0\n"
    ".L0806DBE4: .word __vt_19HardwareBlendObject\n"
    ".L0806DBE8: .word 0x00000889\n"
    ".L0806DBEC:\n"
    "\t.ifdef REGION_DE\n"
    "\t.word 0x00000464\n"
    "\t.else\n"
    "\t.word 0x0000044C\n"
    "\t.endif\n"
    ".L0806DBF0: .word .L0806DBF4\n"
    ".L0806DBF4: @ jump table\n"
    "\t.word .L0806DC08 @ case 0\n"
    "\t.word .L0806DC20 @ case 1\n"
    "\t.word .L0806DC50 @ case 2\n"
    "\t.word .L0806DCF8 @ case 3\n"
    "\t.word .L0806DD2C @ case 4\n"
    ".L0806DC08:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, [r0]\n"
    "\trsbs r0, r1, #0\n"
    "\torrs r0, r1\n"
    "\tcmp r0, #0\n"
    "\tbge .L0806DC16\n"
    "\tb .L0806DD3C\n"
    ".L0806DC16:\n"
    "\tadds r1, r5, #0\n"
    "\tadds r1, #0x44\n"
    "\tmovs r0, #1\n"
    "\tstrb r0, [r1]\n"
    "\tb .L0806DD16\n"
    ".L0806DC20:\n"
    "\tadds r0, r5, #0\n"
    "\tbl MoveBirthdayInputCursor\n"
    "\tadds r0, r5, #0\n"
    "\tbl UpdateBirthdayInputCursor\n"
    "\tadds r0, r5, #0\n"
    "\tbl ConfirmBirthdayInputSelection\n"
    "\tlsls r0, r0, #0x18\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0806DC48\n"
    "\tldr r0, .L0806DC44 @ =0x0000044E\n"
    "\tadds r1, r5, r0\n"
    "\tmovs r0, #0\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0806DD16\n"
    "\t.align 2, 0\n"
    ".L0806DC44:\n"
    "\t.ifdef REGION_DE\n"
    "\t.word 0x00000466\n"
    "\t.else\n"
    "\t.word 0x0000044E\n"
    "\t.endif\n"
    ".L0806DC48:\n"
    "\tadds r0, r5, #0\n"
    "\tbl CancelBirthdayInputSelection\n"
    "\tb .L0806DD3C\n"
    ".L0806DC50:\n"
    "\tldr r1, .L0806DC84 @ =0x0000044E\n"
    "\tadds r0, r5, r1\n"
    "\tmovs r1, #0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tcmp r0, #2\n"
    "\tbne .L0806DD3C\n"
    "\t.ifdef REGION_DE\n"
    "\tmovs r1, #0x8d\n"
    "\t.else\n"
    "\tmovs r1, #0x8a\n"
    "\t.endif\n"
    "\tlsls r1, r1, #3\n"
    "\tadds r0, r5, r1\n"
    "\tmovs r1, #0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tcmp r0, #0\n"
    "\tbne .L0806DCE8\n"
    "\tldr r1, .L0806DC88 @ =0x00000449\n"
    "\tadds r0, r5, r1\n"
    "\tldrb r0, [r0]\n"
    "\tlsls r0, r0, #0x18\n"
    "\tasrs r0, r0, #0x18\n"
    "\tcmp r0, #4\n"
    "\tbeq .L0806DC96\n"
    "\tcmp r0, #4\n"
    "\tbgt .L0806DC8C\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0806DC92\n"
    "\tb .L0806DC9E\n"
    "\t.align 2, 0\n"
    ".L0806DC84:\n"
    "\t.ifdef REGION_DE\n"
    "\t.word 0x00000466\n"
    "\t.else\n"
    "\t.word 0x0000044E\n"
    "\t.endif\n"
    ".L0806DC88:\n"
    "\t.ifdef REGION_DE\n"
    "\t.word 0x00000461\n"
    "\t.else\n"
    "\t.word 0x00000449\n"
    "\t.endif\n"
    ".L0806DC8C:\n"
    "\tcmp r0, #8\n"
    "\tbeq .L0806DC9A\n"
    "\tb .L0806DC9E\n"
    ".L0806DC92:\n"
    "\tmovs r2, #0\n"
    "\tb .L0806DCA0\n"
    ".L0806DC96:\n"
    "\tmovs r2, #1\n"
    "\tb .L0806DCA0\n"
    ".L0806DC9A:\n"
    "\tmovs r2, #2\n"
    "\tb .L0806DCA0\n"
    ".L0806DC9E:\n"
    "\tmovs r2, #3\n"
    ".L0806DCA0:\n"
    "\t.ifdef REGION_DE\n"
    "\tmovs r0, #0x8c\n"
    "\t.else\n"
    "\tmovs r0, #0x89\n"
    "\t.endif\n"
    "\tlsls r0, r0, #3\n"
    "\tadds r6, r5, r0\n"
    "\tldr r1, .L0806DCE4 @ =0x0000044A\n"
    "\tadds r0, r5, r1\n"
    "\tldrb r0, [r0]\n"
    "\tlsls r0, r0, #0x18\n"
    "\tasrs r0, r0, #0x18\n"
    "\tmovs r4, #4\n"
    "\trsbs r4, r4, #0\n"
    "\tands r4, r7\n"
    "\torrs r4, r2\n"
    "\tsubs r1, r0, #1\n"
    "\tcmp r1, #0x1d\n"
    "\tbls .L0806DCC8\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #0x1e\n"
    "\tbl __umodsi3\n"
    "\tadds r1, r0, #0\n"
    ".L0806DCC8:\n"
    "\tmovs r0, #0x1f\n"
    "\tands r1, r0\n"
    "\tlsls r1, r1, #2\n"
    "\tmovs r0, #0x7d\n"
    "\trsbs r0, r0, #0\n"
    "\tands r0, r4\n"
    "\torrs r0, r1\n"
    "\tadds r7, r0, #0\n"
    "\tstrb r0, [r6]\n"
    "\tadds r1, r5, #0\n"
    "\tadds r1, #0x44\n"
    "\tmovs r0, #0\n"
    "\tstrb r0, [r1]\n"
    "\tb .L0806DD16\n"
    "\t.align 2, 0\n"
    ".L0806DCE4:\n"
    "\t.ifdef REGION_DE\n"
    "\t.word 0x00000462\n"
    "\t.else\n"
    "\t.word 0x0000044A\n"
    "\t.endif\n"
    ".L0806DCE8:\n"
    "\tldr r0, .L0806DCF4 @ =0x0000044C\n"
    "\tadds r1, r5, r0\n"
    "\tldrh r0, [r1]\n"
    "\tsubs r0, #1\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0806DD3C\n"
    "\t.align 2, 0\n"
    ".L0806DCF4:\n"
    "\t.ifdef REGION_DE\n"
    "\t.word 0x00000464\n"
    "\t.else\n"
    "\t.word 0x0000044C\n"
    "\t.endif\n"
    ".L0806DCF8:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, .L0806DD24 @ =0x00000889\n"
    "\tadds r0, #0xc\n"
    "\tmovs r2, #1\n"
    "\tmovs r3, #1\n"
    "\tbl EndHardwareBlend\n"
    "\tadds r0, r5, #0\n"
    "\tbl GetHardwareCommandList\n"
    "\tldr r2, [r0, #8]\n"
    "\tldr r1, [sp, #4]\n"
    "\tldr r2, [r2, #0x10]\n"
    "\tbl _call_via_r2\n"
    ".L0806DD16:\n"
    "\tldr r0, .L0806DD28 @ =0x0000044C\n"
    "\tadds r1, r5, r0\n"
    "\tldrh r0, [r1]\n"
    "\tadds r0, #1\n"
    "\tstrh r0, [r1]\n"
    "\tb .L0806DD3C\n"
    "\t.align 2, 0\n"
    ".L0806DD24: .word 0x00000889\n"
    ".L0806DD28:\n"
    "\t.ifdef REGION_DE\n"
    "\t.word 0x00000464\n"
    "\t.else\n"
    "\t.word 0x0000044C\n"
    "\t.endif\n"
    ".L0806DD2C:\n"
    "\tldr r0, [sp, #4]\n"
    "\tldr r1, [r0]\n"
    "\trsbs r0, r1, #0\n"
    "\torrs r0, r1\n"
    "\tcmp r0, #0\n"
    "\tblt .L0806DD3C\n"
    "\tmovs r1, #1\n"
    "\tmov r8, r1\n"
    ".L0806DD3C:\n"
    "\tadds r0, r5, #0\n"
    "\tbl UpdateBirthdayInputUi\n"
    "\tadds r0, r5, #0\n"
    "\tbl RenderBirthdayInputSprites\n"
    "\tmov r0, r8\n"
    "\tcmp r0, #0\n"
    "\tbne .L0806DD50\n"
    "\tb .L0806DBC0\n"
    ".L0806DD50:\n"
    "\tmovs r0, #0\n"
    "\tstr r0, [sp, #8]\n"
    "\tmov r1, sb\n"
    "\tstr r1, [sp, #0xc]\n"
    "\tldr r1, [sp, #0x14]\n"
    "\tstr r0, [r1, #4]\n"
    "\tmov r1, sb\n"
    "\tstr r0, [r1]\n"
    "\tmov r1, sl\n"
    "\tstr r0, [r1]\n"
    "\tldr r1, [sp, #8]\n"
    "\tcmp r1, #0\n"
    "\tbeq .L0806DD76\n"
    "\tldr r0, [r1]\n"
    "\tldr r2, [r0, #8]\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #3\n"
    "\tbl _call_via_r2\n"
    ".L0806DD76:\n"
    "\tldr r1, [sp, #4]\n"
    "\tcmp r1, #0\n"
    "\tbeq .L0806DD88\n"
    "\tldr r0, [r1, #8]\n"
    "\tldr r2, [r0, #0xc]\n"
    "\tadds r0, r1, #0\n"
    "\tmovs r1, #3\n"
    "\tbl _call_via_r2\n"
    ".L0806DD88:\n"
    "\tmov r0, sl\n"
    "\tadd sp, #0x18\n"
    "\tpop {r3, r4, r5}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tmov sl, r5\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
    "\n"
    "    .endif\n"
);


void UpdateBirthdayInputUi(NewGameBirthdayInputCore * core)
{
    UiStateOwner const * ui = core->ui_state.value;
    HardwareCoreState * state = static_cast<HardwareCoreState *>(GetHardwareCoreState(reinterpret_cast<void * const *>(core)));
    HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
    HardwareDisplayState * display = GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    HardwareLinkedList * links = GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    HardwareInterruptList * manager = GetHardwareInterruptList(reinterpret_cast<void * const *>(core));
    HardwareMusicPlayerSlot * music = &core->music_player_1;
    switch (ui->Update(&state->input, sprites, display, links, manager, music)) {
    case 0:
        if (core->dialogue_state == 0) {
            func_08050D5C(core->ui_state.value);
            core->dialogue_state = 3;
        } else {
            core->dialogue_state = 2;
        }
        break;
    case 3:
        if (core->dialogue_state == 5) {
            func_08050D74(reinterpret_cast<void * const *>(core->ui_state.value));
            core->dialogue_state = 1;
        } else if (core->dialogue_state == 4) {
            u32 selection = core->ui_state.value->GetChoiceResult();
            core->dialogue_state = 5;
            if (selection == 1) core->dialogue_choice = 0;
            else if (selection == 2) core->dialogue_choice = 1;
        } else if (core->dialogue_state == 3) {
            core->dialogue_state = 5;
            func_08050E30(core->ui_state.value, gText_NewGameBirthdayInput_Confirmation,
                gText_NewGameBirthdayInput_Yes, gText_NewGameBirthdayInput_No, nullptr, nullptr, nullptr);
            core->dialogue_state = 4;
        }
        break;
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
        break;
    }
}

void MoveBirthdayInputCursor(NewGameBirthdayInputCore * core)
{
    // Direction buttons occupy the low byte of the repeated-key ABI word.
    u32 input = GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core));
    if (reinterpret_cast<u8 const *>(&input)[0] & 0x40) {
        if (core->cursor_row != 0) {
            core->music_player_2.Start(0xCB);
            if (core->cursor_row > 1)
                core->cursor_row--;
            else if (core->cursor_row == 1) {
#if defined(REGION_JP)
                if (core->cursor_column > 1)
                    core->cursor_row = 4;
                else
                    core->cursor_row = 5;
#else
                if (core->cursor_column > 3)
                    core->cursor_row = 4;
                else
                    core->cursor_row = 5;
#endif
            }
        }
    } else if (reinterpret_cast<u8 const *>(&input)[0] & 0x80) {
        if (core->cursor_row != 0) {
            core->music_player_2.Start(0xCB);
            core->cursor_row++;
            if (core->cursor_row == 6 || (core->cursor_row == 5 &&
#if defined(REGION_JP)
                    core->cursor_column > 1))
#else
                    core->cursor_column > 3))
#endif
                core->cursor_row = 1;
        }
    } else if (reinterpret_cast<u8 const *>(&input)[0] & 0x20) {
        core->music_player_2.Start(0xCB);
#if defined(REGION_JP)
        core->cursor_column--;
        if (core->cursor_row == 0) {
            if (core->cursor_column < 0)
                core->cursor_column = 3;
        } else if (core->cursor_column < 0) {
            core->cursor_row--;
            if (core->cursor_row <= 0) {
                core->cursor_row = 5;
                core->cursor_column = 1;
            } else
                core->cursor_column = 6;
        }
#else
        if (core->cursor_row == 0) {
            core->cursor_column -= 4;
            if (core->cursor_column < 0)
                core->cursor_column = 12;
        } else {
            core->cursor_column -= 2;
            if (core->cursor_column < 0) {
                core->cursor_row--;
                if (core->cursor_row <= 0) {
                    core->cursor_row = 5;
                    core->cursor_column = 3;
                } else
                    core->cursor_column = 13;
            }
        }
#endif
    } else if (reinterpret_cast<u8 const *>(&input)[0] & 0x10) {
        core->music_player_2.Start(0xCB);
#if defined(REGION_JP)
        core->cursor_column++;
        if (core->cursor_row == 0) {
            if (core->cursor_column > 3)
                core->cursor_column = 0;
        } else if (core->cursor_row == 5) {
            if (core->cursor_column > 1) {
                core->cursor_row = 1;
                core->cursor_column = 0;
            }
        } else if (core->cursor_column > 6) {
            core->cursor_row++;
            core->cursor_column = 0;
        }
#else
        if (core->cursor_row == 0) {
            core->cursor_column += 4;
            if (core->cursor_column > 12)
                core->cursor_column = 0;
        } else {
            core->cursor_column += 2;
            if (core->cursor_row == 5) {
                if (core->cursor_column > 3) {
                    core->cursor_row = 1;
                    core->cursor_column = 1;
                }
            } else if (core->cursor_column > 13) {
                core->cursor_row++;
                core->cursor_column = 1;
            }
        }
#endif
    }
}

asm_unified(
    ".text\n"
    ".ifdef REGION_JP\n"
    "\n"
    "    .global UpdateBirthdayInputCursor\n"
    "    .thumb_func\n"
    "UpdateBirthdayInputCursor:\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tadds r5, r0, #0\n"
    "\tadds r0, #0x38\n"
    "\tldrb r0, [r0]\n"
    "\tlsls r0, r0, #0x18\n"
    "\tasrs r0, r0, #0x18\n"
    "\tlsls r1, r0, #5\n"
    "\tlsls r0, r0, #1\n"
    "\tadds r0, #2\n"
    "\tadds r1, r1, r0\n"
    "\tldr r2, .Ljp_0806DE4C\n"
    "\tadds r0, r2, #0\n"
    "\tands r1, r0\n"
    "\tldrh r2, [r5, #0x3e]\n"
    "\tldr r0, .Ljp_0806DE50\n"
    "\tands r0, r2\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r5, #0x3e]\n"
    "\tadds r1, r5, #0\n"
    "\tadds r1, #0x39\n"
    "\tmovs r0, #0\n"
    "\tldrsb r0, [r1, r0]\n"
    "\tcmp r0, #0\n"
    "\tble .Ljp_0806DE54\n"
    "\tsubs r0, #1\n"
    "\tlsls r1, r0, #3\n"
    "\tadds r1, r1, r0\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r1, #0x40\n"
    "\tadds r0, r5, #0\n"
    "\tadds r0, #0x3c\n"
    "\tstrb r1, [r0]\n"
    "\tb .Ljp_0806DE5C\n"
    "\t.align 2, 0\n"
    ".Ljp_0806DE4C: .word 0x000001FF\n"
    ".Ljp_0806DE50: .word 0xFFFFFE00\n"
    ".Ljp_0806DE54:\n"
    "\tadds r1, r5, #0\n"
    "\tadds r1, #0x3c\n"
    "\tmovs r0, #0x28\n"
    "\tstrb r0, [r1]\n"
    ".Ljp_0806DE5C:\n"
    "\tadds r1, r5, #0\n"
    "\tadds r1, #0x39\n"
    "\tmovs r0, #0\n"
    "\tldrsb r0, [r1, r0]\n"
    "\tcmp r0, #0\n"
    "\tbne .Ljp_0806DE88\n"
    "\tadds r2, r5, #0\n"
    "\tadds r2, #0x38\n"
    "\tldrb r1, [r2]\n"
    "\tldr r3, .Ljp_0806DE84\n"
    "\tadds r0, r5, r3\n"
    "\tstrb r1, [r0]\n"
    "\tmovs r0, #0\n"
    "\tldrsb r0, [r2, r0]\n"
    "\tadds r0, #0xa\n"
    "\tadds r1, r5, #0\n"
    "\tadds r1, #0x4a\n"
    "\tstrh r0, [r1]\n"
    "\tb .Ljp_0806DED4\n"
    "\t.align 2, 0\n"
    ".Ljp_0806DE84: .word 0x00000279\n"
    ".Ljp_0806DE88:\n"
    "\tadds r2, r5, #0\n"
    "\tadds r2, #0x38\n"
    "\tldrb r1, [r1]\n"
    "\tlsls r1, r1, #0x18\n"
    "\tasrs r1, r1, #0x18\n"
    "\tsubs r1, #1\n"
    "\tlsls r0, r1, #3\n"
    "\tsubs r0, r0, r1\n"
    "\tldrb r2, [r2]\n"
    "\tadds r0, r0, r2\n"
    "\tadds r0, #1\n"
    "\tldr r2, .Ljp_0806DEDC\n"
    "\tadds r1, r5, r2\n"
    "\tstrb r0, [r1]\n"
    "\tmovs r4, #0\n"
    "\tldrsb r4, [r1, r4]\n"
    "\tadds r0, r4, #0\n"
    "\tmovs r1, #0xa\n"
    "\tbl __modsi3\n"
    "\tlsls r0, r0, #0x18\n"
    "\tasrs r6, r0, #0x18\n"
    "\tadds r0, r4, #0\n"
    "\tmovs r1, #0xa\n"
    "\tbl __divsi3\n"
    "\tlsls r0, r0, #0x18\n"
    "\tasrs r0, r0, #0x18\n"
    "\tadds r7, r0, #0\n"
    "\tmovs r1, #0x14\n"
    "\tcmp r0, #0\n"
    "\tbeq .Ljp_0806DECA\n"
    "\tadds r1, r7, #0\n"
    ".Ljp_0806DECA:\n"
    "\tadds r0, r5, #0\n"
    "\tadds r0, #0x52\n"
    "\tstrh r1, [r0]\n"
    "\tadds r0, #8\n"
    "\tstrh r6, [r0]\n"
    ".Ljp_0806DED4:\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
    ".Ljp_0806DEDC: .word 0x0000027A\n"
    "    .else\n"
    "\n"
    "\tthumb_func_start UpdateBirthdayInputCursor\n"
    "UpdateBirthdayInputCursor: @ 0x0806E02C\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tadds r5, r0, #0\n"
    "\tadds r0, #0x38\n"
    "\tmovs r1, #0\n"
    "\tldrsb r1, [r0, r1]\n"
    "\tlsls r1, r1, #4\n"
    "\tldr r2, .L0806E068 @ =0x000001FF\n"
    "\tadds r0, r2, #0\n"
    "\tands r1, r0\n"
    "\tldrh r2, [r5, #0x3e]\n"
    "\tldr r0, .L0806E06C @ =0xFFFFFE00\n"
    "\tands r0, r2\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r5, #0x3e]\n"
    "\tadds r1, r5, #0\n"
    "\tadds r1, #0x39\n"
    "\tmovs r0, #0\n"
    "\tldrsb r0, [r1, r0]\n"
    "\tcmp r0, #0\n"
    "\tble .L0806E070\n"
    "\tsubs r0, #1\n"
    "\tlsls r1, r0, #3\n"
    "\tadds r1, r1, r0\n"
    "\tlsls r1, r1, #1\n"
    "\tadds r1, #0x40\n"
    "\tadds r0, r5, #0\n"
    "\tadds r0, #0x3c\n"
    "\tstrb r1, [r0]\n"
    "\tb .L0806E078\n"
    "\t.align 2, 0\n"
    ".L0806E068: .word 0x000001FF\n"
    ".L0806E06C: .word 0xFFFFFE00\n"
    ".L0806E070:\n"
    "\tadds r1, r5, #0\n"
    "\tadds r1, #0x3c\n"
    "\tmovs r0, #0x28\n"
    "\tstrb r0, [r1]\n"
    ".L0806E078:\n"
    "\tadds r1, r5, #0\n"
    "\tadds r1, #0x39\n"
    "\tmovs r0, #0\n"
    "\tldrsb r0, [r1, r0]\n"
    "\tcmp r0, #0\n"
    "\tbne .L0806E106\n"
    "\tadds r0, r5, #0\n"
    "\tadds r0, #0x38\n"
    "\tldrb r1, [r0]\n"
    "\tldr r2, .L0806E0A4 @ =0x00000449\n"
    "\tadds r0, r5, r2\n"
    "\tstrb r1, [r0]\n"
    "\tldrb r0, [r0]\n"
    "\tlsls r0, r0, #0x18\n"
    "\tasrs r0, r0, #0x18\n"
    "\tcmp r0, #4\n"
    "\tbeq .L0806E0C4\n"
    "\tcmp r0, #4\n"
    "\tbgt .L0806E0A8\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0806E0AE\n"
    "\tb .L0806E0F0\n"
    "\t.align 2, 0\n"
    ".L0806E0A4:\n"
    "\t.ifdef REGION_DE\n"
    "\t.word 0x00000461\n"
    "\t.else\n"
    "\t.word 0x00000449\n"
    "\t.endif\n"
    ".L0806E0A8:\n"
    "\tcmp r0, #8\n"
    "\tbeq .L0806E0DA\n"
    "\tb .L0806E0F0\n"
    ".L0806E0AE:\n"
    "\tadds r2, r5, #0\n"
    "\tadds r2, #0x4a\n"
    "\tmovs r1, #0xf\n"
    "\tadds r0, r5, #0\n"
    "\tadds r0, #0x72\n"
    ".L0806E0B8:\n"
    "\tstrh r1, [r0]\n"
    "\tsubs r1, #1\n"
    "\tsubs r0, #8\n"
    "\tcmp r0, r2\n"
    "\tbge .L0806E0B8\n"
    "\tb .L0806E15A\n"
    ".L0806E0C4:\n"
    "\tadds r2, r5, #0\n"
    "\tadds r2, #0x4a\n"
    "\tmovs r1, #0x15\n"
    "\tadds r0, r5, #0\n"
    "\tadds r0, #0x72\n"
    ".L0806E0CE:\n"
    "\tstrh r1, [r0]\n"
    "\tsubs r1, #1\n"
    "\tsubs r0, #8\n"
    "\tcmp r0, r2\n"
    "\tbge .L0806E0CE\n"
    "\tb .L0806E15A\n"
    ".L0806E0DA:\n"
    "\tadds r2, r5, #0\n"
    "\tadds r2, #0x4a\n"
    "\tmovs r1, #0x1b\n"
    "\tadds r0, r5, #0\n"
    "\tadds r0, #0x72\n"
    ".L0806E0E4:\n"
    "\tstrh r1, [r0]\n"
    "\tsubs r1, #1\n"
    "\tsubs r0, #8\n"
    "\tcmp r0, r2\n"
    "\tbge .L0806E0E4\n"
    "\tb .L0806E15A\n"
    ".L0806E0F0:\n"
    "\tadds r2, r5, #0\n"
    "\tadds r2, #0x4a\n"
    "\tmovs r1, #0x21\n"
    "\tadds r0, r5, #0\n"
    "\tadds r0, #0x72\n"
    ".L0806E0FA:\n"
    "\tstrh r1, [r0]\n"
    "\tsubs r1, #1\n"
    "\tsubs r0, #8\n"
    "\tcmp r0, r2\n"
    "\tbge .L0806E0FA\n"
    "\tb .L0806E15A\n"
    ".L0806E106:\n"
    "\tadds r0, r5, #0\n"
    "\tadds r0, #0x38\n"
    "\tmovs r2, #0\n"
    "\tldrsb r2, [r0, r2]\n"
    "\tlsrs r0, r2, #0x1f\n"
    "\tadds r2, r2, r0\n"
    "\tasrs r2, r2, #1\n"
    "\tldrb r1, [r1]\n"
    "\tlsls r1, r1, #0x18\n"
    "\tasrs r1, r1, #0x18\n"
    "\tsubs r1, #1\n"
    "\tlsls r0, r1, #3\n"
    "\tsubs r0, r0, r1\n"
    "\tadds r2, r2, r0\n"
    "\tadds r2, #1\n"
    "\tldr r1, .L0806E160 @ =0x0000044A\n"
    "\tadds r0, r5, r1\n"
    "\tstrb r2, [r0]\n"
    "\tmovs r4, #0\n"
    "\tldrsb r4, [r0, r4]\n"
    "\tadds r0, r4, #0\n"
    "\tmovs r1, #0xa\n"
    "\tbl __modsi3\n"
    "\tlsls r0, r0, #0x18\n"
    "\tasrs r6, r0, #0x18\n"
    "\tadds r0, r4, #0\n"
    "\tmovs r1, #0xa\n"
    "\tbl __divsi3\n"
    "\tlsls r0, r0, #0x18\n"
    "\tasrs r0, r0, #0x18\n"
    "\tadds r7, r0, #0\n"
    "\t.ifdef REGION_DE\n"
    "\tmovs r1, #0x2d\n"
    "\t.else\n"
    "\tmovs r1, #0x1a\n"
    "\t.endif\n"
    "\tcmp r0, #0\n"
    "\tbeq .L0806E150\n"
    "\tadds r1, r7, #0\n"
    ".L0806E150:\n"
    "\tadds r0, r5, #0\n"
    "\tadds r0, #0x7a\n"
    "\tstrh r1, [r0]\n"
    "\tadds r0, #8\n"
    "\tstrh r6, [r0]\n"
    ".L0806E15A:\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
    ".L0806E160:\n"
    "\t.ifdef REGION_DE\n"
    "\t.word 0x00000462\n"
    "\t.else\n"
    "\t.word 0x0000044A\n"
    "\t.endif\n"
    "\n"
    "    .endif\n"
);


bool ConfirmBirthdayInputSelection(NewGameBirthdayInputCore * core)
{
    bool complete = false;
    bool pressed = false;
    if ((static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core))) & 1) ||
        (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core))) & 8))
        pressed = true;
    if (pressed) {
        core->music_player_2.Start(0x6A);
        if (core->cursor_row == 0) {
            core->saved_season_column = core->cursor_column;
            core->cursor_row = (core->day - 1) / 7 + 1;
#if defined(REGION_JP)
            core->cursor_column = (core->day - 1) % 7;
#else
            core->cursor_column = ((core->day - 1) % 7) * 2 + 1;
#endif
        } else complete = true;
    }
    return complete;
}

bool CancelBirthdayInputSelection(NewGameBirthdayInputCore * core)
{
    bool cancelled = false;
    if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core))) & 2) {
        core->music_player_2.Start(0x6C);
        if (core->cursor_row > 0) {
            core->cursor_column = core->saved_season_column;
            core->cursor_row = 0;
#if defined(REGION_JP)
            core->glyphs[1].glyph_index = 19;
            core->glyphs[2].glyph_index = 19;
#else
            core->glyphs[6].glyph_index = 34;
            core->glyphs[7].glyph_index = 34;
#endif
        } else cancelled = true;
    }
    return cancelled;
}

asm_unified(
    ".text\n"
    ".ifdef REGION_JP\n"
    "    .align 2, 0\n"
    "\n"
    "    .global InitializeBirthdayInputGraphics\n"
    "    .thumb_func\n"
    "InitializeBirthdayInputGraphics:\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sl\n"
    "\tmov r6, sb\n"
    "\tmov r5, r8\n"
    "\tpush {r5, r6, r7}\n"
    "\tsub sp, #0x98\n"
    "\tadds r7, r0, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tmovs r4, #0\n"
    "\tstrh r4, [r1]\n"
    "\tstrh r4, [r0, #0x18]\n"
    "\tadds r0, r7, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r4, [r1]\n"
    "\tstrh r4, [r0, #0x1a]\n"
    "\tadds r0, r7, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r4, [r1]\n"
    "\tstrh r4, [r0, #0x1c]\n"
    "\tadds r0, r7, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r4, [r1]\n"
    "\tstrh r4, [r0, #0x1e]\n"
    "\tldr r1, .Ljp_0806E174\n"
    "\tmovs r0, #0\n"
    "\tmovs r2, #0x20\n"
    "\tbl FillHardwareDma3\n"
    "\tmovs r4, #1\n"
    "\trsbs r4, r4, #0\n"
    "\tldr r0, .Ljp_0806E178\n"
    "\tmov r8, r0\n"
    "\tmovs r6, #0x80\n"
    "\tlsls r6, r6, #4\n"
    "\tadds r0, r4, #0\n"
    "\tmov r1, r8\n"
    "\tadds r2, r6, #0\n"
    "\tbl FillHardwareDma3\n"
    "\tldr r1, .Ljp_0806E17C\n"
    "\tmov sb, r1\n"
    "\tadds r0, r4, #0\n"
    "\tadds r2, r6, #0\n"
    "\tbl FillHardwareDma3\n"
    "\tadds r0, r7, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tmovs r3, #0xc2\n"
    "\tlsls r3, r3, #5\n"
    "\tadds r2, r3, #0\n"
    "\tstrh r2, [r1]\n"
    "\tmovs r5, #0\n"
    "\tstrh r2, [r0]\n"
    "\tadds r0, r7, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r2, sp, #0xc\n"
    "\tldr r3, .Ljp_0806E180\n"
    "\tadds r1, r3, #0\n"
    "\tstrh r1, [r2]\n"
    "\tstrh r1, [r0, #0xe]\n"
    "\tldr r0, .Ljp_0806E184\n"
    "\tldr r0, [r0]\n"
    "\tmovs r1, #0xc0\n"
    "\tlsls r1, r1, #0x13\n"
    "\tldr r2, .Ljp_0806E188\n"
    "\tldr r2, [r2]\n"
    "\tbl CopyHardwareDma3\n"
    "\tldr r0, .Ljp_0806E18C\n"
    "\tmov r1, r8\n"
    "\tadds r2, r6, #0\n"
    "\tbl FillHardwareDma3\n"
    "\tadds r0, r7, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x1c]\n"
    "\tadds r0, r7, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x1e]\n"
    "\tmovs r0, #3\n"
    "\tstr r0, [sp]\n"
    "\tstr r5, [sp, #4]\n"
    "\tstr r5, [sp, #8]\n"
    "\tmov r0, sb\n"
    "\tmovs r1, #0\n"
    "\tmovs r2, #0\n"
    "\tmovs r3, #0x20\n"
    "\tbl DrawUiTextWindowBorder\n"
    "\tadds r0, r7, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x18]\n"
    "\tadds r0, r7, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x1a]\n"
    "\tadds r0, r7, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x14]\n"
    "\tadds r0, r7, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x16]\n"
    "\tldr r0, .Ljp_0806E190\n"
    "\tldr r0, [r0]\n"
    "\tmovs r1, #0xa0\n"
    "\tlsls r1, r1, #0x13\n"
    "\tmovs r2, #0x20\n"
    "\tbl CopyHardwareDma3\n"
    "\tldr r0, .Ljp_0806E194\n"
    "\tmovs r1, #0xf8\n"
    "\tlsls r1, r1, #2\n"
    "\tadds r6, r1, #0\n"
    "\tstrh r6, [r0]\n"
    "\tadds r0, #2\n"
    "\tstrh r5, [r0]\n"
    "\tadds r0, #2\n"
    "\tldr r3, .Ljp_0806E198\n"
    "\tmov r8, r3\n"
    "\tstrh r3, [r0]\n"
    "\tadds r4, r7, #0\n"
    "\tadds r4, #0x20\n"
    "\tldr r1, [r4, #4]\n"
    "\tadds r0, r4, #0\n"
    "\tbl GetObjPaletteBank\n"
    "\tlsls r0, r0, #5\n"
    "\tldr r1, .Ljp_0806E19C\n"
    "\tadds r0, r0, r1\n"
    "\tstrh r6, [r0]\n"
    "\tldr r1, [r4, #4]\n"
    "\tadds r0, r4, #0\n"
    "\tbl GetObjPaletteBank\n"
    "\tlsls r0, r0, #5\n"
    "\tldr r3, .Ljp_0806E1A0\n"
    "\tadds r0, r0, r3\n"
    "\tstrh r5, [r0]\n"
    "\tldr r1, [r4, #4]\n"
    "\tadds r0, r4, #0\n"
    "\tbl GetObjPaletteBank\n"
    "\tlsls r0, r0, #5\n"
    "\tldr r1, .Ljp_0806E1A4\n"
    "\tadds r0, r0, r1\n"
    "\tmov r3, r8\n"
    "\tstrh r3, [r0]\n"
    "\tmovs r4, #0\n"
    "\tadd r5, sp, #0x94\n"
    "\tadd r0, sp, #0x14\n"
    "\tmov sb, r0\n"
    "\tmovs r1, #1\n"
    "\tmov sl, r1\n"
    "\tmovs r3, #2\n"
    "\tmov r8, r3\n"
    "\tadds r6, r5, #0\n"
    ".Ljp_0806E11C:\n"
    "\tldr r1, .Ljp_0806E1A8\n"
    "\tlsls r0, r4, #1\n"
    "\tadds r0, r0, r1\n"
    "\tldrh r1, [r0]\n"
    "\tmov r0, r8\n"
    "\tstrh r0, [r6]\n"
    "\tstrh r0, [r5, #2]\n"
    "\tldr r0, [r6]\n"
    "\tstr r1, [sp]\n"
    "\tmovs r1, #0\n"
    "\tstr r1, [sp, #4]\n"
    "\tmov r3, sl\n"
    "\tstr r3, [sp, #8]\n"
    "\tadd r1, sp, #0x14\n"
    "\tmovs r2, #0\n"
    "\tmovs r3, #0\n"
    "\tbl DrawCharacterGlyphTo2DGfxBufferExt\n"
    "\tadds r0, r7, #0\n"
    "\tadds r0, #0x18\n"
    "\tldr r1, [r0, #4]\n"
    "\tbl GetObjTileIndex\n"
    "\tadds r1, r0, #0\n"
    "\tlsls r0, r4, #2\n"
    "\tadds r1, r1, r0\n"
    "\tlsls r1, r1, #5\n"
    "\tldr r0, .Ljp_0806E1AC\n"
    "\tadds r1, r1, r0\n"
    "\tmov r0, sb\n"
    "\tmovs r2, #0x80\n"
    "\tbl CopyHardwareDma3\n"
    "\tadds r4, #1\n"
    "\tcmp r4, #0x14\n"
    "\tble .Ljp_0806E11C\n"
    "\tadd sp, #0x98\n"
    "\tpop {r3, r4, r5}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tmov sl, r5\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    ".Ljp_0806E174: .word 0x06007FE0\n"
    ".Ljp_0806E178: .word 0x0600E000\n"
    ".Ljp_0806E17C: .word 0x0600E800\n"
    ".Ljp_0806E180: .word 0x00001C03\n"
    ".Ljp_0806E184: .word gUiSharedTiles\n"
    ".Ljp_0806E188: .word gUiSharedTileByteCount\n"
    ".Ljp_0806E18C: .word 0x00030003\n"
    ".Ljp_0806E190: .word gUiSharedPalette\n"
    ".Ljp_0806E194: .word BG_PALETTE + 2 * PLTT_SIZE_4BPP\n"
    ".Ljp_0806E198: .word 0x00004218\n"
    ".Ljp_0806E19C: .word OBJ_PALETTE\n"
    ".Ljp_0806E1A0: .word OBJ_PALETTE + 2\n"
    ".Ljp_0806E1A4: .word OBJ_PALETTE + 2 * 2\n"
    ".Ljp_0806E1A8: .word gNewGameBirthdayInputGlyphs\n"
    ".Ljp_0806E1AC: .word OBJ_VRAM0\n"
    "\n"
    "    .else\n"
    "\n"
    "\tthumb_func_start InitializeBirthdayInputGraphics\n"
    "InitializeBirthdayInputGraphics: @ 0x0806E234\n"
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tmov r7, sl\n"
    "\tmov r6, sb\n"
    "\tmov r5, r8\n"
    "\tpush {r5, r6, r7}\n"
    "\tsub sp, #0x58\n"
    "\tadds r6, r0, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tmovs r4, #0\n"
    "\tstrh r4, [r1]\n"
    "\tstrh r4, [r0, #0x18]\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r4, [r1]\n"
    "\tstrh r4, [r0, #0x1a]\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r4, [r1]\n"
    "\tstrh r4, [r0, #0x1c]\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r4, [r1]\n"
    "\tstrh r4, [r0, #0x1e]\n"
    "\tldr r1, .L0806E400 @ =0x06007FE0\n"
    "\tmovs r0, #0\n"
    "\tmovs r2, #0x20\n"
    "\tbl FillHardwareDma3\n"
    "\tmovs r4, #1\n"
    "\trsbs r4, r4, #0\n"
    "\tldr r0, .L0806E404 @ =0x0600E000\n"
    "\tmov sb, r0\n"
    "\tmovs r1, #0x80\n"
    "\tlsls r1, r1, #4\n"
    "\tmov r8, r1\n"
    "\tadds r0, r4, #0\n"
    "\tmov r1, sb\n"
    "\tmov r2, r8\n"
    "\tbl FillHardwareDma3\n"
    "\tldr r2, .L0806E408 @ =0x0600E800\n"
    "\tmov sl, r2\n"
    "\tadds r0, r4, #0\n"
    "\tmov r1, sl\n"
    "\tmov r2, r8\n"
    "\tbl FillHardwareDma3\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tmovs r3, #0xc2\n"
    "\tlsls r3, r3, #5\n"
    "\tadds r2, r3, #0\n"
    "\tstrh r2, [r1]\n"
    "\tmovs r5, #0\n"
    "\tstrh r2, [r0]\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r2, sp, #0xc\n"
    "\tldr r3, .L0806E40C @ =0x00001C03\n"
    "\tadds r1, r3, #0\n"
    "\tstrh r1, [r2]\n"
    "\tstrh r1, [r0, #0xe]\n"
    "\tldr r0, .L0806E410 @ =gUiSharedTiles\n"
    "\tldr r0, [r0]\n"
    "\tmovs r1, #0xc0\n"
    "\tlsls r1, r1, #0x13\n"
    "\tldr r2, .L0806E414 @ =gUiSharedTileByteCount\n"
    "\tldr r2, [r2]\n"
    "\tbl CopyHardwareDma3\n"
    "\tldr r0, .L0806E418 @ =0x00030003\n"
    "\tmov r1, sb\n"
    "\tmov r2, r8\n"
    "\tbl FillHardwareDma3\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x1c]\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x1e]\n"
    "\tmovs r0, #3\n"
    "\tstr r0, [sp]\n"
    "\tstr r5, [sp, #4]\n"
    "\tstr r5, [sp, #8]\n"
    "\tmov r0, sl\n"
    "\tmovs r1, #0\n"
    "\tmovs r2, #0\n"
    "\tmovs r3, #0x20\n"
    "\tbl DrawUiTextWindowBorder\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x18]\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x1a]\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x14]\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetHardwareDisplayState\n"
    "\tadd r1, sp, #0xc\n"
    "\tstrh r5, [r1]\n"
    "\tstrh r5, [r0, #0x16]\n"
    "\tldr r0, .L0806E41C @ =gUiSharedPalette\n"
    "\tldr r0, [r0]\n"
    "\tmovs r1, #0xa0\n"
    "\tlsls r1, r1, #0x13\n"
    "\tmovs r2, #0x20\n"
    "\tbl CopyHardwareDma3\n"
    "\tldr r0, .L0806E420\n"
    "\tmovs r1, #0xf8\n"
    "\tlsls r1, r1, #2\n"
    "\tmov r8, r1\n"
    "\tstrh r1, [r0]\n"
    "\tadds r0, #2\n"
    "\tstrh r5, [r0]\n"
    "\tadds r0, #2\n"
    "\tldr r2, .L0806E424 @ =0x00004218\n"
    "\tmov sb, r2\n"
    "\tstrh r2, [r0]\n"
    "\tadds r4, r6, #0\n"
    "\tadds r4, #0x20\n"
    "\tldr r1, [r4, #4]\n"
    "\tadds r0, r4, #0\n"
    "\tbl GetObjPaletteBank\n"
    "\tlsls r0, r0, #5\n"
    "\tldr r3, .L0806E428 @ =OBJ_PALETTE\n"
    "\tadds r0, r0, r3\n"
    "\tmov r1, r8\n"
    "\tstrh r1, [r0]\n"
    "\tldr r1, [r4, #4]\n"
    "\tadds r0, r4, #0\n"
    "\tbl GetObjPaletteBank\n"
    "\tlsls r0, r0, #5\n"
    "\tldr r2, .L0806E42C\n"
    "\tadds r0, r0, r2\n"
    "\tstrh r5, [r0]\n"
    "\tldr r1, [r4, #4]\n"
    "\tadds r0, r4, #0\n"
    "\tbl GetObjPaletteBank\n"
    "\tlsls r0, r0, #5\n"
    "\tldr r3, .L0806E430\n"
    "\tadds r0, r0, r3\n"
    "\tmov r1, sb\n"
    "\tstrh r1, [r0]\n"
    "\tadd r2, sp, #0x54\n"
    "\tmov sb, r2\n"
    "\tadd r3, sp, #0x14\n"
    "\tmov r8, r3\n"
    "\tmovs r7, #1\n"
    "\tmovs r0, #2\n"
    "\tmov sl, r0\n"
    "\tadds r6, #0x18\n"
    ".L0806E3A8:\n"
    "\tldr r0, .L0806E434 @ =gNewGameBirthdayInputGlyphs\n"
    "\tlsls r4, r5, #1\n"
    "\tadds r0, r4, r0\n"
    "\tldrh r1, [r0]\n"
    "\tadd r0, sp, #0x54\n"
    "\tstrh r7, [r0]\n"
    "\tmov r3, sl\n"
    "\tmov r2, sb\n"
    "\tstrh r3, [r2, #2]\n"
    "\tldr r0, [sp, #0x54]\n"
    "\tstr r1, [sp]\n"
    "\tmovs r1, #0\n"
    "\tstr r1, [sp, #4]\n"
    "\tstr r7, [sp, #8]\n"
    "\tadd r1, sp, #0x14\n"
    "\tmovs r2, #0\n"
    "\tmovs r3, #0\n"
    "\tbl DrawCharacterGlyphTo2DGfxBufferExt\n"
    "\tldr r1, [r6, #4]\n"
    "\tadds r0, r6, #0\n"
    "\tbl GetObjTileIndex\n"
    "\tadds r1, r0, #0\n"
    "\tadds r1, r1, r4\n"
    "\tlsls r1, r1, #5\n"
    "\tldr r2, .L0806E438 @ =OBJ_VRAM0\n"
    "\tadds r1, r1, r2\n"
    "\tmov r0, r8\n"
    "\tmovs r2, #0x40\n"
    "\tbl CopyHardwareDma3\n"
    "\tadds r5, #1\n"
    "\t.ifdef REGION_DE\n"
    "\tcmp r5, #0x2d\n"
    "\t.else\n"
    "\tcmp r5, #0x2a\n"
    "\t.endif\n"
    "\tble .L0806E3A8\n"
    "\tadd sp, #0x58\n"
    "\tpop {r3, r4, r5}\n"
    "\tmov r8, r3\n"
    "\tmov sb, r4\n"
    "\tmov sl, r5\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
    ".L0806E400: .word 0x06007FE0\n"
    ".L0806E404: .word 0x0600E000\n"
    ".L0806E408: .word 0x0600E800\n"
    ".L0806E40C: .word 0x00001C03\n"
    ".L0806E410: .word gUiSharedTiles\n"
    ".L0806E414: .word gUiSharedTileByteCount\n"
    ".L0806E418: .word 0x00030003\n"
    ".L0806E41C: .word gUiSharedPalette\n"
    ".L0806E420: .word BG_PALETTE + 2 * PLTT_SIZE_4BPP\n"
    ".L0806E424: .word 0x00004218\n"
    ".L0806E428: .word OBJ_PALETTE\n"
    ".L0806E42C: .word OBJ_PALETTE + 2\n"
    ".L0806E430: .word OBJ_PALETTE + 2 * 2\n"
    ".L0806E434: .word gNewGameBirthdayInputGlyphs\n"
    ".L0806E438: .word OBJ_VRAM0\n"
    "\n"
    "    .endif\n"
);


void InitializeBirthdayInputCursor(NewGameBirthdayInputCore * core)
{
    CopyHardwareDma3(gUiSharedPalette,
        reinterpret_cast<void *>(OBJ_PLTT + SpritePaletteBank(core->cursor_palette) * PLTT_SIZE_4BPP), PLTT_SIZE_4BPP);
    reinterpret_cast<u16 *>(OBJ_PLTT + SpritePaletteBank(core->cursor_palette) * PLTT_SIZE_4BPP)[7] = RGB(31, 19, 0);
    FillHardwareDma3(0, &core->cursor_attributes, sizeof(core->cursor_attributes));
#if defined(REGION_JP)
    core->cursor_attributes.size = 2;
    core->cursor_attributes.shape = 1;
#else
    core->cursor_attributes.size = 1;
    core->cursor_attributes.shape = 0;
#endif
    core->cursor_attributes.object_mode = 1;
    // Use the native OAM halfword view for the tile and palette fields.
    reinterpret_cast<HardwareSpriteOamRecord &>(core->cursor_attributes).tile_index = SpriteTileIndex(core->cursor_tiles);
    reinterpret_cast<HardwareSpriteOamRecord &>(core->cursor_attributes).palette_bank = SpritePaletteBank(core->cursor_palette);
    reinterpret_cast<HardwareSpriteOamRecord &>(core->cursor_attributes).priority = 3;
    for (int tile = 0; tile < 8; ++tile) {
        for (int row = 0; row < 8; ++row) {
            *reinterpret_cast<u32 *>(OBJ_VRAM0
                + (SpriteTileIndex(core->cursor_tiles) + tile) * TILE_SIZE_4BPP + row * 4) = 0x77777777;
        }
    }
#if defined(REGION_JP)
    i32 cell_width = core->cursor_column * 32;
    i32 gutter = core->cursor_column * 2 + 2;
    core->cursor_attributes.x = cell_width + gutter;
#else
    core->cursor_attributes.x = core->cursor_column * 16;
#endif
    core->cursor_attributes.y = 40;
}

void BuildBirthdayInputGlyphs(NewGameBirthdayInputCore * core)
{
    core->glyph_count = 0;
#if defined(REGION_JP)
    int title[3];
    title[0] = core->season_column + 10;
#else
    int title[8];
    switch (core->season_column) {
    case 0: {
        for (int i = 0; i < 6; ++i)
            title[i] = i + 10;
    } break;
    case 4: {
        for (int i = 0; i < 6; ++i)
            title[i] = i + 16;
    } break;
    case 8: {
        for (int i = 0; i < 6; ++i)
            title[i] = i + 22;
    } break;
    default: {
        for (int i = 0; i < 6; ++i)
            title[i] = i + 28;
    } break;
    }
#endif
#if defined(REGION_JP)
    title[1] = static_cast<i8>(core->day / 10) == 0 ? 20 : static_cast<i8>(core->day / 10);
    title[2] = static_cast<i8>(core->day % 10);
    AppendBirthdayInputGlyph(core, 144, 8, title[0], 1);
    AppendBirthdayInputGlyph(core, 192, 8, title[1], 1);
    AppendBirthdayInputGlyph(core, 208, 8, title[2], 1);
    for (int i = 0; i < 3; ++i)
        AppendBirthdayInputGlyph(core, 80 + i * 16, 8, i + 14, 1);
    AppendBirthdayInputGlyph(core, 160, 8, 17, 1);
    AppendBirthdayInputGlyph(core, 176, 8, 18, 1);
    AppendBirthdayInputGlyph(core, 224, 8, 16, 1);
    for (int i = 0; i < 4; ++i)
        AppendBirthdayInputGlyph(core, 18 + i * 34, 40, i + 10, 3);
#else
#if defined(REGION_DE)
    title[6] = static_cast<i8>(core->day / 10) == 0 ? 45 : static_cast<i8>(core->day / 10);
#else
    title[6] = static_cast<i8>(core->day / 10) == 0 ? 26 : static_cast<i8>(core->day / 10);
#endif
    title[7] = static_cast<i8>(core->day % 10);
    for (int i = 0; i < 6; ++i)
        AppendBirthdayInputGlyph(core, 120 + i * 8, 8, title[i], 1);
    AppendBirthdayInputGlyph(core, 192, 8, title[6], 1);
    AppendBirthdayInputGlyph(core, 200, 8, title[7], 1);
#endif
    u8 day = 1;
    for (int row = 0; row < 5; ++row) {
        for (int column = 0; column < 7; ++column) {
#if defined(REGION_JP)
            if (day > 9) AppendBirthdayInputGlyph(core, column * 34 + 2, row * 18 + 64, static_cast<u8>(day / 10u), 3);
            AppendBirthdayInputGlyph(core, column * 34 + 18, row * 18 + 64, static_cast<u8>(day % 10u), 3);
#else
            if (day > 9) AppendBirthdayInputGlyph(core, column * 32 + 16, row * 18 + 64, static_cast<u8>(day / 10u), 3);
            AppendBirthdayInputGlyph(core, column * 32 + 24, row * 18 + 64, static_cast<u8>(day % 10u), 3);
#endif
            ++day;
            if (day > 30) break;
        }
    }
#if !defined(REGION_JP)
    for (int i = 0; i < 6; ++i)
        AppendBirthdayInputGlyph(core, i * 8, 40, i + 10, 3);
    for (int i = 0; i < 6; ++i)
        AppendBirthdayInputGlyph(core, i * 8 + 64, 40, i + 16, 3);
    for (int i = 0; i < 6; ++i)
        AppendBirthdayInputGlyph(core, i * 8 + 128, 40, i + 22, 3);
    for (int i = 0; i < 6; ++i)
        AppendBirthdayInputGlyph(core, i * 8 + 192, 40, i + 28, 3);
#if defined(REGION_DE)
    for (int i = 0; i < 10; ++i)
        AppendBirthdayInputGlyph(core, i * 8 + 8, 8, i + 35, 3);
#else
    for (int i = 0; i < 8; ++i)
        AppendBirthdayInputGlyph(core, i * 8 + 8, 8, i + 35, 3);
#endif
#endif
}

void AppendBirthdayInputGlyph(NewGameBirthdayInputCore * core, i32 x, i32 y,
    i32 glyph, i32 priority)
{
    core->glyphs[core->glyph_count].x = x;
    core->glyphs[core->glyph_count].y = y;
    core->glyphs[core->glyph_count].glyph_index = glyph;
    core->glyphs[core->glyph_count].priority = priority;
    core->glyph_count++;
}

void RenderBirthdayInputSprites(NewGameBirthdayInputCore * core)
{
    HardwareSpriteOamRecord attributes;
    attributes.affine_mode = 0;
    attributes.object_mode = 0;
    attributes.color_mode = 0;
#if defined(REGION_JP)
    attributes.shape = 0;
#else
    attributes.shape = 2;
#endif
    attributes.affine_index_low = 0;
    attributes.horizontal_flip = 0;
    attributes.vertical_flip = 0;
#if defined(REGION_JP)
    attributes.size = 1;
#else
    attributes.size = 0;
#endif
    attributes.palette_bank = static_cast<u16>(SpritePaletteBank(core->glyph_palette));
    attributes.affine_coefficient = 0;
    attributes.mosaic = 1;
    for (i32 index = core->glyph_count - 1; index >= 0; --index) {
        attributes.priority = core->glyphs[index].priority;
        attributes.x = core->glyphs[index].x;
        attributes.y = core->glyphs[index].y;
#if defined(REGION_JP)
        attributes.tile_index = SpriteTileIndex(core->glyph_tiles)
            + core->glyphs[index].glyph_index * 4;
#else
        attributes.tile_index = SpriteTileIndex(core->glyph_tiles)
            + core->glyphs[index].glyph_index * 2;
#endif
        SubmitBirthdaySprite(core, attributes);
    }
    // Copy only the six attribute bytes; the buffer owns affine coefficients.
    if (core->cursor_visible) {
        {
            HardwareSpriteBufferState * buffer =
                GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
            u32 const & position_and_mode =
                reinterpret_cast<u32 const &>(core->cursor_attributes);
            u32 count = buffer->sprite_count;
            if (count < ARRAY_COUNT(buffer->sprites)) {
                HardwareSpriteOamRecord & destination = buffer->sprites[count];
                reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
                reinterpret_cast<u16 *>(&destination)[2] = core->cursor_attributes.tile_attributes;
                buffer->sprite_count = count + 1;
            }
        }
#if !defined(REGION_JP)
        if (core->cursor_row == 0) {
            core->cursor_attributes.x = core->cursor_column * 16 + 16;
            {
                HardwareSpriteBufferState * buffer =
                    GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
                u32 const & position_and_mode =
                    reinterpret_cast<u32 const &>(core->cursor_attributes);
                u32 count = buffer->sprite_count;
                if (count < ARRAY_COUNT(buffer->sprites)) {
                    HardwareSpriteOamRecord & destination = buffer->sprites[count];
                    reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
                    reinterpret_cast<u16 *>(&destination)[2] = core->cursor_attributes.tile_attributes;
                    buffer->sprite_count = count + 1;
                }
            }
            core->cursor_attributes.x = core->cursor_column * 16 + 32;
            {
                HardwareSpriteBufferState * buffer =
                    GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
                u32 const & position_and_mode =
                    reinterpret_cast<u32 const &>(core->cursor_attributes);
                u32 count = buffer->sprite_count;
                if (count < ARRAY_COUNT(buffer->sprites)) {
                    HardwareSpriteOamRecord & destination = buffer->sprites[count];
                    reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
                    reinterpret_cast<u16 *>(&destination)[2] = core->cursor_attributes.tile_attributes;
                    buffer->sprite_count = count + 1;
                }
            }
        }
#endif
    }
}

NewGameBirthdayInputScene::NewGameBirthdayInputScene(GameDate birthday)
{
    core = new NewGameBirthdayInputCore(birthday);
}

NewGameBirthdayInputScene::~NewGameBirthdayInputScene()
{
    delete core;
}

SceneTransitionOwner NewGameBirthdayInputScene::Run()
{
    return RunBirthdayInputCore(core);
}

GameDate NewGameBirthdayInputScene::GetDate() const
{
    return core->birthday;
}

#include FOMT_TEXT_INCLUDE(new_game_birthday_input.cc)
