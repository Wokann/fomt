#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0407_LocationInteraction_InspectPestleAndMortar.mary.h"

void EventScript_0407_LocationInteraction_InspectPestleAndMortar(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectPestleAndMortar);
    TalkClose();
}
