#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0408_LocationInteraction_InspectSquaresStreetLamp.mary.h"

void EventScript_0408_LocationInteraction_InspectSquaresStreetLamp(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSquaresStreetLamp);
    TalkClose();
}
