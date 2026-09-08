#ifndef CRT0_HH
#define CRT0_HH

#include "prelude.h"

EXTERN_C

// crt0 reads the first word as the static-constructor count.  Both regional
// ROMs contain four zero words at this label; the remaining words are not
// decoded yet.
extern u32 const init_array[4];

extern char const gCppRuntimeBadAlloc_Crt0[];

EXTERN_C_END

#endif // CRT0_HH
