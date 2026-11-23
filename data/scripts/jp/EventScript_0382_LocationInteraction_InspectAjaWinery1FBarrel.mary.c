#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0382_LocationInteraction_InspectAjaWinery1FBarrel.mary.h"

void EventScript_0382_LocationInteraction_InspectAjaWinery1FBarrel(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWinery1FBarrel);
    TalkClose();
}
