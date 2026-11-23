#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0255_LocationInteraction_InspectInnBackRoomChair.mary.h"

void EventScript_0255_LocationInteraction_InspectInnBackRoomChair(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBackRoomChair);
    TalkClose();
}
