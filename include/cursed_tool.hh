#ifndef CURSED_TOOL_HH
#define CURSED_TOOL_HH

#include "prelude.h"
#include "item.hh"

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
    u32 HaveFoundAllTools() const;
    u32 HaveBlessedAllTools() const;
    void StartCurse(u32 tool_id);
    u32 AdvanceProgress(u32 index);
    void ResetConsecutiveDays(u32 index);
    // Sickle/hammer: consecutive equipped days. Hoe/watering can: church
    // removals. Axe/fishing rod: uses. Church removal also resets the first
    // pair's consecutive-day progress; it does not bless that pair.
    u8 AdvanceEquippedDays(u32 tool_id);
    u8 AttemptChurchRemoval(u32 tool_id);
    u8 AdvanceToolUses(u32 tool_id);

    u8 cursed[6];
    u8 blessed[6];
    u8 progress[6];
};

extern u8 const gCursedToolProgressLimits[];

typedef char CursedToolStateSizeCheck[sizeof(CursedToolState) == 0x14 ? 1 : -1];
typedef char CursedToolStateDataEndCheck[offsetof(CursedToolState, progress) + sizeof(((CursedToolState *) 0)->progress) == 0x12 ? 1 : -1];

#endif
