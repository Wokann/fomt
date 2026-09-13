#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InnAnnRoomLocked[] =
        "It's locked...{Press}";
};

void EventScript_LocationInteraction_InnAnnRoomLocked(void)
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
            if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE)
            {
                if (GetCharacterLove(CHARACTER_ANN) <= LOVE_HEART_PURPLE_MIN)
                {
                    var_0 = FALSE;
                }
                else
                {
                    if (GetCharacterLove(CHARACTER_ANN) > LOVE_HEART_PURPLE_MIN)
                    {
                        var_0 = FALSE;
                        if (GetCharacterLove(CHARACTER_ANN) > LOVE_HEART_GREEN_MIN)
                        {
                            var_0 = TRUE;
                        }
                    }
                }
            }
            else
            {
                if (GetNpcFriendship(CHARACTER_ANN) <= 100)
                {
                    var_0 = FALSE;
                }
                else
                {
                    if (GetNpcFriendship(CHARACTER_ANN) > 100)
                    {
                        var_0 = FALSE;
                        if (GetNpcFriendship(CHARACTER_ANN) > 200)
                        {
                            var_0 = TRUE;
                        }
                    }
                }
            }
        }
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            OpenDoor(DOOR_SLOT_3);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationInteraction_InnAnnRoomLocked);
            TalkClose();
        }
    }
}
