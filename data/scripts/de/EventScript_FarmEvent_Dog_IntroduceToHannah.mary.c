#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Dog_IntroduceToHannah[] =
        "Nun spiel schön mit\r\n"
        "{Dog}, Hannah.\r\n"
        "{Press}";
};

void EventScript_FarmEvent_Dog_IntroduceToHannah(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Dog_IntroduceToHannah);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_DOG_BARK);
}
