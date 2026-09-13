#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectHotSpringSign[] =
        "Hot Spring\r\n"
        "Effects: Recuperate \r\n"
        "Stamina and Fatigue{Press}";
};

void EventScript_LocationInteraction_InspectHotSpringSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHotSpringSign);
    TalkClose();
}
