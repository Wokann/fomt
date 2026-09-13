#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_HarvestGoddessRockPaperScissors_UnavailableIntroduction[] =
        "Ich wollte eigentlich\r\n"
        "Schere-Stein-Papier mit \r\n"
        "dir spielen... Aber nach \r\n"
        "alldem habe ich keine\r\n"
        "Lust mehr dazu. {Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_Instructions[] =
        "Dies ist eine \r\n"
        "Schere-Stein-Papier Show!\r\n"
        "Spielen wir, {Player}!{Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_Shared_PlayerAndGoddessCountdown[] =
        "Eins... Zwei... Drei!...{Press}\r\n";

    const char gText_TV_HarvestGoddessRockPaperScissors_ChoiceRock[] =
        "Schere";

    const char gText_TV_HarvestGoddessRockPaperScissors_ChoicePaper[] =
        "Stein";

    const char gText_TV_HarvestGoddessRockPaperScissors_ChoiceScissors[] =
        "Papier";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerRockGoddessRockDraw[] =
        "{Player}\r\n"
        "Stein        Stein\r\n"
        "            Erntegöttin{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerRockGoddessScissorsWin[] =
        "{Player}\r\n"
        "Stein        Schere\r\n"
        "            Erntegöttin{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerRockGoddessPaperLoss[] =
        "{Player}\r\n"
        "Stein        Papier\r\n"
        "            Erntegöttin {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerScissorsGoddessRockLoss[] =
        "{Player}\r\n"
        "Schere        Stein\r\n"
        "            Erntegöttin {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerScissorsGoddessScissorsDraw[] =
        "{Player}\r\n"
        "Schere        Schere\r\n"
        "            Erntegöttin {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerScissorsGoddessPaperWin[] =
        "{Player}\r\n"
        "Schere        Papier\r\n"
        "            Erntegöttin {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerPaperGoddessRockWin[] =
        "{Player}\r\n"
        "Papier        Stein\r\n"
        "            Erntegöttin {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerPaperGoddessScissorsLoss[] =
        "{Player}\r\n"
        "Papier        Schere\r\n"
        "            Erntegöttin {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerPaperGoddessPaperDraw[] =
        "{Player}\r\n"
        "Papier        Papier\r\n"
        "            Erntegöttin {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_RoundWin[] =
        "Ich habe verloren.\r\n"
        "Ich will Revanche! {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayAgainPrompt[] =
        "Ich will Revanche! {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_RoundLoss[] =
        "Ich habe gewonnen! {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_SessionEnded[] =
        "Tschüss dann. \r\n"
        "{Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_SeriesTied[] =
        "Jeder hat einmal \r\n"
        "gewonnen und verloren.\r\n"
        "Tschüss dann.{Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_GoddessLosesSeries[] =
        "Ich kann nicht fassen,\r\n"
        "dass ich mehr als 100 Mal \r\n"
        "am Stück verloren habe!! {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_WinningStreakAnnouncement[] =
        "Ich kann nicht fassen, dass \r\n"
        "ich {Var1} Mal am Stück\r\n"
        "verloren habe!{Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_RewardGranted[] =
        "Das hier gebe ich \r\n"
        "dir als Belohnung. {Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_RewardPostponedInventoryFull[] =
        "Ich wollte dir eine Beloh- \r\n"
        "nung geben, aber deine \r\n"
        "Hände sind voll. {Press}\p"
        "Zu schade, jetzt musst du \r\n"
        "bis zum nächsten Mal \r\n"
        "abwarten....{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_SessionEndedAfterReward[] =
        "Tschüss dann.\r\n"
        "{Press}";
};

void EventScript_TV_HarvestGoddessRockPaperScissors(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
    var_3 = 0;
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
    if (WasNpcSpokenToToday(CHARACTER_HARVEST_GODDESS) == TRUE)
    {
        var_4 = ShowTelevisionMessage(gText_TV_HarvestGoddessRockPaperScissors_UnavailableIntroduction);
        EndTelevisionProgram();
        TalkClose();
        switch (var_4)
        {
            case TELEVISION_INPUT_UP_WEATHER:
            case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
            case TELEVISION_INPUT_RIGHT_NEWS:
            case TELEVISION_INPUT_LEFT_VARIETY:
                VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_4);
                CallScript(EventScript_TV_EntertainmentChannel);
                break;
            case TELEVISION_INPUT_ADVANCE_TEXT:
            case TELEVISION_INPUT_TURN_OFF:
                break;
            mary_dead_jump:
        }
        return;
    }
    else
    {
        var_4 = ShowTelevisionMessage(gText_TV_HarvestGoddessRockPaperScissors_Instructions);
        TalkClose();
        switch (var_4)
        {
            case TELEVISION_INPUT_UP_WEATHER:
            case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
            case TELEVISION_INPUT_RIGHT_NEWS:
            case TELEVISION_INPUT_LEFT_VARIETY:
                VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_4);
                CallScript(EventScript_TV_EntertainmentChannel);
                break;
            case TELEVISION_INPUT_TURN_OFF:
                break;
            mary_dead_jump:
        }
        TalkOpen();
        do
        {
            switch (var_2)
            {
                case HARVEST_GODDESS_GAME_ROUND_WIN:
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                    TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_Shared_PlayerAndGoddessCountdown);
                    break;
                case HARVEST_GODDESS_GAME_ROUND_DRAW:
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                    TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_Shared_PlayerAndGoddessCountdown);
                    break;
            }
            var_0 = TalkChoice3(gText_TV_HarvestGoddessRockPaperScissors_ChoiceRock, gText_TV_HarvestGoddessRockPaperScissors_ChoicePaper, gText_TV_HarvestGoddessRockPaperScissors_ChoiceScissors);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    var_1 = RandomIntInclusive(0, 2);
                    switch (var_1)
                    {
                        case 0:
                            TalkOpen();
                            TalkAppendMessage(gText_TV_HarvestGoddessRockPaperScissors_PlayerRockGoddessRockDraw);
                            var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                            break;
                        case 1:
                            TalkOpen();
                            TalkAppendMessage(gText_TV_HarvestGoddessRockPaperScissors_PlayerRockGoddessScissorsWin);
                            var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                            break;
                        case 2:
                            TalkOpen();
                            TalkAppendMessage(gText_TV_HarvestGoddessRockPaperScissors_PlayerRockGoddessPaperLoss);
                            var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                            break;
                    }
                    break;
                case CHOICE_OPTION_2:
                    var_1 = RandomIntInclusive(0, 2);
                    switch (var_1)
                    {
                        case 0:
                            TalkOpen();
                            TalkAppendMessage(gText_TV_HarvestGoddessRockPaperScissors_PlayerScissorsGoddessRockLoss);
                            var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                            break;
                        case 1:
                            TalkOpen();
                            TalkAppendMessage(gText_TV_HarvestGoddessRockPaperScissors_PlayerScissorsGoddessScissorsDraw);
                            var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                            break;
                        case 2:
                            TalkOpen();
                            TalkAppendMessage(gText_TV_HarvestGoddessRockPaperScissors_PlayerScissorsGoddessPaperWin);
                            var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                            break;
                    }
                    break;
                case CHOICE_OPTION_3:
                    var_1 = RandomIntInclusive(0, 2);
                    switch (var_1)
                    {
                        case 0:
                            TalkOpen();
                            TalkAppendMessage(gText_TV_HarvestGoddessRockPaperScissors_PlayerPaperGoddessRockWin);
                            var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                            break;
                        case 1:
                            TalkOpen();
                            TalkAppendMessage(gText_TV_HarvestGoddessRockPaperScissors_PlayerPaperGoddessScissorsLoss);
                            var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                            break;
                        case 2:
                            TalkOpen();
                            TalkAppendMessage(gText_TV_HarvestGoddessRockPaperScissors_PlayerPaperGoddessPaperDraw);
                            var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                            break;
                    }
                    break;
            }
            switch (var_2)
            {
                case HARVEST_GODDESS_GAME_ROUND_WIN:
                    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
                    WaitFrames(30);
                    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
                    TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_RoundWin);
                    if (var_3 != 100)
                    {
                        var_3 = var_3 + 1;
                    }
                    break;
                case HARVEST_GODDESS_GAME_ROUND_DRAW:
                    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                    TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_PlayAgainPrompt);
                    break;
                case HARVEST_GODDESS_GAME_ROUND_LOSS:
                    PlaySong(AUDIO_START, AUDIO_SFX_INCORRECT_ANSWER);
                    WaitFrames(30);
                    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                    TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_RoundLoss);
                    break;
            }
        }
        while (var_2 == HARVEST_GODDESS_GAME_ROUND_WIN || var_2 == HARVEST_GODDESS_GAME_ROUND_DRAW);
        if (var_3 == 0)
        {
            TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_SessionEnded);
        }
        else
        {
            if (var_3 == 1)
            {
                SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_SeriesTied);
            }
            else
            {
                if (var_3 == 100)
                {
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
                    TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_GoddessLosesSeries);
                }
                else
                {
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
                    SetTextVariableNumber(TEXT_VARIABLE_1, var_3);
                    TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_WinningStreakAnnouncement);
                }
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                    TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_RewardGranted);
                    TalkClose();
                    if (var_3 == 100)
                    {
                        PlaySong(AUDIO_START, AUDIO_SFX_CEREMONIAL_CHIME);
                        SetPlayerHeldArticle(ITEM_ARTICLE_LOTTERY);
                        WaitFrames(330);
                    }
                    else
                    {
                        if (var_3 >= 90)
                        {
                            PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
                            SetPlayerHeldArticle(ITEM_ARTICLE_ALBUM_11);
                            WaitFrames(240);
                        }
                        else
                        {
                            if (var_3 >= 80)
                            {
                                PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
                                SetPlayerHeldArticle(ITEM_ARTICLE_ALBUM_12);
                                WaitFrames(240);
                            }
                            else
                            {
                                if (var_3 >= 70)
                                {
                                    PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
                                    SetPlayerHeldArticle(ITEM_ARTICLE_ALBUM_13);
                                    WaitFrames(240);
                                }
                                else
                                {
                                    if (var_3 >= 60)
                                    {
                                        PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
                                        SetPlayerHeldArticle(ITEM_ARTICLE_ALBUM_14);
                                        WaitFrames(240);
                                    }
                                    else
                                    {
                                        if (var_3 >= 50)
                                        {
                                            PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
                                            SetPlayerHeldArticle(ITEM_ARTICLE_ALBUM_15);
                                            WaitFrames(240);
                                        }
                                        else
                                        {
                                            if (var_3 >= 40)
                                            {
                                                PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                                SetPlayerHeldArticle(ITEM_ARTICLE_MYTHIC_STONE);
                                                WaitFrames(120);
                                            }
                                            else
                                            {
                                                if (var_3 >= 30)
                                                {
                                                    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                                    SetPlayerHeldArticle(ITEM_ARTICLE_PINK_DIAMOND);
                                                    WaitFrames(120);
                                                }
                                                else
                                                {
                                                    if (var_3 >= 20)
                                                    {
                                                        PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                                        SetPlayerHeldArticle(ITEM_ARTICLE_ALEXANDRITE);
                                                        WaitFrames(120);
                                                    }
                                                    else
                                                    {
                                                        if (var_3 >= 10)
                                                        {
                                                            PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                                            SetPlayerHeldFood(ITEM_FOOD_ELLI_LEAVES);
                                                            WaitFrames(120);
                                                        }
                                                        else
                                                        {
                                                            if (var_3 >= 3)
                                                            {
                                                                PlaySong(AUDIO_START, AUDIO_SFX_STAR_SPARKLE);
                                                                var_1 = RandomIntInclusive(0, 1);
                                                                switch (var_1)
                                                                {
                                                                    case 0:
                                                                        SetPlayerHeldFood(ITEM_FOOD_RICE_CAKE);
                                                                        break;
                                                                    case 1:
                                                                        SetPlayerHeldFood(ITEM_FOOD_BUCKWHEAT_FLOUR);
                                                                        break;
                                                                }
                                                                WaitFrames(60);
                                                            }
                                                            else
                                                            {
                                                                PlaySong(AUDIO_START, AUDIO_SFX_STAR_SPARKLE);
                                                                SetPlayerHeldFood(ITEM_FOOD_WHITE_GRASS);
                                                                WaitFrames(60);
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
                else
                {
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                    TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_RewardPostponedInventoryFull);
                }
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_SessionEndedAfterReward);
            }
        }
    }
    MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
    EndTelevisionProgram();
    TalkClose();
}
