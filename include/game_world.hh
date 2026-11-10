#ifndef GAME_WORLD_HH
#define GAME_WORLD_HH

#include "prelude.h"
#include "game_world_interface.hh"
#include "map_terrain.hh"
#include "world_runtime.hh"
#include "world_weather.hh"
#include "entity_actor.hh"
#include "obj_palette_collection.hh"
#include "obj_tile_collection.hh"
#include "resource_handle.hh"
#include "time_of_day_types.hh"
#include "world_map.hh"
#include "scene_sprite_indexed.hh"
#include "scene_sprite_group.hh"


struct GameScene;
struct GameSceneSongPlayerPool;
struct GameSceneScriptRequest;
struct GameStateClock;
struct GameStateSaveImage;
struct RucksackItem;
struct Article;
struct Product;

// Native construction clears four records; update/draw code uses a 12-byte stride.
// The low state/phase bits, tile coordinates and indexed-sprite owner are
// verified. The records' gameplay role and the remaining bits stay unknown.
struct GameSceneWorldUnk1080Entry {
    GameSceneWorldUnk1080Entry() : state(0), unk_08(nullptr) {}

    u8 State() const { return state; }
    u8 unk_00;
    u8 state : 2;
    u8 phase : 2;
    u8 unk_01_04 : 4;
    u8 unk_02[2];
    u16 tile_x;
    u16 tile_y;
    SmartPtr<GameSceneIndexedSprite> unk_08;
};

// A borrowed save calendar advances after 25 update ticks. Its packed
// minute/hour/date/year carries retain the native save representation.
struct WorldCalendarSource {
    explicit WorldCalendarSource(GameCalendar & input) : source(&input), tick_count(0) {}
    GameCalendar Value() const { return *source; }
    GameCalendar const & operator*() const { return *source; }
    GameCalendar * source;
    bool Tick(u32 updates_per_minute)
    {
        u32 ticks = tick_count + 1;
        if (ticks < updates_per_minute) {
            tick_count = ticks;
            return false;
        }
        tick_count = 0;
        if ((source->time.clock_minute = Value().time.clock_minute + 1) > 59) {
            source->time.clock_minute = 0;
            if ((source->time.clock_hour = Value().time.clock_hour + 1) > 23) {
                source->time.clock_hour = 0;
                source->date.AdvanceDay(30);
                if (source->date == GameDate(SEASON_SPRING, 0)) {
                    EncodedGameYear & year = source->year;
                    u32 remainder = year.digits.remainder + 1;
                    if (remainder > 6) {
                        remainder = 0;
                        u32 quotient = year.encoded >> 3;
                        if (quotient <= 28)
                            year.digits.quotient = quotient + 1;
                    }
                    year.digits.remainder = remainder;
                }
            }
        }
        return true;
    }

    u8 tick_count;
};

typedef char WorldCalendarSourceSizeCheck[sizeof(WorldCalendarSource) == 8 ? 1 : -1];

// Six retained event-icon sprite slots, with ordinary indexed access.
struct GameSceneWorldEventIconSprites {
    SmartPtr<GameSceneGroupSprite> slots[6];
    SmartPtr<GameSceneGroupSprite> * Begin() { return slots; }
    SmartPtr<GameSceneGroupSprite> & operator[](u32 index) { return *(Begin() + index); }
};

typedef char GameSceneWorldEventIconSpritesSizeCheck[sizeof(GameSceneWorldEventIconSprites) == 24 ? 1 : -1];

// The native factory allocates exactly 0x10CC bytes. The complete storage
// boundary is covered below; members without proven roles remain unknown.
// Construction is shared C++; unrecovered virtual methods keep their native entries.
#pragma interface "game_world.hh"

struct GameSceneWorld : GameObject {
    virtual ~GameSceneWorld();
    virtual void Update(GameObjectUpdateContext const & input);
    virtual void Draw(GameObjectDrawContext const & context);
    virtual u32 vfunc_14() asm("GetWorldCurrentMapId");
    virtual i32 GetCameraX() asm("GetWorldCameraX");
    virtual i32 GetCameraY() asm("GetWorldCameraY");
    virtual void SetCameraPosition(i32 x, i32 y) asm("SetWorldCameraPosition");
    virtual void PanCameraTo(i32 x, i32 y, u32 speed) asm("PanWorldCameraTo");
    virtual bool IsCameraMovementComplete() asm("IsWorldCameraMovementComplete");
    virtual i32 GetMapPixelWidth(u32 map_id) asm("GetWorldMapPixelWidth");
    virtual i32 GetMapPixelHeight(u32 map_id) asm("GetWorldMapPixelHeight");
    virtual MapTerrainView GetMapTerrain(u32 map_id) asm("GetWorldMapTerrain");
    virtual void vfunc_38(u32 entity_id) asm("RefreshWorldEntitySlot");
    virtual void vfunc_3C(u32 index) asm("RemoveWorldEntity");
    virtual AEntity * GetEntity(u32 id);
    virtual AEntity * GetEntity(u32 id) const;
    virtual u32 vfunc_48(i32 kind) asm("func_0801B5C0");
    // Resource byte +0x81 is cleared; its complete role remains unknown.
    virtual void ClearSpritePaletteResourceFlag(u32 index) asm("ClearWorldSpritePaletteResourceFlag");
    virtual i32 GetSpritePaletteBank(u32 index) asm("GetWorldSpritePaletteBank");
    // The final byte is retained by the resource; its role remains unknown.
    virtual void SetSpritePaletteColors(u8 const * data, u32 palette_resource, u8 unk) asm("SetWorldSpritePaletteColors");
    virtual EntityAuxiliarySprites * GetEntityAuxiliarySprites() asm("GetWorldEntityAuxiliarySprites");
    virtual IndexedResourceArchive * vfunc_5C() asm("func_0801FC54");
    virtual IndexedResourceArchive * vfunc_60() asm("func_0801FC48");
    virtual IndexedResourceArchive * vfunc_64() asm("func_0801FC60");
    virtual IndexedResourceArchive * vfunc_68() asm("GetWorldActorAnimationArchive");
    virtual IndexedResourceArchive * vfunc_6C() asm("func_0801FC3C");
    virtual IndexedResourceArchive * vfunc_70() asm("func_0801FC0C");
    virtual IndexedResourceArchive * vfunc_74() asm("func_0801FC00");
    virtual IndexedResourceArchive * vfunc_78() asm("func_0801FBF4");
    virtual IndexedResourceArchive * vfunc_7C() asm("func_0801FBE8");
    virtual void StartShipmentBoxDepositAnimation() asm("func_0801DD78");
    virtual void PrepareClockMenuTransition() asm("func_0801DD18");
    virtual void RestoreAfterClockMenu() asm("func_0801DD24");
    virtual void PrepareCookingMenuTransition() asm("func_0801DD30");
    virtual void RestoreAfterCookingMenu() asm("func_0801DD3C");
    virtual void PrepareRecipeMenuTransition() asm("func_0801DD48");
    virtual void RestoreAfterRecipeMenu() asm("func_0801DD54");
    virtual void RefreshBarnFeedTrough(MaryBarnFeedTroughIndex trough) asm("func_0801DD60");
    virtual void RefreshChickenFeedTrough(MaryChickenCoopFeedTroughIndex trough) asm("func_0801DD6C");
    virtual MaryItemArticleId RemoveRecordPlayerAlbum() asm("RemoveRecordPlayerAlbum");
    virtual MaryItemArticleId SwapRecordPlayerAlbum(MaryItemArticleId article) asm("SwapRecordPlayerAlbum");
    virtual void RefreshChickenCoopIncubator(MaryChickenCoopIncubatorIndex incubator) asm("func_0801DE24");
    virtual bool IsTimePaused() const asm("IsWorldTimePaused");
    virtual void ChangeMap(Location const & location, bool unk);
    virtual void RefreshMapTimeOfDayPalette() asm("RefreshWorldMapTimeOfDayPalette");
    virtual void vfunc_BC(GameTime const & time) asm("func_0801EAA0");
    virtual u32 vfunc_C0(Location const & location) asm("func_0801C29C");
    virtual bool vfunc_C4(Location const & location, u32 level) asm("func_0801CA1C");
    virtual bool vfunc_C8(Location const & location, u32 & item_code) asm("func_0801C49C");
    virtual bool vfunc_CC(Location const & location, u32 & item_code) asm("func_0801CAD8");
    virtual bool vfunc_D0(Location const & location, u32 level) asm("func_0801CEFC");
    virtual bool vfunc_D4(Location const & location) asm("func_0801D23C");
    virtual u32 vfunc_D8(Location const & location) asm("func_0801D3FC");
    virtual void vfunc_DC(Location const & location, i32 id) asm("func_0801D4E0");
    virtual void vfunc_E0(Location const & location, RucksackItem & output) asm("func_0801D5BC");
    virtual void vfunc_E4(Location const & location, Article const & article) asm("func_0801D7B0");
    virtual u32 vfunc_E8(Location const & location, Article const & article) asm("func_0801D88C");
    virtual bool vfunc_EC(u32 map_id, u32 level) asm("func_0801CBB0");
    virtual bool vfunc_F0(u32 map_id, u32 level) asm("func_0801CFB8");
    virtual void vfunc_F4() asm("func_0801C3DC");
    virtual void vfunc_F8() asm("func_0801C3E0");
    virtual void RedrawRucksackShelfAfterPurchase() asm("func_0801DE30");
    virtual void RedrawBlueFeatherShelfAfterPurchase() asm("func_0801DE3C");
    virtual void vfunc_104() asm("func_0801DE48");
    virtual bool vfunc_108(Vec2 const & position) asm("func_0801DEB4");
    virtual void OpenDoor(MaryDoorIndex door_index) asm("SetWorldMapPatchFlag");
    virtual void CloseDoor(MaryDoorIndex door_index) asm("ClearWorldMapPatchFlag");
    virtual void vfunc_114() asm("CollectDailyShippingRevenue");
    virtual void SetTelevisionProgram(MaryTelevisionProgramId program) asm("func_0801DC24");
    virtual void EndTelevisionProgram() asm("func_0801DCA8");
    virtual bool vfunc_120(Location const & location) asm("func_08019F38");
    virtual void SuspendUpdates() asm("SuspendWorldUpdates");
    virtual void ResumeUpdates() asm("ResumeWorldUpdates");
    // Separate native bridges dispatch to the non-const and const GetEntity slots.
    virtual AEntity * vfunc_12C(u32 id) asm("GetWorldEntity");
    virtual AEntity * vfunc_130(u32 id) asm("GetWorldEntityConst");
    virtual u32 vfunc_134(Location const & location, Box const & bounds) asm("FindNearestOverlappingWorldEntitySlot");
    virtual void vfunc_138() asm("func_0801E084");
    // Write the pending marker and its still-unknown accompanying byte.
    virtual void SetPendingUnknownValue(u8 value) asm("SetWorldPendingUnknownValue");
    virtual void QueueScript(GameSceneScriptRequest const & request, i32 queue_kind) asm("QueueWorldScript");
    virtual GameStateClock const * GetClock() asm("GetWorldClock");
    virtual u32 GetDefaultAudioSequence() asm("SelectWorldBackgroundAudio");
    virtual GameSceneSongPlayerPool & GetSongPlayerPool();
    virtual void LightFireplaceAtLocation(MaryMapId map);
    virtual void SetVaseArticleId(MaryItemArticleId article);
    virtual void vfunc_158(Location const & location, RucksackItem const & item) asm("func_0801EE00");
    virtual void ShipProduct(Product const & product);
    virtual void CreateEventIcon(MaryEventIconSlot slot, MaryMapSpaceX x, MaryMapSpaceY y, MaryEventIconLayer layer, u16 icon_id) asm("CreateWorldEventIcon");
    virtual void RemoveEventIcon(MaryEventIconSlot slot) asm("RemoveWorldEventIcon");

    GameSceneWorld(GameStateSaveImage * save, GameScene * scene,
        GameSceneWorldMapOwner map, bool unk);

    GameSceneWorldData data;
    GameStateSaveImage * save;
    u8 updates_suspended;
    u8 unk_103D[3];
    WorldCalendarSource calendar;
    i32 time_of_day_period;
    u8 time_palette_blend;
    u8 unk_104D[3];
    FieldRenderTileAttributes * farm_tile_attributes;
    GameScene * scene;
    SmartPtr<GameSceneIndexedSprite> unk_1058;
    SmartPtr<GameSceneIndexedSprite> fireplace_sprite;
    u8 unk_1060;
    u8 unk_1061[3];
    SmartPtr<GameSceneIndexedSprite> beach_house_sprite;
    SmartPtr<GameSceneGroupSprite> vase_sprite;
    SmartPtr<GameSceneIndexedSprite> hill_seasonal_sprites[2];
    SmartPtr<GameSceneIndexedSprite> winter_and_fireplace_sprites[2];
    SmartPtr<GameSceneWeatherEffect> weather_effect;
    GameSceneWorldUnk1080Entry unk_1080[4];
    // Rebuild retained event icons from the scene controller during construction.
    GameSceneWorldEventIconSprites event_icon_sprites;
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
typedef char GameSceneWorldSprite106CCheck[offsetof(GameSceneWorld, hill_seasonal_sprites[0]) == 0x106C ? 1 : -1];
typedef char GameSceneWorldSprite1070Check[offsetof(GameSceneWorld, hill_seasonal_sprites[1]) == 0x1070 ? 1 : -1];
typedef char GameSceneWorldSprite1074Check[offsetof(GameSceneWorld, winter_and_fireplace_sprites[0]) == 0x1074 ? 1 : -1];
typedef char GameSceneWorldSprite1078Check[offsetof(GameSceneWorld, winter_and_fireplace_sprites[1]) == 0x1078 ? 1 : -1];
typedef char GameSceneWorldVaseSpriteCheck[offsetof(GameSceneWorld, vase_sprite) == 0x1068 ? 1 : -1];
typedef char GameSceneWorldFireplaceSpriteCheck[offsetof(GameSceneWorld, fireplace_sprite) == 0x105C ? 1 : -1];

typedef char GameSceneWorldCalendarFlagCheck[offsetof(GameSceneWorld, calendar) + offsetof(WorldCalendarSource, tick_count) == 0x1044 ? 1 : -1];
typedef char GameSceneWorldBeachHouseSpriteCheck[offsetof(GameSceneWorld, beach_house_sprite) == 0x1064 ? 1 : -1];
typedef char GameSceneWorldEventIconSpritesCheck[offsetof(GameSceneWorld, event_icon_sprites) == 0x10B0 ? 1 : -1];

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

bool TryGetFarmPlotAtLocation(GameSceneWorld & world, Location const & location,
    GameSceneFarmPlotLocation & output);
u32 func_0801740C(FieldPlot const & plot);
u32 func_0801746C(FieldPlot const & plot);
bool func_080174C8(Farm & farm, FieldItemState & items, u32 index, i32 season,
    i32 power, bool hammer, GameSceneFieldItemToolResult & result);
RucksackItem PickUpFieldItemAtLocation(GameSceneWorld & world, Location const & location);
// Native world sprite refresh implementations.
void SetWorldWeatherEffect(GameSceneWorld & world, GameSceneWeatherEffect::Kind kind);
void RefreshWorldFireplaceSprite(GameSceneWorld & world);
void RefreshWorldBeachHouseSprite(GameSceneWorld & world);

void UpdateWorldBackgroundAudio(GameSceneWorld & world);

// Still native: update/create the vase sprite in the farmhouse, or release it
// outside that map. ITEM_ARTICLE_NONE leaves an existing vase sprite alone.
void RefreshWorldVase(GameSceneWorld & world);

TimeOfDayPeriod GetWorldTimeOfDayPeriod(GameSceneWorld & world, u32 hour);
// Native palette/cache rebuild; force is a byte, not a new boolean restriction.
void UpdateWorldTimeOfDayPalettes(GameSceneWorld & world, u32 hour, u32 minute, u8 force);

// Release the old two owners first, then create the map/season variants.
void RefreshWorldHillSeasonalSprites(GameSceneWorld & world);
// The supported maps combine winter state and the three actual fireplace bits.
void RefreshWorldWinterAndFireplaceSprites(GameSceneWorld & world);

EXTERN_C_END

// Transfer from the factory's concrete world slot to the base-world owner.
struct GameSceneWorldOwnerTransfer {
    GameSceneWorld * & source;
    GameObject * value;
    GameSceneWorldOwnerTransfer(GameSceneWorld * & input, GameObject * world)
        : source(input), value(world)
    {
        // Cache the base pointer before releasing the concrete source slot.
        input = nullptr;
    }
    GameObject * release() const
    {
        return value;
    }
};

// Own the complete native world. Return adoption clears the source slot
// through its eight-byte transfer record; assignment to the base owner uses
// the separate transfer contract above.
struct GameSceneWorldInstanceTransfer {
    GameSceneWorld * & source;
    GameSceneWorld * value;
    GameSceneWorldInstanceTransfer(GameSceneWorld * & input, GameSceneWorld * world)
        : source(input), value(world) {}
    GameSceneWorld * release() const
    {
        GameSceneWorld * world = value;
        source = nullptr;
        return world;
    }
};

struct GameSceneWorldInstanceOwner {
    GameSceneWorld * value;
    GameSceneWorld * release()
    {
        GameSceneWorld * world = value;
        value = nullptr;
        return world;
    }
    explicit GameSceneWorldInstanceOwner(GameSceneWorld * input = nullptr) : value(input) {}
    GameSceneWorldInstanceOwner(GameSceneWorldInstanceOwner & other) : value(other.release()) {}
    GameSceneWorldInstanceOwner(GameSceneWorldInstanceTransfer input) : value(input.release()) {}
    operator GameSceneWorldInstanceTransfer()
    {
        return GameSceneWorldInstanceTransfer(value, value);
    }
    ~GameSceneWorldInstanceOwner() { delete value; }
    operator GameSceneWorldOwnerTransfer()
    {
        return GameSceneWorldOwnerTransfer(value, value);
    }
};

typedef char GameSceneWorldInstanceTransferSizeCheck[sizeof(GameSceneWorldInstanceTransfer) == 8 ? 1 : -1];
typedef char GameSceneWorldInstanceTransferValueCheck[offsetof(GameSceneWorldInstanceTransfer, value) == 4 ? 1 : -1];

typedef char GameSceneWorldInstanceOwnerSizeCheck[sizeof(GameSceneWorldInstanceOwner) == 4 ? 1 : -1];
typedef char GameSceneWorldOwnerTransferSizeCheck[sizeof(GameSceneWorldOwnerTransfer) == 8 ? 1 : -1];
typedef char GameSceneWorldOwnerTransferValueCheck[offsetof(GameSceneWorldOwnerTransfer, value) == 4 ? 1 : -1];

#endif // GAME_WORLD_HH
