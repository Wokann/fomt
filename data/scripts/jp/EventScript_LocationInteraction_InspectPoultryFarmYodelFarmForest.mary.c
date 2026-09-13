#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectPoultryFarmYodelFarmForest[] =
        "←にわとりりあ\r\n"
        "　　　　　　　ヨーデル牧場→\r\n"
        "↓森{Press}";
};

void EventScript_LocationInteraction_InspectPoultryFarmYodelFarmForest(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectPoultryFarmYodelFarmForest);
    TalkClose();
}
