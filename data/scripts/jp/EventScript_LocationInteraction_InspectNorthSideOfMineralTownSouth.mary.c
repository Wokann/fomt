#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectNorthSideOfMineralTownSouth[] =
        "↑ミネラルタウン北側\r\n"
        "　　　　ミネラルタウン南側→\r\n"
        "↓{Place1}牧場{Press}";
};

void EventScript_LocationInteraction_InspectNorthSideOfMineralTownSouth(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectNorthSideOfMineralTownSouth);
    TalkClose();
}
