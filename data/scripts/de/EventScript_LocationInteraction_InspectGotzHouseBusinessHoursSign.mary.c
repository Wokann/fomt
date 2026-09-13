#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectGotzHouseBusinessHoursSign[] =
        "Holzfäller \r\n"
        "11-16 Uhr geöffnet\r\n"
        "samstags geschlossen{Press}";
};

void EventScript_LocationInteraction_InspectGotzHouseBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHouseBusinessHoursSign);
    TalkClose();
}
