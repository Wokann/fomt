#ifndef RECORDS_SCREEN_HH
#define RECORDS_SCREEN_HH

#include "prelude.h"
#include "utility/container_algorithms.hh"

#include "scene.hh"
#include "scroll_menu.hh"
#include "harvest_sprite.hh"
#include "utility/fixed_str.hh"

struct GameStateSaveImage;

// These fixed-capacity records are RAM rendering state, not ROM strings.
// The native constructor initializes 120 rows; a negative Y ends the used run.
struct RecordsScreenTextRow {
    RecordsScreenTextRow() : y(-1), text(), buffer_index(0), rendered(false) {}

    i16 y : 16;
    FixedStr<31> text;
    u32 buffer_index;
    bool rendered;
};

struct RecordsScreenTextTileBuffer {
    RecordsScreenTextTileBuffer() {}
    u32 unk_00;
    u8 tiles[20 * 2 * 32];
};

struct RecordsScreenPageEntry {
    RecordsScreenPageEntry() : page(0), scroll_position(0) {}
    u32 page;
    i16 scroll_position;
};

// The native constructor adds only the active pages. Unused capacity is not
// part of their lifetime; the original destructor visits count entries.
struct RecordsScreenPageList {
    enum { CAPACITY = 10 };
    RecordsScreenPageList() : count(0) {}

    u32 count;
    u8 storage[CAPACITY * sizeof(RecordsScreenPageEntry)];
    RecordsScreenPageEntry * Data()
    {
        return reinterpret_cast<RecordsScreenPageEntry *>(storage);
    }
    RecordsScreenPageEntry & operator[](u32 index)
    {
        return *reinterpret_cast<RecordsScreenPageEntry *>(reinterpret_cast<u8 *>(this)
            + (sizeof(count) + index * sizeof(RecordsScreenPageEntry)));
    }
    RecordsScreenPageEntry * End()
    {
        return reinterpret_cast<RecordsScreenPageEntry *>(storage + count * sizeof(RecordsScreenPageEntry));
    }
    void Push(RecordsScreenPageEntry const & entry);
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
    SceneCoreOwner<RecordsScreenCore> core;
    SceneTransitionOwner continuation;
};

struct RecordsScreenCore : ScrollMenu {
    enum Page {
        PAGE_SHIPPING = 0,
        PAGE_FISHING = 1,
        PAGE_OTHER = 2,
    };

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

    u32 GetBestMinigameSprite(HarvestSprite::Task task) const;

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
#elif defined(REGION_US) || defined(REGION_EU)
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
#elif defined(REGION_US) || defined(REGION_EU)
    u8 unk_4278[0x8E6C - 0x4278];
#endif
};


#include "status_screen_transitions.hh"


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
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
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
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_Records_MineDepthPadding[];
#endif

#endif // RECORDS_SCREEN_HH
