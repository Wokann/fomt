#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0011_FarmEvent_Cow_DoingWellMessage.mary.h"

void EventScript_0011_FarmEvent_Cow_DoingWellMessage(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Cow_DoingWellMessage);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_COW_MOO);
}
