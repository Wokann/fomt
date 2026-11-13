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
#include "hardware_blend_owner.hh"
#include "hardware_input.hh"
#include "ui_text_window_border.hh"
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

static inline void QueueMenuBlend(HardwareContext * core, HardwareBlendOwner const & blend)
{
    HardwareLinkedList * list =
        GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    list->Append(blend.object);
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
    return entry.GetIndex();
}

static inline u32 NormalizeBirthdayDay(u32 day)
{
    if (day > 29)
        day %= 30;
    return day;
}

static inline void SetBirthdayInputDate(GameDate & destination, Season season,
    u32 const & requested_day)
{
    destination.season = season;
    destination.day = NormalizeBirthdayDay(requested_day);
}

static inline GameDate DateFromBirthdaySelection(Season season, i32 displayed_day)
{
    GameDate date;
    date.season = season;
    date.day = NormalizeBirthdayDay(displayed_day - 1);
    return date;
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

NewGameBirthdayInputCore::NewGameBirthdayInputCore(GameDate initial_date)
    : HardwareContext(HardwareInputRepeatParameters(30, 1)), unk_08(0),
      ui_state(new UiStateOwner(0, 31, 15, unk_08,
          ObjTileCollection(), ObjPaletteCollection())),
      music_player_1(1), music_player_2(2),
      glyph_tiles(7), glyph_palette(), cursor_tiles(3), cursor_palette()
{
    SetBirthdayInputDate(birthday, initial_date.season, initial_date.day);
    step = BIRTHDAY_INPUT_WAIT_OPENING;
    dialogue_state = 2;
    switch (birthday.season)
    {
#if defined(REGION_JP)
    case SEASON_SPRING: season_column = 0; break;
    case SEASON_SUMMER: season_column = 1; break;
    case SEASON_FALL: season_column = 2; break;
    case SEASON_WINTER: season_column = 3; break;
#else
    case SEASON_SPRING: season_column = 0; break;
    case SEASON_SUMMER: season_column = 4; break;
    case SEASON_FALL: season_column = 8; break;
    case SEASON_WINTER: season_column = 12; break;
#endif
    }
    day = birthday.day + 1;
    cursor_column = season_column;
    cursor_row = 0;
    saved_season_column = 0;
    cursor_visible = 0;
}

SceneTransitionOwner RunBirthdayInputCore(NewGameBirthdayInputCore * core)
{
    EnableHardwareForcedBlank(core);
    HardwareDisplayState * display =
        GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    HardwareDisplayRegisterValue control(BLDCNT_TGT1_ALL);
    display->SetBlendControl(control);
    HardwareBlendOwner blend(new HardwareBlendObject(
        GetHardwareDisplayState(reinterpret_cast<void * const *>(core))));
    InitializeBirthdayInputGraphics(core);
    InitializeBirthdayInputCursor(core);
    BuildBirthdayInputGlyphs(core);
    {
        HardwareBlendObject & fade = *blend.object;
        i16 step = 0x889;
        fade.blend.Begin(step, 1, 1);
    }
    QueueMenuBlend(core, blend);

    bool finished = false;
    do
    {
        UpdateHardwareFrame(core);
        UpdateHardwareInput(reinterpret_cast<void * const *>(core));
        switch (core->step)
        {
        case BIRTHDAY_INPUT_WAIT_OPENING:
            if (!blend.IsQueued())
            {
                core->cursor_visible = 1;
                ++core->step;
            }
            break;
        case BIRTHDAY_INPUT_CHOOSE_DATE:
            MoveBirthdayInputCursor(core);
            UpdateBirthdayInputCursor(core);
            if (ConfirmBirthdayInputSelection(core))
            {
                core->dialogue_state = 0;
                ++core->step;
            }
            else
                CancelBirthdayInputSelection(core);
            break;
        case BIRTHDAY_INPUT_CONFIRM_DATE:
            if (core->dialogue_state == 2)
            {
                if (core->dialogue_choice == 0)
                {
                    Season season;
                    switch (core->season_column)
                    {
                    case 0: season = SEASON_SPRING; break;
#if defined(REGION_JP)
                    case 1: season = SEASON_SUMMER; break;
                    case 2: season = SEASON_FALL; break;
#else
                    case 4: season = SEASON_SUMMER; break;
                    case 8: season = SEASON_FALL; break;
#endif
                    default: season = SEASON_WINTER; break;
                    }
                    core->birthday = DateFromBirthdaySelection(season, core->day);
                    core->cursor_visible = 0;
                    ++core->step;
                }
                else
                    --core->step;
            }
            break;
        case BIRTHDAY_INPUT_START_CLOSING:
            {
                HardwareBlendObject & fade = *blend.object;
                i16 step = 0x889;
                fade.blend.End(step, 1, 1);
            }
            QueueMenuBlend(core, blend);
            ++core->step;
            break;
        case BIRTHDAY_INPUT_WAIT_CLOSING:
            if (!blend.IsQueued())
                finished = true;
            break;
        }
        UpdateBirthdayInputUi(core);
        RenderBirthdayInputSprites(core);
    } while (!finished);
    return SceneTransitionOwner();
}


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

#include FOMT_TEXT_INCLUDE(new_game_birthday_input.cc)

#if defined(REGION_JP) || defined(REGION_DE)
// The last glyph is reserved for the empty tens place of a single-digit day.
enum { BirthdayBlankGlyph = ARRAY_COUNT(gNewGameBirthdayInputGlyphs) - 1 };
#else
// The English table reuses the first space in the six-slot "Fall  " field.
enum { BirthdayBlankGlyph = 26 };
#endif

void UpdateBirthdayInputCursor(NewGameBirthdayInputCore * core)
{
#if defined(REGION_JP)
    i32 cell_width = core->cursor_column * 32;
    i32 gutter = core->cursor_column * 2 + 2;
    core->cursor_attributes.x = cell_width + gutter;
#else
    core->cursor_attributes.x = core->cursor_column * 16;
#endif
    if (core->cursor_row > 0)
        core->cursor_attributes.y = (core->cursor_row - 1) * 18 + 64;
    else
        core->cursor_attributes.y = 40;

    if (core->cursor_row == 0)
    {
        core->season_column = core->cursor_column;
#if defined(REGION_JP)
        core->glyphs[0].glyph_index = core->cursor_column + 10;
#else
        switch (core->season_column)
        {
        case 0:
            for (int index = 0; index < 6; ++index)
                core->glyphs[index].glyph_index = index + 10;
            break;
        case 4:
            for (int index = 0; index < 6; ++index)
                core->glyphs[index].glyph_index = index + 16;
            break;
        case 8:
            for (int index = 0; index < 6; ++index)
                core->glyphs[index].glyph_index = index + 22;
            break;
        default:
            for (int index = 0; index < 6; ++index)
                core->glyphs[index].glyph_index = index + 28;
            break;
        }
#endif
    }
    else
    {
        i8 const & column = core->cursor_column;
#if defined(REGION_JP)
        core->day = (core->cursor_row - 1) * 7 + static_cast<u8>(column) + 1;
#else
        core->day = column / 2 + (core->cursor_row - 1) * 7 + 1;
#endif
        i32 day_digits[2];
        day_digits[0] = static_cast<i8>(core->day % 10);
        day_digits[1] = static_cast<i8>(core->day / 10);
#if defined(REGION_JP)
        core->glyphs[1].glyph_index = day_digits[1] == 0 ? BirthdayBlankGlyph : day_digits[1];
        core->glyphs[2].glyph_index = day_digits[0];
#else
        core->glyphs[6].glyph_index = day_digits[1] == 0 ? BirthdayBlankGlyph : day_digits[1];
        core->glyphs[7].glyph_index = day_digits[0];
#endif
    }
}


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

void InitializeBirthdayInputGraphics(NewGameBirthdayInputCore * core)
{
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[2][0], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[2][1], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[3][0], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[3][1], 0);
    FillHardwareDma3(0, reinterpret_cast<void *>(BG_SCREEN_ADDR(15) + BG_SCREEN_SIZE - TILE_SIZE_4BPP), TILE_SIZE_4BPP);
    FillHardwareDma3(0xFFFFFFFF, reinterpret_cast<void *>(BG_SCREEN_ADDR(28)), BG_SCREEN_SIZE);
    FillHardwareDma3(0xFFFFFFFF, reinterpret_cast<void *>(BG_SCREEN_ADDR(29)), BG_SCREEN_SIZE);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetDisplayFlags(
        DISPCNT_OBJ_1D_MAP | DISPCNT_BG3_ON | DISPCNT_OBJ_ON);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(3,
        BGCNT_SCREENBASE(28) | BGCNT_PRIORITY(3));
    CopyHardwareDma3(gUiSharedTiles, reinterpret_cast<void *>(BG_VRAM), gUiSharedTileByteCount);
    FillHardwareDma3(0x00030003, reinterpret_cast<void *>(BG_SCREEN_ADDR(28)), BG_SCREEN_SIZE);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetHorizontalOffset(3, 0);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetVerticalOffset(3, 0);
    DrawUiTextWindowBorder(reinterpret_cast<u16 *>(BG_SCREEN_ADDR(29)), 0, 0, 32, 3, 0, 0);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetHorizontalOffset(2, 0);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetVerticalOffset(2, 0);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetHorizontalOffset(1, 0);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetVerticalOffset(1, 0);
    CopyHardwareDma3(gUiSharedPalette, reinterpret_cast<void *>(BG_PLTT), PLTT_SIZE_4BPP);
    u16 volatile * palette = reinterpret_cast<u16 volatile *>(BG_PLTT + 2 * PLTT_SIZE_4BPP);
    *palette++ = RGB(0, 31, 0);
    *palette++ = RGB(0, 0, 0);
    *palette++ = RGB(24, 16, 16);
    reinterpret_cast<u16 *>(OBJ_PLTT + SpritePaletteBank(core->glyph_palette) * PLTT_SIZE_4BPP)[0] = RGB(0, 31, 0);
    reinterpret_cast<u16 *>(OBJ_PLTT + SpritePaletteBank(core->glyph_palette) * PLTT_SIZE_4BPP)[1] = RGB(0, 0, 0);
    reinterpret_cast<u16 *>(OBJ_PLTT + SpritePaletteBank(core->glyph_palette) * PLTT_SIZE_4BPP)[2] = RGB(24, 16, 16);

    UiSpriteGlyphBuffer glyph;
    for (i32 index = 0; index < static_cast<i32>(ARRAY_COUNT(gNewGameBirthdayInputGlyphs)); ++index)
    {
        u32 character = gNewGameBirthdayInputGlyphs[index];
        glyph.DrawCharacterExt(0, 0, character, 0, 1);
        u32 tile = SpriteTileIndex(core->glyph_tiles) +
            index * UiSpriteGlyphBuffer::TileCount;
        CopyHardwareDma3(glyph.TileData(), reinterpret_cast<void *>(OBJ_VRAM0 +
            tile * TILE_SIZE_4BPP), sizeof(glyph.tiles));
    }
}


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
    title[1] = static_cast<i8>(core->day / 10) == 0 ? BirthdayBlankGlyph : static_cast<i8>(core->day / 10);
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
    title[6] = static_cast<i8>(core->day / 10) == 0 ? BirthdayBlankGlyph : static_cast<i8>(core->day / 10);
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
    // Digits, four six-slot seasons and the underscore precede the caption.
    enum { CaptionStart = 10 + 4 * 6 + 1 };
#if defined(REGION_DE)
    int const caption_end = BirthdayBlankGlyph;
#else
    int const caption_end = ARRAY_COUNT(gNewGameBirthdayInputGlyphs);
#endif
    for (int i = 0; i < caption_end - CaptionStart; ++i)
        AppendBirthdayInputGlyph(core, i * 8 + 8, 8, i + CaptionStart, 3);
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
        attributes.tile_index = SpriteTileIndex(core->glyph_tiles)
            + core->glyphs[index].glyph_index * UiSpriteGlyphBuffer::TileCount;
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
