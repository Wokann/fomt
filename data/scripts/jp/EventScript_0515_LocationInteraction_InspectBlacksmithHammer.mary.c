#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0515_LocationInteraction_InspectBlacksmithHammer.mary.h"

void EventScript_0515_LocationInteraction_InspectBlacksmithHammer(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithHammer);
    TalkClose();
}
