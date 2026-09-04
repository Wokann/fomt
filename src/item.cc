#include "item.hh"

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
    "    .include \"build/jp/data/text/item.s\"\n"
    "    .incbin \"baserom_jp.gba\", 0xE8D74, (0xE9EEC - 0xE8D74)\n"
    "\n"
    "    .global gToolInfo\n"
    "gToolInfo:\n"
    "    .incbin \"baserom_jp.gba\", 0xE9EEC, (0xED3D8 - 0xE9EEC)\n"
    "\n"
    "    .global gFoodInfo\n"
    "gFoodInfo:\n"
    "    .incbin \"baserom_jp.gba\", 0xED3D8, (0xEF738 - 0xED3D8)\n"
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

// Item Info tables

ToolInfo const gToolInfo[] = {
#define o(tag, icon, name, desc) { (name), (icon), (desc) },
#include "data/item/tool.def"
#undef o
};

FoodInfo const gFoodInfo[] = {
#define o(tag, is_drink, stamina, fatigue, icon, name, desc) { (name), (is_drink), (stamina), (fatigue), (icon), (desc) },
#include "data/item/food.def"
#undef o
};

ArticleInfo const gArticleInfo[] = {
#define o(tag, icon, name, desc) { (name), (icon), (desc) },
#include "data/item/article.def"
#undef o
};

ProductInfo const gProductInfo[] = {
#define o(tag, kind, price) { (price), (ProductInfo::KIND_##kind), (kind##_##tag) },
#include "data/item/product.def"
#undef o
};

#endif // REGION_JP
