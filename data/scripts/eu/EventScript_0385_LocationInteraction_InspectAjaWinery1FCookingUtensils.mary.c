#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0385_LocationInteraction_InspectAjaWinery1FCookingUtensils.mary.h"

void EventScript_0385_LocationInteraction_InspectAjaWinery1FCookingUtensils(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWinery1FCookingUtensils);
    TalkClose();
}
