#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackCollectsTodaysShipment[] =
        "今日の出荷したもの、\r\n"
        "もらっていくぜっ！{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackPraisesLargeShipment[] =
        "今日は多いなぁ。\r\n"
        "毎回、この調子で頼むぜ！{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackNotesEmptyShippingBin[] =
        "なんだ、\r\n"
        "今日は何も無いのか。{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingChickensForEggs[] =
        "鶏でも飼ったらどうだ？\r\n"
        "毎朝、世話をちゃんとやってい\r\n"
        "れば、卵を産んでくれるぜ。{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingCowsForMilk[] =
        "牛でも飼ったらどうだ？\r\n"
        "大きくなっていて、世話をちゃ\r\n"
        "んとやっていれば、牛乳を出し{Press}\r\n"
        "てくれるぞ。{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingSheepForWool[] =
        "羊でも飼ったらどうだ？\r\n"
        "大きくなっていて、世話をちゃ\r\n"
        "んとやっていれば、羊毛がとれ{Press}\r\n"
        "るぜ。{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsMiningOreForShipping[] =
        "鉱石場にある鉱石も出荷出来る\r\n"
        "んだぞ。\r\n"
        "たまには鉱石場に行って掘って{Press}\r\n"
        "きたらどうだ？{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsWinterLakeMineGems[] =
        "冬だったら湖の鉱石場にいける\r\n"
        "ぜ。そこだと珍しい鉱石が出る\r\n"
        "って話だ。{Press}\r\n"
        "鉱石でも掘ってみたらどうだ？{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsForagingInMountainsAndForests[] =
        "山とか森に行けば、出荷出来る\r\n"
        "物が落ちているはずだぜ。\r\n"
        "探してみな。{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsGrowingCropsFromSupermarketSeeds[] =
        "作物を作ったらどうだ？\r\n"
        "種は雑貨屋に売ってるぜ。{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsFishingForIncome[] =
        "おまえ、釣りはやらねぇのか？\r\n"
        "出荷したら、金になるぜ。{Press}";
};

void EventScript_FarmEvent_Zack_DailyShippingPickup(void)
{
    int var_0;
    if (GetEntityLocation(ENTITY_PLAYER) == MAP_FARM && GetEntityLocation(ENTITY_ZACK) == MAP_FARM)
    {
        SetPlayerActorUpdateSuspended(TRUE);
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        var_0 = GetEventContextValue();
        if (var_0)
        {
            if (var_0 <= 20000)
            {
                SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
                TalkMessage(gText_FarmEvent_Zack_DailyShippingPickup_ZackCollectsTodaysShipment);
            }
            else
            {
                SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
                TalkMessage(gText_FarmEvent_Zack_DailyShippingPickup_ZackPraisesLargeShipment);
            }
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_ZACK_ANGRY);
            TalkMessage(gText_FarmEvent_Zack_DailyShippingPickup_ZackNotesEmptyShippingBin);
            switch (VarGet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE))
            {
                case ZACK_EMPTY_SHIPPING_BIN_ADVICE_RAISE_CHICKENS_FOR_EGGS:
                    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
                    TalkMessage(gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingChickensForEggs);
                    VarSet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE, VarGet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE) + 1);
                    break;
                case ZACK_EMPTY_SHIPPING_BIN_ADVICE_RAISE_COWS_FOR_MILK:
                    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
                    TalkMessage(gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingCowsForMilk);
                    VarSet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE, VarGet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE) + 1);
                    break;
                case ZACK_EMPTY_SHIPPING_BIN_ADVICE_RAISE_SHEEP_FOR_WOOL:
                    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
                    TalkMessage(gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingSheepForWool);
                    VarSet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE, VarGet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE) + 1);
                    break;
                case ZACK_EMPTY_SHIPPING_BIN_ADVICE_MINE_ORE:
                    SetTalkPortrait(TALK_PORTRAIT_ZACK_AFRAID);
                    TalkMessage(gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsMiningOreForShipping);
                    VarSet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE, VarGet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE) + 1);
                    break;
                case ZACK_EMPTY_SHIPPING_BIN_ADVICE_WINTER_LAKE_MINE_GEMS:
                    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
                    TalkMessage(gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsWinterLakeMineGems);
                    VarSet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE, VarGet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE) + 1);
                    break;
                case ZACK_EMPTY_SHIPPING_BIN_ADVICE_FORAGE_MOUNTAINS_AND_FORESTS:
                    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
                    TalkMessage(gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsForagingInMountainsAndForests);
                    VarSet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE, VarGet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE) + 1);
                    break;
                case ZACK_EMPTY_SHIPPING_BIN_ADVICE_GROW_CROPS:
                    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
                    TalkMessage(gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsGrowingCropsFromSupermarketSeeds);
                    VarSet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE, VarGet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE) + 1);
                    break;
                case ZACK_EMPTY_SHIPPING_BIN_ADVICE_CATCH_FISH:
                    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
                    TalkMessage(gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsFishingForIncome);
                    VarSet(VAR_ZACK_EMPTY_SHIPPING_BIN_ADVICE_CYCLE, ZACK_EMPTY_SHIPPING_BIN_ADVICE_RAISE_CHICKENS_FOR_EGGS);
                    break;
            }
        }
        TalkClose();
        SetPlayerActorUpdateSuspended(FALSE);
    }
}
