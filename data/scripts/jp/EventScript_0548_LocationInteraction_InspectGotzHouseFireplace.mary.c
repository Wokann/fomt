#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0548_LocationInteraction_InspectGotzHouseFireplace.mary.h"

void EventScript_0548_LocationInteraction_InspectGotzHouseFireplace(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHouseFireplace);
    TalkClose();
}
