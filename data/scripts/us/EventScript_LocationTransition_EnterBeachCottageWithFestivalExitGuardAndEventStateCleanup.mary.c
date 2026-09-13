#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterBeachCottageWithFestivalExitGuardAndEventStateCleanup_RickBlocksExitBeforeFireworksFestival[] =
        "Where are you going?\r\n"
        "The fireworks are\r\n"
        "about to start!{Press}";

    const char gText_LocationTransition_EnterBeachCottageWithFestivalExitGuardAndEventStateCleanup_ZackBlocksExitBeforeBeachDayFestival[] =
        "Where are you going?\r\n"
        "The Beach Day\r\n"
        "is about to start!{Press}";

    const char gText_LocationTransition_EnterBeachCottageWithFestivalExitGuardAndEventStateCleanup_BeachDayFestivalConcludesAndReturnsPlayerToWork[] =
        "That was fun!\r\n"
        "Alright, back to work...{Press}";
};

void EventScript_LocationTransition_EnterBeachCottageWithFestivalExitGuardAndEventStateCleanup(void)
{
    int var_0, var_1, var_2, var_3;
    var_0 = VarGet(VAR_SEASON);
    var_1 = VarGet(VAR_DAY);
    var_2 = VarGet(VAR_HOUR);
    var_3 = VarGet(VAR_MINUTE);
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (VarGet(VAR_FIREWORKS_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_LocationTransition_EnterBeachCottageWithFestivalExitGuardAndEventStateCleanup_RickBlocksExitBeforeFireworksFestival);
            TalkClose();
            return;
        }
        else
        {
            if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_1_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
            {
                VarSet(VAR_POPURI_KAI_RIVAL_EVENT_1_STATE, EVENT_LIFECYCLE_COMPLETED);
                ClearEntityEventScript(ENTITY_POPURI);
                ClearEntityEventScript(ENTITY_KAI);
                DisableScriptedNpcControl();
            }
            else
            {
                if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                {
                    VarSet(VAR_POPURI_KAI_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_COMPLETED);
                    ClearEntityEventScript(ENTITY_KAI);
                    DisableScriptedNpcControl();
                }
                else
                {
                    if (VarGet(VAR_POPURI_KAI_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                    {
                        VarSet(VAR_POPURI_KAI_RIVAL_EVENT_3_STATE, EVENT_LIFECYCLE_COMPLETED);
                        ClearEntityEventScript(ENTITY_POPURI);
                        ClearEntityEventScript(ENTITY_KAI);
                        DisableScriptedNpcControl();
                    }
                    else
                    {
                        if (VarGet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                        {
                            VarSet(VAR_ELLI_DOCTOR_RIVAL_EVENT_4_STATE, EVENT_LIFECYCLE_COMPLETED);
                            ClearEntityEventScript(ENTITY_DOCTOR);
                            ClearEntityEventScript(ENTITY_ELLI);
                            DisableScriptedNpcControl();
                        }
                    }
                }
            }
        }
        if (VarGet(VAR_BEACH_DAY_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
        {
            if (!(var_2 == 18 && var_3 == 1))
            {
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_ZACK_ANGRY);
                SetTalkNameplateCharacter(CHARACTER_ZACK);
                TalkMessage(gText_LocationTransition_EnterBeachCottageWithFestivalExitGuardAndEventStateCleanup_ZackBlocksExitBeforeBeachDayFestival);
                TalkClose();
                SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
                return;
            }
            else
            {
                PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                if (VarGet(VAR_FRISBEE_TOURNAMENT_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
                {
                    AddNpcFriendship(CHARACTER_THOMAS, 20);
                    AddNpcFriendship(CHARACTER_JEFF, 20);
                    AddNpcFriendship(CHARACTER_SASHA, 20);
                    AddNpcFriendship(CHARACTER_KAI, 20);
                    AddNpcFriendship(CHARACTER_POPURI, 20);
                    AddNpcFriendship(CHARACTER_ZACK, 20);
                }
                TalkOpen();
                TalkMessage(gText_LocationTransition_EnterBeachCottageWithFestivalExitGuardAndEventStateCleanup_BeachDayFestivalConcludesAndReturnsPlayerToWork);
                TalkClose();
                DisableScriptedNpcControl();
                VarSet(VAR_BEACH_DAY_FESTIVAL_ACTIVE, FESTIVAL_PHASE_ADVANCED);
                ClearContestAnimal(ANIMAL_KIND_DOG);
                VarSet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED, FALSE);
                ClearEntityEventScript(ENTITY_THOMAS);
                ClearEntityEventScript(ENTITY_JEFF);
                ClearEntityEventScript(ENTITY_SASHA);
                ClearEntityEventScript(ENTITY_KAI);
                ClearEntityEventScript(ENTITY_POPURI);
                ClearEntityEventScript(ENTITY_ZACK);
                ChangeMap(MAP_BEACH_HOUSE, X(120), Y(208));
                SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
                FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                return;
            }
        }
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_BEACH_HOUSE, X(120), Y(208));
        SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
