#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenSearchesSleepingPlayersRucksack[] =
        "Schlurf...schlurf...{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenCannotLeaveGiftBecauseRucksackIsFull[] =
        "Dieser Rucksack\r\n"
        "ist so voll. Dies \r\n"
        "passt nicht einmal hinein!{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenLeavesWithoutGivingGift[] =
        "Was nun...?\r\n"
        "Warum trägt er seinen \r\n"
        "Rucksack sogar im {Press}\p"
        "Schlaf? Super! Passt!{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_MarySearchesSleepingPlayersRucksack[] =
        "Hmm...schlurf...schlurf....{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_MaryCannotLeaveGiftBecauseRucksackIsFull[] =
        "Ich wollte es dir geben.\r\n"
        "Wenn du nur Platz in\r\n"
        "deinem Rucksack hättest...{Press}\r\n"
        "Tja, dann esse ich \r\n"
        "es wohl selber. {Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_MaryLeavesWithoutGivingGift[] =
        "Hoffe, er wacht bald auf!\r\n"
        "Ich kann nicht erwarten, \r\n"
        "sein Gesicht zu sehen!{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_Shared_AnnPopuriAndElliSearchSleepingPlayersRucksack[] =
        "Schlurf...schlurf....{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_AnnCannotLeaveGiftBecauseRucksackIsFull[] =
        "Scheibenkleister! \r\n"
        "Ich habe nicht daran\r\n"
        "gedacht, was man tun kann,{Press}\r\n"
        "wenn sein Rucksack\r\n"
        "voll ist...!{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_AnnLeavesWithoutGivingGift[] =
        "...?? \r\n"
        "Zum Glück ist er nicht \r\n"
        "aufgewacht!{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_PopuriCannotLeaveGiftBecauseRucksackIsFull[] =
        "Mist! Sein\r\n"
        "Rucksack ist schon voll!{Press}\p"
        "Ich kann auch nichts\r\n"
        "rausnehmen...Oh, \r\n"
        "ich gebe auf!!{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_PopuriLeavesWithoutGivingGift[] =
        "...{NickName}s schläft.\r\n"
        "Ich kann nicht erwarten, \r\n"
        "sein Gesicht zu sehen!{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_ElliCannotLeaveGiftBecauseRucksackIsFull[] =
        "Mist! Sein Rucksack\r\n"
        "ist voll! Ich hoffe,\r\n"
        "ich vergesse nicht, es{Press}\r\n"
        "ihm später zu geben. {Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_ElliLeavesWithoutGivingGift[] =
        "Ob {NickName}\r\n"
        "überhaupt weiß, dass heute\r\n"
        "das Wintererntedankfest{Press}\r\n"
        "stattfindet?{Press}\p"
        "Ich verstecke dies ein-\r\n"
        "fach in seinem Rucksack!{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessFindsPlayerAsleep[] =
        "Was...? Er schläft?{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessCannotLeaveGiftBecauseRucksackFull[] =
        "All diese Mühe und nun\r\n"
        "ist sein Rucksack\r\n"
        "einfach voll...!{Press}";

    const char gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessLeavesGiftInSleepingPlayersRucksack[] =
        "{Player}, ich habe dir\r\n"
        "was Schönes mitgebracht!\r\n"
        "Wach auf!{Press}\p"
        "Schläft wie ein Stein!\r\n"
        "Ich weiß... Ich tue dies\r\n"
        "in seinen Rucksackl!{Press}";
};

void EventScript_FestivalEvent_WinterThanksgiving_RucksackFull(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_AMBIENCE_NIGHT);
    if (VarGet(VAR_FARMHOUSE_UPGRADE_LEVEL) == FARMHOUSE_UPGRADE_ORIGINAL)
    {
        ChangeMap(MAP_FARMHOUSE, X(200), Y(48));
        SetEntityPosition(ENTITY_PLAYER, X(200), Y(mary_negated_int(-46)), FACING_DOWN);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SLEEPING_IN_BED);
    }
    else
    {
        if (VarGet(VAR_FARMHOUSE_UPGRADE_LEVEL) == FARMHOUSE_UPGRADE_FIRST_EXTENSION)
        {
            ChangeMap(MAP_FARMHOUSE, X(320), Y(48));
            SetEntityPosition(ENTITY_PLAYER, X(320), Y(mary_negated_int(-46)), FACING_DOWN);
            SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SLEEPING_IN_BED);
        }
        else
        {
            if (VarGet(VAR_FARMHOUSE_UPGRADE_LEVEL) == FARMHOUSE_UPGRADE_SECOND_EXTENSION)
            {
                ChangeMap(MAP_FARMHOUSE, X(384), Y(48));
                SetEntityPosition(ENTITY_PLAYER, X(384), Y(mary_negated_int(-46)), FACING_DOWN);
                SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SLEEPING_IN_BED);
            }
        }
    }
    if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        SetEntityPosition(ENTITY_KAREN, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
        SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IN_BED);
    }
    else
    {
        if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
        {
            SetEntityPosition(ENTITY_POPURI, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
            SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IN_BED);
        }
        else
        {
            if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                SetEntityPosition(ENTITY_ANN, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
                SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IN_BED);
            }
            else
            {
                if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    SetEntityPosition(ENTITY_MARY, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
                    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IN_BED);
                }
                else
                {
                    if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        SetEntityPosition(ENTITY_ELLI, X(440), Y(mary_negated_int(-48)), FACING_DOWN);
                        SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IN_BED);
                    }
                }
            }
        }
    }
    if (VarGet(VAR_POPURI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_KAREN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_HARVEST_GODDESS_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        if (VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
        {
            SetEntityPosition(ENTITY_CHILD, X(416), Y(mary_negated_int(-48)), FACING_DOWN);
            SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_SLEEPING);
        }
        else
        {
            SetEntityPosition(ENTITY_CHILD, X(416), Y(mary_negated_int(-48)), FACING_DOWN);
            SetEntityAnim(ENTITY_CHILD, ANIMATION_CHILD_INFANT_SLEEPING);
        }
    }
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    WaitFrames(60 * 2);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    if (VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
    {
        MarkNpcSpokenTo(CHARACTER_KAREN);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenSearchesSleepingPlayersRucksack);
        TalkClose();
        if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
        {
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenCannotLeaveGiftBecauseRucksackIsFull);
            TalkClose();
            VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
        }
        else
        {
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_KAREN);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_KarenLeavesWithoutGivingGift);
            TalkClose();
            if (GetCharacterLove(CHARACTER_KAREN) >= LOVE_HEART_YELLOW_MIN)
            {
                AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
            }
            else
            {
                if (GetCharacterLove(CHARACTER_KAREN) < LOVE_HEART_YELLOW_MIN)
                {
                    AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                }
            }
            VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            AddCharacterLove(CHARACTER_KAREN, 1000);
        }
    }
    else
    {
        if (VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
        {
            MarkNpcSpokenTo(CHARACTER_MARY);
            SetTalkNameplateCharacter(CHARACTER_MARY);
            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_MarySearchesSleepingPlayersRucksack);
            TalkClose();
            if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
            {
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_MARY);
                TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_MaryCannotLeaveGiftBecauseRucksackIsFull);
                TalkClose();
                VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
            }
            else
            {
                TalkOpen();
                SetTalkNameplateCharacter(CHARACTER_MARY);
                TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_MaryLeavesWithoutGivingGift);
                TalkClose();
                if (GetCharacterLove(CHARACTER_MARY) >= LOVE_HEART_YELLOW_MIN)
                {
                    AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
                }
                else
                {
                    if (GetCharacterLove(CHARACTER_MARY) < LOVE_HEART_YELLOW_MIN)
                    {
                        AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                    }
                }
                VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                AddCharacterLove(CHARACTER_MARY, 1000);
            }
        }
        else
        {
            if (VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
            {
                MarkNpcSpokenTo(CHARACTER_ANN);
                SetTalkNameplateCharacter(CHARACTER_ANN);
                TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_Shared_AnnPopuriAndElliSearchSleepingPlayersRucksack);
                TalkClose();
                if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
                {
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_AnnCannotLeaveGiftBecauseRucksackIsFull);
                    TalkClose();
                    VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                }
                else
                {
                    TalkOpen();
                    SetTalkNameplateCharacter(CHARACTER_ANN);
                    TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_AnnLeavesWithoutGivingGift);
                    TalkClose();
                    if (GetCharacterLove(CHARACTER_ANN) >= LOVE_HEART_YELLOW_MIN)
                    {
                        AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
                    }
                    else
                    {
                        if (GetCharacterLove(CHARACTER_ANN) < LOVE_HEART_YELLOW_MIN)
                        {
                            AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                        }
                    }
                    VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    AddCharacterLove(CHARACTER_ANN, 1000);
                }
            }
            else
            {
                if (VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                {
                    MarkNpcSpokenTo(CHARACTER_POPURI);
                    SetTalkNameplateCharacter(CHARACTER_POPURI);
                    TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_Shared_AnnPopuriAndElliSearchSleepingPlayersRucksack);
                    TalkClose();
                    if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
                    {
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_PopuriCannotLeaveGiftBecauseRucksackIsFull);
                        TalkClose();
                        VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                    }
                    else
                    {
                        TalkOpen();
                        SetTalkNameplateCharacter(CHARACTER_POPURI);
                        TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_PopuriLeavesWithoutGivingGift);
                        TalkClose();
                        if (GetCharacterLove(CHARACTER_POPURI) >= LOVE_HEART_YELLOW_MIN)
                        {
                            AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
                        }
                        else
                        {
                            if (GetCharacterLove(CHARACTER_POPURI) < LOVE_HEART_YELLOW_MIN)
                            {
                                AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                            }
                        }
                        VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        AddCharacterLove(CHARACTER_POPURI, 1000);
                    }
                }
                else
                {
                    if (VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED)
                    {
                        MarkNpcSpokenTo(CHARACTER_ELLI);
                        SetTalkNameplateCharacter(CHARACTER_ELLI);
                        TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_Shared_AnnPopuriAndElliSearchSleepingPlayersRucksack);
                        TalkClose();
                        if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
                        {
                            TalkOpen();
                            SetTalkNameplateCharacter(CHARACTER_ELLI);
                            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_ElliCannotLeaveGiftBecauseRucksackIsFull);
                            TalkClose();
                            VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                        }
                        else
                        {
                            TalkOpen();
                            SetTalkNameplateCharacter(CHARACTER_ELLI);
                            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_ElliLeavesWithoutGivingGift);
                            TalkClose();
                            if (GetCharacterLove(CHARACTER_ELLI) >= LOVE_HEART_YELLOW_MIN)
                            {
                                AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
                            }
                            else
                            {
                                if (GetCharacterLove(CHARACTER_ELLI) < LOVE_HEART_YELLOW_MIN)
                                {
                                    AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                                }
                            }
                            VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                            AddCharacterLove(CHARACTER_ELLI, 1000);
                        }
                    }
                    else
                    {
                        if (VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
                        {
                            MarkNpcSpokenTo(CHARACTER_HARVEST_GODDESS);
                            SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                            TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessFindsPlayerAsleep);
                            TalkClose();
                            if (GetFirstFreeRucksackItemSlot() == mary_negated_int(RUCKSACK_SLOT_NOT_FOUND))
                            {
                                TalkOpen();
                                SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                                TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessCannotLeaveGiftBecauseRucksackFull);
                                TalkClose();
                                VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                            }
                            else
                            {
                                TalkOpen();
                                SetTalkNameplateCharacter(CHARACTER_HARVEST_GODDESS);
                                TalkMessage(gText_FestivalEvent_WinterThanksgiving_RucksackFull_HarvestGoddessLeavesGiftInSleepingPlayersRucksack);
                                TalkClose();
                                if (GetCharacterLove(CHARACTER_HARVEST_GODDESS) >= LOVE_HEART_YELLOW_MIN)
                                {
                                    AddFoodToRucksack(ITEM_FOOD_CHOCOLATE_CAKE, 1);
                                }
                                else
                                {
                                    if (GetCharacterLove(CHARACTER_HARVEST_GODDESS) < LOVE_HEART_YELLOW_MIN)
                                    {
                                        AddFoodToRucksack(ITEM_FOOD_CHOCOLATE, 1);
                                    }
                                }
                                VarSet(VAR_WINTER_THANKSGIVING_FARMHOUSE_SPOUSE_GIFT_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
                                AddCharacterLove(CHARACTER_HARVEST_GODDESS, 1000);
                            }
                        }
                    }
                }
            }
        }
    }
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
