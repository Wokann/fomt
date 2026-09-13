#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitGotzHouseWithEventStateCleanupAndDispatch(void)
{
    int var_0, var_1, var_2, var_3, var_4;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_GOTZ_AND_HARRIS_PATROL_DISCUSSION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_GOTZ_AND_HARRIS_PATROL_DISCUSSION_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_GOTZ);
            ClearEntityEventScript(ENTITY_HARRIS);
            DisableScriptedNpcControl();
        }
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        var_2 = VarGet(VAR_DAY_OF_WEEK);
        var_4 = VarGet(VAR_WEATHER_TODAY);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_FOREST, X(612), Y(248));
        SetEntityPosition(ENTITY_PLAYER, X(612), Y(248), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        if (VarGet(VAR_RICK_KAREN_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_RICK_KAREN_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_NOT_STARTED && !(var_0 == SEASON_SPRING) && var_4 == WEATHER_SUNNY && (var_2 == DAY_OF_WEEK_SUNDAY || var_2 == DAY_OF_WEEK_MONDAY) && (var_3 >= 11 && var_3 < 18) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_GREEN_MIN)
        {
            VarSet(VAR_RICK_KAREN_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            CallScript(EventScript_RivalEvent_RickAndKaren_02_BlueHeart_ChildhoodMemories);
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
