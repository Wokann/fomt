#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectLargeStoneRequiresHigherHammerLevel[] =
        "Large Stone\r\n"
        "Your Hammer can't crush\r\n"
        "it unless it's LV2{Press}\r\n"
        "or higher.{Press}";
};

void EventScript_LocationInteraction_InspectLargeStoneRequiresHigherHammerLevel(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLargeStoneRequiresHigherHammerLevel);
    TalkClose();
}
