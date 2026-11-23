#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1039_TV_F314MGrandPrix.mary.h"

void EventScript_1039_TV_F314MGrandPrix(void)
{
    int var_0;
    switch (VarGet(VAR_SEASON))
    {
        case SEASON_SPRING:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race01_PreviewPart01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race01_PreviewPart02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race01_ResultsPart01);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race01_ResultsPart02);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race02_PreviewPart01);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race02_PreviewPart02);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race02_ResultsPart01);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race02_ResultsPart02);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Shared_Race03And23PreviewPart01);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race03_PreviewPart02);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race03_ResultsPart01);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race03_ResultsPart02);
                    break;
                case DAY_13:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race04_PreviewPart01);
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race04_PreviewPart02);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race04_ResultsPart01);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race04_ResultsPart02);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race05_PreviewPart01);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race05_PreviewPart02);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race05_ResultsPart01);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race05_ResultsPart02);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race06_PreviewPart01);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race06_PreviewPart02);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race06_ResultsPart01);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race06_ResultsPart02);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race07_PreviewPart01);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race07_PreviewPart02);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race07_ResultsPart01);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race07_ResultsPart02);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race08_PreviewPart01);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race08_PreviewPart02);
                    break;
            }
            break;
        case SEASON_SUMMER:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race08_ResultsPart01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race08_ResultsPart02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race09_PreviewPart01);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race09_PreviewPart02);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race09_ResultsPart01);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race09_ResultsPart02);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race10_PreviewPart01);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race10_PreviewPart02);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race10_ResultsPart01);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race10_ResultsPart02);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race11_PreviewPart01);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race11_PreviewPart02);
                    break;
                case DAY_13:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race11_ResultsPart01);
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race11_ResultsPart02);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race12_PreviewPart01);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race02_PreviewPart02);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race12_ResultsPart01);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race12_ResultsPart02);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race13_PreviewPart01);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race13_PreviewPart02);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race13_ResultsPart01);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race13_ResultsPart02);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race14_PreviewPart01);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race04_PreviewPart02);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race14_ResultsPart01);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race14_ResultsPart02);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race15_PreviewPart01);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race05_PreviewPart02);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race15_ResultsPart01);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race15_ResultsPart02);
                    break;
            }
            break;
        case SEASON_FALL:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race16_PreviewPart01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race16_PreviewPart02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race16_ResultsPart01);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race16_ResultsPart02);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race07_PreviewPart01);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race07_PreviewPart02);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race17_ResultsPart01);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race17_ResultsPart02);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race18_PreviewPart01);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race18_PreviewPart02);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race18_ResultsPart01);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race18_ResultsPart02);
                    break;
                case DAY_13:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race19_PreviewPart01);
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race09_PreviewPart02);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race19_ResultsPart01);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race19_ResultsPart02);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race20_PreviewPart01);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race20_PreviewPart02);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race20_ResultsPart01);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race20_ResultsPart02);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race21_PreviewPart01);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race11_PreviewPart02);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race21_ResultsPart01);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race21_ResultsPart02);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race22_PreviewPart01);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race22_PreviewPart02);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race22_ResultsPart01);
                    break;
                case DAY_28:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race22_ResultsPart02);
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Shared_Race03And23PreviewPart01);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race23_PreviewPart02);
                    break;
            }
            break;
        case SEASON_WINTER:
            switch (VarGet(VAR_DAY))
            {
                case DAY_01:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race23_ResultsPart01);
                    break;
                case DAY_02:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race23_ResultsPart02);
                    break;
                case DAY_03:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race14_PreviewPart01);
                    break;
                case DAY_04:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race04_PreviewPart02);
                    break;
                case DAY_05:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race24_ResultsPart01);
                    break;
                case DAY_06:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race24_ResultsPart02);
                    break;
                case DAY_07:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race25_PreviewPart01);
                    break;
                case DAY_08:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race25_PreviewPart02);
                    break;
                case DAY_09:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race25_ResultsPart01);
                    break;
                case DAY_10:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race25_ResultsPart02);
                    break;
                case DAY_11:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race26_PreviewPart01);
                    break;
                case DAY_12:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race16_PreviewPart02);
                    break;
                case DAY_13:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race26_ResultsPart01);
                    break;
                case DAY_14:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race26_ResultsPart02);
                    break;
                case DAY_15:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race07_PreviewPart01);
                    break;
                case DAY_16:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race27_PreviewPart02);
                    break;
                case DAY_17:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race27_ResultsPart01);
                    break;
                case DAY_18:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race27_ResultsPart02);
                    break;
                case DAY_19:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race28_PreviewPart01);
                    break;
                case DAY_20:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race28_PreviewPart02);
                    break;
                case DAY_21:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race28_ResultsPart01);
                    break;
                case DAY_22:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race28_ResultsPart02);
                    break;
                case DAY_23:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race19_PreviewPart01);
                    break;
                case DAY_24:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race09_PreviewPart02);
                    break;
                case DAY_25:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race29_ResultsPart01);
                    break;
                case DAY_26:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race29_ResultsPart02);
                    break;
                case DAY_27:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race30_PreviewPart01);
                    break;
                case DAY_28:
// The second preview uses the already translated final-race part two, as JP does.
#ifdef BUGFIX
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race20_PreviewPart02);
#else
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race30_PreviewPart01);
#endif
                    break;
                case DAY_29:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race30_ResultsPart01);
                    break;
                case DAY_30:
                    var_0 = ShowTelevisionMessage(gText_TV_F314MGrandPrix_Race30_ResultsPart02);
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
            CallScript(EventScript_0540_TV_EntertainmentChannel);
            break;
        case TELEVISION_INPUT_ADVANCE_TEXT:
        case TELEVISION_INPUT_TURN_OFF:
            break;
        mary_dead_jump:
    }
}
