#ifndef MAIN_HH
#define MAIN_HH

#include "prelude.h"

EXTERN_C

void AgbMain(void);
void HandleSoftResetKeyInterrupt(void);
// The Game Pak removal callback halts from IWRAM after disabling hardware.
void HandleGamePakInterrupt(void);

EXTERN_C_END

#endif // MAIN_HH
