#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0496_LocationInteraction_InspectSupermarketBusinessHoursSign.mary.h"

void EventScript_0496_LocationInteraction_InspectSupermarketBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketBusinessHoursSign);
    TalkClose();
}
