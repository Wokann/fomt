#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0265_LocationInteraction_InspectInnBackRoomEastBed.mary.h"

void EventScript_0265_LocationInteraction_InspectInnBackRoomEastBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBackRoomEastBed);
    TalkClose();
}
