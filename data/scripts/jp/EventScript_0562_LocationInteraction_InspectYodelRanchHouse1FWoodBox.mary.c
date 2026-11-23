#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0562_LocationInteraction_InspectYodelRanchHouse1FWoodBox.mary.h"

void EventScript_0562_LocationInteraction_InspectYodelRanchHouse1FWoodBox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchHouse1FWoodBox);
    TalkClose();
}
