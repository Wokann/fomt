#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0543_LocationInteraction_InspectGotzHouseChair.mary.h"

void EventScript_0543_LocationInteraction_InspectGotzHouseChair(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHouseChair);
    TalkClose();
}
