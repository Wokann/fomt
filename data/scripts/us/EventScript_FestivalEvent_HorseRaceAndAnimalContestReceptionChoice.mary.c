#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_AreYouReadyToRaceOr[] =
        "Are you ready to race, \r\n"
        "or do you want to place \r\n"
        "a bet or exchange a medal{Press}\r\n"
        "for a prize?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_BeginRace[] =
        "Begin race.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_PlaceABet[] =
        "Place a bet.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Exchange[] =
        "Exchange.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Nothing[] =
        "Nothing.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureReadyToBegin[] =
        "So you're ready to begin?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Yes[] =
        "Yes";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_No[] =
        "No";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsStartThen[] =
        "Great! \r\n"
        "Let's start, then.{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureNotReadyAfterAll[] =
        "So you're not ready\r\n"
        "after all, eh?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_BettingScreenSelectButtonInstructions[] =
        "Alright. Press SELECT ON \r\n"
        "the Betting Screen to see a\r\n"
        "description of how to {Press}\r\n"
        "do it. {Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureGoingToExchangeYour[] =
        "So you're going to exchange\r\n"
        "your medal, eh?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_YouCantDoItWhileHolding[] =
        "You can't do it while\r\n"
        "holding something. {Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_YouWantToExchangeYourMedal[] =
        "You want to exchange your \r\n"
        "medal for a prize?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_MenuExchangeMedalsForPrizes[] =
        "Exchange medal for prize.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Shared_CowAndSheepContestJudgingStartPrompt[] =
        "We want to begin judging the\r\n"
        "Cows now. \r\n"
        "Are you ready?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetsStart[] =
        "Let's start.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_NotYet[] =
        "Not yet.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsGetStartedThen[] =
        "Great. Let's get started,\r\n"
        "then!{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetMeKnowWhenYoureReady[] =
        "Let me know when \r\n"
        "you're ready, then.{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Table[] =
        "Table{Press}";
};

void EventScript_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice(void)
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
                                            CallScript(EventScript_FestivalEvent_SpringHorseRace_PlayerVictory);
                                        }
                                        else
                                        {
                                            VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_WON);
                                            CallScript(EventScript_FestivalEvent_FallHorseRace_PlayerVictory);
                                        }
                                        break;
                                    case FESTIVAL_HORSE_RACE_INTERFACE_PLAYER_LOST:
                                        if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                        {
                                            VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                            CallScript(EventScript_FestivalEvent_SpringHorseRace_Competition);
                                        }
                                        else
                                        {
                                            VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                            CallScript(EventScript_FestivalEvent_FallHorseRace_Competition);
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
                                    CallScript(EventScript_FestivalEvent_SpringHorseRace_PlayerVictory);
                                }
                                else
                                {
                                    VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_WON);
                                    CallScript(EventScript_FestivalEvent_FallHorseRace_PlayerVictory);
                                }
                                break;
                            case FESTIVAL_HORSE_RACE_INTERFACE_PLAYER_LOST:
                                if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                {
                                    VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                    CallScript(EventScript_FestivalEvent_SpringHorseRace_Competition);
                                }
                                else
                                {
                                    VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                    CallScript(EventScript_FestivalEvent_FallHorseRace_Competition);
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
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureGoingToExchangeYour);
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
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_YouCantDoItWhileHolding);
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
                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_YouWantToExchangeYourMedal);
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
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureGoingToExchangeYour);
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
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_YouCantDoItWhileHolding);
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
                    TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Shared_CowAndSheepContestJudgingStartPrompt);
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
                                CallScript(EventScript_FestivalEvent_CowFestival_PlayerVictory);
                            }
                            else
                            {
                                CallScript(EventScript_FestivalEvent_CowFestival_PostJudgingSceneSetup);
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
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Shared_CowAndSheepContestJudgingStartPrompt);
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
                                    CallScript(EventScript_FestivalEvent_SheepFestival_PlayerVictory);
                                }
                                else
                                {
                                    CallScript(EventScript_FestivalEvent_SheepFestival_ClosingAnnouncement);
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
