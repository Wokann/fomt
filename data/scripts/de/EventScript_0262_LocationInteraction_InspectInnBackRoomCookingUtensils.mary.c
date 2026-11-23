#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0262_LocationInteraction_InspectInnBackRoomCookingUtensils.mary.h"

void EventScript_0262_LocationInteraction_InspectInnBackRoomCookingUtensils(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBackRoomCookingUtensils);
    TalkClose();
}
