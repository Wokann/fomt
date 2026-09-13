#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectGotzHouseBusinessHoursSign[] =
        "「木こりの家」\r\n"
        "午前１１時～午後４時。\r\n"
        "土曜日定休日。{Press}";
};

void EventScript_LocationInteraction_InspectGotzHouseBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectGotzHouseBusinessHoursSign);
    TalkClose();
}
