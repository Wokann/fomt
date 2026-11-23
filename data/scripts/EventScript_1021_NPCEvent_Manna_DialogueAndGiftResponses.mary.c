#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1021_NPCEvent_Manna_DialogueAndGiftResponses.mary.h"

void EventScript_1021_NPCEvent_Manna_DialogueAndGiftResponses(void)
{
    int var_0, var_1, var_2, var_3;
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    var_3 = GetEntityFacing(ENTITY_MANNA);
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Introduction);
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    else
    {
        if (IsPlayerHoldingNothing() || (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_CARTER_CONFESSIONAL_DREAM_PREDICTS_GOOD_FORTUNE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS) || (VarGet(VAR_KAREN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_BLUE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_MANNA_FLATTERS_JEFF_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_WON_OFFERS_TO_BUY_JEFFS_PAINTING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_JEFF_AND_SASHA_STORE_CREDIT_LESSON_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS) || (VarGet(VAR_ANN_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_3_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS))
        {
            var_0 = NPC_INTERACTION_NO_APPLICABLE_GIFT;
        }
        else
        {
            switch (GetPlayerHeldItemKind())
            {
                case HELD_ITEM_KIND_FOOD:
                    switch (GetPlayerHeldFoodId())
                    {
                        case ITEM_FOOD_PINEAPPLE:
                        case ITEM_FOOD_GOLDEN_EGG:
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
                        case ITEM_FOOD_HONEY:
                        case ITEM_FOOD_BAMBOO_SHOOT:
                        case ITEM_FOOD_TRUFFLE:
                        case ITEM_FOOD_MUFFIN_MIX_OR_RICE_FLOUR:
                        case ITEM_FOOD_RELAX_TEA_LEAVES:
                        case ITEM_FOOD_VEGETABLE_JUICE:
                        case ITEM_FOOD_VEGETABLE_LATTE:
                        case ITEM_FOOD_STRAWBERRY_JAM:
                        case ITEM_FOOD_TOMATO_JUICE:
                        case ITEM_FOOD_PINEAPPLE_JUICE:
                        case ITEM_FOOD_APPLE_JAM:
                        case ITEM_FOOD_MUSHROOM_RICE:
                        case ITEM_FOOD_BAMBOO_RICE:
                        case ITEM_FOOD_TRUFFLE_RICE:
                        case ITEM_FOOD_SUSHI:
                        case ITEM_FOOD_RAISIN_BREAD:
                        case ITEM_FOOD_RELAXATION_TEA:
                        case ITEM_FOOD_SMALL_FISH:
                        case ITEM_FOOD_MEDIUM_FISH:
                        case ITEM_FOOD_LARGE_FISH:
                        case ITEM_FOOD_FISH_STICKS:
                            var_0 = NPC_INTERACTION_FAVORITE_GIFT;
                            break;
                        case ITEM_FOOD_TURNIP:
                        case ITEM_FOOD_POTATO:
                        case ITEM_FOOD_CUCUMBER:
                        case ITEM_FOOD_STRAWBERRY:
                        case ITEM_FOOD_CABBAGE:
                        case ITEM_FOOD_TOMATO:
                        case ITEM_FOOD_ONION:
                        case ITEM_FOOD_PUMPKIN:
                        case ITEM_FOOD_EGGPLANT:
                        case ITEM_FOOD_CARROT:
                        case ITEM_FOOD_SWEET_POTATO:
                        case ITEM_FOOD_SPINACH:
                        case ITEM_FOOD_GREEN_PEPPER:
                        case ITEM_FOOD_REGULAR_QUALITY_EGG:
                        case ITEM_FOOD_GOOD_QUALITY_EGG:
                        case ITEM_FOOD_HIGH_QUALITY_EGG:
                        case ITEM_FOOD_P_EGG:
                        case ITEM_FOOD_X_EGG:
                        case ITEM_FOOD_CHEESE_S:
                        case ITEM_FOOD_CHEESE_M:
                        case ITEM_FOOD_CHEESE_L:
                        case ITEM_FOOD_CHEESE_G:
                        case ITEM_FOOD_CHEESE_P:
                        case ITEM_FOOD_CHEESE_X:
                        case ITEM_FOOD_APPLE:
                        case ITEM_FOOD_WILD_GRAPES:
                        case ITEM_FOOD_BODIGIZER:
                        case ITEM_FOOD_BODIGIZER_XL:
                        case ITEM_FOOD_GRAPE_JUICE:
                        case ITEM_FOOD_OIL:
                        case ITEM_FOOD_SUGDW_APPLE:
                        case ITEM_FOOD_HMSGB_APPLE:
                        case ITEM_FOOD_AEPFE_APPLE:
                        case ITEM_FOOD_BUCKWHEAT_FLOUR:
                        case ITEM_FOOD_FRUIT_JUICE:
                        case ITEM_FOOD_MIXED_JUICE:
                        case ITEM_FOOD_MIXED_LATTE:
                        case ITEM_FOOD_KETCHUP:
                        case ITEM_FOOD_PUMPKIN_PUDDING:
                        case ITEM_FOOD_PUMPKIN_STEW:
                        case ITEM_FOOD_SWEET_POTATOES:
                        case ITEM_FOOD_BAKED_APPLE:
                        case ITEM_FOOD_BUCKWHEAT_NOODLES:
                        case ITEM_FOOD_NOODLES_W_TEMPURA:
                        case ITEM_FOOD_COOKIES:
                        case ITEM_FOOD_CHOCOLATE_COOKIES:
                        case ITEM_FOOD_ICE_CREAM:
                        case ITEM_FOOD_CAKE:
                        case ITEM_FOOD_CHOCOLATE_CAKE:
                        case ITEM_FOOD_PUDDING:
                        case ITEM_FOOD_MOUNTAIN_STEW:
                        case ITEM_FOOD_MOON_DUMPLINGS:
                        case ITEM_FOOD_RICE_CAKE:
                        case ITEM_FOOD_ROASTED_RICE_CAKE:
                        case ITEM_FOOD_EGG_OVER_RICE_OR_EGG_BOWL:
                        case ITEM_FOOD_PANCAKES:
                        case ITEM_FOOD_CANDIED_POTATO:
                        case ITEM_FOOD_POTATO_PANCAKES_OR_CROQUETTE:
                            var_0 = NPC_INTERACTION_LIKED_GIFT;
                            break;
                        case ITEM_FOOD_CORN:
                        case ITEM_FOOD_SPA_BOILED_EGG:
                        case ITEM_FOOD_TURBOJOLT:
                        case ITEM_FOOD_TURBOJOLT_XL:
                        case ITEM_FOOD_WINE:
                        case ITEM_FOOD_RICE_BALL:
                        case ITEM_FOOD_BREAD:
                        case ITEM_FOOD_FLOUR:
                        case ITEM_FOOD_CURRY_POWDER:
                        case ITEM_FOOD_CHOCOLATE:
                        case ITEM_FOOD_WILD_GRAPE_JUICE:
                        case ITEM_FOOD_SALAD:
                        case ITEM_FOOD_STEW:
                        case ITEM_FOOD_MISO_SOUP:
                        case ITEM_FOOD_STIR_FRY:
                        case ITEM_FOOD_FRIED_RICE:
                        case ITEM_FOOD_SAVORY_PANCAKE:
                        case ITEM_FOOD_SANDWICH:
                        case ITEM_FOOD_FRUIT_LATTE:
                        case ITEM_FOOD_STRAWBERRY_MILK:
                        case ITEM_FOOD_PICKLED_TURNIP:
                        case ITEM_FOOD_FRENCH_FRIES:
                        case ITEM_FOOD_PICKLES:
                        case ITEM_FOOD_POPCORN:
                        case ITEM_FOOD_CORN_FLAKES:
                        case ITEM_FOOD_BAKED_CORN:
                        case ITEM_FOOD_HAPPY_EGGPLANT:
                        case ITEM_FOOD_BAKED_SWEET_POTATO:
                        case ITEM_FOOD_SCRAMBLED_EGGS_OR_JAPANESE_OMELET:
                        case ITEM_FOOD_OMELET:
                        case ITEM_FOOD_OMELET_RICE:
                        case ITEM_FOOD_BOILED_EGG:
                        case ITEM_FOOD_HOT_MILK:
                        case ITEM_FOOD_BUTTER:
                        case ITEM_FOOD_CHEESE_CAKE:
                        case ITEM_FOOD_CHEESE_FONDUE:
                        case ITEM_FOOD_APPLE_PIE:
                        case ITEM_FOOD_JAM_BUN:
                        case ITEM_FOOD_DINNER_ROLL:
                        case ITEM_FOOD_GRAPE_JAM:
                        case ITEM_FOOD_SASHIMI:
                        case ITEM_FOOD_GRILLED_FISH:
                        case ITEM_FOOD_CHIRASHI_SUSHI:
                        case ITEM_FOOD_PIZZA:
                        case ITEM_FOOD_NOODLES:
                        case ITEM_FOOD_CURRY_NOODLES:
                        case ITEM_FOOD_TEMPURA_NOODLES:
                        case ITEM_FOOD_FRIED_NOODLES:
                        case ITEM_FOOD_FRIED_BUCKWHEAT_NOODLES:
                        case ITEM_FOOD_BUCKWHEAT_CHIPS:
                        case ITEM_FOOD_TEMPURA:
                        case ITEM_FOOD_TOAST:
                        case ITEM_FOOD_FRENCH_TOAST:
                        case ITEM_FOOD_TOASTED_RICE_BALL:
                        case ITEM_FOOD_TEMPURA_RICE:
                        case ITEM_FOOD_RICE_GRUEL:
                            var_0 = NPC_INTERACTION_NEUTRAL_GIFT;
                            break;
                        case ITEM_FOOD_GREENS:
                            var_2 = 1;
                            var_0 = NPC_INTERACTION_NEUTRAL_GIFT;
                            break;
                        case ITEM_FOOD_MUSHROOM:
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
                        case ITEM_FOOD_CURRY_RICE:
                        case ITEM_FOOD_CURRY_BREAD:
                        case ITEM_FOOD_ELLI_LEAVES:
                            var_0 = NPC_INTERACTION_DISLIKED_GIFT;
                            break;
                        case ITEM_FOOD_FAILED_DISH:
                        case ITEM_FOOD_FAILED_DRINK:
                        case ITEM_FOOD_FAILED_POT_DISH:
                        case ITEM_FOOD_FAILED_DESSERT:
                        case ITEM_FOOD_FAILED_BREAD:
                        case ITEM_FOOD_FAILED_NOODLES:
                            var_0 = NPC_INTERACTION_HATED_GIFT;
                            break;
                    }
                    break;
                case HELD_ITEM_KIND_ARTICLE:
                    switch (GetPlayerHeldArticleId())
                    {
                        case ITEM_ARTICLE_FLOWER_PINK_CAT:
                        case ITEM_ARTICLE_PINK_DIAMOND:
                        case ITEM_ARTICLE_DIAMOND:
                            var_0 = NPC_INTERACTION_FAVORITE_GIFT;
                            break;
                        case ITEM_ARTICLE_FLOWER_MOON_DROP:
                        case ITEM_ARTICLE_FLOWER_TOY:
                        case ITEM_ARTICLE_YARN_S:
                        case ITEM_ARTICLE_YARN_M:
                        case ITEM_ARTICLE_YARN_L:
                        case ITEM_ARTICLE_YARN_G:
                        case ITEM_ARTICLE_YARN_P:
                        case ITEM_ARTICLE_YARN_X:
                        case ITEM_ARTICLE_EMERALD:
                        case ITEM_ARTICLE_RUBY:
                        case ITEM_ARTICLE_TOPAZ:
                        case ITEM_ARTICLE_AMETHYST:
                        case ITEM_ARTICLE_LUMBER:
                            var_0 = NPC_INTERACTION_LIKED_GIFT;
                            break;
                        case ITEM_ARTICLE_FLOWER_MAGIC_BLUE:
                        case ITEM_ARTICLE_FLOWER_MAGIC_RED:
                        case ITEM_ARTICLE_WOOL_S:
                        case ITEM_ARTICLE_WOOL_M:
                        case ITEM_ARTICLE_WOOL_L:
                        case ITEM_ARTICLE_WOOL_G:
                        case ITEM_ARTICLE_WOOL_P:
                        case ITEM_ARTICLE_WOOL_X:
                        case ITEM_ARTICLE_PERIDOT:
                        case ITEM_ARTICLE_SPRING_SUN:
                        case ITEM_ARTICLE_SUMMER_SUN:
                        case ITEM_ARTICLE_AUTUMN_SUN:
                        case ITEM_ARTICLE_WINTER_SUN:
                        case ITEM_ARTICLE_LITHOGRAPH:
                        case ITEM_ARTICLE_MESSAGE_IN_A_BOTTLE:
                        case ITEM_ARTICLE_BALL:
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
                        case ITEM_ARTICLE_ALEXANDRITE:
                        case ITEM_ARTICLE_MYTHIC_STONE:
                        case ITEM_ARTICLE_FLUORITE:
                        case ITEM_ARTICLE_AGATE:
                        case ITEM_ARTICLE_WEEDS:
                        case ITEM_ARTICLE_STONES:
                        case ITEM_ARTICLE_BRANCHES:
                        case ITEM_ARTICLE_PIRATE_TREASURE:
                        case ITEM_ARTICLE_FOSSIL_OF_FISH:
                        case ITEM_ARTICLE_EMPTY_CAN:
                        case ITEM_ARTICLE_BOOTS:
                        case ITEM_ARTICLE_FISH_BONES:
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
        if (var_0 != NPC_INTERACTION_NO_APPLICABLE_GIFT)
        {
            if ((var_0 == NPC_INTERACTION_FAVORITE_GIFT || var_0 == NPC_INTERACTION_LIKED_GIFT || var_0 == NPC_INTERACTION_NEUTRAL_GIFT) && IsCharacterBirthdayToday(CHARACTER_MANNA))
            {
                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_BirthdayGiftResponse);
                SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_BirthdayDukeForgotPresentStoryPart1);
                SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_BirthdayDukeForgotPresentStoryPart2);
                SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_BirthdayDukeForgotPresentStoryPart3);
                SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_BirthdayDukeForgotPresentStoryPart4);
                SetTalkPortrait(TALK_PORTRAIT_JEFF_ANGRY);
                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_BirthdayJeffExclaimsAtDukesGiftDemand);
                SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_BirthdayDukeForgotPresentStoryPart6);
                SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_BirthdayDukeForgotPresentStoryPart7);
            }
            else
            {
                switch (var_0)
                {
                    case NPC_INTERACTION_FAVORITE_GIFT:
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_FavoriteGiftResponse);
                        break;
                    case NPC_INTERACTION_LIKED_GIFT:
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_LikedGiftResponse);
                        break;
                    case NPC_INTERACTION_NEUTRAL_GIFT:
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_NeutralGiftResponse);
                        break;
                    case NPC_INTERACTION_DISLIKED_GIFT:
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_DislikedGiftResponse);
                        break;
                    case NPC_INTERACTION_HATED_GIFT:
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_HatedGiftResponse);
                        break;
                    case NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE:
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_FavorableAnimalResponse);
                        break;
                    case NPC_INTERACTION_UNFAVORABLE_ANIMAL_RESPONSE:
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_UnfavorableAnimalResponse);
                        break;
                    case NPC_INTERACTION_ACCESSORY:
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_AccessoryGiftResponsePart1);
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_AccessoryGiftResponsePart2);
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_AccessoryGiftResponsePart3);
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
#if defined(REGION_JP) || defined(REGION_DE)
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_AccessoryGiftResponsePart4);
#else
                        TalkMessage(gText_NPCEvent_Manna_DialogueAndGiftResponses_AccessoryGiftResponsePart4);
#endif
                        break;
                    case NPC_INTERACTION_COSMETIC:
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_CosmeticGiftResponse);
                        break;
                    case NPC_INTERACTION_PERFUME:
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_PerfumeGiftResponse);
                        break;
                }
            }
            if (WasNpcGiftedToday(CHARACTER_MANNA) == FALSE)
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
                        var_1 = 9;
                        break;
                    case NPC_INTERACTION_COSMETIC:
                        var_1 = 9;
                        break;
                    case NPC_INTERACTION_PERFUME:
                        var_1 = 9;
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
                        var_1 = 3;
                        break;
                    case NPC_INTERACTION_COSMETIC:
                        var_1 = 3;
                        break;
                    case NPC_INTERACTION_PERFUME:
                        var_1 = 3;
                        break;
                }
            }
            if (IsCharacterBirthdayToday(CHARACTER_MANNA))
            {
                var_1 *= 5;
            }
            if (IsPlayerHeldItemWrapped())
            {
                var_1 = var_1 + var_1 / 4;
            }
            AddNpcFriendship(CHARACTER_MANNA, var_1);
            if (VarGet(VAR_RECIPE_LEARNED_FROM_MANNA) == FALSE && var_2 == 0 && GetNpcFriendship(CHARACTER_MANNA) > 100 && (var_0 == NPC_INTERACTION_FAVORITE_GIFT || var_0 == NPC_INTERACTION_LIKED_GIFT || var_0 == NPC_INTERACTION_NEUTRAL_GIFT))
            {
                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_RecipeTeachingIntroduction);
                VarSet(VAR_RECIPE_LEARNED_FROM_MANNA, TRUE);
            }
            TalkClose();
            if (var_0 == NPC_INTERACTION_FAVORITE_GIFT || var_0 == NPC_INTERACTION_LIKED_GIFT || var_0 == NPC_INTERACTION_NEUTRAL_GIFT || var_0 == NPC_INTERACTION_DISLIKED_GIFT || var_0 == NPC_INTERACTION_HATED_GIFT || var_0 == NPC_INTERACTION_ACCESSORY || var_0 == NPC_INTERACTION_COSMETIC || var_0 == NPC_INTERACTION_PERFUME)
            {
                UsePlayerHeldItem();
            }
            MarkNpcGifted(CHARACTER_MANNA);
        }
        else
        {
            if (IsPlayerHoldingTool())
            {
                switch (GetPlayerHeldToolId())
                {
                    case ITEM_TOOL_BLUE_FEATHER:
                        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_CommentsOnBlueFeather);
                        break;
                }
            }
            else
            {
                if (GetNpcFriendship(CHARACTER_MANNA) > 250 && VarGet(VAR_MANNA_AJAS_DEPARTURE_ADVICE_FROM_FRIENDS_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && HasLocalLinkMilestone(LOCAL_LINK_MILESTONE_MANNA_AJA_UPDATE_DIALOGUE) == FALSE)
                {
                    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                    TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_GameCubeLinkAjaUpdateDialogue);
                    SetLocalLinkMilestone(LOCAL_LINK_MILESTONE_MANNA_AJA_UPDATE_DIALOGUE);
                }
                else
                {
                    switch (GetEntityLocation(ENTITY_MANNA))
                    {
                        case MAP_NORTH_SIDE_TOWN:
                            if (!(VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_SATURDAY) && VarGet(VAR_WEATHER_TODAY) == WEATHER_SUNNY && (VarGet(VAR_HOUR) >= 13 && VarGet(VAR_HOUR) < 16) || VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_SATURDAY && !(VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE && VarGet(VAR_CLIFF_PERMANENT_WINERY_JOB_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && (VarGet(VAR_HOUR) >= 13 && VarGet(VAR_HOUR) < 16))
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_NorthSideTownAfternoonConversation);
                            }
                            else
                            {
                                if (VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_SATURDAY && VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE && VarGet(VAR_CLIFF_PERMANENT_WINERY_JOB_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && (VarGet(VAR_HOUR) >= 13 && VarGet(VAR_HOUR) < 16) && VarGet(VAR_WEATHER_TODAY) == WEATHER_SUNNY)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                    TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_NorthSideTownSaturdayAfternoonAfterCliffWineryEmployment);
                                }
                                else
                                {
                                    if (!(VarGet(VAR_WEATHER_TODAY) == WEATHER_SUNNY) && (VarGet(VAR_HOUR) >= 13 && VarGet(VAR_HOUR) < 16 || VarGet(VAR_HOUR) >= 16 && VarGet(VAR_HOUR) < 22))
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
                                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_NorthSideTownNonSunnyConversation);
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_SATURDAY && VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE && VarGet(VAR_CLIFF_PERMANENT_WINERY_JOB_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && (VarGet(VAR_HOUR) >= 16 && VarGet(VAR_HOUR) < 19))
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
                                            TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_NorthSideTownSaturdayLateAfternoonAfterCliffWineryEmployment);
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_SATURDAY && (VarGet(VAR_HOUR) >= 7 && VarGet(VAR_HOUR) < 13))
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_NorthSideTownSaturdayMorningConversation);
                                            }
                                            else
                                            {
                                                if (!(VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_SATURDAY) && VarGet(VAR_WEATHER_TODAY) == WEATHER_SUNNY && (VarGet(VAR_HOUR) >= 16 && VarGet(VAR_HOUR) < 22) || !(VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_SATURDAY) && !(VarGet(VAR_WEATHER_TODAY) == WEATHER_SUNNY) && (VarGet(VAR_HOUR) >= 16 && VarGet(VAR_HOUR) < 22) || VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_SATURDAY && !(VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE && VarGet(VAR_CLIFF_PERMANENT_WINERY_JOB_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && (VarGet(VAR_HOUR) >= 16 && VarGet(VAR_HOUR) < 22) || VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_SATURDAY && (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE && VarGet(VAR_CLIFF_PERMANENT_WINERY_JOB_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED) && (VarGet(VAR_HOUR) >= 19 && VarGet(VAR_HOUR) < 22))
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
                                                    TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_NorthSideTownEveningConversation);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case MAP_AJA_WINERY_2F:
                            if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Winery2FFirstConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Winery2FRepeatConversation);
                            }
                            break;
                        case MAP_AJA_WINERY_1F:
                            if (VarGet(VAR_HOUR) >= 7 && VarGet(VAR_HOUR) < 13)
                            {
                                if (GetNpcFriendship(CHARACTER_MANNA) <= 100)
                                {
                                    if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
                                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Winery1FMorningFriendship0To100FirstConversation);
                                    }
                                    else
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Winery1FMorningFriendship0To100RepeatConversation);
                                    }
                                }
                                else
                                {
                                    if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Winery1FMorningFriendshipAbove100FirstConversation);
                                    }
                                    else
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
                                        TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Winery1FMorningFriendshipAbove100RepeatConversation);
                                    }
                                }
                            }
                            else
                            {
                                if (VarGet(VAR_HOUR) >= 16 && VarGet(VAR_HOUR) < 22)
                                {
                                    if (GetNpcFriendship(CHARACTER_MANNA) <= 100)
                                    {
                                        if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
                                            TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Winery1FEveningFriendship0To100GreetingBeforeJoannaEstrangementStory);
                                        }
                                        else
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
                                            TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Winery1FEveningFriendship0To100JoannaEstrangementStory);
                                        }
                                    }
                                    else
                                    {
                                        if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                            TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Winery1FEveningFriendshipAbove100GreetingBeforeRodAbsenceStory);
                                            SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
                                            TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Winery1FEveningFriendshipAbove100RodAbsenceStory);
                                        }
                                        else
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                            TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_Winery1FEveningFriendshipAbove100RepeatConversation);
                                        }
                                    }
                                }
                            }
                            break;
                        case MAP_BASIL_HOUSE_1F:
                            if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_BasilHouseFirstConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_BasilHouseRepeatConversation);
                            }
                            break;
                        case MAP_ROSE_SQUARE:
                            if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_RoseSquareGossipFirstConversationPart1);
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_RoseSquareGossipSilentPause);
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_RoseSquareGossipFirstConversationPart3);
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_RoseSquareGossipSilentPause);
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_RoseSquareGossipFirstConversationPart4);
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_RoseSquareGossipFirstConversationPart5);
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_RoseSquareGossipFirstConversationPart6);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_RoseSquareGossipRepeatConversation);
                            }
                            break;
                        case MAP_SUPERMARKET:
                            if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_ANGRY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_SupermarketDukeCreditGossipFirstConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_SupermarketDukeCreditGossipRepeatConversation);
                            }
                            break;
                        case MAP_INN_1F:
                            if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_InnCliffEmploymentFirstConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_InnCliffEmploymentRepeatConversation);
                            }
                            break;
                        case MAP_CHURCH:
                            if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_ChurchCliffConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
                                TalkMessageSlow(gText_NPCEvent_Manna_DialogueAndGiftResponses_ChurchRepeatConversation);
                            }
                            break;
                    }
                    MarkNpcSpokenTo(CHARACTER_MANNA);
                }
            }
        }
    }
    TalkClose();
    SetEntityFacing(ENTITY_MANNA, var_3);
}
