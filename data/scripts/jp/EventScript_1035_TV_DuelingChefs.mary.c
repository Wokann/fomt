#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1035_TV_DuelingChefs.mary.h"

void EventScript_1035_TV_DuelingChefs(void)
{
    int var_0;
    switch (VarGet(VAR_TV_DUELING_CHEFS_EPISODE_INDEX))
    {
        case 0:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode01);
            break;
        case 1:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode02);
            break;
        case 2:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode03);
            break;
        case 3:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode04);
            break;
        case 4:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode05);
            break;
        case 5:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode06);
            break;
        case 6:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode07);
            break;
        case 7:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode08);
            break;
        case 8:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode09);
            break;
        case 9:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode10);
            break;
        case 10:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode11);
            break;
        case 11:
            var_0 = ShowTelevisionMessage(gText_TV_DuelingChefs_Episode12);
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
        mary_dead_jump:
    }
}
