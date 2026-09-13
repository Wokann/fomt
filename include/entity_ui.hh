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

#endif
