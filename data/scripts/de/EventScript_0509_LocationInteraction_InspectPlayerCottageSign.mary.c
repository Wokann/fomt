#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0509_LocationInteraction_InspectPlayerCottageSign.mary.h"

void EventScript_0509_LocationInteraction_InspectPlayerCottageSign(void)
{
    TalkOpen();
    if (VarGet(VAR_HAS_TOWN_COTTAGE) == TRUE)
    {
        TalkAppendMessage(gText_LocationInteraction_InspectPlayerCottageSign_CottageSign);
    }
    else
    {
        TalkAppendMessage(gText_LocationInteraction_InspectPlayerCottageSign_EmptyLotSign);
    }
    TalkClose();
}
