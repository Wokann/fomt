#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectChurchNorthSideOfMineralTown[] =
        "　　　　　　　　　　　教会↑\r\n"
        "←ミネラルタウン北側　\r\n"
        "　　　　　　　　ローズ広場↓{Press}";
};

void EventScript_LocationInteraction_InspectChurchNorthSideOfMineralTown(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectChurchNorthSideOfMineralTown);
    TalkClose();
}
