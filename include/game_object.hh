#ifndef GAME_OBJECT_HH
#define GAME_OBJECT_HH

#include "prelude.h"
#include "fomt_constants.hh"
#include "map_data.hh"
#include "resource_archive.hh"

#pragma interface "game_object.hh"

// The scene passes one borrowed input-state pointer to its world update.
struct HardwareInputState;
struct GameObjectUpdateContext {
    HardwareInputState * input;
};

typedef char GameObjectUpdateContextSizeCheck[sizeof(GameObjectUpdateContext) == 4 ? 1 : -1];
struct AEntity;
struct AActorEntity;
struct Location;
struct GameStateClock;
struct GameSceneScriptRequest;
struct EntityAuxiliarySprites;
struct GameSceneSongPlayerPool;
struct Product;
struct GameTime;

// Native common interface: 44 table words, including the two metadata slots.
// The world interface extends it to 90 words without adding instance storage.
struct GameObjectBase
{
    virtual ~GameObjectBase() {}
    virtual void Update(GameObjectUpdateContext const & input);
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
    virtual EntityAuxiliarySprites * GetEntityAuxiliarySprites();
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
};

struct GameObject : GameObjectBase
{
    virtual ~GameObject() {}
    virtual void ChangeMap(Location const & location, bool unk);
    virtual void RefreshMapTimeOfDayPalette();
    // Unrecovered slots retain their offsets; only the television pair is named.
    // Script SetGameTime forwards a borrowed packed time at this slot.
    virtual void vfunc_BC(GameTime const & time);
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
    // Sets a pending marker and one unknown byte in the native world.
    virtual void SetPendingUnknownValue(u8 value);
    virtual void QueueScript(GameSceneScriptRequest const & request, i32 queue_kind);
    virtual GameStateClock const * GetClock() = 0;

    virtual u32 GetDefaultAudioSequence();
    virtual GameSceneSongPlayerPool & GetSongPlayerPool();
    virtual void LightFireplaceAtLocation(MaryMapId map);
    virtual void SetVaseArticleId(MaryItemArticleId article);
    virtual void vfunc_158();
    virtual void ShipProduct(Product const & product);
    virtual void CreateEventIcon(MaryEventIconSlot slot, MaryMapSpaceX x,
        MaryMapSpaceY y, MaryEventIconLayer layer, u16 icon_id);
    virtual void RemoveEventIcon(MaryEventIconSlot slot);

    /* +00 */ // vtable
};

typedef char GameObjectBaseSizeCheck[sizeof(GameObjectBase) == 4 ? 1 : -1];
typedef char GameObjectSizeCheck[sizeof(GameObject) == 4 ? 1 : -1];

#endif // GAME_OBJECT_HH
