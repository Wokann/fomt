#ifndef BLACKSMITH_TEXT_HH
#define BLACKSMITH_TEXT_HH

#include "prelude.h"

// The original directory is eleven contiguous 20-byte entries.  Selection
// identifiers are interpreted by entry_kind: only kind 1 is passed to ToolUi;
// the maker codes 4–6 are intentionally retained as their original values.
struct BlacksmithCatalogEntry
{
    u32 selection_id;
    char const * menu_text;
    u32 price;
    u32 entry_kind;
    char const * detail_text;
};

// JP stores its initial menu label as a distinct four-word header before the
// ten catalog entries.  US instead encodes the same data as catalog entry 0.
struct BlacksmithMenuHeader
{
    char const * menu_text;
    u32 unknown_04;
    u32 unknown_08;
    char const * title_text;
};

#define BLACKSMITH_MENU SECTION(".rodata.blacksmith_menu")
#define BLACKSMITH_CATALOG SECTION(".rodata.blacksmith_catalog")
#define BLACKSMITH_DIALOGUE SECTION(".rodata.blacksmith_dialogue")

extern char const gText_Blacksmith_ToolUpgradeMenuLabel[];
extern char const gText_Blacksmith_ToolUpgradeTitle[];
extern char const gText_Blacksmith_Empty[];
extern char const gText_Blacksmith_MakeMayonnaiseMaker[];
extern char const gText_Blacksmith_CostAdamantite[];
extern char const gText_Blacksmith_MakeCheeseMaker[];
extern char const gText_Blacksmith_MakeYarnMaker[];
extern char const gText_Blacksmith_MakeNecklace[];
extern char const gText_Blacksmith_CostOrichalc[];
extern char const gText_Blacksmith_MakeEarrings[];
extern char const gText_Blacksmith_MakeBracelet[];
extern char const gText_Blacksmith_MakeBroach[];

extern char const gText_Blacksmith_InsufficientGoldAdamantite[];
extern char const gText_Blacksmith_InsufficientGoldOrichalc[];
extern char const gText_Blacksmith_MakerFiveDays[];
extern char const gText_Blacksmith_MakerOneDay[];
extern char const gText_Blacksmith_InsufficientOreAdamantite[];
extern char const gText_Blacksmith_InsufficientOreOrichalc[];
extern char const gText_Blacksmith_SelectToolAndOre[];
extern char const gText_Blacksmith_InsufficientGold[];
extern char const gText_Blacksmith_EquipmentFull[];
extern char const gText_Blacksmith_NeedAnythingElse[];
extern char const gText_Blacksmith_NothingElse[];
extern char const gText_Blacksmith_PurchaseComplete[];
extern char const gText_Blacksmith_Delivery[];
extern char const gText_Blacksmith_PurchaseMore[];
extern char const gText_Blacksmith_MakeIt[];
extern char const gText_Blacksmith_DontMakeIt[];
extern char const gText_Blacksmith_StartWork[];
extern char const gText_Blacksmith_CannotChangeMind[];
extern char const gText_Blacksmith_NoToolToUpgrade[];
extern char const gText_Blacksmith_NoOreToUpgrade[];

#if defined(REGION_JP)
extern BlacksmithMenuHeader const gBlacksmithMenuHeader;
#endif
extern BlacksmithCatalogEntry const gBlacksmithCatalog[];

#endif // BLACKSMITH_TEXT_HH
