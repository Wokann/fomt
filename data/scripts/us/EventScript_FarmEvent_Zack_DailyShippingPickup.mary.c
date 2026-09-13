#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackCollectsTodaysShipment[] =
        "I'll get today's shipment!{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackPraisesLargeShipment[] =
        "You're shipping a lot today!\r\n"
        "Keep up the good work!{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackNotesEmptyShippingBin[] =
        "What? You have nothing\r\n"
        "to ship today?{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingChickensForEggs[] =
        "Why don't you keep chickens?\r\n"
        "If you feed them everyday,\r\n"
        "they'll lay eggs.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingCowsForMilk[] =
        "Why don't you keep cows?\r\n"
        "If you take good care of\r\n"
        "them, they'll grow up and{Press}\r\n"
        "produce milk.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingSheepForWool[] =
        "Why don't you keep sheep?\r\n"
        "If you take good care of\r\n"
        "them, they'll grow and{Press}\r\n"
        "give you wool.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsMiningOreForShipping[] =
        "There are some ores from the\r\n"
        "mine that you can sell.\r\n"
        "Why don't you go dig{Press}\r\n"
        "some up?{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsWinterLakeMineGems[] =
        "You can got to the lake mine\r\n"
        "in the winter. I heard\r\n"
        "there are gems in that one.{Press}\r\n"
        "Go dig some up.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsForagingInMountainsAndForests[] =
        "You can sell some items from\r\n"
        "the mountains and forests.\r\n"
        "Go look for them.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsGrowingCropsFromSupermarketSeeds[] =
        "Why don't you grow some\r\n"
        "crops? Seeds are at the\r\n"
        "supermarket.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsFishingForIncome[] =
        "Do you fish? Selling fish\r\n"
        "will make you money.{Press}";
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
