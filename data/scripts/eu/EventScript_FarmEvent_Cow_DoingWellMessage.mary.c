#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Cow_DoingWellMessage[] =
        "The cows at this farm\r\n"
        "are always doing well.{Press}";
};

void EventScript_FarmEvent_Cow_DoingWellMessage(void)
{
    TalkOpen();
    TalkMessage(gText_FarmEvent_Cow_DoingWellMessage);
    TalkClose();
    PlaySong(AUDIO_START, AUDIO_SFX_COW_MOO);
}
