#ifndef HARDWARE_DISPLAY_COMMANDS_HH
#define HARDWARE_DISPLAY_COMMANDS_HH

#include "prelude.h"

struct HardwareContext;

EXTERN_C

// Update the shadow's forced-blank bit and enqueue its VBlank upload.
void EnableHardwareForcedBlank(struct HardwareContext * owner);
void DisableHardwareForcedBlank(struct HardwareContext * owner);

EXTERN_C_END

#endif // HARDWARE_DISPLAY_COMMANDS_HH
