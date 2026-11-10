#include "byte_search.h"

namespace std {
template <>
NAKED u8 const * __lower_bound<u8 const *, u32, UnsignedByteLess, ptrdiff_t>(
    u8 const *, u8 const *, u32 const &, UnsignedByteLess, ptrdiff_t *)
{
    asm_unified(
    "\tpush {r4, r5, r6, r7, lr}\n"
    "\tadds r6, r0, #0\n"
    "\tadds r7, r2, #0\n"
    "\tsubs r3, r1, r6\n"
    ".L080E0E88:\n"
    "\tcmp r3, #0\n"
    "\tble .L080E0EAC\n"
    "\tasrs r2, r3, #1\n"
    "\tadds r5, r6, r2\n"
    "\tldrb r1, [r5]\n"
    "\tmovs r4, #0\n"
    "\tldr r0, [r7]\n"
    "\tcmp r1, r0\n"
    "\tbhs .L080E0E9C\n"
    "\tmovs r4, #1\n"
    ".L080E0E9C:\n"
    "\tcmp r4, #0\n"
    "\tbeq .L080E0EA8\n"
    "\tadds r6, r5, #1\n"
    "\tsubs r0, r3, r2\n"
    "\tsubs r3, r0, #1\n"
    "\tb .L080E0E88\n"
    ".L080E0EA8:\n"
    "\tadds r3, r2, #0\n"
    "\tb .L080E0E88\n"
    ".L080E0EAC:\n"
    "\tadds r0, r6, #0\n"
    "\tpop {r4, r5, r6, r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    );
}
}
