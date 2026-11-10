#ifndef SCRIPT_VM_HH
#define SCRIPT_VM_HH

#include "script_engine_base.hh"

// The interpreter and its native-call hosts share this implementation.
// The class-only header also serves the separate virtual-table owner.
#pragma interface "script_vm.hh"
inline char const * AScriptEngine::GetString(u32 id) const
{
    // Preserve the original inclusive test, including its out-of-range case.
    if (id <= string_count)
        return string_pool + string_offset_table[id];

    return "Error";
}

#endif // SCRIPT_VM_HH
