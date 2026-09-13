#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_EnterHotSpring_CannotEnterWhileHoldingItem[] =
        "Gehe von hier in die\r\n"
        "heiße Quelle. Du \r\n"
        "musst dazu aber{Press}\r\n"
        "leere Hände haben.{Press}";
};

void EventScript_LocationInteraction_EnterHotSpring(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (IsPlayerHoldingNothing() == TRUE)
        {
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
            MoveEntityXTo(ENTITY_PLAYER, X(856), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            PanCameraTo(X(912), Y(472), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
            PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
            OpenDoor(DOOR_SLOT_13);
            MoveEntityYTo(ENTITY_PLAYER, Y(472), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
            CloseDoor(DOOR_SLOT_13);
            WaitFrames(30);
            PlaySong(AUDIO_START, AUDIO_SFX_ENTER_HOT_SPRING);
            SetEntityFacing(ENTITY_PLAYER, FACING_RIGHT);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_ENTER_OR_EXIT_HOT_SPRING);
            MoveEntityXTo(ENTITY_PLAYER, X(912), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
            WaitForEntityMovement(ENTITY_PLAYER);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_BATHE_IN_HOT_SPRING);
            PlaySong(AUDIO_START, AUDIO_SFX_THROWN_ITEM_LANDS);
            WaitForCameraMovement();
            EnterHotSpringBathingState();
        }
        else
        {
            TalkOpen();
            TalkMessage(gText_LocationInteraction_EnterHotSpring_CannotEnterWhileHoldingItem);
            TalkClose();
        }
    }
}
