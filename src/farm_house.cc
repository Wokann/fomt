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
extern u8 const gUnk_FarmHouseTilePatchAnimationResource_000[];
extern u8 const gUnk_FarmHouseTilePatchAnimationResource_001[];

extern u8 const gUnk_FarmHouseVisualResource_000[];
extern u8 const gUnk_FarmHouseVisualResource_001[];
extern u8 const gUnk_FarmHouseVisualResource_002[];
extern u8 const gUnk_FarmHouseVisualResource_003[];
extern u8 const gUnk_FarmHouseVisualResource_004[];
extern u8 const gUnk_FarmHouseVisualResource_005[];
extern u8 const gUnk_FarmHouseVisualResource_006[];
extern u8 const gUnk_FarmHouseVisualResource_007[];
extern u8 const gUnk_FarmHouseVisualResource_008[];
extern u8 const gUnk_FarmHouseVisualResource_009[];
extern u8 const gUnk_FarmHouseVisualResource_010[];
extern u8 const gUnk_FarmHouseVisualResource_011[];
extern u8 const gUnk_FarmHouseVisualResource_012[];
extern u8 const gUnk_FarmHouseVisualResource_013[];
extern u8 const gUnk_FarmHouseVisualResource_014[];
extern u8 const gUnk_FarmHouseVisualResource_015[];
extern u8 const gUnk_FarmHouseVisualResource_016[];
extern u8 const gUnk_FarmHouseVisualResource_017[];
extern u8 const gUnk_FarmHouseVisualResource_018[];
extern u8 const gUnk_FarmHouseVisualResource_019[];
extern u8 const gUnk_FarmHouseVisualResource_020[];
extern u8 const gUnk_FarmHouseVisualResource_021[];
extern u8 const gUnk_FarmHouseVisualResource_022[];
extern u8 const gUnk_FarmHouseVisualResource_023[];
extern u8 const gUnk_FarmHouseVisualResource_024[];
extern u8 const gUnk_FarmHouseVisualResource_025[];
extern u8 const gUnk_FarmHouseVisualResource_026[];
extern u8 const gUnk_FarmHouseVisualResource_027[];
extern u8 const gUnk_FarmHouseVisualResource_028[];
extern u8 const gUnk_FarmHouseVisualResource_029[];
extern u8 const gUnk_FarmHouseVisualResource_030[];
extern u8 const gUnk_FarmHouseVisualResource_031[];
extern u8 const gUnk_FarmHouseVisualResource_032[];
extern u8 const gUnk_FarmHouseVisualResource_033[];
extern u8 const gUnk_FarmHouseVisualResource_034[];
extern u8 const gUnk_FarmHouseVisualResource_035[];
extern u8 const gUnk_FarmHouseVisualResource_036[];
extern u8 const gUnk_FarmHouseVisualResource_037[];
extern u8 const gUnk_FarmHouseVisualResource_038[];
extern u8 const gUnk_FarmHouseVisualResource_039[];
extern u8 const gUnk_FarmHouseVisualResource_040[];
extern u8 const gUnk_FarmHouseVisualResource_041[];
extern u8 const gUnk_FarmHouseVisualResource_042[];

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

FarmHouseTilePatchAnimationDescriptor const gFarmHouseTilePatchAnimations[2]
    SECTION(".rodata.farm_house_tile_patch_animations") = {
        { 0x0200, gUnk_FarmHouseTilePatchAnimationResource_000, 0x000C },
        { 0x0212, gUnk_FarmHouseTilePatchAnimationResource_001, 0x0008 },
    };

// The original next object starts on a four-byte boundary.  The linker, not
// this type, emits the one-byte zero gap after this packed 9-byte payload.
FarmHouseStyleNibbleLookupData const gFarmHouseStyleNibbleLookupData
    SECTION(".rodata.farm_house_style_nibble_lookup") ALIGN(1) = {
        { 0x05, 0x06, 0x08 },
        { 0x05, 0x06, 0x05 },
        { 0x05, 0x01, 0x01 },
    };

FarmHouseVisualDescriptor const gFarmHouseVisualDescriptors[7] SECTION(".rodata.farm_house_visual_descriptors") = {
    {
        { 0x06, 0x04,
          { gUnk_FarmHouseVisualResource_000, gUnk_FarmHouseVisualResource_001, nullptr },
          gUnk_FarmHouseVisualResource_002, gUnk_FarmHouseVisualResource_003 },
        gUnk_FarmHouseVisualResource_004, 0x00000180,
        { gUnk_FarmHouseVisualResource_005, nullptr }, 0x0A, 0x01,
    },
    {
        { 0x15, 0x05,
          { gUnk_FarmHouseVisualResource_006, gUnk_FarmHouseVisualResource_007, nullptr },
          gUnk_FarmHouseVisualResource_008, gUnk_FarmHouseVisualResource_009 },
        gUnk_FarmHouseVisualResource_010, 0x000001C0,
        { gUnk_FarmHouseVisualResource_011, gUnk_FarmHouseVisualResource_012 }, 0x09, 0x03,
    },
    {
        { 0x15, 0x05,
          { gUnk_FarmHouseVisualResource_013, gUnk_FarmHouseVisualResource_014, nullptr },
          gUnk_FarmHouseVisualResource_008, gUnk_FarmHouseVisualResource_009 },
        gUnk_FarmHouseVisualResource_015, 0x000001C0,
        { gUnk_FarmHouseVisualResource_016, gUnk_FarmHouseVisualResource_017 }, 0x09, 0x03,
    },
    {
        { 0x0D, 0x0C,
          { gUnk_FarmHouseVisualResource_018, gUnk_FarmHouseVisualResource_019, nullptr },
          gUnk_FarmHouseVisualResource_020, gUnk_FarmHouseVisualResource_021 },
        gUnk_FarmHouseVisualResource_022, 0x00000200,
        { gUnk_FarmHouseVisualResource_023, nullptr }, 0x07, 0x01,
    },
    {
        { 0x18, 0x1B,
          { gUnk_FarmHouseVisualResource_024, gUnk_FarmHouseVisualResource_025, nullptr },
          gUnk_FarmHouseVisualResource_026, gUnk_FarmHouseVisualResource_027 },
        gUnk_FarmHouseVisualResource_028, 0x00000200,
        { gUnk_FarmHouseVisualResource_029, nullptr }, 0x07, 0x03,
    },
    {
        { 0x04, 0x05,
          { gUnk_FarmHouseVisualResource_030, gUnk_FarmHouseVisualResource_031, nullptr },
          gUnk_FarmHouseVisualResource_032, gUnk_FarmHouseVisualResource_033 },
        gUnk_FarmHouseVisualResource_034, 0x00000220,
        { gUnk_FarmHouseVisualResource_035, gUnk_FarmHouseVisualResource_036 }, 0x07, 0x01,
    },
    {
        { 0x0C, 0x0C,
          { gUnk_FarmHouseVisualResource_037, gUnk_FarmHouseVisualResource_038, nullptr },
          gUnk_FarmHouseVisualResource_039, gUnk_FarmHouseVisualResource_040 },
        gUnk_FarmHouseVisualResource_041, 0x00000200,
        { gUnk_FarmHouseVisualResource_042, nullptr }, 0x07, 0x04,
    },
};
