#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackCollectsTodaysShipment[] =
        "Ich hole die heutigen \r\n"
        "Versandwaren ab!{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackPraisesLargeShipment[] =
        "Du versendest heute viel!\r\n"
        "Gute Arbeit, weiter so!{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackNotesEmptyShippingBin[] =
        "Was? Du hast heute\r\n"
        "nichts zu versenden?{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingChickensForEggs[] =
        "Warum hältst du keine\r\n"
        "Hühner?{Press}\r\n"
        "Wenn du sie täglich \r\n"
        "fütterst, legen sie Eier.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingCowsForMilk[] =
        "Warum hast du keine Kühe?\r\n"
        "Wenn du sie gut pflegst,\r\n"
        "wachsen sie und geben{Press}\r\n"
        "später Milch.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsRaisingSheepForWool[] =
        "Warum hältst du keine\r\n"
        "Schafe?{Press}\p"
        "Wenn du sie gut pflegst,\r\n"
        "wachsen sie und geben\r\n"
        "dir später Wolle.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsMiningOreForShipping[] =
        "Dort sind ein paar Erze\r\n"
        "aus der Mine, die du \r\n"
        "verkaufen kannst.{Press}\p"
        "Warum geht du nicht{Press}\r\n"
        "und gräbst ein paar aus?{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsWinterLakeMineGems[] =
        "Im Winter kannst du nicht\r\n"
        "zu der Seemine gehen. Ich{Press}\r\n"
        "habe gehört, dass dort \r\n"
        "Juwelen drin sind.{Press}\r\n"
        "Grabe ein paar aus.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsForagingInMountainsAndForests[] =
        "Du kannst ein paar Dinge\r\n"
        "aus den Bergen und \r\n"
        "Wäldern verkaufen.{Press}\r\n"
        "Suche dir welche.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsGrowingCropsFromSupermarketSeeds[] =
        "Warum baust du nicht ein\r\n"
        "paar Feldfrüchte an? Samen\r\n"
        "gibt es im Supermarkt.{Press}";

    const char gText_FarmEvent_Zack_DailyShippingPickup_ZackSuggestsFishingForIncome[] =
        "Angelst du? Fische \r\n"
        "verkaufen bringt Geld.{Press}";
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
