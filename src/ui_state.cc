#include "prelude.h"
#pragma implementation "ui_state.hh"
#include "ui_state.hh"
#include "font.hh"
#include "resource_handle.hh"
#include "gbasvc.h"
#include <string.h>

bool UiTextInput::Resume() { return true; }
bool UiTextInput::WaitForInput() { return false; }
bool UiTextInput::Fast() { return false; }

u8 UiTextOutput::ShouldStop() { return false; }
void UiTextOutput::NextPage() {}
void UiTextOutput::LineFeed() {}
void UiTextOutput::CarriageReturn() {}

bool UiTextTileCopyCommand::Run()
{
    UiTextTileCopyCommand * command = this;
    u32 const * source = command->source;
    u32 * destination = command->destination;
    if (command->alternate_nibbles) {
        u32 * end = destination + command->tile_count * 8;
        u32 phase = command->nibble_phase ^ 1;
        command->nibble_phase = phase;
        u32 mask = 0x0F0F0F0Fu << (phase * 4);
        u32 alternate = ~mask;
        do {
            *destination++ = *source++ & mask;
            *destination++ = *source++ & alternate;
            *destination++ = *source++ & mask;
            *destination++ = *source++ & alternate;
            *destination++ = *source++ & mask;
            *destination++ = *source++ & alternate;
            *destination++ = *source++ & mask;
            *destination++ = *source++ & alternate;
        } while (destination != end);
        return true;
    }
    CpuFastSet(source, destination, command->tile_count * 8);
    return false;
}

static inline IndexedResourceGroupResult LoadUiPortraitGroup(u32 index)
{
    IndexedResourceArchive archive(gPortraitIndexedResourceArchive);
    IndexedResourceProvider * provider = reinterpret_cast<IndexedResourceProvider *>(&archive);
    IndexedResourceProviderVTable const * table = archive.vtable;
    return table->get_group_data(provider, table->resolve(provider, index)[0].group_index);
}

UiPortraitGroupOwner::UiPortraitGroupOwner()
    : value(new IndexedResourceGroupResult(0, 0, 0, 0, 0, 0, 0, 0)) {}

UiPortraitGroupOwner::UiPortraitGroupOwner(u32 index)
    : value(new IndexedResourceGroupResult(LoadUiPortraitGroup(index))) {}

UiPortraitGroupOwner::~UiPortraitGroupOwner()
{
    delete value;
}

void UiPortraitGroupOwner::Set(u32 index)
{
    *value = LoadUiPortraitGroup(index);
}

IndexedResourceGroupResult UiPortraitGroupOwner::Get() const
{
    return *value;
}

u32 GetUiPortraitCount()
{
    IndexedResourceArchive archive(gPortraitIndexedResourceArchive);
    return archive.entry_descriptor_count;
}

UiTextStream::UiTextStream()
    : phase(0), speed(0x100), progress(0), cursor(nullptr),
      variables(nullptr), replacement_cursor(nullptr) {}

void SetUiTextStreamText(UiTextStream * stream, char const * text,
    ScriptTextVariableStore * variables)
{
    stream->cursor = text;
    stream->variables = variables;
    stream->replacement_cursor = nullptr;
    stream->replacement[0] = '\0';
    stream->phase = text != nullptr;
    stream->progress = 0;
}

void SetUiTextStreamSpeed(UiTextStream * stream, u16 speed)
{
    stream->speed = speed;
}

u32 UpdateUiTextStream(UiTextStream * stream, UiTextOutput * output, UiTextInput * input)
{
    bool fast = false;
    int remaining = AdvanceUiTextStreamClock(stream);
    if (stream->phase == 2) {
        if (!input->Resume())
            remaining = 0;
        else
            stream->phase = 1;
    } else {
        bool enabled = false;
        int requested = input->Fast();
        if (stream->speed == 0)
            requested |= 1;
        if (requested != 0)
            enabled = true;
        fast = enabled;
    }
    char const * cursor = stream->replacement_cursor;
    if (cursor == nullptr)
        cursor = stream->cursor;
    u32 code = 0;
    while (cursor != nullptr && (fast || remaining != 0) && !output->ShouldStop()) {
        u32 byte = static_cast<u8>(*cursor++);
        switch (byte) {
        default:
            if (byte <= 0x1F)
                continue;
            code |= byte;
            if (output->Emit(code))
                code = 0;
            else {
                if (stream->variables != nullptr && stream->replacement_cursor == nullptr) {
                    UiTextSubstitution result = stream->variables->Lookup(code);
                    if (result.found) {
                        code = 0;
                        char * buffer = &stream->replacement[0];
                        strcpy(buffer, result.text);
                        stream->cursor = cursor;
                        stream->replacement_cursor = buffer;
                        cursor = buffer;
                        continue;
                    }
                    code <<= 8;
                } else
                    code <<= 8;
                continue;
            }
            if (remaining != 0)
                --remaining;
            break;
        case '\0':
            if (stream->replacement_cursor != nullptr) {
                stream->replacement_cursor = nullptr;
                cursor = stream->cursor;
                continue;
            }
            cursor = nullptr;
            goto finished;
        case '\r':
            output->CarriageReturn();
            if (remaining != 0)
                --remaining;
            break;
        case '\n':
            output->LineFeed();
            if (remaining != 0)
                --remaining;
            break;
        case 0x0C: // \p: next page
            output->NextPage();
            if (remaining != 0)
                --remaining;
            break;
        case 0x05: // {Press}
            if (input->WaitForInput()) {
                stream->phase = 2;
                goto finished;
            }
            continue;
        }
    }
finished:
    if (stream->replacement_cursor != nullptr)
        stream->replacement_cursor = cursor;
    else {
        stream->cursor = cursor;
        if (cursor == nullptr)
            stream->phase = 0;
    }
    return stream->phase;
}

extern "C" void SetUiObjectStateTwoIfNonzero(void * object)
    SECTION(".text.set_ui_object_state_two_if_nonzero");

extern "C" void ClearUiObjectStateIfNonzero(void * object)
    SECTION(".text.clear_ui_object_state_if_nonzero");

extern "C" void ClearUiActionStateFlag01DC(void * object)
    SECTION(".text.clear_ui_action_state_flag_01dc");

extern "C" void ClearUiActionStateFlag01F0(void * object)
    SECTION(".text.clear_ui_action_state_flag_01f0");

extern "C" void SetUiObjectStateTwoIfNonzero(void * object)
{
    UiObjectState * state = (UiObjectState *)object;

    if (state->state != 0)
    {
        state->state = 2;
    }
}

extern "C" void ClearUiObjectStateIfNonzero(void * object)
{
    UiObjectState * state = (UiObjectState *)object;

    if (state->state != 0)
    {
        state->state = 0;
    }
}

extern "C" void ClearUiActionStateFlag01DC(void * object)
{
    UiActionState * state = (UiActionState *)object;

    state->flags_01dc.active = 0;
}

extern "C" void ClearUiActionStateFlag01F0(void * object)
{
    UiActionState * state = (UiActionState *)object;

    state->flags_01f0.active = 0;
}

UiStateOwner::UiStateOwner(u32 arg_1, u32 arg_2, u32 arg_3, u32 arg_4,
    HardwareStateOwner const & shared, HardwareResource const & resources)
{
    value = new UiStatePayload(arg_1, arg_2, arg_3, arg_4, shared, resources);
}

UiStateOwner::~UiStateOwner()
{
    delete value;
}

i32 UiStateOwner::GetState() const
{
    return value->state;
}

i32 UiStateOwner::Update(HardwareCoreState * state,
    HardwareSpriteBufferState * sprites, HardwareDisplayState * display,
    u8 * links, u8 * manager, MusicPlayer ** music) const
{
    return value->Update(state, sprites, display, links, manager, music);
}

// These adapters follow the owner methods in the same native ROM block.
// Use the verified owner type for opening; unresolved payload operations keep
// their recovered entry-point names and only demonstrably consumed fields.
EC void func_08050D80(void * const * object)
    SECTION(".text.ui_state_adapters");
EC void func_08050D8C(void * const * object, u32 arg_r1)
    SECTION(".text.ui_state_adapters");
EC void func_08050DA0(void * const * object, u32 arg_r1, u32 arg_r2)
    SECTION(".text.ui_state_adapters");
EC void func_08050DB4(void * const * object, u32 arg_r1, u16 arg_r2)
    SECTION(".text.ui_state_adapters");
EC u8 func_08050DD8(void * const * object)
    SECTION(".text.ui_state_adapters");
EC u8 func_08050DE4(void * const * object)
    SECTION(".text.ui_state_adapters");
EC void func_08050424(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3);
EC void func_08050478(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3,
    u32 arg_sp0, u32 arg_sp1, u32 arg_sp2, u32 arg_sp3);
EC void func_08050664(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3,
    u32 arg_sp0, u32 arg_sp1, u32 arg_sp2);
EC void func_08050AD8(void * object, u32 arg_r1);
EC void func_08050C2C(void * object, u32 arg_r1);
EC void func_08050C64(void * object);

EC void func_08050D5C(UiStateOwner const * object)
{
    object->value->Open();
}

EC void func_08050D68(UiStateOwner const * object)
{
    object->value->OpenImmediately();
}

EC void func_08050D74(void * const * object)
{
    SetUiObjectStateTwoIfNonzero(*object);
}

EC void func_08050D80(void * const * object)
{
    ClearUiObjectStateIfNonzero(*object);
}

EC void func_08050D8C(void * const * object, u32 arg_r1)
{
    func_08050424(*object, arg_r1, 0x100, 0);
}

EC void func_08050DA0(void * const * object, u32 arg_r1, u32 arg_r2)
{
    func_08050424(*object, arg_r1, 0x100, arg_r2);
}

EC void func_08050DB4(void * const * object, u32 arg_r1, u16 arg_r2)
{
    func_08050424(*object, arg_r1, arg_r2, 0);
}

EC void func_08050DC8(void * const * object, u32 arg_r1, u16 arg_r2,
    u32 arg_r3)
{
    func_08050424(*object, arg_r1, arg_r2, arg_r3);
}

EC u8 func_08050DD8(void * const * object)
{
    FirstFieldStatusByte * const status = static_cast<FirstFieldStatusByte *>(*object);
    u8 const value = status->value;
    status->value = 0;
    return value;
}

EC u8 func_08050DE4(void * const * object)
{
    FirstFieldStatusByte * const status = static_cast<FirstFieldStatusByte *>(*object);
    u8 const value = status->value;
    status->value = 1;
    return value;
}

EC void * func_08050DF0(void * const * object)
{
    FirstFieldQueryData * const data = static_cast<FirstFieldQueryData *>(*object);

    if (data->mode == 6)
        return nullptr;

    return data->result;
}

static inline void FillUiFastWords(u32 value, void * destination, u32 count)
{
    u32 volatile source = value;
    CpuFastSet((void const *)&source, destination, CPUSET_SRC_FIXED | count);
}
bool UiTextWindowSetupCommand::Run()
{
    UiTextWindowSetupCommand * command = this;
    u16 tile = ((command->first_tile + 3) & 0x3FF) | (command->background_palette << 12);
    u32 fill = tile | (static_cast<u32>(tile) << 16);
    FillUiFastWords(fill, reinterpret_cast<void *>(0x06000000 + command->screen_block * 0x800),
        160);
    func_08051320(reinterpret_cast<u16 *>(0x06000000 + command->screen_block * 0x800),
        16, 0, 14, 3, command->first_tile, command->background_palette);
    func_08051320(reinterpret_cast<u16 *>(0x06000000 + command->screen_block * 0x800),
        0, 3, 30, 7, command->first_tile, command->background_palette);
    u32 palette = command->background_palette;
    CpuFastSet(gUiSharedPalette, reinterpret_cast<void *>(0x05000000 + palette * 32), 8);
    CpuFastSet(IndexedResourceArchive(gUiHandCursorArchive).GetGroupData(0).fifth.data,
        reinterpret_cast<void *>(0x05000200 + command->cursor_palette * 32), 8);
    return false;
}

#include FOMT_TEXT_INCLUDE(ui_state.cc)

UiTextLayoutPositionTable const gUiTextLayoutPositionTable = {
    0x00,
    {
        { 0x08, 0x09, 0x00, 0x00, 0x00, 0x00 },
        { 0x08, 0x09, 0x0A, 0x00, 0x00, 0x00 },
        { 0x08, 0x09, 0x40, 0x41, 0x00, 0x00 },
        { 0x08, 0x09, 0x0A, 0x40, 0x41, 0x00 },
        { 0x08, 0x09, 0x0A, 0x40, 0x41, 0x42 },
        { 0x09, 0x0A, 0x00, 0x00, 0x00, 0x00 },
        { 0x09, 0x0A, 0x41, 0x00, 0x00, 0x00 },
        { 0x09, 0x0A, 0x41, 0x42, 0x00, 0x00 },
    },
};

u8 const * const gUiSharedTiles = gUnk_UiSharedResourceData_000;
u32 const gUiSharedTileByteCount = 0x120;
u8 const * const gUiSharedPalette = gUnk_UiSharedResourceData_001;

EC void func_08050E0C(UiStateOwner const * object, char const * first, char const * second,
    char const * third, char const * fourth, char const * fifth, char const * sixth,
    ScriptTextVariableStore * variables)
{
    func_08050478(object->value, reinterpret_cast<u32>(first), reinterpret_cast<u32>(second),
        reinterpret_cast<u32>(third), reinterpret_cast<u32>(fourth), reinterpret_cast<u32>(fifth),
        reinterpret_cast<u32>(sixth), reinterpret_cast<u32>(variables));
}

EC void func_08050E30(UiStateOwner const * object, char const * prompt, char const * first,
    char const * second, char const * third, char const * fourth,
    ScriptTextVariableStore * variables)
{
    func_08050664(object->value, reinterpret_cast<u32>(prompt), reinterpret_cast<u32>(first),
        reinterpret_cast<u32>(second), reinterpret_cast<u32>(third), reinterpret_cast<u32>(fourth),
        reinterpret_cast<u32>(variables));
}

EC void func_08050E50(void * const * object, u32 arg_r1)
{
    func_08050AD8(*object, arg_r1);
}

EC void func_08050E5C(void * const * object)
{
    ClearUiActionStateFlag01DC(*object);
}

EC void func_08050E68(void * const * object, char const * text)
{
    SetUiNameplateText(static_cast<UiStatePayload *>(*object), text);
}

EC void func_08050E74(void * const * object)
{
    ClearUiActionStateFlag01F0(*object);
}

EC void func_08050E80(void * const * object, u32 arg_r1)
{
    func_08050C2C(*object, arg_r1);
}

EC void func_08050E8C(void * const * object)
{
    func_08050C64(*object);
}

EC u32 func_08050E98(FirstFieldUiOwner & object, u32 const flag_mask)
    SECTION(".text.ui_state_adapters");
EC u32 func_08050EBC(FirstFieldUiOwner & object, u32 const flag_mask)
    SECTION(".text.ui_state_adapters");

EC u32 func_08050E98(FirstFieldUiOwner & object, u32 const flag_mask)
{
    FirstFieldUiFlags * const data = object.data;
    u32 const old_flags = data->low_flags;
    data->low_flags &= ~flag_mask;
    return old_flags;
}

EC u32 func_08050EBC(FirstFieldUiOwner & object, u32 const flag_mask)
{
    FirstFieldUiFlags * const data = object.data;
    u32 const old_flags = data->low_flags;
    data->low_flags |= flag_mask;
    return old_flags;
}

UiTextWindowSetupCommand::UiTextWindowSetupCommand(u32 screen, u32 tile, u32 background, u32 cursor)
    : HardwareLinkBase(), screen_block(screen), first_tile(tile),
      background_palette(background), cursor_palette(cursor)
{
}

UiTextInputAdapter::UiTextInputAdapter(u32 const & pressed, u8 allow_resume)
    : pressed(pressed), allow_resume(allow_resume)
{
}

EC u8 func_08050F70(UnkUiSelectionData const * object)
{
    return object->unk_1a;
}

static inline void SetUiChoiceOutputPosition(UnkUiSelectionData * object, u32 column, u32 row)
{
    u32 second_index = row;
    if (second_index > 2)
        second_index %= 3;
    object->unk_16 = second_index;

    u32 first_index = column;
    if (first_index > 27)
        first_index %= 28;
    object->unk_14 = first_index;
    object->unk_19 = 0;
}

EC void func_08050F74(UnkUiSelectionData * object, u32 const arg_1,
    u32 const arg_2)
{
    SetUiChoiceOutputPosition(object, arg_1, arg_2);
}

static inline bool HasUiSelectionState(HardwareStateEntry const & state)
{
    return state.handle != 0;
}

static inline u32 UiSelectionTileIndex(HardwareStateEntry & state)
{
    return GetHardwareSharedStateTileIndex(&state, state.handle);
}

// Three physical rows contain seven four-column glyph entries each.
// Keep the renderer's original bounds and post-draw handle checks.
static inline u32 DrawUiTextEntry(UnkUiSelectionEntry * entry, u32 code, u32 column)
{
    if (column <= 3) {
        UnkUiSelectionTileBuffer * buffer = entry->pixels.value;
        u32 x = (column & 3) * 8;
        UnkUiSelectionDimensions dimensions(4, 2);
        u32 result = DrawCharacterGlyphTo2DGfxBuffer(reinterpret_cast<u32 const &>(dimensions),
            buffer->tiles, x, 0, code);
        if (result == 1 || result == 2)
            entry->changed = HasUiSelectionState(entry->state);
        return result;
    }
    return 0;
}

static inline void ClearUiTextEntry(UnkUiSelectionEntry * entry)
{
    UnkUiSelectionTileBuffer * buffer = entry->pixels.value;
    UnkUiSelectionDimensions dimensions(4, 2);
    Clear2DGfxBuffer(reinterpret_cast<u32 const &>(dimensions), buffer->tiles, 0);
    entry->changed = HasUiSelectionState(entry->state);
}

static inline int GetUiTextPhysicalRow(UnkUiSelectionData const * object, int row)
{
    int result = row + object->unk_18;
    if (result > 2)
        result -= 3;
    return result;
}

static inline UnkUiSelectionEntry & GetUiTextEntry(UnkUiSelectionData & object,
    int row, int column)
{
    return object.rows[row]->Entry(column);
}

bool UnkUiSelectionData::Emit(u32 code)
{
    u32 column = unk_14;
    UnkUiSelectionRow * row = rows[GetUiTextPhysicalRow(this, unk_16)].Get();
    UnkUiSelectionEntry * entry = &row->Entry(column >> 2);
    u32 advanced = DrawUiTextEntry(entry, code, column & 3);
    if (advanced == 0)
        return false;
    if (advanced > 2)
        return false;
    u32 next = column + advanced;
    if (next > 27)
        next %= 28;
    unk_14 = next;
    if (code != 0x20 && code != 0x8140)
        unk_1b = 1;
    unk_1a = 1;
    return true;
}

void UnkUiSelectionData::CarriageReturn()
{
    unk_14 = 0;
}

void UnkUiSelectionData::LineFeed()
{
    if (unk_16 <= 1)
        ++unk_16;
    else {
        if (++unk_18 > 2)
            unk_18 = 0;
        int row = GetUiTextPhysicalRow(this, 2);
        UnkUiSelectionRow * row_buffer = rows[row].Get();
        for (int column = 0; column <= 6; ++column) {
            UnkUiSelectionEntry * entry = &row_buffer->Entry(column);
            UnkUiSelectionTileBuffer * pixels = entry->pixels.value;
            UnkUiSelectionDimensions dimensions(4, 2);
            Clear2DGfxBuffer(reinterpret_cast<u32 const &>(dimensions), pixels->tiles, 0);
            entry->changed = entry->state.handle != 0;
        }
        unk_19 = 1;
        unk_1a = 1;
    }
}

void UnkUiSelectionData::NextPage()
{
    for (int row = 0; row <= 2; ++row) {
        for (int column = 0; column <= 6; ++column) {
            UnkUiSelectionEntry * entry = &GetUiTextEntry(*this, row, column);
            ClearUiTextEntry(entry);
        }
    }
    unk_16 = 0;
    unk_14 = 0;
    unk_19 = 1;
    unk_1a = 1;
    unk_1b = 0;
}

u8 UnkUiSelectionData::ShouldStop()
{
    return unk_19;
}

static inline bool HasUiTextAdvanceKeys(u8 value)
{
    return value;
}

bool UiTextInputAdapter::Fast()
{
    UiTextInputAdapter const * input = this;
    return HasUiTextAdvanceKeys(static_cast<u8>(input->pressed));
}

bool UiTextInputAdapter::WaitForInput()
{
    return true;
}

bool UiTextInputAdapter::Resume()
{
    UiTextInputAdapter const * input = this;
    bool result = false;
    if (input->allow_resume) {
        if (HasUiTextAdvanceKeys(static_cast<u8>(input->pressed)))
            result = true;
    }
    return result;
}

static inline void UploadUiTextOutput(UnkUiSelectionData * object)
{
    for (int row = 0; row <= 2; ++row)
    {
        int column = 0;
        for (; column <= 6; ++column)
        {
            UnkUiSelectionEntry & entry = GetUiTextEntry(*object, row, column);
            if (entry.changed)
            {
                if (HasUiSelectionState(entry.state))
                {
                    u32 const * pixels = entry.pixels.value->tiles;
                    u32 const index = UiSelectionTileIndex(entry.state);
                    CpuFastSet(pixels, reinterpret_cast<void *>(0x06010000 + index * 32), 64);
                }
                entry.changed = false;
            }
        }
    }
    if (object->unk_19)
        object->unk_19 = 0;
    if (object->unk_1a)
        object->unk_1a = 0;
}

EC void func_080510E8(UnkUiSelectionData * object)
{
    UploadUiTextOutput(object);
}

bool UiTextOutputUploadCommand::Run()
{
    UiTextOutputUploadCommand * command = this;
    UploadUiTextOutput(command->output);
    return false;
}

UnkUiSelectionData::UnkUiSelectionData(HardwareResourceEntry * palette,
    HardwareStateOwner const & state)
    : palette(palette), unk_14(0), unk_16(0), unk_18(0), unk_19(0), unk_1a(0), unk_1b(0)
{
    for (int row = 0; row <= 2; ++row)
    {
        rows[row] = new UnkUiSelectionRow;
        for (int column = 0; column <= 6; ++column)
        {
            UnkUiSelectionEntry * entry = &GetUiTextEntry(*this, row, column);
            entry->state = state.Get(3);
            bool available = HasUiSelectionState(entry->state);
            if (available)
            {
                UnkUiSelectionTileBuffer * const buffer = entry->pixels.value;
                UnkUiSelectionDimensions dimensions(4, 2);
                Clear2DGfxBuffer(reinterpret_cast<u32 const &>(dimensions), buffer->tiles, 0);
                available = true;
            }
            entry->changed = available;
        }
    }
    unk_1a = 1;
}

EC int func_080512B8(UnkUiSelectionData const * object, int index)
{
    int result = index + object->unk_18;
    if (result > 2)
        result -= 3;
    return result;
}

EC UnkUiSelectionRow * func_080512C8(UnkUiSelectionData const * object, u32 index)
{
    return object->rows[index].Get();
}

EC UnkUiSelectionRow * func_080512D0(UnkUiSelectionData const * object, u32 index)
{
    return object->rows[index].Get();
}

UiTextTileCopyCommand::UiTextTileCopyCommand(u32 const * source, u32 * destination,
    u32 tile_count, bool alternate_nibbles)
    : HardwareLinkBase(), source(source), destination(destination), tile_count(tile_count),
      nibble_phase(0), alternate_nibbles(alternate_nibbles)
{
}

// Reverse member destruction owns every resource and unlinks each queued
// command. No borrowed output/queue pointer is separately freed.
UiStatePayload::~UiStatePayload() {}

// Only an inactive window resets its rows and queues setup commands. Reopening
// a closing window keeps its current animation phase and queued ownership.
void UiStatePayload::Open()
{
    if (state == 0) {
        output.NextPage();
        if (mode != 1)
            commands.HardwareLinkedList::Append(&tile_copy);
        commands.HardwareLinkedList::Append(&window);
        unk_0c = 0;
    }
    if (state < 0)
        return;
    if (state > 2)
        return;
    state = 1;
}

void UiStatePayload::OpenImmediately()
{
    Open();
    state = 3;
    unk_0c = 9;
}

UiTextLayoutPosition GetUiChoiceLayoutPosition(u32 layout, u32 selection)
{
    if (layout >= UI_TEXT_LAYOUT_VARIANT_COUNT)
        layout = 0;
    if (selection - 1 >= UI_TEXT_LAYOUT_SLOT_COUNT)
        selection = 1;
    // The leading table byte is also the parser's empty-string fallback.
    // A one-based choice index addresses the actual packed position bytes.
    return reinterpret_cast<UiTextLayoutPosition const *>(&gUiTextLayoutPositionTable)
        [layout * UI_TEXT_LAYOUT_SLOT_COUNT + selection];
}

void RenderUiChoiceLabel(UiStatePayload * payload, UiTextLayoutPosition const & position,
    char const * text, ScriptTextVariableStore * variables)
{
    SetUiChoiceOutputPosition(&payload->output, position.column, position.row);
    SetUiTextStreamText(&payload->text, text, variables);
    u32 phase;
    do {
        UiTextInput input;
        phase = UpdateUiTextStream(&payload->text, &payload->output, &input);
    } while (phase == 1);
}

// Choices are one-based. Down takes priority over up, then either horizontal
// key; no directional input returns one. The horizontal paths for layouts
// 0, 1 and 5 deliberately preserve even an out-of-range selection.
i32 MoveUiChoiceSelection(u32 layout, i32 selection, UiChoiceKeyState keys)
{
    switch (layout) {
    case 0:
    case 5:
        if (keys.value & (UiChoiceKeyState::UP | UiChoiceKeyState::DOWN)) {
            switch (selection) {
            case 1: return 2;
            case 2: return 1;
            }
        } else if (keys.value & (UiChoiceKeyState::LEFT | UiChoiceKeyState::RIGHT)) {
            return selection;
        }
        break;
    case 1:
        if (keys.value & UiChoiceKeyState::DOWN) {
            switch (selection) {
            case 1: return 2;
            case 2: return 3;
            case 3: return 1;
            }
        } else if (keys.value & UiChoiceKeyState::UP) {
            switch (selection) {
            case 1: return 3;
            case 2: return 1;
            case 3: return 2;
            }
        } else if (keys.value & (UiChoiceKeyState::LEFT | UiChoiceKeyState::RIGHT)) {
            return selection;
        }
        break;
    case 6:
        if (keys.value & UiChoiceKeyState::DOWN) {
            switch (selection) {
            case 1: return 2;
            case 2: return 1;
            case 3: return 2;
            }
        } else if (keys.value & UiChoiceKeyState::UP) {
            switch (selection) {
            case 1: return 2;
            case 2: return 1;
            case 3: return 2;
            }
        } else if (keys.value & (UiChoiceKeyState::LEFT | UiChoiceKeyState::RIGHT)) {
            switch (selection) {
            case 1: return 3;
            case 2: return 3;
            case 3: return 1;
            }
        }
        break;
    case 2:
    case 7:
        if (keys.value & UiChoiceKeyState::DOWN) {
            switch (selection) {
            case 1: return 2;
            case 2: return 1;
            case 3: return 4;
            case 4: return 3;
            }
        } else if (keys.value & UiChoiceKeyState::UP) {
            switch (selection) {
            case 1: return 2;
            case 2: return 1;
            case 3: return 4;
            case 4: return 3;
            }
        } else if (keys.value & (UiChoiceKeyState::LEFT | UiChoiceKeyState::RIGHT)) {
            switch (selection) {
            case 1: return 3;
            case 2: return 4;
            case 3: return 1;
            case 4: return 2;
            }
        }
        break;
    case 3:
        if (keys.value & UiChoiceKeyState::DOWN) {
            switch (selection) {
            case 1: return 2;
            case 2: return 3;
            case 3: return 1;
            case 4: return 5;
            case 5: return 4;
            }
        } else if (keys.value & UiChoiceKeyState::UP) {
            switch (selection) {
            case 1: return 3;
            case 2: return 1;
            case 3: return 2;
            case 4: return 5;
            case 5: return 4;
            }
        } else if (keys.value & (UiChoiceKeyState::LEFT | UiChoiceKeyState::RIGHT)) {
            switch (selection) {
            case 1: return 4;
            case 2: return 5;
            case 3: return 5;
            case 4: return 1;
            case 5: return 2;
            }
        }
        break;
    case 4:
        if (keys.value & UiChoiceKeyState::DOWN) {
            switch (selection) {
            case 1: return 2;
            case 2: return 3;
            case 3: return 1;
            case 4: return 5;
            case 5: return 6;
            case 6: return 4;
            }
        } else if (keys.value & UiChoiceKeyState::UP) {
            switch (selection) {
            case 1: return 3;
            case 2: return 1;
            case 3: return 2;
            case 4: return 6;
            case 5: return 4;
            case 6: return 5;
            }
        } else if (keys.value & (UiChoiceKeyState::LEFT | UiChoiceKeyState::RIGHT)) {
            switch (selection) {
            case 1: return 4;
            case 2: return 5;
            case 3: return 6;
            case 4: return 1;
            case 5: return 2;
            case 6: return 3;
            }
        }
        break;
    }
    return 1;
}

static inline void ClearUiNameplateBuffer(UnkUiSelectionTileBuffer * buffer)
{
    UnkUiSelectionDimensions size(4, 2);
    Clear2DGfxBuffer(reinterpret_cast<u32 const &>(size), buffer->tiles, 0);
}

static inline void DrawUiNameplateBuffer(UnkUiSelectionTileBuffer * buffer, char const * text)
{
    UnkUiSelectionDimensions size(4, 2);
    DrawStringTo2DGfxBuffer(reinterpret_cast<u32 const &>(size), buffer->tiles,
        0, 0, reinterpret_cast<u8 const *>(text));
}

void SetUiNameplateText(UiStatePayload * payload, char const * text)
{
    u32 remaining = text != nullptr ? strlen(text) : 0;
    if (remaining - 1 > UI_NAMEPLATE_TEXT_MAX_BYTES - 1) {
        ClearUiActionStateFlag01F0(payload);
        return;
    }
    char const * cursor = text;
    for (u32 index = 0; index < UI_NAMEPLATE_TILE_BUFFER_COUNT; ++index) {
        UnkUiSelectionTileBuffer * buffer = payload->nameplate_tiles + index;
        ClearUiNameplateBuffer(buffer);
        if (remaining != 0) {
            char part[UI_NAMEPLATE_CHUNK_BYTE_COUNT + 1];
            char * output = part;
            do {
                *output++ = *cursor++;
                --remaining;
            } while (remaining != 0 && output != part + UI_NAMEPLATE_CHUNK_BYTE_COUNT);
            *output = '\0';
            DrawUiNameplateBuffer(buffer, part);
        }
    }
    payload->nameplate_flags.active = 1;
    payload->nameplate_flags.changed = 1;
}
