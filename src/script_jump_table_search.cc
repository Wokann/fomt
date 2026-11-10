#include "script_jump_table_search.hh"
#include <algorithm>

template JumpTableEnt const * std::__lower_bound(
    JumpTableEnt const *, JumpTableEnt const *, int const &,
    ScriptJumpTableSearchCompare, ptrdiff_t *);
