#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_NoHeldItemResponse[] =
        "Wie es scheint, hast du \r\n"
        "nichts.  Du solltest \r\n"
        "etwas mitbringen.{Press}";

    const char gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_AsksWhetherPlayerBroughtIngredient[] =
        "Hi, {Player}. \r\n"
        "Hast du etwas für den \r\n"
        "Eintopf mitgebracht?{Press}";

    const char gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_ConfirmContributionChoice[] =
        "Habe ich.";

    const char gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_DeclineContributionChoice[] =
        "Habe ich nicht.";

    const char gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_AcceptsHeldFoodContribution[] =
        "Das hast du mitgebracht?\r\n"
        "Schmeißen wir es hinein\r\n"
        "und essen es!{Press}";

    const char gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_RejectsNonFoodContribution[] =
        "Soll das ein Witz sein?\r\n"
        "Das können wir \r\n"
        "nicht hineintun! {Press}";

    const char gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_DeclinedContributionResponse[] =
        "Wie es scheint, hast du \r\n"
        "nichts. Du solltest \r\n"
        "etwas mitbringen.{Press}";
};

void EventScript_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas(void)
{
    int unused_0, var_1;
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    if (IsPlayerHoldingNothing())
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
        TalkMessage(gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_NoHeldItemResponse);
        TalkClose();
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        TalkMessage(gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_AsksWhetherPlayerBroughtIngredient);
        TalkClose();
        TalkOpen();
        var_1 = TalkChoice2(gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_ConfirmContributionChoice, gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_DeclineContributionChoice);
        switch (var_1)
        {
            case CHOICE_OPTION_1:
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_FOOD)
                {
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    TalkMessage(gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_AcceptsHeldFoodContribution);
                    TalkClose();
                    switch (GetPlayerHeldItemKind())
                    {
                        case HELD_ITEM_KIND_FOOD:
                            switch (GetPlayerHeldFoodId())
                            {
                                case ITEM_FOOD_TURNIP:
                                case ITEM_FOOD_POTATO:
                                case ITEM_FOOD_CUCUMBER:
                                case ITEM_FOOD_STRAWBERRY:
                                case ITEM_FOOD_CABBAGE:
                                case ITEM_FOOD_TOMATO:
                                case ITEM_FOOD_CORN:
                                case ITEM_FOOD_ONION:
                                case ITEM_FOOD_PUMPKIN:
                                case ITEM_FOOD_PINEAPPLE:
                                case ITEM_FOOD_EGGPLANT:
                                case ITEM_FOOD_CARROT:
                                case ITEM_FOOD_SWEET_POTATO:
                                case ITEM_FOOD_SPINACH:
                                case ITEM_FOOD_GREEN_PEPPER:
                                case ITEM_FOOD_REGULAR_QUALITY_EGG:
                                case ITEM_FOOD_GOOD_QUALITY_EGG:
                                case ITEM_FOOD_HIGH_QUALITY_EGG:
                                case ITEM_FOOD_GOLDEN_EGG:
                                case ITEM_FOOD_P_EGG:
                                case ITEM_FOOD_X_EGG:
                                case ITEM_FOOD_SPA_BOILED_EGG:
                                case ITEM_FOOD_MILK_S:
                                case ITEM_FOOD_MILK_M:
                                case ITEM_FOOD_MILK_L:
                                case ITEM_FOOD_MILK_G:
                                case ITEM_FOOD_MILK_P:
                                case ITEM_FOOD_MILK_X:
                                case ITEM_FOOD_CHEESE_S:
                                case ITEM_FOOD_CHEESE_M:
                                case ITEM_FOOD_CHEESE_L:
                                case ITEM_FOOD_CHEESE_G:
                                case ITEM_FOOD_CHEESE_P:
                                case ITEM_FOOD_CHEESE_X:
                                case ITEM_FOOD_APPLE:
                                case ITEM_FOOD_HONEY:
                                case ITEM_FOOD_BAMBOO_SHOOT:
                                case ITEM_FOOD_WILD_GRAPES:
                                case ITEM_FOOD_MUSHROOM:
                                case ITEM_FOOD_TRUFFLE:
                                case ITEM_FOOD_BLUE_GRASS:
                                case ITEM_FOOD_GREEN_GRASS:
                                case ITEM_FOOD_YELLOW_GRASS:
                                case ITEM_FOOD_ORANGE_GRASS:
                                case ITEM_FOOD_PURPLE_GRASS:
                                case ITEM_FOOD_INDIGO_GRASS:
                                case ITEM_FOOD_BLACK_GRASS:
                                case ITEM_FOOD_WHITE_GRASS:
                                case ITEM_FOOD_BODIGIZER:
                                case ITEM_FOOD_BODIGIZER_XL:
                                case ITEM_FOOD_TURBOJOLT:
                                case ITEM_FOOD_TURBOJOLT_XL:
                                case ITEM_FOOD_WINE:
                                case ITEM_FOOD_RICE_BALL:
                                case ITEM_FOOD_FLOUR:
                                case ITEM_FOOD_CURRY_POWDER:
                                case ITEM_FOOD_MUFFIN_MIX_OR_RICE_FLOUR:
                                case ITEM_FOOD_CHOCOLATE:
                                case ITEM_FOOD_RELAX_TEA_LEAVES:
                                case ITEM_FOOD_SUGDW_APPLE:
                                case ITEM_FOOD_HMSGB_APPLE:
                                case ITEM_FOOD_AEPFE_APPLE:
                                case ITEM_FOOD_BUCKWHEAT_FLOUR:
                                case ITEM_FOOD_WILD_GRAPE_JUICE:
                                case ITEM_FOOD_SALAD:
                                case ITEM_FOOD_CURRY_RICE:
                                case ITEM_FOOD_STEW:
                                case ITEM_FOOD_MISO_SOUP:
                                case ITEM_FOOD_STIR_FRY:
                                case ITEM_FOOD_FRIED_RICE:
                                case ITEM_FOOD_SAVORY_PANCAKE:
                                case ITEM_FOOD_SANDWICH:
                                case ITEM_FOOD_VEGETABLE_JUICE:
                                case ITEM_FOOD_VEGETABLE_LATTE:
                                case ITEM_FOOD_TOMATO_JUICE:
                                case ITEM_FOOD_PICKLED_TURNIP:
                                case ITEM_FOOD_FRENCH_FRIES:
                                case ITEM_FOOD_PICKLES:
                                case ITEM_FOOD_KETCHUP:
                                case ITEM_FOOD_CORN_FLAKES:
                                case ITEM_FOOD_BAKED_CORN:
                                case ITEM_FOOD_PUMPKIN_STEW:
                                case ITEM_FOOD_HAPPY_EGGPLANT:
                                case ITEM_FOOD_SWEET_POTATOES:
                                case ITEM_FOOD_BAKED_SWEET_POTATO:
                                case ITEM_FOOD_GREENS:
                                case ITEM_FOOD_SCRAMBLED_EGGS_OR_JAPANESE_OMELET:
                                case ITEM_FOOD_OMELET:
                                case ITEM_FOOD_OMELET_RICE:
                                case ITEM_FOOD_BOILED_EGG:
                                case ITEM_FOOD_HOT_MILK:
                                case ITEM_FOOD_BUTTER:
                                case ITEM_FOOD_CHEESE_FONDUE:
                                case ITEM_FOOD_APPLE_SOUFFLE:
                                case ITEM_FOOD_MUSHROOM_RICE:
                                case ITEM_FOOD_BAMBOO_RICE:
                                case ITEM_FOOD_TRUFFLE_RICE:
                                case ITEM_FOOD_SUSHI:
                                case ITEM_FOOD_CURRY_BREAD:
                                case ITEM_FOOD_SASHIMI:
                                case ITEM_FOOD_GRILLED_FISH:
                                case ITEM_FOOD_CHIRASHI_SUSHI:
                                case ITEM_FOOD_NOODLES:
                                case ITEM_FOOD_CURRY_NOODLES:
                                case ITEM_FOOD_TEMPURA_NOODLES:
                                case ITEM_FOOD_FRIED_NOODLES:
                                case ITEM_FOOD_BUCKWHEAT_NOODLES:
                                case ITEM_FOOD_NOODLES_W_TEMPURA:
                                case ITEM_FOOD_BUCKWHEAT_CHIPS:
                                case ITEM_FOOD_TEMPURA:
                                case ITEM_FOOD_RELAXATION_TEA:
                                case ITEM_FOOD_TOAST:
                                case ITEM_FOOD_FRENCH_TOAST:
                                case ITEM_FOOD_MOUNTAIN_STEW:
                                case ITEM_FOOD_MOON_DUMPLINGS:
                                case ITEM_FOOD_RICE_CAKE:
                                case ITEM_FOOD_ROASTED_RICE_CAKE:
                                case ITEM_FOOD_ELLI_LEAVES:
                                case ITEM_FOOD_SMALL_FISH:
                                case ITEM_FOOD_MEDIUM_FISH:
                                case ITEM_FOOD_LARGE_FISH:
                                case ITEM_FOOD_TOASTED_RICE_BALL:
                                case ITEM_FOOD_TEMPURA_RICE:
                                case ITEM_FOOD_EGG_OVER_RICE_OR_EGG_BOWL:
                                case ITEM_FOOD_RICE_GRUEL:
                                case ITEM_FOOD_FISH_STICKS:
                                case ITEM_FOOD_CANDIED_POTATO:
                                case ITEM_FOOD_POTATO_PANCAKES_OR_CROQUETTE:
                                    VarSet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED, FALSE);
                                    break;
                                case ITEM_FOOD_MAYONNAISE_S:
                                case ITEM_FOOD_MAYONNAISE_M:
                                case ITEM_FOOD_MAYONNAISE_L:
                                case ITEM_FOOD_MAYONNAISE_G:
                                case ITEM_FOOD_MAYONNAISE_P:
                                case ITEM_FOOD_MAYONNAISE_X:
                                case ITEM_FOOD_POISONOUS_MUSHROOM:
                                case ITEM_FOOD_RED_GRASS:
                                case ITEM_FOOD_GRAPE_JUICE:
                                case ITEM_FOOD_BREAD:
                                case ITEM_FOOD_OIL:
                                case ITEM_FOOD_FRUIT_JUICE:
                                case ITEM_FOOD_MIXED_JUICE:
                                case ITEM_FOOD_FRUIT_LATTE:
                                case ITEM_FOOD_MIXED_LATTE:
                                case ITEM_FOOD_STRAWBERRY_MILK:
                                case ITEM_FOOD_STRAWBERRY_JAM:
                                case ITEM_FOOD_POPCORN:
                                case ITEM_FOOD_PINEAPPLE_JUICE:
                                case ITEM_FOOD_PUMPKIN_PUDDING:
                                case ITEM_FOOD_CHEESE_CAKE:
                                case ITEM_FOOD_APPLE_PIE:
                                case ITEM_FOOD_APPLE_JAM:
                                case ITEM_FOOD_JAM_BUN:
                                case ITEM_FOOD_DINNER_ROLL:
                                case ITEM_FOOD_RAISIN_BREAD:
                                case ITEM_FOOD_GRAPE_JAM:
                                case ITEM_FOOD_PIZZA:
                                case ITEM_FOOD_FRIED_BUCKWHEAT_NOODLES:
                                case ITEM_FOOD_COOKIES:
                                case ITEM_FOOD_CHOCOLATE_COOKIES:
                                case ITEM_FOOD_ICE_CREAM:
                                case ITEM_FOOD_CAKE:
                                case ITEM_FOOD_CHOCOLATE_CAKE:
                                case ITEM_FOOD_PUDDING:
                                case ITEM_FOOD_FAILED_DISH:
                                case ITEM_FOOD_FAILED_DRINK:
                                case ITEM_FOOD_FAILED_POT_DISH:
                                case ITEM_FOOD_FAILED_DESSERT:
                                case ITEM_FOOD_FAILED_BREAD:
                                case ITEM_FOOD_FAILED_NOODLES:
                                case ITEM_FOOD_PANCAKES:
                                    VarSet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED, TRUE);
                                    break;
                            }
                            break;
                    }
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    UsePlayerHeldItem();
                    CallScript(EventScript_FestivalEvent_HarvestFestival_CookingSequence);
                }
                else
                {
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    TalkMessage(gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_RejectsNonFoodContribution);
                    TalkClose();
                }
                break;
            case CHOICE_OPTION_2:
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_FestivalEvent_HarvestFestival_IngredientContributionChoice_Thomas_DeclinedContributionResponse);
                TalkClose();
                break;
        }
    }
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
}
