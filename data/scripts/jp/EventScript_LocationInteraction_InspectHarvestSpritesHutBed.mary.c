#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectHarvestSpritesHutBed[] =
        "ベッド{Press}";
};

void EventScript_LocationInteraction_InspectHarvestSpritesHutBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectHarvestSpritesHutBed);
    TalkClose();
}
