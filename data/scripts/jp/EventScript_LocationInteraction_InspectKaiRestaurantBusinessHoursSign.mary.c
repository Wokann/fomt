#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectKaiRestaurantBusinessHoursSign[] =
        "カイの海の家\r\n"
        "夏季限定営業\r\n"
        "休日　日曜日{Press}\p"
        "開店時間\r\n"
        "午前１１時～午後１時\r\n"
        "午後　５時～午後７時{Press}";
};

void EventScript_LocationInteraction_InspectKaiRestaurantBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectKaiRestaurantBusinessHoursSign);
    TalkClose();
}
