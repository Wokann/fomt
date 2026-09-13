#ifndef ENTITY_UI_HH
#define ENTITY_UI_HH

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

struct EntityUiUnknownEntry
{
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
};

// The callers establish the physical 8-byte layout, but not the game-level
// meaning of these fields yet.
struct EntityUiUnknownTableEntry
{
    u16 unk_00;
    u16 unk_02;
    i8 unk_04;
    i8 unk_05;
    u8 unk_06;
    u8 unk_07;
};

struct EntityUiScreenOffset
{
    i16 x;
    i16 y;
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

struct EntityUiCallbackState
{
    u8 unknown_00[0x10];
    void * unknown_10;
    u8 unknown_14[0x1C];
    u8 value_30;
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

extern "C" char const gText_NotAvailable[];

// Native assembly has direct relocations to these source-defined UI tables.
// Keep the unresolved names until the callers establish game-level meanings.
extern "C" u32 const gUnk_080F0E88[];
extern "C" u32 const gUnk_080F0F78[];
extern "C" u16 const gUnk_080F0FCC[6][7];
extern "C" EntityUiUnknownTableEntry const gUnk_080F1020[6][7];
extern "C" u32 const gUnk_080F1170[];
extern "C" u8 const gUnk_080F1178[];
extern "C" u8 const gUnk_080F117F[];
extern "C" u8 const gUnk_080F1184[];
extern "C" u8 const gUnk_080F118C[];
extern "C" u8 const gUnk_080F1194[];
extern "C" u8 const gUnk_080F119C[];
extern "C" u8 const gUnk_080F11A4[];
extern "C" u8 const gUnk_080F11AC[];
extern "C" u8 const gUnk_080F11B4[];
extern "C" u32 const gUnk_080F11BC[];
extern "C" u32 const gUnk_080F11E0[];
extern "C" u32 const gUnk_080F1218[];
extern "C" u32 const gUnk_080F1224[];
extern "C" u8 const gUnk_080F1230[];
extern "C" EntityUiScreenOffset const gUnk_080F1328[];
extern "C" u32 const gUnk_080F143C[];
extern "C" u16 const gEntityUiAnimationLookupTable[];
extern "C" u8 const gUnk_080F1496[];
extern "C" u32 const gUnk_080F149C[];
extern "C" u32 const gUnk_080F14B8[];
extern "C" u16 const gUnk_080F14D4[];
extern "C" u16 const gUnk_080F14E2[];
extern "C" u16 const gUnk_080F14F0[];
extern "C" u16 const gUnk_080F1514[];
extern "C" EntityUiUnknownEntry const gUnk_080F1538[];
extern "C" u16 const gUnk_080F1560[];
extern "C" EntityUiUnknownEntry const gUnk_080F156C[];
extern "C" u16 const gUnk_080F15A4[];
extern "C" EntityUiUnknownEntry const gUnk_080F15B4[];
extern "C" u16 const gUnk_080F161C[];
extern "C" EntityUiUnknownEntry const gUnk_080F1638[];
extern "C" u16 const gUnk_080F1644[];
extern "C" u16 const gUnk_080F165E[];
extern "C" u16 const gUnk_080F1672[];
extern "C" u32 const gUnk_080F1678[];
extern "C" u16 const gUnk_080F1684[][4];
extern "C" u16 const gUnk_080F16AE[];
extern "C" u16 const gUnk_080F16C2[];
extern "C" i16 const gUnk_080F16D2[];
extern "C" u8 const gUnk_080F18D2[];
extern "C" u8 const gUnk_080F1904[];
extern "C" u32 const gUnk_080F1948[];

// These runtime literals are physically interleaved with the native tables
// above, so their declarations belong to this one UI module as well.
extern "C" char const gCppRuntimeBadAlloc_EntityUiBeforeOffsets[];
extern "C" char const gCppRuntimeError_EntityUiBeforeOffsets[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiAfterOffsets[];
extern "C" char const gCppRuntimeError_EntityUiAfterOffsets[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiFirst[];
extern "C" char const gCppRuntimeError_EntityUiFirst[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiSecond[];
extern "C" char const gCppRuntimeError_EntityUiSecond[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiThird[];
extern "C" char const gCppRuntimeError_EntityUiThird[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiFourth[];
extern "C" char const gCppRuntimeError_EntityUiFourth[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiFifth[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiSixth[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiSeventh[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiEighth[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiNinth[];
extern "C" char const gCppRuntimeBadAlloc_EntityUiTenth[];

#endif
