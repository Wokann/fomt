#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Cow_DoingWellMessage[] =
        "Den Kühen auf deiner Farm\r\n"
        "geht es immer gut.{Press}";
};

void EventScript_FarmEvent_Cow_DoingWellMessage(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Cow_DoingWellMessage);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_COW_MOO);
}
