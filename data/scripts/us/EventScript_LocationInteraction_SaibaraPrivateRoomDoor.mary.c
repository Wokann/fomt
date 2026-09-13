#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_SaibaraPrivateRoomDoor[] =
        "That's my room!\r\n"
        "Don't go in there!{Press}";
};

void EventScript_LocationInteraction_SaibaraPrivateRoomDoor(void)
{
    int var_0;
    if (GetNpcFriendship(CHARACTER_SAIBARA) <= 200)
    {
        var_0 = FALSE;
    }
    else
    {
        if (GetNpcFriendship(CHARACTER_SAIBARA) > 200)
        {
            var_0 = TRUE;
        }
    }
    if (var_0 == TRUE)
    {
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        OpenDoor(DOOR_SLOT_8);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
        TalkMessage(gText_LocationInteraction_SaibaraPrivateRoomDoor);
        TalkClose();
    }
}
