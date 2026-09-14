#include "staff_credits.hh"

// This is intentionally not ordinary C++: fomt-text lowers the selected
// regional credit rows into their original fixed text fields and row table
// before agbcp compiles this owner.
FOMT_STAFF_CREDITS();

// This runtime string physically follows the native text fields and pointer
// table in every regional ROM.
#include "data/text/common/staff_credits_1.cc"
