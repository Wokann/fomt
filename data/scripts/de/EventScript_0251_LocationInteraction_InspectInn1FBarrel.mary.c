#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0251_LocationInteraction_InspectInn1FBarrel.mary.h"

void EventScript_0251_LocationInteraction_InspectInn1FBarrel(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInn1FBarrel);
    TalkClose();
}
