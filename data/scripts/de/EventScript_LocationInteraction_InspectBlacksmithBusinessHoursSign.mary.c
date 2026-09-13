#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBlacksmithBusinessHoursSign[] =
        "Saibara der Schmied\r\n"
        "10-16 Uhr geöffnet\r\n"
        "donnerstags geschlossen{Press}";
};

void EventScript_LocationInteraction_InspectBlacksmithBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithBusinessHoursSign);
    TalkClose();
}
