#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectPoultryFarmBusinessHoursSign[] =
        "Poultry Farm\r\n"
        "Open 11AM-4PM\r\n"
        "Closed every Sunday{Press}";
};

void EventScript_LocationInteraction_InspectPoultryFarmBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectPoultryFarmBusinessHoursSign);
    TalkClose();
}
