#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBigKitchen[] =
        "大きい台所{Press}";
};

void EventScript_LocationInteraction_InspectBigKitchen(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBigKitchen);
    TalkClose();
}
