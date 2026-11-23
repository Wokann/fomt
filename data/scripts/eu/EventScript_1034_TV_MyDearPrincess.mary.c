#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1034_TV_MyDearPrincess.mary.h"

void EventScript_1034_TV_MyDearPrincess(void)
{
    int var_0;
    switch (VarGet(VAR_TV_MY_DEAR_PRINCESS_EPISODE_INDEX))
    {
        case 0:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode01);
            break;
        case 1:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode02);
            break;
        case 2:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode03);
            break;
        case 3:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode04);
            break;
        case 4:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode05);
            break;
        case 5:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode06);
            break;
        case 6:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode07);
            break;
        case 7:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode08);
            break;
        case 8:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode09);
            break;
        case 9:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode10);
            break;
        case 10:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode11);
            break;
        case 11:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode12);
            break;
        case 12:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode13);
            break;
        case 13:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode14);
            break;
        case 14:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode15);
            break;
        case 15:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode16);
            break;
        case 16:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode17);
            break;
        case 17:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode18);
            break;
        case 18:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode19);
            break;
        case 19:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode20);
            break;
        case 20:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode21);
            break;
        case 21:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode22);
            break;
        case 22:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode23);
            break;
        case 23:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode24);
            break;
        case 24:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode25);
            break;
        case 25:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode26);
            break;
        case 26:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode27);
            break;
        case 27:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode28);
            break;
        case 28:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode29);
            break;
        case 29:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode30);
            break;
        case 30:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode31);
            break;
        case 31:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode32);
            break;
        case 32:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode33);
            break;
        case 33:
            var_0 = ShowTelevisionMessage(gText_TV_MyDearPrincess_Episode34);
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
