#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0003_LocationInteraction_ShowNothingHappenedMessage.mary.h"

void EventScript_0003_LocationInteraction_ShowNothingHappenedMessage(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_ShowNothingHappenedMessage);
    TalkClose();
}
