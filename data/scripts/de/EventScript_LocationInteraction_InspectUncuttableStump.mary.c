#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectUncuttableStump[] =
        "Deine Axt kann diesen\r\n"
        "Stumpf nicht zerhacken, au-\r\n"
        "ßer sie ist LV2 oder höher.{Press}";
};

void EventScript_LocationInteraction_InspectUncuttableStump(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectUncuttableStump);
    TalkClose();
}
