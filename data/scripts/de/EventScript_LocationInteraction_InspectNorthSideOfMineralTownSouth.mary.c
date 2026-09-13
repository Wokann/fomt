#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectNorthSideOfMineralTownSouth[] =
        "↑Norden von Mineralstadt\r\n"
        "Süden von Mineralstadt→\r\n"
        "↓{Place1}Farm{Press}";
};

void EventScript_LocationInteraction_InspectNorthSideOfMineralTownSouth(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectNorthSideOfMineralTownSouth);
    TalkClose();
}
