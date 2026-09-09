#include "blacksmith_text.hh"

// JP stores a native four-byte zero gap between this menu block and the
// catalog that begins in blacksmith_data.cc.
#if defined(REGION_JP)
#define FOMT_TEXT_BLACKSMITH_MENU
#include "data/text/jp/blacksmith.cc"
#undef FOMT_TEXT_BLACKSMITH_MENU
#else
#define FOMT_TEXT_BLACKSMITH_MENU
#include "data/text/us/blacksmith.cc"
#undef FOMT_TEXT_BLACKSMITH_MENU
#endif
