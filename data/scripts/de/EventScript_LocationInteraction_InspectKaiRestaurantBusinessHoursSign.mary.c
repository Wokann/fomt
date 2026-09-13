#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectKaiRestaurantBusinessHoursSign[] =
        "Kais Strandhäuschen\r\n"
        "Nur im Sommer geöffnet\r\n"
        "sonntags geschlossen{Press}\p"
        "Öffnungszeiten: 11-13 Uhr\r\n"
        "und 17-19 Uhr. {Press}";
};

void EventScript_LocationInteraction_InspectKaiRestaurantBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectKaiRestaurantBusinessHoursSign);
    TalkClose();
}
