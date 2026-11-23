#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0993_NPCEvent_Popuri_DialogueAndGiftResponses.mary.h"

void EventScript_0993_NPCEvent_Popuri_DialogueAndGiftResponses(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
    if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && (VarGet(VAR_CHILD_AGE_DAYS) >= 0 && VarGet(VAR_CHILD_AGE_DAYS) < CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START) && GetEntityLocation(ENTITY_CHILD) != MAP_FARMHOUSE && GetEntityLocation(ENTITY_POPURI) == MAP_FARMHOUSE)
    {
        SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_WITH_NEWBORN);
        var_5 = FALSE;
    }
    else
    {
        SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
        var_5 = TRUE;
    }
    var_4 = GetEntityFacing(ENTITY_POPURI);
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SEASON) == SEASON_WINTER && VarGet(VAR_DAY) == DAY_14)
    {
        switch (GetEntityLocation(ENTITY_POPURI))
        {
            case MAP_FARM:
                CallScript(EventScript_1294_FestivalEvent_WinterThanksgiving_GiftVisit_Popuri);
                break;
        }
    }
    if (VarGet(VAR_SEASON) == SEASON_FALL && VarGet(VAR_DAY) == DAY_30)
    {
        switch (GetEntityLocation(ENTITY_POPURI))
        {
            case MAP_FARM:
                CallScript(EventScript_1292_FestivalEvent_PumpkinFestival_TreatVisit_Popuri);
                break;
        }
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    if (HasMetNpc(CHARACTER_POPURI) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
        {
            ShowTalkHeartIndicator(CHARACTER_POPURI);
        }
        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PopuriIntroducesHerselfToPlayer);
        MarkNpcSpokenTo(CHARACTER_POPURI);
    }
    else
    {
        if (IsPlayerHoldingNothing() || (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_RICK_AND_POPURI_RUSH_TO_SICK_LILLIA_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_LILLIA_READS_RODS_LETTER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_KAREN_COMFORTS_LONELY_RICK_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_LILLIA_AND_SASHA_REMINISCE_ABOUT_JEFFS_MARRIAGE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS) || (VarGet(VAR_ANN_CLIFF_RIVAL_EVENT_2_STATE) == EVENT_LIFECYCLE_IN_PROGRESS || VarGet(VAR_CARTER_CONFESSIONAL_DREAM_PREDICTS_GOOD_FORTUNE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS))
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
                        case ITEM_FOOD_SCRAMBLED_EGGS_OR_JAPANESE_OMELET:
                        case ITEM_FOOD_OMELET:
                        case ITEM_FOOD_OMELET_RICE:
                            var_0 = NPC_INTERACTION_SPECIAL_FAVORITE_GIFT;
                            break;
                        case ITEM_FOOD_STRAWBERRY:
                        case ITEM_FOOD_REGULAR_QUALITY_EGG:
                        case ITEM_FOOD_GOOD_QUALITY_EGG:
                        case ITEM_FOOD_HIGH_QUALITY_EGG:
                        case ITEM_FOOD_GOLDEN_EGG:
                        case ITEM_FOOD_P_EGG:
                        case ITEM_FOOD_X_EGG:
                        case ITEM_FOOD_APPLE:
                        case ITEM_FOOD_CHOCOLATE:
                        case ITEM_FOOD_SUGDW_APPLE:
                        case ITEM_FOOD_HMSGB_APPLE:
                        case ITEM_FOOD_AEPFE_APPLE:
                        case ITEM_FOOD_SANDWICH:
                        case ITEM_FOOD_FRUIT_JUICE:
                        case ITEM_FOOD_STRAWBERRY_MILK:
                        case ITEM_FOOD_STRAWBERRY_JAM:
                        case ITEM_FOOD_BOILED_EGG:
                        case ITEM_FOOD_APPLE_PIE:
                        case ITEM_FOOD_APPLE_JAM:
                        case ITEM_FOOD_BAKED_APPLE:
                        case ITEM_FOOD_ICE_CREAM:
                        case ITEM_FOOD_CAKE:
                        case ITEM_FOOD_CHOCOLATE_CAKE:
                        case ITEM_FOOD_RELAXATION_TEA:
                        case ITEM_FOOD_PUDDING:
                        case ITEM_FOOD_EGG_OVER_RICE_OR_EGG_BOWL:
                        case ITEM_FOOD_PANCAKES:
                            var_0 = NPC_INTERACTION_FAVORITE_GIFT;
                            break;
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
                        case ITEM_FOOD_HONEY:
                        case ITEM_FOOD_GRAPE_JUICE:
                        case ITEM_FOOD_BREAD:
                        case ITEM_FOOD_FLOUR:
                        case ITEM_FOOD_RELAX_TEA_LEAVES:
                        case ITEM_FOOD_STEW:
                        case ITEM_FOOD_SAVORY_PANCAKE:
                        case ITEM_FOOD_FRENCH_FRIES:
                        case ITEM_FOOD_KETCHUP:
                        case ITEM_FOOD_POPCORN:
                        case ITEM_FOOD_BAKED_CORN:
                        case ITEM_FOOD_PINEAPPLE_JUICE:
                        case ITEM_FOOD_PUMPKIN_PUDDING:
                        case ITEM_FOOD_SWEET_POTATOES:
                        case ITEM_FOOD_HOT_MILK:
                        case ITEM_FOOD_BAMBOO_RICE:
                        case ITEM_FOOD_GRAPE_JAM:
                        case ITEM_FOOD_CHIRASHI_SUSHI:
                        case ITEM_FOOD_TOAST:
                        case ITEM_FOOD_FRENCH_TOAST:
                        case ITEM_FOOD_CANDIED_POTATO:
                            var_0 = NPC_INTERACTION_LIKED_GIFT;
                            break;
                        case ITEM_FOOD_POTATO:
                        case ITEM_FOOD_CUCUMBER:
                        case ITEM_FOOD_CABBAGE:
                        case ITEM_FOOD_TOMATO:
                        case ITEM_FOOD_CORN:
                        case ITEM_FOOD_ONION:
                        case ITEM_FOOD_CARROT:
                        case ITEM_FOOD_SWEET_POTATO:
                        case ITEM_FOOD_SPINACH:
                        case ITEM_FOOD_SPA_BOILED_EGG:
                        case ITEM_FOOD_CHEESE_S:
                        case ITEM_FOOD_CHEESE_M:
                        case ITEM_FOOD_CHEESE_L:
                        case ITEM_FOOD_CHEESE_G:
                        case ITEM_FOOD_CHEESE_P:
                        case ITEM_FOOD_CHEESE_X:
                        case ITEM_FOOD_BAMBOO_SHOOT:
                        case ITEM_FOOD_WILD_GRAPES:
                        case ITEM_FOOD_MUSHROOM:
                        case ITEM_FOOD_TRUFFLE:
                        case ITEM_FOOD_RICE_BALL:
                        case ITEM_FOOD_OIL:
                        case ITEM_FOOD_CURRY_POWDER:
                        case ITEM_FOOD_MUFFIN_MIX_OR_RICE_FLOUR:
                        case ITEM_FOOD_SALAD:
                        case ITEM_FOOD_CURRY_RICE:
                        case ITEM_FOOD_MISO_SOUP:
                        case ITEM_FOOD_STIR_FRY:
                        case ITEM_FOOD_FRIED_RICE:
                        case ITEM_FOOD_FRUIT_LATTE:
                        case ITEM_FOOD_PICKLES:
                        case ITEM_FOOD_CORN_FLAKES:
                        case ITEM_FOOD_BAKED_SWEET_POTATO:
                        case ITEM_FOOD_GREENS:
                        case ITEM_FOOD_BUTTER:
                        case ITEM_FOOD_CHEESE_CAKE:
                        case ITEM_FOOD_CHEESE_FONDUE:
                        case ITEM_FOOD_MUSHROOM_RICE:
                        case ITEM_FOOD_TRUFFLE_RICE:
                        case ITEM_FOOD_SUSHI:
                        case ITEM_FOOD_JAM_BUN:
                        case ITEM_FOOD_DINNER_ROLL:
                        case ITEM_FOOD_RAISIN_BREAD:
                        case ITEM_FOOD_CURRY_BREAD:
                        case ITEM_FOOD_SASHIMI:
                        case ITEM_FOOD_GRILLED_FISH:
                        case ITEM_FOOD_PIZZA:
                        case ITEM_FOOD_NOODLES:
                        case ITEM_FOOD_CURRY_NOODLES:
                        case ITEM_FOOD_TEMPURA_NOODLES:
                        case ITEM_FOOD_FRIED_NOODLES:
                        case ITEM_FOOD_BUCKWHEAT_NOODLES:
                        case ITEM_FOOD_NOODLES_W_TEMPURA:
                        case ITEM_FOOD_FRIED_BUCKWHEAT_NOODLES:
                        case ITEM_FOOD_BUCKWHEAT_CHIPS:
                        case ITEM_FOOD_TEMPURA:
                        case ITEM_FOOD_MOUNTAIN_STEW:
                        case ITEM_FOOD_MOON_DUMPLINGS:
                        case ITEM_FOOD_ELLI_LEAVES:
                        case ITEM_FOOD_SMALL_FISH:
                        case ITEM_FOOD_MEDIUM_FISH:
                        case ITEM_FOOD_LARGE_FISH:
                        case ITEM_FOOD_TOASTED_RICE_BALL:
                        case ITEM_FOOD_TEMPURA_RICE:
                        case ITEM_FOOD_RICE_GRUEL:
                        case ITEM_FOOD_FISH_STICKS:
                        case ITEM_FOOD_POTATO_PANCAKES_OR_CROQUETTE:
                            var_0 = NPC_INTERACTION_NEUTRAL_GIFT;
                            break;
                        case ITEM_FOOD_TURNIP:
                        case ITEM_FOOD_PUMPKIN:
                        case ITEM_FOOD_EGGPLANT:
                        case ITEM_FOOD_GREEN_PEPPER:
                        case ITEM_FOOD_BUCKWHEAT_FLOUR:
                        case ITEM_FOOD_VEGETABLE_JUICE:
                        case ITEM_FOOD_MIXED_JUICE:
                        case ITEM_FOOD_VEGETABLE_LATTE:
                        case ITEM_FOOD_MIXED_LATTE:
                        case ITEM_FOOD_TOMATO_JUICE:
                        case ITEM_FOOD_PICKLED_TURNIP:
                        case ITEM_FOOD_PUMPKIN_STEW:
                        case ITEM_FOOD_HAPPY_EGGPLANT:
                        case ITEM_FOOD_RICE_CAKE:
                        case ITEM_FOOD_ROASTED_RICE_CAKE:
                            var_0 = NPC_INTERACTION_DISLIKED_GIFT;
                            break;
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
                        case ITEM_FOOD_WILD_GRAPE_JUICE:
                        case ITEM_FOOD_FAILED_DISH:
                        case ITEM_FOOD_FAILED_DRINK:
                        case ITEM_FOOD_FAILED_POT_DISH:
                        case ITEM_FOOD_FAILED_DESSERT:
                        case ITEM_FOOD_FAILED_BREAD:
                        case ITEM_FOOD_FAILED_NOODLES:
                            var_0 = NPC_INTERACTION_HATED_GIFT;
                            break;
                        case ITEM_FOOD_COOKIES:
                        case ITEM_FOOD_CHOCOLATE_COOKIES:
                            if (VarGet(VAR_SEASON) == SEASON_SPRING && VarGet(VAR_DAY) == DAY_14 && VarGet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_POPURI) == FALSE)
                            {
                                var_0 = NPC_INTERACTION_THANKSGIVING_GIFT;
                            }
                            else
                            {
                                var_0 = NPC_INTERACTION_FAVORITE_GIFT;
                            }
                            break;
                    }
                    break;
                case HELD_ITEM_KIND_ARTICLE:
                    switch (GetPlayerHeldArticleId())
                    {
                        case ITEM_ARTICLE_PINK_DIAMOND:
                        case ITEM_ARTICLE_DIAMOND:
                            var_0 = NPC_INTERACTION_FAVORITE_GIFT;
                            break;
                        case ITEM_ARTICLE_FLOWER_PINK_CAT:
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
                            var_0 = NPC_INTERACTION_LIKED_GIFT;
                            break;
                        case ITEM_ARTICLE_FLOWER_MOON_DROP:
                        case ITEM_ARTICLE_FLOWER_MAGIC_BLUE:
                        case ITEM_ARTICLE_FLOWER_MAGIC_RED:
                        case ITEM_ARTICLE_WOOL_S:
                        case ITEM_ARTICLE_WOOL_M:
                        case ITEM_ARTICLE_WOOL_L:
                        case ITEM_ARTICLE_WOOL_G:
                        case ITEM_ARTICLE_WOOL_P:
                        case ITEM_ARTICLE_WOOL_X:
                        case ITEM_ARTICLE_ADAMANTITE:
                        case ITEM_ARTICLE_PERIDOT:
                        case ITEM_ARTICLE_SPRING_SUN:
                        case ITEM_ARTICLE_SUMMER_SUN:
                        case ITEM_ARTICLE_AUTUMN_SUN:
                        case ITEM_ARTICLE_WINTER_SUN:
                        case ITEM_ARTICLE_WEEDS:
                            var_0 = NPC_INTERACTION_NEUTRAL_GIFT;
                            break;
                        case ITEM_ARTICLE_JUNK_ORE:
                        case ITEM_ARTICLE_COPPER:
                        case ITEM_ARTICLE_SILVER:
                        case ITEM_ARTICLE_GOLD:
                        case ITEM_ARTICLE_MYSTRILE:
                        case ITEM_ARTICLE_ORICHALC:
                        case ITEM_ARTICLE_MOON_STONE:
                        case ITEM_ARTICLE_SAND_ROSE:
                        case ITEM_ARTICLE_ALEXANDRITE:
                        case ITEM_ARTICLE_MYTHIC_STONE:
                        case ITEM_ARTICLE_FLUORITE:
                        case ITEM_ARTICLE_AGATE:
                        case ITEM_ARTICLE_BALL:
                            var_0 = NPC_INTERACTION_DISLIKED_GIFT;
                            break;
                        case ITEM_ARTICLE_STONES:
                        case ITEM_ARTICLE_BRANCHES:
                        case ITEM_ARTICLE_LITHOGRAPH:
                        case ITEM_ARTICLE_MESSAGE_IN_A_BOTTLE:
                        case ITEM_ARTICLE_PIRATE_TREASURE:
                        case ITEM_ARTICLE_FOSSIL_OF_FISH:
                        case ITEM_ARTICLE_EMPTY_CAN:
                        case ITEM_ARTICLE_BOOTS:
                        case ITEM_ARTICLE_FISH_BONES:
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
                    if (VarGet(VAR_DOG_GROWTH_STAGE) == ANIMAL_PET_GROWTH_STAGE_YOUNG)
                    {
                        var_0 = NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE;
                    }
                    else
                    {
                        var_0 = NPC_INTERACTION_UNFAVORABLE_ANIMAL_RESPONSE;
                    }
                    break;
                case HELD_ITEM_KIND_CHICKEN:
                    var_0 = NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE;
                    break;
            }
        }
        if (var_0 != NPC_INTERACTION_NO_APPLICABLE_GIFT)
        {
            if ((var_0 == NPC_INTERACTION_SPECIAL_FAVORITE_GIFT || var_0 == NPC_INTERACTION_FAVORITE_GIFT || var_0 == NPC_INTERACTION_LIKED_GIFT || var_0 == NPC_INTERACTION_NEUTRAL_GIFT) && IsCharacterBirthdayToday(CHARACTER_POPURI))
            {
                if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseBirthdayGiftResponse);
                }
                else
                {
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                    {
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                    }
                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_NonPlayerSpouseBirthdayGiftResponse);
                }
            }
            else
            {
                if ((var_0 == NPC_INTERACTION_ACCESSORY || var_0 == NPC_INTERACTION_COSMETIC) && IsCharacterBirthdayToday(CHARACTER_POPURI))
                {
                    if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseAccessoryOrCosmeticBirthdayGiftResponse);
                    }
                    else
                    {
                        if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                        {
                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpouseAccessoryOrCosmeticBirthdayGiftResponse);
                        }
                        else
                        {
                            SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                            {
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                            }
                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedAccessoryOrCosmeticBirthdayGiftResponse);
                        }
                    }
                }
                else
                {
                    switch (var_0)
                    {
                        case NPC_INTERACTION_SPECIAL_FAVORITE_GIFT:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseSpecialFavoriteGiftResponse);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_NonPlayerSpouseSpecialFavoriteGiftResponse);
                            }
                            break;
                        case NPC_INTERACTION_FAVORITE_GIFT:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFavoriteGiftResponse);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_NonPlayerSpouseFavoriteGiftResponse);
                            }
                            break;
                        case NPC_INTERACTION_LIKED_GIFT:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseLikedGiftResponse);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_NonPlayerSpouseLikedGiftResponse);
                            }
                            break;
                        case NPC_INTERACTION_NEUTRAL_GIFT:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseNeutralGiftResponse);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_NonPlayerSpouseNeutralGiftResponse);
                            }
                            break;
                        case NPC_INTERACTION_DISLIKED_GIFT:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseDislikedGiftResponse);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_NonPlayerSpouseDislikedGiftResponse);
                            }
                            break;
                        case NPC_INTERACTION_HATED_GIFT:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseHatedGiftResponse);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_NonPlayerSpouseHatedGiftResponse);
                            }
                            break;
                        case NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFavorableAnimalResponse);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_NonPlayerSpouseFavorableAnimalResponse);
                            }
                            break;
                        case NPC_INTERACTION_UNFAVORABLE_ANIMAL_RESPONSE:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseUnfavorableAnimalResponse);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_NonPlayerSpouseUnfavorableAnimalResponse);
                            }
                            break;
                        case NPC_INTERACTION_ACCESSORY:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseAccessoryGiftResponse);
                            }
                            else
                            {
                                if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpouseAccessoryOrCosmeticGiftResponse);
                                }
                                else
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                    {
                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                    }
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedAccessoryGiftResponse);
                                }
                            }
                            break;
                        case NPC_INTERACTION_COSMETIC:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseCosmeticGiftResponse);
                            }
                            else
                            {
                                if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
#if defined(REGION_JP)
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpouseCosmeticGiftResponse);
#else
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpouseAccessoryOrCosmeticGiftResponse);
#endif
                                }
                                else
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                    {
                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                    }
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedCosmeticGiftResponse);
                                }
                            }
                            break;
                        case NPC_INTERACTION_PERFUME:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePerfumeGiftResponse);
                            }
                            else
                            {
                                if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePerfumeGiftResponse);
                                }
                                else
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                    {
                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                    }
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedPerfumeGiftResponse);
                                }
                            }
                            break;
                        case NPC_INTERACTION_THANKSGIVING_GIFT:
                            if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_SpringThanksgivingRivalSpouseGiftResponse);
                                VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_POPURI, TRUE);
                            }
                            else
                            {
                                if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_SpringThanksgivingPlayerSpouseGiftResponse);
                                    VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_POPURI, TRUE);
                                }
                                else
                                {
                                    if (VarGet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_POPURI) == FALSE)
                                    {
                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED))
                                        {
                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                        }
                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_SpringThanksgivingWithoutPriorWinterGiftResponse);
                                        VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_POPURI, TRUE);
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_POPURI) == TRUE)
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED))
                                            {
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                            }
                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_SpringThanksgivingAfterPriorWinterGiftResponse);
                                            VarSet(VAR_WINTER_THANKSGIVING_GIFT_RECEIVED_FROM_POPURI, FALSE);
                                            VarSet(VAR_THANKSGIVING_GIFT_EXCHANGED_WITH_POPURI, TRUE);
                                        }
                                    }
                                }
                            }
                            break;
                    }
                }
            }
            if (WasNpcGiftedToday(CHARACTER_POPURI) == FALSE)
            {
                switch (var_0)
                {
                    case NPC_INTERACTION_SPECIAL_FAVORITE_GIFT:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = 800;
                        }
                        var_1 = 9;
                        break;
                    case NPC_INTERACTION_FAVORITE_GIFT:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = 500;
                        }
                        var_1 = 9;
                        break;
                    case NPC_INTERACTION_LIKED_GIFT:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = 300;
                        }
                        var_1 = 3;
                        break;
                    case NPC_INTERACTION_NEUTRAL_GIFT:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = 100;
                        }
                        var_1 = 1;
                        break;
                    case NPC_INTERACTION_DISLIKED_GIFT:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = mary_negated_int(-500);
                        }
                        var_1 = mary_negated_int(-3);
                        break;
                    case NPC_INTERACTION_HATED_GIFT:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = mary_negated_int(-800);
                        }
                        var_1 = mary_negated_int(-9);
                        break;
                    case NPC_INTERACTION_FAVORABLE_ANIMAL_RESPONSE:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = 100;
                        }
                        var_1 = 1;
                        break;
                    case NPC_INTERACTION_UNFAVORABLE_ANIMAL_RESPONSE:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = mary_negated_int(-500);
                        }
                        var_1 = mary_negated_int(-3);
                        break;
                    case NPC_INTERACTION_ACCESSORY:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = 500;
                        }
                        var_1 = 9;
                        break;
                    case NPC_INTERACTION_COSMETIC:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = 500;
                        }
                        var_1 = 9;
                        break;
                    case NPC_INTERACTION_PERFUME:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = 500;
                        }
                        var_1 = 9;
                        break;
                    case NPC_INTERACTION_THANKSGIVING_GIFT:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = 1000;
                        }
                        var_1 = 20;
                        break;
                }
            }
            else
            {
                switch (var_0)
                {
                    case NPC_INTERACTION_SPECIAL_FAVORITE_GIFT:
                        var_1 = 3;
                        break;
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
                    case NPC_INTERACTION_THANKSGIVING_GIFT:
                        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                        {
                            var_2 = 1000;
                        }
                        var_1 = 20;
                        break;
                }
            }
            if (IsCharacterBirthdayToday(CHARACTER_POPURI))
            {
                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                {
                    var_2 *= 5;
                }
                var_1 *= 5;
            }
            if (IsPlayerHeldItemWrapped())
            {
                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                {
                    var_2 = var_2 + var_2 / 4;
                }
                var_1 = var_1 + var_1 / 4;
            }
            AddNpcFriendship(CHARACTER_POPURI, var_1);
            AddCharacterLove(CHARACTER_POPURI, var_2);
            TalkClose();
            if (var_0 == NPC_INTERACTION_SPECIAL_FAVORITE_GIFT || var_0 == NPC_INTERACTION_FAVORITE_GIFT || var_0 == NPC_INTERACTION_LIKED_GIFT || var_0 == NPC_INTERACTION_NEUTRAL_GIFT || var_0 == NPC_INTERACTION_DISLIKED_GIFT || var_0 == NPC_INTERACTION_HATED_GIFT || var_0 == NPC_INTERACTION_ACCESSORY || var_0 == NPC_INTERACTION_COSMETIC || var_0 == NPC_INTERACTION_PERFUME || var_0 == NPC_INTERACTION_THANKSGIVING_GIFT)
            {
                UsePlayerHeldItem();
            }
            MarkNpcGifted(CHARACTER_POPURI);
        }
        else
        {
            if (IsPlayerHoldingTool())
            {
                switch (GetPlayerHeldToolId())
                {
                    case ITEM_TOOL_BLUE_FEATHER:
                        if (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_KAREN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ANN_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_MARY_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_ELLI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HARVEST_GODDESS_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_EVENT_4_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_HAS_LARGE_BED) == TRUE && GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_RED_MIN)
                        {
                            SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PopuriAcceptsBlueFeatherProposalAndAsksToGoToFarmhouse);
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            VarSet(VAR_POPURI_PROPOSAL_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
                            CallScript(EventScript_0043_LoveEvent_Popuri_ProposalAccepted);
                        }
                        else
                        {
                            if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PopuriRejectsBlueFeatherAfterMarriageToKai);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PopuriRejectsBlueFeatherProposal);
                            }
                        }
                        break;
                }
            }
            else
            {
                if (VarGet(VAR_SEASON) == SEASON_WINTER && VarGet(VAR_DAY) == DAY_23 && (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE && VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE)) && GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_GREEN_MIN && VarGet(VAR_STARRY_NIGHT_POPURI_INVITATION_HANDLED) == FALSE && VarGet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX) == STARRY_NIGHT_HOST_NONE)
                {
                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PopuriInvitesPlayerToStarryNightFestival);
                    var_3 = TalkChoice2(gText_NPCEvent_Popuri_DialogueAndGiftResponses_ChoiceAcceptStarryNightInvitation, gText_NPCEvent_Popuri_DialogueAndGiftResponses_ChoiceDeclineStarryNightInvitation);
                    switch (var_3)
                    {
                        case CHOICE_OPTION_1:
                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PopuriConfirmsAcceptedStarryNightInvitation);
                            VarSet(VAR_FESTIVAL_STARRY_NIGHT_HOST_INDEX, STARRY_NIGHT_HOST_POPURI_HOUSEHOLD);
                            VarSet(VAR_STARRY_NIGHT_POPURI_INVITATION_HANDLED, TRUE);
                            break;
                        case CHOICE_OPTION_2:
                            SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PopuriRespondsToDeclinedStarryNightInvitation);
                            VarSet(VAR_STARRY_NIGHT_POPURI_INVITATION_HANDLED, TRUE);
                            break;
                    }
                }
                else
                {
                    switch (GetEntityLocation(ENTITY_POPURI))
                    {
                        case MAP_FARMHOUSE:
                            if (VarGet(VAR_SEASON) == SEASON_WINTER && VarGet(VAR_DAY) == DAY_23)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_FarmhouseStarryNightSpousePartyInvitation);
                            }
                            else
                            {
                                if (VarGet(VAR_POPURI_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED && (VarGet(VAR_HOUR) >= 6 && VarGet(VAR_HOUR) < 12))
                                {
                                    if (VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) >= 0 && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) < PREGNANCY_DAYS_SPOUSE_DIALOGUE_SECOND_STAGE_START)
                                    {
                                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePregnancyStage01FirstConversation);
                                        }
                                        else
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePregnancyStage01RepeatConversation);
                                        }
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) >= PREGNANCY_DAYS_SPOUSE_DIALOGUE_SECOND_STAGE_START && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) < PREGNANCY_DAYS_LATE_STAGE_START)
                                        {
                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePregnancyStage02FirstConversation);
                                            }
                                            else
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePregnancyStage02RepeatConversation);
                                            }
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) >= PREGNANCY_DAYS_LATE_STAGE_START && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) < PREGNANCY_DAYS_BIRTH_IMMINENT_START)
                                            {
                                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePregnancyStage03FirstConversation);
                                                }
                                                else
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePregnancyStage03RepeatConversation);
                                                }
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) >= PREGNANCY_DAYS_BIRTH_IMMINENT_START)
                                                {
                                                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePregnancyStage04BirthImminentFirstConversation);
                                                    }
                                                    else
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePregnancyStage04BirthImminentRepeatConversation);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && (VarGet(VAR_HOUR) >= 6 && VarGet(VAR_HOUR) < 12))
                                    {
                                        if (VarGet(VAR_CHILD_AGE_DAYS) >= 0 && VarGet(VAR_CHILD_AGE_DAYS) < CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
                                        {
                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
#if defined(REGION_DE)
#ifndef BUGFIX
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseNewbornStageFirstConversationUntranslatedEnglishLeadIn);
#endif
#endif
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseNewbornStageFirstConversation);
                                            }
                                            else
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseNewbornStageRepeatConversation);
                                            }
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START && VarGet(VAR_CHILD_AGE_DAYS) < 110)
                                            {
                                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseInfantStageFirstConversation);
                                                }
                                                else
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseInfantStageRepeatConversation);
                                                }
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_CHILD_AGE_DAYS) >= 110 && VarGet(VAR_CHILD_AGE_DAYS) < CHILD_AGE_DAYS_FIRST_STEPS_EVENT_START || VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_NOT_YET)
                                                {
                                                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePreWalkingChildStageFirstConversation);
                                                    }
                                                    else
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePreWalkingChildStageRepeatConversation);
                                                    }
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FIRST_STEPS_EVENT_START && VarGet(VAR_CHILD_AGE_DAYS) < 230 && VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
                                                    {
                                                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseWalkingChildStageFirstConversation);
                                                        }
                                                        else
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseWalkingChildStageRepeatConversation);
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (VarGet(VAR_CHILD_AGE_DAYS) >= 230 && VarGet(VAR_CHILD_CAN_WALK) == CHILD_WALKING_CAN_WALK)
                                                        {
                                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseOlderChildStageFirstConversation);
                                                            }
                                                            else
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseOlderChildStageRepeatConversation);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_GREEN_MIN)
                                        {
                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseBelowGreenHeartFirstConversationAngrySilence);
                                            }
                                            else
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseBelowGreenHeartRepeatConversation);
                                            }
                                        }
                                        else
                                        {
                                            if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_GREEN_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_YELLOW_MIN)
                                            {
                                                if (VarGet(VAR_HOUR) >= 6 && VarGet(VAR_HOUR) < 12)
                                                {
                                                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseGreenHeartMorningFirstConversation);
                                                    }
                                                    else
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseGreenHeartMorningRepeatConversation);
                                                    }
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_HOUR) >= 12 && VarGet(VAR_HOUR) < 20)
                                                    {
                                                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseGreenHeartAfternoonFirstConversation);
                                                        }
                                                        else
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseGreenHeartAfternoonRepeatConversation);
                                                        }
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_YELLOW_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_ORANGE_MIN)
                                                {
                                                    if (VarGet(VAR_HOUR) >= 6 && VarGet(VAR_HOUR) < 12)
                                                    {
                                                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseYellowHeartMorningFirstConversation);
                                                        }
                                                        else
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseYellowHeartMorningRepeatConversation);
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (VarGet(VAR_HOUR) >= 12 && VarGet(VAR_HOUR) < 20)
                                                        {
                                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseYellowHeartAfternoonFirstConversation);
                                                            }
                                                            else
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseYellowHeartAfternoonRepeatConversation);
                                                            }
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_ORANGE_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_RED_MIN)
                                                    {
                                                        if (VarGet(VAR_HOUR) >= 6 && VarGet(VAR_HOUR) < 12)
                                                        {
                                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseOrangeHeartMorningFirstConversation);
                                                            }
                                                            else
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseOrangeHeartMorningRepeatConversation);
                                                            }
                                                        }
                                                        else
                                                        {
                                                            if (VarGet(VAR_HOUR) >= 12 && VarGet(VAR_HOUR) < 20)
                                                            {
                                                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                                {
                                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseOrangeHeartAfternoonFirstConversation);
                                                                }
                                                                else
                                                                {
                                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseOrangeHeartAfternoonRepeatConversation);
                                                                }
                                                            }
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_RED_MIN)
                                                        {
                                                            if (VarGet(VAR_HOUR) >= 6 && VarGet(VAR_HOUR) < 12)
                                                            {
                                                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                                {
                                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseRedHeartMorningFirstConversation);
                                                                }
                                                                else
                                                                {
                                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseRedHeartMorningRepeatConversation);
                                                                }
                                                            }
                                                            else
                                                            {
                                                                if (VarGet(VAR_HOUR) >= 12 && VarGet(VAR_HOUR) < 20)
                                                                {
                                                                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                                    {
                                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseRedHeartAfternoonFirstConversation);
                                                                    }
                                                                    else
                                                                    {
                                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseFarmhouseRedHeartAfternoonRepeatConversation);
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case MAP_POULTRY_FARM_HOUSE_1F:
                            if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                if (VarGet(VAR_POPURI_PREGNANCY_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_NOT_STARTED)
                                {
                                    if (VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) >= 0 && VarGet(VAR_DAYS_SINCE_PREGNANCY_EVENT) < 61)
                                    {
                                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseVisitsPoultryFarmDuringPregnancyFirstConversation);
                                        }
                                        else
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseVisitsPoultryFarmDuringPregnancyRepeatConversation);
                                        }
                                    }
                                }
                                else
                                {
                                    if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                                    {
                                        if (VarGet(VAR_CHILD_AGE_DAYS) > 0)
                                        {
                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseVisitsPoultryFarmAfterChildbirthFirstConversation);
                                            }
                                            else
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseVisitsPoultryFarmAfterChildbirthRepeatConversation);
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_GREEN_MIN)
                                        {
                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
#if defined(REGION_JP)
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseBelowGreenHeartFirstConversationAngrySilence);
#else
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpouseBelowGreenHeartFirstConversationAngrySilence_2);
#endif
                                            }
                                            else
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePoultryFarmBelowGreenHeartRepeatConversation);
                                            }
                                        }
                                        else
                                        {
                                            if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_GREEN_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_YELLOW_MIN)
                                            {
                                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePoultryFarmGreenHeartFirstConversation);
                                                }
                                                else
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePoultryFarmGreenHeartRepeatConversation);
                                                }
                                            }
                                            else
                                            {
                                                if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_YELLOW_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_ORANGE_MIN)
                                                {
                                                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePoultryFarmYellowHeartFirstConversation);
                                                    }
                                                    else
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePoultryFarmYellowHeartRepeatConversation);
                                                    }
                                                }
                                                else
                                                {
                                                    if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_ORANGE_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_RED_MIN)
                                                    {
                                                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePoultryFarmOrangeHeartFirstConversation);
                                                        }
                                                        else
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePoultryFarmOrangeHeartRepeatConversation);
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_RED_MIN)
                                                        {
                                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePoultryFarmRedHeartFirstConversation);
                                                            }
                                                            else
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerSpousePoultryFarmRedHeartRepeatConversation);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                                {
                                    if (VarGet(VAR_DAY_OF_WEEK) == DAY_OF_WEEK_SUNDAY)
                                    {
                                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmSundayFirstConversation);
                                        }
                                        else
                                        {
                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmSundayRepeatConversation);
                                        }
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_WEATHER_TODAY) == WEATHER_RAIN)
                                        {
                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmRainyDayFirstConversation);
                                            }
                                            else
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmRainyDayRepeatConversation);
                                            }
                                        }
                                        else
                                        {
                                            if (GetNpcFriendship(CHARACTER_POPURI) >= 0 && GetNpcFriendship(CHARACTER_POPURI) < 25)
                                            {
                                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PoultryFarmSharedGeneralGreetingFirstConversation);
#else
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PoultryFarmSharedGeneralGreetingFirstConversation);
#endif
                                                }
                                                else
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship000To024RepeatConversation);
                                                }
                                            }
                                            else
                                            {
                                                if (GetNpcFriendship(CHARACTER_POPURI) >= 25 && GetNpcFriendship(CHARACTER_POPURI) < 50)
                                                {
                                                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship025To049FirstConversation);
                                                    }
                                                    else
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship025To049RepeatConversation);
                                                    }
                                                }
                                                else
                                                {
                                                    if (GetNpcFriendship(CHARACTER_POPURI) >= 50 && GetNpcFriendship(CHARACTER_POPURI) < 75)
                                                    {
                                                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship050To074FirstConversation);
                                                        }
                                                        else
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship050To074RepeatConversation);
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (GetNpcFriendship(CHARACTER_POPURI) >= 75 && GetNpcFriendship(CHARACTER_POPURI) < 100)
                                                        {
                                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
#if defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PoultryFarmSharedFarmProgressFirstConversation);
#else
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PoultryFarmSharedFarmProgressFirstConversation);
#endif
                                                            }
                                                            else
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship075To099RepeatConversation);
                                                            }
                                                        }
                                                        else
                                                        {
                                                            if (GetNpcFriendship(CHARACTER_POPURI) >= 100 && GetNpcFriendship(CHARACTER_POPURI) < 150)
                                                            {
                                                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                                {
                                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship100To149FirstConversation);
                                                                }
                                                                else
                                                                {
                                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship100To149RepeatConversation);
                                                                }
                                                            }
                                                            else
                                                            {
                                                                if (GetNpcFriendship(CHARACTER_POPURI) >= 150 && GetNpcFriendship(CHARACTER_POPURI) < 200)
                                                                {
                                                                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                                    {
                                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship150To199FirstConversation);
                                                                    }
                                                                    else
                                                                    {
                                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship150To199RepeatConversation);
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    if (GetNpcFriendship(CHARACTER_POPURI) >= 200)
                                                                    {
                                                                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                                        {
                                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship200PlusFirstConversation);
                                                                        }
                                                                        else
                                                                        {
                                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpousePoultryFarmFriendship200PlusRepeatConversation);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                                    {
                                        if (GetNpcFriendship(CHARACTER_POPURI) >= 0 && GetNpcFriendship(CHARACTER_POPURI) < 100)
                                        {
                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
#if defined(REGION_JP)
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PoultryFarmSharedGeneralGreetingFirstConversation);
#else
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PoultryFarmSharedGeneralGreetingFirstConversation_2);
#endif
                                            }
                                            else
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerMarriedOtherCandidatePoultryFarmFriendship000To099RepeatConversation);
                                            }
                                        }
                                        else
                                        {
                                            if (GetNpcFriendship(CHARACTER_POPURI) >= 100 && GetNpcFriendship(CHARACTER_POPURI) < 200)
                                            {
                                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerMarriedOtherCandidatePoultryFarmFriendship100To199FirstConversation);
                                                }
                                                else
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerMarriedOtherCandidatePoultryFarmFriendship100To199RepeatConversation);
                                                }
                                            }
                                            else
                                            {
                                                if (GetNpcFriendship(CHARACTER_POPURI) >= 200)
                                                {
                                                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
#if defined(REGION_JP)
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PoultryFarmSharedFarmProgressFirstConversation);
#else
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PoultryFarmSharedFarmProgressFirstConversation_2);
#endif
                                                    }
                                                    else
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PlayerMarriedOtherCandidatePoultryFarmFriendship200PlusRepeatConversation);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_POPURI_PROPOSAL_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_SINGLE)
                                        {
                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_FianceeFirstConversationBeforeWedding);
                                            }
                                            else
                                            {
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_FianceeRepeatConversationWishesFatherCouldAttendWedding);
                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_FianceeRepeatConversationWondersWhatFatherWouldThinkOfPlayer);
                                            }
                                        }
                                        else
                                        {
                                            if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_BLACK_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_PURPLE_MIN)
                                            {
                                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedBlackHeartFirstConversation);
                                                }
                                                else
                                                {
                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedBlackHeartRepeatConversation);
                                                }
                                            }
                                            else
                                            {
                                                if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_PURPLE_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_BLUE_MIN)
                                                {
                                                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedPurpleHeartFirstConversation);
                                                    }
                                                    else
                                                    {
                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_ANGRY);
                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedPurpleHeartRepeatConversation);
                                                    }
                                                }
                                                else
                                                {
                                                    if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_BLUE_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_GREEN_MIN)
                                                    {
                                                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedBlueHeartFirstConversation);
                                                        }
                                                        else
                                                        {
                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedBlueHeartRepeatConversation);
                                                        }
                                                    }
                                                    else
                                                    {
                                                        if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_GREEN_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_YELLOW_MIN)
                                                        {
                                                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedGreenHeartFirstConversation);
                                                            }
                                                            else
                                                            {
                                                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                                                ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedGreenHeartRepeatConversation);
                                                            }
                                                        }
                                                        else
                                                        {
                                                            if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_YELLOW_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_ORANGE_MIN)
                                                            {
                                                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                                {
                                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedYellowHeartFirstConversation);
                                                                }
                                                                else
                                                                {
                                                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                                                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedYellowHeartRepeatConversation);
                                                                }
                                                            }
                                                            else
                                                            {
                                                                if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_ORANGE_MIN && GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_RED_MIN)
                                                                {
                                                                    if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                                    {
                                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedOrangeHeartFirstConversation);
                                                                    }
                                                                    else
                                                                    {
                                                                        SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                        TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedOrangeHeartRepeatConversation);
                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_RED_MIN)
                                                                    {
                                                                        if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                                                        {
                                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedRedHeartFirstConversation);
                                                                        }
                                                                        else
                                                                        {
                                                                            SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                                                            ShowTalkHeartIndicator(CHARACTER_POPURI);
                                                                            TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedRedHeartRepeatConversation);
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case MAP_POULTRY_FARM_HOUSE_2F:
                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PoultryFarmBedroomFirstConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_PoultryFarmBedroomRepeatConversation);
                            }
                            break;
                        case MAP_CHURCH:
                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_SURPRISED);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_ChurchFirstConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_ChurchRepeatConversation);
                            }
                            break;
                        case MAP_MOTHERS_HILL_MIDDLE:
                        case MAP_NORTH_SIDE_TOWN:
                        case MAP_ROSE_SQUARE:
                        case MAP_SOUTH_SIDE_TOWN:
                            if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_TownOutdoorRouteFirstConversation);
                            }
                            else
                            {
                                SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
                                if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                {
                                    ShowTalkHeartIndicator(CHARACTER_POPURI);
                                }
                                TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_TownOutdoorRouteRepeatConversation);
                            }
                            break;
                        case MAP_MINERAL_BEACH:
                            if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                            {
                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpouseMineralBeachFirstConversation);
                                }
                                else
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_RivalSpouseMineralBeachRepeatConversation);
                                }
                            }
                            else
                            {
                                if (WasNpcSpokenToJustNow(CHARACTER_POPURI) == FALSE)
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
                                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                    {
                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                    }
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedMineralBeachFirstConversation);
                                }
                                else
                                {
                                    SetTalkPortrait(TALK_PORTRAIT_POPURI_BLUSHING);
                                    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
                                    {
                                        ShowTalkHeartIndicator(CHARACTER_POPURI);
                                    }
                                    TalkMessage(gText_NPCEvent_Popuri_DialogueAndGiftResponses_UnmarriedMineralBeachRepeatConversation);
                                }
                            }
                            break;
                    }
                    if (var_5 == FALSE)
                    {
                        MarkNpcSpokenTo(CHARACTER_POPURI);
                        MarkNpcSpokenTo(CHARACTER_CHILD);
                    }
                    else
                    {
                        MarkNpcSpokenTo(CHARACTER_POPURI);
                    }
                }
            }
        }
    }
    TalkClose();
    SetEntityFacing(ENTITY_POPURI, var_4);
}
