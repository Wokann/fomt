#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectTownNorthCentralDistrictSign[] =
        "North side of Mineral Town→\r\n"
        "　\r\n"
        "↓Central Mineral Town{Press}";
};

void EventScript_LocationInteraction_InspectTownNorthCentralDistrictSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTownNorthCentralDistrictSign);
    TalkClose();
}
