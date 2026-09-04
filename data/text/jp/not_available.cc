#include "not_available_text.hh"

// The trailing bytes are C++ zero-fill within the original eight-byte field.
char const gText_NotAvailable[8] SECTION(".rodata.not_available") =
    "なし";
