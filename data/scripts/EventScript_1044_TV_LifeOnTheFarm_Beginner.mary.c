#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1044_TV_LifeOnTheFarm_Beginner.mary.h"

void EventScript_1044_TV_LifeOnTheFarm_Beginner(void)
{
    int var_0;
    switch (VarGet(VAR_SEASON))
    {
        case SEASON_SPRING:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay03);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay04);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay05);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay06);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay07);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay08);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay09);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay10);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay11);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay12);
                    break;
                case DAY_13:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay13);
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay14);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay15);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay16);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay17);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay18);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay19);
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                    break;
#else
#ifdef BUGFIX
                    // Finish day 19 before the next episode branch.
                    break;
#endif
#endif
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay20);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay21);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay22);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay23);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay24);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay25);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay26);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay27);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay28);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay29);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SpringDay30);
                    break;
            }
            break;
        case SEASON_SUMMER:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay03);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay04);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay05);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay06);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay07);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay08);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay09);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay10);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay11);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay12);
                    break;
                case DAY_13:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay13);
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay14);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay15);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay16);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay17);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay18);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay19);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay20);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay21);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay22);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay23);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay24);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay25);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay26);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay27);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay28);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay29);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_SummerDay30);
                    break;
            }
            break;
        case SEASON_FALL:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay03);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay04);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay05);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay06);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay07);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay08);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay09);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay10);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay11);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay12);
                    break;
                case DAY_13:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay13);
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay14);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay15);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay16);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay17);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay18);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay19);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay20);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay21);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay22);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay23);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay24);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay25);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay26);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay27);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay28);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay29);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_FallDay30);
                    break;
            }
            break;
        case SEASON_WINTER:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay03);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay04);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay05);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay06);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay07);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay08);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay09);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay10);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay11);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay12);
                    break;
                case DAY_13:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay13);
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay14);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay15);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay16);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay17);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay18);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay19);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay20);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay21);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay22);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay23);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay24);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay25);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay26);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay27);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay28);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay29);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_LifeOnTheFarm_Beginner_WinterDay30);
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
