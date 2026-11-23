#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0419_LocationInteraction_InspectAjaWineryBasementBarrelShelf.mary.h"

void EventScript_0419_LocationInteraction_InspectAjaWineryBasementBarrelShelf(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWineryBasementBarrelShelf);
    TalkClose();
}
