#include "prelude.h"

struct EntityUiUnknownState
{
    u8 unknown_00[0x41];
    u8 unknown_41;
};

// The ROM leaf unconditionally returns false.  Its caller-facing purpose is
// not mapped yet.
extern "C" bool func_080324B8()
    SECTION(".text.entity_ui_default_no_action");

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

extern "C" bool func_080324B8()
{
    return false;
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
