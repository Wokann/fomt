#ifndef GAME_SCENE_HH
#define GAME_SCENE_HH
#include "shop_common.hh"

#include "prelude.h"
#include <stdlib.h>
#include "game_state.hh"
#include "scene.hh"
#include "entity_actor.hh"
#include "ui_state.hh"
#include "hardware_display_output.hh"
#include "script_engine.hh"
#include "fomt_constants.hh"
#include "utility/vec2.hh"
#include "resource_handle.hh"
#include "hardware_resource.hh"
#include "hardware_state_clear.hh"
#include "hardware_state_accessors.hh"
#include "hardware_blend.hh"
#include "hardware_music_player.hh"
#include "time_of_day.hh"
#include "field_render_farm_house_data.hh"

// Only the player virtual interface used by these scene commands is modeled.
// The complete player payload, construction, and action implementations remain
// native. This prefix is never allocated or used to infer the complete size.
// The player owns this native catch record; this interface only borrows it.
struct GameSceneCaughtFish;
struct RucksackItem;
struct Article;
struct GameScenePlayerActor : AActorEntity {
    /* vt+3C */ virtual void vfunc_3C();
    /* vt+40 */ virtual bool IsRidingHorse();
    /* vt+44 */ virtual bool IsHoldingTool();
    /* vt+48 */ virtual bool TryShipHeldItem();
    /* vt+4C */ virtual void ThrowHeldItem();
    /* vt+50 */ virtual void UseHeldItem();
    /* vt+54 */ virtual void ClearHeldItem();
    /* vt+58 */ virtual void vfunc_58();
    /* vt+5C */ virtual void SetHeldItem(RucksackItem const & item, bool wrapped);
    /* vt+60 */ virtual void GiveBasket();
    /* vt+64 */ virtual void ChangeStaminaAndFatigue(MaryStaminaDelta stamina_delta,
        MaryFatigueDelta fatigue_delta);
    /* vt+68 */ virtual void BeginHoldingActorGraphic(u16 animation_id);
    // Unrecovered slots retain their positions; these declarations are not called.
    /* vt+6C */ virtual void vfunc_6C();
    /* vt+70 */ virtual void vfunc_70();
    /* vt+74 */ virtual void vfunc_74();
    /* vt+78 */ virtual MaryAnimalSlotIndex GetInteractingAnimalIndex();
    /* vt+7C */ virtual void ObtainMysticBerry();
    /* vt+80 */ virtual void ObtainPowerBerry();
    /* vt+84 */ virtual MaryHeldItemKind GetPresentedItemKind();
    /* vt+88 */ virtual i32 GetPresentedItemId();
    /* vt+8C */ virtual bool IsPresentedItemGiftWrapped();
    /* vt+90 */ virtual GameSceneCaughtFish const * GetCaughtFish();
    // Unrecovered intervening slots are not called by this partial interface.
    /* vt+94 */ virtual void vfunc_94();
    /* vt+98 */ virtual void vfunc_98();
    /* vt+9C */ virtual void vfunc_9C();
    /* vt+A0 */ virtual void vfunc_A0();
    /* vt+A4 */ virtual void vfunc_A4();
    /* vt+A8 */ virtual void EnterHotSpringBathingState();
    /* vt+AC */ virtual void ExitHotSpringBathingState();
private:
    GameScenePlayerActor();
};
struct GameObject;
struct GameScene;
struct GameStateSaveImage;
struct MusicPlayer;
struct GameSceneIndexedSprite;
struct HardwareBlendController;
struct FieldRenderRectDescriptor;
struct FieldRenderTileAttributes;
struct HardwareDmaQueue;

// The map controller stores Q16.16 camera coordinates. Native integer
// readers sign-extend their high halfwords; movement writes the whole word.
union GameSceneCameraCoordinate {
    i32 q16;
    struct {
        u16 fraction;
        i16 integer;
    } parts;
};

struct MapTilePatchAnimationState {
    u8 frame;
    bool update_pending;
    u8 elapsed_frames;
    void Tick(FarmHouseTilePatchAnimationDescriptor const & animation);
    void ResetFrame();
};

typedef char MapTilePatchAnimationPendingCheck[offsetof(MapTilePatchAnimationState, update_pending) == 1 ? 1 : -1];
typedef char MapTilePatchAnimationElapsedCheck[offsetof(MapTilePatchAnimationState, elapsed_frames) == 2 ? 1 : -1];
typedef char MapTilePatchAnimationStateSizeCheck[sizeof(MapTilePatchAnimationState) == 4 ? 1 : -1];

// Only the verified map/camera prefix is modeled, not the complete object.
// The move routine writes per-frame Q16.16 steps and a frame countdown.
struct GameSceneWorldMapPrefix {
    u32 map;
    u32 map_data_id;
    GameSceneCameraCoordinate x;
    GameSceneCameraCoordinate y;
    u16 * tile_layers[3];
    u16 * time_palette_buffers[3];
    u8 unk_28;
    bool view_changed;
    bool time_palette_changed;
    u8 unk_2B;
    FieldRenderTileAttributes * tile_attributes;
    MapTilePatchAnimationState layout_animations[10];
    u8 unk_58;
    u8 unk_59[0x2B];
    i32 step_x_q16;
    i32 step_y_q16;
    u32 movement_frames;
    virtual ~GameSceneWorldMapPrefix();
    virtual void vfunc_0C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual u32 SelectMapData();
    virtual void LoadTiles();
    virtual void LoadTilemaps();
    virtual void LoadTimeOfDayPalette(i32 period, u32 buffer_index);

private:
    GameSceneWorldMapPrefix();
};

// The native saved-map constructor calls the base constructor, replaces its
// vtable at +0x90, then stores the save pointer at +0x94 and this flag at +0x98.
// The allocation is 0xBC bytes. The runtime member at +0x9C remains
// opaque; the two verified animation states begin at +0xB4 and +0xB8.
// This borrowed view is never allocated or used to infer a native class size.
struct GameSceneSavedMapPrefix : GameSceneWorldMapPrefix {
    GameStateSaveImage * save;
    bool unk_98;
    u8 unk_9C[0x18] ALIGN(4);
    MapTilePatchAnimationState tile_animations[2];

private:
    GameSceneSavedMapPrefix();
};

typedef char GameSceneMapLayoutAnimationsCheck[offsetof(GameSceneWorldMapPrefix, layout_animations) == 0x30 ? 1 : -1];
typedef char GameSceneMapLayoutAnimationsSizeCheck[sizeof(((GameSceneWorldMapPrefix *) 0)->layout_animations) == 0x28 ? 1 : -1];

// These are palette buffers, distinct from the three map tile grids.
typedef char GameSceneMapTimePaletteBuffersCheck[offsetof(GameSceneWorldMapPrefix, time_palette_buffers) == 0x1C ? 1 : -1];
typedef char GameSceneMapTimePaletteChangedCheck[offsetof(GameSceneWorldMapPrefix, time_palette_changed) == 0x2A ? 1 : -1];

typedef char GameSceneSavedMapSaveCheck[offsetof(GameSceneSavedMapPrefix, save) == 0x94 ? 1 : -1];
typedef char GameSceneSavedMapFlagCheck[offsetof(GameSceneSavedMapPrefix, unk_98) == 0x98 ? 1 : -1];
typedef char GameSceneSavedMapOpaqueMemberCheck[offsetof(GameSceneSavedMapPrefix, unk_9C) == 0x9C ? 1 : -1];
typedef char GameSceneSavedMapAnimationsCheck[offsetof(GameSceneSavedMapPrefix, tile_animations) == 0xB4 ? 1 : -1];
typedef char GameSceneSavedMapPrefixSizeCheck[sizeof(GameSceneSavedMapPrefix) == 0xBC ? 1 : -1];

// The native palette cache has 22 resource records and 13 retained banks.
// Keep the remaining record bytes and flags opaque until their users are recovered.
struct GameScenePaletteResource {
    u8 unk_00[0x80];
    i8 palette_slot : 8;
    u8 unk_81;
    u8 unk_82;
    u8 unk_83;
};

struct GameScenePaletteSlot {
    HardwareResourceEntry allocation;
    u8 palette_bank;
    i8 resource_index;
    u8 unk_0A;
    u8 unk_0B;
};

struct GameScenePaletteCache {
    u8 encoded_palette_banks[32];
    GameScenePaletteResource resources[22];
    GameScenePaletteSlot slots[13];
    u8 used_slots;
    u8 unk_C15;

    u32 ResourceCount() const { return ARRAY_COUNT(resources); }
};

typedef char GameScenePaletteResourceSizeCheck[sizeof(GameScenePaletteResource) == 132 ? 1 : -1];
typedef char GameScenePaletteResourceFlagOffsetCheck[offsetof(GameScenePaletteResource, unk_81) == 0x81 ? 1 : -1];
typedef char GameScenePaletteSlotSizeCheck[sizeof(GameScenePaletteSlot) == 12 ? 1 : -1];
typedef char GameScenePaletteCacheSlotsCheck[offsetof(GameScenePaletteCache,slots) == 0xB78 ? 1 : -1];
typedef char GameScenePaletteCacheCountCheck[offsetof(GameScenePaletteCache,used_slots) == 0xC14 ? 1 : -1];
typedef char GameScenePaletteCacheSizeCheck[sizeof(GameScenePaletteCache) == 0xC18 ? 1 : -1];

EC void func_0803B0A8(void * object, int flags);

// The concrete pointee is still native; preserve its direct destruction ABI.
struct GameSceneWorldUnkOwner {
    void * value;
    GameSceneWorldUnkOwner & operator=(void * next)
    {
        if (next != value) {
            if (value != nullptr)
                func_0803B0A8(value, 3);
        }
        value = next;
        return *this;
    }
};

// This one-word owner is passed by value to the native data constructor.
// Transfer clears the source slot; destruction uses the map's real virtual ABI.
struct GameSceneWorldMapOwner {
    GameSceneWorldMapPrefix * value;

    explicit GameSceneWorldMapOwner(GameSceneWorldMapPrefix * input) : value(input) {}
    GameSceneWorldMapPrefix * Release()
    {
        GameSceneWorldMapPrefix * result = value;
        value = nullptr;
        return result;
    }
    GameSceneWorldMapOwner(GameSceneWorldMapOwner & source) : value(source.Release()) {}
    ~GameSceneWorldMapOwner() { delete value; }

private:
    GameSceneWorldMapOwner & operator=(GameSceneWorldMapOwner const &);
};

// Only the virtual-destruction prefix is known. Never allocate this view.
struct GameSceneWorldUnkObject {
    u8 unk_00[0x24];
    virtual ~GameSceneWorldUnkObject();

private:
    GameSceneWorldUnkObject();
};

struct GameSceneWorldUnk1028 {
    GameSceneWorldUnkObject * value;
    Vec2 unk_04;
    u8 unk_08;
    u8 unk_09;
};

// This native world member stores three resource groups and a counted
// sixteen-byte index list. The constructor still uses native assembly.
struct GameSceneWorldUnk1020Entry {
    IndexedResourceGroupResult group;
    HardwareStateEntry tiles;
    u16 tile_index;
};

struct GameScenePaletteIndices {
    u32 count;
    u8 values[16];

    u8 & operator[](u32 index) { return values[index]; }
};

struct GameSceneWorldUnk1020 {
    GameObject * world;
    GameSceneWorldUnk1020Entry entries[3];
    GameScenePaletteIndices indices;
    u8 unk_9C;

    // The shared native constructor implements this real C++ ABI.
    explicit GameSceneWorldUnk1020(GameObject * source);
    ~GameSceneWorldUnk1020();
};

typedef char GameSceneWorldUnk1020EntrySizeCheck[sizeof(GameSceneWorldUnk1020Entry) == 44 ? 1 : -1];
typedef char GameSceneWorldUnk1020EntryTilesCheck[offsetof(GameSceneWorldUnk1020Entry, tiles) == 32 ? 1 : -1];
typedef char GameSceneWorldUnk1020EntryTileIndexCheck[offsetof(GameSceneWorldUnk1020Entry, tile_index) == 40 ? 1 : -1];
typedef char GameSceneWorldUnk1020EntriesCheck[offsetof(GameSceneWorldUnk1020, entries) == 4 ? 1 : -1];
typedef char GameSceneWorldUnk1020IndicesCheck[offsetof(GameSceneWorldUnk1020, indices) == 0x88 ? 1 : -1];
typedef char GameSceneWorldUnk1020IndexValuesCheck[offsetof(GameSceneWorldUnk1020, indices.values) == 0x8C ? 1 : -1];
typedef char GameSceneWorldUnk1020FlagCheck[offsetof(GameSceneWorldUnk1020, unk_9C) == 0x9C ? 1 : -1];
typedef char GameSceneWorldUnk1020SizeCheck[sizeof(GameSceneWorldUnk1020) == 0xA0 ? 1 : -1];

// The native constructor receives this member at world+4, not the complete
// world object. Each archive has its own source and reverse-order destruction.
// The constructor and destructor bodies remain native assembly under their
// real C++ ABI names; declaring them does not count as C++ code recovery.
struct GameSceneWorldData {
    GameSceneWorldMapOwner map;
    AActorEntity * entities[100];
    u32 unk_194;
    GameScenePaletteCache palette_cache;
    IndexedResourceArchive actor_archive;
    IndexedResourceArchive unk_DE0;
    IndexedResourceArchive unk_E10;
    IndexedResourceArchive unk_E40;
    IndexedResourceArchive unk_E70;
    IndexedResourceArchive unk_EA0;
    IndexedResourceArchive unk_ED0;
    IndexedResourceArchive unk_F00;
    IndexedResourceArchive unk_F30;
    IndexedResourceArchive unk_F60;
    IndexedResourceArchive unk_F90;
    IndexedResourceArchive unk_FC0;
    IndexedResourceArchive unk_FF0;
    GameSceneWorldUnk1020 * unk_1020;
    void * unk_1024;
    GameSceneWorldUnk1028 unk_1028;

    GameSceneWorldData(GameSceneWorldMapOwner source);
    ~GameSceneWorldData();

private:
    GameSceneWorldData(GameSceneWorldData const &);
    GameSceneWorldData & operator=(GameSceneWorldData const &);
};

// Native construction clears four records; update/draw code uses a 12-byte stride.
// Only the state bits and tile coordinates have been identified.
struct GameSceneWorldUnk1080Entry {
    u8 unk_00;
    u8 state : 2;
    u8 unk_01_02 : 6;
    u8 unk_02[2];
    u16 tile_x;
    u16 tile_y;
    u32 unk_08;
};

// Only the verified prefix of the enclosing GameObject is modeled. It is
// never allocated or used to infer the full size of a native world subclass.
struct GameSceneWorldPrefix : GameObject {
    // Native world slot +0x148 selects the default audio sequence.
    virtual u32 GetDefaultAudioSequence() = 0;
    // Preserve the unrecovered slot before the world-only furniture hooks.
    virtual void vfunc_14C();
    virtual void LightFireplaceAtLocation(MaryMapId map);
    virtual void SetVaseArticleId(MaryItemArticleId article);

    GameSceneWorldData data;
    GameStateSaveImage * save;
    u8 unk_103C[0x14];
    FieldRenderTileAttributes * farm_tile_attributes;
    GameScene * scene;
    SmartPtr<GameSceneIndexedSprite> unk_1058;
    u8 unk_105C[0x20];
    GameSceneWorldUnkOwner unk_107C;
    GameSceneWorldUnk1080Entry unk_1080[4];
};

// A successful farm lookup returns the plot and both tile/grid coordinates.
struct FieldPlot;
struct FieldPlotRenderData;
struct GameSceneFarmPlotLocation {
    GameSceneFarmPlotLocation()
        : plot(nullptr), tile_x(0), tile_y(0), column(0), row(0) {}

    FieldPlot * plot;
    u16 tile_x;
    u16 tile_y;
    u16 column;
    u16 row;
};

// Tool hits distinguish an unsupported target from a supported but unfinished
// removal. Kind and coordinates are valid only when removed is true.
struct Farm;
struct FieldItemState;
struct GameSceneFieldItemToolResult {
    GameSceneFieldItemToolResult() : removed(false), rejected(true) {}

    bool removed;
    i32 kind;
    i32 x;
    i32 y;
    bool rejected;
};

typedef char GameSceneFieldItemToolResultSizeCheck[sizeof(GameSceneFieldItemToolResult) == 20 ? 1 : -1];
typedef char GameSceneFieldItemToolKindCheck[offsetof(GameSceneFieldItemToolResult, kind) == 4 ? 1 : -1];
typedef char GameSceneFieldItemToolPositionCheck[offsetof(GameSceneFieldItemToolResult, x) == 8 ? 1 : -1];
typedef char GameSceneFieldItemToolRejectedCheck[offsetof(GameSceneFieldItemToolResult, rejected) == 16 ? 1 : -1];

typedef char GameSceneWorldUnk1080EntrySizeCheck[sizeof(GameSceneWorldUnk1080Entry) == 12 ? 1 : -1];
typedef char GameSceneWorldUnk1080TileXCheck[offsetof(GameSceneWorldUnk1080Entry, tile_x) == 4 ? 1 : -1];
typedef char GameSceneWorldUnk1080TailCheck[offsetof(GameSceneWorldUnk1080Entry, unk_08) == 8 ? 1 : -1];
typedef char GameSceneWorldFarmTerrainCheck[offsetof(GameSceneWorldPrefix, farm_tile_attributes) == 0x1050 ? 1 : -1];

typedef char GameSceneWorldSceneCheck[offsetof(GameSceneWorldPrefix, scene) == 0x1054 ? 1 : -1];
typedef char GameSceneWorldSpriteCheck[offsetof(GameSceneWorldPrefix, unk_1058) == 0x1058 ? 1 : -1];
typedef char GameSceneWorldUnk105CCheck[offsetof(GameSceneWorldPrefix, unk_105C) == 0x105C ? 1 : -1];

typedef char GameSceneWorldUnk1080Check[offsetof(GameSceneWorldPrefix, unk_1080) == 0x1080 ? 1 : -1];

typedef char GameSceneFarmPlotLocationSizeCheck[sizeof(GameSceneFarmPlotLocation) == 12 ? 1 : -1];
typedef char GameSceneFarmPlotTileXCheck[offsetof(GameSceneFarmPlotLocation, tile_x) == 4 ? 1 : -1];
typedef char GameSceneFarmPlotColumnCheck[offsetof(GameSceneFarmPlotLocation, column) == 8 ? 1 : -1];

typedef char GameSceneCameraCoordinateSizeCheck[sizeof(GameSceneCameraCoordinate) == 4 ? 1 : -1];
typedef char GameSceneCameraIntegerCheck[offsetof(GameSceneCameraCoordinate, parts.integer) == 2 ? 1 : -1];
typedef char GameSceneCameraPointSizeCheck[sizeof(Vec2) == 4 ? 1 : -1];
typedef char GameSceneCameraMapDataIdCheck[offsetof(GameSceneWorldMapPrefix, map_data_id) == 4 ? 1 : -1];
typedef char GameSceneCameraXCheck[offsetof(GameSceneWorldMapPrefix, x) == 8 ? 1 : -1];
typedef char GameSceneCameraYCheck[offsetof(GameSceneWorldMapPrefix, y) == 0xC ? 1 : -1];
typedef char GameSceneMapTileLayersCheck[offsetof(GameSceneWorldMapPrefix, tile_layers) == 0x10 ? 1 : -1];

typedef char GameSceneMapTileAttributesCheck[offsetof(GameSceneWorldMapPrefix, tile_attributes) == 0x2C ? 1 : -1];

typedef char GameSceneMapUnk58Check[offsetof(GameSceneWorldMapPrefix, unk_58) == 0x58 ? 1 : -1];

typedef char GameSceneMapViewChangedCheck[offsetof(GameSceneWorldMapPrefix, view_changed) == 0x29 ? 1 : -1];
typedef char GameSceneCameraStepXCheck[offsetof(GameSceneWorldMapPrefix, step_x_q16) == 0x84 ? 1 : -1];
typedef char GameSceneCameraStepYCheck[offsetof(GameSceneWorldMapPrefix, step_y_q16) == 0x88 ? 1 : -1];
typedef char GameSceneCameraFramesCheck[offsetof(GameSceneWorldMapPrefix, movement_frames) == 0x8C ? 1 : -1];
typedef char GameSceneWorldMapPrefixSizeCheck[sizeof(GameSceneWorldMapPrefix) == 0x94 ? 1 : -1];
typedef char GameSceneWorldMapOwnerSizeCheck[sizeof(GameSceneWorldMapOwner) == 4 ? 1 : -1];
typedef char GameSceneWorldUnkObjectPrefixSizeCheck[sizeof(GameSceneWorldUnkObject) == 0x28 ? 1 : -1];
typedef char GameSceneWorldUnkRecordSizeCheck[sizeof(GameSceneWorldUnk1028) == 12 ? 1 : -1];
typedef char GameSceneWorldUnkRecordPointCheck[offsetof(GameSceneWorldUnk1028, unk_04) == 4 ? 1 : -1];
typedef char GameSceneWorldUnkRecordFlagCheck[offsetof(GameSceneWorldUnk1028, unk_09) == 9 ? 1 : -1];
typedef char GameSceneWorldDataEntitiesCheck[offsetof(GameSceneWorldData, entities) == 4 ? 1 : -1];
typedef char GameSceneWorldDataPaletteCacheCheck[offsetof(GameSceneWorldData, palette_cache) == 0x198 ? 1 : -1];
typedef char GameSceneWorldArchiveSizeCheck[sizeof(IndexedResourceArchive) == 0x30 ? 1 : -1];
typedef char GameSceneWorldDataActorArchiveCheck[offsetof(GameSceneWorldData, actor_archive) == 0xDB0 ? 1 : -1];
typedef char GameSceneWorldDataLastArchiveCheck[offsetof(GameSceneWorldData, unk_FF0) == 0xFF0 ? 1 : -1];
typedef char GameSceneWorldDataUnknownObjectCheck[offsetof(GameSceneWorldData, unk_1020) == 0x1020 ? 1 : -1];
typedef char GameSceneWorldDataUnkRecordCheck[offsetof(GameSceneWorldData, unk_1028) == 0x1028 ? 1 : -1];
typedef char GameSceneWorldDataSizeCheck[sizeof(GameSceneWorldData) == 0x1034 ? 1 : -1];
typedef char GameSceneWorldDataCheck[offsetof(GameSceneWorldPrefix, data) == 4 ? 1 : -1];
typedef char GameSceneWorldMapCheck[offsetof(GameSceneWorldPrefix, data.map.value) == 4 ? 1 : -1];
typedef char GameSceneWorldEntitiesCheck[offsetof(GameSceneWorldPrefix, data.entities) == 8 ? 1 : -1];
typedef char GameSceneWorldPaletteCacheCheck[offsetof(GameSceneWorldPrefix, data.palette_cache) == 0x19C ? 1 : -1];
typedef char GameSceneWorldActorArchiveCheck[offsetof(GameSceneWorldPrefix, data.actor_archive) == 0xDB4 ? 1 : -1];
typedef char GameSceneWorldUnknownObjectCheck[offsetof(GameSceneWorldPrefix, data.unk_1020) == 0x1024 ? 1 : -1];
typedef char GameSceneWorldUnkOwnerSizeCheck[sizeof(GameSceneWorldUnkOwner) == 4 ? 1 : -1];
typedef char GameSceneWorldUnkOwnerCheck[offsetof(GameSceneWorldPrefix, unk_107C) == 0x107C ? 1 : -1];
typedef char GameSceneWorldSaveCheck[offsetof(GameSceneWorldPrefix, save) == 0x1038 ? 1 : -1];

// Only the shared destruction prefix is recovered. The concrete Time Window
// and pause-menu selector payloads and their destructors remain native.
struct GameSceneUiComponent {
    u32 unk_00;
    // Actual existing bootstrap lifecycle ABI; these declarations emit no code.
    GameSceneUiComponent() asm("func_08008444");
    virtual ~GameSceneUiComponent() asm("func_080086BC");
};

struct GameSceneUiComponentOwner {
    GameSceneUiComponent * value;

    GameSceneUiComponentOwner() : value(nullptr) {}
    explicit GameSceneUiComponentOwner(GameSceneUiComponent * input) : value(input) {}
    ~GameSceneUiComponentOwner() { delete value; }
    GameSceneUiComponentOwner & operator=(GameSceneUiComponent * next)
    {
        if (next != value)
            delete value;
        value = next;
        return *this;
    }
};

struct GameSceneTalkWindowOwner {
    UiStateOwner * value;

    GameSceneTalkWindowOwner() : value(nullptr) {}
    ~GameSceneTalkWindowOwner() { delete value; }
    UiStateOwner * Get() const { return value; }
    GameSceneTalkWindowOwner & operator=(UiStateOwner * next)
    {
        if (next != value)
            delete value;
        value = next;
        return *this;
    }
};

struct GameSceneBgmSettings {
    GameSceneBgmSettings()
        : tempo(0x100), volume(0x100), pitch(0), pan(0),
          modulation_depth(0), lfo_speed(0) {}

    u16 tempo;
    u16 volume;
    i16 pitch;
    i8 pan;
    u8 modulation_depth;
    u8 lfo_speed;
};

// Entries point to the scene's pointer slots, not directly to m4a players.
// The empty allocator occupies a word before the capacity pointer at +0x0C.
struct GameSceneSongPlayerPool {
    struct Allocator {
        Allocator() {}
        Allocator(Allocator const &) {}
    };
    struct Allocation {
        Allocator allocator;
        HardwareMusicPlayerSlot ** end;
        Allocation(Allocator const & input) : allocator(input), end(nullptr) {}
    };
    HardwareMusicPlayerSlot ** begin;
    HardwareMusicPlayerSlot ** end;
    Allocation allocation;

    ~GameSceneSongPlayerPool()
    {
        if (begin != nullptr)
            free(begin);
    }

    GameSceneSongPlayerPool(Allocator const & input = Allocator())
        : begin(nullptr), end(nullptr), allocation(input) {}
};

// Each pending request is passed unchanged to LoadById(id, context).
struct GameSceneScriptRequest {
    GameSceneScriptRequest() {}
    GameSceneScriptRequest(i32 script, i32 context)
        : script_id(script), context_value(context) {}

    i32 script_id;
    i32 context_value;
};

template <u32 Capacity>
struct GameSceneScriptQueue {
    GameSceneScriptQueue() : count(0) {}

    u32 count;
    // Only [Data(), End()) contains constructed requests. Native construction
    // leaves the remaining capacity untouched; insertion uses placement new.
    u32 storage[Capacity * 2];

    GameSceneScriptRequest * Data()
    {
        return reinterpret_cast<GameSceneScriptRequest *>(storage);
    }
    GameSceneScriptRequest * End()
    {
        return &reinterpret_cast<GameSceneScriptRequest *>(storage)[count];
    }

    // Native insertion drops a full queue; it does not grow or overwrite it.
    inline void Push(GameSceneScriptRequest const & request);
};

// The native cleanup owns all three adjacent queues and destroys them in
// reverse order. Its out-of-line destructor still has a native implementation.
struct GameSceneScriptQueues {
    ~GameSceneScriptQueues();

    GameSceneScriptQueue<2> queue_0;
    GameSceneScriptQueue<40> queue_1;
    GameSceneScriptQueue<1> queue_2;
};

typedef char GameSceneScriptQueuesSizeCheck[sizeof(GameSceneScriptQueues) == 0x164 ? 1 : -1];
typedef char GameSceneScriptQueuesFirstCheck[offsetof(GameSceneScriptQueues, queue_0) == 0 ? 1 : -1];
typedef char GameSceneScriptQueuesSecondCheck[offsetof(GameSceneScriptQueues, queue_1) == 0x14 ? 1 : -1];
typedef char GameSceneScriptQueuesThirdCheck[offsetof(GameSceneScriptQueues, queue_2) == 0x158 ? 1 : -1];

// The four reusable records back entity slots 70-73, not particular NPCs.
// Actors write their location and animation back here when destroyed; the
// independently stored event-script halfword is read by their script hook.
// See docs/mary-native-audit/entities/entity_event_script_audit.md.
struct GameSceneControllerActorRecord {
    GameSceneControllerActorRecord() asm("func_080D40CC")
        SECTION(".text.game_scene_controller_record_initializers");

    ActorLocation location;
    u16 animation;
    u16 event_script;
};

// The six preceding records also hold packed locations. Only the low two
// bits at +0 and the location are initialized; their gameplay role and the
// remaining fields are not inferred from the four actor records above.
struct GameSceneControllerLocationRecord {
    GameSceneControllerLocationRecord() asm("func_080D4130")
        SECTION(".text.game_scene_controller_record_initializers");

    u8 unk_00_00 : 2;
    u8 unk_00_02 : 6;
    u8 unk_01;
    Location location;
    u8 unk_08[4];
};

typedef char GameSceneControllerActorRecordSizeCheck[sizeof(GameSceneControllerActorRecord) == 12 ? 1 : -1];
typedef char GameSceneControllerActorAnimationCheck[offsetof(GameSceneControllerActorRecord, animation) == 8 ? 1 : -1];
typedef char GameSceneControllerActorScriptCheck[offsetof(GameSceneControllerActorRecord, event_script) == 10 ? 1 : -1];
typedef char GameSceneControllerLocationRecordSizeCheck[sizeof(GameSceneControllerLocationRecord) == 12 ? 1 : -1];
typedef char GameSceneControllerLocationOffsetCheck[offsetof(GameSceneControllerLocationRecord, location) == 2 ? 1 : -1];

// The native clock slot has four-byte storage, unlike the packed GameTime.
// Construction preserves its unknown bits; saving copies only the low halfword.
struct GameScenePreservedClock {
    u16 clock_hour : 5;
    u16 clock_minute : 6;
    u16 unk_11 : 5;

    GameScenePreservedClock() : clock_hour(6), clock_minute(0) {}
};

// This native overnight record saves the map and clock, not coordinates.
struct GameScenePreservedPlayerLocation {
    u8 active;
    u8 unk_01[3];
    MaryMapId map;
    GameScenePreservedClock time;

    MaryMapId GetMapId() const { return map; }

    GameScenePreservedPlayerLocation()
        : active(0), map(MAP_FARMHOUSE) {}
};

// Startup controller, distinct from the eight-byte GameScene wrapper. Both
// constructors, Run and destruction are recovered. The first word is AScene's
// actual inherited vptr, not manually written payload.
struct GameSceneScriptController : AScene {
    GameSceneScriptController(GameStateSaveImageOwner save);
    GameSceneScriptController(char const * farm_name, char const * player_name,
        GameDate birthday, char const * dog_name);
    virtual ~GameSceneScriptController();
    virtual SceneTransitionOwner Run();

    GameStateSaveImageOwner save;
    ScriptEngine script_engine;
    u8 unk_364;
    u8 unk_365[3];
    u32 unk_368;
    GameScenePreservedPlayerLocation preserved_player_location;
    GameSceneScriptQueues queues;
    GameSceneControllerLocationRecord location_records[6];
    GameSceneControllerActorRecord actor_records[4];
};

typedef char GameSceneScriptRequestSizeCheck[sizeof(GameSceneScriptRequest) == 8 ? 1 : -1];
typedef char GameSceneControllerSaveCheck[offsetof(GameSceneScriptController, save) == 4 ? 1 : -1];
typedef char GameSceneControllerEngineCheck[offsetof(GameSceneScriptController, script_engine) == 8 ? 1 : -1];
typedef char GameSceneControllerUnk364Check[offsetof(GameSceneScriptController, unk_364) == 0x364 ? 1 : -1];
typedef char GameSceneControllerUnk368Check[offsetof(GameSceneScriptController, unk_368) == 0x368 ? 1 : -1];
typedef char GameSceneControllerPreservedLocationCheck[offsetof(GameSceneScriptController, preserved_player_location) == 0x36C ? 1 : -1];
typedef char GameSceneControllerPreservedLocationSizeCheck[sizeof(GameScenePreservedPlayerLocation) == 12 ? 1 : -1];
typedef char GameSceneControllerPreservedClockSizeCheck[sizeof(GameScenePreservedClock) == 4 ? 1 : -1];
typedef char GameSceneControllerPreservedFlagCheck[offsetof(GameScenePreservedPlayerLocation, active) == 0 ? 1 : -1];
typedef char GameSceneControllerPreservedMapCheck[offsetof(GameScenePreservedPlayerLocation, map) == 4 ? 1 : -1];
typedef char GameSceneControllerPreservedTimeCheck[offsetof(GameScenePreservedPlayerLocation, time) == 8 ? 1 : -1];
typedef char GameSceneControllerQueuesCheck[offsetof(GameSceneScriptController, queues) == 0x378 ? 1 : -1];
typedef char GameSceneControllerQueue0Check[offsetof(GameSceneScriptController, queues.queue_0) == 0x378 ? 1 : -1];
typedef char GameSceneControllerQueue1Check[offsetof(GameSceneScriptController, queues.queue_1) == 0x38C ? 1 : -1];
typedef char GameSceneControllerQueue2Check[offsetof(GameSceneScriptController, queues.queue_2) == 0x4D0 ? 1 : -1];
typedef char GameSceneControllerLocationArrayCheck[offsetof(GameSceneScriptController, location_records) == 0x4DC ? 1 : -1];
typedef char GameSceneControllerActorArrayCheck[offsetof(GameSceneScriptController, actor_records) == 0x524 ? 1 : -1];
typedef char GameSceneControllerSizeCheck[sizeof(GameSceneScriptController) == 0x554 ? 1 : -1];

// The return transition and the native GameScene constructor copy this whole
// three-word record. Only its first word is initialized by the shop commands;
// the remaining payload is not assumed to be zero or given guessed meanings.
struct GameSceneResumeRequest {
    i32 kind;
    u8 unk_04[8];

    // Native requests initialize only kind; the remaining payload is opaque.
    GameSceneResumeRequest() {}
    explicit GameSceneResumeRequest(i32 value) : kind(value) {}
};

struct SupermarketSceneCore;
struct SupermarketPurchaseSceneCore;

// These two native scene constructors create an owned UI core at +4 and
// consume the continuation at +8. Their UI cores and lifecycle remain native.
struct SupermarketScene : AScene {
    virtual ~SupermarketScene();
    virtual SceneTransitionOwner Run();

    SupermarketSceneCore * core;
    SceneTransitionOwner continuation;
};

struct SupermarketPurchaseScene : AScene {
    virtual ~SupermarketPurchaseScene();
    virtual SceneTransitionOwner Run();

    SupermarketPurchaseSceneCore * core;
    SceneTransitionOwner continuation;
};

// Scene wrappers retain their native cleanup; recovered transition records use
// implicit cleanup of their continuation owner and SceneTransition base.
// Existing native-format tables reference these real methods and CreateScene.
struct SupermarketPurchaseTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MarySupermarketItemId item_id;
};

struct SupermarketTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct ReturnToGameScene : SceneTransition {
    virtual SceneOwner CreateScene();

    GameStateSaveImage * save;
    GameSceneResumeRequest request;
};

typedef char GameSceneResumeRequestSizeCheck[sizeof(GameSceneResumeRequest) == 12 ? 1 : -1];
typedef char SupermarketSceneSizeCheck[sizeof(SupermarketScene) == 12 ? 1 : -1];
typedef char SupermarketSceneCoreCheck[offsetof(SupermarketScene, core) == 4 ? 1 : -1];
typedef char SupermarketSceneContinuationCheck[offsetof(SupermarketScene, continuation) == 8 ? 1 : -1];
typedef char SupermarketPurchaseSceneSizeCheck[sizeof(SupermarketPurchaseScene) == 12 ? 1 : -1];
typedef char SupermarketPurchaseSceneCoreCheck[offsetof(SupermarketPurchaseScene, core) == 4 ? 1 : -1];
typedef char SupermarketPurchaseSceneContinuationCheck[offsetof(SupermarketPurchaseScene, continuation) == 8 ? 1 : -1];
typedef char SupermarketPurchaseTransitionSizeCheck[sizeof(SupermarketPurchaseTransition) == 16 ? 1 : -1];
typedef char SupermarketPurchaseTransitionItemCheck[offsetof(SupermarketPurchaseTransition, item_id) == 12 ? 1 : -1];
typedef char SupermarketTransitionSizeCheck[sizeof(SupermarketTransition) == 12 ? 1 : -1];
typedef char ReturnToGameSceneSizeCheck[sizeof(ReturnToGameScene) == 20 ? 1 : -1];
typedef char ReturnToGameSceneRequestCheck[offsetof(ReturnToGameScene, request) == 8 ? 1 : -1];

// Verified modal scene wrappers and transitions, in native factory order.
struct CalendarSceneCore;
struct CalendarScene : AScene {
    virtual ~CalendarScene();
    virtual SceneTransitionOwner Run();

    CalendarSceneCore * core;
    SceneTransitionOwner continuation;
};

struct CalendarTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char CalendarSceneSizeCheck[sizeof(CalendarScene) == 12 ? 1 : -1];
typedef char CalendarSceneCoreCheck[offsetof(CalendarScene, core) == 4 ? 1 : -1];
typedef char CalendarSceneContinuationCheck[offsetof(CalendarScene, continuation) == 8 ? 1 : -1];
typedef char CalendarTransitionSizeCheck[sizeof(CalendarTransition) == 12 ? 1 : -1];

struct ToolChestSceneCore;
struct ToolChestScene : AScene {
    virtual ~ToolChestScene();
    virtual SceneTransitionOwner Run();

    ToolChestSceneCore * core;
    SceneTransitionOwner continuation;
};

struct ToolChestTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char ToolChestSceneSizeCheck[sizeof(ToolChestScene) == 12 ? 1 : -1];
typedef char ToolChestSceneCoreCheck[offsetof(ToolChestScene, core) == 4 ? 1 : -1];
typedef char ToolChestSceneContinuationCheck[offsetof(ToolChestScene, continuation) == 8 ? 1 : -1];
typedef char ToolChestTransitionSizeCheck[sizeof(ToolChestTransition) == 12 ? 1 : -1];

struct RefrigeratorSceneCore;
struct RefrigeratorScene : AScene {
    virtual ~RefrigeratorScene();
    virtual SceneTransitionOwner Run();

    RefrigeratorSceneCore * core;
    SceneTransitionOwner continuation;
};

struct RefrigeratorTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char RefrigeratorSceneSizeCheck[sizeof(RefrigeratorScene) == 12 ? 1 : -1];
typedef char RefrigeratorSceneCoreCheck[offsetof(RefrigeratorScene, core) == 4 ? 1 : -1];
typedef char RefrigeratorSceneContinuationCheck[offsetof(RefrigeratorScene, continuation) == 8 ? 1 : -1];
typedef char RefrigeratorTransitionSizeCheck[sizeof(RefrigeratorTransition) == 12 ? 1 : -1];

struct ShelfSceneCore;
struct ShelfScene : AScene {
    virtual ~ShelfScene();
    virtual SceneTransitionOwner Run();

    ShelfSceneCore * core;
    SceneTransitionOwner continuation;
};

struct ShelfTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char ShelfSceneSizeCheck[sizeof(ShelfScene) == 12 ? 1 : -1];
typedef char ShelfSceneCoreCheck[offsetof(ShelfScene, core) == 4 ? 1 : -1];
typedef char ShelfSceneContinuationCheck[offsetof(ShelfScene, continuation) == 8 ? 1 : -1];
typedef char ShelfTransitionSizeCheck[sizeof(ShelfTransition) == 12 ? 1 : -1];

struct CookingSceneCore;
struct CookingScene : AScene {
    virtual ~CookingScene();
    virtual SceneTransitionOwner Run();

    CookingSceneCore * core;
    SceneTransitionOwner continuation;
};

struct CookingTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u8 recipe_list;
};

typedef char CookingSceneSizeCheck[sizeof(CookingScene) == 12 ? 1 : -1];
typedef char CookingSceneCoreCheck[offsetof(CookingScene, core) == 4 ? 1 : -1];
typedef char CookingSceneContinuationCheck[offsetof(CookingScene, continuation) == 8 ? 1 : -1];
typedef char CookingTransitionSizeCheck[sizeof(CookingTransition) == 16 ? 1 : -1];

struct ReferencePageSceneCore;
struct ReferencePageScene : AScene {
    virtual ~ReferencePageScene();
    virtual SceneTransitionOwner Run();

    ReferencePageSceneCore * core;
    SceneTransitionOwner continuation;
};

struct ReferencePageTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    i32 page_id;
};

typedef char ReferencePageSceneSizeCheck[sizeof(ReferencePageScene) == 12 ? 1 : -1];
typedef char ReferencePageSceneCoreCheck[offsetof(ReferencePageScene, core) == 4 ? 1 : -1];
typedef char ReferencePageSceneContinuationCheck[offsetof(ReferencePageScene, continuation) == 8 ? 1 : -1];
typedef char ReferencePageTransitionSizeCheck[sizeof(ReferencePageTransition) == 16 ? 1 : -1];

struct SpecialMerchantShopSceneCore;
struct SpecialMerchantShopScene : AScene {
    virtual ~SpecialMerchantShopScene();
    virtual SceneTransitionOwner Run();

    SpecialMerchantShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct SpecialMerchantShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char SpecialMerchantShopSceneSizeCheck[sizeof(SpecialMerchantShopScene) == 12 ? 1 : -1];
typedef char SpecialMerchantShopSceneCoreCheck[offsetof(SpecialMerchantShopScene, core) == 4 ? 1 : -1];
typedef char SpecialMerchantShopSceneContinuationCheck[offsetof(SpecialMerchantShopScene, continuation) == 8 ? 1 : -1];
typedef char SpecialMerchantShopTransitionSizeCheck[sizeof(SpecialMerchantShopTransition) == 12 ? 1 : -1];

struct GiftWrappingSceneCore;
struct GiftWrappingScene : AScene {
    virtual ~GiftWrappingScene();
    virtual SceneTransitionOwner Run();

    GiftWrappingSceneCore * core;
    SceneTransitionOwner continuation;
};

struct GiftWrappingTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char GiftWrappingSceneSizeCheck[sizeof(GiftWrappingScene) == 12 ? 1 : -1];
typedef char GiftWrappingSceneCoreCheck[offsetof(GiftWrappingScene, core) == 4 ? 1 : -1];
typedef char GiftWrappingSceneContinuationCheck[offsetof(GiftWrappingScene, continuation) == 8 ? 1 : -1];
typedef char GiftWrappingTransitionSizeCheck[sizeof(GiftWrappingTransition) == 12 ? 1 : -1];

struct WineryShopSceneCore;
struct WineryShopScene : AScene {
    virtual ~WineryShopScene();
    virtual SceneTransitionOwner Run();

    WineryShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct WineryShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char WineryShopSceneSizeCheck[sizeof(WineryShopScene) == 12 ? 1 : -1];
typedef char WineryShopSceneCoreCheck[offsetof(WineryShopScene, core) == 4 ? 1 : -1];
typedef char WineryShopSceneContinuationCheck[offsetof(WineryShopScene, continuation) == 8 ? 1 : -1];
typedef char WineryShopTransitionSizeCheck[sizeof(WineryShopTransition) == 12 ? 1 : -1];

struct InnShopSceneCore;
struct InnShopScene : AScene {
    virtual ~InnShopScene();
    virtual SceneTransitionOwner Run();

    InnShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct InnShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char InnShopSceneSizeCheck[sizeof(InnShopScene) == 12 ? 1 : -1];
typedef char InnShopSceneCoreCheck[offsetof(InnShopScene, core) == 4 ? 1 : -1];
typedef char InnShopSceneContinuationCheck[offsetof(InnShopScene, continuation) == 8 ? 1 : -1];
typedef char InnShopTransitionSizeCheck[sizeof(InnShopTransition) == 12 ? 1 : -1];

struct BeachCafeShopSceneCore;
struct BeachCafeShopScene : AScene {
    virtual ~BeachCafeShopScene();
    virtual SceneTransitionOwner Run();

    BeachCafeShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct BeachCafeShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char BeachCafeShopSceneSizeCheck[sizeof(BeachCafeShopScene) == 12 ? 1 : -1];
typedef char BeachCafeShopSceneCoreCheck[offsetof(BeachCafeShopScene, core) == 4 ? 1 : -1];
typedef char BeachCafeShopSceneContinuationCheck[offsetof(BeachCafeShopScene, continuation) == 8 ? 1 : -1];
typedef char BeachCafeShopTransitionSizeCheck[sizeof(BeachCafeShopTransition) == 12 ? 1 : -1];

struct WonShopSceneCore;
struct WonShopScene : AScene {
    virtual ~WonShopScene();
    virtual SceneTransitionOwner Run();

    WonShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct WonShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char WonShopSceneSizeCheck[sizeof(WonShopScene) == 12 ? 1 : -1];
typedef char WonShopSceneCoreCheck[offsetof(WonShopScene, core) == 4 ? 1 : -1];
typedef char WonShopSceneContinuationCheck[offsetof(WonShopScene, continuation) == 8 ? 1 : -1];
typedef char WonShopTransitionSizeCheck[sizeof(WonShopTransition) == 12 ? 1 : -1];

struct CarpenterShopSceneCore;
struct CarpenterShopScene : AScene {
    virtual ~CarpenterShopScene();
    virtual SceneTransitionOwner Run();

    CarpenterShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct CarpenterShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char CarpenterShopSceneSizeCheck[sizeof(CarpenterShopScene) == 12 ? 1 : -1];
typedef char CarpenterShopSceneCoreCheck[offsetof(CarpenterShopScene, core) == 4 ? 1 : -1];
typedef char CarpenterShopSceneContinuationCheck[offsetof(CarpenterShopScene, continuation) == 8 ? 1 : -1];
typedef char CarpenterShopTransitionSizeCheck[sizeof(CarpenterShopTransition) == 12 ? 1 : -1];

struct ClinicShopSceneCore;
struct ClinicShopScene : AScene {
    virtual ~ClinicShopScene();
    virtual SceneTransitionOwner Run();

    ClinicShopSceneCore * core;
    SceneTransitionOwner continuation;
};

struct ClinicShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char ClinicShopSceneSizeCheck[sizeof(ClinicShopScene) == 12 ? 1 : -1];
typedef char ClinicShopSceneCoreCheck[offsetof(ClinicShopScene, core) == 4 ? 1 : -1];
typedef char ClinicShopSceneContinuationCheck[offsetof(ClinicShopScene, continuation) == 8 ? 1 : -1];
typedef char ClinicShopTransitionSizeCheck[sizeof(ClinicShopTransition) == 12 ? 1 : -1];

// Verified nonuniform scene layouts; unknown scalar semantics stay unnamed.
struct YodelRanchShopSceneCore;
struct YodelRanchShopScene : AScene {
    virtual ~YodelRanchShopScene();
    virtual SceneTransitionOwner Run();
    YodelRanchShopSceneCore * core;
    SceneTransitionOwner continuation;
    u32 unk_0C;
    GameStateSaveImage * save;
};

struct YodelRanchShopTransition : SceneTransition {
    YodelRanchShopTransition(SceneTransitionOwner next, GameStateSaveImage * image, u32 input)
        : continuation(next), save(image), unk_0C(input) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 unk_0C;
};
typedef char YodelRanchShopSceneSizeCheck[sizeof(YodelRanchShopScene) == 20 ? 1 : -1];
typedef char YodelRanchShopSceneSaveCheck[offsetof(YodelRanchShopScene, save) == 16 ? 1 : -1];
typedef char YodelRanchShopTransitionSizeCheck[sizeof(YodelRanchShopTransition) == 16 ? 1 : -1];

// This saved-target naming operation is distinct from the reusable keyboard.
// The native Run handles the six NAME_ENTRY_* cases and edits the save image.
struct SavedNameEntryScene : AScene {
    SavedNameEntryScene(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryNameEntryKind input_kind, u8 index)
        : continuation(next), save(image), kind(input_kind), target_index(index) {}
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryNameEntryKind kind;
    u8 target_index;
};

struct SavedNameEntryTransition : SceneTransition {
    SavedNameEntryTransition(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryNameEntryKind input_kind, u8 index)
        : continuation(next), save(image), kind(input_kind), target_index(index) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryNameEntryKind kind;
    u8 target_index;
};
typedef char SavedNameEntrySceneSizeCheck[sizeof(SavedNameEntryScene) == 20 ? 1 : -1];
typedef char SavedNameEntryTransitionSizeCheck[sizeof(SavedNameEntryTransition) == 20 ? 1 : -1];
typedef char SavedNameEntrySceneContinuationCheck[offsetof(SavedNameEntryScene, continuation) == 4 ? 1 : -1];
typedef char SavedNameEntrySceneSaveCheck[offsetof(SavedNameEntryScene, save) == 8 ? 1 : -1];
typedef char SavedNameEntrySceneKindCheck[offsetof(SavedNameEntryScene, kind) == 12 ? 1 : -1];
typedef char SavedNameEntryTransitionContinuationCheck[offsetof(SavedNameEntryTransition, continuation) == 4 ? 1 : -1];
typedef char SavedNameEntryTransitionSaveCheck[offsetof(SavedNameEntryTransition, save) == 8 ? 1 : -1];
typedef char SavedNameEntryTransitionKindCheck[offsetof(SavedNameEntryTransition, kind) == 12 ? 1 : -1];
typedef char SavedNameEntrySceneIndexCheck[offsetof(SavedNameEntryScene, target_index) == 16 ? 1 : -1];
typedef char SavedNameEntryTransitionIndexCheck[offsetof(SavedNameEntryTransition, target_index) == 16 ? 1 : -1];

struct PoultryFarmShopSceneCore;
struct PoultryFarmShopScene : AScene {
    virtual ~PoultryFarmShopScene();
    virtual SceneTransitionOwner Run();
    PoultryFarmShopSceneCore * core;
    SceneTransitionOwner continuation;
    u32 unk_0C;
    GameStateSaveImage * save;
};

struct PoultryFarmShopTransition : SceneTransition {
    PoultryFarmShopTransition(SceneTransitionOwner next, GameStateSaveImage * image, u32 input)
        : continuation(next), save(image), unk_0C(input) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 unk_0C;
};
typedef char PoultryFarmShopSceneSizeCheck[sizeof(PoultryFarmShopScene) == 20 ? 1 : -1];
typedef char PoultryFarmShopSceneSaveCheck[offsetof(PoultryFarmShopScene, save) == 16 ? 1 : -1];
typedef char PoultryFarmShopTransitionSizeCheck[sizeof(PoultryFarmShopTransition) == 16 ? 1 : -1];

struct BlacksmithShopSceneCore;
struct BlacksmithShopScene : AScene {
    virtual ~BlacksmithShopScene();
    virtual SceneTransitionOwner Run();
    BlacksmithShopSceneCore * core;
    SceneTransitionOwner continuation;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    GameStateSaveImage * save;
};

struct BlacksmithShopTransition : SceneTransition {
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8 unk_1C;
};
typedef char BlacksmithShopSceneSizeCheck[sizeof(BlacksmithShopScene) == 32 ? 1 : -1];
typedef char BlacksmithShopSceneSaveCheck[offsetof(BlacksmithShopScene, save) == 28 ? 1 : -1];
typedef char BlacksmithShopTransitionSizeCheck[sizeof(BlacksmithShopTransition) == 32 ? 1 : -1];
typedef char BlacksmithShopTransitionByteCheck[offsetof(BlacksmithShopTransition, unk_1C) == 28 ? 1 : -1];

// This is the verified native destruction-prefix view, not the full core hierarchy.
// The concrete core constructor, Run and destructor bodies remain native.
struct BlacksmithShopResultSceneCore : GameSceneUiComponent {
    u8 unk_008[0x108];
    SceneTransitionOwner continuation;
    u8 unk_114;
    u8 unk_115[0xA3];
};
typedef char BlacksmithShopResultSceneCoreSizeCheck[sizeof(BlacksmithShopResultSceneCore) == 0x1B8 ? 1 : -1];
typedef char BlacksmithShopResultSceneCorePayloadCheck[offsetof(BlacksmithShopResultSceneCore, unk_008) == 8 ? 1 : -1];
typedef char BlacksmithShopResultSceneCoreContinuationCheck[offsetof(BlacksmithShopResultSceneCore, continuation) == 0x110 ? 1 : -1];
typedef char BlacksmithShopResultSceneCoreByteCheck[offsetof(BlacksmithShopResultSceneCore, unk_114) == 0x114 ? 1 : -1];

struct BlacksmithShopResultScene : AScene {
    BlacksmithShopResultScene(SceneTransitionOwner next, GameStateSaveImage * image, u8 input);
    virtual ~BlacksmithShopResultScene();
    virtual SceneTransitionOwner Run();
    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

// This result transition is not the 32-byte shop-opening transition above.
// Its byte is passed unchanged to the native result-scene constructor.
struct BlacksmithShopResultTransition : SceneTransition {
    BlacksmithShopResultTransition(SceneTransitionOwner next, GameStateSaveImage * image, u8 input)
        : continuation(next), save(image), unk_0C(input) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u8 unk_0C;
};
typedef char BlacksmithShopResultSceneSizeCheck[sizeof(BlacksmithShopResultScene) == 12 ? 1 : -1];
typedef char BlacksmithShopResultSceneCoreCheck[offsetof(BlacksmithShopResultScene, core) == 4 ? 1 : -1];
typedef char BlacksmithShopResultSceneContinuationCheck[offsetof(BlacksmithShopResultScene, continuation) == 8 ? 1 : -1];
typedef char BlacksmithShopResultTransitionSizeCheck[sizeof(BlacksmithShopResultTransition) == 16 ? 1 : -1];
typedef char BlacksmithShopResultTransitionContinuationCheck[offsetof(BlacksmithShopResultTransition, continuation) == 4 ? 1 : -1];
typedef char BlacksmithShopResultTransitionSaveCheck[offsetof(BlacksmithShopResultTransition, save) == 8 ? 1 : -1];
typedef char BlacksmithShopResultTransitionByteCheck[offsetof(BlacksmithShopResultTransition, unk_0C) == 12 ? 1 : -1];

struct ClockTransition : SceneTransition {
    virtual SceneOwner CreateScene();
    GameStateSaveImage * save;
    SceneTransitionOwner continuation;
};
typedef char ClockTransitionSizeCheck[sizeof(ClockTransition) == 12 ? 1 : -1];
typedef char ClockTransitionOwnerCheck[offsetof(ClockTransition, continuation) == 8 ? 1 : -1];

struct GameSceneBlendOwner {
    HardwareBlendController * value;
    explicit GameSceneBlendOwner(HardwareBlendController * input = nullptr) : value(input) {}
    ~GameSceneBlendOwner() { delete value; }
};

struct GameSceneWorldOwner {
    GameObject * value;
    explicit GameSceneWorldOwner(GameObject * input = nullptr) : value(input) {}
    ~GameSceneWorldOwner() { delete value; }
};

struct GameSceneTextVariablesOwner {
    ScriptTextVariableStore * value;
    explicit GameSceneTextVariablesOwner(ScriptTextVariableStore * input = nullptr) : value(input) {}
    ~GameSceneTextVariablesOwner() { delete value; }
};

// The native constructor allocates 0xF8 bytes and places its vptr at +0xF4.
// The display shadow at +0x10 is constructed as HardwareDisplayState.
// Other fields are typed only where native construction or use proves them.
#pragma interface "game_scene.hh"
struct GameSceneState {
    GameSceneState(GameScene * owner, GameStateSaveImage * image,
        GameSceneResumeRequest const & request);
    HardwareDmaQueue dma_queue;
    HardwareDisplayState display;
    HardwareManagerOwner manager;
    HardwareLinkedList links;
    GameScene * scene;
    GameStateSaveImage * save;
    GameSceneResumeRequest resume_request;
    u32 script_state;
    GameSceneBlendOwner screen_blend;
    SceneTransitionOwner pending_transition;
    GameSceneWorldOwner game_object;
    GameSceneTalkWindowOwner talk_window;
    GameSceneTextVariablesOwner text_variables;
    GameSceneUiComponentOwner time_window;
    GameSceneUiComponentOwner pause_menu_selector;
    HardwareMusicPlayerSlot bgm_player;
    HardwareMusicPlayerSlot music_player_1;
    HardwareMusicPlayerSlot music_player_2;
    HardwareMusicPlayerSlot music_player_3;
    HardwareMusicPlayerSlot music_player_4;
    GameSceneSongPlayerPool song_players;
    u16 wait_frames;
    u16 unk_E2;
    AActorEntity * waiting_entity;
    u8 unk_E8;
    u8 unk_E9;
    u8 unk_EA[6];
    void * unk_F0;
    virtual ~GameSceneState();
};

struct GameScene : AScene {
    GameScene(GameStateSaveImage * image, GameSceneResumeRequest const & request);
#if !defined(REGION_JP)
    explicit GameScene(GameStateSaveImage * image);
#endif
    virtual ~GameScene();
    virtual SceneTransitionOwner Run();

    GameSceneState * state;

    void SetEntityPosition(u32 id, i32 x, i32 y, u32 facing);
    i32 GetEntityX(u32 id);
    i32 GetEntityY(u32 id);
    void SetEntityFacing(u32 id, u32 facing);
    u32 GetEntityFacing(u32 id);
    u32 GetEntityMap(u32 id);
    void SetEntitySpritePriority(u32 id, u32 priority);
    void MoveEntityXTo(u32 id, u32 target, i32 speed_q16);
    void MoveEntityYTo(u32 id, u32 target, i32 speed_q16);
    void WaitForEntityMovement(u32 id);
    void SetEntityAnim(u32 id, u32 animation);
    void NoOp014(i32 unused_value);
    void HideEntity(u32 id);
    void OffsetEntityPosition(u32 id, i32 delta_x, i32 delta_y);
    void StartEntityEffect(u32 id, u32 effect, u32 persistent);
    void StopEntityEffect(u32 id);
    void SetEntityAuxRenderProfile(u32 id, u32 profile);
    void ChangeMap(u32 map, i32 x, i32 y);
    void PanCameraTo(i32 x, i32 y, u32 speed);
    void WaitForCameraMovement();
    void PlayBGM(i32 mode, u32 sequence, GameSceneBgmSettings const & settings);
    void StopBGM();
    void PlaySong(i32 mode, u32 sequence);
    void StopAllSongs();
    void TalkResetUi();
    void TalkClose();
    void TalkMessage(char const * text, u32 rate);
    void TalkTelevisionMessage(char const * text);
    void TalkSetNameplateCharacter(u32 id);
    void TalkSetNameplateText(char const * text);
    void TalkClearNameplate();
    void TalkSetPortrait(u32 id);
    void TalkClearPortrait();
    void TalkShowHeartIndicator(u32 id);
    void TalkHideHeartIndicator();
    void TalkPromptChoices(char const * prompt, char const * first, char const * second,
        char const * third, char const * fourth);
    void TalkChoices(char const * first, char const * second, char const * third,
        char const * fourth, char const * fifth, char const * sixth);
    void FadeScreen(u32 style, i32 speed, bool fade_out, bool call_scene_hook);
    void TextVariableSetNumber(u32 slot, i32 value);
    void TextVariableSetString(u32 slot, char const * text);
    void TextVariableSetNumberFieldWidth(u32 slot, i32 value, u32 width);
    void CallScript(i32 script_id, i32 context_value);
    void QueueScript(GameSceneScriptRequest const & request, i32 queue_kind);
    void WaitFrames(i32 frames);
    void PrepareClockMenuTransition();
    void RestoreAfterClockMenu();
    void PrepareCookingMenuTransition();
    void RestoreAfterCookingMenu();
    void PrepareRecipeMenuTransition();
    void RestoreAfterRecipeMenu();
    void RefreshBarnFeedTrough(MaryBarnFeedTroughIndex trough);
    void RefreshChickenFeedTrough(MaryChickenCoopFeedTroughIndex trough);
    void StartShipmentBoxDepositAnimation();
    bool IsPlayerRidingHorse();
    bool TryShipPlayerHeldItem();
    bool SetPlayerHeldItem(RucksackItem const & item, bool wrapped);
    bool GivePlayerBasket();
    void ThrowPlayerHeldItem();
    void UsePlayerHeldItem();
    void ClearPlayerHeldItem();
    MaryItemArticleId RemoveRecordPlayerAlbum();
    MaryItemArticleId SwapRecordPlayerAlbum(MaryItemArticleId article);
    void SetEntityEventScript(u32 entity_id, MaryScriptId script_id);
    void ClearEntityEventScript(u32 entity_id);
    void SetTelevisionProgram(MaryTelevisionProgramId program);
    void EndTelevisionProgram();
    void EnableScriptedNpcControl();
    void DisableScriptedNpcControl();
    void LightFireplaceAtLocation(MaryMapId map);
    void SetVaseArticleId(MaryItemArticleId article);
    void BeginEggIncubation(MaryChickenCoopIncubatorIndex incubator);
    void RefreshAllNpcSchedules();
    void ChangePlayerStaminaAndFatigue(MaryStaminaDelta stamina_delta,
        MaryFatigueDelta fatigue_delta);
    void CreateFarmHorse(MaryBool skip_creation, MaryAnimalHorseAgeStage age_stage,
        MaryMapId map, MaryMapSpaceX x, MaryMapSpaceY y);
    void RemoveFarmHorse(MaryBool skip_removal, i32 unused_value);
    MaryAnimalSlotIndex GetInteractingAnimalIndex();
    bool IsPlayerHoldingTool();
    void BeginHoldingActorGraphic(MaryAnimationId animation_id);
    void ObtainPowerBerry();
    void ObtainMysticBerry();
    bool IsHarvestSpriteDailyWorkComplete(MaryCharacterId sprite_id);
    MaryHeldItemKind GetPresentedItemKind();
    i32 GetPresentedItemId();
    bool IsPresentedItemGiftWrapped();
    GameSceneCaughtFish const * GetCaughtFish();
    u32 IsBackgroundMusicActive();
    void CreatePlayerChildEntity();
    void SetContestAnimal(MaryAnimalKind animal_kind, MaryAnimalSlotIndex animal_index);
    void OpenDoor(MaryDoorIndex door_index);
    void CloseDoor(MaryDoorIndex door_index);
    void RedrawRucksackShelfAfterPurchase();
    void RedrawBlueFeatherShelfAfterPurchase();
    void func_08016C10();
    void CreateNewYearSunriseEffect();
    void PlayNewYearSunriseEffect();
    void DestroyNewYearSunriseEffect();
    void PlayStarSparkleEffect();
    void EnterHotSpringBathingState();
    void ExitHotSpringBathingState();
    void RefreshEntity(MaryEntityId entity_id);
    void RemoveEntity(MaryEntityId entity_id);
    void PreservePlayerLocationForNextDay();
    void ClearPreservedPlayerLocation();
    MaryMapId GetPreservedPlayerMapId();
};

typedef char GameSceneUiComponentPrefixCheck[sizeof(GameSceneUiComponent) == 8 ? 1 : -1];
typedef char GameSceneUiComponentOwnerSizeCheck[sizeof(GameSceneUiComponentOwner) == 4 ? 1 : -1];
typedef char GameSceneTalkWindowOwnerSizeCheck[sizeof(GameSceneTalkWindowOwner) == 4 ? 1 : -1];
typedef char GameSceneBgmSettingsSizeCheck[sizeof(GameSceneBgmSettings) == 12 ? 1 : -1];
typedef char GameSceneBgmSettingsPitchCheck[offsetof(GameSceneBgmSettings, pitch) == 4 ? 1 : -1];
typedef char GameSceneBgmSettingsLfoCheck[offsetof(GameSceneBgmSettings, lfo_speed) == 8 ? 1 : -1];
typedef char GameSceneSongPlayerPoolSizeCheck[sizeof(GameSceneSongPlayerPool) == 16 ? 1 : -1];
typedef char GameSceneSongPlayerPoolCapacityCheck[offsetof(GameSceneSongPlayerPool, allocation.end) == 12 ? 1 : -1];
typedef char GameSceneStateSizeCheck[sizeof(GameSceneState) == 0xF8 ? 1 : -1];
typedef char GameSceneStateDmaQueueCheck[offsetof(GameSceneState, dma_queue) == 0 ? 1 : -1];
typedef char GameSceneStateDisplayCheck[offsetof(GameSceneState, display) == 0x10 ? 1 : -1];
typedef char GameSceneStateManagerCheck[offsetof(GameSceneState, manager) == 0x68 ? 1 : -1];
typedef char GameSceneStateLinksCheck[offsetof(GameSceneState, links) == 0x6C ? 1 : -1];
typedef char GameSceneStateSceneCheck[offsetof(GameSceneState, scene) == 0x88 ? 1 : -1];
typedef char GameSceneStateBlendControlCheck[offsetof(GameSceneState, display) +
    offsetof(HardwareDisplayState, blend_control) == 0x60 ? 1 : -1];
typedef char GameSceneStateScreenBlendCheck[offsetof(GameSceneState, screen_blend) == 0xA0 ? 1 : -1];
typedef char GameSceneStateFadeByteE8Check[offsetof(GameSceneState, unk_E8) == 0xE8 ? 1 : -1];
typedef char GameSceneStateFadeByteE9Check[offsetof(GameSceneState, unk_E9) == 0xE9 ? 1 : -1];
typedef char GameSceneStateSaveCheck[offsetof(GameSceneState, save) == 0x8C ? 1 : -1];
typedef char GameSceneStateResumeRequestCheck[offsetof(GameSceneState, resume_request) == 0x90 ? 1 : -1];
typedef char GameSceneStateScriptStateCheck[offsetof(GameSceneState, script_state) == 0x9C ? 1 : -1];
typedef char GameSceneStatePendingTransitionCheck[offsetof(GameSceneState, pending_transition) == 0xA4 ? 1 : -1];
typedef char GameSceneStateGameObjectCheck[offsetof(GameSceneState, game_object) == 0xA8 ? 1 : -1];
typedef char GameSceneStateTalkWindowCheck[offsetof(GameSceneState, talk_window) == 0xAC ? 1 : -1];
typedef char GameSceneStateTalkContextCheck[offsetof(GameSceneState, text_variables) == 0xB0 ? 1 : -1];
typedef char GameSceneStateTimeWindowCheck[offsetof(GameSceneState, time_window) == 0xB4 ? 1 : -1];
typedef char GameSceneStateMenuSelectorCheck[offsetof(GameSceneState, pause_menu_selector) == 0xB8 ? 1 : -1];
typedef char GameSceneStateBgmPlayerCheck[offsetof(GameSceneState, bgm_player) == 0xBC ? 1 : -1];
typedef char GameSceneStateMusicPlayer1Check[offsetof(GameSceneState, music_player_1) == 0xC0 ? 1 : -1];
typedef char GameSceneStateMusicPlayer4Check[offsetof(GameSceneState, music_player_4) == 0xCC ? 1 : -1];
typedef char GameSceneStateSongPlayersCheck[offsetof(GameSceneState, song_players) == 0xD0 ? 1 : -1];
typedef char GameSceneStateWaitFramesCheck[offsetof(GameSceneState, wait_frames) == 0xE0 ? 1 : -1];
typedef char GameSceneStateWaitingEntityCheck[offsetof(GameSceneState, waiting_entity) == 0xE4 ? 1 : -1];
typedef char GameSceneStateUnknownPointerCheck[offsetof(GameSceneState, unk_F0) == 0xF0 ? 1 : -1];
typedef char GameSceneSizeCheck[sizeof(GameScene) == 8 ? 1 : -1];
typedef char GameSceneStatePointerCheck[offsetof(GameScene, state) == 4 ? 1 : -1];

EXTERN_C

// Native modal cores remain opaque here. Calendar, cooking and guide cores
// return a temporary transition owner that the scene must destroy before
// handing back its own continuation; the other listed calls return void.
#if defined(REGION_JP)
void func_0807CD80(SupermarketSceneCore * core);
#else
void func_0807D218(SupermarketSceneCore * core);
#endif
void func_0807DE3C(SupermarketPurchaseSceneCore * core);
SceneTransitionOwner func_080A25B0(CalendarSceneCore * core);
#if defined(REGION_JP)
void func_0808A09C(ToolChestSceneCore * core);
#else
void func_0808A55C(ToolChestSceneCore * core);
#endif
#if defined(REGION_JP)
void func_0808E23C(RefrigeratorSceneCore * core);
#else
void func_0808E6FC(RefrigeratorSceneCore * core);
#endif
void func_08090960(ShelfSceneCore * core);
#if defined(REGION_JP)
SceneTransitionOwner func_08094A40(CookingSceneCore * core);
#else
SceneTransitionOwner func_08094F6C(CookingSceneCore * core);
#endif
SceneTransitionOwner func_080790E4(ReferencePageSceneCore * core);
#if defined(REGION_JP)
void func_08080CC4(SpecialMerchantShopSceneCore * core);
#else
void func_0808114C(SpecialMerchantShopSceneCore * core);
#endif
void func_08092D64(GiftWrappingSceneCore * core);
#if defined(REGION_JP)
void func_080800A8(WineryShopSceneCore * core);
#else
void func_08080540(WineryShopSceneCore * core);
#endif
#if defined(REGION_JP)
void func_0807EAF8(InnShopSceneCore * core);
#else
void func_0807EF90(InnShopSceneCore * core);
#endif
#if defined(REGION_JP)
void func_08081734(BeachCafeShopSceneCore * core);
#else
void func_08081BBC(BeachCafeShopSceneCore * core);
#endif
#if defined(REGION_JP)
void func_0807F430(WonShopSceneCore * core);
#else
void func_0807F8C8(WonShopSceneCore * core);
#endif
void func_08084228(CarpenterShopSceneCore * core);
#if defined(REGION_JP)
void func_0807E0C0(ClinicShopSceneCore * core);
#else
void func_0807E558(ClinicShopSceneCore * core);
#endif

// The core still has its native constructor and regional owning Run ABI.
u32 func_08082CEC(BlacksmithShopSceneCore * core);
BlacksmithShopResultSceneCore * func_08090EE0(void *, SceneTransitionOwner, GameStateSaveImage *, u8);
#if defined(REGION_JP)
SceneTransitionOwner func_0809106C(BlacksmithShopResultSceneCore * core);
#else
SceneTransitionOwner func_0809152C(BlacksmithShopResultSceneCore * core);
#endif

// Ranch Run returns the purchased target slot or -1; the second core
// query selects the existing cow/sheep naming branch.
i32 func_08086A08(YodelRanchShopSceneCore * core);
u32 func_08085EEC(YodelRanchShopSceneCore * core);

// The poultry core returns a signed target slot, with -1 meaning no purchase.
#if defined(REGION_JP)
i32 func_0807BA6C(PoultryFarmShopSceneCore * core);
#else
i32 func_0807BEC8(PoultryFarmShopSceneCore * core);
#endif

// Native shop construction ABI: each constructor consumes *continuation.
#if defined(REGION_JP)
SupermarketScene * func_0807D8A0(void * object, SceneTransition ** continuation,
    GameStateSaveImage * save);
SupermarketPurchaseScene * func_0807DFA0(void * object, SceneTransition ** continuation,
    GameStateSaveImage * save, MarySupermarketItemId item_id);
#else
SupermarketScene * func_0807DD38(void * object, SceneTransition ** continuation,
    GameStateSaveImage * save);
SupermarketPurchaseScene * func_0807E438(void * object, SceneTransition ** continuation,
    GameStateSaveImage * save, MarySupermarketItemId item_id);
#endif

CalendarScene * func_080A3744(void *, SceneTransition **, GameStateSaveImage *);

#if defined(REGION_JP)
ToolChestScene * loc_0808A678(void *, SceneTransition **, GameStateSaveImage *);
#else
ToolChestScene * func_0808AB38(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
RefrigeratorScene * loc_0808E818(void *, SceneTransition **, GameStateSaveImage *);
#else
RefrigeratorScene * func_0808ECD8(void *, SceneTransition **, GameStateSaveImage *);
#endif

ShelfScene * func_08090E54(void *, SceneTransition **, GameStateSaveImage *);

#if defined(REGION_JP)
CookingScene * func_08099F0C(void *, SceneTransition **, GameStateSaveImage *, u8);
#else
CookingScene * func_0809A4D4(void *, SceneTransition **, GameStateSaveImage *, u8);
#endif

ReferencePageScene * func_0807B038(void *, SceneTransition **, GameStateSaveImage *, i32);

#if defined(REGION_JP)
SpecialMerchantShopScene * func_080815B8(void *, SceneTransition **, GameStateSaveImage *);
#else
SpecialMerchantShopScene * func_08081A40(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
GiftWrappingScene * loc_08092C7C(void *, SceneTransition **, GameStateSaveImage *);
#else
GiftWrappingScene * func_080931B0(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
WineryShopScene * func_0808090C(void *, SceneTransition **, GameStateSaveImage *);
#else
WineryShopScene * func_08080D94(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
InnShopScene * func_0807F0E8(void *, SceneTransition **, GameStateSaveImage *);
#else
InnShopScene * func_0807F580(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
BeachCafeShopScene * func_08081C8C(void *, SceneTransition **, GameStateSaveImage *);
#else
BeachCafeShopScene * func_08082114(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
WonShopScene * loc_0807FFC4(void *, SceneTransition **, GameStateSaveImage *);
#else
WonShopScene * func_0808045C(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
CarpenterShopScene * loc_0808506C(void *, SceneTransition **, GameStateSaveImage *);
#else
CarpenterShopScene * func_080854F4(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
ClinicShopScene * func_0807E97C(void *, SceneTransition **, GameStateSaveImage *);
#else
ClinicShopScene * func_0807EE14(void *, SceneTransition **, GameStateSaveImage *);
#endif

#if defined(REGION_JP)
YodelRanchShopScene * loc_08087CA8(void *, SceneTransition **, GameStateSaveImage *, u32);
#else
YodelRanchShopScene * func_08088168(void *, SceneTransition **, GameStateSaveImage *, u32);
#endif
#if defined(REGION_JP)
PoultryFarmShopScene * func_0807CBD8(void *, SceneTransition **, GameStateSaveImage *, u32);
#else
PoultryFarmShopScene * func_0807D070(void *, SceneTransition **, GameStateSaveImage *, u32);
#endif
BlacksmithShopScene * func_08083A7C(void *, SceneTransition **, GameStateSaveImage *, u8, u32, u32, u32, u32);

// The global controller and its subobjects are not yet fully recovered.
extern u8 * gUnk_0300040C;

GameSceneControllerActorRecord * func_080100F0(void);
GameSceneControllerLocationRecord * func_08010104(void);
GameSceneScriptQueue<2> * func_08010118(void);
GameScenePreservedPlayerLocation * func_08010128(void);
u8 * func_08010138(void);
u32 func_08010148(void);
ScriptEngine * func_0801014C(void);

GameSceneSongPlayerPool & func_0801468C(GameScene & scene);
u32 func_0801B5C0(GameSceneWorldPrefix & world, i32 kind);
bool TryGetFarmPlotAtLocation(GameSceneWorldPrefix & world, Location const & location,
    GameSceneFarmPlotLocation & output);
u32 func_0801740C(FieldPlot const & plot);
u32 func_0801746C(FieldPlot const & plot);
bool func_080174C8(Farm & farm, FieldItemState & items, u32 index, i32 season,
    i32 power, bool hammer, GameSceneFieldItemToolResult & result);
u32 func_0801C29C(GameSceneWorldPrefix & world, Location const & location);
u32 func_0801D3FC(GameSceneWorldPrefix & world, Location const & location);
void func_0801D4E0(GameSceneWorldPrefix & world, Location const & location, i32 id);
void func_0801D5BC(GameSceneWorldPrefix & world, Location const & location,
    RucksackItem & output);
RucksackItem PickUpFieldItemAtLocation(GameSceneWorldPrefix & world, Location const & location);
void func_0801D7B0(GameSceneWorldPrefix & world, Location const & location,
    Article const & article);
u32 func_0801D88C(GameSceneWorldPrefix & world, Location const & location,
    Article const & article);
void func_0801D8CC(GameSceneWorldPrefix & world);
void func_0801D948(GameSceneWorldPrefix & world);
void func_0801D9A8(GameSceneWorldPrefix & world,
    GameSceneScriptRequest const & request, i32 queue_kind);
u32 func_0801D9BC(GameSceneWorldPrefix & world);
GameSceneSongPlayerPool & func_0801DB44(GameSceneWorldPrefix & world);
void func_0801DB58(GameSceneWorldPrefix & world);
void func_0801DC24(GameSceneWorldPrefix & world, u32 index);
void func_0801DCA8(GameSceneWorldPrefix & world);
void CollectDailyShippingRevenue(GameSceneWorldPrefix & world);
void func_0801DD18(GameSceneWorldPrefix & world);
void func_0801DD24(GameSceneWorldPrefix & world);
void func_0801DD30(GameSceneWorldPrefix & world);
void func_0801DD3C(GameSceneWorldPrefix & world);
void func_0801DD48(GameSceneWorldPrefix & world);
void func_0801DD54(GameSceneWorldPrefix & world);
void func_0801DD60(GameSceneWorldPrefix & world, u32 index);
void func_0801DD6C(GameSceneWorldPrefix & world, u32 index);
void func_0801DD78(GameSceneWorldPrefix & world);
void func_0801DDCC(GameSceneWorldPrefix & world, u32 index);
void func_0801DDF8(GameSceneWorldPrefix & world, u32 index);
void func_0801DE24(GameSceneWorldPrefix & world, u32 unk);
void func_0801DE30(GameSceneWorldPrefix & world);
void func_0801DE3C(GameSceneWorldPrefix & world);
void func_0801DE48(GameSceneWorldPrefix & world);
MaryItemArticleId RemoveRecordPlayerAlbum(GameSceneWorldPrefix & world);
MaryItemArticleId SwapRecordPlayerAlbum(GameSceneWorldPrefix & world, MaryItemArticleId article_id);
void ApplyMapTilePatch(GameSceneWorldMapPrefix * map,
    FieldRenderRectDescriptor const & patch, u32 x, u32 y);
void func_080A601C(GameSceneWorldMapPrefix * map);
void RefreshCoopFeedTrough(GameSceneWorldMapPrefix * map, u32 index);
// This barn dispatcher retains its native implementation and unchecked index.
void func_080A607C(GameSceneWorldMapPrefix * map, u32 index);
void func_080A6138(GameSceneWorldMapPrefix * map);
void func_080A6194(GameSceneWorldMapPrefix * map);
void func_080A61F0(GameSceneWorldMapPrefix * map);
void func_080A6234(GameSceneWorldMapPrefix * map);
void func_080A6278(GameSceneWorldMapPrefix * map);
void func_080A62BC(GameSceneWorldMapPrefix * map);
void func_080A6300(GameSceneWorldMapPrefix * map);
void func_080A635C(GameSceneWorldMapPrefix * map);
void func_080A63B8(GameSceneWorldMapPrefix * map, u32 unk);
u32 SelectDefaultWorldMapData(GameSceneWorldMapPrefix const * map);
FieldRenderTileAttributes * GetWorldMapTileAttributes(GameSceneWorldMapPrefix * map, u32 x, u32 y);
u32 GetWorldMapDataId(GameSceneWorldMapPrefix const * map);
u32 GetWorldMapId(GameSceneWorldMapPrefix const * map);
i32 GetWorldMapViewY(GameSceneWorldMapPrefix const * map);
i32 GetWorldMapViewX(GameSceneWorldMapPrefix const * map);
void UpdateSavedMapTileAnimationTimers(GameSceneSavedMapPrefix * map);
// The base draw implementation remains native. Keep its fourth argument
// opaque until that consumer interface is recovered.
void func_080A4F50(GameSceneWorldMapPrefix * map, HardwareDmaQueue & queue,
    HardwareDisplayState & display, void * unk);
void QueueMapTilePatch(GameSceneWorldMapPrefix * map,
    FarmHouseTilePatchDescriptor const & patch, u32 frame, HardwareDmaQueue & queue);
void DrawSavedWorldMap(GameSceneSavedMapPrefix * map, HardwareDmaQueue & queue,
    HardwareDisplayState & display, void * unk);
void ResetSavedMapTileAnimationFrames(GameSceneSavedMapPrefix * map);
// The shared base update is C++; the regional reset entries remain native.
void UpdateWorldMap(GameSceneWorldMapPrefix * map);
#if defined(REGION_JP)
void func_080A5198(GameSceneWorldMapPrefix * map);
#else
void func_080A5760(GameSceneWorldMapPrefix * map);
#endif
void func_080AA850(GameSceneSavedMapPrefix * map, u32 index);
void func_080AA89C(GameSceneWorldMapPrefix * map);
void func_080AA8BC(GameSceneWorldMapPrefix * map);
void func_080AA8DC(GameSceneSavedMapPrefix * map);
void Unpack(u8 const * source, void * destination);
void LoadWorldMapTilemaps(GameSceneWorldMapPrefix & map);
void LoadWorldMapTiles(GameSceneWorldMapPrefix & map);
bool func_080A5EB8(GameSceneWorldMapPrefix * map, Location const & location);
void SetWorldMapTimeOfDayPalette(GameSceneWorldMapPrefix & map, i32 period);
void LoadWorldMapTimeOfDayPalette(GameSceneWorldMapPrefix & map, i32 period, u32 buffer_index);
void func_080A5F78(GameSceneWorldMapPrefix * map, u32 layer,
    Vec2 const & position, u32 width, u32 height);
bool func_08019F38(GameSceneWorldPrefix & world, Location const & location);
i32 GetWorldMapPixelWidth(GameSceneWorldPrefix & world, u32 map);
i32 GetWorldMapPixelHeight(GameSceneWorldPrefix & world, u32 map);
MapTerrainView GetWorldMapTerrain(GameSceneWorldPrefix & world, u32 map_id);
TimeOfDayPeriod GetWorldTimeOfDayPeriod(GameSceneWorldPrefix & world, u32 hour);
void RefreshFieldPlotTiles(GameSceneWorldMapPrefix * map, u32 x, u32 y,
    FieldPlot const * plot, FieldPlotRenderData const * render_data);

// Recovered native world callbacks. The duplicate slot readers retain
// separate entries; neither adds bounds checking absent from the original.
IndexedResourceArchive * func_0801FBDC(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FBE8(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FBF4(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FC00(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FC0C(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FC18(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FC24(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FC30(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FC3C(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FC48(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FC54(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FC60(GameSceneWorldPrefix & world);
IndexedResourceArchive * func_0801FC6C(GameSceneWorldPrefix & world);
void func_0801FC78(GameSceneWorldPrefix & world);
GameSceneWorldMapPrefix * func_0801FC9C(GameSceneWorldPrefix & world);
GameSceneWorldMapPrefix * func_0801FCA0(GameSceneWorldPrefix & world);
i32 func_0801FCB4(GameSceneWorldPrefix & world, u32 index);
void func_0801FCDC(GameSceneWorldPrefix & world, u32 index);
void * func_0801FD30(GameSceneWorldPrefix & world);

// The bank allocator still has its original native implementation.
i32 func_080AC96C(GameScenePaletteCache * cache, u32 index);

GameStateClock const * func_0801FCA4(GameSceneWorldPrefix const & world);
AActorEntity * func_0801FCF4(GameSceneWorldPrefix const & world, u32 index);
AActorEntity * func_0801FD00(GameSceneWorldPrefix & world, u32 index);
void func_0801FD0C(GameSceneWorldPrefix & world, u32 index);
bool func_0801FD3C(GameSceneWorldPrefix const & world);
i32 func_0801FD48(GameSceneWorldPrefix const & world);
i32 func_0801FD50(GameSceneWorldPrefix const & world);
u32 func_0801FD58(GameSceneWorldPrefix const & world);
void func_0801FD60(GameSceneWorldPrefix & world, i32 x, i32 y, u32 speed);
void func_0801FD6C(GameSceneWorldPrefix & world, i32 x, i32 y);

// A requested screen-center position is clamped to the map's camera origin.
// Set applies it immediately; Pan keeps the native integer frame arithmetic.
Vec2 func_080A58EC(GameSceneWorldMapPrefix const * map, i32 x, i32 y);
void func_080A5960(GameSceneWorldMapPrefix * map, i32 x, i32 y);
void func_080A59BC(GameSceneWorldMapPrefix * map, i32 x, i32 y, u32 speed);
bool func_080A5A9C(GameSceneWorldMapPrefix const * map);

// Recovered state callbacks retain address names where semantics are unresolved.
void func_080D7F08(GameSceneState * state);
void func_080D7F3C(GameSceneState * state);
void func_080D7F60(GameSceneState * state);
void func_080D7F74(GameSceneState * state);
void func_080D7F88(GameSceneState * state);

// This entity-position update helper still remains in native code.
void func_080D7F9C(GameSceneState * state, u32 id, u32 map, i32 x, i32 y,
    u32 facing);

// Native text-variable storage keeps its original byte-based truncation.
// The scene wrappers do not add a slot check or width clamp.
void func_0803B6B8(ScriptTextVariableStore * variables, u32 slot, char const * text);

// The native scene runner still owns the underlying update loop.
SceneTransitionOwner sub_080D8178(GameSceneState * state);

void UpdateGameSceneHardwareFrame(GameSceneState * state, HardwareSpriteBufferState * buffer);

EXTERN_C_END

// Native base owns OBJ tiles and the palette slots returned by GameObject.
struct GameSceneSpriteBase {
    GameObject * world;
    HardwareStateEntry tiles;
    u16 tile_index;
    GameScenePaletteIndices palettes;

    // The real constructor ABI is still implemented by native assembly.
    GameSceneSpriteBase(GameObject * world, u32 size_shift, i32 palette_kind);
    virtual ~GameSceneSpriteBase();
};

struct GameSceneIndexedSprite : GameSceneSpriteBase {
    GameSceneIndexedSprite(IndexedResourceProvider * resource, u32 index,
        GameObject * world, u32 size_shift, i32 palette_kind, bool unk_3D);

    IndexedResourceHandle handle;
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
    u8 unk_3F;
};

typedef char GameSceneSpriteBaseSizeCheck[sizeof(GameSceneSpriteBase) == 0x28 ? 1 : -1];
typedef char GameSceneSpriteBaseTilesCheck[offsetof(GameSceneSpriteBase, tiles) == 4 ? 1 : -1];
typedef char GameSceneSpriteBasePaletteCountCheck[offsetof(GameSceneSpriteBase, palettes.count) == 0x10 ? 1 : -1];
typedef char GameSceneSpriteBasePaletteIndicesCheck[offsetof(GameSceneSpriteBase, palettes.values) == 0x14 ? 1 : -1];
typedef char GameSceneIndexedSpriteSizeCheck[sizeof(GameSceneIndexedSprite) == 0x40 ? 1 : -1];
typedef char GameSceneIndexedSpriteHandleCheck[offsetof(GameSceneIndexedSprite, handle) == 0x28 ? 1 : -1];
typedef char GameSceneIndexedSpriteFlagsCheck[offsetof(GameSceneIndexedSprite, unk_3C) == 0x3C ? 1 : -1];

inline void MapTilePatchAnimationState::Tick(FarmHouseTilePatchAnimationDescriptor const & animation)
{
    if (++elapsed_frames >= animation.frame_duration) {
        elapsed_frames = 0;
        update_pending = true;
    }
}

inline void MapTilePatchAnimationState::ResetFrame()
{
    frame = 0;
    update_pending = false;
}

inline GameSceneScriptController::GameSceneScriptController(GameStateSaveImageOwner input)
    : save(input.release()), script_engine(save.get()), unk_364(0)
{
    gUnk_0300040C = reinterpret_cast<u8 *>(this);
}

inline GameSceneScriptController::GameSceneScriptController(char const * farm_name,
    char const * player_name, GameDate birthday, char const * dog_name)
    : save(new GameStateSaveImage(farm_name, player_name, birthday, dog_name)),
      script_engine(save.get()), unk_364(1), unk_368(0xAB)
{
    gUnk_0300040C = reinterpret_cast<u8 *>(this);
}


// These views expose only the native destruction interfaces and known members.
// Do not independently allocate either prefix or infer the full core hierarchy.
struct GameSceneMenuOwnedDataPrefix {
    u8 unk_000[0x210];
    virtual ~GameSceneMenuOwnedDataPrefix();
    // Native virtual slot +0x0C; its payload-specific meaning is unknown.
    virtual void vfunc_0C();
private:
    GameSceneMenuOwnedDataPrefix();
};
struct GameSceneMenuOwnedDataOwner {
    GameSceneMenuOwnedDataPrefix * value;
    GameSceneMenuOwnedDataOwner() : value(nullptr) {}
    ~GameSceneMenuOwnedDataOwner() { delete value; }
};
struct GameSceneMenuResourceState {
    u16 unk_00;
    u16 unk_02;
    IndexedResourceHandle handle;
    IndexedResourceSpriteParameters parameters;
    u8 unk_34;
    GameSceneMenuResourceState(IndexedResourceProvider * provider, u32 index, i32 delta)
        : unk_00(0), unk_02(0), handle(provider, index, delta), parameters(), unk_34(0) {}
};
typedef char MenuResourceStateSizeCheck[sizeof(GameSceneMenuResourceState) == 0x38 ? 1 : -1];
struct GameSceneMenuCorePrefix : GameSceneUiComponent {
    GameStateSaveImage * save;
    HardwareMusicPlayerSlot music;
    IndexedResourceArchive archive;
    GameSceneMenuResourceState resource_state;
    GameSceneMenuOwnedDataOwner unk_78;
    GameSceneMenuOwnedDataOwner unk_7C;
    UiStateOwner ui;
    // Written by the native UI update, not initialized by this constructor.
    u32 unk_84;
    u32 unk_88;
protected:
    GameSceneMenuCorePrefix(GameStateSaveImage *);
public:
    void Update();
    // Native precondition: the selected panel exists and index is 0..17.
    MenuGridPosition GetCursorPosition(i32) const;
    i32 GetItemIndex(i32, i32) const;
};
typedef char MenuOwnedDataPrefixSizeCheck[sizeof(GameSceneMenuOwnedDataPrefix) == 0x214 ? 1 : -1];
typedef char MenuCorePrefixSizeCheck[sizeof(GameSceneMenuCorePrefix) == 0x8C ? 1 : -1];
typedef char MenuCoreArchiveCheck[offsetof(GameSceneMenuCorePrefix, archive) == 0x10 ? 1 : -1];
typedef char MenuCoreHandleCheck[offsetof(GameSceneMenuCorePrefix, resource_state) + offsetof(GameSceneMenuResourceState, handle) == 0x44 ? 1 : -1];
typedef char MenuCoreSpriteCheck[offsetof(GameSceneMenuCorePrefix, resource_state) + offsetof(GameSceneMenuResourceState, parameters) == 0x58 ? 1 : -1];
typedef char MenuCoreOwnedDataCheck[offsetof(GameSceneMenuCorePrefix, unk_78) == 0x78 ? 1 : -1];
typedef char MenuCoreUiCheck[offsetof(GameSceneMenuCorePrefix, ui) == 0x80 ? 1 : -1];
typedef char MenuCoreResourceStateOffsetCheck[offsetof(GameSceneMenuCorePrefix, resource_state) == 0x40 ? 1 : -1];
typedef char MenuCoreUnknownStateCheck[offsetof(GameSceneMenuCorePrefix, unk_84) == 0x84 ? 1 : -1];
typedef char MenuCoreUnknownResultCheck[offsetof(GameSceneMenuCorePrefix, unk_88) == 0x88 ? 1 : -1];
extern "C" {
#if defined(REGION_JP)
extern u8 const gUnk_084DABB8[];
#else
extern u8 const gUnk_08754C0C[];
#endif
}

// Native menu tilemap command storage. Construction remains in assembly;
// only the verified layout and command/resource cleanup are recovered here.
// Do not allocate these views or assign meaning to untouched words.
struct GameSceneMenuCommandNode {
    GameSceneMenuCommandNode * next;
    GameSceneMenuCommandNode * previous;
    HardwareLinkBase * command;
};
struct GameSceneMenuCommandIterator {
    GameSceneMenuCommandNode * current;
    explicit GameSceneMenuCommandIterator(GameSceneMenuCommandNode * node) : current(node) {}
    GameSceneMenuCommandIterator(GameSceneMenuCommandIterator const & other) : current(other.current) {}
    bool operator!=(GameSceneMenuCommandIterator const & other) const
    {
        return current != other.current;
    }
    GameSceneMenuCommandIterator & operator++()
    {
        current = current->next;
        return *this;
    }
    HardwareLinkBase * operator*() const { return current->command; }
};
struct GameSceneMenuCommandQueue {
    u32 unk_00;
    GameSceneMenuCommandNode * sentinel;
    void ClearNodes();
    ~GameSceneMenuCommandQueue()
    {
        ClearNodes();
        if (sentinel != nullptr)
            free(sentinel);
    }
    GameSceneMenuCommandIterator Begin() const
    {
        return GameSceneMenuCommandIterator(sentinel->next);
    }
    GameSceneMenuCommandIterator End() const
    {
        return GameSceneMenuCommandIterator(sentinel);
    }
private:
    GameSceneMenuCommandQueue();
};

struct GameSceneMenuTilemapData {
    u32 unk_00;
    HardwareStateEntry unk_04;
    HardwareStateEntry unk_0C;
    HardwareResourceEntry unk_14;
    IndexedResourceArchive archive;
    GameSceneMenuResourceState first;
    GameSceneMenuResourceState second;
    u32 unk_BC;
    GameSceneMenuCommandQueue commands;
    ~GameSceneMenuTilemapData();
private:
    GameSceneMenuTilemapData();
};
typedef char MenuCommandNodeSizeCheck[sizeof(GameSceneMenuCommandNode) == 12 ? 1 : -1];
typedef char MenuCommandNodeValueCheck[offsetof(GameSceneMenuCommandNode, command) == 8 ? 1 : -1];
typedef char MenuCommandIteratorSizeCheck[sizeof(GameSceneMenuCommandIterator) == 4 ? 1 : -1];
typedef char MenuCommandQueueSizeCheck[sizeof(GameSceneMenuCommandQueue) == 8 ? 1 : -1];
typedef char MenuCommandQueueHeadCheck[offsetof(GameSceneMenuCommandQueue, sentinel) == 4 ? 1 : -1];
typedef char MenuTilemapDataSizeCheck[sizeof(GameSceneMenuTilemapData) == 0xC8 ? 1 : -1];
typedef char MenuTilemapDataFirstStateCheck[offsetof(GameSceneMenuTilemapData, unk_04) == 4 ? 1 : -1];
typedef char MenuTilemapDataSecondStateCheck[offsetof(GameSceneMenuTilemapData, unk_0C) == 0xC ? 1 : -1];
typedef char MenuTilemapDataPoolEntryCheck[offsetof(GameSceneMenuTilemapData, unk_14) == 0x14 ? 1 : -1];
typedef char MenuTilemapDataArchiveCheck[offsetof(GameSceneMenuTilemapData, archive) == 0x1C ? 1 : -1];
typedef char MenuTilemapDataFirstResourceCheck[offsetof(GameSceneMenuTilemapData, first) == 0x4C ? 1 : -1];
typedef char MenuTilemapDataSecondResourceCheck[offsetof(GameSceneMenuTilemapData, second) == 0x84 ? 1 : -1];
typedef char MenuTilemapDataUnknownWordCheck[offsetof(GameSceneMenuTilemapData, unk_BC) == 0xBC ? 1 : -1];
typedef char MenuTilemapDataQueueCheck[offsetof(GameSceneMenuTilemapData, commands) == 0xC0 ? 1 : -1];

// Borrowed extension of the verified virtual prefix. Not independently allocated.
struct GameSceneMenuOwnedDataState : GameSceneMenuOwnedDataPrefix {
    u8 unk_214[0x68];
    u8 unk_27C;
    u8 unk_27D[0x1B];
    u32 unk_298;
    u32 GetUnk298() const { return unk_298; }
    u8 GetUnk27C() const { return unk_27C; }
private:
    GameSceneMenuOwnedDataState();
};
typedef char MenuOwnedStateWordCheck[offsetof(GameSceneMenuOwnedDataState, unk_298) == 0x298 ? 1 : -1];
typedef char MenuOwnedStateByteCheck[offsetof(GameSceneMenuOwnedDataState, unk_27C) == 0x27C ? 1 : -1];
typedef char MenuOwnedStateSizeCheck[sizeof(GameSceneMenuOwnedDataState) == 0x29C ? 1 : -1];

struct GameSceneMenuCursorData {
    GameSceneMenuCorePrefix * core;
    i32 selection;
    i32 previous;
    i32 left_limit;
    i32 right_limit;
    HardwareStateEntry state;
    HardwareResourceEntry resource;
    IndexedResourceArchive archive;
    GameSceneMenuResourceState sprite;
    GameSceneMenuCursorData(GameSceneMenuCorePrefix *, u32);
    // Navigation requires both panel views and a selection in 0..17.
    inline void RefreshBounds();
    i32 MoveUp();
    i32 MoveDown();
    i32 MoveLeft();
    i32 SwitchPanel();
    void SetSelection(i32);

};
struct GameSceneMenuSpriteData {
    GameSceneMenuCorePrefix * core;
    IndexedResourceArchive archive;
    GameSceneMenuResourceState sprite;
    HardwareStateEntry state;
    HardwareResourceEntry resource;
    u32 unk_7C;
    u32 unk_80;
    u8 unk_84;
    GameSceneMenuSpriteData(GameSceneMenuCorePrefix *);
    void Show(i32, u32);
    void Hide();
};
struct GameSceneMenuCursorDataOwner {
    GameSceneMenuCursorData * value;
    GameSceneMenuCursorDataOwner() : value(nullptr) {}
    ~GameSceneMenuCursorDataOwner() { delete value; }
};
struct GameSceneMenuSpriteDataOwner {
    GameSceneMenuSpriteData * value;
    GameSceneMenuSpriteDataOwner() : value(nullptr) {}
    ~GameSceneMenuSpriteDataOwner() { delete value; }
};
struct GameSceneMenuTilemapDataOwner {
    GameSceneMenuTilemapData * value;
    GameSceneMenuTilemapDataOwner() : value(nullptr) {}
    ~GameSceneMenuTilemapDataOwner() { delete value; }
};
// The concrete scene cores add their own payload after this common 0x98 prefix.
struct GameSceneMenuSelectionCore : GameSceneMenuCorePrefix {
    GameSceneMenuCursorDataOwner cursor;
    GameSceneMenuSpriteDataOwner sprite;
    GameSceneMenuTilemapDataOwner tilemap;
protected:
    GameSceneMenuSelectionCore(GameStateSaveImage *);
public:
    void Update();
};
typedef char MenuCursorSelectionCheck[offsetof(GameSceneMenuCursorData, selection) == 4 ? 1 : -1];
typedef char MenuCursorPreviousCheck[offsetof(GameSceneMenuCursorData, previous) == 8 ? 1 : -1];
typedef char MenuCursorLeftLimitCheck[offsetof(GameSceneMenuCursorData, left_limit) == 0xC ? 1 : -1];
typedef char MenuCursorRightLimitCheck[offsetof(GameSceneMenuCursorData, right_limit) == 0x10 ? 1 : -1];
typedef char MenuCursorDataSizeCheck[sizeof(GameSceneMenuCursorData) == 0x8C ? 1 : -1];
typedef char MenuCursorStateCheck[offsetof(GameSceneMenuCursorData, state) == 0x14 ? 1 : -1];
typedef char MenuCursorResourceCheck[offsetof(GameSceneMenuCursorData, resource) == 0x1C ? 1 : -1];
typedef char MenuCursorArchiveCheck[offsetof(GameSceneMenuCursorData, archive) == 0x24 ? 1 : -1];
typedef char MenuCursorSpriteCheck[offsetof(GameSceneMenuCursorData, sprite) == 0x54 ? 1 : -1];
typedef char MenuSpriteDataSizeCheck[sizeof(GameSceneMenuSpriteData) == 0x88 ? 1 : -1];
typedef char MenuSpriteArchiveCheck[offsetof(GameSceneMenuSpriteData, archive) == 4 ? 1 : -1];
typedef char MenuSpriteParametersCheck[offsetof(GameSceneMenuSpriteData, sprite) == 0x34 ? 1 : -1];
typedef char MenuSpriteStateCheck[offsetof(GameSceneMenuSpriteData, state) == 0x6C ? 1 : -1];
typedef char MenuSpriteResourceCheck[offsetof(GameSceneMenuSpriteData, resource) == 0x74 ? 1 : -1];
typedef char MenuSpriteUnknownWordCheck[offsetof(GameSceneMenuSpriteData, unk_7C) == 0x7C ? 1 : -1];
typedef char MenuSpriteUnknownByteCheck[offsetof(GameSceneMenuSpriteData, unk_84) == 0x84 ? 1 : -1];
typedef char MenuCursorOwnerSizeCheck[sizeof(GameSceneMenuCursorDataOwner) == 4 ? 1 : -1];
typedef char MenuSpriteOwnerSizeCheck[sizeof(GameSceneMenuSpriteDataOwner) == 4 ? 1 : -1];
typedef char MenuTilemapOwnerSizeCheck[sizeof(GameSceneMenuTilemapDataOwner) == 4 ? 1 : -1];
typedef char MenuSelectionCoreSizeCheck[sizeof(GameSceneMenuSelectionCore) == 0x98 ? 1 : -1];
typedef char MenuSelectionCursorCheck[offsetof(GameSceneMenuSelectionCore, cursor) == 0x8C ? 1 : -1];
typedef char MenuSelectionSpriteCheck[offsetof(GameSceneMenuSelectionCore, sprite) == 0x90 ? 1 : -1];
typedef char MenuSelectionTilemapCheck[offsetof(GameSceneMenuSelectionCore, tilemap) == 0x94 ? 1 : -1];
extern "C" u8 const gUiHandCursorArchive[];

extern "C" {
// Actual existing native entries, not generated wrappers or aliases.
void func_080CDDD4(GameSceneMenuCursorData *);
void func_080CECE8(GameSceneMenuSpriteData *);
#if defined(REGION_JP)
void loc_080CDFA0(GameSceneMenuTilemapData *);
void loc_080CBD9C(GameSceneMenuOwnedDataPrefix *, HardwareSpriteBufferState *);
#else
void func_080CE790(GameSceneMenuTilemapData *);
void func_080CC58C(GameSceneMenuOwnedDataPrefix *, HardwareSpriteBufferState *);
#endif
}

// Coordinate readers retain the native unused panel argument, without
// inventing a relationship between the left/right opaque payload types.
MenuGridPosition GetMenuGridLeftCellPosition(GameSceneMenuOwnedDataPrefix const *, i32);
MenuGridPosition GetMenuGridLeftHeaderPosition(GameSceneMenuOwnedDataPrefix const *);
MenuGridPosition GetMenuGridRightCellPosition(GameSceneMenuOwnedDataPrefix const *, i32);
MenuGridPosition GetMenuGridRightHeaderPosition(GameSceneMenuOwnedDataPrefix const *);

#endif // GAME_SCENE_HH
