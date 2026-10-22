#ifndef UNKNOWN_TYPES_HH
#define UNKNOWN_TYPES_HH

#include "prelude.h"

#include "fomt_constants.hh"
#include "map_data.hh"
#include "resource_handle.hh"

// TODO: move elsewhere
struct UnkBarnAnimal2C
{
    /* +00 */ u16 unk_00;
    /* +02 */ u8 unk_02;
    /* +03 */ u8 unk_03;
};

// TODO: move elsewhere
struct UnkBarnAnimal2C_x2
{
    /* +00 */ UnkBarnAnimal2C a;
    /* +04 */ UnkBarnAnimal2C b;
};

// TODO: move elsewhere
struct Box
{
    /* +00 */ i16 x1, y1;
    /* +04 */ i16 x2, y2;

    Box(u32 x, u32 y)
        : x1(x), y1(y), x2(x), y2(y)
    {
    }

    Box(u32 x, u32 y, u32 w, u32 h)
    {
        x1 = x - w / 2;
        y1 = y - h / 2;
        x2 = x + w - w / 2;
        y2 = y + h - h / 2;
    }

    Box(u32 x1, u32 y1, u32 x2, u32 y2, i32 x_off, i32 y_off)
        : x1(x_off + x1), y1(y_off + y1), x2(x_off + x2), y2(y_off + y2)
    {
    }

    Box Moved(i32 x, i32 y) const { return Box(x1, y1, x2, y2, x, y); }
};

// TODO: rename
// TODO: move elsewhere
struct UnkMapBox : public Box
{
    UnkMapBox(Box const & box)
        : Box(box)
    {
    }
};

// TODO: move elsewhere
struct AEntity;
struct AActorEntity;
struct Location;
struct GameStateClock;
struct IndexedResourceArchive;
struct GameSceneScriptRequest;

struct GameObject
{
    virtual ~GameObject();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual u32 vfunc_14(); // ok, get current map
    virtual i32 GetCameraX();
    virtual i32 GetCameraY();
    virtual void SetCameraPosition(i32 x, i32 y);
    virtual void PanCameraTo(i32 x, i32 y, u32 speed);
    virtual bool IsCameraMovementComplete();
    virtual i32 GetMapPixelWidth(u32 map_id);
    virtual i32 GetMapPixelHeight(u32 map_id);
    virtual MapTerrainView GetMapTerrain(u32 map_id);
    virtual void vfunc_38(u32 entity_id);
    virtual void vfunc_3C(u32 index);
    virtual AEntity * GetEntity(u32 id);
    virtual AEntity * GetEntity(u32 id) const;
    virtual u32 vfunc_48(i32 kind);
    virtual void ClearSpritePaletteResourceFlag(u32 index);
    virtual i32 GetSpritePaletteBank(u32 index);
    virtual void SetSpritePaletteColors(u8 const * data, u32 palette_resource, u8 unk);
    virtual void * vfunc_58();
    virtual IndexedResourceArchive * vfunc_5C();
    virtual IndexedResourceArchive * vfunc_60();
    virtual IndexedResourceArchive * vfunc_64();
    virtual IndexedResourceArchive * vfunc_68(); // actor-animation archive
    virtual IndexedResourceArchive * vfunc_6C();
    virtual IndexedResourceArchive * vfunc_70();
    virtual IndexedResourceArchive * vfunc_74();
    virtual IndexedResourceArchive * vfunc_78();
    virtual IndexedResourceArchive * vfunc_7C();
    virtual void StartShipmentBoxDepositAnimation();
    virtual void PrepareClockMenuTransition();
    virtual void RestoreAfterClockMenu();
    virtual void PrepareCookingMenuTransition();
    virtual void RestoreAfterCookingMenu();
    virtual void PrepareRecipeMenuTransition();
    virtual void RestoreAfterRecipeMenu();
    virtual void RefreshBarnFeedTrough(MaryBarnFeedTroughIndex trough);
    virtual void RefreshChickenFeedTrough(MaryChickenCoopFeedTroughIndex trough);
    virtual MaryItemArticleId RemoveRecordPlayerAlbum();
    virtual MaryItemArticleId SwapRecordPlayerAlbum(MaryItemArticleId article);
    virtual void RefreshChickenCoopIncubator(MaryChickenCoopIncubatorIndex incubator);
    virtual bool IsTimePaused() const;
    virtual void ChangeMap(Location const & location, bool unk);
    virtual void RefreshMapTimeOfDayPalette();
    // Unrecovered slots retain their offsets; only the television pair is named.
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual void vfunc_F0();
    virtual void vfunc_F4();
    virtual void vfunc_F8();
    virtual void RedrawRucksackShelfAfterPurchase();
    virtual void RedrawBlueFeatherShelfAfterPurchase();
    virtual void vfunc_104();
    virtual void vfunc_108();
    virtual void OpenDoor(MaryDoorIndex door_index);
    virtual void CloseDoor(MaryDoorIndex door_index);
    virtual void vfunc_114();
    virtual void SetTelevisionProgram(MaryTelevisionProgramId program);
    virtual void EndTelevisionProgram();
    virtual void vfunc_120();
    virtual void SuspendUpdates();
    // Unrecovered entries preserve the native slot order; their call ABIs
    // are not established. GetClock is verified through the concrete table.
    virtual void ResumeUpdates();
    virtual void vfunc_12C();
    virtual void vfunc_130();
    virtual void vfunc_134();
    virtual void vfunc_138();
    virtual void vfunc_13C();
    virtual void QueueScript(GameSceneScriptRequest const & request, i32 queue_kind);
    virtual GameStateClock const * GetClock() = 0;

    /* +00 */ // vtable
};

struct UnknownEntityThingBase
{
    virtual ~UnknownEntityThingBase();
    virtual void vfunc_0C();
    virtual void vfunc_10(u32 dummy);

    /* +00 */ int * dummy;
    /* +04 */ // vtable
};

// TODO: move elsewheres
struct UnknownEntityThing : public UnknownEntityThingBase
{
    /* +08 */ STRUCT_PAD(0x08, 0x30);
    /* +30 */ IndexedResourceHandle sprite_animator;
    /* +44 */ u8 unk_44;
    /* +45 */ u8 unk_45;
    /* +46 */ u8 unk_46;
    /* +47 */ u8 unk_47;

    // TODO: these may be in a different/derived class

    /* +48 */ STRUCT_PAD(0x48, 0x70);

    /* +70 */ IndexedResourceHandle sprite_animator_70;
    /* +84 */ u8 unk_84;
    /* +85 */ STRUCT_PAD(0x85, 0x86);
    /* +86 */ u8 unk_86;
    /* +87 */ u8 unk_87;
    /* +88 */ u8 unk_88;
    /* +89 */ STRUCT_PAD(0x89, 0x8A);
    /* +8A */ u8 unk_8A_0 : 2;
    /* +8A */ u8 unk_8A_2 : 6;
};

typedef char EntitySpriteAnimationOffsetCheck[offsetof(UnknownEntityThing, sprite_animator) == 0x30 ? 1 : -1];
typedef char EntitySecondSpriteAnimationOffsetCheck[offsetof(UnknownEntityThing, sprite_animator_70) == 0x70 ? 1 : -1];

// Calendar day values. Shift these left by two bits when forming a GameDate
// byte, whose low two bits hold a Season.
#define DAY_01 1
#define DAY_02 2
#define DAY_03 3
#define DAY_04 4
#define DAY_05 5
#define DAY_06 6
#define DAY_07 7
#define DAY_08 8
#define DAY_09 9
#define DAY_10 10
#define DAY_11 11
#define DAY_12 12
#define DAY_13 13
#define DAY_14 14
#define DAY_15 15
#define DAY_16 16
#define DAY_17 17
#define DAY_18 18
#define DAY_19 19
#define DAY_20 20
#define DAY_21 21
#define DAY_22 22
#define DAY_23 23
#define DAY_24 24
#define DAY_25 25
#define DAY_26 26
#define DAY_27 27
#define DAY_28 28
#define DAY_29 29
#define DAY_30 30

struct PACKED GameDate
{
    /* bit 0 */ Season season : 2;
    /* bit 2 */ u8 day : 5;

    GameDate() {}
    // Explicit construction stores the supplied packed day field.
    GameDate(Season season, u32 day)
        : season(season), day(day) {}

    Season GetSeason() const { return season; }
    unsigned int GetDay() const { return day; }
};

struct PACKED ALIGN(2) GameTime
{
    /* bit 0 */ u8 clock_hour : 5;
    /* bit 5 */ u8 clock_minute : 6;

    GameTime() {}
    GameTime(u8 hour, u8 minute) : clock_hour(hour), clock_minute(minute) {}

    unsigned int GetHour() const { return clock_hour; }
};

typedef char GameDateSizeCheck[sizeof(GameDate) == 1 ? 1 : -1];
typedef char GameTimeSizeCheck[sizeof(GameTime) == 2 ? 1 : -1];

#endif // UNKNOWN_TYPES_HH
