#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0414_LocationInteraction_InspectAjaWineryStorageShelf.mary.h"

void EventScript_0414_LocationInteraction_InspectAjaWineryStorageShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWineryStorageShelf);
    TalkClose();
}
