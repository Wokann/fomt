#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0421_LocationInteraction_InspectAjaWineryBasementShelf.mary.h"

void EventScript_0421_LocationInteraction_InspectAjaWineryBasementShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWineryBasementShelf);
    TalkClose();
}
