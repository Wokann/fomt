#include "cursed_tool.hh"

u8 const gCursedToolProgressLimits[CURSED_TOOL_COUNT] = {
    /* ITEM_TOOL_KIND_SICKLE */       10,
    /* ITEM_TOOL_KIND_HOE */          10,
    /* ITEM_TOOL_KIND_AXE */          255,
    /* ITEM_TOOL_KIND_HAMMER */       10,
    /* ITEM_TOOL_KIND_WATERING_CAN */ 10,
    /* ITEM_TOOL_KIND_FISHING_ROD */  255,
};

CursedToolState::CursedToolState()
{
    for (u32 i = 0; i < CURSED_TOOL_COUNT; ++i) {
        cursed[i] = 0;
        progress[i] = 0;
        blessed[i] = 0;
    }
}

bool CursedToolState::IsCursedTool(Tool const & tool) const
{
    switch (tool.GetId()) {
    case ITEM_TOOL_SICKLE_CURSED:
    case ITEM_TOOL_HOE_CURSED:
    case ITEM_TOOL_AXE_CURSED:
    case ITEM_TOOL_HAMMER_CURSED:
    case ITEM_TOOL_WATERING_CAN_CURSED:
    case ITEM_TOOL_FISHING_ROD_CURSED:
        return true;
    default:
        return false;
    }
}

u32 CursedToolState::GetToolIndex(u32 tool_id) const
{
    u32 result = ITEM_TOOL_KIND_HOE;
    switch (tool_id) {
    case ITEM_TOOL_SICKLE_CURSED: result = ITEM_TOOL_KIND_SICKLE; break;
    case ITEM_TOOL_HOE_CURSED: result = ITEM_TOOL_KIND_HOE; break;
    case ITEM_TOOL_AXE_CURSED: result = ITEM_TOOL_KIND_AXE; break;
    case ITEM_TOOL_HAMMER_CURSED: result = ITEM_TOOL_KIND_HAMMER; break;
    case ITEM_TOOL_WATERING_CAN_CURSED: result = ITEM_TOOL_KIND_WATERING_CAN; break;
    case ITEM_TOOL_FISHING_ROD_CURSED: result = ITEM_TOOL_KIND_FISHING_ROD; break;
    }
    return result;
}

u8 CursedToolState::IsCursed(u32 tool_id) const
{
    return cursed[GetToolIndex(tool_id)];
}

u8 CursedToolState::IsBlessed(u32 tool_id) const
{
    return blessed[GetToolIndex(tool_id)];
}

bool CursedToolState::HaveFoundAllTools() const
{
    u32 result = 0;
    i32 value = blessed[ITEM_TOOL_KIND_HOE];
    value = -value;
    if ((-cursed[ITEM_TOOL_KIND_HOE] | value) >= 0) goto end;
    value = blessed[ITEM_TOOL_KIND_SICKLE]; value = -value;
    if ((-cursed[ITEM_TOOL_KIND_SICKLE] | value) >= 0) goto end;
    value = blessed[ITEM_TOOL_KIND_AXE]; value = -value;
    if ((-cursed[ITEM_TOOL_KIND_AXE] | value) >= 0) goto end;
    value = blessed[ITEM_TOOL_KIND_HAMMER]; value = -value;
    if ((-cursed[ITEM_TOOL_KIND_HAMMER] | value) >= 0) goto end;
    value = blessed[ITEM_TOOL_KIND_WATERING_CAN]; value = -value;
    if ((-cursed[ITEM_TOOL_KIND_WATERING_CAN] | value) >= 0) goto end;
    value = blessed[ITEM_TOOL_KIND_FISHING_ROD]; value = -value;
    result = (u32)(-cursed[ITEM_TOOL_KIND_FISHING_ROD] | value) >> 31;
end:
    return result;
}

bool CursedToolState::HaveBlessedAllTools() const
{
    u32 result = 0;
    if (blessed[ITEM_TOOL_KIND_HOE] == 0) goto end;
    if (blessed[ITEM_TOOL_KIND_SICKLE] == 0) goto end;
    if (blessed[ITEM_TOOL_KIND_AXE] == 0) goto end;
    if (blessed[ITEM_TOOL_KIND_HAMMER] == 0) goto end;
    if (blessed[ITEM_TOOL_KIND_WATERING_CAN] == 0) goto end;
    result = (u32)-blessed[ITEM_TOOL_KIND_FISHING_ROD] >> 31;
end:
    return result;
}

void CursedToolState::StartCurse(u32 tool_id)
{
    u32 const index = GetToolIndex(tool_id);
    if (cursed[index] == 0) {
        cursed[index] = 1;
        progress[index] = 0;
    }
}

u32 CursedToolState::AdvanceProgress(u32 index)
{
    u32 result = 0;
    if (cursed[index] != 0) {
        u8 * const values = progress;
        u8 & value = values[index];
        // Compare before incrementing, exactly as the original does.
        // Reaching the limit does not bless the tool until the next call.
        if (value < gCursedToolProgressLimits[index])
            ++value;
        else {
            cursed[index] = 0;
            blessed[index] = 1;
            result = 1;
        }
    }
    return result;
}

void CursedToolState::ResetConsecutiveDays(u32 index)
{
    if (cursed[index] != 0) {
        if (index == ITEM_TOOL_KIND_SICKLE || index == ITEM_TOOL_KIND_HAMMER)
            progress[index] = 0;
    }
}

u8 CursedToolState::AdvanceEquippedDays(u32 tool_id)
{
    u8 result = 0;
    u32 index = GetToolIndex(tool_id);
    if (cursed[index] != 0) {
        if (index == ITEM_TOOL_KIND_SICKLE || index == ITEM_TOOL_KIND_HAMMER)
            result = AdvanceProgress(index);
    }
    return result;
}

u8 CursedToolState::AttemptChurchRemoval(u32 tool_id)
{
    u32 index = GetToolIndex(tool_id);
    u8 result = 0;
    if (cursed[index] != 0) {
        if (index == ITEM_TOOL_KIND_HOE || index == ITEM_TOOL_KIND_WATERING_CAN)
            result = AdvanceProgress(index);
        if (index == ITEM_TOOL_KIND_SICKLE || index == ITEM_TOOL_KIND_HAMMER)
            ResetConsecutiveDays(index);
    }
    return result;
}

u8 CursedToolState::AdvanceToolUses(u32 tool_id)
{
    u32 index = GetToolIndex(tool_id);
    u8 result = 0;
    if (cursed[index] != 0) {
        if (index == ITEM_TOOL_KIND_FISHING_ROD || index == ITEM_TOOL_KIND_AXE)
            result = AdvanceProgress(index);
    }
    return result;
}
