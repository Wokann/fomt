#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectTownNorthCentralDistrictSign[] =
        "　　　　ミネラルタウン北側→\r\n"
        "　\r\n"
        "↓ミネラルタウン中央部{Press}";
};

void EventScript_LocationInteraction_InspectTownNorthCentralDistrictSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectTownNorthCentralDistrictSign);
    TalkClose();
}
