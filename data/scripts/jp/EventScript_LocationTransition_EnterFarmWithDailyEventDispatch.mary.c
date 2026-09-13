#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterFarmWithDailyEventDispatch_TyphoonBlocksOutdoorTravel[] =
        "風が強すぎて外に出られない。{Press}";

    const char gText_LocationTransition_EnterFarmWithDailyEventDispatch_SnowstormBlocksOutdoorTravel[] =
        "雪が多すぎて外に出られない。{Press}";

    const char gText_LocationTransition_EnterFarmWithDailyEventDispatch_NickNameWhereAreYouGoing[] =
        "{NickName}、どこ行くの？{Press}";

    const char gText_LocationTransition_EnterFarmWithDailyEventDispatch_PlayerWhereAreYouGoing[] =
        "{Player}ちゃん、\r\n"
        "どこ行くの？{Press}";
};

void EventScript_LocationTransition_EnterFarmWithDailyEventDispatch(void)
{
    int unused_0, var_1, var_2, var_3, var_4, var_5, var_6;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_WEATHER_TODAY) == WEATHER_TYPHOON)
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterFarmWithDailyEventDispatch_TyphoonBlocksOutdoorTravel);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
            }
            MoveEntityYTo(ENTITY_PLAYER, Y(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            return;
        }
        if (VarGet(VAR_WEATHER_TODAY) == WEATHER_SNOWSTORM)
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterFarmWithDailyEventDispatch_SnowstormBlocksOutdoorTravel);
            TalkClose();
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
            }
            MoveEntityYTo(ENTITY_PLAYER, Y(200), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            return;
        }
        if (VarGet(VAR_POPURI_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            ShowTalkHeartIndicator(CHARACTER_POPURI);
            TalkMessage(gText_LocationTransition_EnterFarmWithDailyEventDispatch_NickNameWhereAreYouGoing);
            TalkClose();
            return;
        }
        else
        {
            if (VarGet(VAR_ANN_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_ANN);
                ShowTalkHeartIndicator(CHARACTER_ANN);
                TalkMessage(gText_LocationTransition_EnterFarmWithDailyEventDispatch_NickNameWhereAreYouGoing);
                TalkClose();
                return;
            }
            else
            {
                if (VarGet(VAR_ELLI_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_ELLI);
                    ShowTalkHeartIndicator(CHARACTER_ELLI);
                    TalkMessage(gText_LocationTransition_EnterFarmWithDailyEventDispatch_NickNameWhereAreYouGoing);
                    TalkClose();
                    return;
                }
                else
                {
                    if (VarGet(VAR_KAREN_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_KAREN_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_KAREN);
                        ShowTalkHeartIndicator(CHARACTER_KAREN);
                        TalkMessage(gText_LocationTransition_EnterFarmWithDailyEventDispatch_NickNameWhereAreYouGoing);
                        TalkClose();
                        return;
                    }
                    else
                    {
                        if (VarGet(VAR_MARY_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                        {
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_MARY);
                            ShowTalkHeartIndicator(CHARACTER_MARY);
                            TalkMessage(gText_LocationTransition_EnterFarmWithDailyEventDispatch_NickNameWhereAreYouGoing);
                            TalkClose();
                            return;
                        }
                        else
                        {
                            if (VarGet(VAR_HARVEST_GODDESS_ANNIVERSARY_AND_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                            {
                                TalkOpen();
                                SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                                SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                                TalkMessage(gText_LocationTransition_EnterFarmWithDailyEventDispatch_PlayerWhereAreYouGoing);
                                TalkClose();
                                return;
                            }
                            else
                            {
                                if (VarGet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                {
                                    DisableScriptedNpcControl();
                                    VarSet(VAR_POPURI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                    VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                                    VarSet(VAR_POPURI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                                }
                                else
                                {
                                    if (VarGet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                    {
                                        DisableScriptedNpcControl();
                                        VarSet(VAR_ANN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                                        VarSet(VAR_ANN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                        {
                                            DisableScriptedNpcControl();
                                            VarSet(VAR_ELLI_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                            VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                                            VarSet(VAR_ELLI_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                                            RemoveEventIcon(EVENT_ICON_SLOT_0);
                                            RemoveEventIcon(EVENT_ICON_SLOT_1);
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                            {
                                                DisableScriptedNpcControl();
                                                VarSet(VAR_KAREN_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                VarSet(VAR_KAREN_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                RemoveEventIcon(EVENT_ICON_SLOT_0);
                                                RemoveEventIcon(EVENT_ICON_SLOT_1);
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                                {
                                                    DisableScriptedNpcControl();
                                                    VarSet(VAR_MARY_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                    VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                    VarSet(VAR_MARY_FAMILY_EVENT_CHILD_STAGE_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                    RemoveEventIcon(EVENT_ICON_SLOT_0);
                                                    RemoveEventIcon(EVENT_ICON_SLOT_1);
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_FAMILY_EVENING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                                    {
                                                        DisableScriptedNpcControl();
                                                        VarSet(VAR_HARVEST_GODDESS_CHILD_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                        VarSet(VAR_HARVEST_GODDESS_FAMILY_EVENING_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                        VarSet(VAR_HARVEST_GODDESS_PLAYER_BIRTHDAY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                        RemoveEventIcon(EVENT_ICON_SLOT_0);
                                                        RemoveEventIcon(EVENT_ICON_SLOT_1);
                                                    }
                                                    else
                                                    {
                                                        if (VarGet(VAR_POPURI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                                        {
                                                            DisableScriptedNpcControl();
                                                            ClearEntityEventScript(ENTITY_POPURI);
                                                            ClearEntityEventScript(ENTITY_CHILD);
                                                            VarSet(VAR_POPURI_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                        }
                                                        else
                                                        {
                                                            if (VarGet(VAR_ANN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                                            {
                                                                DisableScriptedNpcControl();
                                                                ClearEntityEventScript(ENTITY_ANN);
                                                                ClearEntityEventScript(ENTITY_CHILD);
                                                                VarSet(VAR_ANN_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                            }
                                                            else
                                                            {
                                                                if (VarGet(VAR_ELLI_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                                                {
                                                                    DisableScriptedNpcControl();
                                                                    ClearEntityEventScript(ENTITY_ELLI);
                                                                    ClearEntityEventScript(ENTITY_CHILD);
                                                                    VarSet(VAR_ELLI_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                                }
                                                                else
                                                                {
                                                                    if (VarGet(VAR_KAREN_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                                                    {
                                                                        DisableScriptedNpcControl();
                                                                        ClearEntityEventScript(ENTITY_KAREN);
                                                                        ClearEntityEventScript(ENTITY_CHILD);
                                                                        VarSet(VAR_KAREN_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                                    }
                                                                    else
                                                                    {
                                                                        if (VarGet(VAR_MARY_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                                                        {
                                                                            DisableScriptedNpcControl();
                                                                            ClearEntityEventScript(ENTITY_MARY);
                                                                            ClearEntityEventScript(ENTITY_CHILD);
                                                                            VarSet(VAR_MARY_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                                        }
                                                                        else
                                                                        {
                                                                            if (VarGet(VAR_HARVEST_GODDESS_CHILD_FIRST_STEPS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                                                            {
                                                                                DisableScriptedNpcControl();
                                                                                ClearEntityEventScript(ENTITY_CHILD);
                                                                                VarSet(VAR_HARVEST_GODDESS_CHILD_FIRST_STEPS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_FARM, X(228), Y(120));
        SetEntityPosition(ENTITY_PLAYER, X(228), Y(120), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        var_1 = VarGet(VAR_SEASON);
        var_2 = VarGet(VAR_DAY);
        var_4 = VarGet(VAR_HOUR);
        var_3 = VarGet(VAR_DAY_OF_WEEK);
        var_5 = VarGet(VAR_WEATHER_TODAY);
        var_6 = VarGet(VAR_YEAR);
        if (VarGet(VAR_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_NOT_TRIGGERED && var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_17 && (var_4 >= 6 && var_4 < 12))
        {
            VarSet(VAR_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_IN_PROGRESS);
            CallScript(EventScript_FestivalEvent_HorseRace_EntryInvitation);
        }
        else
        {
            if (VarGet(VAR_COOKING_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_NOT_TRIGGERED && var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_21 && (var_4 >= 6 && var_4 < 12))
            {
                VarSet(VAR_COOKING_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_IN_PROGRESS);
                CallScript(EventScript_FestivalEvent_CookingFestival_Invitation);
            }
            else
            {
                if (VarGet(VAR_FRISBEE_TOURNAMENT_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_NOT_TRIGGERED && var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_30 && (var_4 >= 6 && var_4 < 12))
                {
                    VarSet(VAR_FRISBEE_TOURNAMENT_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_IN_PROGRESS);
                    CallScript(EventScript_FestivalEvent_FrisbeeTournament_DogEntryInvitation_Zack);
                }
                else
                {
                    if (VarGet(VAR_CHICKEN_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_NOT_TRIGGERED && var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_06 && (var_4 >= 6 && var_4 < 12))
                    {
                        VarSet(VAR_CHICKEN_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_IN_PROGRESS);
                        CallScript(EventScript_FestivalEvent_ChickenFestival_EntryInvitation);
                    }
                    else
                    {
                        if (VarGet(VAR_COW_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_NOT_TRIGGERED && var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_19 && (var_4 >= 6 && var_4 < 12))
                        {
                            VarSet(VAR_COW_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_IN_PROGRESS);
                            CallScript(EventScript_FestivalEvent_CowFestival_Invitation);
                        }
                        else
                        {
                            if (VarGet(VAR_MUSIC_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_NOT_TRIGGERED && var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_02 && (var_4 >= 6 && var_4 < 12))
                            {
                                VarSet(VAR_MUSIC_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_IN_PROGRESS);
                                CallScript(EventScript_FestivalEvent_MusicFestival_Invitation_Carter);
                            }
                            else
                            {
                                if (VarGet(VAR_HARVEST_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_NOT_TRIGGERED && var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_08 && (var_4 >= 6 && var_4 < 12))
                                {
                                    VarSet(VAR_HARVEST_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_IN_PROGRESS);
                                    CallScript(EventScript_FestivalEvent_HarvestFestival_Invitation);
                                }
                                else
                                {
                                    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_NOT_TRIGGERED && var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_17 && (var_4 >= 6 && var_4 < 12))
                                    {
                                        VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_IN_PROGRESS);
                                        CallScript(EventScript_FestivalEvent_FallHorseRace_Invitation);
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_SHEEP_FESTIVAL_INVITATION_EVENT_STATE) == FESTIVAL_INVITATION_NOT_TRIGGERED && var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_20 && (var_4 >= 6 && var_4 < 12))
                                        {
                                            VarSet(VAR_SHEEP_FESTIVAL_INVITATION_EVENT_STATE, FESTIVAL_INVITATION_IN_PROGRESS);
                                            CallScript(EventScript_FestivalEvent_SheepFestival_Invitation);
                                        }
                                        else
                                        {
                                            if (var_6 == 1 && VarGet(VAR_FARM_INTRODUCTION_AND_SHIPPING_TUTORIAL_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_02 && (var_4 >= 6 && var_4 < 12))
                                            {
                                                CallScript(EventScript_FarmEvent_FarmIntroduction_ShippingTutorial);
                                            }
                                            else
                                            {
                                                if (var_6 == 1 && VarGet(VAR_WON_INTRODUCTION_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_03 && (var_4 >= 6 && var_4 < 12))
                                                {
                                                    CallScript(EventScript_NPCEvent_Won_Introduction);
                                                }
                                                else
                                                {
                                                    if (var_6 >= 2 && VarGet(VAR_KAI_RETURN_GREETING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 && HasMetNpc(CHARACTER_KAI) == TRUE && (var_4 >= 6 && var_4 < 12))
                                                    {
                                                        CallScript(EventScript_NPCEvent_Kai_ReturnGreeting);
                                                    }
                                                    else
                                                    {
                                                        if (var_6 >= 2 && VarGet(VAR_KAI_LEAVES_AFTER_SUMMER_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_01 && HasMetNpc(CHARACTER_KAI) == TRUE && (var_4 >= 6 && var_4 < 12))
                                                        {
                                                            CallScript(EventScript_NPCEvent_Kai_LeavesAfterSummer);
                                                        }
                                                        else
                                                        {
                                                            if (var_6 == 1 && VarGet(VAR_DUKE_GRAPE_HARVEST_INVITATION_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_14 && (var_4 >= 6 && var_4 < 12))
                                                            {
                                                                CallScript(EventScript_NPCEvent_Duke_GrapeHarvestInvitation);
                                                            }
                                                            else
                                                            {
                                                                if (!(var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_30 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30) && VarGet(VAR_GOLDEN_LUMBER_WAS_ON_FARM_AT_DAY_START) == TRUE && HasGoldenLumberOnFarm() && (var_4 >= 6 && var_4 < 16))
                                                                {
                                                                    if (VarGet(VAR_GOLDEN_LUMBER_ANGER_EVENT_TODAY_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
                                                                    {
                                                                        CallScript(EventScript_NPCEvent_TownResidents_GoldenLumberAngerConfrontation);
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    if (VarGet(VAR_POPURI_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_30 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30) && (var_4 >= 6 && var_4 < 12) && var_5 == WEATHER_SUNNY && !(var_3 == DAY_OF_WEEK_SUNDAY) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_PURPLE_MIN && IsPlayerHoldingNothing() == TRUE)
                                                                    {
                                                                        VarSet(VAR_POPURI_PURPLE_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                                        CallScript(EventScript_LoveEvent_Popuri_02_PurpleHeart_VisitPlayerFarm);
                                                                    }
                                                                    else
                                                                    {
                                                                        if (GetPendingTVShoppingItem() != TV_SHOPPING_ITEM_NONE)
                                                                        {
                                                                            if (IsTVShoppingDeliveryReady() == TRUE)
                                                                            {
                                                                                if (VarGet(VAR_HOUR) >= 6 && VarGet(VAR_HOUR) < 12)
                                                                                {
                                                                                    switch (GetPendingTVShoppingItem())
                                                                                    {
                                                                                        case TV_SHOPPING_ITEM_CLOCK:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryClock);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_MIRROR:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryMirror);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_REFRIGERATOR:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryRefrigerator);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_SHELF:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryShelf);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_KITCHEN:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryKitchen);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_CARPET:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryCarpet);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_LARGE_BED:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryLargeBed);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_KNIFE:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryKnife);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_FRYING_PAN:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryFryingPan);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_POT:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryPot);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_MIXER:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryMixer);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_WHISK:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryWhisk);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_ROLLING_PIN:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryRollingPin);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_OVEN:
                                                                                            CallScript(EventScript_TV_Shopping_DeliveryOven);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_SEASONING_SET:
                                                                                            CallScript(EventScript_TV_Shopping_DeliverySeasoningSet);
                                                                                            break;
                                                                                        case TV_SHOPPING_ITEM_POWER_BERRY:
                                                                                            if (IsPlayerHoldingNothing() == TRUE)
                                                                                            {
                                                                                                CallScript(EventScript_TV_Shopping_DeliveryPowerBerry);
                                                                                            }
                                                                                            break;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            if (VarGet(VAR_VAN_INTRODUCTION_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_GAMECUBE_LINK_VAN_INTRODUCTION_AVAILABLE) == TRUE && var_3 == DAY_OF_WEEK_WEDNESDAY && var_5 == WEATHER_SUNNY && (var_4 >= 6 && var_4 < 12))
                                                                            {
                                                                                CallScript(EventScript_NPCEvent_Van_Introduction);
                                                                            }
                                                                            else
                                                                            {
                                                                                if (VarGet(VAR_LOU_OR_RUBY_INTRODUCTION_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_GAMECUBE_LINK_LOU_OR_RUBY_INTRODUCTION_AVAILABLE) == TRUE && var_3 == DAY_OF_WEEK_SUNDAY && var_5 == WEATHER_SUNNY && (var_4 >= 6 && var_4 < 12))
                                                                                {
                                                                                    CallScript(EventScript_NPCEvent_LouOrRuby_Introduction);
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (VarGet(VAR_THOMAS_RANDOM_ITEM_REQUEST_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_02 && (var_4 >= 6 && var_4 < 12))
                                                                                    {
                                                                                        CallScript(EventScript_NPCEvent_Thomas_RandomItemRequestChoice);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (!(var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_30 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30) && VarGet(VAR_HARRIS_AJA_LETTER_ADVICE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && var_5 == WEATHER_SUNNY && HasMetNpc(CHARACTER_HARRIS) == TRUE && GetEntityLocation(ENTITY_THOMAS) != MAP_FARM && GetNpcFriendship(CHARACTER_HARRIS) >= 200 && (var_4 >= 19 && var_4 < 21))
                                                                                        {
                                                                                            CallScript(EventScript_NPCEvent_Harris_AjaLetterAdviceChoice);
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (!(var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_30 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30) && VarGet(VAR_HARRIS_AJA_LETTER_ADVICE_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_HARRIS_AJA_LETTER_REJECTION_FOLLOWUP_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARRIS_AJA_LETTER_ADVICE_CHOICE) == HARRIS_AJA_LETTER_ADVICE_TELL_HER_FEELINGS && VarGet(VAR_DAYS_SINCE_HARRIS_AJA_LETTER_ADVICE) == 20 && GetEntityLocation(ENTITY_THOMAS) != MAP_FARM && var_5 == WEATHER_SUNNY && (var_4 >= 19 && var_4 < 21))
                                                                                            {
                                                                                                CallScript(EventScript_NPCEvent_Harris_AjaLetterRejection_FollowupHarrisDialogue);
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if (VarGet(VAR_WON_APPLE_CHALLENGE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_2 == DAY_OF_MONTH_04 && (var_4 >= 6 && var_4 < 12) && WasNpcSpokenToToday(CHARACTER_WON) == FALSE && IsPlayerHoldingNothing() == TRUE && GetMoney() >= 500)
                                                                                                {
                                                                                                    CallScript(EventScript_NPCEvent_Won_AppleChallenge);
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    if (VarGet(VAR_WON_VASE_PURCHASE_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_2 == DAY_OF_MONTH_11 && (var_4 >= 6 && var_4 < 12) && WasNpcSpokenToToday(CHARACTER_WON) == FALSE && VarGet(VAR_HAS_VASE) == FALSE && GetMoney() >= 5000)
                                                                                                    {
                                                                                                        CallScript(EventScript_NPCEvent_Won_VasePurchase);
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                        if (VarGet(VAR_ENTERED_FARMHOUSE_TODAY) == FALSE)
                                                                                                        {
                                                                                                            if (!(var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_30 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30) && VarGet(VAR_BARLEY_FOAL_OFFER_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && HasMetNpc(CHARACTER_BARLEY) == TRUE && var_1 == SEASON_SPRING && var_5 == WEATHER_SUNNY && (var_4 >= 6 && var_4 < 12))
                                                                                                            {
                                                                                                                CallScript(EventScript_FarmEvent_Foal_OfferToPlayer);
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                if (!(var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_30 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30) && VarGet(VAR_BARLEY_HORSE_YEAR_EVALUATION_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HORSE_GROWTH_STAGE) == ANIMAL_PET_GROWTH_STAGE_ADULT && var_5 == WEATHER_SUNNY && (var_4 >= 6 && var_4 < 12))
                                                                                                                {
                                                                                                                    CallScript(EventScript_FarmEvent_Horse_CareEvaluation);
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                    if (!(var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_30 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30) && VarGet(VAR_BARLEY_HORSE_YEAR_EVALUATION_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_BARLEY_REPLACEMENT_FOAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_DAYS_SINCE_FAILED_HORSE_YEAR_EVALUATION) == 120 && VarGet(VAR_HAS_HORSE) == FALSE && var_5 == WEATHER_SUNNY && (var_4 >= 6 && var_4 < 12))
                                                                                                                    {
                                                                                                                        CallScript(EventScript_FarmEvent_Foal_MoveIntoStable);
                                                                                                                    }
                                                                                                                    else
                                                                                                                    {
                                                                                                                        if (!(var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_SPRING && var_2 == DAY_OF_MONTH_22 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_01 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_07 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_SUMMER && var_2 == DAY_OF_MONTH_20 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_03 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_09 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_13 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_18 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_21 || var_1 == SEASON_FALL && var_2 == DAY_OF_MONTH_30 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_14 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_24 || var_1 == SEASON_WINTER && var_2 == DAY_OF_MONTH_30) && VarGet(VAR_ACHIEVEMENT_CAUGHT_EVERY_FISH_SPECIES_STATE) == ACHIEVEMENT_EVENT_COMPLETED && VarGet(VAR_ZACK_CONGRATULATES_CATCHING_EVERY_FISH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (var_4 >= 6 && var_4 < 12))
                                                                                                                        {
                                                                                                                            CallScript(EventScript_AchievementEvent_Fishing_CaughtEveryFishSpeciesZackCongratulations);
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
