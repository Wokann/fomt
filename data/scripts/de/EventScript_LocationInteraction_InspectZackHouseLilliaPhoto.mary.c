#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectZackHouseLilliaPhoto_UnidentifiedBeforeMeetingLillia[] =
        "Wer ist da auf dem Foto?{Press}";

    const char gText_LocationInteraction_InspectZackHouseLilliaPhoto_IdentifiesLilliaAfterMeeting[] =
        "Das ist Lillia.{Press}";
};

void EventScript_LocationInteraction_InspectZackHouseLilliaPhoto(void)
{
    TalkOpen();
    if (HasMetNpc(CHARACTER_LILLIA) == FALSE)
    {
        TalkAppendMessage(gText_LocationInteraction_InspectZackHouseLilliaPhoto_UnidentifiedBeforeMeetingLillia);
    }
    else
    {
        TalkAppendMessage(gText_LocationInteraction_InspectZackHouseLilliaPhoto_IdentifiesLilliaAfterMeeting);
    }
    TalkClose();
}
