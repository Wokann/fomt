#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitHotSpringBathingRoute(void)
{
    ExitHotSpringBathingState();
    PanCameraTo(X(856), Y(536), CAMERA_MOVE_SPEED_NOMINAL_2_PIXELS_PER_UPDATE);
    SetEntityFacing(ENTITY_PLAYER, FACING_LEFT);
    PlaySong(AUDIO_START, AUDIO_SFX_THROWN_ITEM_LANDS);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_ENTER_OR_EXIT_HOT_SPRING);
    MoveEntityXTo(ENTITY_PLAYER, X(856), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    WaitFrames(30);
    PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
    OpenDoor(DOOR_SLOT_13);
    SetEntityFacing(ENTITY_PLAYER, FACING_DOWN);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_WALK_EMPTY_HANDED);
    MoveEntityYTo(ENTITY_PLAYER, Y(536), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    WaitForEntityMovement(ENTITY_PLAYER);
    WaitForCameraMovement();
    PlaySong(AUDIO_START, AUDIO_SFX_CLOSE_DOOR);
    CloseDoor(DOOR_SLOT_13);
}
