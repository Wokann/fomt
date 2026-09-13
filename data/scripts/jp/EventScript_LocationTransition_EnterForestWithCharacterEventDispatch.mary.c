#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterForestWithCharacterEventDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        var_2 = VarGet(VAR_DAY_OF_WEEK);
        var_4 = VarGet(VAR_WEATHER_TODAY);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_FOREST, X(832), Y(24));
        SetEntityPosition(ENTITY_PLAYER, X(832), Y(24), FACING_DOWN);
        if (VarGet(VAR_MARY_MARRIED_LIFE_AND_WRITING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_0 != SEASON_WINTER && var_2 != DAY_OF_WEEK_MONDAY && var_4 == WEATHER_SUNNY && (var_3 >= 10 && var_3 < 18) && (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && GetEntityLocation(ENTITY_GOTZ) != MAP_FOREST && GetEntityLocation(ENTITY_HARRIS) != MAP_FOREST && HasMetNpc(CHARACTER_MARY) == TRUE)
        {
            VarSet(VAR_MARY_MARRIED_LIFE_AND_WRITING_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            CallScript(EventScript_NPCEvent_Mary_GathersGrassForBasilsResearchChoice);
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
