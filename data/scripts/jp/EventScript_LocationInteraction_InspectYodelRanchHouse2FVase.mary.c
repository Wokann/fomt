#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectYodelRanchHouse2FVase[] =
        "花瓶{Press}";
};

void EventScript_LocationInteraction_InspectYodelRanchHouse2FVase(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchHouse2FVase);
    TalkClose();
}
