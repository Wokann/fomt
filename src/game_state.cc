#include "game_state.hh"

// The fixed season rows use the sole physical alignment subsection in this
// source; the rest of this module follows in native ROM order.
#if defined(REGION_JP)
#include "data/text/jp/game_state.cc"
#else
#include "data/text/us/game_state.cc"
#endif

#include "data/text/common/game_state.cc"
