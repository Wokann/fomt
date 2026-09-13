#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectAjaWineryBusinessHoursSign[] =
        "Ajas Weingut\r\n"
        "Geöffnet von 10-12 Uhr\r\n"
        "Täglich außer sonntags{Press}\r\n"
        "Wir verkaufen Wein und Saft.{Press}";
};

void EventScript_LocationInteraction_InspectAjaWineryBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWineryBusinessHoursSign);
    TalkClose();
}
