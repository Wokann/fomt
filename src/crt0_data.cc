#include "crt0.hh"

EXTERN_C

u32 const init_array[4] = {
    0,
    0,
    0,
    0,
};

char const gCppRuntimeBadAlloc_Crt0[] =
    "bad_alloc";

EXTERN_C_END
