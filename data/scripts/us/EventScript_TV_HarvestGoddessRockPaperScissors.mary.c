#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_HarvestGoddessRockPaperScissors_UnavailableIntroduction[] =
        "I was going to play\r\n"
        "Rock-Papers-Scissors with \r\n"
        "you...But I don't feel like\r\n"
        "it today after all. {Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_Instructions[] =
        "This is a \r\n"
        "Rock-Paper-Scissors show!\r\n"
        "Let's play, {Player}.{Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerCountdown[] =
        "One...Two...Three!...{Press}\r\n";

    const char gText_TV_HarvestGoddessRockPaperScissors_GoddessCountdown[] =
        "One...Two...Three...{Press}\r\n";

    const char gText_TV_HarvestGoddessRockPaperScissors_ChoiceRock[] =
        "Rock";

    const char gText_TV_HarvestGoddessRockPaperScissors_ChoicePaper[] =
        "Paper";

    const char gText_TV_HarvestGoddessRockPaperScissors_ChoiceScissors[] =
        "Scissors";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerRockGoddessRockDraw[] =
        "{Player}\r\n"
        "Rock　　　　　　　　Rock\r\n"
        "　　　　　　 Harvest Goddess{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerRockGoddessScissorsWin[] =
        "{Player}\r\n"
        "Rock　　　　　　    Scissors\r\n"
        "　　　　　　 Harvest Goddess{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerRockGoddessPaperLoss[] =
        "{Player}\r\n"
        "Rock  　　　　　　　　 Paper\r\n"
        "　　　       Harvest Goddess{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerScissorsGoddessRockLoss[] =
        "{Player}\r\n"
        "Scissors　　　　　　　　Rock\r\n"
        "　　　　　　 Harvest Goddess{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerScissorsGoddessScissorsDraw[] =
        "{Player}\r\n"
        "Scissors　　　　　　Scissors\r\n"
        "　　　       Harvest Goddess{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerScissorsGoddessPaperWin[] =
        "{Player}\r\n"
        "Scissors 　　　　　　　Paper\r\n"
        "　　　　　　 Harvest Goddess{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerPaperGoddessRockWin[] =
        "{Player}\r\n"
        "Paper　　　　　　　　Rock\r\n"
        "　　　　　   Harvest Goddess{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerPaperGoddessScissorsLoss[] =
        "{Player}\r\n"
        "Paper 　　　　　　　Scissors\r\n"
        "　　　　　　 Harvest Goddess{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayerPaperGoddessPaperDraw[] =
        "{Player}\r\n"
        "Paper　　　　　　　　Paper\r\n"
        "　　　　     Harvest Goddess{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_RoundWin[] =
        "I lost this time.\r\n"
        "Give me a rematch! {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_PlayAgainPrompt[] =
        "Again, again! {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_RoundLoss[] =
        "I won! {Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_SessionEnded[] =
        "Bye now. \r\n"
        "{Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_SeriesTied[] =
        "It's one win, one loss for \r\n"
        "each of us.\r\n"
        "Bye now.{Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_GoddessLosesSeries[] =
        "I can't believe I lost\r\n"
        "more than 100 times in \r\n"
        "a row!!...{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_WinningStreakAnnouncement[] =
        "I can't believe I've lost \r\n"
        "{Var1} times \r\n"
        "in a row!{Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_RewardGranted[] =
        "I'll give you this \r\n"
        "as a reward. {Press}";

    const char gText_TV_HarvestGoddessRockPaperScissors_RewardPostponedInventoryFull[] =
        "I was going to give you \r\n"
        "something as a reward, but \r\n"
        "your hands are full. {Press}\p"
        "Too bad, but you'll have to \r\n"
        "wait until next time....{Press}\p";

    const char gText_TV_HarvestGoddessRockPaperScissors_SessionEndedAfterReward[] =
        "Bye now.\r\n"
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
                    TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_PlayerCountdown);
                    break;
                case HARVEST_GODDESS_GAME_ROUND_DRAW:
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                    TalkMessage(gText_TV_HarvestGoddessRockPaperScissors_GoddessCountdown);
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
