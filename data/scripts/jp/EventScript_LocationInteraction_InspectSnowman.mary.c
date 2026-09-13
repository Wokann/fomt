#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectSnowman_Plants[] =
        "植物{Press}";

    const char gText_LocationInteraction_InspectSnowman_Snowman[] =
        "雪だるま{Press}";
};

void EventScript_LocationInteraction_InspectSnowman(void)
{
    TalkOpen();
    if (VarGet(VAR_SEASON) == SEASON_WINTER)
    {
        if (VarGet(VAR_DAY) == DAY_OF_MONTH_01 && VarGet(VAR_HOUR) < 6)
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
