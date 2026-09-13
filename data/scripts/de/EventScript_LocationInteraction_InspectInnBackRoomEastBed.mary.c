#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectInnBackRoomEastBed[] =
        "Bett{Press}";
};

void EventScript_LocationInteraction_InspectInnBackRoomEastBed(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBackRoomEastBed);
    TalkClose();
}
