#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectBlacksmithShovel[] =
        "スコップ{Press}";
};

void EventScript_LocationInteraction_InspectBlacksmithShovel(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectBlacksmithShovel);
    TalkClose();
}
