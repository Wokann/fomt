#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_TV_DailyProgramDispatcher_ProgramUnavailable[] =
        "Unmöglich!\r\n"
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
                case DAY_01:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_02:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_03:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_04:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_05:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_06:
                case DAY_07:
                case DAY_08:
                case DAY_09:
                case DAY_10:
                case DAY_11:
                case DAY_12:
                case DAY_13:
                case DAY_14:
                case DAY_15:
                case DAY_16:
                case DAY_17:
                case DAY_18:
                case DAY_19:
                case DAY_20:
                case DAY_21:
                case DAY_22:
                case DAY_23:
                case DAY_24:
                case DAY_25:
                case DAY_26:
                case DAY_27:
                case DAY_28:
                case DAY_29:
                case DAY_30:
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
                case DAY_01:
                case DAY_02:
                case DAY_03:
                case DAY_04:
                case DAY_05:
                case DAY_06:
                case DAY_07:
                case DAY_08:
                case DAY_09:
                case DAY_10:
                case DAY_11:
                case DAY_12:
                case DAY_13:
                case DAY_14:
                case DAY_15:
                case DAY_16:
                case DAY_17:
                case DAY_18:
                case DAY_19:
                case DAY_20:
                case DAY_21:
                case DAY_22:
                case DAY_23:
                case DAY_24:
                case DAY_25:
                case DAY_26:
                case DAY_27:
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_DailyProgramDispatcher_ProgramUnavailable);
                    break;
                case DAY_29:
                    CallScript(EventScript_TV_HarvestGoddessMathQuiz);
                    break;
                case DAY_30:
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
