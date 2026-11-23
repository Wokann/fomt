#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1047_TV_MechabotUltrorZero_EpisodeReminders.mary.h"

void EventScript_1047_TV_MechabotUltrorZero_EpisodeReminders(void)
{
    int var_0;
    switch (VarGet(VAR_TV_MECHABOT_ULTROR_ZERO_REMINDER_INDEX))
    {
        case 0:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder01);
            break;
        case 1:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder02);
            break;
        case 2:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder03);
            break;
        case 3:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder04);
            break;
        case 4:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder05);
            break;
        case 5:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder06);
            break;
        case 6:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder07);
            break;
        case 7:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder08);
            break;
        case 8:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder09);
            break;
        case 9:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder10);
            break;
        case 10:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder11);
            break;
        case 11:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder12);
            break;
        case 12:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder13);
            break;
        case 13:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder14);
            break;
        case 14:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder15);
            break;
        case 15:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder16);
            break;
        case 16:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder17);
            break;
        case 17:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder18);
            break;
        case 18:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder19);
            break;
        case 19:
            var_0 = ShowTelevisionMessage(gText_TV_MechabotUltrorZero_Reminder20);
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
    }
}
