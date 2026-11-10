#ifndef WORLD_SAVED_MAP_HH
#define WORLD_SAVED_MAP_HH

#include "world_map.hh"
#include "saved_map_graphics.hh"

// The native saved-map constructor calls the base constructor, replaces its
// vtable at +0x90, then stores the save pointer at +0x94 and this flag at +0x98.
// The allocation is 0xBC bytes. The runtime member at +0x9C is now
// modeled by SavedMapTree; the two animation states begin at +0xB4/+0xB8.
// Every byte of the native 0xBC allocation is covered by this class.
// Its constructor uses normal C++ member initialization. The native
// destructor adapter and generated ABI table belong to saved_map_tree.cc.
#pragma interface "saved_map_tree.hh"
struct GameSceneSavedMap : GameSceneWorldMap {
    // These declarations bind the existing native ABI entries directly.
    // The flag-taking destructor adapter remains the real destructor entry.
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

typedef char GameSceneSavedMapSaveCheck[offsetof(GameSceneSavedMap, save) == 0x94 ? 1 : -1];
typedef char GameSceneSavedMapFlagCheck[offsetof(GameSceneSavedMap, unk_98) == 0x98 ? 1 : -1];
typedef char GameSceneSavedMapTreeCheck[offsetof(GameSceneSavedMap, saved_tree) == 0x9C ? 1 : -1];
typedef char GameSceneSavedMapAnimation0Check[offsetof(GameSceneSavedMap, tile_animation_0) == 0xB4 ? 1 : -1];
typedef char GameSceneSavedMapAnimation1Check[offsetof(GameSceneSavedMap, tile_animation_1) == 0xB8 ? 1 : -1];
typedef char GameSceneSavedMapSizeCheck[sizeof(GameSceneSavedMap) == 0xBC ? 1 : -1];

EXTERN_C

void ResetSavedMapTree(SavedMapTree * tree, u32 first_tile_index, u32 first_palette_index);
SavedMapGraphicsSlot GetOrAllocateSavedMapGraphicsSlot(SavedMapTree * tree, i32 key);
SavedMapTreeNode * GetFirstSavedMapTreeNode(SavedMapTree * tree);
SavedMapTreeNode * GetSavedMapTreeEnd(SavedMapTree * tree);
void UpdateSavedMapTileAnimationTimers(GameSceneSavedMap * map);
void DrawSavedWorldMap(GameSceneSavedMap * map, HardwareDmaQueue & queue,
    HardwareDisplayState & display, HardwareLinkedList & commands);
void RefreshSavedWorldMapAppearance(GameSceneSavedMap * map, i32 period,
    u32 first_weight, u32 second_weight);
void LoadSavedWorldMapTiles(GameSceneSavedMap * map, HardwareDmaQueue & queue);
void LoadSavedWorldMapTilemaps(GameSceneSavedMap * map);
void LoadSavedWorldMapTimeOfDayPalette(GameSceneSavedMap * map, i32 period,
    u32 buffer_index);
void RefreshWorldMapPatch(GameSceneSavedMap * map, u32 index);
void func_080AA89C(GameSceneWorldMap * map);
void func_080AA8BC(GameSceneWorldMap * map);
void func_080AA8DC(GameSceneSavedMap * map);
void RefreshFieldPlotTiles(GameSceneWorldMap * map, u32 x, u32 y,
    FieldPlot const * plot, FieldPlotRenderData const * render_data);

EXTERN_C_END

// Native setup indexes these three-byte tables with the selected exterior
// style, then writes the result into a tile attribute's high nibble.  The
// table names retain physical offsets because the three concrete display
// groups are not fully named yet.
// agbcp otherwise gives this all-u8 aggregate four-byte trailing padding.
// Keep the compiler attribute directly: the original object is exactly 9 bytes.
struct __attribute__((packed)) FarmHouseStyleNibbleLookupData
{
    u8 values_00[3];
    u8 values_03[3];
    u8 values_06[3];
};

extern FarmHouseStyleNibbleLookupData const gFarmHouseStyleNibbleLookupData;

#endif // WORLD_SAVED_MAP_HH
