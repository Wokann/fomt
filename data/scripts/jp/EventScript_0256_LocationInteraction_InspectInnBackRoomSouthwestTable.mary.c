#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0256_LocationInteraction_InspectInnBackRoomSouthwestTable.mary.h"

void EventScript_0256_LocationInteraction_InspectInnBackRoomSouthwestTable(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBackRoomSouthwestTable);
    TalkClose();
}
