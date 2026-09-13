#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectTownNorthLibraryHoursSign_InspectTownNorthLibraryHoursAfterMaryMarriage[] =
        "Marys Bibliothek\r\n"
        "Öffnet: 10 Uhr\r\n"
        "Schließt: 16 Uhr, Donners-{Press}\r\n"
        "tags geschlossen{Press}";

    const char gText_LocationInteraction_InspectTownNorthLibraryHoursSign_InspectTownNorthLibraryHoursBeforeMaryMarriage[] =
        "Marys Bibliothek\r\n"
        "Öffnet: 10 Uhr\r\n"
        "Schließt: 16 Uhr, montags {Press}\r\n"
        "geschlossen{Press}";
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
