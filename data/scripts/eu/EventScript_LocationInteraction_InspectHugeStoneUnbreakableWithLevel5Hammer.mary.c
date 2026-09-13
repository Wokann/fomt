#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer[] =
        "Huge Stone\r\n"
        "Your Hammer is LV5,\r\n"
        "but it can't crush{Press}\r\n"
        "this Sone.{Press}";
};

void EventScript_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer);
    TalkClose();
}
