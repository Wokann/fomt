#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectWineryBasementStairs[] =
        "地下室の階段{Press}";
};

void EventScript_LocationInteraction_InspectWineryBasementStairs(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectWineryBasementStairs);
    TalkClose();
}
