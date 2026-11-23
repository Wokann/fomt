#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1049_TV_Calendar_Program.mary.h"

void EventScript_1049_TV_Calendar_Program(void)
{
    int var_0;
    switch (VarGet(VAR_SEASON))
    {
        case SEASON_SPRING:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay03);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay04);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay05);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay06);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay07);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay08);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay09);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay10);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay11);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay12);
                    break;
                case DAY_13:
                    if (VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_FRIDAY)
                    {
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay13Friday13);
                    }
                    else
                    {
                        var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay13);
                    }
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay14);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay15);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay16);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay17);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay18);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay19);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay20);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay21);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay22);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay23);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay24);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay25);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay26);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay27);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay28);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay29);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SpringDay30);
                    break;
            }
            break;
        case SEASON_SUMMER:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay03);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay04);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay05);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay06);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay07);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay08);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay09);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay10);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay11);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay12);
                    break;
                case DAY_13:
                    if (VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_FRIDAY)
                    {
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay13Friday13);
                    }
                    else
                    {
                        var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay13);
                    }
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay14);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay15);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay16);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay17);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay18);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay19);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay20);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay21);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay22);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay23);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay24);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay25);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay26);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay27);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay28);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay29);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_SummerDay30);
                    break;
            }
            break;
        case SEASON_FALL:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay03);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay04);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay05);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay06);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay07);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay08);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay09);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay10);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay11);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay12);
                    break;
                case DAY_13:
                    if (VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_FRIDAY)
                    {
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay13Friday13);
                    }
                    else
                    {
                        var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay13);
                    }
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay14);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay15);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay16);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay17);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay18);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay19);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay20);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay21);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay22);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay23);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay24);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay25);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay26);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay27);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay28);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay29);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_FallDay30);
                    break;
            }
            break;
        case SEASON_WINTER:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay03);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay04);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay05);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay06);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay07);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay08);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay09);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay10);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay11);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay12);
                    break;
                case DAY_13:
                    if (VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_FRIDAY)
                    {
                        SetTelevisionProgram(TELEVISION_PROGRAM_NO_SIGNAL);
                        var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay13Friday13);
                    }
                    else
                    {
                        var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay13);
                    }
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay14);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay15);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay16);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay17);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay18);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay19);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay20);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay21);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay22);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay23);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay24);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay25);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay26);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay27);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay28);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay29);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_Calendar_WinterDay30);
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
            CallScript(EventScript_0356_TV_ChannelDispatcher);
            break;
        case TELEVISION_INPUT_ADVANCE_TEXT:
        case TELEVISION_INPUT_TURN_OFF:
            break;
    }
}
