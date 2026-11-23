#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0232_LocationInteraction_InspectClinic1FEastBookshelf.mary.h"

void EventScript_0232_LocationInteraction_InspectClinic1FEastBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic1FEastBookshelf);
    TalkClose();
}
