#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_CookingFestivalCompetitionNotStartedExitWarning[] =
        "Wo willst du denn hin?{Press}\p"
        "Der Wettkampf hat noch  \r\n"
        "nicht angefangen!{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_CookingFestivalDepartureMealPlanning[] =
        "Hmm...Was mache ich?{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_CookingFestivalJudgingNotStartedExitWarning[] =
        "Die Auswertung hat\r\n"
        "noch nicht begonnen.{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_PlayerReturnsToWorkAfterFestival[] =
        "Das war ein Spaß!\r\n"
        "Zurück an die Arbeit...{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_NewYearRiceCakeFestivalNotStartedExitWarning[] =
        "Wo willst du denn hin?\r\n"
        "Das Neujahrsfestival \r\n"
        "hat noch nicht begonnen!{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_NewYearsEveNoodleFestivalNotFinishedExitWarning[] =
        "Was machst du denn?\r\n"
        "Wir haben nicht einmal die \r\n"
        "Jahresendnudeln gegessen!{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_HorseRaceStillInProgressExitWarning[] =
        "Es sind noch Rennen übrig.{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_ChickenFestivalStillInProgressExitWarning[] =
        "Wo willst du denn hin?\r\n"
        "Es hat noch nicht begonnen!{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_CowFestivalStillInProgressExitWarning[] =
        "Wo willst du denn hin?{Press}";

    const char gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_SheepFestivalStillInProgressExitWarning[] =
        "Das Schaffestival ist\r\n"
        "noch nicht zu Ende.{Press}";
};

void EventScript_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance(void)
{
    int var_0, var_1, var_2, var_3, unused_4, unused_5, unused_6, var_7;
    mary_nodisc(var_7 = 1);
    var_0 = VarGet(VAR_SEASON);
    var_1 = VarGet(VAR_DAY);
    var_2 = VarGet(VAR_HOUR);
    var_3 = VarGet(VAR_MINUTE);
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (VarGet(VAR_COOKING_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
        {
            if (WasNpcSpokenToToday(CHARACTER_GOURMET) == FALSE)
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_CookingFestivalCompetitionNotStartedExitWarning);
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
                TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_CookingFestivalDepartureMealPlanning);
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
                TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_CookingFestivalJudgingNotStartedExitWarning);
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
                        TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_PlayerReturnsToWorkAfterFestival);
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
                        TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_NewYearRiceCakeFestivalNotStartedExitWarning);
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
                            TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_NewYearsEveNoodleFestivalNotFinishedExitWarning);
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
                                    TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_HorseRaceStillInProgressExitWarning);
                                    TalkClose();
                                    var_7 = 0;
                                }
                                else
                                {
                                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                    TalkOpen();
                                    TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_PlayerReturnsToWorkAfterFestival);
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
                                        TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_ChickenFestivalStillInProgressExitWarning);
                                        TalkClose();
                                        var_7 = 0;
                                    }
                                    else
                                    {
                                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                        TalkOpen();
                                        TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_PlayerReturnsToWorkAfterFestival);
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
                                            TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_CowFestivalStillInProgressExitWarning);
                                            TalkClose();
                                            var_7 = 0;
                                        }
                                        else
                                        {
                                            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                            TalkOpen();
                                            TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_PlayerReturnsToWorkAfterFestival);
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
                                                TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_HorseRaceStillInProgressExitWarning);
                                                TalkClose();
                                                var_7 = 0;
                                            }
                                            else
                                            {
                                                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                                TalkOpen();
                                                TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_PlayerReturnsToWorkAfterFestival);
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
                                                    TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_SheepFestivalStillInProgressExitWarning);
                                                    TalkClose();
                                                    var_7 = 0;
                                                }
                                                else
                                                {
                                                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                                    TalkOpen();
                                                    TalkMessage(gText_FestivalEvent_TownSquareExitGuard_FromNorthTownEntrance_PlayerReturnsToWorkAfterFestival);
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
            ChangeMap(MAP_NORTH_SIDE_TOWN, X(1260), Y(680));
            SetEntityPosition(ENTITY_PLAYER, X(1260), Y(680), FACING_UP);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
            MoveEntityYTo(ENTITY_PLAYER, Y(60), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
        }
    }
}
