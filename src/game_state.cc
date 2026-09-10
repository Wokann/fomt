#include "game_state.hh"

// Regional and shared data follow native ROM order.
#if defined(REGION_JP)
#include "data/text/jp/game_state.cc"
#else
#include "data/text/us/game_state.cc"
#endif

#include "data/text/common/game_state.cc"
