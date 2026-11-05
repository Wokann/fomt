#include "new_game_name_input.hh"
#include "hardware_context.hh"
#include "new_game_data.hh"
#include "ui_graphics_sizes.hh"
#include "hardware_state_accessors.hh"
#include "allocation_failure.hh"
#include "hardware_blend_object.hh"
#include "hardware_dma.hh"
#include "hardware_music_player.hh"
#include "gbaio.h"
#include "fomt_constants.hh"
#include <string.h>
#pragma implementation

void * operator new(unsigned long);
void operator delete(void *);
inline void * operator new(unsigned long, void * location) { return location; }
inline void * operator new[](unsigned long, void * location) { return location; }

static inline void QueueNameInputBlend(HardwareContext * core, HardwareBlendObject & blend)
{
    HardwareLinkedList * list =
        GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    list->Append(&blend);
}

static inline bool NameInputBlendIsQueued(HardwareBlendObject const & blend)
{
    return blend.previous_slot != nullptr;
}

NewGameNameInputCore::NewGameNameInputCore(char const * prompt,
    char const * initial_name)
    : HardwareContext(), music_player_1(1), music_player_2(2)
{
    NewGameNameInputCore * core = this;

    // Publish the constructed UI before these temporary resource owners leave
    // scope, preserving the native allocation, construction and cleanup order.
    void * ui_storage = ::operator new(sizeof(UiStateOwner));
    {
        ObjTileCollection shared;
        ObjPaletteCollection resources;
        UiStateOwner * ui = new (ui_storage) UiStateOwner(0, 15, 4, 0, shared, resources);
        core->ui_state = ui;
    }
    core->prompt = prompt;
    memcpy(core->name, gText_NewGameNameEntry_Placeholder, sizeof(core->name));
    if (initial_name != nullptr) {
        for (int index = 0; index < static_cast<int>(sizeof(core->name)) && initial_name[index]; ++index)
            core->name[index] = initial_name[index];
    }
}

NewGameNameInputCore::~NewGameNameInputCore()
{
    if (ui_state != nullptr)
        delete ui_state;
}

SceneTransitionOwner RunNameInputCore(NewGameNameInputCore * core)
{
    EnableHardwareForcedBlank(core);
    ObjTileCollectionEntry tiles;
    ReleaseObjTileHandle(&tiles, tiles.handle);
    tiles.handle = AllocateObjTileHandle(&tiles, 3);
    u32 tile_index = GetObjTileIndex(&tiles, tiles.handle);
    InitializeNameInputScreen(core);
    InitializeNameInputCursorSprites(core, tile_index);
    ResetNameInputCore(core);
    RenderNameInputName(core);

    HardwareDisplayState * display =
        GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    HardwareDisplayRegisterValue control(BLDCNT_TGT1_ALL);
    display->SetBlendControl(control);
    HardwareBlendObject blend(GetHardwareDisplayState(reinterpret_cast<void * const *>(core)));
    {
        i16 step = 0x889;
        blend.blend.Begin(step, 1, 1);
    }
    QueueNameInputBlend(core, blend);
    while (NameInputBlendIsQueued(blend))
        UpdateHardwareFrame(core);

    while (core->finished == 0)
    {
        UpdateHardwareInput(reinterpret_cast<void * const *>(core));
        ProcessNameInputKeys(core);
        UpdateNameInputCursorSprites(core);
        RenderNameInputName(core);
        RenderNameInputKeyboard(core);
        SubmitNameInputCursorSprites(core);
        UpdateNameInputConfirmation(core);
        UpdateHardwareFrame(core);
    }
    {
        i16 step = 0x889;
        blend.blend.End(step, 1, 1);
    }
    // Re-enqueue the same stack command for the exit blend.
    HardwareBlendObject & linked_blend = blend;
    QueueNameInputBlend(core, linked_blend);
    while (NameInputBlendIsQueued(blend))
        UpdateHardwareFrame(core);
    return SceneTransitionOwner();
}

NAKED void InitializeNameInputScreen(NewGameNameInputCore * core)
{
    asm_unified(
        ".include \"six/asm/hw/memory.s\"\n"
        ".include \"six/asm/hw/video.s\"\n"
#if defined(REGION_JP)
        "    push\t{r4, r5, r6, r7, lr}\n"
        "    mov\tr7, sl\n"
        "    mov\tr6, r9\n"
        "    mov\tr5, r8\n"
        "    push\t{r5, r6, r7}\n"
        "    sub\tsp, #84\t@ 0x54\n"
        "    mov\tsl, r0\n"
        "    ldr r0, .Ljp_00005D9C\n"
        "    ldr\tr0, [r0, #0]\n"
        "    ldr r1, .Ljp_00005DA0\n"
        "    ldr r2, .Ljp_00005DA4\n"
        "    ldr\tr2, [r2, #0]\n"
        "    bl CopyHardwareDma3\n"
        "    ldr r0, .Ljp_00005DA8\n"
        "    ldr\tr0, [r0, #0]\n"
        "    movs\tr1, #(BG_PALETTE >> 19)\n"
        "    lsls\tr1, r1, #19\n"
        "    movs\tr2, #" STRINGIFY(UI_SHARED_PALETTE_BYTES) "\n"
        "    bl CopyHardwareDma3\n"
        "    mov\tr0, sl\n"
        "    bl GetHardwareDisplayState\n"
        "    add\tr1, sp, #12\n"
        "    movs\tr3, #((LCD_OBJ_MAPPING_1D | LCD_BG0_ENABLE | LCD_BG1_ENABLE | LCD_BG2_ENABLE | LCD_OBJ_ENABLE) >> 5)\n"
        "    lsls\tr3, r3, #5\n"
        "    adds\tr2, r3, #0\n"
        "    strh\tr2, [r1, #0]\n"
        "    movs\tr4, #0\n"
        "    strh\tr2, [r0, #0]\n"
        "    mov\tr0, sl\n"
        "    bl GetHardwareDisplayState\n"
        "    add\tr2, sp, #12\n"
        "    ldr r5, .Ljp_00005DAC\n"
        "    adds\tr1, r5, #0\n"
        "    strh\tr1, [r2, #0]\n"
        "    strh\tr1, [r0, #10]\n"
        "    mov\tr0, sl\n"
        "    bl GetHardwareDisplayState\n"
        "    add\tr2, sp, #12\n"
        "    ldr r7, .Ljp_00005DB0\n"
        "    adds\tr1, r7, #0\n"
        "    strh\tr1, [r2, #0]\n"
        "    strh\tr1, [r0, #12]\n"
        "    ldr r0, .Ljp_00005DB4\n"
        "    movs\tr1, #20\n"
        "    str\tr1, [sp, #0]\n"
        "    movs\tr1, #150\t@ 0x96\n"
        "    lsls\tr1, r1, #2\n"
        "    str\tr1, [sp, #4]\n"
        "    str\tr4, [sp, #8]\n"
        "    movs\tr1, #0\n"
        "    movs\tr2, #0\n"
        "    movs\tr3, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    bl DrawUiTextWindowBorder\n"
        "    movs\tr0, #1\n"
        "    negs\tr0, r0\n"
        "    ldr r4, .Ljp_00005DB8\n"
        "    movs\tr2, #(BG_SCREEN_SIZE >> 4)\n"
        "    lsls\tr2, r2, #4\n"
        "    adds\tr1, r4, #0\n"
        "    bl FillHardwareDma3\n"
        "    movs\tr1, #0\n"
        "    add\tr0, sp, #32\n"
        "    mov\tr8, r0\n"
        "    add\tr2, sp, #36\t@ 0x24\n"
        "    mov\tr9, r2\n"
        "    mov\tr3, sp\n"
        "    adds\tr3, #16\n"
        "    str\tr3, [sp, #68]\t@ 0x44\n"
        "    mov\tr5, sp\n"
        "    adds\tr5, #48\t@ 0x30\n"
        "    str\tr5, [sp, #72]\t@ 0x48\n"
        "    mov\tr7, sl\n"
        "    adds\tr7, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
        "    ldr r0, .Ljp_00005DBC\n"
        "    add\tr0, sl\n"
        "    str\tr0, [sp, #64]\t@ 0x40\n"
        "    @ Blank tile from the cleared tail of the final character row.\n"
#if ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) & 1) == 0 && ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) >> 1) <= 255
        "    movs\tr2, #((" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " + 28) >> 1)\n"
        "    lsls\tr2, r2, #1\n"
#else
        "    ldr r2, .Lname_input_jp_screen_blank_tile\n"
#endif
        "    adds\tr6, r2, #0\n"
        ".Ljp_00005C5C:\n"
        "    movs\tr3, #0\n"
        "    lsls\tr2, r1, #6\n"
        "    adds\tr5, r1, #1\n"
        "    adds\tr0, r2, r4\n"
        ".Ljp_00005C64:\n"
        "    strh\tr6, [r0, #0]\n"
        "    adds\tr0, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #29\n"
        "    bls .Ljp_00005C64\n"
        "    adds\tr1, r5, #0\n"
        "    cmp\tr1, #19\n"
        "    bls .Ljp_00005C5C\n"
        "    movs\tr3, #10\n"
        "    ldr r2, .Ljp_00005DC0\n"
        "    ldr r1, .Ljp_00005DC4\n"
        ".Ljp_00005C7A:\n"
        "    strh\tr3, [r1, #0]\n"
        "    adds\tr0, r3, #0\n"
        "    adds\tr0, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    strh\tr0, [r2, #0]\n"
        "    adds\tr2, #2\n"
        "    adds\tr1, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #15\n"
        "    bls .Ljp_00005C7A\n"
        "    movs\tr3, #3\n"
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255
        "    movs r4, #(((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ") >> 1)\n"
        "    lsls r4, r4, #1\n"
#else
        "    ldr r4, .Lname_input_map_jp_1\n"
#endif
        "\n"
        "    adds\tr5, r4, #0\n"
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255
        "    movs r0, #(((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ") >> 1)\n"
        "    lsls r0, r0, #1\n"
#else
        "    ldr r0, .Lname_input_map_jp_2\n"
#endif
        "\n"
        "    adds\tr4, r0, #0\n"
        "    ldr r2, .Ljp_00005DC8\n"
        "    ldr r1, .Ljp_00005DCC\n"
        ".Ljp_00005C9E:\n"
        "    adds\tr0, r3, r5\n"
        "    strh\tr0, [r1, #0]\n"
        "    adds\tr0, r3, r4\n"
        "    strh\tr0, [r2, #0]\n"
        "    adds\tr2, #2\n"
        "    adds\tr1, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #26\n"
        "    bls .Ljp_00005C9E\n"
        "    movs\tr1, #4\n"
        "    ldr r4, .Ljp_00005DB8\n"
        ".Ljp_00005CB4:\n"
        "    movs\tr3, #0\n"
        "    lsls\tr2, r1, #6\n"
        "    adds\tr5, r1, #1\n"
        "    subs\tr1, #2\n"
#if (NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1))
        "    lsls\tr0, r1, #4\n"
        "    subs\tr0, r0, r1\n"
        "    lsls\tr1, r0, #1\n"
#else
        "    ldr r0, .Lname_input_map_jp_row_width\n"
        "    muls r1, r0\n"
#endif
        "    adds\tr2, r2, r4\n"
        ".Ljp_00005CC4:\n"
        "    adds\tr0, r1, r3\n"
        "    strh\tr0, [r2, #0]\n"
        "    adds\tr2, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #29\n"
        "    bls .Ljp_00005CC4\n"
        "    adds\tr1, r5, #0\n"
        "    cmp\tr1, #(4 + " STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " - 1)\n"
        "    bls .Ljp_00005CB4\n"
        "    movs\tr3, #18\n"
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255
        "    movs r1, #((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ") >> 1)\n"
        "    lsls r1, r1, #1\n"
#else
        "    ldr r1, .Lname_input_map_jp_3\n"
#endif
        "\n"
        "    adds\tr5, r1, #0\n"
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255
        "    movs r2, #((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ") >> 1)\n"
        "    lsls r2, r2, #1\n"
#else
        "    ldr r2, .Lname_input_map_jp_4\n"
#endif
        "\n"
        "    adds\tr4, r2, #0\n"
        "    ldr r2, .Ljp_00005DD0\n"
        "    ldr r1, .Ljp_00005DD4\n"
        ".Ljp_00005CE8:\n"
        "    adds\tr0, r3, r5\n"
        "    strh\tr0, [r1, #0]\n"
        "    adds\tr0, r3, r4\n"
        "    strh\tr0, [r2, #0]\n"
        "    adds\tr2, #2\n"
        "    adds\tr1, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #29\n"
        "    bls .Ljp_00005CE8\n"
        "    ldr r0, .Ljp_00005DD8\n"
        "    add\tr0, sl\n"
        "    ldr\tr0, [r0, #0]\n"
        "    cmp\tr0, #0\n"
        "    beq .Ljp_00005D26\n"
        "    movs\tr3, #4\n"
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 4) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 4) >> 2) <= 255
        "    movs r4, #(((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " + 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " - 4) >> 2)\n"
        "    lsls r4, r4, #2\n"
#else
        "    ldr r4, .Lname_input_map_jp_5\n"
#endif
        "\n"
        "    adds\tr5, r4, #0\n"
        "    ldr r0, .Ljp_00005DDC\n"
        "    adds\tr4, r0, #0\n"
        "    ldr r2, .Ljp_00005DE0\n"
        "    ldr r1, .Ljp_00005DE4\n"
        ".Ljp_00005D14:\n"
        "    adds\tr0, r3, r5\n"
        "    strh\tr0, [r1, #0]\n"
        "    adds\tr0, r3, r4\n"
        "    strh\tr0, [r2, #0]\n"
        "    adds\tr2, #2\n"
        "    adds\tr1, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #(4 + " STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_WIDTH) " - 1)\n"
        "    bls .Ljp_00005D14\n"
        ".Ljp_00005D26:\n"
        "    ldr r1, .Ljp_00005DE8\n"
        "    movs\tr0, #0\n"
        "    movs\tr2, #32\n"
        "    bl FillHardwareDma3\n"
        "    movs\tr4, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    movs\tr5, #2\n"
        "    add\tr0, sp, #32\n"
        "    strh\tr4, [r0, #0]\n"
        "    mov\tr1, r8\n"
        "    strh\tr5, [r1, #2]\n"
        "    ldr\tr0, [sp, #32]\n"
        "    adds\tr1, r7, #0\n"
        "    movs\tr2, #0\n"
        "    bl Clear2DGfxBuffer\n"
        "    ldr r1, .Ljp_00005DEC\n"
        "    add\tr0, sp, #36\t@ 0x24\n"
        "    strh\tr4, [r0, #0]\n"
        "    mov\tr2, r9\n"
        "    strh\tr5, [r2, #2]\n"
        "    ldr\tr0, [sp, #36]\t@ 0x24\n"
        "    str\tr1, [sp, #0]\n"
        "    adds\tr1, r7, #0\n"
        "    movs\tr2, #80\t@ 0x50\n"
        "    movs\tr3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    mov\tr0, sl\n"
        "    bl GetHardwareDmaQueue\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r3, r3, #3\n"
#else
        "    ldr r3, .Lname_input_jp_screen_2\n"
#endif
        "\n"
        "    adds\tr6, r0, #0\n"
        "    add\tr0, sp, #16\n"
        "    adds\tr1, r7, #0\n"
        "    movs\tr2, #(MEM_VRAM >> 19)\n"
        "    lsls\tr2, r2, #19\n"
        "    bl __21DmaTransferDescriptorPCvPvUi\n"
        "    ldr\tr3, [sp, #68]\t@ 0x44\n"
        "    mov\tr8, r3\n"
        "    ldr\tr1, [r6, #4]\n"
        "    ldr\tr0, [r6, #12]\n"
        "    cmp\tr1, r0\n"
        "    beq .Ljp_00005DF0\n"
        "    cmp\tr1, #0\n"
        "    beq .Ljp_00005D92\n"
        "    adds\tr0, r1, #0\n"
        "    mov\tr1, r8\n"
        "    ldmia\tr1!, {r4, r5, r7}\n"
        "    stmia\tr0!, {r4, r5, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".Ljp_00005D92:\n"
        "    ldr\tr0, [r6, #4]\n"
        "    adds\tr0, #16\n"
        "    str\tr0, [r6, #4]\n"
        "    b .Ljp_00005EB4\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
        ".Lname_input_jp_screen_2: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !(((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) & 1) == 0 && ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) >> 1) <= 255)
        ".Lname_input_jp_screen_blank_tile: .word (" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " + 28)\n"
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255)
        ".Lname_input_map_jp_1: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ")\n"
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255)
        ".Lname_input_map_jp_2: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255)
        ".Lname_input_map_jp_3: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255)
        ".Lname_input_map_jp_4: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ")\n"
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 4) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT - 4) >> 2) <= 255)
        ".Lname_input_map_jp_5: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " + 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " - 4)\n"
#endif
#if !((NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1)))
        ".Lname_input_map_jp_row_width: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ")\n"
#endif
        ".Ljp_00005D9C: .word gUiSharedTiles\n"
        ".Ljp_00005DA0: .word (MEM_VRAM + 0x4B00)\n"
        ".Ljp_00005DA4: .word gUiSharedTileByteCount\n"
        ".Ljp_00005DA8: .word gUiSharedPalette\n"
        ".Ljp_00005DAC: .word (BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        ".Ljp_00005DB0: .word (BG_PRIO_2 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        ".Ljp_00005DB4: .word (MEM_VRAM + 31 * BG_SCREEN_SIZE)\n"
        ".Ljp_00005DB8: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE)\n"
        ".Ljp_00005DBC: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PROMPT_TILES_OFFSET) ")\n"
        ".Ljp_00005DC0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x94)\n"
        ".Ljp_00005DC4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x54)\n"
        ".Ljp_00005DC8: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x486)\n"
        ".Ljp_00005DCC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x446)\n"
        ".Ljp_00005DD0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0xA4)\n"
        ".Ljp_00005DD4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x64)\n"
        ".Ljp_00005DD8: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) ")\n"
        ".Ljp_00005DDC: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " + 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_WIDTH) " - 4)\n"
        ".Ljp_00005DE0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x88)\n"
        ".Ljp_00005DE4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x48)\n"
        ".Ljp_00005DE8: .word (MEM_VRAM + 0xFFC000)\n"
        ".Ljp_00005DEC: .word gText_NewGameNameEntry_NameLabel\n"
        ".Ljp_00005DF0:\n"
        "    str\tr1, [sp, #76]\t@ 0x4c\n"
        "    movs\tr0, #1\n"
        "    str\tr0, [sp, #44]\t@ 0x2c\n"
        "    ldr\tr0, [r6, #0]\n"
        "    subs\tr0, r1, r0\n"
        "    asrs\tr4, r0, #4\n"
        "    str\tr4, [sp, #40]\t@ 0x28\n"
        "    add\tr1, sp, #44\t@ 0x2c\n"
        "    add\tr0, sp, #40\t@ 0x28\n"
        "    cmp\tr4, #1\n"
        "    bcs .Ljp_00005E08\n"
        "    adds\tr0, r1, #0\n"
        ".Ljp_00005E08:\n"
        "    ldr\tr0, [r0, #0]\n"
        "    adds\tr0, r4, r0\n"
        "    cmp\tr0, #0\n"
        "    beq .Ljp_00005E26\n"
        "    lsls\tr4, r0, #4\n"
        "    adds\tr0, r4, #0\n"
        "    bl malloc\n"
        "    mov\tr9, r4\n"
        "    cmp\tr0, #0\n"
        "    bne .Ljp_00005E2A\n"
        "    mov\tr0, r9\n"
        "    bl RetryMemoryAllocation\n"
        "    b .Ljp_00005E2A\n"
        ".Ljp_00005E26:\n"
        "    movs\tr0, #0\n"
        "    mov\tr9, r0\n"
        ".Ljp_00005E2A:\n"
        "    adds\tr5, r0, #0\n"
        "    str\tr5, [sp, #80]\t@ 0x50\n"
        "    ldr\tr2, [r6, #0]\n"
        "    adds\tr3, r5, #0\n"
        "    ldr\tr4, [sp, #76]\t@ 0x4c\n"
        "    cmp\tr2, r4\n"
        "    beq .Ljp_00005E52\n"
        ".Ljp_00005E38:\n"
        "    cmp\tr3, #0\n"
        "    beq .Ljp_00005E48\n"
        "    adds\tr0, r3, #0\n"
        "    adds\tr1, r2, #0\n"
        "    ldmia\tr1!, {r4, r5, r7}\n"
        "    stmia\tr0!, {r4, r5, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".Ljp_00005E48:\n"
        "    adds\tr2, #16\n"
        "    adds\tr3, #16\n"
        "    ldr\tr5, [sp, #76]\t@ 0x4c\n"
        "    cmp\tr2, r5\n"
        "    bne .Ljp_00005E38\n"
        ".Ljp_00005E52:\n"
        "    adds\tr5, r3, #0\n"
        "    ldr\tr0, [sp, #44]\t@ 0x2c\n"
        "    cmp\tr0, #1\n"
        "    bne .Ljp_00005E6E\n"
        "    cmp\tr5, #0\n"
        "    beq .Ljp_00005E6A\n"
        "    adds\tr0, r5, #0\n"
        "    mov\tr1, r8\n"
        "    ldmia\tr1!, {r2, r3, r7}\n"
        "    stmia\tr0!, {r2, r3, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".Ljp_00005E6A:\n"
        "    adds\tr5, #16\n"
        "    b .Ljp_00005E90\n"
        ".Ljp_00005E6E:\n"
        "    adds\tr3, r0, #0\n"
        "    adds\tr2, r5, #0\n"
        "    cmp\tr3, #0\n"
        "    beq .Ljp_00005E8E\n"
        ".Ljp_00005E76:\n"
        "    cmp\tr2, #0\n"
        "    beq .Ljp_00005E86\n"
        "    adds\tr0, r2, #0\n"
        "    mov\tr1, r8\n"
        "    ldmia\tr1!, {r4, r5, r7}\n"
        "    stmia\tr0!, {r4, r5, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".Ljp_00005E86:\n"
        "    subs\tr3, #1\n"
        "    adds\tr2, #16\n"
        "    cmp\tr3, #0\n"
        "    bne .Ljp_00005E76\n"
        ".Ljp_00005E8E:\n"
        "    adds\tr5, r2, #0\n"
        ".Ljp_00005E90:\n"
        "    ldr\tr2, [r6, #4]\n"
        "    ldr\tr0, [r6, #0]\n"
        "    adds\tr1, r0, #0\n"
        "    cmp\tr0, r2\n"
        "    beq .Ljp_00005EA0\n"
        ".Ljp_00005E9A:\n"
        "    adds\tr1, #16\n"
        "    cmp\tr1, r2\n"
        "    bne .Ljp_00005E9A\n"
        ".Ljp_00005EA0:\n"
        "    cmp\tr0, #0\n"
        "    beq .Ljp_00005EA8\n"
        "    bl free\n"
        ".Ljp_00005EA8:\n"
        "    ldr\tr0, [sp, #80]\t@ 0x50\n"
        "    add\tr0, r9\n"
        "    ldr\tr1, [sp, #80]\t@ 0x50\n"
        "    str\tr1, [r6, #0]\n"
        "    str\tr5, [r6, #4]\n"
        "    str\tr0, [r6, #12]\n"
        ".Ljp_00005EB4:\n"
        "    ldr r1, .Ljp_00005F48\n"
        "    add\tr1, sl\n"
        "    movs\tr0, #0\n"
        "    str\tr0, [r1, #0]\n"
        "    ldr r0, .Ljp_00005F4C\n"
        "    add\tr0, sl\n"
        "    movs\tr2, #1\n"
        "    mov\tr8, r2\n"
        "    mov\tr3, r8\n"
        "    strb\tr3, [r0, #0]\n"
        "    mov\tr0, sl\n"
        "    bl RenderNameInputKeyboard\n"
        "    movs r5, #" STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_WIDTH) "\n"
        "    movs r6, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) "\n"
        "    add\tr0, sp, #48\t@ 0x30\n"
        "    strh\tr5, [r0, #0]\n"
        "    ldr\tr4, [sp, #72]\t@ 0x48\n"
        "    strh\tr6, [r4, #2]\n"
        "    ldr\tr0, [sp, #48]\t@ 0x30\n"
        "    ldr\tr4, [sp, #64]\t@ 0x40\n"
        "    adds\tr1, r4, #0\n"
        "    movs\tr2, #0\n"
        "    bl Clear2DGfxBuffer\n"
        "    ldr r0, .Ljp_00005F50\n"
        "    add\tr0, sl\n"
        "    ldr\tr1, [r0, #0]\n"
        "    cmp\tr1, #0\n"
        "    beq .Ljp_00005F04\n"
        "    add\tr0, sp, #52\t@ 0x34\n"
        "    strh\tr5, [r0, #0]\n"
        "    strh\tr6, [r0, #2]\n"
        "    ldr\tr0, [sp, #52]\t@ 0x34\n"
        "    str\tr1, [sp, #0]\n"
        "    adds\tr1, r4, #0\n"
        "    movs\tr2, #0\n"
        "    movs\tr3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        ".Ljp_00005F04:\n"
        "    mov\tr0, sl\n"
        "    bl GetHardwareDmaQueue\n"
#if ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 1) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 1) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) ") >> 1)\n"
        "    lsls r3, r3, #1\n"
#else
        "    ldr r3, .Lname_input_jp_screen_3\n"
#endif
        "\n"
        "    adds\tr6, r0, #0\n"
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
        "    movs r2, #((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 6)\n"
        "    lsls r2, r2, #3\n"
        "    lsls r2, r2, #3\n"
#else
        "    ldr r2, .Lname_input_jp_screen_1\n"
#endif
        "\n"
        "    ldr r5, .Ljp_00005F54\n"
        "    adds\tr2, r2, r5\n"
        "    add\tr0, sp, #12\n"
        "    ldr\tr1, [sp, #64]\t@ 0x40\n"
        "    bl __21DmaTransferDescriptorPCvPvUi\n"
        "    add\tr7, sp, #12\n"
        "    mov\tr9, r7\n"
        "    ldr\tr1, [r6, #4]\n"
        "    ldr\tr0, [r6, #12]\n"
        "    cmp\tr1, r0\n"
        "    beq .Ljp_00005F58\n"
        "    cmp\tr1, #0\n"
        "    beq .Ljp_00005F3E\n"
        "    adds\tr0, r1, #0\n"
        "    add\tr1, sp, #12\n"
        "    ldmia\tr1!, {r2, r3, r4}\n"
        "    stmia\tr0!, {r2, r3, r4}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".Ljp_00005F3E:\n"
        "    ldr\tr0, [r6, #4]\n"
        "    adds\tr0, #16\n"
        "    str\tr0, [r6, #4]\n"
        "    b .Ljp_0000601A\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
        ".Lname_input_jp_screen_1: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 1) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 1) <= 255)
        ".Lname_input_jp_screen_3: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) ")\n"
#endif
        ".Ljp_00005F48: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ")\n"
        ".Ljp_00005F4C: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET) ")\n"
        ".Ljp_00005F50: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) ")\n"
        ".Ljp_00005F54: .word (MEM_VRAM + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
        ".Ljp_00005F58:\n"
        "    str\tr1, [sp, #76]\t@ 0x4c\n"
        "    mov\tr5, r8\n"
        "    str\tr5, [sp, #60]\t@ 0x3c\n"
        "    ldr\tr0, [r6, #0]\n"
        "    adds\tr7, r1, #0\n"
        "    subs\tr0, r7, r0\n"
        "    asrs\tr4, r0, #4\n"
        "    str\tr4, [sp, #56]\t@ 0x38\n"
        "    add\tr1, sp, #60\t@ 0x3c\n"
        "    add\tr0, sp, #56\t@ 0x38\n"
        "    cmp\tr4, #1\n"
        "    bcs .Ljp_00005F72\n"
        "    adds\tr0, r1, #0\n"
        ".Ljp_00005F72:\n"
        "    ldr\tr0, [r0, #0]\n"
        "    adds\tr0, r4, r0\n"
        "    cmp\tr0, #0\n"
        "    beq .Ljp_00005F90\n"
        "    lsls\tr4, r0, #4\n"
        "    adds\tr0, r4, #0\n"
        "    bl malloc\n"
        "    mov\tr8, r4\n"
        "    cmp\tr0, #0\n"
        "    bne .Ljp_00005F94\n"
        "    mov\tr0, r8\n"
        "    bl RetryMemoryAllocation\n"
        "    b .Ljp_00005F94\n"
        ".Ljp_00005F90:\n"
        "    movs\tr0, #0\n"
        "    mov\tr8, r0\n"
        ".Ljp_00005F94:\n"
        "    adds\tr5, r0, #0\n"
        "    str\tr5, [sp, #80]\t@ 0x50\n"
        "    ldr\tr2, [r6, #0]\n"
        "    adds\tr3, r5, #0\n"
        "    b .Ljp_00005FB2\n"
        ".Ljp_00005F9E:\n"
        "    cmp\tr3, #0\n"
        "    beq .Ljp_00005FAE\n"
        "    adds\tr0, r3, #0\n"
        "    adds\tr1, r2, #0\n"
        "    ldmia\tr1!, {r4, r5, r7}\n"
        "    stmia\tr0!, {r4, r5, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".Ljp_00005FAE:\n"
        "    adds\tr2, #16\n"
        "    adds\tr3, #16\n"
        ".Ljp_00005FB2:\n"
        "    ldr\tr0, [sp, #76]\t@ 0x4c\n"
        "    cmp\tr2, r0\n"
        "    bne .Ljp_00005F9E\n"
        "    adds\tr5, r3, #0\n"
        "    ldr\tr0, [sp, #60]\t@ 0x3c\n"
        "    cmp\tr0, #1\n"
        "    bne .Ljp_00005FD4\n"
        "    cmp\tr5, #0\n"
        "    beq .Ljp_00005FD0\n"
        "    adds\tr0, r5, #0\n"
        "    mov\tr1, r9\n"
        "    ldmia\tr1!, {r2, r3, r4}\n"
        "    stmia\tr0!, {r2, r3, r4}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".Ljp_00005FD0:\n"
        "    adds\tr5, #16\n"
        "    b .Ljp_00005FF6\n"
        ".Ljp_00005FD4:\n"
        "    adds\tr3, r0, #0\n"
        "    adds\tr2, r5, #0\n"
        "    cmp\tr3, #0\n"
        "    beq .Ljp_00005FF4\n"
        ".Ljp_00005FDC:\n"
        "    cmp\tr2, #0\n"
        "    beq .Ljp_00005FEC\n"
        "    adds\tr0, r2, #0\n"
        "    mov\tr1, r9\n"
        "    ldmia\tr1!, {r4, r5, r7}\n"
        "    stmia\tr0!, {r4, r5, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".Ljp_00005FEC:\n"
        "    subs\tr3, #1\n"
        "    adds\tr2, #16\n"
        "    cmp\tr3, #0\n"
        "    bne .Ljp_00005FDC\n"
        ".Ljp_00005FF4:\n"
        "    adds\tr5, r2, #0\n"
        ".Ljp_00005FF6:\n"
        "    ldr\tr2, [r6, #4]\n"
        "    ldr\tr0, [r6, #0]\n"
        "    adds\tr1, r0, #0\n"
        "    cmp\tr0, r2\n"
        "    beq .Ljp_00006006\n"
        ".Ljp_00006000:\n"
        "    adds\tr1, #16\n"
        "    cmp\tr1, r2\n"
        "    bne .Ljp_00006000\n"
        ".Ljp_00006006:\n"
        "    cmp\tr0, #0\n"
        "    beq .Ljp_0000600E\n"
        "    bl free\n"
        ".Ljp_0000600E:\n"
        "    ldr\tr0, [sp, #80]\t@ 0x50\n"
        "    add\tr0, r8\n"
        "    ldr\tr7, [sp, #80]\t@ 0x50\n"
        "    str\tr7, [r6, #0]\n"
        "    str\tr5, [r6, #4]\n"
        "    str\tr0, [r6, #12]\n"
        ".Ljp_0000601A:\n"
        "    ldr r0, .Ljp_00006070\n"
        "    add\tr0, sl\n"
        "    ldr\tr0, [r0, #0]\n"
        "    mov\tr9, r0\n"
        "    mov\tr0, sl\n"
        "    bl GetHardwareCoreState\n"
        "    mov\tr8, r0\n"
        "    mov\tr0, sl\n"
        "    bl GetHardwareSpriteBuffer\n"
        "    adds\tr6, r0, #0\n"
        "    mov\tr0, sl\n"
        "    bl GetHardwareDisplayState\n"
        "    adds\tr5, r0, #0\n"
        "    mov\tr0, sl\n"
        "    bl GetHardwareCommandList\n"
        "    adds\tr4, r0, #0\n"
        "    mov\tr0, sl\n"
        "    bl GetHardwareInterruptList\n"
        "    ldr r1, .Ljp_00006074\n"
        "    add\tr1, sl\n"
        "    str\tr4, [sp, #0]\n"
        "    str\tr0, [sp, #4]\n"
        "    str\tr1, [sp, #8]\n"
        "    mov\tr0, r9\n"
        "    mov\tr1, r8\n"
        "    adds\tr2, r6, #0\n"
        "    adds\tr3, r5, #0\n"
        "    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot\n"
        "    add\tsp, #84\t@ 0x54\n"
        "    pop\t{r3, r4, r5}\n"
        "    mov\tr8, r3\n"
        "    mov\tr9, r4\n"
        "    mov\tsl, r5\n"
        "    pop\t{r4, r5, r6, r7}\n"
        "    pop\t{r0}\n"
        "    bx\tr0\n"
        "    .align 2, 0\n"
        ".Ljp_00006070: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_UI_OFFSET) ")\n"
        ".Ljp_00006074: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_MUSIC_OFFSET) ")\n"
#else
#if defined(REGION_DE)
        ".LNewGameDE_08005CEC:\n"
        "    push\t{r4, r5, r6, r7, lr}\n"
        "    mov\tr7, sl\n"
        "    mov\tr6, r9\n"
        "    mov\tr5, r8\n"
        "    push\t{r5, r6, r7}\n"
        "    sub\tsp, #84\n"
        "    mov\tsl, r0\n"
        "    ldr\tr0, .LNewGameDE_08005ED4\n"
        "    ldr\tr0, [r0, #0]\n"
        "    ldr\tr1, .LNewGameDE_08005ED8\n"
        "    ldr\tr2, .LNewGameDE_08005EDC\n"
        "    ldr\tr2, [r2, #0]\n"
        "    bl\tCopyHardwareDma3\n"
        "    ldr\tr0, .LNewGameDE_08005EE0\n"
        "    ldr\tr0, [r0, #0]\n"
        "    movs\tr1, #(BG_PALETTE >> 19)\n"
        "    lsls\tr1, r1, #19\n"
        "    movs\tr2, #" STRINGIFY(UI_SHARED_PALETTE_BYTES) "\n"
        "    bl\tCopyHardwareDma3\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareDisplayState\n"
        ".LNewGameDE_08005D1C:\n"
        "    add\tr1, sp, #12\n"
        "    movs\tr3, #((LCD_OBJ_MAPPING_1D | LCD_BG0_ENABLE | LCD_BG1_ENABLE | LCD_BG2_ENABLE | LCD_OBJ_ENABLE) >> 5)\n"
        "    lsls\tr3, r3, #5\n"
        "    adds\tr2, r3, #0\n"
        "    strh\tr2, [r1, #0]\n"
        "    movs\tr4, #0\n"
        "    strh\tr2, [r0, #0]\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareDisplayState\n"
        ".LNewGameDE_08005D30:\n"
        "    add\tr2, sp, #12\n"
        "    ldr\tr5, .LNewGameDE_08005EE4\n"
        "    adds\tr1, r5, #0\n"
        "    strh\tr1, [r2, #0]\n"
        "    strh\tr1, [r0, #10]\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareDisplayState\n"
        "    add\tr2, sp, #12\n"
        "    ldr\tr7, .LNewGameDE_08005EE8\n"
        "    adds\tr1, r7, #0\n"
        "    strh\tr1, [r2, #0]\n"
        "    strh\tr1, [r0, #12]\n"
        "    ldr\tr0, .LNewGameDE_08005EEC\n"
        "    movs\tr1, #20\n"
        "    str\tr1, [sp, #0]\n"
        "    movs\tr1, #155\n"
        "    lsls\tr1, r1, #2\n"
        "    str\tr1, [sp, #4]\n"
        "    str\tr4, [sp, #8]\n"
        "    movs\tr1, #0\n"
        "    movs\tr2, #0\n"
        "    movs\tr3, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    bl\tDrawUiTextWindowBorder\n"
        "    movs\tr0, #1\n"
        "    negs\tr0, r0\n"
        "    ldr\tr4, .LNewGameDE_08005EF0\n"
        "    movs\tr2, #(BG_SCREEN_SIZE >> 4)\n"
        "    lsls\tr2, r2, #4\n"
        "    adds\tr1, r4, #0\n"
        "    bl\tFillHardwareDma3\n"
        "    movs\tr1, #0\n"
        "    add\tr0, sp, #32\n"
        "    mov\tr8, r0\n"
        "    add\tr2, sp, #36\n"
        "    mov\tr9, r2\n"
        "    mov\tr3, sp\n"
        "    adds\tr3, #16\n"
        "    str\tr3, [sp, #64]\n"
        "    mov\tr5, sp\n"
        "    adds\tr5, #48\n"
        "    str\tr5, [sp, #68]\n"
        "    mov\tr7, sl\n"
        "    adds\tr7, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
        "    ldr\tr0, .LNewGameDE_08005EF4\n"
        "    add\tr0, sl\n"
        "    str\tr0, [sp, #72]\n"
        "    @ DE uses cleared tile 28 of buffer 0, after the Name label.\n"
        "    movs\tr6, #28\n"
        ".LNewGameDE_08005D94:\n"
        "    movs\tr3, #0\n"
        "    lsls\tr2, r1, #6\n"
        "    adds\tr5, r1, #1\n"
        "    adds\tr0, r2, r4\n"
        ".LNewGameDE_08005D9C:\n"
        "    strh\tr6, [r0, #0]\n"
        "    adds\tr0, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #29\n"
        "    bls.n\t.LNewGameDE_08005D9C\n"
        "    adds\tr1, r5, #0\n"
        "    cmp\tr1, #19\n"
        "    bls.n\t.LNewGameDE_08005D94\n"
        "    movs\tr3, #10\n"
        "    ldr\tr2, .LNewGameDE_08005EF8\n"
        "    ldr\tr1, .LNewGameDE_08005EFC\n"
        ".LNewGameDE_08005DB2:\n"
        "    strh\tr3, [r1, #0]\n"
        "    adds\tr0, r3, #0\n"
        "    adds\tr0, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    strh\tr0, [r2, #0]\n"
        "    adds\tr2, #2\n"
        "    adds\tr1, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #15\n"
        "    bls.n\t.LNewGameDE_08005DB2\n"
        ".LNewGameDE_08005DC4:\n"
        "    movs\tr3, #3\n"
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255
        "    movs r1, #(((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ") >> 1)\n"
        "    lsls r1, r1, #1\n"
#else
        "    ldr r1, .Lname_input_map_de_7\n"
#endif
        "\n"
        "    adds\tr5, r1, #0\n"
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255
        "    movs r2, #(((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ") >> 1)\n"
        "    lsls r2, r2, #1\n"
#else
        "    ldr r2, .Lname_input_map_de_8\n"
#endif
        "\n"
        "    adds\tr4, r2, #0\n"
        "    ldr\tr2, .LNewGameDE_08005F00\n"
        "    ldr\tr1, .LNewGameDE_08005F04\n"
        ".LNewGameDE_08005DD6:\n"
        "    adds\tr0, r3, r5\n"
        "    strh\tr0, [r1, #0]\n"
        "    adds\tr0, r3, r4\n"
        "    strh\tr0, [r2, #0]\n"
        "    adds\tr2, #2\n"
        "    adds\tr1, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #26\n"
        "    bls.n\t.LNewGameDE_08005DD6\n"
        "    movs\tr1, #4\n"
        "    ldr\tr4, .LNewGameDE_08005EF0\n"
        ".LNewGameDE_08005DEC:\n"
        "    movs\tr3, #0\n"
        "    lsls\tr2, r1, #6\n"
        "    adds\tr5, r1, #1\n"
        "    subs\tr1, #2\n"
#if (NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1))
        "    lsls\tr0, r1, #4\n"
        "    subs\tr0, r0, r1\n"
        "    lsls\tr1, r0, #1\n"
#else
        "    ldr r0, .Lname_input_map_de_row_width\n"
        "    muls r1, r0\n"
#endif
        "    adds\tr2, r2, r4\n"
        ".LNewGameDE_08005DFC:\n"
        "    adds\tr0, r1, r3\n"
        "    strh\tr0, [r2, #0]\n"
        "    adds\tr2, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #29\n"
        "    bls.n\t.LNewGameDE_08005DFC\n"
        "    adds\tr1, r5, #0\n"
        "    cmp\tr1, #(4 + " STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " - 1)\n"
        "    bls.n\t.LNewGameDE_08005DEC\n"
        "    movs\tr3, #18\n"
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 3) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 2) <= 255
        "    movs r4, #((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ") >> 2)\n"
        "    lsls r4, r4, #2\n"
#else
        "    ldr r4, .Lname_input_map_de_9\n"
#endif
        "\n"
        "    adds\tr5, r4, #0\n"
        "    ldr\tr0, .LNewGameDE_08005F08\n"
        "    adds\tr4, r0, #0\n"
        "    ldr\tr2, .LNewGameDE_08005F0C\n"
        "    ldr\tr1, .LNewGameDE_08005F10\n"
        ".LNewGameDE_08005E1E:\n"
        "    adds\tr0, r3, r5\n"
        "    strh\tr0, [r1, #0]\n"
        "    adds\tr0, r3, r4\n"
        "    strh\tr0, [r2, #0]\n"
        "    adds\tr2, #2\n"
        "    adds\tr1, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #29\n"
        "    bls.n\t.LNewGameDE_08005E1E\n"
#if ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) >> 7) <= 255
        "    movs r0, #((" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) ") >> 7)\n"
        "    lsls r0, r0, #7\n"
#else
        "    ldr r0, .Lname_input_de_screen_11\n"
#endif
        "\n"
        "    add\tr0, sl\n"
        "    ldr\tr0, [r0, #0]\n"
        "    cmp\tr0, #0\n"
        "    beq.n\t.LNewGameDE_08005E5E\n"
        "    movs\tr3, #1\n"
        "    ldr\tr1, .LNewGameDE_08005F14\n"
        "    adds\tr5, r1, #0\n"
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) >> 2) <= 255
        "    movs r2, #(((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " + 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_WIDTH) " - 1) >> 2)\n"
        "    lsls r2, r2, #2\n"
#else
        "    ldr r2, .Lname_input_map_de_10\n"
#endif
        "\n"
        "    adds\tr4, r2, #0\n"
        "    ldr\tr2, .LNewGameDE_08005F18\n"
        "    ldr\tr1, .LNewGameDE_08005F1C\n"
        ".LNewGameDE_08005E4C:\n"
        "    adds\tr0, r3, r5\n"
        "    strh\tr0, [r1, #0]\n"
        "    adds\tr0, r3, r4\n"
        "    strh\tr0, [r2, #0]\n"
        "    adds\tr2, #2\n"
        "    adds\tr1, #2\n"
        "    adds\tr3, #1\n"
        "    cmp\tr3, #(1 + " STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_WIDTH) " - 1)\n"
        "    bls.n\t.LNewGameDE_08005E4C\n"
        ".LNewGameDE_08005E5E:\n"
        "    ldr\tr1, .LNewGameDE_08005F20\n"
        "    movs\tr0, #0\n"
        "    movs\tr2, #32\n"
        "    bl\tFillHardwareDma3\n"
        "    movs\tr4, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    movs\tr5, #2\n"
        "    add\tr0, sp, #32\n"
        "    strh\tr4, [r0, #0]\n"
        "    mov\tr3, r8\n"
        "    strh\tr5, [r3, #2]\n"
        "    ldr\tr0, [sp, #32]\n"
        "    adds\tr1, r7, #0\n"
        "    movs\tr2, #0\n"
        "    bl\tClear2DGfxBuffer\n"
        "    ldr\tr1, .LNewGameDE_08005F24\n"
        "    add\tr0, sp, #36\n"
        "    strh\tr4, [r0, #0]\n"
        "    mov\tr4, r9\n"
        "    strh\tr5, [r4, #2]\n"
        "    ldr\tr0, [sp, #36]\n"
        "    str\tr1, [sp, #0]\n"
        "    adds\tr1, r7, #0\n"
        "    movs\tr2, #88\n"
        "    movs\tr3, #0\n"
        "    bl\tDrawStringTo2DGfxBuffer\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareDmaQueue\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r3, r3, #3\n"
#else
        "    ldr r3, .Lname_input_de_screen_13\n"
#endif
        "\n"
        "    adds\tr6, r0, #0\n"
        "    add\tr0, sp, #16\n"
        "    adds\tr1, r7, #0\n"
        "    movs\tr2, #(MEM_VRAM >> 19)\n"
        "    lsls\tr2, r2, #19\n"
        "    bl\t__21DmaTransferDescriptorPCvPvUi\n"
        "    ldr\tr5, [sp, #64]\n"
        "    mov\tr8, r5\n"
        "    ldr\tr1, [r6, #4]\n"
        "    ldr\tr0, [r6, #12]\n"
        "    cmp\tr1, r0\n"
        "    beq.n\t.LNewGameDE_08005F28\n"
        "    cmp\tr1, #0\n"
        "    beq.n\t.LNewGameDE_08005ECA\n"
        "    adds\tr0, r1, #0\n"
        "    mov\tr1, r8\n"
        "    ldmia\tr1!, {r2, r3, r7}\n"
        "    stmia\tr0!, {r2, r3, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_08005ECA:\n"
        "    ldr\tr0, [r6, #4]\n"
        "    adds\tr0, #16\n"
        "    str\tr0, [r6, #4]\n"
        "    b.n\t.LNewGameDE_08005FEE\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) >> 7) <= 255)
        ".Lname_input_de_screen_11: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
        ".Lname_input_de_screen_13: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255)
        ".Lname_input_map_de_7: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ")\n"
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255)
        ".Lname_input_map_de_8: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 3) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 2) <= 255)
        ".Lname_input_map_de_9: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ")\n"
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) >> 2) <= 255)
        ".Lname_input_map_de_10: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " + 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_WIDTH) " - 1)\n"
#endif
#if !((NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1)))
        ".Lname_input_map_de_row_width: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ")\n"
#endif
        ".LNewGameDE_08005ED4: .word gUiSharedTiles\n"
        ".LNewGameDE_08005ED8: .word (MEM_VRAM + 0x4D80)\n"
        ".LNewGameDE_08005EDC: .word gUiSharedTileByteCount\n"
        ".LNewGameDE_08005EE0: .word gUiSharedPalette\n"
        ".LNewGameDE_08005EE4: .word (BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        ".LNewGameDE_08005EE8: .word (BG_PRIO_2 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        ".LNewGameDE_08005EEC: .word (MEM_VRAM + 31 * BG_SCREEN_SIZE)\n"
        ".LNewGameDE_08005EF0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE)\n"
        ".LNewGameDE_08005EF4: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PROMPT_TILES_OFFSET) ")\n"
        ".LNewGameDE_08005EF8: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x94)\n"
        ".LNewGameDE_08005EFC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x54)\n"
        ".LNewGameDE_08005F00: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x4C6)\n"
        ".LNewGameDE_08005F04: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x486)\n"
        ".LNewGameDE_08005F08: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ")\n"
        ".LNewGameDE_08005F0C: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0xA4)\n"
        ".LNewGameDE_08005F10: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x64)\n"
        ".LNewGameDE_08005F14: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " + 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " - 1)\n"
        ".LNewGameDE_08005F18: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x82)\n"
        ".LNewGameDE_08005F1C: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x42)\n"
        ".LNewGameDE_08005F20: .word (MEM_VRAM + 0xFFC000)\n"
        ".LNewGameDE_08005F24: .word gText_NewGameNameEntry_NameLabel\n"
        ".LNewGameDE_08005F28:\n"
        "    str\tr1, [sp, #76]\n"
        "    movs\tr0, #1\n"
        "    str\tr0, [sp, #44]\n"
        "    ldr\tr0, [r6, #0]\n"
        "    adds\tr4, r1, #0\n"
        "    subs\tr0, r4, r0\n"
        "    asrs\tr4, r0, #4\n"
        "    str\tr4, [sp, #40]\n"
        "    add\tr1, sp, #44\n"
        "    add\tr0, sp, #40\n"
        "    cmp\tr4, #1\n"
        "    bcs.n\t.LNewGameDE_08005F42\n"
        "    adds\tr0, r1, #0\n"
        ".LNewGameDE_08005F42:\n"
        "    ldr\tr0, [r0, #0]\n"
        "    adds\tr0, r4, r0\n"
        "    cmp\tr0, #0\n"
        "    beq.n\t.LNewGameDE_08005F60\n"
        "    lsls\tr4, r0, #4\n"
        "    adds\tr0, r4, #0\n"
        "    bl\tmalloc\n"
        "    mov\tr9, r4\n"
        "    cmp\tr0, #0\n"
        "    bne.n\t.LNewGameDE_08005F64\n"
        "    mov\tr0, r9\n"
        "    bl\tRetryMemoryAllocation\n"
        "    b.n\t.LNewGameDE_08005F64\n"
        ".LNewGameDE_08005F60:\n"
        "    movs\tr0, #0\n"
        "    mov\tr9, r0\n"
        ".LNewGameDE_08005F64:\n"
        "    adds\tr5, r0, #0\n"
        "    str\tr5, [sp, #80]\n"
        "    ldr\tr2, [r6, #0]\n"
        "    adds\tr3, r5, #0\n"
        "    ldr\tr5, [sp, #76]\n"
        "    cmp\tr2, r5\n"
        "    beq.n\t.LNewGameDE_08005F8C\n"
        ".LNewGameDE_08005F72:\n"
        "    cmp\tr3, #0\n"
        "    beq.n\t.LNewGameDE_08005F82\n"
        "    adds\tr0, r3, #0\n"
        "    adds\tr1, r2, #0\n"
        "    ldmia\tr1!, {r4, r5, r7}\n"
        "    stmia\tr0!, {r4, r5, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_08005F82:\n"
        "    adds\tr2, #16\n"
        "    adds\tr3, #16\n"
        "    ldr\tr7, [sp, #76]\n"
        "    cmp\tr2, r7\n"
        "    bne.n\t.LNewGameDE_08005F72\n"
        ".LNewGameDE_08005F8C:\n"
        "    adds\tr5, r3, #0\n"
        "    ldr\tr0, [sp, #44]\n"
        "    cmp\tr0, #1\n"
        "    bne.n\t.LNewGameDE_08005FA8\n"
        "    cmp\tr5, #0\n"
        "    beq.n\t.LNewGameDE_08005FA4\n"
        "    adds\tr0, r5, #0\n"
        "    mov\tr1, r8\n"
        "    ldmia\tr1!, {r2, r3, r4}\n"
        "    stmia\tr0!, {r2, r3, r4}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_08005FA4:\n"
        "    adds\tr5, #16\n"
        "    b.n\t.LNewGameDE_08005FCA\n"
        ".LNewGameDE_08005FA8:\n"
        "    adds\tr3, r0, #0\n"
        "    adds\tr2, r5, #0\n"
        "    cmp\tr3, #0\n"
        "    beq.n\t.LNewGameDE_08005FC8\n"
        ".LNewGameDE_08005FB0:\n"
        "    cmp\tr2, #0\n"
        "    beq.n\t.LNewGameDE_08005FC0\n"
        "    adds\tr0, r2, #0\n"
        "    mov\tr1, r8\n"
        "    ldmia\tr1!, {r4, r5, r7}\n"
        "    stmia\tr0!, {r4, r5, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_08005FC0:\n"
        "    subs\tr3, #1\n"
        "    adds\tr2, #16\n"
        "    cmp\tr3, #0\n"
        "    bne.n\t.LNewGameDE_08005FB0\n"
        ".LNewGameDE_08005FC8:\n"
        "    adds\tr5, r2, #0\n"
        ".LNewGameDE_08005FCA:\n"
        "    ldr\tr2, [r6, #4]\n"
        "    ldr\tr0, [r6, #0]\n"
        "    adds\tr1, r0, #0\n"
        "    cmp\tr0, r2\n"
        "    beq.n\t.LNewGameDE_08005FDA\n"
        ".LNewGameDE_08005FD4:\n"
        "    adds\tr1, #16\n"
        "    cmp\tr1, r2\n"
        "    bne.n\t.LNewGameDE_08005FD4\n"
        ".LNewGameDE_08005FDA:\n"
        "    cmp\tr0, #0\n"
        "    beq.n\t.LNewGameDE_08005FE2\n"
        "    bl\tfree\n"
        ".LNewGameDE_08005FE2:\n"
        "    ldr\tr0, [sp, #80]\n"
        "    add\tr0, r9\n"
        "    ldr\tr7, [sp, #80]\n"
        "    str\tr7, [r6, #0]\n"
        "    str\tr5, [r6, #4]\n"
        "    str\tr0, [r6, #12]\n"
        ".LNewGameDE_08005FEE:\n"
        "    ldr\tr1, .LNewGameDE_08006088\n"
        "    add\tr1, sl\n"
        "    movs\tr0, #0\n"
        "    str\tr0, [r1, #0]\n"
        "    ldr\tr0, .LNewGameDE_0800608C\n"
        "    add\tr0, sl\n"
        "    movs\tr1, #1\n"
        "    mov\tr8, r1\n"
        "    mov\tr2, r8\n"
        "    strb\tr2, [r0, #0]\n"
        "    mov\tr0, sl\n"
        "    bl\tRenderNameInputKeyboard\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r7, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r7, r7, #3\n"
#else
        "    ldr r7, .Lname_input_de_screen_14\n"
#endif
        "    movs r5, #" STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_WIDTH) "\n"
        "    movs r6, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) "\n"
        "    add\tr0, sp, #48\n"
        "    strh\tr5, [r0, #0]\n"
        "    ldr\tr3, [sp, #68]\n"
        "    strh\tr6, [r3, #2]\n"
        "    ldr\tr0, [sp, #48]\n"
        "    ldr\tr4, [sp, #72]\n"
        "    adds\tr1, r4, #0\n"
        "    movs\tr2, #0\n"
        "    bl\tClear2DGfxBuffer\n"
#if ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) >> 7) <= 255
        "    movs r0, #((" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) ") >> 7)\n"
        "    lsls r0, r0, #7\n"
#else
        "    ldr r0, .Lname_input_de_screen_12\n"
#endif
        "\n"
        "    add\tr0, sl\n"
        "    ldr\tr1, [r0, #0]\n"
        "    cmp\tr1, #0\n"
        "    beq.n\t.LNewGameDE_08006044\n"
        "    add\tr0, sp, #52\n"
        "    strh\tr5, [r0, #0]\n"
        "    strh\tr6, [r0, #2]\n"
        "    ldr\tr0, [sp, #52]\n"
        "    str\tr1, [sp, #0]\n"
        "    adds\tr1, r4, #0\n"
        "    movs\tr2, #0\n"
        "    movs\tr3, #0\n"
        "    bl\tDrawStringTo2DGfxBuffer\n"
        ".LNewGameDE_08006044:\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareDmaQueue\n"
#if ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 3) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 2) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) ") >> 2)\n"
        "    lsls r3, r3, #2\n"
#else
        "    ldr r3, .Lname_input_de_screen_15\n"
#endif
        "\n"
        "    adds\tr6, r0, #0\n"
#if (NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) == (((1 << 2) + 1) * (1 << 1))
        "    lsls\tr2, r7, #2\n"
        "    adds\tr2, r7, r2\n"
        "    lsls\tr2, r2, #1\n"
#else
        "    ldr r2, .Lname_input_de_screen_16\n"
#endif
        "    movs\tr0, #(MEM_VRAM >> 19)\n"
        "    lsls\tr0, r0, #19\n"
        "    adds\tr2, r2, r0\n"
        "    add\tr0, sp, #12\n"
        "    ldr\tr1, [sp, #72]\n"
        "    bl\t__21DmaTransferDescriptorPCvPvUi\n"
        "    add\tr4, sp, #12\n"
        "    mov\tr9, r4\n"
        "    ldr\tr1, [r6, #4]\n"
        "    ldr\tr0, [r6, #12]\n"
        "    cmp\tr1, r0\n"
        "    beq.n\t.LNewGameDE_08006090\n"
        "    cmp\tr1, #0\n"
        "    beq.n\t.LNewGameDE_08006080\n"
        "    adds\tr0, r1, #0\n"
        "    add\tr1, sp, #12\n"
        "    ldmia\tr1!, {r2, r5, r7}\n"
        "    stmia\tr0!, {r2, r5, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_08006080:\n"
        "    ldr\tr0, [r6, #4]\n"
        "    adds\tr0, #16\n"
        "    str\tr0, [r6, #4]\n"
        "    b.n\t.LNewGameDE_08006156\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) >> 7) <= 255)
        ".Lname_input_de_screen_12: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
        ".Lname_input_de_screen_14: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 3) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 2) <= 255)
        ".Lname_input_de_screen_15: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) ")\n"
#endif
#if !((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) == (((1 << 2) + 1) * (1 << 1)))
        ".Lname_input_de_screen_16: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " + 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
        ".LNewGameDE_08006088: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ")\n"
        ".LNewGameDE_0800608C: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET) ")\n"
        ".LNewGameDE_08006090:\n"
        "    str\tr1, [sp, #76]\n"
        "    mov\tr3, r8\n"
        "    str\tr3, [sp, #60]\n"
        "    ldr\tr0, [r6, #0]\n"
        "    adds\tr4, r1, #0\n"
        "    subs\tr0, r4, r0\n"
        "    asrs\tr4, r0, #4\n"
        "    str\tr4, [sp, #56]\n"
        "    add\tr1, sp, #60\n"
        "    add\tr0, sp, #56\n"
        "    cmp\tr4, #1\n"
        "    bcs.n\t.LNewGameDE_080060AA\n"
        "    adds\tr0, r1, #0\n"
        ".LNewGameDE_080060AA:\n"
        "    ldr\tr0, [r0, #0]\n"
        "    adds\tr0, r4, r0\n"
        "    cmp\tr0, #0\n"
        "    beq.n\t.LNewGameDE_080060C8\n"
        "    lsls\tr4, r0, #4\n"
        "    adds\tr0, r4, #0\n"
        "    bl\tmalloc\n"
        "    mov\tr8, r4\n"
        "    cmp\tr0, #0\n"
        "    bne.n\t.LNewGameDE_080060CC\n"
        "    mov\tr0, r8\n"
        "    bl\tRetryMemoryAllocation\n"
        "    b.n\t.LNewGameDE_080060CC\n"
        ".LNewGameDE_080060C8:\n"
        "    movs\tr0, #0\n"
        "    mov\tr8, r0\n"
        ".LNewGameDE_080060CC:\n"
        "    adds\tr5, r0, #0\n"
        "    str\tr5, [sp, #80]\n"
        "    ldr\tr2, [r6, #0]\n"
        "    adds\tr3, r5, #0\n"
        "    ldr\tr5, [sp, #76]\n"
        "    cmp\tr2, r5\n"
        "    beq.n\t.LNewGameDE_080060F4\n"
        ".LNewGameDE_080060DA:\n"
        "    cmp\tr3, #0\n"
        "    beq.n\t.LNewGameDE_080060EA\n"
        "    adds\tr0, r3, #0\n"
        "    adds\tr1, r2, #0\n"
        "    ldmia\tr1!, {r4, r5, r7}\n"
        "    stmia\tr0!, {r4, r5, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_080060EA:\n"
        "    adds\tr2, #16\n"
        "    adds\tr3, #16\n"
        "    ldr\tr7, [sp, #76]\n"
        "    cmp\tr2, r7\n"
        "    bne.n\t.LNewGameDE_080060DA\n"
        ".LNewGameDE_080060F4:\n"
        "    adds\tr5, r3, #0\n"
        "    ldr\tr0, [sp, #60]\n"
        "    cmp\tr0, #1\n"
        "    bne.n\t.LNewGameDE_08006110\n"
        "    cmp\tr5, #0\n"
        "    beq.n\t.LNewGameDE_0800610C\n"
        "    adds\tr0, r5, #0\n"
        "    mov\tr1, r9\n"
        "    ldmia\tr1!, {r2, r3, r4}\n"
        "    stmia\tr0!, {r2, r3, r4}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_0800610C:\n"
        "    adds\tr5, #16\n"
        "    b.n\t.LNewGameDE_08006132\n"
        ".LNewGameDE_08006110:\n"
        "    adds\tr3, r0, #0\n"
        "    adds\tr2, r5, #0\n"
        "    cmp\tr3, #0\n"
        "    beq.n\t.LNewGameDE_08006130\n"
        ".LNewGameDE_08006118:\n"
        "    cmp\tr2, #0\n"
        "    beq.n\t.LNewGameDE_08006128\n"
        "    adds\tr0, r2, #0\n"
        "    mov\tr1, r9\n"
        "    ldmia\tr1!, {r4, r5, r7}\n"
        "    stmia\tr0!, {r4, r5, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_08006128:\n"
        "    subs\tr3, #1\n"
        "    adds\tr2, #16\n"
        "    cmp\tr3, #0\n"
        "    bne.n\t.LNewGameDE_08006118\n"
        ".LNewGameDE_08006130:\n"
        "    adds\tr5, r2, #0\n"
        ".LNewGameDE_08006132:\n"
        "    ldr\tr2, [r6, #4]\n"
        "    ldr\tr0, [r6, #0]\n"
        "    adds\tr1, r0, #0\n"
        "    cmp\tr0, r2\n"
        "    beq.n\t.LNewGameDE_08006142\n"
        ".LNewGameDE_0800613C:\n"
        "    adds\tr1, #16\n"
        "    cmp\tr1, r2\n"
        "    bne.n\t.LNewGameDE_0800613C\n"
        ".LNewGameDE_08006142:\n"
        "    cmp\tr0, #0\n"
        "    beq.n\t.LNewGameDE_0800614A\n"
        "    bl\tfree\n"
        ".LNewGameDE_0800614A:\n"
        "    ldr\tr0, [sp, #80]\n"
        "    add\tr0, r8\n"
        "    ldr\tr7, [sp, #80]\n"
        "    str\tr7, [r6, #0]\n"
        "    str\tr5, [r6, #4]\n"
        "    str\tr0, [r6, #12]\n"
        ".LNewGameDE_08006156:\n"
        "    ldr\tr0, .LNewGameDE_080061AC\n"
        "    add\tr0, sl\n"
        "    ldr\tr0, [r0, #0]\n"
        "    mov\tr9, r0\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareCoreState\n"
        "    mov\tr8, r0\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareSpriteBuffer\n"
        "    adds\tr6, r0, #0\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareDisplayState\n"
        "    adds\tr5, r0, #0\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareCommandList\n"
        "    adds\tr4, r0, #0\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareInterruptList\n"
        "    ldr\tr1, .LNewGameDE_080061B0\n"
        "    add\tr1, sl\n"
        "    str\tr4, [sp, #0]\n"
        "    str\tr0, [sp, #4]\n"
        "    str\tr1, [sp, #8]\n"
        "    mov\tr0, r9\n"
        "    mov\tr1, r8\n"
        "    adds\tr2, r6, #0\n"
        "    adds\tr3, r5, #0\n"
        "    bl\tUpdate__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot\n"
        "    add\tsp, #84\n"
        "    pop\t{r3, r4, r5}\n"
        "    mov\tr8, r3\n"
        "    mov\tr9, r4\n"
        "    mov\tsl, r5\n"
        "    pop\t{r4, r5, r6, r7}\n"
        "    pop\t{r0}\n"
        "    bx\tr0\n"
        "    .align 2, 0\n"
        ".LNewGameDE_080061AC: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_UI_OFFSET) ")\n"
        ".LNewGameDE_080061B0: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_MUSIC_OFFSET) ")\n"
        "\n"
#else
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x54\n"
        "    mov sl, r0\n"
        "    ldr r0, .L08005EC8 @ =gUiSharedTiles\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L08005ECC\n"
        "    ldr r2, .L08005ED0 @ =gUiSharedTileByteCount\n"
        "    ldr r2, [r2]\n"
        "    bl CopyHardwareDma3\n"
        "    ldr r0, .L08005ED4 @ =gUiSharedPalette\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #(BG_PALETTE >> 19)\n"
        "    lsls r1, r1, #0x13\n"
        "    movs r2, #" STRINGIFY(UI_SHARED_PALETTE_BYTES) "\n"
        "    bl CopyHardwareDma3\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDisplayState\n"
        "    add r1, sp, #0xc\n"
        "    movs r3, #((LCD_OBJ_MAPPING_1D | LCD_BG0_ENABLE | LCD_BG1_ENABLE | LCD_BG2_ENABLE | LCD_OBJ_ENABLE) >> 5)\n"
        "    lsls r3, r3, #5\n"
        "    adds r2, r3, #0\n"
        "    strh r2, [r1]\n"
        "    movs r4, #0\n"
        "    strh r2, [r0]\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDisplayState\n"
        "    add r2, sp, #0xc\n"
        "    ldr r5, .L08005ED8 @ =0x00001841\n"
        "    adds r1, r5, #0\n"
        "    strh r1, [r2]\n"
        "    strh r1, [r0, #0xa]\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDisplayState\n"
        "    add r2, sp, #0xc\n"
        "    ldr r7, .L08005EDC @ =0x00001F02\n"
        "    adds r1, r7, #0\n"
        "    strh r1, [r2]\n"
        "    strh r1, [r0, #0xc]\n"
        "    ldr r0, .L08005EE0\n"
        "    movs r1, #0x14\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x96\n"
        "    lsls r1, r1, #2\n"
        "    str r1, [sp, #4]\n"
        "    str r4, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    bl DrawUiTextWindowBorder\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    ldr r4, .L08005EE4\n"
        "    movs r2, #(BG_SCREEN_SIZE >> 4)\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r4, #0\n"
        "    bl FillHardwareDma3\n"
        "    movs r1, #0\n"
        "    add r0, sp, #0x20\n"
        "    mov r8, r0\n"
        "    add r2, sp, #0x24\n"
        "    mov sb, r2\n"
        "    mov r3, sp\n"
        "    adds r3, #0x10\n"
        "    str r3, [sp, #0x44]\n"
        "    mov r5, sp\n"
        "    adds r5, #0x30\n"
        "    str r5, [sp, #0x48]\n"
        "    mov r7, sl\n"
        "    adds r7, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
        "    ldr r0, .L08005EE8\n"
        "    add r0, sl\n"
        "    str r0, [sp, #0x40]\n"
        "    @ Blank tile from the cleared tail of the final character row.\n"
#if ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) & 1) == 0 && ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) >> 1) <= 255
        "    movs r2, #((" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " + 28) >> 1)\n"
        "    lsls r2, r2, #1\n"
#else
        "    ldr r2, .Lname_input_overseas_screen_blank_tile\n"
#endif
        "    adds r6, r2, #0\n"
        ".L08005D88:\n"
        "    movs r3, #0\n"
        "    lsls r2, r1, #6\n"
        "    adds r5, r1, #1\n"
        "    adds r0, r2, r4\n"
        ".L08005D90:\n"
        "    strh r6, [r0]\n"
        "    adds r0, #2\n"
        "    adds r3, #1\n"
        "    cmp r3, #0x1d\n"
        "    bls .L08005D90\n"
        "    adds r1, r5, #0\n"
        "    cmp r1, #0x13\n"
        "    bls .L08005D88\n"
        "    movs r3, #0xa\n"
        "    ldr r2, .L08005EEC\n"
        "    ldr r1, .L08005EF0\n"
        ".L08005DA6:\n"
        "    strh r3, [r1]\n"
        "    adds r0, r3, #0\n"
        "    adds r0, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    strh r0, [r2]\n"
        "    adds r2, #2\n"
        "    adds r1, #2\n"
        "    adds r3, #1\n"
        "    cmp r3, #0xf\n"
        "    bls .L08005DA6\n"
        "    movs r3, #3\n"
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255
        "    movs r4, #(((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ") >> 1)\n"
        "    lsls r4, r4, #1\n"
#else
        "    ldr r4, .Lname_input_map_overseas_12\n"
#endif
        "\n"
        "    adds r5, r4, #0\n"
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255
        "    movs r0, #(((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ") >> 1)\n"
        "    lsls r0, r0, #1\n"
#else
        "    ldr r0, .Lname_input_map_overseas_13\n"
#endif
        "\n"
        "    adds r4, r0, #0\n"
        "    ldr r2, .L08005EF4\n"
        "    ldr r1, .L08005EF8\n"
        ".L08005DCA:\n"
        "    adds r0, r3, r5\n"
        "    strh r0, [r1]\n"
        "    adds r0, r3, r4\n"
        "    strh r0, [r2]\n"
        "    adds r2, #2\n"
        "    adds r1, #2\n"
        "    adds r3, #1\n"
        "    cmp r3, #0x1a\n"
        "    bls .L08005DCA\n"
        "    movs r1, #4\n"
        "    ldr r4, .L08005EE4\n"
        ".L08005DE0:\n"
        "    movs r3, #0\n"
        "    lsls r2, r1, #6\n"
        "    adds r5, r1, #1\n"
        "    subs r1, #2\n"
#if (NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1))
        "    lsls r0, r1, #4\n"
        "    subs r0, r0, r1\n"
        "    lsls r1, r0, #1\n"
#else
        "    ldr r0, .Lname_input_map_overseas_row_width\n"
        "    muls r1, r0\n"
#endif
        "    adds r2, r2, r4\n"
        ".L08005DF0:\n"
        "    adds r0, r1, r3\n"
        "    strh r0, [r2]\n"
        "    adds r2, #2\n"
        "    adds r3, #1\n"
        "    cmp r3, #0x1d\n"
        "    bls .L08005DF0\n"
        "    adds r1, r5, #0\n"
        "    cmp r1, #(4 + " STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " - 1)\n"
        "    bls .L08005DE0\n"
        "    movs r3, #0x12\n"
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255
        "    movs r1, #((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ") >> 1)\n"
        "    lsls r1, r1, #1\n"
#else
        "    ldr r1, .Lname_input_map_overseas_14\n"
#endif
        "\n"
        "    adds r5, r1, #0\n"
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255
        "    movs r2, #((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ") >> 1)\n"
        "    lsls r2, r2, #1\n"
#else
        "    ldr r2, .Lname_input_map_overseas_15\n"
#endif
        "\n"
        "    adds r4, r2, #0\n"
        "    ldr r2, .L08005EFC\n"
        "    ldr r1, .L08005F00\n"
        ".L08005E14:\n"
        "    adds r0, r3, r5\n"
        "    strh r0, [r1]\n"
        "    adds r0, r3, r4\n"
        "    strh r0, [r2]\n"
        "    adds r2, #2\n"
        "    adds r1, #2\n"
        "    adds r3, #1\n"
        "    cmp r3, #0x1d\n"
        "    bls .L08005E14\n"
        "    ldr r0, .L08005F04\n"
        "    add r0, sl\n"
        "    ldr r0, [r0]\n"
        "    cmp r0, #0\n"
        "    beq .L08005E52\n"
        "    movs r3, #1\n"
        "    ldr r4, .L08005F08 @ =0x0000021B\n"
        "    adds r5, r4, #0\n"
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) >> 2) <= 255
        "    movs r0, #(((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " + 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_WIDTH) " - 1) >> 2)\n"
        "    lsls r0, r0, #2\n"
#else
        "    ldr r0, .Lname_input_map_overseas_16\n"
#endif
        "\n"
        "    adds r4, r0, #0\n"
        "    ldr r2, .L08005F0C\n"
        "    ldr r1, .L08005F10\n"
        ".L08005E40:\n"
        "    adds r0, r3, r5\n"
        "    strh r0, [r1]\n"
        "    adds r0, r3, r4\n"
        "    strh r0, [r2]\n"
        "    adds r2, #2\n"
        "    adds r1, #2\n"
        "    adds r3, #1\n"
        "    cmp r3, #(1 + " STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_WIDTH) " - 1)\n"
        "    bls .L08005E40\n"
        ".L08005E52:\n"
        "    ldr r1, .L08005F14\n"
        "    movs r0, #0\n"
        "    movs r2, #0x20\n"
        "    bl FillHardwareDma3\n"
        "    movs r4, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    movs r5, #2\n"
        "    add r0, sp, #0x20\n"
        "    strh r4, [r0]\n"
        "    mov r1, r8\n"
        "    strh r5, [r1, #2]\n"
        "    ldr r0, [sp, #0x20]\n"
        "    adds r1, r7, #0\n"
        "    movs r2, #0\n"
        "    bl Clear2DGfxBuffer\n"
        "    ldr r1, .L08005F18 @ =gText_NewGameNameEntry_NameLabel\n"
        "    add r0, sp, #0x24\n"
        "    strh r4, [r0]\n"
        "    mov r2, sb\n"
        "    strh r5, [r2, #2]\n"
        "    ldr r0, [sp, #0x24]\n"
        "    str r1, [sp]\n"
        "    adds r1, r7, #0\n"
        "    movs r2, #0x58\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDmaQueue\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r3, r3, #3\n"
#else
        "    ldr r3, .Lname_input_overseas_screen_19\n"
#endif
        "\n"
        "    adds r6, r0, #0\n"
        "    add r0, sp, #0x10\n"
        "    adds r1, r7, #0\n"
        "    movs r2, #(MEM_VRAM >> 19)\n"
        "    lsls r2, r2, #0x13\n"
        "    bl __21DmaTransferDescriptorPCvPvUi\n"
        "    ldr r3, [sp, #0x44]\n"
        "    mov r8, r3\n"
        "    ldr r1, [r6, #4]\n"
        "    ldr r0, [r6, #0xc]\n"
        "    cmp r1, r0\n"
        "    beq .L08005F1C\n"
        "    cmp r1, #0\n"
        "    beq .L08005EBE\n"
        "    adds r0, r1, #0\n"
        "    mov r1, r8\n"
        "    ldm r1!, {r4, r5, r7}\n"
        "    stm r0!, {r4, r5, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08005EBE:\n"
        "    ldr r0, [r6, #4]\n"
        "    adds r0, #0x10\n"
        "    str r0, [r6, #4]\n"
        "    b .L08005FE0\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
        ".Lname_input_overseas_screen_19: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !(((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) & 1) == 0 && ((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH + 28) >> 1) <= 255)
        ".Lname_input_overseas_screen_blank_tile: .word (" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " + 28)\n"
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255)
        ".Lname_input_map_overseas_12: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ")\n"
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255)
        ".Lname_input_map_overseas_13: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT) >> 1) <= 255)
        ".Lname_input_map_overseas_14: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) & 1) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_TILE_WIDTH) >> 1) <= 255)
        ".Lname_input_map_overseas_15: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ")\n"
#endif
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) & 3) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT + 1) * NEW_GAME_NAME_INPUT_TILE_WIDTH * NEW_GAME_NAME_INPUT_TILE_HEIGHT + NEW_GAME_NAME_INPUT_PROMPT_WIDTH - 1) >> 2) <= 255)
        ".Lname_input_map_overseas_16: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " + 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_WIDTH) " - 1)\n"
#endif
#if !((NEW_GAME_NAME_INPUT_TILE_WIDTH) == (((1 << 4) - 1) * (1 << 1)))
        ".Lname_input_map_overseas_row_width: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) ")\n"
#endif
        ".L08005EC8: .word gUiSharedTiles\n"
        ".L08005ECC: .word (MEM_VRAM + 0x4B00)\n"
        ".L08005ED0: .word gUiSharedTileByteCount\n"
        ".L08005ED4: .word gUiSharedPalette\n"
        ".L08005ED8: .word (BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        ".L08005EDC: .word (BG_PRIO_2 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        ".L08005EE0: .word (MEM_VRAM + 31 * BG_SCREEN_SIZE)\n"
        ".L08005EE4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE)\n"
        ".L08005EE8: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PROMPT_TILES_OFFSET) ")\n"
        ".L08005EEC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x94)\n"
        ".L08005EF0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x54)\n"
        ".L08005EF4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x486)\n"
        ".L08005EF8: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x446)\n"
        ".L08005EFC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0xA4)\n"
        ".L08005F00: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x64)\n"
        ".L08005F04: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) ")\n"
        ".L08005F08: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " + 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) " - 1)\n"
        ".L08005F0C: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x82)\n"
        ".L08005F10: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x42)\n"
        ".L08005F14: .word (MEM_VRAM + 0xFFC000)\n"
        ".L08005F18: .word gText_NewGameNameEntry_NameLabel\n"
        ".L08005F1C:\n"
        "    str r1, [sp, #0x4c]\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0x2c]\n"
        "    ldr r0, [r6]\n"
        "    subs r0, r1, r0\n"
        "    asrs r4, r0, #4\n"
        "    str r4, [sp, #0x28]\n"
        "    add r1, sp, #0x2c\n"
        "    add r0, sp, #0x28\n"
        "    cmp r4, #1\n"
        "    bhs .L08005F34\n"
        "    adds r0, r1, #0\n"
        ".L08005F34:\n"
        "    ldr r0, [r0]\n"
        "    adds r0, r4, r0\n"
        "    cmp r0, #0\n"
        "    beq .L08005F52\n"
        "    lsls r4, r0, #4\n"
        "    adds r0, r4, #0\n"
        "    bl malloc\n"
        "    mov sb, r4\n"
        "    cmp r0, #0\n"
        "    bne .L08005F56\n"
        "    mov r0, sb\n"
        "    bl RetryMemoryAllocation\n"
        "    b .L08005F56\n"
        ".L08005F52:\n"
        "    movs r0, #0\n"
        "    mov sb, r0\n"
        ".L08005F56:\n"
        "    adds r5, r0, #0\n"
        "    str r5, [sp, #0x50]\n"
        "    ldr r2, [r6]\n"
        "    adds r3, r5, #0\n"
        "    ldr r4, [sp, #0x4c]\n"
        "    cmp r2, r4\n"
        "    beq .L08005F7E\n"
        ".L08005F64:\n"
        "    cmp r3, #0\n"
        "    beq .L08005F74\n"
        "    adds r0, r3, #0\n"
        "    adds r1, r2, #0\n"
        "    ldm r1!, {r4, r5, r7}\n"
        "    stm r0!, {r4, r5, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08005F74:\n"
        "    adds r2, #0x10\n"
        "    adds r3, #0x10\n"
        "    ldr r5, [sp, #0x4c]\n"
        "    cmp r2, r5\n"
        "    bne .L08005F64\n"
        ".L08005F7E:\n"
        "    adds r5, r3, #0\n"
        "    ldr r0, [sp, #0x2c]\n"
        "    cmp r0, #1\n"
        "    bne .L08005F9A\n"
        "    cmp r5, #0\n"
        "    beq .L08005F96\n"
        "    adds r0, r5, #0\n"
        "    mov r1, r8\n"
        "    ldm r1!, {r2, r3, r7}\n"
        "    stm r0!, {r2, r3, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08005F96:\n"
        "    adds r5, #0x10\n"
        "    b .L08005FBC\n"
        ".L08005F9A:\n"
        "    adds r3, r0, #0\n"
        "    adds r2, r5, #0\n"
        "    cmp r3, #0\n"
        "    beq .L08005FBA\n"
        ".L08005FA2:\n"
        "    cmp r2, #0\n"
        "    beq .L08005FB2\n"
        "    adds r0, r2, #0\n"
        "    mov r1, r8\n"
        "    ldm r1!, {r4, r5, r7}\n"
        "    stm r0!, {r4, r5, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08005FB2:\n"
        "    subs r3, #1\n"
        "    adds r2, #0x10\n"
        "    cmp r3, #0\n"
        "    bne .L08005FA2\n"
        ".L08005FBA:\n"
        "    adds r5, r2, #0\n"
        ".L08005FBC:\n"
        "    ldr r2, [r6, #4]\n"
        "    ldr r0, [r6]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, r2\n"
        "    beq .L08005FCC\n"
        ".L08005FC6:\n"
        "    adds r1, #0x10\n"
        "    cmp r1, r2\n"
        "    bne .L08005FC6\n"
        ".L08005FCC:\n"
        "    cmp r0, #0\n"
        "    beq .L08005FD4\n"
        "    bl free\n"
        ".L08005FD4:\n"
        "    ldr r0, [sp, #0x50]\n"
        "    add r0, sb\n"
        "    ldr r1, [sp, #0x50]\n"
        "    str r1, [r6]\n"
        "    str r5, [r6, #4]\n"
        "    str r0, [r6, #0xc]\n"
        ".L08005FE0:\n"
#if ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255
        "    movs r1, #((" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ") >> 7)\n"
        "    lsls r1, r1, #7\n"
#else
        "    ldr r1, .Lname_input_overseas_screen_17\n"
#endif
        "\n"
        "    add r1, sl\n"
        "    movs r0, #0\n"
        "    str r0, [r1]\n"
        "    ldr r0, .L08006074\n"
        "    add r0, sl\n"
        "    movs r2, #1\n"
        "    mov r8, r2\n"
        "    mov r3, r8\n"
        "    strb r3, [r0]\n"
        "    mov r0, sl\n"
        "    bl RenderNameInputKeyboard\n"
        "    movs r5, #" STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_WIDTH) "\n"
        "    movs r6, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_HEIGHT) "\n"
        "    add r0, sp, #0x30\n"
        "    strh r5, [r0]\n"
        "    ldr r4, [sp, #0x48]\n"
        "    strh r6, [r4, #2]\n"
        "    ldr r0, [sp, #0x30]\n"
        "    ldr r4, [sp, #0x40]\n"
        "    adds r1, r4, #0\n"
        "    movs r2, #0\n"
        "    bl Clear2DGfxBuffer\n"
        "    ldr r0, .L08006078\n"
        "    add r0, sl\n"
        "    ldr r1, [r0]\n"
        "    cmp r1, #0\n"
        "    beq .L08006032\n"
        "    add r0, sp, #0x34\n"
        "    strh r5, [r0]\n"
        "    strh r6, [r0, #2]\n"
        "    ldr r0, [sp, #0x34]\n"
        "    str r1, [sp]\n"
        "    adds r1, r4, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        ".L08006032:\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDmaQueue\n"
#if ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 3) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 2) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) ") >> 2)\n"
        "    lsls r3, r3, #2\n"
#else
        "    ldr r3, .Lname_input_overseas_screen_20\n"
#endif
        "\n"
        "    adds r6, r0, #0\n"
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
        "    movs r2, #((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 6)\n"
        "    lsls r2, r2, #3\n"
        "    lsls r2, r2, #3\n"
#else
        "    ldr r2, .Lname_input_overseas_screen_18\n"
#endif
        "\n"
        "    ldr r5, .L0800607C\n"
        "    adds r2, r2, r5\n"
        "    add r0, sp, #0xc\n"
        "    ldr r1, [sp, #0x40]\n"
        "    bl __21DmaTransferDescriptorPCvPvUi\n"
        "    add r7, sp, #0xc\n"
        "    mov sb, r7\n"
        "    ldr r1, [r6, #4]\n"
        "    ldr r0, [r6, #0xc]\n"
        "    cmp r1, r0\n"
        "    beq .L08006080\n"
        "    cmp r1, #0\n"
        "    beq .L0800606C\n"
        "    adds r0, r1, #0\n"
        "    add r1, sp, #0xc\n"
        "    ldm r1!, {r2, r3, r4}\n"
        "    stm r0!, {r2, r3, r4}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L0800606C:\n"
        "    ldr r0, [r6, #4]\n"
        "    adds r0, #0x10\n"
        "    str r0, [r6, #4]\n"
        "    b .L08006142\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255)
        ".Lname_input_overseas_screen_17: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
        ".Lname_input_overseas_screen_18: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) & 3) == 0 && ((NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) >> 2) <= 255)
        ".Lname_input_overseas_screen_20: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_PROMPT_TILE_BYTES) ")\n"
#endif
        ".L08006074: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET) ")\n"
        ".L08006078: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PROMPT_OFFSET) ")\n"
        ".L0800607C: .word (MEM_VRAM + " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
        ".L08006080:\n"
        "    str r1, [sp, #0x4c]\n"
        "    mov r5, r8\n"
        "    str r5, [sp, #0x3c]\n"
        "    ldr r0, [r6]\n"
        "    adds r7, r1, #0\n"
        "    subs r0, r7, r0\n"
        "    asrs r4, r0, #4\n"
        "    str r4, [sp, #0x38]\n"
        "    add r1, sp, #0x3c\n"
        "    add r0, sp, #0x38\n"
        "    cmp r4, #1\n"
        "    bhs .L0800609A\n"
        "    adds r0, r1, #0\n"
        ".L0800609A:\n"
        "    ldr r0, [r0]\n"
        "    adds r0, r4, r0\n"
        "    cmp r0, #0\n"
        "    beq .L080060B8\n"
        "    lsls r4, r0, #4\n"
        "    adds r0, r4, #0\n"
        "    bl malloc\n"
        "    mov r8, r4\n"
        "    cmp r0, #0\n"
        "    bne .L080060BC\n"
        "    mov r0, r8\n"
        "    bl RetryMemoryAllocation\n"
        "    b .L080060BC\n"
        ".L080060B8:\n"
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        ".L080060BC:\n"
        "    adds r5, r0, #0\n"
        "    str r5, [sp, #0x50]\n"
        "    ldr r2, [r6]\n"
        "    adds r3, r5, #0\n"
        "    b .L080060DA\n"
        ".L080060C6:\n"
        "    cmp r3, #0\n"
        "    beq .L080060D6\n"
        "    adds r0, r3, #0\n"
        "    adds r1, r2, #0\n"
        "    ldm r1!, {r4, r5, r7}\n"
        "    stm r0!, {r4, r5, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L080060D6:\n"
        "    adds r2, #0x10\n"
        "    adds r3, #0x10\n"
        ".L080060DA:\n"
        "    ldr r0, [sp, #0x4c]\n"
        "    cmp r2, r0\n"
        "    bne .L080060C6\n"
        "    adds r5, r3, #0\n"
        "    ldr r0, [sp, #0x3c]\n"
        "    cmp r0, #1\n"
        "    bne .L080060FC\n"
        "    cmp r5, #0\n"
        "    beq .L080060F8\n"
        "    adds r0, r5, #0\n"
        "    mov r1, sb\n"
        "    ldm r1!, {r2, r3, r4}\n"
        "    stm r0!, {r2, r3, r4}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L080060F8:\n"
        "    adds r5, #0x10\n"
        "    b .L0800611E\n"
        ".L080060FC:\n"
        "    adds r3, r0, #0\n"
        "    adds r2, r5, #0\n"
        "    cmp r3, #0\n"
        "    beq .L0800611C\n"
        ".L08006104:\n"
        "    cmp r2, #0\n"
        "    beq .L08006114\n"
        "    adds r0, r2, #0\n"
        "    mov r1, sb\n"
        "    ldm r1!, {r4, r5, r7}\n"
        "    stm r0!, {r4, r5, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08006114:\n"
        "    subs r3, #1\n"
        "    adds r2, #0x10\n"
        "    cmp r3, #0\n"
        "    bne .L08006104\n"
        ".L0800611C:\n"
        "    adds r5, r2, #0\n"
        ".L0800611E:\n"
        "    ldr r2, [r6, #4]\n"
        "    ldr r0, [r6]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, r2\n"
        "    beq .L0800612E\n"
        ".L08006128:\n"
        "    adds r1, #0x10\n"
        "    cmp r1, r2\n"
        "    bne .L08006128\n"
        ".L0800612E:\n"
        "    cmp r0, #0\n"
        "    beq .L08006136\n"
        "    bl free\n"
        ".L08006136:\n"
        "    ldr r0, [sp, #0x50]\n"
        "    add r0, r8\n"
        "    ldr r7, [sp, #0x50]\n"
        "    str r7, [r6]\n"
        "    str r5, [r6, #4]\n"
        "    str r0, [r6, #0xc]\n"
        ".L08006142:\n"
        "    ldr r0, .L08006198\n"
        "    add r0, sl\n"
        "    ldr r0, [r0]\n"
        "    mov sb, r0\n"
        "    mov r0, sl\n"
        "    bl GetHardwareCoreState\n"
        "    mov r8, r0\n"
        "    mov r0, sl\n"
        "    bl GetHardwareSpriteBuffer\n"
        "    adds r6, r0, #0\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDisplayState\n"
        "    adds r5, r0, #0\n"
        "    mov r0, sl\n"
        "    bl GetHardwareCommandList\n"
        "    adds r4, r0, #0\n"
        "    mov r0, sl\n"
        "    bl GetHardwareInterruptList\n"
        "    ldr r1, .L0800619C\n"
        "    add r1, sl\n"
        "    str r4, [sp]\n"
        "    str r0, [sp, #4]\n"
        "    str r1, [sp, #8]\n"
        "    mov r0, sb\n"
        "    mov r1, r8\n"
        "    adds r2, r6, #0\n"
        "    adds r3, r5, #0\n"
        "    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot\n"
        "    add sp, #0x54\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .align 2, 0\n"
        ".L08006198: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_UI_OFFSET) ")\n"
        ".L0800619C: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_MUSIC_OFFSET) ")\n"
#endif
#endif
    );
}

void InitializeNameInputCursorSprites(NewGameNameInputCore * core, u32 tile_index)
{
    FillHardwareDma3(0, &core->sprites[0].attributes,
        sizeof(core->sprites[0].attributes));
    FillHardwareDma3(0, &core->sprites[1].attributes,
        sizeof(core->sprites[1].attributes));
#if defined(REGION_JP)
    core->sprites[0].attributes.size = ST_OAM_SIZE_1;
    core->sprites[1].attributes.size = ST_OAM_SIZE_1;
#else
    core->sprites[0].attributes.size = ST_OAM_SIZE_0;
    core->sprites[1].attributes.size = ST_OAM_SIZE_0;
    core->sprites[1].attributes.shape = ST_OAM_V_RECTANGLE;
#endif
    core->sprites[0].attributes.object_mode = ST_OAM_OBJ_BLEND;
    core->sprites[1].attributes.object_mode = ST_OAM_OBJ_BLEND;
    core->sprites[1].attributes.tile_index =
        core->sprites[0].attributes.tile_index = tile_index;
    core->sprites[0].attributes.palette_bank = 4;
    core->sprites[1].attributes.palette_bank = 4;

    u8 row = 0;
    u32 const offset = tile_index * TILE_SIZE_4BPP;
    for (; row <= 7; ++row) {
        u32 const pixel_offset = offset + row * 4;
        *reinterpret_cast<u32 *>(OBJ_VRAM0 + pixel_offset) = 0x88888888;
        *reinterpret_cast<u32 *>(OBJ_VRAM0 + 1 * TILE_SIZE_4BPP + pixel_offset) = 0x88888888;
        *reinterpret_cast<u32 *>(OBJ_VRAM0 + 2 * TILE_SIZE_4BPP + pixel_offset) = 0x88888888;
        *reinterpret_cast<u32 *>(OBJ_VRAM0 + 3 * TILE_SIZE_4BPP + pixel_offset) = 0x88888888;
        *reinterpret_cast<u32 *>(OBJ_VRAM0 + 4 * TILE_SIZE_4BPP + pixel_offset) = 0x88888888;
        *reinterpret_cast<u32 *>(OBJ_VRAM0 + 5 * TILE_SIZE_4BPP + pixel_offset) = 0x88888888;
        *reinterpret_cast<u32 *>(OBJ_VRAM0 + 6 * TILE_SIZE_4BPP + pixel_offset) = 0x88888888;
        *reinterpret_cast<u32 *>(OBJ_VRAM0 + 7 * TILE_SIZE_4BPP + pixel_offset) = 0x88888888;
    }
    reinterpret_cast<u16 *>(OBJ_PLTT)[4 * 16 + 8] = RGB(31, 19, 0);
    core->sprites[1].attributes.x = 144;
    core->sprites[1].attributes.y = 8;
    core->sprites[0].attributes.x = 0;
    core->sprites[0].attributes.y = 32;
    core->sprites[1].attributes.priority = 2;
    core->sprites[0].attributes.priority = 2;
}

void ResetNameInputCore(NewGameNameInputCore * core)
{
    core->unk_after_keyboard_redraw[1] = 0;
    core->unk_after_keyboard_redraw[0] = 0;
    core->finished = 0;
    core->keyboard_redraw_pending = 0;
    core->sprites[0].unk_00[1] = 0;
    core->sprites[0].unk_00[0] = 0;
    core->keyboard_page = 0;
    core->sprites[1].unk_00[0] = 0;
    core->unk_463c = 0;
}

// The retail text rasterizers inline this descriptor-append path. Keep
// its real allocation, copy construction and destruction order here.
// Other queue consumers retain their separately recovered inline body.
static inline void * AllocateTextDmaBytes(u32 bytes)
{
    void * memory = malloc(bytes);
    if (memory == nullptr)
        return RetryMemoryAllocation(bytes);
    return memory;
}

static inline DmaTransferDescriptor * AllocateTextDmaDescriptors(u32 count)
{
    return count != 0 ? static_cast<DmaTransferDescriptor *>(
        AllocateTextDmaBytes(count * sizeof(DmaTransferDescriptor))) : nullptr;
}

static inline DmaTransferDescriptor * CopyTextDmaDescriptors(DmaTransferDescriptor const * first,
    DmaTransferDescriptor const * last, DmaTransferDescriptor * result)
{
    DmaTransferDescriptor * current = result;
    for (; first != last; ++first, ++current)
        if (current != nullptr)
            new (current) DmaTransferDescriptor(*first);
    return current;
}

static inline DmaTransferDescriptor * FillTextDmaDescriptors(DmaTransferDescriptor * first,
    u32 count, DmaTransferDescriptor const & value)
{
    DmaTransferDescriptor * current = first;
    for (; count != 0; --count, ++current)
        if (current != nullptr)
            new (current) DmaTransferDescriptor(value);
    return current;
}

static inline void GrowTextDmaQueue(HardwareDmaQueue * queue,
    DmaTransferDescriptor * old_end, u32 count, DmaTransferDescriptor const & value)
{
    u32 old_size = old_end - queue->first;
    u32 new_size = old_size + max_ref_inl(old_size, count);
    DmaTransferDescriptor * replacement = AllocateTextDmaDescriptors(new_size);
    DmaTransferDescriptor * end = replacement;
    end = CopyTextDmaDescriptors(queue->first, old_end, end);
    if (count == 1) {
        if (end != nullptr)
            new (end) DmaTransferDescriptor(value);
        ++end;
    } else {
        end = FillTextDmaDescriptors(end, count, value);
    }
    typedef __type_traits<DmaTransferDescriptor>::has_trivial_destructor TrivialDestructor;
    DmaTransferDescriptor * old_last = queue->last;
    DmaTransferDescriptor * const old_first = queue->first;
    destroy_range_inl(old_first, old_last, TrivialDestructor());
    if (old_first != nullptr)
        free(old_first);
    DmaTransferDescriptor * capacity_end = replacement + new_size;
    queue->first = replacement;
    queue->last = end;
    queue->allocation.end = capacity_end;
}

static inline void AppendTextDmaTransfer(HardwareDmaQueue * queue,
    DmaTransferDescriptor const & value)
{
    if (queue->last != queue->allocation.end) {
        if (queue->last != nullptr)
            new (queue->last) DmaTransferDescriptor(value);
        ++queue->last;
    } else {
        GrowTextDmaQueue(queue, queue->last, 1, value);
    }
}

// Refresh the editable name and queue its full two-tile-high buffer.
void RenderNameInputName(NewGameNameInputCore * core)
{
    u32 bytes = sizeof(core->name_buffer.tiles);
    NewGameNameInputKeyboardBuffer & buffer = core->name_buffer;
    buffer.ClearRect(0, 0, 96, 16, 0);
    buffer.DrawString(144, 0, core->name);
    HardwareDmaQueue * queue = GetHardwareDmaQueue(reinterpret_cast<void * const *>(core));
    DmaTransferDescriptor transfer(buffer.tiles,
        reinterpret_cast<void *>(VRAM + bytes * ARRAY_COUNT(core->keyboard_buffers)), bytes);
    AppendTextDmaTransfer(queue, transfer);
}

NAKED void RenderNameInputKeyboard(NewGameNameInputCore * core)
{
    asm_unified(
#if defined(REGION_JP)
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, r9\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x5c\n"
        "    mov sl, r0\n"
        "    ldr r0, .Ljp_080064A4\n"
        "    add r0, sl\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .Ljp_080063D6\n"
        "    b .Ljp_0800671E\n"
        ".Ljp_080063D6:\n"
        "    movs r0, #1\n"
        "    mov r8, r0\n"
        "    mov r1, sp\n"
        "    adds r1, #0x14\n"
        "    str r1, [sp, #0x40]\n"
        "    mov r2, sp\n"
        "    adds r2, #0x18\n"
        "    str r2, [sp, #0x44]\n"
        "    mov r3, sp\n"
        "    adds r3, #0x24\n"
        "    str r3, [sp, #0x48]\n"
        "    ldr r4, .Ljp_080064A8\n"
        "    add r4, sl\n"
        "    str r4, [sp, #0x50]\n"
        "    mov r6, sp\n"
        "    adds r6, #4\n"
        "    str r6, [sp, #0x3c]\n"
        ".Ljp_080063F8:\n"
        "    mov r7, r8\n"
#if (NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2))
        "    lsls r4, r7, #4\n"
        "    subs r4, r4, r7\n"
        "    lsls r4, r4, #5\n"
        "    add r4, r8\n"
        "    lsls r4, r4, #2\n"
#else
        "    ldr r4, .Lname_input_jp_keyboard_8\n"
        "    muls r4, r7\n"
#endif
        "    mov r0, sl\n"
        "    adds r1, r4, r0\n"
        "    add r0, sp, #0x14\n"
        "    movs r2, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    strh r2, [r0]\n"
        "    movs r6, #2\n"
        "    ldr r3, [sp, #0x40]\n"
        "    strh r6, [r3, #2]\n"
        "    ldr r0, [sp, #0x14]\n"
        "    adds r1, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
        "    movs r2, #0\n"
        "    bl Clear2DGfxBuffer\n"
        "    ldr r0, .Ljp_080064AC\n"
        "    add r0, sl\n"
        "    ldr r3, [r0]\n"
        "    mov r7, sl\n"
        "    adds r1, r4, r7\n"
        "    mov r0, r8\n"
#if (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1)
        "    lsls r2, r0, #5\n"
        "    subs r2, r2, r0\n"
#else
        "    ldr r2, .Lname_input_jp_keyboard_9\n"
        "    muls r2, r0\n"
#endif
#if (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH) <= 255
        "    movs r0, #(" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) " * " STRINGIFY(NEW_GAME_NAME_ENTRY_ROW_WIDTH) ")\n"
#else
        "    ldr r0, .Lname_input_jp_keyboard_10\n"
#endif
        "\n"
        "    muls r0, r3\n"
        "    adds r2, r2, r0\n"
        "    ldr r0, .Ljp_080064B0\n"
        "    adds r2, r2, r0\n"
        "    add r0, sp, #0x18\n"
        "    movs r3, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    strh r3, [r0]\n"
        "    ldr r7, [sp, #0x44]\n"
        "    strh r6, [r7, #2]\n"
        "    ldr r0, [sp, #0x18]\n"
        "    adds r1, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
        "    str r2, [sp]\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDmaQueue\n"
        "    add r4, sl\n"
        "    adds r4, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r1, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r1, r1, #3\n"
#else
        "    ldr r1, .Lname_input_jp_keyboard_6\n"
#endif
        "\n"
        "    mov r2, r8\n"
        "    muls r2, r1\n"
        "    adds r5, r0, #0\n"
        "    movs r3, #(MEM_VRAM >> 19)\n"
        "    lsls r3, r3, #0x13\n"
        "    adds r2, r2, r3\n"
        "    add r0, sp, #4\n"
        "    adds r1, r4, #0\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r3, r3, #3\n"
#else
        "    ldr r3, .Lname_input_jp_keyboard_6\n"
#endif
        "\n"
        "    bl __21DmaTransferDescriptorPCvPvUi\n"
        "    ldr r1, [r5, #4]\n"
        "    ldr r0, [r5, #0xc]\n"
        "    cmp r1, r0\n"
        "    beq .Ljp_080064B4\n"
        "    cmp r1, #0\n"
        "    beq .Ljp_0800648E\n"
        "    adds r0, r1, #0\n"
        "    add r1, sp, #4\n"
        "    ldmia r1!, {r4, r6, r7}\n"
        "    stmia r0!, {r4, r6, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_0800648E:\n"
        "    ldr r0, [r5, #4]\n"
        "    adds r0, #0x10\n"
        "    str r0, [r5, #4]\n"
        "    movs r0, #1\n"
        "    add r8, r0\n"
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
        "    movs r1, #((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 6)\n"
        "    lsls r1, r1, #3\n"
        "    lsls r1, r1, #3\n"
#else
        "    ldr r1, .Lname_input_jp_keyboard_4\n"
#endif
        "\n"
        "    str r1, [sp, #0x4c]\n"
        "    b .Ljp_08006586\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
        ".Lname_input_jp_keyboard_4: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
        ".Lname_input_jp_keyboard_6: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !((NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2)))
        ".Lname_input_jp_keyboard_8: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_BUFFER_BYTES) ")\n"
#endif
#if !((NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1))
        ".Lname_input_jp_keyboard_9: .word (" STRINGIFY(NEW_GAME_NAME_ENTRY_ROW_WIDTH) ")\n"
#endif
#if !((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH) <= 255)
        ".Lname_input_jp_keyboard_10: .word (" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) " * " STRINGIFY(NEW_GAME_NAME_ENTRY_ROW_WIDTH) ")\n"
#endif
        ".Ljp_080064A4: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET) ")\n"
        ".Ljp_080064A8: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) " + (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_BUFFER_BYTES) ")\n"
        ".Ljp_080064AC: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ")\n"
        "    @ This is the one-row-before base consumed by the keyboard-row renderer,\n"
        "    @ not an interior pointer into the confirmation text.\n"
        ".Ljp_080064B0: .word gNewGameNameEntryCharacterRows - " STRINGIFY(NEW_GAME_NAME_ENTRY_ROW_WIDTH) "\n"
        ".Ljp_080064B4:\n"
        "    str r1, [sp, #0x54]\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0x20]\n"
        "    ldr r0, [r5]\n"
        "    adds r2, r1, #0\n"
        "    subs r0, r2, r0\n"
        "    asrs r4, r0, #4\n"
        "    str r4, [sp, #0x1c]\n"
        "    add r1, sp, #0x20\n"
        "    add r0, sp, #0x1c\n"
        "    cmp r4, #1\n"
        "    bcs .Ljp_080064CE\n"
        "    adds r0, r1, #0\n"
        ".Ljp_080064CE:\n"
        "    ldr r0, [r0]\n"
        "    adds r0, r4, r0\n"
        "    cmp r0, #0\n"
        "    beq .Ljp_080064EC\n"
        "    lsls r4, r0, #4\n"
        "    adds r0, r4, #0\n"
        "    bl malloc\n"
        "    mov r9, r4\n"
        "    cmp r0, #0\n"
        "    bne .Ljp_080064F0\n"
        "    mov r0, r9\n"
        "    bl RetryMemoryAllocation\n"
        "    b .Ljp_080064F0\n"
        ".Ljp_080064EC:\n"
        "    movs r0, #0\n"
        "    mov r9, r0\n"
        ".Ljp_080064F0:\n"
        "    adds r4, r0, #0\n"
        "    str r4, [sp, #0x58]\n"
        "    ldr r2, [r5]\n"
        "    adds r3, r4, #0\n"
        "    movs r4, #1\n"
        "    add r8, r4\n"
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
        "    movs r6, #((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 6)\n"
        "    lsls r6, r6, #3\n"
        "    lsls r6, r6, #3\n"
#else
        "    ldr r6, .Lname_input_jp_keyboard_5\n"
#endif
        "\n"
        "    str r6, [sp, #0x4c]\n"
        "    ldr r7, [sp, #0x54]\n"
        "    cmp r2, r7\n"
        "    beq .Ljp_08006524\n"
        ".Ljp_0800650A:\n"
        "    cmp r3, #0\n"
        "    beq .Ljp_0800651A\n"
        "    adds r0, r3, #0\n"
        "    adds r1, r2, #0\n"
        "    ldmia r1!, {r4, r6, r7}\n"
        "    stmia r0!, {r4, r6, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_0800651A:\n"
        "    adds r2, #0x10\n"
        "    adds r3, #0x10\n"
        "    ldr r0, [sp, #0x54]\n"
        "    cmp r2, r0\n"
        "    bne .Ljp_0800650A\n"
        ".Ljp_08006524:\n"
        "    adds r4, r3, #0\n"
        "    ldr r0, [sp, #0x20]\n"
        "    cmp r0, #1\n"
        "    bne .Ljp_08006540\n"
        "    cmp r4, #0\n"
        "    beq .Ljp_0800653C\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x3c]\n"
        "    ldmia r1!, {r2, r3, r6}\n"
        "    stmia r0!, {r2, r3, r6}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_0800653C:\n"
        "    adds r4, #0x10\n"
        "    b .Ljp_08006562\n"
        ".Ljp_08006540:\n"
        "    adds r3, r0, #0\n"
        "    adds r2, r4, #0\n"
        "    cmp r3, #0\n"
        "    beq .Ljp_08006560\n"
        ".Ljp_08006548:\n"
        "    cmp r2, #0\n"
        "    beq .Ljp_08006558\n"
        "    adds r0, r2, #0\n"
        "    ldr r1, [sp, #0x3c]\n"
        "    ldmia r1!, {r4, r6, r7}\n"
        "    stmia r0!, {r4, r6, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_08006558:\n"
        "    subs r3, #1\n"
        "    adds r2, #0x10\n"
        "    cmp r3, #0\n"
        "    bne .Ljp_08006548\n"
        ".Ljp_08006560:\n"
        "    adds r4, r2, #0\n"
        ".Ljp_08006562:\n"
        "    ldr r2, [r5, #4]\n"
        "    ldr r0, [r5]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, r2\n"
        "    beq .Ljp_08006572\n"
        ".Ljp_0800656C:\n"
        "    adds r1, #0x10\n"
        "    cmp r1, r2\n"
        "    bne .Ljp_0800656C\n"
        ".Ljp_08006572:\n"
        "    cmp r0, #0\n"
        "    beq .Ljp_0800657A\n"
        "    bl free\n"
        ".Ljp_0800657A:\n"
        "    ldr r0, [sp, #0x58]\n"
        "    add r0, r9\n"
        "    ldr r7, [sp, #0x58]\n"
        "    str r7, [r5]\n"
        "    str r4, [r5, #4]\n"
        "    str r0, [r5, #0xc]\n"
        ".Ljp_08006586:\n"
        "    mov r0, r8\n"
        "    cmp r0, #" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) "\n"
        "    bhi .Ljp_0800658E\n"
        "    b .Ljp_080063F8\n"
        ".Ljp_0800658E:\n"
        "    movs r4, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    movs r5, #2\n"
        "    add r0, sp, #0x24\n"
        "    strh r4, [r0]\n"
        "    ldr r1, [sp, #0x48]\n"
        "    strh r5, [r1, #2]\n"
        "    ldr r0, [sp, #0x24]\n"
        "    ldr r1, [sp, #0x50]\n"
        "    movs r2, #0\n"
        "    bl Clear2DGfxBuffer\n"
        "    ldr r0, .Ljp_080065B8\n"
        "    add r0, sl\n"
        "    ldr r2, [r0]\n"
        "    cmp r2, #1\n"
        "    beq .Ljp_080065D4\n"
        "    cmp r2, #1\n"
        "    bgt .Ljp_080065BC\n"
        "    cmp r2, #0\n"
        "    beq .Ljp_080065C2\n"
        "    b .Ljp_08006606\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
        ".Lname_input_jp_keyboard_5: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
        ".Ljp_080065B8: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ")\n"
        ".Ljp_080065BC:\n"
        "    cmp r2, #2\n"
        "    beq .Ljp_080065F0\n"
        "    b .Ljp_08006606\n"
        ".Ljp_080065C2:\n"
        "    ldr r1, .Ljp_080065D0\n"
        "    add r0, sp, #0x28\n"
        "    strh r4, [r0]\n"
        "    strh r5, [r0, #2]\n"
        "    ldr r0, [sp, #0x28]\n"
        "    b .Ljp_080065DE\n"
        "    .align 2, 0\n"
        ".Ljp_080065D0: .word gText_NewGameNameEntry_ModeKatakana\n"
        ".Ljp_080065D4:\n"
        "    ldr r1, .Ljp_080065EC\n"
        "    add r0, sp, #0x2c\n"
        "    strh r4, [r0]\n"
        "    strh r5, [r0, #2]\n"
        "    ldr r0, [sp, #0x2c]\n"
        ".Ljp_080065DE:\n"
        "    str r1, [sp]\n"
        "    ldr r1, [sp, #0x50]\n"
        "    movs r2, #0x18\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    b .Ljp_08006606\n"
        ".Ljp_080065EC: .word gText_NewGameNameEntry_ModeSymbols\n"
        ".Ljp_080065F0:\n"
        "    ldr r1, .Ljp_0800664C\n"
        "    add r0, sp, #0x30\n"
        "    strh r4, [r0]\n"
        "    strh r2, [r0, #2]\n"
        "    ldr r0, [sp, #0x30]\n"
        "    str r1, [sp]\n"
        "    ldr r1, [sp, #0x50]\n"
        "    movs r2, #0x18\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        ".Ljp_08006606:\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDmaQueue\n"
        "    adds r5, r0, #0\n"
        "    ldr r3, [sp, #0x4c]\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r4, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r4, r4, #3\n"
#else
        "    ldr r4, .Lname_input_jp_keyboard_7\n"
#endif
        "\n"
        "    subs r2, r3, r4\n"
        "    movs r6, #(MEM_VRAM >> 19)\n"
        "    lsls r6, r6, #0x13\n"
        "    adds r2, r2, r6\n"
        "    add r0, sp, #4\n"
        "    ldr r1, [sp, #0x50]\n"
        "    adds r3, r4, #0\n"
        "    bl __21DmaTransferDescriptorPCvPvUi\n"
        "    add r7, sp, #4\n"
        "    mov r9, r7\n"
        "    ldr r1, [r5, #4]\n"
        "    ldr r0, [r5, #0xc]\n"
        "    cmp r1, r0\n"
        "    beq .Ljp_08006650\n"
        "    cmp r1, #0\n"
        "    beq .Ljp_08006642\n"
        "    adds r0, r1, #0\n"
        "    add r1, sp, #4\n"
        "    ldmia r1!, {r2, r3, r4}\n"
        "    stmia r0!, {r2, r3, r4}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_08006642:\n"
        "    ldr r0, [r5, #4]\n"
        "    adds r0, #0x10\n"
        "    str r0, [r5, #4]\n"
        "    b .Ljp_08006716\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
        ".Lname_input_jp_keyboard_7: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
        ".Ljp_0800664C: .word gText_NewGameNameEntry_ModeHiragana\n"
        ".Ljp_08006650:\n"
        "    str r1, [sp, #0x54]\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0x38]\n"
        "    ldr r0, [r5]\n"
        "    adds r6, r1, #0\n"
        "    subs r0, r6, r0\n"
        "    asrs r4, r0, #4\n"
        "    str r4, [sp, #0x34]\n"
        "    add r1, sp, #0x38\n"
        "    add r0, sp, #0x34\n"
        "    cmp r4, #1\n"
        "    bcs .Ljp_0800666A\n"
        "    adds r0, r1, #0\n"
        ".Ljp_0800666A:\n"
        "    ldr r0, [r0]\n"
        "    adds r0, r4, r0\n"
        "    cmp r0, #0\n"
        "    beq .Ljp_08006688\n"
        "    lsls r4, r0, #4\n"
        "    adds r0, r4, #0\n"
        "    bl malloc\n"
        "    mov r8, r4\n"
        "    cmp r0, #0\n"
        "    bne .Ljp_0800668C\n"
        "    mov r0, r8\n"
        "    bl RetryMemoryAllocation\n"
        "    b .Ljp_0800668C\n"
        ".Ljp_08006688:\n"
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        ".Ljp_0800668C:\n"
        "    adds r4, r0, #0\n"
        "    str r4, [sp, #0x58]\n"
        "    ldr r2, [r5]\n"
        "    adds r3, r4, #0\n"
        "    ldr r7, [sp, #0x54]\n"
        "    cmp r2, r7\n"
        "    beq .Ljp_080066B4\n"
        ".Ljp_0800669A:\n"
        "    cmp r3, #0\n"
        "    beq .Ljp_080066AA\n"
        "    adds r0, r3, #0\n"
        "    adds r1, r2, #0\n"
        "    ldmia r1!, {r4, r6, r7}\n"
        "    stmia r0!, {r4, r6, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_080066AA:\n"
        "    adds r2, #0x10\n"
        "    adds r3, #0x10\n"
        "    ldr r0, [sp, #0x54]\n"
        "    cmp r2, r0\n"
        "    bne .Ljp_0800669A\n"
        ".Ljp_080066B4:\n"
        "    adds r4, r3, #0\n"
        "    ldr r0, [sp, #0x38]\n"
        "    cmp r0, #1\n"
        "    bne .Ljp_080066D0\n"
        "    cmp r4, #0\n"
        "    beq .Ljp_080066CC\n"
        "    adds r0, r4, #0\n"
        "    mov r1, r9\n"
        "    ldmia r1!, {r2, r3, r6}\n"
        "    stmia r0!, {r2, r3, r6}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_080066CC:\n"
        "    adds r4, #0x10\n"
        "    b .Ljp_080066F2\n"
        ".Ljp_080066D0:\n"
        "    adds r3, r0, #0\n"
        "    adds r2, r4, #0\n"
        "    cmp r3, #0\n"
        "    beq .Ljp_080066F0\n"
        ".Ljp_080066D8:\n"
        "    cmp r2, #0\n"
        "    beq .Ljp_080066E8\n"
        "    adds r0, r2, #0\n"
        "    mov r1, r9\n"
        "    ldmia r1!, {r4, r6, r7}\n"
        "    stmia r0!, {r4, r6, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_080066E8:\n"
        "    subs r3, #1\n"
        "    adds r2, #0x10\n"
        "    cmp r3, #0\n"
        "    bne .Ljp_080066D8\n"
        ".Ljp_080066F0:\n"
        "    adds r4, r2, #0\n"
        ".Ljp_080066F2:\n"
        "    ldr r2, [r5, #4]\n"
        "    ldr r0, [r5]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, r2\n"
        "    beq .Ljp_08006702\n"
        ".Ljp_080066FC:\n"
        "    adds r1, #0x10\n"
        "    cmp r1, r2\n"
        "    bne .Ljp_080066FC\n"
        ".Ljp_08006702:\n"
        "    cmp r0, #0\n"
        "    beq .Ljp_0800670A\n"
        "    bl free\n"
        ".Ljp_0800670A:\n"
        "    ldr r0, [sp, #0x58]\n"
        "    add r0, r8\n"
        "    ldr r7, [sp, #0x58]\n"
        "    str r7, [r5]\n"
        "    str r4, [r5, #4]\n"
        "    str r0, [r5, #0xc]\n"
        ".Ljp_08006716:\n"
        "    ldr r1, .Ljp_08006730\n"
        "    add r1, sl\n"
        "    movs r0, #0\n"
        "    strb r0, [r1]\n"
        ".Ljp_0800671E:\n"
        "    add sp, #0x5c\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov r9, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .align 2, 0\n"
        ".Ljp_08006730: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET) ")\n"
#else
#if defined(REGION_DE)
        ".LNewGameDE_080064F8:\n"
        "    push\t{r4, r5, r6, r7, lr}\n"
        "    mov\tr7, sl\n"
        "    mov\tr6, r9\n"
        "    mov\tr5, r8\n"
        "    push\t{r5, r6, r7}\n"
        "    sub\tsp, #92\n"
        "    mov\tsl, r0\n"
        "    ldr r0, .LNewGameDE_080065E4\n"
        "    add\tr0, sl\n"
        "    ldrb\tr0, [r0, #0]\n"
        "    cmp\tr0, #0\n"
        "    bne.n\t.LNewGameDE_08006512\n"
        "    b.n\t.LNewGameDE_0800685A\n"
        ".LNewGameDE_08006512:\n"
        "    movs\tr0, #1\n"
        "    mov\tr8, r0\n"
        "    mov\tr1, sp\n"
        "    adds\tr1, #20\n"
        "    str\tr1, [sp, #64]\n"
        "    mov\tr2, sp\n"
        "    adds\tr2, #24\n"
        "    str\tr2, [sp, #68]\n"
        "    mov\tr3, sp\n"
        "    adds\tr3, #36\n"
        "    str\tr3, [sp, #72]\n"
        "    ldr r4, .LNewGameDE_080065E8\n"
        "    add\tr4, sl\n"
        "    str\tr4, [sp, #80]\n"
        "    mov\tr6, sp\n"
        "    adds\tr6, #4\n"
        "    str\tr6, [sp, #60]\n"
        ".LNewGameDE_08006534:\n"
        "    mov\tr7, r8\n"
#if (NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2))
        "    lsls\tr4, r7, #4\n"
        "    subs\tr4, r4, r7\n"
        "    lsls\tr4, r4, #5\n"
        "    add\tr4, r8\n"
        "    lsls\tr4, r4, #2\n"
#else
        "    ldr r4, .Lname_input_de_keyboard_25\n"
        "    muls r4, r7\n"
#endif
        "    mov\tr0, sl\n"
        "    adds\tr1, r4, r0\n"
        "    add\tr0, sp, #20\n"
        "    movs\tr2, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    strh\tr2, [r0, #0]\n"
        "    movs\tr6, #2\n"
        "    ldr\tr3, [sp, #64]\n"
        "    strh\tr6, [r3, #2]\n"
        "    ldr\tr0, [sp, #20]\n"
        "    adds\tr1, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
        "    movs\tr2, #0\n"
        "    bl\tClear2DGfxBuffer\n"
        "    ldr r0, .LNewGameDE_080065EC\n"
        "    add\tr0, sl\n"
        "    ldr\tr0, [r0, #0]\n"
        "    mov\tr7, sl\n"
        "    adds\tr1, r4, r7\n"
        "    mov\tr2, r8\n"
#if (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1)
        "    lsls\tr3, r2, #5\n"
        "    subs\tr3, r3, r2\n"
#else
        "    ldr r3, .Lname_input_de_keyboard_26\n"
        "    muls r3, r2\n"
#endif
#if (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) == ((1 << 3) - 1) && (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1)
        "    lsls\tr2, r0, #3\n"
        "    subs\tr2, r2, r0\n"
        "    lsls\tr0, r2, #5\n"
        "    subs\tr0, r0, r2\n"
#else
        "    ldr r2, .Lname_input_de_keyboard_27\n"
        "    muls r2, r0\n"
        "    ldr r0, .Lname_input_de_keyboard_28\n"
        "    muls r0, r2\n"
#endif
        "    adds\tr3, r3, r0\n"
        "    ldr r0, .LNewGameDE_080065F0\n"
        "    adds\tr3, r3, r0\n"
        "    add\tr0, sp, #24\n"
        "    movs\tr6, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    strh\tr6, [r0, #0]\n"
        "    movs\tr0, #2\n"
        ".LNewGameDE_08006580:\n"
        "    ldr\tr7, [sp, #68]\n"
        "    strh\tr0, [r7, #2]\n"
        "    ldr\tr0, [sp, #24]\n"
        "    adds\tr1, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
        "    str\tr3, [sp, #0]\n"
        "    movs\tr2, #0\n"
        "    movs\tr3, #0\n"
        "    bl\tDrawStringTo2DGfxBuffer\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareDmaQueue\n"
        "    add\tr4, sl\n"
        "    adds\tr4, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r1, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r1, r1, #3\n"
#else
        "    ldr r1, .Lname_input_de_keyboard_23\n"
#endif
        "\n"
        "    mov\tr2, r8\n"
        "    muls\tr2, r1\n"
        "    adds\tr5, r0, #0\n"
        "    movs\tr3, #192\n"
        ".LNewGameDE_080065A8:\n"
        "    lsls\tr3, r3, #19\n"
        "    adds\tr2, r2, r3\n"
        "    add\tr0, sp, #4\n"
        "    adds\tr1, r4, #0\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r3, r3, #3\n"
#else
        "    ldr r3, .Lname_input_de_keyboard_23\n"
#endif
        "\n"
        "    bl\t__21DmaTransferDescriptorPCvPvUi\n"
        "    ldr\tr1, [r5, #4]\n"
        "    ldr\tr0, [r5, #12]\n"
        "    cmp\tr1, r0\n"
        "    beq.n\t.LNewGameDE_080065F4\n"
        "    cmp\tr1, #0\n"
        "    beq.n\t.LNewGameDE_080065D0\n"
        "    adds\tr0, r1, #0\n"
        "    add\tr1, sp, #4\n"
        "    ldmia\tr1!, {r4, r6, r7}\n"
        "    stmia\tr0!, {r4, r6, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_080065D0:\n"
        "    ldr\tr0, [r5, #4]\n"
        "    adds\tr0, #16\n"
        "    str\tr0, [r5, #4]\n"
        "    movs\tr0, #1\n"
        "    add\tr8, r0\n"
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
        "    movs r1, #(((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 6)\n"
        "    lsls r1, r1, #3\n"
        "    lsls r1, r1, #3\n"
#else
        "    ldr r1, .Lname_input_de_keyboard_21\n"
#endif
        "\n"
        "    str\tr1, [sp, #76]\n"
        "    b.n\t.LNewGameDE_080066C6\n"
        "    .align 2, 0\n"
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
        ".Lname_input_de_keyboard_21: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
        ".Lname_input_de_keyboard_23: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !((NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2)))
        ".Lname_input_de_keyboard_25: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_BUFFER_BYTES) ")\n"
#endif
#if !((NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1))
        ".Lname_input_de_keyboard_26: .word (" STRINGIFY(NEW_GAME_NAME_ENTRY_ROW_WIDTH) ")\n"
#endif
#if !((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) == ((1 << 3) - 1) && (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1))
        ".Lname_input_de_keyboard_27: .word (" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) ")\n"
#endif
#if !((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) == ((1 << 3) - 1) && (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1))
        ".Lname_input_de_keyboard_28: .word (" STRINGIFY(NEW_GAME_NAME_ENTRY_ROW_WIDTH) ")\n"
#endif
        ".LNewGameDE_080065E4: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET) ")\n"
        ".LNewGameDE_080065E8: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) " + (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_BUFFER_BYTES) ")\n"
        ".LNewGameDE_080065EC: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ")\n"
        ".LNewGameDE_080065F0: .word gNewGameNameEntryCharacterRows - " STRINGIFY(NEW_GAME_NAME_ENTRY_ROW_WIDTH) "\n"
        ".LNewGameDE_080065F4:\n"
        "    str\tr1, [sp, #84]\n"
        "    movs\tr0, #1\n"
        "    str\tr0, [sp, #32]\n"
        "    ldr\tr0, [r5, #0]\n"
        "    adds\tr2, r1, #0\n"
        "    subs\tr0, r2, r0\n"
        "    asrs\tr4, r0, #4\n"
        "    str\tr4, [sp, #28]\n"
        "    add\tr1, sp, #32\n"
        "    add\tr0, sp, #28\n"
        "    cmp\tr4, #1\n"
        "    bcs.n\t.LNewGameDE_0800660E\n"
        "    adds\tr0, r1, #0\n"
        ".LNewGameDE_0800660E:\n"
        "    ldr\tr0, [r0, #0]\n"
        "    adds\tr0, r4, r0\n"
        "    cmp\tr0, #0\n"
        "    beq.n\t.LNewGameDE_0800662C\n"
        "    lsls\tr4, r0, #4\n"
        "    adds\tr0, r4, #0\n"
        "    bl\tmalloc\n"
        "    mov\tr9, r4\n"
        "    cmp\tr0, #0\n"
        "    bne.n\t.LNewGameDE_08006630\n"
        "    mov\tr0, r9\n"
        "    bl\tRetryMemoryAllocation\n"
        "    b.n\t.LNewGameDE_08006630\n"
        ".LNewGameDE_0800662C:\n"
        "    movs\tr0, #0\n"
        "    mov\tr9, r0\n"
        ".LNewGameDE_08006630:\n"
        "    adds\tr4, r0, #0\n"
        "    str\tr4, [sp, #88]\n"
        "    ldr\tr2, [r5, #0]\n"
        "    adds\tr3, r4, #0\n"
        "    movs\tr4, #1\n"
        "    add\tr8, r4\n"
#if (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
        "    movs r6, #(((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 6)\n"
        "    lsls r6, r6, #3\n"
        "    lsls r6, r6, #3\n"
#else
        "    ldr r6, .Lname_input_de_keyboard_22\n"
#endif
        "\n"
        "    str\tr6, [sp, #76]\n"
        "    ldr\tr7, [sp, #84]\n"
        "    cmp\tr2, r7\n"
        "    beq.n\t.LNewGameDE_08006664\n"
        ".LNewGameDE_0800664A:\n"
        "    cmp\tr3, #0\n"
        "    beq.n\t.LNewGameDE_0800665A\n"
        "    adds\tr0, r3, #0\n"
        "    adds\tr1, r2, #0\n"
        "    ldmia\tr1!, {r4, r6, r7}\n"
        "    stmia\tr0!, {r4, r6, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_0800665A:\n"
        "    adds\tr2, #16\n"
        "    adds\tr3, #16\n"
        "    ldr\tr0, [sp, #84]\n"
        "    cmp\tr2, r0\n"
        "    bne.n\t.LNewGameDE_0800664A\n"
        ".LNewGameDE_08006664:\n"
        "    adds\tr4, r3, #0\n"
        "    ldr\tr0, [sp, #32]\n"
        "    cmp\tr0, #1\n"
        "    bne.n\t.LNewGameDE_08006680\n"
        "    cmp\tr4, #0\n"
        "    beq.n\t.LNewGameDE_0800667C\n"
        "    adds\tr0, r4, #0\n"
        "    ldr\tr1, [sp, #60]\n"
        "    ldmia\tr1!, {r2, r3, r6}\n"
        "    stmia\tr0!, {r2, r3, r6}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_0800667C:\n"
        "    adds\tr4, #16\n"
        "    b.n\t.LNewGameDE_080066A2\n"
        ".LNewGameDE_08006680:\n"
        "    adds\tr3, r0, #0\n"
        "    adds\tr2, r4, #0\n"
        "    cmp\tr3, #0\n"
        "    beq.n\t.LNewGameDE_080066A0\n"
        ".LNewGameDE_08006688:\n"
        "    cmp\tr2, #0\n"
        "    beq.n\t.LNewGameDE_08006698\n"
        "    adds\tr0, r2, #0\n"
        "    ldr\tr1, [sp, #60]\n"
        "    ldmia\tr1!, {r4, r6, r7}\n"
        "    stmia\tr0!, {r4, r6, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_08006698:\n"
        "    subs\tr3, #1\n"
        "    adds\tr2, #16\n"
        "    cmp\tr3, #0\n"
        "    bne.n\t.LNewGameDE_08006688\n"
        ".LNewGameDE_080066A0:\n"
        "    adds\tr4, r2, #0\n"
        ".LNewGameDE_080066A2:\n"
        "    ldr\tr2, [r5, #4]\n"
        "    ldr\tr0, [r5, #0]\n"
        "    adds\tr1, r0, #0\n"
        "    cmp\tr0, r2\n"
        "    beq.n\t.LNewGameDE_080066B2\n"
        ".LNewGameDE_080066AC:\n"
        "    adds\tr1, #16\n"
        "    cmp\tr1, r2\n"
        "    bne.n\t.LNewGameDE_080066AC\n"
        ".LNewGameDE_080066B2:\n"
        "    cmp\tr0, #0\n"
        "    beq.n\t.LNewGameDE_080066BA\n"
        "    bl\tfree\n"
        ".LNewGameDE_080066BA:\n"
        "    ldr\tr0, [sp, #88]\n"
        "    add\tr0, r9\n"
        "    ldr\tr7, [sp, #88]\n"
        "    str\tr7, [r5, #0]\n"
        "    str\tr4, [r5, #4]\n"
        "    str\tr0, [r5, #12]\n"
        ".LNewGameDE_080066C6:\n"
        "    mov\tr0, r8\n"
        "    cmp\tr0, #" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) "\n"
        "    bhi.n\t.LNewGameDE_080066CE\n"
        "    b.n\t.LNewGameDE_08006534\n"
        ".LNewGameDE_080066CE:\n"
        "    movs\tr4, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    movs\tr5, #2\n"
        "    add\tr0, sp, #36\n"
        "    strh\tr4, [r0, #0]\n"
        "    ldr\tr1, [sp, #72]\n"
        "    strh\tr5, [r1, #2]\n"
        "    ldr\tr0, [sp, #36]\n"
        "    ldr\tr1, [sp, #80]\n"
        "    movs\tr2, #0\n"
        "    bl\tClear2DGfxBuffer\n"
        "    ldr r0, .LNewGameDE_080066F8\n"
        "    add\tr0, sl\n"
        "    ldr\tr2, [r0, #0]\n"
        "    cmp\tr2, #1\n"
        "    beq.n\t.LNewGameDE_08006714\n"
        "    cmp\tr2, #1\n"
        "    bgt.n\t.LNewGameDE_080066FC\n"
        "    cmp\tr2, #0\n"
        "    beq.n\t.LNewGameDE_08006702\n"
        "    b.n\t.LNewGameDE_08006746\n"
        "    .align 2, 0\n"
#if !((((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && (((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT - 1) * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
        ".Lname_input_de_keyboard_22: .word ((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
        ".LNewGameDE_080066F8: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ")\n"
        ".LNewGameDE_080066FC:\n"
        "    cmp\tr2, #2\n"
        "    beq.n\t.LNewGameDE_08006730\n"
        "    b.n\t.LNewGameDE_08006746\n"
        ".LNewGameDE_08006702:\n"
        "    ldr r1, .LNewGameDE_08006710\n"
        "    add\tr0, sp, #40\n"
        "    strh\tr4, [r0, #0]\n"
        "    strh\tr5, [r0, #2]\n"
        "    ldr\tr0, [sp, #40]\n"
        "    b.n\t.LNewGameDE_0800671E\n"
        "    .align 2, 0\n"
        ".LNewGameDE_08006710: .word gText_NewGameNameEntry_EndLatin\n"
        ".LNewGameDE_08006714:\n"
        "    ldr r1, .LNewGameDE_0800672C\n"
        "    add\tr0, sp, #44\n"
        "    strh\tr4, [r0, #0]\n"
        "    strh\tr5, [r0, #2]\n"
        "    ldr\tr0, [sp, #44]\n"
        ".LNewGameDE_0800671E:\n"
        "    str\tr1, [sp, #0]\n"
        "    ldr\tr1, [sp, #80]\n"
        "    movs\tr2, #24\n"
        "    movs\tr3, #0\n"
        "    bl\tDrawStringTo2DGfxBuffer\n"
        "    b.n\t.LNewGameDE_08006746\n"
        ".LNewGameDE_0800672C: .word gText_NewGameNameEntry_EndLatin\n"
        ".LNewGameDE_08006730:\n"
        "    ldr r1, .LNewGameDE_08006788\n"
        "    add\tr0, sp, #48\n"
        "    strh\tr4, [r0, #0]\n"
        "    strh\tr2, [r0, #2]\n"
        "    ldr\tr0, [sp, #48]\n"
        "    str\tr1, [sp, #0]\n"
        "    ldr\tr1, [sp, #80]\n"
        "    movs\tr2, #24\n"
        "    movs\tr3, #0\n"
        "    bl\tDrawStringTo2DGfxBuffer\n"
        ".LNewGameDE_08006746:\n"
        "    mov\tr0, sl\n"
        "    bl\tGetHardwareDmaQueue\n"
        "    adds\tr5, r0, #0\n"
        "    movs\tr2, #(MEM_VRAM >> 19)\n"
        "    lsls\tr2, r2, #19\n"
        "    ldr\tr3, [sp, #76]\n"
        "    adds\tr2, r3, r2\n"
        "    add\tr0, sp, #4\n"
        "    ldr\tr1, [sp, #80]\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r3, r3, #3\n"
#else
        "    ldr r3, .Lname_input_de_keyboard_24\n"
#endif
        "\n"
        "    bl\t__21DmaTransferDescriptorPCvPvUi\n"
        "    add\tr4, sp, #4\n"
        "    mov\tr9, r4\n"
        "    ldr\tr1, [r5, #4]\n"
        "    ldr\tr0, [r5, #12]\n"
        "    cmp\tr1, r0\n"
        "    beq.n\t.LNewGameDE_0800678C\n"
        "    cmp\tr1, #0\n"
        "    beq.n\t.LNewGameDE_0800677E\n"
        "    adds\tr0, r1, #0\n"
        "    add\tr1, sp, #4\n"
        "    ldmia\tr1!, {r2, r6, r7}\n"
        "    stmia\tr0!, {r2, r6, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_0800677E:\n"
        "    ldr\tr0, [r5, #4]\n"
        "    adds\tr0, #16\n"
        "    str\tr0, [r5, #4]\n"
        "    b.n\t.LNewGameDE_08006852\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
        ".Lname_input_de_keyboard_24: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
        ".LNewGameDE_08006788: .word gText_NewGameNameEntry_EndLatin\n"
        ".LNewGameDE_0800678C:\n"
        "    str\tr1, [sp, #84]\n"
        "    movs\tr0, #1\n"
        "    str\tr0, [sp, #56]\n"
        "    ldr\tr0, [r5, #0]\n"
        "    adds\tr3, r1, #0\n"
        "    subs\tr0, r3, r0\n"
        "    asrs\tr4, r0, #4\n"
        "    str\tr4, [sp, #52]\n"
        "    add\tr1, sp, #56\n"
        "    add\tr0, sp, #52\n"
        "    cmp\tr4, #1\n"
        "    bcs.n\t.LNewGameDE_080067A6\n"
        "    adds\tr0, r1, #0\n"
        ".LNewGameDE_080067A6:\n"
        "    ldr\tr0, [r0, #0]\n"
        "    adds\tr0, r4, r0\n"
        "    cmp\tr0, #0\n"
        "    beq.n\t.LNewGameDE_080067C4\n"
        "    lsls\tr4, r0, #4\n"
        "    adds\tr0, r4, #0\n"
        "    bl\tmalloc\n"
        "    mov\tr8, r4\n"
        "    cmp\tr0, #0\n"
        "    bne.n\t.LNewGameDE_080067C8\n"
        "    mov\tr0, r8\n"
        "    bl\tRetryMemoryAllocation\n"
        "    b.n\t.LNewGameDE_080067C8\n"
        ".LNewGameDE_080067C4:\n"
        "    movs\tr0, #0\n"
        "    mov\tr8, r0\n"
        ".LNewGameDE_080067C8:\n"
        "    adds\tr4, r0, #0\n"
        "    str\tr4, [sp, #88]\n"
        "    ldr\tr2, [r5, #0]\n"
        "    adds\tr3, r4, #0\n"
        "    ldr\tr4, [sp, #84]\n"
        "    cmp\tr2, r4\n"
        "    beq.n\t.LNewGameDE_080067F0\n"
        ".LNewGameDE_080067D6:\n"
        "    cmp\tr3, #0\n"
        "    beq.n\t.LNewGameDE_080067E6\n"
        "    adds\tr0, r3, #0\n"
        "    adds\tr1, r2, #0\n"
        "    ldmia\tr1!, {r4, r6, r7}\n"
        "    stmia\tr0!, {r4, r6, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_080067E6:\n"
        "    adds\tr2, #16\n"
        "    adds\tr3, #16\n"
        "    ldr\tr6, [sp, #84]\n"
        "    cmp\tr2, r6\n"
        "    bne.n\t.LNewGameDE_080067D6\n"
        ".LNewGameDE_080067F0:\n"
        "    adds\tr4, r3, #0\n"
        "    ldr\tr0, [sp, #56]\n"
        "    cmp\tr0, #1\n"
        "    bne.n\t.LNewGameDE_0800680C\n"
        "    cmp\tr4, #0\n"
        "    beq.n\t.LNewGameDE_08006808\n"
        "    adds\tr0, r4, #0\n"
        "    mov\tr1, r9\n"
        "    ldmia\tr1!, {r2, r3, r7}\n"
        "    stmia\tr0!, {r2, r3, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_08006808:\n"
        "    adds\tr4, #16\n"
        "    b.n\t.LNewGameDE_0800682E\n"
        ".LNewGameDE_0800680C:\n"
        "    adds\tr3, r0, #0\n"
        "    adds\tr2, r4, #0\n"
        "    cmp\tr3, #0\n"
        "    beq.n\t.LNewGameDE_0800682C\n"
        ".LNewGameDE_08006814:\n"
        "    cmp\tr2, #0\n"
        "    beq.n\t.LNewGameDE_08006824\n"
        "    adds\tr0, r2, #0\n"
        "    mov\tr1, r9\n"
        "    ldmia\tr1!, {r4, r6, r7}\n"
        "    stmia\tr0!, {r4, r6, r7}\n"
        "    ldr\tr1, [r1, #0]\n"
        "    str\tr1, [r0, #0]\n"
        ".LNewGameDE_08006824:\n"
        "    subs\tr3, #1\n"
        "    adds\tr2, #16\n"
        "    cmp\tr3, #0\n"
        "    bne.n\t.LNewGameDE_08006814\n"
        ".LNewGameDE_0800682C:\n"
        "    adds\tr4, r2, #0\n"
        ".LNewGameDE_0800682E:\n"
        "    ldr\tr2, [r5, #4]\n"
        "    ldr\tr0, [r5, #0]\n"
        "    adds\tr1, r0, #0\n"
        "    cmp\tr0, r2\n"
        "    beq.n\t.LNewGameDE_0800683E\n"
        ".LNewGameDE_08006838:\n"
        "    adds\tr1, #16\n"
        "    cmp\tr1, r2\n"
        "    bne.n\t.LNewGameDE_08006838\n"
        ".LNewGameDE_0800683E:\n"
        "    cmp\tr0, #0\n"
        "    beq.n\t.LNewGameDE_08006846\n"
        "    bl\tfree\n"
        ".LNewGameDE_08006846:\n"
        "    ldr\tr0, [sp, #88]\n"
        "    add\tr0, r8\n"
        "    ldr\tr1, [sp, #88]\n"
        "    str\tr1, [r5, #0]\n"
        "    str\tr4, [r5, #4]\n"
        "    str\tr0, [r5, #12]\n"
        ".LNewGameDE_08006852:\n"
        "    ldr r1, .LNewGameDE_0800686C\n"
        "    add\tr1, sl\n"
        "    movs\tr0, #0\n"
        "    strb\tr0, [r1, #0]\n"
        ".LNewGameDE_0800685A:\n"
        "    add\tsp, #92\n"
        "    pop\t{r3, r4, r5}\n"
        "    mov\tr8, r3\n"
        "    mov\tr9, r4\n"
        "    mov\tsl, r5\n"
        "    pop\t{r4, r5, r6, r7}\n"
        "    pop\t{r0}\n"
        "    bx\tr0\n"
        "    .align 2, 0\n"
        ".LNewGameDE_0800686C: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET) ")\n"
        "\n"
#else
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x5c\n"
        "    mov sl, r0\n"
        "    ldr r0, .L080065D0\n"
        "    add r0, sl\n"
        "    ldrb r0, [r0]\n"
        "    cmp r0, #0\n"
        "    bne .L08006502\n"
        "    b .L08006842\n"
        ".L08006502:\n"
        "    movs r0, #1\n"
        "    mov r8, r0\n"
        "    mov r1, sp\n"
        "    adds r1, #0x14\n"
        "    str r1, [sp, #0x40]\n"
        "    mov r2, sp\n"
        "    adds r2, #0x18\n"
        "    str r2, [sp, #0x44]\n"
        "    mov r3, sp\n"
        "    adds r3, #0x24\n"
        "    str r3, [sp, #0x48]\n"
        "    ldr r4, .L080065D4\n"
        "    add r4, sl\n"
        "    str r4, [sp, #0x50]\n"
        "    mov r6, sp\n"
        "    adds r6, #4\n"
        "    str r6, [sp, #0x3c]\n"
        ".L08006524:\n"
        "    mov r7, r8\n"
#if (NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2))
        "    lsls r4, r7, #4\n"
        "    subs r4, r4, r7\n"
        "    lsls r4, r4, #5\n"
        "    add r4, r8\n"
        "    lsls r4, r4, #2\n"
#else
        "    ldr r4, .Lname_input_overseas_keyboard_35\n"
        "    muls r4, r7\n"
#endif
        "    mov r0, sl\n"
        "    adds r1, r4, r0\n"
        "    add r0, sp, #0x14\n"
        "    movs r2, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    strh r2, [r0]\n"
        "    movs r6, #2\n"
        "    ldr r3, [sp, #0x40]\n"
        "    strh r6, [r3, #2]\n"
        "    ldr r0, [sp, #0x14]\n"
        "    adds r1, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
        "    movs r2, #0\n"
        "    bl Clear2DGfxBuffer\n"
#if ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255
        "    movs r0, #((" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ") >> 7)\n"
        "    lsls r0, r0, #7\n"
#else
        "    ldr r0, .Lname_input_overseas_keyboard_29\n"
#endif
        "\n"
        "    add r0, sl\n"
        "    ldr r3, [r0]\n"
        "    mov r7, sl\n"
        "    adds r1, r4, r7\n"
        "    mov r0, r8\n"
#if (NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1)
        "    lsls r2, r0, #5\n"
        "    subs r2, r2, r0\n"
#else
        "    ldr r2, .Lname_input_overseas_keyboard_36\n"
        "    muls r2, r0\n"
#endif
#if (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH) <= 255
        "    movs r0, #(" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) " * " STRINGIFY(NEW_GAME_NAME_ENTRY_ROW_WIDTH) ")\n"
#else
        "    ldr r0, .Lname_input_overseas_keyboard_37\n"
#endif
        "\n"
        "    muls r0, r3, r0\n"
        "    adds r2, r2, r0\n"
        "    ldr r0, .L080065D8 @ =gNewGameNameEntryCharacterRows - NEW_GAME_NAME_ENTRY_ROW_WIDTH\n"
        "    adds r2, r2, r0\n"
        "    add r0, sp, #0x18\n"
        "    movs r3, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    strh r3, [r0]\n"
        "    ldr r7, [sp, #0x44]\n"
        "    strh r6, [r7, #2]\n"
        "    ldr r0, [sp, #0x18]\n"
        "    adds r1, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
        "    str r2, [sp]\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDmaQueue\n"
        "    add r4, sl\n"
        "    adds r4, #" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) "\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r1, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r1, r1, #3\n"
#else
        "    ldr r1, .Lname_input_overseas_keyboard_33\n"
#endif
        "\n"
        "    mov r2, r8\n"
        "    muls r2, r1, r2\n"
        "    adds r5, r0, #0\n"
        "    movs r3, #(MEM_VRAM >> 19)\n"
        "    lsls r3, r3, #0x13\n"
        "    adds r2, r2, r3\n"
        "    add r0, sp, #4\n"
        "    adds r1, r4, #0\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r3, r3, #3\n"
#else
        "    ldr r3, .Lname_input_overseas_keyboard_33\n"
#endif
        "\n"
        "    bl __21DmaTransferDescriptorPCvPvUi\n"
        "    ldr r1, [r5, #4]\n"
        "    ldr r0, [r5, #0xc]\n"
        "    cmp r1, r0\n"
        "    beq .L080065DC\n"
        "    cmp r1, #0\n"
        "    beq .L080065BC\n"
        "    adds r0, r1, #0\n"
        "    add r1, sp, #4\n"
        "    ldm r1!, {r4, r6, r7}\n"
        "    stm r0!, {r4, r6, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L080065BC:\n"
        "    ldr r0, [r5, #4]\n"
        "    adds r0, #0x10\n"
        "    str r0, [r5, #4]\n"
        "    movs r0, #1\n"
        "    add r8, r0\n"
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
        "    movs r1, #((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 6)\n"
        "    lsls r1, r1, #3\n"
        "    lsls r1, r1, #3\n"
#else
        "    ldr r1, .Lname_input_overseas_keyboard_31\n"
#endif
        "\n"
        "    str r1, [sp, #0x4c]\n"
        "    b .L080066AE\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255)
        ".Lname_input_overseas_keyboard_29: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
        ".Lname_input_overseas_keyboard_31: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
        ".Lname_input_overseas_keyboard_33: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
#if !((NEW_GAME_NAME_INPUT_BUFFER_BYTES) == ((((1 << 4) - 1) * (1 << 5) + 1) * (1 << 2)))
        ".Lname_input_overseas_keyboard_35: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_BUFFER_BYTES) ")\n"
#endif
#if !((NEW_GAME_NAME_ENTRY_ROW_WIDTH) == ((1 << 5) - 1))
        ".Lname_input_overseas_keyboard_36: .word (" STRINGIFY(NEW_GAME_NAME_ENTRY_ROW_WIDTH) ")\n"
#endif
#if !((NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH) <= 255)
        ".Lname_input_overseas_keyboard_37: .word (" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) " * " STRINGIFY(NEW_GAME_NAME_ENTRY_ROW_WIDTH) ")\n"
#endif
        ".L080065D0: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET) ")\n"
        ".L080065D4: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_TILES_OFFSET) " + (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " - 1) * " STRINGIFY(NEW_GAME_NAME_INPUT_BUFFER_BYTES) ")\n"
        "@ r8 is one-based here, so this is the keyboard table address minus exactly\n"
        "@ one fixed-width row.  It is not a pointer into DogName.\n"
        ".L080065D8: .word gNewGameNameEntryCharacterRows - " STRINGIFY(NEW_GAME_NAME_ENTRY_ROW_WIDTH) "\n"
        ".L080065DC:\n"
        "    str r1, [sp, #0x54]\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0x20]\n"
        "    ldr r0, [r5]\n"
        "    adds r2, r1, #0\n"
        "    subs r0, r2, r0\n"
        "    asrs r4, r0, #4\n"
        "    str r4, [sp, #0x1c]\n"
        "    add r1, sp, #0x20\n"
        "    add r0, sp, #0x1c\n"
        "    cmp r4, #1\n"
        "    bhs .L080065F6\n"
        "    adds r0, r1, #0\n"
        ".L080065F6:\n"
        "    ldr r0, [r0]\n"
        "    adds r0, r4, r0\n"
        "    cmp r0, #0\n"
        "    beq .L08006614\n"
        "    lsls r4, r0, #4\n"
        "    adds r0, r4, #0\n"
        "    bl malloc\n"
        "    mov sb, r4\n"
        "    cmp r0, #0\n"
        "    bne .L08006618\n"
        "    mov r0, sb\n"
        "    bl RetryMemoryAllocation\n"
        "    b .L08006618\n"
        ".L08006614:\n"
        "    movs r0, #0\n"
        "    mov sb, r0\n"
        ".L08006618:\n"
        "    adds r4, r0, #0\n"
        "    str r4, [sp, #0x58]\n"
        "    ldr r2, [r5]\n"
        "    adds r3, r4, #0\n"
        "    movs r4, #1\n"
        "    add r8, r4\n"
#if ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255
        "    movs r6, #((" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 6)\n"
        "    lsls r6, r6, #3\n"
        "    lsls r6, r6, #3\n"
#else
        "    ldr r6, .Lname_input_overseas_keyboard_32\n"
#endif
        "\n"
        "    str r6, [sp, #0x4c]\n"
        "    ldr r7, [sp, #0x54]\n"
        "    cmp r2, r7\n"
        "    beq .L0800664C\n"
        ".L08006632:\n"
        "    cmp r3, #0\n"
        "    beq .L08006642\n"
        "    adds r0, r3, #0\n"
        "    adds r1, r2, #0\n"
        "    ldm r1!, {r4, r6, r7}\n"
        "    stm r0!, {r4, r6, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08006642:\n"
        "    adds r2, #0x10\n"
        "    adds r3, #0x10\n"
        "    ldr r0, [sp, #0x54]\n"
        "    cmp r2, r0\n"
        "    bne .L08006632\n"
        ".L0800664C:\n"
        "    adds r4, r3, #0\n"
        "    ldr r0, [sp, #0x20]\n"
        "    cmp r0, #1\n"
        "    bne .L08006668\n"
        "    cmp r4, #0\n"
        "    beq .L08006664\n"
        "    adds r0, r4, #0\n"
        "    ldr r1, [sp, #0x3c]\n"
        "    ldm r1!, {r2, r3, r6}\n"
        "    stm r0!, {r2, r3, r6}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08006664:\n"
        "    adds r4, #0x10\n"
        "    b .L0800668A\n"
        ".L08006668:\n"
        "    adds r3, r0, #0\n"
        "    adds r2, r4, #0\n"
        "    cmp r3, #0\n"
        "    beq .L08006688\n"
        ".L08006670:\n"
        "    cmp r2, #0\n"
        "    beq .L08006680\n"
        "    adds r0, r2, #0\n"
        "    ldr r1, [sp, #0x3c]\n"
        "    ldm r1!, {r4, r6, r7}\n"
        "    stm r0!, {r4, r6, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08006680:\n"
        "    subs r3, #1\n"
        "    adds r2, #0x10\n"
        "    cmp r3, #0\n"
        "    bne .L08006670\n"
        ".L08006688:\n"
        "    adds r4, r2, #0\n"
        ".L0800668A:\n"
        "    ldr r2, [r5, #4]\n"
        "    ldr r0, [r5]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, r2\n"
        "    beq .L0800669A\n"
        ".L08006694:\n"
        "    adds r1, #0x10\n"
        "    cmp r1, r2\n"
        "    bne .L08006694\n"
        ".L0800669A:\n"
        "    cmp r0, #0\n"
        "    beq .L080066A2\n"
        "    bl free\n"
        ".L080066A2:\n"
        "    ldr r0, [sp, #0x58]\n"
        "    add r0, sb\n"
        "    ldr r7, [sp, #0x58]\n"
        "    str r7, [r5]\n"
        "    str r4, [r5, #4]\n"
        "    str r0, [r5, #0xc]\n"
        ".L080066AE:\n"
        "    mov r0, r8\n"
        "    cmp r0, #" STRINGIFY(NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) "\n"
        "    bhi .L080066B6\n"
        "    b .L08006524\n"
        ".L080066B6:\n"
        "    movs r4, #" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_WIDTH) "\n"
        "    movs r5, #2\n"
        "    add r0, sp, #0x24\n"
        "    strh r4, [r0]\n"
        "    ldr r1, [sp, #0x48]\n"
        "    strh r5, [r1, #2]\n"
        "    ldr r0, [sp, #0x24]\n"
        "    ldr r1, [sp, #0x50]\n"
        "    movs r2, #0\n"
        "    bl Clear2DGfxBuffer\n"
#if ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255
        "    movs r0, #((" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ") >> 7)\n"
        "    lsls r0, r0, #7\n"
#else
        "    ldr r0, .Lname_input_overseas_keyboard_30\n"
#endif
        "\n"
        "    add r0, sl\n"
        "    ldr r2, [r0]\n"
        "    cmp r2, #1\n"
        "    beq .L080066F8\n"
        "    cmp r2, #1\n"
        "    bgt .L080066E2\n"
        "    cmp r2, #0\n"
        "    beq .L080066E8\n"
        "    b .L0800672A\n"
        ".L080066E2:\n"
        "    cmp r2, #2\n"
        "    beq .L08006714\n"
        "    b .L0800672A\n"
        ".L080066E8:\n"
        "    ldr r1, .L080066F4 @ =gText_NewGameNameEntry_EndLatin\n"
        "    add r0, sp, #0x28\n"
        "    strh r4, [r0]\n"
        "    strh r5, [r0, #2]\n"
        "    ldr r0, [sp, #0x28]\n"
        "    b .L08006702\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) & 127) == 0 && ((NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) >> 7) <= 255)
        ".Lname_input_overseas_keyboard_30: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_PAGE_OFFSET) ")\n"
#endif
#if !(((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) & 63) == 0 && ((NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT * NEW_GAME_NAME_INPUT_TILE_BYTES) >> 6) <= 255)
        ".Lname_input_overseas_keyboard_32: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_KEYBOARD_BUFFER_COUNT) " * " STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
        ".L080066F4: .word gText_NewGameNameEntry_EndLatin\n"
        ".L080066F8:\n"
        "    ldr r1, .L08006710 @ =gText_NewGameNameEntry_EndFullWidth\n"
        "    add r0, sp, #0x2c\n"
        "    strh r4, [r0]\n"
        "    strh r5, [r0, #2]\n"
        "    ldr r0, [sp, #0x2c]\n"
        ".L08006702:\n"
        "    str r1, [sp]\n"
        "    ldr r1, [sp, #0x50]\n"
        "    movs r2, #0x18\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    b .L0800672A\n"
        "    .align 2, 0\n"
        ".L08006710: .word gText_NewGameNameEntry_EndFullWidth\n"
        ".L08006714:\n"
        "    ldr r1, .L08006770 @ =gText_NewGameNameEntry_EndFullWidth\n"
        "    add r0, sp, #0x30\n"
        "    strh r4, [r0]\n"
        "    strh r2, [r0, #2]\n"
        "    ldr r0, [sp, #0x30]\n"
        "    str r1, [sp]\n"
        "    ldr r1, [sp, #0x50]\n"
        "    movs r2, #0x18\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        ".L0800672A:\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDmaQueue\n"
        "    adds r5, r0, #0\n"
        "    ldr r3, [sp, #0x4c]\n"
#if ((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255
        "    movs r4, #((" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ") >> 3)\n"
        "    lsls r4, r4, #3\n"
#else
        "    ldr r4, .Lname_input_overseas_keyboard_34\n"
#endif
        "\n"
        "    subs r2, r3, r4\n"
        "    movs r6, #(MEM_VRAM >> 19)\n"
        "    lsls r6, r6, #0x13\n"
        "    adds r2, r2, r6\n"
        "    add r0, sp, #4\n"
        "    ldr r1, [sp, #0x50]\n"
        "    adds r3, r4, #0\n"
        "    bl __21DmaTransferDescriptorPCvPvUi\n"
        "    add r7, sp, #4\n"
        "    mov sb, r7\n"
        "    ldr r1, [r5, #4]\n"
        "    ldr r0, [r5, #0xc]\n"
        "    cmp r1, r0\n"
        "    beq .L08006774\n"
        "    cmp r1, #0\n"
        "    beq .L08006766\n"
        "    adds r0, r1, #0\n"
        "    add r1, sp, #4\n"
        "    ldm r1!, {r2, r3, r4}\n"
        "    stm r0!, {r2, r3, r4}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08006766:\n"
        "    ldr r0, [r5, #4]\n"
        "    adds r0, #0x10\n"
        "    str r0, [r5, #4]\n"
        "    b .L0800683A\n"
        "    .align 2, 0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_NAME_INPUT_TILE_BYTES) & 7) == 0 && ((NEW_GAME_NAME_INPUT_TILE_BYTES) >> 3) <= 255)
        ".Lname_input_overseas_keyboard_34: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_TILE_BYTES) ")\n"
#endif
        ".L08006770: .word gText_NewGameNameEntry_EndFullWidth\n"
        ".L08006774:\n"
        "    str r1, [sp, #0x54]\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0x38]\n"
        "    ldr r0, [r5]\n"
        "    adds r6, r1, #0\n"
        "    subs r0, r6, r0\n"
        "    asrs r4, r0, #4\n"
        "    str r4, [sp, #0x34]\n"
        "    add r1, sp, #0x38\n"
        "    add r0, sp, #0x34\n"
        "    cmp r4, #1\n"
        "    bhs .L0800678E\n"
        "    adds r0, r1, #0\n"
        ".L0800678E:\n"
        "    ldr r0, [r0]\n"
        "    adds r0, r4, r0\n"
        "    cmp r0, #0\n"
        "    beq .L080067AC\n"
        "    lsls r4, r0, #4\n"
        "    adds r0, r4, #0\n"
        "    bl malloc\n"
        "    mov r8, r4\n"
        "    cmp r0, #0\n"
        "    bne .L080067B0\n"
        "    mov r0, r8\n"
        "    bl RetryMemoryAllocation\n"
        "    b .L080067B0\n"
        ".L080067AC:\n"
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        ".L080067B0:\n"
        "    adds r4, r0, #0\n"
        "    str r4, [sp, #0x58]\n"
        "    ldr r2, [r5]\n"
        "    adds r3, r4, #0\n"
        "    ldr r7, [sp, #0x54]\n"
        "    cmp r2, r7\n"
        "    beq .L080067D8\n"
        ".L080067BE:\n"
        "    cmp r3, #0\n"
        "    beq .L080067CE\n"
        "    adds r0, r3, #0\n"
        "    adds r1, r2, #0\n"
        "    ldm r1!, {r4, r6, r7}\n"
        "    stm r0!, {r4, r6, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L080067CE:\n"
        "    adds r2, #0x10\n"
        "    adds r3, #0x10\n"
        "    ldr r0, [sp, #0x54]\n"
        "    cmp r2, r0\n"
        "    bne .L080067BE\n"
        ".L080067D8:\n"
        "    adds r4, r3, #0\n"
        "    ldr r0, [sp, #0x38]\n"
        "    cmp r0, #1\n"
        "    bne .L080067F4\n"
        "    cmp r4, #0\n"
        "    beq .L080067F0\n"
        "    adds r0, r4, #0\n"
        "    mov r1, sb\n"
        "    ldm r1!, {r2, r3, r6}\n"
        "    stm r0!, {r2, r3, r6}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L080067F0:\n"
        "    adds r4, #0x10\n"
        "    b .L08006816\n"
        ".L080067F4:\n"
        "    adds r3, r0, #0\n"
        "    adds r2, r4, #0\n"
        "    cmp r3, #0\n"
        "    beq .L08006814\n"
        ".L080067FC:\n"
        "    cmp r2, #0\n"
        "    beq .L0800680C\n"
        "    adds r0, r2, #0\n"
        "    mov r1, sb\n"
        "    ldm r1!, {r4, r6, r7}\n"
        "    stm r0!, {r4, r6, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L0800680C:\n"
        "    subs r3, #1\n"
        "    adds r2, #0x10\n"
        "    cmp r3, #0\n"
        "    bne .L080067FC\n"
        ".L08006814:\n"
        "    adds r4, r2, #0\n"
        ".L08006816:\n"
        "    ldr r2, [r5, #4]\n"
        "    ldr r0, [r5]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, r2\n"
        "    beq .L08006826\n"
        ".L08006820:\n"
        "    adds r1, #0x10\n"
        "    cmp r1, r2\n"
        "    bne .L08006820\n"
        ".L08006826:\n"
        "    cmp r0, #0\n"
        "    beq .L0800682E\n"
        "    bl free\n"
        ".L0800682E:\n"
        "    ldr r0, [sp, #0x58]\n"
        "    add r0, r8\n"
        "    ldr r7, [sp, #0x58]\n"
        "    str r7, [r5]\n"
        "    str r4, [r5, #4]\n"
        "    str r0, [r5, #0xc]\n"
        ".L0800683A:\n"
        "    ldr r1, .L08006854\n"
        "    add r1, sl\n"
        "    movs r0, #0\n"
        "    strb r0, [r1]\n"
        ".L08006842:\n"
        "    add sp, #0x5c\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .align 2, 0\n"
        ".L08006854: .word (" STRINGIFY(NEW_GAME_NAME_INPUT_CORE_REDRAW_OFFSET) ")\n"
#endif
#endif
    );
}

void SubmitNameInputCursorSprites(NewGameNameInputCore * core)
{
    // Submit only the six OAM attribute bytes. The destination's affine
    // coefficient is owned by the sprite buffer and must remain untouched.
    if (core->unk_463c == 0) {
        HardwareSpriteBufferState * buffer =
            GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
        u32 const & position_and_mode =
            reinterpret_cast<u32 const &>(core->sprites[0].attributes);
        u32 count = buffer->sprite_count;
        if (count < ARRAY_COUNT(buffer->sprites)) {
            HardwareSpriteOamRecord & destination = buffer->sprites[count];
            reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
            reinterpret_cast<u16 *>(&destination)[2] =
                reinterpret_cast<u16 const *>(&core->sprites[0].attributes)[2];
            buffer->sprite_count = count + 1;
        }
    }
    {
        HardwareSpriteBufferState * buffer =
            GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
        u32 const & position_and_mode =
            reinterpret_cast<u32 const &>(core->sprites[1].attributes);
        u32 count = buffer->sprite_count;
        if (count < ARRAY_COUNT(buffer->sprites)) {
            HardwareSpriteOamRecord & destination = buffer->sprites[count];
            reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
            reinterpret_cast<u16 *>(&destination)[2] =
                reinterpret_cast<u16 const *>(&core->sprites[1].attributes)[2];
            buffer->sprite_count = count + 1;
        }
    }
}

void UpdateNameInputCursorSprites(NewGameNameInputCore * core)
{
#if defined(REGION_JP)
    core->sprites[1].attributes.x = core->sprites[1].unk_00[0] * 16 + 0x90;
#else
    core->sprites[1].attributes.x = core->sprites[1].unk_00[0] * 8 + 0x90;
#endif
    core->sprites[1].attributes.y = 8;

    if (static_cast<i8>(core->sprites[0].unk_00[1]) < NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) {
        core->sprites[0].attributes.x = static_cast<i8>(core->sprites[0].unk_00[0]) * 16;
        core->sprites[0].attributes.y = static_cast<i8>(core->sprites[0].unk_00[1]) * 16 + 0x20;
#if defined(REGION_JP)
        core->sprites[0].attributes.size = ST_OAM_SIZE_1;
        core->sprites[0].attributes.shape = ST_OAM_SQUARE;
#else
        core->sprites[0].attributes.size = ST_OAM_SIZE_0;
        core->sprites[0].attributes.shape = ST_OAM_V_RECTANGLE;
#endif
    } else {
        u8 group = 0;
        u8 column = core->sprites[0].unk_00[0];
        while (column > 4) {
            column -= 5;
            group++;
        }
        core->sprites[0].attributes.x = group * 80 + 0x18;
#if defined(REGION_DE)
        core->sprites[0].attributes.y = 0x90;
#else
        core->sprites[0].attributes.y = 0x88;
#endif
        core->sprites[0].attributes.size = ST_OAM_SIZE_2;
        core->sprites[0].attributes.shape = ST_OAM_H_RECTANGLE;
    }
}

void MoveNameInputKeyboardCursor(NewGameNameInputCore * core)
{
    int const last_character_row = NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE - 1;
    int const bottom_row = NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE;
#if defined(REGION_DE)
    int const last_column = 4;
#elif !defined(REGION_JP)
    int const last_column = 12;
#endif
    u32 input = GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core));
    u32 up = input & DPAD_UP;
    if (static_cast<u8>(up)) {
        core->music_player_2.Start(AUDIO_SFX_MENU_CURSOR);
        core->sprites[0].unk_00[1]--;
        if (static_cast<i8>(core->sprites[0].unk_00[1]) < 0) {
            core->sprites[0].unk_00[1] = bottom_row;
#if !defined(REGION_JP)
            core->sprites[0].unk_00[0] = 12;
#endif
        }
        if (static_cast<i8>(core->sprites[0].unk_00[1]) == last_character_row) {
#if defined(REGION_JP)
            int last_column = core->keyboard_page == 2 ? 12 : 9;
#endif
            if (static_cast<i8>(core->sprites[0].unk_00[0]) > last_column)
                core->sprites[0].unk_00[1]--;
        }
    } else {
        u32 down = input & DPAD_DOWN;
        if (static_cast<u8>(down)) {
            core->music_player_2.Start(AUDIO_SFX_MENU_CURSOR);
            core->sprites[0].unk_00[1]++;
            if (static_cast<i8>(core->sprites[0].unk_00[1]) > bottom_row)
                core->sprites[0].unk_00[1] = 0;
            if (static_cast<i8>(core->sprites[0].unk_00[1]) == last_character_row) {
#if defined(REGION_JP)
                int last_column = core->keyboard_page == 2 ? 12 : 9;
#endif
                if (static_cast<i8>(core->sprites[0].unk_00[0]) > last_column)
                    core->sprites[0].unk_00[1]++;
            }
#if !defined(REGION_JP)
            if (static_cast<i8>(core->sprites[0].unk_00[1]) == bottom_row)
                core->sprites[0].unk_00[0] = 12;
#endif
        } else if (input & DPAD_RIGHT) {
            core->music_player_2.Start(AUDIO_SFX_MENU_CURSOR);
            if (static_cast<i8>(core->sprites[0].unk_00[1]) == bottom_row) {
#if defined(REGION_JP)
                if (static_cast<i8>(core->sprites[0].unk_00[0]) <= 4)
                    core->sprites[0].unk_00[0] = 7;
                else if (static_cast<i8>(core->sprites[0].unk_00[0]) > 9)
                    core->sprites[0].unk_00[0] = 2;
                else
                    core->sprites[0].unk_00[0] = 12;
#else
                core->sprites[0].unk_00[0] = 12;
#endif
            } else {
                core->sprites[0].unk_00[0]++;
                if (static_cast<i8>(core->sprites[0].unk_00[1]) == last_character_row) {
#if defined(REGION_JP)
                    int last_column = core->keyboard_page == 2 ? 12 : 9;
#endif
#if defined(REGION_US) || defined(REGION_EU)
                    u32 column = core->sprites[0].unk_00[0];
                    if (static_cast<i8>(column) > last_column)
#else
                    if (static_cast<i8>(core->sprites[0].unk_00[0]) > last_column)
#endif
                        core->sprites[0].unk_00[0] = 0;
                } else if (static_cast<i8>(core->sprites[0].unk_00[0]) > 14)
                    core->sprites[0].unk_00[0] = 0;
            }
        } else if (input & DPAD_LEFT) {
            core->music_player_2.Start(AUDIO_SFX_MENU_CURSOR);
            if (static_cast<i8>(core->sprites[0].unk_00[1]) == bottom_row) {
#if defined(REGION_JP)
                if (static_cast<i8>(core->sprites[0].unk_00[0]) <= 4)
                    core->sprites[0].unk_00[0] = 12;
                else if (static_cast<i8>(core->sprites[0].unk_00[0]) > 9)
                    core->sprites[0].unk_00[0] = 7;
                else
                    core->sprites[0].unk_00[0] = 2;
#else
                core->sprites[0].unk_00[0] = 12;
#endif
            } else {
                core->sprites[0].unk_00[0]--;
                if (static_cast<i8>(core->sprites[0].unk_00[1]) == last_character_row) {
#if defined(REGION_JP)
                    int last_column = core->keyboard_page == 2 ? 12 : 9;
#endif
                    if (static_cast<i8>(core->sprites[0].unk_00[0]) < 0)
                        core->sprites[0].unk_00[0] = last_column;
                } else if (static_cast<i8>(core->sprites[0].unk_00[0]) < 0)
                    core->sprites[0].unk_00[0] = 14;
            }
        }
    }
}

void InsertNameInputCharacter(NewGameNameInputCore * core)
{
    char character[2];
    character[0] = gNewGameNameEntryCharacterRows.bytes[
        static_cast<i8>(core->sprites[0].unk_00[0]) * 2
        + static_cast<i8>(core->sprites[0].unk_00[1]) * NEW_GAME_NAME_ENTRY_ROW_WIDTH
        + core->keyboard_page * (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH)];
#if defined(REGION_JP)
    character[1] = gNewGameNameEntryCharacterRows.bytes[
        (static_cast<i8>(core->sprites[0].unk_00[0]) * 2 + 1)
        + static_cast<i8>(core->sprites[0].unk_00[1]) * NEW_GAME_NAME_ENTRY_ROW_WIDTH
        + core->keyboard_page * (NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE * NEW_GAME_NAME_ENTRY_ROW_WIDTH)];
    if (core->name[core->sprites[1].unk_00[0] * 2] == character[0]
            && core->name[core->sprites[1].unk_00[0] * 2 + 1] == character[1])
        core->sprites[1].unk_00[0]++;
    else {
        core->name[core->sprites[1].unk_00[0] * 2] = character[0];
        core->name[core->sprites[1].unk_00[0] * 2 + 1] = character[1];
        core->sprites[1].unk_00[0]++;
    }
    if (core->sprites[1].unk_00[0] > 5) {
        core->sprites[0].unk_00[0] = 12;
        core->sprites[0].unk_00[1] = 6;
        core->sprites[1].unk_00[0] = 5;
    }
#else
    if (core->name[core->sprites[1].unk_00[0]] == character[0])
        core->sprites[1].unk_00[0]++;
    else {
        core->name[core->sprites[1].unk_00[0]] = character[0];
        core->sprites[1].unk_00[0]++;
    }
    if (core->sprites[1].unk_00[0] > 11) {
        core->sprites[0].unk_00[0] = 12;
#if defined(REGION_DE)
        core->sprites[0].unk_00[1] = 7;
#else
        core->sprites[0].unk_00[1] = 6;
#endif
        core->sprites[1].unk_00[0] = 11;
    }
#endif
}

void EraseNameInputCharacter(NewGameNameInputCore * core, u8 index)
{
#if defined(REGION_JP)
    u8 byte_index = index * 2;
    for (; byte_index < 10; byte_index += 2) {
        core->name[byte_index] = core->name[byte_index + 2];
        core->name[byte_index + 1] = core->name[byte_index + 3];
    }
    core->name[10] = 0x81;
    core->name[11] = 0x51;
#else
    for (; index < 11; index++)
        core->name[index] = core->name[index + 1];
    core->name[11] = '_';
#endif
}

bool NormalizeNameInput(NewGameNameInputCore * core)
{
    int length = 0;
    int blank_count = 0;
    strcpy(reinterpret_cast<char *>(core->normalized_name), core->name);

    // Scan all fixed slots, not strlen(name). Spaces count as blank characters
    // but remain significant at the end of a nonblank name; placeholders do not.
    for (int index = 0, next = 0; index < 12; index = next) {
#if defined(REGION_JP)
        u32 high = core->normalized_name[index] << 8;
        u32 character = core->normalized_name[index + 1] | high;
        if (character == 0x8151) {
            blank_count++;
            next = index + 2;
        } else {
            if (character == 0x8140)
                blank_count++;
            length = index + 2;
            next = length;
        }
#else
        u32 character = core->normalized_name[index];
        if (character == '_') {
            blank_count++;
            next = index + 1;
        } else {
            if (character == ' ')
                blank_count++;
            length = index + 1;
            next = length;
        }
#endif
    }
#if defined(REGION_JP)
    if (blank_count == 6)
#else
    if (blank_count == 12)
#endif
        length = 0;
    else {
#if defined(REGION_JP)
        for (int index = 0; index < length; index += 2) {
            u32 high = core->normalized_name[index] << 8;
            u32 character = core->normalized_name[index + 1] | high;
            if (character == 0x8151) {
                core->normalized_name[index] = 0x81;
                core->normalized_name[index + 1] = 0x40;
            }
        }
#else
        for (int index = 0; index < length; index++)
            if (core->normalized_name[index] == '_')
                core->normalized_name[index] = ' ';
#endif
    }
    core->normalized_name[length] = 0;
    return length != 0;
}

void ProcessNameInputKeys(NewGameNameInputCore * core)
{
    if (core->unk_463c != 0)
        return;
    MoveNameInputKeyboardCursor(core);
    u32 input = GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core));
    if (reinterpret_cast<u8 const *>(&input)[0] & A_BUTTON) {
        if (static_cast<i8>(core->sprites[0].unk_00[1]) < NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE) {
            core->music_player_2.Start(AUDIO_SFX_PICK_UP_ITEM);
            InsertNameInputCharacter(core);
        } else {
            if (static_cast<i8>(core->sprites[0].unk_00[0]) <= 4) {
                if (core->keyboard_page == NEW_GAME_NAME_ENTRY_PAGE_COUNT - 1)
                    core->keyboard_page = 0;
                else
                    core->keyboard_page++;
                core->keyboard_redraw_pending = 1;
                core->music_player_2.Start(AUDIO_SEQUENCE_202);
            } else if (static_cast<u8>(core->sprites[0].unk_00[0] - 5) <= 4) {
                if (core->keyboard_page == 0)
                    core->keyboard_page = NEW_GAME_NAME_ENTRY_PAGE_COUNT - 1;
                else
                    core->keyboard_page--;
                core->keyboard_redraw_pending = 1;
                core->music_player_2.Start(AUDIO_SEQUENCE_202);
            } else {
                if (NormalizeNameInput(core)) {
                    core->unk_463c = 1;
                    core->music_player_2.Start(AUDIO_SFX_MENU_CONFIRM);
                } else
                    core->music_player_2.Start(AUDIO_SFX_INCORRECT_ANSWER);
            }
        }
    } else if (reinterpret_cast<u8 const *>(&input)[0] & B_BUTTON) {
        if (core->sprites[1].unk_00[0] != 0) {
            core->sprites[1].unk_00[0]--;
            EraseNameInputCharacter(core, core->sprites[1].unk_00[0]);
            core->music_player_2.Start(AUDIO_SFX_THROW_ITEM);
        } else {
            u8 placeholder_count = 0;
#if defined(REGION_JP)
            for (int index = 0; index < 12; index += 2) {
                u16 character = (static_cast<u8>(core->name[index]) << 8)
                    | static_cast<u8>(core->name[index + 1]);
                if (character == 0x8151)
                    placeholder_count++;
            }
            if (placeholder_count == 6)
#else
            for (int index = 0; index < 12; index++)
                if (core->name[index] == '_')
                    placeholder_count++;
            if (placeholder_count == 12)
#endif
                core->music_player_2.Start(AUDIO_SFX_INCORRECT_ANSWER);
            else {
                EraseNameInputCharacter(core, 0);
                core->music_player_2.Start(AUDIO_SFX_THROW_ITEM);
            }
        }
#if defined(REGION_JP)
    } else if (reinterpret_cast<u8 const *>(&input)[0] & SELECT_BUTTON) {
        if (core->keyboard_page == NEW_GAME_NAME_ENTRY_PAGE_COUNT - 1)
            core->keyboard_page = 0;
        else
            core->keyboard_page++;
        core->keyboard_redraw_pending = 1;
        core->music_player_2.Start(AUDIO_SEQUENCE_202);
#endif
    } else if (reinterpret_cast<u8 const *>(&input)[0] & START_BUTTON) {
        if (static_cast<i8>(core->sprites[0].unk_00[1]) == NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE
                && static_cast<i8>(core->sprites[0].unk_00[0]) > 9
                && static_cast<i8>(core->sprites[0].unk_00[0]) <= 14) {
            if (NormalizeNameInput(core))
                core->unk_463c = 1;
            core->music_player_2.Start(AUDIO_SFX_MENU_CONFIRM);
        } else {
            core->sprites[0].unk_00[0] = 12;
            core->sprites[0].unk_00[1] = NEW_GAME_NAME_ENTRY_ROWS_PER_PAGE;
            core->music_player_2.Start(AUDIO_SFX_MENU_CURSOR);
        }
    } else if (reinterpret_cast<u8 const *>(&input)[1] & (L_BUTTON >> 8)) {
        if (core->sprites[1].unk_00[0] != 0)
            core->sprites[1].unk_00[0]--;
        core->music_player_2.Start(AUDIO_SFX_MENU_CURSOR);
    } else if (reinterpret_cast<u8 const *>(&input)[1] & (R_BUTTON >> 8)) {
#if defined(REGION_JP)
        if (core->sprites[1].unk_00[0] != 5)
#else
        if (core->sprites[1].unk_00[0] != 11)
#endif
            core->sprites[1].unk_00[0]++;
        core->music_player_2.Start(AUDIO_SFX_MENU_CURSOR);
    }
}

void UpdateNameInputConfirmation(NewGameNameInputCore * core)
{
    if (core->unk_463c != 0) {
        i32 previous_state = core->ui_state->GetState();
        UiStateOwner * ui = core->ui_state;
        HardwareCoreState * state = static_cast<HardwareCoreState *>(
            GetHardwareCoreState(reinterpret_cast<void * const *>(core)));
        HardwareSpriteBufferState * sprites =
            GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
        HardwareDisplayState * display =
            GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
        HardwareLinkedList * links = GetHardwareCommandList(reinterpret_cast<void * const *>(core));
        HardwareInterruptList * manager = GetHardwareInterruptList(reinterpret_cast<void * const *>(core));
        HardwareMusicPlayerSlot * music = &core->music_player_1;
        switch (ui->Update(state, sprites, display, links, manager, music)) {
        case 0:
            if (core->unk_after_keyboard_redraw[0]) {
                core->unk_463c = 0;
                core->unk_after_keyboard_redraw[0] = 0;
            }
            if (core->unk_after_keyboard_redraw[1]) {
                core->unk_after_keyboard_redraw[1] = 0;
                core->finished = 1;
                strcpy(core->name, reinterpret_cast<char const *>(core->normalized_name));
            }
            func_08050D5C(core->ui_state);
            break;
        case 3:
            switch (previous_state) {
            default:
                func_08050D74(reinterpret_cast<void * const *>(core->ui_state));
                break;
            case 1:
                if (core->unk_463c == 1) {
                    func_08050E30(core->ui_state,
                        gText_NewGameNameEntry_Confirm, gText_NewGameNameEntry_Yes,
                        gText_NewGameNameEntry_No, nullptr, nullptr, nullptr);
                }
                break;
            case 4:
            case 5:
                break;
            case 6:
                {
                    u32 selection = core->ui_state->GetChoiceResult();
                    switch (selection) {
                    case 1:
                        core->unk_after_keyboard_redraw[1] = selection;
                        break;
                    case 2:
                        core->unk_after_keyboard_redraw[0] = 1;
                        break;
                    }
                }
                break;
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
}

NewGameNameInputScene::NewGameNameInputScene(char const * prompt,
    char const * initial_name)
{
    core = new NewGameNameInputCore(prompt, initial_name);
}

NewGameNameInputScene::~NewGameNameInputScene()
{
    delete core;
}

SceneTransitionOwner NewGameNameInputScene::Run()
{
    return RunNameInputCore(core);
}

char const * NewGameNameInputScene::GetName() const
{
    return core->name;
}

char const * GetNameInputCoreName(NewGameNameInputCore const * core)
{
    return core->name;
}
