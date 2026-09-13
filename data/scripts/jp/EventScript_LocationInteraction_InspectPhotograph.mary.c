#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectPhotograph[] =
        "写真{Press}";
};

void EventScript_LocationInteraction_InspectPhotograph(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectPhotograph);
    TalkClose();
}
