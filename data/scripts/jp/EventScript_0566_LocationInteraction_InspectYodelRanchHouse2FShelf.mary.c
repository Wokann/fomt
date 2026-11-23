#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0566_LocationInteraction_InspectYodelRanchHouse2FShelf.mary.h"

void EventScript_0566_LocationInteraction_InspectYodelRanchHouse2FShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchHouse2FShelf);
    TalkClose();
}
