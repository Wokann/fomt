#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectYodelRanchBusinessHoursSign[] =
        "Yodel Farm\r\n"
        "We're open 10AM to \r\n"
        "3PM, except Mondays{Press}";
};

void EventScript_LocationInteraction_InspectYodelRanchBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchBusinessHoursSign);
    TalkClose();
}
