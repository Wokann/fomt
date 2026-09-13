#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectSupermarketBusinessHoursSign[] =
        "「ザっか屋」\r\n"
        "午前９時から午後５時まで。\r\n"
        "火曜日と日曜日はお休みです。{Press}";
};

void EventScript_LocationInteraction_InspectSupermarketBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectSupermarketBusinessHoursSign);
    TalkClose();
}
