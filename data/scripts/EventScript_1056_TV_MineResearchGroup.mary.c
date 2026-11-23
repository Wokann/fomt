#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1056_TV_MineResearchGroup.mary.h"

void EventScript_1056_TV_MineResearchGroup(void)
{
    int var_0;
    switch (VarGet(VAR_TV_MINE_RESEARCH_GROUP_EPISODE_INDEX))
    {
        case 0:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode01);
            break;
        case 1:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode02);
            break;
        case 2:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode03);
            break;
        case 3:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode04);
            break;
        case 4:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode05);
            break;
        case 5:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode06);
            break;
        case 6:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode07);
            break;
        case 7:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode08);
            break;
        case 8:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode09);
            break;
        case 9:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode10);
            break;
        case 10:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode11);
            break;
        case 11:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode12);
            break;
        case 12:
            var_0 = ShowTelevisionMessage(gText_TV_MineResearchGroup_Episode13);
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
