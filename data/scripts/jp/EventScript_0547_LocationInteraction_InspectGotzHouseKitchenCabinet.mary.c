#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0547_LocationInteraction_InspectGotzHouseKitchenCabinet.mary.h"

void EventScript_0547_LocationInteraction_InspectGotzHouseKitchenCabinet(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHouseKitchenCabinet);
    TalkClose();
}
