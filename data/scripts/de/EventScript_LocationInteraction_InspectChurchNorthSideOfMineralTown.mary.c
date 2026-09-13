#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectChurchNorthSideOfMineralTown[] =
        "　　　　　　　　　　Kirche↑\r\n"
        "←Norden von Mineralstadt,\r\n"
        "\t     Rosenplatz↓{Press}";
};

void EventScript_LocationInteraction_InspectChurchNorthSideOfMineralTown(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectChurchNorthSideOfMineralTown);
    TalkClose();
}
