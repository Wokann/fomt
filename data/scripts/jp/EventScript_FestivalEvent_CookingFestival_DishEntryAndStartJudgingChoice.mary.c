#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_HaveYouBroughtADishPlayer[] =
        "{Player}くん、\r\n"
        "料理は持ってきたかい？{Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_IHave[] =
        "持ってきた";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_IHaveNot[] =
        "持ってきていない";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_ISeeYouDontHaveAnything[] =
        "料理を持っていないみたい\r\n"
        "だね。{Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_PlaceYourDishAlongWithEverybody[] =
        "じゃあ、キミの料理も\r\n"
        "ならべよう。{Press}\p"
        "グルメマンが、一番いいと\r\n"
        "思った料理を作った人が\r\n"
        "優勝になるんだよ。{Press}\p"
        "もう、審査を始めて\r\n"
        "もらってもいいかな？{Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_Yes[] =
        "はい";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_No[] =
        "いいえ";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_LetTheJudgingBeginGourmetGo[] =
        "それじゃあ、今からグルメマン\r\n"
        "に審査を始めてもらおう。{Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_WellWhenYoureReadyJustLet[] =
        "そうかい。\r\n"
        "じゃあ、審査を始めてもよく\r\n"
        "なったらまた、わたしに声を{Press}\r\n"
        "かけてくれ。{Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_WedLikeToBeginTheJudging[] =
        "じゃあ、誰が優勝するか見て\r\n"
        "いくといいよ。\r\n"
        "審査を始めてもいいかな？{Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_CanWeBeginTheJudgingNow[] =
        "もう、審査を始めて\r\n"
        "もらってもいいかな？{Press}";

    const char gText_FestivalEvent_CookingFestival_DishEntryAndStartJudgingChoice_WeCantBeginTheJudgingIf[] =
        "うーん、物を持ってたら審査を\r\n"
        "始められないよ。どこかに\r\n"
        "しまってくれないかな？{Press}";
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
