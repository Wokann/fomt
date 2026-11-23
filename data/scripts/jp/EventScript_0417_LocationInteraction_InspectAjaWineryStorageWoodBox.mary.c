#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0417_LocationInteraction_InspectAjaWineryStorageWoodBox.mary.h"

void EventScript_0417_LocationInteraction_InspectAjaWineryStorageWoodBox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWineryStorageWoodBox);
    TalkClose();
}
