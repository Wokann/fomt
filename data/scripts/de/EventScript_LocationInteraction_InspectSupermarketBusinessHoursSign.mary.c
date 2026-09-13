#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectSupermarketBusinessHoursSign[] =
        "Supermarkt\r\n"
        "9-16 Uhr geöffnet\r\n"
        "dienstags und samstags{Press}\r\n"
        "geschlossen{Press}";
};

void EventScript_LocationInteraction_InspectSupermarketBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketBusinessHoursSign);
    TalkClose();
}
