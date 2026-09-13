#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectZackHouseLilliaPhoto_UnidentifiedBeforeMeetingLillia[] =
        "Who is this photo of...?{Press}";

    const char gText_LocationInteraction_InspectZackHouseLilliaPhoto_IdentifiesLilliaAfterMeeting[] =
        "It's a photo of Lillia.{Press}";
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
