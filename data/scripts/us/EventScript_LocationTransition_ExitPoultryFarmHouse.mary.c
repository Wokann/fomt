#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitPoultryFarmHouse(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_POPURI_YELLOW_HEART_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_RICK);
            ClearEntityEventScript(ENTITY_POPURI);
            ClearEntityEventScript(ENTITY_LILLIA);
            DisableScriptedNpcControl();
        }
        else
        {
            if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                VarSet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_COMPLETED);
                ClearEntityEventScript(ENTITY_RICK);
                ClearEntityEventScript(ENTITY_POPURI);
                ClearEntityEventScript(ENTITY_LILLIA);
                DisableScriptedNpcControl();
            }
            else
            {
                if (VarGet(VAR_RICK_AND_POPURI_RUSH_TO_SICK_LILLIA_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    VarSet(VAR_RICK_AND_POPURI_RUSH_TO_SICK_LILLIA_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    ClearEntityEventScript(ENTITY_RICK);
                    ClearEntityEventScript(ENTITY_POPURI);
                    ClearEntityEventScript(ENTITY_LILLIA);
                    DisableScriptedNpcControl();
                }
                else
                {
                    if (VarGet(VAR_LILLIA_READS_RODS_LETTER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        VarSet(VAR_LILLIA_READS_RODS_LETTER_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        ClearEntityEventScript(ENTITY_RICK);
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_LILLIA);
                        DisableScriptedNpcControl();
                    }
                    else
                    {
                        if (VarGet(VAR_KAREN_COMFORTS_LONELY_RICK_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                        {
                            VarSet(VAR_KAREN_COMFORTS_LONELY_RICK_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                            ClearEntityEventScript(ENTITY_RICK);
                            ClearEntityEventScript(ENTITY_KAREN);
                            DisableScriptedNpcControl();
                        }
                        else
                        {
                            if (VarGet(VAR_ZACK_VISITS_SICK_LILLIA_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                            {
                                VarSet(VAR_ZACK_VISITS_SICK_LILLIA_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                ClearEntityEventScript(ENTITY_LILLIA);
                                DisableScriptedNpcControl();
                            }
                            else
                            {
                                if (VarGet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                {
                                    VarSet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                    ClearEntityEventScript(ENTITY_SASHA);
                                    ClearEntityEventScript(ENTITY_LILLIA);
                                    DisableScriptedNpcControl();
                                }
                            }
                        }
                    }
                }
            }
        }
        var_0 = VarGet(VAR_SEASON);
        var_1 = VarGet(VAR_DAY);
        var_3 = VarGet(VAR_HOUR);
        var_2 = VarGet(VAR_DAY_OF_WEEK);
        var_4 = VarGet(VAR_WEATHER_TODAY);
        var_5 = VarGet(VAR_YEAR);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_SOUTH_SIDE_TOWN, X(572), Y(232));
        SetEntityPosition(ENTITY_PLAYER, X(572), Y(232), FACING_DOWN);
        PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
        if (VarGet(VAR_RICK_KAREN_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_RICK_KAREN_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && var_5 >= 4 && var_4 == WEATHER_SUNNY && !(var_2 == DAY_OF_WEEK_SUNDAY || var_2 == DAY_OF_WEEK_MONDAY || var_2 == DAY_OF_WEEK_WEDNESDAY || var_2 == DAY_OF_WEEK_FRIDAY) && (var_3 >= 13 && var_3 < 16) && (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED) && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_RICK_KAREN_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_WEDDING_POPURI_INTRO_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && GetEntityLocation(ENTITY_POPURI) != MAP_SOUTH_SIDE_TOWN && GetEntityLocation(ENTITY_BARLEY) != MAP_SOUTH_SIDE_TOWN && GetEntityLocation(ENTITY_GRAY) != MAP_SOUTH_SIDE_TOWN && GetEntityLocation(ENTITY_MARY) != MAP_SOUTH_SIDE_TOWN && GetEntityLocation(ENTITY_SASHA) != MAP_SOUTH_SIDE_TOWN && GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_RED_MIN)
        {
            VarSet(VAR_RICK_KAREN_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
            CallScript(EventScript_RivalEvent_RickAndKaren_04_OrangeHeart_LilliasMarriageQuestion);
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
