#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer[] =
        "Huge Stone\r\n"
// Even an LV5 hammer cannot break this rock; this is not the player's current level.
#ifdef BUGFIX
        "Even if your Hammer is LV5,\r\n"
        "it can't crush{Press}\r\n"
        "this Stone.{Press}";
#else
        "Your Hammer is LV5,\r\n"
        "but it can't crush{Press}\r\n"
        "this Sone.{Press}";
#endif
};

void EventScript_0969_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer);
    TalkClose();
}
