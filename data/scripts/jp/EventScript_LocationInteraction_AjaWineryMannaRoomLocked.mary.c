#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_AjaWineryMannaRoomLocked[] =
        "カギがかかってる…{Press}";
};

void EventScript_LocationInteraction_AjaWineryMannaRoomLocked(void)
{
    int var_0;
    if (GetNpcFriendship(CHARACTER_MANNA) <= 200)
    {
        var_0 = FALSE;
    }
    else
    {
        var_0 = TRUE;
    }
    if (var_0 == TRUE)
    {
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        OpenDoor(DOOR_SLOT_0);
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_LocationInteraction_AjaWineryMannaRoomLocked);
        TalkClose();
    }
}
