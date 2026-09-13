#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectNorthSideOfMineralTownSouth[] =
        "↑North side of Mineral Town\r\n"
        "South side of Mineral Town→\r\n"
        "↓{Place1}farm{Press}";
};

void EventScript_LocationInteraction_InspectNorthSideOfMineralTownSouth(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectNorthSideOfMineralTownSouth);
    TalkClose();
}
