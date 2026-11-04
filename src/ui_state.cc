#include "hardware_resource.hh"
#include "prelude.h"
#pragma implementation "ui_state.hh"
#include "ui_state.hh"
#include "ui_graphics_sizes.hh"
#include "ui_text_window.hh"
#include "font.hh"
#include "resource_handle.hh"
#include "gbasvc.h"
#include <string.h>

UiTextSubstitution ScriptTextVariableStore::Lookup(u32)
{
    return UiTextSubstitution(false, FixedStr<31>());
}

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
    IndexedResourceProvider const * provider = &archive;
    return provider->GetGroupData(provider->Resolve(index)[0].group_index);
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
    HardwareLinkedList * links, HardwareInterruptList * manager, HardwareMusicPlayerSlot * music) const
{
    return value->Update(state, sprites, display, links, manager, music);
}

// These adapters follow the owner methods in the same native ROM block.
// Use the verified payload methods for opening and ordinary message text.
// Other unresolved operations keep their recovered native entry-point names.
EC void func_08050D80(void * const * object)
    SECTION(".text.ui_state_adapters");
EC void func_08050D8C(void * const * object, u32 arg_r1)
    SECTION(".text.ui_state_adapters");
EC void func_08050DB4(void * const * object, u32 arg_r1, u16 arg_r2)
    SECTION(".text.ui_state_adapters");

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
    static_cast<UiStatePayload *>(*object)->SetText(
        reinterpret_cast<char const *>(arg_r1), 0x100, nullptr);
}

EC void func_08050DA0(UiStateOwner const * object, char const * text,
    ScriptTextVariableStore * variables)
{
    object->value->SetText(text, 0x100, variables);
}

EC void func_08050DB4(void * const * object, u32 arg_r1, u16 arg_r2)
{
    static_cast<UiStatePayload *>(*object)->SetText(
        reinterpret_cast<char const *>(arg_r1), arg_r2, nullptr);
}

EC void func_08050DC8(void * const * object, u32 arg_r1, u16 arg_r2,
    u32 arg_r3)
{
    static_cast<UiStatePayload *>(*object)->SetText(
        reinterpret_cast<char const *>(arg_r1), arg_r2,
        reinterpret_cast<ScriptTextVariableStore *>(arg_r3));
}

u8 UiStateOwner::DisableResume() const
{
    u8 const previous = value->allow_resume;
    value->allow_resume = 0;
    return previous;
}

u8 UiStateOwner::EnableResume() const
{
    u8 const previous = value->allow_resume;
    value->allow_resume = 1;
    return previous;
}

u32 UiStateOwner::GetChoiceResult() const
{
    if (value->state == 6)
        return 0;
    return value->choice_index;
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
    DrawUiTextWindowBorder(reinterpret_cast<u16 *>(0x06000000 + command->screen_block * 0x800),
        16, 0, 14, 3, command->first_tile, command->background_palette);
    DrawUiTextWindowBorder(reinterpret_cast<u16 *>(0x06000000 + command->screen_block * 0x800),
        0, 3, 30, 7, command->first_tile, command->background_palette);
    u32 palette = command->background_palette;
    CpuFastSet(gUiSharedPalette, reinterpret_cast<void *>(0x05000000 + palette * 32), 8);
    CpuFastSet(IndexedResourceArchive(gUiHandCursorArchive).GetGroupData(0).palettes.data,
        reinterpret_cast<void *>(0x05000200 + command->cursor_palette * 32), 8);
    return false;
}


EC void func_08050E0C(UiStateOwner const * object, char const * first, char const * second,
    char const * third, char const * fourth, char const * fifth, char const * sixth,
    ScriptTextVariableStore * variables)
{
    object->value->SetChoices(first, second, third, fourth, fifth, sixth, variables);
}

EC void func_08050E30(UiStateOwner const * object, char const * prompt, char const * first,
    char const * second, char const * third, char const * fourth,
    ScriptTextVariableStore * variables)
{
    object->value->SetPromptChoices(prompt, first, second, third, fourth, variables);
}

void UiStateOwner::ShowPortrait(u32 index) const
{
    value->ShowPortrait(index);
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

void UiStateOwner::ShowHeartIndicator(u32 level) const
{
    value->ShowHeartIndicator(level);
}

void UiStateOwner::HideHeartIndicator() const
{
    value->HideHeartIndicator();
}

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

inline UiTextWindowSetupCommand::UiTextWindowSetupCommand(u32 screen, u32 tile, u32 background, u32 cursor)
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

static inline void AppendUiTextRowSprite(HardwareSpriteBufferState * buffer,
    HardwareSpriteOamRecord attributes, i32 const & x, u32 const & y, u32 palette)
{
    attributes.y = y;
    // attr1 is a real 16-bit register view; a whole-word bitfield assignment
    // would also rewrite attr0 with this old compiler.
    reinterpret_cast<HardwareSpriteOamAttributes *>(&attributes)->horizontal.x = x;
    u8 & palette_attribute = reinterpret_cast<u8 *>(&attributes)[5];
    palette_attribute = (palette_attribute & 15) | (palette << 4);
    u32 count = buffer->sprite_count;
    if (count < ARRAY_COUNT(buffer->sprites)) {
        HardwareSpriteOamRecord & destination = buffer->sprites[count];
        reinterpret_cast<u32 *>(&destination)[0] = reinterpret_cast<u32 const &>(attributes);
        reinterpret_cast<u16 *>(&destination)[2] = reinterpret_cast<u16 const *>(&attributes)[2];
        buffer->sprite_count = count + 1;
    }
}

void DrawUiTextRows(UnkUiSelectionData * object, HardwareSpriteBufferState * sprites)
{
    i32 palette = GetObjPaletteBank(object->palette, object->palette->handle);
    if (palette >= 0) {
        for (int row = 0, y = 107; row <= 2; ++row, y += 17) {
            int index = row + object->unk_18;
            if (index > 2) index -= 3;
            UnkUiSelectionRow * line = object->rows[index].Get();
            for (int column = 0, x = 8; column <= 6; ++column, x += 32) {
                UnkUiSelectionEntry & entry = line->Entry(column);
                HardwareSpriteOamRecord attributes = {};
                attributes.mosaic = 1;
                attributes.shape = 1;
                attributes.size = 2;
                if (HasUiSelectionState(entry.state))
                    attributes.tile_index = GetHardwareSharedStateTileIndex(&entry.state, entry.state.handle);
                else
                    attributes.affine_mode = 2;
                AppendUiTextRowSprite(sprites, attributes, x, y, palette);
            }
        }
    }
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

inline UnkUiSelectionData::UnkUiSelectionData(HardwareResourceEntry * palette,
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

inline UiTextTileCopyCommand::UiTextTileCopyCommand(u32 const * source, u32 * destination,
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

void UiStatePayload::SetText(char const * message, u16 speed,
    ScriptTextVariableStore * variables)
{
    if (state >= 0) {
        if (state <= 2)
            OpenImmediately();
        else if (state <= 6)
            output.NextPage();
    }
    SetUiTextStreamText(&text, message, variables);
    SetUiTextStreamSpeed(&text, speed);
    state = 4;
}

void UiStatePayload::SetChoices(char const * first, char const * second,
    char const * third, char const * fourth, char const * fifth, char const * sixth,
    ScriptTextVariableStore * variables)
{
    if (state >= 0) {
        if (state <= 2)
            OpenImmediately();
        else if (state <= 6)
            output.NextPage();
    }
    // Layouts 0..4 hold two through six choices. Four or more use two columns
    // and the shorter encoded-byte limit. Missing inner slots stay selectable.
    int layout = 4;
    u32 limit = 12;
    if (sixth == nullptr) {
        layout = 3;
        if (fifth == nullptr) {
            layout = 2;
            if (fourth == nullptr) {
                limit = 26;
                layout = 0;
                if (third != nullptr)
                    ++layout;
            }
        }
    }
    switch (layout) {
    default: layout = 0;
    case 4:
        if (sixth == nullptr || strlen(sixth) > limit)
            sixth = reinterpret_cast<char const *>(&gUiTextLayoutPositionTable);
        // Fall through to validate every earlier optional slot.
    case 3:
        if (fifth == nullptr || strlen(fifth) > limit)
            fifth = reinterpret_cast<char const *>(&gUiTextLayoutPositionTable);
    case 2:
        if (fourth == nullptr || strlen(fourth) > limit)
            fourth = reinterpret_cast<char const *>(&gUiTextLayoutPositionTable);
    case 1:
        if (third == nullptr || strlen(third) > limit)
            third = reinterpret_cast<char const *>(&gUiTextLayoutPositionTable);
    case 0:
        break;
    }
    if (second == nullptr || strlen(second) > limit)
        second = reinterpret_cast<char const *>(&gUiTextLayoutPositionTable);
    if (first == nullptr || strlen(first) > limit)
        first = reinterpret_cast<char const *>(&gUiTextLayoutPositionTable);
    switch (layout) {
    case 4:
        RenderUiChoiceLabel(this, GetUiChoiceLayoutPosition(layout, 6), sixth, variables);
    case 3:
        RenderUiChoiceLabel(this, GetUiChoiceLayoutPosition(layout, 5), fifth, variables);
    case 2:
        RenderUiChoiceLabel(this, GetUiChoiceLayoutPosition(layout, 4), fourth, variables);
    case 1:
        RenderUiChoiceLabel(this, GetUiChoiceLayoutPosition(layout, 3), third, variables);
    case 0:
        RenderUiChoiceLabel(this, GetUiChoiceLayoutPosition(layout, 2), second, variables);
        RenderUiChoiceLabel(this, GetUiChoiceLayoutPosition(layout, 1), first, variables);
        break;
    default:
        layout = 0;
    }
    choice_layout = layout;
    choice_index = 1;
    state = 6;
    InitializeIndexedResourceHandle(&choice_handle,
        &hand_cursor, 0);
}

void UiStatePayload::SetPromptChoices(char const * prompt, char const * first,
    char const * second, char const * third, char const * fourth,
    ScriptTextVariableStore * variables)
{
    if (prompt == nullptr || strlen(prompt) > 28)
        prompt = reinterpret_cast<char const *>(&gUiTextLayoutPositionTable);
    // Layouts 5..7 reserve the first row for the prompt and hold 2..4 choices.
    int layout = 7;
    u32 limit = 12;
    if (fourth == nullptr) {
        layout = 6;
        if (third == nullptr) {
            limit = 26;
            layout = 5;
        }
    }
    switch (layout) {
    default: layout = 5;
    case 7:
        if (fourth == nullptr || strlen(fourth) > limit)
            fourth = reinterpret_cast<char const *>(&gUiTextLayoutPositionTable);
    case 6:
        if (third == nullptr || strlen(third) > limit)
            third = reinterpret_cast<char const *>(&gUiTextLayoutPositionTable);
    case 5:
        break;
    }
    if (second == nullptr || strlen(second) > limit)
        second = reinterpret_cast<char const *>(&gUiTextLayoutPositionTable);
    if (first == nullptr || strlen(first) > limit)
        first = reinterpret_cast<char const *>(&gUiTextLayoutPositionTable);
    output.NextPage();
    UiTextLayoutPosition prompt_position = {0, 0, 0};
    RenderUiChoiceLabel(this, prompt_position, prompt, variables);
    switch (layout) {
    case 7:
        RenderUiChoiceLabel(this, GetUiChoiceLayoutPosition(layout, 4), fourth, variables);
    case 6:
        RenderUiChoiceLabel(this, GetUiChoiceLayoutPosition(layout, 3), third, variables);
    case 5:
        RenderUiChoiceLabel(this, GetUiChoiceLayoutPosition(layout, 2), second, variables);
        RenderUiChoiceLabel(this, GetUiChoiceLayoutPosition(layout, 1), first, variables);
        break;
    default:
        layout = 5;
    }
    choice_layout = layout;
    choice_index = 1;
    state = 6;
    InitializeIndexedResourceHandle(&choice_handle,
        &hand_cursor, 0);
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

void UiStatePayload::ShowHeartIndicator(u32 level)
{
    if (level >= heart_indicator_archive.GetEntryDescriptorCount()) {
        HideHeartIndicator();
        return;
    }
    heart_indicator_visible = 1;
    ResolveIndexedResourceHandle(&heart_indicator_handle, level);
}

void UiStatePayload::HideHeartIndicator()
{
    heart_indicator_visible = 0;
}

UiStatePayload::UiStatePayload(u32 background, u32 screen, u32 palette_bank,
    u32 mode, HardwareStateOwner const & shared, HardwareResource const & resources)
    : background(background), screen_block(screen), character_block(screen >> 3),
      first_tile((screen & 7) * 64 + 20), background_palette(palette_bank),
      mode(mode), state(0), unk_0c(0), allow_resume(1),
      palette(resources.Get()), background_state(shared.Get(2)),
      commands(), records(), records_command(records), output(&palette, shared),
      text(), output_command(&output),
      tile_copy(reinterpret_cast<u32 const *>(gUiSharedTiles),
          &reinterpret_cast<u32 (*)[512][8]>(0x06000000)[character_block][first_tile][0],
          gUiSharedTileByteCount / 32, mode == 1),
      window(screen_block, first_tile, background_palette,
          palette.GetIndex()),
      choice_index(0), hand_cursor(gUiHandCursorArchive),
#if defined(REGION_JP)
      choice_cursor(gUnk_084AF4E4),
#else
      choice_cursor(gUnk_0872937C),
#endif
      choice_handle(&choice_cursor, 0, 256), choice_state(shared.Get(7)),
      portrait_flags(), portrait(), portrait_palette(resources.Get()), nameplate_flags(),
      nameplate_tiles(), heart_indicator_visible(0),
      heart_indicator_archive(gUiHeartIndicatorArchive),
      heart_indicator_handle(&heart_indicator_archive, 0, 256),
      heart_indicator_palette(resources.Get()), low_flags()
{
}

// Keep the native text/table/pointer order. Definitions follow their consumers
// so the old compiler retains accesses through the named pointer/count objects.
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
u32 const gUiSharedTileByteCount = UI_SHARED_TILE_BYTES;
u8 const * const gUiSharedPalette = gUnk_UiSharedResourceData_001;
u32 const gUiSharedPaletteByteCount = UI_SHARED_PALETTE_BYTES;
