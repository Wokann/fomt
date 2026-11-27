#ifndef SCRIPT_JUMP_TABLE_SEARCH_HH
#define SCRIPT_JUMP_TABLE_SEARCH_HH

#include "prelude.h"

// Each native jump-table entry pairs a signed case value with a script offset.
struct JumpTableEnt
{
    int value;
    u32 target;
};

struct ScriptJumpTableSearchCompare
{
    bool operator()(JumpTableEnt const & left, int right) { return left.value < right; }
};


#endif // SCRIPT_JUMP_TABLE_SEARCH_HH
