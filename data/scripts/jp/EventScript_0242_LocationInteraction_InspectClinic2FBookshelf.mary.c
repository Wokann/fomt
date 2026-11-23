#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0242_LocationInteraction_InspectClinic2FBookshelf.mary.h"

void EventScript_0242_LocationInteraction_InspectClinic2FBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic2FBookshelf);
    TalkClose();
}
