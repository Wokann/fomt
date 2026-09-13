#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_CookingFestivalCompetitionNotStartedExitWarning[] =
        "{Player}, \r\n"
        "where are you going?{Press}\p"
        "The competition hasn't\r\n"
        "started yet.{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_CookingFestivalDepartureMealPlanning[] =
        "Hmm...What should I make?{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_CookingFestivalJudgingNotStartedExitWarning[] =
        "The judging hasn't\r\n"
        "even begun yet.{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_PlayerReturnsToWorkAfterFestival[] =
        "That was fun!\r\n"
        "Now back to work...{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_NewYearRiceCakeFestivalNotStartedExitWarning[] =
        "Where are you going?\r\n"
        "The New Year Festival \r\n"
        "hasn't even started yet!{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_NewYearsEveNoodleFestivalNotFinishedExitWarning[] =
        "What are you doing?\r\n"
        "We haven't eaten the \r\n"
        "year end noodles yet!{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_HorseRaceStillInProgressExitWarning[] =
        "There are still races left.{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_ChickenFestivalStillInProgressExitWarning[] =
        "Where are you going?\r\n"
        "It hasn't started yet!{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_CowFestivalStillInProgressExitWarning[] =
        "Where are you going?{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_SheepFestivalStillInProgressExitWarning[] =
        "{Player},\r\n"
        "The Sheep Festival hasn't\r\n"
        "ended yet.{Press}";
};

void EventScript_FestivalEvent_TownSquareExitGuard_FromBeachEntrance(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6, var_7;
    mary_nodisc(var_7 = 1);
    var_0 = VarGet(VAR_SEASON);
    var_1 = VarGet(VAR_DAY);
    var_2 = VarGet(VAR_HOUR);
    var_6 = VarGet(VAR_YEAR);
    var_3 = VarGet(VAR_MINUTE);
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_RIGHT)
    {
        if (VarGet(VAR_COOKING_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
        {
            if (WasNpcSpokenToToday(CHARACTER_GOURMET) == FALSE)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_CookingFestivalCompetitionNotStartedExitWarning);
                TalkClose();
                var_7 = 0;
            }
            else
            {
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                VarSet(VAR_COOKING_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                ClearEntityEventScript(ENTITY_THOMAS);
                ClearEntityEventScript(ENTITY_DOCTOR);
                ClearEntityEventScript(ENTITY_CARTER);
                ClearEntityEventScript(ENTITY_GOURMET);
                ClearEntityEventScript(ENTITY_ZACK);
                ClearEntityEventScript(ENTITY_ANN);
                ClearEntityEventScript(ENTITY_GOTZ);
                ClearEntityEventScript(ENTITY_KAREN);
                ClearEntityEventScript(ENTITY_DOUG);
                ClearEntityEventScript(ENTITY_SASHA);
                ClearEntityEventScript(ENTITY_MANNA);
                ClearEntityEventScript(ENTITY_RICK);
                ClearEntityEventScript(ENTITY_LILLIA);
                DisableScriptedNpcControl();
                TalkOpen();
                TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_CookingFestivalDepartureMealPlanning);
                TalkClose();
                PlacePlayerAtFarmhouseBed();
                SetGameTime(12, 0);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                return;
            }
        }
        else
        {
            if (VarGet(VAR_COOKING_FESTIVAL_COMPLETED) == FESTIVAL_PHASE_INITIAL)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_CookingFestivalJudgingNotStartedExitWarning);
                TalkClose();
                var_7 = 0;
            }
            else
            {
                if (VarGet(VAR_HARVEST_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                {
                    if (VarGet(VAR_HARVEST_FESTIVAL_SESSION_PHASE) == HARVEST_FESTIVAL_SESSION_JUDGING_STARTED)
                    {
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        VarSet(VAR_HARVEST_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                        ClearEntityEventScript(ENTITY_THOMAS);
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CARTER);
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_GOTZ);
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_DOUG);
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_SASHA);
                        ClearEntityEventScript(ENTITY_ANNA);
                        ClearEntityEventScript(ENTITY_MANNA);
                        DisableScriptedNpcControl();
                        TalkOpen();
                        TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_PlayerReturnsToWorkAfterFestival);
                        TalkClose();
                        PlacePlayerAtFarmhouseBed();
                        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        return;
                    }
                    else
                    {
                        VarSet(VAR_HARVEST_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INACTIVE);
                        ClearEntityEventScript(ENTITY_THOMAS);
                        ClearEntityEventScript(ENTITY_ELLI);
                        ClearEntityEventScript(ENTITY_CARTER);
                        ClearEntityEventScript(ENTITY_ANN);
                        ClearEntityEventScript(ENTITY_GOTZ);
                        ClearEntityEventScript(ENTITY_KAREN);
                        ClearEntityEventScript(ENTITY_DOUG);
                        ClearEntityEventScript(ENTITY_MARY);
                        ClearEntityEventScript(ENTITY_SASHA);
                        ClearEntityEventScript(ENTITY_ANNA);
                        ClearEntityEventScript(ENTITY_MANNA);
                        DisableScriptedNpcControl();
                    }
                }
                else
                {
                    if (VarGet(VAR_NEW_YEAR_RICE_CAKE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_NewYearRiceCakeFestivalNotStartedExitWarning);
                        TalkClose();
                        var_7 = 0;
                    }
                    else
                    {
                        if (VarGet(VAR_NEW_YEARS_EVE_NOODLE_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                        {
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                            SetTalkNameplateCharacter(CHARACTER_THOMAS);
                            TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_NewYearsEveNoodleFestivalNotFinishedExitWarning);
                            TalkClose();
                            var_7 = 0;
                        }
                        else
                        {
                            if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                            {
                                if (!(var_2 == 18 && var_3 == 1))
                                {
                                    TalkOpen();
                                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                    TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_HorseRaceStillInProgressExitWarning);
                                    TalkClose();
                                    var_7 = 0;
                                }
                                else
                                {
                                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                    TalkOpen();
                                    TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_PlayerReturnsToWorkAfterFestival);
                                    TalkClose();
                                    DisableScriptedNpcControl();
                                    VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                                    ClearContestAnimal(ANIMAL_KIND_HORSE);
                                    VarSet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
                                    ClearEntityEventScript(ENTITY_RICK);
                                    ClearEntityEventScript(ENTITY_POPURI);
                                    ClearEntityEventScript(ENTITY_BARLEY);
                                    ClearEntityEventScript(ENTITY_MAY);
                                    ClearEntityEventScript(ENTITY_SAIBARA);
                                    ClearEntityEventScript(ENTITY_DUKE);
                                    ClearEntityEventScript(ENTITY_MANNA);
                                    ClearEntityEventScript(ENTITY_THOMAS);
                                    ClearEntityEventScript(ENTITY_HARRIS);
                                    ClearEntityEventScript(ENTITY_JEFF);
                                    ClearEntityEventScript(ENTITY_SASHA);
                                    ClearEntityEventScript(ENTITY_KAREN);
                                    ClearEntityEventScript(ENTITY_DOUG);
                                    ClearEntityEventScript(ENTITY_ANN);
                                    ClearEntityEventScript(ENTITY_ZACK);
                                    PlacePlayerAtFarmhouseBed();
                                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                                    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                    return;
                                }
                            }
                            else
                            {
                                if (VarGet(VAR_CHICKEN_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                {
                                    if (!(var_2 == 18 && var_3 == 1))
                                    {
                                        TalkOpen();
                                        SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
                                        SetTalkNameplateCharacter(CHARACTER_RICK);
                                        TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_ChickenFestivalStillInProgressExitWarning);
                                        TalkClose();
                                        var_7 = 0;
                                    }
                                    else
                                    {
                                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                        TalkOpen();
                                        TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_PlayerReturnsToWorkAfterFestival);
                                        TalkClose();
                                        DisableScriptedNpcControl();
                                        VarSet(VAR_CHICKEN_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                                        ClearContestAnimal(ANIMAL_KIND_CHICKEN);
                                        VarSet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
                                        ClearEntityEventScript(ENTITY_RICK);
                                        ClearEntityEventScript(ENTITY_BARLEY);
                                        ClearEntityEventScript(ENTITY_SAIBARA);
                                        ClearEntityEventScript(ENTITY_DUKE);
                                        ClearEntityEventScript(ENTITY_THOMAS);
                                        ClearEntityEventScript(ENTITY_POPURI);
                                        ClearEntityEventScript(ENTITY_DOUG);
                                        PlacePlayerAtFarmhouseBed();
                                        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                                        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                        return;
                                    }
                                }
                                else
                                {
                                    if (VarGet(VAR_COW_FESTIVAL_SESSION_STATE) == FESTIVAL_PHASE_INITIAL)
                                    {
                                        if (!(var_2 == 18 && var_3 == 1))
                                        {
                                            TalkOpen();
                                            SetTalkPortrait(TALK_PORTRAIT_BARLEY_AFRAID);
                                            SetTalkNameplateCharacter(CHARACTER_BARLEY);
                                            TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_CowFestivalStillInProgressExitWarning);
                                            TalkClose();
                                            var_7 = 0;
                                        }
                                        else
                                        {
                                            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                            TalkOpen();
                                            TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_PlayerReturnsToWorkAfterFestival);
                                            TalkClose();
                                            DisableScriptedNpcControl();
                                            VarSet(VAR_COW_FESTIVAL_SESSION_STATE, FESTIVAL_PHASE_ADVANCED);
                                            ClearContestAnimal(ANIMAL_KIND_COW);
                                            VarSet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
                                            ClearEntityEventScript(ENTITY_RICK);
                                            ClearEntityEventScript(ENTITY_POPURI);
                                            ClearEntityEventScript(ENTITY_BARLEY);
                                            ClearEntityEventScript(ENTITY_MAY);
                                            ClearEntityEventScript(ENTITY_BASIL);
                                            ClearEntityEventScript(ENTITY_MARY);
                                            ClearEntityEventScript(ENTITY_THOMAS);
                                            ClearEntityEventScript(ENTITY_STU);
                                            ClearEntityEventScript(ENTITY_DOCTOR);
                                            ClearEntityEventScript(ENTITY_ELLI);
                                            ClearEntityEventScript(ENTITY_CARTER);
                                            HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1);
                                            HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2);
                                            HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3);
                                            ClearEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1);
                                            ClearEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2);
                                            ClearEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3);
                                            PlacePlayerAtFarmhouseBed();
                                            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                                            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                            return;
                                        }
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                        {
                                            if (!(var_2 == 18 && var_3 == 1))
                                            {
                                                TalkOpen();
                                                SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                                                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                                TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_HorseRaceStillInProgressExitWarning);
                                                TalkClose();
                                                var_7 = 0;
                                            }
                                            else
                                            {
                                                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                                TalkOpen();
                                                TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_PlayerReturnsToWorkAfterFestival);
                                                TalkClose();
                                                DisableScriptedNpcControl();
                                                VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                                                ClearContestAnimal(ANIMAL_KIND_HORSE);
                                                VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
                                                ClearEntityEventScript(ENTITY_THOMAS);
                                                ClearEntityEventScript(ENTITY_BARLEY);
                                                ClearEntityEventScript(ENTITY_SAIBARA);
                                                ClearEntityEventScript(ENTITY_ZACK);
                                                ClearEntityEventScript(ENTITY_GOTZ);
                                                ClearEntityEventScript(ENTITY_GRAY);
                                                ClearEntityEventScript(ENTITY_MARY);
                                                ClearEntityEventScript(ENTITY_DOUG);
                                                ClearEntityEventScript(ENTITY_ELLI);
                                                ClearEntityEventScript(ENTITY_DOCTOR);
                                                ClearEntityEventScript(ENTITY_CARTER);
                                                ClearEntityEventScript(ENTITY_LILLIA);
                                                ClearEntityEventScript(ENTITY_RICK);
                                                ClearEntityEventScript(ENTITY_HARRIS);
                                                ClearEntityEventScript(ENTITY_DUKE);
                                                PlacePlayerAtFarmhouseBed();
                                                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                                                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                                return;
                                            }
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_SHEEP_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                            {
                                                if (!(var_2 == 18 && var_3 == 1))
                                                {
                                                    TalkOpen();
                                                    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                                                    SetTalkNameplateCharacter(CHARACTER_BARLEY);
                                                    TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_SheepFestivalStillInProgressExitWarning);
                                                    TalkClose();
                                                    var_7 = 0;
                                                }
                                                else
                                                {
                                                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                                    TalkOpen();
                                                    TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromBeachEntrance_PlayerReturnsToWorkAfterFestival);
                                                    TalkClose();
                                                    DisableScriptedNpcControl();
                                                    VarSet(VAR_SHEEP_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                                                    ClearContestAnimal(ANIMAL_KIND_SHEEP);
                                                    VarSet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED, FESTIVAL_PLAYER_ENTRY_NOT_SELECTED);
                                                    ClearEntityEventScript(ENTITY_RICK);
                                                    ClearEntityEventScript(ENTITY_KAREN);
                                                    ClearEntityEventScript(ENTITY_BARLEY);
                                                    ClearEntityEventScript(ENTITY_MAY);
                                                    ClearEntityEventScript(ENTITY_HARRIS);
                                                    ClearEntityEventScript(ENTITY_ANNA);
                                                    ClearEntityEventScript(ENTITY_THOMAS);
                                                    ClearEntityEventScript(ENTITY_GOTZ);
                                                    ClearEntityEventScript(ENTITY_GRAY);
                                                    ClearEntityEventScript(ENTITY_JEFF);
                                                    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1);
                                                    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2);
                                                    HideEntity(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3);
                                                    ClearEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1);
                                                    ClearEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2);
                                                    ClearEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3);
                                                    PlacePlayerAtFarmhouseBed();
                                                    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                                                    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                                    return;
                                                }
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_MANNA_AJAS_DEPARTURE_ADVICE_FROM_FRIENDS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                                {
                                                    VarSet(VAR_MANNA_AJAS_DEPARTURE_ADVICE_FROM_FRIENDS_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                                    ClearEntityEventScript(ENTITY_SASHA);
                                                    ClearEntityEventScript(ENTITY_ANNA);
                                                    ClearEntityEventScript(ENTITY_MANNA);
                                                    DisableScriptedNpcControl();
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
        if (var_7)
        {
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
            SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
            var_0 = VarGet(VAR_SEASON);
            var_1 = VarGet(VAR_DAY);
            var_2 = VarGet(VAR_HOUR);
            var_4 = VarGet(VAR_DAY_OF_WEEK);
            var_5 = VarGet(VAR_WEATHER_TODAY);
            var_6 = VarGet(VAR_YEAR);
            if (VarGet(VAR_BEACH_DAY_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01)
            {
                if (var_2 >= 6 && var_2 < 10)
                {
                    CallScript(EventScript_FestivalEvent_BeachDay_DayAnnouncement_WestEntrance);
                }
                if (var_2 >= 10 && var_2 < 18)
                {
                    VarSet(VAR_BEACH_DAY_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
                    CallScript(EventScript_FestivalEvent_FrisbeeTournament_Opening);
                }
            }
            else
            {
                if (VarGet(VAR_FIREWORKS_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INACTIVE && var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24)
                {
                    if (var_2 >= 18 && var_2 < 21)
                    {
                        VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
                        CallScript(EventScript_FestivalEvent_FireworksFestival_Opening);
                    }
                }
                else
                {
                    if (VarGet(VAR_ELLI_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30) && var_4 == DAY_OF_WEEK_WEDNESDAY && var_5 == WEATHER_SUNNY && (var_2 >= 9 && var_2 < 18) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetEntityLocation(ENTITY_POPURI) != MAP_MINERAL_BEACH && GetEntityLocation(ENTITY_KAI) != MAP_MINERAL_BEACH && GetEntityLocation(ENTITY_ZACK) != MAP_MINERAL_BEACH && GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_YELLOW_MIN && IsPlayerHoldingNothing() == TRUE)
                    {
                        VarSet(VAR_ELLI_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                        CallScript(EventScript_LoveEvent_Elli_04_YellowHeart_DiscussRaisingStu);
                    }
                    else
                    {
                        if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30) && var_0 == SEASON_SUMMER && var_4 == DAY_OF_WEEK_SUNDAY && var_5 == WEATHER_SUNNY && (var_2 >= 13 && var_2 < 16) && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_PURPLE_MIN && GetEntityLocation(ENTITY_ZACK) != MAP_MINERAL_BEACH && GetEntityLocation(ENTITY_POPURI) == MAP_MINERAL_BEACH && GetEntityLocation(ENTITY_KAI) == MAP_MINERAL_BEACH && HasMetNpc(CHARACTER_POPURI) == TRUE && HasMetNpc(CHARACTER_KAI) == TRUE)
                        {
                            VarSet(VAR_POPURI_KAI_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia);
                        }
                        else
                        {
                            if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_KAI_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30) && var_0 == SEASON_SUMMER && (var_4 == DAY_OF_WEEK_TUESDAY || var_4 == DAY_OF_WEEK_THURSDAY || var_4 == DAY_OF_WEEK_SATURDAY) && var_5 == WEATHER_SUNNY && (var_2 >= 9 && var_2 < 19) && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_GREEN_MIN && GetEntityLocation(ENTITY_ZACK) != MAP_MINERAL_BEACH)
                            {
                                VarSet(VAR_POPURI_KAI_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                CallScript(EventScript_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation);
                            }
                            else
                            {
                                if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_KAI_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30) && var_6 >= 2 && var_0 == SEASON_SUMMER && var_4 == DAY_OF_WEEK_SUNDAY && var_5 == WEATHER_SUNNY && (var_2 >= 13 && var_2 < 16) && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_YELLOW_MIN && GetEntityLocation(ENTITY_ZACK) != MAP_MINERAL_BEACH && GetEntityLocation(ENTITY_POPURI) == MAP_MINERAL_BEACH && GetEntityLocation(ENTITY_KAI) == MAP_MINERAL_BEACH)
                                {
                                    VarSet(VAR_POPURI_KAI_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                    CallScript(EventScript_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict);
                                }
                                else
                                {
                                    if (VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_SPRING && var_1 == DAY_OF_MONTH_22 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_01 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_07 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_SUMMER && var_1 == DAY_OF_MONTH_20 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_03 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_09 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_13 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_18 || var_0 == SEASON_FALL && var_1 == DAY_OF_MONTH_21 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_24 || var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_30) && var_6 >= 4 && var_4 == DAY_OF_WEEK_WEDNESDAY && var_5 == WEATHER_SUNNY && (var_2 >= 19 && var_2 < 22) && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_RED_MIN && GetEntityLocation(ENTITY_ZACK) != MAP_MINERAL_BEACH)
                                    {
                                        VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                        CallScript(EventScript_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession);
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_RICK_CONFRONTS_KAI_ABOUT_POPURI_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) != EVENT_LIFECYCLE_COMPLETED && var_0 == SEASON_SUMMER && var_4 != DAY_OF_WEEK_SUNDAY && (var_2 >= 13 && var_2 < 17) && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && GetEntityLocation(ENTITY_ZACK) != MAP_MINERAL_BEACH)
                                        {
                                            VarSet(VAR_RICK_CONFRONTS_KAI_ABOUT_POPURI_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                            CallScript(EventScript_NPCEvent_Rick_ConfrontsKaiAboutPopuri);
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_CLIFF_LEAVES_MINERAL_TOWN_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == FALSE && var_6 == 1 && var_0 == SEASON_WINTER && var_1 == DAY_OF_MONTH_29 && (var_2 >= 6 && var_2 < 12) && GetEntityLocation(ENTITY_ZACK) != MAP_MINERAL_BEACH)
                                            {
                                                VarSet(VAR_CLIFF_LEAVES_MINERAL_TOWN_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                                                CallScript(EventScript_NPCEvent_Cliff_LeavesMineralTown);
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
        else
        {
            SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
            MoveEntityXTo(ENTITY_PLAYER, X(420), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
        }
    }
}
