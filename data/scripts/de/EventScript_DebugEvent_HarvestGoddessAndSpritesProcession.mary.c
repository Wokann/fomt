#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_DebugEvent_HarvestGoddessAndSpritesProcession(void)
{
    SetEntityPosition(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER) + 16), Y(GetEntityY(ENTITY_PLAYER)), FACING_DOWN);
    SetEntityFacing(ENTITY_HARVEST_GODDESS, FACING_LEFT);
    MoveEntityXTo(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER) + 32), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    OffsetEntityPosition(ENTITY_HOGGY, X(GetEntityX(ENTITY_PLAYER) + 16), Y(GetEntityY(ENTITY_PLAYER)));
    WaitForEntityMovement(ENTITY_HARVEST_GODDESS);
    MoveEntityXTo(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER) + 48), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    OffsetEntityPosition(ENTITY_TIMID, X(GetEntityX(ENTITY_PLAYER) + 32), Y(GetEntityY(ENTITY_PLAYER)));
    WaitForEntityMovement(ENTITY_HARVEST_GODDESS);
    MoveEntityXTo(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER) + 64), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    OffsetEntityPosition(ENTITY_AQUA, X(GetEntityX(ENTITY_PLAYER) + 48), Y(GetEntityY(ENTITY_PLAYER)));
    WaitForEntityMovement(ENTITY_HARVEST_GODDESS);
    MoveEntityXTo(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER) + 80), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    OffsetEntityPosition(ENTITY_STAID, X(GetEntityX(ENTITY_PLAYER) + 64), Y(GetEntityY(ENTITY_PLAYER)));
    WaitForEntityMovement(ENTITY_HARVEST_GODDESS);
    MoveEntityXTo(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER) + 96), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    OffsetEntityPosition(ENTITY_BOLD, X(GetEntityX(ENTITY_PLAYER) + 80), Y(GetEntityY(ENTITY_PLAYER)));
    WaitForEntityMovement(ENTITY_HARVEST_GODDESS);
    MoveEntityXTo(ENTITY_HARVEST_GODDESS, X(GetEntityX(ENTITY_PLAYER) + 112), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
    OffsetEntityPosition(ENTITY_NAPPY, X(GetEntityX(ENTITY_PLAYER) + 96), Y(GetEntityY(ENTITY_PLAYER)));
    WaitForEntityMovement(ENTITY_HARVEST_GODDESS);
    HideEntity(ENTITY_HARVEST_GODDESS);
    OffsetEntityPosition(ENTITY_CHEF, X(GetEntityX(ENTITY_PLAYER) + 112), Y(GetEntityY(ENTITY_PLAYER)));
    PlaySong(AUDIO_START, AUDIO_SFX_HARVEST_GODDESS_APPEARS);
    return;
}
