#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectWaterMill[] =
        "↑Wassermühle\r\n"
        "Gib Getreide hinein, für\r\n"
        "30 Einheiten Hühnerfutter.{Press}";
};

void EventScript_LocationInteraction_InspectWaterMill(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectWaterMill);
    TalkClose();
}
