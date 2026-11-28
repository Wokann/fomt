#ifndef FARM_STATUS_SCREEN_HH
#define FARM_STATUS_SCREEN_HH

#include "prelude.h"

#include "scene.hh"

struct GameStateSaveImage;

#include "scroll_menu.hh"
#include "hardware_context.hh"
#include "hardware_sprite_buffer.hh"
#include "sprite_oam.h"
#include "new_game_ui.hh"


// Native insertion constructs only count entries. Capacity is storage, not
// a set of default-constructed records; destruction visits that active range.
template <typename T, u32 Capacity>
struct FarmStatusEntries {
    FarmStatusEntries() : count(0) {}
    T * Begin() { return reinterpret_cast<T *>(storage); }
    T * End()
    {
        return reinterpret_cast<T *>(reinterpret_cast<u8 *>(this)
            + (sizeof(count) + count * sizeof(T)));
    }
    T & operator[](u32 index)
    {
        return *reinterpret_cast<T *>(reinterpret_cast<u8 *>(this)
            + (sizeof(count) + index * sizeof(T)));
    }
    ~FarmStatusEntries()
    {
        T * last = End();
        T * first = Begin();
        for (; first != last; ++first)
            first->~T();
    }
    u32 count;
    u32 storage[Capacity * sizeof(T) / sizeof(u32)];
};

struct FarmStatusPageEntry {
    u32 page;
    i16 scroll_position;
};

// The overlay uses the signed Y and X fields. The final two words are copied
// during insertion but their meaning is not yet established.
struct FarmStatusMarkerRow {
    i16 y;
    i32 x;
    u32 unk_08;
    u32 unk_0C;
};

#pragma interface "farm_status_screen.hh"

struct FarmStatusScreenCore;

// The scene owns the separately allocated menu core.
struct FarmStatusScreenScene : AScene
{
    FarmStatusScreenScene(SceneTransitionOwner next, GameStateSaveImage * image, u8 argument);
    virtual ~FarmStatusScreenScene();
    virtual SceneTransitionOwner Run();
    SceneCoreOwner<FarmStatusScreenCore> core;
    SceneTransitionOwner continuation;
};

struct FarmStatusScreenCore : ScrollMenu {
    FarmStatusScreenCore(GameStateSaveImage * image, u8 argument);
    virtual void ChangePage(i32 direction);
    void SelectPage(u32 page);
    GameStateSaveImage * save;
    FarmStatusEntries<FarmStatusPageEntry, 7> pages;
    u32 selected_page;
};

// The native constructors still draw into these unclassified RAM arenas.
// Their extents come from allocation bounds, not invented ROM padding.
struct FarmStatusOverviewPage : ScrollMenuPage {
    FarmStatusOverviewPage(ScrollMenu * menu, GameStateSaveImage * image);
    virtual inline u32 Draw()
    {
        ScrollMenuPage::Draw();
        return 1;
    }
    u8 unk_5B8[0x1B6C - 0x5B8];
};

struct FarmStatusAnimalPage : ScrollMenuPage {
    FarmStatusAnimalPage(ScrollMenu * menu, GameStateSaveImage * image,
        u32 rows, char const * title);
    virtual u32 Draw();
    u32 const * DrawAnimalName(u32 index, char const * text);
#if defined(REGION_JP)
    u8 unk_5B8[0xD5C - 0x5B8];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    u8 unk_5B8[0x12DC - 0x5B8];
#endif
    NewGameTextTileBuffer<12> name_tiles[16];
};

struct FarmStatusChickenPage : FarmStatusAnimalPage {
    FarmStatusChickenPage(ScrollMenu * menu, GameStateSaveImage * image);
};

struct FarmStatusCowPage : FarmStatusAnimalPage {
    FarmStatusCowPage(ScrollMenu * menu, GameStateSaveImage * image);
};

struct FarmStatusSheepPage : FarmStatusAnimalPage {
    FarmStatusSheepPage(ScrollMenu * menu, GameStateSaveImage * image);
};

struct FarmStatusHarvestSpritesPage : ScrollMenuPage {
    FarmStatusHarvestSpritesPage(ScrollMenu * menu, GameStateSaveImage * image);
    virtual inline NAKED u32 Draw()
    {
        asm_unified(
            "    push {r4, r5, r6, r7, lr}\n"
            "    mov r7, sl\n"
            "    mov r6, r9\n"
            "    mov r5, r8\n"
            "    push {r5, r6, r7}\n"
            "    sub sp, #24\n"
            "    adds r7, r0, #0\n"
            "    bl Draw__14ScrollMenuPage\n"
            "    movs r0, #0\n"
            "    mov r8, r0\n"
            "    ldr r1, .LFarmStatusHarvestSpritesPage_draw_5\n"
            "    adds r0, r7, r1\n"
            "    movs r2, #0\n"
            "    ldrsh r0, [r0, r2]\n"
            "    adds r0, #48\n"
            "    movs r3, #178\n"
            "    lsls r3, r3, #3\n"
            "    adds r1, r7, r3\n"
            "    movs r2, #0\n"
            "    ldrsh r1, [r1, r2]\n"
            "    cmp r0, r1\n"
            "    bge .LFarmStatusHarvestSpritesPage_draw_1\n"
            "    adds r2, r1, #0\n"
            "    ldr r3, .LFarmStatusHarvestSpritesPage_draw_5\n"
            "    adds r1, r7, r3\n"
            ".LFarmStatusHarvestSpritesPage_draw_0:\n"
            "    adds r1, #16\n"
            "    movs r0, #1\n"
            "    add r8, r0\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r1, r3]\n"
            "    adds r0, #48\n"
            "    cmp r0, r2\n"
            "    blt .LFarmStatusHarvestSpritesPage_draw_0\n"
            ".LFarmStatusHarvestSpritesPage_draw_1:\n"
            "    ldr r1, .LFarmStatusHarvestSpritesPage_draw_6\n"
            "    adds r0, r7, r1\n"
            "    ldr r0, [r0, #0]\n"
            "    cmp r8, r0\n"
            "    bcs .LFarmStatusHarvestSpritesPage_draw_4\n"
            "    adds r2, r1, #0\n"
            "    adds r2, r2, r7\n"
            "    mov sl, r2\n"
            "    movs r3, #178\n"
            "    lsls r3, r3, #3\n"
            "    adds r3, r3, r7\n"
            "    mov r9, r3\n"
            "    mov r1, r8\n"
            "    lsls r0, r1, #4\n"
            "    ldr r2, .LFarmStatusHarvestSpritesPage_draw_5\n"
            "    adds r0, r0, r2\n"
            "    adds r5, r0, r7\n"
            ".LFarmStatusHarvestSpritesPage_draw_2:\n"
            "    movs r3, #0\n"
            "    ldrsh r1, [r5, r3]\n"
            "    mov r2, r9\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r2, r3]\n"
            "    adds r0, #160\n"
            "    cmp r1, r0\n"
            "    bgt .LFarmStatusHarvestSpritesPage_draw_3\n"
            "    ldr r0, [r7, #0]\n"
            "    bl GetHardwareSpriteBuffer\n"
            "    adds r4, r0, #0\n"
            "    movs r0, #0\n"
            "    ldrsh r2, [r5, r0]\n"
            "    mov r1, r9\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r1, r3]\n"
            "    subs r2, r2, r0\n"
            "    ldr r1, [r5, #4]\n"
            "    movs r0, #1\n"
            "    str r0, [sp, #0]\n"
            "    str r0, [sp, #4]\n"
            "    movs r0, #0\n"
            "    str r0, [sp, #8]\n"
            "    str r0, [sp, #12]\n"
            "    add r6, sp, #16\n"
            "    adds r0, r6, #0\n"
            "    movs r3, #5\n"
            "    bl InitializeMosaicSpriteOam\n"
            "    ldrb r2, [r4, #0]\n"
            "    cmp r2, #127\n"
            "    bhi .LFarmStatusHarvestSpritesPage_draw_3\n"
            "    lsls r1, r2, #3\n"
            "    adds r1, #4\n"
            "    adds r1, r4, r1\n"
            "    ldr r0, [sp, #16]\n"
            "    str r0, [r1, #0]\n"
            "    ldrh r0, [r6, #4]\n"
            "    strh r0, [r1, #4]\n"
            "    adds r0, r2, #1\n"
            "    strb r0, [r4, #0]\n"
            ".LFarmStatusHarvestSpritesPage_draw_3:\n"
            "    adds r5, #16\n"
            "    movs r0, #1\n"
            "    add r8, r0\n"
            "    mov r1, sl\n"
            "    ldr r0, [r1, #0]\n"
            "    cmp r8, r0\n"
            "    bcc .LFarmStatusHarvestSpritesPage_draw_2\n"
            ".LFarmStatusHarvestSpritesPage_draw_4:\n"
            "    movs r0, #1\n"
            "    add sp, #24\n"
            "    pop {r3, r4, r5}\n"
            "    mov r8, r3\n"
            "    mov r9, r4\n"
            "    mov sl, r5\n"
            "    pop {r4, r5, r6, r7}\n"
            "    pop {r1}\n"
            "    bx r1\n"
            "    .align 2, 0\n"
            ".LFarmStatusHarvestSpritesPage_draw_5: .word 0x00002168\n"
            ".LFarmStatusHarvestSpritesPage_draw_6: .word 0x00002164\n"
        );
    }
    u8 unk_5B8[0x2164 - 0x5B8];
    FarmStatusEntries<FarmStatusMarkerRow, 21> markers;
};

struct FarmStatusEarningsPage : ScrollMenuPage {
    FarmStatusEarningsPage(ScrollMenu * menu, GameStateSaveImage * image);
#if defined(REGION_JP)
    virtual inline NAKED u32 Draw()
    {
        asm_unified(
            "    push {r4, r5, r6, r7, lr}\n"
            "    mov r7, sl\n"
            "    mov r6, r9\n"
            "    mov r5, r8\n"
            "    push {r5, r6, r7}\n"
            "    sub sp, #36\n"
            "    adds r7, r0, #0\n"
            "    bl Draw__14ScrollMenuPage\n"
            "    movs r0, #0\n"
            "    mov r8, r0\n"
            "    ldr r1, .LFarmStatusEarningsPage_draw_10\n"
            "    adds r0, r7, r1\n"
            "    movs r2, #0\n"
            "    ldrsh r0, [r0, r2]\n"
            "    adds r0, #48\n"
            "    movs r3, #178\n"
            "    lsls r3, r3, #3\n"
            "    adds r1, r7, r3\n"
            "    movs r2, #0\n"
            "    ldrsh r1, [r1, r2]\n"
            "    cmp r0, r1\n"
            "    bge .LFarmStatusEarningsPage_draw_1\n"
            "    adds r2, r1, #0\n"
            "    ldr r3, .LFarmStatusEarningsPage_draw_10\n"
            "    adds r1, r7, r3\n"
            ".LFarmStatusEarningsPage_draw_0:\n"
            "    adds r1, #16\n"
            "    movs r0, #1\n"
            "    add r8, r0\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r1, r3]\n"
            "    adds r0, #48\n"
            "    cmp r0, r2\n"
            "    blt .LFarmStatusEarningsPage_draw_0\n"
            ".LFarmStatusEarningsPage_draw_1:\n"
            "    ldr r1, .LFarmStatusEarningsPage_draw_11\n"
            "    adds r0, r7, r1\n"
            "    ldr r0, [r0, #0]\n"
            "    movs r2, #142\n"
            "    lsls r2, r2, #5\n"
            "    adds r2, r7, r2\n"
            "    str r2, [sp, #32]\n"
            "    cmp r8, r0\n"
            "    bcs .LFarmStatusEarningsPage_draw_4\n"
            "    adds r3, r1, #0\n"
            "    adds r3, r3, r7\n"
            "    mov sl, r3\n"
            "    movs r0, #178\n"
            "    lsls r0, r0, #3\n"
            "    adds r0, r0, r7\n"
            "    mov r9, r0\n"
            "    mov r1, r8\n"
            "    lsls r0, r1, #4\n"
            "    ldr r2, .LFarmStatusEarningsPage_draw_10\n"
            "    adds r0, r0, r2\n"
            "    adds r5, r0, r7\n"
            ".LFarmStatusEarningsPage_draw_2:\n"
            "    movs r3, #0\n"
            "    ldrsh r1, [r5, r3]\n"
            "    mov r2, r9\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r2, r3]\n"
            "    adds r0, #160\n"
            "    cmp r1, r0\n"
            "    bgt .LFarmStatusEarningsPage_draw_3\n"
            "    ldr r0, [r7, #0]\n"
            "    bl GetHardwareSpriteBuffer\n"
            "    adds r4, r0, #0\n"
            "    movs r0, #0\n"
            "    ldrsh r2, [r5, r0]\n"
            "    mov r1, r9\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r1, r3]\n"
            "    subs r2, r2, r0\n"
            "    ldr r1, [r5, #4]\n"
            "    movs r0, #2\n"
            "    str r0, [sp, #0]\n"
            "    movs r0, #1\n"
            "    str r0, [sp, #4]\n"
            "    str r0, [sp, #8]\n"
            "    movs r0, #0\n"
            "    str r0, [sp, #12]\n"
            "    add r6, sp, #16\n"
            "    adds r0, r6, #0\n"
            "    movs r3, #16\n"
            "    bl InitializeMosaicSpriteOam\n"
            "    ldrb r2, [r4, #0]\n"
            "    cmp r2, #127\n"
            "    bhi .LFarmStatusEarningsPage_draw_3\n"
            "    lsls r1, r2, #3\n"
            "    adds r1, #4\n"
            "    adds r1, r4, r1\n"
            "    ldr r0, [sp, #16]\n"
            "    str r0, [r1, #0]\n"
            "    ldrh r0, [r6, #4]\n"
            "    strh r0, [r1, #4]\n"
            "    adds r0, r2, #1\n"
            "    strb r0, [r4, #0]\n"
            ".LFarmStatusEarningsPage_draw_3:\n"
            "    adds r5, #16\n"
            "    movs r0, #1\n"
            "    add r8, r0\n"
            "    mov r1, sl\n"
            "    ldr r0, [r1, #0]\n"
            "    cmp r8, r0\n"
            "    bcc .LFarmStatusEarningsPage_draw_2\n"
            ".LFarmStatusEarningsPage_draw_4:\n"
            "    movs r2, #0\n"
            "    mov r8, r2\n"
            "    ldr r3, [sp, #32]\n"
            "    movs r1, #0\n"
            "    ldrsh r0, [r3, r1]\n"
            "    adds r0, #48\n"
            "    movs r2, #178\n"
            "    lsls r2, r2, #3\n"
            "    adds r1, r7, r2\n"
            "    movs r3, #0\n"
            "    ldrsh r1, [r1, r3]\n"
            "    cmp r0, r1\n"
            "    bge .LFarmStatusEarningsPage_draw_6\n"
            "    adds r2, r1, #0\n"
            "    movs r0, #142\n"
            "    lsls r0, r0, #5\n"
            "    adds r1, r7, r0\n"
            ".LFarmStatusEarningsPage_draw_5:\n"
            "    adds r1, #16\n"
            "    movs r3, #1\n"
            "    add r8, r3\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r1, r3]\n"
            "    adds r0, #48\n"
            "    cmp r0, r2\n"
            "    blt .LFarmStatusEarningsPage_draw_5\n"
            ".LFarmStatusEarningsPage_draw_6:\n"
            "    ldr r1, .LFarmStatusEarningsPage_draw_12\n"
            "    adds r0, r7, r1\n"
            "    ldr r0, [r0, #0]\n"
            "    cmp r8, r0\n"
            "    bcs .LFarmStatusEarningsPage_draw_9\n"
            "    adds r2, r1, #0\n"
            "    adds r2, r2, r7\n"
            "    mov sl, r2\n"
            "    movs r3, #178\n"
            "    lsls r3, r3, #3\n"
            "    adds r3, r3, r7\n"
            "    mov r9, r3\n"
            "    mov r1, r8\n"
            "    lsls r0, r1, #4\n"
            "    movs r2, #142\n"
            "    lsls r2, r2, #5\n"
            "    adds r0, r0, r2\n"
            "    adds r6, r0, r7\n"
            ".LFarmStatusEarningsPage_draw_7:\n"
            "    movs r3, #0\n"
            "    ldrsh r1, [r6, r3]\n"
            "    mov r2, r9\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r2, r3]\n"
            "    adds r0, #160\n"
            "    cmp r1, r0\n"
            "    bgt .LFarmStatusEarningsPage_draw_8\n"
            "    ldr r0, [r7, #0]\n"
            "    bl GetHardwareSpriteBuffer\n"
            "    adds r4, r0, #0\n"
            "    movs r0, #0\n"
            "    ldrsh r2, [r6, r0]\n"
            "    mov r1, r9\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r1, r3]\n"
            "    subs r2, r2, r0\n"
            "    ldr r1, [r6, #4]\n"
            "    movs r0, #1\n"
            "    str r0, [sp, #0]\n"
            "    str r0, [sp, #4]\n"
            "    movs r0, #0\n"
            "    str r0, [sp, #8]\n"
            "    str r0, [sp, #12]\n"
            "    add r5, sp, #24\n"
            "    adds r0, r5, #0\n"
            "    movs r3, #5\n"
            "    bl InitializeMosaicSpriteOam\n"
            "    ldrb r2, [r4, #0]\n"
            "    cmp r2, #127\n"
            "    bhi .LFarmStatusEarningsPage_draw_8\n"
            "    lsls r1, r2, #3\n"
            "    adds r1, #4\n"
            "    adds r1, r4, r1\n"
            "    ldr r0, [sp, #24]\n"
            "    str r0, [r1, #0]\n"
            "    ldrh r0, [r5, #4]\n"
            "    strh r0, [r1, #4]\n"
            "    adds r0, r2, #1\n"
            "    strb r0, [r4, #0]\n"
            ".LFarmStatusEarningsPage_draw_8:\n"
            "    adds r6, #16\n"
            "    movs r0, #1\n"
            "    add r8, r0\n"
            "    mov r1, sl\n"
            "    ldr r0, [r1, #0]\n"
            "    cmp r8, r0\n"
            "    bcc .LFarmStatusEarningsPage_draw_7\n"
            ".LFarmStatusEarningsPage_draw_9:\n"
            "    movs r0, #1\n"
            "    add sp, #36\n"
            "    pop {r3, r4, r5}\n"
            "    mov r8, r3\n"
            "    mov r9, r4\n"
            "    mov sl, r5\n"
            "    pop {r4, r5, r6, r7}\n"
            "    pop {r1}\n"
            "    bx r1\n"
            ".LFarmStatusEarningsPage_draw_10: .word 0x00000dec\n"
            ".LFarmStatusEarningsPage_draw_11: .word 0x00000de8\n"
            ".LFarmStatusEarningsPage_draw_12: .word 0x000011bc\n"
        );
    }
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    virtual inline NAKED u32 Draw()
    {
        asm_unified(
            "    push {r4, r5, r6, r7, lr}\n"
            "    mov r7, sl\n"
            "    mov r6, r9\n"
            "    mov r5, r8\n"
            "    push {r5, r6, r7}\n"
            "    sub sp, #36\n"
            "    adds r7, r0, #0\n"
            "    bl Draw__14ScrollMenuPage\n"
            "    movs r0, #0\n"
            "    mov r8, r0\n"
            "    ldr r1, .LDraw__22FarmStatusEarningsPage_native_198\n"
            "    adds r0, r7, r1\n"
            "    movs r2, #0\n"
            "    ldrsh r0, [r0, r2]\n"
            "    adds r0, #48\n"
            "    movs r3, #178\n"
            "    lsls r3, r3, #3\n"
            "    adds r1, r7, r3\n"
            "    movs r2, #0\n"
            "    ldrsh r1, [r1, r2]\n"
            "    cmp r0, r1\n"
            "    bge .LDraw__22FarmStatusEarningsPage_native_44\n"
            "    adds r2, r1, #0\n"
            "    ldr r3, .LDraw__22FarmStatusEarningsPage_native_198\n"
            "    adds r1, r7, r3\n"
            ".LDraw__22FarmStatusEarningsPage_native_34:\n"
            "    adds r1, #16\n"
            "    movs r0, #1\n"
            "    add r8, r0\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r1, r3]\n"
            "    adds r0, #48\n"
            "    cmp r0, r2\n"
            "    blt .LDraw__22FarmStatusEarningsPage_native_34\n"
            ".LDraw__22FarmStatusEarningsPage_native_44:\n"
            "    ldr r1, .LDraw__22FarmStatusEarningsPage_native_19c\n"
            "    adds r0, r7, r1\n"
            "    ldr r0, [r0, #0]\n"
            "    ldr r2, .LDraw__22FarmStatusEarningsPage_native_1a0\n"
            "    adds r2, r7, r2\n"
            "    str r2, [sp, #32]\n"
            "    cmp r8, r0\n"
            "    bcs .LDraw__22FarmStatusEarningsPage_native_d0\n"
            "    adds r3, r1, #0\n"
            "    adds r3, r3, r7\n"
            "    mov sl, r3\n"
            "    movs r0, #178\n"
            "    lsls r0, r0, #3\n"
            "    adds r0, r0, r7\n"
            "    mov r9, r0\n"
            "    mov r1, r8\n"
            "    lsls r0, r1, #4\n"
            "    ldr r2, .LDraw__22FarmStatusEarningsPage_native_198\n"
            "    adds r0, r0, r2\n"
            "    adds r5, r0, r7\n"
            ".LDraw__22FarmStatusEarningsPage_native_6c:\n"
            "    movs r3, #0\n"
            "    ldrsh r1, [r5, r3]\n"
            "    mov r2, r9\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r2, r3]\n"
            "    adds r0, #160\n"
            "    cmp r1, r0\n"
            "    bgt .LDraw__22FarmStatusEarningsPage_native_c2\n"
            "    ldr r0, [r7, #0]\n"
            "    bl GetHardwareSpriteBuffer\n"
            "    adds r4, r0, #0\n"
            "    movs r0, #0\n"
            "    ldrsh r2, [r5, r0]\n"
            "    mov r1, r9\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r1, r3]\n"
            "    subs r2, r2, r0\n"
            "    ldr r1, [r5, #4]\n"
            "    movs r0, #2\n"
            "    str r0, [sp, #0]\n"
            "    movs r0, #1\n"
            "    str r0, [sp, #4]\n"
            "    str r0, [sp, #8]\n"
            "    movs r0, #0\n"
            "    str r0, [sp, #12]\n"
            "    add r6, sp, #16\n"
            "    adds r0, r6, #0\n"
            "    movs r3, #16\n"
            "    bl InitializeMosaicSpriteOam\n"
            "    ldrb r2, [r4, #0]\n"
            "    cmp r2, #127\n"
            "    bhi .LDraw__22FarmStatusEarningsPage_native_c2\n"
            "    lsls r1, r2, #3\n"
            "    adds r1, #4\n"
            "    adds r1, r4, r1\n"
            "    ldr r0, [sp, #16]\n"
            "    str r0, [r1, #0]\n"
            "    ldrh r0, [r6, #4]\n"
            "    strh r0, [r1, #4]\n"
            "    adds r0, r2, #1\n"
            "    strb r0, [r4, #0]\n"
            ".LDraw__22FarmStatusEarningsPage_native_c2:\n"
            "    adds r5, #16\n"
            "    movs r0, #1\n"
            "    add r8, r0\n"
            "    mov r1, sl\n"
            "    ldr r0, [r1, #0]\n"
            "    cmp r8, r0\n"
            "    bcc .LDraw__22FarmStatusEarningsPage_native_6c\n"
            ".LDraw__22FarmStatusEarningsPage_native_d0:\n"
            "    movs r2, #0\n"
            "    mov r8, r2\n"
            "    ldr r3, [sp, #32]\n"
            "    movs r1, #0\n"
            "    ldrsh r0, [r3, r1]\n"
            "    adds r0, #48\n"
            "    movs r2, #178\n"
            "    lsls r2, r2, #3\n"
            "    adds r1, r7, r2\n"
            "    movs r3, #0\n"
            "    ldrsh r1, [r1, r3]\n"
            "    cmp r0, r1\n"
            "    bge .LDraw__22FarmStatusEarningsPage_native_100\n"
            "    adds r2, r1, #0\n"
            "    ldr r0, .LDraw__22FarmStatusEarningsPage_native_1a0\n"
            "    adds r1, r7, r0\n"
            ".LDraw__22FarmStatusEarningsPage_native_f0:\n"
            "    adds r1, #16\n"
            "    movs r3, #1\n"
            "    add r8, r3\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r1, r3]\n"
            "    adds r0, #48\n"
            "    cmp r0, r2\n"
            "    blt .LDraw__22FarmStatusEarningsPage_native_f0\n"
            ".LDraw__22FarmStatusEarningsPage_native_100:\n"
            "    ldr r1, .LDraw__22FarmStatusEarningsPage_native_1a4\n"
            "    adds r0, r7, r1\n"
            "    ldr r0, [r0, #0]\n"
            "    cmp r8, r0\n"
            "    bcs .LDraw__22FarmStatusEarningsPage_native_184\n"
            "    adds r2, r1, #0\n"
            "    adds r2, r2, r7\n"
            "    mov sl, r2\n"
            "    movs r3, #178\n"
            "    lsls r3, r3, #3\n"
            "    adds r3, r3, r7\n"
            "    mov r9, r3\n"
            "    mov r1, r8\n"
            "    lsls r0, r1, #4\n"
            "    ldr r2, .LDraw__22FarmStatusEarningsPage_native_1a0\n"
            "    adds r0, r0, r2\n"
            "    adds r6, r0, r7\n"
            ".LDraw__22FarmStatusEarningsPage_native_122:\n"
            "    movs r3, #0\n"
            "    ldrsh r1, [r6, r3]\n"
            "    mov r2, r9\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r2, r3]\n"
            "    adds r0, #160\n"
            "    cmp r1, r0\n"
            "    bgt .LDraw__22FarmStatusEarningsPage_native_176\n"
            "    ldr r0, [r7, #0]\n"
            "    bl GetHardwareSpriteBuffer\n"
            "    adds r4, r0, #0\n"
            "    movs r0, #0\n"
            "    ldrsh r2, [r6, r0]\n"
            "    mov r1, r9\n"
            "    movs r3, #0\n"
            "    ldrsh r0, [r1, r3]\n"
            "    subs r2, r2, r0\n"
            "    ldr r1, [r6, #4]\n"
            "    movs r0, #1\n"
            "    str r0, [sp, #0]\n"
            "    str r0, [sp, #4]\n"
            "    movs r0, #0\n"
            "    str r0, [sp, #8]\n"
            "    str r0, [sp, #12]\n"
            "    add r5, sp, #24\n"
            "    adds r0, r5, #0\n"
            "    movs r3, #5\n"
            "    bl InitializeMosaicSpriteOam\n"
            "    ldrb r2, [r4, #0]\n"
            "    cmp r2, #127\n"
            "    bhi .LDraw__22FarmStatusEarningsPage_native_176\n"
            "    lsls r1, r2, #3\n"
            "    adds r1, #4\n"
            "    adds r1, r4, r1\n"
            "    ldr r0, [sp, #24]\n"
            "    str r0, [r1, #0]\n"
            "    ldrh r0, [r5, #4]\n"
            "    strh r0, [r1, #4]\n"
            "    adds r0, r2, #1\n"
            "    strb r0, [r4, #0]\n"
            ".LDraw__22FarmStatusEarningsPage_native_176:\n"
            "    adds r6, #16\n"
            "    movs r0, #1\n"
            "    add r8, r0\n"
            "    mov r1, sl\n"
            "    ldr r0, [r1, #0]\n"
            "    cmp r8, r0\n"
            "    bcc .LDraw__22FarmStatusEarningsPage_native_122\n"
            ".LDraw__22FarmStatusEarningsPage_native_184:\n"
            "    movs r0, #1\n"
            "    add sp, #36\n"
            "    pop {r3, r4, r5}\n"
            "    mov r8, r3\n"
            "    mov r9, r4\n"
            "    mov sl, r5\n"
            "    pop {r4, r5, r6, r7}\n"
            "    pop {r1}\n"
            "    bx r1\n"
            "    .align 2, 0\n"
            ".LDraw__22FarmStatusEarningsPage_native_198: .word 0x00001268\n"
            ".LDraw__22FarmStatusEarningsPage_native_19c: .word 0x00001264\n"
            ".LDraw__22FarmStatusEarningsPage_native_1a0: .word 0x0000163c\n"
            ".LDraw__22FarmStatusEarningsPage_native_1a4: .word 0x00001638\n"
        );
    }
#endif
#if defined(REGION_JP)
    u8 unk_5B8[0xDE8 - 0x5B8];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    u8 unk_5B8[0x1264 - 0x5B8];
#endif
    FarmStatusEntries<FarmStatusMarkerRow, 61> markers_1264;
    FarmStatusEntries<FarmStatusMarkerRow, 60> markers_1638;
};

struct FarmStatusToolsPage : ScrollMenuPage {
    FarmStatusToolsPage(ScrollMenu * menu, GameStateSaveImage * image);
    virtual inline u32 Draw()
    {
        ScrollMenuPage::Draw();
        return 1;
    }
    u8 unk_5B8[0x9C4 - 0x5B8];
    IndexedResourceArchive archive;
};

#if defined(REGION_JP)
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
#endif

#include "status_screen_transitions.hh"


extern char const gText_FarmStatus_OverviewTitle[];
extern char const gText_FarmStatus_GoldUnit[];
extern char const gText_FarmStatus_Healthy[];
extern char const gText_FarmStatus_Unhappy[];
extern char const gText_FarmStatus_Sick[];
extern char const gText_FarmStatus_Spring[];
extern char const gText_FarmStatus_Summer[];
extern char const gText_FarmStatus_Autumn[];
extern char const gText_FarmStatus_Winter[];
extern char const gText_FarmStatus_AgeUnit[];
extern char const gText_FarmStatus_ChickenList[];
extern char const gText_FarmStatus_CattleList[];
extern char const gText_FarmStatus_SheepList[];
extern char const gText_FarmStatus_HarvestSpriteList[];
extern char const gText_FarmStatus_DaysRemaining[];
extern char const gText_FarmStatus_WorkAssignment[];
extern char const gText_FarmStatus_NotAssigned[];
extern char const gText_FarmStatus_EarningsReport[];
extern char const gText_FarmStatus_PlusSign[];
extern char const gText_FarmStatus_MinusSign[];
extern char const gText_FarmStatus_YearLabel[];
extern char const gText_FarmStatus_Income[];
extern char const gText_FarmStatus_Expenses[];
extern char const gText_FarmStatus_ToolLevelList[];
extern char const gText_FarmStatus_PercentSign[];

#if defined(REGION_JP)
extern char const gText_FarmStatus_CounterBirds[];
extern char const gText_FarmStatus_CounterHeads[];
extern char const gText_FarmStatus_CounterAnimals[];
extern char const gText_FarmStatus_CounterSheets[];
extern char const gText_FarmStatus_CounterPieces[];
extern char const gText_FarmStatus_CounterLongObjects[];
extern char const gText_FarmStatus_DayUnit[];
extern char const gText_FarmStatus_MonthSuffix[];
extern char const gText_FarmStatus_ToolUpgradeInProgress[];
extern char const gText_FarmStatus_ToolUpgradeAvailable[];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_FarmStatus_CountFieldPadding[];
extern char const gText_FarmStatus_DayAbbreviation[];
extern char const gText_FarmStatus_ToolShopLabel[];
extern char const gText_FarmStatus_ToolUpgradeQuestion[];
#endif

#endif // FARM_STATUS_SCREEN_HH
