#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationTransition_EnterBehindChurchWithAccessGuard_DoorIsLocked[] =
        "It's locked...{Press}";
};

void EventScript_LocationTransition_EnterBehindChurchWithAccessGuard(void)
{
    int var_0;
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        var_0 = FALSE;
        if (VarGet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_WEDDING_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MUSIC_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
        {
            var_0 = FALSE;
        }
        else
        {
            if (VarGet(VAR_CARTER_CHURCH_BACK_DOOR_MUSHROOM_SECRET_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
            {
                var_0 = TRUE;
            }
            else
            {
                if (VarGet(VAR_CARTER_CONFESSIONAL_DREAM_PREDICTS_GOOD_FORTUNE_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                {
                    var_0 = TRUE;
                }
            }
        }
        if (var_0 == TRUE)
        {
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            OpenDoor(DOOR_SLOT_10);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_HOLDING_ITEM);
            }
            MoveEntityXTo(ENTITY_PLAYER, X(308), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            MoveEntityYTo(ENTITY_PLAYER, Y(56), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            if (IsPlayerHoldingNothing() == TRUE)
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
            }
            else
            {
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
            }
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            ChangeMap(MAP_BEHIND_CHURCH, X(252), Y(368));
            SetEntityPosition(ENTITY_PLAYER, X(252), Y(368), FACING_UP);
            FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationTransition_EnterBehindChurchWithAccessGuard_DoorIsLocked);
            TalkClose();
        }
    }
}
