#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer[] =
        "Großer Stein\r\n"
// Even an LV5 hammer cannot break this rock; this is not the player's current level.
#ifdef BUGFIX
        "Auch auf LV5 kann dein\r\n"
        "Hammer diesen Stein{Press}\r\n"
        "nicht zertrümmern.{Press}";
#else
        "Dein Hammer ist LV5,\r\n"
        "also kann er diesen Stein{Press}\r\n"
        "nicht zertrümmern.{Press}";
#endif
};

void EventScript_0969_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHugeStoneUnbreakableWithLevel5Hammer);
    TalkClose();
}
