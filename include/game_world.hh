#ifndef GAME_WORLD_HH
#define GAME_WORLD_HH

#include "prelude.h"
#include "world_runtime.hh"
#include "world_weather.hh"
#include "entity_actor.hh"
#include "hardware_resource.hh"
#include "hardware_state_clear.hh"
#include "resource_handle.hh"
#include "time_of_day.hh"
#include "world_map.hh"
#include "scene_sprite.hh"

#pragma interface "game_world.hh"

struct GameScene;
struct GameSceneSongPlayerPool;
struct GameSceneScriptRequest;
struct GameStateClock;
struct GameStateSaveImage;
struct RucksackItem;
struct Article;
struct Product;

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

// The native factory allocates exactly 0x10CC bytes. The complete storage
// boundary is covered below; members without proven roles remain unknown.
// Construction and the native virtual-table implementation are still imported.
struct GameSceneWorld : GameObject {
    virtual AEntity * GetEntity(u32 index);
    virtual AEntity * GetEntity(u32 index) const;
    // Native world slot +0x148 selects the default audio sequence.
    virtual u32 GetDefaultAudioSequence();
    virtual GameStateClock const * GetClock();
    // Native world slot +0x14C borrows the scene's sound-player pool.
    virtual GameSceneSongPlayerPool & GetSongPlayerPool();
    virtual void LightFireplaceAtLocation(MaryMapId map);
    virtual void SetVaseArticleId(MaryItemArticleId article);
    virtual void vfunc_158();
    virtual void ShipProduct(Product const & product);
    virtual void CreateEventIcon(MaryEventIconSlot slot, MaryMapSpaceX x,
        MaryMapSpaceY y, MaryEventIconLayer layer, u16 icon_id);
    virtual void RemoveEventIcon(MaryEventIconSlot slot);

    GameSceneWorld(GameStateSaveImage * save, GameScene * scene,
        GameSceneWorldMapOwner map, bool unk);

    GameSceneWorldData data;
    GameStateSaveImage * save;
    u8 updates_suspended;
    u8 unk_103D[3];
    GameCalendar const * calendar;
    u32 unk_1044;
    i32 time_of_day_period;
    u8 time_palette_blend;
    u8 unk_104D[3];
    FieldRenderTileAttributes * farm_tile_attributes;
    GameScene * scene;
    SmartPtr<GameSceneIndexedSprite> unk_1058;
    SmartPtr<GameSceneIndexedSprite> fireplace_sprite;
    u8 unk_1060;
    u8 unk_1061[7];
    SmartPtr<GameSceneGroupSprite> vase_sprite;
    SmartPtr<GameSceneIndexedSprite> unk_106C;
    SmartPtr<GameSceneIndexedSprite> unk_1070;
    SmartPtr<GameSceneIndexedSprite> unk_1074;
    SmartPtr<GameSceneIndexedSprite> unk_1078;
    SmartPtr<GameSceneWeatherEffect> weather_effect;
    GameSceneWorldUnk1080Entry unk_1080[4];
    // The enclosing native object continues beyond the previously verified
    // prefix. Do not infer the layout of these intervening bytes yet.
    u8 unk_10B0[0x18];
    // The callback sets the first byte; native update consumes and clears it.
    // The associated byte affects that pending path; its meaning is unknown.
    u8 unk_10C8;
    u8 unk_10C9;
};

typedef char GameSceneWorldSizeCheck[sizeof(GameSceneWorld) == 0x10CC ? 1 : -1];

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
typedef char GameSceneWorldFarmTerrainCheck[offsetof(GameSceneWorld, farm_tile_attributes) == 0x1050 ? 1 : -1];

typedef char GameSceneWorldSceneCheck[offsetof(GameSceneWorld, scene) == 0x1054 ? 1 : -1];
typedef char GameSceneWorldSpriteCheck[offsetof(GameSceneWorld, unk_1058) == 0x1058 ? 1 : -1];
typedef char GameSceneWorldFireplaceFlagCheck[offsetof(GameSceneWorld, unk_1060) == 0x1060 ? 1 : -1];
typedef char GameSceneWorldSprite106CCheck[offsetof(GameSceneWorld, unk_106C) == 0x106C ? 1 : -1];
typedef char GameSceneWorldSprite1070Check[offsetof(GameSceneWorld, unk_1070) == 0x1070 ? 1 : -1];
typedef char GameSceneWorldSprite1074Check[offsetof(GameSceneWorld, unk_1074) == 0x1074 ? 1 : -1];
typedef char GameSceneWorldSprite1078Check[offsetof(GameSceneWorld, unk_1078) == 0x1078 ? 1 : -1];
typedef char GameSceneWorldVaseSpriteCheck[offsetof(GameSceneWorld, vase_sprite) == 0x1068 ? 1 : -1];
typedef char GameSceneWorldFireplaceSpriteCheck[offsetof(GameSceneWorld, fireplace_sprite) == 0x105C ? 1 : -1];

typedef char GameSceneWorldUnknown10C8Check[offsetof(GameSceneWorld, unk_10C8) == 0x10C8 ? 1 : -1];
typedef char GameSceneWorldUnknown10C9Check[offsetof(GameSceneWorld, unk_10C9) == 0x10C9 ? 1 : -1];

typedef char GameSceneWorldUnk1080Check[offsetof(GameSceneWorld, unk_1080) == 0x1080 ? 1 : -1];

typedef char GameSceneFarmPlotLocationSizeCheck[sizeof(GameSceneFarmPlotLocation) == 12 ? 1 : -1];
typedef char GameSceneFarmPlotTileXCheck[offsetof(GameSceneFarmPlotLocation, tile_x) == 4 ? 1 : -1];
typedef char GameSceneFarmPlotColumnCheck[offsetof(GameSceneFarmPlotLocation, column) == 8 ? 1 : -1];




typedef char GameSceneWorldDataCheck[offsetof(GameSceneWorld, data) == 4 ? 1 : -1];
typedef char GameSceneWorldMapCheck[offsetof(GameSceneWorld, data.map.value) == 4 ? 1 : -1];
typedef char GameSceneWorldEntitiesCheck[offsetof(GameSceneWorld, data.entities) == 8 ? 1 : -1];
typedef char GameSceneWorldPaletteCacheCheck[offsetof(GameSceneWorld, data.palette_cache) == 0x19C ? 1 : -1];
typedef char GameSceneWorldActorArchiveCheck[offsetof(GameSceneWorld, data.actor_archive) == 0xDB4 ? 1 : -1];
typedef char GameSceneWorldEntityAuxiliarySpritesCheck[offsetof(GameSceneWorld, data.entity_auxiliary_sprites) == 0x1024 ? 1 : -1];
typedef char GameSceneWorldWeatherOwnerSizeCheck[sizeof(SmartPtr<GameSceneWeatherEffect>) == 4 ? 1 : -1];
typedef char GameSceneWorldWeatherOwnerCheck[offsetof(GameSceneWorld, weather_effect) == 0x107C ? 1 : -1];
typedef char GameSceneWorldSaveCheck[offsetof(GameSceneWorld, save) == 0x1038 ? 1 : -1];
typedef char GameSceneWorldSuspensionCheck[offsetof(GameSceneWorld, updates_suspended) == 0x103C ? 1 : -1];
typedef char GameSceneWorldCalendarCheck[offsetof(GameSceneWorld, calendar) == 0x1040 ? 1 : -1];
typedef char GameSceneWorldPeriodCheck[offsetof(GameSceneWorld, time_of_day_period) == 0x1048 ? 1 : -1];
typedef char GameSceneWorldPaletteBlendCheck[offsetof(GameSceneWorld, time_palette_blend) == 0x104C ? 1 : -1];


EXTERN_C

// Native virtual bridges at +0x12C/+0x130 dispatch through the selected
// world's +0x40/+0x44 GetEntity implementation. Const qualifies the world;
// the original return value is still an entity pointer.
AEntity * GetWorldEntity(GameObject * world, u32 id);
AEntity * GetWorldEntityConst(GameObject const * world, u32 id);

// World virtual slot +0x13C. Preserve the native byte write and pending marker
// without assigning an unverified gameplay meaning to either saved byte.
void SetWorldPendingUnknownValue(GameSceneWorld & world, u8 value);
u32 func_0801B5C0(GameSceneWorld & world, i32 kind);
// Native palette callback at virtual slot +0x54. The final byte
// is retained by the resource; its complete meaning is still unknown.
void SetWorldSpritePaletteColors(GameSceneWorld & world,
    u8 const * data, u32 palette_resource, u8 unk);
bool TryGetFarmPlotAtLocation(GameSceneWorld & world, Location const & location,
    GameSceneFarmPlotLocation & output);
u32 func_0801740C(FieldPlot const & plot);
u32 func_0801746C(FieldPlot const & plot);
bool func_080174C8(Farm & farm, FieldItemState & items, u32 index, i32 season,
    i32 power, bool hammer, GameSceneFieldItemToolResult & result);
u32 func_0801C29C(GameSceneWorld & world, Location const & location);
u32 func_0801D3FC(GameSceneWorld & world, Location const & location);
void func_0801D4E0(GameSceneWorld & world, Location const & location, i32 id);
void func_0801D5BC(GameSceneWorld & world, Location const & location,
    RucksackItem & output);
RucksackItem PickUpFieldItemAtLocation(GameSceneWorld & world, Location const & location);
void func_0801D7B0(GameSceneWorld & world, Location const & location,
    Article const & article);
u32 func_0801D88C(GameSceneWorld & world, Location const & location,
    Article const & article);
// These two world implementations remain native; their real callers and
// virtual slots are named without replacing their bodies with approximations.
void CreateWorldEventIcon(GameSceneWorld & world, MaryEventIconSlot slot,
    MaryMapSpaceX x, MaryMapSpaceY y, MaryEventIconLayer layer, u16 icon_id);
void RemoveWorldEventIcon(GameSceneWorld & world, MaryEventIconSlot slot);
void QueueWorldScript(GameSceneWorld & world,
    GameSceneScriptRequest const & request, i32 queue_kind);
void func_0801DC24(GameSceneWorld & world, u32 index);
void func_0801DCA8(GameSceneWorld & world);
void CollectDailyShippingRevenue(GameSceneWorld & world);
void func_0801DD18(GameSceneWorld & world);
void func_0801DD24(GameSceneWorld & world);
void func_0801DD30(GameSceneWorld & world);
void func_0801DD3C(GameSceneWorld & world);
void func_0801DD48(GameSceneWorld & world);
void func_0801DD54(GameSceneWorld & world);
void func_0801DD60(GameSceneWorld & world, u32 index);
void func_0801DD6C(GameSceneWorld & world, u32 index);
void func_0801DD78(GameSceneWorld & world);
void SetWorldMapPatchFlag(GameSceneWorld & world, u32 index);
void ClearWorldMapPatchFlag(GameSceneWorld & world, u32 index);
void func_0801DE24(GameSceneWorld & world, u32 unk);
void func_0801DE30(GameSceneWorld & world);
void func_0801DE3C(GameSceneWorld & world);
void func_0801DE48(GameSceneWorld & world);
MaryItemArticleId RemoveRecordPlayerAlbum(GameSceneWorld & world);
MaryItemArticleId SwapRecordPlayerAlbum(GameSceneWorld & world, MaryItemArticleId article_id);
bool func_08019F38(GameSceneWorld & world, Location const & location);
i32 GetWorldMapPixelWidth(GameSceneWorld & world, u32 map);
i32 GetWorldMapPixelHeight(GameSceneWorld & world, u32 map);
MapTerrainView GetWorldMapTerrain(GameSceneWorld & world, u32 map_id);
// Recovered native world callbacks. The duplicate slot readers retain
// separate entries; neither adds bounds checking absent from the original.
IndexedResourceArchive * func_0801FBDC(GameSceneWorld & world);
IndexedResourceArchive * func_0801FBE8(GameSceneWorld & world);
IndexedResourceArchive * func_0801FBF4(GameSceneWorld & world);
IndexedResourceArchive * func_0801FC00(GameSceneWorld & world);
IndexedResourceArchive * func_0801FC0C(GameSceneWorld & world);
IndexedResourceArchive * GetWorldMapSpriteArchive(GameSceneWorld & world);
IndexedResourceArchive * func_0801FC24(GameSceneWorld & world);
IndexedResourceArchive * func_0801FC30(GameSceneWorld & world);
IndexedResourceArchive * func_0801FC3C(GameSceneWorld & world);
IndexedResourceArchive * func_0801FC48(GameSceneWorld & world);
IndexedResourceArchive * func_0801FC54(GameSceneWorld & world);
IndexedResourceArchive * func_0801FC60(GameSceneWorld & world);
IndexedResourceArchive * GetWorldActorAnimationArchive(GameSceneWorld & world);
GameSceneWorldMap * func_0801FC9C(GameSceneWorld & world);
GameSceneWorldMap * func_0801FCA0(GameSceneWorld & world);
EntityAuxiliarySprites * GetWorldEntityAuxiliarySprites(GameSceneWorld & world);

GameStateClock const * GetWorldClock(GameSceneWorld const & world);
void RemoveWorldEntity(GameSceneWorld & world, u32 index);
bool IsWorldCameraMovementComplete(GameSceneWorld const & world);
i32 GetWorldCameraY(GameSceneWorld const & world);
i32 GetWorldCameraX(GameSceneWorld const & world);
u32 GetWorldCurrentMapId(GameSceneWorld const & world);
void PanWorldCameraTo(GameSceneWorld & world, i32 x, i32 y, u32 speed);
void SetWorldCameraPosition(GameSceneWorld & world, i32 x, i32 y);

EXTERN_C_END

#endif // GAME_WORLD_HH
