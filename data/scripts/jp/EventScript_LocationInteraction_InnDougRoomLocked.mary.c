#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InnDougRoomLocked[] =
        "カギがかかっている…{Press}";
};

void EventScript_LocationInteraction_InnDougRoomLocked(void)
{
    int var_0;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
        {
            var_0 = TRUE;
        }
        else
        {
            if (GetNpcFriendship(CHARACTER_DOUG) <= 100)
            {
                var_0 = FALSE;
            }
            else
            {
                if (GetNpcFriendship(CHARACTER_DOUG) > 100)
                {
                    var_0 = FALSE;
                    if (GetNpcFriendship(CHARACTER_DOUG) > 200)
                    {
                        var_0 = TRUE;
                    }
                }
            }
        }
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            OpenDoor(DOOR_SLOT_2);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationInteraction_InnDougRoomLocked);
            TalkClose();
        }
    }
}
