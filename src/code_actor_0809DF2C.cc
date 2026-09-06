#include "prelude.h"

extern "C" i32 GetFirstSlotWithTool__C8RucksackUi(void * rucksack, u32 type);
extern "C" i32 GetFirstSlotWith__C9ToolChestUi(void * tool_chest, u32 type);

EC bool func_0809DF2C(u32 unused, u32 group, u8 * game)
{
    bool available = false;
    i32 type = 0x51;

    switch (group)
    {
    case 4:
        type = 5;
        break;
    case 5:
        type = 0xD;
        break;
    case 6:
        type = 0x15;
        break;
    case 7:
        type = 0x1D;
        break;
    case 8:
        type = 0x25;
        break;
    case 9:
        type = 0x2D;
        break;
    }

    if (type <= 0x50)
    {
        if (GetFirstSlotWithTool__C8RucksackUi(game + 0x1C38, type) != -1)
            available = true;
        if (GetFirstSlotWith__C9ToolChestUi(game + 0x380, type) != -1)
            available = true;
    }
    return available;
}
