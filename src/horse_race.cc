#include "horse_race.hh"

extern AnimalFestivalRandomRangePair const gAnimalFestivalRandomRangePairs[] = {
    { 0, 250, 0, 250 },
    { 0, 90, 0, 250 },
    { 150, 250, 0, 250 },
    { 100, 149, 0, 250 },
    { 0, 70, 0, 250 },
    { 100, 250, 0, 250 },
    { 0, 250, 0, 250 },
};

#include "game_state_types.hh"
#include "horse.hh"
#include "hardware_blend.hh"
#include "hardware_blend_owner.hh"
#include "hardware_input.hh"
#include <stdlib.h>
#include "obj_palette_collection.hh"
#include "new_game_name_input.hh"

#include "hardware_display_state.hh"
#include "hardware_dma_queue.hh"
#include "hardware_sprite_buffer.hh"
#include "new_game_ui.hh"
#include "ui_text_window_border.hh"
#include "compression.hh"
#include "gbaio.h"

// Text and tables follow their original read-only order.
#include FOMT_TEXT_INCLUDE(horse_race_1.cc)

extern u8 const gAnimalFestivalLivestockContestantValues[][4] = {
    { 70, 80, 40, 90 },
    { 30, 20, 40, 40 },
    { 20, 20, 20, 20 },
    { 100, 100, 100, 100 },
    { 30, 40, 40, 40 },
    { 0, 100, 0, 0 },
    { 70, 90, 90, 70 },
    { 20, 30, 30, 50 },
    { 10, 50, 70, 20 },
    { 40, 70, 50, 50 },
    { 30, 60, 40, 70 },
    { 40, 50, 30, 30 },
    { 100, 0, 0, 0 },
    { 60, 70, 60, 70 },
    { 10, 40, 20, 20 },
    { 0, 60, 60, 0 },
    { 20, 30, 50, 30 },
    { 40, 0, 30, 40 },
    { 0, 50, 0, 50 },
    { 0, 0, 0, 0 },
    { 50, 50, 50, 50 },
    { 60, 50, 40, 50 },
    { 10, 20, 30, 40 },
    { 40, 20, 40, 30 },
    { 0, 30, 10, 20 },
    { 0, 0, 100, 0 },
    { 30, 20, 0, 90 },
    { 0, 0, 0, 100 },
    { 50, 20, 60, 10 },
    { 10, 30, 20, 50 },
    { 20, 40, 20, 40 },
    { 30, 30, 40, 20 },
    { 90, 0, 0, 60 },
    { 70, 20, 40, 30 },
    { 30, 50, 40, 20 },
    { 50, 0, 50, 0 },
    { 20, 70, 40, 30 },
    { 20, 10, 40, 50 },
    { 30, 40, 40, 20 },
    { 60, 10, 40, 80 },
};

#include FOMT_TEXT_INCLUDE(horse_race_2.cc)

char const * const gHorseRaceTicketControls[] = {
    gText_HorseRace_TicketControls_DPadUpDown,
    gText_HorseRace_TicketControls_SelectHorse,
    gText_HorseRace_TicketControls_DPadLeftRight,
    gText_HorseRace_TicketControls_ChangeQuantity,
    gText_HorseRace_TicketControls_LRButtons,
    gText_HorseRace_TicketControls_ChangeQuantityByTen,
    gText_HorseRace_TicketControls_ChangeQuantityByTenContinuation,
    gText_HorseRace_TicketControls_MoveCursorToConfirm,
    gText_HorseRace_TicketControls_Buy,
    gText_HorseRace_TicketControls_Cancel,
    nullptr,
};

static inline void QueueHorseRaceBlend(HorseRaceCore * core, HardwareBlendOwner const & blend)
{
    GetHardwareCommandList(reinterpret_cast<void * const *>(core))->Append(blend.object);
}

static inline IndexedResourceGroupResult HorseRaceSpriteGroup(IndexedResourceHandle const & handle)
{
    return handle.resource->GetGroupData(handle.resolved_resource[handle.current_entry_index].group_index);
}

static inline IndexedResourceGroupResult HorseRaceResolvedGroup(IndexedResourceProvider const * provider,
    u32 index, u32 frame)
{
    return provider->GetGroupData(provider->Resolve(index)[frame].group_index);
}

static inline u32 HorseRacePaletteBank(ObjPaletteCollectionEntry & entry)
{
    return entry.GetIndex();
}

inline HorseRaceCoreOwner::~HorseRaceCoreOwner() { delete value; }

extern "C" void PrepareHorseRaceEntries(GameStateUnknown2C1C * state, bool compete, u32 difficulty)
{
    state->unk_2C_00 = 0;
    state->unk_2C_21 = compete;
    for (i32 index = 0; index < 12; ++index)
        state->contestant_name_ids[index] = 0xFF;
    for (i32 index = 0; index < 12; ++index)
    {
        bool duplicate;
        do
        {
            state->contestant_name_ids[index] = (rand() >> 8) % ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_COUNT;
            duplicate = false;
            for (i32 other = 0; other < 12; ++other)
                if (index != other && state->contestant_name_ids[other] == state->contestant_name_ids[index])
                    duplicate = true;
        } while (duplicate);
    }
    GenerateHorseRaceRoundEntries(state, difficulty);
}

extern "C" void AdvanceHorseRaceRound(GameStateUnknown2C1C * state, u32 difficulty)
{
    ++state->unk_2C_00;
    GenerateHorseRaceRoundEntries(state, difficulty);
}

extern "C" bool AreHorseRacesComplete(GameStateUnknown2C1C * state)
{
    return state->unk_2C_00 == 3;
}

extern "C" void GenerateHorseRaceRoundEntries(GameStateUnknown2C1C * state, u32 difficulty)
{
    bool player_round = state->unk_2C_00 == 2 ? state->unk_2C_21 : false;
    HorseRaceSavedEntry * entry = state->entries;
    for (i32 index = 0; index < 4; ++index, ++entry)
    {
        i32 range;
        if (!player_round)
            range = index;
        else
        {
            switch (difficulty)
            {
            case 1:
            case 3: range = index; break;
            case 2: range = 4; break;
            case 4: range = 5; break;
            default: range = 6; break;
            }
        }
        i32 minimum = gAnimalFestivalRandomRangePairs[range].first_minimum;
        i32 maximum = gAnimalFestivalRandomRangePairs[range].first_maximum;
        entry->adequacy = rand() % (maximum - minimum) + minimum;
        minimum = gAnimalFestivalRandomRangePairs[range].second_minimum;
        maximum = gAnimalFestivalRandomRangePairs[range].second_maximum;
        entry->affection = rand() % (maximum - minimum) + minimum;
        entry->contestant_name_id = state->contestant_name_ids[state->unk_2C_00 * 4 + index];
        i32 remaining = 250 - entry->adequacy;
        i32 odds = remaining * remaining / 1000;
        i32 random_odds = rand();
        random_odds &= 3;
        ++random_odds;
        odds += random_odds;
        entry->odds = odds;
    }
}

HorseRaceCore::HorseRaceCore(GameStateSaveImage * image, bool player_competes)
    : HardwareContext(HardwareInputRepeatParameters(30, 1)), save(image), unk_00C(0),
      ui_state(::operator new(sizeof(UiStateOwner)), 0, unk_00C),
      music_1(1),
      music_0(0),
      music_2(2),
      unk_archive_020(gUnk_0872EE78), unk_archive_050(gUnk_0873CCB4),
      unk_archive_080(gUnk_0873D234), unk_archive_0B0(gUnk_0873CF90),
      unk_archive_0E0(gUnk_0873DE44), unk_archive_110(gUnk_0873ED1C),
      unk_archive_140(gUnk_087401A4), cursor_archive(gUiHandCursorArchive),
      actor_archive(gActorIndexedResourceArchive),
      lane_marker(&unk_archive_020, 0),
      runner_sprite_1(&actor_archive, 0x762),
      runner_sprite_2(&actor_archive, 0x73E),
      runner_sprite_3(&actor_archive, 0x74A),
      runner_sprite_4(&actor_archive, 0x756),
      player_runner_sprite(&actor_archive, 0x76E),
      stamina_indicator(&unk_archive_080, 0),
      ticket_entry_marker(&unk_archive_0B0, 0),
      runner_effect_1(&unk_archive_110, 0),
      runner_effect_2(&unk_archive_110, 0),
      runner_effect_3(&unk_archive_110, 0),
      runner_effect_4(&unk_archive_110, 0),
      boost_overlay_1(&unk_archive_140, 0),
      boost_overlay_2(&unk_archive_140, 0),
      boost_overlay_3(&unk_archive_140, 0),
      boost_overlay_4(&unk_archive_140, 0),
      ticket_cursor(&cursor_archive, 0),
      shared_runner_sprite(&actor_archive, 0x91C),
      tiles_5C0(4), palette_5C8(false), tiles_5D0(4), palette_5D8(false),
      tiles_5E0(5), palette_5E8(false), tiles_5F0(6), palette_5F8(false),
      tiles_600(4), palette_608(), tiles_610(7), palette_618(), palette_620(),
      tiles_628(4), tiles_630(4), palette_638(false), tiles_640(2),
      palette_648(), tiles_650(3)
{
    HorseRaceTextVariables & variables = text_variables;
    variables.contestant_name_ids[0] = 0;
    variables.contestant_name_ids[1] = 0;
    variables.contestant_name_ids[2] = 0;
    variables.contestant_name_ids[3] = 0;
    variables.round_number = 0;
    variables.player_horse_name = nullptr;
    if (AreHorseRacesComplete(&save->unk_2C1C))
        PrepareHorseRaceEntries(&save->unk_2C1C, false, 1);
    compete = player_competes;
    u32 const balance = save->money_account.balance;
    money = balance;
    money_after_tickets = balance;
    medals = save->unk_2C1C.unk_2C_02;
    if (medals > 99999)
        medals = 99999;
    player_stamina_level = 0;
    payout_remaining = 0;
    total_tickets = 0;
    round = save->unk_2C1C.unk_2C_00;
    if (round == 2)
        player_competes_this_round = save->unk_2C1C.unk_2C_21;
    else
        player_competes_this_round = false;
    pause_flags = 0;
    showing_controls = false;
    phase = 0;
    dialogue_state = 2;
    player_horse = save->farm.GetHorse();
}

SceneTransitionOwner HorseRaceCore::Run()
{
    EnableHardwareForcedBlank(this);
    WriteHardwareDisplayRegister(*GetHardwareDisplayState(reinterpret_cast<void * const *>(this)),
        &HardwareDisplayState::blend_control, BLDCNT_TGT1_ALL);
    HardwareBlendOwner blend(new HardwareBlendObject(
        GetHardwareDisplayState(reinterpret_cast<void * const *>(this))));
    ui_state.value->ShowPortrait(117);
    for (i32 index = 0; index < 4; ++index)
    {
        runners[index].contestant_name_id = save->unk_2C1C.entries[index].contestant_name_id;
        runners[index].adequacy = save->unk_2C1C.entries[index].adequacy;
        runners[index].affection = save->unk_2C1C.entries[index].affection;
        runners[index].odds = save->unk_2C1C.entries[index].odds;
        runners[index].ticket_count = 0;
    }
    InitializeHorseRaceRunners(this);
    save->unk_2C1C.unk_2C_22 = false;
    save->unk_2C1C.unk_2C_23 = false;
    if (compete)
        phase = 13;
    else
    {
        InitializeHorseRaceTicketGraphics(this);
        RenderHorseRaceTicketPurchaseScreen(this, false);
        LoadHorseRaceTicketControls(this);
        {
            HardwareBlendObject & fade = *blend.object;
            i16 step = 0x889;
            fade.blend.Begin(step, 1, 1);
        }
        QueueHorseRaceBlend(this, blend);
    }
    while (phase != 13)
    {
        UpdateHardwareFrame(this);
        UpdateHardwareInput(reinterpret_cast<void * const *>(this));
        switch (phase)
        {
        case 0:
            if (!blend.IsQueued())
            {
                selected_ticket = 0;
                ++phase;
            }
            break;
        case 1:
            if (!showing_controls)
            {
                if (static_cast<u8>(GetHardwareHeldKeys(reinterpret_cast<void * const *>(this)) & SELECT_BUTTON))
                {
                    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->control.dispcnt,
                        DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_BG3_ON);
                    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->background_control[2],
                        BGCNT_PRIORITY(1) | BGCNT_CHARBASE(2) | BGCNT_MOSAIC | BGCNT_SCREENBASE(31));
                    showing_controls = true;
                    break;
                }
            }
            else
            {
                if (!(static_cast<u8>(GetHardwareHeldKeys(reinterpret_cast<void * const *>(this)) & SELECT_BUTTON)))
                {
                    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->control.dispcnt,
                        DISPCNT_OBJ_1D_MAP | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON);
                    WriteHardwareDisplayRegister(GetHardwareDisplayState(reinterpret_cast<void * const *>(this))->background_control[2],
                        BGCNT_PRIORITY(1) | BGCNT_MOSAIC | BGCNT_SCREENBASE(29));
                    showing_controls = false;
                }
                break;
            }
            if (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & DPAD_UP))
            {
                selected_ticket = selected_ticket > 0 ? selected_ticket - 1 : 4;
                music_2.Start(0xCB);
            }
            else if (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & DPAD_DOWN))
            {
                selected_ticket = selected_ticket <= 3 ? selected_ticket + 1 : 0;
                music_2.Start(0xCB);
            }
            if (selected_ticket != 4)
            {
                i32 delta = 0;
                if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)) & DPAD_RIGHT))
                    delta = 1;
                else if (static_cast<u8>(GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)) & DPAD_LEFT))
                    delta = -1;
                else if (HardwareKeySnapshot::ShoulderBits(
                    GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)), R_BUTTON))
                    delta = 10;
                else if (HardwareKeySnapshot::ShoulderBits(
                    GetHardwareRepeatedKeys(reinterpret_cast<void * const *>(this)), L_BUTTON))
                    delta = -10;
                if (delta)
                {
                    AdjustHorseRaceTicketQuantity(this, delta);
                    music_2.Start(0xCB);
                    break;
                }
            }
            if (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & B_BUTTON))
            {
                music_2.Start(0xC6);
                dialogue_state = 0;
                phase = 2;
            }
            else
            {
                bool confirm = static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & START_BUTTON)
                    || (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & A_BUTTON)
                        && selected_ticket == 4);
                if (confirm)
                {
                    music_2.Start(0xC5);
                    total_tickets = 0;
                    for (i32 index = 0; index < 4; ++index)
                        total_tickets += runners[index].ticket_count;
                    if (total_tickets > 0)
                    {
                        dialogue_state = 0;
                        phase = 7;
                    }
                    else
                    {
                        dialogue_state = 0;
                        phase = 2;
                    }
                }
            }
            break;
        case 2:
        case 3:
        case 4:
            UpdateHorseRaceDialogue(this);
            if (dialogue_state == 2)
            {
                if (dialogue_choice == 0)
                    phase = 5;
                else
                {
                    phase = 1;
                    LoadHorseRaceTicketControls(this);
                }
            }
            break;
        case 7:
        case 8:
        case 9:
            UpdateHorseRaceDialogue(this);
            if (dialogue_state == 2)
            {
                if (dialogue_choice == 0)
                    phase = 10;
                else
                {
                    phase = 1;
                    LoadHorseRaceTicketControls(this);
                }
            }
            break;
        case 5:
        case 10:
            {
                HardwareBlendObject & fade = *blend.object;
                i16 step = 0x889;
                fade.blend.End(step, 1, 1);
            }
            QueueHorseRaceBlend(this, blend);
            ++phase;
            break;
        case 11:
            if (!blend.IsQueued())
            {
                SubtractMoneyFromAccount(&save->money_account, total_tickets * 50);
                money -= total_tickets * 50;
                phase = 13;
            }
            break;
        case 6:
            if (!blend.IsQueued())
            {
                save->unk_2C1C.unk_2C_22 = true;
                return SceneTransitionOwner();
            }
            break;
        }
        BuildHorseRaceTicketGlyphs(this, false);
        RenderHorseRaceTicketSprites(this);
    }
    EnableHardwareForcedBlank(this);
    palette_608.Clear();
    palette_618.Clear();
    palette_620.Clear();
    palette_648.Clear();
    palette_5C8.Reset();
    palette_5D8.Reset();
    palette_5E8.Reset();
    palette_5F8.Reset();
    palette_638.Reset();
    InitializeHorseRaceBackground(this);
    UpdateHorseRaceBackground(this);
    LoadHorseRaceSpriteResources(this);
    music_0.Start(33);
    {
        HardwareBlendObject & fade = *blend.object;
        i16 step = 0x889;
        fade.blend.Begin(step, 1, 1);
    }
    QueueHorseRaceBlend(this, blend);
    while (phase != 29)
    {
        UpdateHardwareFrame(this);
        UpdateHardwareInput(reinterpret_cast<void * const *>(this));
        bool toggle_pause = false;
        if ((static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & START_BUTTON)) && (pause_flags & 2))
            toggle_pause = true;
        if (toggle_pause)
        {
            pause_flags ^= 1;
            if (pause_flags & 1)
                music_2.Start(184);
        }
        if (pause_flags & 1)
        {
            RenderHorseRaceSprites(this);
            continue;
        }
        switch (phase)
        {
        case 13:
            if (!blend.IsQueued())
            {
                dialogue_state = 0;
                if (!player_competes_this_round)
                {
                    func_08050E5C(reinterpret_cast<void * const *>(ui_state.value));
                    phase = 22;
                }
                else
                {
                    ui_state.value->ShowPortrait(117);
                    ++phase;
                }
            }
            break;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
            UpdateHorseRaceDialogue(this);
            if (dialogue_state == 2)
            {
                dialogue_state = 0;
                func_08050E5C(reinterpret_cast<void * const *>(ui_state.value));
                ++phase;
            }
            break;
        case 22:
            text_variables.contestant_name_ids[0] = runners[0].contestant_name_id;
            text_variables.contestant_name_ids[1] = runners[1].contestant_name_id;
            text_variables.contestant_name_ids[2] = runners[2].contestant_name_id;
            text_variables.contestant_name_ids[3] = runners[3].contestant_name_id;
            text_variables.player_horse_name = player_horse->GetName();
            UpdateHorseRaceDialogue(this);
            if (dialogue_state == 2)
            {
                ++phase;
                timer = 120;
                pause_flags |= 2;
            }
            break;
        case 23:
            if (--timer <= 0)
            {
                ResolveIndexedResourceHandle(&runner_sprite_1.resource, 0x766);
                ResolveIndexedResourceHandle(&runner_sprite_2.resource, 0x742);
                ResolveIndexedResourceHandle(&runner_sprite_3.resource, 0x74E);
                ResolveIndexedResourceHandle(&runner_sprite_4.resource, 0x75A);
                ResolveIndexedResourceHandle(&player_runner_sprite.resource, 0x772);
                finish_count = 0;
                for (i32 index = 0; index < static_cast<i32>(ARRAY_COUNT(finishing_order)); ++index)
                    finishing_order[index] = index;
                music_2.Start(185);
                ++phase;
            }
            break;
        case 24:
            if (UpdateHorseRaceRunners(this) > 3)
            {
                timer = 120;
                ++phase;
            }
            UpdateHorseRaceBackground(this);
            break;
        case 25:
            if (--timer <= 0)
            {
                if (player_competes_this_round == 1 && finishing_order[0] == 2)
                {
                    save->unk_2C1C.unk_2C_23 = true;
                    player_horse->SetFestivalWinner();
                }
                pause_flags &= ~2;
                dialogue_state = 0;
                ++phase;
            }
            break;
        case 26:
            text_variables.contestant_name_ids[0] = runners[finishing_order[0]].contestant_name_id;
            text_variables.contestant_name_ids[1] = runners[finishing_order[1]].contestant_name_id;
            text_variables.contestant_name_ids[2] = runners[finishing_order[2]].contestant_name_id;
            text_variables.contestant_name_ids[3] = runners[finishing_order[3]].contestant_name_id;
            UpdateHorseRaceDialogue(this);
            if (dialogue_state == 2)
                ++phase;
            break;
        case 27:
            {
                HardwareBlendObject & fade = *blend.object;
                i16 step = 0x889;
                fade.blend.End(step, 1, 1);
            }
            QueueHorseRaceBlend(this, blend);
            ++phase;
            break;
        case 28:
            if (!blend.IsQueued())
                ++phase;
            break;
        }
        RenderHorseRaceSprites(this);
    }
    EnableHardwareForcedBlank(this);
    for (i32 index = 0; index < 4; ++index)
    {
        contestant_tiles[index].palettes[0].Clear();
        contestant_tiles[index].palettes[1].Clear();
    }
    palette_608.Reset();
    palette_618.Reset();
    palette_620.Reset();
    selected_ticket = -1;
    InitializeHorseRaceTicketGraphics(this);
    RenderHorseRaceTicketPurchaseScreen(this, true);
    payout_remaining = runners[finishing_order[0]].ticket_count * runners[finishing_order[0]].odds;
    {
        HardwareBlendObject & fade = *blend.object;
        i16 step = 0x889;
        fade.blend.Begin(step, 1, 1);
    }
    QueueHorseRaceBlend(this, blend);
    while (phase != 36)
    {
        UpdateHardwareFrame(this);
        UpdateHardwareInput(reinterpret_cast<void * const *>(this));
        switch (phase)
        {
        case 29:
            if (!blend.IsQueued())
            {
                func_08050E5C(reinterpret_cast<void * const *>(ui_state.value));
                dialogue_state = 0;
                ++phase;
            }
            break;
        case 30:
            text_variables.round_number = round + 1;
            UpdateHorseRaceDialogue(this);
            if (dialogue_state == 2)
            {
                payout_delay = 8;
                total_tickets = 0;
                timer = 60;
                ++phase;
            }
            break;
        case 31:
            if (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & A_BUTTON))
            {
                payout_delay = 0;
                if (timer == 0)
                {
                    medals += payout_remaining;
                    if (medals > 99999)
                        medals = 99999;
                    payout_remaining = 0;
                    music_2.Start(186);
                }
            }
            if (timer > 0)
                --timer;
            else if (payout_remaining > 0)
            {
                music_2.Start(186);
                --payout_remaining;
                ++medals;
                if (medals > 99999)
                    medals = 99999;
                ++total_tickets;
                if (total_tickets % 5 == 0 && payout_delay > 0)
                    --payout_delay;
                timer = payout_delay;
            }
            else
            {
                save->unk_2C1C.unk_2C_02 = medals;
                timer = 30;
                ++phase;
            }
            break;
        case 32:
            // Preserve the native signed countdown branch, including its > 0 test.
            if (--timer > 0)
            {
                ui_state.value->ShowPortrait(117);
                dialogue_state = 0;
                ++phase;
            }
            break;
        case 33:
            UpdateHorseRaceDialogue(this);
            if (dialogue_state == 2 && (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(this)) & A_BUTTON)))
                ++phase;
            break;
        case 34:
            {
                HardwareBlendObject & fade = *blend.object;
                i16 step = 0x889;
                fade.blend.End(step, 1, 1);
            }
            QueueHorseRaceBlend(this, blend);
            ++phase;
            break;
        case 35:
            if (!blend.IsQueued())
            {
                ++phase;
                AdvanceHorseRaceRound(&save->unk_2C1C, 1);
            }
            break;
        case 36:
            break;
        }
        BuildHorseRaceTicketGlyphs(this, true);
        RenderHorseRaceTicketSprites(this);
    }
    return SceneTransitionOwner();
}

extern "C" i32 AdjustHorseRaceTicketQuantity(HorseRaceCore * core, i32 delta)
{
    core->total_tickets = 0;
    for (i32 index = 0; index < 4; ++index)
        if (index != core->selected_ticket)
            core->total_tickets += core->runners[index].ticket_count;
    i32 maximum = (core->money - core->total_tickets * 50) / 50;
    if (maximum > 99)
        maximum = 99;
    i16 quantity = core->runners[core->selected_ticket].ticket_count;
    if (quantity == maximum && delta > 0)
        quantity = 0;
    else if (quantity == 0 && delta < 0)
        quantity = maximum;
    else
    {
        quantity += delta;
        if (quantity > maximum)
            quantity = maximum;
        if (quantity < 0)
            quantity = 0;
    }
    core->runners[core->selected_ticket].ticket_count = quantity;
    core->total_tickets += quantity;
    core->money_after_tickets = core->money - core->total_tickets * 50;
    return quantity;
}

extern "C" void UpdateHorseRaceDialogue(HorseRaceCore * core)
{
    UiStateOwner * ui = core->ui_state.value;
    HardwareCoreState * state = GetHardwareCoreState(reinterpret_cast<void * const *>(core));
    HardwareSpriteBufferState * sprites = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
    HardwareDisplayState * display = GetHardwareDisplayState(reinterpret_cast<void * const *>(core));
    HardwareLinkedList * commands = GetHardwareCommandList(reinterpret_cast<void * const *>(core));
    HardwareInterruptList * interrupts = GetHardwareInterruptList(reinterpret_cast<void * const *>(core));
    HardwareMusicPlayerSlot * music = &core->music_1;
    switch (ui->Update(&state->input, sprites, display, commands, interrupts, music))
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
    case 1:
    case 2:
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
                if (choice == 1) { core->dialogue_choice = 0; core->phase = 3; }
                else if (choice == 2) { core->dialogue_choice = 1; core->phase = 4; }
                break;
            case 7:
                if (choice == 1) { core->dialogue_choice = 0; core->phase = 8; }
                else if (choice == 2) { core->dialogue_choice = 1; core->phase = 9; }
                break;
            case 14:
                if (choice == 1) core->phase = 15;
                else if (choice == 2) core->phase = 21;
                break;
            case 20:
                if (choice == 1) core->phase = 21;
                else if (choice == 2) core->phase = 15;
                break;
            }
        }
        else if (core->dialogue_state == 3)
        {
            core->dialogue_state = 5;
            switch (core->phase)
            {
            case 2:
                ShowUiTwoChoicePrompt(core->ui_state.value, gText_HorseRace_BuyTicketDeclined,
                    gText_HorseRace_Yes, gText_HorseRace_No, &core->text_variables);
                core->dialogue_state = 4;
                break;
            case 3:
                func_08050DA0(core->ui_state.value, gText_HorseRace_ComeAgain, &core->text_variables);
                break;
            case 4:
                func_08050DA0(core->ui_state.value, gText_HorseRace_TakeYourTime, &core->text_variables);
                break;
            case 7:
                ShowUiTwoChoicePrompt(core->ui_state.value, gText_HorseRace_TicketPurchaseConfirmation,
                    gText_HorseRace_Yes, gText_HorseRace_No, &core->text_variables);
                core->dialogue_state = 4;
                break;
            case 8:
                if (!core->player_competes_this_round)
                    func_08050DA0(core->ui_state.value, gText_HorseRace_TicketPurchaseApproval, &core->text_variables);
                else
#if defined(REGION_JP)
                    func_08050DA0(core->ui_state.value, gText_HorseRace_TicketPurchaseEncouragement, &core->text_variables);
#else
                    func_08050DA0(core->ui_state.value, gText_HorseRace_TicketPurchaseApproval, &core->text_variables);
#endif
                break;
            case 9:
                func_08050DA0(core->ui_state.value, gText_HorseRace_ChangeMind, &core->text_variables);
                break;
            case 14:
                ShowUiTwoChoicePrompt(core->ui_state.value, gText_HorseRace_ExplanationQuestion,
                    gText_HorseRace_Yes, gText_HorseRace_No, &core->text_variables);
                core->dialogue_state = 4;
                break;
            case 15:
                func_08050DA0(core->ui_state.value, gText_HorseRace_ExplanationBasics, &core->text_variables);
                core->phase = 16;
                core->dialogue_state = 3;
                break;
            case 16:
                func_08050DA0(core->ui_state.value, gText_HorseRace_ExplanationGreenStamina, &core->text_variables);
                core->phase = 17;
                core->dialogue_state = 3;
                break;
            case 17:
                func_08050DA0(core->ui_state.value, gText_HorseRace_ExplanationYellowStamina, &core->text_variables);
                core->runners[2].stamina = 120;
                core->phase = 18;
                core->dialogue_state = 3;
                break;
            case 18:
                func_08050DA0(core->ui_state.value, gText_HorseRace_ExplanationRedStamina, &core->text_variables);
                core->runners[2].stamina = 60;
                core->phase = 19;
                core->dialogue_state = 3;
                break;
            case 19:
                func_08050DA0(core->ui_state.value, gText_HorseRace_ExplanationStaminaRecovery, &core->text_variables);
                core->runners[2].stamina = 255;
                core->phase = 20;
                core->dialogue_state = 3;
                break;
            case 20:
                ShowUiTwoChoicePrompt(core->ui_state.value, gText_HorseRace_ExplanationUnderstoodQuestion,
                    gText_HorseRace_ExplanationUnderstood, gText_HorseRace_ExplanationRepeat,
                    &core->text_variables);
                core->dialogue_state = 4;
                break;
            case 21:
                func_08050DA0(core->ui_state.value, gText_HorseRace_StartRace, &core->text_variables);
                break;
            case 22:
                func_08050DA0(core->ui_state.value, gText_HorseRace_RaceStartAnnouncement, &core->text_variables);
                break;
            case 26:
                func_08050DA0(core->ui_state.value, gText_HorseRace_RaceResults, &core->text_variables);
                break;
            case 30:
                func_08050DA0(core->ui_state.value, gText_HorseRace_RacePayouts, &core->text_variables);
                break;
            case 33:
                func_08050DA0(core->ui_state.value, gText_HorseRace_MedalExchangeExplanation, &core->text_variables);
                break;
            }
        }
        break;
    case 4:
    case 5:
    case 6:
        break;
    }
}

extern "C" void InitializeHorseRaceTicketGraphics(HorseRaceCore * core)
{
    IndexedResourceGroupResult group(nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0);
    group = HorseRaceSpriteGroup(core->ticket_entry_marker.resource);
    group = HorseRaceSpriteGroup(core->ticket_entry_marker.resource);
    CopyHardwareDma3(group.palettes.GetData(),
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_608) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount());
    u32 tile_offset = 0;
    for (i32 index = 0; index < 4; ++index)
    {
        ResolveIndexedResourceHandle(&core->ticket_entry_marker.resource, index);
        group = HorseRaceSpriteGroup(core->ticket_entry_marker.resource);
        CopyHardwareDma3(group.tiles.data,
            reinterpret_cast<void *>(OBJ_VRAM0 +
                (core->tiles_600.GetTileIndex() + tile_offset) * TILE_SIZE_4BPP),
            group.tiles.GetByteCount());
        tile_offset += group.tiles.GetByteCount() / TILE_SIZE_4BPP;
    }
    FillHardwareDma3(0, reinterpret_cast<void *>(BG_VRAM + 0x7FE0), TILE_SIZE_4BPP);
    FillHardwareDma3(0xFFFFFFFF, reinterpret_cast<void *>(BG_SCREEN_ADDR(28)), BG_SCREEN_SIZE);
    FillHardwareDma3(0xFFFFFFFF, reinterpret_cast<void *>(BG_SCREEN_ADDR(29)), BG_SCREEN_SIZE);
    FillHardwareDma3(0xFFFFFFFF, reinterpret_cast<void *>(BG_SCREEN_ADDR(30)), BG_SCREEN_SIZE);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetDisplayFlags(
        DISPCNT_OBJ_1D_MAP | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(3,
        BGCNT_SIZE(1) | BGCNT_MOSAIC | BGCNT_SCREENBASE(28) | BGCNT_PRIORITY(3));
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(2,
        BGCNT_MOSAIC | BGCNT_SCREENBASE(29) | BGCNT_PRIORITY(1));
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(1,
        BGCNT_SIZE(1) | BGCNT_MOSAIC | BGCNT_SCREENBASE(30) | BGCNT_PRIORITY(2));
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
    reinterpret_cast<volatile u16 *>(BG_PLTT + 2 * PLTT_SIZE_4BPP)[0] = RGB(0, 31, 0);
    reinterpret_cast<volatile u16 *>(BG_PLTT + 2 * PLTT_SIZE_4BPP)[1] = RGB(0, 0, 0);
    reinterpret_cast<volatile u16 *>(BG_PLTT + 2 * PLTT_SIZE_4BPP)[2] = RGB(24, 16, 16);
    reinterpret_cast<u16 *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_618) * PLTT_SIZE_4BPP)[0] = RGB(0, 31, 0);
    reinterpret_cast<u16 *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_618) * PLTT_SIZE_4BPP)[1] = RGB(0, 0, 0);
    reinterpret_cast<u16 *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_618) * PLTT_SIZE_4BPP)[2] = RGB(24, 16, 16);
    UiSpriteGlyphBuffer glyph;
    for (i32 index = 0; index < static_cast<i32>(ARRAY_COUNT(gHorseRaceTicketCharacterCodes)); ++index)
    {
        u32 character = gHorseRaceTicketCharacterCodes[index];
        glyph.DrawCharacterExt(0, 0, character, 0, 1);
        u32 tile = core->tiles_610.GetTileIndex() +
            index * UiSpriteGlyphBuffer::TileCount;
        CopyHardwareDma3(glyph.tiles, reinterpret_cast<void *>(OBJ_VRAM0 +
            tile * TILE_SIZE_4BPP), sizeof(glyph.tiles));
    }
}

static inline void * TicketBackgroundTileAddress(u32 tile_index)
{
    return reinterpret_cast<void *>(BG_VRAM + tile_index * TILE_SIZE_4BPP);
}

extern "C" void RenderHorseRaceTicketPurchaseScreen(HorseRaceCore * core, i32 payout)
{
    enum { NameTile = 0x140, TitleTile = 0x200 };
    if (!payout)
    {
        IndexedResourceGroupResult group = core->cursor_archive.GetGroupData(0);
        CopyHardwareDma3(group.palettes.GetData(),
            reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_648) * PLTT_SIZE_4BPP),
            group.palettes.GetByteCount());
        CopyHardwareDma3(group.tiles.GetData(),
            reinterpret_cast<void *>(OBJ_VRAM0 + core->tiles_640.GetTileIndex() * TILE_SIZE_4BPP),
            group.tiles.GetByteCount());
        CopyHardwareDma3(gFarmStatusCreatureIcon11Tiles,
            reinterpret_cast<void *>(OBJ_VRAM0 +
                ARRAY_COUNT(gHorseRaceTicketCharacterCodes) * UiSpriteGlyphBuffer::TileCount * TILE_SIZE_4BPP +
                core->tiles_610.GetTileIndex() * TILE_SIZE_4BPP), 4 * TILE_SIZE_4BPP);
        CopyHardwareDma3(gFarmStatusCreatureIcon11Palette,
            reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_620) * PLTT_SIZE_4BPP), PLTT_SIZE_4BPP);
    }
    else
    {
        CopyHardwareDma3(gAnimalFestivalIcon01Tiles,
            reinterpret_cast<void *>(OBJ_VRAM0 +
                ARRAY_COUNT(gHorseRaceTicketCharacterCodes) * UiSpriteGlyphBuffer::TileCount * TILE_SIZE_4BPP +
                core->tiles_610.GetTileIndex() * TILE_SIZE_4BPP), 4 * TILE_SIZE_4BPP);
        CopyHardwareDma3(gAnimalFestivalIcon01Palette,
            reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_620) * PLTT_SIZE_4BPP), PLTT_SIZE_4BPP);
    }
    NewGameTextTileBuffer<12> name;
    HorseRaceRunner const * runner = core->runners;
    for (i32 index = 0; index < 4; ++index, ++runner)
    {
        name.Clear();
        if (runner->contestant_name_id < ANIMAL_FESTIVAL_LIVESTOCK_CONTESTANT_NAME_COUNT)
            name.DrawStringExt(0, 0, gText_AnimalFestival_LivestockContestantNames[runner->contestant_name_id], 0, 1);
        else
            name.DrawStringExt(0, 0, core->player_horse->GetName(), 0, 1);
        CopyHardwareDma3(name.tiles, TicketBackgroundTileAddress(NameTile + index * name.TileCount), sizeof(name.tiles));
    }
    NewGameTextTileBuffer<32> label;
    label.Clear();
    label.DrawStringExt(0, 0, gText_HorseRace_TicketPurchaseTitle, 0, 1);
    CopyHardwareDma3(label.tiles, TicketBackgroundTileAddress(TitleTile), sizeof(label.tiles));
    label.Clear();
    if (!payout)
        label.DrawStringExt(0, 0, gText_HorseRace_TicketPurchaseConfirm, 0, 1);
    else
        label.DrawStringExt(0, 0, gText_HorseRace_TicketPurchaseMedalsToWin, 0, 1);
    CopyHardwareDma3(label.tiles, TicketBackgroundTileAddress(TitleTile + label.TileCount), sizeof(label.tiles));
    FillHardwareDma3(0xFFFFFFFF, core->background_tilemap.ticket, sizeof(core->background_tilemap.ticket));
    u16 first_tile = (2 << 12) + NameTile;
    for (i32 index = 0; index < 4; ++index)
    {
        for (i32 column = 0; column < name.TileWidth; ++column)
        {
            core->background_tilemap.ticket[index * 2 + 6][4 + column] = first_tile + column;
            core->background_tilemap.ticket[index * 2 + 7][4 + column] = first_tile + name.TileWidth + column;
        }
        first_tile += name.TileCount;
    }
    for (i32 index = 0; index < label.TileCount; ++index)
    {
        core->background_tilemap.ticket[index / 32 + 4][index % 32] = (2 << 12) + TitleTile + index;
        core->background_tilemap.ticket[index / 32 + 15][index % 32] = (2 << 12) + TitleTile + label.TileCount + index;
    }
    CopyHardwareDma3(core->background_tilemap.ticket, reinterpret_cast<void *>(BG_SCREEN_ADDR(30)), sizeof(core->background_tilemap.ticket));
}

extern "C" void LoadHorseRaceTicketControls(HorseRaceCore * core)
{
    FillHardwareDma3(0, reinterpret_cast<void *>(BG_VRAM + 0x8000), 0x2C00);
    FillHardwareDma3(0, reinterpret_cast<void *>(BG_SCREEN_ADDR(31)), BG_SCREEN_SIZE);
    u16 (*tilemap)[32] = reinterpret_cast<u16 (*)[32]>(BG_SCREEN_ADDR(31));
    for (u32 row = 0; row < 22; ++row)
        for (u32 column = 0; column < 32; ++column)
            tilemap[row][column] = 0x2000 + row * 32 + column;
    NewGameTextTileBuffer<32> line;
    for (i32 index = 0; gHorseRaceTicketControls[index]; ++index)
    {
        Clear2DGfxBuffer(line.PackedDimensions(), line.tiles, 0);
        line.DrawStringExt(0, 0, gHorseRaceTicketControls[index], 0, 1);
        CopyHardwareDma3(line.tiles,
            reinterpret_cast<void *>(BG_VRAM + 0x8000 + index * sizeof(line.tiles)), sizeof(line.tiles));
    }
}

extern "C" void BuildHorseRaceTicketGlyphs(HorseRaceCore * core, i32 payout)
{
    core->glyph_count = 0;
    if (!payout)
    {
        AppendHorseRaceGlyph(core, 16, 4, ARRAY_COUNT(gHorseRaceTicketCharacterCodes), 1);
        AppendHorseRaceNumber(core, 40, 4, 1, core->money_after_tickets, 10, 12);
    }
    else
    {
        for (i32 index = 0; index < static_cast<i32>(ARRAY_COUNT(gHorseRaceTicketCharacterCodes)) - 13; ++index)
            AppendHorseRaceGlyph(core, 8 + index * (UiSpriteGlyphBuffer::TileWidth * 8), 4, 13 + index, 1);
        AppendHorseRaceNumber(core, 136, 4, 1, core->medals, 5, 10);
        AppendHorseRaceNumber(core, 160, 120, 2, core->payout_remaining, 4, 10);
        AppendHorseRaceGlyph(core, 0, 48 + core->finishing_order[0] * 16,
            ARRAY_COUNT(gHorseRaceTicketCharacterCodes), 2);
    }
#if defined(REGION_JP)
    AppendHorseRaceNumber(core, 16, 32, 2, core->round + 1, 1, 0);
#elif defined(REGION_DE)
    AppendHorseRaceNumber(core, 136, 32, 2, core->round + 1, 1, 0);
#else
    AppendHorseRaceNumber(core, 32, 32, 2, core->round + 1, 1, 0);
#endif
    HorseRaceRunner * runner = core->runners;
    for (i32 index = 0; index < static_cast<i32>(ARRAY_COUNT(core->runners)); ++index, ++runner)
    {
        i32 y = 48 + index * 16;
#if defined(REGION_JP)
        AppendHorseRaceNumber(core, 136, y, 2, runner->odds, 2, 11);
#else
        AppendHorseRaceGlyph(core, 136, y, 11, 2);
        AppendHorseRaceNumber(core, 144, y, 2, runner->odds, 2, 10);
#endif
        AppendHorseRaceNumber(core, 192, y, 2, runner->ticket_count, 2, 10);
    }
}

extern "C" void AppendHorseRaceNumber(HorseRaceCore * core, i32 x, i32 y,
    u32 priority, i32 value, i32 digits, i32 suffix)
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
    for (; divisor > 0; divisor /= 10)
    {
        if (divisor == 1)
            started = true;
        digit = value / divisor;
        if (digit || started)
        {
            AppendHorseRaceGlyph(core, x, y, digit, priority);
            started = true;
        }
        x += UiSpriteGlyphBuffer::TileWidth * 8;
        value -= digit * divisor;
    }
    if (suffix)
        AppendHorseRaceGlyph(core, x, y, suffix, priority);
}

extern "C" void AppendHorseRaceGlyph(HorseRaceCore * core, i32 x, i32 y, i32 glyph, u32 priority)
{
    core->glyphs[core->glyph_count].x = x;
    core->glyphs[core->glyph_count].y = y;
    core->glyphs[core->glyph_count].glyph_index = glyph;
    core->glyphs[core->glyph_count].priority = priority;
    ++core->glyph_count;
}

extern "C" void RenderHorseRaceTicketSprites(HorseRaceCore * core)
{
    IndexedResourceSpriteParameters parameters;
    IndexedResourceGroupResult group(nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0);
    if (core->selected_ticket >= 0)
    {
        UpdateIndexedResourceHandle(&core->ticket_cursor.resource);
        group = HorseRaceSpriteGroup(core->ticket_cursor.resource);
        parameters = core->ticket_cursor.parameters;
        parameters.x = core->selected_ticket <= 3 ? 12 : 28;
        parameters.y = core->selected_ticket <= 3 ? core->selected_ticket * 16 + 56 : 128;
        parameters.tile_offset = core->tiles_640.GetTileIndex();
        parameters.palette_offset = HorseRacePaletteBank(core->palette_648);
        parameters.priority = 2;
        parameters.mosaic = 1;
        DrawIndexedResourceSprites(GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core)),
            group.sprites.Data(), group.sprites.Count(), &parameters);
    }
    for (i32 index = 0; index < 4; ++index)
    {
        ResolveIndexedResourceHandle(&core->ticket_entry_marker.resource, index);
        group = HorseRaceSpriteGroup(core->ticket_entry_marker.resource);
        parameters.x = 16;
        parameters.y = 48 + index * 16;
        parameters.palette_offset = HorseRacePaletteBank(core->palette_608);
        parameters.tile_offset = core->tiles_600.GetTileIndex() + index * 4;
        parameters.priority = 2;
        parameters.mosaic = 1;
        DrawIndexedResourceSprites(GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core)),
            group.sprites.Data(), group.sprites.Count(), &parameters);
    }
    HardwareSpriteOamRecord attributes;
    attributes.affine_mode = 0;
    attributes.object_mode = 0;
    attributes.mosaic = 1;
    attributes.color_mode = 0;
    attributes.shape = ST_OAM_SQUARE;
    attributes.affine_index_low = 0;
    attributes.horizontal_flip = 0;
    attributes.vertical_flip = 0;
    attributes.size = ST_OAM_SIZE_1;
    attributes.palette_bank = HorseRacePaletteBank(core->palette_618);
    attributes.affine_coefficient = 0;
    --core->glyph_count;
    while (core->glyph_count >= 0)
    {
        attributes.priority = core->glyphs[core->glyph_count].priority;
        attributes.x = core->glyphs[core->glyph_count].x;
        attributes.y = core->glyphs[core->glyph_count].y;
        attributes.tile_index = core->tiles_610.GetTileIndex() +
            core->glyphs[core->glyph_count].glyph_index * UiSpriteGlyphBuffer::TileCount;
        if (core->glyphs[core->glyph_count].glyph_index != static_cast<i32>(ARRAY_COUNT(gHorseRaceTicketCharacterCodes)))
        {
            attributes.palette_bank = HorseRacePaletteBank(core->palette_618);
#if !defined(REGION_JP)
            attributes.shape = ST_OAM_V_RECTANGLE;
            attributes.size = ST_OAM_SIZE_0;
#endif
        }
        else
        {
            attributes.palette_bank = HorseRacePaletteBank(core->palette_620);
#if !defined(REGION_JP)
            attributes.shape = ST_OAM_SQUARE;
            attributes.size = ST_OAM_SIZE_1;
#endif
        }
        HardwareSpriteBufferState * buffer = GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core));
        u32 count = buffer->sprite_count;
        if (count < ARRAY_COUNT(buffer->sprites))
        {
            HardwareSpriteOamRecord & destination = buffer->sprites[count];
            reinterpret_cast<u32 *>(&destination)[0] = reinterpret_cast<u32 const &>(attributes);
            reinterpret_cast<u16 *>(&destination)[2] = reinterpret_cast<u16 const *>(&attributes)[2];
            buffer->sprite_count = count + 1;
        }
        --core->glyph_count;
    }
}

extern "C" void InitializeHorseRaceBackground(HorseRaceCore * core)
{
    FillHardwareDma3(0, reinterpret_cast<void *>(BG_VRAM + 0x7FE0), TILE_SIZE_4BPP);
    FillHardwareDma3(0xFFFFFFFF, reinterpret_cast<void *>(BG_SCREEN_ADDR(25)), 2 * BG_SCREEN_SIZE);
    FillHardwareDma3(0xFFFFFFFF, reinterpret_cast<void *>(BG_SCREEN_ADDR(27)), 2 * BG_SCREEN_SIZE);
    FillHardwareDma3(0xFFFFFFFF, reinterpret_cast<void *>(BG_SCREEN_ADDR(29)), 2 * BG_SCREEN_SIZE);
    Unpack(gUiThreeLayerBackgroundTilemap0, core->background_tilemap.race);
    Unpack(gUiThreeLayerBackgroundTilemap1, core->background_tilemap.race + 0x80);
    Unpack(gUiThreeLayerBackgroundTilemap2, core->background_tilemap.race + 0x100);
    Unpack(gUiThreeLayerBackgroundTilemap3, core->background_tilemap.race + 0x180);
    Unpack(gUiThreeLayerBackgroundTiles, reinterpret_cast<void *>(BG_VRAM));
    CopyHardwareDma3(gUiThreeLayerBackgroundPalette, reinterpret_cast<void *>(BG_PLTT), BG_PLTT_SIZE);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetDisplayFlags(
        DISPCNT_OBJ_1D_MAP | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(3,
        BGCNT_SIZE(1) | BGCNT_MOSAIC | BGCNT_SCREENBASE(25) | BGCNT_PRIORITY(3));
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(2,
        BGCNT_SIZE(1) | BGCNT_MOSAIC | BGCNT_SCREENBASE(27) | BGCNT_PRIORITY(2));
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundFlags(1,
        BGCNT_SIZE(1) | BGCNT_MOSAIC | BGCNT_SCREENBASE(29) | BGCNT_PRIORITY(1));
    for (i32 column = 0; column < 32; ++column)
        for (i32 row = 0; row < 30; row += 6)
        {
            CopyHardwareDma3(core->background_tilemap.race + column * 6,
                reinterpret_cast<u16 *>(BG_SCREEN_ADDR(25)) + column * 32 + row, 6 * sizeof(u16));
            if (row != 18)
                CopyHardwareDma3(core->background_tilemap.race + 0x80 + column * 6,
                    reinterpret_cast<u16 *>(BG_SCREEN_ADDR(27)) + column * 32 + row, 6 * sizeof(u16));
            else
                CopyHardwareDma3(core->background_tilemap.race + 0x180 + column * 6,
                    reinterpret_cast<u16 *>(BG_SCREEN_ADDR(27)) + column * 32 + row, 6 * sizeof(u16));
            CopyHardwareDma3(core->background_tilemap.race + 0x100 + column * 6,
                reinterpret_cast<u16 *>(BG_SCREEN_ADDR(29)) + column * 32 + row, 6 * sizeof(u16));
        }
    core->background_x[0] = 1536;
    core->background_x[1] = 1536;
    core->background_x[2] = 1536;
    core->previous_background_x[0] = 0;
    core->previous_background_x[1] = 0;
    core->previous_background_x[2] = 0;
    core->background_column[0] = 0;
    core->background_column[1] = 0;
    core->background_column[2] = 0;
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetVerticalOffset(1, 0);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetVerticalOffset(2, 0);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetVerticalOffset(3, 0);
}

static inline void QueueHorseRaceTilePair(HardwareDmaQueue * queue, u16 const * source, void * destination)
{
    queue->PushBack(DmaTransferDescriptor(source, destination, 2 * sizeof(u16)));
}

extern "C" void UpdateHorseRaceBackground(HorseRaceCore * core)
{
    i32 row;
    i32 tile_x;

    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundX(1, core->background_x[0]);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundX(2, core->background_x[1]);
    GetHardwareDisplayState(reinterpret_cast<void * const *>(core))->SetBackgroundX(3, core->background_x[2]);
    if (core->previous_background_x[2] != (core->background_x[2] & 0xFFF0))
    {
        core->previous_background_x[2] = core->background_x[2] & 0xFFF0;
        if (--core->background_column[2] < 0)
            core->background_column[2] = 2;
        tile_x = ((core->previous_background_x[2] - 16) & 0x1F0) >> 3;
        for (row = 0; row < 20; ++row)
        {
            QueueHorseRaceTilePair(GetHardwareDmaQueue(reinterpret_cast<void * const *>(core)),
                core->background_tilemap.race + (row * 3 + core->background_column[2]) * 2,
                reinterpret_cast<u8 *>(BG_SCREEN_ADDR(25)) +
                    (row * 64 + (tile_x >> 5) * BG_SCREEN_SIZE + (tile_x & 31) * sizeof(u16)));
        }
    }
    if (core->previous_background_x[1] != (core->background_x[1] & 0xFFF0))
    {
        core->previous_background_x[1] = core->background_x[1] & 0xFFF0;
        if (--core->background_column[1] < 0)
            core->background_column[1] = 2;
        tile_x = ((core->previous_background_x[1] - 16) & 0x1F0) >> 3;
        if (static_cast<u16>(core->previous_background_x[1] - 144) <= 47)
        {
            for (row = 3; row < 18; ++row)
            {
                QueueHorseRaceTilePair(GetHardwareDmaQueue(reinterpret_cast<void * const *>(core)),
                    core->background_tilemap.race + 0x180 + (row * 3 + core->background_column[1]) * 2,
                    reinterpret_cast<u8 *>(BG_SCREEN_ADDR(27)) +
                        (row * 64 + (tile_x >> 5) * BG_SCREEN_SIZE + (tile_x & 31) * sizeof(u16)));
            }
        }
        else
        {
            for (row = 3; row < 18; ++row)
            {
                QueueHorseRaceTilePair(GetHardwareDmaQueue(reinterpret_cast<void * const *>(core)),
                    core->background_tilemap.race + 0x80 + (row * 3 + core->background_column[1]) * 2,
                    reinterpret_cast<u8 *>(BG_SCREEN_ADDR(27)) +
                        (row * 64 + (tile_x >> 5) * BG_SCREEN_SIZE + (tile_x & 31) * sizeof(u16)));
            }
        }
    }
    if (core->previous_background_x[0] != (core->background_x[0] & 0xFFF0))
    {
        core->previous_background_x[0] = core->background_x[0] & 0xFFF0;
        if (--core->background_column[0] < 0)
            core->background_column[0] = 2;
        tile_x = ((core->previous_background_x[0] - 16) & 0x1F0) >> 3;
        for (row = 17; row < 20; ++row)
        {
            QueueHorseRaceTilePair(GetHardwareDmaQueue(reinterpret_cast<void * const *>(core)),
                core->background_tilemap.race + 0x100 + (row * 3 + core->background_column[0]) * 2,
                reinterpret_cast<u8 *>(BG_SCREEN_ADDR(29)) +
                    (row * 64 + (tile_x >> 5) * BG_SCREEN_SIZE + (tile_x & 31) * sizeof(u16)));
        }
    }
}

extern "C" void LoadHorseRaceSpriteResources(HorseRaceCore * core)
{
    IndexedResourceGroupResult group(nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0);
    group = HorseRaceSpriteGroup(core->lane_marker.resource);
    CopyHardwareDma3(group.palettes.GetData(),
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_5C8) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount());
    u32 tile_offset = 0;
    for (i32 index = 0; index < 4; ++index)
    {
        ResolveIndexedResourceHandle(&core->lane_marker.resource, index);
        group = HorseRaceSpriteGroup(core->lane_marker.resource);
        CopyHardwareDma3(group.tiles.GetData(),
            reinterpret_cast<void *>(OBJ_VRAM0 + (core->tiles_5C0.GetTileIndex() + tile_offset) * TILE_SIZE_4BPP),
            group.tiles.GetByteCount());
        tile_offset += group.tiles.GetByteCount() / TILE_SIZE_4BPP;
    }
    group = HorseRaceSpriteGroup(core->runner_sprite_1.resource);
    CopyHardwareDma3(group.palettes.data,
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->contestant_tiles[0].palettes[0]) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount() / 2);
    CopyHardwareDma3(reinterpret_cast<u8 const *>(group.palettes.data) + group.palettes.GetByteCount() / 2,
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->contestant_tiles[0].palettes[1]) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount() / 2);
    group = HorseRaceSpriteGroup(core->runner_sprite_2.resource);
    CopyHardwareDma3(group.palettes.data,
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->contestant_tiles[1].palettes[0]) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount() / 2);
    CopyHardwareDma3(reinterpret_cast<u8 const *>(group.palettes.data) + group.palettes.GetByteCount() / 2,
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->contestant_tiles[1].palettes[1]) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount() / 2);
    if (!core->player_competes_this_round)
    {
        group = HorseRaceSpriteGroup(core->runner_sprite_3.resource);
        CopyHardwareDma3(group.palettes.data,
            reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->contestant_tiles[2].palettes[0]) * PLTT_SIZE_4BPP),
            group.palettes.GetByteCount() / 2);
        CopyHardwareDma3(reinterpret_cast<u8 const *>(group.palettes.data) + group.palettes.GetByteCount() / 2,
            reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->contestant_tiles[2].palettes[1]) * PLTT_SIZE_4BPP),
            group.palettes.GetByteCount() / 2);
    }
    else
    {
        group = HorseRaceSpriteGroup(core->player_runner_sprite.resource);
        CopyHardwareDma3(group.palettes.data,
            reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->contestant_tiles[2].palettes[0]) * PLTT_SIZE_4BPP),
            group.palettes.GetByteCount() / 2);
        CopyHardwareDma3(reinterpret_cast<u8 const *>(group.palettes.data) + group.palettes.GetByteCount() / 2,
            reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->contestant_tiles[2].palettes[1]) * PLTT_SIZE_4BPP),
            group.palettes.GetByteCount() / 2);
    }
    group = HorseRaceSpriteGroup(core->runner_sprite_4.resource);
    CopyHardwareDma3(group.palettes.data,
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->contestant_tiles[3].palettes[0]) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount() / 2);
    CopyHardwareDma3(reinterpret_cast<u8 const *>(group.palettes.data) + group.palettes.GetByteCount() / 2,
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->contestant_tiles[3].palettes[1]) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount() / 2);
    group = core->unk_archive_050.GetGroupData(0);
    CopyHardwareDma3(group.palettes.GetData(),
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_5D8) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount());
    CopyHardwareDma3(group.tiles.GetData(),
        reinterpret_cast<void *>(OBJ_VRAM0 + core->tiles_5D0.GetTileIndex() * TILE_SIZE_4BPP),
        group.tiles.GetByteCount());
    group = core->unk_archive_050.GetGroupData(1);
    CopyHardwareDma3(group.tiles.GetData(),
        reinterpret_cast<void *>(OBJ_VRAM0 + 8 * TILE_SIZE_4BPP + core->tiles_5D0.GetTileIndex() * TILE_SIZE_4BPP),
        group.tiles.GetByteCount());
    for (i32 index = 0; index < 32; ++index)
    {
        core->dust_points[index][HorseRaceDustX] = -1;
        core->dust_points[index][HorseRaceDustY] = (index >> 3) * 24 + 64;
    }
    group = HorseRaceSpriteGroup(core->stamina_indicator.resource);
    CopyHardwareDma3(group.palettes.GetData(),
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_5E8) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount());
    tile_offset = 0;
    for (i32 index = 0; index < 3; ++index)
    {
        for (i32 frame = 0; frame < 2; ++frame)
        {
            group = HorseRaceResolvedGroup(&core->unk_archive_080, index, frame);
            CopyHardwareDma3(group.tiles.GetData(),
                reinterpret_cast<void *>(OBJ_VRAM0 + (core->tiles_5E0.GetTileIndex() + tile_offset) * TILE_SIZE_4BPP),
                group.tiles.GetByteCount());
            tile_offset += group.tiles.GetByteCount() / TILE_SIZE_4BPP;
        }
    }
    group = core->unk_archive_0E0.GetGroupData(0);
    CopyHardwareDma3(group.palettes.GetData(),
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_5F8) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount());
    CopyHardwareDma3(group.tiles.GetData(),
        reinterpret_cast<void *>(OBJ_VRAM0 + core->tiles_5F0.GetTileIndex() * TILE_SIZE_4BPP),
        group.tiles.GetByteCount());
    tile_offset = 0;
    for (i32 index = 0; index < 4; ++index)
    {
        core->runner_effect_tile_offsets[index] = tile_offset;
        group = HorseRaceResolvedGroup(&core->unk_archive_110, 0, index);
        CopyHardwareDma3(group.tiles.GetData(),
            reinterpret_cast<void *>(OBJ_VRAM0 + (core->tiles_628.GetTileIndex() + tile_offset) * TILE_SIZE_4BPP),
            group.tiles.GetByteCount());
        tile_offset += group.tiles.GetByteCount() / TILE_SIZE_4BPP;
    }
    group = HorseRaceSpriteGroup(core->boost_overlay_1.resource);
    CopyHardwareDma3(group.palettes.GetData(),
        reinterpret_cast<void *>(OBJ_PLTT + HorseRacePaletteBank(core->palette_638) * PLTT_SIZE_4BPP),
        group.palettes.GetByteCount());
    tile_offset = 0;
    for (i32 index = 0; index < 4; ++index)
    {
        core->runner_overlay_tile_offsets[index] = tile_offset;
        group = HorseRaceResolvedGroup(&core->unk_archive_140, 0, index);
        CopyHardwareDma3(group.tiles.GetData(),
            reinterpret_cast<void *>(OBJ_VRAM0 + (core->tiles_630.GetTileIndex() + tile_offset) * TILE_SIZE_4BPP),
            group.tiles.GetByteCount());
        tile_offset += group.tiles.GetByteCount() / TILE_SIZE_4BPP;
    }
    group = HorseRaceSpriteGroup(core->shared_runner_sprite.resource);
    CopyHardwareDma3(group.tiles.GetData(),
        reinterpret_cast<void *>(OBJ_VRAM0 + core->tiles_650.GetTileIndex() * TILE_SIZE_4BPP),
        group.tiles.GetByteCount());
}

extern "C" void RenderHorseRaceSprites(HorseRaceCore * core)
{
    HorseRaceSpriteState * sprite = nullptr;
    IndexedResourceSpriteParameters parameters;
    IndexedResourceGroupResult group(nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0);
    i32 index;
    if (core->pause_flags & 1)
    {
        group = core->unk_archive_0E0.GetGroupData(0);
        parameters.x = 64;
        parameters.y = 64;
        parameters.palette_offset = HorseRacePaletteBank(core->palette_5F8);
        parameters.tile_offset = core->tiles_5F0.GetTileIndex();
        parameters.priority = 2;
        parameters.mosaic = 1;
        DrawIndexedResourceSprites(GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core)),
            group.sprites.Data(), group.sprites.Count(), &parameters);
    }
    if (core->background_x[1] > 1472)
    {
        for (index = 0; index < 4; ++index)
        {
            ResolveIndexedResourceHandle(&core->lane_marker.resource, index);
            group = core->lane_marker.FrameGroup();
            parameters.x = 1752 - core->background_x[1];
            parameters.y = 48 + index * 24;
            parameters.palette_offset = HorseRacePaletteBank(core->palette_5C8);
            parameters.tile_offset = core->tiles_5C0.GetTileIndex() + index * 4;
            parameters.priority = 2;
            parameters.mosaic = 1;
            DrawIndexedResourceSprites(GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core)),
                group.sprites.Data(), group.sprites.Count(), &parameters);
        }
    }
    if ((core->pause_flags & 1) == 0)
    {
        core->runner_sprite_1.update_result = UpdateIndexedResourceHandle(&core->runner_sprite_1.resource);
        core->runner_sprite_2.update_result = UpdateIndexedResourceHandle(&core->runner_sprite_2.resource);
        core->runner_sprite_3.update_result = UpdateIndexedResourceHandle(&core->runner_sprite_3.resource);
        core->runner_sprite_4.update_result = UpdateIndexedResourceHandle(&core->runner_sprite_4.resource);
        core->player_runner_sprite.update_result = UpdateIndexedResourceHandle(&core->player_runner_sprite.resource);
        if (core->player_competes_this_round)
        {
            i32 const stamina = core->runners[2].stamina;
            i32 level = 0;
            if (stamina <= 171)
                level = stamina > 85 ? 1 : 2;
            if (core->player_stamina_level != level)
            {
                core->player_stamina_level = level;
                ResolveIndexedResourceHandle(&core->stamina_indicator.resource, core->player_stamina_level);
            }
            else
                core->stamina_indicator.update_result = UpdateIndexedResourceHandle(&core->stamina_indicator.resource);
        }
        if (core->phase == 24)
        {
            UpdateIndexedResourceHandle(&core->runner_effect_1.resource);
            UpdateIndexedResourceHandle(&core->runner_effect_2.resource);
            UpdateIndexedResourceHandle(&core->runner_effect_3.resource);
            UpdateIndexedResourceHandle(&core->runner_effect_4.resource);
        }
        for (index = 0; index < 4; ++index)
            if (core->runners[index].boost_phase > 1)
                switch (index)
                {
                case 0: UpdateIndexedResourceHandle(&core->boost_overlay_1.resource); break;
                case 1: UpdateIndexedResourceHandle(&core->boost_overlay_2.resource); break;
                case 2: UpdateIndexedResourceHandle(&core->boost_overlay_3.resource); break;
                case 3: UpdateIndexedResourceHandle(&core->boost_overlay_4.resource); break;
                }
    }
    for (index = 3; index >= 0; --index)
    {
        if (core->phase == 24)
        {
            HorseRaceSpriteState * overlay = nullptr;
            switch (index)
            {
            case 0: sprite = &core->runner_effect_1; overlay = &core->boost_overlay_1; break;
            case 1: sprite = &core->runner_effect_2; overlay = &core->boost_overlay_2; break;
            case 2: sprite = &core->runner_effect_3; overlay = &core->boost_overlay_3; break;
            case 3: sprite = &core->runner_effect_4; overlay = &core->boost_overlay_4; break;
            default: break;
            }
            group = sprite->FrameGroup();
            parameters = sprite->parameters;
            parameters.x = (core->runners[index].x_fixed >> 16) - core->background_x[1];
            parameters.y = 60 + index * 24;
            parameters.priority = 2;
            parameters.palette_offset = HorseRacePaletteBank(core->palette_638);
            parameters.tile_offset = core->tiles_628.GetTileIndex() +
                core->runner_effect_tile_offsets[sprite->resource.resolved_resource[sprite->resource.current_entry_index].group_index];
            parameters.mosaic = 1;
            DrawIndexedResourceSprites(GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core)),
                group.sprites.Data(), group.sprites.Count(), &parameters);
            if (core->runners[index].boost_phase > 1)
            {
                group = overlay->FrameGroup();
                parameters = overlay->parameters;
                parameters.x = (core->runners[index].x_fixed >> 16) - core->background_x[1] + 16;
                parameters.y = 60 + index * 24;
                parameters.priority = 2;
                parameters.palette_offset = HorseRacePaletteBank(core->palette_638);
                parameters.tile_offset = core->tiles_630.GetTileIndex() +
                    core->runner_overlay_tile_offsets[overlay->resource.resolved_resource[overlay->resource.current_entry_index].group_index];
                parameters.mosaic = 1;
                DrawIndexedResourceSprites(GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core)),
                    group.sprites.Data(), group.sprites.Count(), &parameters);
            }
        }
        switch (index)
        {
        case 0: sprite = &core->runner_sprite_1; break;
        case 1: sprite = &core->runner_sprite_2; break;
        case 2:
            if (!core->player_competes_this_round)
                sprite = &core->runner_sprite_3;
            else
                sprite = &core->player_runner_sprite;
            break;
        case 3: sprite = &core->runner_sprite_4; break;
        default: break;
        }
        group = sprite->FrameGroup();
        parameters = sprite->parameters;
        parameters.x = (core->runners[index].x_fixed >> 16) - core->background_x[1];
        parameters.y = 60 + index * 24;
        parameters.priority = 2;
        parameters.tile_offset = core->contestant_tiles[index].tiles.GetTileIndex();
        parameters.mosaic = 1;
        if (sprite->update_result.flags.group_changed)
        {
            QueueObjTileTransfer(GetHardwareDmaQueue(reinterpret_cast<void * const *>(core)),
                group.tiles.GetData(), core->contestant_tiles[index].tiles.GetTileIndex(), 0,
                group.tiles.GetByteCount());
        }
        DrawHorseRaceContestantSprites(core, group.sprites.Data(), group.sprites.Count(), &parameters,
            &core->contestant_tiles[index]);
        if (core->player_competes_this_round && index == 2)
        {
            IndexedResourceHandle const & player_animation = core->stamina_indicator.resource;
            group = HorseRaceSpriteGroup(player_animation);
            parameters = core->stamina_indicator.parameters;
            parameters.x = (core->runners[2].x_fixed >> 16) - core->background_x[1] - 39;
            parameters.y = 76;
            parameters.palette_offset = HorseRacePaletteBank(core->palette_5E8);
            parameters.priority = 2;
            parameters.mosaic = 1;
            parameters.tile_offset = core->tiles_5E0.GetTileIndex() +
                player_animation.resolved_resource[player_animation.current_entry_index].group_index * 4;
            DrawIndexedResourceSprites(GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core)),
                group.sprites.Data(), group.sprites.Count(), &parameters);
        }
        group = core->shared_runner_sprite.FrameGroup();
        parameters = core->shared_runner_sprite.parameters;
        parameters.x = (core->runners[index].x_fixed >> 16) - core->background_x[1];
        parameters.y = 60 + index * 24;
        parameters.priority = 2;
        parameters.palette_offset = HorseRacePaletteBank(core->palette_5D8);
        parameters.tile_offset = core->tiles_650.GetTileIndex();
        parameters.mosaic = 1;
        DrawIndexedResourceSprites(GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core)),
            group.sprites.Data(), group.sprites.Count(), &parameters);
    }
    for (index = 0; index < 32; ++index)
    {
        if (core->dust_points[index][HorseRaceDustX] != -1)
        {
            group = core->unk_archive_050.GetGroupData(index & 1);
            parameters.x = core->dust_points[index][HorseRaceDustX] - core->background_x[1];
            parameters.y = core->dust_points[index][HorseRaceDustY];
            parameters.palette_offset = HorseRacePaletteBank(core->palette_5D8);
            parameters.tile_offset = core->tiles_5D0.GetTileIndex() + (index & 1) * 8;
            parameters.priority = 2;
            parameters.mosaic = 1;
            DrawIndexedResourceSprites(GetHardwareSpriteBuffer(reinterpret_cast<void * const *>(core)),
                group.sprites.Data(), group.sprites.Count(), &parameters);
        }
    }
}

extern "C" void DrawHorseRaceContestantSprites(HorseRaceCore * core,
    HardwareSpriteOamRecord const * records, u32 count,
    IndexedResourceSpriteParameters const * parameters, HorseRaceContestantTiles * tiles)
{
    HardwareSpriteOamRecord const * cursor = records;
    HardwareSpriteOamRecord const * end = cursor + count;
    for (; cursor != end; ++cursor)
    {
        HardwareSpriteOamRecord attributes = *cursor;
        i32 x = static_cast<i16>(attributes.x);
        i32 y = static_cast<i16>(attributes.y);
        u32 const shape = attributes.shape;
        u32 size = attributes.size;
        i32 width, height;
        if (shape == ST_OAM_SQUARE)
            width = height = 8 << size;
        else
        {
            u32 longer = 8 << (((size + 1) >> 1) + 1);
            u32 shorter = size == 1 ? 8 : longer / 2;
            if (shape != ST_OAM_H_RECTANGLE)
            {
                height = longer;
                width = shorter;
            }
            else
            {
                height = shorter;
                width = longer;
            }
        }
        if (parameters->flips & 1)
        {
            x = -(x + width);
            attributes.horizontal_flip ^= 1;
        }
        if (parameters->flips & 2)
        {
            y = -(y + height);
            attributes.vertical_flip ^= 1;
        }
        x += parameters->x;
        y += parameters->y;
        if (x + width <= 0 || x > 239 || y + height <= 0 || y > 159)
            continue;
        attributes.x = x;
        attributes.y = y;
        attributes.palette_bank = HorseRacePaletteBank(tiles->palettes[attributes.palette_bank]);
        attributes.tile_index += parameters->tile_offset;
        attributes.priority = parameters->priority;
        attributes.object_mode = parameters->object_mode;
        attributes.affine_mode = parameters->affine_mode;
        attributes.mosaic = parameters->mosaic;
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

extern "C" void InitializeHorseRaceRunners(HorseRaceCore * core)
{
    HorseRaceRunner * runner = core->runners;
    if (core->player_competes_this_round == 1)
    {
        core->runners[2].contestant_name_id = 0x80;
        core->runners[2].adequacy = core->player_horse->GetAdequacy();
        core->runners[2].affection = core->player_horse->GetAffection();
        i32 remaining = 250 - core->runners[2].adequacy;
        i32 odds = remaining * remaining / 1000;
        i32 random_odds = rand();
        random_odds &= 3;
        ++random_odds;
        odds += random_odds;
        core->runners[2].odds = odds;
    }
    for (i32 index = 0; index < 4; ++index, ++runner)
    {
        i32 normal = (0xC49 * runner->adequacy + (88 << 16)) / 60;
        runner->normal_speed = normal;
        runner->boosted_speed = (0xC49 * runner->affection + (12 << 16)) / 60 + normal;
        runner->acceleration = (runner->boosted_speed - normal) / 60;
        runner->deceleration = 0;
        runner->timer = 12;
        runner->stamina = 255;
        runner->stamina_recovery_ticks = 0;
        runner->speed = normal;
        runner->x_fixed = 1720 << 16;
        runner->finishing_place = 0xFF;
        runner->boost_phase = 0;
        runner->ticket_count = 0;
        if (core->phase == 0)
        {
            if (core->player_competes_this_round == 1 && index == 2)
            {
                for (i32 byte = 0; byte < static_cast<i32>(ARRAY_COUNT(runner->boost_probabilities)); ++byte)
                    runner->boost_probabilities[byte] = 0;
            }
            else
                for (i32 byte = 0; byte < 4; ++byte)
                    runner->boost_probabilities[byte] = gAnimalFestivalLivestockContestantValues[runner->contestant_name_id][byte];
        }
    }
}

extern "C" i32 UpdateHorseRaceRunners(HorseRaceCore * core)
{
    i32 order[4];
    i32 positions[4];
    HorseRaceRunner * current = core->runners;
    i32 nearest = 1720 << 16;
    i32 entry;
    for (entry = 0; entry < 4; ++entry, ++current)
    {
        if (++current->stamina_recovery_ticks > 9)
        {
            current->stamina_recovery_ticks = 0;
            current->stamina += 3;
            if (current->stamina >= 255)
                current->stamina = 255;
        }
        switch (current->boost_phase)
        {
        case 0:
            break;
        case 1:
            switch (entry)
            {
            case 0:
                core->runner_sprite_1.resource.SetScrollDelta(384);
                core->runner_effect_1.resource.SetScrollDelta(384);
                ResolveIndexedResourceHandle(&core->boost_overlay_1.resource, 0);
                break;
            case 1:
                core->runner_sprite_2.resource.SetScrollDelta(384);
                core->runner_effect_2.resource.SetScrollDelta(384);
                ResolveIndexedResourceHandle(&core->boost_overlay_2.resource, 0);
                break;
            case 2:
                if (!core->player_competes_this_round)
                    core->runner_sprite_3.resource.SetScrollDelta(384);
                else
                    core->player_runner_sprite.resource.SetScrollDelta(384);
                core->runner_effect_3.resource.SetScrollDelta(384);
                ResolveIndexedResourceHandle(&core->boost_overlay_3.resource, 0);
                break;
            case 3:
                core->runner_sprite_4.resource.SetScrollDelta(384);
                core->runner_effect_4.resource.SetScrollDelta(384);
                ResolveIndexedResourceHandle(&core->boost_overlay_4.resource, 0);
                break;
            }
            current->timer = 60;
            current->boost_phase = 2;
            // The trigger frame also advances the acceleration phase.
        case 2:
            current->speed += current->acceleration;
            --current->timer;
            if (current->speed >= current->boosted_speed)
                current->timer = 0;
            if (current->timer <= 0)
            {
                current->boost_phase = 3;
                current->speed = current->boosted_speed;
                current->timer = 60;
            }
            break;
        case 3:
            if (--current->timer <= 0)
            {
                current->boost_phase = 4;
                current->timer = 60 / current->stamina + 30;
                current->deceleration = (current->boosted_speed - current->normal_speed) / current->timer;
            }
            break;
        case 4:
            current->speed -= current->deceleration;
            --current->timer;
            if (current->speed <= current->normal_speed)
                current->timer = 0;
            if (current->timer <= 0)
            {
                current->boost_phase = 0;
                current->speed = current->normal_speed;
                current->timer = 12;
                switch (entry)
                {
                case 0:
                    core->runner_sprite_1.resource.SetScrollDelta(256);
                    core->runner_effect_1.resource.SetScrollDelta(256);
                    break;
                case 1:
                    core->runner_sprite_2.resource.SetScrollDelta(256);
                    core->runner_effect_2.resource.SetScrollDelta(256);
                    break;
                case 2:
                    if (!core->player_competes_this_round)
                        core->runner_sprite_3.resource.SetScrollDelta(256);
                    else
                        core->player_runner_sprite.resource.SetScrollDelta(256);
                    core->runner_effect_3.resource.SetScrollDelta(256);
                    break;
                case 3:
                    core->runner_sprite_4.resource.SetScrollDelta(256);
                    core->runner_effect_4.resource.SetScrollDelta(256);
                    break;
                }
            }
            break;
        }
        i32 position = current->x_fixed - current->speed;
        current->x_fixed = position;
        positions[entry] = position;
        if (nearest > position)
            nearest = position;
        i16 x = static_cast<u32>(position) >> 16;
        if (x > 31)
        {
            i16 dust_slot = (x >> 5) & 7;
            if ((core->dust_points[entry * 8 + dust_slot][HorseRaceDustX] & 0xFFE0) != (x & 0xFFE0))
                core->dust_points[entry * 8 + dust_slot][HorseRaceDustX] = x;
        }
    }
    // Count the runners ahead of each entry before recording its rank.
    i32 count;
    for (entry = 0; entry < 4; ++entry)
    {
        count = 0;
        for (i32 other = 0; other < 4; ++other)
            if (entry != other && positions[entry] > positions[other])
                ++count;
        order[count] = entry;
    }
    // Reuse the counter for runners that have cleared the finish area.
    count = 0;
    for (entry = 0; entry < 4; ++entry)
    {
        i32 const & index = order[entry];
        current = &core->runners[index];
        if (current->finishing_place == 0xFF)
        {
            if (current->x_fixed <= (184 << 16))
            {
                core->finishing_order[core->finish_count] = index;
                current->finishing_place = core->finish_count++;
                if (current->finishing_place == 0)
                {
                    HorseRaceSpriteState * sprite;
                    i32 animation;
                    switch (index)
                    {
                    case 0:
                        sprite = &core->runner_sprite_1;
                        animation = 0x76A;
                        break;
                    case 1:
                        sprite = &core->runner_sprite_2;
                        animation = 0x746;
                        break;
                    case 2:
                        if (!core->player_competes_this_round)
                        {
                            sprite = &core->runner_sprite_3;
                            animation = 0x752;
                        }
                        else
                        {
                            sprite = &core->player_runner_sprite;
                            animation = 0x776;
                        }
                        break;
                    case 3:
                        sprite = &core->runner_sprite_4;
                        animation = 0x75E;
                        break;
                    default:
                        continue;
                    }
                    ResolveIndexedResourceHandle(&sprite->resource, animation);
                    sprite->resource.scroll_delta = 256;
                }
            }
            else if (core->player_competes_this_round == 1 && index == 2)
            {
                if (static_cast<u8>(GetHardwarePressedKeys(reinterpret_cast<void * const *>(core))) & A_BUTTON)
                {
                    core->music_2.Start(0xA8);
                    if (current->stamina > 40)
                    {
                        switch (current->boost_phase)
                        {
                        case 1:
                        case 2:
                            break;
                        case 0:
                        case 4:
                            current->boost_phase = 1;
                            current->stamina -= 40;
                            break;
                        case 3:
                            current->timer += 60;
                            current->stamina -= 40;
                            break;
                        }
                    }
                }
            }
            else if (current->boost_phase == 0)
            {
                if (current->timer > 0)
                    --current->timer;
                else
                {
                    i32 probability_index = 0;
                    if (entry > 0 && positions[order[entry]] - positions[order[entry - 1]] > 0x1FFFFF)
                        probability_index = 1;
                    if (current->x_fixed <= 0x2FFFFFF)
                        probability_index += 2;
                    if (current->boost_probabilities[probability_index] > rand() % 100)
                    {
                        if (current->stamina > 39)
                        {
                            current->stamina -= 40;
                            current->boost_phase = 1;
                            if (!core->player_competes_this_round)
                                core->music_2.Start(0xA8);
                        }
                    }
                    else
                        current->timer = 12;
                }
            }
        }
        else if (current->x_fixed < 0)
        {
            current->speed = 0;
            ++count;
        }
    }
    if (core->player_competes_this_round == 1)
        nearest = positions[2];
    if (core->background_x[1] > 48)
    {
        nearest >>= 16;
        if (nearest < core->background_x[1] + 120)
        {
            core->background_x[1] = nearest - 120;
            if (core->background_x[1] < 48)
                core->background_x[1] = 48;
            core->background_x[0] = 1536 - (1536 - core->background_x[1]) * 2;
            core->background_x[2] = core->background_x[1];
        }
    }
    return count;
}

HorseRaceScene::HorseRaceScene(SceneTransitionOwner next, GameStateSaveImage * image, bool compete)
    : core(new HorseRaceCore(image, compete)), continuation(next)
{
}

HorseRaceScene::~HorseRaceScene()
{
}

SceneTransitionOwner HorseRaceScene::Run()
{
    core.value->Run();
    return continuation;
}
