#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectAjaWineryStorageWoodBox[] =
        "Wood Box{Press}";
};

void EventScript_LocationInteraction_InspectAjaWineryStorageWoodBox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWineryStorageWoodBox);
    TalkClose();
}
