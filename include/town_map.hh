#ifndef TOWN_MAP_HH
#define TOWN_MAP_HH

#include "prelude.h"
#include "red_black_tree.hh"
#include "allocation_failure.hh"
#include <stdlib.h>

// Both lookup records and tree keys store a four-byte-aligned pair of
// screen coordinates. The final two bytes are padding, not another field.
struct ALIGN(4) TownMapMarkerPosition {
    u8 x;
    u8 y;

    bool operator<(TownMapMarkerPosition const & other) const
    {
        return x < other.x || (!(other.x < x) && y < other.y);
    }
};

EXTERN_C

struct TownMapHotspot
{
    char const * primary_text;
    char const * alternate_text;
    u32 map_id;
    u16 map_x;
    u16 map_y;
    u8 min_cursor_x;
    u8 min_cursor_y;
    u8 max_cursor_x;
    u8 max_cursor_y;
};

// Native Town Map selection scans each subtable until its all-zero record.
struct TownMapAreaBounds
{
    u16 min_x;
    u16 min_y;
    u16 max_x;
    u16 max_y;
    TownMapMarkerPosition marker_position;
};

enum
{
    TOWN_MAP_AREA_BOUNDS_000_COUNT = 18,
    TOWN_MAP_AREA_BOUNDS_003_COUNT = 11,
    TOWN_MAP_AREA_BOUNDS_005_COUNT = 27,
    TOWN_MAP_AREA_BOUNDS_007_COUNT = 17,
    TOWN_MAP_AREA_BOUNDS_001_COUNT = 3,
};

struct TownMapAreaBoundsTables
{
    TownMapAreaBounds map_000[TOWN_MAP_AREA_BOUNDS_000_COUNT];
    TownMapAreaBounds map_003[TOWN_MAP_AREA_BOUNDS_003_COUNT];
    TownMapAreaBounds map_005[TOWN_MAP_AREA_BOUNDS_005_COUNT];
    TownMapAreaBounds map_007[TOWN_MAP_AREA_BOUNDS_007_COUNT];
    TownMapAreaBounds map_001[TOWN_MAP_AREA_BOUNDS_001_COUNT];
};

extern TownMapAreaBoundsTables const gTownMapAreaBounds;

enum
{
    TOWN_MAP_HOTSPOT_COUNT = 40,
    TOWN_MAP_AREA_LOOKUP_COUNT = 0x34,
};

struct TownMapAreaLookup
{
    TownMapMarkerPosition marker_position;
    TownMapAreaBounds const * bounds;
};

extern TownMapHotspot const gTownMapHotspots[TOWN_MAP_HOTSPOT_COUNT];
extern u16 const gTownMapResourceIds[];
extern TownMapAreaLookup const gTownMapAreaLookup[TOWN_MAP_AREA_LOOKUP_COUNT];
extern TownMapAreaLookup const gTownMapAreaLookupFallback_034To133;
extern TownMapAreaLookup const gTownMapAreaLookupFallback_134To233;

void CopyBgMap30x13(void const *, u32 map_block, u16 const * source);

void CopyBgMapRect(
    void const *,
    u32 map_block,
    u32 x,
    u32 y,
    u32 width,
    u32 height,
    u16 const * source);

bool TownMapHotspotContains(
    void const *, u32 cursor_x, u32 cursor_y, TownMapHotspot const * hotspot);

EXTERN_C_END

extern char const gText_TownMap_LibraryOpeningHours[];
extern char const gText_TownMap_PlayerFarmNameSuffix[];
extern char const gText_TownMap_PlayerFarmDescription[];
extern char const gText_TownMap_PlayerFarmLabel[];
extern char const gText_TownMap_MountainCottageLabel[];
extern char const gText_TownMap_SeasideCottageLabel[];
extern char const gText_TownMap_TownCottageLabel[];
extern char const gText_TownMap_TimeWindowSeasonDescription[];
extern char const gText_TownMap_TimeWindowDateDescription[];
extern char const gText_TownMap_TimeWindowDayDescription[];
extern char const gText_TownMap_TimeWindowTimeDescription[];
extern char const gText_TownMap_TimeWindowWeatherDescription[];
extern char const gText_TownMap_TimeWindowLabel[];
extern char const gText_TownMap_BasilHouseLabel[];
extern char const gText_TownMap_MaryLibraryDescription[];
extern char const gText_TownMap_MaryLibraryHours[];
extern char const gText_TownMap_EllenHouseLabel[];
extern char const gText_TownMap_MayorHouseLabel[];
extern char const gText_TownMap_SupermarketDescription[];
extern char const gText_TownMap_SupermarketHours[];
extern char const gText_TownMap_MineralClinicDescription[];
extern char const gText_TownMap_MineralClinicHours[];
extern char const gText_TownMap_ChurchDescription[];
extern char const gText_TownMap_ChurchHours[];
extern char const gText_TownMap_AjaWineryDescription[];
extern char const gText_TownMap_AjaWineryHours[];
extern char const gText_TownMap_DukeCellarLabel[];
extern char const gText_TownMap_DougsInnDescription[];
extern char const gText_TownMap_DougsInnHours[];
extern char const gText_TownMap_HarvestSpritesHomeDescription[];
extern char const gText_TownMap_HarvestSpritesHomeHours[];
extern char const gText_TownMap_ZackHouseDescription[];
extern char const gText_TownMap_ZackHouseLabel[];
extern char const gText_TownMap_KaiSeasideLodgeDescription[];
extern char const gText_TownMap_KaiSeasideLodgeHours[];
extern char const gText_TownMap_SaibaraBlacksmithDescription[];
extern char const gText_TownMap_SaibaraBlacksmithHours[];
extern char const gText_TownMap_YodelFarmDescription[];
extern char const gText_TownMap_YodelFarmHours[];
extern char const gText_TownMap_PoultryFarmDescription[];
extern char const gText_TownMap_PoultryFarmHours[];
extern char const gText_TownMap_WoodcutterHouseDescription[];
extern char const gText_TownMap_WoodcutterHouseHours[];
extern char const gText_TownMap_LakeMineDescription[];
extern char const gText_TownMap_LakeMineLabel[];
extern char const gText_TownMap_SpringMineDescription[];
extern char const gText_TownMap_SpringMineLabel[];
extern char const gText_TownMap_HotSpringDescription[];
extern char const gText_TownMap_HotSpringLabel[];
extern char const gText_TownMap_Empty[];
extern char const gText_TownMap_NorthMineralTownDescription[];
extern char const gText_TownMap_NorthMineralTownLabel[];
extern char const gText_TownMap_RearChurchDescription[];
extern char const gText_TownMap_RearChurchLabel[];
extern char const gText_TownMap_RoseSquareDescription[];
extern char const gText_TownMap_RoseSquareLabel[];
extern char const gText_TownMap_MineralBeachDescription[];
extern char const gText_TownMap_MineralBeachLabel[];
extern char const gText_TownMap_SouthMineralTownDescription[];
extern char const gText_TownMap_SouthMineralTownLabel[];
extern char const gText_TownMap_ForestDescription[];
extern char const gText_TownMap_ForestLabel[];
extern char const gText_TownMap_MothersHillPeakDescription[];
extern char const gText_TownMap_MothersHillPeakLabel[];
extern char const gText_TownMap_MothersHillDescription[];
extern char const gText_TownMap_MothersHillLabel[];

// Plain inline container helpers are not part of the virtual interface's
// explicitly emitted standalone methods.
#include "resource_handle.hh"

struct TownMapMarkerCountEntry {
    TownMapMarkerPosition position;
    u8 count;
};

struct TownMapMarkerNode : RedBlackTreeNode {
    TownMapMarkerCountEntry entry;
};

struct TownMapMarkerCounts {
    inline ~TownMapMarkerCounts();

    u32 unk_00;
    TownMapMarkerNode * header;
    u32 node_count;
    u32 unk_0C;
};

struct TownMapMarkerIterator {
    TownMapMarkerIterator() {}
    explicit TownMapMarkerIterator(TownMapMarkerNode * value) : node(value) {}
    TownMapMarkerIterator(TownMapMarkerIterator const & other) : node(other.node) {}
    TownMapMarkerNode * node;
};

inline bool operator==(TownMapMarkerIterator const & first, TownMapMarkerIterator const & second)
{
    return first.node == second.node;
}

struct TownMapMarkerInsertResult {
    TownMapMarkerInsertResult(TownMapMarkerIterator const & position, bool success)
        : iterator(position), inserted(success) {}
    TownMapMarkerIterator iterator;
    bool inserted;
};

struct TownMapMarker {
    TownMapMarker(i32 x, i32 y, IndexedResourceProvider * archive,
        u32 index, i32 scroll_delta)
        : x(x), y(y), resource(archive, index, scroll_delta) {}

    i32 x;
    i32 y;
    IndexedResourceHandle resource;
};

struct TownMapMarkers {
    inline ~TownMapMarkers();
    inline void PushBack(TownMapMarker const & value);

    TownMapMarker * first;
    TownMapMarker * last;
    u32 unk_08;
    TownMapMarker * capacity_end;
};


extern "C" void EraseTownMapMarkerNodes(TownMapMarkerCounts *, TownMapMarkerNode *);



#pragma interface "town_map.hh"
#include "scene.hh"
#include "actor.hh"
#include "hardware_context.hh"
#include "ui_state.hh"
#include "map_clock_status.hh"
#include "resource_sprite_renderer.hh"
#include "resource_handle.hh"
struct GameStateSaveImage;



#pragma interface "town_map.hh"
struct TownMapUiCore;

// The native UI owns its core and returns the result-bearing continuation.
// Its constructor and virtual methods are still supplied by native code.
struct TownMapUiScene : AScene {
    TownMapUiScene(GameStateSaveImage * image, SceneTransitionOwner next, bool allow_teleport);
    virtual ~TownMapUiScene();
    virtual SceneTransitionOwner Run();
    TownMapUiCore * core;
};

// Construction is inlined in the native TownMapUiScene constructor. The core
// destructor still owns the original native container/resource cleanup.
struct TownMapUiCore : HardwareContext {
    ~TownMapUiCore();

    GameStateSaveImage * save;
    SceneTransitionOwner continuation;
    u32 allow_teleport;
    u8 unk_14;
    UiStateOwner ui;
    MapClockStatusHudContent clock;
    ResourceSpriteRenderer renderer;
    IndexedResourceArchive cursor_archive;
    IndexedResourceGroupResult cursor_group;
    IndexedResourceHandle cursor;
    i32 cursor_x;
    i32 cursor_y;
    u32 current_hotspot;
    // Appends are capped at 127 bytes, leaving the C string terminator.
    char farm_description[128];
    char farm_label[128];
    u32 unk_198;
    IndexedResourceArchive marker_archive;
    TownMapMarkers markers;
    TownMapMarkerCounts marker_counts;
};


EXTERN_C

void FadeInTownMap(TownMapUiCore * core);
void FadeOutTownMap(TownMapUiCore * core);
void DrawTownMap(TownMapUiCore * core);
void UpdateTownMapUi(TownMapUiCore * core);

void AddTownMapMarker(TownMapUiCore * core, Location const * location, u32 resource_id);
void EraseTownMapMarkerNodes(TownMapMarkerCounts * counts, TownMapMarkerNode * node);
// The iterator copy constructor gives the native return-storage ABI.
TownMapMarkerIterator InsertTownMapMarkerNode(TownMapMarkerCounts * counts,
    TownMapMarkerNode * position, TownMapMarkerNode * parent,
    TownMapMarkerCountEntry const * entry, TownMapMarkerNode * right_hint);
TownMapMarkerInsertResult InsertTownMapMarkerCount(TownMapMarkerCounts * counts,
    TownMapMarkerCountEntry const * entry);
TownMapMarkerIterator * InsertTownMapMarkerCountWithHint(TownMapMarkerIterator * result,
    TownMapMarkerCounts * counts,
    TownMapMarkerIterator const * hint, TownMapMarkerCountEntry const * entry);

EXTERN_C_END


#include "town_map_transition.hh"


#endif // TOWN_MAP_HH
