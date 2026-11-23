#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0254_LocationInteraction_InspectInnBackRoomWestBed.mary.h"

void EventScript_0254_LocationInteraction_InspectInnBackRoomWestBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBackRoomWestBed);
    TalkClose();
}
