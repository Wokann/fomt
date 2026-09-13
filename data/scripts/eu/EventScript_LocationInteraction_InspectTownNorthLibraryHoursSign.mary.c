#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectTownNorthLibraryHoursSign_InspectTownNorthLibraryHoursAfterMaryMarriage[] =
        "Mary's Library\r\n"
        "Open: 10AM\r\n"
        "Closed: 4PM  Closed Thursdays{Press}";

    const char gText_LocationInteraction_InspectTownNorthLibraryHoursSign_InspectTownNorthLibraryHoursBeforeMaryMarriage[] =
        "Mary's Library\r\n"
        "Open: 10AM\r\n"
        "Closed: 4PM  Closed Mondays{Press}";
};

void EventScript_LocationInteraction_InspectTownNorthLibraryHoursSign(void)
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
