#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MoonViewingOrNewYearSunrise_ExitGuard_Warning[] =
        "Warte eine Sekunde!\r\n"
        "Du bist zu weit gekommen,\r\n"
        "um jetzt umzudrehen!{Press}";
};

void EventScript_FestivalEvent_MoonViewingOrNewYearSunrise_ExitGuard(void)
{
    int var_0, var_1;
    mary_nodisc(var_1 = 1);
    switch (VarGet(VAR_FESTIVAL_MOON_VIEWING_PARTNER_INDEX))
    {
        case FESTIVAL_MOON_VIEWING_PARTNER_KAREN:
            var_0 = ENTITY_KAREN;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_ANN:
            var_0 = ENTITY_ANN;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_POPURI:
            var_0 = ENTITY_POPURI;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_MARY:
            var_0 = ENTITY_MARY;
            break;
        case FESTIVAL_MOON_VIEWING_PARTNER_ELLI:
            var_0 = ENTITY_ELLI;
            break;
    }
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_NEW_YEAR_SUNRISE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_SAIBARA);
            TalkMessage(gText_FestivalEvent_MoonViewingOrNewYearSunrise_ExitGuard_Warning);
            TalkClose();
            var_1 = 0;
        }
        else
        {
            if (VarGet(VAR_MOON_VIEWING_FESTIVAL_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                VarSet(VAR_MOON_VIEWING_FESTIVAL_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
                ClearEntityEventScript(var_0);
                DisableScriptedNpcControl();
            }
            else
            {
                if (VarGet(VAR_MARY_AND_GRAY_BOOK_AND_HEALTH_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    VarSet(VAR_MARY_AND_GRAY_BOOK_AND_HEALTH_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    ClearEntityEventScript(ENTITY_MARY);
                    ClearEntityEventScript(ENTITY_GRAY);
                    DisableScriptedNpcControl();
                }
                else
                {
                    if (VarGet(VAR_ANN_MOTHERS_DEATH_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        VarSet(VAR_ANN_MOTHERS_DEATH_ANNIVERSARY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        ClearEntityEventScript(ENTITY_DOUG);
                        DisableScriptedNpcControl();
                    }
                }
            }
        }
        if (var_1)
        {
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_MOTHERS_HILL_MIDDLE, X(500), Y(20));
            SetEntityPosition(ENTITY_PLAYER, X(500), Y(20), FACING_DOWN);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            MoveEntityYTo(ENTITY_PLAYER, Y(438), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
        }
    }
}
