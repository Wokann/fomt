#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer[] =
        "大きい岩\r\n"
        "ハンマーのためＬＶ５を\r\n"
        "使っても壊せない。{Press}";
};

void EventScript_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer);
    TalkClose();
}
