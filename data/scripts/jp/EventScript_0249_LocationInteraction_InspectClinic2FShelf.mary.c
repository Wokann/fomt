#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0249_LocationInteraction_InspectClinic2FShelf.mary.h"

void EventScript_0249_LocationInteraction_InspectClinic2FShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic2FShelf);
    TalkClose();
}
