#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0236_LocationInteraction_InspectClinic1FSofa.mary.h"

void EventScript_0236_LocationInteraction_InspectClinic1FSofa(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectClinic1FSofa_InspectionLabel);
    TalkClose();
}
