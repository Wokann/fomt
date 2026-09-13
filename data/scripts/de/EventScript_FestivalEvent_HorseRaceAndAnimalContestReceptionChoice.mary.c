#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_AreYouReadyToRaceOr[] =
        "Bist du bereit zum Rennen, \r\n"
        "willst du eine Wette ab- \r\n"
        "schließen oder eine{Press}\r\n"
        "Medaille gegen einen \r\n"
        "Preis eintauschen?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_BeginRace[] =
        "Rennstart.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_PlaceABet[] =
        "Wetten.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Exchange[] =
        "Preistausch.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Nothing[] =
        "Nichts.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureReadyToBegin[] =
        "Bist du bereit?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Yes[] =
        "Ja";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_No[] =
        "Nein";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsStartThen[] =
        "Super! \r\n"
        "Fangen wir an.{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureNotReadyAfterAll[] =
        "Also du bist noch\r\n"
        "nicht fertig, was?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_BettingScreenSelectButtonInstructions[] =
        "Ok. Drück SELECT auf dem\r\n"
        "Wettfenster für{Press}\r\n"
        "die Beschrei-\r\n"
        "bung, wie man Wetten {Press}\r\n"
        "platziert. {Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_HorseRaceMedalExchangePrompt[] =
        "Du willst also deine\r\n"
        "Medaille tauschen, was?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_HorseRaceExchangeBlockedWhileHoldingItem[] =
        "Du kannst es nicht tun,\r\n"
        "solange du etwas hältst. {Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_MenuExchangeMedalsForPrizes[] =
        "Medaille gegen Preis.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_AnimalContestMedalExchangePrompt[] =
        "Du willst deine Medaille \r\n"
        "gegen einen Preis tauschen?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_AnimalContestExchangeBlockedWhileHoldingItem[] =
        "Du kannst es nicht tun,\r\n"
        "solange du etwas hältst.{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Shared_CowAndSheepContestJudgingStartPrompt[] =
        "Wir wollen jetzt die\r\n"
        "Kühe bewerten. \r\n"
        "Bist du fertig?{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetsStart[] =
        "Los geht's.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_NotYet[] =
        "Noch nicht.";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsGetStartedThen[] =
        "Super. Dann mal\r\n"
        "los!{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetMeKnowWhenYoureReady[] =
        "Sag Bescheid, wenn\r\n"
        "du soweit bist.{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Table[] =
        "Tisch{Press}";
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
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_HorseRaceMedalExchangePrompt);
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
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_HorseRaceExchangeBlockedWhileHoldingItem);
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
                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_HorseRaceMedalExchangePrompt);
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
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_AnimalContestMedalExchangePrompt);
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
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_AnimalContestExchangeBlockedWhileHoldingItem);
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
