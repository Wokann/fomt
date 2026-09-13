#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectWineryBasementStairs[] =
        "Stairs to Basement{Press}";
};

void EventScript_LocationInteraction_InspectWineryBasementStairs(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectWineryBasementStairs);
    TalkClose();
}
