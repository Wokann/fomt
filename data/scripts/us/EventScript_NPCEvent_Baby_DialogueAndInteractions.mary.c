#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantFavorableGiftWithChildNearbyResponse[] =
        "Goo!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantFavoriteGiftOrHighFriendshipRepeatResponse[] =
        "Hee hee hee!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantMediumFriendshipRepeatOrYoungChildLikedGiftOrFavorableAnimalResponse[] =
        "Gaaa...gaa....{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantNeutralGiftResponse[] =
        "Ooof!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantDislikedGiftOrYoungChildLowFriendshipRepeatResponse[] =
        "Geee! {Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantHatedGiftResponse[] =
        "Da...?{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantFavorableAnimalResponse[] =
        "Ta...ta...!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantUnfavorableAnimalResponse[] =
        "Ppphhtt!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantAccessoryOrCosmeticResponse[] =
        "?{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantPerfumeResponse[] =
        "Cough...cough...{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildFavoriteGiftResponse[] =
        "Yah! Gaaa...gaa....{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildLikedGiftResponse[] =
        "Heee...hee...{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildNeutralGiftResponse[] =
        "Choof...{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildDislikedGiftResponse[] =
        "Moooomoo.{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildHatedGiftOrUnfavorableAnimalResponse[] =
        "Noooo...!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildAccessoryOrCosmeticGiftResponse[] =
        "??{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildPerfumeResponse[] =
        "Mmm...??{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildFavorableGiftWithChildNearbyResponse[] =
        "Mooommy...\r\n"
        "Daaadaa...Keessh!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildFavoriteGiftResponse[] =
        "Yah!\r\n"
        "Keeshu, keeshu!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildLikedGiftResponse[] =
        "Dada, dada...{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildNeutralGiftResponse[] =
        "Da-boom!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildDislikedGiftResponse[] =
        "No, noooo!...{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildHatedGiftResponse[] =
        "Yahhh!!..{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildFavorableAnimalResponse[] =
        "Goo...gaaa... Upppp.{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildUnfavorableAnimalResponse[] =
        "Noooo!...\r\n"
        "Tha-way, tha-way!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildAccessoryOrCosmeticResponse[] =
        "Gooo....{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildPerfumeResponse[] =
        "Goo, good?{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantLowFriendshipFirstConversation[] =
        "Boo...baa....boo...{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantLowFriendshipRepeatConversation[] =
        "Geeba!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantMediumFriendshipFirstConversation[] =
        "Da?...{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_InfantHighFriendshipFirstConversation[] =
        "Da...boo...{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildUnder200DaysFirstConversation[] =
        "Maa....ma....{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildUnder200DaysRepeatConversation[] =
        "Shaa...da...{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_YoungChild200To254DaysFirstConversation[] =
        "Dada...Mooning!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_YoungChild200To254DaysRepeatConversation[] =
        "Maa... Nigh-nigh.{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildFirstConversation[] =
        "Dada...wooff...look!{Press}";

    const char gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildRepeatConversation[] =
        "Dada...wooff....{Press}";
};

void EventScript_NPCEvent_Baby_DialogueAndInteractions(void)
{
    int var_0, var_1, var_2;
    if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_NOT_YET)
    {
        SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_PRE_WALKING_IDLE);
    }
    else
    {
        SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_WALKING_IDLE);
    }
    var_2 = GetEntityFacing(ENTITY_CHILD);
    SetEntityFacing(ENTITY_CHILD, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    if (IsPlayerHoldingNothing())
    {
        var_0 = NPC_INTERACTION_NO_APPLICABLE_GIFT;
    }
    else
    {
        if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_NOT_YET)
        {
            switch (GetPlayerHeldItemKind())
            {
                case HELD_ITEM_KIND_FOOD:
                    switch (GetPlayerHeldFoodId())
                    {
                        case ITEM_FOOD_HONEY:
                        case ITEM_FOOD_WILD_GRAPES:
                        case ITEM_FOOD_GRAPE_JUICE:
                        case ITEM_FOOD_STRAWBERRY_MILK:
                        case ITEM_FOOD_HOT_MILK:
                        case ITEM_FOOD_CHEESE_CAKE:
                        case ITEM_FOOD_NOODLES:
                        case ITEM_FOOD_ICE_CREAM:
                        case ITEM_FOOD_CAKE:
                        case ITEM_FOOD_PANCAKES:
                            var_0 = NPC_INTERACTION_FAVORITE_GIFT;
                            break;
                        case ITEM_FOOD_STRAWBERRY:
                        case ITEM_FOOD_PINEAPPLE:
                        case ITEM_FOOD_CARROT:
                        case ITEM_FOOD_MAYONNAISE_S:
                        case ITEM_FOOD_MAYONNAISE_M:
                        case ITEM_FOOD_MAYONNAISE_L:
                        case ITEM_FOOD_MAYONNAISE_G:
                        case ITEM_FOOD_MAYONNAISE_P:
                        case ITEM_FOOD_MAYONNAISE_X:
                        case ITEM_FOOD_MILK_S:
                        case ITEM_FOOD_MILK_M:
                        case ITEM_FOOD_MILK_L:
                        case ITEM_FOOD_MILK_G:
                        case ITEM_FOOD_MILK_P:
                        case ITEM_FOOD_MILK_X:
                        case ITEM_FOOD_APPLE:
                        case ITEM_FOOD_CHOCOLATE:
                        case ITEM_FOOD_RELAX_TEA_LEAVES:
                        case ITEM_FOOD_SUGDW_APPLE:
                        case ITEM_FOOD_HMSGB_APPLE:
                        case ITEM_FOOD_AEPFE_APPLE:
                        case ITEM_FOOD_FRUIT_JUICE:
                        case ITEM_FOOD_VEGETABLE_JUICE:
                        case ITEM_FOOD_MIXED_JUICE:
                        case ITEM_FOOD_FRUIT_LATTE:
                        case ITEM_FOOD_VEGETABLE_LATTE:
                        case ITEM_FOOD_MIXED_LATTE:
                        case ITEM_FOOD_TOMATO_JUICE:
                        case ITEM_FOOD_PINEAPPLE_JUICE:
                        case ITEM_FOOD_PUMPKIN_PUDDING:
                        case ITEM_FOOD_SWEET_POTATOES:
                        case ITEM_FOOD_OMELET:
                        case ITEM_FOOD_APPLE_SOUFFLE:
                        case ITEM_FOOD_CHOCOLATE_CAKE:
                        case ITEM_FOOD_CANDIED_POTATO:
                            var_0 = NPC_INTERACTION_LIKED_GIFT;
                            break;
                        case ITEM_FOOD_TOMATO:
                        case ITEM_FOOD_PUMPKIN:
                        case ITEM_FOOD_SPINACH:
                        case ITEM_FOOD_REGULAR_QUALITY_EGG:
                        case ITEM_FOOD_GOOD_QUALITY_EGG:
                        case ITEM_FOOD_HIGH_QUALITY_EGG:
                        case ITEM_FOOD_GOLDEN_EGG:
                        case ITEM_FOOD_P_EGG:
                        case ITEM_FOOD_X_EGG:
                        case ITEM_FOOD_SPA_BOILED_EGG:
                        case ITEM_FOOD_RICE_BALL:
                        case ITEM_FOOD_BREAD:
                        case ITEM_FOOD_MUFFIN_MIX_OR_RICE_FLOUR:
                        case ITEM_FOOD_SALAD:
                        case ITEM_FOOD_STEW:
                        case ITEM_FOOD_MISO_SOUP:
                        case ITEM_FOOD_SANDWICH:
                        case ITEM_FOOD_STRAWBERRY_JAM:
                        case ITEM_FOOD_FRENCH_FRIES:
                        case ITEM_FOOD_KETCHUP:
                        case ITEM_FOOD_POPCORN:
                        case ITEM_FOOD_CORN_FLAKES:
                        case ITEM_FOOD_PUMPKIN_STEW:
                        case ITEM_FOOD_HAPPY_EGGPLANT:
                        case ITEM_FOOD_BAKED_SWEET_POTATO:
                        case ITEM_FOOD_GREENS:
                        case ITEM_FOOD_SCRAMBLED_EGGS_OR_JAPANESE_OMELET:
                        case ITEM_FOOD_OMELET_RICE:
                        case ITEM_FOOD_BOILED_EGG:
                        case ITEM_FOOD_APPLE_PIE:
                        case ITEM_FOOD_APPLE_JAM:
                        case ITEM_FOOD_JAM_BUN:
                        case ITEM_FOOD_DINNER_ROLL:
                        case ITEM_FOOD_RAISIN_BREAD:
                        case ITEM_FOOD_GRAPE_JAM:
                        case ITEM_FOOD_GRILLED_FISH:
                        case ITEM_FOOD_RELAXATION_TEA:
                        case ITEM_FOOD_TOAST:
                        case ITEM_FOOD_FRENCH_TOAST:
                        case ITEM_FOOD_PUDDING:
                        case ITEM_FOOD_MOUNTAIN_STEW:
                        case ITEM_FOOD_MOON_DUMPLINGS:
                        case ITEM_FOOD_RICE_CAKE:
                        case ITEM_FOOD_ROASTED_RICE_CAKE:
                        case ITEM_FOOD_TOASTED_RICE_BALL:
                        case ITEM_FOOD_EGG_OVER_RICE_OR_EGG_BOWL:
                        case ITEM_FOOD_RICE_GRUEL:
                            var_0 = NPC_INTERACTION_NEUTRAL_GIFT;
                            break;
                        case ITEM_FOOD_TURNIP:
                        case ITEM_FOOD_POTATO:
                        case ITEM_FOOD_CUCUMBER:
                        case ITEM_FOOD_CABBAGE:
                        case ITEM_FOOD_CORN:
                        case ITEM_FOOD_ONION:
                        case ITEM_FOOD_EGGPLANT:
                        case ITEM_FOOD_SWEET_POTATO:
                        case ITEM_FOOD_GREEN_PEPPER:
                        case ITEM_FOOD_CHEESE_S:
                        case ITEM_FOOD_CHEESE_M:
                        case ITEM_FOOD_CHEESE_L:
                        case ITEM_FOOD_CHEESE_G:
                        case ITEM_FOOD_CHEESE_P:
                        case ITEM_FOOD_CHEESE_X:
                        case ITEM_FOOD_MUSHROOM:
                        case ITEM_FOOD_RED_GRASS:
                        case ITEM_FOOD_BODIGIZER:
                        case ITEM_FOOD_BODIGIZER_XL:
                        case ITEM_FOOD_TURBOJOLT:
                        case ITEM_FOOD_TURBOJOLT_XL:
                        case ITEM_FOOD_WINE:
                        case ITEM_FOOD_BUCKWHEAT_FLOUR:
                        case ITEM_FOOD_WILD_GRAPE_JUICE:
                        case ITEM_FOOD_CURRY_RICE:
                        case ITEM_FOOD_STIR_FRY:
                        case ITEM_FOOD_FRIED_RICE:
                        case ITEM_FOOD_SAVORY_PANCAKE:
                        case ITEM_FOOD_PICKLED_TURNIP:
                        case ITEM_FOOD_PICKLES:
                        case ITEM_FOOD_BAKED_CORN:
                        case ITEM_FOOD_BUTTER:
                        case ITEM_FOOD_CHEESE_FONDUE:
                        case ITEM_FOOD_MUSHROOM_RICE:
                        case ITEM_FOOD_BAMBOO_RICE:
                        case ITEM_FOOD_TRUFFLE_RICE:
                        case ITEM_FOOD_SUSHI:
                        case ITEM_FOOD_CURRY_BREAD:
                        case ITEM_FOOD_SASHIMI:
                        case ITEM_FOOD_CHIRASHI_SUSHI:
                        case ITEM_FOOD_PIZZA:
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
                        case ITEM_FOOD_FAILED_DISH:
                        case ITEM_FOOD_FAILED_DRINK:
                        case ITEM_FOOD_FAILED_POT_DISH:
                        case ITEM_FOOD_FAILED_DESSERT:
                        case ITEM_FOOD_FAILED_BREAD:
                        case ITEM_FOOD_FAILED_NOODLES:
                        case ITEM_FOOD_SMALL_FISH:
                        case ITEM_FOOD_MEDIUM_FISH:
                        case ITEM_FOOD_LARGE_FISH:
                        case ITEM_FOOD_TEMPURA_RICE:
                        case ITEM_FOOD_FISH_STICKS:
                        case ITEM_FOOD_POTATO_PANCAKES_OR_CROQUETTE:
                            var_0 = NPC_INTERACTION_DISLIKED_GIFT;
                            break;
                        case ITEM_FOOD_BAMBOO_SHOOT:
                        case ITEM_FOOD_POISONOUS_MUSHROOM:
                        case ITEM_FOOD_TRUFFLE:
                        case ITEM_FOOD_BLUE_GRASS:
                        case ITEM_FOOD_GREEN_GRASS:
                        case ITEM_FOOD_YELLOW_GRASS:
                        case ITEM_FOOD_ORANGE_GRASS:
                        case ITEM_FOOD_PURPLE_GRASS:
                        case ITEM_FOOD_INDIGO_GRASS:
                        case ITEM_FOOD_BLACK_GRASS:
                        case ITEM_FOOD_WHITE_GRASS:
                        case ITEM_FOOD_OIL:
                        case ITEM_FOOD_FLOUR:
                        case ITEM_FOOD_CURRY_POWDER:
                        case ITEM_FOOD_ELLI_LEAVES:
                            var_0 = NPC_INTERACTION_HATED_GIFT;
                            break;
                    }
                    break;
                case HELD_ITEM_KIND_ARTICLE:
                    switch (GetPlayerHeldArticleId())
                    {
                        case ITEM_ARTICLE_YARN_S:
                        case ITEM_ARTICLE_YARN_M:
                        case ITEM_ARTICLE_YARN_L:
                        case ITEM_ARTICLE_YARN_G:
                        case ITEM_ARTICLE_YARN_P:
                        case ITEM_ARTICLE_YARN_X:
                            var_0 = NPC_INTERACTION_FAVORITE_GIFT;
                            break;
                        case ITEM_ARTICLE_FLOWER_MOON_DROP:
                        case ITEM_ARTICLE_FLOWER_PINK_CAT:
                        case ITEM_ARTICLE_FLOWER_MAGIC_BLUE:
                        case ITEM_ARTICLE_FLOWER_MAGIC_RED:
                        case ITEM_ARTICLE_FLOWER_TOY:
                        case ITEM_ARTICLE_STONES:
                        case ITEM_ARTICLE_BRANCHES:
                        case ITEM_ARTICLE_BALL:
                            var_0 = NPC_INTERACTION_LIKED_GIFT;
                            break;
                        case ITEM_ARTICLE_SPRING_SUN:
                        case ITEM_ARTICLE_SUMMER_SUN:
                        case ITEM_ARTICLE_AUTUMN_SUN:
                        case ITEM_ARTICLE_WINTER_SUN:
                            var_0 = NPC_INTERACTION_NEUTRAL_GIFT;
                            break;
                        case ITEM_ARTICLE_WEEDS:
                        case ITEM_ARTICLE_FISH_BONES:
                            var_0 = NPC_INTERACTION_DISLIKED_GIFT;
                            break;
                        case ITEM_ARTICLE_WOOL_S:
                        case ITEM_ARTICLE_WOOL_M:
                        case ITEM_ARTICLE_WOOL_L:
                        case ITEM_ARTICLE_WOOL_G:
                        case ITEM_ARTICLE_WOOL_P:
                        case ITEM_ARTICLE_WOOL_X:
                        case ITEM_ARTICLE_JUNK_ORE:
                        case ITEM_ARTICLE_COPPER:
                        case ITEM_ARTICLE_SILVER:
                        case ITEM_ARTICLE_GOLD:
                        case ITEM_ARTICLE_MYSTRILE:
                        case ITEM_ARTICLE_ORICHALC:
                        case ITEM_ARTICLE_ADAMANTITE:
                        case ITEM_ARTICLE_MOON_STONE:
                        case ITEM_ARTICLE_SAND_ROSE:
                        case ITEM_ARTICLE_PINK_DIAMOND:
                        case ITEM_ARTICLE_ALEXANDRITE:
                        case ITEM_ARTICLE_MYTHIC_STONE:
                        case ITEM_ARTICLE_DIAMOND:
                        case ITEM_ARTICLE_EMERALD:
                        case ITEM_ARTICLE_RUBY:
                        case ITEM_ARTICLE_TOPAZ:
                        case ITEM_ARTICLE_PERIDOT:
                        case ITEM_ARTICLE_FLUORITE:
                        case ITEM_ARTICLE_AGATE:
                        case ITEM_ARTICLE_AMETHYST:
                        case ITEM_ARTICLE_LITHOGRAPH:
                        case ITEM_ARTICLE_MESSAGE_IN_A_BOTTLE:
                        case ITEM_ARTICLE_PIRATE_TREASURE:
                        case ITEM_ARTICLE_FOSSIL_OF_FISH:
                        case ITEM_ARTICLE_EMPTY_CAN:
                        case ITEM_ARTICLE_BOOTS:
                        case ITEM_ARTICLE_LUMBER:
                        case ITEM_ARTICLE_GOLDEN_LUMBER:
                        case ITEM_ARTICLE_ANIMAL_FODDER:
                        case ITEM_ARTICLE_CHICKEN_FEED:
                            var_0 = NPC_INTERACTION_HATED_GIFT;
                            break;
                        case ITEM_ARTICLE_HARVEST_GODDESS_JEWEL:
                        case ITEM_ARTICLE_KAPPA_JEWEL:
                        case ITEM_ARTICLE_JEWEL_OF_TRUTH:
                        case ITEM_ARTICLE_KARENS_WINE:
                        case ITEM_ARTICLE_POPURIS_MUD_BALL:
                        case ITEM_ARTICLE_ANNS_MUSIC_BOX:
                        case ITEM_ARTICLE_MARYS_GREAT_BOOK:
                        case ITEM_ARTICLE_ELLIS_PRESSED_FLOWER:
                        case ITEM_ARTICLE_ALBUM_1:
                        case ITEM_ARTICLE_ALBUM_2:
                        case ITEM_ARTICLE_ALBUM_3:
                        case ITEM_ARTICLE_ALBUM_4:
                        case ITEM_ARTICLE_ALBUM_5:
                        case ITEM_ARTICLE_ALBUM_6:
                        case ITEM_ARTICLE_ALBUM_7:
                        case ITEM_ARTICLE_ALBUM_8:
                        case ITEM_ARTICLE_ALBUM_9:
                        case ITEM_ARTICLE_ALBUM_10:
                        case ITEM_ARTICLE_ALBUM_11:
                        case ITEM_ARTICLE_ALBUM_12:
                        case ITEM_ARTICLE_ALBUM_13:
                        case ITEM_ARTICLE_ALBUM_14:
                        case ITEM_ARTICLE_ALBUM_15:
                        case ITEM_ARTICLE_BOOK:
                        case ITEM_ARTICLE_PHOTO:
                        case ITEM_ARTICLE_INVITATION:
                        case ITEM_ARTICLE_LOTTERY:
                        case ITEM_ARTICLE_FRISBEE:
                            var_0 = NPC_INTERACTION_NO_APPLICABLE_GIFT;
                            break;
                        case ITEM_ARTICLE_BRACELET:
                        case ITEM_ARTICLE_NECKLACE:
                        case ITEM_ARTICLE_EARRINGS:
                        case ITEM_ARTICLE_BROOCH:
                            var_0 = NPC_INTERACTION_ACCESSORY;
                            break;
                        case ITEM_ARTICLE_DRESS:
                        case ITEM_ARTICLE_FACIAL_PACK:
                        case ITEM_ARTICLE_SKIN_LOTION:
                        case ITEM_ARTICLE_SUNBLOCK:
                            var_0 = NPC_INTERACTION_COSMETIC;
                            break;
                        case ITEM_ARTICLE_PERFUME:
                            var_0 = NPC_INTERACTION_PERFUME;
                            break;
                    }
                    break;
                case HELD_ITEM_KIND_BASKET:
                    var_0 = NPC_INTERACTION_NO_APPLICABLE_GIFT;
                    break;
                case HELD_ITEM_KIND_DOG:
                    var_0 = NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE;
                    break;
                case HELD_ITEM_KIND_CHICKEN:
                    var_0 = NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE;
                    break;
            }
        }
        else
        {
            if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
            {
                switch (GetPlayerHeldItemKind())
                {
                    case HELD_ITEM_KIND_FOOD:
                        switch (GetPlayerHeldFoodId())
                        {
                            case ITEM_FOOD_HONEY:
                            case ITEM_FOOD_WILD_GRAPES:
                            case ITEM_FOOD_GRAPE_JUICE:
                            case ITEM_FOOD_FRUIT_LATTE:
                            case ITEM_FOOD_STRAWBERRY_MILK:
                            case ITEM_FOOD_OMELET_RICE:
                            case ITEM_FOOD_HOT_MILK:
                            case ITEM_FOOD_CHEESE_CAKE:
                            case ITEM_FOOD_APPLE_PIE:
                            case ITEM_FOOD_COOKIES:
                            case ITEM_FOOD_CHOCOLATE_COOKIES:
                            case ITEM_FOOD_ICE_CREAM:
                            case ITEM_FOOD_CAKE:
                            case ITEM_FOOD_CHOCOLATE_CAKE:
                            case ITEM_FOOD_PANCAKES:
                                var_0 = NPC_INTERACTION_FAVORITE_GIFT;
                                break;
                            case ITEM_FOOD_STRAWBERRY:
                            case ITEM_FOOD_PINEAPPLE:
                            case ITEM_FOOD_MAYONNAISE_S:
                            case ITEM_FOOD_MAYONNAISE_M:
                            case ITEM_FOOD_MAYONNAISE_L:
                            case ITEM_FOOD_MAYONNAISE_G:
                            case ITEM_FOOD_MAYONNAISE_P:
                            case ITEM_FOOD_MAYONNAISE_X:
                            case ITEM_FOOD_MILK_S:
                            case ITEM_FOOD_MILK_M:
                            case ITEM_FOOD_MILK_L:
                            case ITEM_FOOD_MILK_G:
                            case ITEM_FOOD_MILK_P:
                            case ITEM_FOOD_MILK_X:
                            case ITEM_FOOD_APPLE:
                            case ITEM_FOOD_TRUFFLE:
                            case ITEM_FOOD_CHOCOLATE:
                            case ITEM_FOOD_RELAX_TEA_LEAVES:
                            case ITEM_FOOD_SUGDW_APPLE:
                            case ITEM_FOOD_HMSGB_APPLE:
                            case ITEM_FOOD_AEPFE_APPLE:
                            case ITEM_FOOD_FRUIT_JUICE:
                            case ITEM_FOOD_VEGETABLE_JUICE:
                            case ITEM_FOOD_MIXED_JUICE:
                            case ITEM_FOOD_VEGETABLE_LATTE:
                            case ITEM_FOOD_MIXED_LATTE:
                            case ITEM_FOOD_STRAWBERRY_JAM:
                            case ITEM_FOOD_TOMATO_JUICE:
                            case ITEM_FOOD_FRENCH_FRIES:
                            case ITEM_FOOD_POPCORN:
                            case ITEM_FOOD_PINEAPPLE_JUICE:
                            case ITEM_FOOD_PUMPKIN_PUDDING:
                            case ITEM_FOOD_SWEET_POTATOES:
                            case ITEM_FOOD_APPLE_JAM:
                            case ITEM_FOOD_APPLE_SOUFFLE:
                            case ITEM_FOOD_JAM_BUN:
                            case ITEM_FOOD_GRAPE_JAM:
                            case ITEM_FOOD_CANDIED_POTATO:
                                var_0 = NPC_INTERACTION_LIKED_GIFT;
                                break;
                            case ITEM_FOOD_TOMATO:
                            case ITEM_FOOD_PUMPKIN:
                            case ITEM_FOOD_SPINACH:
                            case ITEM_FOOD_REGULAR_QUALITY_EGG:
                            case ITEM_FOOD_GOOD_QUALITY_EGG:
                            case ITEM_FOOD_HIGH_QUALITY_EGG:
                            case ITEM_FOOD_GOLDEN_EGG:
                            case ITEM_FOOD_P_EGG:
                            case ITEM_FOOD_X_EGG:
                            case ITEM_FOOD_SPA_BOILED_EGG:
                            case ITEM_FOOD_RICE_BALL:
                            case ITEM_FOOD_BREAD:
                            case ITEM_FOOD_MUFFIN_MIX_OR_RICE_FLOUR:
                            case ITEM_FOOD_SALAD:
                            case ITEM_FOOD_STEW:
                            case ITEM_FOOD_MISO_SOUP:
                            case ITEM_FOOD_SANDWICH:
                            case ITEM_FOOD_KETCHUP:
                            case ITEM_FOOD_CORN_FLAKES:
                            case ITEM_FOOD_PUMPKIN_STEW:
                            case ITEM_FOOD_BAKED_SWEET_POTATO:
                            case ITEM_FOOD_SCRAMBLED_EGGS_OR_JAPANESE_OMELET:
                            case ITEM_FOOD_OMELET:
                            case ITEM_FOOD_BOILED_EGG:
                            case ITEM_FOOD_DINNER_ROLL:
                            case ITEM_FOOD_RAISIN_BREAD:
                            case ITEM_FOOD_NOODLES:
                            case ITEM_FOOD_RELAXATION_TEA:
                            case ITEM_FOOD_TOAST:
                            case ITEM_FOOD_FRENCH_TOAST:
                            case ITEM_FOOD_PUDDING:
                            case ITEM_FOOD_MOUNTAIN_STEW:
                            case ITEM_FOOD_MOON_DUMPLINGS:
                            case ITEM_FOOD_RICE_CAKE:
                            case ITEM_FOOD_ROASTED_RICE_CAKE:
                            case ITEM_FOOD_TOASTED_RICE_BALL:
                            case ITEM_FOOD_EGG_OVER_RICE_OR_EGG_BOWL:
                            case ITEM_FOOD_RICE_GRUEL:
                                var_0 = NPC_INTERACTION_NEUTRAL_GIFT;
                                break;
                            case ITEM_FOOD_TURNIP:
                            case ITEM_FOOD_POTATO:
                            case ITEM_FOOD_CUCUMBER:
                            case ITEM_FOOD_CABBAGE:
                            case ITEM_FOOD_CORN:
                            case ITEM_FOOD_EGGPLANT:
                            case ITEM_FOOD_CHEESE_S:
                            case ITEM_FOOD_CHEESE_M:
                            case ITEM_FOOD_CHEESE_L:
                            case ITEM_FOOD_CHEESE_G:
                            case ITEM_FOOD_CHEESE_P:
                            case ITEM_FOOD_CHEESE_X:
                            case ITEM_FOOD_BAMBOO_SHOOT:
                            case ITEM_FOOD_MUSHROOM:
                            case ITEM_FOOD_BUCKWHEAT_FLOUR:
                            case ITEM_FOOD_CURRY_RICE:
                            case ITEM_FOOD_STIR_FRY:
                            case ITEM_FOOD_FRIED_RICE:
                            case ITEM_FOOD_SAVORY_PANCAKE:
                            case ITEM_FOOD_PICKLED_TURNIP:
                            case ITEM_FOOD_PICKLES:
                            case ITEM_FOOD_BAKED_CORN:
                            case ITEM_FOOD_HAPPY_EGGPLANT:
                            case ITEM_FOOD_GREENS:
                            case ITEM_FOOD_BUTTER:
                            case ITEM_FOOD_CHEESE_FONDUE:
                            case ITEM_FOOD_MUSHROOM_RICE:
                            case ITEM_FOOD_BAMBOO_RICE:
                            case ITEM_FOOD_TRUFFLE_RICE:
                            case ITEM_FOOD_SUSHI:
                            case ITEM_FOOD_CURRY_BREAD:
                            case ITEM_FOOD_CHIRASHI_SUSHI:
                            case ITEM_FOOD_PIZZA:
                            case ITEM_FOOD_CURRY_NOODLES:
                            case ITEM_FOOD_TEMPURA_NOODLES:
                            case ITEM_FOOD_FRIED_NOODLES:
                            case ITEM_FOOD_BUCKWHEAT_NOODLES:
                            case ITEM_FOOD_NOODLES_W_TEMPURA:
                            case ITEM_FOOD_FRIED_BUCKWHEAT_NOODLES:
                            case ITEM_FOOD_BUCKWHEAT_CHIPS:
                            case ITEM_FOOD_TEMPURA:
                            case ITEM_FOOD_FAILED_DISH:
                            case ITEM_FOOD_FAILED_DRINK:
                            case ITEM_FOOD_FAILED_POT_DISH:
                            case ITEM_FOOD_FAILED_DESSERT:
                            case ITEM_FOOD_FAILED_BREAD:
                            case ITEM_FOOD_FAILED_NOODLES:
                            case ITEM_FOOD_SMALL_FISH:
                            case ITEM_FOOD_MEDIUM_FISH:
                            case ITEM_FOOD_LARGE_FISH:
                            case ITEM_FOOD_TEMPURA_RICE:
                            case ITEM_FOOD_FISH_STICKS:
                            case ITEM_FOOD_POTATO_PANCAKES_OR_CROQUETTE:
                                var_0 = NPC_INTERACTION_DISLIKED_GIFT;
                                break;
                            case ITEM_FOOD_ONION:
                            case ITEM_FOOD_CARROT:
                            case ITEM_FOOD_SWEET_POTATO:
                            case ITEM_FOOD_GREEN_PEPPER:
                            case ITEM_FOOD_POISONOUS_MUSHROOM:
                            case ITEM_FOOD_BLUE_GRASS:
                            case ITEM_FOOD_GREEN_GRASS:
                            case ITEM_FOOD_RED_GRASS:
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
                            case ITEM_FOOD_OIL:
                            case ITEM_FOOD_FLOUR:
                            case ITEM_FOOD_CURRY_POWDER:
                            case ITEM_FOOD_WILD_GRAPE_JUICE:
                            case ITEM_FOOD_SASHIMI:
                            case ITEM_FOOD_GRILLED_FISH:
                            case ITEM_FOOD_ELLI_LEAVES:
                                var_0 = NPC_INTERACTION_HATED_GIFT;
                                break;
                        }
                        break;
                    case HELD_ITEM_KIND_ARTICLE:
                        switch (GetPlayerHeldArticleId())
                        {
                            case ITEM_ARTICLE_FLOWER_MOON_DROP:
                            case ITEM_ARTICLE_FLOWER_PINK_CAT:
                            case ITEM_ARTICLE_FLOWER_TOY:
                                var_0 = NPC_INTERACTION_FAVORITE_GIFT;
                                break;
                            case ITEM_ARTICLE_FLOWER_MAGIC_BLUE:
                            case ITEM_ARTICLE_FLOWER_MAGIC_RED:
                            case ITEM_ARTICLE_WOOL_S:
                            case ITEM_ARTICLE_WOOL_M:
                            case ITEM_ARTICLE_WOOL_L:
                            case ITEM_ARTICLE_WOOL_G:
                            case ITEM_ARTICLE_WOOL_P:
                            case ITEM_ARTICLE_WOOL_X:
                            case ITEM_ARTICLE_YARN_S:
                            case ITEM_ARTICLE_YARN_M:
                            case ITEM_ARTICLE_YARN_L:
                            case ITEM_ARTICLE_YARN_G:
                            case ITEM_ARTICLE_YARN_P:
                            case ITEM_ARTICLE_YARN_X:
                            case ITEM_ARTICLE_STONES:
                            case ITEM_ARTICLE_BRANCHES:
                            case ITEM_ARTICLE_MESSAGE_IN_A_BOTTLE:
                            case ITEM_ARTICLE_BALL:
                            case ITEM_ARTICLE_EMPTY_CAN:
                                var_0 = NPC_INTERACTION_LIKED_GIFT;
                                break;
                            case ITEM_ARTICLE_SPRING_SUN:
                            case ITEM_ARTICLE_SUMMER_SUN:
                            case ITEM_ARTICLE_AUTUMN_SUN:
                            case ITEM_ARTICLE_WINTER_SUN:
                            case ITEM_ARTICLE_BOOTS:
                                var_0 = NPC_INTERACTION_NEUTRAL_GIFT;
                                break;
                            case ITEM_ARTICLE_JUNK_ORE:
                            case ITEM_ARTICLE_COPPER:
                            case ITEM_ARTICLE_SILVER:
                            case ITEM_ARTICLE_GOLD:
                            case ITEM_ARTICLE_MYSTRILE:
                            case ITEM_ARTICLE_ORICHALC:
                            case ITEM_ARTICLE_ADAMANTITE:
                            case ITEM_ARTICLE_MOON_STONE:
                            case ITEM_ARTICLE_SAND_ROSE:
                            case ITEM_ARTICLE_PINK_DIAMOND:
                            case ITEM_ARTICLE_ALEXANDRITE:
                            case ITEM_ARTICLE_MYTHIC_STONE:
                            case ITEM_ARTICLE_DIAMOND:
                            case ITEM_ARTICLE_EMERALD:
                            case ITEM_ARTICLE_RUBY:
                            case ITEM_ARTICLE_TOPAZ:
                            case ITEM_ARTICLE_PERIDOT:
                            case ITEM_ARTICLE_FLUORITE:
                            case ITEM_ARTICLE_AGATE:
                            case ITEM_ARTICLE_AMETHYST:
                            case ITEM_ARTICLE_WEEDS:
                            case ITEM_ARTICLE_LITHOGRAPH:
                            case ITEM_ARTICLE_FISH_BONES:
                                var_0 = NPC_INTERACTION_DISLIKED_GIFT;
                                break;
                            case ITEM_ARTICLE_PIRATE_TREASURE:
                            case ITEM_ARTICLE_FOSSIL_OF_FISH:
                            case ITEM_ARTICLE_LUMBER:
                            case ITEM_ARTICLE_GOLDEN_LUMBER:
                            case ITEM_ARTICLE_ANIMAL_FODDER:
                            case ITEM_ARTICLE_CHICKEN_FEED:
                                var_0 = NPC_INTERACTION_HATED_GIFT;
                                break;
                            case ITEM_ARTICLE_HARVEST_GODDESS_JEWEL:
                            case ITEM_ARTICLE_KAPPA_JEWEL:
                            case ITEM_ARTICLE_JEWEL_OF_TRUTH:
                            case ITEM_ARTICLE_KARENS_WINE:
                            case ITEM_ARTICLE_POPURIS_MUD_BALL:
                            case ITEM_ARTICLE_ANNS_MUSIC_BOX:
                            case ITEM_ARTICLE_MARYS_GREAT_BOOK:
                            case ITEM_ARTICLE_ELLIS_PRESSED_FLOWER:
                            case ITEM_ARTICLE_ALBUM_1:
                            case ITEM_ARTICLE_ALBUM_2:
                            case ITEM_ARTICLE_ALBUM_3:
                            case ITEM_ARTICLE_ALBUM_4:
                            case ITEM_ARTICLE_ALBUM_5:
                            case ITEM_ARTICLE_ALBUM_6:
                            case ITEM_ARTICLE_ALBUM_7:
                            case ITEM_ARTICLE_ALBUM_8:
                            case ITEM_ARTICLE_ALBUM_9:
                            case ITEM_ARTICLE_ALBUM_10:
                            case ITEM_ARTICLE_ALBUM_11:
                            case ITEM_ARTICLE_ALBUM_12:
                            case ITEM_ARTICLE_ALBUM_13:
                            case ITEM_ARTICLE_ALBUM_14:
                            case ITEM_ARTICLE_ALBUM_15:
                            case ITEM_ARTICLE_BOOK:
                            case ITEM_ARTICLE_PHOTO:
                            case ITEM_ARTICLE_INVITATION:
                            case ITEM_ARTICLE_LOTTERY:
                            case ITEM_ARTICLE_FRISBEE:
                                var_0 = NPC_INTERACTION_NO_APPLICABLE_GIFT;
                                break;
                            case ITEM_ARTICLE_BRACELET:
                            case ITEM_ARTICLE_NECKLACE:
                            case ITEM_ARTICLE_EARRINGS:
                            case ITEM_ARTICLE_BROOCH:
                                var_0 = NPC_INTERACTION_ACCESSORY;
                                break;
                            case ITEM_ARTICLE_DRESS:
                            case ITEM_ARTICLE_FACIAL_PACK:
                            case ITEM_ARTICLE_SKIN_LOTION:
                            case ITEM_ARTICLE_SUNBLOCK:
                                var_0 = NPC_INTERACTION_COSMETIC;
                                break;
                            case ITEM_ARTICLE_PERFUME:
                                var_0 = NPC_INTERACTION_PERFUME;
                                break;
                        }
                        break;
                    case HELD_ITEM_KIND_BASKET:
                        var_0 = NPC_INTERACTION_NO_APPLICABLE_GIFT;
                        break;
                    case HELD_ITEM_KIND_DOG:
                        var_0 = NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE;
                        break;
                    case HELD_ITEM_KIND_CHICKEN:
                        var_0 = NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE;
                        break;
                }
            }
        }
    }
    if (var_0 != NPC_INTERACTION_NO_APPLICABLE_GIFT)
    {
        if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_NOT_YET)
        {
            if ((var_0 == NPC_INTERACTION_FAVORITE_GIFT || var_0 == NPC_INTERACTION_LIKED_GIFT || var_0 == NPC_INTERACTION_NEUTRAL_GIFT) && IsCharacterBirthdayToday(CHARACTER_CHILD))
            {
                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantFavorableGiftWithChildNearbyResponse);
            }
            else
            {
                switch (var_0)
                {
                    case NPC_INTERACTION_FAVORITE_GIFT:
                        SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                        TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantFavoriteGiftOrHighFriendshipRepeatResponse);
                        break;
                    case NPC_INTERACTION_LIKED_GIFT:
                        SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                        TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantMediumFriendshipRepeatOrYoungChildLikedGiftOrFavorableAnimalResponse);
                        break;
                    case NPC_INTERACTION_NEUTRAL_GIFT:
                        SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                        TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantNeutralGiftResponse);
                        break;
                    case NPC_INTERACTION_DISLIKED_GIFT:
                        SetTalkPortrait(TALK_PORTRAIT_BABY_ANGRY);
                        TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantDislikedGiftOrYoungChildLowFriendshipRepeatResponse);
                        break;
                    case NPC_INTERACTION_HATED_GIFT:
                        SetTalkPortrait(TALK_PORTRAIT_BABY_INDIGNATED);
                        TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantHatedGiftResponse);
                        break;
                    case NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE:
                        SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
                        TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantFavorableAnimalResponse);
                        break;
                    case NPC_INTERACTION_UNFAVORABLE_ANIMAL_RESPONSE:
                        SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
                        TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantUnfavorableAnimalResponse);
                        break;
                    case NPC_INTERACTION_ACCESSORY:
                    case NPC_INTERACTION_COSMETIC:
                        SetTalkPortrait(TALK_PORTRAIT_BABY_INDIGNATED);
                        TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantAccessoryOrCosmeticResponse);
                        break;
                    case NPC_INTERACTION_PERFUME:
                        SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
                        TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantPerfumeResponse);
                        break;
                }
            }
            if (WasNpcGiftedToday(CHARACTER_CHILD) == FALSE)
            {
                switch (var_0)
                {
                    case NPC_INTERACTION_FAVORITE_GIFT:
                        var_1 = 9;
                        break;
                    case NPC_INTERACTION_LIKED_GIFT:
                        var_1 = 3;
                        break;
                    case NPC_INTERACTION_NEUTRAL_GIFT:
                        var_1 = 1;
                        break;
                    case NPC_INTERACTION_DISLIKED_GIFT:
                        var_1 = mary_negated_int(-3);
                        break;
                    case NPC_INTERACTION_HATED_GIFT:
                        var_1 = mary_negated_int(-9);
                        break;
                    case NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE:
                        var_1 = 1;
                        break;
                    case NPC_INTERACTION_UNFAVORABLE_ANIMAL_RESPONSE:
                        var_1 = mary_negated_int(-3);
                        break;
                    case NPC_INTERACTION_ACCESSORY:
                        var_1 = mary_negated_int(-9);
                        break;
                    case NPC_INTERACTION_COSMETIC:
                        var_1 = mary_negated_int(-9);
                        break;
                    case NPC_INTERACTION_PERFUME:
                        var_1 = mary_negated_int(-3);
                        break;
                }
            }
            else
            {
                switch (var_0)
                {
                    case NPC_INTERACTION_FAVORITE_GIFT:
                        var_1 = 3;
                        break;
                    case NPC_INTERACTION_LIKED_GIFT:
                        var_1 = 1;
                        break;
                    case NPC_INTERACTION_NEUTRAL_GIFT:
                        var_1 = 0;
                        break;
                    case NPC_INTERACTION_DISLIKED_GIFT:
                        var_1 = mary_negated_int(-3);
                        break;
                    case NPC_INTERACTION_HATED_GIFT:
                        var_1 = mary_negated_int(-9);
                        break;
                    case NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE:
                        var_1 = 0;
                        break;
                    case NPC_INTERACTION_UNFAVORABLE_ANIMAL_RESPONSE:
                        var_1 = mary_negated_int(-3);
                        break;
                    case NPC_INTERACTION_ACCESSORY:
                        var_1 = mary_negated_int(-9);
                        break;
                    case NPC_INTERACTION_COSMETIC:
                        var_1 = mary_negated_int(-9);
                        break;
                    case NPC_INTERACTION_PERFUME:
                        var_1 = mary_negated_int(-3);
                        break;
                }
            }
        }
        else
        {
            if (VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
            {
                if (VarGet(VAR_CHILD_AGE_DAYS) < CHILD_AGE_DAYS_SATURATED_MAXIMUM)
                {
                    if ((var_0 == NPC_INTERACTION_FAVORITE_GIFT || var_0 == NPC_INTERACTION_LIKED_GIFT || var_0 == NPC_INTERACTION_NEUTRAL_GIFT) && IsCharacterBirthdayToday(CHARACTER_CHILD))
                    {
                        SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                        TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantMediumFriendshipRepeatOrYoungChildLikedGiftOrFavorableAnimalResponse);
                    }
                    else
                    {
                        switch (var_0)
                        {
                            case NPC_INTERACTION_FAVORITE_GIFT:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildFavoriteGiftResponse);
                                break;
                            case NPC_INTERACTION_LIKED_GIFT:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildLikedGiftResponse);
                                break;
                            case NPC_INTERACTION_NEUTRAL_GIFT:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildNeutralGiftResponse);
                                break;
                            case NPC_INTERACTION_DISLIKED_GIFT:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_ANGRY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildDislikedGiftResponse);
                                break;
                            case NPC_INTERACTION_HATED_GIFT:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildHatedGiftOrUnfavorableAnimalResponse);
                                break;
                            case NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantMediumFriendshipRepeatOrYoungChildLikedGiftOrFavorableAnimalResponse);
                                break;
                            case NPC_INTERACTION_UNFAVORABLE_ANIMAL_RESPONSE:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildHatedGiftOrUnfavorableAnimalResponse);
                                break;
                            case NPC_INTERACTION_ACCESSORY:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildAccessoryOrCosmeticGiftResponse);
                                break;
                            case NPC_INTERACTION_COSMETIC:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildAccessoryOrCosmeticGiftResponse);
                                break;
                            case NPC_INTERACTION_PERFUME:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_INDIGNATED);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildPerfumeResponse);
                                break;
                        }
                    }
                }
                else
                {
                    if ((var_0 == NPC_INTERACTION_FAVORITE_GIFT || var_0 == NPC_INTERACTION_LIKED_GIFT || var_0 == NPC_INTERACTION_NEUTRAL_GIFT) && IsCharacterBirthdayToday(CHARACTER_CHILD))
                    {
                        SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                        TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildFavorableGiftWithChildNearbyResponse);
                    }
                    else
                    {
                        switch (var_0)
                        {
                            case NPC_INTERACTION_FAVORITE_GIFT:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildFavoriteGiftResponse);
                                break;
                            case NPC_INTERACTION_LIKED_GIFT:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildLikedGiftResponse);
                                break;
                            case NPC_INTERACTION_NEUTRAL_GIFT:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildNeutralGiftResponse);
                                break;
                            case NPC_INTERACTION_DISLIKED_GIFT:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_ANGRY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildDislikedGiftResponse);
                                break;
                            case NPC_INTERACTION_HATED_GIFT:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildHatedGiftResponse);
                                break;
                            case NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildFavorableAnimalResponse);
                                break;
                            case NPC_INTERACTION_UNFAVORABLE_ANIMAL_RESPONSE:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_CRYING);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildUnfavorableAnimalResponse);
                                break;
                            case NPC_INTERACTION_ACCESSORY:
                            case NPC_INTERACTION_COSMETIC:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildAccessoryOrCosmeticResponse);
                                break;
                            case NPC_INTERACTION_PERFUME:
                                SetTalkPortrait(TALK_PORTRAIT_BABY_INDIGNATED);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildPerfumeResponse);
                                break;
                        }
                    }
                }
                if (WasNpcGiftedToday(CHARACTER_CHILD) == FALSE)
                {
                    switch (var_0)
                    {
                        case NPC_INTERACTION_FAVORITE_GIFT:
                            var_1 = 9;
                            break;
                        case NPC_INTERACTION_LIKED_GIFT:
                            var_1 = 3;
                            break;
                        case NPC_INTERACTION_NEUTRAL_GIFT:
                            var_1 = 1;
                            break;
                        case NPC_INTERACTION_DISLIKED_GIFT:
                            var_1 = mary_negated_int(-3);
                            break;
                        case NPC_INTERACTION_HATED_GIFT:
                            var_1 = mary_negated_int(-9);
                            break;
                        case NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE:
                            var_1 = 1;
                            break;
                        case NPC_INTERACTION_UNFAVORABLE_ANIMAL_RESPONSE:
                            var_1 = mary_negated_int(-3);
                            break;
                        case NPC_INTERACTION_ACCESSORY:
                            var_1 = 1;
                            break;
                        case NPC_INTERACTION_COSMETIC:
                            var_1 = 1;
                            break;
                        case NPC_INTERACTION_PERFUME:
                            var_1 = mary_negated_int(-3);
                            break;
                    }
                }
                else
                {
                    switch (var_0)
                    {
                        case NPC_INTERACTION_FAVORITE_GIFT:
                            var_1 = 3;
                            break;
                        case NPC_INTERACTION_LIKED_GIFT:
                            var_1 = 1;
                            break;
                        case NPC_INTERACTION_NEUTRAL_GIFT:
                            var_1 = 0;
                            break;
                        case NPC_INTERACTION_DISLIKED_GIFT:
                            var_1 = mary_negated_int(-3);
                            break;
                        case NPC_INTERACTION_HATED_GIFT:
                            var_1 = mary_negated_int(-9);
                            break;
                        case NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE:
                            var_1 = 0;
                            break;
                        case NPC_INTERACTION_UNFAVORABLE_ANIMAL_RESPONSE:
                            var_1 = mary_negated_int(-3);
                            break;
                        case NPC_INTERACTION_ACCESSORY:
                            var_1 = 0;
                            break;
                        case NPC_INTERACTION_COSMETIC:
                            var_1 = 0;
                            break;
                        case NPC_INTERACTION_PERFUME:
                            var_1 = mary_negated_int(-3);
                            break;
                    }
                }
            }
        }
        if (IsCharacterBirthdayToday(CHARACTER_CHILD))
        {
            var_1 *= 5;
        }
        if (IsPlayerHeldItemWrapped())
        {
            var_1 = var_1 + var_1 / 4;
        }
        AddNpcFriendship(CHARACTER_CHILD, var_1);
        TalkClose();
        if (var_0 == NPC_INTERACTION_FAVORITE_GIFT || var_0 == NPC_INTERACTION_LIKED_GIFT || var_0 == NPC_INTERACTION_NEUTRAL_GIFT || var_0 == NPC_INTERACTION_DISLIKED_GIFT || var_0 == NPC_INTERACTION_HATED_GIFT || var_0 == NPC_INTERACTION_ACCESSORY || var_0 == NPC_INTERACTION_COSMETIC || var_0 == NPC_INTERACTION_PERFUME)
        {
            UsePlayerHeldItem();
        }
        MarkNpcGifted(CHARACTER_CHILD);
    }
    else
    {
        switch (GetEntityLocation(ENTITY_CHILD))
        {
            case MAP_FARMHOUSE:
                if (VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START && VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_NOT_YET)
                {
                    if (GetNpcFriendship(CHARACTER_CHILD) <= 100)
                    {
                        if (WasNpcSpokenToJustNow(CHARACTER_CHILD) == FALSE)
                        {
                            SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
                            TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantLowFriendshipFirstConversation);
                        }
                        else
                        {
                            SetTalkPortrait(TALK_PORTRAIT_BABY_INDIGNATED);
                            TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantLowFriendshipRepeatConversation);
                        }
                    }
                    else
                    {
                        if (GetNpcFriendship(CHARACTER_CHILD) > 100 && GetNpcFriendship(CHARACTER_CHILD) <= 200)
                        {
                            if (WasNpcSpokenToJustNow(CHARACTER_CHILD) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantMediumFriendshipFirstConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantMediumFriendshipRepeatOrYoungChildLikedGiftOrFavorableAnimalResponse);
                            }
                        }
                        else
                        {
                            if (WasNpcSpokenToJustNow(CHARACTER_CHILD) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantHighFriendshipFirstConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_InfantFavoriteGiftOrHighFriendshipRepeatResponse);
                            }
                        }
                    }
                }
                else
                {
                    if (VarGet(VAR_CHILD_AGE_DAYS) < 200)
                    {
                        if (WasNpcSpokenToJustNow(CHARACTER_CHILD) == FALSE)
                        {
                            SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
                            TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildUnder200DaysFirstConversation);
                        }
                        else
                        {
                            SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
                            TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChildUnder200DaysRepeatConversation);
                        }
                    }
                    else
                    {
                        if (VarGet(VAR_CHILD_AGE_DAYS) >= 200 && VarGet(VAR_CHILD_AGE_DAYS) < CHILD_AGE_DAYS_SATURATED_MAXIMUM)
                        {
                            if (WasNpcSpokenToJustNow(CHARACTER_CHILD) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChild200To254DaysFirstConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_BABY_INDIGNATED);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_YoungChild200To254DaysRepeatConversation);
                            }
                        }
                        else
                        {
                            if (WasNpcSpokenToJustNow(CHARACTER_CHILD) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildFirstConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
                                TalkMessage(gText_NPCEvent_Baby_DialogueAndInteractions_MatureChildRepeatConversation);
                            }
                        }
                    }
                }
                break;
        }
        MarkNpcSpokenTo(CHARACTER_CHILD);
    }
    TalkClose();
    SetEntityFacing(ENTITY_CHILD, var_2);
}
