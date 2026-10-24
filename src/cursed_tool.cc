#include "cursed_tool.hh"

u8 const gCursedToolProgressLimits[] = { 10, 10, 255, 10, 10, 255 };

CursedToolState::CursedToolState()
{
    for (u32 i = 0; i < 6; ++i) {
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
    u32 result = 1;
    switch (tool_id) {
    case ITEM_TOOL_SICKLE_CURSED: result = 0; break;
    case ITEM_TOOL_HOE_CURSED: result = 1; break;
    case ITEM_TOOL_AXE_CURSED: result = 2; break;
    case ITEM_TOOL_HAMMER_CURSED: result = 3; break;
    case ITEM_TOOL_WATERING_CAN_CURSED: result = 4; break;
    case ITEM_TOOL_FISHING_ROD_CURSED: result = 5; break;
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

u32 CursedToolState::HaveFoundAllTools() const
{
    u32 result = 0;
    i32 value = blessed[1];
    value = -value;
    if ((-cursed[1] | value) >= 0) goto end;
    value = blessed[0]; value = -value;
    if ((-cursed[0] | value) >= 0) goto end;
    value = blessed[2]; value = -value;
    if ((-cursed[2] | value) >= 0) goto end;
    value = blessed[3]; value = -value;
    if ((-cursed[3] | value) >= 0) goto end;
    value = blessed[4]; value = -value;
    if ((-cursed[4] | value) >= 0) goto end;
    value = blessed[5]; value = -value;
    result = (u32)(-cursed[5] | value) >> 31;
end:
    return result;
}

bool CursedToolState::HaveBlessedAllTools() const
{
    u32 result = 0;
    if (blessed[1] == 0) goto end;
    if (blessed[0] == 0) goto end;
    if (blessed[2] == 0) goto end;
    if (blessed[3] == 0) goto end;
    if (blessed[4] == 0) goto end;
    result = (u32)-blessed[5] >> 31;
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
        if (index == 0 || index == 3)
            progress[index] = 0;
    }
}

u8 CursedToolState::AdvanceEquippedDays(u32 tool_id)
{
    u8 result = 0;
    u32 index = GetToolIndex(tool_id);
    if (cursed[index] != 0) {
        if (index == 0 || index == 3)
            result = AdvanceProgress(index);
    }
    return result;
}

u8 CursedToolState::AttemptChurchRemoval(u32 tool_id)
{
    u32 index = GetToolIndex(tool_id);
    u8 result = 0;
    if (cursed[index] != 0) {
        if (index == 1 || index == 4)
            result = AdvanceProgress(index);
        if (index == 0 || index == 3)
            ResetConsecutiveDays(index);
    }
    return result;
}

u8 CursedToolState::AdvanceToolUses(u32 tool_id)
{
    u32 index = GetToolIndex(tool_id);
    u8 result = 0;
    if (cursed[index] != 0) {
        if (index == 5 || index == 2)
            result = AdvanceProgress(index);
    }
    return result;
}
