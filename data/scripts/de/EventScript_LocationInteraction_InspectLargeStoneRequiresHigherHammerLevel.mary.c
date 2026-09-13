#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectLargeStoneRequiresHigherHammerLevel[] =
        "Großer Stein\r\n"
        "Dein Hammer kann ihn\r\n"
        "nicht zertrümmern, außer{Press}\r\n"
        "er ist LV 2 oder besser.{Press}";
};

void EventScript_LocationInteraction_InspectLargeStoneRequiresHigherHammerLevel(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectLargeStoneRequiresHigherHammerLevel);
    TalkClose();
}
