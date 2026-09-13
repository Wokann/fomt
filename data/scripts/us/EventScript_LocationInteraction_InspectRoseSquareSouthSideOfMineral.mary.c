#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectRoseSquareSouthSideOfMineral[] =
        "　　　　　　　↑Rose Square\r\n"
        "　\r\n"
        "←South side of Mineral Town{Press}";
};

void EventScript_LocationInteraction_InspectRoseSquareSouthSideOfMineral(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectRoseSquareSouthSideOfMineral);
    TalkClose();
}
