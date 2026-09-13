#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectInnBusinessHoursSign[] =
        "Doug's Place\r\n"
        "Bar Hours: 8:00 - 21:00{Press}";
};

void EventScript_LocationInteraction_InspectInnBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBusinessHoursSign);
    TalkClose();
}
