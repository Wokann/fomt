#include "farm_house.hh"

#include <stdlib.h>

FarmHouse::FarmHouse()
    : upgrade_level(0),
      window_style(0),
      mailbox_style(0),
      doghouse_style(0),
      has_bathroom(false),
      has_fridge(false),
      has_shelf(false),
      has_record_player(false),
      has_large_bed(false),
      has_carpet(false),
      has_vase(false),
      vase_article_id(ARTICLE_NONE),
      has_mirror(false),
      has_clock(false),
      has_stocking(false),
      stocking_article_id(ARTICLE_NONE),
      fireplace_lighted(false),
      has_kitchen(false),
      has_kitchen_knife(false),
      has_kitchen_frying_pan(false),
      has_kitchen_pot(false),
      has_kitchen_mixer(false),
      has_kitchen_whisk(false),
      has_kitchen_rolling_pin(false),
      has_kitchen_oven(false),
      has_kitchen_seasoning_set(false)
{
}

u32 FarmHouse::GetUpgradeLevel() const
{
    return upgrade_level;
}

Fridge const * FarmHouse::GetFridge() const
{
    return !has_fridge ? nullptr : &fridge;
}

Shelf const * FarmHouse::GetShelf() const
{
    return !has_shelf ? nullptr : &shelf;
}

RecordPlayer const * FarmHouse::GetRecordPlayer() const
{
    return !has_record_player ? nullptr : &record_player;
}

u32 FarmHouse::GetWindowStyle() const
{
    return window_style;
}

u32 FarmHouse::GetMailboxStyle() const
{
    return mailbox_style;
}

u32 FarmHouse::GetDoghouseStyle() const
{
    return doghouse_style;
}

bool FarmHouse::HasBathroom() const
{
    return has_bathroom;
}

bool FarmHouse::HasLargeBed() const
{
    return has_large_bed;
}

bool FarmHouse::HasCarpet() const
{
    return has_carpet;
}

bool FarmHouse::HasVase() const
{
    return has_vase;
}

u32 FarmHouse::GetVaseArticleId() const
{
    return vase_article_id;
}

bool FarmHouse::HasMirror() const
{
    return has_mirror;
}

bool FarmHouse::HasClock() const
{
    return has_clock;
}

bool FarmHouse::HasStocking() const
{
    return has_stocking;
}

bool FarmHouse::IsFireplaceLighted() const
{
    return fireplace_lighted;
}

bool FarmHouse::HasKitchen() const
{
    return has_kitchen;
}

bool FarmHouse::HasKitchenKnife() const
{
    return has_kitchen_knife;
}

bool FarmHouse::HasKitchenFryingPan() const
{
    return has_kitchen_frying_pan;
}

bool FarmHouse::HasKitchenPot() const
{
    return has_kitchen_pot;
}

bool FarmHouse::HasKitchenMixer() const
{
    return has_kitchen_mixer;
}

bool FarmHouse::HasKitchenWhisk() const
{
    return has_kitchen_whisk;
}

bool FarmHouse::HasKitchenRollingPin() const
{
    return has_kitchen_rolling_pin;
}

bool FarmHouse::HasKitchenOven() const
{
    return has_kitchen_oven;
}

bool FarmHouse::HasKitchenSeasoningSet() const
{
    return has_kitchen_seasoning_set;
}

u32 FarmHouse::GetStockingArticleId() const
{
    return stocking_article_id;
}

void FarmHouse::UpgradeHouseLevel()
{
    if (upgrade_level < 2)
        upgrade_level++;
}

Fridge * FarmHouse::GetFridge()
{
    return !has_fridge ? nullptr : &fridge;
}

Shelf * FarmHouse::GetShelf()
{
    return !has_shelf ? nullptr : &shelf;
}

RecordPlayer * FarmHouse::GetRecordPlayer()
{
    return !has_record_player ? nullptr : &record_player;
}

void FarmHouse::SetWindowStyle(u32 style_id)
{
    if (upgrade_level > 1)
        window_style = style_id;
}

void FarmHouse::SetMailboxStyle(u32 style_id)
{
    if (upgrade_level > 1)
        mailbox_style = style_id;
}

void FarmHouse::SetDoghouseStyle(u32 style_id)
{
    if (upgrade_level > 1)
        doghouse_style = style_id;
}

void FarmHouse::AddBathroom()
{
    if (upgrade_level == 2)
        has_bathroom = true;
}

void FarmHouse::AddFridge()
{
    if (upgrade_level != 0)
        has_fridge = true;
}

void FarmHouse::AddShelf()
{
    if (upgrade_level != 0)
        has_shelf = true;
}

void FarmHouse::AddRecordPlayer()
{
    has_record_player = true;
}

void FarmHouse::AddLargeBed()
{
    if (upgrade_level > 1)
        has_large_bed = true;
}

void FarmHouse::AddCarpet()
{
    if (upgrade_level != 0)
        has_carpet = true;
}

void FarmHouse::AddVase()
{
    has_vase = true;
}

void FarmHouse::SetVaseArticleId(u32 article_id)
{
    vase_article_id = article_id;

    switch (vase_article_id)
    {
        default:
            vase_article_lifespan = 0;
            break;

        case ARTICLE_MOON_DROP_GRASS:
            vase_article_lifespan = 7;
            break;

        case ARTICLE_BLUE_MAGIC_GRASS:
            vase_article_lifespan = 10;
            break;

        case ARTICLE_PINK_CAT_GRASS:
        case ARTICLE_RED_MAGIC_GRASS:
        case ARTICLE_TOY_FLOWER:
            vase_article_lifespan = 5;
            break;
    }
}

void FarmHouse::AddMirror()
{
    has_mirror = true;
}

void FarmHouse::AddClock()
{
    has_clock = true;
}

void FarmHouse::AddStocking()
{
    has_stocking = true;
}

void FarmHouse::RemoveStocking()
{
    has_stocking = false;
}

void FarmHouse::LightFireplace()
{
    if (upgrade_level > 1 && !fireplace_lighted)
        fireplace_lighted = true;
}

void FarmHouse::AddKitchen()
{
    if (upgrade_level != 0 && GetFridge() != nullptr)
        has_kitchen = true;
}

void FarmHouse::AddKitchenKnife()
{
    if (has_kitchen)
        has_kitchen_knife = true;
}

void FarmHouse::AddKitchenFryingPan()
{
    if (has_kitchen)
        has_kitchen_frying_pan = true;
}

void FarmHouse::AddKitchenPot()
{
    if (has_kitchen)
        has_kitchen_pot = true;
}

void FarmHouse::AddKitchenMixer()
{
    if (has_kitchen)
        has_kitchen_mixer = true;
}

void FarmHouse::AddKitchenWhisk()
{
    if (has_kitchen)
        has_kitchen_whisk = true;
}

void FarmHouse::KitchenRollingPin()
{
    if (has_kitchen)
        has_kitchen_rolling_pin = true;
}

void FarmHouse::AddKitchenOven()
{
    if (has_kitchen)
        has_kitchen_oven = true;
}

void FarmHouse::AddKitchenSeasoningSet()
{
    if (has_kitchen)
        has_kitchen_seasoning_set = true;
}

void FarmHouse::SetStockingArticleId(u32 article_id)
{
    stocking_article_id = article_id;
}

void FarmHouse::DayUpdate(Season season)
{
    fireplace_lighted = false;

    if (!has_vase || (u8)vase_article_id == ARTICLE_NONE)
        return;

    if (vase_article_lifespan)
        vase_article_lifespan--;

    switch (vase_article_id)
    {
        case ARTICLE_MOON_DROP_GRASS:
        case ARTICLE_TOY_FLOWER:
            if (season != SEASON_SPRING)
                vase_article_id = ARTICLE_NONE;

            break;

        case ARTICLE_PINK_CAT_GRASS:
            if (season != SEASON_SUMMER)
                vase_article_id = ARTICLE_NONE;

            break;

        case ARTICLE_BLUE_MAGIC_GRASS:
        case ARTICLE_RED_MAGIC_GRASS:
            if (season != SEASON_AUTUMN)
                vase_article_id = ARTICLE_NONE;

            break;
    }

    if (vase_article_lifespan == 0 && (rand() & 0xFF) <= 100)
        vase_article_id = ARTICLE_NONE;
}

// These source payloads remain in the regional asset container.  The table
// below keeps real relocations to those raw resources rather than embedding
// their ROM addresses in this C++ object.
extern u8 const gUnk_FarmHouseTilePatchResource_000[];
extern u8 const gUnk_FarmHouseTilePatchResource_001[];
extern u8 const gUnk_FarmHouseTilePatchResource_002[];
extern u8 const gUnk_FarmHouseTilePatchResource_003[];
extern u8 const gUnk_FarmHouseTilePatchResource_004[];
extern u8 const gUnk_FarmHouseTilePatchResource_005[];
extern u8 const gUnk_FarmHouseTilePatchResource_006[];
extern u8 const gUnk_FarmHouseTilePatchResource_007[];
extern u8 const gUnk_FarmHouseTilePatchResource_008[];
extern u8 const gUnk_FarmHouseTilePatchResource_009[];
extern u8 const gUnk_FarmHouseTilePatchResource_010[];
extern u8 const gUnk_FarmHouseTilePatchResource_011[];
extern u8 const gUnk_FarmHouseTilePatchResource_012[];
extern u8 const gUnk_FarmHouseTilePatchResource_013[];
extern u8 const gUnk_FarmHouseTilePatchResource_014[];
extern u8 const gUnk_FarmHouseTilePatchResource_015[];
extern u8 const gUnk_FarmHouseTilePatchResource_016[];
extern u8 const gUnk_FarmHouseTilePatchResource_017[];
extern u8 const gUnk_FarmHouseTilePatchResource_018[];
extern u8 const gUnk_FarmHouseTilePatchResource_019[];
extern u8 const gUnk_FarmHouseTilePatchResource_020[];
extern u8 const gUnk_FarmHouseTilePatchResource_021[];
extern u8 const gUnk_FarmHouseTilePatchResource_022[];
extern u8 const gUnk_FarmHouseTilePatchResource_023[];
extern u8 const gUnk_FarmHouseTilePatchResource_024[];
extern u8 const gUnk_FarmHouseTilePatchResource_025[];
extern u8 const gUnk_FarmHouseTilePatchResource_026[];
extern u8 const gUnk_FarmHouseTilePatchResource_027[];

FarmHouseTilePatchData const gFarmHouseTilePatchData SECTION(".rodata.farm_house_tile_patches") = {
    {
        { 0x0099, gUnk_FarmHouseTilePatchResource_000 },
        { 0x0099, gUnk_FarmHouseTilePatchResource_001 },
        { 0x009F, gUnk_FarmHouseTilePatchResource_002 },
        { 0x009F, gUnk_FarmHouseTilePatchResource_003 },
        { 0x00AB, gUnk_FarmHouseTilePatchResource_004 },
        { 0x00AB, gUnk_FarmHouseTilePatchResource_005 },
        { 0x0000, gUnk_FarmHouseTilePatchResource_006 },
    },
    {
        { 0x003D, gUnk_FarmHouseTilePatchResource_007, 0x0010 },
        { 0x003D, gUnk_FarmHouseTilePatchResource_008, 0x0010 },
        { 0x002F, gUnk_FarmHouseTilePatchResource_009, 0x0008 },
        { 0x002F, gUnk_FarmHouseTilePatchResource_010, 0x0008 },
    },
    {
        { 0x0090, gUnk_FarmHouseTilePatchResource_011 },
        { 0x0090, gUnk_FarmHouseTilePatchResource_012 },
        { 0x0000, gUnk_FarmHouseTilePatchResource_013 },
    },
    {
        { 0x0000, gUnk_FarmHouseTilePatchResource_014, 0x000A },
        { 0x0010, gUnk_FarmHouseTilePatchResource_015, 0x000A },
        { 0x0000, gUnk_FarmHouseTilePatchResource_016, 0x000A },
        { 0x0010, gUnk_FarmHouseTilePatchResource_017, 0x000A },
        { 0x0025, gUnk_FarmHouseTilePatchResource_018, 0x000A },
        { 0x0010, gUnk_FarmHouseTilePatchResource_019, 0x000A },
        { 0x0039, gUnk_FarmHouseTilePatchResource_020, 0x000A },
        { 0x0025, gUnk_FarmHouseTilePatchResource_021, 0x000A },
        { 0x0010, gUnk_FarmHouseTilePatchResource_022, 0x000A },
        { 0x0039, gUnk_FarmHouseTilePatchResource_023, 0x000A },
        { 0x0000, gUnk_FarmHouseTilePatchResource_024, 0x001E },
        { 0x001E, gUnk_FarmHouseTilePatchResource_025, 0x0007 },
        { 0x0000, gUnk_FarmHouseTilePatchResource_026, 0x001E },
        { 0x0000, gUnk_FarmHouseTilePatchResource_027, 0x000A },
    },
};
