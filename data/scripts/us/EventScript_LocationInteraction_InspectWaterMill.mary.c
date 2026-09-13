#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectWaterMill[] =
        "↑Water Mill\r\n"
        "Put Corn in here to get\r\n"
        "30 bushels of Chicken Feed.{Press}";
};

void EventScript_LocationInteraction_InspectWaterMill(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectWaterMill);
    TalkClose();
}
