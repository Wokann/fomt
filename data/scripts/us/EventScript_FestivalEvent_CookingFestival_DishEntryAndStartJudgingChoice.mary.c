#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_HaveYouBroughtADishPlayer[] =
        "Have you brought a dish, \r\n"
        "{Player}? {Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_IHave[] =
        "I have.";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_IHaveNot[] =
        "I have not.";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_ISeeYouDontHaveAnything[] =
        "I see you don't have \r\n"
        "anything with you. {Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_PlaceYourDishAlongWithEverybody[] =
        "Place your dish along with \r\n"
        "everybody else's. {Press}\p"
        "The Gourmet will try them\r\n"
        "all and declare the winner.{Press}\p"
        "Can we start now?{Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_Yes[] =
        "Yes.";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_No[] =
        "No.";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_LetTheJudgingBeginGourmetGo[] =
        "Let the judging begin!\r\n"
        "Gourmet, go to it!{Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_WellWhenYoureReadyJustLet[] =
        "Well, when you're ready \r\n"
        "just let us know. {Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_WedLikeToBeginTheJudging[] =
        "We'd like to begin the \r\n"
        "judging now. Alright? {Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_CanWeBeginTheJudgingNow[] =
        "Can we begin the judging\r\n"
        " now? {Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_WeCantBeginTheJudgingIf[] =
        "We can't begin the judging \r\n"
        "if you're still holding onto\r\n"
        "your entry, you know! {Press}";
};

void EventScript_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice(void)
{
    int var_0, var_1;
    switch (GetPlayerHeldItemKind())
    {
        case HELD_ITEM_KIND_FOOD:
            switch (GetPlayerHeldFoodId())
            {
                case ITEM_FOOD_X_EGG:
                case ITEM_FOOD_MAYONNAISE_S:
                case ITEM_FOOD_MAYONNAISE_M:
                case ITEM_FOOD_MAYONNAISE_L:
                case ITEM_FOOD_MAYONNAISE_G:
                case ITEM_FOOD_MAYONNAISE_P:
                case ITEM_FOOD_MAYONNAISE_X:
                case ITEM_FOOD_MILK_X:
                case ITEM_FOOD_CHEESE_X:
                case ITEM_FOOD_BODIGIZER_XL:
                case ITEM_FOOD_TURBOJOLT_XL:
                case ITEM_FOOD_GRAPE_JUICE:
                case ITEM_FOOD_RICE_BALL:
                case ITEM_FOOD_BREAD:
                case ITEM_FOOD_WILD_GRAPE_JUICE:
                case ITEM_FOOD_SALAD:
                case ITEM_FOOD_CURRY_RICE:
                case ITEM_FOOD_STEW:
                case ITEM_FOOD_MISO_SOUP:
                case ITEM_FOOD_STIR_FRY:
                case ITEM_FOOD_FRIED_RICE:
                case ITEM_FOOD_SAVORY_PANCAKE:
                case ITEM_FOOD_SANDWICH:
                case ITEM_FOOD_FRUIT_JUICE:
                case ITEM_FOOD_VEGETABLE_JUICE:
                case ITEM_FOOD_MIXED_JUICE:
                case ITEM_FOOD_FRUIT_LATTE:
                case ITEM_FOOD_VEGETABLE_LATTE:
                case ITEM_FOOD_MIXED_LATTE:
                case ITEM_FOOD_STRAWBERRY_MILK:
                case ITEM_FOOD_STRAWBERRY_JAM:
                case ITEM_FOOD_TOMATO_JUICE:
                case ITEM_FOOD_PICKLED_TURNIP:
                case ITEM_FOOD_FRENCH_FRIES:
                case ITEM_FOOD_PICKLES:
                case ITEM_FOOD_KETCHUP:
                case ITEM_FOOD_POPCORN:
                case ITEM_FOOD_CORN_FLAKES:
                case ITEM_FOOD_BAKED_CORN:
                case ITEM_FOOD_PINEAPPLE_JUICE:
                case ITEM_FOOD_PUMPKIN_PUDDING:
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
                case ITEM_FOOD_CHEESE_CAKE:
                case ITEM_FOOD_CHEESE_FONDUE:
                case ITEM_FOOD_APPLE_PIE:
                case ITEM_FOOD_APPLE_JAM:
                case ITEM_FOOD_APPLE_SOUFFLE:
                case ITEM_FOOD_MUSHROOM_RICE:
                case ITEM_FOOD_BAMBOO_RICE:
                case ITEM_FOOD_TRUFFLE_RICE:
                case ITEM_FOOD_SUSHI:
                case ITEM_FOOD_JAM_BUN:
                case ITEM_FOOD_DINNER_ROLL:
                case ITEM_FOOD_RAISIN_BREAD:
                case ITEM_FOOD_GRAPE_JAM:
                case ITEM_FOOD_CURRY_BREAD:
                case ITEM_FOOD_SASHIMI:
                case ITEM_FOOD_GRILLED_FISH:
                case ITEM_FOOD_CHIRASHI_SUSHI:
                case ITEM_FOOD_PIZZA:
                case ITEM_FOOD_NOODLES:
                case ITEM_FOOD_CURRY_NOODLES:
                case ITEM_FOOD_TEMPURA_NOODLES:
                case ITEM_FOOD_FRIED_NOODLES:
                case ITEM_FOOD_BUCKWHEAT_NOODLES:
                case ITEM_FOOD_NOODLES_W_TEMPURA:
                case ITEM_FOOD_FRIED_BUCKWHEAT_NOODLES:
                case ITEM_FOOD_BUCKWHEAT_CHIPS:
                case ITEM_FOOD_COOKIES:
                case ITEM_FOOD_CHOCOLATE_COOKIES:
                case ITEM_FOOD_TEMPURA:
                case ITEM_FOOD_ICE_CREAM:
                case ITEM_FOOD_CAKE:
                case ITEM_FOOD_CHOCOLATE_CAKE:
                case ITEM_FOOD_RELAXATION_TEA:
                case ITEM_FOOD_TOAST:
                case ITEM_FOOD_FRENCH_TOAST:
                case ITEM_FOOD_PUDDING:
                case ITEM_FOOD_MOUNTAIN_STEW:
                case ITEM_FOOD_MOON_DUMPLINGS:
                case ITEM_FOOD_RICE_CAKE:
                case ITEM_FOOD_ROASTED_RICE_CAKE:
                case ITEM_FOOD_ELLI_LEAVES:
                case ITEM_FOOD_FAILED_DISH:
                case ITEM_FOOD_FAILED_DRINK:
                case ITEM_FOOD_FAILED_POT_DISH:
                case ITEM_FOOD_FAILED_DESSERT:
                case ITEM_FOOD_FAILED_BREAD:
                case ITEM_FOOD_FAILED_NOODLES:
                case ITEM_FOOD_TOASTED_RICE_BALL:
                case ITEM_FOOD_TEMPURA_RICE:
                case ITEM_FOOD_EGG_OVER_RICE_OR_EGG_BOWL:
                case ITEM_FOOD_RICE_GRUEL:
                case ITEM_FOOD_PANCAKES:
                case ITEM_FOOD_FISH_STICKS:
                case ITEM_FOOD_CANDIED_POTATO:
                case ITEM_FOOD_POTATO_PANCAKES_OR_CROQUETTE:
                    var_1 = 15;
                    break;
            }
            break;
    }
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
    if (VarGet(VAR_COOKING_FESTIVAL_PLAYER_ENTERED) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_HaveYouBroughtADishPlayer);
        TalkClose();
        TalkOpen();
        var_0 = TalkChoice2(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_IHave, gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_IHaveNot);
        switch (var_0)
        {
            case CHOICE_OPTION_1:
                TalkClose();
                TalkOpen();
                if (IsPlayerHoldingNothing())
                {
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_ISeeYouDontHaveAnything);
                    TalkClose();
                }
                else
                {
                    if (var_1 == 15)
                    {
                        VarSet(VAR_COOKING_FESTIVAL_PLAYER_ENTERED, TRUE);
                        VarSet(VAR_COOKING_FESTIVAL_PLAYER_DISH_RATING, GetCookingFestivalDishRating());
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_PlaceYourDishAlongWithEverybody);
                        TalkClose();
                        UsePlayerHeldItem();
                        TalkOpen();
                        var_0 = TalkChoice2(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_Yes, gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_No);
                        switch (var_0)
                        {
                            case CHOICE_OPTION_1:
                                TalkClose();
                                TalkOpen();
                                SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_LetTheJudgingBeginGourmetGo);
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                CallScript(EventScript_FestivalEvent_CookingFestival_Judging);
                                break;
                            case CHOICE_OPTION_2:
                                TalkClose();
                                TalkOpen();
                                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_WellWhenYoureReadyJustLet);
                                TalkClose();
                                break;
                        }
                    }
                    else
                    {
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_ISeeYouDontHaveAnything);
                        TalkClose();
                    }
                }
                break;
            case CHOICE_OPTION_2:
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_WedLikeToBeginTheJudging);
                TalkClose();
                TalkOpen();
                var_0 = TalkChoice2(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_Yes, gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_No);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_LetTheJudgingBeginGourmetGo);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        CallScript(EventScript_FestivalEvent_CookingFestival_Judging);
                        break;
                    case CHOICE_OPTION_2:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_WellWhenYoureReadyJustLet);
                        TalkClose();
                        break;
                }
                break;
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_CanWeBeginTheJudgingNow);
        TalkClose();
        TalkOpen();
        var_0 = TalkChoice2(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_Yes, gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_No);
        switch (var_0)
        {
            case CHOICE_OPTION_1:
                if (IsPlayerHoldingNothing())
                {
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_LetTheJudgingBeginGourmetGo);
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    CallScript(EventScript_FestivalEvent_CookingFestival_Judging);
                }
                else
                {
                    TalkClose();
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_THOMAS);
                    TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_WeCantBeginTheJudgingIf);
                    TalkClose();
                }
                break;
            case CHOICE_OPTION_2:
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_WellWhenYoureReadyJustLet);
                TalkClose();
                break;
        }
    }
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
}
