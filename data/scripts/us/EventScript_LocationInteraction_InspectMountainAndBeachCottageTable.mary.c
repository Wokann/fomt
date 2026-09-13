#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectMountainAndBeachCottageTable[] =
        "Table{Press}";
};

void EventScript_LocationInteraction_InspectMountainAndBeachCottageTable(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectMountainAndBeachCottageTable);
    TalkClose();
}
