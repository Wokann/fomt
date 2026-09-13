#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectHotSpringEggSign[] =
        "ここから卵を投げ込めば\r\n"
        "温泉たまごができあがる。\r\n"
        "{Press}";
};

void EventScript_LocationInteraction_InspectHotSpringEggSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHotSpringEggSign);
    TalkClose();
}
