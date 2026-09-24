#include "staff_credits.hh"

// This is intentionally not ordinary C++: fomt-text lowers the selected
// regional credit rows into aligned text fields and their shared-pointer row
// table before agbcp compiles this owner.
FOMT_STAFF_CREDITS();

// This runtime string physically follows the native text fields and pointer
// table in every regional ROM.
#include FOMT_TEXT_INCLUDE(staff_credits_2.cc)
