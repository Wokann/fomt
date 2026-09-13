#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectSupermarketBusinessHoursSign[] =
        "Supermarket\r\n"
        "Open 9AM-5PM\r\n"
        "Closed Tuesdays and Sundays{Press}";
};

void EventScript_LocationInteraction_InspectSupermarketBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketBusinessHoursSign);
    TalkClose();
}
