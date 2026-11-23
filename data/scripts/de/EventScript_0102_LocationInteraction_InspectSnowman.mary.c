#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0102_LocationInteraction_InspectSnowman.mary.h"

void EventScript_0102_LocationInteraction_InspectSnowman(void)
{
    TalkOpen();
    if (VarGet(VAR_SEASON) == SEASON_WINTER)
    {
        if (VarGet(VAR_DAY) == DAY_01 && VarGet(VAR_HOUR) < 6)
        {
            TalkAppendMessage(gText_LocationInteraction_InspectSnowman_Plants);
        }
        else
        {
            TalkAppendMessage(gText_LocationInteraction_InspectSnowman_Snowman);
        }
    }
    else
    {
        TalkAppendMessage(gText_LocationInteraction_InspectSnowman_Plants);
    }
    TalkClose();
}
