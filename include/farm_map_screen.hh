#ifndef FARM_MAP_SCREEN_HH
#define FARM_MAP_SCREEN_HH

#include "prelude.h"
#include <stdlib.h>

#include "scene.hh"
#include "hardware_context.hh"
#include "resource_handle.hh"
#include "resource_sprite_renderer.hh"

struct GameStateSaveImage;
// Marker coordinates are map pixels. Each entry carries its own borrowed
// resource handle, while the list owns the 28-byte entry allocation.
struct FarmMapScreenMarker
{
    i32 x;
    i32 y;
    IndexedResourceHandle resource;
};

struct FarmMapScreenMarkers
{
    FarmMapScreenMarkers() : first(nullptr), last(nullptr), capacity_end(nullptr) {}
    ~FarmMapScreenMarkers()
    {
        for (FarmMapScreenMarker * marker = first; marker != last; ++marker)
            marker->~FarmMapScreenMarker();
        if (first != nullptr)
            free(first);
    }

    FarmMapScreenMarker * first;
    FarmMapScreenMarker * last;
    u32 unk_08;
    FarmMapScreenMarker * capacity_end;
};

struct FarmMapScreenIndoorMarkerRow
{
    FarmMapScreenIndoorMarkerRow() : first(nullptr), last(nullptr), capacity_end(nullptr) {}
    ~FarmMapScreenIndoorMarkerRow()
    {
        if (first != nullptr)
            free(first);
    }

    u32 * first;
    u32 * last;
    u32 unk_08;
    u32 * capacity_end;
};

#pragma interface "farm_map_screen.hh"
struct FarmMapScreenIndoorMarkers
{
    FarmMapScreenIndoorMarkers() {}
    ~FarmMapScreenIndoorMarkers();
    // Three independently constructed rows; cleanup releases them in reverse order.
    FarmMapScreenIndoorMarkerRow row_00;
    FarmMapScreenIndoorMarkerRow row_10;
    FarmMapScreenIndoorMarkerRow row_20;
};
#pragma interface "farm_map_screen.hh"

struct FarmMapScreenCore;

struct FarmMapScreenScene : AScene
{
    FarmMapScreenScene(GameStateSaveImage * image, SceneTransitionOwner next);
    virtual ~FarmMapScreenScene();
    virtual SceneTransitionOwner Run();
    FarmMapScreenCore * core;
};

struct FarmMapScreenCore : HardwareContext
{
    inline FarmMapScreenCore(GameStateSaveImage * image, SceneTransitionOwner next);
    virtual ~FarmMapScreenCore();
    void FadeIn();
    void FadeOut();
    void LoadTilemap(u32 screen_block, u8 const * compressed_tilemap);
    void CopyTilemapRect(u32 screen_block, u32 x, u32 y,
        u32 width, u32 height, u16 const * tilemap);
    void LoadGraphics();
    void ScrollAndDrawArrows(i32 dx, i32 dy);
    void AddLocationMarker(u32 map, i32 x, i32 y, u32 resource_entry);
    void AddIndoorMarkers(u32 building);
    void SetTilemapPalette(u32 screen_block, u32 x, u32 y,
        u32 width, u32 height, u32 palette);
    void RenderMarkers();

    GameStateSaveImage * save;
    SceneTransitionOwner continuation;
    i32 scroll_y;
    i32 scroll_x;
    ResourceSpriteRenderer renderer;
    IndexedResourceArchive arrow_archive;
    IndexedResourceHandle up_arrow;
    IndexedResourceHandle down_arrow;
    IndexedResourceHandle right_arrow;
    IndexedResourceHandle left_arrow;
    IndexedResourceArchive marker_archive;
    FarmMapScreenMarkers markers;
    // Farmhouse, chicken coop, barn, then horse stable; see AddLocationMarker.
    FarmMapScreenIndoorMarkers indoor_markers[4];
};

typedef char FarmMapScreenMarkerSizeCheck[sizeof(FarmMapScreenMarker) == 28 ? 1 : -1];
typedef char FarmMapScreenMarkersSizeCheck[sizeof(FarmMapScreenMarkers) == 16 ? 1 : -1];
typedef char FarmMapScreenIndoorMarkerRowSizeCheck[sizeof(FarmMapScreenIndoorMarkerRow) == 16 ? 1 : -1];
typedef char FarmMapScreenIndoorMarkersSecondRowCheck[offsetof(FarmMapScreenIndoorMarkers, row_10) == 0x10 ? 1 : -1];
typedef char FarmMapScreenIndoorMarkersThirdRowCheck[offsetof(FarmMapScreenIndoorMarkers, row_20) == 0x20 ? 1 : -1];
typedef char FarmMapScreenIndoorMarkersSizeCheck[sizeof(FarmMapScreenIndoorMarkers) == 48 ? 1 : -1];
typedef char FarmMapScreenCoreRendererCheck[offsetof(FarmMapScreenCore, renderer) == 0x18 ? 1 : -1];
typedef char FarmMapScreenCoreArrowArchiveCheck[offsetof(FarmMapScreenCore, arrow_archive) == 0x20 ? 1 : -1];
typedef char FarmMapScreenCoreMarkerArchiveCheck[offsetof(FarmMapScreenCore, marker_archive) == 0xA0 ? 1 : -1];
typedef char FarmMapScreenCoreMarkersCheck[offsetof(FarmMapScreenCore, markers) == 0xD0 ? 1 : -1];
typedef char FarmMapScreenCoreIndoorMarkersCheck[offsetof(FarmMapScreenCore, indoor_markers) == 0xE0 ? 1 : -1];
typedef char FarmMapScreenCoreSizeCheck[sizeof(FarmMapScreenCore) == 0x1A0 ? 1 : -1];

// The scene owns the complete map core; its native construction is inlined
// into this scene constructor in all four regional ROMs.

#include "status_screen_transitions.hh"

typedef char FarmMapScreenSceneSizeCheck[sizeof(FarmMapScreenScene) == 8 ? 1 : -1];

struct FarmMapScreenIndoorMarkerOrigin
{
    u16 x;
    u16 y;
};

struct FarmMapScreenBuildingPreview
{
    u8 const *primary_tilemap;
    u8 const *alternate_tilemap;
    u16 x;
    u16 y;
    u8 width;
    u8 height;
    u16 unused;
};

struct FarmMapScreenExteriorStyleData
{
    u8 doghouse[3];
    u8 mailbox[3][3];
};

extern u8 const gUnk_08527094[];
#if defined(REGION_JP)
extern u8 const gUnk_084D977C[];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern u8 const gUnk_087537D0[];
#endif

#if defined(REGION_JP)
extern u8 const gUnk_082AFC74[];
extern u8 const gUnk_082AFCD4[];
extern u8 const gUnk_082AFDC8[];
extern u8 const gUnk_082AFE70[];
extern u8 const gUnk_082AFED0[];
extern u8 const gUnk_082B0744[];
extern u8 const gUnk_082B07E0[];
extern u8 const gUnk_082B2F20[];
extern u8 const gUnk_082B2F80[];
extern u8 const gUnk_082B3074[];
extern u8 const gUnk_082B311C[];
extern u8 const gUnk_082B317C[];
extern u8 const gUnk_082B39F0[];
extern u8 const gUnk_082B3A8C[];
#elif defined(REGION_DE)
extern u8 const gUnk_082B0BB4[];
extern u8 const gUnk_082B0C14[];
extern u8 const gUnk_082B0D08[];
extern u8 const gUnk_082B0DB0[];
extern u8 const gUnk_082B0E10[];
extern u8 const gUnk_082B1684[];
extern u8 const gUnk_082B1720[];
extern u8 const gUnk_082B3E60[];
extern u8 const gUnk_082B3EC0[];
extern u8 const gUnk_082B3FB4[];
extern u8 const gUnk_082B405C[];
extern u8 const gUnk_082B40BC[];
extern u8 const gUnk_082B4930[];
extern u8 const gUnk_082B49CC[];
#elif defined(REGION_US) || defined(REGION_EU)
extern u8 const gUnk_08529B18[];
extern u8 const gUnk_08529B78[];
extern u8 const gUnk_08529C6C[];
extern u8 const gUnk_08529D14[];
extern u8 const gUnk_08529D74[];
extern u8 const gUnk_0852A5E8[];
extern u8 const gUnk_0852A684[];
extern u8 const gUnk_0852CDC4[];
extern u8 const gUnk_0852CE24[];
extern u8 const gUnk_0852CF18[];
extern u8 const gUnk_0852CFC0[];
extern u8 const gUnk_0852D020[];
extern u8 const gUnk_0852D894[];
extern u8 const gUnk_0852D930[];
#endif

extern FarmMapScreenIndoorMarkerOrigin const gFarmMapScreenIndoorMarkerOrigins[];
extern u16 const gFarmMapScreenTileLookup[];
extern FarmMapScreenBuildingPreview const gFarmMapScreenFarmHousePreviews[];
extern FarmMapScreenBuildingPreview const gFarmMapScreenCoopPreviews[];
extern FarmMapScreenBuildingPreview const gFarmMapScreenBarnPreviews[];
extern FarmMapScreenExteriorStyleData const gFarmMapScreenExteriorStyleData;

#endif // FARM_MAP_SCREEN_HH
