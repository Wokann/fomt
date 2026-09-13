#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectInnBusinessHoursSign[] =
        "Dougs Gasthof\r\n"
        "Geöffnet: 8:00 - 21:00 Uhr{Press}";
};

void EventScript_LocationInteraction_InspectInnBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBusinessHoursSign);
    TalkClose();
}
