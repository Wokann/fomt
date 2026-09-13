#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectUnbreakableStone[] =
        "Your Hammer can't crush\r\n"
        "this Stone unless it's\r\n"
        "LV3 or higher.{Press}";
};

void EventScript_LocationInteraction_InspectUnbreakableStone(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectUnbreakableStone);
    TalkClose();
}
