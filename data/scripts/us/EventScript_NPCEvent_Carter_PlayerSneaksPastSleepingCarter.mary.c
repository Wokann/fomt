#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Carter_PlayerSneaksPastSleepingCarter_Narration[] =
        "Carter's sleeping, so I'll \r\n"
        "just sneak out now...{Press}";
};

void EventScript_NPCEvent_Carter_PlayerSneaksPastSleepingCarter(void)
{
    TalkOpen();
    TalkMessage(gText_NPCEvent_Carter_PlayerSneaksPastSleepingCarter_Narration);
    TalkClose();
    ChangeMap(MAP_NORTH_SIDE_TOWN, X(1232), Y(168));
    SetEntityPosition(ENTITY_PLAYER, X(1232), Y(168), FACING_DOWN);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_PLAYER_SNEAKS_PAST_SLEEPING_CARTER_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
}
