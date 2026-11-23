#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0502_LocationInteraction_InspectTownNorthLibraryHoursSign.mary.h"

void EventScript_0502_LocationInteraction_InspectTownNorthLibraryHoursSign(void)
{
    TalkOpen();
    if (VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        TalkAppendMessage(gText_LocationInteraction_InspectTownNorthLibraryHoursSign_InspectTownNorthLibraryHoursAfterMaryMarriage);
    }
    else
    {
        TalkAppendMessage(gText_LocationInteraction_InspectTownNorthLibraryHoursSign_InspectTownNorthLibraryHoursBeforeMaryMarriage);
    }
    TalkClose();
}
