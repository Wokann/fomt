#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBlacksmithBusinessHoursSign[] =
        "「鍛冶屋サイバラ」\r\n"
        "午前１０時～午後４時。\r\n"
        "木曜休日。{Press}";
};

void EventScript_LocationInteraction_InspectBlacksmithBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithBusinessHoursSign);
    TalkClose();
}
