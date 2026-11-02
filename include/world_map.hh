#ifndef WORLD_MAP_HH
#define WORLD_MAP_HH

#include "prelude.h"
#include "utility/vec2.hh"
#include "hardware_linked_list.hh"
#include "field_render_farm_house_data.hh"

struct GameStateSaveImage;
struct FieldRenderTileAttributes;
struct FieldRenderRectDescriptor;
struct FieldPlot;
struct FieldPlotRenderData;
struct Location;
struct HardwareDmaQueue;
struct HardwareDisplayState;

// The map controller stores Q16.16 camera coordinates. Native integer
// readers sign-extend their high halfwords; movement writes the whole word.
union GameSceneCameraCoordinate {
    GameSceneCameraCoordinate() : q16(0) {}
    i32 q16;
    struct {
        u16 fraction;
        i16 integer;
    } parts;
};

struct MapTilePatchAnimationState {
    MapTilePatchAnimationState() : frame(0), update_pending(false), elapsed_frames(0) {}
    u8 frame;
    bool update_pending;
    u8 elapsed_frames;
    void Tick(FarmHouseTilePatchAnimationDescriptor const & animation);
    void ResetFrame();
};

typedef char MapTilePatchAnimationPendingCheck[offsetof(MapTilePatchAnimationState, update_pending) == 1 ? 1 : -1];
typedef char MapTilePatchAnimationElapsedCheck[offsetof(MapTilePatchAnimationState, elapsed_frames) == 2 ? 1 : -1];
typedef char MapTilePatchAnimationStateSizeCheck[sizeof(MapTilePatchAnimationState) == 4 ? 1 : -1];

// One DMA source/destination pair for a visible tilemap layer.
struct MapViewportTilemapTransfer {
    u16 const * source;
    u16 * destination;
};

// The one-shot hardware command copies a 31x21 viewport into the
// 32-entry destination rows, then returns false to leave the list.
struct MapViewportTilemapCommand : HardwareLinkBase {
    virtual bool Run();

    MapViewportTilemapTransfer layers[3];
    u16 source_width;
};

typedef char MapViewportTilemapCommandSizeCheck[sizeof(MapViewportTilemapCommand) == 0x28 ? 1 : -1];
typedef char MapViewportTilemapCommandLayersCheck[offsetof(MapViewportTilemapCommand, layers) == 0xC ? 1 : -1];
typedef char MapViewportTilemapCommandWidthCheck[offsetof(MapViewportTilemapCommand, source_width) == 0x24 ? 1 : -1];

// The base map owns three tile grids, time-of-day palettes and tile attributes.
// The move routine writes per-frame Q16.16 steps and a frame countdown.
struct GameSceneWorldMap {
    u32 map;
    u32 map_data_id;
    GameSceneCameraCoordinate x;
    GameSceneCameraCoordinate y;
    u16 * tile_layers[3];
    u16 * time_palette_buffers[3];
    u8 tiles_changed;
    bool view_changed;
    bool time_palette_changed;
    u8 unk_2B;
    FieldRenderTileAttributes * tile_attributes;
    // Native construction initializes ten independent state objects.
    // Their individual layout roles are not yet fully identified.
    MapTilePatchAnimationState layout_animation_0;
    MapTilePatchAnimationState layout_animation_1;
    MapTilePatchAnimationState layout_animation_2;
    MapTilePatchAnimationState layout_animation_3;
    MapTilePatchAnimationState layout_animation_4;
    MapTilePatchAnimationState layout_animation_5;
    MapTilePatchAnimationState layout_animation_6;
    MapTilePatchAnimationState layout_animation_7;
    MapTilePatchAnimationState layout_animation_8;
    MapTilePatchAnimationState layout_animation_9;
    u8 tile_patch_countdown;
    u8 unk_59[3];
    MapViewportTilemapCommand viewport_command;
    i32 step_x_q16;
    i32 step_y_q16;
    u32 movement_frames;
    virtual ~GameSceneWorldMap();
    virtual void Update();
    // Draw retains its native body for now.
    virtual void Draw(HardwareDmaQueue & queue, HardwareDisplayState & display, HardwareLinkedList & commands);
    virtual void RefreshAppearance(i32 period, u32 first_weight, u32 second_weight);
    virtual u32 SelectMapData();
    // The base ignores the queue; saved-map overrides enqueue extra tiles.
    virtual void LoadTiles(HardwareDmaQueue & queue);
    virtual void LoadTilemaps();
    virtual void LoadTimeOfDayPalette(i32 period, u32 buffer_index);

    void SetLocation(Location const & location, i32 period, u32 first_weight, u32 second_weight);
    // The RGB5 bank mixer still retains its native assembly body.
    void BlendTimeOfDayPalettes(u32 first_weight, u32 second_weight);

    GameSceneWorldMap();
};

// The saved-map sentinel owns a full node. Its links and node count are
// known; the flag, payload and untouched container bytes remain unknown.
struct SavedMapTreeNode {
    u8 unk_00;
    SavedMapTreeNode * parent;
    SavedMapTreeNode * left;
    SavedMapTreeNode * right;
    u8 unk_10[8];
};

struct SavedMapTreeState {
    u8 unk_00[4];
    SavedMapTreeNode * header;
    u32 node_count;
    u32 unk_0C;
};

struct SavedMapTree {
    // Sentinel construction retains its native implementation.
    SavedMapTree();
    u32 unk_00;
    u32 unk_04;
    SavedMapTreeState state;
};

typedef char SavedMapTreeNodeSizeCheck[sizeof(SavedMapTreeNode) == 0x18 ? 1 : -1];
typedef char SavedMapTreeNodeParentCheck[offsetof(SavedMapTreeNode, parent) == 4 ? 1 : -1];
typedef char SavedMapTreeNodeLeftCheck[offsetof(SavedMapTreeNode, left) == 8 ? 1 : -1];
typedef char SavedMapTreeNodeRightCheck[offsetof(SavedMapTreeNode, right) == 12 ? 1 : -1];
typedef char SavedMapTreeStateSizeCheck[sizeof(SavedMapTreeState) == 16 ? 1 : -1];
typedef char SavedMapTreeHeaderCheck[offsetof(SavedMapTreeState, header) == 4 ? 1 : -1];
typedef char SavedMapTreeNodeCountCheck[offsetof(SavedMapTreeState, node_count) == 8 ? 1 : -1];
typedef char SavedMapTreeSizeCheck[sizeof(SavedMapTree) == 0x18 ? 1 : -1];
typedef char SavedMapTreeStateCheck[offsetof(SavedMapTree, state) == 8 ? 1 : -1];

// The native saved-map constructor calls the base constructor, replaces its
// vtable at +0x90, then stores the save pointer at +0x94 and this flag at +0x98.
// The allocation is 0xBC bytes. The runtime member at +0x9C is now
// modeled by SavedMapTree; the two animation states begin at +0xB4/+0xB8.
// Every byte of the native 0xBC allocation is covered by this class.
// Its constructor uses normal C++ member initialization. The native
// destructor adapter and exact ABI table remain explicit.
struct GameSceneSavedMap : GameSceneWorldMap {
    // These declarations bind the existing native ABI entries directly.
    // The flag-taking destructor adapter still owns the native table below.
    virtual ~GameSceneSavedMap() asm("DestroySavedWorldMap");
    virtual void Update() asm("UpdateSavedMapTileAnimationTimers");
    virtual void Draw(HardwareDmaQueue & queue, HardwareDisplayState & display,
        HardwareLinkedList & commands) asm("DrawSavedWorldMap");
    virtual void RefreshAppearance(i32 period, u32 first_weight, u32 second_weight)
        asm("RefreshSavedWorldMapAppearance");
    virtual u32 SelectMapData() asm("SelectSavedWorldMapData");
    virtual void LoadTiles(HardwareDmaQueue & queue) asm("LoadSavedWorldMapTiles");
    virtual void LoadTilemaps() asm("LoadSavedWorldMapTilemaps");
    virtual void LoadTimeOfDayPalette(i32 period, u32 buffer_index)
        asm("LoadSavedWorldMapTimeOfDayPalette");

    GameStateSaveImage * save;
    bool unk_98;
    SavedMapTree saved_tree;
    MapTilePatchAnimationState tile_animation_0;
    MapTilePatchAnimationState tile_animation_1;

    GameSceneSavedMap(GameStateSaveImage * image);
};

// Layout of the imported flag-taking destructor and native virtual entries.
// This is the one actual table referenced by the old GCC constructor ABI.
struct GameSceneSavedMapVTable {
    u32 unk_00;
    u32 unk_04;
    void (*destroy)(GameSceneSavedMap *, int);
    void (*update)(GameSceneSavedMap *);
    void (*draw)(GameSceneSavedMap *, HardwareDmaQueue &, HardwareDisplayState &,
        HardwareLinkedList &);
    void (*refresh_appearance)(GameSceneSavedMap *, i32, u32, u32);
    u32 (*select_map_data)(GameSceneSavedMap *);
    void (*load_tiles)(GameSceneSavedMap *, HardwareDmaQueue &);
    void (*load_tilemaps)(GameSceneSavedMap *);
    void (*load_time_of_day_palette)(GameSceneSavedMap *, i32, u32);
};

typedef char GameSceneSavedMapVTableSizeCheck[sizeof(GameSceneSavedMapVTable) == 40 ? 1 : -1];
extern GameSceneSavedMapVTable const gGameSceneSavedMapVTable
    asm("__vt_17GameSceneSavedMap");

typedef char GameSceneMapLayoutAnimation0Check[offsetof(GameSceneWorldMap, layout_animation_0) == 0x30 ? 1 : -1];
typedef char GameSceneMapLayoutAnimation1Check[offsetof(GameSceneWorldMap, layout_animation_1) == 0x34 ? 1 : -1];
typedef char GameSceneMapLayoutAnimation2Check[offsetof(GameSceneWorldMap, layout_animation_2) == 0x38 ? 1 : -1];
typedef char GameSceneMapLayoutAnimation3Check[offsetof(GameSceneWorldMap, layout_animation_3) == 0x3c ? 1 : -1];
typedef char GameSceneMapLayoutAnimation4Check[offsetof(GameSceneWorldMap, layout_animation_4) == 0x40 ? 1 : -1];
typedef char GameSceneMapLayoutAnimation5Check[offsetof(GameSceneWorldMap, layout_animation_5) == 0x44 ? 1 : -1];
typedef char GameSceneMapLayoutAnimation6Check[offsetof(GameSceneWorldMap, layout_animation_6) == 0x48 ? 1 : -1];
typedef char GameSceneMapLayoutAnimation7Check[offsetof(GameSceneWorldMap, layout_animation_7) == 0x4c ? 1 : -1];
typedef char GameSceneMapLayoutAnimation8Check[offsetof(GameSceneWorldMap, layout_animation_8) == 0x50 ? 1 : -1];
typedef char GameSceneMapLayoutAnimation9Check[offsetof(GameSceneWorldMap, layout_animation_9) == 0x54 ? 1 : -1];

// These are palette buffers, distinct from the three map tile grids.
typedef char GameSceneMapTimePaletteBuffersCheck[offsetof(GameSceneWorldMap, time_palette_buffers) == 0x1C ? 1 : -1];
typedef char GameSceneMapTimePaletteChangedCheck[offsetof(GameSceneWorldMap, time_palette_changed) == 0x2A ? 1 : -1];

typedef char GameSceneSavedMapSaveCheck[offsetof(GameSceneSavedMap, save) == 0x94 ? 1 : -1];
typedef char GameSceneSavedMapFlagCheck[offsetof(GameSceneSavedMap, unk_98) == 0x98 ? 1 : -1];
typedef char GameSceneSavedMapTreeCheck[offsetof(GameSceneSavedMap, saved_tree) == 0x9C ? 1 : -1];
typedef char GameSceneSavedMapAnimation0Check[offsetof(GameSceneSavedMap, tile_animation_0) == 0xB4 ? 1 : -1];
typedef char GameSceneSavedMapAnimation1Check[offsetof(GameSceneSavedMap, tile_animation_1) == 0xB8 ? 1 : -1];
typedef char GameSceneSavedMapSizeCheck[sizeof(GameSceneSavedMap) == 0xBC ? 1 : -1];


typedef char GameSceneCameraCoordinateSizeCheck[sizeof(GameSceneCameraCoordinate) == 4 ? 1 : -1];
typedef char GameSceneCameraIntegerCheck[offsetof(GameSceneCameraCoordinate, parts.integer) == 2 ? 1 : -1];
typedef char GameSceneCameraPointSizeCheck[sizeof(Vec2) == 4 ? 1 : -1];
typedef char GameSceneCameraMapDataIdCheck[offsetof(GameSceneWorldMap, map_data_id) == 4 ? 1 : -1];
typedef char GameSceneCameraXCheck[offsetof(GameSceneWorldMap, x) == 8 ? 1 : -1];
typedef char GameSceneCameraYCheck[offsetof(GameSceneWorldMap, y) == 0xC ? 1 : -1];
typedef char GameSceneMapTileLayersCheck[offsetof(GameSceneWorldMap, tile_layers) == 0x10 ? 1 : -1];
typedef char GameSceneMapTileAttributesCheck[offsetof(GameSceneWorldMap, tile_attributes) == 0x2C ? 1 : -1];
typedef char GameSceneMapViewportCommandCheck[offsetof(GameSceneWorldMap, viewport_command) == 0x5C ? 1 : -1];

typedef char GameSceneMapTilePatchCountdownCheck[offsetof(GameSceneWorldMap, tile_patch_countdown) == 0x58 ? 1 : -1];
typedef char GameSceneMapTilesChangedCheck[offsetof(GameSceneWorldMap, tiles_changed) == 0x28 ? 1 : -1];
typedef char GameSceneMapViewChangedCheck[offsetof(GameSceneWorldMap, view_changed) == 0x29 ? 1 : -1];
typedef char GameSceneCameraStepXCheck[offsetof(GameSceneWorldMap, step_x_q16) == 0x84 ? 1 : -1];
typedef char GameSceneCameraStepYCheck[offsetof(GameSceneWorldMap, step_y_q16) == 0x88 ? 1 : -1];
typedef char GameSceneCameraFramesCheck[offsetof(GameSceneWorldMap, movement_frames) == 0x8C ? 1 : -1];
typedef char GameSceneWorldMapSizeCheck[sizeof(GameSceneWorldMap) == 0x94 ? 1 : -1];

EXTERN_C

// These callbacks keep the native tree traversal and destruction flags.
void ResetSavedMapTree(SavedMapTree * tree, u32 unk_00, u32 unk_04);
void EraseSavedMapTreeNodes(SavedMapTreeState * state, SavedMapTreeNode * node);
void DestroySavedWorldMap(GameSceneSavedMap * map, int flags);
// Direct declaration of the existing C++ base destructor ABI, not a wrapper.
void DestroyWorldMapBase(GameSceneWorldMap * map, int flags)
    asm("_._17GameSceneWorldMap");
void ApplyMapTilePatch(GameSceneWorldMap * map,
    FieldRenderRectDescriptor const & patch, u32 x, u32 y);
void StartWorldMapTilePatchCountdown(GameSceneWorldMap * map);
void RefreshCoopFeedTrough(GameSceneWorldMap * map, u32 index);
// This barn dispatcher retains its native implementation and unchecked index.
void func_080A607C(GameSceneWorldMap * map, u32 index);
void func_080A6138(GameSceneWorldMap * map);
void func_080A6194(GameSceneWorldMap * map);
void func_080A61F0(GameSceneWorldMap * map);
void func_080A6234(GameSceneWorldMap * map);
void func_080A6278(GameSceneWorldMap * map);
void func_080A62BC(GameSceneWorldMap * map);
void func_080A6300(GameSceneWorldMap * map);
void func_080A635C(GameSceneWorldMap * map);
void func_080A63B8(GameSceneWorldMap * map, u32 unk);
FieldRenderTileAttributes * GetWorldMapTileAttributes(GameSceneWorldMap * map, u32 x, u32 y);
u32 GetWorldMapDataId(GameSceneWorldMap const * map);
u32 GetWorldMapId(GameSceneWorldMap const * map);
i32 GetWorldMapViewY(GameSceneWorldMap const * map);
i32 GetWorldMapViewX(GameSceneWorldMap const * map);
void UpdateSavedMapTileAnimationTimers(GameSceneSavedMap * map);
void QueueMapTilePatch(GameSceneWorldMap * map,
    FarmHouseTilePatchDescriptor const & patch, u32 frame, HardwareDmaQueue & queue);
void DrawSavedWorldMap(GameSceneSavedMap * map, HardwareDmaQueue & queue,
    HardwareDisplayState & display, HardwareLinkedList & commands);
void RefreshSavedWorldMapAppearance(GameSceneSavedMap * map, i32 period,
    u32 first_weight, u32 second_weight);
// Native overrides keep real symbol entries while their bodies remain assembly.
u32 SelectSavedWorldMapData(GameSceneSavedMap * map);
void LoadSavedWorldMapTiles(GameSceneSavedMap * map, HardwareDmaQueue & queue);
void LoadSavedWorldMapTilemaps(GameSceneSavedMap * map);
void LoadSavedWorldMapTimeOfDayPalette(GameSceneSavedMap * map, i32 period,
    u32 buffer_index);
void RefreshWorldMapPatch(GameSceneSavedMap * map, u32 index);
void func_080AA89C(GameSceneWorldMap * map);
void func_080AA8BC(GameSceneWorldMap * map);
void func_080AA8DC(GameSceneSavedMap * map);
bool func_080A5EB8(GameSceneWorldMap * map, Location const & location);
void SetWorldMapTimeOfDayPalette(GameSceneWorldMap & map, i32 period);
void ClearWorldMapTileRectangle(GameSceneWorldMap * map, u32 layer,
    Vec2 const & position, u32 width, u32 height);
void RefreshFieldPlotTiles(GameSceneWorldMap * map, u32 x, u32 y,
    FieldPlot const * plot, FieldPlotRenderData const * render_data);

// A requested screen-center position is clamped to the map's camera origin.
// Set applies it immediately; Pan keeps the native integer frame arithmetic.
Vec2 ClampWorldMapCameraPosition(GameSceneWorldMap const * map, i32 x, i32 y);
void SetWorldMapCameraPosition(GameSceneWorldMap * map, i32 x, i32 y);
void PanWorldMapCameraTo(GameSceneWorldMap * map, i32 x, i32 y, u32 speed);
bool IsWorldMapCameraMovementComplete(GameSceneWorldMap const * map);

EXTERN_C_END

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


#endif // WORLD_MAP_HH
