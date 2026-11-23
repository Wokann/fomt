#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0162_LocationInteraction_InspectShipmentBox.mary.h"

void EventScript_0162_LocationInteraction_InspectShipmentBox(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectShipmentBox);
    TalkClose();
}
