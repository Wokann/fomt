#include "fixed_labels_text.hh"

// Directly addressed fixed-width non-script fields.  Their consumer remains
// raw, so the symbol names intentionally describe only the displayed labels.
// The trailing bytes are normal C++ zero-fill within their original fields.
char const gText_Moneybags[16] SECTION(".rodata.fixed_labels") =
    "成金やろう";

char const gText_UnnamedSetting[12] SECTION(".rodata.fixed_labels") =
    "名称未設定";
