#include "fixed_labels_text.hh"

// Directly addressed fixed-width non-script fields.  Their consumer remains
// raw, so the symbol names intentionally describe only the displayed labels.
// The trailing bytes are normal C++ zero-fill within their original fields.
char const gText_Moneybags[16] SECTION(".rodata.fixed_labels") =
    "Moneybags ";

char const gText_UnnamedSetting[16] SECTION(".rodata.fixed_labels") =
    "Unnamed setting";
