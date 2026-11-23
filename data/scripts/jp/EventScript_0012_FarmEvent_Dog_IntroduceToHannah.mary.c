#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0012_FarmEvent_Dog_IntroduceToHannah.mary.h"

void EventScript_0012_FarmEvent_Dog_IntroduceToHannah(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Dog_IntroduceToHannah);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_DOG_BARK);
}
