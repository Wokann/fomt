#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0551_LocationInteraction_InspectGotzHouseWoodBox.mary.h"

void EventScript_0551_LocationInteraction_InspectGotzHouseWoodBox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHouseWoodBox);
    TalkClose();
}
