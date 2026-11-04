#ifndef CRT0_DATA_HH
#define CRT0_DATA_HH

#include "prelude.h"

EXTERN_C

// crt0 reads the first word as the constructor count. All four ROMs have
// three more zero words after that count.
extern u32 const init_array[];

extern char const gCppRuntimeBadAlloc_Crt0[];

EXTERN_C_END

#endif // CRT0_DATA_HH
