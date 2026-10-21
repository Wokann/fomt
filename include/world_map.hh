#ifndef WORLD_MAP_HH
#define WORLD_MAP_HH

#include "prelude.h"
#include "utility/vec2.hh"
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
    virtual void RefreshAppearance(i32 period, u32 first_weight, u32 second_weight);
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

EXTERN_C
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
void RefreshSavedWorldMapAppearance(GameSceneSavedMapPrefix * map, i32 period,
    u32 first_weight, u32 second_weight);
// Per-frame movement is C++; appearance refresh still has a native base.
// Appearance also refreshes tile data and forwards both encoded palette weights.
void UpdateWorldMap(GameSceneWorldMapPrefix * map);
void RefreshWorldMapAppearance(GameSceneWorldMapPrefix * map, i32 period,
    u32 first_weight, u32 second_weight);
void func_080AA850(GameSceneSavedMapPrefix * map, u32 index);
void func_080AA89C(GameSceneWorldMapPrefix * map);
void func_080AA8BC(GameSceneWorldMapPrefix * map);
void func_080AA8DC(GameSceneSavedMapPrefix * map);
void LoadWorldMapTilemaps(GameSceneWorldMapPrefix & map);
void LoadWorldMapTiles(GameSceneWorldMapPrefix & map);
bool func_080A5EB8(GameSceneWorldMapPrefix * map, Location const & location);
void SetWorldMapTimeOfDayPalette(GameSceneWorldMapPrefix & map, i32 period);
void LoadWorldMapTimeOfDayPalette(GameSceneWorldMapPrefix & map, i32 period, u32 buffer_index);
void func_080A5F78(GameSceneWorldMapPrefix * map, u32 layer,
    Vec2 const & position, u32 width, u32 height);
void RefreshFieldPlotTiles(GameSceneWorldMapPrefix * map, u32 x, u32 y,
    FieldPlot const * plot, FieldPlotRenderData const * render_data);

// A requested screen-center position is clamped to the map's camera origin.
// Set applies it immediately; Pan keeps the native integer frame arithmetic.
Vec2 ClampWorldMapCameraPosition(GameSceneWorldMapPrefix const * map, i32 x, i32 y);
void SetWorldMapCameraPosition(GameSceneWorldMapPrefix * map, i32 x, i32 y);
void PanWorldMapCameraTo(GameSceneWorldMapPrefix * map, i32 x, i32 y, u32 speed);
bool IsWorldMapCameraMovementComplete(GameSceneWorldMapPrefix const * map);

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
