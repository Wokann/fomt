#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectDesk[] =
        "勉強机{Press}";
};

void EventScript_LocationInteraction_InspectDesk(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectDesk);
    TalkClose();
}
