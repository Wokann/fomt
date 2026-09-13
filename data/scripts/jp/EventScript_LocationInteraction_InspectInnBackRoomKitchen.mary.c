#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectInnBackRoomKitchen[] =
        "台所{Press}";
};

void EventScript_LocationInteraction_InspectInnBackRoomKitchen(void)
{
    TalkOpen();
    TalkAppendMessage(gText_LocationInteraction_InspectInnBackRoomKitchen);
    TalkClose();
}
