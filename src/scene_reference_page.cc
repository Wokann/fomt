#include "config.h"
#include "scene_reference_page.hh"
#include "game_state_types.hh"
#include "hardware_blend.hh"
#include "hardware_blend_owner.hh"
#include "hardware_display_state.hh"
#include "hardware_dma_queue.hh"
#include "hardware_input.hh"
#include "hardware_sprite_buffer.hh"
#include "ui_state.hh"
#include "ui_text_window_border.hh"
#include "reference_guide.hh"
#include "allocation_failure.hh"
#include <algorithm>
#include <functional>
#include <memory>
#include <string.h>

// The native list reads 32-bit IDs and stores their low halfwords.
u32 const gReferencePageInitialEntryIds[] = {
        0x00000002,
        0x00000088,
        0x00000003,
        0x00000004,
        0x00000005,
        0x00000006,
        0x00000007,
        0x00000008,
    };

// The native selector chooses one of two rows. Its stride is 9 bytes
// in JP and 12 bytes overseas; each row includes its own terminator.
#include FOMT_TEXT_INCLUDE(scene_reference_page.cc)

extern template u32 * std::__lower_bound(
    u32 *, u32 *, u32 const &, std::less<u32>, ptrdiff_t *);

static inline void QueueReferencePageBlend(ReferencePageSceneCore * core,
    HardwareBlendOwner const & blend)
{
    GetHardwareCommandList(reinterpret_cast<void * const *>(core))->Append(blend.object);
}

static inline IndexedResourceGroupResult ReferenceSpriteGroup(IndexedResourceHandle const & handle)
{
    return handle.resource->GetGroupData(handle.resolved_resource[handle.current_entry_index].group_index);
}

ReferencePageSceneCore::ReferencePageSceneCore(GameStateSaveImage * image, i32 page)
    : HardwareContext(HardwareInputRepeatParameters(30, 1)), save(image), music(1),
      title(), arrow_archive(gUnk_08527094), cursor_archive(gUiHandCursorArchive),
      up_arrow(&arrow_archive, 0), down_arrow(&arrow_archive, 1),
      cursor(&cursor_archive, 0), arrow_tiles(4), arrow_palette(),
      title_sprite_tiles(6), title_sprite_palette(), cursor_tiles(2), cursor_palette(),
      starred_lines()
{
    scroll_y = 0;
    previous_row_y = 0;
    saved_menu_scroll_y = 0;
    scroll_y_fixed = 0;
    selected_entry = 0;
    first_visible_row = 0;
    if (page == ReferencePageScene::BOOK_LIST)
    {
        direct_page = false;
        letter_list = false;
        phase = 0;
    }
    else if (page == ReferencePageScene::LETTER_LIST)
    {
        direct_page = false;
        letter_list = true;
        phase = 0;
    }
    else if (page == 0x1002)
    {
        direct_page = false;
        letter_list = false;
        phase = 0;
    }
    else
    {
        page_id = page;
        lines = gReferenceGuideTables[page_id];
        direct_page = true;
        letter_list = true;
        phase = 7;
    }
}

inline void ReferencePageSceneCore::ScrollWithHeldKeys(HardwareKeySnapshot const & held)
{
    u8 const * buttons = held.bytes;
    i32 step = (buttons[1] & (R_BUTTON >> 8)) ? 8 << 16 : 4 << 16;
    if (buttons[0] & DPAD_UP)
        ScrollReferenceArticle(this, -step);
    else if (buttons[0] & DPAD_DOWN)
        ScrollReferenceArticle(this, step);
}

SceneTransitionOwner ReferencePageSceneCore::Run()
{
    EnableHardwareForcedBlank(this);
    HardwareDisplayRegisterValue display_value;
    GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->SetBlendControl(display_value = BLDCNT_TGT1_ALL);
    HardwareBlendOwner blend(new HardwareBlendObject(
        GetHardwareDisplayState(reinterpret_cast<void * const *>(this))));
    LoadReferencePageGraphics(this);
    InitializeReferencePageSprites(this);
    bool finished = false;
    while (finished != true)
    {
        if (phase <= 6)
        {
            EnableHardwareForcedBlank(this);
            scroll_y = saved_menu_scroll_y;
            previous_row_y = scroll_y;
            scroll_y_fixed = scroll_y << 16;
            InitializeReferenceBookList(this);
            {
                HardwareBlendObject & fade = *blend.object;
                i16 step = 0x889;
                fade.blend.Begin(step, 1, 1);
            }
            QueueReferencePageBlend(this, blend);
            bool leave_page = false;
            do
            {
                UpdateHardwareFrame(this);
                UpdateHardwareInput(reinterpret_cast<void * const *>(this));
                switch (phase)
                {
                default:
                case 0:
                    cursor.unk_30 = 1;
                    phase = 1;
                    break;
                case 1:
                    if (!blend.IsQueued())
                        phase = 2;
                    break;
                case 2:
                    if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)) & DPAD_UP))
                    {
                        music.Start(0xCB);
                        selected_entry = selected_entry > 0 ? (--selected_entry, selected_entry) : 0;
                        if (selected_entry < first_visible_row)
                        {
                            --first_visible_row;
                            previous_row_y = scroll_y & 0xFFF0;
                            phase = 3;
                        }
                    }
                    else if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)) & DPAD_DOWN))
                    {
                        music.Start(0xCB);
                        selected_entry = selected_entry < entry_count - 1
                            ? (++selected_entry, selected_entry) : static_cast<i16>(entry_count - 1);
                        if (selected_entry - first_visible_row > 7)
                        {
                            ++first_visible_row;
                            previous_row_y = scroll_y & 0xFFF0;
                            phase = 4;
                        }
                    }
                    else if (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & A_BUTTON))
                    {
                        music.Start(0xC5);
                        saved_menu_scroll_y = scroll_y;
                        page_id = entry_ids[selected_entry];
                        lines = gReferenceGuideTables[page_id];
                        phase = 5;
                    }
                    else if (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & B_BUTTON))
                    {
                        music.Start(0xC6);
                        page_id = -1;
                        phase = 5;
                    }
                    break;
                case 3:
                    scroll_y_fixed -= 4 << 16;
                    if (scroll_y_fixed < 0)
                        scroll_y_fixed = 0;
                    scroll_y = static_cast<i16>(scroll_y_fixed >> 16);
                    if ((scroll_y & 15) == 0)
                    {
                        UpdateReferenceBookListRow(this);
                        phase = 2;
                    }
                    break;
                case 4:
                    scroll_y_fixed += 4 << 16;
                    if (scroll_y_fixed > maximum_scroll_fixed)
                        scroll_y_fixed = maximum_scroll_fixed;
                    scroll_y = static_cast<i16>(scroll_y_fixed >> 16);
                    if ((scroll_y & 15) == 0)
                    {
                        UpdateReferenceBookListRow(this);
                        phase = 2;
                    }
                    break;
                case 5:
                    {
                        HardwareBlendObject & fade = *blend.object;
                        i16 step = 0x889;
                        fade.blend.End(step, 1, 1);
                    }
                    QueueReferencePageBlend(this, blend);
                    phase = 6;
                    break;
                case 6:
                    if (!blend.IsQueued())
                    {
                        if (page_id < 0)
                            finished = true;
                        else
                            phase = 7;
                        leave_page = true;
                    }
                    break;
                }
                GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->SetBackgroundY(1, display_value = scroll_y);
                cursor_x = 12;
                cursor_y = selected_entry * 16 - static_cast<i16>(first_visible_row * 16 - 40);
                RenderReferencePageSprites(this);
            } while (leave_page != true);
            if (finished)
                continue;
        }
        EnableHardwareForcedBlank(this);
        InitializeReferenceArticle(this);
        {
            HardwareBlendObject & fade = *blend.object;
            i16 step = 0x889;
            fade.blend.Begin(step, 1, 1);
        }
        QueueReferencePageBlend(this, blend);
        bool leave_article = false;
        do
        {
            UpdateHardwareFrame(this);
            UpdateHardwareInput(reinterpret_cast<void * const *>(this));
            switch (phase)
            {
            default:
            case 7:
                scroll_y = 0;
                previous_row_y = scroll_y;
                scroll_y_fixed = scroll_y << 16;
                cursor.unk_30 = 0;
                phase = 8;
                break;
            case 8:
                if (!blend.IsQueued())
                    phase = 9;
                break;
            case 9:
            {
                HardwareKeySnapshot held;
                held.value = GetHardwareHeldKeys(reinterpret_cast<void * const *>(this));
                u32 pressed = GetHardwarePressedKeys(reinterpret_cast<void * const *>(this));
                if (pressed & (A_BUTTON | B_BUTTON))
                {
                    music.Start(0xC6);
                    phase = 13;
                }
                else
                {
                    // Move the two direction bits to bit 31 before comparing them.
                    HardwareKeySnapshot direction = held;
                    u32 up = direction.value << 25;
                    u32 down = direction.value << 24;
                    up >>= 31;
                    down >>= 31;
                    if (up == down)
                        break;
                    u8 const * buttons = held.bytes;
                    if ((buttons[1] & (L_BUTTON >> 8)) && !starred_lines.Empty())
                    {
                        if (pressed & (L_BUTTON | DPAD_UP | DPAD_DOWN))
                        {
                            u32 row = scroll_y >> 4;
                            if (buttons[0] & DPAD_UP)
                            {
                                u32 next = row;
                                if (scroll_y_fixed & 0xFFFFF)
                                    ++next;
                                if (next > starred_lines.Front())
                                    phase = 10;
                            }
                            else if (row < starred_lines.End()[-1])
                                phase = 11;
                        }
                    }
                    else
                    {
                        ScrollWithHeldKeys(held);
                    }
                }
                break;
            }
            case 10:
                ScrollReferenceArticle(this,
                    ((scroll_y_fixed - 1) & 0xFFF00000) - scroll_y_fixed);
                if (scroll_y_fixed == 0 || IsTopLineStarred())
                    phase = 12;
                break;
            case 11:
                ScrollReferenceArticle(this,
                    ((scroll_y_fixed + (16 << 16)) & 0xFFF00000) - scroll_y_fixed);
                if (scroll_y_fixed == maximum_scroll_fixed || IsTopLineStarred())
                    phase = 12;
                break;
            case 12:
            {
                HardwareKeySnapshot held;
                held.value = GetHardwareHeldKeys(reinterpret_cast<void * const *>(this));
                u8 const * buttons = held.bytes;
                if (!(buttons[0] & (DPAD_UP | DPAD_DOWN)) || !(buttons[1] & (L_BUTTON >> 8)))
                    phase = 9;
                break;
            }
            case 13:
                {
                    HardwareBlendObject & fade = *blend.object;
                    i16 step = 0x889;
                    fade.blend.End(step, 1, 1);
                }
                QueueReferencePageBlend(this, blend);
                phase = 14;
                break;
            case 14:
                if (!blend.IsQueued())
                {
                    if (direct_page == true)
                        finished = true;
                    else
                        phase = 0;
                    leave_article = true;
                }
                break;
            }
            GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->SetBackgroundY(1, display_value = scroll_y);
            RenderReferencePageSprites(this);
        } while (leave_article != true);
    }
    return SceneTransitionOwner();
}

void LoadReferencePageGraphics(ReferencePageSceneCore * core)
{
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[1][0], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[1][1], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[2][0], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[2][1], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[3][0], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[3][1], 0);
    FillHardwareDma3(0, reinterpret_cast<void *>(BG_VRAM + 0x7FE0), TILE_SIZE_4BPP);
    FillHardwareDma3(~u32(0), reinterpret_cast<void *>(BG_VRAM + 0xE000), BG_SCREEN_SIZE);
    FillHardwareDma3(~u32(0), reinterpret_cast<void *>(BG_VRAM + 0xE800), BG_SCREEN_SIZE);
    FillHardwareDma3(~u32(0), reinterpret_cast<void *>(BG_VRAM + 0xF000), BG_SCREEN_SIZE);
    WriteHardwareDisplayFlags(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_control[3],
        BGCNT_PRIORITY(3) | BGCNT_SCREENBASE(28) | BGCNT_MOSAIC);
    WriteHardwareDisplayFlags(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_control[2],
        BGCNT_PRIORITY(1) | BGCNT_SCREENBASE(29) | BGCNT_MOSAIC);
    WriteHardwareDisplayFlags(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_control[1],
        BGCNT_PRIORITY(2) | BGCNT_SCREENBASE(30) | BGCNT_MOSAIC);
    CopyHardwareDma3(gUiSharedTiles, reinterpret_cast<void *>(BG_VRAM), gUiSharedTileByteCount);
    FillHardwareDma3(0x00030003, reinterpret_cast<void *>(BG_VRAM + 0xE000), BG_SCREEN_SIZE);
    DrawUiTextWindowBorder(reinterpret_cast<u16 *>(BG_VRAM + 0xE800), 0, 0, 32, 3, 0, 0);
    CopyHardwareDma3(gUiSharedPalette, reinterpret_cast<void *>(BG_PLTT), PLTT_SIZE_4BPP);
    reinterpret_cast<volatile u16 *>(BG_PLTT + 2 * PLTT_SIZE_4BPP)[0] = 0x03E0;
    reinterpret_cast<volatile u16 *>(BG_PLTT + 2 * PLTT_SIZE_4BPP)[1] = 0;
    reinterpret_cast<volatile u16 *>(BG_PLTT + 2 * PLTT_SIZE_4BPP)[2] = 0x4218;
    reinterpret_cast<volatile u16 *>(OBJ_PLTT + core->title_sprite_palette.GetIndex() * PLTT_SIZE_4BPP)[0] = 0x03E0;
    reinterpret_cast<volatile u16 *>(OBJ_PLTT + core->title_sprite_palette.GetIndex() * PLTT_SIZE_4BPP)[1] = 0;
    reinterpret_cast<volatile u16 *>(OBJ_PLTT + core->title_sprite_palette.GetIndex() * PLTT_SIZE_4BPP)[2] = 0x4218;
    u16 tilemap[32][32];
    FillHardwareDma3(~u32(0), tilemap, sizeof(tilemap));
    u16 first = 0x2060;
    for (i32 row = 0; row < 16; ++row)
    {
        for (i32 column = 0; column < 28; ++column)
        {
            tilemap[row * 2][column + 1] = first + column;
            tilemap[row * 2 + 1][column + 1] = first + column + 28;
        }
        first += 56;
    }
    CopyHardwareDma3(tilemap, reinterpret_cast<void *>(BG_VRAM + 0xF000), sizeof(tilemap));
}

void InitializeReferenceBookList(ReferencePageSceneCore * core)
{
    core->entry_count = 0;
    if (!core->letter_list)
    {
        for (u32 index = 0; index < ARRAY_COUNT(gReferencePageInitialEntryIds); ++index)
        {
            core->entry_ids[core->entry_count] = gReferencePageInitialEntryIds[index];
            ++core->entry_count;
        }
        if (core->save->farm.farm_house.HasVase())
        {
            core->entry_ids[core->entry_count] = 74;
            ++core->entry_count;
        }
        if (core->save->farm.farm_house.GetFridge())
        {
            core->entry_ids[core->entry_count] = 75;
            ++core->entry_count;
        }
        if (core->save->farm.farm_house.GetShelf())
        {
            core->entry_ids[core->entry_count] = 76;
            ++core->entry_count;
        }
        if (core->save->farm.farm_house.HasKitchen())
        {
            core->entry_ids[core->entry_count] = 12;
            ++core->entry_count;
        }
        if (core->save->farm.farm_house.HasBathroom())
        {
            core->entry_ids[core->entry_count] = 73;
            ++core->entry_count;
        }
        if (core->save->farm.farm_house.GetRecordPlayer())
        {
            core->entry_ids[core->entry_count] = 72;
            ++core->entry_count;
        }
    }
    else
    {
        for (i32 page = 77; page <= 136; ++page)
            if (core->save->farm.farm_house.unk.method_0800BD40(page))
            {
                core->entry_ids[core->entry_count] = page;
                ++core->entry_count;
            }
    }
    if (core->entry_count + 2 > 10)
        core->maximum_scroll_fixed = (core->entry_count + 2 - 10) << 20;
    else
        core->maximum_scroll_fixed = 0;
    for (i32 row = 0; row <= 10; ++row)
    {
        core->title.Clear();
        i32 entry = core->first_visible_row + row;
        if (entry > 1 && entry < core->entry_count + 2)
        {
            core->lines = gReferenceGuideTables[core->entry_ids[entry - 2]];
            if (core->lines[0])
            {
                char text[32];
                ExpandReferencePageText(core, core->lines[0], text);
                core->title.DrawStringExt(0, 0, text, 0, 1);
            }
        }
        u32 slot = ((core->scroll_y >> 4) + row) & 15;
        CopyHardwareDma3(core->title.tiles, reinterpret_cast<void *>(BG_VRAM + 0xC00 +
            slot * sizeof(core->title.tiles)), sizeof(core->title.tiles));
    }
    FillHardwareDma3(0, reinterpret_cast<void *>(OBJ_VRAM0 +
        core->title_sprite_tiles.GetTileIndex() * TILE_SIZE_4BPP), sizeof(core->title.tiles));
    UiSpriteGlyphBuffer glyph;
    for (i32 index = 0; index < static_cast<i32>(sizeof(gText_ReferencePage_Menu[0])); ++index)
    {
#if defined(REGION_JP)
        u32 byte_index = index * 2;
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
        u32 byte_index = index;
#endif
        u32 menu = static_cast<u32>(core->letter_list) & 1;
#if defined(REGION_JP)
        u8 character[2];
        character[0] = gText_ReferencePage_Menu[menu][byte_index];
        if (character[0])
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
        u8 character = gText_ReferencePage_Menu[menu][byte_index];
        if (character)
#endif
        {
#if defined(REGION_JP)
            character[1] = gText_ReferencePage_Menu[menu][byte_index + 1];
#endif
            glyph.Clear();
#if defined(REGION_JP)
            u32 lead = character[0] << 8;
            glyph.DrawCharacterExt(0, 0, character[1] | lead, 0, 1);
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
            glyph.DrawCharacterExt(0, 0, character, 0, 1);
#endif
            CopyHardwareDma3(glyph.tiles, reinterpret_cast<void *>(OBJ_VRAM0 +
                (core->title_sprite_tiles.GetTileIndex() +
                index * UiSpriteGlyphBuffer::TileCount) * TILE_SIZE_4BPP), sizeof(glyph.tiles));
        }
        else
            break;
    }
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetDisplayFlags(
        DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
}

static inline void QueueReferencePageRow(ReferencePageTitleBuffer const & buffer,
    HardwareDmaQueue * queue, u32 slot)
{
    queue->PushBack(DmaTransferDescriptor(buffer.tiles,
        reinterpret_cast<void *>(BG_VRAM + 0xC00 + slot * sizeof(buffer.tiles)), sizeof(buffer.tiles)));
}

void UpdateReferenceBookListRow(ReferencePageSceneCore * core)
{
    i32 row;
    u32 slot;
    if (core->scroll_y > core->previous_row_y)
    {
        row = (core->scroll_y >> 4) + 8;
        slot = (static_cast<u32>(core->scroll_y >> 4) + 10) % 16;
    }
    else
    {
        row = (core->scroll_y >> 4) - 2;
        slot = static_cast<u32>(core->scroll_y >> 4) % 16;
    }
    core->title.Clear();
    if (row >= 0)
    {
        core->lines = gReferenceGuideTables[core->entry_ids[row]];
        if (core->lines[0])
        {
            char text[32];
            ExpandReferencePageText(core, core->lines[0], text);
            core->title.DrawStringExt(0, 0, text, 0, 1);
        }
    }
    QueueReferencePageRow(core->title,
        GetHardwareDmaQueue(reinterpret_cast<void * const *>(core)), slot);
}

inline u32 * ReferencePageStarredLines::Allocator::AllocateBytes(u32 bytes) const
{
    u32 * result = static_cast<u32 *>(malloc(bytes));
    if (!result)
        result = static_cast<u32 *>(RetryMemoryAllocation(bytes));
    return result;
}

static inline u8 * CopyReferenceLineBytes(u8 * destination, u8 const * first, u8 const * last)
{
    if (last != first)
    {
        u32 bytes = last - first;
        return static_cast<u8 *>(memmove(destination, first, bytes)) + bytes;
    }
    return destination;
}

static inline u32 * CopyReferenceStarredLines(u32 * destination, u32 const * first, u32 const * last)
{
    return reinterpret_cast<u32 *>(CopyReferenceLineBytes(reinterpret_cast<u8 *>(destination),
        reinterpret_cast<u8 const *>(first), reinterpret_cast<u8 const *>(last)));
}

static inline void AppendReferenceStarredLine(ReferencePageStarredLines & rows, u32 const & value)
{
    if (rows.last != rows.allocation.end)
    {
        std::construct(rows.last, value);
        ++rows.last;
    }
    else
    {
        u32 * old_end = rows.last;
        u32 amount = 1;
        u32 count = old_end - rows.first;
        u32 capacity = count + std::max(count, amount);
        u32 * const replacement = capacity ? rows.allocation.AllocateBytes(capacity * sizeof(u32)) : nullptr;
        u32 * end = CopyReferenceStarredLines(replacement, rows.first, old_end);
        for (u32 remaining = amount; remaining; --remaining)
            *end++ = value;
        if (rows.first)
            rows.allocation.Deallocate(rows.first, rows.allocation.end - rows.first);
        u32 * capacity_end = reinterpret_cast<u32 *>(
            capacity * sizeof(u32) + reinterpret_cast<uptr>(replacement));
        rows.first = replacement;
        rows.last = end;
        rows.allocation.end = capacity_end;
    }
}

void InitializeReferenceArticle(ReferencePageSceneCore * core)
{
    i16 count = 0;
    while (core->lines[count])
    {
        if (core->lines[count][0] == '<')
        {
            u8 const * text = reinterpret_cast<u8 const *>(core->lines[count]);
            if (static_cast<u8>(text[1] - '0') <= 9)
            {
                u8 digits[3];
                for (i32 index = 0; index < 3; ++index)
                    digits[index] = text[index + 1] - '0';
                if (IsReferenceProfileBoundary(core, digits[0] * 100 + digits[1] * 10 + digits[2]) == 1)
                    break;
            }
        }
        ++count;
    }
    --count;
    if (count + 2 > 10)
        core->maximum_scroll_fixed = (count + 2 - 10) << 20;
    else
        core->maximum_scroll_fixed = 0;
    core->starred_lines.Clear();
    for (i32 row = 0; row < count; ++row)
    {
        u8 const * text = reinterpret_cast<u8 const *>(core->lines[row + 1]);
        if ((text[0] << 8 | text[1]) == 0x819A)
            AppendReferenceStarredLine(core->starred_lines, row);
    }
    FillHardwareDma3(0, reinterpret_cast<void *>(BG_VRAM + 0xC00), sizeof(core->title.tiles) * 2);
    for (i32 row = 0; row <= 8; ++row)
    {
        core->title.Clear();
        if (row < count && core->lines[row + 1])
        {
            char text[32];
            ExpandReferencePageText(core, core->lines[row + 1], text);
            core->title.DrawStringExt(0, 0, text, 0, 1);
        }
        CopyHardwareDma3(core->title.tiles, reinterpret_cast<void *>(BG_VRAM + 0x1A00 +
            row * sizeof(core->title.tiles)), sizeof(core->title.tiles));
    }
    FillHardwareDma3(0, reinterpret_cast<void *>(OBJ_VRAM0 +
        core->title_sprite_tiles.GetTileIndex() * TILE_SIZE_4BPP), sizeof(core->title.tiles));
    if (core->lines[0])
    {
        char text[32];
        ExpandReferencePageText(core, core->lines[0], text);
        UiSpriteGlyphBuffer glyph;
        for (i32 index = 0; index < ReferencePageTitleBuffer::GlyphCount; ++index)
        {
#if defined(REGION_JP)
            u8 character[2];
            character[0] = text[index * 2];
            if (character[0])
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
            u8 character = text[index];
            if (character)
#endif
            {
#if defined(REGION_JP)
                character[1] = text[index * 2 + 1];
#endif
                glyph.Clear();
#if defined(REGION_JP)
                u32 lead = character[0] << 8;
                glyph.DrawCharacterExt(0, 0, character[1] | lead, 0, 1);
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
                glyph.DrawCharacterExt(0, 0, character, 0, 1);
#endif
                CopyHardwareDma3(glyph.tiles, reinterpret_cast<void *>(OBJ_VRAM0 +
                    (core->title_sprite_tiles.GetTileIndex() +
                    index * UiSpriteGlyphBuffer::TileCount) * TILE_SIZE_4BPP), sizeof(glyph.tiles));
            }
            else
                break;
        }
    }
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetDisplayFlags(
        DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
}

i32 IsReferenceProfileBoundary(ReferencePageSceneCore * core, u32 condition)
{
    bool boundary = false;
    u32 level;
    switch (condition / 10)
    {
    case 0: level = core->save->event_state.gamecube_link_awl_takakura_profile_level; break;
    case 1: level = core->save->event_state.gamecube_link_awl_romana_profile_level; break;
    case 2: level = core->save->event_state.gamecube_link_awl_lumina_profile_level; break;
    case 3: level = core->save->event_state.gamecube_link_awl_sebastian_profile_level; break;
    case 4: level = core->save->event_state.gamecube_link_awl_wally_profile_level; break;
    case 5: level = core->save->event_state.gamecube_link_awl_chris_profile_level; break;
    case 6: level = core->save->event_state.gamecube_link_awl_hugh_profile_level; break;
    case 7: level = core->save->event_state.gamecube_link_awl_grant_profile_level; break;
    case 8: level = core->save->event_state.gamecube_link_awl_samantha_profile_level; break;
    case 9: level = core->save->event_state.gamecube_link_awl_kate_profile_level; break;
    case 10: level = core->save->event_state.gamecube_link_awl_galen_profile_level; break;
    case 11: level = core->save->event_state.gamecube_link_awl_nina_profile_level; break;
    case 12: level = core->save->event_state.gamecube_link_awl_daryl_profile_level; break;
    case 13: level = core->save->event_state.gamecube_link_awl_gustafa_profile_level; break;
    case 14: level = core->save->event_state.gamecube_link_awl_cody_profile_level; break;
    case 15: level = core->save->event_state.gamecube_link_awl_kassey_profile_level; break;
    case 16: level = core->save->event_state.gamecube_link_awl_patrick_profile_level; break;
    case 17: level = core->save->event_state.gamecube_link_awl_murrey_profile_level; break;
    case 18: level = core->save->event_state.gamecube_link_awl_tim_profile_level; break;
    case 19: level = core->save->event_state.gamecube_link_awl_lou_or_ruby_profile_level; break;
    case 20: level = core->save->event_state.gamecube_link_awl_nami_profile_level; break;
    case 21: level = core->save->event_state.gamecube_link_awl_rock_profile_level; break;
    case 22: level = core->save->event_state.gamecube_link_awl_griffin_profile_level; break;
    case 23: level = core->save->event_state.gamecube_link_awl_muffy_profile_level; break;
    case 24: level = core->save->event_state.gamecube_link_awl_carter_profile_level; break;
    case 25: level = core->save->event_state.gamecube_link_awl_flora_profile_level; break;
    case 26: level = core->save->event_state.gamecube_link_awl_vesta_profile_level; break;
    case 27: level = core->save->event_state.gamecube_link_awl_marlin_profile_level; break;
    case 28: level = core->save->event_state.gamecube_link_awl_celia_profile_level; break;
    case 29: level = core->save->event_state.gamecube_link_awl_hardy_profile_level; break;
    case 30: level = core->save->event_state.gamecube_link_awl_van_profile_level; break;
    case 31: level = core->save->event_state.gamecube_link_awl_mooky_profile_level; break;
    case 32: level = core->save->event_state.gamecube_link_awl_child_profile_level; break;
    case 33: level = core->save->event_state.gamecube_link_awl_nak_profile_level; break;
    case 34: level = core->save->event_state.gamecube_link_awl_nic_profile_level; break;
    case 35: level = core->save->event_state.gamecube_link_awl_flak_profile_level; break;
    case 36: level = core->save->event_state.gamecube_link_awl_player_profile_level; break;
    default: level = 0; break;
    }
    if (level <= condition % 10)
        boundary = true;
    return boundary;
}

void UpdateReferenceArticleRow(ReferencePageSceneCore * core)
{
    i32 row;
    u32 slot;
    if (core->scroll_y > core->previous_row_y)
    {
        row = (core->scroll_y >> 4) + 8;
        slot = (static_cast<u32>(core->scroll_y >> 4) + 10) % 16;
    }
    else
    {
        row = (core->scroll_y >> 4) - 2;
        slot = static_cast<u32>(core->scroll_y >> 4) % 16;
    }
    core->title.Clear();
    if (row >= 0 && core->lines[row + 1])
    {
        char text[32];
        ExpandReferencePageText(core, core->lines[row + 1], text);
        core->title.DrawStringExt(0, 0, text, 0, 1);
    }
    QueueReferencePageRow(core->title,
        GetHardwareDmaQueue(reinterpret_cast<void * const *>(core)), slot);
}

void ExpandReferencePageText(ReferencePageSceneCore * core, char const * text, char * output)
{
    i32 count = 0;
    u8 bytes[3];
    bytes[0] = text[0];
    bytes[1] = text[1];
    while (bytes[0])
    {
        if (bytes[0] == '<')
        {
            if (static_cast<u8>(bytes[1] - '0') <= 9)
                text += 5;
            else if (bytes[1] == 'p')
            {
                for (i32 index = 0; index <= 12 && core->save->farmer.GetName()[index]; ++index)
                    *output++ = core->save->farmer.GetName()[index];
                text += 3;
            }
            else if (bytes[1] == 'f')
            {
                for (i32 index = 0; index <= 12 && core->save->farm.GetName()[index]; ++index)
                    *output++ = core->save->farm.GetName()[index];
                text += 3;
            }
            else if (bytes[1] == 'c')
            {
                bytes[2] = text[2];
                char const * name = nullptr;
                if (bytes[2] == 'p')
                    name = core->save->link_record.name_24;
                else if (bytes[2] == 'f')
                    name = core->save->link_record.name_14;
                else if (bytes[2] == 's')
                    name = core->save->link_record.name_34;
                if (name)
                    for (i32 index = 0; index <= 16 && name[index]; ++index)
                        *output++ = name[index];
                text += 4;
            }
        }
        else
        {
            output[0] = bytes[0];
#if defined(BUGFIX) && (defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE))
            // Neither NUL nor '<' can be a Shift-JIS trailing byte.
            if (bytes[1] == 0)
            {
                ++output;
                break;
            }
            if (bytes[1] == '<')
            {
                ++output;
                ++text;
            }
            else
#endif
            {
                output[1] = bytes[1];
                output += 2;
                text += 2;
            }
        }
        if (++count > 13)
            break;
        bytes[0] = text[0];
        bytes[1] = text[1];
    }
    *output = 0;
}

void InitializeReferencePageSprites(ReferencePageSceneCore * core)
{
    IndexedResourceGroupResult group(nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0);
    group = ReferenceSpriteGroup(core->up_arrow.handle);
    CopyHardwareDma3(group.palettes.GetData(),
        reinterpret_cast<void *>(OBJ_PLTT + core->arrow_palette.GetIndex() * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount());
    group = core->cursor_archive.GetGroupData(0);
    CopyHardwareDma3(group.palettes.GetData(),
        reinterpret_cast<void *>(OBJ_PLTT + core->cursor_palette.GetIndex() * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount());
    CopyHardwareDma3(group.tiles.GetData(),
        reinterpret_cast<void *>(OBJ_VRAM0 + core->cursor_tiles.GetTileIndex() * TILE_SIZE_4BPP), group.tiles.GetByteCount());
}

void RenderReferencePageSprites(ReferencePageSceneCore * core)
{
    IndexedResourceSpriteParameters parameters;
    IndexedResourceGroupResult group(nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0);
    HardwareSpriteOamRecord attributes;
    attributes.affine_mode = 0;
    attributes.object_mode = 0;
    attributes.mosaic = 1;
    attributes.color_mode = 0;
#if defined(REGION_JP)
    attributes.shape = ST_OAM_SQUARE;
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    attributes.shape = ST_OAM_V_RECTANGLE;
#endif
    attributes.affine_index_low = 0;
    attributes.horizontal_flip = 0;
    attributes.vertical_flip = 0;
#if defined(REGION_JP)
    attributes.size = ST_OAM_SIZE_1;
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    attributes.size = ST_OAM_SIZE_0;
#endif
    attributes.palette_bank = static_cast<u16>(core->title_sprite_palette.GetIndex());
    attributes.affine_coefficient = 0;
    attributes.priority = 1;
    attributes.y = 4;
    for (i32 index = 0; index < ReferencePageTitleBuffer::GlyphCount; ++index)
    {
        attributes.x = 8 + index * (UiSpriteGlyphBuffer::TileWidth * 8);
        attributes.tile_index = core->title_sprite_tiles.GetTileIndex() +
            index * UiSpriteGlyphBuffer::TileCount;
        HardwareSpriteBufferState * buffer = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
        u32 count = buffer->sprite_count;
        if (count < ARRAY_COUNT(buffer->sprites))
        {
            HardwareSpriteOamRecord & destination = buffer->sprites[count];
            reinterpret_cast<u32 *>(&destination)[0] = reinterpret_cast<u32 const &>(attributes);
            reinterpret_cast<u16 *>(&destination)[2] = reinterpret_cast<u16 const *>(&attributes)[2];
            buffer->sprite_count = count + 1;
        }
    }
    if (core->scroll_y_fixed > 0)
    {
        UpdateIndexedResourceHandle(&core->up_arrow.handle);
        group = ReferenceSpriteGroup(core->up_arrow.handle);
        parameters = core->up_arrow.parameters;
        parameters.x = 232;
        parameters.y = 26;
        parameters.tile_offset = core->arrow_tiles.GetTileIndex();
        parameters.palette_offset = core->arrow_palette.GetIndex();
        parameters.priority = 2;
        parameters.mosaic = 1;
        QueueObjTileTransfer(GetHardwareDmaQueue(reinterpret_cast<void * const *>(core)),
            group.tiles.GetData(), core->arrow_tiles.GetTileIndex(), 0, group.tiles.GetByteCount());
        HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
        DrawIndexedResourceSprites(sprites, group.sprites.Data(), group.sprites.Count(), &parameters);
    }
    if (core->scroll_y_fixed < core->maximum_scroll_fixed)
    {
        UpdateIndexedResourceHandle(&core->down_arrow.handle);
        group = ReferenceSpriteGroup(core->down_arrow.handle);
        parameters = core->down_arrow.parameters;
        parameters.x = 232;
        parameters.y = 152;
        parameters.tile_offset = core->arrow_tiles.GetTileIndex() + 4;
        parameters.palette_offset = core->arrow_palette.GetIndex();
        parameters.priority = 2;
        parameters.mosaic = 1;
        QueueObjTileTransfer(GetHardwareDmaQueue(reinterpret_cast<void * const *>(core)),
            group.tiles.GetData(), core->arrow_tiles.GetTileIndex(), 4, group.tiles.GetByteCount());
        HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
        DrawIndexedResourceSprites(sprites, group.sprites.Data(), group.sprites.Count(), &parameters);
    }
    if (core->cursor.unk_30)
    {
        UpdateIndexedResourceHandle(&core->cursor.handle);
        group = ReferenceSpriteGroup(core->cursor.handle);
        parameters = core->cursor.parameters;
        parameters.x = core->cursor_x;
        parameters.y = core->cursor_y;
        parameters.tile_offset = core->cursor_tiles.GetTileIndex();
        parameters.palette_offset = core->cursor_palette.GetIndex();
        parameters.priority = 1;
        parameters.mosaic = 1;
        HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
        DrawIndexedResourceSprites(sprites, group.sprites.Data(), group.sprites.Count(), &parameters);
    }
}

void ScrollReferenceArticle(ReferencePageSceneCore * core, i32 delta)
{
    core->previous_row_y = core->scroll_y & 0xFFF0;
    core->scroll_y_fixed += delta;
    if (core->scroll_y_fixed < 0)
        core->scroll_y_fixed = 0;
    else if (core->scroll_y_fixed > core->maximum_scroll_fixed)
        core->scroll_y_fixed = core->maximum_scroll_fixed;
    core->scroll_y = static_cast<i16>(core->scroll_y_fixed >> 16);
    if (core->previous_row_y != (core->scroll_y & 0xFFF0))
        UpdateReferenceArticleRow(core);
}

bool ReferencePageSceneCore::IsTopLineStarred() const
{
    ReferencePageStarredLines const & rows = starred_lines;
    u32 * first = rows.first;
    u32 * last = rows.last;
    u32 row = scroll_y >> 4;
    u32 * found = std::lower_bound(first, last, row, std::less<u32>());
    return found != last && !(row < *found);
}

inline ReferencePageSceneCoreOwner::ReferencePageSceneCoreOwner(ReferencePageSceneCore * input) : value(input) {}


ReferencePageScene::ReferencePageScene(SceneTransitionOwner next, GameStateSaveImage * image, i32 page)
    : core(new ReferencePageSceneCore(image, page)), continuation(next)
{
}

inline ReferencePageSceneCoreOwner::~ReferencePageSceneCoreOwner() { delete value; }

ReferencePageScene::~ReferencePageScene()
{
}

SceneTransitionOwner ReferencePageScene::Run()
{
    core.value->Run();
    return continuation;
}
