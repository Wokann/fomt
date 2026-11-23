#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0235_LocationInteraction_InspectClinic1FShelf.mary.h"

void EventScript_0235_LocationInteraction_InspectClinic1FShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic1FShelf);
    TalkClose();
}
