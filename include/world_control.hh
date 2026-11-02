#ifndef WORLD_CONTROL_HH
#define WORLD_CONTROL_HH

#include "prelude.h"

struct GameSceneWorld;

EXTERN_C
// The native time query combines world suspension and the current map flag.
// Per-frame player/script gates remain separate in the native update routine.
bool IsWorldTimePaused(GameSceneWorld const & world);
// Suspension notifies every live entity. Script-controlled resume only
// notifies entity zero; the ordinary resume path visits every live entity.
void SuspendWorldUpdates(GameSceneWorld & world);
void ResumeWorldUpdates(GameSceneWorld & world);
EXTERN_C_END

#endif // WORLD_CONTROL_HH
