#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0231_LocationInteraction_InspectClinic1FCenterBookshelf.mary.h"

void EventScript_0231_LocationInteraction_InspectClinic1FCenterBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic1FCenterBookshelf);
    TalkClose();
}
