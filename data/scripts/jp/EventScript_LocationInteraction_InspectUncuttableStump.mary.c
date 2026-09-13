#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectUncuttableStump[] =
        "切り株\r\n"
        "オノのためＬＶ２以上を\r\n"
        "使わないと壊せない。{Press}";
};

void EventScript_LocationInteraction_InspectUncuttableStump(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectUncuttableStump);
    TalkClose();
}
