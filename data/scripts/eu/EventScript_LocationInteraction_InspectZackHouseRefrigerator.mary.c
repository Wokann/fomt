#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectZackHouseRefrigerator[] =
        "Refrigerator{Press}";
};

void EventScript_LocationInteraction_InspectZackHouseRefrigerator(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectZackHouseRefrigerator);
    TalkClose();
}
