#include "blacksmith_text.hh"

// The upgrade UI is a distinct later rodata block in both regional ROMs.
#if defined(REGION_JP)
#include "data/text/jp/blacksmith_upgrade.cc"
#else
#include "data/text/us/blacksmith_upgrade.cc"
#endif
