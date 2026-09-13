#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Cow_DoingWellMessage[] =
        "やあ、ここの牛は\r\n"
        "いつも元気だなぁ。{Press}";
};

void EventScript_FarmEvent_Cow_DoingWellMessage(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Cow_DoingWellMessage);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_COW_MOO);
}
