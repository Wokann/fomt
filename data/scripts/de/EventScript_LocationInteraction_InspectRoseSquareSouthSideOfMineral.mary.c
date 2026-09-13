#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectRoseSquareSouthSideOfMineral[] =
        "       ↑Rosenplatz\r\n"
        " \r\n"
        "←Süden von Mineralstadt{Press}";
};

void EventScript_LocationInteraction_InspectRoseSquareSouthSideOfMineral(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectRoseSquareSouthSideOfMineral);
    TalkClose();
}
