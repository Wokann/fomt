#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasAsksToSeeRequestedItem[] =
        "やぁ、{Player}くん。\r\n"
        "持って来てくれたかね？{Press}\p"
        "持って来てくれたのなら\r\n"
        "見せてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsUnrelatedItem[] =
        "これじゃないよ。\r\n"
        "{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsDiamondRequest[] =
        "わたしが頼んでいたのは\r\n"
        "「ダイヤモンド」だよ。\r\n"
        "はやく持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsBraceletRequest[] =
        "わたしが頼んでいたのは\r\n"
        "「ブレスレット」だよ。\r\n"
        "はやく持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsGreenPepperRequest[] =
        "わたしが頼んでいたのは\r\n"
        "「ピーマン」だよ。\r\n"
        "はやく持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsGoldenEggRequest[] =
        "わたしが頼んでいたのは\r\n"
        "「金の卵」だよ。\r\n"
        "はやく持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsBlackGrassRequest[] =
        "わたしが頼んでいたのは\r\n"
        "「黒い草」だよ。\r\n"
        "はやく持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsWhiteGrassRequest[] =
        "わたしが頼んでいたのは\r\n"
        "「白い草」だよ。\r\n"
        "はやく持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsTruffleRequest[] =
        "わたしが頼んでいたのは\r\n"
        "「まつたけ」だよ。\r\n"
        "はやく持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsMoonStoneRequest[] =
        "わたしが頼んでいたのは\r\n"
        "「ムーンストーン」だよ。\r\n"
        "はやく持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsAEPFEAppleRequest[] =
        "わたしが頼んでいたのは\r\n"
        "「ＡＥＰＦＥりんご」だよ。\r\n"
        "はやく持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsRiceCakeRequest[] =
        "わたしが頼んでいたのは\r\n"
        "「おもち」だよ。\r\n"
        "はやく持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasAcceptsItemAndPreparesToShowNeighboringMayor[] =
        "おお！　これだよ、これ！\r\n"
        "やっぱり、キミは大したやつ\r\n"
        "だ！{Press}\p"
        "さっそく、隣町まで行ってくる\r\n"
        "よ。これはわたしからの気持ち\r\n"
        "だ。受け取ってくれたまえ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasExplainsGoldenLumberRewardAndWarning[] =
        "これは黄金の資材といってね、\r\n"
        "とても高価なものなんだよ。{Press}\p"
        "家において見ているぐらいに\r\n"
        "しておくといいよ。{Press}\p"
        "外においておくとイヤミに\r\n"
        "見えるからね。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasThanksPlayerAgain[] =
        "じゃ、わたしはこれで…\r\n"
        "{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsPinkDiamond[] =
        "おしいっ！\r\n"
        "色がついている必要はないんだ\r\n"
        "よ！{Press}\p"
        "普通の「ダイヤモンド」を\r\n"
        "持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsOtherJewelry[] =
        "確かにこれもサイバラさんに\r\n"
        "作ってもらえる物なんだけど\r\n"
        "これじゃないんだよ。{Press}\p"
        "「ブレスレット」を持ってきて\r\n"
        "くれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsOrdinaryEgg[] =
        "残念だが、この卵じゃないんだ\r\n"
        "よ。{Press}\p"
        "「金の卵」を持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsEggDish[] =
        "卵料理を持ってきてどうするん\r\n"
        "だ！{Press}\p"
        "「金の卵」を持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsWrongGrass[] =
        "残念だが、この色の草じゃない\r\n"
        "んだよ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsBlackGrassRequestAfterWrongGrass[] =
        "「黒い草」を持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsWhiteGrassRequestAfterWrongGrass[] =
        "「白い草」を持ってきてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsTruffleRice[] =
        "まつたけごはんにしゃダメ\r\n"
        "だよ！{Press}\p"
        "「まつたけ」を持ってきて\r\n"
        "くれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsMushroomForTruffle[] =
        "このきのこじゃダメなんだよ！\r\n"
        "{Press}\p"
        "「まつたけ」を持ってきて\r\n"
        "くれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsRegularAppleForAEPFEApple[] =
        "普通のりんごじゃダメなん\r\n"
        "だよ！{Press}\p"
        "「ＡＥＰＦＥりんご」を持って\r\n"
        "きてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsSUGDWOrHMSGBAppleForAEPFEApple[] =
        "おしいけど、このりんごじゃ\r\n"
        "ダメなんだよ！{Press}\p"
        "「ＡＥＰＦＥりんご」を持って\r\n"
        "きてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsCookedAppleForAEPFEApple[] =
        "りんごのお料理を持ってきて\r\n"
        "どうするんだ！{Press}\p"
        "「ＡＥＰＦＥりんご」を持って\r\n"
        "きてくれ。{Press}";

    const char gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsRoastedRiceCake[] =
        "焼いちゃダメだよ。\r\n"
        "普通の「おもち」を持ってきて\r\n"
        "くれ。{Press}";
};

void EventScript_NPCEvent_Thomas_RandomItemRequestDelivery(void)
{
    int unused_0, var_1;
    VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_CHECKING_ITEM);
    var_1 = THOMAS_RANDOM_ITEM_DELIVERY_UNRELATED_ITEM;
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (IsPlayerHoldingNothing() == TRUE)
    {
        TalkOpen();
        VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasAsksToSeeRequestedItem);
        TalkClose();
        return;
    }
    else
    {
        switch (VarGet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX))
        {
            case THOMAS_RANDOM_ITEM_REQUEST_DIAMOND:
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE)
                {
                    if (GetPlayerHeldArticleId() == ITEM_ARTICLE_DIAMOND)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_EXACT_MATCH;
                    }
                    if (GetPlayerHeldArticleId() == ITEM_ARTICLE_PINK_DIAMOND)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_PINK_DIAMOND;
                    }
                }
                break;
            case THOMAS_RANDOM_ITEM_REQUEST_BRACELET:
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE)
                {
                    if (GetPlayerHeldArticleId() == ITEM_ARTICLE_BRACELET)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_EXACT_MATCH;
                    }
                    if (GetPlayerHeldArticleId() == ITEM_ARTICLE_NECKLACE || GetPlayerHeldArticleId() == ITEM_ARTICLE_EARRINGS || GetPlayerHeldArticleId() == ITEM_ARTICLE_BROOCH)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_OTHER_JEWELRY;
                    }
                }
                break;
            case THOMAS_RANDOM_ITEM_REQUEST_GREEN_PEPPER:
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_FOOD)
                {
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_GREEN_PEPPER)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_EXACT_MATCH;
                    }
                }
                break;
            case THOMAS_RANDOM_ITEM_REQUEST_GOLDEN_EGG:
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_FOOD)
                {
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_GOLDEN_EGG)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_EXACT_MATCH;
                    }
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_REGULAR_QUALITY_EGG || GetPlayerHeldFoodId() == ITEM_FOOD_GOOD_QUALITY_EGG || GetPlayerHeldFoodId() == ITEM_FOOD_HIGH_QUALITY_EGG || GetPlayerHeldFoodId() == ITEM_FOOD_P_EGG || GetPlayerHeldFoodId() == ITEM_FOOD_X_EGG)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_NON_GOLDEN_EGG;
                    }
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_SPA_BOILED_EGG || GetPlayerHeldFoodId() == ITEM_FOOD_SCRAMBLED_EGGS_OR_JAPANESE_OMELET || GetPlayerHeldFoodId() == ITEM_FOOD_OMELET || GetPlayerHeldFoodId() == ITEM_FOOD_OMELET_RICE || GetPlayerHeldFoodId() == ITEM_FOOD_BOILED_EGG || GetPlayerHeldFoodId() == ITEM_FOOD_EGG_OVER_RICE_OR_EGG_BOWL)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_EGG_DISH;
                    }
                }
                break;
            case THOMAS_RANDOM_ITEM_REQUEST_BLACK_GRASS:
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_FOOD)
                {
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_BLACK_GRASS)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_EXACT_MATCH;
                    }
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_BLUE_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_GREEN_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_RED_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_YELLOW_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_ORANGE_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_PURPLE_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_INDIGO_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_WHITE_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_ELLI_LEAVES)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_WRONG_GRASS;
                    }
                }
                break;
            case THOMAS_RANDOM_ITEM_REQUEST_WHITE_GRASS:
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_FOOD)
                {
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_WHITE_GRASS)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_EXACT_MATCH;
                    }
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_BLUE_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_GREEN_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_RED_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_YELLOW_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_ORANGE_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_PURPLE_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_INDIGO_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_BLACK_GRASS || GetPlayerHeldFoodId() == ITEM_FOOD_ELLI_LEAVES)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_WRONG_GRASS;
                    }
                }
                break;
            case THOMAS_RANDOM_ITEM_REQUEST_TRUFFLE:
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_FOOD)
                {
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_TRUFFLE)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_EXACT_MATCH;
                    }
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_TRUFFLE_RICE)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_TRUFFLE_RICE;
                    }
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_MUSHROOM || GetPlayerHeldFoodId() == ITEM_FOOD_POISONOUS_MUSHROOM)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_MUSHROOM;
                    }
                }
                break;
            case THOMAS_RANDOM_ITEM_REQUEST_MOON_STONE:
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_ARTICLE)
                {
                    if (GetPlayerHeldArticleId() == ITEM_ARTICLE_MOON_STONE)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_EXACT_MATCH;
                    }
                }
                break;
            case THOMAS_RANDOM_ITEM_REQUEST_AEPFE_APPLE:
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_FOOD)
                {
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_AEPFE_APPLE)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_EXACT_MATCH;
                    }
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_APPLE)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_REGULAR_APPLE;
                    }
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_SUGDW_APPLE || GetPlayerHeldFoodId() == ITEM_FOOD_HMSGB_APPLE)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_OTHER_SPECIAL_APPLE;
                    }
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_APPLE_PIE || GetPlayerHeldFoodId() == ITEM_FOOD_APPLE_JAM || GetPlayerHeldFoodId() == ITEM_FOOD_APPLE_SOUFFLE)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_COOKED_APPLE;
                    }
                }
                break;
            case THOMAS_RANDOM_ITEM_REQUEST_RICE_CAKE:
                if (GetPlayerHeldItemKind() == HELD_ITEM_KIND_FOOD)
                {
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_RICE_CAKE)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_EXACT_MATCH;
                    }
                    if (GetPlayerHeldFoodId() == ITEM_FOOD_ROASTED_RICE_CAKE)
                    {
                        var_1 = THOMAS_RANDOM_ITEM_DELIVERY_ROASTED_RICE_CAKE;
                    }
                }
                break;
        }
        switch (var_1)
        {
            case THOMAS_RANDOM_ITEM_DELIVERY_UNRELATED_ITEM:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_ANGRY);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsUnrelatedItem);
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                switch (VarGet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX))
                {
                    case THOMAS_RANDOM_ITEM_REQUEST_DIAMOND:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsDiamondRequest);
                        break;
                    case THOMAS_RANDOM_ITEM_REQUEST_BRACELET:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsBraceletRequest);
                        break;
                    case THOMAS_RANDOM_ITEM_REQUEST_GREEN_PEPPER:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsGreenPepperRequest);
                        break;
                    case THOMAS_RANDOM_ITEM_REQUEST_GOLDEN_EGG:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsGoldenEggRequest);
                        break;
                    case THOMAS_RANDOM_ITEM_REQUEST_BLACK_GRASS:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsBlackGrassRequest);
                        break;
                    case THOMAS_RANDOM_ITEM_REQUEST_WHITE_GRASS:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsWhiteGrassRequest);
                        break;
                    case THOMAS_RANDOM_ITEM_REQUEST_TRUFFLE:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsTruffleRequest);
                        break;
                    case THOMAS_RANDOM_ITEM_REQUEST_MOON_STONE:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsMoonStoneRequest);
                        break;
                    case THOMAS_RANDOM_ITEM_REQUEST_AEPFE_APPLE:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsAEPFEAppleRequest);
                        break;
                    case THOMAS_RANDOM_ITEM_REQUEST_RICE_CAKE:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsRiceCakeRequest);
                        break;
                }
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_EXACT_MATCH:
                UsePlayerHeldItem();
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasAcceptsItemAndPreparesToShowNeighboringMayor);
                TalkClose();
                SetPlayerHeldArticle(ITEM_ARTICLE_GOLDEN_LUMBER);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasExplainsGoldenLumberRewardAndWarning);
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasThanksPlayerAgain);
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                AddNpcFriendship(CHARACTER_THOMAS, 30);
                if (X(GetEntityX(ENTITY_THOMAS)) != X(340))
                {
                    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
                    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
                    MoveEntityXTo(ENTITY_THOMAS, X(340), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                    WaitForEntityMovement(ENTITY_THOMAS);
                    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
                }
                SetEntityFacing(ENTITY_THOMAS, FACING_UP);
                SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_WALK);
                MoveEntityYTo(ENTITY_THOMAS, Y(0), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
                WaitForEntityMovement(ENTITY_THOMAS);
                SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
                HideEntity(ENTITY_THOMAS);
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_COMPLETED);
                RefreshAllNpcSchedules();
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_PINK_DIAMOND:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsPinkDiamond);
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_OTHER_JEWELRY:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsOtherJewelry);
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_NON_GOLDEN_EGG:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsOrdinaryEgg);
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_EGG_DISH:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_ANGRY);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsEggDish);
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_WRONG_GRASS:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsWrongGrass);
                switch (VarGet(VAR_THOMAS_RANDOM_ITEM_REQUESTED_ITEM_INDEX))
                {
                    case THOMAS_RANDOM_ITEM_REQUEST_BLACK_GRASS:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsBlackGrassRequestAfterWrongGrass);
                        break;
                    case THOMAS_RANDOM_ITEM_REQUEST_WHITE_GRASS:
                        TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRepeatsWhiteGrassRequestAfterWrongGrass);
                        break;
                }
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_TRUFFLE_RICE:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_ANGRY);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsTruffleRice);
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_MUSHROOM:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_ANGRY);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsMushroomForTruffle);
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_REGULAR_APPLE:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsRegularAppleForAEPFEApple);
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_OTHER_SPECIAL_APPLE:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsSUGDWOrHMSGBAppleForAEPFEApple);
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_COOKED_APPLE:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_ANGRY);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsCookedAppleForAEPFEApple);
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
            case THOMAS_RANDOM_ITEM_DELIVERY_ROASTED_RICE_CAKE:
                VarSet(VAR_THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_STATE, THOMAS_RANDOM_ITEM_REQUEST_DELIVERY_IDLE);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_NPCEvent_Thomas_RandomItemRequestDelivery_ThomasRejectsRoastedRiceCake);
                TalkClose();
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                break;
        }
    }
    return;
}
