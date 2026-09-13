#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectWaterMill[] =
        "↑水車小屋\r\n"
        "ここにとうもろこしを入れると\r\n"
        "鶏のエサが３０コできる。{Press}";
};

void EventScript_LocationInteraction_InspectWaterMill(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectWaterMill);
    TalkClose();
}
