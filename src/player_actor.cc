#include "prelude.h"

#pragma implementation "player_actor.hh"
#include "player_actor.hh"

#include "game_state.hh"
#include "field_tool.hh"
#include "entity_ui.hh"
#include <string.h>

u32 PlayerActor::GetMaxWateringCanCapacity() const
{
    u32 max_tier = 0;
    ToolStack const & held = save_image->farmer.unk_5C;
    if (!held.IsEmpty()) {
        Tool tool = save_image->farmer.GetUpgradedTool(held.GetTool());
        max_tier = AccumulateMaxWateringCanTier(0, tool);
    }

    Rucksack const & rucksack = save_image->farmer.rucksack;
    for (u32 index = 0; index < rucksack.GetSize(); ++index) {
        ToolStack const & stack = rucksack.GetToolAt(index);
        if (!stack.IsEmpty()) {
            Tool tool = save_image->farmer.GetUpgradedTool(stack.GetTool());
            max_tier = AccumulateMaxWateringCanTier(max_tier, tool);
        }
    }

    ToolChest const & chest = save_image->farm.farm_house.tool_chest;
    for (u32 index = 0; index < ToolChest::CAPACITY; ++index) {
        ToolStack const & stack = *chest.GetToolStackAt(index);
        if (!stack.IsEmpty()) {
            Tool tool = save_image->farmer.GetUpgradedTool(stack.GetTool());
            max_tier = AccumulateMaxWateringCanTier(max_tier, tool);
        }
    }

    u8 capacities[7];
    memcpy(capacities, gWateringCanCapacityByTier, sizeof(capacities));
    return capacities[max_tier];
}

u8 PlayerActor::GetUpdateSuspended() const
{
    return update_suspended;
}

void PlayerActor::SetUpdateSuspended(u8 suspended)
{
    update_suspended = suspended;
}
