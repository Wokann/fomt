#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0987_FarmEvent_Zack_DailyShippingPickup.mary.h"

void EventScript_0987_FarmEvent_Zack_DailyShippingPickup(void)
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
