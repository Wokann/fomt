#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0244_LocationInteraction_InspectClinic2FSofa.mary.h"

void EventScript_0244_LocationInteraction_InspectClinic2FSofa(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic2FSofa);
    TalkClose();
}
