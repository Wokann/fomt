#include "blacksmith_text.hh"

// JP stores a native four-byte zero gap between this menu block and the
// catalog that begins in blacksmith_data.cc.
#if defined(REGION_JP)
#include "data/text/jp/blacksmith_menu.cc"
#else
#include "data/text/us/blacksmith_menu.cc"
#endif
