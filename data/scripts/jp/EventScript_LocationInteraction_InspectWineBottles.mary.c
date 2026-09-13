#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectWineBottles[] =
        "酒棚{Press}";
};

void EventScript_LocationInteraction_InspectWineBottles(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectWineBottles);
    TalkClose();
}
