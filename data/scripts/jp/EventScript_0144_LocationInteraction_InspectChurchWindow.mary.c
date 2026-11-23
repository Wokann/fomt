#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0144_LocationInteraction_InspectChurchWindow.mary.h"

void EventScript_0144_LocationInteraction_InspectChurchWindow(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectChurchWindow);
    TalkClose();
}
