#ifndef SCENE_MENU_TRANSITIONS_HH
#define SCENE_MENU_TRANSITIONS_HH

#include "scene.hh"
#include "fomt_constants.hh"
#include "gamecube_link_scene.hh"
#include "intro_story_scene.hh"
#include "animal_festival_selection.hh"
#include "name_entry.hh"
#include "scene_minigames.hh"
#include "scene_calendar.hh"
#include "scene_tool_chest.hh"
#include "scene_refrigerator.hh"
#include "scene_shelf.hh"
#include "scene_rucksack.hh"
#include "frisbee_scoreboard.hh"
#include "frisbee.hh"
#include "horse_race.hh"
#include "scene_cooking.hh"
#include "scene_reference_page.hh"
#include "scene_special_merchant_shop.hh"
#include "staff_credits.hh"
#include "scene_gift_wrapping.hh"
#include "scene_yodel_ranch_shop.hh"
#include "scene_poultry_farm_shop.hh"
#include "scene_winery_shop.hh"
#include "scene_inn_shop.hh"
#include "scene_beach_cafe_shop.hh"
#include "scene_won_shop.hh"
#include "scene_carpenter_shop.hh"
#include "scene_clinic_shop.hh"
#include "scene_blacksmith_shop.hh"
#include "scene_supermarket.hh"

#pragma interface "scene_menu_transitions.hh"

struct GameStateSaveImage;

// These menu requests share one contiguous native factory/destructor range.
// agbcp emits their virtual tables in reverse class-declaration order.
// Constructors stay inline at their callers. Each virtual factory and its
// implicit destructor are emitted together by scene_menu_transitions.cc.
struct SupermarketTransition : SceneTransition {
    SupermarketTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__16SupermarketSceneG20SceneTransitionOwnerP18GameStateSaveImage(::operator new(sizeof(SupermarketScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct SupermarketPurchaseTransition : SceneTransition {
    SupermarketPurchaseTransition(SceneTransitionOwner next, GameStateSaveImage * image,
        MarySupermarketItemId item);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__24SupermarketPurchaseSceneG20SceneTransitionOwnerP18GameStateSaveImage21MarySupermarketItemId(::operator new(sizeof(SupermarketPurchaseScene)),
            &next, save, item_id));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MarySupermarketItemId item_id;
};

struct BlacksmithShopTransition : SceneTransition {
    // The initial visit has no selected tool, ore or pending commission.
    BlacksmithShopTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__19BlacksmithShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUcUiUiUiUi(
            ::operator new(sizeof(BlacksmithShopScene)), &next, save,
            has_purchased, tool_id, ore_id, order_price, work_days));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 tool_id;
    u32 ore_id;
    u32 order_price;
    u32 work_days;
    u8 has_purchased;
};

struct ClinicShopTransition : SceneTransition {
    ClinicShopTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__15ClinicShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(ClinicShopScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct CarpenterShopTransition : SceneTransition {
    CarpenterShopTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__18CarpenterShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(CarpenterShopScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct WonShopTransition : SceneTransition {
    WonShopTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__12WonShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(::operator new(sizeof(WonShopScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct BeachCafeShopTransition : SceneTransition {
    BeachCafeShopTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__18BeachCafeShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(BeachCafeShopScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct InnShopTransition : SceneTransition {
    InnShopTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__12InnShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(InnShopScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct WineryShopTransition : SceneTransition {
    WineryShopTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__15WineryShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(WineryShopScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct PoultryFarmShopTransition : SceneTransition {
    PoultryFarmShopTransition(SceneTransitionOwner next, GameStateSaveImage * image, u32 input);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__20PoultryFarmShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUi(
            ::operator new(sizeof(PoultryFarmShopScene)), &next, save, unk_0C));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 unk_0C;
};

struct YodelRanchShopTransition : SceneTransition {
    YodelRanchShopTransition(SceneTransitionOwner next, GameStateSaveImage * image, u32 input);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__19YodelRanchShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUi(
            ::operator new(sizeof(YodelRanchShopScene)), &next, save, unk_0C));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 unk_0C;
};

struct GiftWrappingTransition : SceneTransition {
    GiftWrappingTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__17GiftWrappingSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(GiftWrappingScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct StaffCreditsTransition : SceneTransition {
    StaffCreditsTransition(SceneTransitionOwner next);
    virtual SceneOwner CreateScene()
    {
        return SceneOwner(new StaffCreditsScene(continuation));
    }
    SceneTransitionOwner continuation;
};

struct SpecialMerchantShopTransition : SceneTransition {
    SpecialMerchantShopTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__24SpecialMerchantShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(SpecialMerchantShopScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct ReferencePageTransition : SceneTransition {
    ReferencePageTransition(SceneTransitionOwner next, GameStateSaveImage * image, i32 page);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__18ReferencePageSceneG20SceneTransitionOwnerP18GameStateSaveImagei(
            ::operator new(sizeof(ReferencePageScene)), &next, save, page_id));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    i32 page_id;
};

struct CookingTransition : SceneTransition {
    CookingTransition(SceneTransitionOwner next, GameStateSaveImage * image, u8 show_recipes);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__12CookingSceneG20SceneTransitionOwnerP18GameStateSaveImageUc(
            ::operator new(sizeof(CookingScene)), &next, save, recipe_list));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u8 recipe_list;
};

struct HorseRaceTransition : SceneTransition {
    HorseRaceTransition(SceneTransitionOwner next, GameStateSaveImage * image, bool compete);
    virtual SceneOwner CreateScene()
    {
        return SceneOwner(new HorseRaceScene(continuation, save, player_competes));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    bool player_competes;
};

struct HorseRaceMedalExchangeTransition : SceneTransition {
    HorseRaceMedalExchangeTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__27HorseRaceMedalExchangeSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(HorseRaceMedalExchangeScene)), &next, save));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct FrisbeeTransition : SceneTransition {
    FrisbeeTransition(SceneTransitionOwner next, GameStateSaveImage * image, bool contest);
    virtual SceneOwner CreateScene()
    {
        return SceneOwner(new FrisbeeScene(continuation, save, contest_mode));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    bool contest_mode;
};

struct FrisbeeScoreboardTransition : SceneTransition {
    FrisbeeScoreboardTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__22FrisbeeScoreboardSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(FrisbeeScoreboardScene)), &next, save));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct RucksackMenuTransition : SceneTransition {
    RucksackMenuTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(ConstructRucksackMenuScene(
            ::operator new(sizeof(RucksackMenuScene)), &next, save));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct ToolChestTransition : SceneTransition {
    ToolChestTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__14ToolChestSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(ToolChestScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct ShelfTransition : SceneTransition {
    ShelfTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__10ShelfSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(ShelfScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct RefrigeratorTransition : SceneTransition {
    RefrigeratorTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__17RefrigeratorSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(RefrigeratorScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct CalendarTransition : SceneTransition {
    CalendarTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(__13CalendarSceneG20SceneTransitionOwnerP18GameStateSaveImage(
            ::operator new(sizeof(CalendarScene)), &next, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct ChickenFestivalContestTransition : SceneTransition {
    ChickenFestivalContestTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        return SceneOwner(new ChickenFestivalContestScene(continuation, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

struct HarvestSpriteAnimalCareTransition : SceneTransition {
    HarvestSpriteAnimalCareTransition(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id);
    virtual SceneOwner CreateScene()
    {
        return SceneOwner(new HarvestSpriteAnimalCareScene(continuation, save, sprite_id));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

struct HarvestSpriteHarvestingTransition : SceneTransition {
    HarvestSpriteHarvestingTransition(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id);
    virtual SceneOwner CreateScene()
    {
        return SceneOwner(new HarvestSpriteHarvestingScene(continuation, save, sprite_id));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

struct HarvestSpriteWateringTransition : SceneTransition {
    HarvestSpriteWateringTransition(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id);
    virtual SceneOwner CreateScene()
    {
        return SceneOwner(new HarvestSpriteWateringScene(continuation, save, sprite_id));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

struct SavedNameEntryTransition : SceneTransition {
    SavedNameEntryTransition(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryNameEntryKind input_kind, u8 index);
    virtual SceneOwner CreateScene()
    {
        return SceneOwner(new SavedNameEntryScene(continuation, save, kind, target_index));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryNameEntryKind kind;
    u8 target_index;
};

struct FestivalAnimalSelectionTransition : SceneTransition {
    FestivalAnimalSelectionTransition(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryFestivalAnimalKind input_kind);
    virtual SceneOwner CreateScene()
    {
        return SceneOwner(new FestivalAnimalSelectionScene(continuation, save, kind));
    }
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryFestivalAnimalKind kind;
};

struct IntroStoryTransition : SceneTransition
{
    IntroStoryTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        SceneTransition * next = continuation.release();
        return SceneOwner(new IntroStoryScene(next, saved));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * saved;
};

struct GameCubeLinkTransition : SceneTransition {
    GameCubeLinkTransition(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneOwner CreateScene()
    {
        return SceneOwner(new GameCubeLinkScene(continuation, save));
    }

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char GameCubeLinkTransitionSizeCheck[sizeof(GameCubeLinkTransition) == 12 ? 1 : -1];
typedef char IntroStoryTransitionSizeCheck[sizeof(IntroStoryTransition) == 12 ? 1 : -1];
typedef char IntroStoryTransitionContinuationOffsetCheck[offsetof(IntroStoryTransition, continuation) == 4 ? 1 : -1];
typedef char IntroStoryTransitionSavedOffsetCheck[offsetof(IntroStoryTransition, saved) == 8 ? 1 : -1];
typedef char FestivalAnimalSelectionTransitionSizeCheck[sizeof(FestivalAnimalSelectionTransition) == 16 ? 1 : -1];
typedef char FestivalAnimalSelectionTransitionContinuationCheck[offsetof(FestivalAnimalSelectionTransition, continuation) == 4 ? 1 : -1];
typedef char FestivalAnimalSelectionTransitionSaveCheck[offsetof(FestivalAnimalSelectionTransition, save) == 8 ? 1 : -1];
typedef char FestivalAnimalSelectionTransitionKindCheck[offsetof(FestivalAnimalSelectionTransition, kind) == 12 ? 1 : -1];
typedef char SavedNameEntryTransitionSizeCheck[sizeof(SavedNameEntryTransition) == 20 ? 1 : -1];
typedef char SavedNameEntryTransitionContinuationCheck[offsetof(SavedNameEntryTransition, continuation) == 4 ? 1 : -1];
typedef char SavedNameEntryTransitionSaveCheck[offsetof(SavedNameEntryTransition, save) == 8 ? 1 : -1];
typedef char SavedNameEntryTransitionKindCheck[offsetof(SavedNameEntryTransition, kind) == 12 ? 1 : -1];
typedef char SavedNameEntryTransitionIndexCheck[offsetof(SavedNameEntryTransition, target_index) == 16 ? 1 : -1];
typedef char HarvestSpriteWateringTransitionSizeCheck[sizeof(HarvestSpriteWateringTransition) == 16 ? 1 : -1];
typedef char HarvestSpriteHarvestingTransitionSizeCheck[sizeof(HarvestSpriteHarvestingTransition) == 16 ? 1 : -1];
typedef char HarvestSpriteAnimalCareTransitionSizeCheck[sizeof(HarvestSpriteAnimalCareTransition) == 16 ? 1 : -1];
typedef char ChickenFestivalContestTransitionSizeCheck[sizeof(ChickenFestivalContestTransition) == 12 ? 1 : -1];
typedef char ChickenFestivalContestTransitionContinuationCheck[offsetof(ChickenFestivalContestTransition, continuation) == 4 ? 1 : -1];
typedef char ChickenFestivalContestTransitionSaveCheck[offsetof(ChickenFestivalContestTransition, save) == 8 ? 1 : -1];
typedef char CalendarTransitionSizeCheck[sizeof(CalendarTransition) == 12 ? 1 : -1];
typedef char ToolChestTransitionSizeCheck[sizeof(ToolChestTransition) == 12 ? 1 : -1];
typedef char RefrigeratorTransitionSizeCheck[sizeof(RefrigeratorTransition) == 12 ? 1 : -1];
typedef char ShelfTransitionSizeCheck[sizeof(ShelfTransition) == 12 ? 1 : -1];
typedef char RucksackMenuTransitionSizeCheck[sizeof(RucksackMenuTransition) == 12 ? 1 : -1];
typedef char RucksackMenuTransitionContinuationCheck[offsetof(RucksackMenuTransition, continuation) == 4 ? 1 : -1];
typedef char RucksackMenuTransitionSaveCheck[offsetof(RucksackMenuTransition, save) == 8 ? 1 : -1];
typedef char FrisbeeScoreboardTransitionSizeCheck[sizeof(FrisbeeScoreboardTransition) == 12 ? 1 : -1];
typedef char FrisbeeScoreboardTransitionContinuationCheck[offsetof(FrisbeeScoreboardTransition, continuation) == 4 ? 1 : -1];
typedef char FrisbeeScoreboardTransitionSaveCheck[offsetof(FrisbeeScoreboardTransition, save) == 8 ? 1 : -1];
typedef char FrisbeeTransitionSizeCheck[sizeof(FrisbeeTransition) == 16 ? 1 : -1];
typedef char FrisbeeTransitionContinuationCheck[offsetof(FrisbeeTransition, continuation) == 4 ? 1 : -1];
typedef char FrisbeeTransitionSaveCheck[offsetof(FrisbeeTransition, save) == 8 ? 1 : -1];
typedef char FrisbeeTransitionModeCheck[offsetof(FrisbeeTransition, contest_mode) == 12 ? 1 : -1];
typedef char HorseRaceMedalExchangeTransitionSizeCheck[sizeof(HorseRaceMedalExchangeTransition) == 12 ? 1 : -1];
typedef char HorseRaceMedalExchangeTransitionContinuationCheck[offsetof(HorseRaceMedalExchangeTransition, continuation) == 4 ? 1 : -1];
typedef char HorseRaceMedalExchangeTransitionSaveCheck[offsetof(HorseRaceMedalExchangeTransition, save) == 8 ? 1 : -1];
typedef char HorseRaceTransitionSizeCheck[sizeof(HorseRaceTransition) == 16 ? 1 : -1];
typedef char HorseRaceTransitionContinuationCheck[offsetof(HorseRaceTransition, continuation) == 4 ? 1 : -1];
typedef char HorseRaceTransitionSaveCheck[offsetof(HorseRaceTransition, save) == 8 ? 1 : -1];
typedef char HorseRaceTransitionModeCheck[offsetof(HorseRaceTransition, player_competes) == 12 ? 1 : -1];
typedef char CookingTransitionSizeCheck[sizeof(CookingTransition) == 16 ? 1 : -1];
typedef char CookingTransitionSaveCheck[offsetof(CookingTransition, save) == 8 ? 1 : -1];
typedef char CookingTransitionModeCheck[offsetof(CookingTransition, recipe_list) == 12 ? 1 : -1];
typedef char ReferencePageTransitionSizeCheck[sizeof(ReferencePageTransition) == 16 ? 1 : -1];
typedef char SpecialMerchantShopTransitionSizeCheck[sizeof(SpecialMerchantShopTransition) == 12 ? 1 : -1];
typedef char StaffCreditsTransitionSizeCheck[sizeof(StaffCreditsTransition) == 8 ? 1 : -1];
typedef char GiftWrappingTransitionSizeCheck[sizeof(GiftWrappingTransition) == 12 ? 1 : -1];
typedef char YodelRanchShopTransitionSizeCheck[sizeof(YodelRanchShopTransition) == 16 ? 1 : -1];
typedef char PoultryFarmShopTransitionSizeCheck[sizeof(PoultryFarmShopTransition) == 16 ? 1 : -1];
typedef char WineryShopTransitionSizeCheck[sizeof(WineryShopTransition) == 12 ? 1 : -1];
typedef char InnShopTransitionSizeCheck[sizeof(InnShopTransition) == 12 ? 1 : -1];
typedef char BeachCafeShopTransitionSizeCheck[sizeof(BeachCafeShopTransition) == 12 ? 1 : -1];
typedef char WonShopTransitionSizeCheck[sizeof(WonShopTransition) == 12 ? 1 : -1];
typedef char CarpenterShopTransitionSizeCheck[sizeof(CarpenterShopTransition) == 12 ? 1 : -1];
typedef char ClinicShopTransitionSizeCheck[sizeof(ClinicShopTransition) == 12 ? 1 : -1];
typedef char BlacksmithShopTransitionSizeCheck[sizeof(BlacksmithShopTransition) == 32 ? 1 : -1];
typedef char BlacksmithShopTransitionByteCheck[offsetof(BlacksmithShopTransition, has_purchased) == 28 ? 1 : -1];
typedef char SupermarketPurchaseTransitionSizeCheck[sizeof(SupermarketPurchaseTransition) == 16 ? 1 : -1];
typedef char SupermarketPurchaseTransitionItemCheck[offsetof(SupermarketPurchaseTransition, item_id) == 12 ? 1 : -1];
typedef char SupermarketTransitionSizeCheck[sizeof(SupermarketTransition) == 12 ? 1 : -1];

#pragma interface "game_scene.hh"

inline SupermarketTransition::SupermarketTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline SupermarketPurchaseTransition::SupermarketPurchaseTransition(SceneTransitionOwner next, GameStateSaveImage * image,
        MarySupermarketItemId item)
    : continuation(next), save(image), item_id(item) {}

inline BlacksmithShopTransition::BlacksmithShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image), tool_id(ITEM_TOOL_NONE), ore_id(ITEM_ARTICLE_NONE),
          order_price(0), work_days(0), has_purchased(0) {}

inline ClinicShopTransition::ClinicShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline CarpenterShopTransition::CarpenterShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline WonShopTransition::WonShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline BeachCafeShopTransition::BeachCafeShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline InnShopTransition::InnShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline WineryShopTransition::WineryShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline PoultryFarmShopTransition::PoultryFarmShopTransition(SceneTransitionOwner next, GameStateSaveImage * image, u32 input)
    : continuation(next), save(image), unk_0C(input) {}

inline YodelRanchShopTransition::YodelRanchShopTransition(SceneTransitionOwner next, GameStateSaveImage * image, u32 input)
    : continuation(next), save(image), unk_0C(input) {}

inline GiftWrappingTransition::GiftWrappingTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline StaffCreditsTransition::StaffCreditsTransition(SceneTransitionOwner next)
    : continuation(next) {}

inline SpecialMerchantShopTransition::SpecialMerchantShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline ReferencePageTransition::ReferencePageTransition(SceneTransitionOwner next, GameStateSaveImage * image, i32 page)
    : continuation(next), save(image), page_id(page) {}

inline CookingTransition::CookingTransition(SceneTransitionOwner next, GameStateSaveImage * image, u8 show_recipes)
    : continuation(next), save(image), recipe_list(show_recipes) {}

inline HorseRaceTransition::HorseRaceTransition(SceneTransitionOwner next, GameStateSaveImage * image, bool compete)
    : continuation(next), save(image), player_competes(compete) {}

inline HorseRaceMedalExchangeTransition::HorseRaceMedalExchangeTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline FrisbeeTransition::FrisbeeTransition(SceneTransitionOwner next, GameStateSaveImage * image, bool contest)
    : continuation(next), save(image), contest_mode(contest) {}

inline FrisbeeScoreboardTransition::FrisbeeScoreboardTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline RucksackMenuTransition::RucksackMenuTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline ToolChestTransition::ToolChestTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline ShelfTransition::ShelfTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline RefrigeratorTransition::RefrigeratorTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline CalendarTransition::CalendarTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline ChickenFestivalContestTransition::ChickenFestivalContestTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline HarvestSpriteAnimalCareTransition::HarvestSpriteAnimalCareTransition(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
    : continuation(next), save(image), sprite_id(id) {}

inline HarvestSpriteHarvestingTransition::HarvestSpriteHarvestingTransition(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
    : continuation(next), save(image), sprite_id(id) {}

inline HarvestSpriteWateringTransition::HarvestSpriteWateringTransition(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
    : continuation(next), save(image), sprite_id(id) {}

inline SavedNameEntryTransition::SavedNameEntryTransition(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryNameEntryKind input_kind, u8 index)
    : continuation(next), save(image), kind(input_kind), target_index(index) {}

inline FestivalAnimalSelectionTransition::FestivalAnimalSelectionTransition(SceneTransitionOwner next, GameStateSaveImage * image,
        MaryFestivalAnimalKind input_kind)
    : continuation(next), save(image), kind(input_kind) {}

inline IntroStoryTransition::IntroStoryTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), saved(image) {}

inline GameCubeLinkTransition::GameCubeLinkTransition(SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}


#endif // SCENE_MENU_TRANSITIONS_HH
