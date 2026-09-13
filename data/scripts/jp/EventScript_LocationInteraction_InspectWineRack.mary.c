#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectWineRack[] =
        "ワイン棚{Press}";
};

void EventScript_LocationInteraction_InspectWineRack(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectWineRack);
    TalkClose();
}
