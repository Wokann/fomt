#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_ExitChurchWithEventStateCleanupAndMusicFestivalGuard_CarterBlocksExitDuringMusicFestival[] =
        "{Player}くん。\r\n"
        "ダメだよ外に出ちゃあ。{Press}";
};

void EventScript_LocationTransition_ExitChurchWithEventStateCleanupAndMusicFestivalGuard(void)
{
    int var_0;
    mary_nodisc(var_0 = 1);
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        if (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            VarSet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE, EVENT_LIFECYCLE_COMPLETED);
            ClearEntityEventScript(ENTITY_CLIFF);
            ClearEntityEventScript(ENTITY_CARTER);
            DisableScriptedNpcControl();
        }
        else
        {
            if (VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS)
            {
                DisableScriptedNpcControl();
                VarSet(VAR_RICK_KAREN_WEDDING_MISSED, TRUE);
                VarSet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_SINGLE);
            }
            else
            {
                if (VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS)
                {
                    DisableScriptedNpcControl();
                    VarSet(VAR_POPURI_KAI_WEDDING_MISSED, TRUE);
                    VarSet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_SINGLE);
                }
                else
                {
                    if (VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS)
                    {
                        DisableScriptedNpcControl();
                        VarSet(VAR_ANN_CLIFF_WEDDING_MISSED, TRUE);
                        VarSet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_SINGLE);
                    }
                    else
                    {
                        if (VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS)
                        {
                            DisableScriptedNpcControl();
                            VarSet(VAR_MARY_GRAY_WEDDING_MISSED, TRUE);
                            VarSet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_SINGLE);
                        }
                        else
                        {
                            if (VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS)
                            {
                                DisableScriptedNpcControl();
                                VarSet(VAR_ELLI_DOCTOR_WEDDING_MISSED, TRUE);
                                VarSet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_SINGLE);
                            }
                            else
                            {
                                if (VarGet(VAR_MUSIC_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                {
                                    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
                                    TalkOpen();
                                    SetTalkPortrait(TALK_PORTRAIT_CARTER_ANGRY);
                                    SetTalkNameplateCharacter(CHARACTER_CARTER);
                                    TalkMessage(gText_LocationTransition_ExitChurchWithEventStateCleanupAndMusicFestivalGuard_CarterBlocksExitDuringMusicFestival);
                                    TalkClose();
                                    var_0 = 0;
                                }
                                else
                                {
                                    if (VarGet(VAR_CARTER_CONFESSIONAL_DREAM_PREDICTS_GOOD_FORTUNE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
                                    {
                                        VarSet(VAR_CARTER_CONFESSIONAL_DREAM_PREDICTS_GOOD_FORTUNE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                        ClearEntityEventScript(ENTITY_CARTER);
                                        DisableScriptedNpcControl();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (var_0)
        {
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_NORTH_SIDE_TOWN, X(1232), Y(168));
            SetEntityPosition(ENTITY_PLAYER, X(1232), Y(168), FACING_DOWN);
            PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            SetEntityFacing(ENTITY_PLAYER, FACING_UP);
            MoveEntityYTo(ENTITY_PLAYER, Y(292), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
        }
    }
}
