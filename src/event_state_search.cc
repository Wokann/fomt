#include "event_state.hh"
#include <algorithm>

// Registration searches a const range; removal searches a mutable range.
template u16 const * std::find(u16 const *, u16 const *, u16 const &);
template u16 * std::find(u16 *, u16 *, u16 const &);
