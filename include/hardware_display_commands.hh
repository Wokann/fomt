#ifndef HARDWARE_DISPLAY_COMMANDS_HH
#define HARDWARE_DISPLAY_COMMANDS_HH

#include "prelude.h"

struct HardwareBootstrap;

EXTERN_C

// Update the shadow's forced-blank bit and enqueue its VBlank upload.
void EnableHardwareForcedBlank(struct HardwareBootstrap * owner);
void DisableHardwareForcedBlank(struct HardwareBootstrap * owner);

EXTERN_C_END

#endif // HARDWARE_DISPLAY_COMMANDS_HH
