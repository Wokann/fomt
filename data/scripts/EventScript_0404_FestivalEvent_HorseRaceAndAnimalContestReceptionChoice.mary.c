#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0404_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice.mary.h"

void EventScript_0404_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
    var_1 = VarGet(VAR_HOUR);
    var_2 = VarGet(VAR_MINUTE);
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
        {
            if (!(var_1 == 18 && var_2 == 1))
            {
                MarkNpcSpokenTo(CHARACTER_THOMAS);
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_AreYouReadyToRaceOr);
                TalkClose();
                TalkOpen();
                var_0 = TalkChoice4(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_BeginRace, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_PlaceABet, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Exchange, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Nothing);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureReadyToBegin);
                        TalkClose();
                        TalkOpen();
                        var_0 = TalkChoice2(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Yes, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_No);
                        switch (var_0)
                        {
                            case CHOICE_OPTION_1:
                                TalkClose();
                                TalkOpen();
                                SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsStartThen);
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_3 = RunHorseRace(FESTIVAL_HORSE_RACE_MODE_COMPETE);
                                switch (var_3)
                                {
                                    case FESTIVAL_HORSE_RACE_INTERFACE_CANCELLED:
                                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                        break;
                                    case FESTIVAL_HORSE_RACE_INTERFACE_CLOSED_WITHOUT_RESULT:
                                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                        PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
                                        break;
                                    case FESTIVAL_HORSE_RACE_INTERFACE_PLAYER_WON:
                                        if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                        {
                                            VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_WON);
                                            CallScript(EventScript_1098_FestivalEvent_SpringHorseRace_PlayerVictory);
                                        }
                                        else
                                        {
                                            VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_WON);
                                            CallScript(EventScript_1264_FestivalEvent_FallHorseRace_PlayerVictory);
                                        }
                                        break;
                                    case FESTIVAL_HORSE_RACE_INTERFACE_PLAYER_LOST:
                                        if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                        {
                                            VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                            CallScript(EventScript_1081_FestivalEvent_SpringHorseRace_Competition);
                                        }
                                        else
                                        {
                                            VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                            CallScript(EventScript_1247_FestivalEvent_FallHorseRace_Competition);
                                        }
                                        break;
                                }
                                break;
                            case CHOICE_OPTION_2:
                                TalkClose();
                                TalkOpen();
                                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureNotReadyAfterAll);
                                TalkClose();
                                break;
                        }
                        break;
                    case CHOICE_OPTION_2:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_BettingScreenSelectButtonInstructions);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_3 = RunHorseRace(FESTIVAL_HORSE_RACE_MODE_BETTING);
                        switch (var_3)
                        {
                            case FESTIVAL_HORSE_RACE_INTERFACE_CANCELLED:
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                break;
                            case FESTIVAL_HORSE_RACE_INTERFACE_CLOSED_WITHOUT_RESULT:
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
                                break;
                            case FESTIVAL_HORSE_RACE_INTERFACE_PLAYER_WON:
                                if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                {
                                    VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_WON);
                                    CallScript(EventScript_1098_FestivalEvent_SpringHorseRace_PlayerVictory);
                                }
                                else
                                {
                                    VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_WON);
                                    CallScript(EventScript_1264_FestivalEvent_FallHorseRace_PlayerVictory);
                                }
                                break;
                            case FESTIVAL_HORSE_RACE_INTERFACE_PLAYER_LOST:
                                if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                {
                                    VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                    CallScript(EventScript_1081_FestivalEvent_SpringHorseRace_Competition);
                                }
                                else
                                {
                                    VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                    CallScript(EventScript_1247_FestivalEvent_FallHorseRace_Competition);
                                }
                                break;
                        }
                        break;
                    case CHOICE_OPTION_3:
                        if (IsPlayerHoldingNothing() == TRUE)
                        {
                            TalkClose();
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_THOMAS);
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_HorseRaceMedalExchangePrompt);
#else
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_HorseRaceMedalExchangePrompt);
#endif
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            OpenHorseRaceMedalExchange();
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        }
                        else
                        {
                            TalkClose();
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_THOMAS);
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_ExchangeBlockedWhileHoldingItem);
#else
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_ExchangeBlockedWhileHoldingItem);
#endif
                            TalkClose();
                        }
                        break;
                    case CHOICE_OPTION_4:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureNotReadyAfterAll);
                        TalkClose();
                        break;
                }
            }
            else
            {
                MarkNpcSpokenTo(CHARACTER_THOMAS);
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_AnimalContestMedalExchangePrompt);
#else
                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_HorseRaceMedalExchangePrompt);
#endif
                TalkClose();
                TalkOpen();
                var_0 = TalkChoice2(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_MenuExchangeMedalsForPrizes, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Nothing);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        if (IsPlayerHoldingNothing() == TRUE)
                        {
                            TalkClose();
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_THOMAS);
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_HorseRaceMedalExchangePrompt);
#else
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_AnimalContestMedalExchangePrompt);
#endif
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            OpenHorseRaceMedalExchange();
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        }
                        else
                        {
                            TalkClose();
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_THOMAS);
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_ExchangeBlockedWhileHoldingItem);
#else
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_ExchangeBlockedWhileHoldingItem_2);
#endif
                            TalkClose();
                        }
                        break;
                    case CHOICE_OPTION_2:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureNotReadyAfterAll);
                        TalkClose();
                        break;
                }
            }
        }
        else
        {
            if (VarGet(VAR_COW_FESTIVAL_SESSION_STATE) == FESTIVAL_PHASE_INITIAL)
            {
                if (!(var_1 == 18 && var_2 == 1))
                {
                    var_4 = GetContestAnimalIndex(ANIMAL_KIND_COW);
                    if (HasMetNpc(CHARACTER_BARLEY) == FALSE)
                    {
                        MarkNpcSpokenTo(CHARACTER_BARLEY);
                    }
                    SetEntityFacing(ENTITY_BARLEY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_BARLEY);
                    TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_CowContestJudgingStartPrompt);
                    TalkClose();
                    TalkOpen();
                    var_0 = TalkChoice2(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetsStart, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_NotYet);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            TalkClose();
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_BARLEY);
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsGetStartedThen);
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
                            {
                                AddNpcFriendship(CHARACTER_BARLEY, 5);
                            }
                            MarkNpcSpokenTo(CHARACTER_BARLEY);
                            SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
                            if (GetAnimalAffection(ANIMAL_KIND_COW, var_4) >= 200)
                            {
                                VarSet(VAR_COW_FESTIVAL_PLAYER_RESULT, FESTIVAL_CONTEST_RESULT_WON);
                            }
                            if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
                            {
                                CallScript(EventScript_1190_FestivalEvent_CowFestival_PlayerVictory);
                            }
                            else
                            {
                                CallScript(EventScript_1177_FestivalEvent_CowFestival_PostJudgingSceneSetup);
                            }
                            break;
                        case CHOICE_OPTION_2:
                            TalkClose();
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_BARLEY);
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetMeKnowWhenYoureReady);
                            TalkClose();
                            if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
                            {
                                AddNpcFriendship(CHARACTER_BARLEY, 5);
                            }
                            MarkNpcSpokenTo(CHARACTER_BARLEY);
                            SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
                            break;
                    }
                }
                else
                {
                    TalkOpen();
                    TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Table);
                    TalkClose();
                }
            }
            else
            {
                if (VarGet(VAR_SHEEP_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                {
                    if (!(var_1 == 18 && var_2 == 1))
                    {
                        var_5 = GetContestAnimalIndex(ANIMAL_KIND_SHEEP);
                        if (HasMetNpc(CHARACTER_BARLEY) == FALSE)
                        {
                            MarkNpcSpokenTo(CHARACTER_BARLEY);
                        }
                        SetEntityFacing(ENTITY_BARLEY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_BARLEY);
#if defined(REGION_JP)
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SheepContestJudgingStartPrompt);
#else
#ifdef BUGFIX
                        // The shared overseas prompt names cows even at the sheep reception.
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SheepContestJudgingStartPrompt);
#else
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_CowContestJudgingStartPrompt);
#endif
#endif
                        TalkClose();
                        TalkOpen();
                        var_0 = TalkChoice2(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetsStart, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_NotYet);
                        switch (var_0)
                        {
                            case CHOICE_OPTION_1:
                                TalkClose();
                                TalkOpen();
                                SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsGetStartedThen);
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
                                {
                                    AddNpcFriendship(CHARACTER_BARLEY, 5);
                                }
                                MarkNpcSpokenTo(CHARACTER_BARLEY);
                                SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
                                if (GetAnimalAffection(ANIMAL_KIND_SHEEP, var_5) >= 200)
                                {
                                    VarSet(VAR_SHEEP_FESTIVAL_RESULT, FESTIVAL_CONTEST_RESULT_WON);
                                }
                                if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
                                {
                                    CallScript(EventScript_1289_FestivalEvent_SheepFestival_PlayerVictory);
                                }
                                else
                                {
                                    CallScript(EventScript_1277_FestivalEvent_SheepFestival_ClosingAnnouncement);
                                }
                                break;
                            case CHOICE_OPTION_2:
                                TalkClose();
                                TalkOpen();
                                SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetMeKnowWhenYoureReady);
                                TalkClose();
                                if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
                                {
                                    AddNpcFriendship(CHARACTER_BARLEY, 5);
                                }
                                MarkNpcSpokenTo(CHARACTER_BARLEY);
                                SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
                                break;
                        }
                    }
                    else
                    {
                        TalkOpen();
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Table);
                        TalkClose();
                    }
                }
                else
                {
                    TalkOpen();
                    TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Table);
                    TalkClose();
                }
            }
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Table);
        TalkClose();
    }
}
