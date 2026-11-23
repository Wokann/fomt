#include "horse_race_medal_exchange.hh"
#include "game_state_types.hh"
#include "hardware_blend.hh"
#include "hardware_blend_owner.hh"
#include "hardware_display_state.hh"
#include "hardware_dma_queue.hh"
#include "hardware_input.hh"
#include "hardware_sprite_buffer.hh"
#include "obj_palette_collection.hh"
#include "new_game_name_input.hh"
#include "new_game_ui.hh"
#include "ui_text_window_border.hh"
#include "font_draw.hh"
#include "gbaio.h"
#include <new>
#include <string.h>

enum { HORSE_RACE_PRIZE_ROW_HEIGHT = 16 };

static inline u32 PrizeTileIndex(ObjTileCollectionEntry & entry)
{
    return GetObjTileIndex(&entry, entry.handle);
}

static inline u32 PrizePaletteBank(ObjPaletteCollectionEntry & entry)
{
    return entry.GetIndex();
}

static inline void QueueHorseRacePrizeBlend(HorseRaceMedalExchangeCore * core,
    HardwareBlendOwner const & blend)
{
    HardwareLinkedList * list = GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    list->Append(blend.object);
}

static inline IndexedResourceGroupResult PrizeSpriteGroup(IndexedResourceHandle const & handle)
{
    return handle.resource->GetGroupData(handle.resolved_resource[handle.current_entry_index].group_index);
}

HorseRaceMedalExchangeCore::HorseRaceMedalExchangeCore(GameStateSaveImage * image)
    : HardwareContext(HardwareInputRepeatParameters(30, 1)), save(image),
      unk_00C(0),
      ui_state(new UiStateOwner(0, 31, 0, unk_00C,
          ObjTileCollection(), ObjPaletteCollection())),
      music_1(1), music_0(0), music_2(2), arrow_archive(gUnk_08527094),
      cursor_archive(gUiHandCursorArchive),
      up_arrow(&arrow_archive, 0), down_arrow(&arrow_archive, 1),
      cursor(&cursor_archive, 0), glyph_tiles(7), glyph_palette(),
      arrow_tiles(4), arrow_palette(), cursor_tiles(2), cursor_palette()
{
    HorseRacePrizeTextVariables & variables = text_variables;
    variables.prize_index = HORSE_RACE_PRIZE_JEWEL_OF_TRUTH;
    medals = save->horse_race.medals;
    if (medals > 99999)
        medals = 99999;
    scroll_y = 0;
}

SceneTransitionOwner HorseRaceMedalExchangeCore::Run()
{
    EnableHardwareForcedBlank(this);
    HardwareDisplayState * display = GetHardwareDisplayState(reinterpret_cast<void * const *>(this));
    HardwareDisplayRegisterValue display_value(BLDCNT_TGT1_ALL);
    display->SetBlendControl(display_value);
    HardwareBlendOwner blend(new HardwareBlendObject(
        GetHardwareDisplayState(reinterpret_cast<void * const *>(this))));
    ui_state.value->ShowPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
    for (i32 index = 0; index < static_cast<i32>(ARRAY_COUNT(menu_prize_ids)); ++index)
        menu_prize_ids[index] = index;
    if (save->horse_race.jewel_of_truth_redeemed)
        menu_prize_ids[HORSE_RACE_PRIZE_JEWEL_OF_TRUTH] = HORSE_RACE_PRIZE_DRESS;
    if (save->horse_race.power_berry_redeemed)
        menu_prize_ids[HORSE_RACE_PRIZE_POWER_BERRY] = HORSE_RACE_PRIZE_PERFUME;
    InitializeHorseRacePrizeGraphics(this);
    InitializeHorseRacePrizeCatalogGraphics(this);
    selection = 0;
    first_visible_row = 0;
    selected_prize = HORSE_RACE_PRIZE_JEWEL_OF_TRUTH;
    dialogue_state = 2;
    phase = 0;
    {
        HardwareBlendObject & fade = *blend.object;
        i16 step = 0x889;
        fade.blend.Begin(step, 1, 1);
    }
    QueueHorseRacePrizeBlend(this, blend);
    bool finished = false;
    do
    {
        UpdateHardwareFrame(this);
        UpdateHardwareInput(reinterpret_cast<void * const *>(this));
        switch (phase)
        {
        case 0:
            if (!blend.IsQueued())
                ++phase;
            break;
        case 1:
            // Sequence the field update before the common assignment in C++98.
            if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)) & DPAD_UP))
            {
                music_2.Start(AUDIO_SFX_MENU_CURSOR);
                selection = selection > 0 ? (--selection, selection) : 0;
                if (selection < first_visible_row)
                {
                    --first_visible_row;
                    phase = 5;
                }
            }
            else if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)) & DPAD_DOWN))
            {
                music_2.Start(AUDIO_SFX_MENU_CURSOR);
                selection = selection < HORSE_RACE_PRIZE_MENU_COUNT - 1
                    ? (++selection, selection) : HORSE_RACE_PRIZE_MENU_COUNT - 1;
                if (selection - first_visible_row > HORSE_RACE_PRIZE_VISIBLE_ROWS - 1)
                {
                    ++first_visible_row;
                    phase = 6;
                }
            }
            else if (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & A_BUTTON))
            {
                music_2.Start(AUDIO_SFX_MENU_CONFIRM);
                dialogue_state = 0;
                selected_prize = menu_prize_ids[selection];
                if (gHorseRacePrizeCatalog[selected_prize].medal_cost <= medals)
                {
                    text_variables.prize_index = selected_prize;
                    phase = 8;
                }
                else
                    phase = 7;
            }
            else if (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & B_BUTTON))
            {
                music_2.Start(AUDIO_SFX_MENU_CANCEL);
                dialogue_state = 0;
                phase = 2;
            }
            break;
        case 2:
        case 3:
        case 4:
            if (dialogue_state == 2)
            {
                if (dialogue_choice == 0)
                    phase = 11;
                else
                    phase = 1;
            }
            break;
        case 5:
            scroll_y -= 4;
            if ((scroll_y & (HORSE_RACE_PRIZE_ROW_HEIGHT - 1)) == 0)
                phase = 1;
            break;
        case 6:
            scroll_y += 4;
            if ((scroll_y & (HORSE_RACE_PRIZE_ROW_HEIGHT - 1)) == 0)
                phase = 1;
            break;
        case 7:
            if (dialogue_state == 2)
                phase = 1;
            break;
        case 8:
        case 9:
        case 10:
            if (dialogue_state == 2)
            {
                if (dialogue_choice == 0)
                {
                    switch (selected_prize)
                    {
                    case HORSE_RACE_PRIZE_POWER_BERRY:
                        func_0800EAFC(save->farmer);
                        save->horse_race.power_berry_redeemed = true;
                        func_0800F510(&save->farmer.held_item, 351);
                        break;
                    case HORSE_RACE_PRIZE_TRUFFLE:
                    {
                        Food food(gHorseRacePrizeItemIds[HORSE_RACE_PRIZE_TRUFFLE]);
                        func_0800F3B0(&save->farmer.held_item, food);
                    } break;
                    case HORSE_RACE_PRIZE_JEWEL_OF_TRUTH:
                        save->horse_race.jewel_of_truth_redeemed = true;
                        ++save->event_state.jewels_of_truth_found_count;
                        save->event_state.jewel_of_truth_from_festival_horse_race_prize_exchange_collected = true;
                        // The truth-jewel path also puts the prize in hand.
                    default:
                    {
                        Article article(gHorseRacePrizeItemIds[selected_prize]);
                        func_0800F3E8(&save->farmer.held_item, article);
                    } break;
                    }
                    medals -= gHorseRacePrizeCatalog[selected_prize].medal_cost;
                    save->horse_race.medals = medals;
                    phase = 11;
                }
                else
                    phase = 1;
            }
            break;
        case 11:
            {
                HardwareBlendObject & fade = *blend.object;
                i16 step = 0x889;
                fade.blend.End(step, 1, 1);
            }
            QueueHorseRacePrizeBlend(this, blend);
            ++phase;
            break;
        case 12:
            if (!blend.IsQueued())
                finished = true;
            break;
        }
        UpdateHorseRacePrizeDialogue(this);
        HardwareDisplayState * scroll_display = GetHardwareDisplayState(reinterpret_cast<void * const *>(this));
        display_value = scroll_y;
        scroll_display->SetBackgroundY(1, display_value);
        BuildHorseRacePrizeGlyphs(this);
        RenderHorseRacePrizeSprites(this);
    } while (finished != true);
    return SceneTransitionOwner();
}

void UpdateHorseRacePrizeDialogue(HorseRaceMedalExchangeCore * core)
{
    UiStateOwner const * ui = core->ui_state.value;
    HardwareCoreState * state = static_cast<HardwareCoreState *>(
        GetHardwareCoreState(reinterpret_cast<void * const *>(core)));
    HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
    HardwareDisplayState * display = GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    HardwareLinkedList * links = GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    HardwareInterruptList * interrupts = GetHardwareInterruptList(reinterpret_cast<void * const *>(core));
    HardwareMusicPlayerSlot * music = &core->music_1;
    switch (ui->Update(&state->input, sprites, display, links, interrupts, music))
    {
    case 0:
        if (core->dialogue_state == 0)
        {
            func_08050D5C(core->ui_state.value);
            core->dialogue_state = 3;
        }
        else
            core->dialogue_state = 2;
        break;
    case 3:
        if (core->dialogue_state == 5)
        {
            func_08050D74(reinterpret_cast<void * const *>(core->ui_state.value));
            core->dialogue_state = 1;
        }
        else if (core->dialogue_state == 4)
        {
            u32 choice = core->ui_state.value->GetChoiceResult();
            core->dialogue_state = 3;
            switch (core->phase)
            {
            case 2:
                if (choice == 1)
                {
                    core->dialogue_choice = 0;
                    core->phase = 3;
                }
                else if (choice == 2)
                {
                    core->dialogue_choice = 1;
                    core->phase = 4;
                }
                break;
            case 8:
                if (choice == 1)
                {
                    core->dialogue_choice = 0;
                    core->dialogue_state = 5;
                    core->phase = 9;
                }
                else if (choice == 2)
                {
                    core->dialogue_choice = 1;
                    core->phase = 10;
                }
                break;
            }
        }
        else if (core->dialogue_state == 3)
        {
            core->dialogue_state = 5;
            switch (core->phase)
            {
            case 2:
                ShowUiTwoChoicePrompt(core->ui_state.value, gText_HorseRace_PrizeExchangePrompt,
                    gText_HorseRace_PrizeExchangeYes, gText_HorseRace_PrizeExchangeNo,
                    &core->text_variables);
                core->dialogue_state = 4;
                break;
            case 3:
                func_08050DA0(core->ui_state.value, gText_HorseRace_PrizeExchangeComeAgain,
                    &core->text_variables);
                break;
            case 4:
                func_08050DA0(core->ui_state.value, gText_HorseRace_PrizeExchangeTakeYourTime,
                    &core->text_variables);
                break;
            case 8:
                ShowUiTwoChoicePrompt(core->ui_state.value, gText_HorseRace_PrizeSelectionConfirmation,
                    gText_HorseRace_PrizeExchangeYes, gText_HorseRace_PrizeExchangeNo,
                    &core->text_variables);
                core->dialogue_state = 4;
                break;
            case 10:
                func_08050DA0(core->ui_state.value, gText_HorseRace_PrizeExchangeLeaveConfirmation,
                    &core->text_variables);
                break;
            case 7:
                func_08050DA0(core->ui_state.value, gText_HorseRace_PrizeExchangeInsufficientMedals,
                    &core->text_variables);
                break;
            }
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

#include FOMT_TEXT_INCLUDE(horse_race_medal_exchange_1.cc)

u16 const gHorseRacePrizeItemIds[HORSE_RACE_PRIZE_COUNT] = {
    /* HORSE_RACE_PRIZE_JEWEL_OF_TRUTH */ ITEM_ARTICLE_JEWEL_OF_TRUTH,
    /* HORSE_RACE_PRIZE_POWER_BERRY */    ITEM_ARTICLE_FLOWER_MOON_DROP,
    /* HORSE_RACE_PRIZE_FACIAL_PACK */    ITEM_ARTICLE_FACIAL_PACK,
    /* HORSE_RACE_PRIZE_SKIN_LOTION */    ITEM_ARTICLE_SKIN_LOTION,
    /* HORSE_RACE_PRIZE_SUNBLOCK */       ITEM_ARTICLE_SUNBLOCK,
    /* HORSE_RACE_PRIZE_NECKLACE */       ITEM_ARTICLE_NECKLACE,
    /* HORSE_RACE_PRIZE_BROOCH */         ITEM_ARTICLE_BROOCH,
    /* HORSE_RACE_PRIZE_DIAMOND */        ITEM_ARTICLE_DIAMOND,
    /* HORSE_RACE_PRIZE_TRUFFLE */        ITEM_FOOD_TRUFFLE,
    /* HORSE_RACE_PRIZE_ADAMANTITE */     ITEM_ARTICLE_ADAMANTITE,
    /* HORSE_RACE_PRIZE_DRESS */          ITEM_ARTICLE_DRESS,
    /* HORSE_RACE_PRIZE_PERFUME */        ITEM_ARTICLE_PERFUME,
};

#include FOMT_TEXT_INCLUDE(horse_race_medal_exchange_2.cc)

void InitializeHorseRacePrizeGraphics(HorseRaceMedalExchangeCore * core)
{
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[1][0], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[1][1], core->scroll_y);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[2][0], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[2][1], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[3][0], 0);
    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->background_scroll[3][1], 0);
    FillHardwareDma3(0, reinterpret_cast<void *>(BG_VRAM + 0x8000 - TILE_SIZE_4BPP), TILE_SIZE_4BPP);
    FillHardwareDma3(0xFFFFFFFF, reinterpret_cast<void *>(BG_SCREEN_ADDR(28)), BG_SCREEN_SIZE);
    FillHardwareDma3(0xFFFFFFFF, reinterpret_cast<void *>(BG_SCREEN_ADDR(29)), BG_SCREEN_SIZE);
    FillHardwareDma3(0xFFFFFFFF, reinterpret_cast<void *>(BG_SCREEN_ADDR(30)), BG_SCREEN_SIZE);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetDisplayFlags(
        DISPCNT_OBJ_1D_MAP | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(3,
        BGCNT_SCREENBASE(28) | BGCNT_PRIORITY(3) | BGCNT_SIZE(1) | BGCNT_MOSAIC);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(2,
        BGCNT_SCREENBASE(29) | BGCNT_PRIORITY(1) | BGCNT_MOSAIC);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(1,
        BGCNT_SCREENBASE(30) | BGCNT_PRIORITY(2) | BGCNT_SIZE(1) | BGCNT_MOSAIC);
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
    reinterpret_cast<u16 *>(OBJ_PLTT + PrizePaletteBank(core->glyph_palette) * PLTT_SIZE_4BPP)[0] = RGB(0, 31, 0);
    reinterpret_cast<u16 *>(OBJ_PLTT + PrizePaletteBank(core->glyph_palette) * PLTT_SIZE_4BPP)[1] = RGB(0, 0, 0);
    reinterpret_cast<u16 *>(OBJ_PLTT + PrizePaletteBank(core->glyph_palette) * PLTT_SIZE_4BPP)[2] = RGB(24, 16, 16);
    UiSpriteGlyphBuffer glyph;
    for (i32 index = 0; index < static_cast<i32>(ARRAY_COUNT(gHorseRacePrizeExchangeCharacterCodes)); ++index)
    {
        u32 character = gHorseRacePrizeExchangeCharacterCodes[index];
        glyph.DrawCharacterExt(0, 0, character, 0, 1);
        u32 tile = PrizeTileIndex(core->glyph_tiles) + index * UiSpriteGlyphBuffer::TileCount;
        CopyHardwareDma3(glyph.TileData(), reinterpret_cast<void *>(OBJ_VRAM0 + tile * TILE_SIZE_4BPP), sizeof(glyph.tiles));
    }
}

void InitializeHorseRacePrizeCatalogGraphics(HorseRaceMedalExchangeCore * core)
{
    IndexedResourceGroupResult group(nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0);
    group = PrizeSpriteGroup(core->up_arrow.resource);
    CopyHardwareDma3(group.palettes.GetData(),
        reinterpret_cast<void *>(OBJ_PLTT + PrizePaletteBank(core->arrow_palette) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount());
    group = core->cursor_archive.GetGroupData(0);
    CopyHardwareDma3(group.palettes.GetData(),
        reinterpret_cast<void *>(OBJ_PLTT + PrizePaletteBank(core->cursor_palette) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount());
    CopyHardwareDma3(group.tiles.GetData(),
        reinterpret_cast<void *>(OBJ_VRAM0 + PrizeTileIndex(core->cursor_tiles) * TILE_SIZE_4BPP), group.tiles.GetByteCount());
    NewGameTextTileBuffer<14> name;
    for (i32 index = 0; index < static_cast<i32>(ARRAY_COUNT(core->menu_prize_ids)); ++index)
    {
        name.Clear();
        name.DrawStringExt(0, 0,
            gHorseRacePrizeCatalog[core->menu_prize_ids[index]].name, 0, 1);
        CopyHardwareDma3(name.tiles,
            reinterpret_cast<void *>(BG_VRAM + 0x2800 + index * sizeof(name.tiles)), sizeof(name.tiles));
    }
    FillHardwareDma3(0xFFFFFFFF, core->name_tilemap, sizeof(core->name_tilemap));
    u16 first_tile = 0x2140;
    for (i32 row = 0; row < static_cast<i32>(ARRAY_COUNT(core->menu_prize_ids)); ++row)
    {
        for (i32 column = 0; column < 14; ++column)
        {
            core->name_tilemap[row * 2 + 4][column + 2] = first_tile + column;
            core->name_tilemap[row * 2 + 5][column + 2] = first_tile + 14 + column;
        }
        first_tile += 28;
    }
    CopyHardwareDma3(core->name_tilemap, reinterpret_cast<void *>(BG_SCREEN_ADDR(30)), sizeof(core->name_tilemap));
}

void BuildHorseRacePrizeGlyphs(HorseRaceMedalExchangeCore * core)
{
    core->glyph_count = 0;
    for (i32 row = 0; row < static_cast<i32>(ARRAY_COUNT(core->menu_prize_ids)); ++row)
    {
        i32 y = row * HORSE_RACE_PRIZE_ROW_HEIGHT;
        i32 scroll_offset = core->scroll_y;
        scroll_offset -= 32;
        y -= scroll_offset;
        AppendHorseRacePrizeNumber(core, 144, y, 3,
            gHorseRacePrizeCatalog[core->menu_prize_ids[row]].medal_cost, 4, 10);
    }
    for (i32 index = 0; index < static_cast<i32>(ARRAY_COUNT(gHorseRacePrizeExchangeCharacterCodes)) - 13; ++index)
        AppendHorseRacePrizeGlyph(core, 8 + index * (UiSpriteGlyphBuffer::TileWidth * 8), 4, index + 13, 1);
    AppendHorseRacePrizeNumber(core, 136, 4, 1, core->medals, 5, 10);
}

void AppendHorseRacePrizeNumber(HorseRaceMedalExchangeCore * core, i32 x, i32 y,
    i32 priority, i32 value, i32 digits, i32 suffix)
{
    i32 divisor = digits;
    i32 digit;
    if (divisor > 1)
    {
        --divisor;
        digit = 10;
        while (divisor > 1)
        {
            digit *= 10;
            --divisor;
        }
        divisor = digit;
    }
    else
        divisor = 1;
    bool started = false;
    while (divisor > 0)
    {
        if (divisor == 1)
            started = true;
        digit = value / divisor;
        if (digit != 0 || started)
        {
            AppendHorseRacePrizeGlyph(core, x, y, digit, priority);
            started = true;
        }
        x += UiSpriteGlyphBuffer::TileWidth * 8;
        value -= digit * divisor;
        divisor /= 10;
    }
    if (suffix != 0)
        AppendHorseRacePrizeGlyph(core, x, y, suffix, priority);
}

void AppendHorseRacePrizeGlyph(HorseRaceMedalExchangeCore * core, i32 x, i32 y,
    i32 glyph, i32 priority)
{
    core->glyphs[core->glyph_count].x = x;
    core->glyphs[core->glyph_count].y = y;
    core->glyphs[core->glyph_count].glyph_index = glyph;
    core->glyphs[core->glyph_count].priority = priority;
    ++core->glyph_count;
}

static inline void QueueHorseRacePrizeArrow(HorseRaceMedalExchangeCore * core,
    ObjTileCollectionEntry & arrow_tiles, IndexedResourceTileRange const & tiles, u32 tile_offset)
{
    QueueObjTileTransfer(GetHardwareDmaQueue(reinterpret_cast<void * const *>(core)),
        tiles.GetData(), PrizeTileIndex(arrow_tiles), tile_offset, tiles.GetByteCount());
}

void RenderHorseRacePrizeSprites(HorseRaceMedalExchangeCore * core)
{
    IndexedResourceSpriteParameters parameters;
    IndexedResourceGroupResult group(nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0);
    if (core->phase > 0)
    {
        UpdateIndexedResourceHandle(&core->cursor.resource);
        group = PrizeSpriteGroup(core->cursor.resource);
        parameters = core->cursor.parameters;
        parameters.x = 12;
        parameters.y = core->selection * HORSE_RACE_PRIZE_ROW_HEIGHT -
            static_cast<i16>(core->first_visible_row * HORSE_RACE_PRIZE_ROW_HEIGHT - 40);
        parameters.tile_offset = PrizeTileIndex(core->cursor_tiles);
        parameters.palette_offset = PrizePaletteBank(core->cursor_palette);
        parameters.priority = 2;
        parameters.mosaic = 1;
        HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
        DrawIndexedResourceSprites(sprites, group.sprites.Data(), group.sprites.Count(), &parameters);
    }
    if (core->scroll_y != 0)
    {
        UpdateIndexedResourceHandle(&core->up_arrow.resource);
        group = PrizeSpriteGroup(core->up_arrow.resource);
        parameters = core->up_arrow.parameters;
        parameters.x = 232;
        parameters.y = 26;
        parameters.tile_offset = PrizeTileIndex(core->arrow_tiles) + 4;
        parameters.palette_offset = PrizePaletteBank(core->arrow_palette);
        parameters.priority = 2;
        parameters.mosaic = 1;
        QueueHorseRacePrizeArrow(core, core->arrow_tiles, group.tiles, 4);
        HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
        DrawIndexedResourceSprites(sprites, group.sprites.Data(), group.sprites.Count(), &parameters);
    }
    if (core->scroll_y <= (HORSE_RACE_PRIZE_MENU_COUNT - HORSE_RACE_PRIZE_VISIBLE_ROWS) *
            HORSE_RACE_PRIZE_ROW_HEIGHT - 1)
    {
        UpdateIndexedResourceHandle(&core->down_arrow.resource);
        group = PrizeSpriteGroup(core->down_arrow.resource);
        parameters = core->down_arrow.parameters;
        parameters.x = 232;
        parameters.y = 152;
        parameters.tile_offset = PrizeTileIndex(core->arrow_tiles) + 8;
        parameters.palette_offset = PrizePaletteBank(core->arrow_palette);
        parameters.priority = 2;
        parameters.mosaic = 1;
        QueueHorseRacePrizeArrow(core, core->arrow_tiles, group.tiles, 8);
        HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
        DrawIndexedResourceSprites(sprites, group.sprites.Data(), group.sprites.Count(), &parameters);
    }
    HardwareSpriteOamRecord attributes;
    attributes.affine_mode = 0;
    attributes.object_mode = 0;
    attributes.mosaic = 1;
    attributes.color_mode = 0;
#if defined(REGION_JP)
    attributes.shape = 0;
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    attributes.shape = 2;
#endif
    attributes.affine_index_low = 0;
    attributes.horizontal_flip = 0;
    attributes.vertical_flip = 0;
#if defined(REGION_JP)
    attributes.size = 1;
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    attributes.size = 0;
#endif
    attributes.palette_bank = static_cast<u16>(PrizePaletteBank(core->glyph_palette));
    attributes.affine_coefficient = 0;
    attributes.mosaic = 1;
    while (--core->glyph_count >= 0)
    {
        attributes.priority = core->glyphs[core->glyph_count].priority;
        attributes.x = core->glyphs[core->glyph_count].x;
        attributes.y = core->glyphs[core->glyph_count].y;
        attributes.tile_index = PrizeTileIndex(core->glyph_tiles) +
            core->glyphs[core->glyph_count].glyph_index * UiSpriteGlyphBuffer::TileCount;
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
}

HorseRaceMedalExchangeScene::HorseRaceMedalExchangeScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(new HorseRaceMedalExchangeCore(image)), continuation(next)
{
}

inline HorseRaceMedalExchangeCoreOwner::~HorseRaceMedalExchangeCoreOwner() { delete value; }

HorseRaceMedalExchangeScene::~HorseRaceMedalExchangeScene()
{
}

SceneTransitionOwner HorseRaceMedalExchangeScene::Run()
{
    core->Run();
    return continuation;
}
