#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectAjaWineryBusinessHoursSign[] =
        "Ajas Weingut\r\n"
        "Geöffnet von 10-12 Uhr\r\n"
// The sign says Sunday, but the winery shop actually closes on Saturday.
#ifdef BUGFIX
        "Täglich außer samstags{Press}\r\n"
#else
        "Täglich außer sonntags{Press}\r\n"
#endif
        "Wir verkaufen Wein und Saft.{Press}";
};

void EventScript_LocationInteraction_InspectAjaWineryBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectAjaWineryBusinessHoursSign);
    TalkClose();
}
