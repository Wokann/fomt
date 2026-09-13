#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectUncuttableStump[] =
        "Your Axe can't\r\n"
        "cut this stump unless it's\r\n"
        "LV2 or higher.{Press}";
};

void EventScript_LocationInteraction_InspectUncuttableStump(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectUncuttableStump);
    TalkClose();
}
