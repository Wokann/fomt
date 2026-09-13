#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterSupermarketBackRoomWithAccessGuard_DoorIsLocked[] =
        "Abgeschlossen...{Press}";
};

void EventScript_LocationTransition_EnterSupermarketBackRoomWithAccessGuard(void)
{
    int var_0;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        if (VarGet(VAR_KAREN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MANNA_FLATTERS_JEFF_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_JEFF_AND_SASHA_STORE_CREDIT_LESSON_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            var_0 = FALSE;
        }
        else
        {
            if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                if (GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET_BACK_ROOM)
                {
                    var_0 = TRUE;
                }
            }
            else
            {
                if (GetEntityLocation(ENTITY_SASHA) == MAP_SUPERMARKET_BACK_ROOM)
                {
                    if (GetNpcFriendship(CHARACTER_SASHA) <= 100)
                    {
                        var_0 = FALSE;
                    }
                    else
                    {
                        if (GetNpcFriendship(CHARACTER_SASHA) > 100)
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
            OpenDoor(DOOR_SLOT_9);
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_SUPERMARKET_BACK_ROOM, X(92), Y(320));
            SetEntityPosition(ENTITY_PLAYER, X(92), Y(320), FACING_UP);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterSupermarketBackRoomWithAccessGuard_DoorIsLocked);
            TalkClose();
        }
    }
}
