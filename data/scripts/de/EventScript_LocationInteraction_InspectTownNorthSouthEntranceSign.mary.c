#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectTownNorthSouthEntranceSign[] =
        "↑Norden von Mineralstadt,\r\n"
        " Zentrum von Mineralstadt→\r\n"
        "↓Süden von Mineralstadt{Press}";
};

void EventScript_LocationInteraction_InspectTownNorthSouthEntranceSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTownNorthSouthEntranceSign);
    TalkClose();
}
