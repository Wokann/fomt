#include "prelude.h"

#include "entity.hh"
#include "harvest_sprite.hh"

struct EntityUiUnknownState
{
    u8 unknown_00[0x41];
    u8 unknown_41;
};

struct EntityUiConstructorState
{
    void * unknown_00;
    void const * vtable;
};

struct EntityUiHarvestSpriteEntry
{
    u8 flags;
    u8 unknown_01[7];
};

struct EntityUiHarvestSpriteResult
{
    u8 flags;
    u8 unknown_01[7];
};

struct EntityUiAnimationState
{
    u8 unknown_00[0x30];
    u8 entry_index;
};

struct EntityUiResourceSetupState
{
    u8 unknown_00[0xB4];
    u8 resource_handle[0x14];
    u8 enabled;
    u8 unknown_C9;
    u8 active;
    u8 visible;
    u16 first_value;
    u16 second_value;
    u16 duration;
};

struct EntityUiHarvestSpriteState : public AEntity
{
    EntityUiHarvestSpriteState(GameObject * game_object, Location const & location)
        : AEntity(game_object, location)
    {
    }

    u8 unknown_18[0x18];
    u8 entry_index;
    u8 unknown_31[3];
    HarvestSprite * harvest_sprite;
    EntityUiHarvestSpriteEntry const * entries;
    void * unknown_3C;
};

extern "C" void func_080330F4(EntityUiHarvestSpriteResult * result,
                               void * unknown_3C, GameObject * game_object,
                               Location const * location,
                               HarvestSprite::Task task,
                               EntityUiHarvestSpriteEntry const * entries);

extern "C" u16 const gEntityUiAnimationLookupTable[];
extern "C" u16 const gEntityUiResourceIdTable[];
extern "C" void ResolveIndexedResourceHandle(void * handle, u32 index);
extern "C" void func_080324BC(EntityUiConstructorState * state, void * arg_1,
                               u32 arg_2, u32 arg_3, u32 arg_4, u32 arg_5,
                               u32 arg_6, bool arg_7);
extern "C" u8 const vtable_unk_080E6864[];

// The ROM leaf unconditionally returns false.  Its caller-facing purpose is
// not mapped yet.
extern "C" bool func_080324B8()
    SECTION(".text.entity_ui_default_no_action");

// Initializes an unmapped entity-UI object, then assigns its verified vtable.
extern "C" EntityUiConstructorState * func_08032A00(
    EntityUiConstructorState * state, void * arg_1)
    SECTION(".text.entity_ui_constructor");

// The semantic name of byte 0x41 is still unknown; preserve the exact leaf
// write while its callers and owning entity layout are recovered.
extern "C" void func_08033B7C(void * entity)
    SECTION(".text.entity_ui_unknown_flag");

// For kind 2, x=0x110..0x3BF and y=0xB0..0x24F return 1; other coordinates
// return 2.  Every other kind returns 0.  The caller's domain remains unmapped.
extern "C" u32 func_08032900(u32 kind, u32 x, i32 y)
    SECTION(".text.entity_ui_region_classification");

// Converts Harvest Sprite task experience into the fixed-point value consumed
// by the following entity-UI path.  The game-level meaning remains unmapped.
extern "C" u32 func_08033914(u32 task_experience)
    SECTION(".text.entity_ui_harvest_sprite_task_experience");

// Tests the selected Harvest Sprite UI entry before and after its shared
// result-record calculation.  The names of the byte flags remain unmapped.
extern "C" bool func_08033B24(EntityUiHarvestSpriteState * state)
    SECTION(".text.entity_ui_harvest_sprite_selection");

// The caller uses this lookup result as an AActorEntityUi animation ID.  Its
// state-byte categories have not been named yet.
extern "C" u32 func_08034248(EntityUiAnimationState const * state, u32 value)
    SECTION(".text.entity_ui_animation_lookup");

// Initializes the resource handle at +0xB4 and its following UI fields.  The
// three control-byte meanings are not mapped yet.
extern "C" void func_08034BFC(EntityUiResourceSetupState * state,
                               u32 table_index, u32 first_value,
                               u32 second_value)
    SECTION(".text.entity_ui_resource_setup");

extern "C" bool func_080324B8()
{
    return false;
}

extern "C" EntityUiConstructorState * func_08032A00(
    EntityUiConstructorState * state, void * arg_1)
{
    func_080324BC(state, arg_1, 6, 0x20, 1, 0, 0, false);
    state->vtable = vtable_unk_080E6864;
    return state;
}

extern "C" void func_08033B7C(void * entity)
{
    EntityUiUnknownState * state = (EntityUiUnknownState *)entity;

    state->unknown_41 = 0;
}

extern "C" u32 func_08032900(u32 kind, u32 x, i32 y)
{
    if (kind == 2)
    {
        x += (u32)-0x110;
        i32 limit = 0x2AF;

        if (x <= (u32)limit)
        {
            if (y > 0xAF)
            {
                limit -= 0x60;
                if (y <= limit)
                {
                    return 1;
                }
            }
        }

        return 2;
    }

    return 0;
}

extern "C" u32 func_08033914(u32 task_experience)
{
    u32 scale = 0xC0;
    scale <<= 9;

    task_experience++;
    task_experience *= scale;
    task_experience >>= 8;

    u32 base = 0x80;
    base <<= 8;
    return task_experience + base;
}

extern "C" bool func_08033B24(EntityUiHarvestSpriteState * state)
{
    u32 entry_offset = state->entry_index;
    EntityUiHarvestSpriteEntry const * entry = state->entries;
    entry_offset <<= 3;
    entry = (EntityUiHarvestSpriteEntry const *)((u8 const *)entry + entry_offset);
    if ((entry->flags << 28) != 0)
    {
        return false;
    }

    GameObject * game_object = state->game_object;
    EntityUiHarvestSpriteResult result;
    Location location = state->GetLocation();
    HarvestSprite::Task task = state->harvest_sprite->GetCurrentTask();
    func_080330F4(&result, state->unknown_3C, game_object, &location, task,
                  state->entries);

    EntityUiHarvestSpriteResult * result_pointer = &result;
    u32 value = 0;
    if ((result_pointer->flags << 28) == 0)
    {
        value = 1;
    }
    return value;
}

extern "C" u32 func_08034248(EntityUiAnimationState const * state, u32 value)
{
    u16 const * table = gEntityUiAnimationLookupTable;
    u8 entry_index = state->entry_index;
    u32 table_offset = entry_index;
    table_offset <<= 2;
    table_offset += entry_index;
    table_offset += value;
    table_offset <<= 1;

    return *(u16 const *)((u8 const *)table + table_offset);
}

extern "C" void func_08034BFC(EntityUiResourceSetupState * state,
                               u32 table_index, u32 first_value,
                               u32 second_value)
{
    u16 const * table = gEntityUiResourceIdTable;
    u16 resource_id = table[table_index];
    ResolveIndexedResourceHandle(state->resource_handle, resource_id);

    state->enabled = 1;
    state->active = 0;
    state->visible = 1;
    state->first_value = first_value;
    state->second_value = second_value;
    state->duration = 0x3C;
}
