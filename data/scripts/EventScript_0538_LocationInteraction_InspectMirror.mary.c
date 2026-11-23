#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0538_LocationInteraction_InspectMirror.mary.h"

void EventScript_0538_LocationInteraction_InspectMirror(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectMirror);
    TalkClose();
}
