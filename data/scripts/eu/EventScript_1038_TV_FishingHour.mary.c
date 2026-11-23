#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1038_TV_FishingHour.mary.h"

void EventScript_1038_TV_FishingHour(void)
{
    int var_0, var_1, var_2;
    var_1 = VarGet(VAR_SEASON);
    var_2 = VarGet(VAR_TV_FISHING_HOUR_SEGMENT_INDEX);
    switch (var_1)
    {
        case SEASON_SPRING:
            switch (var_2)
            {
                case 0:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode01);
                    break;
                case 1:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode02);
                    break;
                case 2:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode03);
                    break;
                case 3:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode04);
                    break;
            }
            break;
        case SEASON_SUMMER:
            switch (var_2)
            {
                case 0:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode05);
                    break;
                case 1:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode06);
                    break;
                case 2:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode07);
                    break;
                case 3:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode08);
                    break;
            }
            break;
        case SEASON_FALL:
            switch (var_2)
            {
                case 0:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode09);
                    break;
                case 1:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode10);
                    break;
                case 2:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode11);
                    break;
                case 3:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode12);
                    break;
            }
            break;
        case SEASON_WINTER:
            switch (var_2)
            {
                case 0:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode13);
                    break;
                case 1:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode14);
                    break;
                case 2:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode15);
                    break;
                case 3:
                    var_0 = ShowTelevisionMessage(gText_TV_FishingHour_Episode16);
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
