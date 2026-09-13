#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectChurchNorthSideOfMineralTown[] =
        "　　　　　　　　　　Church↑\r\n"
        "←North side of Mineral Town\r\n"
        "　　　　　Rose Square↓{Press}";
};

void EventScript_LocationInteraction_InspectChurchNorthSideOfMineralTown(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectChurchNorthSideOfMineralTown);
    TalkClose();
}
