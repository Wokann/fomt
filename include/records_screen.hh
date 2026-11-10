#ifndef RECORDS_SCREEN_HH
#define RECORDS_SCREEN_HH

#include "prelude.h"
#include "utility/container_algorithms.hh"

#include "scene.hh"
#include "scroll_menu.hh"

struct GameStateSaveImage;

// These fixed-capacity records are RAM rendering state, not ROM strings.
// The native constructor initializes 120 rows; a negative Y ends the used run.
struct RecordsScreenTextRow {
    i16 y;
    char text[32] ALIGN(4);
    u32 buffer_index;
    bool rendered;
};

struct RecordsScreenTextTileBuffer {
    u32 unk_00;
    u8 tiles[20 * 2 * 32];
};

struct RecordsScreenPageEntry {
    u32 page;
    i16 scroll_position;
};

// The native constructor adds only the active pages. Unused capacity is not
// part of their lifetime; the original destructor visits count entries.
struct RecordsScreenPageList {
    u32 count;
    u8 storage[10 * sizeof(RecordsScreenPageEntry)];
    RecordsScreenPageEntry * Data()
    {
        return reinterpret_cast<RecordsScreenPageEntry *>(storage);
    }
    RecordsScreenPageEntry * End()
    {
        return reinterpret_cast<RecordsScreenPageEntry *>(storage + count * sizeof(RecordsScreenPageEntry));
    }
    ~RecordsScreenPageList()
    {
        destroy_ptrs(Data(), End());
    }
};

#pragma interface "records_screen.hh"

struct RecordsScreenCore;

struct RecordsScreenScene : AScene
{
    RecordsScreenScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~RecordsScreenScene();
    virtual SceneTransitionOwner Run();
    RecordsScreenCore * core;
    SceneTransitionOwner continuation;
};

struct RecordsScreenCore : ScrollMenu {
    RecordsScreenCore(GameStateSaveImage * image);
    virtual void ChangePage(i32 direction);
    void SelectPage(u32 page);

    GameStateSaveImage * save;
    RecordsScreenPageList pages;
    u32 selected_page;
};

struct RecordsScreenPage : ScrollMenuPage {
    RecordsScreenPage(ScrollMenu * menu, GameStateSaveImage * image,
        u32 rows, char const * title);
    virtual ~RecordsScreenPage();
    virtual u32 Draw();

    RecordsScreenTextRow text_rows[120];
    RecordsScreenTextTileBuffer text_buffers[8];
};

struct ShippingRecordsPage : RecordsScreenPage {
    ShippingRecordsPage(ScrollMenu * menu, GameStateSaveImage * image);
    virtual u32 Draw();

    u32 unk_4278;
    u8 shipped_count_suffix_tiles[2 * 2 * 32];
};

// These regional RAM extents come from the actual page allocations. The
// remaining per-label tile buffers have not yet been assigned field names.
struct FishingRecordsPage : RecordsScreenPage {
    FishingRecordsPage(ScrollMenu * menu, GameStateSaveImage * image);
    virtual u32 Draw();
#if defined(REGION_JP)
    u8 unk_4278[0x4994 - 0x4278];
#elif defined(REGION_DE)
    u8 unk_4278[0x4D14 - 0x4278];
#else
    u8 unk_4278[0x4B94 - 0x4278];
#endif
};

struct OtherRecordsPage : RecordsScreenPage {
    OtherRecordsPage(ScrollMenu * menu, GameStateSaveImage * image);
    virtual u32 Draw();
    void DrawAnimalLifetime(u32 days, u32 row);
#if defined(REGION_JP)
    u8 unk_4278[0x816C - 0x4278];
#elif defined(REGION_DE)
    u8 unk_4278[0x8FEC - 0x4278];
#else
    u8 unk_4278[0x8E6C - 0x4278];
#endif
};

typedef char RecordsScreenTextRowSizeCheck[sizeof(RecordsScreenTextRow) == 44 ? 1 : -1];
typedef char RecordsScreenTextRowTextCheck[offsetof(RecordsScreenTextRow, text) == 4 ? 1 : -1];
typedef char RecordsScreenTextTileBufferSizeCheck[sizeof(RecordsScreenTextTileBuffer) == 0x504 ? 1 : -1];
typedef char RecordsScreenPageRowsCheck[offsetof(RecordsScreenPage, text_rows) == 0x5B8 ? 1 : -1];
typedef char RecordsScreenPageBuffersCheck[offsetof(RecordsScreenPage, text_buffers) == 0x1A58 ? 1 : -1];
typedef char RecordsScreenPageSizeCheck[sizeof(RecordsScreenPage) == 0x4278 ? 1 : -1];
typedef char ShippingRecordsPageSizeCheck[sizeof(ShippingRecordsPage) == 0x42FC ? 1 : -1];
typedef char RecordsScreenPageEntrySizeCheck[sizeof(RecordsScreenPageEntry) == 8 ? 1 : -1];
typedef char RecordsScreenPageListSizeCheck[sizeof(RecordsScreenPageList) == 0x54 ? 1 : -1];
typedef char RecordsScreenCorePageCountCheck[offsetof(RecordsScreenCore, pages) == 0x124 ? 1 : -1];
typedef char RecordsScreenCorePagesCheck[offsetof(RecordsScreenCore, pages) + offsetof(RecordsScreenPageList, storage) == 0x128 ? 1 : -1];
typedef char RecordsScreenCoreSelectedCheck[offsetof(RecordsScreenCore, selected_page) == 0x178 ? 1 : -1];
typedef char RecordsScreenCoreSizeCheck[sizeof(RecordsScreenCore) == 0x17C ? 1 : -1];

#include "status_screen_transitions.hh"

typedef char RecordsScreenSceneSizeCheck[sizeof(RecordsScreenScene) == 12 ? 1 : -1];

struct RecordsScreenTaskResourcePair
{
    u8 const *tiles;
    u8 const *palette;
};

#if defined(REGION_JP)
extern u8 const gUnk_084D7EB8[];
extern u8 const gUnk_084D7F38[];
extern u8 const gUnk_084D7F58[];
extern u8 const gUnk_084D7FD8[];
extern u8 const gUnk_084D7FF8[];
extern u8 const gUnk_084D8078[];
extern u8 const gUnk_084D8098[];
extern u8 const gUnk_084D8118[];
extern u8 const gUnk_084D8138[];
extern u8 const gUnk_084D81B8[];
extern u8 const gUnk_084D81D8[];
extern u8 const gUnk_084D8258[];
extern u8 const gUnk_084D8278[];
extern u8 const gUnk_084D82F8[];
#else
extern u8 const gUnk_08751F0C[];
extern u8 const gUnk_08751F8C[];
extern u8 const gUnk_08751FAC[];
extern u8 const gUnk_0875202C[];
extern u8 const gUnk_0875204C[];
extern u8 const gUnk_087520CC[];
extern u8 const gUnk_087520EC[];
extern u8 const gUnk_0875216C[];
extern u8 const gUnk_0875218C[];
extern u8 const gUnk_0875220C[];
extern u8 const gUnk_0875222C[];
extern u8 const gUnk_087522AC[];
extern u8 const gUnk_087522CC[];
extern u8 const gUnk_0875234C[];
#endif

extern RecordsScreenTaskResourcePair const gRecordsScreenMinigameTaskResources[];

extern char const gText_Records_NumberShipped[];
extern char const gText_Records_ShippedCountSuffix[];
extern char const gText_Records_Fishing[];
extern char const gText_Records_Name[];
extern char const gText_Records_MaximumSize[];
extern char const gText_Records_Results[];
extern char const gText_Records_FishUnit[];
extern char const gText_Records_MeterUnit[];
extern char const gText_Records_CentimeterUnit[];
extern char const gText_Records_Separator[];
extern char const gText_Records_Other[];
extern char const gText_Records_MiniGameRecords[];
extern char const gText_Records_Harvest[];
extern char const gText_Records_AnimalHusbandry[];
extern char const gText_Records_Watering[];
extern char const gText_Records_Frisbee[];
extern char const gText_Records_SecondsUnit[];
extern char const gText_Records_IncomeExpenses[];
extern char const gText_Records_HighestAmount[];
extern char const gText_Records_Earned[];
extern char const gText_Records_Used[];
extern char const gText_Records_GoldUnit[];
extern char const gText_Records_LongestLivingAnimal[];
extern char const gText_Records_Chicken[];
extern char const gText_Records_Cow[];
extern char const gText_Records_Sheep[];
extern char const gText_Records_YearsUnit[];
extern char const gText_Records_MonthsUnit[];
extern char const gText_Records_DaysUnit[];
extern char const gText_Records_MineDepth[];
extern char const gText_Records_BelowGround[];
extern char const gText_Records_MolesWhacked[];

#if defined(REGION_JP)
extern char const gText_Records_FloorUnit[];
#else
extern char const gText_Records_MineDepthPadding[];
#endif

#endif // RECORDS_SCREEN_HH
