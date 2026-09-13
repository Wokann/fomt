#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectClinicBusinessHoursSign[] =
        "Mineral Clinic\r\n"
        "Office Hours: 9AM-4PM\r\n"
        "Closed on Wednesdays{Press}";
};

void EventScript_LocationInteraction_InspectClinicBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinicBusinessHoursSign);
    TalkClose();
}
