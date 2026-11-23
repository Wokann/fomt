#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0563_LocationInteraction_InspectYodelRanchHouse2FBed.mary.h"

void EventScript_0563_LocationInteraction_InspectYodelRanchHouse2FBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchHouse2FBed);
    TalkClose();
}
