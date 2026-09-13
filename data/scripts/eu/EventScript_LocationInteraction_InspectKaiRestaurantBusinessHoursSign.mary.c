#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectKaiRestaurantBusinessHoursSign[] =
        "Kai's Beach House\r\n"
        "Open Summer Only\r\n"
        "Closed Sunday{Press}\p"
        "Hours: 11AM-1PM and\r\n"
        "5-7PM. {Press}";
};

void EventScript_LocationInteraction_InspectKaiRestaurantBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectKaiRestaurantBusinessHoursSign);
    TalkClose();
}
