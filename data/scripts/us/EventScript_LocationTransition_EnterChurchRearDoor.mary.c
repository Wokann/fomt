#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterChurchRearDoor(void)
{
    int var_0;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        var_0 = VarGet(VAR_HOUR);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_CHURCH, X(308), Y(64));
        SetEntityPosition(ENTITY_PLAYER, X(308), Y(64), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        if (var_0 >= 22 && var_0 <= 23 || var_0 >= 0 && var_0 < 6)
        {
            VarSet(VAR_PLAYER_SNEAKS_PAST_SLEEPING_CARTER_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            CallScript(EventScript_NPCEvent_Carter_PlayerSneaksPastSleepingCarter);
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
