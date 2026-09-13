#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectPoultryFarmBusinessHoursSign[] =
        "「にわとりりあ」\r\n"
        "ＡＭ１１時～ＰＭ４時開いて\r\n"
        "ます。日曜日は定休日です。{Press}";
};

void EventScript_LocationInteraction_InspectPoultryFarmBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectPoultryFarmBusinessHoursSign);
    TalkClose();
}
