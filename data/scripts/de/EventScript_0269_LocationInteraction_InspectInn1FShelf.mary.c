#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0269_LocationInteraction_InspectInn1FShelf.mary.h"

void EventScript_0269_LocationInteraction_InspectInn1FShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInn1FShelf);
    TalkClose();
}
