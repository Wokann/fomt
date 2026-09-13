#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectYodelRanchBusinessHoursSign[] =
        "Jodel-Farm\r\n"
        "Wir haben von 10 bis \r\n"
        "15 Uhr geöffnet, außer{Press}\r\n"
        "montags{Press}";
};

void EventScript_LocationInteraction_InspectYodelRanchBusinessHoursSign(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectYodelRanchBusinessHoursSign);
    TalkClose();
}
