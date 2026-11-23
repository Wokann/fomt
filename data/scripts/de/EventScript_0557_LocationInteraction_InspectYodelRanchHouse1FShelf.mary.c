#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0557_LocationInteraction_InspectYodelRanchHouse1FShelf.mary.h"

void EventScript_0557_LocationInteraction_InspectYodelRanchHouse1FShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchHouse1FShelf);
    TalkClose();
}
