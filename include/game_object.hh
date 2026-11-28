#ifndef GAME_OBJECT_HH
#define GAME_OBJECT_HH

#include "prelude.h"
#include "fomt_constants.hh"
#include "map_terrain.hh"
#include "resource_archive.hh"

#pragma interface "game_object.hh"

// The scene passes one borrowed input-state pointer to its world update.
struct HardwareInputState;
struct GameObjectUpdateContext {
    HardwareInputState * input;
};

// Borrowed hardware state for one native world draw, at offsets 0/4/8/C.
struct HardwareDmaQueue;
struct HardwareDisplayState;
struct HardwareSpriteBufferState;
struct HardwareLinkedList;
struct GameObjectDrawContext {
    HardwareDmaQueue * queue;
    HardwareDisplayState * display;
    HardwareSpriteBufferState * sprites;
    HardwareLinkedList * commands;
};

struct AEntity;
struct AActorEntity;
struct Location;
struct GameStateClock;
struct GameSceneScriptRequest;
struct EntityAuxiliarySprites;
struct GameSceneSongPlayerPool;
struct Product;
struct GameTime;
struct RucksackItem;
struct Article;
struct Vec2;
struct Box;

// Native common interface: 44 table words, including the two metadata slots.
// The world interface extends it to 90 words without adding instance storage.
struct GameObjectBase
{
    virtual ~GameObjectBase() {}
    virtual void Update(GameObjectUpdateContext const & input) = 0;
    virtual void Draw(GameObjectDrawContext const & context) = 0;
    virtual u32 vfunc_14() = 0; // ok, get current map
    virtual i32 GetCameraX() = 0;
    virtual i32 GetCameraY() = 0;
    virtual void SetCameraPosition(i32 x, i32 y) = 0;
    virtual void PanCameraTo(i32 x, i32 y, u32 speed) = 0;
    virtual bool IsCameraMovementComplete() = 0;
    virtual i32 GetMapPixelWidth(u32 map_id) = 0;
    virtual i32 GetMapPixelHeight(u32 map_id) = 0;
    virtual MapTerrainView GetMapTerrain(u32 map_id) = 0;
    virtual void vfunc_38(u32 entity_id) = 0;
    virtual void RemoveEntity(u32 index) = 0;
    virtual AEntity * GetEntity(u32 id) = 0;
    virtual AEntity * GetEntity(u32 id) const = 0;
    virtual u32 vfunc_48(i32 kind) = 0;
    virtual void ClearSpritePaletteResourceFlag(u32 index) = 0;
    virtual i32 GetSpritePaletteBank(u32 index) = 0;
    virtual void SetSpritePaletteColors(u8 const * data, u32 palette_resource, u8 unk) = 0;
    virtual EntityAuxiliarySprites * GetEntityAuxiliarySprites() = 0;
    virtual IndexedResourceArchive * vfunc_5C() = 0;
    virtual IndexedResourceArchive * vfunc_60() = 0;
    virtual IndexedResourceArchive * vfunc_64() = 0;
    virtual IndexedResourceArchive * vfunc_68() = 0; // actor-animation archive
    virtual IndexedResourceArchive * vfunc_6C() = 0;
    virtual IndexedResourceArchive * vfunc_70() = 0;
    virtual IndexedResourceArchive * vfunc_74() = 0;
    virtual IndexedResourceArchive * vfunc_78() = 0;
    virtual IndexedResourceArchive * vfunc_7C() = 0;
    virtual void StartShipmentBoxDepositAnimation() = 0;
    virtual void PrepareClockMenuTransition() = 0;
    virtual void RestoreAfterClockMenu() = 0;
    virtual void PrepareCookingMenuTransition() = 0;
    virtual void RestoreAfterCookingMenu() = 0;
    virtual void PrepareRecipeMenuTransition() = 0;
    virtual void RestoreAfterRecipeMenu() = 0;
    virtual void RefreshBarnFeedTrough(MaryBarnFeedTroughIndex trough) = 0;
    virtual void RefreshChickenFeedTrough(MaryChickenCoopFeedTroughIndex trough) = 0;
    virtual MaryItemArticleId RemoveRecordPlayerAlbum() = 0;
    virtual MaryItemArticleId SwapRecordPlayerAlbum(MaryItemArticleId article) = 0;
    virtual void RefreshChickenCoopIncubator(MaryChickenCoopIncubatorIndex incubator) = 0;
};

struct GameObject : GameObjectBase
{
    virtual ~GameObject() {}
    virtual bool IsTimePaused() const = 0;
    virtual void ChangeMap(Location const & location, bool unk) = 0;
    virtual void RefreshMapTimeOfDayPalette() = 0;
    // Script SetGameTime forwards a borrowed packed time at this slot.
    virtual void vfunc_BC(GameTime const & time) = 0;
    virtual u32 vfunc_C0(Location const & location) = 0;
    virtual bool vfunc_C4(Location const & location, u32 level) = 0;
    virtual bool vfunc_C8(Location const & location, u32 & item_code) = 0;
    virtual bool vfunc_CC(Location const & location, u32 & item_code) = 0;
    virtual bool vfunc_D0(Location const & location, u32 level) = 0;
    virtual bool vfunc_D4(Location const & location) = 0;
    virtual u32 vfunc_D8(Location const & location) = 0;
    virtual void vfunc_DC(Location const & location, i32 id) = 0;
    virtual void vfunc_E0(Location const & location, RucksackItem & output) = 0;
    virtual void vfunc_E4(Location const & location, Article const & article) = 0;
    virtual u32 vfunc_E8(Location const & location, Article const & article) = 0;
    virtual bool vfunc_EC(u32 map_id, u32 level) = 0;
    virtual bool vfunc_F0(u32 map_id, u32 level) = 0;
    virtual void vfunc_F4() = 0;
    virtual void vfunc_F8() = 0;
    virtual void RedrawRucksackShelfAfterPurchase() = 0;
    virtual void RedrawBlueFeatherShelfAfterPurchase() = 0;
    virtual void vfunc_104() = 0;
    virtual bool vfunc_108(Vec2 const & position) = 0;
    virtual void OpenDoor(MaryDoorIndex door_index) = 0;
    virtual void CloseDoor(MaryDoorIndex door_index) = 0;
    virtual void vfunc_114() = 0;
    virtual void SetTelevisionProgram(MaryTelevisionProgramId program) = 0;
    virtual void EndTelevisionProgram() = 0;
    virtual bool vfunc_120(Location const & location) = 0;
    virtual void SuspendUpdates() = 0;
    virtual void ResumeUpdates() = 0;
    virtual AEntity * vfunc_12C(u32 id) = 0;
    virtual AEntity * vfunc_130(u32 id) = 0;
    virtual u32 vfunc_134(Location const & location, Box const & bounds) = 0;
    virtual void vfunc_138() = 0;
    // Sets a pending marker and one unknown byte in the native world.
    virtual void SetPendingUnknownValue(u8 value) = 0;
    virtual void QueueScript(GameSceneScriptRequest const & request, i32 queue_kind) = 0;
    virtual GameStateClock const * GetClock() = 0;

    virtual u32 GetDefaultAudioSequence() = 0;
    virtual GameSceneSongPlayerPool & GetSongPlayerPool() = 0;
    virtual void LightFireplaceAtLocation(MaryMapId map) = 0;
    virtual void SetVaseArticleId(MaryItemArticleId article) = 0;
    virtual void vfunc_158(Location const & location, RucksackItem const & item) = 0;
    virtual void ShipProduct(Product const & product) = 0;
    virtual void CreateEventIcon(MaryEventIconSlot slot, MaryMapSpaceX x,
        MaryMapSpaceY y, MaryEventIconLayer layer, u16 icon_id) = 0;
    virtual void RemoveEventIcon(MaryEventIconSlot slot) = 0;

    /* +00 */ // vtable
};



#endif // GAME_OBJECT_HH
