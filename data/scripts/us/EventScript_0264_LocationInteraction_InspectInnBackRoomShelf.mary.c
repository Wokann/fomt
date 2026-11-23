#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0264_LocationInteraction_InspectInnBackRoomShelf.mary.h"

void EventScript_0264_LocationInteraction_InspectInnBackRoomShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBackRoomShelf);
    TalkClose();
}
