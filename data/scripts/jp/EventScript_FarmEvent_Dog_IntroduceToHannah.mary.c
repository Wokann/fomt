#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Dog_IntroduceToHannah[] =
        "やあ、ハナちゃん。\r\n"
        "{Dog}と\r\n"
        "仲良くしてやってね。{Press}";
};

void EventScript_FarmEvent_Dog_IntroduceToHannah(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Dog_IntroduceToHannah);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_DOG_BARK);
}
