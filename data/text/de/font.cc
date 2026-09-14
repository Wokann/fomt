#include "font.hh"

// This is an ordinary terminated C string. Its two additional trailing zero
// bytes arise from the four-byte alignment of the following object.
extern char const gCppRuntimeBadAlloc_Font[] ALIGN(4) =
    "bad_alloc";
