#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectLilliaHouse1FSofa[] =
        "ソファ{Press}";
};

void EventScript_LocationInteraction_InspectLilliaHouse1FSofa(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLilliaHouse1FSofa);
    TalkClose();
}
