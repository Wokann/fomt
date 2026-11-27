#ifndef WORLD_MAP_HH
#define WORLD_MAP_HH

#include "prelude.h"
#include "saved_map_tree.hh"
#include <stdlib.h>
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


// One DMA source/destination pair for a visible tilemap layer.
struct MapViewportTilemapTransfer {
    u16 const * source;
    u16 * destination;
};

#pragma interface "world_map_command_lifetimes.hh"
// The one-shot hardware command copies a 31x21 viewport into the
// 32-entry destination rows, then returns false to leave the list.
struct MapViewportTilemapCommand : HardwareLinkBase {
    virtual bool Run();

    MapViewportTilemapTransfer layers[3];
    u16 source_width;
};


#pragma interface "world_map.hh"

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


struct GameSceneSavedMap;
#include "world_saved_map.hh"


// These are palette buffers, distinct from the three map tile grids.




EXTERN_C

// These callbacks keep the native tree traversal and destruction flags.
// Missing keys reserve four tiles and one palette. Key 13 keeps its
// original reserved slot (tile 0x3E6, palette 11).
// Direct declaration of the existing C++ base destructor ABI, not a wrapper.
void DestroyWorldMapBase(GameSceneWorldMap * map, int flags)
    asm("_._17GameSceneWorldMap");
void ApplyMapTilePatch(GameSceneWorldMap * map,
    FieldRenderRectDescriptor const & patch, u32 x, u32 y);
void StartWorldMapTilePatchCountdown(GameSceneWorldMap * map);
void RefreshCoopFeedTrough(GameSceneWorldMap * map, u32 index);
// This barn dispatcher retains its native implementation and unchecked index.
void RefreshBarnFeedTrough(GameSceneWorldMap * map, u32 index);
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
void QueueMapTilePatch(GameSceneWorldMap * map,
    FarmHouseTilePatchDescriptor const & patch, u32 frame, HardwareDmaQueue & queue);
// Native overrides keep real symbol entries while their bodies remain assembly.
bool func_080A5EB8(GameSceneWorldMap * map, Location const & location);
void SetWorldMapTimeOfDayPalette(GameSceneWorldMap & map, i32 period);
void ClearWorldMapTileRectangle(GameSceneWorldMap * map, u32 layer,
    Vec2 const & position, u32 width, u32 height);

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

struct FieldRenderPatchArgumentData
{
    u8 values_00[8];
    u8 values_08[4];
    u8 values_0C[16][2];
    u8 overlapping_values_2C[0x30];
    u8 values_5C[4];
};

// One independently addressed table for each viewport configuration field.
extern u32 const gWorldMapViewportScreenBlocks[3];
extern u32 const gWorldMapViewportPriorities[3];
extern volatile u16 * const gWorldMapViewportControlRegisters[3];
extern volatile u16 * const gWorldMapViewportHorizontalScrollRegisters[3];
extern volatile u16 * const gWorldMapViewportVerticalScrollRegisters[3];
extern FieldRenderPatchArgumentData const gFieldRenderPatchArgumentData;



#include "world_map_command_lifetimes.hh"

#endif // WORLD_MAP_HH
