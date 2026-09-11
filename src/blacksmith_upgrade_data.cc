#include "blacksmith_text.hh"

// The upgrade UI is a distinct later rodata block in both regional ROMs.
#if defined(REGION_JP)
#define FOMT_TEXT_BLACKSMITH_UPGRADE
#include FOMT_TEXT_INCLUDE(blacksmith.cc)
#undef FOMT_TEXT_BLACKSMITH_UPGRADE
#else
#define FOMT_TEXT_BLACKSMITH_UPGRADE
#include FOMT_TEXT_INCLUDE(blacksmith.cc)
#undef FOMT_TEXT_BLACKSMITH_UPGRADE
#endif
