#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0431_LocationInteraction_InspectBeachHouseWindow.mary.h"

void EventScript_0431_LocationInteraction_InspectBeachHouseWindow(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectBeachHouseWindow);
    TalkClose();
}
