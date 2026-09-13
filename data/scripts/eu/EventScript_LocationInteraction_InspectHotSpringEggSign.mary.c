#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectHotSpringEggSign[] =
        "If you throw an Egg in\r\n"
        "from here, you can make a\r\n"
        "Spa-Boiled Egg!{Press}";
};

void EventScript_LocationInteraction_InspectHotSpringEggSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHotSpringEggSign);
    TalkClose();
}
