#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1051_TV_Shopping_ProductBroadcasts.mary.h"

void EventScript_1051_TV_Shopping_ProductBroadcasts(void)
{
    int var_0, var_1;
    if (VarGet(VAR_FARMHOUSE_UPGRADE_LEVEL) == FARMHOUSE_UPGRADE_ORIGINAL)
    {
        if (VarGet(VAR_HAS_CLOCK) == FALSE || VarGet(VAR_HAS_MIRROR) == FALSE)
        {
            switch (VarGet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS))
            {
                case 0:
                case 2:
                case 4:
                case 6:
                    if (VarGet(VAR_HAS_CLOCK) == TRUE)
                    {
                        var_1 = 1;
                    }
                    else
                    {
                        var_1 = 0;
                    }
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                    if (VarGet(VAR_HAS_MIRROR) == TRUE)
                    {
                        var_1 = 0;
                    }
                    else
                    {
                        var_1 = 1;
                    }
                    break;
            }
        }
        else
        {
            var_1 = 16;
        }
    }
    else
    {
        if (VarGet(VAR_HAS_REFRIGERATOR) == FALSE || VarGet(VAR_HAS_SHELF) == FALSE)
        {
            switch (VarGet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS))
            {
                case 0:
                case 2:
                case 4:
                case 6:
                    if (VarGet(VAR_HAS_REFRIGERATOR) == TRUE)
                    {
                        var_1 = 3;
                    }
                    else
                    {
                        var_1 = 2;
                    }
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                    if (VarGet(VAR_HAS_SHELF) == TRUE)
                    {
                        var_1 = 2;
                    }
                    else
                    {
                        var_1 = 3;
                    }
                    break;
            }
        }
        else
        {
            if (VarGet(VAR_HAS_KITCHEN) == FALSE)
            {
                var_1 = 4;
            }
            else
            {
                if (VarGet(VAR_HAS_KITCHEN_KNIFE) == FALSE || VarGet(VAR_HAS_KITCHEN_FRYING_PAN) == FALSE || VarGet(VAR_HAS_KITCHEN_POT) == FALSE || VarGet(VAR_HAS_KITCHEN_MIXER) == FALSE || VarGet(VAR_HAS_KITCHEN_WHISK) == FALSE || VarGet(VAR_HAS_KITCHEN_ROLLING_PIN) == FALSE || VarGet(VAR_HAS_KITCHEN_OVEN) == FALSE || VarGet(VAR_HAS_KITCHEN_SEASONING_SET) == FALSE)
                {
                    switch (VarGet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS))
                    {
                        case 0:
                            if (VarGet(VAR_HAS_KITCHEN_KNIFE) == FALSE)
                            {
                                var_1 = 7;
                            }
                            else
                            {
                                if (VarGet(VAR_HAS_KITCHEN_FRYING_PAN) == FALSE)
                                {
                                    var_1 = 8;
                                }
                                else
                                {
                                    if (VarGet(VAR_HAS_KITCHEN_POT) == FALSE)
                                    {
                                        var_1 = 9;
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_HAS_KITCHEN_MIXER) == FALSE)
                                        {
                                            var_1 = 10;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_HAS_KITCHEN_WHISK) == FALSE)
                                            {
                                                var_1 = 11;
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_HAS_KITCHEN_ROLLING_PIN) == FALSE)
                                                {
                                                    var_1 = 12;
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_HAS_KITCHEN_OVEN) == FALSE)
                                                    {
                                                        var_1 = 13;
                                                    }
                                                    else
                                                    {
                                                        var_1 = 14;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 1:
                            if (VarGet(VAR_HAS_KITCHEN_FRYING_PAN) == FALSE)
                            {
                                var_1 = 8;
                            }
                            else
                            {
                                if (VarGet(VAR_HAS_KITCHEN_POT) == FALSE)
                                {
                                    var_1 = 9;
                                }
                                else
                                {
                                    if (VarGet(VAR_HAS_KITCHEN_MIXER) == FALSE)
                                    {
                                        var_1 = 10;
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_HAS_KITCHEN_WHISK) == FALSE)
                                        {
                                            var_1 = 11;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_HAS_KITCHEN_ROLLING_PIN) == FALSE)
                                            {
                                                var_1 = 12;
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_HAS_KITCHEN_OVEN) == FALSE)
                                                {
                                                    var_1 = 13;
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_HAS_KITCHEN_SEASONING_SET) == FALSE)
                                                    {
                                                        var_1 = 14;
                                                    }
                                                    else
                                                    {
                                                        var_1 = 7;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 2:
                            if (VarGet(VAR_HAS_KITCHEN_POT) == FALSE)
                            {
                                var_1 = 9;
                            }
                            else
                            {
                                if (VarGet(VAR_HAS_KITCHEN_MIXER) == FALSE)
                                {
                                    var_1 = 10;
                                }
                                else
                                {
                                    if (VarGet(VAR_HAS_KITCHEN_WHISK) == FALSE)
                                    {
                                        var_1 = 11;
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_HAS_KITCHEN_ROLLING_PIN) == FALSE)
                                        {
                                            var_1 = 12;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_HAS_KITCHEN_OVEN) == FALSE)
                                            {
                                                var_1 = 13;
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_HAS_KITCHEN_SEASONING_SET) == FALSE)
                                                {
                                                    var_1 = 14;
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_HAS_KITCHEN_KNIFE) == FALSE)
                                                    {
                                                        var_1 = 7;
                                                    }
                                                    else
                                                    {
                                                        var_1 = 8;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 3:
                            if (VarGet(VAR_HAS_KITCHEN_MIXER) == FALSE)
                            {
                                var_1 = 10;
                            }
                            else
                            {
                                if (VarGet(VAR_HAS_KITCHEN_WHISK) == FALSE)
                                {
                                    var_1 = 11;
                                }
                                else
                                {
                                    if (VarGet(VAR_HAS_KITCHEN_ROLLING_PIN) == FALSE)
                                    {
                                        var_1 = 12;
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_HAS_KITCHEN_OVEN) == FALSE)
                                        {
                                            var_1 = 13;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_HAS_KITCHEN_SEASONING_SET) == FALSE)
                                            {
                                                var_1 = 14;
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_HAS_KITCHEN_KNIFE) == FALSE)
                                                {
                                                    var_1 = 7;
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_HAS_KITCHEN_FRYING_PAN) == FALSE)
                                                    {
                                                        var_1 = 8;
                                                    }
                                                    else
                                                    {
                                                        var_1 = 9;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 4:
                            if (VarGet(VAR_HAS_KITCHEN_WHISK) == FALSE)
                            {
                                var_1 = 11;
                            }
                            else
                            {
                                if (VarGet(VAR_HAS_KITCHEN_ROLLING_PIN) == FALSE)
                                {
                                    var_1 = 12;
                                }
                                else
                                {
                                    if (VarGet(VAR_HAS_KITCHEN_OVEN) == FALSE)
                                    {
                                        var_1 = 13;
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_HAS_KITCHEN_SEASONING_SET) == FALSE)
                                        {
                                            var_1 = 14;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_HAS_KITCHEN_KNIFE) == FALSE)
                                            {
                                                var_1 = 7;
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_HAS_KITCHEN_FRYING_PAN) == FALSE)
                                                {
                                                    var_1 = 8;
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_HAS_KITCHEN_POT) == FALSE)
                                                    {
                                                        var_1 = 9;
                                                    }
                                                    else
                                                    {
                                                        var_1 = 10;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 5:
                            if (VarGet(VAR_HAS_KITCHEN_ROLLING_PIN) == FALSE)
                            {
                                var_1 = 12;
                            }
                            else
                            {
                                if (VarGet(VAR_HAS_KITCHEN_OVEN) == FALSE)
                                {
                                    var_1 = 13;
                                }
                                else
                                {
                                    if (VarGet(VAR_HAS_KITCHEN_SEASONING_SET) == FALSE)
                                    {
                                        var_1 = 14;
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_HAS_KITCHEN_KNIFE) == FALSE)
                                        {
                                            var_1 = 7;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_HAS_KITCHEN_FRYING_PAN) == FALSE)
                                            {
                                                var_1 = 8;
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_HAS_KITCHEN_POT) == FALSE)
                                                {
                                                    var_1 = 9;
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_HAS_KITCHEN_MIXER) == FALSE)
                                                    {
                                                        var_1 = 10;
                                                    }
                                                    else
                                                    {
                                                        var_1 = 11;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 6:
                            if (VarGet(VAR_HAS_KITCHEN_OVEN) == FALSE)
                            {
                                var_1 = 13;
                            }
                            else
                            {
                                if (VarGet(VAR_HAS_KITCHEN_SEASONING_SET) == FALSE)
                                {
                                    var_1 = 14;
                                }
                                else
                                {
                                    if (VarGet(VAR_HAS_KITCHEN_KNIFE) == FALSE)
                                    {
                                        var_1 = 7;
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_HAS_KITCHEN_FRYING_PAN) == FALSE)
                                        {
                                            var_1 = 8;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_HAS_KITCHEN_POT) == FALSE)
                                            {
                                                var_1 = 9;
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_HAS_KITCHEN_MIXER) == FALSE)
                                                {
                                                    var_1 = 10;
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_HAS_KITCHEN_WHISK) == FALSE)
                                                    {
                                                        var_1 = 11;
                                                    }
                                                    else
                                                    {
                                                        var_1 = 12;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 7:
                            if (VarGet(VAR_HAS_KITCHEN_SEASONING_SET) == FALSE)
                            {
                                var_1 = 14;
                            }
                            else
                            {
                                if (VarGet(VAR_HAS_KITCHEN_KNIFE) == FALSE)
                                {
                                    var_1 = 7;
                                }
                                else
                                {
                                    if (VarGet(VAR_HAS_KITCHEN_FRYING_PAN) == FALSE)
                                    {
                                        var_1 = 8;
                                    }
                                    else
                                    {
                                        if (VarGet(VAR_HAS_KITCHEN_POT) == FALSE)
                                        {
                                            var_1 = 9;
                                        }
                                        else
                                        {
                                            if (VarGet(VAR_HAS_KITCHEN_MIXER) == FALSE)
                                            {
                                                var_1 = 10;
                                            }
                                            else
                                            {
                                                if (VarGet(VAR_HAS_KITCHEN_WHISK) == FALSE)
                                                {
                                                    var_1 = 11;
                                                }
                                                else
                                                {
                                                    if (VarGet(VAR_HAS_KITCHEN_ROLLING_PIN) == FALSE)
                                                    {
                                                        var_1 = 12;
                                                    }
                                                    else
                                                    {
                                                        var_1 = 13;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                    }
                }
                else
                {
                    if (VarGet(VAR_HAS_CLOCK) == FALSE || VarGet(VAR_HAS_MIRROR) == FALSE)
                    {
                        switch (VarGet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS))
                        {
                            case 0:
                            case 2:
                            case 4:
                            case 6:
                                if (VarGet(VAR_HAS_CLOCK) == TRUE)
                                {
                                    var_1 = 1;
                                }
                                else
                                {
                                    var_1 = 0;
                                }
                                break;
                            case 1:
                            case 3:
                            case 5:
                            case 7:
                                if (VarGet(VAR_HAS_MIRROR) == TRUE)
                                {
                                    var_1 = 0;
                                }
                                else
                                {
                                    var_1 = 1;
                                }
                                break;
                        }
                    }
                    else
                    {
                        if (VarGet(VAR_FARMHOUSE_UPGRADE_LEVEL) == FARMHOUSE_UPGRADE_FIRST_EXTENSION)
                        {
                            var_1 = 16;
                        }
                        else
                        {
                            if (VarGet(VAR_HAS_CARPET) == FALSE || VarGet(VAR_HAS_LARGE_BED) == FALSE)
                            {
                                switch (VarGet(VAR_TV_HARVEST_GODDESS_NUMBER_GAME_PROGRESS))
                                {
                                    case 0:
                                    case 2:
                                    case 4:
                                    case 6:
                                        if (VarGet(VAR_HAS_CARPET) == TRUE)
                                        {
                                            var_1 = 6;
                                        }
                                        else
                                        {
                                            var_1 = 5;
                                        }
                                        break;
                                    case 1:
                                    case 3:
                                    case 5:
                                    case 7:
                                        if (VarGet(VAR_HAS_LARGE_BED) == TRUE)
                                        {
                                            var_1 = 5;
                                        }
                                        else
                                        {
                                            var_1 = 6;
                                        }
                                        break;
                                }
                            }
                            else
                            {
                                if (VarGet(VAR_TV_SHOPPING_POWER_BERRY_DELIVERY_STATE) == TV_SHOPPING_DELIVERY_COMPLETED)
                                {
                                    var_1 = 16;
                                }
                                else
                                {
                                    var_1 = 15;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    switch (var_1)
    {
        case 0:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductClockBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_CLOCK);
            break;
        case 1:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductMirrorBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_MIRROR);
            break;
        case 2:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductRefrigeratorBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_REFRIGERATOR);
            break;
        case 3:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductShelfBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_SHELF);
            break;
        case 4:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductKitchenBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_KITCHEN);
            break;
        case 5:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductCarpetBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_CARPET);
            break;
        case 6:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductLargeBedBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_LARGE_BED);
            break;
        case 7:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductKnifeBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_KNIFE);
            break;
        case 8:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductFryingPanBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_FRYING_PAN);
            break;
        case 9:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductPotBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_POT);
            break;
        case 10:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductMixerBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_MIXER);
            break;
        case 11:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductWhiskBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_WHISK);
            break;
        case 12:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductRollingPinBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_ROLLING_PIN);
            break;
        case 13:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductOvenBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_OVEN);
            break;
        case 14:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductSeasoningSetBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_SEASONING_SET);
            break;
        case 15:
            SetTelevisionProgram(TELEVISION_PROGRAM_TV_SHOPPING);
            var_0 = ShowTelevisionMessage(gText_TV_Shopping_ProductPowerBerryBroadcast);
            SetTVShoppingSelection(TV_SHOPPING_ITEM_POWER_BERRY);
            break;
        case 16:
            SetTelevisionProgram(TELEVISION_PROGRAM_ST_EMERALD_ACADEMY);
            CallScript(EventScript_1055_TV_StEmeraldAcademy);
            break;
    }
    EndTelevisionProgram();
    TalkClose();
    switch (var_0)
    {
        case TELEVISION_INPUT_UP_WEATHER:
        case TELEVISION_INPUT_DOWN_FARM_PROGRAM:
        case TELEVISION_INPUT_RIGHT_NEWS:
        case TELEVISION_INPUT_LEFT_VARIETY:
            VarSet(VAR_SHARED_CALLED_SCRIPT_ARGUMENT, var_0);
            CallScript(EventScript_0356_TV_ChannelDispatcher);
            break;
        case TELEVISION_INPUT_ADVANCE_TEXT:
        case TELEVISION_INPUT_TURN_OFF:
            break;
    }
}
