#include "blacksmith_text.hh"

#include "item.hh"

// JP and US encode the tool-upgrade header differently.  Keep their native
// layouts rather than adding artificial data solely to make the arrays match.
#if defined(REGION_JP)
BlacksmithMenuHeader const gBlacksmithMenuHeader BLACKSMITH_CATALOG = {
    gText_Blacksmith_ToolUpgradeMenuLabel,
    0,
    0,
    gText_Blacksmith_ToolUpgradeTitle,
};
#endif

BlacksmithCatalogEntry const gBlacksmithCatalog[] BLACKSMITH_CATALOG = {
#if defined(REGION_US)
    { 0, gText_Blacksmith_ToolUpgradeMenuLabel, 0, 0, gText_Blacksmith_ToolUpgradeTitle },
#endif
    { TOOL_BRUSH, gText_Blacksmith_Empty, 800, 1, gText_Blacksmith_Empty },
    { TOOL_MILKER, gText_Blacksmith_Empty, 2000, 1, gText_Blacksmith_Empty },
    { TOOL_CLIPPER, gText_Blacksmith_Empty, 1800, 1, gText_Blacksmith_Empty },
    { 4, gText_Blacksmith_MakeMayonnaiseMaker, 20000, 3, gText_Blacksmith_CostAdamantite },
    { 5, gText_Blacksmith_MakeCheeseMaker, 20000, 3, gText_Blacksmith_CostAdamantite },
    { 6, gText_Blacksmith_MakeYarnMaker, 20000, 3, gText_Blacksmith_CostAdamantite },
    { ARTICLE_NECKLACE, gText_Blacksmith_MakeNecklace, 1000, 2, gText_Blacksmith_CostOrichalc },
    { ARTICLE_EARRINGS, gText_Blacksmith_MakeEarrings, 1000, 2, gText_Blacksmith_CostOrichalc },
    { ARTICLE_BRACELET, gText_Blacksmith_MakeBracelet, 1000, 2, gText_Blacksmith_CostOrichalc },
    { ARTICLE_BROACH, gText_Blacksmith_MakeBroach, 1000, 2, gText_Blacksmith_CostOrichalc },
};
