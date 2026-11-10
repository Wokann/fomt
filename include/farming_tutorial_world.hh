#ifndef FARMING_TUTORIAL_WORLD_HH
#define FARMING_TUTORIAL_WORLD_HH

#include "game_object.hh"
#include "world_runtime.hh"
#include "entity_actor.hh"
#include "farming_tutorial_map.hh"

struct FarmingTutorialWorldBase;

// The native factory and tutorial runner transfer a one-pointer owner.
// The transfer caches the pointer while clearing the source slot; cleanup
// dispatches through the tutorial world's own common virtual interface.
struct FarmingTutorialWorldOwnerTransfer {
    FarmingTutorialWorldBase * & source;
    FarmingTutorialWorldBase * value;

    FarmingTutorialWorldOwnerTransfer(FarmingTutorialWorldBase * & slot,
        FarmingTutorialWorldBase * world) : source(slot), value(world) {}
    FarmingTutorialWorldBase * release() const
    {
        source = nullptr;
        return value;
    }
};

struct FarmingTutorialWorldOwner {
    FarmingTutorialWorldBase * value;

    FarmingTutorialWorldBase * release()
    {
        FarmingTutorialWorldBase * world = value;
        value = nullptr;
        return world;
    }
    explicit FarmingTutorialWorldOwner(FarmingTutorialWorldBase * world = nullptr) : value(world) {}
    FarmingTutorialWorldOwner(FarmingTutorialWorldOwner & other) : value(other.release()) {}
    FarmingTutorialWorldOwner(FarmingTutorialWorldOwnerTransfer other) : value(other.release()) {}
    ~FarmingTutorialWorldOwner();
    FarmingTutorialWorldOwner & operator=(FarmingTutorialWorldOwner & other);
    FarmingTutorialWorldOwner & operator=(FarmingTutorialWorldOwnerTransfer other);
    operator FarmingTutorialWorldOwnerTransfer()
    {
        return FarmingTutorialWorldOwnerTransfer(value, value);
    }
};

#pragma interface "farming_tutorial_world.hh"

// The tutorial shares the first 44 virtual-table words with GameObjectBase,
// then extends the interface with its four tutorial-specific operations.
struct FarmingTutorialWorldBase : GameObjectBase {
    virtual void Update(GameObjectUpdateContext const & input) = 0;
    virtual void Draw(GameObjectDrawContext const & context) = 0;
    virtual u32 vfunc_14() = 0;
    virtual i32 GetCameraX() = 0;
    virtual i32 GetCameraY() = 0;
    virtual void SetCameraPosition(i32 x, i32 y) = 0;
    virtual void PanCameraTo(i32 x, i32 y, u32 speed) = 0;
    virtual bool IsCameraMovementComplete() = 0;
    virtual i32 GetMapPixelWidth(u32 map_id) = 0;
    virtual i32 GetMapPixelHeight(u32 map_id) = 0;
    virtual MapTerrainView GetMapTerrain(u32 map_id) = 0;
    virtual void vfunc_38(u32 entity_id) = 0;
    virtual void vfunc_3C(u32 index) = 0;
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
    virtual IndexedResourceArchive * vfunc_68() = 0;
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
    virtual void ChangeMap(Location const & location) = 0;
    virtual void SetPlot(i32 x, i32 y, FieldPlot const & plot) = 0;
    virtual void SpawnEffect(i32 x, i32 y, u32 kind) = 0;
    virtual void vfunc_BC(Location const & location, u16 resource_index) = 0;
};

// Tutorial livestock use the ordinary actor state and a dedicated visual setup.
struct FarmingTutorialActor : AActorEntity {
    // Construction is still inlined in FarmingTutorialWorld::vfunc_38.
    explicit FarmingTutorialActor(GameObject * game_object);

    virtual EntityVisualController * CreateVisualController()
    {
        return new EntitySpriteController(this, 5, 0x1B, 1, 0, 0, false);
    }
};

// The persistent and tutorial worlds both own this data at +4, but expose
// different extended virtual interfaces. They are not interchangeable types.
struct FarmingTutorialWorld : FarmingTutorialWorldBase {
    FarmingTutorialWorld(GameSceneWorldMapOwner map);
    virtual void Update(GameObjectUpdateContext const & input);
    virtual void Draw(GameObjectDrawContext const & context);
    virtual u32 vfunc_14();
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
    virtual IndexedResourceArchive * vfunc_68();
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
    virtual void ChangeMap(Location const & location);
    virtual void SetPlot(i32 x, i32 y, FieldPlot const & plot);
    virtual void SpawnEffect(i32 x, i32 y, u32 kind);
    virtual void vfunc_BC(Location const & location, u16 resource_index);

    GameSceneWorldData data;
};

typedef char FarmingTutorialWorldBaseSizeCheck[sizeof(FarmingTutorialWorldBase) == 4 ? 1 : -1];
typedef char FarmingTutorialWorldDataCheck[offsetof(FarmingTutorialWorld, data) == 4 ? 1 : -1];
typedef char FarmingTutorialWorldSizeCheck[sizeof(FarmingTutorialWorld) == 0x1038 ? 1 : -1];
typedef char FarmingTutorialActorSizeCheck[sizeof(FarmingTutorialActor) == 0x30 ? 1 : -1];


typedef char FarmingTutorialWorldOwnerSizeCheck[sizeof(FarmingTutorialWorldOwner) == 4 ? 1 : -1];
typedef char FarmingTutorialWorldOwnerTransferSizeCheck[sizeof(FarmingTutorialWorldOwnerTransfer) == 8 ? 1 : -1];

// Nontrivial C++ return values use the existing r0 result slot. The factory's
// native body remains unchanged and returns that same slot in all four ROMs.
extern "C" FarmingTutorialWorldOwner CreateFarmingTutorialWorld();

#endif // FARMING_TUTORIAL_WORLD_HH
