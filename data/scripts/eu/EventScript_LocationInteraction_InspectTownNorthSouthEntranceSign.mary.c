#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectTownNorthSouthEntranceSign[] =
        "↑North side of Mineral Town\r\n"
        "　Central Mineral Town→\r\n"
        "↓South side of Mineral Town{Press}";
};

void EventScript_LocationInteraction_InspectTownNorthSouthEntranceSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTownNorthSouthEntranceSign);
    TalkClose();
}
