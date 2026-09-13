#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectMirror[] =
        "鏡{Press}";
};

void EventScript_LocationInteraction_InspectMirror(void)
{
    TalkOpen();
    TalkMessage(gText_LocationInteraction_InspectMirror);
    TalkClose();
}
