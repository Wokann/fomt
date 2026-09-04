#include "item.hh"

static inline bool IsValidFoodId(u8 id)
{
    return id < NUM_FOODS;
}

Tool::Tool(u32 a_id)
{
    id = a_id;
}

int Tool::GetId() const
{
    return id;
}

#if defined(REGION_JP)
/*
 * Byte-exact JP assembly stays in this module.  As matching functions are
 * recovered, keep shared definitions outside the regional guard and retain
 * only genuinely version-specific definitions inside it.
 */
asm(
    "    @ JP revision 0 counterpart of src/item.cc.\n"
    "    @\n"
    "    @ The item method bodies retain their US boundaries, while the localized\n"
    "    @ item descriptions and names form one JP-only data block.  Both ranges\n"
    "    @ were matched directly against baserom_jp.gba.\n"
    "\n"
    "    .section .text\n"
    "    .syntax unified\n"
    "    .thumb\n"
    "\n"
    "    .macro jp_item_func name, start, end\n"
    "        .global \\name\n"
    "        .thumb_func\n"
    "\\name:\n"
    "        .incbin \"baserom_jp.gba\", \\start, (\\end - \\start)\n"
    "    .endm\n"
    "\n"
    "    jp_item_func GetName__C4Tool, 0xDB14, 0xDB40\n"
    "    jp_item_func GetIconId__C4Tool, 0xDB40, 0xDB6C\n"
    "    jp_item_func GetDesc__C4Tool, 0xDB6C, 0xDBA8\n"
    "    jp_item_func __9ToolStack, 0xDBA8, 0xDBC0\n"
    "    jp_item_func __9ToolStackG4ToolUi, 0xDBC0, 0xDBF0\n"
    "    jp_item_func GetTool__C9ToolStack, 0xDBF0, 0xDC14\n"
    "    jp_item_func IsEmpty__C9ToolStack, 0xDC14, 0xDC28\n"
    "    jp_item_func GetAmount__C9ToolStack, 0xDC28, 0xDC3C\n"
    "    jp_item_func AddAmount__9ToolStackUi, 0xDC3C, 0xDC6C\n"
    "    jp_item_func SubtractAmount__9ToolStackUi, 0xDC6C, 0xDC88\n"
    "    @ Keep later shared C++ emission in agbcp's default syntax mode.\n"
    "    .syntax divided\n"
);
#else

#include <algorithm>

struct ToolInfo
{
    /* +00 */ char const * name;
    /* +04 */ u16 icon_id;
    /* +08 */ char const * desc;
};

struct FoodInfo
{
    /* +00 */ char const * name;
    /* +04 */ bool is_drink : 1;
    /* +05 */ i8 stamina;
    /* +06 */ i8 fatigue;
    /* +08 */ u16 icon_id;
    /* +0C */ char const * desc;
};

struct ArticleInfo
{
    /* +00 */ char const * name;
    /* +04 */ u16 icon_id;
    /* +08 */ char const * desc;
};

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

extern ToolInfo const gToolInfo[];
extern FoodInfo const gFoodInfo[];
extern ArticleInfo const gArticleInfo[];
extern ProductInfo const gProductInfo[];

static inline bool IsValidToolId(u8 id)
{
    return id < NUM_TOOLS;
}

static inline bool IsValidArticleId(u8 id)
{
    return id < NUM_ARTICLES;
}

static inline bool IsValidProductId(u8 id)
{
    return id < NUM_PRODUCTS;
}

char const * Tool::GetName() const
{
    if (IsValidToolId(id))
        return gToolInfo[id].name;

    return "Broken Tool";
}

u16 Tool::GetIconId() const
{
    if (IsValidToolId(id))
        return gToolInfo[id].icon_id;

    // TODO: icon id constants
    return 457; // Turnip
}

static inline char const * GetToolDescById(u32 id)
{
    if (gToolInfo[id].desc != nullptr)
        return gToolInfo[id].desc;

    return "No Explanation";
}

char const * Tool::GetDesc() const
{
    if (IsValidToolId(id))
        return GetToolDescById(id);

    return "No Explanation";
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
        amount = *(u8 *)&std::min<u32>(MAX_AMOUNT, a_amount);
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
        amount = std::min<u32>(MAX_AMOUNT, amount + a_amount);
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

#endif // REGION_JP

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

#if defined(REGION_JP)
asm(
    "    .section .text\n"
    "    .syntax unified\n"
    "    .thumb\n"
    "\n"
    "    jp_item_func GetName__C4Food, 0xDC98, 0xDCC0\n"
    "    jp_item_func GetIconId__C4Food, 0xDCC0, 0xDCE8\n"
    "    jp_item_func GetStaminaGain__C4Food, 0xDCE8, 0xDD1C\n"
    "    jp_item_func GetFatigueGain__C4Food, 0xDD1C, 0xDD4C\n"
    "\n"
    "    .syntax divided\n"
);
#else

char const * Food::GetName() const
{
    if (IsValidFoodId(id))
        return gFoodInfo[id].name;

    return "Broken Food";
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

#endif // REGION_JP

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

#if defined(REGION_JP)
asm(
    "    .section .text\n"
    "    .syntax unified\n"
    "    .thumb\n"
    "    .incbin \"baserom_jp.gba\", 0xDD8A, 0x2\n"
    "\n"
    "    jp_item_func IsDrink__C4Food, 0xDD8C, 0xDDB4\n"
    "    jp_item_func GetDesc__C4Food, 0xDDB4, 0xDDEC\n"
    "\n"
    "    .syntax divided\n"
);
#else

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

    return "No Explanation";
}

char const * Food::GetDesc() const
{
    if (IsValidFoodId(id))
        return GetFoodDescById(id);

    return "No Explanation";
}

#endif // REGION_JP

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

#if defined(REGION_JP)
asm(
    "    .section .text\n"
    "    .syntax unified\n"
    "    .thumb\n"
    "    .incbin \"baserom_jp.gba\", 0xDE5E, 0x2\n"
    "\n"
    "    jp_item_func __9FoodStackG4FoodUi, 0xDE60, 0xDE98\n"
    "    jp_item_func GetFood__C9FoodStack, 0xDE98, 0xDEBC\n"
    "\n"
    "    .syntax divided\n"
);
#else

FoodStack::FoodStack(Food food, u32 a_amount)
    : Food(food)
{
    if (a_amount != 0)
    {
        // ugh
        amount = *(u8 *)&std::min<u32>(MAX_AMOUNT, a_amount);
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

#endif // REGION_JP

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

#if defined(REGION_JP)
asm(
    "    .section .text\n"
    "    .syntax unified\n"
    "    .thumb\n"
    "\n"
    "    jp_item_func AddAmount__9FoodStackUi, 0xDEE4, 0xDF14\n"
    "\n"
    "    .syntax divided\n"
);
#else

void FoodStack::AddAmount(u32 a_amount)
{
    if (amount != 0)
    {
        amount = std::min<u32>(MAX_AMOUNT, amount + a_amount);
    }
}

#endif // REGION_JP

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

#if defined(REGION_JP)
asm(
    "    .section .text\n"
    "    .syntax unified\n"
    "    .thumb\n"
    "    .incbin \"baserom_jp.gba\", 0xDF2E, 0x2\n"
    "\n"
    "    jp_item_func __7ArticleUi, 0xDF30, 0xDF34\n"
    "    jp_item_func GetId__C7Article, 0xDF34, 0xDF38\n"
    "    jp_item_func GetName__C7Article, 0xDF38, 0xDF64\n"
    "    jp_item_func GetIconId__C7Article, 0xDF64, 0xDF90\n"
    "    jp_item_func CanBeDiscarded__C7Article, 0xDF90, 0xDFB4\n"
    "    jp_item_func GetDesc__C7Article, 0xDFB4, 0xDFF0\n"
    "    jp_item_func __12ArticleStack, 0xDFF0, 0xE008\n"
    "    jp_item_func __12ArticleStackG7ArticleUi, 0xE008, 0xE038\n"
    "    jp_item_func GetArticle__C12ArticleStack, 0xE038, 0xE05C\n"
    "    jp_item_func IsEmpty__C12ArticleStack, 0xE05C, 0xE070\n"
    "    jp_item_func GetAmount__C12ArticleStack, 0xE070, 0xE084\n"
    "    jp_item_func AddAmount__12ArticleStackUi, 0xE084, 0xE0B4\n"
    "    jp_item_func SubtractAmount__12ArticleStackUi, 0xE0B4, 0xE0D0\n"
    "    jp_item_func __7Product, 0xE0D0, 0xE0D8\n"
    "    jp_item_func __7ProductUi, 0xE0D8, 0xE0DC\n"
    "    jp_item_func __7ProductG4Food, 0xE0DC, 0xE128\n"
    "    jp_item_func __7ProductG7Article, 0xE128, 0xE174\n"
    "    jp_item_func GetId__C7Product, 0xE174, 0xE178\n"
    "    jp_item_func GetPrice__C7Product, 0xE178, 0xE1A0\n"
    "    jp_item_func GetName__C7Product, 0xE1A0, 0xE1F4\n"
    "    jp_item_func GetIconId__C7Product, 0xE1F4, 0xE248\n"
    "    jp_item_func AsTool__C11ItemVariant, 0xE248, 0xE270\n"
    "    jp_item_func AsFood__C11ItemVariant, 0xE270, 0xE298\n"
    "    jp_item_func AsArticle__C11ItemVariant, 0xE298, 0xE2C4\n"
    "\n"
    "    .section .rodata\n"
    "jp_item_data_start:\n"
    "    .incbin \"baserom_jp.gba\", 0xE8AB4, (0xE9EEC - 0xE8AB4)\n"
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

Article::Article(u32 a_id)
{
    id = a_id;
}

int Article::GetId() const
{
    return id;
}

char const * Article::GetName() const
{
    if (IsValidArticleId(id))
        return gArticleInfo[id].name;

    return "Broken Article";
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

    return "No Explanation";
}

char const * Article::GetDesc() const
{
    if (IsValidArticleId(id))
        return GetArticleDescById(id);

    return "No Explanation";
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
        amount = *(u8 *)&std::min<u32>(MAX_AMOUNT, a_amount);
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
        amount = std::min<u32>(MAX_AMOUNT, amount + a_amount);
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

    return "Broken Shipment";
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
