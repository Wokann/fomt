#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectAjaWineryBusinessHoursSign[] =
        "Aja Winery\r\n"
        "Open 10AM to noon\r\n"
        "everyday except Sunday{Press}\r\n"
        "We sell wine and juice.{Press}";
};

void EventScript_LocationInteraction_InspectAjaWineryBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWineryBusinessHoursSign);
    TalkClose();
}
