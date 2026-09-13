#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_HarvestGoddessNumberGuessing_DailySessionEnded[] =
        "That's it for today.\r\n"
        "Bye now.{Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_Instructions[] =
        "This is a New Year's \r\n"
        "game show. \r\n"
        "First I'll show you a \r\n"
        "number, then you guess \r\n"
        "whether the next number \r\n"
        "will be higher or lower.\r\n"
        "Got it?{Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_NumberDisplay[] =
        "{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}\r\n"
        "{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}\r\n"
        "{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Var2}{Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_InitialOrSharedComparisonPrompt[] =
        "Compared to {Var2}, it's";

    const char gText_TV_HarvestGoddessNumberGuessing_ChoiceHigher[] =
        "Larger";

    const char gText_TV_HarvestGoddessNumberGuessing_ChoiceLower[] =
        "Smaller";

    const char gText_TV_HarvestGoddessNumberGuessing_NextNumberDisplay[] =
        "{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}\r\n"
        "{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}\r\n"
        "{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Var1}{Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_CorrectHigherResult[] =
        "The first number was {Var2},\r\n"
        "and the second was {Var1}.\r\n"
        "You chose \"Larger,\" so...{Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_CorrectLowerResult[] =
        "The first number was {Var2},\r\n"
        "and the second was {Var1}.\r\n"
        "You chose \"Smaller,\" so...{Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_CorrectContinuePrompt[] =
        "Correct! {Press}\p"
        "Once more, now.{Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_EqualContinuePrompt[] =
        "Same number! {Press}\p"
        "Once more, now. {Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_IncorrectGameOver[] =
        "Incorrect! {Press}\p"
        "Sorry, game over... {Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_SessionEnded[] =
        "Bye now.\r\n"
        "{Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_SingleWinSessionEnded[] =
        "You only won once.\r\n"
        "Bye now. {Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_TenWinsAnnouncement[] =
        "Wow!\r\n"
        "I can't believe you've \r\n"
        "won over 100{Press}\r\n"
        "times in a row!{Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_WinningStreakAnnouncement[] =
        "I'm impressed!\r\n"
        "You've won {Var1}\r\n"
        "times in a row!{Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_RewardGranted[] =
        "I'll give you this \r\n"
        "as a reward. {Press}";

    const char gText_TV_HarvestGoddessNumberGuessing_RewardPostponedInventoryFull[] =
        "I was going to give you \r\n"
        "something as a reward, but \r\n"
        "your hands are full. {Press}\p"
        "Too bad, but you'll have to \r\n"
        "wait until next time....{Press}\p";
};

void EventScript_TV_HarvestGoddessNumberGuessing(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5, var_6, var_7;
    var_6 = FALSE;
    var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
    var_3 = 0;
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
    if (VarGet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS) >= 5)
    {
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
        var_7 = ShowTelevisionMessage(gText_TV_HarvestGoddessNumberGuessing_DailySessionEnded);
        EndTelevisionProgram();
        TalkClose();
        switch (var_7)
        {
            case TELEVISION_INPUT_UP_WEATHER:
            case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
            case TELEVISION_INPUT_RIGHT_NEWS:
            case TELEVISION_INPUT_LEFT_VARIETY:
                VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_7);
                CallScript(EventScript_TV_ChannelDispatcher);
                break;
            case TELEVISION_INPUT_TURN_OFF:
                break;
            mary_dead_jump:
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
        var_7 = ShowTelevisionMessage(gText_TV_HarvestGoddessNumberGuessing_Instructions);
        TalkClose();
        switch (var_7)
        {
            case TELEVISION_INPUT_UP_WEATHER:
            case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
            case TELEVISION_INPUT_RIGHT_NEWS:
            case TELEVISION_INPUT_LEFT_VARIETY:
                VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_7);
                CallScript(EventScript_TV_ChannelDispatcher);
                break;
            case TELEVISION_INPUT_TURN_OFF:
                break;
            mary_dead_jump:
        }
        do
        {
            if (var_6 == FALSE)
            {
                TalkOpen();
                var_4 = RandomIntInclusive(0, 9);
                SetTextVariableNumber(TEXT_VARIABLE_2, var_4);
                TalkAppendMessage(gText_TV_HarvestGoddessNumberGuessing_NumberDisplay);
                var_0 = TalkPromptChoice2(gText_TV_HarvestGoddessNumberGuessing_InitialOrSharedComparisonPrompt, gText_TV_HarvestGoddessNumberGuessing_ChoiceHigher, gText_TV_HarvestGoddessNumberGuessing_ChoiceLower);
                var_6 = TRUE;
            }
            else
            {
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                var_4 = var_1;
                SetTextVariableNumber(TEXT_VARIABLE_2, var_4);
                var_0 = TalkPromptChoice2(gText_TV_HarvestGoddessNumberGuessing_InitialOrSharedComparisonPrompt, gText_TV_HarvestGoddessNumberGuessing_ChoiceHigher, gText_TV_HarvestGoddessNumberGuessing_ChoiceLower);
            }
            switch (var_0)
            {
                case PROMPT_CHOICE_OPTION_1:
                    var_5 = TRUE;
                    break;
                case PROMPT_CHOICE_OPTION_2:
                    var_5 = FALSE;
                    break;
            }
            TalkOpen();
            var_1 = RandomIntInclusive(0, 9);
            SetTextVariableNumber(TEXT_VARIABLE_1, var_1);
            SetTextVariableNumber(TEXT_VARIABLE_2, var_4);
            TalkAppendMessage(gText_TV_HarvestGoddessNumberGuessing_NextNumberDisplay);
            if (var_5 == TRUE)
            {
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                TalkMessage(gText_TV_HarvestGoddessNumberGuessing_CorrectHigherResult);
                switch (var_1)
                {
                    case 0:
                        switch (var_4)
                        {
                            case 0:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                        }
                        break;
                    case 1:
                        switch (var_4)
                        {
                            case 0:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                            case 1:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                        }
                        break;
                    case 2:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                            case 2:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                        }
                        break;
                    case 3:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                            case 3:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                        }
                        break;
                    case 4:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                            case 4:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                        }
                        break;
                    case 5:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                            case 5:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                        }
                        break;
                    case 6:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                            case 6:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                        }
                        break;
                    case 7:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                            case 7:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                        }
                        break;
                    case 8:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                            case 8:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                        }
                        break;
                    case 9:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                        }
                        break;
                }
            }
            else
            {
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                TalkMessage(gText_TV_HarvestGoddessNumberGuessing_CorrectLowerResult);
                switch (var_1)
                {
                    case 0:
                        switch (var_4)
                        {
                            case 0:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                        }
                        break;
                    case 1:
                        switch (var_4)
                        {
                            case 0:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                            case 1:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                        }
                        break;
                    case 2:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                            case 2:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                        }
                        break;
                    case 3:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                            case 3:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                        }
                        break;
                    case 4:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                            case 4:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                        }
                        break;
                    case 5:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                            case 5:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 6:
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                        }
                        break;
                    case 6:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                            case 6:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 7:
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                        }
                        break;
                    case 7:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                            case 7:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 8:
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                        }
                        break;
                    case 8:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                            case 8:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_WIN;
                                break;
                        }
                        break;
                    case 9:
                        switch (var_4)
                        {
                            case 0:
                            case 1:
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                            case 7:
                            case 8:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_LOSS;
                                break;
                            case 9:
                                var_2 = HARVEST_GODDESS_GAME_ROUND_DRAW;
                                break;
                        }
                        break;
                }
            }
            switch (var_2)
            {
                case HARVEST_GODDESS_GAME_ROUND_WIN:
                    PlaySong(AUDIO_START, AUDIO_SFX_ATTENTION_CHIME);
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                    TalkMessage(gText_TV_HarvestGoddessNumberGuessing_CorrectContinuePrompt);
                    if (var_3 != 100)
                    {
                        var_3 = var_3 + 1;
                    }
                    break;
                case HARVEST_GODDESS_GAME_ROUND_DRAW:
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                    TalkMessage(gText_TV_HarvestGoddessNumberGuessing_EqualContinuePrompt);
                    break;
                case HARVEST_GODDESS_GAME_ROUND_LOSS:
                    PlaySong(AUDIO_START, AUDIO_SFX_INCORRECT_ANSWER);
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_ANGRY);
                    TalkMessage(gText_TV_HarvestGoddessNumberGuessing_IncorrectGameOver);
                    break;
            }
        }
        while (var_2 == HARVEST_GODDESS_GAME_ROUND_WIN || var_2 == HARVEST_GODDESS_GAME_ROUND_DRAW);
        if (var_3 == 0)
        {
            TalkMessage(gText_TV_HarvestGoddessNumberGuessing_SessionEnded);
        }
        else
        {
            if (var_3 == 1)
            {
                SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                TalkMessage(gText_TV_HarvestGoddessNumberGuessing_SingleWinSessionEnded);
            }
            else
            {
                if (var_3 == 100)
                {
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                    TalkMessage(gText_TV_HarvestGoddessNumberGuessing_TenWinsAnnouncement);
                }
                else
                {
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                    SetTextVariableNumber(TEXT_VARIABLE_1, var_3);
                    TalkMessage(gText_TV_HarvestGoddessNumberGuessing_WinningStreakAnnouncement);
                }
                if (IsPlayerHoldingNothing() == TRUE)
                {
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                    TalkMessage(gText_TV_HarvestGoddessNumberGuessing_RewardGranted);
                    TalkClose();
                    if (var_3 == 100)
                    {
                        PlaySong(AUDIO_START, AUDIO_SFX_CEREMONIAL_CHIME);
                        SetPlayerHeldArticle(ITEM_ARTICLE_BOOK);
                        WaitFrames(330);
                    }
                    else
                    {
                        if (var_3 >= 90)
                        {
                            PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
                            SetPlayerHeldArticle(ITEM_ARTICLE_LITHOGRAPH);
                            WaitFrames(240);
                        }
                        else
                        {
                            if (var_3 >= 80)
                            {
                                PlaySong(AUDIO_START, AUDIO_SFX_SUCCESS);
                                SetPlayerHeldArticle(ITEM_ARTICLE_MESSAGE_IN_A_BOTTLE);
                                WaitFrames(240);
                            }
                            else
                            {
                                if (var_3 >= 70)
                                {
                                    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                    SetPlayerHeldArticle(ITEM_ARTICLE_PIRATE_TREASURE);
                                    WaitFrames(120);
                                }
                                else
                                {
                                    if (var_3 >= 60)
                                    {
                                        PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                        SetPlayerHeldArticle(ITEM_ARTICLE_FOSSIL_OF_FISH);
                                        WaitFrames(120);
                                    }
                                    else
                                    {
                                        if (var_3 >= 50)
                                        {
                                            PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                            SetPlayerHeldArticle(ITEM_ARTICLE_GOLDEN_LUMBER);
                                            WaitFrames(120);
                                        }
                                        else
                                        {
                                            if (var_3 >= 40)
                                            {
                                                PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                                SetPlayerHeldArticle(ITEM_ARTICLE_DRESS);
                                                WaitFrames(120);
                                            }
                                            else
                                            {
                                                if (var_3 >= 30)
                                                {
                                                    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                                    SetPlayerHeldArticle(ITEM_ARTICLE_PERFUME);
                                                    WaitFrames(120);
                                                }
                                                else
                                                {
                                                    if (var_3 >= 25)
                                                    {
                                                        PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                                        SetPlayerHeldArticle(ITEM_ARTICLE_FACIAL_PACK);
                                                        WaitFrames(120);
                                                    }
                                                    else
                                                    {
                                                        if (var_3 >= 20)
                                                        {
                                                            PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                                            SetPlayerHeldArticle(ITEM_ARTICLE_SKIN_LOTION);
                                                            WaitFrames(120);
                                                        }
                                                        else
                                                        {
                                                            if (var_3 >= 15)
                                                            {
                                                                PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                                                SetPlayerHeldArticle(ITEM_ARTICLE_SUNBLOCK);
                                                                WaitFrames(120);
                                                            }
                                                            else
                                                            {
                                                                if (var_3 >= 10)
                                                                {
                                                                    PlaySong(AUDIO_START, AUDIO_SFX_ITEM_OBTAINED);
                                                                    SetPlayerHeldFood(ITEM_FOOD_RELAX_TEA_LEAVES);
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
                                                                        var_1 = RandomIntInclusive(0, 8);
                                                                        switch (var_1)
                                                                        {
                                                                            case 0:
                                                                                SetPlayerHeldFood(ITEM_FOOD_BLUE_GRASS);
                                                                                break;
                                                                            case 1:
                                                                                SetPlayerHeldFood(ITEM_FOOD_GREEN_GRASS);
                                                                                break;
                                                                            case 2:
                                                                                SetPlayerHeldFood(ITEM_FOOD_RED_GRASS);
                                                                                break;
                                                                            case 3:
                                                                                SetPlayerHeldFood(ITEM_FOOD_YELLOW_GRASS);
                                                                                break;
                                                                            case 4:
                                                                                SetPlayerHeldFood(ITEM_FOOD_ORANGE_GRASS);
                                                                                break;
                                                                            case 5:
                                                                                SetPlayerHeldFood(ITEM_FOOD_PURPLE_GRASS);
                                                                                break;
                                                                            case 6:
                                                                                SetPlayerHeldFood(ITEM_FOOD_INDIGO_GRASS);
                                                                                break;
                                                                            case 7:
                                                                                SetPlayerHeldFood(ITEM_FOOD_BLACK_GRASS);
                                                                                break;
                                                                            case 8:
                                                                                SetPlayerHeldFood(ITEM_FOOD_WHITE_GRASS);
                                                                                break;
                                                                        }
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
                    }
                }
                else
                {
                    SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_NORMAL);
                    TalkMessage(gText_TV_HarvestGoddessNumberGuessing_RewardPostponedInventoryFull);
                }
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                SetTalkPortrait(TALK_PORTRAIT_HARVEST_GODDESS_HAPPY);
                TalkMessage(gText_TV_HarvestGoddessNumberGuessing_SessionEnded);
            }
        }
        VarSet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS, VarGet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS) + 1);
    }
    EndTelevisionProgram();
    TalkClose();
}
