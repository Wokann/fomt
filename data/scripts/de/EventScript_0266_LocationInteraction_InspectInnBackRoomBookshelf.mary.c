#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0266_LocationInteraction_InspectInnBackRoomBookshelf.mary.h"

void EventScript_0266_LocationInteraction_InspectInnBackRoomBookshelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBackRoomBookshelf);
    TalkClose();
}
