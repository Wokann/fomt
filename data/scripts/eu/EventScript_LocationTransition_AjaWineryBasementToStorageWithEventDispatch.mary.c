#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_AjaWineryBasementToStorageWithEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        var_2 = VarGet(VAR_DAY_OF_WEEK);
        var_4 = VarGet(VAR_WEATHER_TODAY);
        var_5 = VarGet(VAR_YEAR);
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_AJA_WINERY_STORAGE_1F, X(120), Y(208));
        SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
        if (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_5 >= 4 && !(var_2 == DAY_OF_WEEK_SATURDAY) && (var_3 >= 10 && var_3 < 13) && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_RED_MIN && GetEntityLocation(ENTITY_CLIFF) == MAP_AJA_WINERY_STORAGE_B1F)
        {
            VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            CallScript(EventScript_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice);
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
