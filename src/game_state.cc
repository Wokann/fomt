#include "game_state.hh"

// Regional and shared data follow native ROM order.
#if defined(REGION_JP)
#include FOMT_TEXT_INCLUDE(game_state.cc)
#else
#include FOMT_TEXT_INCLUDE(game_state.cc)
#endif

#include "data/text/common/game_state.cc"
