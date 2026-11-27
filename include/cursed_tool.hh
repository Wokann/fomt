#ifndef CURSED_TOOL_HH
#define CURSED_TOOL_HH

#include "prelude.h"
#include "item.hh"

enum { CURSED_TOOL_COUNT = 6 };

// Saved at GameStateSaveImage +0x3480. The arrays are parallel, not six
// interleaved records: sickle, hoe, axe, hammer, watering can, fishing rod.
// Only the eighteen data bytes are initialized; the last two are padding.
struct CursedToolState
{
    CursedToolState();
    bool IsCursedTool(Tool const & tool) const;
    // The original fallback is the hoe slot (1), even for invalid IDs.
    // Callers normally supply one of the six ITEM_TOOL_*_CURSED constants.
    u32 GetToolIndex(u32 tool_id) const;
    u8 IsCursed(u32 tool_id) const;
    u8 IsBlessed(u32 tool_id) const;
    bool HaveFoundAllTools() const;
    bool HaveBlessedAllTools() const;
    void StartCurse(u32 tool_id);
    u32 AdvanceProgress(u32 index);
    void ResetConsecutiveDays(u32 index);
    // Sickle/hammer: consecutive equipped days. Hoe/watering can: church
    // removals. Axe/fishing rod: uses. Church removal also resets the first
    // pair's consecutive-day progress; it does not bless that pair.
    u8 AdvanceEquippedDays(u32 tool_id);
    u8 AttemptChurchRemoval(u32 tool_id);
    u8 AdvanceToolUses(u32 tool_id);

    u8 cursed[CURSED_TOOL_COUNT];
    u8 blessed[CURSED_TOOL_COUNT];
    u8 progress[CURSED_TOOL_COUNT];
};

extern u8 const gCursedToolProgressLimits[CURSED_TOOL_COUNT];


#endif
