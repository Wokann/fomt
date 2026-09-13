#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBlacksmithBusinessHoursSign[] =
        "Saibara the Blacksmith\r\n"
        "Open 10AM-4PM\r\n"
        "Closed Thursdays{Press}";
};

void EventScript_LocationInteraction_InspectBlacksmithBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithBusinessHoursSign);
    TalkClose();
}
