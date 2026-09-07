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

extern "C" char const gText_NotAvailable[8];

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
