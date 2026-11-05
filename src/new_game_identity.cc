#include "prelude.h"
#pragma implementation "new_game_identity.hh"
#include "new_game_identity.hh"
#include "hardware_context.hh"
#include "new_game_data.hh"
#include "hardware_state_accessors.hh"
#include "hardware_blend_object.hh"
#include "hardware_music_player.hh"
#include "hardware_song.hh"
#include "fomt_constants.hh"
#include "gbaio.h"
#include "font.hh"
#include "time_of_day.hh"
#include <string.h>
#pragma implementation

void * operator new(unsigned long);
void operator delete(void *);
inline void * operator new(unsigned long, void * storage) { return storage; }
inline void * operator new[](unsigned long, void * storage) { return storage; }

static inline void AppendIdentityField(FixedStr<15> & field, char const * text)
{
    char * start = &field[0];
    u32 size = strlen(start);
    char * end = start + size;
    u32 available = sizeof(field) - 1 - size;
    if (available != 0) {
        u32 length = strlen(text);
        if (length > available)
            length = available;
        memcpy(end, text, length);
        end[length] = '\0';
    }
}

NewGameIdentityCore * InitializeNewGameIdentityCore(NewGameIdentityCore * core,
    char const * player_name, GameDate birthday, char const * farm_name,
    char const * dog_name)
{
    ConstructHardwareContext(core);
    InstallHardwareContextNativeVTable(core, __vt_19NewGameIdentityCore);
#if defined(REGION_JP)
    new (core->buffers) NewGameIdentityValueBuffer[2 * NEW_GAME_IDENTITY_FIELD_COUNT];
#else
    new (core->value_buffers) NewGameIdentityValueBuffer[NEW_GAME_IDENTITY_FIELD_COUNT];
    new (core->label_buffers) NewGameIdentityLabelBuffer[NEW_GAME_IDENTITY_FIELD_COUNT];
#endif
    core->unk_1A28 = 2;
    UiStateOwner * storage = static_cast<UiStateOwner *>(::operator new(sizeof(UiStateOwner)));
    {
        ObjTileCollection shared;
        ObjPaletteCollection resources;
        UiStateOwner * ui = new (storage) UiStateOwner(0, 28, 4, 0, shared, resources);
        core->ui_state = ui;
    }
    // Borrow the player assigned to this SFX for the confirmation UI.
    core->music = GetHardwareSongPlayerSlot(AUDIO_SFX_KAPPA_SURPRISE);
    new (core->fields) FixedStr<15>[NEW_GAME_IDENTITY_FIELD_COUNT];
    core->confirmed = 0;
    core->fields[NEW_GAME_IDENTITY_PLAYER_NAME] = player_name;

    char day[16];
#if defined(REGION_JP)
    FormatFullWidthDecimal(birthday.GetDay() + 1, day, 2);
#else
    FormatSignedDecimal(birthday.GetDay() + 1, day, 2);
#endif
    CalendarSeasonLabel season_name = GetCalendarSeasonLabel(birthday.GetSeason());
    FixedStr<15> & date = core->fields[NEW_GAME_IDENTITY_BIRTHDAY];
    AppendIdentityField(date, season_name);
#if defined(REGION_JP)
    AppendIdentityField(date, gText_NewGameIdentity_BirthMonthSuffix);
#endif
    AppendIdentityField(date, day);
#if defined(REGION_JP)
    AppendIdentityField(date, gText_NewGameIdentity_BirthDaySuffix);
#endif
    core->fields[NEW_GAME_IDENTITY_FARM_NAME] = farm_name;
    core->fields[NEW_GAME_IDENTITY_DOG_NAME] = dog_name;
    return core;
}

static inline void QueueIdentityBlend(HardwareContext * core, HardwareBlendOwner const & owner)
{
    HardwareLinkedList * list =
        GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    list->Append(owner.object);
}

NewGameIdentityCore::~NewGameIdentityCore()
{
    if (ui_state != nullptr)
        delete ui_state;
}

SceneTransitionOwner RunNewGameIdentityCore(NewGameIdentityCore * core)
{
    BlankNewGameIdentityDisplay(core);
    ResetNewGameIdentityControl(core);
    InitializeNewGameIdentityScreen(core);

    HardwareDisplayState * display =
        GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    HardwareDisplayRegisterValue control(BLDCNT_TGT1_ALL);
    display->SetBlendControl(control);

    HardwareBlendOwner owner(new HardwareBlendObject(
        GetHardwareDisplayState(reinterpret_cast<void * const *>(core))));
    BeginHardwareBlend(&owner.object->blend, 0x889, 1, 1);
    QueueIdentityBlend(core, owner);

    i16 phase = 0;
    bool finished = false;
    do
    {
        UpdateHardwareFrame(core);
        UpdateHardwareInput(reinterpret_cast<void * const *>(core));
        GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(core));
        switch (phase)
        {
        case 0:
            if (!owner.IsQueued())
                phase = 1;
            break;
        case 1:
            UpdateNewGameIdentityDialog(core);
            if (core->unk_1A74 != 0)
                phase = 2;
            break;
        case 2:
            EndHardwareBlend(&owner.object->blend, 0x889, 1, 1);
            QueueIdentityBlend(core, owner);
            phase = 3;
            break;
        case 3:
            if (!owner.IsQueued())
                finished = true;
            break;
        }
    } while (!finished);
    return SceneTransitionOwner();
}

void BlankNewGameIdentityDisplay(NewGameIdentityCore * core)
{
    EnableHardwareForcedBlank(core);
}

void ResetNewGameIdentityControl(NewGameIdentityCore * core)
{
    core->unk_1A75 = 0;
    core->unk_1A74 = 0;
}

NAKED void InitializeNewGameIdentityScreen(NewGameIdentityCore * core)
{
    asm_unified(
        ".include \"six/asm/hw/memory.s\"\n"
        ".include \"six/asm/hw/video.s\"\n"
#if defined(REGION_JP)
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x70\n"
        "    mov sl, r0\n"
        "    ldr r0, .Ljp_080054B0\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .Ljp_080054B4\n"
        "    ldr r2, .Ljp_080054B8\n"
        "    ldr r2, [r2]\n"
        "    bl CopyHardwareDma3\n"
        "    ldr r0, .Ljp_080054BC\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #(BG_PALETTE >> 19)\n"
        "    lsls r1, r1, #0x13\n"
        "    movs r2, #PLTT_SIZE_4BPP\n"
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
        "    ldr r5, .Ljp_080054C0\n"
        "    adds r1, r5, #0\n"
        "    strh r1, [r2]\n"
        "    strh r1, [r0, #0xa]\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDisplayState\n"
        "    add r2, sp, #0xc\n"
        "    ldr r3, .Ljp_080054C4\n"
        "    adds r1, r3, #0\n"
        "    strh r1, [r2]\n"
        "    strh r1, [r0, #0xc]\n"
        "    ldr r0, .Ljp_080054C8\n"
        "    movs r1, #0x14\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x96\n"
        "    lsls r1, r1, #2\n"
        "    str r1, [sp, #4]\n"
        "    str r4, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x1e\n"
        "    bl DrawUiTextWindowBorder\n"
        "    ldr r1, .Ljp_080054CC\n"
        "    movs r0, #0\n"
        "    movs r2, #0x20\n"
        "    bl FillHardwareDma3\n"
        "    movs r7, #0\n"
        "    add r5, sp, #0x20\n"
        "    add r4, sp, #0x24\n"
        "    mov sb, r4\n"
        "    mov r0, sp\n"
        "    adds r0, #0x28\n"
        "    str r0, [sp, #0x44]\n"
        "    mov r1, sp\n"
        "    adds r1, #0x2c\n"
        "    str r1, [sp, #0x4c]\n"
        "    mov r2, sp\n"
        "    adds r2, #0x30\n"
        "    str r2, [sp, #0x50]\n"
        "    mov r3, sp\n"
        "    adds r3, #0x34\n"
        "    str r3, [sp, #0x54]\n"
        "    mov r4, sp\n"
        "    adds r4, #0x10\n"
        "    str r4, [sp, #0x60]\n"
        "    movs r0, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) "\n"
        "    mov r8, r0\n"
        "    movs r6, #" STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) "\n"
        "    mov r4, sl\n"
        "    adds r4, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILES_OFFSET) "\n"
        ".Ljp_08005398:\n"
        "    add r0, sp, #0x20\n"
        "    mov r1, r8\n"
        "    strh r1, [r0]\n"
        "    strh r6, [r5, #2]\n"
        "    ldr r0, [sp, #0x20]\n"
        "    adds r1, r4, #0\n"
        "    movs r2, #0\n"
        "    bl Clear2DGfxBuffer\n"
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
        "    movs r2, #((" STRINGIFY(NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) ") >> 2)\n"
        "    lsls r2, r2, #2\n"
#else
        "    ldr r2, .Lidentity_jp_first_value_stride\n"
#endif
        "    adds r4, r4, r2\n"
        "    adds r7, #1\n"
        "    cmp r7, #(2 * " STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bls .Ljp_08005398\n"
        "    movs r7, #0\n"
        "    ldr r3, .Ljp_080054D0\n"
        "    add r3, sl\n"
        "    mov r8, r3\n"
#if ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 4) <= 255
        "    movs r4, #((" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILES_OFFSET) " + " STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ") >> 4)\n"
        "    lsls r4, r4, #4\n"
#else
        "    ldr r4, .Lidentity_jp_first_label1\n"
#endif
        "    add r4, sl\n"
        "    str r4, [sp, #0x48]\n"
        "    ldr r5, .Ljp_080054D4\n"
        "    add r5, sl\n"
        "    str r5, [sp, #0x5c]\n"
        "    ldr r0, .Ljp_080054D8\n"
        "    add r0, sl\n"
        "    str r0, [sp, #0x58]\n"
        "    movs r6, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) "\n"
        "    movs r5, #" STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) "\n"
        "    mov r4, sl\n"
        "    adds r4, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILES_OFFSET) "\n"
        ".Ljp_080053DA:\n"
        "    lsls r1, r7, #4\n"
        "    add r1, sl\n"
        "    ldr r2, .Ljp_080054DC\n"
        "    adds r1, r1, r2\n"
        "    add r0, sp, #0x24\n"
        "    strh r6, [r0]\n"
        "    mov r3, sb\n"
        "    strh r5, [r3, #2]\n"
        "    ldr r0, [sp, #0x24]\n"
        "    str r1, [sp]\n"
        "    adds r1, r4, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
        "    movs r0, #((" STRINGIFY(NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) ") >> 2)\n"
        "    lsls r0, r0, #2\n"
#else
        "    ldr r0, .Lidentity_jp_first_value_stride\n"
#endif
        "    adds r4, r4, r0\n"
        "    adds r7, #1\n"
        "    cmp r7, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bls .Ljp_080053DA\n"
        "    ldr r1, .Ljp_080054E0\n"
        "    movs r4, #" STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) "\n"
        "    movs r5, #" STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) "\n"
        "    add r0, sp, #0x28\n"
        "    strh r4, [r0]\n"
        "    ldr r2, [sp, #0x44]\n"
        "    strh r5, [r2, #2]\n"
        "    ldr r0, [sp, #0x28]\n"
        "    str r1, [sp]\n"
        "    mov r1, r8\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    ldr r1, .Ljp_080054E4\n"
        "    add r0, sp, #0x2c\n"
        "    strh r4, [r0]\n"
        "    ldr r3, [sp, #0x4c]\n"
        "    strh r5, [r3, #2]\n"
        "    ldr r0, [sp, #0x2c]\n"
        "    str r1, [sp]\n"
        "    ldr r1, [sp, #0x48]\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    ldr r1, .Ljp_080054E8\n"
        "    add r0, sp, #0x30\n"
        "    strh r4, [r0]\n"
        "    ldr r0, [sp, #0x50]\n"
        "    strh r5, [r0, #2]\n"
        "    ldr r0, [sp, #0x30]\n"
        "    str r1, [sp]\n"
        "    ldr r1, [sp, #0x5c]\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    ldr r1, .Ljp_080054EC\n"
        "    add r0, sp, #0x34\n"
        "    strh r4, [r0]\n"
        "    ldr r2, [sp, #0x54]\n"
        "    strh r5, [r2, #2]\n"
        "    ldr r0, [sp, #0x34]\n"
        "    str r1, [sp]\n"
        "    ldr r1, [sp, #0x58]\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    movs r7, #0\n"
        "    ldr r3, [sp, #0x60]\n"
        "    str r3, [sp, #0x40]\n"
        "    movs r4, #(MEM_VRAM >> 19)\n"
        "    lsls r4, r4, #0x13\n"
        "    str r4, [sp, #0x64]\n"
        "    mov r5, sl\n"
        "    adds r5, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILES_OFFSET) "\n"
        "    str r5, [sp, #0x68]\n"
        ".Ljp_0800547A:\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDmaQueue\n"
        "    adds r6, r0, #0\n"
        "    add r0, sp, #0x10\n"
        "    ldr r1, [sp, #0x68]\n"
        "    ldr r2, [sp, #0x64]\n"
#if ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ") >> 2)\n"
        "    lsls r3, r3, #2\n"
#else
        "    ldr r3, .Lidentity_jp_first_value_bytes\n"
#endif
        "    bl __21DmaTransferDescriptorPCvPvUi\n"
        "    ldr r1, [r6, #4]\n"
        "    ldr r0, [r6, #0xc]\n"
        "    cmp r1, r0\n"
        "    beq .Ljp_080054F0\n"
        "    cmp r1, #0\n"
        "    beq .Ljp_080054A8\n"
        "    adds r0, r1, #0\n"
        "    ldr r1, [sp, #0x40]\n"
        "    ldm r1!, {r2, r3, r4}\n"
        "    stm r0!, {r2, r3, r4}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_080054A8:\n"
        "    ldr r0, [r6, #4]\n"
        "    adds r0, #0x10\n"
        "    str r0, [r6, #4]\n"
        "    b .Ljp_080055BA\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 4) <= 255)
        ".Lidentity_jp_first_label1: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILES_OFFSET) " + " STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ")\n"
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255)
        ".Lidentity_jp_first_value_stride: .word (" STRINGIFY(NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) ")\n"
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255)
        ".Lidentity_jp_first_value_bytes: .word (" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ")\n"
#endif
        ".Ljp_080054B0: .word gUiSharedTiles\n"
        ".Ljp_080054B4: .word (MEM_VRAM + 0x4B00)\n"
        ".Ljp_080054B8: .word gUiSharedTileByteCount\n"
        ".Ljp_080054BC: .word gUiSharedPalette\n"
        ".Ljp_080054C0: .word (BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        ".Ljp_080054C4: .word (BG_PRIO_1 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        ".Ljp_080054C8: .word (MEM_VRAM + 31 * BG_SCREEN_SIZE)\n"
        "@ Preserve the native mirrored VRAM destination; this is not BG screen block 24.\n"
        ".Ljp_080054CC: .word (MEM_VRAM + 0xFFC000)\n"
        ".Ljp_080054D0: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILES_OFFSET) ")\n"
        ".Ljp_080054D4: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILES_OFFSET) " + 2 * " STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ")\n"
        ".Ljp_080054D8: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILES_OFFSET) " + 3 * " STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ")\n"
        ".Ljp_080054DC: .word (" STRINGIFY(NEW_GAME_IDENTITY_CORE_FIELDS_OFFSET) ")\n"
        ".Ljp_080054E0: .word gText_NewGameIdentity_PlayerName\n"
        ".Ljp_080054E4: .word gText_NewGameIdentity_PlayerBirthday\n"
        ".Ljp_080054E8: .word gText_NewGameIdentity_FarmName\n"
        ".Ljp_080054EC: .word gText_NewGameIdentity_DogName\n"
        ".Ljp_080054F0:\n"
        "    mov r8, r1\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0x3c]\n"
        "    ldr r0, [r6]\n"
        "    subs r0, r1, r0\n"
        "    asrs r4, r0, #4\n"
        "    str r4, [sp, #0x38]\n"
        "    add r1, sp, #0x3c\n"
        "    add r0, sp, #0x38\n"
        "    cmp r4, #1\n"
        "    bhs .Ljp_08005508\n"
        "    adds r0, r1, #0\n"
        ".Ljp_08005508:\n"
        "    ldr r0, [r0]\n"
        "    adds r0, r4, r0\n"
        "    cmp r0, #0\n"
        "    beq .Ljp_08005526\n"
        "    lsls r4, r0, #4\n"
        "    adds r0, r4, #0\n"
        "    bl malloc\n"
        "    mov sb, r4\n"
        "    cmp r0, #0\n"
        "    bne .Ljp_0800552A\n"
        "    mov r0, sb\n"
        "    bl RetryMemoryAllocation\n"
        "    b .Ljp_0800552A\n"
        ".Ljp_08005526:\n"
        "    movs r0, #0\n"
        "    mov sb, r0\n"
        ".Ljp_0800552A:\n"
        "    adds r5, r0, #0\n"
        "    str r5, [sp, #0x6c]\n"
        "    ldr r2, [r6]\n"
        "    mov ip, r5\n"
        "    cmp r2, r8\n"
        "    beq .Ljp_08005552\n"
        ".Ljp_08005536:\n"
        "    mov r5, ip\n"
        "    cmp r5, #0\n"
        "    beq .Ljp_08005548\n"
        "    mov r0, ip\n"
        "    adds r1, r2, #0\n"
        "    ldm r1!, {r3, r4, r5}\n"
        "    stm r0!, {r3, r4, r5}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_08005548:\n"
        "    adds r2, #0x10\n"
        "    movs r0, #0x10\n"
        "    add ip, r0\n"
        "    cmp r2, r8\n"
        "    bne .Ljp_08005536\n"
        ".Ljp_08005552:\n"
        "    mov r5, ip\n"
        "    ldr r0, [sp, #0x3c]\n"
        "    cmp r0, #1\n"
        "    bne .Ljp_0800556E\n"
        "    cmp r5, #0\n"
        "    beq .Ljp_0800556A\n"
        "    adds r0, r5, #0\n"
        "    ldr r1, [sp, #0x40]\n"
        "    ldm r1!, {r2, r3, r4}\n"
        "    stm r0!, {r2, r3, r4}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_0800556A:\n"
        "    adds r5, #0x10\n"
        "    b .Ljp_08005596\n"
        ".Ljp_0800556E:\n"
        "    mov r8, r0\n"
        "    adds r2, r5, #0\n"
        "    cmp r0, #0\n"
        "    beq .Ljp_08005594\n"
        ".Ljp_08005576:\n"
        "    cmp r2, #0\n"
        "    beq .Ljp_08005586\n"
        "    adds r0, r2, #0\n"
        "    ldr r1, [sp, #0x40]\n"
        "    ldm r1!, {r3, r4, r5}\n"
        "    stm r0!, {r3, r4, r5}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".Ljp_08005586:\n"
        "    movs r5, #1\n"
        "    rsbs r5, r5, #0\n"
        "    add r8, r5\n"
        "    adds r2, #0x10\n"
        "    mov r0, r8\n"
        "    cmp r0, #0\n"
        "    bne .Ljp_08005576\n"
        ".Ljp_08005594:\n"
        "    adds r5, r2, #0\n"
        ".Ljp_08005596:\n"
        "    ldr r2, [r6, #4]\n"
        "    ldr r0, [r6]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, r2\n"
        "    beq .Ljp_080055A6\n"
        ".Ljp_080055A0:\n"
        "    adds r1, #0x10\n"
        "    cmp r1, r2\n"
        "    bne .Ljp_080055A0\n"
        ".Ljp_080055A6:\n"
        "    cmp r0, #0\n"
        "    beq .Ljp_080055AE\n"
        "    bl free\n"
        ".Ljp_080055AE:\n"
        "    ldr r0, [sp, #0x6c]\n"
        "    add r0, sb\n"
        "    ldr r1, [sp, #0x6c]\n"
        "    str r1, [r6]\n"
        "    str r5, [r6, #4]\n"
        "    str r0, [r6, #0xc]\n"
        ".Ljp_080055BA:\n"
        "    ldr r2, [sp, #0x64]\n"
#if ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ") >> 2)\n"
        "    lsls r3, r3, #2\n"
#else
        "    ldr r3, .Lidentity_jp_last_value_bytes\n"
#endif
        "    adds r2, r2, r3\n"
        "    str r2, [sp, #0x64]\n"
        "    ldr r4, [sp, #0x68]\n"
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
        "    movs r5, #((" STRINGIFY(NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) ") >> 2)\n"
        "    lsls r5, r5, #2\n"
#else
        "    ldr r5, .Lidentity_jp_last_value_stride\n"
#endif
        "    adds r4, r4, r5\n"
        "    str r4, [sp, #0x68]\n"
        "    adds r7, #1\n"
        "    cmp r7, #(2 * " STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bhi .Ljp_080055D6\n"
        "    b .Ljp_0800547A\n"
        ".Ljp_080055D6:\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    ldr r4, .Ljp_080056BC\n"
        "    movs r2, #(BG_SCREEN_SIZE >> 4)\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r4, #0\n"
        "    bl FillHardwareDma3\n"
        "    movs r7, #0\n"
        "    @ Blank tile from the second (full-width space) DogName label glyph.\n"
        "    @ Keep that label space: the map reuses its empty upper-left tile.\n"
        "    movs r1, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " * " STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) " + 3 * " STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) " + 2)\n"
        ".Ljp_080055EA:\n"
        "    movs r5, #0\n"
        "    lsls r0, r7, #6\n"
        "    adds r0, r0, r4\n"
        ".Ljp_080055F0:\n"
        "    strh r1, [r0]\n"
        "    adds r0, #2\n"
        "    adds r5, #1\n"
        "    cmp r5, #0x1d\n"
        "    bls .Ljp_080055F0\n"
        "    adds r7, #1\n"
        "    cmp r7, #0x13\n"
        "    bls .Ljp_080055EA\n"
        "    movs r5, #2\n"
        "    ldr r6, .Ljp_080056C0\n"
        ".Ljp_08005604:\n"
        "    movs r7, #0\n"
        "    lsls r1, r5, #1\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " * " STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) " - 2)\n"
        "    adds r3, r5, #0\n"
        "    adds r3, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " * " STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) " - 2)\n"
        "    ldr r0, .Ljp_080056C4\n"
        "    adds r2, r1, r0\n"
        ".Ljp_08005614:\n"
        "    strh r3, [r2]\n"
        "    adds r0, r1, r6\n"
        "    strh r4, [r0]\n"
        "    adds r4, #(" STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) ")\n"
        "    adds r3, #(" STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) ")\n"
        "    adds r2, #(3 * 32 * 2)\n"
        "    adds r1, #(3 * 32 * 2)\n"
        "    adds r7, #1\n"
        "    cmp r7, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bls .Ljp_08005614\n"
        "    adds r5, #1\n"
        "    cmp r5, #(2 + " STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) " - 1)\n"
        "    bls .Ljp_08005604\n"
        "    movs r5, #0x10\n"
        "    ldr r1, .Ljp_080056C8\n"
        "    mov r8, r1\n"
        "    ldr r2, .Ljp_080056C0\n"
        "    mov sb, r2\n"
        ".Ljp_08005638:\n"
        "    movs r7, #0\n"
        "    lsls r1, r5, #1\n"
        "    adds r6, r5, #1\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) "\n"
        "    mov r3, r8\n"
        "    adds r4, r0, r3\n"
        "    adds r3, r5, r3\n"
        "    ldr r5, .Ljp_080056C4\n"
        "    adds r2, r1, r5\n"
        ".Ljp_0800564C:\n"
        "    strh r3, [r2]\n"
        "    mov r5, sb\n"
        "    adds r0, r1, r5\n"
        "    strh r4, [r0]\n"
        "    adds r4, #(" STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) ")\n"
        "    adds r3, #(" STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) ")\n"
        "    adds r2, #(3 * 32 * 2)\n"
        "    adds r1, #(3 * 32 * 2)\n"
        "    adds r7, #1\n"
        "    cmp r7, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bls .Ljp_0800564C\n"
        "    adds r5, r6, #0\n"
        "    cmp r5, #(16 + " STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " - 1)\n"
        "    bls .Ljp_08005638\n"
        "    ldr r0, .Ljp_080056CC\n"
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
        "    ldr r1, .Ljp_080056D0\n"
        "    add r1, sl\n"
        "    str r4, [sp]\n"
        "    str r0, [sp, #4]\n"
        "    str r1, [sp, #8]\n"
        "    mov r0, sb\n"
        "    mov r1, r8\n"
        "    adds r2, r6, #0\n"
        "    adds r3, r5, #0\n"
        "    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot\n"
        "    add sp, #0x70\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255)
        ".Lidentity_jp_last_value_stride: .word (" STRINGIFY(NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) ")\n"
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255)
        ".Lidentity_jp_last_value_bytes: .word (" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ")\n"
#endif
        ".Ljp_080056BC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE)\n"
        ".Ljp_080056C0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 2 * 32 * 2)\n"
        ".Ljp_080056C4: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 32 * 2)\n"
        ".Ljp_080056C8: .word (0x10000 - 16)\n"
        ".Ljp_080056CC: .word (" STRINGIFY(NEW_GAME_IDENTITY_CORE_UI_OFFSET) ")\n"
        ".Ljp_080056D0: .word (" STRINGIFY(NEW_GAME_IDENTITY_CORE_MUSIC_OFFSET) ")\n"
#else
        "    push {r4, r5, r6, r7, lr}\n"
        "    mov r7, sl\n"
        "    mov r6, sb\n"
        "    mov r5, r8\n"
        "    push {r5, r6, r7}\n"
        "    sub sp, #0x94\n"
        "    mov sl, r0\n"
        "    ldr r0, .L08005488 @ =gUiSharedTiles\n"
        "    ldr r0, [r0]\n"
        "    ldr r1, .L0800548C @ =(MEM_VRAM + 0x4B00)\n"
        "    ldr r2, .L08005490 @ =gUiSharedTileByteCount\n"
        "    ldr r2, [r2]\n"
        "    bl CopyHardwareDma3\n"
        "    ldr r0, .L08005494 @ =gUiSharedPalette\n"
        "    ldr r0, [r0]\n"
        "    movs r1, #(BG_PALETTE >> 19)\n"
        "    lsls r1, r1, #0x13\n"
        "    movs r2, #PLTT_SIZE_4BPP\n"
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
        "    ldr r5, .L08005498 @ =(BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        "    adds r1, r5, #0\n"
        "    strh r1, [r2]\n"
        "    strh r1, [r0, #0xa]\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDisplayState\n"
        "    add r2, sp, #0xc\n"
        "    ldr r7, .L0800549C @ =(BG_PRIO_1 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        "    adds r1, r7, #0\n"
        "    strh r1, [r2]\n"
        "    strh r1, [r0, #0xc]\n"
        "    ldr r0, .L080054A0 @ =(MEM_VRAM + 31 * BG_SCREEN_SIZE)\n"
        "    movs r1, #0x14\n"
        "    str r1, [sp]\n"
        "    movs r1, #0x96\n"
        "    lsls r1, r1, #2\n"
        "    str r1, [sp, #4]\n"
        "    str r4, [sp, #8]\n"
        "    movs r1, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0x1e\n"
        "    bl DrawUiTextWindowBorder\n"
        "    ldr r1, .L080054A4 @ =(MEM_VRAM + 0xFFC000)\n"
        "    movs r0, #0\n"
        "    movs r2, #0x20\n"
        "    bl FillHardwareDma3\n"
        "    movs r0, #0\n"
        "    mov r8, r0\n"
        "    add r5, sp, #0x20\n"
        "    add r1, sp, #0x24\n"
        "    mov sb, r1\n"
        "    mov r2, sp\n"
        "    adds r2, #0x28\n"
        "    str r2, [sp, #0x64]\n"
        "    mov r3, sp\n"
        "    adds r3, #0x2c\n"
        "    str r3, [sp, #0x68]\n"
        "    mov r4, sp\n"
        "    adds r4, #0x30\n"
        "    str r4, [sp, #0x70]\n"
        "    mov r7, sp\n"
        "    adds r7, #0x34\n"
        "    str r7, [sp, #0x74]\n"
        "    mov r0, sp\n"
        "    adds r0, #0x38\n"
        "    str r0, [sp, #0x78]\n"
        "    mov r1, sp\n"
        "    adds r1, #0x10\n"
        "    str r1, [sp, #0x5c]\n"
        "    movs r7, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) "\n"
        "    movs r6, #" STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) "\n"
        "    mov r4, sl\n"
        "    adds r4, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILES_OFFSET) "\n"
        ".L0800532E:\n"
        "    add r0, sp, #0x20\n"
        "    strh r7, [r0]\n"
        "    strh r6, [r5, #2]\n"
        "    ldr r0, [sp, #0x20]\n"
        "    adds r1, r4, #0\n"
        "    movs r2, #0\n"
        "    bl Clear2DGfxBuffer\n"
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
        "    movs r2, #((" STRINGIFY(NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) ") >> 2)\n"
        "    lsls r2, r2, #2\n"
#else
        "    ldr r2, .Lidentity_overseas_first_value_stride\n"
#endif
        "    adds r4, r4, r2\n"
        "    movs r3, #1\n"
        "    add r8, r3\n"
        "    mov r0, r8\n"
        "    cmp r0, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bls .L0800532E\n"
        "    movs r1, #0\n"
        "    mov r8, r1\n"
        "    ldr r7, .L080054A8\n"
        "    add r7, sl\n"
#if ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 4) <= 255
        "    movs r2, #((" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILES_OFFSET) " + " STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ") >> 4)\n"
        "    lsls r2, r2, #4\n"
#else
        "    ldr r2, .Lidentity_overseas_first_label1\n"
#endif
        "    add r2, sl\n"
        "    str r2, [sp, #0x54]\n"
        "    ldr r3, .L080054AC\n"
        "    add r3, sl\n"
        "    str r3, [sp, #0x58]\n"
        "    ldr r4, .L080054B0\n"
        "    add r4, sl\n"
        "    str r4, [sp, #0x6c]\n"
        "    movs r6, #" STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) "\n"
        "    movs r5, #" STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) "\n"
        "    ldr r4, .L080054A8\n"
        "    add r4, sl\n"
        ".L08005372:\n"
        "    add r0, sp, #0x24\n"
        "    strh r6, [r0]\n"
        "    mov r0, sb\n"
        "    strh r5, [r0, #2]\n"
        "    ldr r0, [sp, #0x24]\n"
        "    adds r1, r4, #0\n"
        "    movs r2, #0\n"
        "    bl Clear2DGfxBuffer\n"
#if ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 2) <= 255
        "    movs r1, #((" STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ") >> 2)\n"
        "    lsls r1, r1, #2\n"
#else
        "    ldr r1, .Lidentity_overseas_first_label_stride\n"
#endif
        "    adds r4, r4, r1\n"
        "    movs r2, #1\n"
        "    add r8, r2\n"
        "    mov r3, r8\n"
        "    cmp r3, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bls .L08005372\n"
        "    movs r4, #0\n"
        "    mov r8, r4\n"
        "    movs r6, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) "\n"
        "    movs r5, #" STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) "\n"
        "    mov r4, sl\n"
        "    adds r4, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILES_OFFSET) "\n"
        ".L080053A0:\n"
        "    mov r0, r8\n"
        "    lsls r1, r0, #4\n"
        "    add r1, sl\n"
        "    ldr r2, .L080054B4\n"
        "    adds r1, r1, r2\n"
        "    add r0, sp, #0x28\n"
        "    strh r6, [r0]\n"
        "    ldr r3, [sp, #0x64]\n"
        "    strh r5, [r3, #2]\n"
        "    ldr r0, [sp, #0x28]\n"
        "    str r1, [sp]\n"
        "    adds r1, r4, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
        "    movs r0, #((" STRINGIFY(NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) ") >> 2)\n"
        "    lsls r0, r0, #2\n"
#else
        "    ldr r0, .Lidentity_overseas_first_value_stride\n"
#endif
        "    adds r4, r4, r0\n"
        "    movs r1, #1\n"
        "    add r8, r1\n"
        "    mov r2, r8\n"
        "    cmp r2, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bls .L080053A0\n"
        "    ldr r1, .L080054B8 @ =gText_NewGameIdentity_PlayerName\n"
        "    movs r4, #" STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) "\n"
        "    movs r5, #" STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) "\n"
        "    add r0, sp, #0x2c\n"
        "    strh r4, [r0]\n"
        "    ldr r3, [sp, #0x68]\n"
        "    strh r5, [r3, #2]\n"
        "    ldr r0, [sp, #0x2c]\n"
        "    str r1, [sp]\n"
        "    adds r1, r7, #0\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    ldr r1, .L080054BC @ =gText_NewGameIdentity_PlayerBirthday\n"
        "    add r0, sp, #0x30\n"
        "    strh r4, [r0]\n"
        "    ldr r7, [sp, #0x70]\n"
        "    strh r5, [r7, #2]\n"
        "    ldr r0, [sp, #0x30]\n"
        "    str r1, [sp]\n"
        "    ldr r1, [sp, #0x54]\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    ldr r1, .L080054C0 @ =gText_NewGameIdentity_FarmName\n"
        "    add r0, sp, #0x34\n"
        "    strh r4, [r0]\n"
        "    ldr r0, [sp, #0x74]\n"
        "    strh r5, [r0, #2]\n"
        "    ldr r0, [sp, #0x34]\n"
        "    str r1, [sp]\n"
        "    ldr r1, [sp, #0x58]\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    ldr r1, .L080054C4 @ =gText_NewGameIdentity_DogName\n"
        "    add r0, sp, #0x38\n"
        "    strh r4, [r0]\n"
        "    ldr r2, [sp, #0x78]\n"
        "    strh r5, [r2, #2]\n"
        "    ldr r0, [sp, #0x38]\n"
        "    str r1, [sp]\n"
        "    ldr r1, [sp, #0x6c]\n"
        "    movs r2, #0\n"
        "    movs r3, #0\n"
        "    bl DrawStringTo2DGfxBuffer\n"
        "    movs r3, #0\n"
        "    mov r8, r3\n"
        "    ldr r4, [sp, #0x5c]\n"
        "    str r4, [sp, #0x4c]\n"
        "    movs r5, #(MEM_VRAM >> 19)\n"
        "    lsls r5, r5, #0x13\n"
        "    str r5, [sp, #0x84]\n"
        "    mov r7, sl\n"
        "    adds r7, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILES_OFFSET) "\n"
        "    str r7, [sp, #0x88]\n"
        ".L08005448:\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDmaQueue\n"
        "    adds r6, r0, #0\n"
        "    add r0, sp, #0x10\n"
        "    ldr r1, [sp, #0x88]\n"
        "    ldr r2, [sp, #0x84]\n"
#if ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ") >> 2)\n"
        "    lsls r3, r3, #2\n"
#else
        "    ldr r3, .Lidentity_overseas_first_value_bytes\n"
#endif
        "    bl __21DmaTransferDescriptorPCvPvUi\n"
        "    ldr r1, [r6, #4]\n"
        "    ldr r0, [r6, #0xc]\n"
        "    cmp r1, r0\n"
        "    beq .L080054C8\n"
        "    cmp r1, #0\n"
        "    beq .L08005476\n"
        "    adds r0, r1, #0\n"
        "    ldr r1, [sp, #0x4c]\n"
        "    ldm r1!, {r2, r3, r4}\n"
        "    stm r0!, {r2, r3, r4}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08005476:\n"
        "    ldr r0, [r6, #4]\n"
        "    adds r0, #0x10\n"
        "    str r0, [r6, #4]\n"
#if ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 4) <= 255
        "    movs r5, #((" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " * " STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ") >> 4)\n"
        "    lsls r5, r5, #2\n"
        "    lsls r5, r5, #2\n"
#else
        "    ldr r5, .Lidentity_overseas_first_value_span\n"
#endif
        "    str r5, [sp, #0x60]\n"
        "    b .L08005596\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILES_OFFSET + NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 4) <= 255)
        ".Lidentity_overseas_first_label1: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILES_OFFSET) " + " STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ")\n"
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255)
        ".Lidentity_overseas_first_value_stride: .word (" STRINGIFY(NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) ")\n"
#endif
#if !(((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 2) <= 255)
        ".Lidentity_overseas_first_label_stride: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ")\n"
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255)
        ".Lidentity_overseas_first_value_bytes: .word (" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ")\n"
#endif
#if !(((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 4) <= 255)
        ".Lidentity_overseas_first_value_span: .word (" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " * " STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ")\n"
#endif
        ".L08005488: .word gUiSharedTiles\n"
        ".L0800548C: .word (MEM_VRAM + 0x4B00)\n"
        ".L08005490: .word gUiSharedTileByteCount\n"
        ".L08005494: .word gUiSharedPalette\n"
        ".L08005498: .word (BG_PRIO_1 | BG_MOSAIC_ENABLE | (24 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        ".L0800549C: .word (BG_PRIO_1 | (31 << BF_BG_MAP_BASE_OFFSET) | BG_SIZE_256x256)\n"
        ".L080054A0: .word (MEM_VRAM + 31 * BG_SCREEN_SIZE)\n"
        "@ Preserve the native mirrored VRAM destination; this is not BG screen block 24.\n"
        ".L080054A4: .word (MEM_VRAM + 0xFFC000)\n"
        ".L080054A8: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILES_OFFSET) ")\n"
        ".L080054AC: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILES_OFFSET) " + 2 * " STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ")\n"
        ".L080054B0: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILES_OFFSET) " + 3 * " STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ")\n"
        ".L080054B4: .word (" STRINGIFY(NEW_GAME_IDENTITY_CORE_FIELDS_OFFSET) ")\n"
        ".L080054B8: .word gText_NewGameIdentity_PlayerName\n"
        ".L080054BC: .word gText_NewGameIdentity_PlayerBirthday\n"
        ".L080054C0: .word gText_NewGameIdentity_FarmName\n"
        ".L080054C4: .word gText_NewGameIdentity_DogName\n"
        ".L080054C8:\n"
        "    str r1, [sp, #0x8c]\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0x40]\n"
        "    ldr r0, [r6]\n"
        "    adds r7, r1, #0\n"
        "    subs r0, r7, r0\n"
        "    asrs r4, r0, #4\n"
        "    str r4, [sp, #0x3c]\n"
        "    add r1, sp, #0x40\n"
        "    add r0, sp, #0x3c\n"
        "    cmp r4, #1\n"
        "    bhs .L080054E2\n"
        "    adds r0, r1, #0\n"
        ".L080054E2:\n"
        "    ldr r0, [r0]\n"
        "    adds r0, r4, r0\n"
        "    cmp r0, #0\n"
        "    beq .L08005500\n"
        "    lsls r4, r0, #4\n"
        "    adds r0, r4, #0\n"
        "    bl malloc\n"
        "    mov sb, r4\n"
        "    cmp r0, #0\n"
        "    bne .L08005504\n"
        "    mov r0, sb\n"
        "    bl RetryMemoryAllocation\n"
        "    b .L08005504\n"
        ".L08005500:\n"
        "    movs r0, #0\n"
        "    mov sb, r0\n"
        ".L08005504:\n"
        "    adds r5, r0, #0\n"
        "    str r5, [sp, #0x90]\n"
        "    ldr r2, [r6]\n"
        "    adds r3, r5, #0\n"
#if ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 4) <= 255
        "    movs r0, #((" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " * " STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ") >> 4)\n"
        "    lsls r0, r0, #2\n"
        "    lsls r0, r0, #2\n"
#else
        "    ldr r0, .Lidentity_overseas_middle_value_span\n"
#endif
        "    str r0, [sp, #0x60]\n"
        "    ldr r1, [sp, #0x8c]\n"
        "    cmp r2, r1\n"
        "    beq .L08005534\n"
        ".L0800551A:\n"
        "    cmp r3, #0\n"
        "    beq .L0800552A\n"
        "    adds r0, r3, #0\n"
        "    adds r1, r2, #0\n"
        "    ldm r1!, {r4, r5, r7}\n"
        "    stm r0!, {r4, r5, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L0800552A:\n"
        "    adds r2, #0x10\n"
        "    adds r3, #0x10\n"
        "    ldr r0, [sp, #0x8c]\n"
        "    cmp r2, r0\n"
        "    bne .L0800551A\n"
        ".L08005534:\n"
        "    adds r5, r3, #0\n"
        "    ldr r0, [sp, #0x40]\n"
        "    cmp r0, #1\n"
        "    bne .L08005550\n"
        "    cmp r5, #0\n"
        "    beq .L0800554C\n"
        "    adds r0, r5, #0\n"
        "    ldr r1, [sp, #0x4c]\n"
        "    ldm r1!, {r2, r3, r4}\n"
        "    stm r0!, {r2, r3, r4}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L0800554C:\n"
        "    adds r5, #0x10\n"
        "    b .L08005572\n"
        ".L08005550:\n"
        "    adds r3, r0, #0\n"
        "    adds r2, r5, #0\n"
        "    cmp r3, #0\n"
        "    beq .L08005570\n"
        ".L08005558:\n"
        "    cmp r2, #0\n"
        "    beq .L08005568\n"
        "    adds r0, r2, #0\n"
        "    ldr r1, [sp, #0x4c]\n"
        "    ldm r1!, {r4, r5, r7}\n"
        "    stm r0!, {r4, r5, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08005568:\n"
        "    subs r3, #1\n"
        "    adds r2, #0x10\n"
        "    cmp r3, #0\n"
        "    bne .L08005558\n"
        ".L08005570:\n"
        "    adds r5, r2, #0\n"
        ".L08005572:\n"
        "    ldr r2, [r6, #4]\n"
        "    ldr r0, [r6]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, r2\n"
        "    beq .L08005582\n"
        ".L0800557C:\n"
        "    adds r1, #0x10\n"
        "    cmp r1, r2\n"
        "    bne .L0800557C\n"
        ".L08005582:\n"
        "    cmp r0, #0\n"
        "    beq .L0800558A\n"
        "    bl free\n"
        ".L0800558A:\n"
        "    ldr r0, [sp, #0x90]\n"
        "    add r0, sb\n"
        "    ldr r7, [sp, #0x90]\n"
        "    str r7, [r6]\n"
        "    str r5, [r6, #4]\n"
        "    str r0, [r6, #0xc]\n"
        ".L08005596:\n"
        "    ldr r0, [sp, #0x84]\n"
#if ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255
        "    movs r1, #((" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ") >> 2)\n"
        "    lsls r1, r1, #2\n"
#else
        "    ldr r1, .Lidentity_overseas_middle_value_bytes\n"
#endif
        "    adds r0, r0, r1\n"
        "    str r0, [sp, #0x84]\n"
        "    ldr r2, [sp, #0x88]\n"
#if ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) ") >> 2)\n"
        "    lsls r3, r3, #2\n"
#else
        "    ldr r3, .Lidentity_overseas_middle_value_stride\n"
#endif
        "    adds r2, r2, r3\n"
        "    str r2, [sp, #0x88]\n"
        "    movs r4, #1\n"
        "    add r8, r4\n"
        "    mov r5, r8\n"
        "    cmp r5, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bhi .L080055B6\n"
        "    b .L08005448\n"
        ".L080055B6:\n"
        "    movs r7, #0\n"
        "    mov r8, r7\n"
        "    mov r0, sp\n"
        "    adds r0, #0xc\n"
        "    str r0, [sp, #0x50]\n"
        "    movs r0, #(MEM_VRAM >> 19)\n"
        "    lsls r0, r0, #0x13\n"
        "    ldr r1, [sp, #0x60]\n"
        "    adds r0, r1, r0\n"
        "    str r0, [sp, #0x7c]\n"
        "    ldr r2, .L08005608\n"
        "    add r2, sl\n"
        "    str r2, [sp, #0x80]\n"
        ".L080055D0:\n"
        "    mov r0, sl\n"
        "    bl GetHardwareDmaQueue\n"
        "    adds r6, r0, #0\n"
        "    add r0, sp, #0xc\n"
        "    ldr r1, [sp, #0x80]\n"
        "    ldr r2, [sp, #0x7c]\n"
#if ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) >> 2) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILE_BYTES) ") >> 2)\n"
        "    lsls r3, r3, #2\n"
#else
        "    ldr r3, .Lidentity_overseas_middle_label_bytes\n"
#endif
        "    bl __21DmaTransferDescriptorPCvPvUi\n"
        "    ldr r1, [r6, #4]\n"
        "    ldr r0, [r6, #0xc]\n"
        "    cmp r1, r0\n"
        "    beq .L0800560C\n"
        "    cmp r1, #0\n"
        "    beq .L080055FE\n"
        "    adds r0, r1, #0\n"
        "    add r1, sp, #0xc\n"
        "    ldm r1!, {r3, r4, r5}\n"
        "    stm r0!, {r3, r4, r5}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L080055FE:\n"
        "    ldr r0, [r6, #4]\n"
        "    adds r0, #0x10\n"
        "    str r0, [r6, #4]\n"
        "    b .L080056CE\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) >> 2) <= 255)
        ".Lidentity_overseas_middle_value_stride: .word (" STRINGIFY(NEW_GAME_IDENTITY_VALUE_BUFFER_BYTES) ")\n"
#endif
#if !(((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 2) <= 255)
        ".Lidentity_overseas_middle_value_bytes: .word (" STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ")\n"
#endif
#if !(((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) >> 2) <= 255)
        ".Lidentity_overseas_middle_label_bytes: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILE_BYTES) ")\n"
#endif
#if !(((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) & 15) == 0 && ((NEW_GAME_IDENTITY_FIELD_COUNT * NEW_GAME_IDENTITY_VALUE_TILE_BYTES) >> 4) <= 255)
        ".Lidentity_overseas_middle_value_span: .word (" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " * " STRINGIFY(NEW_GAME_IDENTITY_VALUE_TILE_BYTES) ")\n"
#endif
        ".L08005608: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILES_OFFSET) ")\n"
        ".L0800560C:\n"
        "    str r1, [sp, #0x8c]\n"
        "    movs r0, #1\n"
        "    str r0, [sp, #0x48]\n"
        "    ldr r0, [r6]\n"
        "    adds r7, r1, #0\n"
        "    subs r0, r7, r0\n"
        "    asrs r4, r0, #4\n"
        "    str r4, [sp, #0x44]\n"
        "    add r1, sp, #0x48\n"
        "    add r0, sp, #0x44\n"
        "    cmp r4, #1\n"
        "    bhs .L08005626\n"
        "    adds r0, r1, #0\n"
        ".L08005626:\n"
        "    ldr r0, [r0]\n"
        "    adds r0, r4, r0\n"
        "    cmp r0, #0\n"
        "    beq .L08005644\n"
        "    lsls r4, r0, #4\n"
        "    adds r0, r4, #0\n"
        "    bl malloc\n"
        "    mov sb, r4\n"
        "    cmp r0, #0\n"
        "    bne .L08005648\n"
        "    mov r0, sb\n"
        "    bl RetryMemoryAllocation\n"
        "    b .L08005648\n"
        ".L08005644:\n"
        "    movs r0, #0\n"
        "    mov sb, r0\n"
        ".L08005648:\n"
        "    adds r5, r0, #0\n"
        "    str r5, [sp, #0x90]\n"
        "    ldr r2, [r6]\n"
        "    adds r3, r5, #0\n"
        "    b .L08005666\n"
        ".L08005652:\n"
        "    cmp r3, #0\n"
        "    beq .L08005662\n"
        "    adds r0, r3, #0\n"
        "    adds r1, r2, #0\n"
        "    ldm r1!, {r4, r5, r7}\n"
        "    stm r0!, {r4, r5, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08005662:\n"
        "    adds r2, #0x10\n"
        "    adds r3, #0x10\n"
        ".L08005666:\n"
        "    ldr r0, [sp, #0x8c]\n"
        "    cmp r2, r0\n"
        "    bne .L08005652\n"
        "    adds r5, r3, #0\n"
        "    ldr r0, [sp, #0x48]\n"
        "    cmp r0, #1\n"
        "    bne .L08005688\n"
        "    cmp r5, #0\n"
        "    beq .L08005684\n"
        "    adds r0, r5, #0\n"
        "    ldr r1, [sp, #0x50]\n"
        "    ldm r1!, {r2, r3, r4}\n"
        "    stm r0!, {r2, r3, r4}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L08005684:\n"
        "    adds r5, #0x10\n"
        "    b .L080056AA\n"
        ".L08005688:\n"
        "    adds r3, r0, #0\n"
        "    adds r2, r5, #0\n"
        "    cmp r3, #0\n"
        "    beq .L080056A8\n"
        ".L08005690:\n"
        "    cmp r2, #0\n"
        "    beq .L080056A0\n"
        "    adds r0, r2, #0\n"
        "    ldr r1, [sp, #0x50]\n"
        "    ldm r1!, {r4, r5, r7}\n"
        "    stm r0!, {r4, r5, r7}\n"
        "    ldr r1, [r1]\n"
        "    str r1, [r0]\n"
        ".L080056A0:\n"
        "    subs r3, #1\n"
        "    adds r2, #0x10\n"
        "    cmp r3, #0\n"
        "    bne .L08005690\n"
        ".L080056A8:\n"
        "    adds r5, r2, #0\n"
        ".L080056AA:\n"
        "    ldr r2, [r6, #4]\n"
        "    ldr r0, [r6]\n"
        "    adds r1, r0, #0\n"
        "    cmp r0, r2\n"
        "    beq .L080056BA\n"
        ".L080056B4:\n"
        "    adds r1, #0x10\n"
        "    cmp r1, r2\n"
        "    bne .L080056B4\n"
        ".L080056BA:\n"
        "    cmp r0, #0\n"
        "    beq .L080056C2\n"
        "    bl free\n"
        ".L080056C2:\n"
        "    ldr r0, [sp, #0x90]\n"
        "    add r0, sb\n"
        "    ldr r7, [sp, #0x90]\n"
        "    str r7, [r6]\n"
        "    str r5, [r6, #4]\n"
        "    str r0, [r6, #0xc]\n"
        ".L080056CE:\n"
        "    ldr r0, [sp, #0x7c]\n"
#if ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) >> 2) <= 255
        "    movs r1, #((" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILE_BYTES) ") >> 2)\n"
        "    lsls r1, r1, #2\n"
#else
        "    ldr r1, .Lidentity_overseas_last_label_bytes\n"
#endif
        "    adds r0, r0, r1\n"
        "    str r0, [sp, #0x7c]\n"
        "    ldr r2, [sp, #0x80]\n"
#if ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 2) <= 255
        "    movs r3, #((" STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ") >> 2)\n"
        "    lsls r3, r3, #2\n"
#else
        "    ldr r3, .Lidentity_overseas_last_label_stride\n"
#endif
        "    adds r2, r2, r3\n"
        "    str r2, [sp, #0x80]\n"
        "    movs r4, #1\n"
        "    add r8, r4\n"
        "    mov r5, r8\n"
        "    cmp r5, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bhi .L080056EE\n"
        "    b .L080055D0\n"
        ".L080056EE:\n"
        "    movs r0, #1\n"
        "    rsbs r0, r0, #0\n"
        "    ldr r4, .L080057E8 @ =(MEM_VRAM + 24 * BG_SCREEN_SIZE)\n"
        "    movs r2, #(BG_SCREEN_SIZE >> 4)\n"
        "    lsls r2, r2, #4\n"
        "    adds r1, r4, #0\n"
        "    bl FillHardwareDma3\n"
        "    movs r7, #0\n"
        "    mov r8, r7\n"
        "    @ Blank tile from the fifth (ASCII space) PlayerName label glyph.\n"
        "    @ Keep that label space: the map reuses this empty tile.\n"
        "    movs r1, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " * " STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) " + 4)\n"
        ".L08005704:\n"
        "    movs r5, #0\n"
        "    mov r2, r8\n"
        "    lsls r0, r2, #6\n"
        "    adds r0, r0, r4\n"
        ".L0800570C:\n"
        "    strh r1, [r0]\n"
        "    adds r0, #2\n"
        "    adds r5, #1\n"
        "    cmp r5, #0x1d\n"
        "    bls .L0800570C\n"
        "    movs r3, #1\n"
        "    add r8, r3\n"
        "    mov r5, r8\n"
        "    cmp r5, #0x13\n"
        "    bls .L08005704\n"
        "    movs r5, #2\n"
        "    ldr r6, .L080057EC @ =(MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x80)\n"
        ".L08005724:\n"
        "    movs r7, #0\n"
        "    mov r8, r7\n"
        "    lsls r1, r5, #1\n"
        "    adds r4, r5, #0\n"
        "    adds r4, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " * " STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) " + " STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) " - 2)\n"
        "    adds r3, r5, #0\n"
        "    adds r3, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " * " STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) " - 2)\n"
        "    ldr r0, .L080057F0 @ =(MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x40)\n"
        "    adds r2, r1, r0\n"
        ".L08005736:\n"
        "    strh r3, [r2]\n"
        "    adds r0, r1, r6\n"
        "    strh r4, [r0]\n"
        "    adds r4, #(" STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) ")\n"
        "    adds r3, #(" STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) ")\n"
        "    adds r2, #(3 * 32 * 2)\n"
        "    adds r1, #(3 * 32 * 2)\n"
        "    movs r7, #1\n"
        "    add r8, r7\n"
        "    mov r0, r8\n"
        "    cmp r0, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bls .L08005736\n"
        "    adds r5, #1\n"
        "    cmp r5, #(2 + " STRINGIFY(NEW_GAME_IDENTITY_LABEL_WIDTH) " - 1)\n"
        "    bls .L08005724\n"
        "    movs r5, #0x10\n"
        "    ldr r1, .L080057F4 @ =0x0000FFF0\n"
        "    adds r7, r1, #0\n"
        "    ldr r2, .L080057EC @ =(MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x80)\n"
        "    mov sb, r2\n"
        ".L0800575E:\n"
        "    movs r3, #0\n"
        "    mov r8, r3\n"
        "    lsls r1, r5, #1\n"
        "    adds r6, r5, #1\n"
        "    adds r0, r5, #0\n"
        "    adds r0, #" STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) "\n"
        "    adds r4, r0, r7\n"
        "    adds r3, r5, r7\n"
        "    ldr r5, .L080057F0 @ =(MEM_VRAM + 24 * BG_SCREEN_SIZE + 0x40)\n"
        "    adds r2, r1, r5\n"
        ".L08005772:\n"
        "    strh r3, [r2]\n"
        "    mov r5, sb\n"
        "    adds r0, r1, r5\n"
        "    strh r4, [r0]\n"
        "    adds r4, #(" STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) ")\n"
        "    adds r3, #(" STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " * " STRINGIFY(NEW_GAME_IDENTITY_TILE_HEIGHT) ")\n"
        "    adds r2, #(3 * 32 * 2)\n"
        "    adds r1, #(3 * 32 * 2)\n"
        "    movs r0, #1\n"
        "    add r8, r0\n"
        "    mov r5, r8\n"
        "    cmp r5, #(" STRINGIFY(NEW_GAME_IDENTITY_FIELD_COUNT) " - 1)\n"
        "    bls .L08005772\n"
        "    adds r5, r6, #0\n"
        "    cmp r5, #(16 + " STRINGIFY(NEW_GAME_IDENTITY_VALUE_WIDTH) " - 1)\n"
        "    bls .L0800575E\n"
        "    ldr r0, .L080057F8\n"
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
        "    ldr r1, .L080057FC\n"
        "    add r1, sl\n"
        "    str r4, [sp]\n"
        "    str r0, [sp, #4]\n"
        "    str r1, [sp, #8]\n"
        "    mov r0, sb\n"
        "    mov r1, r8\n"
        "    adds r2, r6, #0\n"
        "    adds r3, r5, #0\n"
        "    bl Update__C12UiStateOwnerP17HardwareCoreStateP25HardwareSpriteBufferStateP20HardwareDisplayStateP18HardwareLinkedListP21HardwareInterruptListP23HardwareMusicPlayerSlot\n"
        "    add sp, #0x94\n"
        "    pop {r3, r4, r5}\n"
        "    mov r8, r3\n"
        "    mov sb, r4\n"
        "    mov sl, r5\n"
        "    pop {r4, r5, r6, r7}\n"
        "    pop {r0}\n"
        "    bx r0\n"
        "    .align 2, 0\n"
#if !(((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) >> 2) <= 255)
        ".Lidentity_overseas_last_label_stride: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_BUFFER_BYTES) ")\n"
#endif
#if !(((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) & 3) == 0 && ((NEW_GAME_IDENTITY_LABEL_TILE_BYTES) >> 2) <= 255)
        ".Lidentity_overseas_last_label_bytes: .word (" STRINGIFY(NEW_GAME_IDENTITY_LABEL_TILE_BYTES) ")\n"
#endif
        ".L080057E8: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE)\n"
        ".L080057EC: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 2 * 32 * 2)\n"
        ".L080057F0: .word (MEM_VRAM + 24 * BG_SCREEN_SIZE + 32 * 2)\n"
        ".L080057F4: .word (0x10000 - 16)\n"
        ".L080057F8: .word (" STRINGIFY(NEW_GAME_IDENTITY_CORE_UI_OFFSET) ")\n"
        ".L080057FC: .word (" STRINGIFY(NEW_GAME_IDENTITY_CORE_MUSIC_OFFSET) ")\n"
#endif
    );
}

void UpdateNewGameIdentityDialog(NewGameIdentityCore * core)
{
    int state = core->ui_state->GetState();
    UiStateOwner * owner = core->ui_state;
    HardwareCoreState * hardware = static_cast<HardwareCoreState *>(
        GetHardwareCoreState(reinterpret_cast<void * const *>(core)));
    HardwareSpriteBufferState * sprites =
        GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
    HardwareDisplayState * display =
        GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    HardwareLinkedList * links = GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    HardwareInterruptList * manager = GetHardwareInterruptList(reinterpret_cast<void * const *>(core));
    HardwareMusicPlayerSlot * music = &core->music;
    int action = owner->Update(hardware, sprites, display, links, manager, music);

    switch (action)
    {
    case 0:
        if (core->unk_1A75 != 0)
            core->unk_1A74 = 1;
        func_08050D5C(core->ui_state);
        break;
    case 3:
        switch (state)
        {
        case 4:
        case 5:
            break;
        default:
            func_08050D74(reinterpret_cast<void * const *>(core->ui_state));
            break;
        case 1:
            func_08050E30(core->ui_state,
                gText_NewGameIdentity_Confirm, gText_NewGameIdentity_Yes,
                gText_NewGameIdentity_No, nullptr, nullptr, nullptr);
            break;
        case 6:
            switch (core->ui_state->GetChoiceResult())
            {
            case 1:
                core->unk_1A75 = 1;
                core->confirmed = 1;
                break;
            case 2:
                core->unk_1A75 = 1;
                core->confirmed = 0;
                break;
            case 0:
            case 3:
            case 4:
            case 5:
            case 6:
                break;
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

NewGameIdentityScene::NewGameIdentityScene(char const * player_name,
    GameDate birthday, char const * farm_name, char const * dog_name)
{
    core = InitializeNewGameIdentityCore(static_cast<NewGameIdentityCore *>(
        ::operator new(sizeof(NewGameIdentityCore))), player_name, birthday, farm_name, dog_name);
}

NewGameIdentityScene::~NewGameIdentityScene()
{
    delete core;
}

SceneTransitionOwner NewGameIdentityScene::Run()
{
    return RunNewGameIdentityCore(core);
}

u8 NewGameIdentityScene::GetConfirmed() const
{
    return core->confirmed;
}

u8 GetNewGameIdentityCoreConfirmed(NewGameIdentityCore const * core)
{
    return core->confirmed;
}
