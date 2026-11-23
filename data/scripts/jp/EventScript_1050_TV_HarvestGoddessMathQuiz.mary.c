#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1050_TV_HarvestGoddessMathQuiz.mary.h"

void EventScript_1050_TV_HarvestGoddessMathQuiz(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    var_2 = 0;
    var_3 = 0;
    TalkOpen();
    var_4 = ShowTelevisionMessage(gText_TV_HarvestGoddessMathQuiz_Instructions);
    TalkClose();
    switch (var_4)
    {
        case TELEVISION_INPUT_UP_WEATHER:
        case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
        case TELEVISION_INPUT_RIGHT_NEWS:
        case TELEVISION_INPUT_LEFT_VARIETY:
            VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_4);
            CallScript(EventScript_0540_TV_EntertainmentChannel);
            break;
        case TELEVISION_INPUT_TURN_OFF:
            break;
        mary_dead_jump:
    }
    TalkOpen();
    TalkAppendMessage(gText_TV_HarvestGoddessMathQuiz_InputWarning);
    do
    {
        switch (var_3)
        {
            case 0:
                TalkAppendMessage(gText_TV_HarvestGoddessMathQuiz_Question01);
                break;
            case 1:
                TalkAppendMessage(gText_TV_HarvestGoddessMathQuiz_Question02);
                break;
            case 2:
                TalkAppendMessage(gText_TV_HarvestGoddessMathQuiz_Question03);
                break;
            case 3:
                TalkAppendMessage(gText_TV_HarvestGoddessMathQuiz_Question04);
                break;
            case 4:
                TalkAppendMessage(gText_TV_HarvestGoddessMathQuiz_Question05);
                break;
            case 5:
                TalkAppendMessage(gText_TV_HarvestGoddessMathQuiz_Question06);
                break;
            case 6:
                TalkAppendMessage(gText_TV_HarvestGoddessMathQuiz_Question07);
                break;
            case 7:
                TalkAppendMessage(gText_TV_HarvestGoddessMathQuiz_Question08);
                break;
            case 8:
                TalkAppendMessage(gText_TV_HarvestGoddessMathQuiz_Question09);
                break;
            case 9:
                TalkAppendMessage(gText_TV_HarvestGoddessMathQuiz_Question10);
                break;
        }
        var_1 = RandomIntInclusive(0, 5);
        switch (var_1)
        {
            case 0:
                TalkMessageSlow(gText_TV_HarvestGoddessMathQuiz_AnswerPattern01);
                var_0 = TalkChoice6(gText_TV_HarvestGoddessMathQuiz_AnswerChoice01, gText_TV_HarvestGoddessMathQuiz_AnswerChoice02, gText_TV_HarvestGoddessMathQuiz_AnswerChoice03, gText_TV_HarvestGoddessMathQuiz_AnswerChoice04, gText_TV_HarvestGoddessMathQuiz_AnswerChoice05, gText_TV_HarvestGoddessMathQuiz_AnswerChoice06);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                    case CHOICE_OPTION_2:
                    case CHOICE_OPTION_3:
                    case CHOICE_OPTION_4:
                    case CHOICE_OPTION_5:
                        break;
                    case CHOICE_OPTION_6:
                        var_2++;
                        break;
                }
                break;
            case 1:
                TalkMessageSlow(gText_TV_HarvestGoddessMathQuiz_AnswerPattern02);
                var_0 = TalkChoice6(gText_TV_HarvestGoddessMathQuiz_AnswerChoice01, gText_TV_HarvestGoddessMathQuiz_AnswerChoice02, gText_TV_HarvestGoddessMathQuiz_AnswerChoice03, gText_TV_HarvestGoddessMathQuiz_AnswerChoice04, gText_TV_HarvestGoddessMathQuiz_AnswerChoice05, gText_TV_HarvestGoddessMathQuiz_AnswerChoice06);
                switch (var_0)
                {
                    case CHOICE_OPTION_2:
                    case CHOICE_OPTION_3:
                    case CHOICE_OPTION_4:
                    case CHOICE_OPTION_5:
                    case CHOICE_OPTION_6:
                        break;
                    case CHOICE_OPTION_1:
                        var_2++;
                        break;
                }
                break;
            case 2:
                TalkMessageSlow(gText_TV_HarvestGoddessMathQuiz_AnswerPattern03);
                var_0 = TalkChoice6(gText_TV_HarvestGoddessMathQuiz_AnswerChoice01, gText_TV_HarvestGoddessMathQuiz_AnswerChoice02, gText_TV_HarvestGoddessMathQuiz_AnswerChoice03, gText_TV_HarvestGoddessMathQuiz_AnswerChoice04, gText_TV_HarvestGoddessMathQuiz_AnswerChoice05, gText_TV_HarvestGoddessMathQuiz_AnswerChoice06);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                    case CHOICE_OPTION_3:
                    case CHOICE_OPTION_4:
                    case CHOICE_OPTION_5:
                    case CHOICE_OPTION_6:
                        break;
                    case CHOICE_OPTION_2:
                        var_2++;
                        break;
                }
                break;
            case 3:
                TalkMessageSlow(gText_TV_HarvestGoddessMathQuiz_AnswerPattern04);
                var_0 = TalkChoice6(gText_TV_HarvestGoddessMathQuiz_AnswerChoice01, gText_TV_HarvestGoddessMathQuiz_AnswerChoice02, gText_TV_HarvestGoddessMathQuiz_AnswerChoice03, gText_TV_HarvestGoddessMathQuiz_AnswerChoice04, gText_TV_HarvestGoddessMathQuiz_AnswerChoice05, gText_TV_HarvestGoddessMathQuiz_AnswerChoice06);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                    case CHOICE_OPTION_2:
                    case CHOICE_OPTION_4:
                    case CHOICE_OPTION_5:
                    case CHOICE_OPTION_6:
                        break;
                    case CHOICE_OPTION_3:
                        var_2++;
                        break;
                }
                break;
            case 4:
                TalkMessageSlow(gText_TV_HarvestGoddessMathQuiz_AnswerPattern05);
                var_0 = TalkChoice6(gText_TV_HarvestGoddessMathQuiz_AnswerChoice01, gText_TV_HarvestGoddessMathQuiz_AnswerChoice02, gText_TV_HarvestGoddessMathQuiz_AnswerChoice03, gText_TV_HarvestGoddessMathQuiz_AnswerChoice04, gText_TV_HarvestGoddessMathQuiz_AnswerChoice05, gText_TV_HarvestGoddessMathQuiz_AnswerChoice06);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                    case CHOICE_OPTION_2:
                    case CHOICE_OPTION_3:
                    case CHOICE_OPTION_5:
                    case CHOICE_OPTION_6:
                        break;
                    case CHOICE_OPTION_4:
                        var_2++;
                        break;
                }
                break;
            case 5:
                TalkMessageSlow(gText_TV_HarvestGoddessMathQuiz_AnswerPattern06);
                var_0 = TalkChoice6(gText_TV_HarvestGoddessMathQuiz_AnswerChoice01, gText_TV_HarvestGoddessMathQuiz_AnswerChoice02, gText_TV_HarvestGoddessMathQuiz_AnswerChoice03, gText_TV_HarvestGoddessMathQuiz_AnswerChoice04, gText_TV_HarvestGoddessMathQuiz_AnswerChoice05, gText_TV_HarvestGoddessMathQuiz_AnswerChoice06);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                    case CHOICE_OPTION_2:
                    case CHOICE_OPTION_3:
                    case CHOICE_OPTION_4:
                    case CHOICE_OPTION_6:
                        break;
                    case CHOICE_OPTION_5:
                        var_2++;
                        break;
                }
                break;
        }
        var_3++;
    }
    while (var_3 < 10);
    if (var_2 == 10)
    {
        TalkMessageSlow(gText_TV_HarvestGoddessMathQuiz_AllCorrect);
        if (VarGet(VAR_JEWEL_OF_TRUTH_FROM_HARVEST_GODDESS_MATH_QUIZ_COLLECTED) == TRUE)
        {
            TalkMessageSlow(gText_TV_HarvestGoddessMathQuiz_RewardAlreadyClaimed);
        }
        else
        {
            if (IsPlayerHoldingNothing() == TRUE)
            {
                TalkMessageSlow(gText_TV_HarvestGoddessMathQuiz_RewardJewelOfTruth);
                VarSet(VAR_JEWEL_OF_TRUTH_FROM_HARVEST_GODDESS_MATH_QUIZ_COLLECTED, TRUE);
                TalkClose();
                SetPlayerHeldArticle(ITEM_ARTICLE_JEWEL_OF_TRUTH);
                VarSet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT, VarGet(VAR_JEWELS_OF_TRUTH_FOUND_COUNT) + 1);
            }
            else
            {
                TalkMessageSlow(gText_TV_HarvestGoddessMathQuiz_RewardPostponedInventoryFull);
            }
        }
    }
    else
    {
        TalkMessageSlow(gText_TV_HarvestGoddessMathQuiz_AllIncorrect);
    }
    EndTelevisionProgram();
    TalkClose();
}
