#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer[] =
        "Großer Stein\r\n"
        "Dein Hammer ist LV5,\r\n"
        "also kann er diesen Stein{Press}\r\n"
        "nicht zertrümmern.{Press}";
};

void EventScript_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer);
    TalkClose();
}
