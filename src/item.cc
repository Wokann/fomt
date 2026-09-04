#include "item.hh"
#include "item_text.hh"

struct FoodInfo
{
    /* +00 */ char const * name;
    /* +04 */ bool is_drink : 1;
    /* +05 */ i8 stamina;
    /* +06 */ i8 fatigue;
    /* +08 */ u16 icon_id;
    /* +0C */ char const * desc;
};

extern FoodInfo const gFoodInfo[];

struct ArticleInfo
{
    /* +00 */ char const * name;
    /* +04 */ u16 icon_id;
    /* +08 */ char const * desc;
};

extern ArticleInfo const gArticleInfo[];

struct ProductInfo
{
    enum Kind
    {
        KIND_FOOD,
        KIND_ARTICLE,
    };

    /* +00 */ u32 price : 15;
    /* +01 */ u32 kind : 1;
    /* +02 */ u32 item : 8;
};

extern ProductInfo const gProductInfo[];

struct ToolInfo
{
    /* +00 */ char const * name;
    /* +04 */ u16 icon_id;
    /* +08 */ char const * desc;
};

extern ToolInfo const gToolInfo[];

static inline bool IsValidFoodId(u8 id)
{
    return id < NUM_FOODS;
}

static inline bool IsValidArticleId(u8 id)
{
    return id < NUM_ARTICLES;
}

static inline bool IsValidProductId(u8 id)
{
    return id < NUM_PRODUCTS;
}

static inline bool IsValidToolId(u8 id)
{
    return id < NUM_TOOLS;
}

Tool::Tool(u32 a_id)
{
    id = a_id;
}

int Tool::GetId() const
{
    return id;
}

template <typename T>
static inline T const & FomtMin(T const & left, T const & right)
{
    return right < left ? right : left;
}

#if defined(REGION_JP)
extern char const gBrokenToolName[];
extern char const gNoExplanation[];
extern char const gBrokenFoodName[];
extern char const gBrokenArticleName[];
extern char const gBrokenShipmentName[];
#else
#include <algorithm>

static char const gBrokenToolName[] = "Broken Tool";
#endif

char const * Tool::GetName() const
{
    if (IsValidToolId(id))
        return gToolInfo[id].name;

    return gBrokenToolName;
}

u16 Tool::GetIconId() const
{
    if (IsValidToolId(id))
        return gToolInfo[id].icon_id;

    // TODO: icon id constants
    return 457; // Turnip
}

#if !defined(REGION_JP)
static char const gNoExplanation[] = "No Explanation";
#endif

static inline char const * GetToolDescById(u32 id)
{
    if (gToolInfo[id].desc != nullptr)
        return gToolInfo[id].desc;

    return gNoExplanation;
}

char const * Tool::GetDesc() const
{
    if (IsValidToolId(id))
        return GetToolDescById(id);

    return gNoExplanation;
}

ToolStack::ToolStack()
    : Tool(TOOL_NONE)
{
    amount = 0;
}

ToolStack::ToolStack(Tool kind, u32 a_amount)
    : Tool(kind)
{
    if (a_amount != 0)
    {
        // ugh
        amount = *(u8 *)&FomtMin<u32>(MAX_AMOUNT, a_amount);
    }
    else
    {
        amount = 1;
    }
}

Tool ToolStack::GetTool() const
{
    if (amount != 0)
        return *this;

    return Tool(TOOL_NONE);
}

bool ToolStack::IsEmpty() const
{
    return amount == 0;
}

u32 ToolStack::GetAmount() const
{
    if (amount != 0)
        return amount;

    return 0;
}

void ToolStack::AddAmount(u32 a_amount)
{
    if (amount != 0)
    {
        amount = FomtMin<u32>(MAX_AMOUNT, amount + a_amount);
    }
}

void ToolStack::SubtractAmount(u32 a_amount)
{
    if (amount != 0)
    {
        if (amount <= a_amount)
            amount = 0;
        else
            amount -= a_amount;
    }
}

Food::Food(u32 a_id)
{
    id = a_id;
    stamina_bonus = 0;
    fatigue_bonus = 0;
}

int Food::GetId() const
{
    return id;
}

#if !defined(REGION_JP)
static char const gBrokenFoodName[] = "Broken Food";
#endif

char const * Food::GetName() const
{
    if (IsValidFoodId(id))
        return gFoodInfo[id].name;

    return gBrokenFoodName;
}

u16 Food::GetIconId() const
{
    if (IsValidFoodId(id))
        return gFoodInfo[id].icon_id;

    // TODO: icon id constants
    return 428; // Stones
}

int Food::GetStaminaGain() const
{
    if (IsValidFoodId(id))
        return gFoodInfo[id].stamina + stamina_bonus;

    return -100;
}

int Food::GetFatigueGain() const
{
    if (IsValidFoodId(id))
        return gFoodInfo[id].fatigue + fatigue_bonus;

    return +100;
}

int Food::GetStaminaBonus() const
{
    if (IsValidFoodId(id))
        return stamina_bonus;

    return -100;
}

int Food::GetFatigueBonus() const
{
    if (IsValidFoodId(id))
        return fatigue_bonus;

    return +100;
}

asm(".align 2, 0");

bool Food::IsDrink() const
{
    if (IsValidFoodId(id))
        return gFoodInfo[id].is_drink;

    return false;
}

static inline char const * GetFoodDescById(u32 id)
{
    if (gFoodInfo[id].desc != nullptr)
        return gFoodInfo[id].desc;

    return gNoExplanation;
}

char const * Food::GetDesc() const
{
    if (IsValidFoodId(id))
        return GetFoodDescById(id);

    return gNoExplanation;
}

void Food::AddBonuses(i8 stamina_amount, i8 fatigue_amount)
{
    int total;

    if (IsValidFoodId(id))
    {
        total = stamina_bonus + stamina_amount;

        if (total < -128)
            total = -128;
        else if (total > 127)
            total = 127;

        stamina_bonus = total;

        total = fatigue_bonus + fatigue_amount;

        if (total < -128)
            total = -128;
        else if (total > 127)
            total = 127;

        fatigue_bonus = total;
    }
}

FoodStack::FoodStack()
    : Food(FOOD_NONE)
{
    amount = 0;
}

asm(".align 2, 0");

FoodStack::FoodStack(Food food, u32 a_amount)
    : Food(food)
{
    if (a_amount != 0)
    {
        // ugh
        amount = *(u8 *)&FomtMin<u32>(MAX_AMOUNT, a_amount);
    }
    else
    {
        amount = 1;
    }
}

Food FoodStack::GetFood() const
{
    if (amount > 0)
        return *this;

    return Food(FOOD_NONE);
}

bool FoodStack::IsEmpty() const
{
    return amount == 0;
}

u32 FoodStack::GetAmount() const
{
    if (amount > 0)
        return amount;

    return 0;
}

void FoodStack::AddAmount(u32 a_amount)
{
    if (amount != 0)
    {
        amount = FomtMin<u32>(MAX_AMOUNT, amount + a_amount);
    }
}

void FoodStack::SubtractAmount(u32 a_amount)
{
    if (amount != 0)
    {
        if (amount <= a_amount)
            amount = 0;
        else
            amount -= a_amount;
    }
}

asm(".align 2, 0");

Article::Article(u32 a_id)
{
    id = a_id;
}

int Article::GetId() const
{
    return id;
}

#if !defined(REGION_JP)
static char const gBrokenArticleName[] = "Broken Article";
#endif

char const * Article::GetName() const
{
    if (IsValidArticleId(id))
        return gArticleInfo[id].name;

    return gBrokenArticleName;
}

u16 Article::GetIconId() const
{
    if (IsValidArticleId(id))
        return gArticleInfo[id].icon_id;

    return 457; // Turnip
}

bool Article::CanBeDiscarded() const
{
    switch (id)
    {
        default:
            return true;

        case ARTICLE_HARVEST_GODDESS_JEWEL:
        case ARTICLE_KAPPA_JEWEL:
        case ARTICLE_JEWEL_OF_TRUTH:
        case ARTICLE_KARENS_WINE:
        case ARTICLE_POPURIS_MUD_BALL:
        case ARTICLE_ANNS_MUSIC_BOX:
        case ARTICLE_MARYS_GREAT_BOOK:
        case ARTICLE_ELLIS_PRESSED_FLOWER:
        case ARTICLE_FRISBEE:
            return false;
    }
}

static inline char const * GetArticleDescById(u32 id)
{
    if (gArticleInfo[id].desc != nullptr)
        return gArticleInfo[id].desc;

    return gNoExplanation;
}

char const * Article::GetDesc() const
{
    if (IsValidArticleId(id))
        return GetArticleDescById(id);

    return gNoExplanation;
}

ArticleStack::ArticleStack()
    : Article(ARTICLE_NONE)
{
    amount = 0;
}

ArticleStack::ArticleStack(Article article, u32 a_amount)
    : Article(article)
{
    if (a_amount != 0)
    {
        // ugh
        amount = *(u8 *)&FomtMin<u32>(MAX_AMOUNT, a_amount);
    }
    else
    {
        amount = 1;
    }
}

Article ArticleStack::GetArticle() const
{
    if (amount != 0)
        return *this;

    return Article(ARTICLE_NONE);
}

bool ArticleStack::IsEmpty() const
{
    return amount == 0;
}

u32 ArticleStack::GetAmount() const
{
    if (amount != 0)
        return amount;

    return 0;
}

void ArticleStack::AddAmount(u32 a_amount)
{
    if (amount != 0)
    {
        amount = FomtMin<u32>(MAX_AMOUNT, amount + a_amount);
    }
}

void ArticleStack::SubtractAmount(u32 a_amount)
{
    if (amount != 0)
    {
        if (amount <= a_amount)
            amount = 0;
        else
            amount -= a_amount;
    }
}

Product::Product()
{
    id = PRODUCT_NONE;
}

Product::Product(u32 a_id)
{
    id = a_id;
}

Product::Product(Food food)
{
    id = PRODUCT_NONE;

    u32 food_id = food.GetId();

    for (int i = 0; i < PRODUCT_NONE; i++)
    {
        ProductInfo const * info = gProductInfo + i;

        if (info->kind == ProductInfo::KIND_FOOD && info->item == food_id)
        {
            id = i;
            break;
        }
    }
}

Product::Product(Article article)
{
    id = PRODUCT_NONE;

    u32 article_id = article.GetId();

    for (int i = 0; i < PRODUCT_NONE; ++i)
    {
        ProductInfo const * info = gProductInfo + i;

        if (info->kind == ProductInfo::KIND_ARTICLE && info->item == article_id)
        {
            id = i;
            break;
        }
    }
}

int Product::GetId() const
{
    return id;
}

u32 Product::GetPrice() const
{
    if (IsValidProductId(id))
        return gProductInfo[id].price;

    return 0;
}

#if !defined(REGION_JP)
static char const gBrokenShipmentName[] = "Broken Shipment";
#endif

char const * Product::GetName() const
{
    if (IsValidProductId(id))
    {
        ProductInfo const * info = gProductInfo + id;

        if (info->kind == ProductInfo::KIND_FOOD)
        {
            return Food(info->item).GetName();
        }
        else
        {
            return Article(info->item).GetName();
        }
    }

    return gBrokenShipmentName;
}

u16 Product::GetIconId() const
{
    if (IsValidProductId(id))
    {
        ProductInfo const * info = gProductInfo + id;

        if (info->kind == ProductInfo::KIND_FOOD)
        {
            return Food(info->item).GetIconId();
        }
        else
        {
            return Article(info->item).GetIconId();
        }
    }

    return 0;
}

Tool ItemVariant::AsTool() const
{
    return (kind == KIND_TOOL) ? Tool(id) : Tool(TOOL_NONE);
}

Food ItemVariant::AsFood() const
{
    return (kind == KIND_FOOD) ? Food(id) : Food(FOOD_NONE);
}

Article ItemVariant::AsArticle() const
{
    return (kind == KIND_ARTICLE) ? Article(id) : Article(ARTICLE_NONE);
}

#if defined(REGION_JP)
asm(
    "    .section .rodata\n"
    "jp_item_data_start:\n"
    "    .incbin \"baserom_jp.gba\", 0xE8AB4, (0xE8AC0 - 0xE8AB4)\n"
    "\n"
    "    .global gBrokenToolName\n"
    "gBrokenToolName:\n"
    "    .incbin \"baserom_jp.gba\", 0xE8AC0, (0xE8ACC - 0xE8AC0)\n"
    "\n"
    "    .global gNoExplanation\n"
    "gNoExplanation:\n"
    "    .incbin \"baserom_jp.gba\", 0xE8ACC, (0xE8ADC - 0xE8ACC)\n"
    "\n"
    "    .global gBrokenFoodName\n"
    "gBrokenFoodName:\n"
    "    .incbin \"baserom_jp.gba\", 0xE8ADC, (0xE8AE8 - 0xE8ADC)\n"
    "\n"
    "    .global gBrokenArticleName\n"
    "gBrokenArticleName:\n"
    "    .incbin \"baserom_jp.gba\", 0xE8AE8, (0xE8AF8 - 0xE8AE8)\n"
    "\n"
    "    .global gBrokenShipmentName\n"
    "gBrokenShipmentName:\n"
    "    .incbin \"baserom_jp.gba\", 0xE8AF8, (0xE8B08 - 0xE8AF8)\n"
    "\n"
    "    .include \"build/jp/data/text/tool.s\"\n"
    "\n"
    "    .global gToolInfo\n"
    "gToolInfo:\n"
    "    .incbin \"baserom_jp.gba\", 0xE9EEC, (0xEA2B8 - 0xE9EEC)\n"
    "\n"
    "    .include \"build/jp/data/text/food.s\"\n"
    "\n"
    "    .global gFoodInfo\n"
    "gFoodInfo:\n"
    "    .incbin \"baserom_jp.gba\", 0xED3D8, (0xEDE88 - 0xED3D8)\n"
    "\n"
    "    .include \"build/jp/data/text/article.s\"\n"
    "\n"
    "    .global gArticleInfo\n"
    "gArticleInfo:\n"
    "    .incbin \"baserom_jp.gba\", 0xEF738, (0xEFBAC - 0xEF738)\n"
    "\n"
    "    .global gProductInfo\n"
    "gProductInfo:\n"
    "    .incbin \"baserom_jp.gba\", 0xEFBAC, (0xEFD48 - 0xEFBAC)\n"
    "\n"
    "    .syntax divided\n"
);
#else

asm(
    "    .section .rodata\n"
    "    .include \"build/us/data/text/tool.s\"\n"
);

// Item Info tables

ToolInfo const gToolInfo[] = {
    /* 0x00 */ { gText_Item_Tool_IronSickle_Name, 403, gText_Item_Tool_IronSickle_Description },
    /* 0x01 */ { gText_Item_Tool_CopperSickle_Name, 404, gText_Item_Tool_CopperSickle_Description },
    /* 0x02 */ { gText_Item_Tool_SilverSickle_Name, 405, gText_Item_Tool_SilverSickle_Description },
    /* 0x03 */ { gText_Item_Tool_GoldSickle_Name, 406, gText_Item_Tool_GoldSickle_Description },
    /* 0x04 */ { gText_Item_Tool_MystrileSickle_Name, 407, gText_Item_Tool_MystrileSickle_Description },
    /* 0x05 */ { gText_Item_Tool_CursedSickle_Name, 409, gText_Item_Tool_CursedSickle_Description },
    /* 0x06 */ { gText_Item_Tool_BlessedSickle_Name, 408, gText_Item_Tool_BlessedSickle_Description },
    /* 0x07 */ { gText_Item_Tool_MythicSickle_Name, 410, gText_Item_Tool_MythicSickle_Description },
    /* 0x08 */ { gText_Item_Tool_IronHoe_Name, 234, gText_Item_Tool_IronHoe_Description },
    /* 0x09 */ { gText_Item_Tool_CopperHoe_Name, 235, gText_Item_Tool_CopperHoe_Description },
    /* 0x0A */ { gText_Item_Tool_SilverHoe_Name, 236, gText_Item_Tool_SilverHoe_Description },
    /* 0x0B */ { gText_Item_Tool_GoldHoe_Name, 237, gText_Item_Tool_GoldHoe_Description },
    /* 0x0C */ { gText_Item_Tool_MystrileHoe_Name, 238, gText_Item_Tool_MystrileHoe_Description },
    /* 0x0D */ { gText_Item_Tool_CursedHoe_Name, 240, gText_Item_Tool_CursedHoe_Description },
    /* 0x0E */ { gText_Item_Tool_BlessedHoe_Name, 239, gText_Item_Tool_BlessedHoe_Description },
    /* 0x0F */ { gText_Item_Tool_MythicHoe_Name, 241, gText_Item_Tool_MythicHoe_Description },
    /* 0x10 */ { gText_Item_Tool_IronAxe_Name, 13, gText_Item_Tool_IronAxe_Description },
    /* 0x11 */ { gText_Item_Tool_CopperAxe_Name, 14, gText_Item_Tool_CopperAxe_Description },
    /* 0x12 */ { gText_Item_Tool_SilverAxe_Name, 15, gText_Item_Tool_SilverAxe_Description },
    /* 0x13 */ { gText_Item_Tool_GoldAxe_Name, 16, gText_Item_Tool_GoldAxe_Description },
    /* 0x14 */ { gText_Item_Tool_MystrileAxe_Name, 17, gText_Item_Tool_MystrileAxe_Description },
    /* 0x15 */ { gText_Item_Tool_CursedAxe_Name, 19, gText_Item_Tool_CursedAxe_Description },
    /* 0x16 */ { gText_Item_Tool_BlessedAxe_Name, 18, gText_Item_Tool_BlessedAxe_Description },
    /* 0x17 */ { gText_Item_Tool_MythicAxe_Name, 20, gText_Item_Tool_MythicAxe_Description },
    /* 0x18 */ { gText_Item_Tool_IronHammer_Name, 223, gText_Item_Tool_IronHammer_Description },
    /* 0x19 */ { gText_Item_Tool_CopperHammer_Name, 224, gText_Item_Tool_CopperHammer_Description },
    /* 0x1A */ { gText_Item_Tool_SilverHammer_Name, 225, gText_Item_Tool_SilverHammer_Description },
    /* 0x1B */ { gText_Item_Tool_GoldHammer_Name, 226, gText_Item_Tool_GoldHammer_Description },
    /* 0x1C */ { gText_Item_Tool_MystrileHammer_Name, 227, gText_Item_Tool_MystrileHammer_Description },
    /* 0x1D */ { gText_Item_Tool_CursedHammer_Name, 229, gText_Item_Tool_CursedHammer_Description },
    /* 0x1E */ { gText_Item_Tool_BlessedHammer_Name, 228, gText_Item_Tool_BlessedHammer_Description },
    /* 0x1F */ { gText_Item_Tool_MythicHammer_Name, 230, gText_Item_Tool_MythicHammer_Description },
    /* 0x20 */ { gText_Item_Tool_WateringCan_Name, 462, gText_Item_Tool_WateringCan_Description },
    /* 0x21 */ { gText_Item_Tool_CopperWateringCan_Name, 463, gText_Item_Tool_CopperWateringCan_Description },
    /* 0x22 */ { gText_Item_Tool_SilverWateringCan_Name, 464, gText_Item_Tool_SilverWateringCan_Description },
    /* 0x23 */ { gText_Item_Tool_GoldWateringCan_Name, 465, gText_Item_Tool_GoldWateringCan_Description },
    /* 0x24 */ { gText_Item_Tool_MystrileWateringCan_Name, 466, gText_Item_Tool_MystrileWateringCan_Description },
    /* 0x25 */ { gText_Item_Tool_CursedWateringCan_Name, 468, gText_Item_Tool_CursedWateringCan_Description },
    /* 0x26 */ { gText_Item_Tool_BlessedWateringCan_Name, 467, gText_Item_Tool_BlessedWateringCan_Description },
    /* 0x27 */ { gText_Item_Tool_MythicWateringCan_Name, 469, gText_Item_Tool_MythicWateringCan_Description },
    /* 0x28 */ { gText_Item_Tool_FishingRod_Name, 148, gText_Item_Tool_FishingRod_Description },
    /* 0x29 */ { gText_Item_Tool_CopperFishingRod_Name, 149, gText_Item_Tool_CopperFishingRod_Description },
    /* 0x2A */ { gText_Item_Tool_SilverFishingRod_Name, 150, gText_Item_Tool_SilverFishingRod_Description },
    /* 0x2B */ { gText_Item_Tool_GoldFishingRod_Name, 151, gText_Item_Tool_GoldFishingRod_Description },
    /* 0x2C */ { gText_Item_Tool_MystrileFishingRod_Name, 152, gText_Item_Tool_MystrileFishingRod_Description },
    /* 0x2D */ { gText_Item_Tool_CursedFishingRod_Name, 154, gText_Item_Tool_CursedFishingRod_Description },
    /* 0x2E */ { gText_Item_Tool_BlessedFishingRod_Name, 153, gText_Item_Tool_BlessedFishingRod_Description },
    /* 0x2F */ { gText_Item_Tool_MythicFishingRod_Name, 155, gText_Item_Tool_MythicFishingRod_Description },
    /* 0x30 */ { gText_Item_Tool_CowMiraclePotion_Name, 91, gText_Item_Tool_CowMiraclePotion_Description },
    /* 0x31 */ { gText_Item_Tool_SheepMiraclePotion_Name, 402, gText_Item_Tool_SheepMiraclePotion_Description },
    /* 0x32 */ { gText_Item_Tool_TurnipSeeds_Name, 458, gText_Item_Tool_TurnipSeeds_Description },
    /* 0x33 */ { gText_Item_Tool_PotatoSeeds_Name, 348, gText_Item_Tool_PotatoSeeds_Description },
    /* 0x34 */ { gText_Item_Tool_CucumberSeeds_Name, 114, gText_Item_Tool_CucumberSeeds_Description },
    /* 0x35 */ { gText_Item_Tool_StrawberrySeeds_Name, 433, gText_Item_Tool_StrawberrySeeds_Description },
    /* 0x36 */ { gText_Item_Tool_CabbageSeeds_Name, 85, gText_Item_Tool_CabbageSeeds_Description },
    /* 0x37 */ { gText_Item_Tool_TomatoSeeds_Name, 450, gText_Item_Tool_TomatoSeeds_Description },
    /* 0x38 */ { gText_Item_Tool_CornSeeds_Name, 111, gText_Item_Tool_CornSeeds_Description },
    /* 0x39 */ { gText_Item_Tool_OnionSeeds_Name, 320, gText_Item_Tool_OnionSeeds_Description },
    /* 0x3A */ { gText_Item_Tool_PumpkinSeeds_Name, 356, gText_Item_Tool_PumpkinSeeds_Description },
    /* 0x3B */ { gText_Item_Tool_PineappleSeeds_Name, 335, gText_Item_Tool_PineappleSeeds_Description },
    /* 0x3C */ { gText_Item_Tool_EggplantSeeds_Name, 134, gText_Item_Tool_EggplantSeeds_Description },
    /* 0x3D */ { gText_Item_Tool_CarrotSeeds_Name, 90, gText_Item_Tool_CarrotSeeds_Description },
    /* 0x3E */ { gText_Item_Tool_SweetPotatoSeeds_Name, 440, gText_Item_Tool_SweetPotatoSeeds_Description },
    /* 0x3F */ { gText_Item_Tool_SpinachSeeds_Name, 424, gText_Item_Tool_SpinachSeeds_Description },
    /* 0x40 */ { gText_Item_Tool_GreenPepperSeeds_Name, 219, gText_Item_Tool_GreenPepperSeeds_Description },
    /* 0x41 */ { gText_Item_Tool_GrassSeeds_Name, 215, gText_Item_Tool_GrassSeeds_Description },
    /* 0x42 */ { gText_Item_Tool_MoonDropSeeds_Name, 305, gText_Item_Tool_MoonDropSeeds_Description },
    /* 0x43 */ { gText_Item_Tool_PinkCatSeeds_Name, 339, gText_Item_Tool_PinkCatSeeds_Description },
    /* 0x44 */ { gText_Item_Tool_MagicSeeds_Name, 276, gText_Item_Tool_MagicSeeds_Description },
    /* 0x45 */ { gText_Item_Tool_ToyFlowerSeeds_Name, 454, gText_Item_Tool_ToyFlowerSeeds_Description },
    /* 0x46 */ { gText_Item_Tool_Brush_Name, 80, gText_Item_Tool_Brush_Description },
    /* 0x47 */ { gText_Item_Tool_Milker_Name, 294, gText_Item_Tool_Milker_Description },
    /* 0x48 */ { gText_Item_Tool_Clipper_Name, 222, gText_Item_Tool_Clipper_Description },
    /* 0x49 */ { gText_Item_Tool_Bell_Name, 59, gText_Item_Tool_Bell_Description },
    /* 0x4A */ { gText_Item_Tool_AnimalMedicine_Name, 6, gText_Item_Tool_AnimalMedicine_Description },
    /* 0x4B */ { gText_Item_Tool_BlueFeather_Name, 67, gText_Item_Tool_BlueFeather_Description },
    /* 0x4C */ { gText_Item_Tool_Pedometer_Name, 328, gText_Item_Tool_Pedometer_Description },
    /* 0x4D */ { gText_Item_Tool_TeleportStone_Name, 165, gText_Item_Tool_TeleportStone_Description },
    /* 0x4E */ { gText_Item_Tool_GemOfTheGoddess_Name, 208, gText_Item_Tool_GemOfTheGoddess_Description },
    /* 0x4F */ { gText_Item_Tool_GemOfTheKappa_Name, 262, gText_Item_Tool_GemOfTheKappa_Description },
    /* 0x50 */ { gText_Item_Tool_GemOfTruth_Name, 456, gText_Item_Tool_GemOfTruth_Description },
};

asm(
    "    .section .rodata\n"
    "    .include \"build/us/data/text/food.s\"\n"
);

FoodInfo const gFoodInfo[] = {
    /* 0x00 */ { gText_Item_Food_Turnip_Name, false, 3, -1, 457, gText_Item_Food_Turnip_Description },
    /* 0x01 */ { gText_Item_Food_Potato_Name, false, 3, -1, 347, gText_Item_Food_Potato_Description },
    /* 0x02 */ { gText_Item_Food_Cucumber_Name, false, 4, -1, 113, gText_Item_Food_Cucumber_Description },
    /* 0x03 */ { gText_Item_Food_Strawberry_Name, false, 5, -2, 430, gText_Item_Food_Strawberry_Description },
    /* 0x04 */ { gText_Item_Food_Cabbage_Name, false, 3, -1, 84, gText_Item_Food_Cabbage_Description },
    /* 0x05 */ { gText_Item_Food_Tomato_Name, false, 4, -1, 448, gText_Item_Food_Tomato_Description },
    /* 0x06 */ { gText_Item_Food_Corn_Name, false, 3, -1, 109, gText_Item_Food_Corn_Description },
    /* 0x07 */ { gText_Item_Food_Onion_Name, false, 3, -1, 319, gText_Item_Food_Onion_Description },
    /* 0x08 */ { gText_Item_Food_Pumpkin_Name, false, 3, -1, 354, gText_Item_Food_Pumpkin_Description },
    /* 0x09 */ { gText_Item_Food_Pineapple_Name, false, 5, -2, 334, gText_Item_Food_Pineapple_Description },
    /* 0x0A */ { gText_Item_Food_Eggplant_Name, false, 3, -1, 132, gText_Item_Food_Eggplant_Description },
    /* 0x0B */ { gText_Item_Food_Carrot_Name, false, 4, -1, 89, gText_Item_Food_Carrot_Description },
    /* 0x0C */ { gText_Item_Food_SweetPotato_Name, false, 3, -1, 439, gText_Item_Food_SweetPotato_Description },
    /* 0x0D */ { gText_Item_Food_Spinach_Name, false, 3, -1, 423, gText_Item_Food_Spinach_Description },
    /* 0x0E */ { gText_Item_Food_GreenPepper_Name, false, 3, -1, 218, gText_Item_Food_GreenPepper_Description },
    /* 0x0F */ { gText_Item_Food_RegularQualityEgg_Name, false, 3, -1, 125, gText_Item_Food_RegularQualityEgg_Description },
    /* 0x10 */ { gText_Item_Food_GoodQualityEgg_Name, false, 3, -1, 126, gText_Item_Food_GoodQualityEgg_Description },
    /* 0x11 */ { gText_Item_Food_HighQualityEgg_Name, false, 3, -1, 127, gText_Item_Food_HighQualityEgg_Description },
    /* 0x12 */ { gText_Item_Food_GoldenEgg_Name, false, 4, -2, 128, gText_Item_Food_GoldenEgg_Description },
    /* 0x13 */ { gText_Item_Food_PEgg_Name, false, 5, -3, 129, gText_Item_Food_PEgg_Description },
    /* 0x14 */ { gText_Item_Food_XEgg_Name, false, 6, -4, 130, gText_Item_Food_XEgg_Description },
    /* 0x15 */ { gText_Item_Food_SpaboiledEgg_Name, false, 4, -2, 131, gText_Item_Food_SpaboiledEgg_Description },
    /* 0x16 */ { gText_Item_Food_MayonnaiseS_Name, false, 1, -1, 284, gText_Item_Food_MayonnaiseS_Description },
    /* 0x17 */ { gText_Item_Food_MayonnaiseM_Name, false, 2, -1, 285, gText_Item_Food_MayonnaiseM_Description },
    /* 0x18 */ { gText_Item_Food_MayonnaiseL_Name, false, 3, -1, 286, gText_Item_Food_MayonnaiseL_Description },
    /* 0x19 */ { gText_Item_Food_MayonnaiseG_Name, false, 4, -2, 287, gText_Item_Food_MayonnaiseG_Description },
    /* 0x1A */ { gText_Item_Food_MayonnaiseP_Name, false, 5, -3, 288, gText_Item_Food_MayonnaiseP_Description },
    /* 0x1B */ { gText_Item_Food_MayonnaiseX_Name, false, 6, -3, 289, gText_Item_Food_MayonnaiseX_Description },
    /* 0x1C */ { gText_Item_Food_MilkS_Name, true, 2, -2, 296, gText_Item_Food_MilkS_Description },
    /* 0x1D */ { gText_Item_Food_MilkM_Name, true, 3, -2, 293, gText_Item_Food_MilkM_Description },
    /* 0x1E */ { gText_Item_Food_MilkL_Name, true, 4, -2, 292, gText_Item_Food_MilkL_Description },
    /* 0x1F */ { gText_Item_Food_MilkG_Name, true, 5, -3, 291, gText_Item_Food_MilkG_Description },
    /* 0x20 */ { gText_Item_Food_MilkP_Name, true, 6, -4, 295, gText_Item_Food_MilkP_Description },
    /* 0x21 */ { gText_Item_Food_MilkX_Name, true, 7, -5, 297, gText_Item_Food_MilkX_Description },
    /* 0x22 */ { gText_Item_Food_CheeseS_Name, false, 5, -1, 92, gText_Item_Food_CheeseS_Description },
    /* 0x23 */ { gText_Item_Food_CheeseM_Name, false, 6, -1, 93, gText_Item_Food_CheeseM_Description },
    /* 0x24 */ { gText_Item_Food_CheeseL_Name, false, 7, -1, 94, gText_Item_Food_CheeseL_Description },
    /* 0x25 */ { gText_Item_Food_CheeseG_Name, false, 8, -2, 95, gText_Item_Food_CheeseG_Description },
    /* 0x26 */ { gText_Item_Food_CheeseP_Name, false, 9, -3, 96, gText_Item_Food_CheeseP_Description },
    /* 0x27 */ { gText_Item_Food_CheeseX_Name, false, 10, -4, 97, gText_Item_Food_CheeseX_Description },
    /* 0x28 */ { gText_Item_Food_Apple_Name, false, 2, -2, 8, gText_Item_Food_Apple_Description },
    /* 0x29 */ { gText_Item_Food_Honey_Name, false, 2, -2, 242, gText_Item_Food_Honey_Description },
    /* 0x2A */ { gText_Item_Food_BambooShoot_Name, false, 10, -1, 50, gText_Item_Food_BambooShoot_Description },
    /* 0x2B */ { gText_Item_Food_WildGrapes_Name, false, 10, -2, 309, gText_Item_Food_WildGrapes_Description },
    /* 0x2C */ { gText_Item_Food_Mushroom_Name, false, 10, -1, 306, gText_Item_Food_Mushroom_Description },
    /* 0x2D */ { gText_Item_Food_PoisonousMushroom_Name, false, -50, 10, 245, gText_Item_Food_PoisonousMushroom_Description },
    /* 0x2E */ { gText_Item_Food_Truffle_Name, false, 20, -1, 281, gText_Item_Food_Truffle_Description },
    /* 0x2F */ { gText_Item_Food_BlueGrass_Name, false, 10, -1, 65, gText_Item_Food_BlueGrass_Description },
    /* 0x30 */ { gText_Item_Food_GreenGrass_Name, false, 0, -2, 216, gText_Item_Food_GreenGrass_Description },
    /* 0x31 */ { gText_Item_Food_RedGrass_Name, false, -10, 5, 376, gText_Item_Food_RedGrass_Description },
    /* 0x32 */ { gText_Item_Food_YellowGrass_Name, false, -5, -5, 490, gText_Item_Food_YellowGrass_Description },
    /* 0x33 */ { gText_Item_Food_OrangeGrass_Name, false, 0, 0, 322, gText_Item_Food_OrangeGrass_Description },
    /* 0x34 */ { gText_Item_Food_PurpleGrass_Name, false, 5, -2, 357, gText_Item_Food_PurpleGrass_Description },
    /* 0x35 */ { gText_Item_Food_IndigoGrass_Name, false, 20, -1, 256, gText_Item_Food_IndigoGrass_Description },
    /* 0x36 */ { gText_Item_Food_BlackGrass_Name, false, 5, -5, 63, gText_Item_Food_BlackGrass_Description },
    /* 0x37 */ { gText_Item_Food_WhiteGrass_Name, false, 10, -10, 473, gText_Item_Food_WhiteGrass_Description },
    /* 0x38 */ { gText_Item_Food_QueenOfTheNight_Name, false, 0, 0, 58, gText_Item_Food_QueenOfTheNight_Description },
    /* 0x39 */ { gText_Item_Food_Bodigizer_Name, true, 50, -1, 349, gText_Item_Food_Bodigizer_Description },
    /* 0x3A */ { gText_Item_Food_BodigizerXl_Name, true, 100, -1, 350, gText_Item_Food_BodigizerXl_Description },
    /* 0x3B */ { gText_Item_Food_Turbojolt_Name, true, 0, -20, 146, gText_Item_Food_Turbojolt_Description },
    /* 0x3C */ { gText_Item_Food_TurbojoltXl_Name, true, 0, -50, 147, gText_Item_Food_TurbojoltXl_Description },
    /* 0x3D */ { gText_Item_Food_Wine_Name, true, 1, -5, 475, gText_Item_Food_Wine_Description },
    /* 0x3E */ { gText_Item_Food_GrapeJuice_Name, true, 5, -5, 221, gText_Item_Food_GrapeJuice_Description },
    /* 0x3F */ { gText_Item_Food_RiceBall_Name, false, 2, -1, 380, gText_Item_Food_RiceBall_Description },
    /* 0x40 */ { gText_Item_Food_Bread_Name, false, 2, -1, 78, gText_Item_Food_Bread_Description },
    /* 0x41 */ { gText_Item_Food_Oil_Name, false, 1, 1, 315, gText_Item_Food_Oil_Description },
    /* 0x42 */ { gText_Item_Food_Flower_Name, false, 1, 1, 163, gText_Item_Food_Flower_Description },
    /* 0x43 */ { gText_Item_Food_CurryPowder_Name, false, 1, 1, 118, gText_Item_Food_CurryPowder_Description },
    /* 0x44 */ { gText_Item_Food_MuffinMix_Name, false, 1, 1, 122, gText_Item_Food_MuffinMix_Description },
    /* 0x45 */ { gText_Item_Food_Chocolate_Name, false, 2, -2, 102, gText_Item_Food_Chocolate_Description },
    /* 0x46 */ { gText_Item_Food_RelaxTeaLeaves_Name, false, 2, -3, 379, gText_Item_Food_RelaxTeaLeaves_Description },
    /* 0x47 */ { gText_Item_Food_SugdwApple_Name, false, 2, -2, 435, gText_Item_Food_SugdwApple_Description },
    /* 0x48 */ { gText_Item_Food_HmsgbApple_Name, false, 2, -2, 233, gText_Item_Food_HmsgbApple_Description },
    /* 0x49 */ { gText_Item_Food_AepfeApple_Name, false, 2, -2, 1, gText_Item_Food_AepfeApple_Description },
    /* 0x4A */ { gText_Item_Food_BuckwheatFlour_Name, false, 1, 1, 81, gText_Item_Food_BuckwheatFlour_Description },
    /* 0x4B */ { gText_Item_Food_WildGrapeJuice_Name, true, 1, -40, 214, gText_Item_Food_WildGrapeJuice_Description },
    /* 0x4C */ { gText_Item_Food_Salad_Name, false, 20, -5, 396, gText_Item_Food_Salad_Description },
    /* 0x4D */ { gText_Item_Food_CurryRice_Name, false, 30, -2, 115, gText_Item_Food_CurryRice_Description },
    /* 0x4E */ { gText_Item_Food_Stew_Name, false, 30, -2, 427, gText_Item_Food_Stew_Description },
    /* 0x4F */ { gText_Item_Food_MisoSoup_Name, false, 5, -3, 298, gText_Item_Food_MisoSoup_Description },
    /* 0x50 */ { gText_Item_Food_StirFry_Name, false, 40, -1, 206, gText_Item_Food_StirFry_Description },
    /* 0x51 */ { gText_Item_Food_FriedRice_Name, false, 40, -1, 388, gText_Item_Food_FriedRice_Description },
    /* 0x52 */ { gText_Item_Food_SavoryPancake_Name, false, 50, -1, 316, gText_Item_Food_SavoryPancake_Description },
    /* 0x53 */ { gText_Item_Food_Sandwich_Name, false, 40, -5, 398, gText_Item_Food_Sandwich_Description },
    /* 0x54 */ { gText_Item_Food_FruitJuice_Name, true, 20, -15, 202, gText_Item_Food_FruitJuice_Description },
    /* 0x55 */ { gText_Item_Food_VegetableJuice_Name, true, 20, -20, 459, gText_Item_Food_VegetableJuice_Description },
    /* 0x56 */ { gText_Item_Food_MixedJuice_Name, true, 50, -30, 300, gText_Item_Food_MixedJuice_Description },
    /* 0x57 */ { gText_Item_Food_FruitLatte_Name, true, 30, -15, 203, gText_Item_Food_FruitLatte_Description },
    /* 0x58 */ { gText_Item_Food_VegetableLatte_Name, true, 30, -20, 460, gText_Item_Food_VegetableLatte_Description },
    /* 0x59 */ { gText_Item_Food_MixedLatte_Name, true, 60, -20, 301, gText_Item_Food_MixedLatte_Description },
    /* 0x5A */ { gText_Item_Food_StrawberryMilk_Name, true, 30, -15, 432, gText_Item_Food_StrawberryMilk_Description },
    /* 0x5B */ { gText_Item_Food_StrawberryJam_Name, false, 5, -5, 431, gText_Item_Food_StrawberryJam_Description },
    /* 0x5C */ { gText_Item_Food_TomatoJuice_Name, true, 20, -20, 449, gText_Item_Food_TomatoJuice_Description },
    /* 0x5D */ { gText_Item_Food_PickledTurnip_Name, false, 20, -4, 333, gText_Item_Food_PickledTurnip_Description },
    /* 0x5E */ { gText_Item_Food_FrenchFries_Name, false, 30, -2, 205, gText_Item_Food_FrenchFries_Description },
    /* 0x5F */ { gText_Item_Food_Pickles_Name, false, 20, -7, 332, gText_Item_Food_Pickles_Description },
    /* 0x60 */ { gText_Item_Food_Ketchup_Name, false, 1, 0, 264, gText_Item_Food_Ketchup_Description },
    /* 0x61 */ { gText_Item_Food_Popcorn_Name, false, 30, -1, 343, gText_Item_Food_Popcorn_Description },
    /* 0x62 */ { gText_Item_Food_CornFlakes_Name, false, 10, -2, 110, gText_Item_Food_CornFlakes_Description },
    /* 0x63 */ { gText_Item_Food_BakedCorn_Name, false, 7, -1, 384, gText_Item_Food_BakedCorn_Description },
    /* 0x64 */ { gText_Item_Food_PineappleJuice_Name, true, 5, -15, 359, gText_Item_Food_PineappleJuice_Description },
    /* 0x65 */ { gText_Item_Food_PumpkinPudding_Name, false, 50, -10, 355, gText_Item_Food_PumpkinPudding_Description },
    /* 0x66 */ { gText_Item_Food_PumpkinStew_Name, false, 8, -1, 70, gText_Item_Food_PumpkinStew_Description },
    /* 0x67 */ { gText_Item_Food_HappyEggplant_Name, false, 30, -2, 133, gText_Item_Food_HappyEggplant_Description },
    /* 0x68 */ { gText_Item_Food_SweetPotatoes_Name, false, 40, -5, 441, gText_Item_Food_SweetPotatoes_Description },
    /* 0x69 */ { gText_Item_Food_BakedSweetPotato_Name, false, 40, -5, 387, gText_Item_Food_BakedSweetPotato_Description },
    /* 0x6A */ { gText_Item_Food_Greens_Name, false, 20, -1, 314, gText_Item_Food_Greens_Description },
    /* 0x6B */ { gText_Item_Food_ScrambledEggs_Name, false, 40, -3, 385, gText_Item_Food_ScrambledEggs_Description },
    /* 0x6C */ { gText_Item_Food_Omelet_Name, false, 50, -4, 317, gText_Item_Food_Omelet_Description },
    /* 0x6D */ { gText_Item_Food_OmeletRice_Name, false, 60, -4, 318, gText_Item_Food_OmeletRice_Description },
    /* 0x6E */ { gText_Item_Food_BoiledEgg_Name, false, 20, -2, 68, gText_Item_Food_BoiledEgg_Description },
    /* 0x6F */ { gText_Item_Food_HotMilk_Name, true, 20, -10, 244, gText_Item_Food_HotMilk_Description },
    /* 0x70 */ { gText_Item_Food_Butter_Name, false, 1, 0, 82, gText_Item_Food_Butter_Description },
    /* 0x71 */ { gText_Item_Food_CheeseCake_Name, false, 50, -5, 98, gText_Item_Food_CheeseCake_Description },
    /* 0x72 */ { gText_Item_Food_CheeseFondue_Name, false, 40, -3, 99, gText_Item_Food_CheeseFondue_Description },
    /* 0x73 */ { gText_Item_Food_ApplePie_Name, false, 50, -8, 11, gText_Item_Food_ApplePie_Description },
    /* 0x74 */ { gText_Item_Food_AppleJam_Name, false, 5, -5, 10, gText_Item_Food_AppleJam_Description },
    /* 0x75 */ { gText_Item_Food_AppleSouffl_Name, false, 8, -2, 383, gText_Item_Food_AppleSouffl_Description },
    /* 0x76 */ { gText_Item_Food_MushroomRice_Name, false, 30, -1, 308, gText_Item_Food_MushroomRice_Description },
    /* 0x77 */ { gText_Item_Food_BambooRice_Name, false, 30, -1, 442, gText_Item_Food_BambooRice_Description },
    /* 0x78 */ { gText_Item_Food_TruffleRice_Name, false, 60, -1, 283, gText_Item_Food_TruffleRice_Description },
    /* 0x79 */ { gText_Item_Food_Sushi_Name, false, 40, -1, 438, gText_Item_Food_Sushi_Description },
    /* 0x7A */ { gText_Item_Food_JamBun_Name, false, 40, -5, 260, gText_Item_Food_JamBun_Description },
    /* 0x7B */ { gText_Item_Food_DinnerRole_Name, false, 40, -2, 83, gText_Item_Food_DinnerRole_Description },
    /* 0x7C */ { gText_Item_Food_RaisinBread_Name, false, 30, -4, 212, gText_Item_Food_RaisinBread_Description },
    /* 0x7D */ { gText_Item_Food_GrapeJam_Name, false, 5, -5, 213, gText_Item_Food_GrapeJam_Description },
    /* 0x7E */ { gText_Item_Food_CurryBread_Name, false, 30, -2, 116, gText_Item_Food_CurryBread_Description },
    /* 0x7F */ { gText_Item_Food_Sashimi_Name, false, 30, -3, 399, gText_Item_Food_Sashimi_Description },
    /* 0x80 */ { gText_Item_Food_GrilledFish_Name, false, 30, -1, 220, gText_Item_Food_GrilledFish_Description },
    /* 0x81 */ { gText_Item_Food_ChirashiSushi_Name, false, 50, -1, 101, gText_Item_Food_ChirashiSushi_Description },
    /* 0x82 */ { gText_Item_Food_Pizza_Name, false, 40, -1, 341, gText_Item_Food_Pizza_Description },
    /* 0x83 */ { gText_Item_Food_Noodles_Name, false, 40, -3, 312, gText_Item_Food_Noodles_Description },
    /* 0x84 */ { gText_Item_Food_CurryNoodles_Name, false, 60, -3, 117, gText_Item_Food_CurryNoodles_Description },
    /* 0x85 */ { gText_Item_Food_TempuraNoodles_Name, false, 60, -3, 445, gText_Item_Food_TempuraNoodles_Description },
    /* 0x86 */ { gText_Item_Food_FriedNoodles_Name, false, 60, -2, 386, gText_Item_Food_FriedNoodles_Description },
    /* 0x87 */ { gText_Item_Food_BuckwheatNoodles_Name, false, 40, -3, 492, gText_Item_Food_BuckwheatNoodles_Description },
    /* 0x88 */ { gText_Item_Food_NoodlesWTempura_Name, false, 60, -3, 446, gText_Item_Food_NoodlesWTempura_Description },
    /* 0x89 */ { gText_Item_Food_FriedNoodles_Name, false, 60, -2, 391, gText_Item_Food_FriedNoodles_Description },
    /* 0x8A */ { gText_Item_Food_BuckwheatChips_Name, false, 15, -2, 421, gText_Item_Food_BuckwheatChips_Description },
    /* 0x8B */ { gText_Item_Food_Cookies_Name, false, 15, -5, 107, gText_Item_Food_Cookies_Description },
    /* 0x8C */ { gText_Item_Food_ChocolateCookies_Name, false, 30, -5, 104, gText_Item_Food_ChocolateCookies_Description },
    /* 0x8D */ { gText_Item_Food_Tempura_Name, false, 20, -2, 443, gText_Item_Food_Tempura_Description },
    /* 0x8E */ { gText_Item_Food_IceCream_Name, false, 30, -20, 248, gText_Item_Food_IceCream_Description },
    /* 0x8F */ { gText_Item_Food_Cake_Name, false, 40, -8, 86, gText_Item_Food_Cake_Description },
    /* 0x90 */ { gText_Item_Food_ChocolateCake_Name, false, 70, -8, 103, gText_Item_Food_ChocolateCake_Description },
    /* 0x91 */ { gText_Item_Food_RelaxationTea_Name, true, 50, -50, 378, gText_Item_Food_RelaxationTea_Description },
    /* 0x92 */ { gText_Item_Food_Toast_Name, false, 7, -1, 447, gText_Item_Food_Toast_Description },
    /* 0x93 */ { gText_Item_Food_FrenchToast_Name, false, 30, -2, 168, gText_Item_Food_FrenchToast_Description },
    /* 0x94 */ { gText_Item_Food_Pudding_Name, false, 30, -8, 353, gText_Item_Food_Pudding_Description },
    /* 0x95 */ { gText_Item_Food_MountainStew_Name, false, 40, -1, 100, gText_Item_Food_MountainStew_Description },
    /* 0x96 */ { gText_Item_Food_MoonDumplings_Name, false, 40, -3, 119, gText_Item_Food_MoonDumplings_Description },
    /* 0x97 */ { gText_Item_Food_RiceCake_Name, false, 2, -1, 381, gText_Item_Food_RiceCake_Description },
    /* 0x98 */ { gText_Item_Food_RoastedRiceCake_Name, false, 10, -2, 390, gText_Item_Food_RoastedRiceCake_Description },
    /* 0x99 */ { gText_Item_Food_ElliLeaves_Name, false, 100, -50, 138, gText_Item_Food_ElliLeaves_Description },
    /* 0x9A */ { gText_Item_Food_FailedDish_Name, false, -10, 10, 140, gText_Item_Food_FailedDish_Description },
    /* 0x9B */ { gText_Item_Food_FailedDrink_Name, true, -10, 10, 143, gText_Item_Food_FailedDish_Description },
    /* 0x9C */ { gText_Item_Food_FailedPotDish_Name, false, -10, 10, 145, gText_Item_Food_FailedDish_Description },
    /* 0x9D */ { gText_Item_Food_FailedDessert_Name, false, -10, 10, 142, gText_Item_Food_FailedDish_Description },
    /* 0x9E */ { gText_Item_Food_FailedBread_Name, false, -10, 10, 141, gText_Item_Food_FailedDish_Description },
    /* 0x9F */ { gText_Item_Food_FailedNoodles_Name, false, -10, 10, 144, gText_Item_Food_FailedDish_Description },
    /* 0xA0 */ { gText_Item_Food_SmallFish_Name, false, 2, -1, 159, gText_Item_Food_SmallFish_Description },
    /* 0xA1 */ { gText_Item_Food_MediumFish_Name, false, 3, -1, 158, gText_Item_Food_MediumFish_Description },
    /* 0xA2 */ { gText_Item_Food_LargeFish_Name, false, 4, -1, 157, gText_Item_Food_LargeFish_Description },
    /* 0xA3 */ { gText_Item_Food_ToastedRiceBall_Name, false, 5, -1, 389, gText_Item_Food_ToastedRiceBall_Description },
    /* 0xA4 */ { gText_Item_Food_TempuraRice_Name, false, 30, -2, 444, gText_Item_Food_TempuraRice_Description },
    /* 0xA5 */ { gText_Item_Food_EggOverRice_Name, false, 20, -1, 135, gText_Item_Food_EggOverRice_Description },
    /* 0xA6 */ { gText_Item_Food_RiceGruel_Name, false, 5, -3, 382, gText_Item_Food_RiceGruel_Description },
    /* 0xA7 */ { gText_Item_Food_Pancakes_Name, false, 20, -3, 243, gText_Item_Food_Pancakes_Description },
    /* 0xA8 */ { gText_Item_Food_FishSticks_Name, false, 5, -1, 69, gText_Item_Food_FishSticks_Description },
    /* 0xA9 */ { gText_Item_Food_CandiedPotato_Name, false, 8, -1, 88, gText_Item_Food_CandiedPotato_Description },
    /* 0xAA */ { gText_Item_Food_PotatoPancakes_Name, false, 20, -2, 112, gText_Item_Food_PotatoPancakes_Description },
};

asm(
    "    .section .rodata\n"
    "    .include \"build/us/data/text/article.s\"\n"
);

ArticleInfo const gArticleInfo[] = {
    /* 0x00 */ { gText_Item_Article_MoonDropGrass_Name, 303, gText_Item_Article_MoonDropGrass_Description },
    /* 0x01 */ { gText_Item_Article_PinkCatGrass_Name, 337, gText_Item_Article_PinkCatGrass_Description },
    /* 0x02 */ { gText_Item_Article_BlueMagicGrass_Name, 272, gText_Item_Article_BlueMagicGrass_Description },
    /* 0x03 */ { gText_Item_Article_RedMagicGrass_Name, 274, gText_Item_Article_RedMagicGrass_Description },
    /* 0x04 */ { gText_Item_Article_ToyFlower_Name, 452, gText_Item_Article_ToyFlower_Description },
    /* 0x05 */ { gText_Item_Article_WoolS_Name, 488, gText_Item_Article_WoolS_Description },
    /* 0x06 */ { gText_Item_Article_WoolM_Name, 486, gText_Item_Article_WoolM_Description },
    /* 0x07 */ { gText_Item_Article_WoolL_Name, 485, gText_Item_Article_WoolL_Description },
    /* 0x08 */ { gText_Item_Article_WoolG_Name, 484, gText_Item_Article_WoolG_Description },
    /* 0x09 */ { gText_Item_Article_WoolP_Name, 487, gText_Item_Article_WoolP_Description },
    /* 0x0A */ { gText_Item_Article_WoolP_Name, 489, gText_Item_Article_WoolP_Description },
    /* 0x0B */ { gText_Item_Article_YarnS_Name, 482, gText_Item_Article_YarnS_Description },
    /* 0x0C */ { gText_Item_Article_YarnM_Name, 480, gText_Item_Article_YarnM_Description },
    /* 0x0D */ { gText_Item_Article_YarnL_Name, 479, gText_Item_Article_YarnL_Description },
    /* 0x0E */ { gText_Item_Article_YarnG_Name, 478, gText_Item_Article_YarnG_Description },
    /* 0x0F */ { gText_Item_Article_YarnP_Name, 481, gText_Item_Article_YarnP_Description },
    /* 0x10 */ { gText_Item_Article_YarnX_Name, 483, gText_Item_Article_YarnX_Description },
    /* 0x11 */ { gText_Item_Article_JunkOre_Name, 267, gText_Item_Article_JunkOre_Description },
    /* 0x12 */ { gText_Item_Article_Copper_Name, 108, gText_Item_Article_Copper_Description },
    /* 0x13 */ { gText_Item_Article_Silver_Name, 411, gText_Item_Article_Silver_Description },
    /* 0x14 */ { gText_Item_Article_Gold_Name, 209, gText_Item_Article_Gold_Description },
    /* 0x15 */ { gText_Item_Article_Mystrile_Name, 299, gText_Item_Article_Mystrile_Description },
    /* 0x16 */ { gText_Item_Article_Orichalc_Name, 326, gText_Item_Article_Orichalc_Description },
    /* 0x17 */ { gText_Item_Article_Adamantite_Name, 0, gText_Item_Article_Adamantite_Description },
    /* 0x18 */ { gText_Item_Article_MoonStone_Name, 302, gText_Item_Article_MoonStone_Description },
    /* 0x19 */ { gText_Item_Article_SandRose_Name, 397, gText_Item_Article_SandRose_Description },
    /* 0x1A */ { gText_Item_Article_PinkDiamond_Name, 336, gText_Item_Article_PinkDiamond_Description },
    /* 0x1B */ { gText_Item_Article_Alexandrite_Name, 3, gText_Item_Article_Alexandrite_Description },
    /* 0x1C */ { gText_Item_Article_MythicStone_Name, 395, gText_Item_Article_MythicStone_Description },
    /* 0x1D */ { gText_Item_Article_Diamond_Name, 120, gText_Item_Article_Diamond_Description },
    /* 0x1E */ { gText_Item_Article_Emerald_Name, 137, gText_Item_Article_Emerald_Description },
    /* 0x1F */ { gText_Item_Article_Ruby_Name, 393, gText_Item_Article_Ruby_Description },
    /* 0x20 */ { gText_Item_Article_Topaz_Name, 451, gText_Item_Article_Topaz_Description },
    /* 0x21 */ { gText_Item_Article_Peridot_Name, 330, gText_Item_Article_Peridot_Description },
    /* 0x22 */ { gText_Item_Article_Fluorite_Name, 164, gText_Item_Article_Fluorite_Description },
    /* 0x23 */ { gText_Item_Article_Agate_Name, 2, gText_Item_Article_Agate_Description },
    /* 0x24 */ { gText_Item_Article_Amethyst_Name, 5, gText_Item_Article_Amethyst_Description },
    /* 0x25 */ { gText_Item_Article_HarvestGoddessJewel_Name, 207, gText_Item_Article_HarvestGoddessJewel_Description },
    /* 0x26 */ { gText_Item_Article_KappaJewel_Name, 261, gText_Item_Article_KappaJewel_Description },
    /* 0x27 */ { gText_Item_Article_JewelOfTruth_Name, 455, gText_Item_Article_JewelOfTruth_Description },
    /* 0x28 */ { gText_Item_Article_TheSpringSun_Name, 426, gText_Item_Article_TheSpringSun_Description },
    /* 0x29 */ { gText_Item_Article_TheSummerSun_Name, 436, gText_Item_Article_TheSpringSun_Description },
    /* 0x2A */ { gText_Item_Article_TheAutumnSun_Name, 12, gText_Item_Article_TheSpringSun_Description },
    /* 0x2B */ { gText_Item_Article_TheWinterSun_Name, 476, gText_Item_Article_TheSpringSun_Description },
    /* 0x2C */ { gText_Item_Article_Bracelet_Name, 75, gText_Item_Article_Bracelet_Description },
    /* 0x2D */ { gText_Item_Article_Necklace_Name, 311, gText_Item_Article_Necklace_Description },
    /* 0x2E */ { gText_Item_Article_Earrings_Name, 123, gText_Item_Article_Earrings_Description },
    /* 0x2F */ { gText_Item_Article_Broach_Name, 79, gText_Item_Article_Broach_Description },
    /* 0x30 */ { gText_Item_Article_Weeds_Name, 471, gText_Item_Article_Weeds_Description },
    /* 0x31 */ { gText_Item_Article_Stones_Name, 428, gText_Item_Article_Stones_Description },
    /* 0x32 */ { gText_Item_Article_Branches_Name, 76, gText_Item_Article_Branches_Description },
    /* 0x33 */ { gText_Item_Article_Lithograph_Name, 270, gText_Item_Article_Lithograph_Description },
    /* 0x34 */ { gText_Item_Article_MessageInABottle_Name, 74, gText_Item_Article_MessageInABottle_Description },
    /* 0x35 */ { gText_Item_Article_Ball_Name, 49, gText_Item_Article_Ball_Description },
    /* 0x36 */ { gText_Item_Article_PirateTreasure_Name, 340, gText_Item_Article_PirateTreasure_Description },
    /* 0x37 */ { gText_Item_Article_FossilOfFish_Name, 167, gText_Item_Article_FossilOfFish_Description },
    /* 0x38 */ { gText_Item_Article_EmptyCan_Name, 87, gText_Item_Article_EmptyCan_Description },
    /* 0x39 */ { gText_Item_Article_Boots_Name, 73, gText_Item_Article_Boots_Description },
    /* 0x3A */ { gText_Item_Article_FishBones_Name, 71, gText_Item_Article_FishBones_Description },
    /* 0x3B */ { gText_Item_Article_KarensWine_Name, 263, gText_Item_Article_KarensWine_Description },
    /* 0x3C */ { gText_Item_Article_PopurisMudBall_Name, 345, gText_Item_Article_PopurisMudBall_Description },
    /* 0x3D */ { gText_Item_Article_AnnsMusicBox_Name, 360, gText_Item_Article_AnnsMusicBox_Description },
    /* 0x3E */ { gText_Item_Article_MarysGreatBook_Name, 277, gText_Item_Article_MarysGreatBook_Description },
    /* 0x3F */ { gText_Item_Article_EllisPressedFlower_Name, 136, gText_Item_Article_EllisPressedFlower_Description },
    /* 0x40 */ { gText_Item_Article_Album1_Name, 361, gText_Item_Article_Album1_Description },
    /* 0x41 */ { gText_Item_Article_Album2_Name, 362, gText_Item_Article_Album2_Description },
    /* 0x42 */ { gText_Item_Article_Album3_Name, 363, gText_Item_Article_Album3_Description },
    /* 0x43 */ { gText_Item_Article_Album4_Name, 364, gText_Item_Article_Album4_Description },
    /* 0x44 */ { gText_Item_Article_Album5_Name, 365, gText_Item_Article_Album5_Description },
    /* 0x45 */ { gText_Item_Article_Album6_Name, 366, gText_Item_Article_Album6_Description },
    /* 0x46 */ { gText_Item_Article_Album7_Name, 367, gText_Item_Article_Album7_Description },
    /* 0x47 */ { gText_Item_Article_Album8_Name, 368, gText_Item_Article_Album8_Description },
    /* 0x48 */ { gText_Item_Article_Album9_Name, 369, gText_Item_Article_Album9_Description },
    /* 0x49 */ { gText_Item_Article_Album10_Name, 370, gText_Item_Article_Album10_Description },
    /* 0x4A */ { gText_Item_Article_Album11_Name, 371, gText_Item_Article_Album11_Description },
    /* 0x4B */ { gText_Item_Article_Album12_Name, 372, gText_Item_Article_Album12_Description },
    /* 0x4C */ { gText_Item_Article_Album13_Name, 373, gText_Item_Article_Album13_Description },
    /* 0x4D */ { gText_Item_Article_Album14_Name, 374, gText_Item_Article_Album14_Description },
    /* 0x4E */ { gText_Item_Article_Album15_Name, 375, gText_Item_Article_Album15_Description },
    /* 0x4F */ { gText_Item_Article_Bandaid_Name, 52, gText_Item_Article_Bandaid_Description },
    /* 0x50 */ { gText_Item_Article_Book_Name, 72, gText_Item_Article_Book_Description },
    /* 0x51 */ { gText_Item_Article_Perfume_Name, 329, gText_Item_Article_Perfume_Description },
    /* 0x52 */ { gText_Item_Article_Photo_Name, 331, gText_Item_Article_Photo_Description },
    /* 0x53 */ { gText_Item_Article_PlantEncyclopedia_Name, 342, gText_Item_Article_PlantEncyclopedia_Description },
    /* 0x54 */ { gText_Item_Article_Invitation_Name, 258, gText_Item_Article_Invitation_Description },
    /* 0x55 */ { gText_Item_Article_Dress_Name, 121, gText_Item_Article_Dress_Description },
    /* 0x56 */ { gText_Item_Article_FacialPack_Name, 139, gText_Item_Article_FacialPack_Description },
    /* 0x57 */ { gText_Item_Article_SkinLotion_Name, 412, gText_Item_Article_SkinLotion_Description },
    /* 0x58 */ { gText_Item_Article_Sunblock_Name, 437, gText_Item_Article_Sunblock_Description },
    /* 0x59 */ { gText_Item_Article_Lumber_Name, 278, gText_Item_Article_Lumber_Description },
    /* 0x5A */ { gText_Item_Article_GoldenLumber_Name, 210, gText_Item_Article_GoldenLumber_Description },
    /* 0x5B */ { gText_Item_Article_AnimalFodder_Name, 166, gText_Item_Article_AnimalFodder_Description },
    /* 0x5C */ { gText_Item_Article_ChickenFeed_Name, 231, gText_Item_Article_ChickenFeed_Description },
    /* 0x5D */ { gText_Item_Article_Lottery_Name, 271, gText_Item_Article_Lottery_Description },
    /* 0x5E */ { gText_Item_Article_Frisbee_Name, 201, gText_Item_Article_Frisbee_Description },
};

ProductInfo const gProductInfo[] = {
    /* 0x00 */ { 60, ProductInfo::KIND_FOOD, FOOD_TURNIP },
    /* 0x01 */ { 80, ProductInfo::KIND_FOOD, FOOD_POTATO },
    /* 0x02 */ { 60, ProductInfo::KIND_FOOD, FOOD_CUCUMBER },
    /* 0x03 */ { 250, ProductInfo::KIND_FOOD, FOOD_CABBAGE },
    /* 0x04 */ { 30, ProductInfo::KIND_FOOD, FOOD_STRAWBERRY },
    /* 0x05 */ { 60, ProductInfo::KIND_FOOD, FOOD_TOMATO },
    /* 0x06 */ { 100, ProductInfo::KIND_FOOD, FOOD_CORN },
    /* 0x07 */ { 80, ProductInfo::KIND_FOOD, FOOD_ONION },
    /* 0x08 */ { 500, ProductInfo::KIND_FOOD, FOOD_PINEAPPLE },
    /* 0x09 */ { 250, ProductInfo::KIND_FOOD, FOOD_PUMPKIN },
    /* 0x0A */ { 80, ProductInfo::KIND_FOOD, FOOD_EGGPLANT },
    /* 0x0B */ { 120, ProductInfo::KIND_FOOD, FOOD_CARROT },
    /* 0x0C */ { 120, ProductInfo::KIND_FOOD, FOOD_SWEET_POTATO },
    /* 0x0D */ { 40, ProductInfo::KIND_FOOD, FOOD_GREEN_PEPPER },
    /* 0x0E */ { 80, ProductInfo::KIND_FOOD, FOOD_SPINACH },
    /* 0x0F */ { 50, ProductInfo::KIND_FOOD, FOOD_REGULAR_QUALITY_EGG },
    /* 0x10 */ { 60, ProductInfo::KIND_FOOD, FOOD_GOOD_QUALITY_EGG },
    /* 0x11 */ { 80, ProductInfo::KIND_FOOD, FOOD_HIGH_QUALITY_EGG },
    /* 0x12 */ { 100, ProductInfo::KIND_FOOD, FOOD_GOLDEN_EGG },
    /* 0x13 */ { 180, ProductInfo::KIND_FOOD, FOOD_P_EGG },
    /* 0x14 */ { 350, ProductInfo::KIND_FOOD, FOOD_X_EGG },
    /* 0x15 */ { 80, ProductInfo::KIND_FOOD, FOOD_SPABOILED_EGG },
    /* 0x16 */ { 100, ProductInfo::KIND_FOOD, FOOD_MAYONNAISE_S },
    /* 0x17 */ { 150, ProductInfo::KIND_FOOD, FOOD_MAYONNAISE_M },
    /* 0x18 */ { 200, ProductInfo::KIND_FOOD, FOOD_MAYONNAISE_L },
    /* 0x19 */ { 300, ProductInfo::KIND_FOOD, FOOD_MAYONNAISE_G },
    /* 0x1A */ { 450, ProductInfo::KIND_FOOD, FOOD_MAYONNAISE_P },
    /* 0x1B */ { 800, ProductInfo::KIND_FOOD, FOOD_MAYONNAISE_X },
    /* 0x1C */ { 100, ProductInfo::KIND_FOOD, FOOD_MILK_S },
    /* 0x1D */ { 150, ProductInfo::KIND_FOOD, FOOD_MILK_M },
    /* 0x1E */ { 200, ProductInfo::KIND_FOOD, FOOD_MILK_L },
    /* 0x1F */ { 300, ProductInfo::KIND_FOOD, FOOD_MILK_G },
    /* 0x20 */ { 500, ProductInfo::KIND_FOOD, FOOD_MILK_P },
    /* 0x21 */ { 800, ProductInfo::KIND_FOOD, FOOD_MILK_X },
    /* 0x22 */ { 300, ProductInfo::KIND_FOOD, FOOD_CHEESE_S },
    /* 0x23 */ { 400, ProductInfo::KIND_FOOD, FOOD_CHEESE_M },
    /* 0x24 */ { 500, ProductInfo::KIND_FOOD, FOOD_CHEESE_L },
    /* 0x25 */ { 600, ProductInfo::KIND_FOOD, FOOD_CHEESE_G },
    /* 0x26 */ { 750, ProductInfo::KIND_FOOD, FOOD_CHEESE_P },
    /* 0x27 */ { 1500, ProductInfo::KIND_FOOD, FOOD_CHEESE_X },
    /* 0x28 */ { 50, ProductInfo::KIND_FOOD, FOOD_APPLE },
    /* 0x29 */ { 50, ProductInfo::KIND_FOOD, FOOD_SUGDW_APPLE },
    /* 0x2A */ { 50, ProductInfo::KIND_FOOD, FOOD_HMSGB_APPLE },
    /* 0x2B */ { 50, ProductInfo::KIND_FOOD, FOOD_AEPFE_APPLE },
    /* 0x2C */ { 50, ProductInfo::KIND_FOOD, FOOD_HONEY },
    /* 0x2D */ { 50, ProductInfo::KIND_FOOD, FOOD_BAMBOO_SHOOT },
    /* 0x2E */ { 50, ProductInfo::KIND_FOOD, FOOD_WILD_GRAPES },
    /* 0x2F */ { 70, ProductInfo::KIND_FOOD, FOOD_MUSHROOM },
    /* 0x30 */ { 100, ProductInfo::KIND_FOOD, FOOD_POISONOUS_MUSHROOM },
    /* 0x31 */ { 500, ProductInfo::KIND_FOOD, FOOD_TRUFFLE },
    /* 0x32 */ { 100, ProductInfo::KIND_FOOD, FOOD_BLUE_GRASS },
    /* 0x33 */ { 100, ProductInfo::KIND_FOOD, FOOD_GREEN_GRASS },
    /* 0x34 */ { 110, ProductInfo::KIND_FOOD, FOOD_RED_GRASS },
    /* 0x35 */ { 120, ProductInfo::KIND_FOOD, FOOD_YELLOW_GRASS },
    /* 0x36 */ { 100, ProductInfo::KIND_FOOD, FOOD_ORANGE_GRASS },
    /* 0x37 */ { 120, ProductInfo::KIND_FOOD, FOOD_PURPLE_GRASS },
    /* 0x38 */ { 100, ProductInfo::KIND_FOOD, FOOD_INDIGO_GRASS },
    /* 0x39 */ { 10, ProductInfo::KIND_FOOD, FOOD_BLACK_GRASS },
    /* 0x3A */ { 150, ProductInfo::KIND_FOOD, FOOD_WHITE_GRASS },
    /* 0x3B */ { 100, ProductInfo::KIND_FOOD, FOOD_CHOCOLATE },
    /* 0x3C */ { 1000, ProductInfo::KIND_FOOD, FOOD_RELAX_TEA_LEAVES },
    /* 0x3D */ { 50, ProductInfo::KIND_FOOD, FOOD_SMALL_FISH },
    /* 0x3E */ { 120, ProductInfo::KIND_FOOD, FOOD_MEDIUM_FISH },
    /* 0x3F */ { 200, ProductInfo::KIND_FOOD, FOOD_LARGE_FISH },
    /* 0x40 */ { 10000, ProductInfo::KIND_ARTICLE, ARTICLE_PIRATE_TREASURE },
    /* 0x41 */ { 5000, ProductInfo::KIND_ARTICLE, ARTICLE_FOSSIL_OF_FISH },
    /* 0x42 */ { 200, ProductInfo::KIND_ARTICLE, ARTICLE_RED_MAGIC_GRASS },
    /* 0x43 */ { 100, ProductInfo::KIND_ARTICLE, ARTICLE_WOOL_S },
    /* 0x44 */ { 400, ProductInfo::KIND_ARTICLE, ARTICLE_WOOL_M },
    /* 0x45 */ { 500, ProductInfo::KIND_ARTICLE, ARTICLE_WOOL_L },
    /* 0x46 */ { 600, ProductInfo::KIND_ARTICLE, ARTICLE_WOOL_G },
    /* 0x47 */ { 1000, ProductInfo::KIND_ARTICLE, ARTICLE_WOOL_P },
    /* 0x48 */ { 2000, ProductInfo::KIND_ARTICLE, ARTICLE_WOOL_X },
    /* 0x49 */ { 300, ProductInfo::KIND_ARTICLE, ARTICLE_YARN_S },
    /* 0x4A */ { 700, ProductInfo::KIND_ARTICLE, ARTICLE_YARN_M },
    /* 0x4B */ { 800, ProductInfo::KIND_ARTICLE, ARTICLE_YARN_L },
    /* 0x4C */ { 1000, ProductInfo::KIND_ARTICLE, ARTICLE_YARN_G },
    /* 0x4D */ { 1500, ProductInfo::KIND_ARTICLE, ARTICLE_YARN_P },
    /* 0x4E */ { 4000, ProductInfo::KIND_ARTICLE, ARTICLE_YARN_X },
    /* 0x4F */ { 2000, ProductInfo::KIND_ARTICLE, ARTICLE_BRACELET },
    /* 0x50 */ { 2000, ProductInfo::KIND_ARTICLE, ARTICLE_NECKLACE },
    /* 0x51 */ { 2000, ProductInfo::KIND_ARTICLE, ARTICLE_EARRINGS },
    /* 0x52 */ { 2000, ProductInfo::KIND_ARTICLE, ARTICLE_BROACH },
    /* 0x53 */ { 1, ProductInfo::KIND_ARTICLE, ARTICLE_JUNK_ORE },
    /* 0x54 */ { 15, ProductInfo::KIND_ARTICLE, ARTICLE_COPPER },
    /* 0x55 */ { 20, ProductInfo::KIND_ARTICLE, ARTICLE_SILVER },
    /* 0x56 */ { 25, ProductInfo::KIND_ARTICLE, ARTICLE_GOLD },
    /* 0x57 */ { 40, ProductInfo::KIND_ARTICLE, ARTICLE_MYSTRILE },
    /* 0x58 */ { 50, ProductInfo::KIND_ARTICLE, ARTICLE_ORICHALC },
    /* 0x59 */ { 50, ProductInfo::KIND_ARTICLE, ARTICLE_ADAMANTITE },
    /* 0x5A */ { 20000, ProductInfo::KIND_ARTICLE, ARTICLE_MYTHIC_STONE },
    /* 0x5B */ { 10000, ProductInfo::KIND_ARTICLE, ARTICLE_PINK_DIAMOND },
    /* 0x5C */ { 10000, ProductInfo::KIND_ARTICLE, ARTICLE_ALEXANDRITE },
    /* 0x5D */ { 55, ProductInfo::KIND_ARTICLE, ARTICLE_MOON_STONE },
    /* 0x5E */ { 60, ProductInfo::KIND_ARTICLE, ARTICLE_SAND_ROSE },
    /* 0x5F */ { 100, ProductInfo::KIND_ARTICLE, ARTICLE_DIAMOND },
    /* 0x60 */ { 80, ProductInfo::KIND_ARTICLE, ARTICLE_EMERALD },
    /* 0x61 */ { 75, ProductInfo::KIND_ARTICLE, ARTICLE_RUBY },
    /* 0x62 */ { 70, ProductInfo::KIND_ARTICLE, ARTICLE_TOPAZ },
    /* 0x63 */ { 68, ProductInfo::KIND_ARTICLE, ARTICLE_PERIDOT },
    /* 0x64 */ { 65, ProductInfo::KIND_ARTICLE, ARTICLE_FLUORITE },
    /* 0x65 */ { 62, ProductInfo::KIND_ARTICLE, ARTICLE_AGATE },
    /* 0x66 */ { 60, ProductInfo::KIND_ARTICLE, ARTICLE_AMETHYST },
};

#endif // REGION_JP
