#include "blacksmith_data.hh"

#include "item.hh"

// Menu labels precede the catalog in the original ROM.
#include FOMT_TEXT_INCLUDE(blacksmith_data_1.cc)

BlacksmithCatalogEntry const gBlacksmithCatalog[] = {
    { 0, gText_Blacksmith_ToolUpgradeMenuLabel, 0, 0, gText_Blacksmith_ToolUpgradeTitle },
    { ITEM_TOOL_BRUSH, gText_Blacksmith_Empty, 800, 1, gText_Blacksmith_Empty },
    { ITEM_TOOL_MILKER, gText_Blacksmith_Empty, 2000, 1, gText_Blacksmith_Empty },
    { ITEM_TOOL_CLIPPER_OR_CLIPPERS, gText_Blacksmith_Empty, 1800, 1, gText_Blacksmith_Empty },
    { 4, gText_Blacksmith_MakeMayonnaiseMaker, 20000, 3, gText_Blacksmith_CostAdamantite },
    { 5, gText_Blacksmith_MakeCheeseMaker, 20000, 3, gText_Blacksmith_CostAdamantite },
    { 6, gText_Blacksmith_MakeYarnMaker, 20000, 3, gText_Blacksmith_CostAdamantite },
    { ITEM_ARTICLE_NECKLACE, gText_Blacksmith_MakeNecklace, 1000, 2, gText_Blacksmith_CostOrichalc },
    { ITEM_ARTICLE_EARRINGS, gText_Blacksmith_MakeEarrings, 1000, 2, gText_Blacksmith_CostOrichalc },
    { ITEM_ARTICLE_BRACELET, gText_Blacksmith_MakeBracelet, 1000, 2, gText_Blacksmith_CostOrichalc },
    { ITEM_ARTICLE_BROOCH, gText_Blacksmith_MakeBroach, 1000, 2, gText_Blacksmith_CostOrichalc },
};

#include FOMT_TEXT_INCLUDE(blacksmith_data_2.cc)
