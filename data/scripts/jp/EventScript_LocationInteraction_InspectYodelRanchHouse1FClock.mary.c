#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectYodelRanchHouse1FClock[] =
        "時計{Press}";
};

void EventScript_LocationInteraction_InspectYodelRanchHouse1FClock(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchHouse1FClock);
    TalkClose();
}
