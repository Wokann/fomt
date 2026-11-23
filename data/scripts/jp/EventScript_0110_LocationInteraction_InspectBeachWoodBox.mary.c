#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0110_LocationInteraction_InspectBeachWoodBox.mary.h"

void EventScript_0110_LocationInteraction_InspectBeachWoodBox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBeachWoodBox);
    TalkClose();
}
