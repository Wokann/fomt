#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_DailyProgramDispatcher_ProgramUnavailable[] =
        "That's impossible!\r\n"
        "{Press}";
};

void EventScript_TV_DailyProgramDispatcher(void)
{
    int var_0;
    switch (VarGet(VAR_SEASON))
    {
        case SEASON_SPRING:
            SetTelevisionProgram(TELEVISION_PROGRAM_NEW_YEAR_SPRING_SPECIAL);
            switch (VarGet(VAR_DAY))
            {
                case DAY_OF_MONTH_01:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_OF_MONTH_02:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_OF_MONTH_03:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_OF_MONTH_04:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_OF_MONTH_05:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_OF_MONTH_06:
                case DAY_OF_MONTH_07:
                case DAY_OF_MONTH_08:
                case DAY_OF_MONTH_09:
                case DAY_OF_MONTH_10:
                case DAY_OF_MONTH_11:
                case DAY_OF_MONTH_12:
                case DAY_OF_MONTH_13:
                case DAY_OF_MONTH_14:
                case DAY_OF_MONTH_15:
                case DAY_OF_MONTH_16:
                case DAY_OF_MONTH_17:
                case DAY_OF_MONTH_18:
                case DAY_OF_MONTH_19:
                case DAY_OF_MONTH_20:
                case DAY_OF_MONTH_21:
                case DAY_OF_MONTH_22:
                case DAY_OF_MONTH_23:
                case DAY_OF_MONTH_24:
                case DAY_OF_MONTH_25:
                case DAY_OF_MONTH_26:
                case DAY_OF_MONTH_27:
                case DAY_OF_MONTH_28:
                case DAY_OF_MONTH_29:
                case DAY_OF_MONTH_30:
                    var_0 = ShowTelevisionMessage(gText_TV_DailyProgramDispatcher_ProgramUnavailable);
                    break;
            }
            break;
        case SEASON_SUMMER:
        case SEASON_FALL:
            var_0 = ShowTelevisionMessage(gText_TV_DailyProgramDispatcher_ProgramUnavailable);
            break;
        case SEASON_WINTER:
            SetTelevisionProgram(TELEVISION_PROGRAM_NEW_YEAR_WINTER_SPECIAL);
            switch (VarGet(VAR_DAY))
            {
                case DAY_OF_MONTH_01:
                case DAY_OF_MONTH_02:
                case DAY_OF_MONTH_03:
                case DAY_OF_MONTH_04:
                case DAY_OF_MONTH_05:
                case DAY_OF_MONTH_06:
                case DAY_OF_MONTH_07:
                case DAY_OF_MONTH_08:
                case DAY_OF_MONTH_09:
                case DAY_OF_MONTH_10:
                case DAY_OF_MONTH_11:
                case DAY_OF_MONTH_12:
                case DAY_OF_MONTH_13:
                case DAY_OF_MONTH_14:
                case DAY_OF_MONTH_15:
                case DAY_OF_MONTH_16:
                case DAY_OF_MONTH_17:
                case DAY_OF_MONTH_18:
                case DAY_OF_MONTH_19:
                case DAY_OF_MONTH_20:
                case DAY_OF_MONTH_21:
                case DAY_OF_MONTH_22:
                case DAY_OF_MONTH_23:
                case DAY_OF_MONTH_24:
                case DAY_OF_MONTH_25:
                case DAY_OF_MONTH_26:
                case DAY_OF_MONTH_27:
                case DAY_OF_MONTH_28:
                    var_0 = ShowTelevisionMessage(gText_TV_DailyProgramDispatcher_ProgramUnavailable);
                    break;
                case DAY_OF_MONTH_29:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_OF_MONTH_30:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
            }
            break;
    }
    EndTelevisionProgram();
    TalkClose();
    switch (var_0)
    {
        case TELEVISION_INPUT_UP_WEATHER:
        case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
        case TELEVISION_INPUT_RIGHT_NEWS:
        case TELEVISION_INPUT_LEFT_VARIETY:
            VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
            CallScript(EventScript_TV_EntertainmentChannel);
            break;
        case TELEVISION_INPUT_ADVANCE_TEXT:
        case TELEVISION_INPUT_TURN_OFF:
            break;
    }
}
