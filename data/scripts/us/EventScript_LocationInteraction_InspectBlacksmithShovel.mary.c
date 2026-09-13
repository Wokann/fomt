#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBlacksmithShovel[] =
        "Shovel{Press}";
};

void EventScript_LocationInteraction_InspectBlacksmithShovel(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithShovel);
    TalkClose();
}
