#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1054_TV_StarLilyBanditGirl.mary.h"

void EventScript_1054_TV_StarLilyBanditGirl(void)
{
    int var_0;
    switch (VarGet(VAR_TV_STAR_LILY_BANDIT_GIRL_EPISODE_INDEX))
    {
        case 0:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode01);
            break;
        case 1:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode02);
            break;
        case 2:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode03);
            break;
        case 3:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode04);
            break;
        case 4:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode05);
            break;
        case 5:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode06);
            break;
        case 6:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode07);
            break;
        case 7:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode08);
            break;
        case 8:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode09);
            break;
        case 9:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode10);
            break;
        case 10:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode11);
            break;
        case 11:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode12);
            break;
        case 12:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode13);
            break;
        case 13:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode14);
            break;
        case 14:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode15);
            break;
        case 15:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode16);
            break;
        case 16:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode17);
            break;
        case 17:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode18);
            break;
        case 18:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode19);
            break;
        case 19:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode20);
            break;
        case 20:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode21);
            break;
        case 21:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode22);
            break;
        case 22:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode23);
            break;
        case 23:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode24);
            break;
        case 24:
            var_0 = ShowTelevisionMessage(gText_TV_StarLilyBanditGirl_Episode25);
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
