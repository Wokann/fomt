#include "new_game_name_input.hh"
#include "hardware_context.hh"
#include "new_game_data.hh"
#include "hardware_state_accessors.hh"
#include "new.hh"
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
