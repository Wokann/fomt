#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0263_LocationInteraction_InspectInnBackRoomRefrigerator.mary.h"

void EventScript_0263_LocationInteraction_InspectInnBackRoomRefrigerator(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBackRoomRefrigerator);
    TalkClose();
}
