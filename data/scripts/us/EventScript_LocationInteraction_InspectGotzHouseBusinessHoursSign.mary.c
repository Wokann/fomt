#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectGotzHouseBusinessHoursSign[] =
        "Woodcutter's \r\n"
        "Open 11AM-4PM\r\n"
        "Closed Saturdays{Press}";
};

void EventScript_LocationInteraction_InspectGotzHouseBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHouseBusinessHoursSign);
    TalkClose();
}
