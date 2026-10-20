#ifndef GAME_WORLD_HH
#define GAME_WORLD_HH

#include "prelude.h"
#include "world_runtime.hh"
#include "entity_actor.hh"
#include "hardware_resource.hh"
#include "hardware_state_clear.hh"
#include "resource_handle.hh"
#include "time_of_day.hh"
#include "world_map.hh"

#pragma interface "game_world.hh"

struct GameScene;
struct GameSceneScriptRequest;
struct GameSceneIndexedSprite;
struct GameStateClock;
struct GameStateSaveImage;
struct RucksackItem;
struct Article;

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
    virtual AEntity * GetEntity(u32 index);
    virtual AEntity * GetEntity(u32 index) const;
    // Native world slot +0x148 selects the default audio sequence.
    virtual u32 GetDefaultAudioSequence() = 0;
    // Preserve the unrecovered slot before the world-only furniture hooks.
    virtual void vfunc_14C();
    virtual void LightFireplaceAtLocation(MaryMapId map);
    virtual void SetVaseArticleId(MaryItemArticleId article);
    virtual void vfunc_158();
    virtual void vfunc_15C();
    virtual void CreateEventIcon(MaryEventIconSlot slot, MaryMapSpaceX x,
        MaryMapSpaceY y, MaryEventIconLayer layer, u16 icon_id);
    virtual void RemoveEventIcon(MaryEventIconSlot slot);

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




typedef char GameSceneWorldDataCheck[offsetof(GameSceneWorldPrefix, data) == 4 ? 1 : -1];
typedef char GameSceneWorldMapCheck[offsetof(GameSceneWorldPrefix, data.map.value) == 4 ? 1 : -1];
typedef char GameSceneWorldEntitiesCheck[offsetof(GameSceneWorldPrefix, data.entities) == 8 ? 1 : -1];
typedef char GameSceneWorldPaletteCacheCheck[offsetof(GameSceneWorldPrefix, data.palette_cache) == 0x19C ? 1 : -1];
typedef char GameSceneWorldActorArchiveCheck[offsetof(GameSceneWorldPrefix, data.actor_archive) == 0xDB4 ? 1 : -1];
typedef char GameSceneWorldUnknownObjectCheck[offsetof(GameSceneWorldPrefix, data.unk_1020) == 0x1024 ? 1 : -1];
typedef char GameSceneWorldUnkOwnerSizeCheck[sizeof(GameSceneWorldUnkOwner) == 4 ? 1 : -1];
typedef char GameSceneWorldUnkOwnerCheck[offsetof(GameSceneWorldPrefix, unk_107C) == 0x107C ? 1 : -1];
typedef char GameSceneWorldSaveCheck[offsetof(GameSceneWorldPrefix, save) == 0x1038 ? 1 : -1];
typedef char GameSceneWorldSuspensionCheck[offsetof(GameSceneWorldPrefix, updates_suspended) == 0x103C ? 1 : -1];
typedef char GameSceneWorldCalendarCheck[offsetof(GameSceneWorldPrefix, calendar) == 0x1040 ? 1 : -1];
typedef char GameSceneWorldPeriodCheck[offsetof(GameSceneWorldPrefix, time_of_day_period) == 0x1048 ? 1 : -1];
typedef char GameSceneWorldPaletteBlendCheck[offsetof(GameSceneWorldPrefix, time_palette_blend) == 0x104C ? 1 : -1];


EXTERN_C
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
// These two world implementations remain native; their real callers and
// virtual slots are named without replacing their bodies with approximations.
void CreateWorldEventIcon(GameSceneWorldPrefix & world, MaryEventIconSlot slot,
    MaryMapSpaceX x, MaryMapSpaceY y, MaryEventIconLayer layer, u16 icon_id);
void RemoveWorldEventIcon(GameSceneWorldPrefix & world, MaryEventIconSlot slot);
void QueueWorldScript(GameSceneWorldPrefix & world,
    GameSceneScriptRequest const & request, i32 queue_kind);
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
bool func_08019F38(GameSceneWorldPrefix & world, Location const & location);
i32 GetWorldMapPixelWidth(GameSceneWorldPrefix & world, u32 map);
i32 GetWorldMapPixelHeight(GameSceneWorldPrefix & world, u32 map);
MapTerrainView GetWorldMapTerrain(GameSceneWorldPrefix & world, u32 map_id);
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
IndexedResourceArchive * GetWorldActorAnimationArchive(GameSceneWorldPrefix & world);
void func_0801FC78(GameSceneWorldPrefix & world);
GameSceneWorldMapPrefix * func_0801FC9C(GameSceneWorldPrefix & world);
GameSceneWorldMapPrefix * func_0801FCA0(GameSceneWorldPrefix & world);
void * func_0801FD30(GameSceneWorldPrefix & world);

GameStateClock const * GetWorldClock(GameSceneWorldPrefix const & world);
void RemoveWorldEntity(GameSceneWorldPrefix & world, u32 index);
bool IsWorldCameraMovementComplete(GameSceneWorldPrefix const & world);
i32 GetWorldCameraY(GameSceneWorldPrefix const & world);
i32 GetWorldCameraX(GameSceneWorldPrefix const & world);
u32 GetWorldCurrentMapId(GameSceneWorldPrefix const & world);
void PanWorldCameraTo(GameSceneWorldPrefix & world, i32 x, i32 y, u32 speed);
void SetWorldCameraPosition(GameSceneWorldPrefix & world, i32 x, i32 y);

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


#endif // GAME_WORLD_HH
