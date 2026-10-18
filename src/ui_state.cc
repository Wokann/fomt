#include "ui_state.hh"
#include "font.hh"
#include "gbasvc.h"

inline void * operator new(unsigned long, void * address) { return address; }

UiTextStream * InitializeUiTextStream(UiTextStream * stream)
{
    return new (stream) UiTextStream;
}

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
// The owning high-level UI class is still unknown, so retain the recovered
// entry-point names and only model fields that the code demonstrably uses.
EC void func_08050D68(void * const * object)
    SECTION(".text.ui_state_adapters");
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
EC void func_0805039C(void * object);
EC void func_080503E4(void * object);
EC void func_08050424(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3);
EC void func_08050478(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3,
    u32 arg_sp0, u32 arg_sp1, u32 arg_sp2, u32 arg_sp3);
EC void func_08050664(void * object, u32 arg_r1, u32 arg_r2, u32 arg_r3,
    u32 arg_sp0, u32 arg_sp1, u32 arg_sp2);
EC void func_08050AD8(void * object, u32 arg_r1);
EC void func_08050B50(void * object, char const * text);
EC void func_08050C2C(void * object, u32 arg_r1);
EC void func_08050C64(void * object);

EC void func_08050D5C(void * const * object)
{
    func_0805039C(*object);
}

EC void func_08050D68(void * const * object)
{
    func_080503E4(*object);
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
    func_08050B50(*object, text);
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

EC UnkUiPackedLinkCommand * func_08050EE4(UnkUiPackedLinkCommand * object,
    u32 arg_1, u32 arg_2, u32 arg_3, u32 arg_4)
{
    object->previous_slot = nullptr;
    object->next = nullptr;
#if defined(REGION_JP)
    object->vtable = (void **)vtable_unk_080E7868;
#else
    object->vtable = (void **)vtable_unk_080E7878;
#endif
    object->unk_0c_00 = arg_1;
    object->unk_0c_05 = arg_2;
    object->unk_0c_15 = arg_3;
    object->unk_0c_19 = arg_4;
    return object;
}

EC UiTextInputAdapter * InitializeUiTextInputAdapter(UiTextInputAdapter * input,
    u32 const & pressed, u8 allow_resume)
{
#if defined(REGION_JP)
    input->vtable = vtable_unk_080E7898;
#else
    input->vtable = vtable_unk_080E78A8;
#endif
    input->pressed = pressed;
    input->allow_resume = allow_resume;
    return input;
}

EC u8 func_08050F70(UnkUiSelectionData const * object)
{
    return object->unk_1a;
}

EC void func_08050F74(UnkUiSelectionData * object, u32 const arg_1,
    u32 const arg_2)
{
    u32 second_index = arg_2;
    if (second_index > 2)
        second_index %= 3;
    object->unk_16 = second_index;

    u32 first_index = arg_1;
    if (first_index > 27)
        first_index %= 28;
    object->unk_14 = first_index;
    object->unk_19 = 0;
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

bool EmitUiTextGlyph(UnkUiSelectionData * object, u32 code)
{
    u32 column = object->unk_14;
    UnkUiSelectionRow * row = object->rows[GetUiTextPhysicalRow(object, object->unk_16)].Get();
    UnkUiSelectionEntry * entry = &row->Entry(column >> 2);
    u32 advanced = DrawUiTextEntry(entry, code, column & 3);
    if (advanced == 0)
        return false;
    if (advanced > 2)
        return false;
    u32 next = column + advanced;
    if (next > 27)
        next %= 28;
    object->unk_14 = next;
    if (code != 0x20 && code != 0x8140)
        object->unk_1b = 1;
    object->unk_1a = 1;
    return true;
}

void ReturnUiTextCursor(UnkUiSelectionData * object)
{
    object->unk_14 = 0;
}

void AdvanceUiTextLine(UnkUiSelectionData * object)
{
    if (object->unk_16 <= 1)
        ++object->unk_16;
    else {
        if (++object->unk_18 > 2)
            object->unk_18 = 0;
        int row = GetUiTextPhysicalRow(object, 2);
        UnkUiSelectionRow * row_buffer = object->rows[row].Get();
        for (int column = 0; column <= 6; ++column) {
            UnkUiSelectionEntry * entry = &row_buffer->Entry(column);
            UnkUiSelectionTileBuffer * pixels = entry->pixels.value;
            UnkUiSelectionDimensions dimensions(4, 2);
            Clear2DGfxBuffer(reinterpret_cast<u32 const &>(dimensions), pixels->tiles, 0);
            entry->changed = entry->state.handle != 0;
        }
        object->unk_19 = 1;
        object->unk_1a = 1;
    }
}

void ClearUiTextPage(UnkUiSelectionData * object)
{
    for (int row = 0; row <= 2; ++row) {
        for (int column = 0; column <= 6; ++column) {
            UnkUiSelectionEntry * entry = &object->Entry(row, column);
            ClearUiTextEntry(entry);
        }
    }
    object->unk_16 = 0;
    object->unk_14 = 0;
    object->unk_19 = 1;
    object->unk_1a = 1;
    object->unk_1b = 0;
}

u8 GetUiTextStopFlag(UnkUiSelectionData const * object)
{
    return object->unk_19;
}

static inline bool HasUiTextAdvanceKeys(u8 value)
{
    return value;
}

bool IsUiTextFastRequested(UiTextInputAdapter const * input)
{
    return HasUiTextAdvanceKeys(static_cast<u8>(input->pressed));
}

bool ShouldWaitForUiTextInput(UiTextInputAdapter const *)
{
    return true;
}

bool CanResumeUiText(UiTextInputAdapter const * input)
{
    bool result = false;
    if (input->allow_resume) {
        if (HasUiTextAdvanceKeys(static_cast<u8>(input->pressed)))
            result = true;
    }
    return result;
}

EC void func_080510E8(UnkUiSelectionData * object)
{
    for (int row = 0; row <= 2; ++row)
    {
        int column = 0;
        for (; column <= 6; ++column)
        {
            UnkUiSelectionEntry & entry = object->Entry(row, column);
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

EC UnkUiSelectionData * func_0805116C(UnkUiSelectionData * object,
    HardwareResourceEntry * palette, HardwareStateOwner const & state)
{
#if defined(REGION_JP)
    object->vtable = vtable_unk_080E78B0;
#else
    object->vtable = vtable_unk_080E78C0;
#endif
    object->palette = palette;
    UnkUiSelectionRowOwner * first_row = object->rows;
    for (int count = 2; count != -1; --count)
        (first_row++)->value = nullptr;
    object->unk_14 = 0;
    object->unk_16 = 0;
    object->unk_18 = 0;
    object->unk_19 = 0;
    object->unk_1a = 0;
    object->unk_1b = 0;
    for (int row = 0; row <= 2; ++row)
    {
        object->rows[row] = new UnkUiSelectionRow;
        for (int column = 0; column <= 6; ++column)
        {
            UnkUiSelectionEntry * entry = &object->Entry(row, column);
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
    object->unk_1a = 1;
    return object;
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

EC UnkUiSelectionLinkCommand * func_080512D8(UnkUiSelectionLinkCommand * object,
    u32 arg_1, u32 arg_2, u32 arg_3, bool arg_4)
{
    object->previous_slot = nullptr;
    object->next = nullptr;
#if defined(REGION_JP)
    object->vtable = (void **)vtable_unk_080E78D0;
#else
    object->vtable = (void **)vtable_unk_080E78E0;
#endif
    object->unk_0c = arg_1;
    object->unk_10 = arg_2;
    object->unk_14_00 = arg_3;
    object->unk_14_14 = 0;
    object->unk_14_15 = arg_4;
    return object;
}
