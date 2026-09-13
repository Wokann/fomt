#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectTownNorthSouthEntranceSign[] =
        "↑ミネラルタウン北側\r\n"
        "　　　ミネラルタウン中央部→\r\n"
        "↓ミネラルタウン南側{Press}";
};

void EventScript_LocationInteraction_InspectTownNorthSouthEntranceSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTownNorthSouthEntranceSign);
    TalkClose();
}
